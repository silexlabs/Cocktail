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
 * also start the layout on each of its children
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerStyle extends Style
{
	/**
	 * Store a reference to the formatting context used to format
	 * in-flow children. It is used when rendering to compute all
	 * the boxes into which this styled DOMElement is lad out.
	 */
	private var _childrenFormattingContext:FormattingContext;
	
	/**
	 * Stores a reference ot each of the absolutely positioned children that
	 * must be attached to this styled ContainerDOMElement. The array only has
	 * children if this styled ContainerDOMElement is itself positioned
	 */
	private var _absolutelyPositionedChildrenTemporaryPositionsData:Array<ChildTemporaryPositionData>;
	
	/**
	 * class constructor
	 * @param	domElement
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
		
		//get the boxes data from the formatting context which was used to layout the children of this ContainerDOMElement
		var boxesData:Array<BoxData> = _childrenFormattingContext.getBoxesData(this._domElement);
		
		//will contain all the NativeElements which must be attached to this ContainerDOMElement
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		//for each box, render the background, border and
		//the children of each box
		for (i in 0...boxesData.length)
		{
			var boxNativeElements:Array<NativeElement> = renderBox(boxesData[i], i == 0);
			
			for (j in 0...boxNativeElements.length)
			{
				nativeElements.push(boxNativeElements[j]);
			}
		}
		
		//render the absolutely positioned children of this ContainerDOMElement
		var absolutelyPositionedNativeElements:Array<NativeElement> = renderChildren(_absolutelyPositionedChildrenTemporaryPositionsData);
		
		for (i in 0...absolutelyPositionedNativeElements.length)
		{
			nativeElements.push(absolutelyPositionedNativeElements[i]);
		}
		
		//store the nativeElements so that they can be detached on next layout
		_nativeElements = nativeElements;
		
		//do attach the nativeElements using runtime specific API
		attachNativeElements(nativeElements);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render one box of the DOMElement and return the resulting
	 * nativeElements which must be attached to this styled
	 * ContainerDOMElement
	 * @param	box
	 * @param firstBox determine wether the first box of the DOMElement is being rendered
	 * @return
	 */
	private function renderBox(box:BoxData, firstBox:Bool):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		//if the ContainerDOMElement is an inline container, then each 
		//boxs need its own background, else it should only have one box
		//which has the same dimensions as the ContainerDOMElement, so
		//only the first box is rendered
		//
		//TODO : improve 'firstBox', it should be done before
		if (isInlineContainer() == true || firstBox == true)
		{
			//render the background of the box
			var backgroundNativeElements:Array<NativeElement> = renderBackground(box, this);
		
			for (i in 0...backgroundNativeElements.length)
			{
				nativeElements.push(backgroundNativeElements[i]);
			}
		}
	
		
		//render each children of the box which are all in-flow DOMElements
		var inFlowChildrenNativeElements:Array<NativeElement> = renderChildren(box.children);
		for (i in 0...inFlowChildrenNativeElements.length)
		{
			nativeElements.push(inFlowChildrenNativeElements[i]);
		}
		
		return nativeElements;
	}
	
	/**
	 * Render the background of the box and return an array
	 * containing the background color if any and all
	 * the background images if any
	 * @param	box
	 * @param	style
	 * @return
	 */
	private function renderBackground(box:BoxData, style:AbstractStyle):Array<NativeElement>
	{
		box.bounds = getBounds(box);
		return _backgroundManager.render(box.bounds, style);
	}
	
	/**
	 * Render an array of child by applying their computed layout position and 
	 * returnin gall of their nativeElements
	 * 
	 * @param	children
	 * @return
	 */
	private function renderChildren(children:Array<ChildTemporaryPositionData>):Array<NativeElement>
	{
		var childrenNativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...children.length)
		{
			var child:ChildTemporaryPositionData = children[i];
			
			//apply x and y
			child.domElement.style.setNativeX(child.domElement, child.x + _computedStyle.marginLeft + _computedStyle.paddingLeft);
			child.domElement.style.setNativeY(child.domElement, child.y + _computedStyle.marginTop + _computedStyle.paddingTop);
			
			childrenNativeElements.push(child.domElement.nativeElement);
		}
		
		return childrenNativeElements;
	}
	
	/**
	 * Get the bound of a box in the coordinate space
	 * of this styled ContainerDOMElement
	 * @param	boxData
	 * @return
	 */
	private function getBounds(boxData:BoxData):RectangleData
	{
		var bounds:RectangleData;
		
		//if the ContainerDOMElement is an inline container, then
		//it is itself placed at the origin of its formatting context
		//Its bounds are determined by the area formed by its children
		if (isInlineContainer() == true)
		{
			var left:Float = 50000;
			var top:Float = 50000;
			var right:Float = -50000;
			var bottom:Float = -50000;
			
			
			for (i in 0...boxData.children.length)
			{
				//TODO : do not compute child if it is an
				//inline container as its x will be 0
				if (boxData.children[i].position == true)
				{
					if (boxData.children[i].x < left)
					{
						left = boxData.children[i].x;
					}
					if (boxData.children[i].y < top)
					{
						//TODO : probably won't be robust enough
						top = boxData.children[i].y - fontMetrics.ascent - fontMetrics.descent;
					}
					if (boxData.children[i].x + boxData.children[i].width > right)
					{
						right = boxData.children[i].x + boxData.children[i].width;
					}
					if (boxData.children[i].y + boxData.children[i].height > bottom)
					{
						bottom = boxData.children[i].y + boxData.children[i].height -  fontMetrics.ascent - fontMetrics.descent;
					}
				}
			}
			
				bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
				
			}
		
		//if the container is a block container, then its box is formed from its own
		//width and height
		else
		{
			var width:Float = _domElement.offsetWidth;
			var height:Float = _domElement.offsetHeight;
			
			bounds = {
					x:0.0,
					y:0.0,
					width : width,
					height :  height,
				}
		}
		
		return bounds;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerDOMElement. The ContainerDOMElement
	 * will be measured and placed as well as all of its children.
	 * 
	 * Once all the layout is done, then the ContainerDOMElement and its children are rendered
	 */
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{		
		flow(containingDOMElementData, viewportData, lastPositionedDOMElementData, null, null);
		render();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
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
			//to be inline as they are always laid out on a line and when rendered,
			//they use the ContainerDOMElement's styles
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
		var childrenFormattingContext:FormattingContext;
		
		//if the FormattingContext is null, this ContainerDOMElement
		//is the first to be laid out, it is not necessarily the root
		//DOMElement of the document as any DOMElement can trigger
		//a layout
		if (formattingContext == null)
		{
			formattingContext = getformattingContext();
			childrenFormattingContext = getformattingContext();
		}
		else
		{
			childrenFormattingContext = getformattingContext(formattingContext);
		}
		
		//get the dimensions that will be used to lay out the children
		//of the DOMElement. For instance, if the ContainerDOMElement establishes an
		//inline formatting context, then its lineHeight will be used
		//instead of its height as containing height
		var childrenContainingDOMElementData:ContainingDOMElementData = getContainerDOMElementData();
		
		//get the computed font metrics of the ContainerDOMElement. Those metrics
		//are based on the font and the font size used
		var childrenContainingDOMElementFontMetricsData:FontMetricsData = this.fontMetrics;
		
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children
		var childLastPositionedDOMElementData:LastPositionedDOMElementData;
		
		//if the ContainerDOMElement is positioned, it becomes the last positioned DOMElement for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this ContainerDOMElement is laid out, it will position all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this ContainerDOMElement are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the ContainerDOMElement as reference
		childLastPositionedDOMElementData = getChildLastPositionedDOMElementData(lastPositionedDOMElementData);
		
		//flow all children and store their laid out position relative to this styled DOMElement
		childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);

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
				childrenFormattingContext = doFlowChildren(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
		}
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized. Fort some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		if (this._height == DimensionStyleValue.autoValue)
		{
			this._computedStyle.height = applyContentHeightIfNeeded(containingDOMElementData, childrenFormattingContext.formattingContextData.maxHeight);
		}

		//retrieve the floats overflowing from the children of this ContainerDOMElement, 
		//that will also affect the position of its following siblings
		formattingContext.retrieveFloats(childrenFormattingContext);
		
		//if this ContainerDOMElement is positioned, it means that it is the first positioned ancestor
		//for its children and it is its responsability to position them. An array containing all their
		//laid out positions is returned and stored, to be sued during rendering
		_absolutelyPositionedChildrenTemporaryPositionsData = doPositionAbsolutelyPositionedDOMElements(isPositioned(), childLastPositionedDOMElementData, viewportData);

		//the array containing all the children of this ContainerDOMElement and their
		//positions relative to the ContainerDOMElement is stored, to be used
		//during rendering
		_childrenFormattingContext = childrenFormattingContext;
	}
	
	/**
	 * If the ContainerDOMElement doesn't start a new formatting context, it is
	 * added to the flow, however it won't be place, so that the corresponding
	 * nativeElement will be located at the origin of the formatting context
	 * once rendered
	 * 
	 * @param render a relative positioned DOMElement is inserted into the flow, like a
	 * static DOMElement but it is not rendered in the flow, as it will
	 * already be rendered as an absolute DOMElement which is always visually on top
	 * of the static DOMElement in the same formatting context
	 */
	override private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{

		var render:Bool = isRelativePositioned() == false;
		
		if (establishesNewFormattingContext() == true)
		{
			formattingContext.insertDOMElement(this._domElement, this._domElement.parent);
		}
		else
		{
			formattingContext.insertNonLaidOutDOMElement(this._domElement, this._domElement.parent);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually flow all the children of the ContainerDOMElement
	 */
	private function doFlowChildren(childrenContainingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, childLastPositionedDOMElementData:LastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//TODO : improve, put in a separate method ?
			if (establishesNewFormattingContext() == false && isInlineContainer() == true)
			{
				childrenFormattingContext.insertOffset(_computedStyle.marginLeft + _computedStyle.paddingLeft);
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
				childrenDOMElement.style.flow(childrenContainingDOMElementData, viewportData, childLastPositionedDOMElementData, childrenContainingDOMElementFontMetricsData, childrenFormattingContext);
			}
			//else if it is a TextElement, call a method that will create as many TextFragmentDOMElement
			//as necessary to render the TextElement and insert them into the document
			else 
			{
				var childrenTextElement:TextElement = cast(containerDOMElement.children[i].child);
				insertTextElement(childrenTextElement, childrenFormattingContext, childrenContainingDOMElementData);
			}
			
		
			
		}
		
			//TODO : improve, put in a separate method ?
			if (establishesNewFormattingContext() == false  && isInlineContainer() == true)
			{
				childrenFormattingContext.insertOffset(_computedStyle.marginRight + _computedStyle.paddingRight);
			}
		
		//destroy the current formatting context, prompting
		//to clean up all references it might have and also
		//lays out the last line of DOMElement for an
		//inline formatting context
		//This method is only called if a new formatting
		//context was established by this ContainerDOMElement,
		//meaning that it also is responsible to "clean" it.
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.destroy();
		}

		return childrenFormattingContext;
	}
	
	/**
	 * When this ContainerDOMElement is positioned, position each of its children using it
	 * as its origin. This method is called once all the dimensions of ContainerDOMElement
	 * are known so that absolutely positioned children can be positioned using the bottom
	 * and right styles
	 */
	private function doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor:Bool, childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Array<ChildTemporaryPositionData>
	{
		var childrenTemporaryPositionData:Array<ChildTemporaryPositionData> = new Array<ChildTemporaryPositionData>();
		
		if (isFirstPositionedAncestor == true)
		{
			//update the data of the ContainerDOMElement now that its width and height are known
			childLastPositionedDOMElementData.data = getContainerDOMElementData();
			
			//ensure that the actual height of the ContainerDOMElement is used instead of its lineHeight
			childLastPositionedDOMElementData.data.height = this._computedStyle.height;
			
			//position each stored children
			for (i in 0...childLastPositionedDOMElementData.children.length)
			{
				var positionedDOMElementData:PositionedDOMElementData = childLastPositionedDOMElementData.children[i];
				
				//relatively positioned DOMElement are both stored in the childLastPositionedDOMElementData array and
				//also inserted in a formatting context. At this point, their static position must be retrieved form
				//the formatting context which formatted the relative DOMElement
				if (positionedDOMElementData.style.isRelativePositioned() == true)
				{
					//all the in-flow children that share the same parent in the stored
					//formatting context are retrieved
					var childrenBoxesData:Array<BoxData> = positionedDOMElementData.formattingContext.getBoxesData(positionedDOMElementData.style.domElement.parent);
					
					//loop in all the children to find a reference
					//to the relative positioned DOMElement
					for (i in 0...childrenBoxesData.length)
					{
						for (j in 0...childrenBoxesData[i].children.length)
						{
							//when found, use its in-flow position as the static position used for
							//relative positioned DOMElement
							if (childrenBoxesData[i].children[j].domElement == positionedDOMElementData.style.domElement)
							{
								var x:Float = childrenBoxesData[i].children[j].x;
								var y:Float = childrenBoxesData[i].children[j].y;
								positionedDOMElementData.staticPosition = {
									x:x,
									y:y
								}
							}
						}
						
					}
				}
				
				//now the static position of all the positioned DOMElement must be updated as they
				//are in their formatting context space and they must be converted to this
				//ContainerDOMElement space, as they will be attached to it
				
				//the domElement which started the formatting context of the child is retrieved
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
				var childTemporaryPositionData:ChildTemporaryPositionData = positionedDOMElementData.style.positionElement(childLastPositionedDOMElementData.data, viewportData, positionedDOMElementData.staticPosition );
			
				//absolutely positioned DOMElement are positioned relative to the margin box
				//of their parent and not the content box, so an offset need to be applied
				if (childTemporaryPositionData.domElement.style.isRelativePositioned() == false)
				{
					childTemporaryPositionData.x -= _computedStyle.paddingLeft + _computedStyle.marginLeft;
					childTemporaryPositionData.y -= _computedStyle.marginTop + _computedStyle.paddingTop;
				}
				
				childrenTemporaryPositionData.push(childTemporaryPositionData);
			}
		}
		
		return childrenTemporaryPositionData;
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
		
		//apply the white space rule defined by the WhiteSpaceStyleValue to the text
		text = AbstractTextElement.applyWhiteSpace(text, this._computedStyle.whiteSpace);
		
		//split the text into an array of text token
		var textFragments:Array<TextFragmentData> = textElement.getTextFragments(text);
		
		//loop through the text tokens
		for (i in 0...textFragments.length)
		{
			switch(textFragments[i].textToken)
			{
				case word(value):
					//insert a word in the flow
					formattingContext.insertText(getTextFragmentDOMElement(textFragments[i], value), this._domElement);
					
					
				case space:
					//insert a space in the flow
					formattingContext.insertSpace(_computedStyle.whiteSpace, fontMetrics.spaceWidth);
					
					
				case tab:
					//insert a tab in the flow
					formattingContext.insertTab(_computedStyle.whiteSpace, fontMetrics.spaceWidth * 8);
					
					
				case lineFeed:
					//start a new line
					formattingContext.insertLineFeed(_computedStyle.whiteSpace);
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
	 * Return the dimensions and position data
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
		//same if the ContainerDOMElement starts
		//an inline formatting context
		else if (isInlineLevel() == false && childrenInline() == true)
		{
			height = Math.round(this._computedStyle.lineHeight);
		}
		//else it starts a block formatting context
		//and its height is used
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
		if (establishesNewFormattingContext() == true)
		{
			//the formatting context that will be passed to the
			//new formatting context
			var usedformattingContext:FormattingContext;
			
			//If the container DOMElement is absolutely positioned, then it belongs to a
			//different stacking context than the curent flow and is not influenced by the previously
			//declared float, so it doesn't use the previousFormattingContext
			if (isPositioned() == true && isRelativePositioned() == false)
			{
				usedformattingContext = null;
			}
			else
			{
				usedformattingContext = previousformattingContext;
			}
			
			//instantiate the right formatting context
			//based on the children display
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(containerDOMElement, usedformattingContext);	
			}
			else
			{
				formattingContext = new BlockFormattingContext(containerDOMElement, usedformattingContext);
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
		
		if (this.isPositioned() == true)
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
	 * Determine wether a block container
	 * starts a new formatting context for
	 * its children
	 */
	private function establishesNewFormattingContext():Bool
	{
		var ret:Bool = false;
		
		//floats starts new context
		if (isFloat() == true)
		{
			ret = true;
		}
		//positioned element which are not relative start new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			ret = true;
		}
		//element with an inline-block display style
		//start a new context
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