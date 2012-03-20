/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement;

import core.dom.HTMLImageElement;
import core.Style;
import core.unit.UnitData;

//////////////////////////////////////////////////////////////////////////////////////////
// Container DOMElement structures and enums
//////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * ContainerDOMElement can have both DOMElement and TextElement
	 * as children. This structures holds of reference to the
	 * children and to its type
	 */
	typedef ContainerDOMElementChildData = {
		var child:Dynamic;
		var type:ContainerDOMElementChildValue;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The types of children a ContainerDOMElement
	 * can have
	 */
	enum ContainerDOMElementChildValue {
		domElement;
		textElement;
	}
	
//////////////////////////////////////////////////////////////////////////////////////////
// DOMElement Structures
//////////////////////////////////////////////////////////////////////////////////////////

/**
	 * When a DOMElement's content is scrolled,
	 * the scroll event contains the corresponding
	 * scroll metrics
	 * 
	 * TODO : move into its own module ?
	 */
typedef ScrollEventData = {
		
		/**
		 * the distance from the top
		 * of the DOMElement to the top
		 * of its displayed content
		 */
		var scrollTop:Int;
		
		/**
		 * the distance from the left
		 * of the DOMElement and the left
		 * of its displayed content
		 */
		var scrollLeft:Int;
		
		/**
		 * the width of the currently displayed
		 * area of the DOMElement
		 */
		var scrollWidth:Int;
		
		/**
		 * the height of the currently displayed
		 * area of the DOMElement
		 */
		var scrollHeight:Int;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Link DOMElement enums
//////////////////////////////////////////////////////////////////////////////////////////

/**
	 * Specifies where to open the linked document
	 */
enum LinkTargetValue {
		
		/**
		 * Opens the linked document in a new window or tab
		 */
		blank;
		
		/**
		 * Opens the linked document in the same frame as it was clicked (this is default)
		 */
		self;
		
		/**
		 * Opens the linked document in the parent frame
		 */
		parent;
		
		/**
		 * Opens the linked document in the full body of the window
		 */
		top;
}

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
		 * a unit element of a gradient. A gradient, is formed
		 * of multiple GradientStop
		 */
		typedef GradientStopData = {
			
			//a color info for this stop, containing the color value
			//and it's alpha
			var colorStop:ColorData;
			
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
		typedef RGBData = {
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
			monochrome(colorStop:ColorData);
			
			//a gradient fill, with multiple colors each with their own alpha,
			//the gradient might be rotated
			gradient(gradientStyle:GradientStyleData);
			
			//a bitmap fill, created with the data of an image DOMElement.
			//The fill might be repeated (tiled)
			bitmap(htmlImageElement:HTMLImageElement, repeat:Bool);
		}

		/**
		 * The different style which can be applied to a line/stroke
		 */
		enum LineStyleValue {
			
			//no line (transaparent
			none;
			
			//a line with only one color with an alpha
			monochrome(color:ColorData, lineStyle:LineStyleData);
			
			//a gradient line, with multiple colors each with their own alpha,
			//the gradient might be rotated
			gradient(gradientStyle:GradientStyleData, lineStyle:LineStyleData);
			
			//a bitmap line, created with the data of an image DOMElement.
			//The line fill might be repeated (tiled)
			bitmap(htmlImageElement:HTMLImageElement, lineStyle:LineStyleData, repeat:Bool);
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
	
