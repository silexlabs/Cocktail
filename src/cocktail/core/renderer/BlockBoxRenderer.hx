 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.InitialStyleDeclaration;
import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.linebox.LineBox;
import cocktail.port.DrawingManager;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.formatter.InlineFormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;
import cocktail.port.GraphicsContext;
import haxe.Log;
import cocktail.core.layer.LayerRenderer;

/**
 * A block box renderer is an element which participate
 * in a block formatting context and which can establish
 * either a block or inline formatting context.
 * 
 * When it starts an inline formatting context, it holds
 * an array of root line box which are the start of
 * each of the lines created by this block box.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockBoxRenderer extends ScrollableRenderer
{	
	/**
	 * flag set when replacing inline children by anonymous block
	 * to prevent inifinite loop caused by calls to appendChild
	 */
	private var _isMakingChildrenNonInline:Bool;
	
	/**
	 * class constructor.
	 * Init class attributes
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_isMakingChildrenNonInline = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden to replace inline children by anonymous block if
	 * necessary
	 */
	override public function appendChild(newChild:ElementRenderer):ElementRenderer
	{
		//flag determining wether inline children must be wrapped
		//in anonymous block
		var shouldMakeChildrenNonInline:Bool = false;
		
		var elementRendererChild:ElementRenderer = newChild;

		//if this is the first child, no need to wrap inline block
		//as it not yet known wether this block box starts an inline
		//formatting context or participates/establishes a block
		//formatting context
		if (childNodes.length > 0)
		{
			//absolutely positioned children are not taken into account when determining wether this
			//BlockBoxRenderer establishes/participate in a block or inline formatting context
			if (elementRendererChild.isPositioned() == false || elementRendererChild.isRelativePositioned() ==  true)
			{	
				//the BlockBoxRenderer should have at least one significant child to determine wether to 
				//establish/participate in a block or inline formatting context, and thus if inline children
				//shoud be wrapped in anonymous block
				if (hasSignificantChild() == true)
				{
					//if the new child is doesn't match the display of the other children,
					///for instance if it is the first inline while all the other
					//children are block, all the inline children should be wrapped
					if (elementRendererChild.isInlineLevel() != childrenInline())
					{
						shouldMakeChildrenNonInline = true;
					}
				}
			}
		}
		
		//append the new child
		super.appendChild(newChild);
		//make all children non inline if necessary
		if (shouldMakeChildrenNonInline == true)
		{	
			//check the flag to prevent infinite loop,
			//as makeChildrenNonInline itself call the 
			//appendChild method
			if (_isMakingChildrenNonInline == false)
			{
				_isMakingChildrenNonInline = true;
				makeChildrenNonInline();
				_isMakingChildrenNonInline = false;
			}
		}
		return newChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANONYMOUS BLOCK METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is called when all the inline children of this block
	 * box should be wrapped in anonymous block. It is done to preserve
	 * the invariant in CSS where all the children of a block box must
	 * either all be block or must all be inline. Wrapping inline children
	 * makes all the children blocks
	 */
	private function makeChildrenNonInline():Void
	{
		//will store all the current block children and the newly created
		//anonymous block, in order and will replace the current child nodes array
		var newChildNodes:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		//loop in the child nodes in reverse order, as the child nodes
		//array will be modified during this loop
		var i:Int = childNodes.length -1;
		while( i >= 0)
		{
			var child:ElementRenderer = childNodes[i];
			
			//for inline children, create an anonymous block, and attach the child to it
			if (child.isInlineLevel() == true)
			{
				//TODO 2 : only 1 anonymous block should be created for contiguous
				//inline elements
				var anonymousBlock:AnonymousBlockBoxRenderer = createAnonymousBlock(child);
				newChildNodes.push(anonymousBlock);
			}
			else
			{
				newChildNodes.push(child);
			}
			
			i--;
		}
		
		//must reverse as the child nodes where
		//looped in reverse order
		newChildNodes.reverse();
		
		//attach all the block children and the newly
		//created anonymous block box
		var length:Int = newChildNodes.length;
		for (i in 0...length)
		{
			appendChild(newChildNodes[i]);
		}
	}
	
	/**
	 * create an anonymous block and append an inline child to it
	 */ 
	private function createAnonymousBlock(child:ElementRenderer):AnonymousBlockBoxRenderer
	{
		var anonymousBlock:AnonymousBlockBoxRenderer = new AnonymousBlockBoxRenderer();
		anonymousBlock.appendChild(child);
		
		anonymousBlock.coreStyle = anonymousBlock.domNode.coreStyle;
		
		//anonymous block use the style of their parent for cascading, they can't 
		//have style declaration of their own
		var parentStyleDeclaration:CSSStyleDeclaration = child.domNode.parentNode.coreStyle.computedValues;
		var parentFontMetrics:FontMetricsData = child.domNode.parentNode.coreStyle.fontMetrics;
		
		var htmlDocument:HTMLDocument = cast(child.domNode.ownerDocument);
		
		//TODO 1 : can't access htmlDocument.initialStyleDeclaration in macro target
		//is htmlDocument null ?
		var initialStyleDeclaration:InitialStyleDeclaration = new InitialStyleDeclaration();
		
		//only use style declarations from the parent node
		anonymousBlock.coreStyle.cascade(initialStyleDeclaration.supportedCSSProperties, initialStyleDeclaration,
		initialStyleDeclaration, initialStyleDeclaration, 
		initialStyleDeclaration, 12, 12, false);
		
		return anonymousBlock;
	}
	
	/**
	 * returns wether the FlowBoxRenderer has at least one significant child
	 * which can define wether he establish/participate in a block or inline
	 * formatting context.
	 * 
	 * For instance if the FlowBoxRenderer has only absolutely positioned
	 * or floated children, it can't yet know from its children wether
	 * to establish/participate in a bock or inline formatting context
	 */
	private function hasSignificantChild():Bool
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			if (child.isFloat() == false)
			{
				if (child.isPositioned() == false || child.isRelativePositioned() == true)
				{
					//if at least one child child is not absolutely positioned
					//or floated, formatting context to used can be determined
					return true;
				}
			}
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a BlockBoxRenderer render its children too
	 */
	override private function renderChildren(graphicContext:GraphicsContext):Void
	{
		super.renderChildren(graphicContext);
		
		//the BlockBoxRenderer is responsible for rendering its children in the same stacking
		//context if it establishes a stacking context itself or is rendered as if it did
		if (establishesNewStackingContext() == true || rendersAsIfEstablishingStackingContext() == true)
		{
			//render all the block box which belong to the same stacking context
			renderBlockContainerChildren(graphicContext);
			
			//TODO 5 : render non-positioned float
			
			//render all the replaced (embedded) box displayed as blocks belonging
			//to the same stacking context
			renderBlockReplacedChildren(graphicContext);
			
			//render all the line boxes belonging to the same stacking context
			renderLineBoxes(graphicContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the LineBoxes of child BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderLineBoxes(graphicContext:GraphicsContext):Void
	{
		//retrieve all the line boxes in all of the lines generated in this BlockBoxRenderer
		var lineBoxes:Array<LineBox> = getChilrenLineBoxes(this, layerRenderer);

		//loop in all of the lineboxes
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			lineBoxes[i].render(graphicContext);
		}
	}
	
	/**
	 * Render all the replaced children displayed as blocks which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockReplacedChildren(graphicContext:GraphicsContext):Void
	{
		var childrenBlockReplaced:Array<ElementRenderer> = getBlockReplacedChildren(this, layerRenderer);
		var length:Int = childrenBlockReplaced.length;
		for (i in 0...length)
		{
			childrenBlockReplaced[i].render(graphicContext);
		}
	}
	
	/**
	 * Render all the BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockContainerChildren(graphicContext:GraphicsContext):Void
	{
		var childrenBlockContainer:Array<ElementRenderer> = getBlockContainerChildren(this, layerRenderer);
		var length:Int = childrenBlockContainer.length;
		for (i in 0...length)
		{
			childrenBlockContainer[i].render(graphicContext);
		}
	}
	
	/**
	 * Render the scrollbars of this BlockBoxRenderer if needed
	 */
	override public function renderScrollBars(graphicContext:GraphicsContext, windowWidth:Int, windowHeight:Int):Void
	{
		if (_horizontalScrollBar != null)
		{
			_horizontalScrollBar.elementRenderer.layerRenderer.render(windowWidth, windowHeight );
		}
		
		if (_verticalScrollBar != null)
		{
			_verticalScrollBar.elementRenderer.layerRenderer.render(windowWidth, windowHeight);
		}
	}
	
	/**
	 * Return all the line box belonging to the same
	 * stacking context as this BlockBoxRenderer
	 * 
	 * TODO 4 : can probably be simplified
	 */
	private function getChilrenLineBoxes(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		if (rootRenderer.establishesNewFormattingContext() == true && rootRenderer.childrenInline() == true)
		{
			var blockBoxRenderer:ElementRenderer = rootRenderer;
			
			var length:Int = blockBoxRenderer.lineBoxes.length;
			for (i in 0...length)
			{
				var lineBoxes:Array<LineBox> = getLineBoxesInLine(blockBoxRenderer.lineBoxes[i]);

				var childLength:Int = lineBoxes.length;
				for (j in 0...childLength)
				{
					if (lineBoxes[j].elementRenderer.layerRenderer == referenceLayer)
					{
						ret.push(lineBoxes[j]);
					}
				}
			}
		}
		else
		{
			var length:Int = rootRenderer.childNodes.length;
			for (i in 0...length)
			{
				var child:ElementRenderer = rootRenderer.childNodes[i];
			
				if (child.layerRenderer == referenceLayer)
				{
					if (child.isReplaced() == false)
					{	
						var childLineBoxes:Array<LineBox> = getChilrenLineBoxes(child, referenceLayer);
						var childLength:Int = childLineBoxes.length;
						for (j in 0...childLength)
						{
							ret.push(childLineBoxes[j]);
						}
					}
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Return all the replaced child displayed as block belonging
	 * to the same stacking context
	 * 
	 * TODO 1 : all those methods should only be 1 method pushing into different arrays, and
	 * only called once when dom changes
	 */
	private function getBlockReplacedChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var length:Int = rootRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = rootRenderer.childNodes[i];
			
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 2 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK )
				{
					var childElementRenderer:Array<ElementRenderer> = getBlockReplacedChildren(child, referenceLayer);
					var childLength:Int = childElementRenderer.length;
					for (j in 0...childLength)
					{
						ret.push(childElementRenderer[j]);
					}
				}
				else if (child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK)
				{
					ret.push(child);
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Return all the BlockBoxRenderer children belonging
	 * to the same stacking context
	 */
	private function getBlockContainerChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var length:Int = rootRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = rootRenderer.childNodes[i];
			
			//check that the child is not positioned, as if it is an auto z-index positioned
			//element, it will be on the same layerRenderer but should not be rendered as 
			//a block container children
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 3 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) != INLINE_BLOCK)
				{
					ret.push(child);
					
					var childElementRenderer:Array<ElementRenderer> = getBlockContainerChildren(child, referenceLayer);
					var childLength:Int = childElementRenderer.length;
					for (j in 0...childLength)
					{
						ret.push(childElementRenderer[j]);
					}
				}
			}
		}
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a BlockBoxRenderer might
	 * also start the formatting of its
	 * in flow children
	 */
	override private function layoutChildren():Void
	{
		super.layoutChildren();
		format();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * starts the formatting of this block box if it
	 * establishes a new formatting context.
	 */
	private function format():Void
	{
		if (establishesNewFormattingContext() == true )
		{
			if (isPositioned() == true && isRelativePositioned() == false)
			{
				doFormat();
			}
			else if (isFloat() == true)
			{
				doFormat();
			}
			else if (coreStyle.getKeyword(coreStyle.display) == INLINE_BLOCK)
			{
				doFormat();
			}
			else if (childrenInline() == false)
			{
				doFormat();
			}
		}
	}
	
	/**
	 * Actually starts formatting this BlockBoxRenderer
	 * if it indeed establishes a new formatting context.
	 * 
	 * Instantiate the right formatting context, based
	 * on the display of the children
	 */
	private function doFormat():Void
	{
		if (childrenInline() == true)
		{
			new InlineFormattingContext(this).format(new FloatsManager());
		}
		else
		{
			new BlockFormattingContext(this).format(new FloatsManager());
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as BlockBoxRenderer can also starts a new stacking context
	 * if the overflow x or y style value is different from visible
	 */
	override public function establishesNewStackingContext():Bool
	{
		var establishesNewStackingContext:Bool = super.establishesNewStackingContext();
		
		if (establishesNewStackingContext == true)
		{
			return true;
		}
		
		return canAlwaysOverflow() != true;
	}
	
	/**
	 * Determine wether the ElementRenderer
	 * establishes a new formatting context for
	 * its children or participate in its
	 * parent formatting context
	 */
	override public function establishesNewFormattingContext():Bool
	{
		var establishesNewFormattingContext:Bool = false;
		
		//floats always establishes new formatting context
		if (isFloat() == true)
		{
			establishesNewFormattingContext = true;
		}
		//block box renderer which may use scrollbars to display
		//their children always establishes a new formatting context
		else if (canAlwaysOverflow() == false)
		{
			establishesNewFormattingContext = true;
		}
		//positioned element which are not relative always establishes new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			establishesNewFormattingContext = true;
		}
		//anonymous block always establish new inline formatting as they are used 
		//to wrap inline elements in block formatting
		else if (isAnonymousBlockBox() == true)
		{
			establishesNewFormattingContext = true;
		}
		else
		{
			switch (coreStyle.getKeyword(coreStyle.display))
			{
				//element with an inline-block display style
				//always establishes a new context
				case INLINE_BLOCK:
				establishesNewFormattingContext = true; 
				
				//a block ElementRenderer may start a new inline
				//formatting context if all its children are inline,
				//else it participates in the current block formatting
				//context
				case BLOCK:
					if (childrenInline() == true)
					{
						establishesNewFormattingContext = true;
					}
		
				default:
			}
		}
		
		//in the other cases, the block particpates in its parent's
		//formatting context
		
		return establishesNewFormattingContext;
	}
	
	override public function isBlockContainer():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as a block box renderer might be rendered as if
	 * establishing stacking context, based on its computed styles
	 * value
	 */
	override private function rendersAsIfEstablishingStackingContext():Bool
	{
		if (coreStyle.getKeyword(coreStyle.display) == INLINE_BLOCK)
		{
			return true;
		}
		else if (isFloat() == true)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Overriden, as if scrollbars are displayed, their 
	 * width or height must be substracted from the containing
	 * block width/height
	 */
	override public function getContainerBlockData():ContainingBlockData
	{
		var height:Float = coreStyle.usedValues.height;
		if (_horizontalScrollBar != null)
		{
			height -= _horizontalScrollBar.coreStyle.usedValues.height;
		}
		
		var width:Float = coreStyle.usedValues.width;
		if (_verticalScrollBar != null)
		{
			width -= _verticalScrollBar.coreStyle.usedValues.width;
		}
		
		return {
			width:width,
			isWidthAuto:coreStyle.isAuto(coreStyle.width),
			height:height,
			isHeightAuto:coreStyle.isAuto(coreStyle.height)
		};
	}
}