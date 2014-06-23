/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.invalidation;

import cocktail.core.config.Config;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.geom.GeomUtils;
import cocktail.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.stacking.StackingContext;
import cocktail.core.layout.LayoutData;
import cocktail.geom.GeomData;
import cocktail.css.CSSStyleData;

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
	 * Set to true when at least one layer of the document
	 * was scrolled since last document update
	 */
	private var _scrollOffsetNeedsUpdate:Bool;
	
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
	 * Wether some pending transitions need to 
	 * be started or ended
	 */
	private var _pendingTransitionsNeedUpdate:Bool;
	
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
	 * Wheter the viewport size changed
	 * since last document update.
	 * If it did, then a resize
	 * event should be dispatched
	 * after next update
	 */
	private var _viewportResized:Bool;
	
	/**
	 * Wether the graphics context bitmap
	 * onto which the document is rendered
	 * needs to update their size.
	 * Happens for instance when the 
	 * viweport sizes changes
	 */
	private var _bitmapSizeNeedsUpdate:Bool;
	
	/**
	 * a reference to the HTMLDocument owning
	 * the invalidation manager
	 */
	private var _htmlDocument:HTMLDocument;
	
	/**
	 * When computing the transformations matrix
	 * of all the layers of the document by  concatenating
	 * them , start
	 * with this identity matrix
	 */
	private var _initialMatrix:Matrix;
	
	/**
	 * Between each rendering, each time the 
	 * invalidate rendering method is called, 
	 * the bounds which must be repainted are
	 * provided and added to the dirty rect.
	 * 
	 * The dirty rect is the actual rectangle
	 * which gets repainted on the next rendering,
	 * this prevent repainting the whole viewport
	 * each time
	 */
	private var _dirtyRect:RectangleVO;
	
	/**
	 * A flag which if true means that the whole
	 * viewport must be updated on next rendering
	 */
	private var _repaintWholeViewport:Bool;
	
	/**
	 * A flag determining wether the dirty rect
	 * added to the global dirty rect is the first
	 * since last rendering. If it is, it becomes
	 * the dirty rect instead of being aded to it
	 */
	private var _firstDirtyRect:Bool;
	
	
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
		_pendingTransitionsNeedUpdate = true;
		_forceLayout = false;
		_viewportResized = false;
		_bitmapSizeNeedsUpdate = true;
		_scrollOffsetNeedsUpdate = false;
		
		_initialMatrix = new Matrix();
		_dirtyRect = new RectangleVO();
		
		_firstDirtyRect = true;
		
		//for the first rendering, the
		//while viewport must be painted
		_repaintWholeViewport = true;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_htmlDocument = null;
		_initialMatrix = null;
		_dirtyRect = null;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC UPDATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * start the update of the document
	 */
	public function update():Void
	{
		_invalidationScheduled = false;
		updateDocument();
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * synchronously update the document
	 */
	public function updateDocumentImmediately():Void
	{
		//when the document is updated synchronously
		//only data structure representing the document
		//need to be updated, so we prevent the document
		//from rendering now, it will render on next frame
		//if needed, thus preventing an unecessary repaint
		//of the document
		if (_documentNeedsRendering == false)
		{
			updateDocument();
		}
		else
		{
			_documentNeedsRendering = false;
			updateDocument();
			_documentNeedsRendering = true;
		}
	}
	
	/**
	 * schedule a layout and rendering of the docuement
	 * when the viewport is resized
	 */
	public function invalidateViewportSize():Void
	{
		invalidateLayout(true);
		invalidateRendering();
		_viewportResized = true;
		_bitmapSizeNeedsUpdate = true;
	}
	
	/**
	 * schedule an update of the sizes
	 * of the bitmaps used for rendering
	 */
	public function invalidateBitmapSizes():Void
	{
		_bitmapSizeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule a layout of the document
	 * @param force when true, force all elements to 
	 * be re-laid out
	 */
	public function invalidateLayout(force:Bool):Void
	{
		if (_forceLayout == true)
		{
			_forceLayout = force;
		}
	
		_documentNeedsLayout = true;
		invalidate();
	}
	
	/**
	 * schedule a rendering of the document.
	 * 
	 * An optionnal dirty rect is provided,
	 * which is the area which should be repainted on
	 * next rendering.
	 * 
	 * If no dirty rect is provided, the whole viewport
	 * will be repainted on next rendering
	 */
	public function invalidateRendering(dirtyRect:RectangleVO = null):Void
	{
		_documentNeedsRendering = true;
		invalidate();
		
		//early return if all the viewport
		//should already be repainted
		if (_repaintWholeViewport == true)
		{
			return;
		}
		
		if (dirtyRect == null)
		{
			_repaintWholeViewport = true;
		}
		//if provided dirty rect is not null, 
		//add its bounds to the global document
		//dirty rect
		else
		{
			//id this the first dirty rect added, it is 
			//used as is instead of added
			if (_firstDirtyRect == true)
			{
				_dirtyRect.x = dirtyRect.x;
				_dirtyRect.y = dirtyRect.y;
				_dirtyRect.width = dirtyRect.width;
				_dirtyRect.height = dirtyRect.height;
				
				_firstDirtyRect = false;
			}
			else
			{
				GeomUtils.addBounds(dirtyRect, _dirtyRect);
			}
		}
	}
	
	/**
	 * Called when the scroll top and/or left of a 
	 * layer has changed. Schedule an update of
	 * the document. 
	 * 
	 * If until the next update, the
	 * document rendering is not invalidated with the
	 * invalidateRendering method , this 
	 * flag allows for faster redraw of scrolled layer,
	 * as the already drawn region of the layer can 
	 * be mostly reused and only the new region appearing
	 * because of scroll needs to be actually redrawn
	 */
	public function invalidateScrollOffset():Void
	{
		_scrollOffsetNeedsUpdate = true;
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
	 * schedule starting/ending the pending transitions
	 */
	public function invalidatePendingTransitions():Void
	{
		_pendingTransitionsNeedUpdate = true;
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
	
	/**
	 * Actually invalidate the document. Default
	 * behaviour for the document is to schedule
	 * an asynchronous update
	 */
	private function doInvalidate():Void
	{
		if (_htmlDocument.onDocumentInvalidated != null)
		{
			_invalidationScheduled = true;
			_htmlDocument.onDocumentInvalidated();
		}
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
			updateCascade(true);
			_documentNeedsCascading = false;
		}
		
		//update the rendering tree before layout and
		//rendering if needed
		if (_renderingTreeNeedsUpdate == true)
		{
			updateRenderingTree();
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
			//update text element used for rendering
			_htmlDocument.documentElement.elementRenderer.updateText();
			
			updateLayout(_forceLayout);
			
			_forceLayout = false;
			_documentNeedsLayout = false;
		}
		
		//start all the pending transitions if any
		if (_pendingTransitionsNeedUpdate == true)
		{
			//start all pending transitions
			var atLeastOneTransitionStarted:Bool = _htmlDocument.documentElement.startPendingTransitions();
			
			//if at least one pending transition started, an immediate layout
			//must be performed before rendering, else the rendering will be
			//done with the end value of the animations instead of the beggining
			//value, resulting in a visual glitch
			if (atLeastOneTransitionStarted == true)
			{
				updateLayout(false);
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
		
		//when the viewport is resized or on first update,
		//all bitmaps used for rendering
		//needs to update their sizes to match
		//the new size
		if (_bitmapSizeNeedsUpdate == true)
		{
			_htmlDocument.documentElement.elementRenderer.layerRenderer.graphicsContext.updateGraphicsSize(Math.floor(_htmlDocument.getViewportWidth()), Math.floor(_htmlDocument.getViewportHeight()));
			_bitmapSizeNeedsUpdate = false;
		}
		
		//update rendering of the document
		if (_documentNeedsRendering == true || _scrollOffsetNeedsUpdate == true)
		{
			var initialLayerRenderer:LayerRenderer = _htmlDocument.documentElement.elementRenderer.layerRenderer;
			
			//standard rendering
			if (_documentNeedsRendering == true)
			{
				//for each layer concatenate its transformations with those of its parents
				initialLayerRenderer.updateLayerMatrix(_initialMatrix);
				
				//update all of the layers element renderers bounds
				initialLayerRenderer.updateBounds();
				
				//update clipped bounds of layers which don't overflow 
				initialLayerRenderer.updateClippedBounds();
				
				//update the scrollable bounds of the layer which define the area it can scroll
				initialLayerRenderer.updateScrollableBounds();
				
				//update the added scroll offset of all the layers
				initialLayerRenderer.resetScrollOffset();
				initialLayerRenderer.updateScrollOffset();
				
				//update the clip rects of layers used for rendering, default clip rect starts with the viewport
				initialLayerRenderer.resetClipRect(0, 0, _htmlDocument.getViewportWidth(), _htmlDocument.getViewportHeight());
				initialLayerRenderer.updateClipRect();
				
				//update the hit testing bound to respond accurately to user interaction
				_htmlDocument.documentElement.elementRenderer.updateHitTestingBounds();
				
				//for each layer, compute its alpha by concatenating alpha of all ancestor layers
				//TODO 2 : need not to be updated each rendering
				initialLayerRenderer.updateLayerAlpha(1.0);
				
				//for each element renderer, update the list of text
				//decorations, such as underlining to apply to
				//text elements
				_htmlDocument.documentElement.elementRenderer.updateTextDecorations(false, false, false, false);
				
				//if the whole viewport is set to be repainted,
				//the dirty rect becomes the whole viewport
				if (_repaintWholeViewport == true)
				{
					_dirtyRect.x = 0;
					_dirtyRect.y = 0;
					_dirtyRect.width = _htmlDocument.getViewportWidth();
					_dirtyRect.height = _htmlDocument.getViewportHeight();
				}
				
				//on every layer with its bitmap, clear the area of the dirty rect which is about to
				//be repainted
				initialLayerRenderer.clear(_dirtyRect.x, _dirtyRect.y, _dirtyRect.width, _dirtyRect.height);
				
				//start rendering of the document at the initial stacking context, providing the direct
				//rect to prevent repainting the whole viewport if not necessary
				initialLayerRenderer.stackingContext.render(_dirtyRect);
			}
			//special case of rendering, here rendering is needed only because 
			//one or multiple layer have been scrolled. Can be optimised
			//to reuse most of the drawn bitmap region
			else
			{
				//no need to update most of the layer bounds, as any 
				//change which would have changed them would have caused regular
				//rendering to be done instead
				
				initialLayerRenderer.resetScrollOffset();
				initialLayerRenderer.updateScrollOffset();
				
				initialLayerRenderer.resetClipRect(0, 0, _htmlDocument.getViewportWidth(), _htmlDocument.getViewportHeight());
				initialLayerRenderer.updateClipRect();
				
				//update the hit testing bound to respond accurately to user interaction
				_htmlDocument.documentElement.elementRenderer.updateHitTestingBounds();
				
				_dirtyRect.x = 0;
				_dirtyRect.y = 0; 
				_dirtyRect.width = 0;
				_dirtyRect.height = 0;
				
				//layer which have been scrolled reuse here their previous rendered bitmap
				//and update a dirty rect of all the region which actually needs to be rendered
				initialLayerRenderer.updateScrollRegion(_dirtyRect);
				
				//clear and repaint the scroll region needing it
				initialLayerRenderer.clear(_dirtyRect.x, _dirtyRect.y, _dirtyRect.width, _dirtyRect.height);
				initialLayerRenderer.stackingContext.render(_dirtyRect);
			}
			
			_documentNeedsRendering = false;
			_repaintWholeViewport = false;
			//reset the dirty rect for next rendering
			_firstDirtyRect = true;
			_dirtyRect.x = 0;
			_dirtyRect.y = 0; 
			_dirtyRect.width = 0;
			_dirtyRect.height = 0;
			_scrollOffsetNeedsUpdate = false;
		}
		
		//when the document has been entirely updated
		//end the pending transitions
		if (_pendingTransitionsNeedUpdate == true)
		{
			//Make all transitions which just ended dispose
			//of themselves and dispatch a complete event.
			//The event must be dispatched once the layout 
			//and rendering are done to prevent the user
			//from modififying the DOM with not up to date
			//info
			_htmlDocument.documentElement.endPendingTransitions();
			_pendingTransitionsNeedUpdate = false;
		}
		
		//if the viewport was resized since last update,
		//dispatched a resize event now that layout is up to date
		if (_viewportResized == true)
		{
			_viewportResized = false;
			var resizeEvent:UIEvent = new UIEvent();
			resizeEvent.initUIEvent(EventConstants.RESIZE, false, false, null, 0);
			_htmlDocument.dispatchEvent(resizeEvent);
		}
		
		//signal to the document that it is up to date
		_htmlDocument.onUpdated();
	}
	
	/**
	 * Star cascading the whole document
	 * 
	 * @param programmaticChange whether the cascading
	 * is the result of a programmatic change to the DOM/CSS.
	 * It is used to determine wether animation/transition
	 * can be started during the cascade 
	 */
	private function updateCascade(programmaticChange:Bool):Void
	{
		_htmlDocument.cascadeManager.reset();
		
		//before cascading, we must update the references used for relative
		//length computation which will remain the same during the whole cascade
		var parentRelativeLengthReference:RelativeLengthReferenceData = _htmlDocument.cascadeManager.parentRelativeLengthReference;
		var relativeLengthReference:RelativeLengthReferenceData = _htmlDocument.cascadeManager.relativeLengthReference;
		
		parentRelativeLengthReference.viewportHeight = _htmlDocument.getViewportHeight();
		parentRelativeLengthReference.viewportWidth = _htmlDocument.getViewportWidth();
		relativeLengthReference.viewportHeight = _htmlDocument.getViewportHeight();
		relativeLengthReference.viewportWidth = _htmlDocument.getViewportWidth();
	
		_htmlDocument.documentElement.cascade(_htmlDocument.cascadeManager, programmaticChange);
	}
	
	/**
	 * Start the layout of the rendering tree,
	 * starting with the root ElementRenderer
	 */
	private function updateLayout(forceLayout:Bool):Void
	{
		//layout all ElementRenderer, after this, ElementRenderer are 
		//aware of their bounds relative to their containing block
		_htmlDocument.documentElement.elementRenderer.layout(forceLayout, LayoutStateValue.NORMAL);
		
		//set the global bounds on the rendering tree. After this, ElementRenderer
		//are aware of their bounds relative ot the viewport
		_htmlDocument.documentElement.elementRenderer.setGlobalOrigins(0, 0, 0, 0);
	}
	
	/**
	 * update the rendering tree data structure
	 */
	private function updateRenderingTree():Void
	{
		_htmlDocument.documentElement.updateElementRenderer();
		_htmlDocument.documentElement.elementRenderer.updateAnonymousBlock();
		_htmlDocument.documentElement.elementRenderer.updateInlineBoxes();
	}
}
