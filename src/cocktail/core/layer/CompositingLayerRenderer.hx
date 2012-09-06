/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layer;

import cocktail.core.renderer.ElementRenderer;

/**
 * Compositing layer are used for elements 
 * which can't be redered by drawing bitmap,
 * for instance an hardware accelerated video
 * rendering is hadled by the GPU. It is
 * given a compositing layer so that it can
 * be integrated in the DOM
 * 
 * @author Yannick DOMINGUEZ
 */
class CompositingLayerRenderer extends LayerRenderer
{

	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	/**
	 * A compositing layer always has its own
	 * graphic context for compositing
	 */
	override private function establishesNewGraphicsContext():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	////////////////////////////////
	
	override public function isCompositingLayer():Bool
	{
		return true;
	}
	
	
}