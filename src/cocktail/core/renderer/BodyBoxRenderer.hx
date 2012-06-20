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
import cocktail.core.NativeElement;
import cocktail.core.style.StyleData;
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
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as the background of the HTMLBodyElement must be painted over
	 * the whole viewport
	 */
	override private function renderBackground(graphicContext:NativeElement):Void
	{
				//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO 4 : check if its still necessary that they are only computed
		//during rendering
		_coreStyle.computeBackgroundStyles();
		
		var backgroundManager:BackgroundManager = new BackgroundManager();
		
		var windowData:ContainingBlockData = getWindowData();
		
		var width:Float = windowData.width;
		var height:Float = windowData.height;
		
		var bodyBounds:RectangleData = {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		}
		
		//TODO 3 : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = backgroundManager.render(bodyBounds, _coreStyle);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		for (i in 0...backgrounds.length)
		{
			containerGraphicContext.addChild(backgrounds[i]);
		}
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overiden as the body's element renderer computed height is a special
	 * case where the height should be the height of the initial containing block
	 * if it specified as 'auto'
	 * 
	 * TODO 3 : shouldn't it be in boxComputers instead ?
	 */
	override private function layoutSelf():Void
	{
		super.layoutSelf();
		if (_coreStyle.height == Dimension.cssAuto && (isPositioned() == false || isRelativePositioned() == true))
		{
			this.computedStyle.height = _containingBlock.getContainerBlockData().height - computedStyle.marginTop - computedStyle.marginBottom
			-computedStyle.paddingTop - computedStyle.paddingBottom;
		}
	}
	
	
}