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

import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;

/**
 * EmbeddedLineBoxes wrap an embedded element
 * when it is displayed on a line, such
 * as an image element with a display style of 'inline'
 * 
 * It also wrap inline-block elements starting new formatting
 * context
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
	override public function render(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		elementRenderer.render(graphicContext, clipRect, scrollOffset);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function isEmbedded():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * The ascent of an embedded inline box, is always
	 * equal to its ElementRenderer's margin box
	 * 
	 * TODO 3 : should add special case of inline-block whose
	 * ascent is its last line baseline if it establishes an inline
	 * formatting context
	 */
	override private function getLeadedAscent():Float 
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		return bounds.height + usedValues.marginTop + usedValues.marginBottom;
	}
	
	/**
	 * An embbeded line box don't have any descent
	 */
	override private function getLeadedDescent():Float
	{
		return 0;
	}
	
	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////

	/**
	 * Embedded Line boxes return the bounds of its embedded ElementRenderer
	 */
	override private function get_bounds():RectangleVO
	{
		return elementRenderer.bounds;
	}
}