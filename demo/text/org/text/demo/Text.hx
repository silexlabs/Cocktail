/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.text.demo;

import cocktail.Lib;
import cocktail.Dom;
import flash.display.Graphics;
import haxe.Http;
import haxe.Timer;

class Text 
{
	static inline var NUM_WORDS:Int = 5000;
	public static function main()
	{	
		new Text();
	}
	
	public function new()
	{
		Lib.document.body.innerHTML = "<p>Please wait... Creating "+NUM_WORDS+" words... I will zoom. **You can drag and drop.**</p>";//</p><p>
		Timer.delay(init, 2);
	}
	public function init()
	{
		var array:Array<String> = (NUM_WORDS+" words... I will zoom. **You can drag and drop.** Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus mauris leo, consectetur eget mollis eu, interdum quis massa. Etiam urna nibh, mattis nec congue nec, porta eu ligula. Curabitur massa mi, rutrum at bibendum vel, condimentum et tellus. Cras quis volutpat odio. Praesent pellentesque pulvinar metus sit amet vehicula. Aenean mi orci, cursus a rutrum id, venenatis non lacus. Nulla luctus erat ut massa varius sagittis a non neque. Aliquam pellentesque dolor a turpis mollis in sagittis ante aliquam. In fringilla neque et eros mollis interdum. Suspendisse potenti.Maecenas tincidunt ultricies leo, consequat dignissim velit faucibus sed. Nam placerat lacus mattis quam imperdiet eu blandit felis rhoncus. Cras interdum commodo nisi, sit amet ullamcorper dui cursus vitae. Aenean metus sapien, hendrerit in consequat nec, tempor et dui. Quisque ac velit nec magna convallis aliquet. Pellentesque dolor velit, malesuada ut ullamcorper sed, fermentum sed lacus. Praesent nec nunc elit, quis consequat risus. Cras tristique nulla sit amet lorem posuere a tristique metus blandit. Praesent eu libero id elit euismod volutpat at non magna. Nam a leo at justo consectetur eleifend. In vel libero libero. Suspendisse potenti. Nunc commodo, sem eget tempus bibendum, lorem nisi facilisis purus, id consequat urna quam a dolor. Nunc ac posuere felis. Quisque eleifend lectus a dui malesuada vel ullamcorper magna scelerisque.Vivamus varius vestibulum ligula, id bibendum eros varius nec. Aliquam posuere viverra diam a fringilla. Aenean a urna sit amet sem rhoncus congue et nec neque. Donec sollicitudin orci imperdiet ligula condimentum et vehicula libero mollis. Nullam vel congue sapien. Etiam vel est ut nibh tempor fringilla vel a metus. Curabitur elit orci, rhoncus quis rhoncus laoreet, dignissim nec lorem. Suspendisse mattis ipsum vitae leo ultrices posuere. Donec vehicula neque nec dui dictum tempus. In porta rutrum pharetra. ").split(" ");
		var txt = "<div><p>";
		for (i in 0...NUM_WORDS)
			txt += array[i % array.length] + " ";
		txt += "</p></div>";
		
		Lib.document.body.innerHTML = txt;
		
		#if (flash9 || nme)
		
		//Timer.delay(drawTextFieldsBackgrounds, 2);
		flash.Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_DOWN, onStageMouseDown);
		flash.Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_MOVE, onStageMouseMove);
//		flash.Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_WHEEL, onStageMouseWheel);
		zoom = 100;
		var speed:Float = -5.0;
		var a:Float = 0;
		(flash.Lib.current.stage.addEventListener(flash.events.Event.ENTER_FRAME, function(e)
		{ 
			trace(Math.round(flash.Lib.current.stage.frameRate) + " fps");
			zoom += speed;
			if (zoom < 30 || zoom > 600) 
			{
				speed = -speed;
				a = 0;
			}
//			speed += a;
//			if (speed < 0 || speed > 4) a = -a;
//			a -= .0001;
			
			flash.Lib.current.scaleX = zoom / 100; 
			flash.Lib.current.scaleY = zoom / 100;
//			flash.Lib.current.x -= 10;
//			flash.Lib.current.y -= 10;
		}));
		
		#end
	}
			var zoom:Float;
	

	private function onStageMouseWheel(e:flash.events.MouseEvent):Void
	{
		flash.Lib.current.scaleX += e.delta / 10;
		flash.Lib.current.scaleY += e.delta / 10;	
	}
	
	private var _stageX:Float;
	private var _stageY:Float;
	
	private function onStageMouseDown(e:flash.events.MouseEvent):Void
	{
		_stageX = e.stageX;
		_stageY = e.stageY;
	}
	
	private function onStageMouseMove(e:flash.events.MouseEvent):Void
	{
		if (e.buttonDown)
		{
			var xOffset:Float = e.stageX - _stageX;
			var yOffset:Float = e.stageY - _stageY;
			
			_stageX = e.stageX;
			_stageY = e.stageY;
			
			moveStageChildren(100 * xOffset / zoom, 100 * yOffset / zoom);
		}
	}
	
	private function moveStageChildren(xOffset:Float, yOffset:Float):Void
	{
/*		flash.Lib.current.x += zoom*xOffset/100;
		flash.Lib.current.y += zoom*yOffset/100;
		return;
*/		for (i in 0...flash.Lib.current.numChildren - 1)
		{
			flash.Lib.current.getChildAt(i).x += xOffset;
			flash.Lib.current.getChildAt(i).y += yOffset;
		}
	}
}