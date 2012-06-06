/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer;

import cocktail.core.geom.Matrix;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;

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
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//opacity
		computedStyle.opacity = style.opacity;
		
		//visibility
		computedStyle.visibility = getComputedVisibility(style);
		
		//overflow
		computedStyle.overflowX = style.overflowX;
		computedStyle.overflowY = style.overflowY;
		
		//transformOrigin
		computedStyle.transformOrigin = getComputedTransformOrigin(style);
		
		//transform
		computedStyle.transform = getComputedTransform(style);
		
		//transition-delay
		computedStyle.transitionDelay = getComputedTransitionDelay(style);
		
		//transition-property
		computedStyle.transitionProperty = style.transitionProperty;
		
		//transition-duration
		computedStyle.transitionDuration = getComputedTransitionDuration(style);
		
		//transition-timing-function
		computedStyle.transitionTimingFunction = style.transitionTimingFunction;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'transition-duration' style
	 */
	private static function getComputedTransitionDuration(style:CoreStyle):Array<Float>
	{
		var transitionDurations:Array<Float> = new Array<Float>();
		
		for (i in 0...style.transitionDuration.length)
		{
			switch (style.transitionDuration[i])
			{
				case TimeValue.seconds(value):
					transitionDurations.push(value);
					
				case TimeValue.milliSeconds(value):
					//convert to seconds
					transitionDurations.push(value / 1000);
			}
		}
		
		return transitionDurations;
		
	}
	
	/**
	 * Compute the 'transition-delay' style
	 */
	private static function getComputedTransitionDelay(style:CoreStyle):Array<Float>
	{
		var transitionDelays:Array<Float> = new Array<Float>();
		
		for (i in 0...style.transitionDelay.length)
		{
			switch (style.transitionDelay[i])
			{
				case TimeValue.seconds(value):
					transitionDelays.push(value);
					
				case TimeValue.milliSeconds(value):
					//convert to seconds
					transitionDelays.push(value / 1000);
			}
		}
		
		return transitionDelays;
	}
	
	/**
	 * Compute the 'visibility' style
	 */
	private static function getComputedVisibility(style:CoreStyle):Bool
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
	private static function getComputedTransformOrigin(style:CoreStyle):PointData
	{
		var x:Float;
		var y:Float;
		
		//x axis
		switch (style.transformOrigin.x)
		{
			case TransformOriginX.length(value):
				x = UnitManager.getPixelFromLength(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			case TransformOriginX.percent(value):
				x = UnitManager.getPixelFromPercent(value, style.computedStyle.width);
				
			case TransformOriginX.left:
				x = UnitManager.getPixelFromPercent(0, style.computedStyle.width);
				
			case TransformOriginX.center:
				x = UnitManager.getPixelFromPercent(50, style.computedStyle.width);	
				
			case TransformOriginX.right:
				x = UnitManager.getPixelFromPercent(100, style.computedStyle.width);		
		}
		
		//y axis
		switch (style.transformOrigin.y)
		{
			case TransformOriginY.length(value):
				y = UnitManager.getPixelFromLength(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			case TransformOriginY.percent(value):
				y = UnitManager.getPixelFromPercent(value, style.computedStyle.width);
				
			case TransformOriginY.top:
				y = UnitManager.getPixelFromPercent(0, style.computedStyle.width);
				
			case TransformOriginY.center:
				y = UnitManager.getPixelFromPercent(50, style.computedStyle.width);	
				
			case TransformOriginY.bottom:
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
	 * Compute a transformation matrix to apply to the htmlElement
	 * from the array of transform functions concatenated in order
	 */
	private static function getComputedTransform(style:CoreStyle):Matrix
	{
		var transformFunctions:Array<TransformFunction>;
		var transformOrigin:PointData = style.computedStyle.transformOrigin;
		
		//the matrix that will concatenate the transform functions
		var matrix:Matrix = new Matrix();
		
		//retrieve the transform functions or init an empty array
		switch (style.transform)
		{
			case Transform.transformFunctions(value):
				transformFunctions = value;
				
			case Transform.none:
				transformFunctions = new Array<TransformFunction>();
		}
		
		//apply each transform functions to the matrix in order
		for (i in 0...transformFunctions.length)
		{
			var transformFunction:TransformFunction = transformFunctions[i];
			
			switch (transformFunction)
			{
				//concatenate another matrix
				case TransformFunction.matrix(data):
					matrix.concatenate(new Matrix(data));
				
				//rotate	
				case TransformFunction.rotate(value):
					var angle:Float = Math.round(UnitManager.getRadFromAngle(value));
					matrix.rotate(angle, transformOrigin);
				
				//scale x and y	
				case TransformFunction.scale(sx, sys):
					matrix.scale(sx, sys, transformOrigin);
				
				//scale x	
				case TransformFunction.scaleX(sx):
					matrix.scale(sx, 1, transformOrigin);
				
				//scale y	
				case TransformFunction.scaleY(sy):
					matrix.scale(1, sy, transformOrigin);
				
				//skew x and y	
				case TransformFunction.skew(angleX, angleY):
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
					matrix.skew(skewX, skewY, transformOrigin);
				
				//skew x	
				case TransformFunction.skewX(angleX):
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					matrix.skew(skewX, 1, transformOrigin);
				
				//skew y	
				case TransformFunction.skewY(angleY):
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
					matrix.skew(1, skewY, transformOrigin);
				
				//translate x and y	
				case TransformFunction.translate(tx, ty):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width);
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height);
					matrix.translate(translationX, translationY);
				
				//translate x	
				case TransformFunction.translateX(tx):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width);
					matrix.translate(translationX, 0.0);
				
				//translate y	
				case TransformFunction.translateY(ty):
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height);
					matrix.translate(0.0, translationY);	
			}
		}
		
		return matrix;
	}
	
	/**
	 * Utils method to compute a TransformValue into a float
	 */
	private static function getComputedTranslation(style:CoreStyle, translation:Translation, percentReference:Int):Float
	{
		var computedTranslation:Float;
		
		switch (translation)
		{
			case Translation.length(value):
				computedTranslation = UnitManager.getPixelFromLength(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case Translation.percent(value):
				computedTranslation = UnitManager.getPixelFromPercent(value, percentReference);
		}
		
		return computedTranslation;
	}
	
}