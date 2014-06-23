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
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.geom.GeomData;
import cocktail.core.font.FontData;

/**
 * A subclass of Inline box, a space is similar to a TextInlineBox but lighter as 
 * it doesn't need to instantiate a native text display object,
 * its font metrics thanks to the spaceWidth attribute are sufficient for layout
 * 
 * @author Yannick DOMINGUEZ
 */
class SpaceInlineBox extends InlineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, leadedAscent:Float, leadedDescent:Float, spaceWidth:Float) 
	{
		super(elementRenderer, leadedAscent, leadedDescent);
		
		bounds.width = spaceWidth;
		bounds.height = leadedAscent + leadedDescent;
		
		isSpace = true;
		isText = true;
	}
}
