/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.computer;

import cocktail.core.geom.Matrix;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;

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
	private static function getComputedTransformOrigin(style:CoreStyle):PointData
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
				x = UnitManager.getPixelFromPercent(value, style.usedValues.width);
				
			case KEYWORD(value):
				switch(value)
				{
					case LEFT:
						x = UnitManager.getPixelFromPercent(0, style.usedValues.width);
						
					case CENTER:	
						x = UnitManager.getPixelFromPercent(50, style.usedValues.width);	
						
					case RIGHT:
						x = UnitManager.getPixelFromPercent(100, style.usedValues.width);
						
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
				y = UnitManager.getPixelFromPercent(value, style.usedValues.width);
				
			case KEYWORD(value):
				switch(value)
				{
					case TOP:
						y = UnitManager.getPixelFromPercent(0, style.usedValues.width);
						
					case CENTER:	
						y = UnitManager.getPixelFromPercent(50, style.usedValues.width);	
						
					case BOTTOM:
						y = UnitManager.getPixelFromPercent(100, style.usedValues.width);
						
					default:	
				}
				
			default:
					
		}
		
		//return the point
		var transformOriginPoint:PointData = {
			x:x,
			y:y
		}
		
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
		var transformOrigin:PointData = style.usedValues.transformOrigin;
		
		//retrieve the transform functions
		switch (style.transform)
		{
			case GROUP(value):
				for (i in 0...value.length)
				{
					switch(value[i])
					{
						case TRANSFORM_FUNCTION(value):
							transformFunctions.push(value);
							
						default:	
					}
				}
				
				
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
				case MATRIX(data):
					matrix.concatenate(new Matrix(data));
				
				//rotate	
				case ROTATE(value):
					var angle:Float = UnitManager.getRadFromAngle(value);
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
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
					matrix.skew(skewX, skewY);
				
				//skew x	
				case SKEW_X(angleX):
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					matrix.skew(skewX, 0);
				
				//skew y	
				case SKEW_Y(angleY):
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
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
				computedTranslation = UnitManager.getPixelFromPercent(value, percentReference);
				
			default:	
		}
		
		return computedTranslation;
	}
	
}