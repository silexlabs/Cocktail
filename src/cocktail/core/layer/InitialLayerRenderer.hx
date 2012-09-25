/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layer;

import cocktail.core.renderer.ElementRenderer;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;

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
	// OVERRIDEN PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The initial LayerRenderer always creates the GraphicsContext
	 * at the root of the GraphicsContext tree
	 */
	override private function attachGraphicsContext():Void
	{
		//TODO 1 : should use Platform class
		#if macro
		#elseif (flash9 || nme)
		var initialNativeLayer:NativeElement = new flash.display.Sprite();
		flash.Lib.current.addChild(initialNativeLayer);
		graphicsContext = new GraphicsContext(this, initialNativeLayer);
		_needsBitmapSizeUpdate = true;
		hasOwnGraphicsContext = true;
		
	
		#end
	}
	
	/**
	 * The initial LayerRenderer always dispose of its GraphicsContext
	 */
	override private function detachGraphicsContext():Void 
	{
		//TODO 2 : should also use Platform class
		#if macro
		#elseif (flash9 || nme)
		if (graphicsContext != null)
		{
			flash.Lib.current.removeChild(graphicsContext.nativeLayer);
			graphicsContext.dispose();
			graphicsContext = null;
			hasOwnGraphicsContext = false;
		}
		#end
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
	
	
}