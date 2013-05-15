/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.air;

import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeTextInputBase;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;
import cocktail.core.geom.GeomData;

/**
 * This is the air port of for the native text area,
 * which in is a multiline StageText
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextArea extends NativeTextInput
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		
		//TODO : implement multiline StageText which is an option of the 
		//StageText constructor
	}
}