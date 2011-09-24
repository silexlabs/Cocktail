/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement;

//////////////////////////////////////////////////////////////////////////////////////////
// Graphic DOMElement structures and enums
//////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Stores the corner radius values of a rounded rectangle
	 */
	typedef CornerRadiusData = {
		
		//top left
		var tlCornerRadius:Int;
		
		//top right
		var trCornerRadius:Int;
		
		//bottom left
		var blCornerRadius:Int;
		
		//bottom right
		var brCornerRadius:Int;
	}

	/**
	 * Contains the data for a color, which can be
	 * used in a monochrome or gradient fill.
	 */
	typedef ColorStopData = {
		
		//the value of the color
		var color:Int;
		
		//the alpha of the color, from 0 (transparent)
		//to 100 (opaque)
		var alpha:Int;
	}

	/**
	 * a unit element of a gradient. A gradient, is formed
	 * of multiple GradientStop
	 */
	typedef GradientStopData = {
		
		//a color info for this stop, containing the color value
		//and it's alpha
		var colorStop:ColorStopData;
		
		//the ratio of the stop from 0 (left) to 100 (right). For instance
		//if a gradient is formed of 3 GradientStop, the gradient will be
		//even if they have the ratios 0,50 and 100
		var ratio:Int;
	}

	/**
	 * the style of a line other than it's color/fill
	 */
	typedef LineStyleData =  {
		
		//the thickness of the line in pixels
		var thickness:Int;
		
		//the style of caps at the end of the line
		var capStyle:CapsStyleValue;
		
		//the style of joint at line intersection
		var jointStyle:JointStyleValue;
		
		//from flash documentation :
		//"A number that indicates the limit at which a miter is cut off"
		var miterLimit:Int;	
	}

	/**
	 * The data of a gradient fill
	 */
	typedef GradientStyleData = {
		
		//type of gradient
		var gradientType:GradientTypeValue;
		
		//all of the gradient stops (color + alpha and ratio)
		var gradientStops:Array<GradientStopData>;
		
		//global rotation of the gradient
		var rotation:Int;
	}
	
	/**
	 * defines an RGB color
	 */
	typedef RGB = {
		var red:Int;
		var green:Int;
		var blue:Int;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * The different styles which can be applied to a fill
	 */
	enum FillStyleValue {
		
		//no fill (transparent)
		none;
		
		//a fill with only one color with an alpha
		monochrome(colorStop:ColorStopData);
		
		//a gradient fill, with multiple colors each with their own alpha,
		//the gradient might be rotated
		gradient(gradientStyle:GradientStyleData);
		
		//a bitmap fill, created with the data of an image DOMElement.
		//The fill might be repeated (tiled)
		bitmap(imageDOMElement:DOMElement, repeat:Bool);
	}

	/**
	 * The different style which can be applied to a line/stroke
	 */
	enum LineStyleValue {
		
		//no line (transaparent
		none;
		
		//a line with only one color with an alpha
		monochrome(colorStop:ColorStopData, lineStyle:LineStyleData);
		
		//a gradient line, with multiple colors each with their own alpha,
		//the gradient might be rotated
		gradient(gradientStyle:GradientStyleData, lineStyle:LineStyleData);
		
		//a bitmap line, created with the data of an image DOMElement.
		//The line fill might be repeated (tiled)
		bitmap(imageDOMElement:DOMElement, lineStyle:LineStyleData, repeat:Bool);
	}

	/**
	 * The available types of gradient for a gradient fill.
	 */
	enum GradientTypeValue {
		linear;
		radial;
	}

	/**
	 * The available types of caps at the end of a drawn line.
	 */
	enum CapsStyleValue {
		none;
		square;
		round;
	}

	/**
	 * The available type of joint apparence, used at line angles.
	 */
	enum JointStyleValue {
		miter;
		round;
		bevel;
	}
	
//////////////////////////////////////////////////////////////////////////////////////////
// Styled DOMElement structures and enums
// lists all the supported styles for DOMElements
//////////////////////////////////////////////////////////////////////////////////////////	

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * List all the available styles
	 */
	typedef StyleData = {
		
		/**
		 * margins
		 */
		var marginLeft:MarginStyleValue;
		var marginRight:MarginStyleValue;
		var marginTop:MarginStyleValue;
		var marginBottom:MarginStyleValue;
		
		/**
		 * paddings
		 */
		var paddingLeft:PaddingStyleValue;
		var paddingRight:PaddingStyleValue;
		var paddingTop:PaddingStyleValue;
		var paddingBottom:PaddingStyleValue;
		
		/**
		 * The way a DOMElement flows in a document
		 */
		var display:DisplayStyleValue;
		
		/**
		 * The way a DOMElement position himself
		 * relative to a parent
		 */
		var position:PositionStyleValue;
		
		/**
		 * dimensions of a DOMElement
		 */
		var width:DimensionStyleValue;
		var height:DimensionStyleValue;
		
		/**
		 * dimensions constraint of a DOMElement
		 */
		var minHeight:ConstrainedDimensionStyleValue;
		var maxHeight:ConstrainedDimensionStyleValue;
		var minWidth:ConstrainedDimensionStyleValue;
		var maxWidth:ConstrainedDimensionStyleValue;
		
		/**
		 * offsets of a DOMElement
		 */
		var top:PositionOffsetStyleValue;
		var left:PositionOffsetStyleValue;
		var bottom:PositionOffsetStyleValue;
		var right:PositionOffsetStyleValue;
	}

	/**
	 * Represents the width and height of a DOMElement's
	 * parent content, into which it can be placed
	 */
	typedef ContainingDOMElementDimensions = {
		var width:Int;
		var height:Int;
	}
	
	/**
	 * Stores all of the dimensions used to 
	 * place a DOMElement
	 */
	typedef ComputedDOMElementDimensions = {
		var width:Int;
		var height:Int;
		var marginLeft:Int;
		var marginRight:Int;
		var marginTop:Int;
		var marginBottom:Int;
		var paddingLeft:Int;
		var paddingRight:Int;
		var paddingTop:Int;
		var paddingBottom:Int;
		var left:Int;
		var right:Int;
		var top:Int;
		var bottom:Int;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dimensions values for margin thickness
	 */
	enum MarginStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relatvie to the
		 * parent DOMElement's widthor height
		 */
		percent(value:Int);
		
		/**
		 * Margin takes the remaining space
		 * in the parent DOMElement width or height
		 */
		auto;
	}
	
	/**
	 * Dimensions value for padding thickness
	 */
	enum PaddingStyleValue {
		
		/**
		 * absolute thickness
		 */
		length(value:LengthValue);
		
		/**
		 * thickness relative to the
		 * parent DOMElement width or height
		 */
		percent(value:Int);
	}
	
	/**
	 * Display of a DOMElement in a 
	 * DOMElements flow
	 */
	enum DisplayStyleValue {
		
		/**
		 * add a line break before
		 * and after the DOMElement. Act
		 * as a box with margins, paddings
		 * and dimensions
		 */
		block;
		
		/**
		 * Displays as block but is placed
		 * on the current line in the flow
		 */
		inlineBlock;
		
		/**
		 * Displayed on the current line. 
		 * Doesn't have block's attributes
		 * such as margins, paddings...
		 */
		_inline;
		
		/**
		 * The DOMElement isn't displays
		 * and doesn't influence the flow
		 */
		none;
	}
	
	/**
	 * Determine how a DOMElement is positioned relative
	 * to its ancestors
	 */
	enum PositionStyleValue {
		
		/**
		 * Appear after its parent in the flow, on a
		 * new line or the current one based on its
		 * display
		 */
		_static;
		
		/**
		 * same as static but an offset can be applied
		 * with the top, left, right and bottom styles
		 * once the DOMElement is placed in the flow
		 */
		relative;
		
		/**
		 * The DOMElement is outside of the flow, it 
		 * is placed using its left, right, bottom and
		 * top offsets, its origin being its first ancestor
		 * with a position different from static
		 */
		absolute;
		
		/**
		 * The DOMElement is outside the flow, it
		 * is placed using its left, right, bottom
		 * and top offsets, its origin being the first
		 * DOMElement (the one at the top of the 
		 * hierarchy)
		 */
		fixed;
	}
	
	/**
	 * The offset applied to a DOMElement
	 * once positioned
	 */
	enum PositionOffsetStyleValue {
		
		/**
		 * absolute offset
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent
		 * DOMElement width or heigt
		 */
		percent(value:Int);
		
		/**
		 * no offset
		 */
		auto;
	}
	
	/**
	 * The dimension of the content of 
	 * a DOMElement (without margins 
	 * and paddings)
	 */
	enum DimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative the parent DOMElement
		 * dimensions
		 */
		percent(value:Int);
		
		/**
		 * takes the remaining space in
		 * the parent element width or 
		 * height
		 */
		auto;
	}
	
	/**
	 * The constraint applied to the content
	 * of a DOMElement contrained its max/min
	 * width or height
	 */
	enum ConstrainedDimensionStyleValue {
		
		/**
		 * absolute value
		 */
		length(value:LengthValue);
		
		/**
		 * relative to the parent DOMElement
		 * dimensions 
		 */
		percent(value:Int);
		
		/**
		 * No constraint is enforced
		 */
		none;
	}
	
	/**
	 * Lists the different types of 
	 * unit supported with an explicitly
	 * set length such as px, cm, em...
	 */
	enum LengthValue {
		
		/**
		 * a length defined in screen pixels
		 */
		pixel(value:Int);
	}