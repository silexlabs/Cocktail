 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.layout.LayoutManager;
import cocktail.core.linebox.LineBox;

import cocktail.core.layout.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.BoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import cocktail.core.font.FontData;

/**
 * This is a base class for ElementRenderer which are
 * container such as the block box and inline box.
 * 
 * It takes cares of laying out its children
 * 
 * @author Yannick DOMINGUEZ
 */
class FlowBoxRenderer extends BoxRenderer 
{
	/**
	 * holds a reference to each positioned child
	 * for which this FlowBoxRenderer is the first
	 * positioned ancestor.
	 * 
	 * Positioned children register and unregister
	 * themselves when attached and detached
	 */
	private var _positionedChildren:Array<ElementRenderer>;
	
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_positionedChildren = new Array<ElementRenderer>();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return all the LineBoxes created by this ElementRenderer
	 * in one line, as an array of LineBoxes
	 */
	private function getLineBoxesInLine(rootLineBox:LineBox):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		var length:Int = rootLineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = rootLineBox.childNodes[i];
			ret.push(child);
			
			if (child.hasChildNodes() == true)
			{
				var childLineBoxes:Array<LineBox> = getLineBoxesInLine(child);
				
				var childLength:Int = childLineBoxes.length;
				for (j in 0...childLength)
				{
					ret.push(childLineBoxes[j]);
				}
			}
		}
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Used by positioned children to register themselves to their
	 * first positioned ancestor so that they can be laid out by it.
	 * Called when the children are attached
	 */
	public function addPositionedChildren(element:ElementRenderer):Void
	{
		_positionedChildren.push(element);
	}
	
	/**
	 * The positioned children unregister themselves when they 
	 * are detached
	 */
	public function removePositionedChild(element:ElementRenderer):Void
	{
		_positionedChildren.remove(element);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overridenas FlowBoxRenderer are also responsible
	 * for laying out their children
	 */
	override public function layout(forceLayout:Bool):Void
	{
		super.layout(forceLayout);
		
		//layout all the in flow children (non positioned or floated)
		layoutChildren();
		
		if (_positionedChildrenNeedLayout == true || forceLayout == true)
		{
			//if this ElementRenderer is positioned, it means that it is the first positioned ancestor
			//for its positioned children and it is its responsability to lay them out
			if (isPositioned() == true)
			{
				layoutPositionedChildren();
			}
			_positionedChildrenNeedLayout = false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually layout all the children of the ElementRenderer by calling
	 * the layout on all the children
	 */
	private function layoutChildren():Void
	{
		var childNodes:Array<ElementRenderer> = this.childNodes;
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].layout(_childrenNeedLayout);
		}
	}
	
	private function layoutPositionedChildren():Void
	{
		var containerBlockData:ContainingBlockVO = getContainerBlockData();
		var windowData:ContainingBlockVO = getWindowData();
		
		//lay out each stored children
		var length:Int = _positionedChildren.length;
		for (i in 0...length)
		{
			//layout the child ElementRenderer which set its x and y positioned origin in the space of this ElementRenderer's
			//positioned origin
			layoutPositionedChild(_positionedChildren[i], containerBlockData, windowData);
		}
	}
	
	/**
	 * layout an absolutely positioned ElementRenderer (with a position style of 'fixed' or 'absolute')
	 * using either the first positioned ancestor dimensions or the viewport's
	 * 
	 * @param firstPositionedAncestorData the dimensions of the first positioned ancestor
	 * @param viewportData the dimensions of the viewport
	 */
	private function layoutPositionedChild(elementRenderer:ElementRenderer, firstPositionedAncestorData:ContainingBlockVO, viewportData:ContainingBlockVO):Void
	{
		var coreStyle:CoreStyle = elementRenderer.coreStyle;
		switch (coreStyle.getKeyword(elementRenderer.coreStyle.position))
		{	
			//positioned 'fixed' ElementRenderer, use the viewport
			case FIXED:
				doLayoutPositionedChild(elementRenderer, viewportData);
				
			//positioned 'absolute' ElementRenderer use the first positioned ancestor data	
			case ABSOLUTE:
				doLayoutPositionedChild(elementRenderer, firstPositionedAncestorData);
				
			default:
		}
	}
	
	/**
	 * Actually lay out the positioned ElementRenderer
	 */
	private function doLayoutPositionedChild(elementRenderer:ElementRenderer, containingBlockData:ContainingBlockVO):Void
	{
		var elementCoreStyle:CoreStyle = elementRenderer.coreStyle;

		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (elementCoreStyle.isAuto(elementCoreStyle.left) == false)
		{
			elementRenderer.positionedOrigin.x = getLeftOffset(elementRenderer);
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing block width minus the
		//width of the positioned children as value for a 0 right offset
		else if (elementCoreStyle.isAuto(elementCoreStyle.right) == false)
		{
			elementRenderer.positionedOrigin.x = getRightOffset(elementRenderer, containingBlockData.width);
		}
		//if both right and left are 'auto', then the ElementRenderer is positioned to its
		//static position, the position it would have had in the flow if it were positioned as 'static'.
		//At this point the bounds of the ElementRenderer already matches its static position
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (elementCoreStyle.isAuto(elementCoreStyle.top) == false)
		{
			elementRenderer.positionedOrigin.y = getTopOffset(elementRenderer);
		}
		else if (elementCoreStyle.isAuto(elementCoreStyle.bottom) == false)
		{
			elementRenderer.positionedOrigin.y = getBottomOffset(elementRenderer, containingBlockData.height);
		}
	}
	
	/**
	 * get the left offset to apply the ElementRenderer
	 */
	private function getLeftOffset(elementRenderer:ElementRenderer):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		return usedValues.left + usedValues.marginLeft;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(elementRenderer:ElementRenderer, containingHTMLElementWidth:Float):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		return containingHTMLElementWidth - usedValues.width - usedValues.paddingLeft
		- usedValues.paddingRight - usedValues.right - usedValues.marginRight;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(elementRenderer:ElementRenderer):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		return usedValues.top + usedValues.marginTop;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(elementRenderer:ElementRenderer, containingHTMLElementHeight:Float):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		return containingHTMLElementHeight - usedValues.height - usedValues.paddingTop -
		usedValues.paddingBottom - usedValues.bottom;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the children of this ElementRenderer
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * @return true if at least one child is inline level
	 */
	override public function childrenInline():Bool
	{	
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			
			if (child.isInlineLevel() == true)
			{
				//floated and absolutely positioned element are not taken into
				//account
				if (child.isFloat() == false)
				{
					if (child.isPositioned() == false || child.isRelativePositioned() == true)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}