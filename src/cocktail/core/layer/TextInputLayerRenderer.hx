/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layer;

import cocktail.core.html.HTMLInputElement;
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.TextInputRenderer;

/**
 * TODO 1 : this class is identical to PluginLayerRenderer
 * but for native text input, should use CompositingLayerRenderer
 * base class, need to implement same thing for video
 * 
 * @author Yannick DOMINGUEZ
 */
class TextInputLayerRenderer extends CompositingLayerRenderer
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
		var htmlInputElement:HTMLInputElement = cast(rootElementRenderer.domNode);
		if (htmlInputElement.elementRenderer != null)
		{
			var textInputRenderer:TextInputRenderer = cast(htmlInputElement.elementRenderer);
			textInputRenderer.nativeTextInput.attach(graphicsContext);
		}
	}
	
	override public function detachGraphicsContext():Void
	{
		if (hasOwnGraphicsContext == true)
		{
			var htmlInputElement:HTMLInputElement = cast(rootElementRenderer.domNode);
			if (htmlInputElement.elementRenderer != null)
			{
				var textInputRenderer:TextInputRenderer = cast(htmlInputElement.elementRenderer);
				textInputRenderer.nativeTextInput.detach(graphicsContext);
			}
		}
		super.detachGraphicsContext();
	}
	
}