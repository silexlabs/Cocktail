/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.renderer.ElementRenderer;

import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
/**
 * A subclass of TextLineBox, a space is lighter as 
 * it doesn't need to instantiate a native text display object,
 * its font metrics thanks to the spaceWidth attribute are sufficient for layout
 * 
 * @author Yannick DOMINGUEZ
 */
class SpaceLineBox extends TextLineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, fontMetrics:FontMetricsVO, fontManager:FontManager) 
	{
		super(elementRenderer, "", fontMetrics, null);
	}
	
	/**
	 * Don't need to create a native text element for space
	 */ 
	override private function initNativeTextElement(text:String, fontManager:FontManager, style:CoreStyle):Void
	{
		
	}
	
	/**
	 * as there is no text element, there is no bitmap data
	 */
	override private function initTextBitmap():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Spaces don't need to be rendered
	 */
	override public function render(graphicContext:GraphicsContext):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function isSpace():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the space width using the font metrics
	 */
	override private function getTextWidth():Float
	{
		//the width of a space is retrieved from the font metrics, plus the letter spacing
		//which also apply to space and the word spacing which applies only to space
		var letterSpacing:Float = elementRenderer.coreStyle.usedValues.letterSpacing;
		var wordSpacing:Float = elementRenderer.coreStyle.getAbsoluteLength(elementRenderer.coreStyle.wordSpacing);
		return _fontMetrics.spaceWidth + letterSpacing + wordSpacing;
	}
}