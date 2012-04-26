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
import cocktail.core.style.StyleData;
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
	
	
	/**
	 * Render and position the background color and
	 * image of the element using runtime specific
	 * API and return an array of NativeElement from
	 * it
	 */
	override public function render():Array<NativeElement>
	{
		
		//TODO : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _coreStyle);
		
		for (i in 0...backgrounds.length)
		{
			//TODO : cause bug in the placement of block box backgrounds as x and y are also
			//applied in the LayerRenderer
			#if (flash9 || nme)
			
			if (_coreStyle.position == fixed)
			{
				
				if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
				{
					backgrounds[i].x = _globalOrigin.x + _bounds.x;
				}
				else
				{
					backgrounds[i].x = _positionedOrigin.x;
				}
				
				if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
				{
					backgrounds[i].y = _globalOrigin.y + _bounds.y;
				}
				else
				{
					backgrounds[i].y = _positionedOrigin.y;
				}
			}
			else if (_coreStyle.position == absolute)
			{
				if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
				{
					backgrounds[i].x = _globalOrigin.x + _bounds.x;
				}
				else
				{
					backgrounds[i].x = _globalPositionnedOrigin.x + _positionedOrigin.x;
				}
				
				if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
				{
					backgrounds[i].y = _globalOrigin.y + _bounds.y;
				}
				else
				{
					backgrounds[i].y = _globalPositionnedOrigin.y + _positionedOrigin.y;
				}
			}
			else
			{
				backgrounds[i].x = _globalOrigin.x + _bounds.x;
				backgrounds[i].y = _globalOrigin.y + _bounds.y;
			}
			
			#end
		
		}
		
		#if (flash9 || nme)
		
		if (isInitialContainer() == false)
		{
			
			//TODO : implement properly hit area for flash_player
			var nativeElement:flash.display.Sprite = cast(_coreStyle.htmlElement.nativeElement);
		
			nativeElement.x = 0;
			nativeElement.y = 0;
			
			nativeElement.graphics.clear();
			
			#if flash9
			nativeElement.graphics.beginFill(0xFF0000, 0.0);
			//bug in nme, no click event for transparent rect
			#elseif nme
			nativeElement.graphics.beginFill(0xFF0000, 0.01);
			#end
			nativeElement.graphics.drawRect(_globalOrigin.x + _bounds.x, _globalOrigin.y + _bounds.y, _bounds.width, _bounds.height);
			nativeElement.graphics.endFill();
			
			backgrounds.push(nativeElement);
			
		}
		#end
		
	
		return backgrounds;
	}

}