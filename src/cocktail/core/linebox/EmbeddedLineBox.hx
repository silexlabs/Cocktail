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
import cocktail.core.style.ComputedStyle;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * EmbeddedLineBoxes wrap an embedded element
 * when it is displayed on a line, such
 * as an image element with a display style of 'inline'
 * 
 * Those embedded ElementRenderer only have one line box
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedLineBox extends LineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Embeded LineBoxes defer rendering to their ElementRenderer
	 */
	override public function render(graphicContext:NativeElement, forceRendering:Bool):Void
	{
		elementRenderer.render(graphicContext, forceRendering);
	}
	
	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////
	
	/**
	 * The ascent of an embedded inline box, is always
	 * equal to its ElementRenderer's margin box
	 */
	override private function get_leadedAscent():Float 
	{
		var computedStyle:ComputedStyle = elementRenderer.coreStyle.computedStyle;
		return bounds.height + computedStyle.marginTop + computedStyle.marginBottom;
	}
	
	/**
	 * An embbeded line box don't have any descent
	 */
	override private function get_leadedDescent():Float
	{
		return 0.0;
	}
	
	/**
	 * Embedded Line boxes return the bounds of its embedded ElementRenderer
	 */
	override private function get_bounds():RectangleData
	{
		return elementRenderer.bounds;
	}
}