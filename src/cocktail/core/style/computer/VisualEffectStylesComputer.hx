/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.style.computer;

import cocktail.core.geom.Matrix;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;
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
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyle = style.computedStyle;
		var fontMetrics:FontMetricsData = style.fontMetrics;
		
		//transformOrigin
		computedStyle.transformOrigin = getComputedTransformOrigin(style, fontMetrics);
		
		//transform
		computedStyle.transform = getComputedTransform(style, fontMetrics);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the transformation origin and returns it as a 2d point
	 * in pixel
	 */
	private static function getComputedTransformOrigin(style:CoreStyle, fontMetrics:FontMetricsData):PointData
	{
		var x:Float;
		var y:Float;
		
		//x axis
		switch (style.transformOrigin.x)
		{
			case TransformOriginX.length(value):
				x = UnitManager.getPixelFromLength(value, fontMetrics.fontSize, fontMetrics.xHeight);
			
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
				y = UnitManager.getPixelFromLength(value, fontMetrics.fontSize, fontMetrics.xHeight);
			
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
	private static function getComputedTransform(style:CoreStyle, fontMetrics:FontMetricsData):Matrix
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
		
		//translate the matrix to the coordinate system of the 
		//transformation origin
		matrix.translate(transformOrigin.x, transformOrigin.y);
		
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
					var angle:Float = UnitManager.getRadFromAngle(value);
					matrix.rotate(angle);
				
				//scale x and y	
				case TransformFunction.scale(sx, sy):
					matrix.scale(sx, sy);
				
				//scale x	
				case TransformFunction.scaleX(sx):
					matrix.scale(sx, 1);
				
				//scale y	
				case TransformFunction.scaleY(sy):
					matrix.scale(1, sy);
				
				//skew x and y	
				case TransformFunction.skew(angleX, angleY):
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
					matrix.skew(skewX, skewY);
				
				//skew x	
				case TransformFunction.skewX(angleX):
					var skewX:Float = UnitManager.getRadFromAngle(angleX);
					matrix.skew(skewX, 0);
				
				//skew y	
				case TransformFunction.skewY(angleY):
					var skewY:Float = UnitManager.getRadFromAngle(angleY);
					matrix.skew(0, skewY);
				
				//translate x and y	
				case TransformFunction.translate(tx, ty):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width, fontMetrics);
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height, fontMetrics);
					matrix.translate(translationX, translationY);
				
				//translate x	
				case TransformFunction.translateX(tx):
					var translationX:Float = getComputedTranslation(style, tx, style.computedStyle.width, fontMetrics);
					matrix.translate(translationX, 0.0);
				
				//translate y	
				case TransformFunction.translateY(ty):
					var translationY:Float = getComputedTranslation(style, ty, style.computedStyle.height, fontMetrics);
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
	private static function getComputedTranslation(style:CoreStyle, translation:Translation, percentReference:Float, fontMetrics:FontMetricsData):Float
	{
		var computedTranslation:Float;
		
		switch (translation)
		{
			case Translation.length(value):
				computedTranslation = UnitManager.getPixelFromLength(value, fontMetrics.fontSize, fontMetrics.xHeight);
				
			case Translation.percent(value):
				computedTranslation = UnitManager.getPixelFromPercent(value, percentReference);
		}
		
		return computedTranslation;
	}
	
}