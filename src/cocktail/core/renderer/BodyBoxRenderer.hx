/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;

import cocktail.port.NativeElement;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;

/**
 * 
 * This is a special sub class of block box
 * for the HTMLBodyElement
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyBoxRenderer extends BlockBoxRenderer
{

	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overiden as the body's element renderer computed height is a special
	 * case where the height should be the height of the initial containing block
	 * if it specified as 'auto'
	 */
	override private function layoutSelf():Void
	{
		super.layoutSelf();
		
		if (coreStyle.isAuto(coreStyle.height) == true && (isPositioned() == false || isRelativePositioned() == true))
		{
			var usedValues:UsedValuesVO = coreStyle.usedValues;
			usedValues.height = _containingBlock.getContainerBlockData().height - usedValues.marginTop - usedValues.marginBottom
			- usedValues.paddingTop - usedValues.paddingBottom;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The HTMLBodyElement uses the bounds of the viewport
	 * for its background
	 */
	override private function getBackgroundBounds():RectangleVO
	{
		var windowData:ContainingBlockVO = getWindowData();
		
		var width:Float = windowData.width;
		var height:Float = windowData.height;
		
		return new RectangleVO(0.0, 0.0, width, height);
	}
	
	
}