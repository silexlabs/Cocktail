package cocktail.style.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.InLineBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.formatter.BlockFormattingContext;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.positioner.AbsolutePositioner;
import cocktail.style.positioner.BoxPositioner;
import cocktail.style.positioner.FixedPositioner;
import cocktail.style.positioner.RelativePositioner;
import cocktail.style.StyleData;

#if flash9
import cocktail.style.as3.Style;
#elseif js
import cocktail.style.js.Style;
#end

import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractContainerStyle extends Style
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		flow(containingDOMElementDimensions, null, true);
		positionElement(lastPositionedDOMElement, rootDOMElement);
	}
	
	override public function flow(containingDOMElementDimensions:ContainingDOMElementDimensions, formatingContext:FormattingContext = null, initialContainer:Bool = false):Void
	{
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		computePositionStyle();
		
		this._computedStyle = computeBoxModelStyle(containingDOMElementDimensions);
		
		if (this._computedStyle.display == DisplayStyleValue.none)
		{
			this._domElement.isVisible = false;
			return;
		}
		
		
		for (i in 0...containerDOMElement.children.length)
		{
			containerDOMElement.children[i].style.computePositionStyle();
		}
		
		var childrenFormattingContext:FormattingContext;
		
		if (initialContainer == true)
		{
			formatingContext = FormattingContext.getFormatingContext(containerDOMElement, formatingContext);
			childrenFormattingContext = formatingContext;
			

		}
		else if (formatingContext.beginNewFormattingContext(containerDOMElement))
		{
			childrenFormattingContext = FormattingContext.getFormatingContext(containerDOMElement, formatingContext);		
			
			containingDOMElementDimensions = {
			width:this._computedStyle.width,
			height:this._computedStyle.height
		}
		}
		else
		{
			childrenFormattingContext = formatingContext;
		}
		
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.isFloat() == true)
			{
				childrenFormattingContext.insertFloat(containerDOMElement.children[i]);
			}
		}
		

		
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.isFloat() == false)
			{
				if (containerDOMElement.children[i].style.isClear())
				{
					formatingContext.clearFloat(containerDOMElement.children[i].style.computedStyle.clear);
				}
				containerDOMElement.children[i].style.flow(containingDOMElementDimensions, childrenFormattingContext);
			}
		}
		
		if (isInline() == false && this._computedStyle.height == -1)
		{
			
			this._computedStyle.height = childrenFormattingContext.flowData.totalHeight;
		}
		
		this._domElement.width = this._computedStyle.width;
		this._domElement.height = this._computedStyle.height;
		
		
		if (isPositioned() == false || isRelativePositioned() == true)
		{
			if (initialContainer == false)
			{
				formatingContext.insert(this._domElement);
			}
			
			
		}
		
		
	}
	
	override public function positionElement(lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		if (isPositioned() == true)
		{
			lastPositionedDOMElement = this._domElement;
		}
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		for (i in 0...containerDOMElement.children.length)
		{
			var childDOMElement:DOMElement = containerDOMElement.children[i];
			
			childDOMElement.style.positionElement(lastPositionedDOMElement, rootDOMElement);
			
						
			if (childDOMElement.style.isPositioned() == true)
			{
				var positioner:BoxPositioner;
				if (childDOMElement.style.isRelativePositioned() == true)
				{
					positioner = new RelativePositioner();
					positioner.position(childDOMElement, lastPositionedDOMElement);
				}
				else
				{
					switch (childDOMElement.style.computedStyle.position)
					{
						case fixed:
							positioner = new FixedPositioner();
							positioner.position(childDOMElement, rootDOMElement);
							
						case absolute:
							positioner = new AbsolutePositioner();
							positioner.position(childDOMElement, lastPositionedDOMElement);
							
						default:	
							positioner = new AbsolutePositioner();
					}
				}
				
			}
		}
		
	}
	
	public function isInlineFlow():Bool
	{
		var ret:Bool = false;
		
		switch(this._computedStyle.display)
		{
			case _inline:
				ret = true;
				
			default:
				ret = childrenInline();
		}
		
		return ret;
	}
	
	public function childrenInline():Bool
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		var ret:Bool = true;
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.computedStyle.display == block)
			{
				ret = true;
			}
		}
		
		return ret;
	}
	
}