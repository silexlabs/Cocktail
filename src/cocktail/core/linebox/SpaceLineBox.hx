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
import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
/**
 * A subclass of TextLineBox, a space is lighter as 
 * it doesn't need to instantiate a native text display object,
 * its font metrics are sufficient for layout
 * 
 * @author Yannick DOMINGUEZ
 */
class SpaceLineBox extends TextLineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, fontMetrics:FontMetricsData, fontManager:FontManager) 
	{
		super(elementRenderer, "", fontMetrics, null);
	}
	
	/**
	 * Don't need to create a native text element for space
	 */ 
	override private function initNativeTextElement(text:String, fontManager:FontManager, computedStyle:ComputedStyle):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Spaces don't need to be rendered
	 */
	override public function render(graphicContext:NativeElement, forceRendering:Bool):Void
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
		return _fontMetrics.spaceWidth;
	}
}