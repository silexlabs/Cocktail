/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.viewport.Viewport;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.domElement.TextFragmentDOMElement;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.formatter.BlockFormattingContext;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.formatter.InlineFormattingContext;
import cocktailCore.style.positioner.AbsolutePositioner;
import cocktailCore.style.positioner.BoxPositioner;
import cocktailCore.style.positioner.FixedPositioner;
import cocktailCore.style.positioner.RelativePositioner;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktailCore.textElement.abstract.AbstractTextElement;
import cocktailCore.textElement.TextElementData;
import cocktail.geom.GeomData;
import haxe.Timer;

#if (flash9 || cpp || nme)
import cocktailCore.style.as3.Style;
#elseif js
import cocktailCore.style.js.Style;
#end

import haxe.Log;

/**
 * This is the style implementation for ContainerDOMElement.
 * 
 * ContainerDOMElement can have children, and when laid out,
 * also start the layout on each of its children using
 * either a block or inline formatting
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerStyle extends Style
{
	/**
	 * Store a reference to the formatting context used to format
	 * in-flow children. It is used when rendering to retrieve all
	 * the boxes into which this styled DOMElement is laid out.
	 * An inline level container DOMElement can be laid out
	 * on multiple line and thus have multiple boxes
	 */
	private var _childrenFormattingContext:FormattingContext;
	
	/**
	 * Stores a reference ot each of the absolutely positioned element that
	 * must be attached to this styled ContainerDOMElement. The array only has
	 * elements if this styled ContainerDOMElement is itself positioned and
	 * thus responsible for positioning its positioned children for whom
	 * it is the first positioned ancestor
	 */
	private var _absolutelyPositionedBoxElementData:Array<BoxElementData>;
	
	/**
	 * class constructor.
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When rendering, a ContainerStyle first calls the render
	 * method recursively on all its children, then retrieve
	 * the data of all the boxes it is laid out into (for instance
	 * an inline container DOMElement laid out on multiple lines has
	 * one box for each line) and attach all its backgrounds, children...
	 * 
	 * TODO : in As3, as DisplayObjectContainer have now a width and height of 0
	 * most of the time and children are not attached to them, mouse event
	 * don't work anymore
	 */
	override public function render():Void
	{
		super.render();
		
		
		
		//render all its children recursively
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		for (i in 0...containerDOMElement.children.length)
		{
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.render();
			}
		}
		
		//will contain all the NativeElements which must be attached to this ContainerDOMElement
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		if (establishesNewFormattingContext() == true)
		{
			//get the boxes data from the formatting context which was used to layout the children of this ContainerDOMElement
			var boxesData:Array<BoxData> = _childrenFormattingContext.getBoxesData();
			
			if (childrenInline() == true)
			{
				//for each box, render the background, border and
				//the children of each box
				for (i in 0...boxesData.length)
				{
					var boxNativeElements:Array<NativeElement> = renderBox(boxesData[i]);
					
					for (j in 0...boxNativeElements.length)
					{
						nativeElements.push(boxNativeElements[j]);
					}
				}
			}
			else
			{
				//TODO : shouldn't have to do that
				boxesData.reverse();
				
				//for each box, render the background, border and
				//the children of each box
				for (i in 0...boxesData.length)
				{
					var boxNativeElements:Array<NativeElement> = renderBackgroundOfBlockBox(boxesData[i]);
					
					for (j in 0...boxNativeElements.length)
					{
						nativeElements.push(boxNativeElements[j]);
					}
				}
				//TODO : shouldn't have to do that
				boxesData.reverse();
				
				//for each box, render the background, border and
				//the children of each box
				for (i in 0...boxesData.length)
				{
					var boxNativeElements:Array<NativeElement> = renderChildren(boxesData[i].children);
					
					for (j in 0...boxNativeElements.length)
					{

						nativeElements.push(boxNativeElements[j]);
					}
				}
			}
			
			//render the absolutely positioned children of this ContainerDOMElement
			var absolutelyPositionedNativeElements:Array<NativeElement> = renderChildren(_absolutelyPositionedBoxElementData);
			
			for (i in 0...absolutelyPositionedNativeElements.length)
			{
				nativeElements.push(absolutelyPositionedNativeElements[i]);
			}
			//store the nativeElements so that they can be detached on next layout
			_nativeElements = nativeElements;
			//do attach the nativeElements using runtime specific API
			attachNativeElements(nativeElements);
			
		}
		
		
		
		
	
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render one box of the DOMElement and return the resulting
	 * nativeElements which must be attached to this styled
	 * ContainerDOMElement
	 * @param	box
	 * @return
	 */
	private function renderBox(box:BoxData):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();

		//render the background of the box
		var backgroundNativeElements:Array<NativeElement> = renderBackgroundOfLineBox(box);
		
		for (i in 0...backgroundNativeElements.length)
		{
			nativeElements.push(backgroundNativeElements[i]);
		}
		
		//render each children of the box which are all in-flow DOMElements
		var inFlowChildrenNativeElements:Array<NativeElement> = renderChildren(box.children);
		for (i in 0...inFlowChildrenNativeElements.length)
		{
			nativeElements.push(inFlowChildrenNativeElements[i]);
		}
		
		return nativeElements;
	}
	
	private function renderBackgroundOfLineBox(box:BoxData):Array<NativeElement>
	{
		var backgrounds:Array<NativeElement> = new Array<NativeElement>();
		//no line backround for anonymous child of inline containing block
		if (box.parentDOMElement != this._domElement)
		{
			backgrounds = _backgroundManager.render(box.bounds, box.parentDOMElement.style);
		}
		return backgrounds;
	}
	
	/**
	 * Render the background of the box and return an array
	 * containing the background color if any and all
	 * the background images if any
	 * @param	box
	 * @param	style
	 * @return
	 */
	private function renderBackgroundOfBlockBox(box:BoxData):Array<NativeElement>
	{
		
		var backgrounds:Array<NativeElement> = new Array<NativeElement>();
		
		
		
		for (i in 0...box.children.length)
		{
			var tempBackground = new Array<NativeElement>();
			switch (box.children[i].element)
			{
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
					
					var x:Float = box.children[i].x;
					var y:Float = box.children[i].y;
					var width:Float = box.children[i].width;
					var height:Float = box.children[i].height;
					
					var bounds:RectangleData = {
						x:x,
						y:y,
						width:width,
						height:height
					}
				

					tempBackground  = _backgroundManager.render( bounds,
					 domElement.style);
					
					//TODO : should be the responsability of the containing block to render its background,
					//else the z-order might be wrong
					case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
					
					
					var x:Float = box.children[i].x;
					var y:Float = box.children[i].y;
					var width:Float = box.children[i].width;
					var height:Float = box.children[i].height;
					
					var bounds:RectangleData = {
						x:x,
						y:y,
						width:width,
						height:height
					}
					
					tempBackground  = _backgroundManager.render( bounds,
					 domElement.style);
					 
				default:	
			}
			
			for (j in 0...tempBackground.length)
			{
				backgrounds.push(tempBackground[j]);
			}
		}
		
		return backgrounds;
	}
	
	/**
	 * Render an array of child by applying their computed layout position and 
	 * returnin gall of their nativeElements
	 * 
	 * @param	children
	 * @return
	 */
	private function renderChildren(children:Array<BoxElementData>):Array<NativeElement>
	{
		var childrenNativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...children.length)
		{
			var child:BoxElementData = children[i];
			
			switch (child.element)
			{
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				
					
				//apply x and y
				domElement.style.setNativeX(domElement, child.x + _computedStyle.marginLeft + _computedStyle.paddingLeft);
				domElement.style.setNativeY(domElement, child.y + _computedStyle.marginTop + _computedStyle.paddingTop);
				
				
				childrenNativeElements.push(domElement.nativeElement);
				
				case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
				
				
					//apply x and y
					domElement.style.setNativeX(domElement, child.x + _computedStyle.marginLeft + _computedStyle.paddingLeft);
					domElement.style.setNativeY(domElement, child.y + _computedStyle.marginTop + _computedStyle.paddingTop);
			
				
				childrenNativeElements.push(domElement.nativeElement);
				
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				
				//TODO : clean-up, should'nt be here
				if (isInlineContainer() == false)
				{
					//apply x and y
					domElement.style.setNativeX(domElement, child.x + _computedStyle.marginLeft + _computedStyle.paddingLeft);
					domElement.style.setNativeY(domElement, child.y + _computedStyle.marginTop + _computedStyle.paddingTop);
				}
				else
				{
						//apply x and y
					domElement.style.setNativeX(domElement, child.x );
					domElement.style.setNativeY(domElement, child.y );
				}
				
				childrenNativeElements.push(domElement.nativeElement);
				
				case BoxElementValue.text(domElement, parentDOMElement):
				
				//TODO : clean-up, should'nt be here
				if (isInlineContainer() == false)
				{
					//apply x and y
					domElement.style.setNativeX(domElement, child.x + _computedStyle.marginLeft + _computedStyle.paddingLeft);
					domElement.style.setNativeY(domElement, child.y + _computedStyle.marginTop + _computedStyle.paddingTop);
				}
				else
				{
						//apply x and y
					domElement.style.setNativeX(domElement, child.x );
					domElement.style.setNativeY(domElement, child.y );
				}
				
				childrenNativeElements.push(domElement.nativeElement);
				
				default:
			}
		
		}
		
		return childrenNativeElements;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerDOMElement. The ContainerDOMElement
	 * will be measured and placed as well as all of its children.
	 * 
	 * Once all the layout is done, then the ContainerDOMElement and its children are rendered and displayed
	 */
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{		
		flow(containingDOMElementData, viewportData, lastPositionedDOMElementData,null, null, null);
		render();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, parentAbsolutelyPositionedBoxElementData:Array<BoxElementData>, containingDOMElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		//cast the ContainerDOMElement, as base DOMElement have no children attribute
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0...containerDOMElement.children.length)
		{
			//only DOMElement styles are computed, not TextElement as they have no style.
			//When determining the formatting context to use, TextElement are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text use its ContainerDOMElement's styles for rendering
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.computeDisplayStyles();
			}
		}
		
		//The children use either a new formatting context to
		//be laid out into if the ContainerDOMElement establishes
		//a new formatting context or participate in the current formatting
		//context
		var childrenFormattingContext:FormattingContext = getformattingContext(formattingContext);
		
		//get the dimensions that will be used to lay out the children
		//of the DOMElement. For instance, if the ContainerDOMElement establishes an
		//inline formatting context, then its lineHeight will be used
		//instead of its height as containing height
		var childrenContainingDOMElementData:ContainingDOMElementData = getContainerDOMElementData();
		
		//get the computed font metrics of the ContainerDOMElement. Those metrics
		//are based on the font itself and the font size used
		var childrenContainingDOMElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this ContainerDOMElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this ContainerDOMElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the ContainerDOMElement as reference
		childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		
		if (establishesNewFormattingContext() == true)
		{
			parentAbsolutelyPositionedBoxElementData = new Array<BoxElementData>();
		}
		else if (parentAbsolutelyPositionedBoxElementData == null)
		{
			parentAbsolutelyPositionedBoxElementData = new Array<BoxElementData>();
		}
		
		//flow all children and store their laid out position in the formatting context, relative to the ContainerDOMElement
		//which started the children formatting context
		childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, parentAbsolutelyPositionedBoxElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);

		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		if (this._width == DimensionStyleValue.autoValue)
		{

		
			var currentWidth:Int = this._computedStyle.width;
			this._computedStyle.width = shrinkToFitIfNeeded(containingDOMElementData, childrenFormattingContext.formattingContextData.maxWidth);
			
				
			//if the computed width of the ContainerDOMElement was shrinked, then
			//a new layout must happen
			if (currentWidth != this._computedStyle.width)
			{
				//update the structures used for the layout and starts a new layout
				childrenFormattingContext = getformattingContext(formattingContext);
				childrenContainingDOMElementData = getContainerDOMElementData();
				childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
				childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, parentAbsolutelyPositionedBoxElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
		}
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == DimensionStyleValue.autoValue)
		{
			//format the children formatting context, so that the bounds
			//of the children of this ContainerDOMElement can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for ContainerDOMElement which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			this._computedStyle.height = applyContentHeightIfNeeded(containingDOMElementData,childrenFormattingContext.getChildrenHeight(this._domElement));
		}
		
		//if this ContainerDOMElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them. An array containing all their
		//laid out positions is returned and stored, to be used during rendering
		var absolutelyPositionedBoxElementData = doPositionAbsolutelyPositionedDOMElements(isPositioned(), childLastPositionedDOMElementData, viewportData);

		for (i in 0...absolutelyPositionedBoxElementData.length)
		{
			parentAbsolutelyPositionedBoxElementData.push(absolutelyPositionedBoxElementData[i]);
		}
		//only save the positioned children for block containers, as they will be attached to it
		//TODO : document this functionnality
		if (establishesNewFormattingContext() == true)
		{
			_absolutelyPositionedBoxElementData = parentAbsolutelyPositionedBoxElementData;
		}
		
		//the children formatting context is stored, it will be used
		//to retrieve all the in flow children that this ContainerDOMElement must
		//layout when rendering
		_childrenFormattingContext = childrenFormattingContext;
	}
	
	/**
	 * The ContaionerDOMElement is added to the flow either as a containing block if it
	 * establishes a new formatting context for its children or as a container if it 
	 * uses its parent formatting context to format its children
	 */
	override private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{
		if (establishesNewFormattingContext() == true)
		{
			formattingContext.insertElement(BoxElementValue.containingBlockDOMElement(this._domElement, this._domElement.parent));
		}
		else
		{
			formattingContext.insertElement(BoxElementValue.containerDOMElement(this._domElement, this._domElement.parent));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually flow all the children of the ContainerDOMElement
	 */
	private function doFlowChildren(childrenContainingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, childLastPositionedDOMElementData:LastPositionedDOMElementData, parentAbsolutelyPositionedBoxElementData:Array<BoxElementData>, childrenContainingDOMElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//TODO : must now be put in inline formatting context ?
			if (establishesNewFormattingContext() == false && isInlineContainer() == true)
			{
				childrenFormattingContext.insertElement(BoxElementValue.offset(_computedStyle.marginLeft + _computedStyle.paddingLeft, this._domElement));
			}
		
		//flow all children 
		for (i in 0...containerDOMElement.children.length)
		{
			//if the children is a DOMElement, call its flow method
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				//the flow method also lays out recursively all the children of the childrenDOMElement
				//if it is a ContainerDOMElement
				childrenDOMElement.style.flow(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, parentAbsolutelyPositionedBoxElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentDOMElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenTextElement:TextElement = cast(containerDOMElement.children[i].child);
				insertTextElement(childrenTextElement, childrenFormattingContext, childrenContainingDOMElementData);
			}
		}
		
			//TODO : must now be put in inline formatting context ?
			if (establishesNewFormattingContext() == false  && isInlineContainer() == true)
			{
				childrenFormattingContext.insertElement(BoxElementValue.offset(_computedStyle.marginRight + _computedStyle.paddingRight, this._domElement));
			}
		
		//prompt the children formatting context, to format all the children
		//that were added to it. After this call, an array of all the boxes
		//created by this formatting context becomes available
		//
		//This method is only called if a new formatting
		//context was established by this ContainerDOMElement,
		//meaning that it also is responsible to start its formatting.
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}

		return childrenFormattingContext;
	}
	
	/**
	 * When this ContainerDOMElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of ContainerDOMElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 * 
	 * TODO : check if fixed positioning still works
	 */
	private function doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor:Bool, childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Array<BoxElementData>
	{
		var boxElementsData:Array<BoxElementData> = new Array<BoxElementData>();
		
		if (isFirstPositionedAncestor == true)
		{
			//update the data of the ContainerDOMElement now that its width and height are known
			childLastPositionedDOMElementData.data = getContainerDOMElementData();
			
			//ensure that the actual height of the ContainerDOMElement is used instead of its lineHeight
			childLastPositionedDOMElementData.data.height = getComputedHeight();
			
			//position each stored children
			for (i in 0...childLastPositionedDOMElementData.children.length)
			{
				var positionedDOMElementData:PositionedDOMElementData = childLastPositionedDOMElementData.children[i];
				
				//the static position of all the positioned DOMElement must be updated as they
				//are in their own formatting context space and they must be converted to this
				//ContainerDOMElement's formatting context space, as they will be attached to it
				
				//the domElement which started the formatting context of the child is retrieved
				//TODO : should not have to retrieve it, add globalX and Y to formattingContextData ?
				var formattingContextRootParent:DOMElement = positionedDOMElementData.formattingContext.containingDOMElement;
				
				//the offsets between this ContainerDOMElement and the domElement which started the formatting
				//context of the positioned DOMElement is computed and applied to the static position of the
				//positioned DOMElement
				
				//TODO : should not use globalX/Y, should instead find first common ancestor ?
				var xOffset:Int = formattingContextRootParent.globalX - _domElement.globalX;
				var yOffset:Int = formattingContextRootParent.globalY - _domElement.globalY;
				positionedDOMElementData.staticPosition.x += xOffset;
				positionedDOMElementData.staticPosition.y += yOffset;
				
				//position the DOMElement which return its x and y coordinates in the space of this ContainerDOMElement
				var boxElementData:BoxElementData = positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data, viewportData, positionedDOMElementData.staticPosition );
			
				//absolutely positioned DOMElement are positioned relative to the margin box
				//of their parent and not the content box, so an offset need to be applied
				//
				//TODO : to check : shouldn't it be relative to the padding box instead ?
				switch (boxElementData.element)
				{
					case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
						if (domElement.style.isRelativePositioned() == false)
						{
							boxElementData.x -= _computedStyle.paddingLeft + _computedStyle.marginLeft;
							boxElementData.y -= _computedStyle.marginTop + _computedStyle.paddingTop;
						}
						
					case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
						if (domElement.style.isRelativePositioned() == false)
						{
							boxElementData.x -= _computedStyle.paddingLeft + _computedStyle.marginLeft;
							boxElementData.y -= _computedStyle.marginTop + _computedStyle.paddingTop;
						}	
						
					case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
						if (domElement.style.isRelativePositioned() == false)
						{
							boxElementData.x -= _computedStyle.paddingLeft + _computedStyle.marginLeft;
							boxElementData.y -= _computedStyle.marginTop + _computedStyle.paddingTop;
						}	
					default:	
				}
			
				boxElementsData.push(boxElementData);
			}
		}
		
		return boxElementsData;
	}
	
	/**
	 * Insert a TextElement (a string of text without formatting) by creating as many TextFragmentDOMElement as needed from it
	 * and inserting them into the flow
	 * @param	textElement the string of text used as content for the created text lines
	 */
	private function insertTextElement(textElement:TextElement, formattingContext:FormattingContext, containingDOMElementData:ContainingDOMElementData):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		//get the text to display from the TextElement
		var text:String = textElement.text;
		
		//split the text into an array of text token
		var textFragments:Array<TextFragmentData> = textElement.getTextFragments(text);
		
		//loop through the text tokens
		for (i in 0...textFragments.length)
		{
			switch(textFragments[i].textToken)
			{
				case word(value):
					//insert a word in the flow
					formattingContext.insertElement(BoxElementValue.text(getTextFragmentDOMElement(textFragments[i], value), this._domElement));
					
					
				case space:
					//insert a space in the flow
					formattingContext.insertElement(BoxElementValue.space(_computedStyle.whiteSpace, fontMetrics.spaceWidth, this._domElement));
					
					
				case tab:
					//insert a tab in the flow
					formattingContext.insertElement(BoxElementValue.tab(_computedStyle.whiteSpace, fontMetrics.spaceWidth * 8, this._domElement));
					
					
				case lineFeed:
					//start a new line
					formattingContext.insertElement(BoxElementValue.lineFeed(_computedStyle.whiteSpace, this._domElement));
			}
		}		
	}
	
	/**
	 * In certain cases, when the width of the ContainerDOMElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * @param	containingDOMElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this ContainerDOMElement which will be the minimum width that should
	 * have this DOMElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.shrinkToFit(this, containingDOMElementData, minimumWidth);
	}
	
	/**
	 * In most cases, when the height of a ContainerDOMElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	containingDOMElementData
	 * @param	childrenHeight the total height of the children once laid out
	 */
	private function applyContentHeightIfNeeded(containingDOMElementData:ContainingDOMElementData, childrenHeight:Int):Int
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.applyContentHeight(this, containingDOMElementData, childrenHeight);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When invalidating text on a ContainerDOMElement, the created TextFragmentDOMElement
	 * must be deleted so that they can be redrawn on next layout
	 */
	override public function invalidateText():Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.resetTextFragments();	
		super.invalidateText();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE TEXT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Take a TextFragmentData and a text, and create
	 * a TextFragmentDOMElement from it if it doesn't already
	 * exists. If it does, return it
	 */
	private function getTextFragmentDOMElement(textFragmentData:TextFragmentData, text:String):TextFragmentDOMElement
	{
		var textFragmentDOMElement:TextFragmentDOMElement;
		
		if (textFragmentData.textFragmentDOMElement == null)
		{
			textFragmentDOMElement = createTextFragment(text);
			textFragmentData.textFragmentDOMElement = textFragmentDOMElement;
		}
		else
		{
			textFragmentDOMElement = textFragmentData.textFragmentDOMElement;
		}
		
		return textFragmentDOMElement;
	}
	
	/**
	 * Create a TextFragmentDOMElement from a string of text and
	 * add it to the ContainerDOMElement
	 */
	private function createTextFragment(text:String):TextFragmentDOMElement
	{
		var textFragmentDOMElement:TextFragmentDOMElement = doCreateTextFragment(text);
	
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.addTextFragment(textFragmentDOMElement);
		
		return  textFragmentDOMElement;
	}
	
	/**
	 * Actually create the TextFragmentDOMElement using runtime
	 * specific API. Overriden by each runtime
	 */
	private function doCreateTextFragment(text:String):TextFragmentDOMElement
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the dimensions data
	 * of the ContainerDOMElement
	 */
	public function getContainerDOMElementData():ContainingDOMElementData
	{
		var height:Int;
		
		//if the ContainerDOMElement
		//is inline level, then its line height will
		//be used to lay out its children in lines
		if (isInlineLevel() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//same if the ContainerDOMElement establishes
		//an inline formatting context
		else if (establishesNewFormattingContext() == true && childrenInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//else it either establishes a block formatting context or participate
		//in one and its height is used
		else
		{
			height = this._computedStyle.height;
		}
		
		return {
			width:this._computedStyle.width,
			isWidthAuto:this._width == DimensionStyleValue.autoValue,
			height:height,
			isHeightAuto:this._height == DimensionStyleValue.autoValue
		};
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the right formatting context to layout this ContainerDOMElement
	 * children.
	 * 
	 * A ContainerDOMElement can either establish a new formatting context
	 * or participate in the current formatting context. If it participates
	 * in the current formatting context, then the previous formatting
	 * is returned else a new block or inline formatting context is
	 * instantiated
	 * 
	 * @param	previousformattingContext the formatting context of the parent of this
	 * Container DOMElement, might be returned if the container DOMElement participates
	 * in the same formatting context as its parent
	 * 
	 * @return an inline or block formatting context
	 */
	private function getformattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		var formattingContext:FormattingContext;
		
		//here, a new formatting context is created
		if (establishesNewFormattingContext() == true || previousformattingContext == null)
		{
			//instantiate the right formatting context
			//based on the children computed display styles
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(containerDOMElement);	
			}
			else
			{
				formattingContext = new BlockFormattingContext(containerDOMElement);
			}
		}
		else
		{
			formattingContext = previousformattingContext;
		}
		
		return formattingContext;
	}
	
	/**
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * TODO : throw exception when there is a float in the children
	 * 
	 * @return true if all children are inline level DOMElements
	 */
	private function childrenInline():Bool
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//return false for a container with no children
		if (containerDOMElement.children.length == 0)
		{
			return false;
		}
		
		//establish if the first child is inline or block
		//all other child must be of the same type
		var ret:Bool = isChildInline(containerDOMElement.children[0]);
		
		//loop in all children and throw an exception
		//if one the children is not of the same type as the first
		for (i in 0...containerDOMElement.children.length)
		{
			if (isChildInline(containerDOMElement.children[i]) != ret)
			{
				//throw "children of a block container can only be either all block or all inline";
			}
		}
		
		return ret;
	}
	
	/**
	 * Determine wether a children is inline or not
	 */
	private function isChildInline(child:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = true;
		
		//here the children is a DOMElement
		if (isDOMElement(child))
		{
			var childrenDOMElement:DOMElement = cast(child.child);
			//here the child is of type block
			if (childrenDOMElement.style.computedStyle.display == block)
			{
				//floated children are not taken into account 
				if (childrenDOMElement.style.isFloat() == false)
				{
					ret = false;
				}
				//absolutely positioned children are not taken into account but relative positioned are
				else if (childrenDOMElement.style.isPositioned() == false || childrenDOMElement.style.isRelativePositioned() == true)
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
		//here the children is a textElement, which is
		//always inline as text is always displayed on a line
		else
		{
			ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the structure used to layout absolutely positioned
	 * children. If this ContainerDOMElement is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildLastPositionedDOMElementData(lastPositionedDOMElementData:LastPositionedDOMElementData):LastPositionedDOMElementData
	{
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		if (isPositioned() == true)
		{
			childLastPositionedDOMElementData = {
				data: getContainerDOMElementData(),
				children: new Array<PositionedDOMElementData>()
			}
		}
		else
		{
			childLastPositionedDOMElementData = lastPositionedDOMElementData;
		}
		
		return childLastPositionedDOMElementData;
	}
	
	/**
	 * Determine wether the ContainerDOMElement
	 * establishes a new formatting context for
	 * its children
	 */
	private function establishesNewFormattingContext():Bool
	{
		var ret:Bool = false;
		
		//floats always establishes new context
		if (isFloat() == true)
		{
			ret = true;
		}
		//positioned element which are not relative always establishes new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			ret = true;
		}
		//element with an inline-block display style
		//alwyas establishes a new context
		else
		{
			switch (this._computedStyle.display)
			{
				case inlineBlock:
				ret = true; 
				//a block DOMElement may start a new inline
				//formatting context if all its children are inline,
				//else its children participate in the current block formatting
				//context
				case block:
					if (childrenInline() == true)
					{
						ret = true;
					}
					
				default:
			}
		}
		
		//in the other cases such as an inline level inline container
		//the current formatting context is used
		
		return ret;
	}
	
	/**
	 * Determine wheter the container DOMElement
	 * is an inline or block container. For instance,
	 * an inline-block containerDOMElement is both
	 * inline level (because it is placed on a line) and
	 * a block container, because it can layout its
	 * children either into either a block or
	 * inline formatting context. An inline container
	 * can only lay out its children into an
	 * inline formatting context
	 */
	private function isInlineContainer():Bool
	{
		var ret:Bool;
		
		switch(this._computedStyle.display)
		{ 
			case block, inlineBlock:
				ret = false;
				
			case inlineStyle:
				ret = true;
				
			default:
				ret = true;
		}
		
		return ret;
	}
	
	/**
	 * Return the computed height of the ContainerDOMElement.
	 * Use as a hook to be overriden by the BodyStyle
	 * to return the viewport height
	 */
	private function getComputedHeight():Int
	{
		return this._computedStyle.height;
	}
	
	/**
	 * Determine wether the given children is a 
	 * DOMElement or a TextElement
	 */
	private function isDOMElement(containerDOMElementChildData:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = false;
		
		switch (containerDOMElementChildData.type)
		{
			case ContainerDOMElementChildValue.domElement:
				ret = true;
			
			case ContainerDOMElementChildValue.textElement:
				ret = false;
		}
		
		return ret;
	}
	
}