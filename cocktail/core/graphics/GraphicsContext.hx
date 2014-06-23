/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.graphics;

import cocktail.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.ds.FastNode;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.core.layout.LayoutData;


/**
 * Each LayerRenderer has a reference to a graphics context.
 * Graphics context are stored as a tree of GraphicContext object.
 * 
 * Each GraphicContext has a reference to a native object representing
 * the concept of a layer in the target platform. For instance, for
 * the Flash platform, a layer can be assimilated to a Sprite.
 * 
 * They are the closest abstraction in Cocktail from the native
 * display list tree of the underlying platform. The tree of GraphicContext
 * builds a tree of native layer from the target platform.
 *
 * We could have had just one GraphicContext for the whole document and
 * paint onto it, but it seems like a better approach for platform integration
 * to instead leverage the native display list of the platform.
 * 
 * For instance, for a video it allows the underlying platform to take care of the compositing,
 * the video being given its own GraphicContext. Elements below and on top of the video are also
 * given their GraphicContext so that they can respect the z-ordering of the document. 
 * 
 * This compositing can be deactivated (see Config.hx) in which case only one GraphicContext is created
 * for the document which prevent overlapping but reduce memory usage.
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicsContext extends FastNode<GraphicsContext>
{
	/**
	 * A reference to a native layer
	 */
	public var nativeLayer(default, null):NativeLayer;
	
	/**
	 * A reference to the LayerRenderer which created this GraphicsContext
	 */
	public var layerRenderer(default, null):LayerRenderer;
	
	/**
	 * A flag set when the native layers needs to be re-attached to the native
	 * display list, after a change in the ordered list of child graphics
	 * context
	 */
	private var _needsNativeLayerUpdate:Bool;
	
	/**
	 * class constructor
	 * @param layerRenderer the LayerRenderer which instantiated this 
	 * GraphicsContext
	 */
	public function new(layerRenderer:LayerRenderer)
	{
		super();
		this.layerRenderer = layerRenderer;
		_needsNativeLayerUpdate = true;
		nativeLayer = new NativeLayer();
	}
	
	/**
	 * clean-up method
	 */
	public function dispose():Void
	{
		nativeLayer.dispose();
		nativeLayer = null;
		layerRenderer = null;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Overriden to invalidate the native layer tree, and the
	 * size of the bitmap
	 */ 
	override public function appendChild(newChild:GraphicsContext):Void
	{
		super.appendChild(newChild);
		newChild.addedToGraphicsContextTree();
	}
	
	/**
	 * Overriden to invalidate the native layer tree, the size
	 * of the bitmap
	 * and detach the old child
	 */ 
	override public function removeChild(oldChild:GraphicsContext):Void
	{
		oldChild.removedFromGraphicsContextTree();
		super.removeChild(oldChild);
	}
	
	/**
	 * Overriden to invalidate the native layer tree
	 * and the size of the bitmap
	 */ 
	override public function insertBefore(newChild:GraphicsContext, refChild:GraphicsContext):Void
	{
		super.insertBefore(newChild, refChild);

		if (refChild == null)
		{
			return;
		}
		
		newChild.addedToGraphicsContextTree();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC GRAPHICS CONTEXT TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called by the parent GraphicsContext when
	 * this GraphicsContext is appended to the
	 * GraphicsContext tree
	 */
	public function addedToGraphicsContextTree():Void
	{
		invalidateNativeLayer();
		invalidateBitmapSize();
	}
	
	/**
	 * Called by the parent GraphicsContext when
	 * this GraphicsContext is removed from the
	 * GraphicsContext tree
	 */
	public function removedFromGraphicsContextTree():Void
	{
		detach();
		invalidateNativeLayer();
		invalidateBitmapSize();
	}
	
	/**
	 * Called when the size of the viewport changed
	 * or when a new graphics context was added to
	 * the graphics context tree. Update 
	 * the size of the bitmaps used for rendering
	 * 
	 * @param	viewportWidth	the width of the viewport, used as the width of the bitmap
	 * @param	viewportHeight	the height of the viewport, used as the height of the bitmap
	 */
	public function updateGraphicsSize(viewportWidth:Int, viewportHeight:Int):Void
	{
		//some layer don't need their own bitmap surface
		if (layerRenderer.needsBitmap() ==  true)
		{
			nativeLayer.initBitmapData(viewportWidth, viewportHeight);
		}
		
		var child:GraphicsContext = firstChild;
		while (child != null)
		{
			child.updateGraphicsSize(viewportWidth, viewportHeight);
			child = child.nextSibling;
		}
	}
	
	/**
	 * Main method building the native layer tree.
	 * Called by the document when the tree needs
	 * to be updated
	 */
	public function updateNativeLayer():Void
	{
		if (_needsNativeLayerUpdate == true)
		{
			_needsNativeLayerUpdate = false;
			detach();
			attach();
			return;
		}
		
		var child:GraphicsContext = firstChild;
		while (child != null)
		{
			child.updateNativeLayer();
			child = child.nextSibling;
		}
	}
	
	/**
	 * called when the native layer is invalid, schedule
	 * a call to update the native layer tree
	 */
	public function invalidateNativeLayer():Void
	{
		_needsNativeLayerUpdate = true;
		var htmlDocument:HTMLDocument = cast(layerRenderer.rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateNativeLayerTree();
	}
	
	/**
	 * called when the graphics context is added to
	 * the graphics context tree, its bitmap should
	 * be instantiated/updated
	 */
	public function invalidateBitmapSize():Void
	{
		var htmlDocument:HTMLDocument = cast(layerRenderer.rootElementRenderer.domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateBitmapSizes();
	}
	
	/**
	 * attachement for graphics context
	 * consist in attaching the native layer
	 * to the native display list
	 */
	public function attach():Void
	{
		doAttach();
		
		var child:GraphicsContext = firstChild;
		while (child != null)
		{
			child.attach();
			child = child.nextSibling;
		}
	}
	
	/**
	 * when detached, the graphics context
	 * detach its native layer from
	 * the native layer tree
	 */
	public function detach():Void
	{
		var child:GraphicsContext = firstChild;
		while (child != null)
		{
			child.detach();
			child = child.nextSibling;
		}
		
		doDetach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE GRAPHICS CONTEXT TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually attach the native layer
	 */
	private function doAttach():Void
	{
		//find the index of this graphic context among its
		//parent's child nodes
		var index:Int = 0;
		var previousGraphicsContextSibling:GraphicsContext = this.previousSibling;
		while (previousGraphicsContextSibling != null)
		{
			index++;
			previousGraphicsContextSibling = previousGraphicsContextSibling.previousSibling;
		}
		
		nativeLayer.attach(parentNode.nativeLayer.platformLayer, index);
	}
	
	/**
	 * Actually detach the native layer
	 */
	private function doDetach():Void
	{
		nativeLayer.detach(parentNode.nativeLayer.platformLayer);
	}
}
