/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layer;

import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InputRenderer;
import cocktail.core.renderer.TextInputRenderer;
import haxe.Stack;

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
			var htmlInputElement:HTMLElement = rootElementRenderer.domNode;
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
			var htmlInputElement:HTMLElement = rootElementRenderer.domNode;
			if (htmlInputElement.elementRenderer != null)
			{
				var inputRenderer:InputRenderer = cast(htmlInputElement.elementRenderer);
				inputRenderer.nativeInput.detach(graphicsContext);
			}
		}
		
		super.detachGraphicsContext();
	}
	
}