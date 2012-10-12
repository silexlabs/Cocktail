/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.invalidation;

import cocktail.core.html.HTMLDocument;

/**
 * This class is in charge of keeping
 * track of which aspects of the docuement
 * needs updating and to schedule those
 * update
 * 
 * An invalidation method for each aspect
 * of the document to prevent unecessary
 * layout and repaint
 * 
 * @author Yannick DOMINGUEZ
 */
class InvalidationManager 
{
	/**
	 * Wether a call to the invalidation method is already
	 * scheduled, only one call to this method
	 * method can be scheduled at a time to prevent too many
	 * re-layout and re-rendering
	 */
	private var _invalidationScheduled:Bool;
	
	/*
	 * Wheter the document needs a re-layout on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsLayout:Bool;
	
	/**
	 * Wether all elements will be laid out,
	 * even if they were not invalidated
	 */
	private var _forceLayout:Bool;
	
	/*
	 * Wheter the document needs a re-rendering on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsRendering:Bool;
	
	/**
	 * Wether the document needs to cascade the styles
	 * on nex invalidation method call
	 */
	private var _documentNeedsCascading:Bool;
	
	/**
	 * wether the rendering tree, in charge of layout
	 * and rendering should be updated after
	 * its structure changed
	 */
	private var _renderingTreeNeedsUpdate:Bool;
	
	/**
	 * wether the layer tree, in charge of the
	 * rendering of the rendering tree should
	 * be updated after its structure changed
	 */
	private var _layerTreeNeedsUpdate:Bool;
	
	/**
	 * Wether the stacking contexts, which represents
	 * the z-index for the layer of the document
	 * needs to be updated
	 */
	private var _stackingContextsNeedUpdate:Bool;
	
	/**
	 * Wether the native layer tree which is 
	 * a tree formed of native display list
	 * elements needs to be updated
	 */
	private var _nativeLayerTreeNeedsUpdate:Bool;
	
	/**
	 * Wether some pending animations need to 
	 * be started or ended
	 */
	private var _pendingAnimationsNeedUpdate:Bool;
	
	/**
	 * Wheter the graphics context tree, used
	 * to paint the rendering tree should
	 * be updated after its structure changed
	 */
	private var _graphicsContextTreeNeedsUpdate:Bool;
	
	/**
	 * Wheter the whole graphics context tree should be
	 * updated. Happens when a compositing layer is
	 * attached/removed
	 */
	private var _forceGraphicsContextUpdate:Bool;
	
	/**
	 * a reference to the HTMLDocument owning
	 * the invalidation manager
	 */
	private var _htmlDocument:HTMLDocument;
	
	public function new(htmlDocument:HTMLDocument) 
	{
		_htmlDocument = htmlDocument;
		
		_invalidationScheduled = false;
		_documentNeedsLayout = true;
		_documentNeedsRendering = true;
		_documentNeedsCascading = true;
		_graphicsContextTreeNeedsUpdate = true;
		_forceGraphicsContextUpdate = false;
		_renderingTreeNeedsUpdate = true;
		_layerTreeNeedsUpdate = true;
		_nativeLayerTreeNeedsUpdate = true;
		_stackingContextsNeedUpdate = true;
		_pendingAnimationsNeedUpdate = true;
		_forceLayout = false;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * schedule a layout of the document, or 
	 * layout it immediately if needed
	 * @param immediate wether the layout should be
	 * synchronous
	 * @param force when true, force all elements to 
	 * be re-laid out
	 */
	public function invalidateLayout(immediate:Bool, force:Bool):Void
	{
		_documentNeedsLayout = true;
		_forceLayout = force;
		if (immediate == false)
		{
			invalidate();
		}
		else
		{
			updateDocument();
		}
	}
	
	/**
	 * schedule a rendering of the document
	 */
	public function invalidateRendering():Void
	{
		_documentNeedsRendering = true;
		invalidate();
	}
	
	/**
	 * Schedule an update of the rendering tree
	 */
	public function invalidateRenderingTree():Void
	{
		_renderingTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the layer tree
	 */
	public function invalidateLayerTree():Void
	{
		_layerTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the stacking context
	 */
	public function invalidateStackingContexts():Void
	{
		_stackingContextsNeedUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the native layer tree
	 */
	public function invalidateNativeLayerTree():Void
	{
		_nativeLayerTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule starting/ending the pending animations
	 */
	public function invalidatePendingAnimations():Void
	{
		_pendingAnimationsNeedUpdate = true;
		invalidate();
	}
	
	/**
	 * Shedule an update of the graphics
	 * context tree
	 */
	public function invalidateGraphicsContextTree(force:Bool):Void
	{
		_graphicsContextTreeNeedsUpdate = true;
		if (force == true)
		{
			_forceGraphicsContextUpdate = true;
		}
		invalidate();
	}
	
	/**
	 * schedule a cascade of the document
	 */
	public function invalidateCascade():Void
	{
		_documentNeedsCascading = true;
		invalidate();
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * schedule an invalidation
	 */
	private function invalidate():Void
	{
		if (_invalidationScheduled == false)
		{
			doInvalidate();
		}
	}
	
	private static var _g:Int = 0;
	
	/**
	 * Actually schedule an update if one
	 * is not yet scheduled
	 */
	private function doInvalidate():Void
	{
		_invalidationScheduled = true;
		_htmlDocument.timer.delay(onUpdateSchedule);
	}
	
	/**
	 * main update method for the docuement,
	 * after this method is called, the
	 * document is up to date
	 */
	private function updateDocument():Void
	{
		//only cascade if needed
		if (_documentNeedsCascading == true)
		{
			startCascade(true);
		}
		
		//update the rendering tree before layout and
		//rendering if needed
		if (_renderingTreeNeedsUpdate == true)
		{
			_htmlDocument.documentElement.updateElementRenderer();
			_htmlDocument.documentElement.elementRenderer.updateAnonymousBlock();
			_htmlDocument.documentElement.elementRenderer.updateLineBoxes();
			_renderingTreeNeedsUpdate = false;
		}
		
		//update the layer tree before rendergin if
		//needed
		if (_layerTreeNeedsUpdate == true)
		{
			_htmlDocument.documentElement.elementRenderer.updateLayerRenderer();
			_layerTreeNeedsUpdate = false;
		}
		
		//update the layers stacking contexts
		if (_stackingContextsNeedUpdate == true)
		{
			_htmlDocument.documentElement.elementRenderer.layerRenderer.updateStackingContext();
			_stackingContextsNeedUpdate = false;
		}
		
		//only layout if the invalidate layout
		//method was called
		if (_documentNeedsLayout == true)
		{
			startLayout(_forceLayout);
			_forceLayout = false;
		}
		
		//start all the pending animations if any
		if (_pendingAnimationsNeedUpdate == true)
		{
			//start all pending animations
			var atLeastOneAnimationStarted:Bool = _htmlDocument.documentElement.startPendingAnimation();
			
			//if at least one pending animation started, an immediate layout
			//must be performed before rendering, else the rendering will be
			//done with the end value of the animations instead of the beggining
			//value, resulting in a visual glitch
			if (atLeastOneAnimationStarted == true)
			{
				startLayout(false);
			}
		}
		
		//update the graphics context tree if needed,
		//before painting onto it
		if (_graphicsContextTreeNeedsUpdate == true)
		{
			_htmlDocument.documentElement.elementRenderer.layerRenderer.updateGraphicsContext(_forceGraphicsContextUpdate);
			_graphicsContextTreeNeedsUpdate = false;
			_forceGraphicsContextUpdate = false;
		}
		
		//update the tree of native layer if needed
		if (_nativeLayerTreeNeedsUpdate == true)
		{
			_htmlDocument.documentElement.elementRenderer.layerRenderer.graphicsContext.updateNativeLayer();
			_nativeLayerTreeNeedsUpdate = false;
		}
		
		//same as for layout
		if (_documentNeedsRendering == true)
		{
			_htmlDocument.documentElement.elementRenderer.layerRenderer.updateLayerAlpha(1.0);
			_htmlDocument.documentElement.elementRenderer.layerRenderer.render(_htmlDocument.window.innerWidth, _htmlDocument.window.innerHeight);
			_documentNeedsRendering = false;
		}
		
		//when the document has been entirely updated
		//end the pending animation
		if (_pendingAnimationsNeedUpdate == true)
		{
			//Make all animations which just ended dispose
			//of themselves and dispatch a complete event.
			//The event must be dispatched once the layout 
			//and rendering are done to prevent the user
			//from modififying the DOM with not up to date
			//info
			_htmlDocument.documentElement.endPendingAnimation();
			_pendingAnimationsNeedUpdate = false;
		}
	}
	
	/**
	 * Callback called after an invalidation is
	 * scheduled, starts updating the document
	 */
	private function onUpdateSchedule(timeStamp:Float):Void
	{
		_invalidationScheduled = false;
		updateDocument();
	}
	
	/**
	 * Star cascading the whole document
	 * 
	 * @param programmaticChange whether the cascading
	 * is the result of a programmatic change to the DOM/CSS.
	 * It is used to determine wether animation/transition
	 * can be started during the cascade 
	 */
	private function startCascade(programmaticChange:Bool):Void
	{
		_htmlDocument.documentElement.cascade(_htmlDocument.cascadeManager, programmaticChange);
		_documentNeedsCascading = false;
	}
	
	/**
	 * Start the layout of the rendering tree,
	 * starting with the root ElementRenderer
	 */
	private function startLayout(forceLayout:Bool):Void
	{
		//layout all ElementRenderer, after this, ElementRenderer are 
		//aware of their bounds relative to their containing block
		_htmlDocument.documentElement.elementRenderer.layout(forceLayout);
		
		//set the global bounds on the rendering tree. After this, ElementRenderer
		//are aware of their bounds relative ot the viewport
		_htmlDocument.documentElement.elementRenderer.setGlobalOrigins(0, 0, 0, 0, 0 ,0);
	}
	
}