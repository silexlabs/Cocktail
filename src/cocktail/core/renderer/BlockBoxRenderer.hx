 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.css.CascadeManager;
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
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.formatter.InlineFormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.Lib;
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
	 * class constructor.
	 * Init class attributes
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * If this block element renderer has both inline and
	 * block children, the inline children are wrapped
	 * in anonymous block to preserve the CSS invariant
	 * where all children of a block must either be all
	 * inline or all block
	 */
	override public function updateAnonymousBlock():Void
	{
		//flag determining wether inline children must be wrapped
		//in anonymous block
		var shouldMakeChildrenNonInline:Bool = false;
		
		//the BlockBoxRenderer should have at least one significant child to determine wether to 
		//establish/participate in a block or inline formatting context, and thus if inline children
		//shoud be wrapped in anonymous block
		if (hasSignificantChild() == true)
		{
			//store wether the children of this block are curently inline
			//or block
			var childrenInline:Bool = childrenInline();
			
			//loop in all children, looking for one which doesn't
			//coreespond to the currrent formatting of the block
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				var child:ElementRenderer = childNodes[i];
				
				//absolutely positioned children are not taken into account when determining wether this
				//BlockBoxRenderer establishes/participate in a block or inline formatting context
				if (child.isPositioned() == false || child.isRelativePositioned() ==  true)
				{	
					//if this child doesn't match the display of the other children,
					///for instance if it is the first inline while all the other
					//children are block, all the inline children should be wrapped in 
					//anonymous blocks
					if (child.isInlineLevel() != childrenInline)
					{
						shouldMakeChildrenNonInline = true;
						break;
					}
				}
			}
		}
		
		//make all children non inline if necessary
		if (shouldMakeChildrenNonInline == true)
		{
			makeChildrenNonInline();
		}
		
		super.updateAnonymousBlock();
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
		
		//TODO 2 : shouldn't have to instantiate each time
		var cascadeManager:CascadeManager = new CascadeManager();
		cascadeManager.shouldCascadeAll();
		
		var initialStyleDeclaration:InitialStyleDeclaration = Lib.document.initialStyleDeclaration;
		
		//only use initial style declarations
		anonymousBlock.coreStyle.cascade(cascadeManager, initialStyleDeclaration,
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
		
		//the BlockBoxRenderer is responsible for rendering its children in the same layer
		//context if it establishes a layer itself or is rendered as if it did
		if (createOwnLayer() == true || rendersAsIfCreateOwnLayer() == true)
		{
			//render all the block box which belong to the same stacking context
			renderBlockContainerChildren(this, layerRenderer, graphicContext);
			
			//TODO 5 : render non-positioned float
			
			//render all the replaced (embedded) box displayed as blocks belonging
			//to the same stacking context
			renderBlockReplacedChildren(this, layerRenderer, graphicContext);
			
			//render all the line boxes belonging to the same stacking context
			renderLineBoxes(this, layerRenderer, graphicContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the LineBoxes of child BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderLineBoxes(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext):Void
	{
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
						lineBoxes[j].render(graphicContext);
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
						renderLineBoxes(child, referenceLayer, graphicContext);
					}
				}
			}
		}
	}
	
	/**
	 * Render all the replaced children displayed as blocks which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockReplacedChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext):Void
	{
		var length:Int = rootRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = rootRenderer.childNodes[i];
			
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 2 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK )
				{
					renderBlockReplacedChildren(child, referenceLayer, graphicContext);
				}
				else if (child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK)
				{
					child.render(graphicContext);
				}
			}
		}
	}
	
	/**
	 * Render all the BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockContainerChildren(rootElementRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext):Void
	{
		var length:Int = rootElementRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = rootElementRenderer.childNodes[i];
			
			//check that the child is not positioned, as if it is an auto z-index positioned
			//element, it will be on the same layerRenderer but should not be rendered as 
			//a block container children
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 3 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) != INLINE_BLOCK)
				{
					child.render(graphicContext);
					renderBlockContainerChildren(child, referenceLayer, graphicContext);
				}
			}
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
			var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
			htmlDocument.layoutManager.inlineFormattingContext.format(this, true);
		}
		else
		{
			var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
			htmlDocument.layoutManager.blockFormattingContext.format(this, true);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as BlockBoxRenderer can also create a new layer
	 * if the overflow x or y style value is different from visible
	 */
	override public function createOwnLayer():Bool
	{
		var creatOwnLayer:Bool = super.createOwnLayer();
		
		if (creatOwnLayer == true)
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
	 * it creates its own layer, based on its computed styles
	 * value
	 */
	override private function rendersAsIfCreateOwnLayer():Bool
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
	override public function getContainerBlockData():ContainingBlockVO
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
		
		_containerBlockData.width = width;
		_containerBlockData.isWidthAuto = coreStyle.isAuto(coreStyle.width);
		_containerBlockData.height = height;
		_containerBlockData.isHeightAuto = coreStyle.isAuto(coreStyle.height);
		
		return _containerBlockData;
	}
}