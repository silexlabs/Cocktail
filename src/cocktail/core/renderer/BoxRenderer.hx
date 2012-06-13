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
import cocktail.core.FontManager;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
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
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to render elements spefic to a box (background, border...)
	 * TODO 4 : apply visibility
	 */
	override public function render(parentGraphicContext:NativeElement):Void
	{
		
		if (_needsRendering == false)
		{
			//return;
		}
		
		clear();
		//get the relative offset of this ElementRenderer and add it to
		//its parent
		renderBackground(_graphicsContext);
		renderChildren(_graphicsContext);
		
		//if (_needsVisualEffectsRendering == true)
		//{
			applyVisualEffects(_graphicsContext);
		//}
		_needsVisualEffectsRendering = false;
		
		
		//draws the graphic context of this block box on the one of its
		//parent
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(parentGraphicContext);
		containerGraphicContext.addChild(_graphicsContext);
		#end
		
		_needsRendering = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the background of the box using the provided graphic context
	 */
	private function renderBackground(graphicContext:NativeElement):Void
	{

				//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO 4 : check if its still necessary that they are only computed
		//during rendering
		_coreStyle.computeBackgroundStyles();
		
		var backgroundManager:BackgroundManager = new BackgroundManager();
		
		//TODO 3 : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = backgroundManager.render(bounds, _coreStyle);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		var length:Int = backgrounds.length;
		var globalBounds:RectangleData = globalBounds;

		for (i in 0...length)
		{
			backgrounds[i].x = globalBounds.x;
			backgrounds[i].y = globalBounds.y;
			containerGraphicContext.addChild(backgrounds[i]);
		}
		#end
	}
	
	/**
	 * Render the children of the box
	 */
	private function renderChildren(graphicContext:NativeElement):Void
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
		_coreStyle.computeVisualEffectStyles();
		
		applyOpacity(graphicContext);
		applyTransformationMatrix(graphicContext);
	}
	
	/**
	 * Apply the transformation matrix computed with the
	 * transform and transform-origin style on the graphic context
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
	 * This method is in charge of laying out an ElementRenderer which consist in computing its styles (box model, font, text...)
	 * into usable values and determining its bounds in the space of the containing block which started its formatting context.
	 * 
	 * This method is called recursively on every children of the ElementRenderer if it has any to layout all of the rendering tree.
	 * 
	 * @param	containingBlockData the computed dimensions of the parent block of this
	 * ElementRenderer.
	 * @param	viewportData a reference to the dimensions of the viewport of the document. When laying out a fixed positioned ElementRenderer
	 * (an ElementRenderer with a 'position' style of 'fixed'), its dimensions are used as containing dimensions
	 * @param	firstPositionedAncestorData the dimensions of the first positioned ancestor in the hierarchy, meaning that
	 * it has a 'position' other than 'static'. When laying out an absolutelty positioned ElementRenderer ( an ElementRenderer with a 'position' style
	 * of 'absolute'), it it used as containing block dimensions. It also contains a reference to each absolutely positioned ElementRenderer for whom
	 * it is the first positioned ancestor
	 * @param   containingBlockFontMetricsData the font metrics of the containing block which might be necessary to compute some styles.
	 * For instance, style defined with a length using the 'em' unit will refer to the computed font size of the containing block
	 */
	override public function layout(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{	
		if (_needsLayout == true)
		{
			layoutSelf();
			_needsLayout = false;
		}
		
		
		
		//if (_childrenNeedLayout == true)
		//{
			//layout all the children of the ElementRenderer if it has any
			layoutChildren(firstPositionedAncestorData);
		//}
		_childrenNeedLayout = false;
		

		
		//insert the ElementRenderer in the absolutely positioned array if it is itself absolutely positioned
		//so that it can be positioned by its first positioned ancestor once it is laid out
		storeAbsolutelyPositionedChild(firstPositionedAncestorData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function layoutSelf():Void
	{
		var containiningBlock:BlockBoxRenderer = getContainingBlock();
			
		var containingBlockData:ContainingBlockData = containiningBlock.getContainerBlockData();
		var containingBlockFontMetricsData:FontMetricsData = containiningBlock.coreStyle.fontMetrics;
		//compute all the styles of the ElementRenderer
		//
		//TODO 1 : styles which can be computed without any external data should be when their specified
		//value changes instead of now, which is unecessary
		_coreStyle.computeTextAndFontStyles(containingBlockData, containingBlockFontMetricsData);

		//compute the box styles (width, height, margins, paddings...)
		_coreStyle.computeBoxModelStyles(containingBlockData, isReplaced());
	}
	
	/**
	 * Lay out all the children of the ElementRenderer
	 */
	private function layoutChildren(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{
		//abstract
	}
	
	/**
	 * Insert the ElementRenderer in the array of absolutely positioned elements if it
	 * in fact an absolutely positioned element
	 */
	private function storeAbsolutelyPositionedChild(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{
		//don't do anything for static or relative positioned elements.
		//Relative positioning is only an offset applied during rendering
		if (isPositioned() == false || isRelativePositioned() == true)
		{
			return;
		}
		
		//store as a positioned ElementRenderer.
		//an absolutely positioned ElementRenderer is not laid out right away, it must
		//wait for its first positioned ancestor to be laid out. The reason is that
		//if the positioned ancestor height is 'auto', the height of the positioned
		//ancestor is not yet determined and so this ElementRenderer can't be laid out
		//using the bottom or right style yet. Once the first ancestor is laid out, it
		//lays out all the stored positioned children
		
		//store the ElementRenderer to be laid out later
		firstPositionedAncestorData.elements.push(this);
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
	 * 
	 * TODO 2 : hack, shouldn't have to compute display style before
	 * 
	 */
	override public function establishesNewStackingContext():Bool
	{
		_coreStyle.computeDisplayStyles();
		
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