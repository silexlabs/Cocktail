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
import haxe.Log;

/**
 * Base class for box renderers. A box renderer
 * is an element displayed as a box, with margins,
 * paddings, backgrounds...
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxRenderer extends ElementRenderer
{
	/**
	 * a reference to the background manager in charge
	 * of displaying the background of the element
	 */
	private var _backgroundManager:BackgroundManager;
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyleData;

	
	/**
	 * determine wether the HTMLElement is currently being
	 * laid out, in which case it won't take any subsequent
	 * layout request into account
	 */
	private var _isLayingOut:Bool;
	
	/**
	 * class constructor
	 */
	public function new(node:Node) 
	{
		super(node);
		this._isLayingOut = false;
		init();
		
	}
	
	private function init():Void
	{
		_backgroundManager = new BackgroundManager();
	}
	
	
	
	/**
	 * Render and position the background color and
	 * image of the element using runtime specific
	 * API and return an array of NativeElement from
	 * it
	 */
	override public function render():Array<NativeElement>
	{
		
		//TODO : should only pass dimensions instead of bounds
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _coreStyle);
		
		for (i in 0...backgrounds.length)
		{
			#if (flash9 || nme)
			backgrounds[i].x = globalBounds.x;
			backgrounds[i].y = globalBounds.y;
			#end
		}
	
		return backgrounds;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the HTMLElement
	 * 
	 * TODO : move implementation to flow box renderer
	 * 
	 */
	private function layoutChildren(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		
	}
	

	

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is in charge of laying out an HTMLElement which consist in computing its styles (box model, font, text...)
	 * into usable values and determining the bounds of its corresponding ElementRenderer in its containing block space.
	 * 
	 * This method is called recursively on every children of the HTMLElement if it has any to layout all of the rendering tree.
	 * 
	 * After this method was called, each ElementRenderer in the rendering tree is aware of its bounds relative to
	 * its containing block which is the HTMLElement which started the formatting context used to layout the ElementRenderer
	 * 
	 * @param	containingHTMLElementData the dimensions of the parent HTMLElement used to layout this
	 * HTMLElement. for instance if this HTMLElement has a width style of 'auto', it will use the width
	 * of its containing HTMLElement
	 * @param	viewportData a reference to the dimensions of the viewport of the document. When laying out a fixed positioned HTMLElement
	 * (a HTMLElement with a 'position' style of 'fixed'), its dimensions are used as containing dimensions
	 * @param	lastPositionedHTMLElementData the dimensions of the first ancestor HTMLElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' other than 'static'. When laying out an absolutelty positioned HTMLElement ( a HTMLElement with a 'position' style
	 * of 'absolute'), it it used as containing dimensions. It also contains a reference to each absolutely positioned ElementRenderer for whom
	 * it is the first positioned ancestor
	 * @param   containingHTMLElementFontMetricsData the font metrics of the containing block parent which might be necessary to compute some styles.
	 * For instance, style defined with a length using the 'em' value will refer to the computed font size of the containing parent
	 * @param	formattingContext The formatting context used by the parent HTMLElement. Can be an inline or block formatting context.
	 * @param parentElementRenderer the parent node in the rendering tree
	 */
	override public function layout(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		//do nothing if the HTMLElement must not be displayed, i.e, added
		//to the DOM
		if (isDisplayed() == false)
		{
			return;
		}

		//reset the computed styles, useful for instance to
		//reset an auto height to 0 if a layout has already
		//occured which might create bugs in the computation of
		//font and text styles which use the computed height value
		//
		//TODO : re-implement
		//initComputedStyles();
		
		//compute all the styles of a HTMLElement
		
		_coreStyle.computeDisplayStyles();
		_coreStyle.computeTextAndFontStyles(containingHTMLElementData, containingHTMLElementFontMetricsData);
		_coreStyle.computeBoxModelStyles(getContainingHTMLElementData(containingHTMLElementData, viewportData,  lastPositionedHTMLElementData.data));
		
		//layout all the children of the HTMLElement if it has any
		layoutChildren(containingHTMLElementData, viewportData, lastPositionedHTMLElementData, containingHTMLElementFontMetricsData, formattingContext);
		
		//when all the dimensions of the htmlElement are known, compute the 
		//visual effects to apply (visibility, opacity, transform)
		//it is necessary to wait for all dimensions to be known because for
		//instance the transform style use the height and width of the HTMLElement
		//to determine the transformation center
		_coreStyle.computeVisualEffectStyles();
		
		//some text and font styles needs to be re-computed now that all the dimension
		//of the HTMLElement are known, for instance some values of the VerticalAlign style
		//might need those dimensions to compute the right values
		//
		//TODO : shouldn't have to re-compute all of the font and text styles
		_coreStyle.computeTextAndFontStyles(containingHTMLElementData, containingHTMLElementFontMetricsData);
		
		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO : check if its still necessary that they are only computed
		//during rendering
		_coreStyle.computeBackgroundStyles();
		
		//insert the HTMLElement in the absolutely positioned array if it is itself absolutely positioned
		//so that it can be positioned by its first positioned ancestor once it is laid out
		//
		//TODO : should happen instead in doFlowChildren of ContainerCoreStyle ?
		insertAbsolutelyPositionedHTMLElementIfNecessary(formattingContext, lastPositionedHTMLElementData);
		
		
		//The HTMLElement has been laid out and can now be laid out again
		//if it changes
		this._isLayingOut = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ABSOLUTE POSITIONING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Position an absolutely positioned ElementRenderer (with a position style of 'fixed' or 'absolute')
	 * using either the first positioned ancestor as reference or the viewport
	 * 
	 * TODO : tried to move it to ContainerCoreStyle but had problem has ElementRenderer
	 * was passed by value instead of reference
	 * 
	 * @param lastPositionedHTMLElementData the dimensions of the first positioned ancestor
	 * @param viewportData the dimensions of the viewport
	 */
	override public function positionElement(lastPositionedHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		switch (_coreStyle.computedStyle.position)
		{	
			//positioned 'fixed' HTMLElement, use the viewport
			case fixed:
				doPositionElement(this, viewportData);
				
			//positioned 'absolute' HTMLElement	
			case absolute:
				doPositionElement(this, lastPositionedHTMLElementData);
			default:
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ABSOLUTE POSITIONING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually position the positioned ElementRenderer
	 * 
	 * TODO : should be called by FlowBoxRenderer on itzs children instead
	 */
	private function doPositionElement(elementRenderer:ElementRenderer, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (elementRenderer.coreStyle.left != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.x = getLeftOffset(elementRenderer);
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing HTMLElement width minus the
		//width of the positioned children as value for a 0 right offset
		else if (elementRenderer.coreStyle.right != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.x = getRightOffset(elementRenderer, containingHTMLElementData.width);
		}
		//if both right and left are 'auto', then the HTMLElement is positioned to its
		//static position, the position it would have had in the flow if it were positioned as 'static'.
		//At this point the bounds of the ElementRenderer already matches its static position
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (elementRenderer.coreStyle.top != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getTopOffset(elementRenderer);
		}
		else if (elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getBottomOffset(elementRenderer, containingHTMLElementData.height);
		}
	}
	
	/**
	 * get the left offset to apply the ElementRenderer
	 */
	private function getLeftOffset(elementRenderer:ElementRenderer):Int
	{
		return elementRenderer.coreStyle.computedStyle.left + elementRenderer.coreStyle.computedStyle.marginLeft;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(elementRenderer:ElementRenderer, containingHTMLElementWidth:Int):Int
	{
		return containingHTMLElementWidth - elementRenderer.coreStyle.computedStyle.width + elementRenderer.coreStyle.computedStyle.paddingLeft
		+ elementRenderer.coreStyle.computedStyle.paddingRight + elementRenderer.coreStyle.computedStyle.right - elementRenderer.coreStyle.computedStyle.marginRight;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(elementRenderer:ElementRenderer):Int
	{
		return elementRenderer.coreStyle.computedStyle.top + elementRenderer.coreStyle.computedStyle.marginTop;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(elementRenderer:ElementRenderer, containingHTMLElementHeight:Int):Int
	{
		return containingHTMLElementHeight - elementRenderer.coreStyle.computedStyle.height + elementRenderer.coreStyle.computedStyle.paddingTop +
		elementRenderer.coreStyle.computedStyle.paddingBottom - elementRenderer.coreStyle.computedStyle.bottom;
	}
	
	/**
	 * Insert the HTMLElement's ElementRenderer in the array of absolutely positioned elements if it
	 * in fact an absolutely positioned element
	 */
	private function insertAbsolutelyPositionedHTMLElementIfNecessary(formattingContext:FormattingContext, lastPositionedHTMLElementData:LastPositionedHTMLElementData):Void
	{
		//don't do anything for static or relative positioned elements.
		//Relative positioning is only an offset applied during rendering
		if (isPositioned() == false || isRelativePositioned() == true)
		{
			return;
		}
		
		//store as a positioned ElementRenderer.
		//an absolutely positioned ElementRenderer is not positioned right away, it must
		//wait for its first positioned ancestor to be laid out. The reason is that
		//if the positioned ancestor height is 'auto', the height of the positioned
		//ancestor is not yet determined and so this ElementRenderer can't be positioned
		//using the bottom or right style yet. Once the first ancestor is laid out, it
		//position all the stored positioned children
		
		//store the ElementRenderer to be positioned later
		lastPositionedHTMLElementData.elements.push(this);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the value of a style that require
	 * a re-layout (such as width, height, display...) is
	 * changed.
	 * 
	 * An invalidated HTMLElement will in turn invalidate its
	 * parent and so on until the root HTMLBodyElement is invalidated.
	 * The root HTMLBodyElement will then layout itself, laying out
	 * at the same time all its invalidated children.
	 * 
	 * A layout can be immediate or scheduled asynchronously, which
	 * increase preformance when many style value are set in a 
	 * row as the layout only happen once
	 */
	override public function invalidate(immediate:Bool = false):Void
	{
		//only invalidate the parent if it isn't
		//already being laid out or if an immediate layout is required
		if (this._isLayingOut == false || immediate == true)
		{
			//set the layout flag to prevent multiple
			//layout of the HTMLElement in a row
			//The HTMLElement will be able to be invalidated
			//again once it has been laid out
			this._isLayingOut = true;
			
			//if the HTMLElement doesn't have a parent, then it
			//is not currently added to the DOM and doesn't require
			//a layout
			if (this._parentNode != null)
			{
				var parent:ElementRenderer = cast(_parentNode);
				parent.invalidate(immediate);	
			}
		}
	}


	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get the right containing parent dimensions for an HTMLElement
	 * based on its position style value
	 */
	private function getContainingHTMLElementData(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:ContainingHTMLElementData):ContainingHTMLElementData
	{
		var containingBlockDimensions:ContainingHTMLElementData;
		
		switch (computedStyle.position)
		{
			//for 'fixed' HTMLElement, takes the viewport (the 'window' through which the document is viewed)
			case fixed:
				containingBlockDimensions = {
					width:viewportData.width,
					height:viewportData.height,
					isHeightAuto:viewportData.isHeightAuto,
					isWidthAuto:viewportData.isWidthAuto };
					
			//for 'absolute' takes the first positioned ancestor
			case absolute:
				containingBlockDimensions = {
					width:lastPositionedHTMLElementData.width,
					height:lastPositionedHTMLElementData.height,
					isHeightAuto:lastPositionedHTMLElementData.isHeightAuto,
					isWidthAuto:lastPositionedHTMLElementData.isWidthAuto};
				
			//for 'static' or 'relative' HTMLElement, takes the containing HTMLElement dimensions which is the parent		
			case cssStatic, relative:
				containingBlockDimensions = containingHTMLElementData;
				
		}
		
		return containingBlockDimensions;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine if the HTMLElement is a floated
	 * HTMLElement. A floated HTMLElement is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its container.
	 * Any subsequent HTMLElement flows
	 * around the float until a new line 
	 * starts below the float or if it is cleared
	 * by another HTMLElement.
	 * 
	 * An HTMLElement is float if he declares either
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
	 * a HTMLElement 'positioned'. 
	 * 
	 * The 'absolute' and 'fixed' value make
	 * a HTMLElement an 'absolutely positioned'
	 * HTMLElement. This kind of HTMLElement
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
	 * Determine wether a HTMLElement has
	 * the 'position' value 'relative'.
	 * 
	 * A 'relative' HTMLElement is first placed
	 * normally in the flow then an offset is 
	 * applied to it with the top, left, right
	 * and bottom computed styles.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * HTMLElement is found
	 */
	override public function isRelativePositioned():Bool
	{
		return this.computedStyle.position == relative;
	}
	
	/**
	 * An inline-level HTMLElement is one that is
	 * laid out on a line. It will be placed
	 * either next to the preceding HTMLElement
	 * or on a new line if the current line
	 * is too short to host it.
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
	 * Determine wether the HTMLElement is added
	 * to the document
	 */
	override public function isDisplayed():Bool
	{
		return this.computedStyle.display != Display.none;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the HTMLElement introduces
	 * 'clearance', which as the effect of placing
	 * the HTMLElement below any preceding floated
	 * HTMLElement. A HTMLElement introduces clearance
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
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingHTMLElementData
	{	
		var windowData:ContainingHTMLElementData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:cocktail.Lib.window.innerWidth,
			height:cocktail.Lib.window.innerHeight
		}
		
		return windowData;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the children of this HTMLElement
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * TODO : throw exception when there is a float in the children
	 * 
	 * @return true if all children are inline level HTMLElements
	 */
	override public function childrenInline():Bool
	{
		
		//return false for a container with no children
		if (_node.childNodes.length == 0)
		{
			return false;
		}
		
		//establish if the first child is inline or block
		//all other child must be of the same type
		var ret:Bool = isChildInline(_node.childNodes[0]);
		
		//loop in all children and throw an exception
		//if one the children is not of the same type as the first
		for (i in 0..._node.childNodes.length)
		{
			if (isChildInline(_node.childNodes[i]) != ret)
			{
				//throw "children of a block container can only be either all block or all inline";
			}
		}
		
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the dimensions data
	 * of the HTMLElement
	 */
	private function getContainerHTMLElementData():ContainingHTMLElementData
	{
		return {
			width:this.computedStyle.width,
			isWidthAuto:this._coreStyle.width == Dimension.cssAuto,
			height:this.computedStyle.height,
			isHeightAuto:this._coreStyle.height == Dimension.cssAuto
		};
	}
	
	/**
	 * return the data of this htmlElement to be used when it is
	 * the first positioned ancestor for its children.
	 * Meant to be overriden
	 */
	private function getPositionedHTMLElementData():ContainingHTMLElementData
	{
		return getContainerHTMLElementData();
	}
	
	/**
	 * Return the right formatting context to layout this HTMLElement's
	 * children.
	 * 
	 * An HTMLElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * HTMLElement, might be returned if the HTMLElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		var formattingContext:FormattingContext;
		
		//here, a new formatting context is created
		if (establishesNewFormattingContext() == true || previousformattingContext == null)
		{	
			//instantiate the right formatting context
			//based on the children computed display styles
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(cast(this));	
			}
			else
			{
				formattingContext = new BlockFormattingContext(cast(this));
			}
		}
		else
		{
			formattingContext = previousformattingContext;
		}
		
		return formattingContext;
	}
	
	/**
	 * Determine wether a children is inline or not
	 */
	private function isChildInline(child:Node):Bool
	{
		var ret:Bool = true;
		
		//here the children is a HTMLElement
		if (child.nodeType == Node.ELEMENT_NODE)
		{
			var childHTMLElement:HTMLElement = cast(child);
			//here the child is of type block
			if (childHTMLElement.coreStyle.computedStyle.display == block)
			{
				//floated children are not taken into account 
				if (childHTMLElement.elementRenderer.isFloat() == false)
				{
					ret = false;
				}
				//absolutely positioned children are not taken into account but relative positioned are
				else if (childHTMLElement.elementRenderer.isPositioned() == false || childHTMLElement.elementRenderer.isRelativePositioned() == true)
				{
					ret = false;
				}
			}
			//here the child is inline
			else
			{
				ret = true;
			}
		}
		//here the children is a Text node, which is
		//always inline as text is always displayed on a line
		else
		{
			ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the structure used to layout absolutely positioned
	 * children. If this HTMLElement is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData:LastPositionedHTMLElementData):LastPositionedHTMLElementData
	{
		var childLastPositionedHTMLElementData:LastPositionedHTMLElementData;
		
		if (isPositioned() == true)
		{
			childLastPositionedHTMLElementData = {
				data: getContainerHTMLElementData(),
				elements: new Array<ElementRenderer>()
			}
		}
		else
		{
			childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
		}
		
		return childLastPositionedHTMLElementData;
	}
	
	private function getComputedStyle():ComputedStyleData
	{
		return _coreStyle.computedStyle;
	}
	
	private function setComputedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _coreStyle.computedStyle = value;
	}
	
	
}