/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.core.graphics.InitialGraphicsContext;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.stacking.StackingContext;

/**
 * This a special LayerRenderer used as the root of the 
 * LayerRenderer tree. It is similar to the InitialBlockRenderer
 * from the ElementRenderer tree
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialLayerRenderer extends LayerRenderer
{
	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The initial LayerRenderer always creates the GraphicsContext
	 * at the root of the GraphicsContext tree
	 */
	override private function doAttachGraphicsContext():Void
	{
		graphicsContext = new InitialGraphicsContext(this);
		hasOwnGraphicsContext = true;
	}
	
	/**
	 * Detach the initial graphics context
	 */
	override private function doDetachGraphicsContext():Void 
	{
		graphicsContext.removedFromGraphicsContextTree();
		graphicsContext.dispose();
		hasOwnGraphicsContext = false;
		graphicsContext = null;
	}
	
	/**
	 * The initial layer renderer always creates the StackingContext
	 * at the root of the stacking context tree
	 */
	override private function doAttachStackingContext():Void
	{
		stackingContext = new StackingContext(this);
		hasOwnStackingContext = true;
	}
	
	/**
	 * always detach stacking context
	 */
	override private function doDetachStackingContext():Void
	{
		stackingContext = null;
		hasOwnStackingContext = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Always establishes a new graphic context
	 */
	override private function establishesNewGraphicsContext():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE LAYER TREE METHODS
	////////////////////////////////	
	
	/**
	 * The initial layer renderer always establishes
	 * the roor stacking context
	 */
	override private function establishesNewStackingContext():Bool
	{
		return true;
	}
	
	/**
	 * The root layer has no siblings
	 */
	override private function hasCompositingLayerSibling():Bool
	{
		return false;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE UTILS METHODS
	////////////////////////////////	
	
	/**
	 * overriden as for the initial layer, a computed value
	 * of visible for overflow behaves the same as a computed
	 * value of auto
	 */
	override private function treatVisibleOverflowAsAuto():Bool
	{
		return true;
	}
	
}