 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLElement;
import cocktail.port.NativeElement;
import cocktail.core.background.BackgroundManager;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.style.computer.DisplayStylesComputer;
import cocktail.core.style.computer.FontAndTextStylesComputer;
import cocktail.core.style.computer.VisualEffectStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.formatter.InlineFormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import cocktail.core.unit.UnitManager;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * Base class for box renderers. A box renderer
 * is a visual element which conforms to the
 * CSS box model. This base class is used by
 * both replaced box (image...) and container box
 * (block box, inline box)
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxRenderer extends ElementRenderer
{
	
	/**
	 * A graphic context object onto which this ElementRenderer
	 * is painted
	 */
	public var graphicsContext(default, null):NativeElement;
	
	public var childrenGraphicsContext(default, null):NativeElement;
	
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		
		#if (flash9 || nme)
		graphicsContext = new flash.display.Sprite();
		childrenGraphicsContext = new flash.display.Sprite();
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to render elements spefic to a box (background, border...)
	 * TODO 4 : apply visibility
	 */
	override public function render(parentGraphicContext:NativeElement, forceRendering:Bool):Void
	{
		
		//get the relative offset of this ElementRenderer and add it to
		//its parent
		
		if (_needsRendering == true || forceRendering == true)
		{
			clear(graphicsContext);
			renderSelf(graphicsContext);
			_needsRendering = false;
		}
		
		//if (_childrenNeedRendering == true || forceRendering == true)
		//{
			clear(childrenGraphicsContext);
			renderChildren(childrenGraphicsContext, forceRendering == true || _childrenNeedRendering == true);
			_childrenNeedRendering = false;
		//}
		
		#if (flash9 || nme)
		var selfGraphicContext:flash.display.DisplayObjectContainer = cast(graphicsContext);
		selfGraphicContext.addChild(childrenGraphicsContext);
		#end
	
		
		//if (_needsVisualEffectsRendering == true)
		//{
			applyVisualEffects(graphicsContext);
		//}
		_needsVisualEffectsRendering = false;
		
		
		//draws the graphic context of this block box on the one of its
		//parent
		#if (flash9 || nme)
		
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(parentGraphicContext);
		containerGraphicContext.addChild(graphicsContext);
		#end
	}
	
	public function scroll(x:Float, y:Float):Void
	{
		if (computedStyle.position == fixed)
		{
			#if (flash9 || nme)
		{
			graphicsContext.x = x;
			graphicsContext.y = y;
		}
		#end
		
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function renderSelf(graphicContext:NativeElement):Void
	{
		renderBackground(graphicContext);
	}
	
	/**
	 * Clears the content of the graphic
	 * context of this ElementRenderer
	 */
	private function clear(graphicsContext:NativeElement):Void
	{
		#if (flash9 || nme)
		var containerGraphicsContext:flash.display.DisplayObjectContainer = cast(graphicsContext);
			var length:Int = containerGraphicsContext.numChildren;
			for (i in 0...length)
			{
				containerGraphicsContext.removeChildAt(0);
			}
		#end	
	}
	
	/**
	 * Render the background of the box using the provided graphic context
	 */
	private function renderBackground(graphicContext:NativeElement):Void
	{

		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO 4 : update doc for this
		_coreStyle.computeBackgroundStyles();
		
		var backgroundManager:BackgroundManager = new BackgroundManager(this);
		
		var backgroundBounds:RectangleData = getBackgroundBounds();
		
		//TODO 3 : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = backgroundManager.render(backgroundBounds, _coreStyle);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		var length:Int = backgrounds.length;

		for (i in 0...length)
		{
			backgrounds[i].x = backgroundBounds.x;
			backgrounds[i].y = backgroundBounds.y;
			containerGraphicContext.addChild(backgrounds[i]);
		}
		#end
	}
	
	/**
	 * Render the children of the box
	 */
	private function renderChildren(graphicContext:NativeElement, forceRendering:Bool):Void
	{
		//abstract
	}
	
	/**
	 * Apply the computed visual effect
	 * using the graphic context
	 */
	private function applyVisualEffects(graphicContext:NativeElement):Void
	{
		//when all the dimensions of the ElementRenderer are known, compute the 
		//visual effects to apply (visibility, opacity, transform, transition)
		//it is necessary to wait for all dimensions to be known because for
		//instance the transform style use the height and width of the ElementRenderer
		//to determine the transformation center
		//
		//TODO 2 : update doc
		
		
		applyOpacity(graphicContext);
		
		//apply only if the element is either relative positioned or has
		//transformations functions
		if (isRelativePositioned() == true || _coreStyle.transform != Transform.none)
		{
			//TODO 2 : should ony compute transform and transform-origin, anything
			//else can be done before layout
			_coreStyle.computeVisualEffectStyles();
			
			applyTransformationMatrix(graphicContext);
		}
		
	}
	
	/**
	 * Apply both the transformation matrix computed with the
	 * transform and transform-origin style and the relative
	 * offset if the element is relative positioned
	 */
	private function applyTransformationMatrix(graphicContext:NativeElement):Void
	{
		var relativeOffset:PointData = getRelativeOffset();
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(computedStyle.transform, relativeOffset);
		
		//apply relative positioning as well
		concatenatedMatrix.translate(relativeOffset.x, relativeOffset.y);
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = concatenatedMatrix.data;
		#if (flash9 || nme)
		//create a native flash matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
		//apply the native flash matrix to the native flash DisplayObject
		graphicContext.transform.matrix = nativeTransformMatrix;
		#end
	}
	
	/**
	 * Apply the computed opacity to the graphic context
	 */ 
	private function applyOpacity(graphicContext:NativeElement):Void
	{
		#if (flash9 || nme)
		graphicContext.alpha = computedStyle.opacity;
		#end
	}
	
	/**
	 * Concatenate the transformation matrix obtained with the
	 * transform and transform-origin styles with the current
	 * transformations applied to the box renderer, such as for 
	 * instance its position in the global space, or the transformation
	 * applied via a relative offset
	 * 
	 */
	private function getConcatenatedMatrix(matrix:Matrix, relativeOffset:PointData):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		var globalBounds:RectangleData = globalBounds;
		
		//translate to the coordiante system of the box renderer
		currentMatrix.translate(globalBounds.x + relativeOffset.x, globalBounds.y + relativeOffset.y);
		
		currentMatrix.concatenate(matrix);
		
		//translate backe from the coordiante system of the box renderer
		currentMatrix.translate((globalBounds.x + relativeOffset.x) * -1, (globalBounds.y + relativeOffset.y) * -1);
		return currentMatrix;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is in charge of laying out an ElementRenderer which consist 
	 * in computing its styles (box model, font, text...) into usable values and determining its 
	 * bounds in the space of the containing block which started its formatting context.
	 */
	override public function layout(forceLayout:Bool):Void
	{	
		if (_needsLayout == true || forceLayout == true)
		{
			layoutSelf();
			_needsLayout = false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the ElementRenderer needs to lays itself out,
	 * meanng its must compute its dimensions
	 */
	private function layoutSelf():Void
	{
		//get the dimensions and font metrics of the containing block of this 
		//element which are necesseray to compute the styles of this ElementRenderer
		//into usable value. For instance, a with defined as a percentage will compute
		//to a percentage of the containing block width
		var containingBlockData:ContainingBlockData = _containingBlock.getContainerBlockData();
		var containingBlockFontMetricsData:FontMetricsData = _containingBlock.coreStyle.fontMetrics;

		//compute the font style (font-size, line-height...)
		_coreStyle.computeTextAndFontStyles(containingBlockData, containingBlockFontMetricsData);

		//compute the box styles (width, height, margins, paddings...)
		_coreStyle.computeBoxModelStyles(containingBlockData, isReplaced());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine if the ElementRenderer is a floated
	 * ElementRenderer. A floated ElementRenderer is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its containing block.
	 * Any subsequent line box flows
	 * around its margin box until a new line 
	 * starts below the float or if it is cleared
	 * by another ElementRenderer.
	 * 
	 * An ElementRenderer is floated if it declares either
	 * a left or right float
	 */
	override public function isFloat():Bool
	{
		var ret:Bool = false;
		
		switch (this.computedStyle.cssFloat) 
		{
			case CSSFloat.left, CSSFloat.right:
				ret = true;
			
			case CSSFloat.none:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * A positioned element is one that 
	 * is positioned outside of the normal
	 * flow.
	 * 
	 * The 'relative', 'absolute' and'fixed'
	 * values of the 'position' style makes
	 * an ElementRenderer 'positioned'. 
	 * 
	 * The 'absolute' and 'fixed' value make
	 * an ElementRenderer an 'absolutely positioned'
	 * ElementRenderer. This kind of ElementRenderer
	 * doesn't affect the normal flow (it is
	 * treated as if it doesn't exist). It
	 * uses as origin its first ancestor
	 * which is also positioned
	 * 
	 * See below for the 'relative' value
	 */
	override public function isPositioned():Bool
	{
		var ret:Bool = false;
		
		switch (this.computedStyle.position) 
		{
			case relative, absolute, fixed:
				ret = true;
			
			case cssStatic:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Determine wether an ElementRenderer has
	 * the 'position' value 'relative'.
	 * 
	 * A 'relative' ElementRenderer is first placed
	 * normally in the flow then an offset is 
	 * applied to it with the top, left, right
	 * and bottom computed styles.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * ElementRenderer is found
	 */
	override public function isRelativePositioned():Bool
	{
		return this.computedStyle.position == relative;
	}
	
	/**
	 * An inline-level ElementRenderer is one that is
	 * laid out on a line. Its line boxes will be placed
	 * either next to the preceding ElementRenderer's line boxes
	 * or on new lines if the current line
	 * is too short to host them.
	 * 
	 * Wheter an element is inline-level is determined
	 * by its display style
	 */
	override public function isInlineLevel():Bool
	{
		var ret:Bool = false;
		
		switch (this.computedStyle.display) 
		{
			case cssInline, inlineBlock:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Overriden as BoxRenderer might create new stacking context, for
	 * instance if they are positioned.
	 */
	override public function establishesNewStackingContext():Bool
	{
		if (isPositioned() == true)
		{
			if (isAutoZIndexPositioned() == true)
			{
				return false;
			}
			else
			{
				return true;
			}
			//if a box is positioned, it only establishes
			//a new stacking context if its z-index is not
			//auto, else it uses the LayerRenderer of its parent
			switch (computedStyle.zIndex)
			{
				case ZIndex.cssAuto:
					return false;
					
				case ZIndex.integer(value):
					return true;
			}
		}
		
		//in all other cases, no new stacking context is created
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the ElementRenderer is both positioned
	 * and have an 'auto' z-index value, as if it does, it 
	 * means it doesn't have to establish a new stacking context
	 */
	override private function isAutoZIndexPositioned():Bool
	{
		if (isPositioned() == false)
		{
			return false;
		}
		
		switch(computedStyle.zIndex)
		{
			case ZIndex.cssAuto:
				return true;
				
			case ZIndex.integer(value):
				return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the ElementRenderer introduces
	 * 'clearance', which as the effect of placing
	 * the ElementRenderer below any preceding floated
	 * ElementRenderer. An ElementRenderer introduces clearance
	 * if he clears either left floats, right floats
	 * or both
	 */
	private function isClear():Bool
	{
		var ret:Bool = false;
		
		switch (this.computedStyle.clear) 
		{
			case Clear.left, Clear.right, Clear.both:
				ret = true;
			
			case Clear.none:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Helper method returning the bounds to 
	 * be used to draw the background. Meant
	 * to be overriden as for instance the HTMLBodyElement's
	 * ElementRenderer uses the viewport bounds for its background
	 * instead of its own
	 */
	private function getBackgroundBounds():RectangleData
	{
		return globalBounds;
	}
	
	/**
	 * Return the dimensions data
	 * of the ElementRenderer
	 */
	public function getContainerBlockData():ContainingBlockData
	{
		return {
			width:this.computedStyle.width,
			isWidthAuto:this._coreStyle.width == Dimension.cssAuto,
			height:this.computedStyle.height,
			isHeightAuto:this._coreStyle.height == Dimension.cssAuto
		};
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingBlockData
	{	
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		var windowData:ContainingBlockData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:width,
			height:height
		}
		
		return windowData;
	}
}