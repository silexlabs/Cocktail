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
import cocktail.core.geom.GeomData;

/**
 * This line box is used as a place holder for absolutely
 * positioned elements, to determine their static position
 * when formatting an inline formatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class StaticPositionLineBox extends LineBox
{
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}

	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHOD
	////////////////////////////////

	override public function isStaticPosition():Bool
	{
		return true;
	}

	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////

	/**
	 * Return the bounds of the absolutely positioned
	 * element, so that its static bounds can be set
	 * during formatting
	 */
	override private function get_bounds():RectangleData
	{
		return elementRenderer.bounds;
	}

}