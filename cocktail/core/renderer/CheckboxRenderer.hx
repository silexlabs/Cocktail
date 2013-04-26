/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.core.geom.GeomData;
import cocktail.core.layer.InputLayerRenderer;
import cocktail.port.NativeCheckbox;
import cocktail.port.NativeInput;

/**
 * This is an input element renderrer in charge of
 * rendering a checkbox
 * 
 * @author Yannick DOMINGUEZ
 */
class CheckboxRenderer extends InputRenderer
{
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	/**
	 * Instantiate a native checkbox input
	 */
	override private function createNativeInput():Void
	{
		nativeInput = new NativeCheckbox(domNode);
	}
}