/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layout.computer;

import cocktail.geom.Matrix;

import cocktail.core.css.CoreStyle;
import cocktail.css.CSSStyleData;
import cocktail.core.layout.LayoutData;
import cocktail.geom.GeomData;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.font.FontData;

/**
 * This is a static class in charge of
 * computing the visual effect styles
 * 
 * @author Yannick DOMINGUEZ
 */
class VisualEffectStylesComputer 
{
	/**
	 * Class contructor. Private, as
	 * this class is meant to be accessed
	 * through its public static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute all the visual effect styles
	 * 
	 * @param	style contain the styles definition of the 
	 * target htmlElement
	 */
	public static function compute(style:CoreStyle):Void
	{
		//transformOrigin
		style.usedValues.transformOrigin = getComputedTransformOrigin(style);
		
		//transform
		style.usedValues.transform = getComputedTransform(style);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the transformation origin and returns it as a 2d point
	 * in pixel
	 */
	private static function getComputedTransformOrigin(style:CoreStyle):PointVO
	{
		var x:Float = 0.0;
		var y:Float = 0.0;
		
		var transformOriginX:CSSPropertyValue = null;
		var transformOriginY:CSSPropertyValue = null;
		
		switch(style.transformOrigin)
		{
			case GROUP(value):
				transformOriginX = value[0];
				transformOriginY = value[1];
				
			default:	
				
		}
		
		//x axis
		switch (transformOriginX)
		{
			case ABSOLUTE_LENGTH(value):
				x = value;
			
			case PERCENTAGE(value):
				x = CSSValueConverter.getPixelFromPercent(value, style.usedValues.width);
				
			case KEYWORD(value):
				switch(value)
				{
					case LEFT:
						x = CSSValueConverter.getPixelFromPercent(0, style.usedValues.width);
						
					case CENTER:	
						x = CSSValueConverter.getPixelFromPercent(50, style.usedValues.width);	
						
					case RIGHT:
						x = CSSValueConverter.getPixelFromPercent(100, style.usedValues.width);
						
					default:	
				}
				
			default:
					
		}
		
		//y axis
		switch (transformOriginY)
		{
			case ABSOLUTE_LENGTH(value):
				y = value;
			
			case PERCENTAGE(value):
				y = CSSValueConverter.getPixelFromPercent(value, style.usedValues.width);
				
			case KEYWORD(value):
				switch(value)
				{
					case TOP:
						y = CSSValueConverter.getPixelFromPercent(0, style.usedValues.width);
						
					case CENTER:	
						y = CSSValueConverter.getPixelFromPercent(50, style.usedValues.width);	
						
					case BOTTOM:
						y = CSSValueConverter.getPixelFromPercent(100, style.usedValues.width);
						
					default:	
				}
				
			default:
					
		}
		
		//return the point
		var transformOriginPoint:PointVO = new PointVO(x, y);
		
		return transformOriginPoint;
	}
	
	/**
	 * Compute a transformation matrix to apply to the htmlElement
	 * from the array of transform functions concatenated in order
	 */
	private static function getComputedTransform(style:CoreStyle):Matrix
	{
		//early return if no transforms are applied, return
		//an identity matrix
		if (style.isNone(style.transform))
		{
			return new Matrix();
		}
		
		//the matrix that will concatenate the transform functions
		var matrix:Matrix = new Matrix();
		
		var transformFunctions:Array<CSSTransformFunctionValue> = new Array<CSSTransformFunctionValue>();
		var transformOrigin:PointVO = style.usedValues.transformOrigin;
		
		//retrieve the transform functions
		switch (style.transform)
		{
			case CSS_LIST(value):
				for (i in 0...value.length)
				{
					switch(value[i])
					{
						case TRANSFORM_FUNCTION(value):
							transformFunctions.push(value);
							
						default:	
					}
				}
			case TRANSFORM_FUNCTION(value):
				transformFunctions.push(value);
				
			default:		
		}
		
		//translate the matrix to the coordinate system of the 
		//transformation origin
		matrix.translate(transformOrigin.x, transformOrigin.y);
		
		//apply each transform functions to the matrix in order
		for (i in 0...transformFunctions.length)
		{
			var transformFunction:CSSTransformFunctionValue = transformFunctions[i];
			
			switch (transformFunction)
			{
				//concatenate another matrix
				case MATRIX(a, b ,c, d, e, f):
					matrix.concatenate(new Matrix(a, b, c, d, e, f));
				
				//rotate	
				case ROTATE(value):
					var angle:Float = getRadFromAngle(value);
					matrix.rotate(angle);
				
				//scale x and y	
				case SCALE(sx, sy):
					matrix.scale(sx, sy);
				
				//scale x	
				case SCALE_X(sx):
					matrix.scale(sx, 1);
				
				//scale y	
				case SCALE_Y(sy):
					matrix.scale(1, sy);
				
				//skew x and y	
				case SKEW(angleX, angleY):
					var skewX:Float = getRadFromAngle(angleX);
					var skewY:Float = getRadFromAngle(angleY);
					matrix.skew(skewX, skewY);
				
				//skew x	
				case SKEW_X(angleX):
					var skewX:Float = getRadFromAngle(angleX);
					matrix.skew(skewX, 0);
				
				//skew y	
				case SKEW_Y(angleY):
					var skewY:Float = getRadFromAngle(angleY);
					matrix.skew(0, skewY);
				
				//translate x and y	
				case TRANSLATE(tx, ty):
					var translationX:Float = getComputedTranslation(style, tx, style.usedValues.width);
					var translationY:Float = getComputedTranslation(style, ty, style.usedValues.height);
					matrix.translate(translationX, translationY);
				
				//translate x	
				case TRANSLATE_X(tx):
					var translationX:Float = getComputedTranslation(style, tx, style.usedValues.width);
					matrix.translate(translationX, 0.0);
				
				//translate y	
				case TRANSLATE_Y(ty):
					var translationY:Float = getComputedTranslation(style, ty, style.usedValues.height);
					matrix.translate(0.0, translationY);	
			}
		}
		
		//translate the matrix back from the coordinate system of the 
		//transformation origin
		matrix.translate(transformOrigin.x * -1, transformOrigin.y * -1);
		
		return matrix;
	}
	
	/**
	 * Utils method to compute a TransformValue into a float
	 */
	private static function getComputedTranslation(style:CoreStyle, translation:CSSTranslationValue, percentReference:Float):Float
	{
		var computedTranslation:Float = 0.0;
		
		switch (translation)
		{
			case ABSOLUTE_LENGTH(value):
				computedTranslation = value;
				
			case PERCENTAGE(value):
				computedTranslation = CSSValueConverter.getPixelFromPercent(value, percentReference);
				
			default:	
		}
		
		return computedTranslation;
	}
	
	/**
	 * Get a radian angle from any other angle value
	 */
	public static function getRadFromAngle(value:CSSAngleValue):Float
	{
		var angle:Float;
		
		switch (value)
		{
			case DEG(value):
				angle = value * (Math.PI / 180);
				
			case RAD(value):
				angle = value;
				
			case TURN(value):
				angle = (value * 360) * (Math.PI / 180);
				
			case GRAD(value):	
				angle = value * (Math.PI / 200);
		}
		
		return angle;
	}
	
}
