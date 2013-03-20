/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.core.geom.GeomData;
import cocktail.core.layer.InputLayerRenderer;
import cocktail.port.NativeButton;
import cocktail.port.NativeCheckbox;
import cocktail.port.NativeInput;

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
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	/**
	 * Instantiate a native button input
	 */
	override private function createNativeInput():Void
	{
		nativeInput = new NativeButton(domNode);
	}
}