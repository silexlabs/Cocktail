/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.html.HTMLElement;
import cocktail.port.DrawingManager;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import cocktail.port.NativeTextInput;

/**
 * This is an ElementRenderer in charge of
 * rendering a text input form control
 * 
 * TODO 1 IMPORTANT : this might be a temporary 
 * implementation. Another approach, instead of 
 * using a NativeTextInput wrapper would be to
 * implement the text input entirely cross-platform.
 * It will allow more fidelity of rendering but less OS
 * integration
 * 
 * @author Yannick DOMINGUEZ
 */
class TextInputRenderer extends EmbeddedBoxRenderer
{
	
	/**
	 * A reference to a class wrapping a native, 
	 * runtime specific text input
	 */
	private var _nativeTextInput:NativeTextInput;
	
	/**
	 * Get/set the value of the text input
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(node:HTMLElement) 
	{
		super(node);

		_nativeTextInput = new NativeTextInput();
		
		//listen to cocktail focus events on the HTMLInputElement
		node.addEventListener(FocusEvent.FOCUS, onTextInputFocus);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also render the native text input
	 */
	override private function renderEmbeddedAsset(graphicContext:DrawingManager)
	{
		updateNativeTextInput();
		//TODO 2 : should create detach() method too ?
		//-> yes and this method should only be called when ElementRenderer is detached
		_nativeTextInput.attach(graphicContext);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the HTMLInputElement gains focus, 
	 * set the native focus on the native text
	 * input
	 */
	private function onTextInputFocus(e:Event):Void
	{
		_nativeTextInput.focus();
	}
	
	/**
	 * Update the display of the native text input
	 */
	private function updateNativeTextInput():Void
	{
		var globalBounds:RectangleData = this.globalBounds;
		
		//set the position and size of the native text input, relative
		//to the Window
		_nativeTextInput.viewport = {
			x: globalBounds.x,
			y: globalBounds.y + globalBounds.height / 2 - coreStyle.computedStyle.fontSize + coreStyle.fontMetrics.ascent / 2,
			width: globalBounds.width,
			height: globalBounds.height
		}
	
		//set the style of the text input text using the CSS applying to it
		//Based on the platform not all of those style might be taken into account
		
		_nativeTextInput.fontFamily = coreStyle.computedStyle.fontFamily[0];
		_nativeTextInput.letterSpacing = coreStyle.computedStyle.letterSpacing;
		_nativeTextInput.fontSize = coreStyle.computedStyle.fontSize;
	
		var bold:Bool;
		switch (coreStyle.computedStyle.fontWeight)
		{
			case lighter, FontWeight.normal,
			css100, css200, css300, css400:
				bold = false;
				
			case FontWeight.bold, bolder, css500, css600,
			css700, css800, css900:
				bold = true;
		}
		
		_nativeTextInput.bold = bold;
		_nativeTextInput.italic = coreStyle.computedStyle.fontStyle == FontStyle.italic;
		_nativeTextInput.letterSpacing = coreStyle.computedStyle.letterSpacing;
		_nativeTextInput.color = coreStyle.computedStyle.color.color;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_value():String 
	{
		return _nativeTextInput.value;
	}
	
	private function set_value(value:String):String 
	{
		return _nativeTextInput.value = value;
	}
}