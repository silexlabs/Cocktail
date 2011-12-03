/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style;
import cocktail.domElement.DOMElement;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Represents the width, height of a DOMElement's
	 * parent content, and it's global position, relative
	 * to the root DOMElement.
	 * Specify for each dimension if it is 'auto', 
	 * meaning it depends on its content
	 */
	typedef ContainingDOMElementData = {
		var width:Int;
		var isWidthAuto:Bool;
		var height:Int;
		var isHeightAuto:Bool;
		var globalX:Int;
		var globalY:Int;
	}
	
	/**
	 * Stores all the computed styles
	 * of a DOMElement as they are 
	 * used multiple times when applying
	 * styles
	 */
	typedef ComputedStyleData = {
		
		/**
		 * content dimensions
		 */
		var width:Int;
		var height:Int;
		
		/**
		 * content dimensions constraints
		 */
		var minWidth:Int;
		var maxWidth:Int;
		var maxHeight:Int;
		var minHeight:Int;
		
		/**
		 * margins
		 */
		var marginLeft:Int;
		var marginRight:Int;
		var marginTop:Int;
		var marginBottom:Int;
		
		/**
		 * paddings
		 */
		var paddingLeft:Int;
		var paddingRight:Int;
		var paddingTop:Int;
		var paddingBottom:Int;
		
		/**
		 * position offset
		 */
		var left:Int;
		var right:Int;
		var top:Int;
		var bottom:Int;
		
		/**
		 * display
		 */
		var display:DisplayStyleValue;
		var float:FloatStyleValue;
		var clear:ClearStyleValue;
		var position:PositionStyleValue;
		var lineHeight:Float;
		
		/**
		 * font
		 */
		var fontSize:Float;
		var fontWeight:FontWeightStyleValue;
		var fontStyle:FontStyleStyleValue;
		var fontFamily:Array<FontFamilyStyleValue>;
		var fontVariant:FontVariantStyleValue;
		
		/**
		 * text
		 */
		var textTransform:TextTransformStyleValue;
		var letterSpacing:Int;
		var verticalAlign:Float;
		var wordSpacing:Int;
		var textIndent:Int;
		var whiteSpace:WhiteSpaceStyleValue;
		var textAlign:TextAlignStyleValue;
		var color:Int;
		
	}
	
	/**
	 * Contains the data necessary to place
	 * a DOMElement in flow
	 */
	typedef FlowData = {
		/**
		 * the x position where the next in flow DOMElement
		 * should be
		 */
		var x:Int;
		
		/**
		 * the y position where the next in flow DOMElement
		 * should be
		 */
		var y:Int;
		
		/**
		 * The x offset applied to each starting line
		 * (matches the containing DOMElement left padding)
		 */
		var xOffset:Int;
		
		/**
		 * The y offset applied to the formatting context
		 * (matches the containing DOMElement top padding)
		 */
		var yOffset:Int;
		
		/**
		 * Determine the largest width of a line in
		 * a formatting context
		 */
		var maxWidth:Int;
		
		/**
		 * The accumulated height of all the in flow DOMElements
		 * (includes paddings and margins)
		 */
		var totalHeight:Int;
	}
	
	/**
	 * Represents the left and right
	 * floats registered for a 
	 * container DOMElement
	 */
	typedef FloatsData = {
		var left:Array<FloatData>;
		var right:Array<FloatData>;
	}
	
	/**
	 * Represents the coordinates and
	 * dimensions of the float in its
	 * parent coordinate space
	 */
	typedef FloatData = {
		var x:Int;
		var y:Int;
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Given a font family and a font size
	 * provided by the DOMElement's styles, 
	 * this structures return metrics info
	 * on the font
	 */
	typedef FontMetricsData = {
		
		/**
		 * The font size of 
		 * the DOMElement, in pixels
		 */
		var fontSize:Float;
		
		/**
		 * A characteristic height
		 * of the font above the 
		 * baseline defined by
		 * the font creator. This is a metric
		 * for the font has a whole, 
		 * not specific to any glyphs
		 */
		var ascent:Int;
		
		/**
		 * A characteristic height
		 * of the font below the 
		 * baseline defined by
		 * the font creator. This is a metric
		 * for the font has a whole, 
		 * not specific to any glyphs
		 */
		var descent:Int;
		
		/**
		 * This is a standard metrics used 
		 * to define a font size. Represents
		 * the height of a lowercase "x" glyph
		 * at the given font size
		 */ 
		var xHeight:Int;
		
		/**
		 * A suggested offset to apply
		 * from the baseline for subscript
		 * glyphs
		 */
		var subscriptOffset:Int;
		
		/**
		 * A suggested offset to apply
		 * from the baseline for superscript
		 * glyphs
		 */
		var superscriptOffset:Int;
		
		/**
		 * A suggested offset to apply from
		 * the baseline when drawing underlines
		 */
		var underlineOffset:Int;
		
		/**
		 * the width of a space character for
		 * a given font at a given size
		 */
		var spaceWidth:Int;
	}
	
	/**
	 * Defines a DOMElement added to a LineBox
	 * and its type
	 */
	typedef LineBoxElementData = {
		var domElement:DOMElement;
		var domElementType:InlineBoxValue;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lists the different kind of
	 * boxes that can be added in an
	 * inline formatting context.
	 * 
	 * Spaces and tabs are separated
	 * from other domElement as they
	 * can influence a linebox layout
	 * once it is complete
	 */
	enum InlineBoxValue {
		domElement;
		space;
		tab;
	}