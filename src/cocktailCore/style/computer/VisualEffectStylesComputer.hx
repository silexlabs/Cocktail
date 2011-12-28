/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer;

import cocktail.geom.Matrix;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.Style;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import cocktailCore.unit.UnitManager;

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
	 * target DOMElement
	 */
	public static function compute(style:AbstractStyle):Void
	{
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//opacity
		computedStyle.opacity = getComputedOpacity(style);
		
		//visibility
		computedStyle.visibility = getComputedVisibility(style);
		
		//transformOrigin
		computedStyle.transformOrigin = getComputedTransformOrigin(style);
		
		//transform
		computedStyle.transform = getComputedTransform(style);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'opacity' style.
	 */
	private static function getComputedOpacity(style:AbstractStyle):Float
	{
		var opacity:Float;
		
		switch (style.opacity)
		{
			case OpacityStyleValue.number(value):
				opacity = value;
		}
		
		return opacity;
	}
	
	/**
	 * Compute the 'visibility' style
	 */
	private static function getComputedVisibility(style:AbstractStyle):Bool
	{
		var visibility:Bool;
		
		switch(style.visibility)
		{
			case visible:
				visibility = true;
				
			case hidden:
				visibility = false;
		}
		
		return visibility;
	}
	
	/**
	 * Compute the transformation origin and returns it as a 2d point
	 * in pixel
	 */
	private static function getComputedTransformOrigin(style:AbstractStyle):PointData
	{
		var x:Float;
		var y:Float;
		
		//x axis
		switch (style.transformOrigin.x)
		{
			case TransformOriginXStyleValue.length(value):
				x = UnitManager.getPixelFromLengthValue(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			case TransformOriginXStyleValue.percent(value):
				x = UnitManager.getPixelFromPercent(value, style.computedStyle.width);
				
			case TransformOriginXStyleValue.left:
				x = UnitManager.getPixelFromPercent(0, style.computedStyle.width);
				
			case TransformOriginXStyleValue.center:
				x = UnitManager.getPixelFromPercent(50, style.computedStyle.width);	
				
			case TransformOriginXStyleValue.right:
				x = UnitManager.getPixelFromPercent(100, style.computedStyle.width);		
		}
		
		//y axis
		switch (style.transformOrigin.y)
		{
			case TransformOriginYStyleValue.length(value):
				y = UnitManager.getPixelFromLengthValue(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			case TransformOriginYStyleValue.percent(value):
				y = UnitManager.getPixelFromPercent(value, style.computedStyle.width);
				
			case TransformOriginYStyleValue.top:
				y = UnitManager.getPixelFromPercent(0, style.computedStyle.width);
				
			case TransformOriginYStyleValue.center:
				y = UnitManager.getPixelFromPercent(50, style.computedStyle.width);	
				
			case TransformOriginYStyleValue.bottom:
				y = UnitManager.getPixelFromPercent(100, style.computedStyle.width);			
		}
		
		//return the point
		var transformOriginPoint:PointData = {
			x:x,
			y:y
		}
		
		return transformOriginPoint;
	}
	
	/**
	 * Compute a transformation matrix to apply to the DOMElement
	 * from the array of transform functions concatenated in order
	 */
	private static function getComputedTransform(style:AbstractStyle):Matrix
	{
		var transformFunctions:Array<TransformFunctionValue>;
		var transformOrigin:PointData = style.computedStyle.transformOrigin;
		
		//the matrix that will concatenate the transform functions
		var matrix:Matrix = new Matrix();
		
		//retrieve the transform functions or init an empty array
		switch (style.transform)
		{
			case TransformStyleValue.transformFunctions(value):
				transformFunctions = value;
				
			case TransformStyleValue.none:
				transformFunctions = new Array<TransformFunctionValue>();
		}
		
		//apply each transform functions to the matrix in order
		for (i in 0...transformFunctions.length)
		{
			var transformFunction:TransformFunctionValue = transformFunctions[i];
			
			switch (transformFunction)
			{
				//concatenate another matrix
				case TransformFunctionValue.matrix(data):
					matrix.concatenate(new Matrix(data));
				
				//rotate	
				case TransformFunctionValue.rotate(value):
					var angle:Float = Math.round(UnitManager.getRadFromAngleValue(value));
					matrix.rotate(angle, transformOrigin);
				
				//scale x and y	
				case TransformFunctionValue.scale(sx, sys):
					matrix.scale(sx, sys, transformOrigin);
				
				//scale x	
				case TransformFunctionValue.scaleX(sx):
					matrix.scale(sx, 1, transformOrigin);
				
				//scale y	
				case TransformFunctionValue.scaleY(sy):
					matrix.scale(1, sy, transformOrigin);
				
				//skew x and y	
				case TransformFunctionValue.skew(angleX, angleY):
					var skewX:Float = UnitManager.getRadFromAngleValue(angleX);
					var skewY:Float = UnitManager.getRadFromAngleValue(angleY);
					matrix.skew(skewX, skewY, transformOrigin);
				
				//skew x	
				case TransformFunctionValue.skewX(angleX):
					var skewX:Float = UnitManager.getRadFromAngleValue(angleX);
					matrix.skew(skewX, 1, transformOrigin);
				
				//skew y	
				case TransformFunctionValue.skewY(angleY):
					var skewY:Float = UnitManager.getRadFromAngleValue(angleY);
					matrix.skew(1, skewY, transformOrigin);
				
				//translate x and y	
				case TransformFunctionValue.translate(tx, ty):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width);
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height);
					matrix.translate(translationX, translationY);
				
				//translate x	
				case TransformFunctionValue.translateX(tx):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width);
					matrix.translate(translationX, 0.0);
				
				//translate y	
				case TransformFunctionValue.translateY(ty):
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height);
					matrix.translate(0.0, translationY);	
			}
		}
		
		return matrix;
	}
	
	/**
	 * Utils method to compute a TransformValue into a float
	 */
	private static function getComputedTranslation(style:AbstractStyle, translation:TranslationValue, percentReference:Int):Float
	{
		var computedTranslation:Float;
		
		switch (translation)
		{
			case TranslationValue.length(value):
				computedTranslation = UnitManager.getPixelFromLengthValue(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case TranslationValue.percent(value):
				computedTranslation = UnitManager.getPixelFromPercent(value, percentReference);
		}
		
		return computedTranslation;
	}
	
}