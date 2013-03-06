/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.port.NativeElement;
import cocktail.core.renderer.TextLineBox;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.unit.UnitData;


/**
 * ...
 * @author Yannick DOMINGUEZ
 */

/**
 * TODO 5 : obsolete, should now use the Canvas API
 * TODO 2 : is in the wrong package
 */
//////////////////////////////////////////////////////////////////////////////////////////
// Graphic HTMLElement structures and enums
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
			
			//a bitmap fill, created with the data of an image htmlElement.
			//The fill might be repeated (tiled)
			bitmap(nativeElement:NativeElement, repeat:Bool);
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
			
			//a bitmap line, created with the data of an image htmlElement.
			//The line fill might be repeated (tiled)
			bitmap(nativeElement:NativeElement, lineStyle:LineStyleData, repeat:Bool);
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
	