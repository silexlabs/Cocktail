/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.css.CoreStyle;
import cocktail.core.geom.GeomData;

/**
 * A special kind of line box which represents
 * the start of a line in an inline formatting context.
 * 
 * Each line is stored as a tree of line boxes started
 * by a RootLineBox
 * 
 * @author Yannick DOMINGUEZ
 */
class RootLineBox extends LineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The bounds of a root line box is the bounds
	 * of all of its child line boxes
	 */
	override private function get_bounds():RectangleVO
	{
		//TODO 3 : shouldn'thave to update bounds each time
		getLineBoxesBounds(this, bounds);
		return bounds;
	}
}