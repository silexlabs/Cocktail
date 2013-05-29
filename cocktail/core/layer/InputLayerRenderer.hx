/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InputRenderer;
import cocktail.core.renderer.TextInputRenderer;


/**
 * A layer used to display a native input
 * 
 * @author Yannick DOMINGUEZ
 */
class InputLayerRenderer extends CompositingLayerRenderer
{
	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING TREE METHODS
	////////////////////////////////
	
	override public function attachGraphicsContext():Void
	{
		super.attachGraphicsContext();
		
		if (graphicsContext != null)
		{
			var htmlInputElement:HTMLElement = cast(rootElementRenderer.domNode);
			if (htmlInputElement.elementRenderer != null)
			{
				var inputRenderer:InputRenderer = cast(htmlInputElement.elementRenderer);
				inputRenderer.nativeInput.attach(graphicsContext);
			}
		}
	}
	
	override public function detachGraphicsContext():Void
	{
		//TODO 3 : is graphics context supposed to be null at some point ?
		if (graphicsContext != null)
		{
			var htmlInputElement:HTMLElement = cast(rootElementRenderer.domNode);
			if (htmlInputElement.elementRenderer != null)
			{
				var inputRenderer:InputRenderer = cast(htmlInputElement.elementRenderer);
				inputRenderer.nativeInput.detach(graphicsContext);
			}
		}
		
		super.detachGraphicsContext();
	}
	
}