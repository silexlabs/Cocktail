/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.FocusEvent;
import cocktail.event.KeyboardEvent;
import cocktail.geom.Matrix;
import cocktail.core.html.HTMLElement;
import cocktail.core.css.CSSValueConverter;
import cocktail.geom.GeomData;
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.Bindings;

/**
 * This is an input renderer in charge of
 * rendering a text area form control
 * 
 * @author Yannick DOMINGUEZ
 */
class TextAreaRenderer extends TextInputRenderer
{
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate a native text area
	 */
	override private function createNativeInput():Void
	{
		nativeTextInput = new NativeTextArea(cast(domNode));
		nativeInput = nativeTextInput;
	}
	
	/**
	 * set top of bounds for text area
	 */
	override private function getViewportY(scrollOffset:PointVO):Float
	{
		 return globalBounds.y + coreStyle.usedValues.borderTopWidth;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a the content of the text area is used for default value
	 * but should not be rendered
	 */
	override private function renderChildren(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		
	}
}
