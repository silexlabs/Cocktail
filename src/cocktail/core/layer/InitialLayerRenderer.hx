/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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