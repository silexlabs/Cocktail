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
	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to render elements spefic to a box (background, border...)
	 * 
	 * TODO 5 : apply transformations, opacity
	 * TODO 4 : apply visibility
	 */
	override public function render(parentGraphicContext:NativeElement, parentRelativeOffset:PointData):Void
	{
		super.render(parentGraphicContext, parentRelativeOffset);
		//get the relative offset of this ElementRenderer and add it to
		//its parent
		var relativeOffset:PointData = getConcatenatedRelativeOffset(parentRelativeOffset);
		renderBackground(_graphicsContext, relativeOffset);
		applyVisualEffects(_graphicsContext, relativeOffset );
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the background of the box using the provided graphic context
	 * 
	 * TODO 4 : opacity should be applied to background
	 */
	private function renderBackground(graphicContext:NativeElement, relativeOffset:PointData):Void
	{

		var backgroundManager:BackgroundManager = new BackgroundManager();
		
		//TODO 3 : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = backgroundManager.render(bounds, _coreStyle);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		for (i in 0...backgrounds.length)
		{
			backgrounds[i].x = globalBounds.x + relativeOffset.x;
			backgrounds[i].y = globalBounds.y + relativeOffset.y;
			containerGraphicContext.addChild(backgrounds[i]);
		}
		#end
		
	}
	
	private function applyVisualEffects(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		#if (flash9 || nme)
		graphicContext.alpha = computedStyle.opacity;
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(computedStyle.transform, relativeOffset);
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = concatenatedMatrix.data;
		
		//create a native flash matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
		//apply the native flash matrix to the native flash DisplayObject
		graphicContext.transform.matrix = nativeTransformMatrix;

		#end
	}
	
	/**
	 * Concatenate the new matrix with the "base" matrix of the HTMLElement
	 * where only translations (the x and y of the HTMLElement) and scales
	 * (the width and height of the HTMLElement) are applied.
	 * It is neccessary in flash to do so to prevent losing the x, y, width
	 * and height applied during layout
	 * 
	 */
	private function getConcatenatedMatrix(matrix:Matrix, relativeOffset:PointData):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		currentMatrix.translate(globalBounds.x + relativeOffset.x, globalBounds.y + relativeOffset.y);
		currentMatrix.concatenate(matrix);
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
	 * @param	formattingContext The formatting context used by the containing block. Can be an inline or block formatting context.
	 */
	override public function layout(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		//reset the computed styles, useful for instance to
		//reset an auto height to 0 if a layout has already
		//occured which might create bugs in the computation of
		//font and text styles which use the computed height value
		_coreStyle.initComputedStyles();
		
		//compute all the styles of the ElementRenderer
		_coreStyle.computeDisplayStyles();
		_coreStyle.computeTextAndFontStyles(containingBlockData, containingBlockFontMetricsData);

		//compute the box styles (width, height, margins, paddings...)
		_coreStyle.computeBoxModelStyles(getRelevantContainingBlockData(containingBlockData, viewportData,  firstPositionedAncestorData.data), isReplaced());
		
		//layout all the children of the ElementRenderer if it has any
		layoutChildren(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		
		//when all the dimensions of the ElementRenderer are known, compute the 
		//visual effects to apply (visibility, opacity, transform, transition)
		//it is necessary to wait for all dimensions to be known because for
		//instance the transform style use the height and width of the ElementRenderer
		//to determine the transformation center
		_coreStyle.computeVisualEffectStyles();
		
		//some text and font styles needs to be re-computed now that all the dimension
		//of the ElementRenderer are known, for instance some values of the VerticalAlign style
		//might need those dimensions to compute the right values
		//
		//TODO 4 : shouldn't be necessary anymore as vertical align is computed during formatting.
		//Only used for vertical align and text indent
		_coreStyle.computeTextAndFontStyles(containingBlockData, containingBlockFontMetricsData);
		
		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO 4 : check if its still necessary that they are only computed
		//during rendering
		_coreStyle.computeBackgroundStyles();
		
		//insert the ElementRenderer in the absolutely positioned array if it is itself absolutely positioned
		//so that it can be positioned by its first positioned ancestor once it is laid out
		storeAbsolutelyPositionedChild(firstPositionedAncestorData);
		
		//The ElementRenderer has been laid out and can now be laid out again
		//if it changes
		this._isLayingOut = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the layout of all of the HTMLElements tree which set the bounds
	 * of the all of the rendring tree elements relative to their containing block.
	 * Then set the global bounds (relative to the window) for all of the elements
	 * of the rendering tree
	 * 
	 * TODO 2 : for now only called by the InitialBlockRenderer but should be callable
	 * by any BoxRenderer to prevent from laying out and rendering all of the rendering
	 * tree
	 */
	private function startLayout():Void
	{
		var windowData:ContainingBlockData = getWindowData();
		
		//TODO 2 : should retrieve the data of the first positioned ancestor
		var firstPositionedAncestorData:FirstPositionedAncestorData = {
			elements: new Array<ElementRenderer>(),
			data:getContainerBlockData()
		}
		
		//layout all the HTMLElements. After that they all know their bounds relative to the containing
		//blocks
		layout(getContainerBlockData(), windowData, firstPositionedAncestorData, _coreStyle.fontMetrics, null);
		//set the global bounds on the rendering tree. After that all the elements know their positions
		//relative to the window
		
		
		setGlobalOrigins(this,globalBounds.x,globalBounds.y, positionedOrigin.x,positionedOrigin.y);
	}
	
	/**
	 * Set the global bounds (relative to the window) of all the elements of the rendering tree, by
	 * traversing it recursively
	 * 
	 * 
	 * @param	elementRenderer the current node in the render tree onto which the global bounds are set
	 * @param	addedX the added x position for the normal flow
	 * @param	addedY the added y position for the normal flow
	 * @param	addedPositionedX the added X position for positioned elements
	 * @param	addedPositionedY the added Y position for positioned elements
	 */
	private function setGlobalOrigins(elementRenderer:ElementRenderer, addedX:Float, addedY:Float, addedPositionedX:Float, addedPositionedY:Float):Void
	{
		
		//if the element establishes a new formatting context, then its
		//bounds must be added to the global x and y bounds for the normal flow
		if (elementRenderer.establishesNewFormattingContext() == true)
		{
			//if the element is positioned, it can either add its bounds
			//or positioned origin to the global x and y for normal flow. If it
			//uses its static position, it uses its bounds, else it uses its
			//positioned origin
			if (elementRenderer.isPositioned() == true && elementRenderer.isRelativePositioned() == false)
			{
				if (elementRenderer.coreStyle.left != PositionOffset.cssAuto || elementRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedX += elementRenderer.positionedOrigin.x;
					}
					//here the positioned ElementRenderer is fixed and is placed
					//relative to the window. In this case, its x is not added
					else
					{
						addedX = elementRenderer.positionedOrigin.x;
					}
				}
				else
				{
					addedX += elementRenderer.bounds.x;
				}
				
				if (elementRenderer.coreStyle.top != PositionOffset.cssAuto || elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedY += elementRenderer.positionedOrigin.y;
					}
					else
					{
						addedY = elementRenderer.positionedOrigin.y;
					}
				}
				else
				{
					addedY += elementRenderer.bounds.y;
				}
			}
			//if the element is not positioned or relatively positioned, it always add
			//its bounds to the global x and y flow
			//TODO 3 : hack, check if elementRenderer is the one which started layout, as if it is
			//it must not add its bounds again, as they are passed as parameters. Should instead use the
			//bounds of containing block ?
			else if (elementRenderer != this)
			{
				addedX += elementRenderer.bounds.x;
				addedY += elementRenderer.bounds.y;
			}
		}
		
		//if the element is positioned, it must also add
		//its bounds to the global positioned origin
		if (elementRenderer.isPositioned() == true)
		{
			//absolutely positioned elements either add their static position
			//or their positioned origin
			if (elementRenderer.coreStyle.computedStyle.position != relative)
			{
				if (elementRenderer.coreStyle.left != PositionOffset.cssAuto || elementRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedPositionedX += elementRenderer.positionedOrigin.x;
					}
					else
					{
						addedPositionedX = elementRenderer.positionedOrigin.x;
					}
					
				}
				else
				{
					addedPositionedX += elementRenderer.bounds.x;
				}
				if (elementRenderer.coreStyle.top != PositionOffset.cssAuto || elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedPositionedY += elementRenderer.positionedOrigin.y;
					}
					else
					{
						addedPositionedY = elementRenderer.positionedOrigin.y;
					}
					
				}
				else
				{
					addedPositionedY += elementRenderer.bounds.y;
				}
			}
			//relative positioned elements always use their bounds, as the relative
			//offset is only applied at render time and isn't used in the bounds
			//computation
			else
			{
				addedPositionedX += elementRenderer.bounds.x;
				addedPositionedY += elementRenderer.bounds.y;
			}
		}
		
		//for its child of the element
		for (i in 0...elementRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			//TODO 1 : doc on added body margin. Shouldn't be always applied
			child.globalContainingBlockOrigin = {
				x: addedX,
				y : addedY
			}
			
			
			child.globalPositionnedAncestorOrigin = {
				x: addedPositionedX,
				y : addedPositionedY
			}
			
				
				//call the method recursively if the child has children itself
				if (child.hasChildNodes() == true)
				{
					setGlobalOrigins(child, addedX, addedY, addedPositionedX, addedPositionedY);
				}
			
			
			
		}
	}
	
	/**
	 * Lay out all the children of the ElementRenderer
	 */
	private function layoutChildren(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
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
		_coreStyle.computeDisplayStyles();
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
	 * TODO 2 : shouldn't have to compute display style before
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
	private function getContainerBlockData():ContainingBlockData
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
		var windowData:ContainingBlockData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:cocktail.Lib.window.innerWidth,
			height:cocktail.Lib.window.innerHeight
		}
		
		return windowData;
	}
	
	/**
	 * Get the right containing block dimensions for an ElementRenderer
	 * based on its positioning scheme
	 */
	private function getRelevantContainingBlockData(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:ContainingBlockData):ContainingBlockData
	{
		var containingBlockDimensions:ContainingBlockData;
		
		switch (computedStyle.position)
		{
			//for 'fixed' ElementRenderer, takes the viewport (the 'window' through which the document is viewed)
			case fixed:
				containingBlockDimensions = {
					width:viewportData.width,
					height:viewportData.height,
					isHeightAuto:viewportData.isHeightAuto,
					isWidthAuto:viewportData.isWidthAuto };
					
			//for 'absolute' takes the first positioned ancestor
			case absolute:
				containingBlockDimensions = {
					width:firstPositionedAncestorData.width,
					height:firstPositionedAncestorData.height,
					isHeightAuto:firstPositionedAncestorData.isHeightAuto,
					isWidthAuto:firstPositionedAncestorData.isWidthAuto};
				
			//for 'static' or 'relative' ElementRenderer, takes the containing block dimensions which is the parent	block	
			case cssStatic, relative:
				containingBlockDimensions = containingBlockData;
				
		}
		
		return containingBlockDimensions;
	}
}