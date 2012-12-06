/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

using cocktail.core.utils.Utils;
import cocktail.core.dom.Document;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.layer.ScrollableView;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.layout.computer.VisualEffectStylesComputer;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.stacking.StackingContext;
import cocktail.core.utils.FastNode;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import haxe.Log;
import cocktail.core.layer.ScrollableView;
import haxe.Stack;

/**
 * Each ElementRenderer belongs to a LayerRenderer representing
 * its position in the document in the z axis. LayerRenderer
 * are instantiated by ElementRenderer. Not all ElementRenderer
 * create their own layer, only those which can potentially overlap
 * other ElementRenderer, for instance ElementRenderer with a
 * non-static position (absolute, relative or fixed). Transparent
 * element renderer also create their own layer to ease compositing
 * when rendering
 * 
 * ElementRenderer which don't create their own LayerRenderer use
 * the one of their parent
 * 
 * The created LayerRenderers form the LayerRenderer tree,
 * paralleling the rendering tree.
 * 
 * Each LayerRenderer has a reference to a graphic context which is passed
 * to each ElementRenderer so that they can paint themselves onto it
 * 
 * Each LayerRenderer also has a reference to a stacking context.
 * Each LayerRenderer either creates their own stacking context or use
 * the one of their parent. Stacking context are created for each layer
 * which are both positioned and have a z-index other than 'auto' (an integer value)
 * Stacking contexts form a tree, ordered by the z-index of the LayerRenderer
 * which creates it.
 * This stacking context tree is used when rendering to paint the layers in the
 * right order, according to their z-index
 * 
 * @author Yannick DOMINGUEZ
 */
class LayerRenderer extends ScrollableView<LayerRenderer>
{	
	/**
	 * The stacking context onto which this
	 * layer belong, determining its z-index
	 * in the document when rendered
	 */
	public var stackingContext(default, null):StackingContext;
	
	/**
	 * The graphics context onto which all the ElementRenderers
	 * belonging to this LayerRenderer are painted onto
	 */
	public var graphicsContext(default, null):GraphicsContext;
	
	/**
	 * A flag determining wether this LayerRenderer has its own
	 * GraphicsContext or use the one of its parent. It helps
	 * to determine if this LayerRenderer is responsible to perform
	 * operation such as clearing its graphics context when rendering
	 */
	public var hasOwnGraphicsContext(default, null):Bool;
	
	/**
	 * A flag determining wether this layer renderer establishes
	 * its own stacking context. It helps to determine
	 * wether it needs to render all its child layer in
	 * the same stacking context
	 */
	public var hasOwnStackingContext(default, null):Bool;
	
	/**
	 * A flag determining wether the layer renderer needs
	 * to do any rendering. As soon as an ElementRenderer
	 * from the LayerRenderer needs rendering, its
	 * LayerRenderer needs rendering
	 * 
	 * TODO 2 : should actually be at graphics context level ?
	 * event if a layer don't need to be updated, if another
	 * sharing the same graphics context ease, it will get updated
	 */
	private var _needsRendering:Bool;
	
	/**
	 * A flag determining wether the layer should
	 * update its graphics context, it is the case for
	 * instance when the layer is attached to the rendering
	 * tree
	 */
	private var _needsGraphicsContextUpdate:Bool;
	
	/**
	 * A flag determining wether the layer should update
	 * its its stacking context before next rendering
	 */
	private var _needsStackingContextUpdate:Bool;
	
	/**
	 * This is the alpha, from 0 to 1 which
	 * should be used when rendering all
	 * the element renderer of this
	 * layer.
	 * 
	 * This is the combined value of
	 * the alphas of this layer
	 * and its ancestors
	 */
	private var _alpha:Float;
	
	/**
	 * This is the transformation matrix
	 * used when rendering the layer.
	 * 
	 * It is the concatenation of all
	 * the transformations of the ancestor
	 * layers
	 * 
	 * Default is an identity matrix
	 */
	public var matrix(default, null):Matrix;
	
	/**
	 * class constructor. init class attributes
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
		
		hasOwnGraphicsContext = false;
		hasOwnStackingContext = false;
		
		_needsRendering = true;
		_needsGraphicsContextUpdate = true;
		_needsStackingContextUpdate = true;
		
		matrix = new Matrix();
		_alpha = 1.0;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		rootElementRenderer = null;
		graphicsContext = null;
	}
	
	/////////////////////////////////
	// PUBLIC METHOD
	////////////////////////////////
	
	/**
	 * Called by the document when the graphics
	 * context tree needs to be updated. It
	 * can for instance happen when
	 * a layer which didn't have its own
	 * graphic context should now have it
	 */
	public function updateGraphicsContext(force:Bool):Void
	{
		if (_needsGraphicsContextUpdate == true || force == true)
		{
			_needsGraphicsContextUpdate = false;
			
			if (graphicsContext == null)
			{
				attachGraphicsContext();
				return;
			}
			else if (hasOwnGraphicsContext != establishesNewGraphicsContext())
			{
				detachGraphicsContext();
				attachGraphicsContext();
				return;
			}
		}
		
		var child:LayerRenderer = firstChild;
		while(child != null)
		{
			child.updateGraphicsContext(force);
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the transformation matrix of this layer before
	 * rendering. It is obtained by concatenating the transformations
	 * of this layer with those of the ancestors layers
	 * 
	 * TODO 2 : might need to split matrix of transform style and of
	 * relative positioning, as relative positioning of ancestors shouldn't apply
	 * to fixed elements but other transformations do
	 */
	public function updateLayerMatrix(parentMatrix:Matrix):Void
	{
		//reset layer's matrix
		matrix.identity();
		
		if (rootElementRenderer.isTransformed() == true)
		{
			//TODO 2 : should it still be separate class ?
			VisualEffectStylesComputer.compute(rootElementRenderer.coreStyle);
			//update transformation matrix of layer 
			matrix = getTransformationMatrix();
		}
		//concatenate layer transformation with parent transformations
		matrix.concatenate(parentMatrix);
		
		//update the whole layer tree recursively
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.updateLayerMatrix(matrix);
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the alpha of this layer before
	 * rendering. It is obtained by
	 * combining the alpha of the root element
	 * renderer with the alpha of the parent layer.
	 * 
	 * For instance if the parent alpha is 0.5 and
	 * this layer's root element renderer is 0.5,
	 * then this layer alpha will be 0.25
	 * 
	 * @param	parentAlpha the alpha of the parent
	 * layer
	 */
	public function updateLayerAlpha(parentAlpha:Float):Void
	{
		//default to 1 if the layer is opaque
		var layerAlpha:Float = 1.0;
		
		//get opacity of root element renderer if transparent
		if (rootElementRenderer.isTransparent() == true)
		{
			var coreStyle:CoreStyle = rootElementRenderer.coreStyle;
			
			switch(coreStyle.opacity)
			{
				case NUMBER(value):
					layerAlpha = value;
					
				case ABSOLUTE_LENGTH(value):
					layerAlpha = value;
					
				default:	
			}
		}
		
		//combine alpha with parent alpha
		_alpha = layerAlpha * parentAlpha;
		
		//update the whole layer tree recursively
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.updateLayerAlpha(_alpha);
			child = child.nextSibling;
		}
	}
	
	/**
	 * Called by the docuement before rendering when
	 * the stacking context of the layer tree needs to
	 * be updated
	 */
	public function updateStackingContext():Void
	{
		//only update if necessary
		if (_needsStackingContextUpdate == true)
		{
			_needsStackingContextUpdate = false;
			
			//all layer should have a stacking context
			if (stackingContext == null)
			{
				attachStackingContext();
				//early return as all child layer stacking contexts have
				//been attached recursively
				return;
			}
			//update if layer now needs own stacking context or if no longer
			//needs it
			else if (establishesNewStackingContext() != hasOwnStackingContext)
			{
				detachStackingContext();
				attachStackingContext();
				return;
			}
		}
		
		//traverse all the layer renderer tree
		var child:LayerRenderer = firstChild;
		while(child != null)
		{
			child.updateStackingContext();
			child = child.nextSibling;
		}
	}
	
	/////////////////////////////////
	// PUBLIC INVALIDATION METHOD
	////////////////////////////////
	
	/**
	 * Schedule an update of the graphics context
	 * tree using the document
	 * 
	 * @param force wether the whole graphics context tree
	 * should be updated. Happens when inserting/removing
	 * a compositing layer
	 */
	public function invalidateGraphicsContext(force:Bool):Void
	{
		_needsGraphicsContextUpdate = true;
		var htmlDocument:HTMLDocument = cast(rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateGraphicsContextTree(force);
	}
	
	/**
	 * Invalidate the rendering of this layer.
	 * If this layer has its own graphic context,
	 * each child layer using the same graphics
	 * context is also invalidated
	 */
	public function invalidateRendering():Void
	{
		_needsRendering = true;
		
		var htmlDocument:HTMLDocument = cast(rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateRendering();
		
		if (hasOwnGraphicsContext == true)
		{
			invalidateChildLayerRenderer(this);
		}
		else
		{
			//if the child has no graphics context, 
			//invalidate instead the first parent which does
			if (parentNode != null)
			{
				var parent = parentNode;
				while(parent.establishesNewGraphicsContext() == false)
				{
					parent = parent.parentNode;
				}
				
				parent.invalidateRendering();
			}
		}
		
	}
	
	/**
	 * only invalidate self, used when invalidating
	 * children to prevent infinite loop
	 */
	public function invalidateOwnRendering():Void
	{
		_needsRendering = true;
	}
	
	/**
	 * Schedule an update of the stacking
	 * contexts tree using the docuement
	 */
	public function invalidateStackingContext():Void
	{	
		var htmlDocument:HTMLDocument = cast(rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateStackingContexts();
		
		_needsStackingContextUpdate = true;
		
		detachStackingContext();
	}
	
	/////////////////////////////////
	// PRIVATE INVALIDATION METHOD
	////////////////////////////////
	
	/**
	 * Invalidate all children with
	 * the same graphic context as 
	 * this one
	 */
	private function invalidateChildLayerRenderer(rootLayer:LayerRenderer):Void
	{
		var child:LayerRenderer = rootLayer.firstChild;
		while (child != null)
		{
			if (child.hasOwnGraphicsContext == false)
			{
				child.invalidateOwnRendering();
				invalidateChildLayerRenderer(child);
			}
			child = child.nextSibling;
		}
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Overriden to schedule updates
	 */ 
	override public function appendChild(newChild:LayerRenderer):Void
	{
		super.appendChild(newChild);
		
		newChild.invalidateStackingContext();
		newChild.invalidateRendering();
		
		//needs to update graphic context, in case the new child
		//changes it
		//
		//TODO 3 : eventually, it might not be needed to invalidate
		//every time
		newChild.invalidateGraphicsContext(newChild.isCompositingLayer());
	}
	
	/**
	 * Overriden to schedule updates
	 */ 
	override public function insertBefore(newChild:LayerRenderer, refChild:LayerRenderer):Void
	{
		super.insertBefore(newChild, refChild);
		
		//if the refChild is null, then the new child
		//was inserted with appendChild and already invalidated
		if (refChild == null)
		{
			return;
		}
		
		newChild.invalidateStackingContext();
		newChild.invalidateRendering();
		//needs to update graphic context, in case the new child
		//changes it
		//
		//TODO 3 : eventually, it might not be needed to invalidate
		//every time
		newChild.invalidateGraphicsContext(newChild.isCompositingLayer());
	}
	
	/**
	 * Overriden to schedule updates
	 */ 
	override public function removeChild(oldChild:LayerRenderer):Void
	{
		//need to update graphic context after removing a child
		//as it might trigger graphic contex creation/deletion
		oldChild.invalidateGraphicsContext(oldChild.isCompositingLayer());
		oldChild.invalidateStackingContext();
		oldChild.invalidateRendering();
		
		oldChild.detachGraphicsContext();

		super.removeChild(oldChild);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach the graphics context of the layer
	 * tree. Each layer either creates its own
	 * graphics context or use the one
	 * of its parent
	 */
	public function attachGraphicsContext():Void
	{
		doAttachGraphicsContext();

		//attach all its children recursively
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.attachGraphicsContext();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Detach the graphics contexts of the layer tree.
	 * If a layer has its own graphics context,
	 * it is responsible for disposing of it
	 */
	public function detachGraphicsContext():Void
	{
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.detachGraphicsContext();
			child = child.nextSibling;
		}
		
		doDetachGraphicsContext();
	}
	
	/**
	 * Attach the stacking context of each layer
	 * of the layer tree. Each layer either
	 * creates its own stacking context or
	 * use the one of its parent
	 */
	public function attachStackingContext():Void
	{
		doAttachStackingContext();
		
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.attachStackingContext();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Detach the stacking context of each layer
	 * of the layer tree. If a layer has its own
	 * stacking context, it is responsible for
	 * disposing of it
	 */
	public function detachStackingContext():Void
	{
		var child:LayerRenderer = firstChild;
		while (child != null)
		{
			child.detachStackingContext();
			child = child.nextSibling;
		}
		
		doDetachStackingContext();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a graphics context or use the
	 * one of the parent
	 */
	private function doAttachGraphicsContext():Void
	{
		if (parentNode != null)
		{
			createGraphicsContext(parentNode.graphicsContext);
		}
	}
	
	/**
	 * Detach the GraphicContext
	 */
	private function doDetachGraphicsContext():Void 
	{
		//if this LayerRenderer instantiated its own
		//GraphicContext, it is responsible for disposing of it
		if (hasOwnGraphicsContext == true)
		{
			parentNode.graphicsContext.removeChild(graphicsContext);
			graphicsContext.dispose();
			hasOwnGraphicsContext = false;
		}
		
		graphicsContext = null;
	}
	
	/**
	 * Create a stacking context or use the one
	 * of the parent
	 */
	private function doAttachStackingContext():Void
	{
		if (parentNode != null)
		{
			createStackingContext(parentNode.stackingContext);
		}
	}
	
	/**
	 * Detach the stacking context
	 */
	private function doDetachStackingContext():Void
	{
		//if this LayerRenderer has its own stacking context,
		//dispose of it
		if (hasOwnStackingContext == true)
		{
			parentNode.stackingContext.removeChild(stackingContext);
			hasOwnStackingContext = false;
		}
		
		stackingContext = null;
	}
	
	/**
	 * Create a new GraphicsContext for this LayerRenderer
	 * or use the one of its parent
	 */
	private function createGraphicsContext(parentGraphicsContext:GraphicsContext):Void
	{
		if (establishesNewGraphicsContext() == true)
		{
			graphicsContext = new GraphicsContext(this);
			hasOwnGraphicsContext = true;
			
			//get the stacking context of the parent, this child
			//layer belongs to it
			var parentStackingContext:StackingContext = parentNode.stackingContext;
			
			var foundSelf:Bool = false;
			
			var child:StackingContext = parentStackingContext.firstChild;
			
			//loop to find the position where to insert this new graphics context, it must
			//be inserted before its first sibling with a superior z-index. The sibling
			//must also establish a new graphics context
			while(child != null)
			{
				if (foundSelf == true)
				{
					if (child.layerRenderer.graphicsContext != null)
					{
						if (child.layerRenderer.hasOwnGraphicsContext == true)
						{
							parentGraphicsContext.insertBefore(graphicsContext, child.layerRenderer.graphicsContext);
							return;
						}
					}
				}
				
				//when this layer is found,
				//its graphic context will be
				//inserted before the graphics context
				//of the next layer owning a graphics context
				if (hasOwnStackingContext == true)
				{
					if (child.layerRenderer == this)
					{
						foundSelf = true;
					}
				}
				//if the layer doesn't have its own stacking context,
				//find itself among the layer belonging to its graphics context
				else
				{
					//TODO 2 : this behaviour assumes that layer creating
					//a graphics context also create a stacking context, which
					//might not always be true
					if (stackingContext.layerRenderer == child.layerRenderer)
					{
						foundSelf = true;
					}
				}
				
				child = child.nextSibling;
			}
			
			//here the new graphics context is
			//inserted last as it didn't found a sibling
			//with a lower z-index
			parentGraphicsContext.appendChild(graphicsContext);
		}
		else
		{
			graphicsContext = parentGraphicsContext;
		}
	}
	
	/**
	 * Wether this LayerRenderer should create its
	 * own GraphicsContext
	 */
	private function establishesNewGraphicsContext():Bool
	{
		if (hasCompositingLayerDescendant(this) == true)
		{
			return true;
		}
		else if (hasCompositingLayerSibling() == true)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Create a new stacking context for this layer 
	 * if needed or use the one of 
	 * its parent
	 */
	private function createStackingContext(parentStackingContext:StackingContext):Void
	{
		//here a new stacking context is created
		if (establishesNewStackingContext() == true)
		{
			stackingContext = new StackingContext(this);
			hasOwnStackingContext = true;
			
			//get the z-index of the root element renderer of this layer
			var zIndex:Int = getZIndex(this);
			
			//loop in all the sibling stacking context, the new stacking context
			//created by this layer should be inserted before the first stacking
			//context whose layer has a z-index superior to this one
			var child:StackingContext = parentStackingContext.firstChild;
			while (child != null)
			{
				var childZIndex:Int = getZIndex(child.layerRenderer);
				if (childZIndex > zIndex)
				{
					//found the first sibling with a superior z-index
					parentStackingContext.insertBefore(stackingContext, child);
					return;
				}
				
				child = child.nextSibling;
			}
			
			//here either the new stacking context are no siblings
			//or they all have a lower z-index, insert the new
			//stacking context last
			parentStackingContext.appendChild(stackingContext);
			
		}
		else
		{
			stackingContext = parentStackingContext;
		}
	}
	
	/**
	 * Utils method returning the z index
	 * of the root element renderer of a layer
	 * @return	return zIndex as interger, if zIndex
	 * is 'auto', return 0
	 */
	private function getZIndex(layerRenderer:LayerRenderer):Int
	{
		var zIndex:Int = 0;
		
		switch(layerRenderer.rootElementRenderer.coreStyle.zIndex)
		{
			case INTEGER(value):
				zIndex = value;
				
			default:	
		}
		
		return zIndex;
	}
	
	/**
	 * Return wether a given layer has a descendant which is
	 * a compositing layer by traversing the layer tree
	 * recursively.
	 * 
	 * If it does, it must then have its own graphic context
	 * to respect z-index when compositing
	 */
	private function hasCompositingLayerDescendant(rootLayerRenderer:LayerRenderer):Bool
	{
		var child:LayerRenderer = rootLayerRenderer.firstChild;
		while (child != null)
		{
			if (child.isCompositingLayer() == true || child.hasOwnGraphicsContext == true)
			{
				return true;
			}
			else if (child.firstChild != null)
			{
				var hasCompositingLayer:Bool = hasCompositingLayerDescendant(child);
				if (hasCompositingLayer == true)
				{
					return true;
				}
			}
			
			child = child.nextSibling;
		}
		
		return false;
	}
	
	/**
	 * return wether this layer has a sibling stacking
	 * context or layer which
	 * has its own graphics context and has a lower z-index
	 * than itself.
	 * 
	 * If the layer has such a sibling, it means it is
	 * composited on top of a compositing layer and
	 * it must have its own graphic context to respect
	 * z-index
	 * 
	 * TODO 1 : should also inspect layer which don't
	 * establish stacking context
	 */
	private function hasCompositingLayerSibling():Bool
	{
		var parentStackingContext:StackingContext = parentNode.stackingContext;
		
		//TODO 1 : should never be the case, but may be called
		//before stacking context initially created, when child 
		//layer is appended, invalidateRendering is called and call
		//this method
		if (parentStackingContext == null)
		{
			return false;
		}
		
		//a flag determining wether layer with auto and 0
		//z-index of parent have already been checked
		var hasCheckedAutoAndZeroLayers:Bool = false;
		
		var child:StackingContext = parentStackingContext.firstChild;
		while (child != null)
		{
			//layer with a 0 or auto z-index must be checked by following
			//layer tree order
			if (hasCheckedAutoAndZeroLayers == false)
			{
				//the first time a child stacking context with a z-index of 0 or more
				//is found, check all auto layer and 0 stacking context in layer tree order
				if (child.layerRenderer.getZIndex(child.layerRenderer) >= 0)
				{
					var ret:Bool = hasZeroOrAutoCompositingLayerSibling(parentStackingContext.layerRenderer, this);
					if (ret == true)
					{
						return true;
					}
					
					hasCheckedAutoAndZeroLayers = true;
				}
			}
			
			//if this layer is found before any compositing layer
			//then it is rendred below and doesn't need a compositing layer
			if (child.layerRenderer == this)
			{
				return false;
			}
			else if (child.layerRenderer.isCompositingLayer() == true || child.layerRenderer.hasOwnGraphicsContext == true)
			{
				return true;
			}
			
			child = child.nextSibling;
		}
		
		//here, there is no child stacking context with a zindex != 0, 
		//but layer with auto and 0 zindex shoul still
		//be checked
		if (hasCheckedAutoAndZeroLayers == false)
		{
			return hasZeroOrAutoCompositingLayerSibling(parentStackingContext.layerRenderer, this);
		}
		
		return false;
	}
	
	/**
	 * In a given stacking context, check
	 * among the auto and 0 zindex layer wether there is a compositing layer
	 * or a layer with its own graphics context which is below the reference
	 * layer
	 */
	private function hasZeroOrAutoCompositingLayerSibling(rootLayer:LayerRenderer, referenceLayer:LayerRenderer):Bool
	{
		var child:LayerRenderer = rootLayer.firstChild;
		while (child != null)
		{
			//if the reference layer is found before
			//a layer with its own graphics context, then
			//it is below and don't need its own
			//graphics context
			if (child == referenceLayer)
			{
				return false;
			}
			
			//child is auto layer
			if (child.hasOwnStackingContext == false)
			{
				if (child.isCompositingLayer() == true || child.hasOwnGraphicsContext == true)
				{
					return true;
				}
				
				//check all layers belonging to the same stacking context
				var ret:Bool = hasZeroOrAutoCompositingLayerSibling(child, referenceLayer);
				if (ret == true)
				{
					return true;
				}
			}
			//child is 0 zindex layer
			else
			{
				switch(child.rootElementRenderer.coreStyle.zIndex)
				{
					case INTEGER(value):
						if (value == 0)
						{
							if (child.isCompositingLayer() == true || child.hasOwnGraphicsContext == true)
							{
								return true;
							}
						}
					default:	
				}
			}
			
			child = child.nextSibling;
		}
		
		return false;
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	////////////////////////////////
	
	/**
	 * Wether this layer is a compositing layer,
	 * meaning it always have its own graphic context.
	 * For instance, a GPU accelerated video layer is always a
	 * compositing layer
	 */
	public function isCompositingLayer():Bool
	{
		return false;
	}
	
	/**
	 * Wheter this layer needs its own bitmap
	 * when it has its own graphics context
	 */
	public function needsBitmap():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN BOUNDS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also
	 * add the layer's transformations
	 * to the bounds
	 * 
	 * TODO 2 : for now only support
	 * translation
	 */
	override public function updateBounds():Void
	{
		super.updateBounds();
		bounds.x += matrix.e;
		bounds.y += matrix.f;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SCROLL GETTER/SETTER
	// overriden to invalidate rendering when updated
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_scrollLeft(value:Float):Float
	{
		invalidateRendering();
		return super.set_scrollLeft(value);
	}

	override private function set_scrollTop(value:Float):Float
	{
		invalidateRendering();
		return super.set_scrollTop(value);
	}
	
	/////////////////////////////////
	// PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Starts the rendering of this LayerRenderer.
	 * Render all the element renderer belonging
	 * to this layer starting with the root element renderer.
	 */
	public function render():Void
	{
		_needsRendering = true;
		
		//only clear if a rendering is necessary
		if (_needsRendering == true)
		{
			//only clear the bitmaps if the GraphicsContext
			//was created by this LayerRenderer
			if (hasOwnGraphicsContext == true)
			{
				//reset the bitmap
				clear();
			}
		}
		
		//only render if necessary
		if (_needsRendering == true)
		{
			//if this layer is transparent, start a transparent
			//layer with the graphics context
			if (_alpha != 1.0)
			{
				graphicsContext.graphics.beginTransparency(_alpha);
			}
			
			//apply layer matrix to graphics context, so that all element
			//renderers of the lyer use those transformations
			graphicsContext.graphics.beginTransformations(matrix);
			
			//render the rootElementRenderer itself which will also
			//render all ElementRenderer belonging to this LayerRenderer
			rootElementRenderer.render(graphicsContext, clipRect, scrollOffset);
			
			//stop using the layer's transformations
			graphicsContext.graphics.endTransformations();
			
			//end transparency layer
			if (_alpha != 1.0)
			{
				graphicsContext.graphics.endTransparency();
			}
		}
		
		//layer no longer needs rendering
		_needsRendering = false;
	}
	
	/////////////////////////////////
	// PRIVATE RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Reset the bitmap
	 */
	private function clear():Void
	{
		graphicsContext.graphics.clear();
	}
	
	/**
	 * Compute all the transformation that should be applied to this LayerRenderer
	 * and return it as a transformation matrix
	 */
	private function getTransformationMatrix():Matrix
	{
		var relativeOffset:PointVO = getRelativeOffset(rootElementRenderer);
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(rootElementRenderer.coreStyle.usedValues.transform, relativeOffset);
		
		//apply relative positioning as well
		concatenatedMatrix.translate(relativeOffset.x, relativeOffset.y);
		
		return concatenatedMatrix;
	}
	
	/**
	 * Concatenate the transformation matrix obtained with the
	 * transform and transform-origin styles with the current
	 * transformations applied to the root element renderer, such as for 
	 * instance its position in the global space
	 */
	private function getConcatenatedMatrix(matrix:Matrix, relativeOffset:PointVO):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		var globalBounds:RectangleVO = rootElementRenderer.globalBounds;
		
		//translate to the coordinate system of the root element renderer
		currentMatrix.translate(globalBounds.x + relativeOffset.x, globalBounds.y + relativeOffset.y);
		
		currentMatrix.concatenate(matrix);
		
		//translate back from the coordinate system of the root element renderer
		currentMatrix.translate((globalBounds.x + relativeOffset.x) * -1, (globalBounds.y + relativeOffset.y) * -1);
		return currentMatrix;
	}
	
		
	/**
	 * Return the relative offset applied to an ElementRenerer as an x/y point. 
	 * Return 0,0 if the element renderer is not relatively positioned
	 */
	private function getRelativeOffset(elementRenderer:ElementRenderer):PointVO
	{
		var relativeOffset:PointVO = new PointVO(0.0, 0.0);
		
		//only relatively positioned ElementRenderer can have
		//an offset
		if (elementRenderer.isRelativePositioned() == true)
		{
			//first try to apply the left offset of the ElementRenderer if it is
			//not auto
			if (elementRenderer.coreStyle.isAuto(elementRenderer.coreStyle.left) == false)
			{
				relativeOffset.x += elementRenderer.coreStyle.usedValues.left;
			}
			//else the right offset,
			else if (elementRenderer.coreStyle.isAuto(elementRenderer.coreStyle.right) == false)
			{
				relativeOffset.x -= elementRenderer.coreStyle.usedValues.right;
			}
			
			//if both left and right offset are auto, then the ElementRenderer uses its static
			//position (its normal position in the flow) and no relative offset needs to
			//be applied
		
			//same for vertical offset
			if (elementRenderer.coreStyle.isAuto(elementRenderer.coreStyle.top) == false)
			{
				relativeOffset.y += elementRenderer.coreStyle.usedValues.top; 
			}
			else if (elementRenderer.coreStyle.isAuto(elementRenderer.coreStyle.bottom) == false)
			{
				relativeOffset.y -= elementRenderer.coreStyle.usedValues.bottom; 
			}
		}
		
		return relativeOffset;
	}
	
	/////////////////////////////////
	// PRIVATE LAYER TREE METHODS
	////////////////////////////////
	
	/**
	 * Wether this LayerRenderer establishes a new stacking
	 * context. If it does it is responsible for rendering
	 * all the LayerRenderer in the same stacking context, 
	 * and its child LayerRenderer which establish new
	 * stacking context themselves
	 */
	private function establishesNewStackingContext():Bool
	{
		//only layer created by positioned element
		//can establish new stacking context
		if (rootElementRenderer.isPositioned() == false)
		{
			return false;
		}
		
		//positioned with an integer z-index do
		//establish a new stacking context
		switch(rootElementRenderer.coreStyle.zIndex)
		{
			case KEYWORD(value):
				if (value == AUTO)
				{
					return false;
				}
				
			default:	
		}
		
		return true;
	}
}