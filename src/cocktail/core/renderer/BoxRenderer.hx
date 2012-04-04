 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.NativeElement;
import cocktail.core.background.BackgroundManager;
import cocktail.core.style.CoreStyle;
import haxe.Log;

/**
 * Base class for box renderers. A box renderer
 * is an element displayed as a box, with margins,
 * paddings, backgrounds...
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxRenderer extends ElementRenderer
{
	/**
	 * a reference to the background manager in charge
	 * of displaying the background of the element
	 */
	private var _backgroundManager:BackgroundManager;
	
	/**
	 * class constructor
	 */
	public function new(style:CoreStyle) 
	{
		super(style);
		init();
		
	}
	
	private function init():Void
	{
		_backgroundManager = new BackgroundManager();
	}
	
	override public function dispose():Void
	{
		super.dispose();
		
		_backgroundManager.dispose();
		
		_backgroundManager = null;
	}
	
	/**
	 * Render and position the background color and
	 * image of the element using runtime specific
	 * API and return an array of NativeElement from
	 * it
	 */
	override public function renderBackground():Array<NativeElement>
	{
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _coreStyle);
		
		for (i in 0...backgrounds.length)
		{
			#if (flash9 || nme)
			backgrounds[i].x = _bounds.x;
			backgrounds[i].y = _bounds.y;
			#end
		}
		
		#if (flash9 || nme)
		
		if (isInitialContainer() == false)
		{
			//TODO : implement properly hit area for flash_player
			var nativeElement:flash.display.Sprite = cast(_coreStyle.htmlElement.nativeElement);
			
			nativeElement.graphics.clear();
			nativeElement.graphics.beginFill(0x00FF00, 0.0);
			nativeElement.graphics.drawRect(_bounds.x +_coreStyle.computedStyle.paddingLeft,
			_bounds.y + _coreStyle.computedStyle.paddingTop, _bounds.width, _bounds.height);
			nativeElement.graphics.endFill();
			
			//nativeElement.x = _style.computedStyle.marginLeft;
			
			backgrounds.push(nativeElement);
			
		}
	#end
		
	
		return backgrounds;
	}

}