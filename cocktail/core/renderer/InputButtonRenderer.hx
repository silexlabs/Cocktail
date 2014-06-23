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
import cocktail.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.geom.GeomData;
import cocktail.core.layer.InputLayerRenderer;
import cocktail.port.Bindings;

/**
 * This is an input element renderrer in charge of
 * rendering a button
 * 
 * @author Yannick DOMINGUEZ
 */
class InputButtonRenderer extends InputRenderer
{
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
	}
	
	/**
	 * Instantiate a native button input
	 */
	override private function createNativeInput():Void
	{
		nativeInput = new NativeButton(cast(domNode));
	}
}
