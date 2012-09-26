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
import cocktail.core.event.EventConstants;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.geom.GeomData;
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.layer.TextInputLayerRenderer;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeTextInput;
import cocktail.core.css.CSSData;

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
	public var nativeTextInput(default, null):NativeTextInput;
	
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

		nativeTextInput = new NativeTextInput();
		
		//listen to cocktail focus events on the HTMLInputElement
		node.addEventListener(EventConstants.FOCUS, onTextInputFocus);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A text input always create its own layer,
	 * has it is needs to be composited to
	 * leverage the native platfrom text input
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}
	
	/**
	 * A text input always create its own compositing
	 * layer
	 */
	override private function createLayer(parentLayer:LayerRenderer):Void
	{
		layerRenderer = new TextInputLayerRenderer(this);
		parentLayer.appendChild(layerRenderer);
		_hasOwnLayer = true;
	}
	
	/**
	 * Overriden to update the native text input display
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext)
	{
		updateNativeTextInput();
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
		nativeTextInput.focus();
	}
	
	/**
	 * Update the display of the native text input
	 */
	private function updateNativeTextInput():Void
	{
		var globalBounds:RectangleVO = this.globalBounds;
		
		//set the position and size of the native text input, relative
		//to the Window
		var x:Float = globalBounds.x - scrollOffset.x;
		var y:Float =  globalBounds.y + globalBounds.height / 2 - coreStyle.fontMetrics.fontSize + coreStyle.fontMetrics.ascent / 2 - scrollOffset.y;
		var width:Float =  globalBounds.width;
		var height:Float =  globalBounds.height;
		nativeTextInput.viewport = new RectangleVO(x, y, width, height);
		
		//set the style of the text input text using the CSS applying to it
		//Based on the platform not all of those style might be taken into account
		
		nativeTextInput.fontFamily = CSSValueConverter.getFontFamilyAsStringArray(coreStyle.fontFamily)[0];
		nativeTextInput.letterSpacing = coreStyle.usedValues.letterSpacing;
		nativeTextInput.fontSize = coreStyle.getAbsoluteLength(coreStyle.fontSize);
	
		var bold:Bool = false;
		switch (coreStyle.fontWeight)
		{
			case KEYWORD(value):
				switch(value)
				{
					case LIGHTER, NORMAL:
						bold = false;
						
					case BOLDER, BOLD:
						bold = true;
						
					default:
						throw 'Illegal keyword for bold style';
				}
				
			case INTEGER(value):
				bold = value > 400;
				
			default:
				throw 'Illegal value for bold style';
		}
		
		nativeTextInput.bold = bold;
		nativeTextInput.italic = coreStyle.getKeyword(coreStyle.fontStyle) == ITALIC;
		nativeTextInput.letterSpacing = coreStyle.usedValues.letterSpacing;
		nativeTextInput.color = coreStyle.usedValues.color.color;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_value():String 
	{
		return nativeTextInput.value;
	}
	
	private function set_value(value:String):String 
	{
		return nativeTextInput.value = value;
	}
}