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
import cocktail.core.geom.GeomUtils;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.linebox.EmbeddedLineBox;
import cocktail.core.linebox.InlineBox;
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
import cocktail.core.linebox.RootLineBox;
import cocktail.core.linebox.StaticPositionLineBox;
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
class BlockBoxRenderer extends FlowBoxRenderer
{	
	/**
	 * An array where each item represents a line
	 * . Used when this block box establishes an 
	 * inline formatting context
	 */
	public var rootLineBoxes(default, null):Array<LineBox>;
	
	/**
	 * count the number of root line box
	 * used, this is used to prevent creating
	 * too much root line box when updateing layout
	 */
	private var _usedRootLineBoxes:Int;
	
	public var floatsManager:FloatsManager;
	
	private var _isLayingOut:Bool;
	
	/**
	 * Those bounds are used during layout to
	 * get the width and height of this block
	 * box when it depends on its children.
	 */
	private var _layoutBounds:RectangleVO;
	
	/**
	 * class constructor.
	 * Init class attributes
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		rootLineBoxes = new Array<LineBox>();
		_usedRootLineBoxes = 0;
		floatsManager = new FloatsManager();
		_isLayingOut = false;
		_layoutBounds = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LINE BOXES METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * reset each root line box owned by this
	 * block box. Root line box are reused
	 * instead of being instantiated each time
	 */
	public function resetRootLineBoxes():Void
	{
		var length:Int = rootLineBoxes.length;
		for (i in 0...length)
		{
			//reset the root line box data
			var rootLineBox:LineBox = rootLineBoxes[i];
			rootLineBox.bounds.x = 0;
			rootLineBox.bounds.y = 0;
			rootLineBox.bounds.width = 0;
			rootLineBox.bounds.height = 0;
			
			//remove all its children
			var child:LineBox = rootLineBox.firstChild;
			while(child != null)
			{
				var nextSibling:LineBox = child.nextSibling;
				rootLineBox.removeChild(child);
				child = nextSibling;
			}
		}
		
		_usedRootLineBoxes = 0;
	}
	
	/**
	 * Return a usable root line box, used during
	 * layout
	 */
	public function getRootLineBox():RootLineBox
	{
		_usedRootLineBoxes++;
	
		//create a new root line box if all root line
		//boxes are used
		if (_usedRootLineBoxes > rootLineBoxes.length)
		{
			rootLineBoxes.push(new RootLineBox(this));
		}
		
		return cast(rootLineBoxes[_usedRootLineBoxes - 1]);
	}
	
	/**
	 * Return the last added root line box
	 */
	public function getLastRootLineBox():RootLineBox
	{
		return cast(rootLineBoxes[_usedRootLineBoxes - 1]);
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
			var child:ElementRenderer = firstChild;
			while(child != null)
			{
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
				
				child = child.nextSibling;
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
		var child:ElementRenderer = lastChild;
		while(child != null)
		{
			var previousSibling:ElementRenderer = child.previousSibling;
			
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
			
			child = previousSibling;
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
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			if (child.isFloat() == false)
			{
				if (child.isPositioned() == false || child.isRelativePositioned() == true)
				{
					//if at least one child child is not absolutely positioned
					//or floated, formatting context to used can be determined
					return true;
				}
			}
			
			child = child.nextSibling;
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a BlockBoxRenderer render its children too
	 */
	override private function renderChildren(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		super.renderChildren(graphicContext, clipRect, scrollOffset);
		
		//the BlockBoxRenderer is responsible for rendering its children in the same layer
		//context if it establishes a layer itself or is rendered as if it did
		if (createOwnLayer() == true || rendersAsIfCreateOwnLayer() == true)
		{
			//render all the block box which belong to the same stacking context
			renderBlockContainerChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
			
			//TODO 5 : render non-positioned float
			
			//render all the replaced (embedded) box displayed as blocks belonging
			//to the same stacking context
			renderBlockReplacedChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
			
			//render all the line boxes belonging to the same stacking context
			renderLineBoxes(this, layerRenderer, graphicContext, clipRect, scrollOffset);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the LineBoxes of child BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderLineBoxes(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		if (rootRenderer.establishesNewBlockFormattingContext() == true && rootRenderer.childrenInline() == true)
		{	
			var blockboxRenderer:BlockBoxRenderer = cast(rootRenderer);
			var length:Int = blockboxRenderer.rootLineBoxes.length;
			for (i in 0...length)
			{
				renderLineBoxesInLine(blockboxRenderer.rootLineBoxes[i], graphicContext, referenceLayer, clipRect, scrollOffset);
			}
		}
		else
		{
			var child:ElementRenderer = rootRenderer.firstChild;
			while(child != null)
			{
				if (child.layerRenderer == referenceLayer)
				{
					if (child.isReplaced() == false)
					{	
						renderLineBoxes(child, referenceLayer, graphicContext, clipRect, scrollOffset);
					}
				}
				
				child = child.nextSibling;
			}
		}
	}
	
	/**
	 * Render all the line boxes in one line
	 */
	private function renderLineBoxesInLine(rootLineBox:LineBox, graphicContext:GraphicsContext, referenceLayer:LayerRenderer, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:LineBox = rootLineBox.firstChild;
		while(child != null)
		{
			if (child.elementRenderer.layerRenderer == referenceLayer)
			{
				child.render(graphicContext, clipRect, scrollOffset);
				if (child.firstChild != null)
				{
					renderLineBoxesInLine(child, graphicContext, referenceLayer, clipRect, scrollOffset);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Render all the replaced children displayed as blocks which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockReplacedChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootRenderer.firstChild;
		while(child != null)
		{
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 2 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK )
				{
					renderBlockReplacedChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
				}
				else if (child.coreStyle.getKeyword(child.coreStyle.display) == CSSKeywordValue.BLOCK)
				{
					child.render(graphicContext, clipRect, scrollOffset);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Render all the BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockContainerChildren(rootElementRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			//check that the child is not positioned, as if it is an auto z-index positioned
			//element, it will be on the same layerRenderer but should not be rendered as 
			//a block container children
			if (child.layerRenderer == referenceLayer)
			{
				//TODO 3 : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.getKeyword(child.coreStyle.display) != INLINE_BLOCK)
				{
					child.render(graphicContext, clipRect, scrollOffset);
					renderBlockContainerChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function layoutChildren():Void
	{
		if (establishesNewBlockFormattingContext() == true)
		{
			if (_isLayingOut == false)
			{
				floatsManager.init();
			}
		}
		else
		{
			var containingBlockAsBlock:BlockBoxRenderer = cast(containingBlock);
			//TODO : convert float in containing block space to this space
			//floatsManager.convertToSpace(this, containingBlockAsBlock.floatsManager, containingBlockAsBlock);
		}
		
		_isLayingOut = true;
		
		var shouldLayoutAgain:Bool = false;
		if (childrenInline() == false)
		{
			shouldLayoutAgain = layoutBlockChildrenAndFloats();
		}
		else
		{
			shouldLayoutAgain = layoutInlineChildrenAndFloats();
		} 
		
		if (coreStyle.isAuto(coreStyle.height) == true)
		{
			_layoutBounds.x = 500000;
			_layoutBounds.y = 500000;
			_layoutBounds.width = 0;
			_layoutBounds.height = 0;
			
			//TODO : take min-height into account ?
			if (childrenInline() == true)
			{
				//TODO : adding vertical padding and borders
				getLineBoxesBounds(lineBoxes, _layoutBounds);
				bounds.height = _layoutBounds.height;
			}
			else
			{
				if (establishesNewBlockFormattingContext() == false)
				{
					//TODO : adding vertical padding and borders
					getChildrenBounds(this, _layoutBounds);
					bounds.height = _layoutBounds.height;
				}
				else
				{
					//TODO : add vertical padding and borders
					getChildrenMarginBounds(this, _layoutBounds);
					bounds.height = _layoutBounds.height;
					
					//TODO : if floats bounds higher, use instead for height
				}
			}
		}
		
		if (establishesNewBlockFormattingContext() == true && coreStyle.isAuto(coreStyle.width) == true)
		{
			if (useShrinkToFit() == true)
			{
				
			}
		}
		
		_isLayingOut = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : implement
	private function useShrinkToFit():Bool
	{
		return true;
	}
	
	
	private function getChildrenBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			GeomUtils.addBounds(child.bounds, bounds);
			if (child.firstChild != null)
			{
				doGetChildrenBounds(child, bounds);
			}
			
			child = child.nextSibling;
		}
	}
	
	//TODO : for each child bounds, add intermediate child bounds with margins
	private function getChildrenMarginBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			GeomUtils.addBounds(child.bounds, bounds);
			if (child.firstChild != null)
			{
				doGetChildrenBounds(child, bounds);
			}
			
			child = child.nextSibling;
		}
	}
	
	private function layoutBlockChildrenAndFloats():Bool
	{
		var childPosition:PointVO = new PointVO(0, 0);
			
		var child:ElementRenderer = firstChild;
		while (child != null)
		{
			if (child.hasClearance() == true)
			{
				//TODO : when clearing, should only clear flotes declared before in document order
				floatsManager.clearFloats(child.coreStyle.clear, childPosition.y);
			}
			
			if (child.isPositioned() == true && child.isRelativePositioned() == false)
			{
				//TODO : margin collapsing
				if (child.isFloat() == false)
				{
					if (child.establishesNewBlockFormattingContext() == false && child.isBlockContainer() == true)
					{
						childPosition.y += child.coreStyle.usedValues.marginTop;
						childPosition.x = child.coreStyle.usedValues.marginLeft;
						
						child.bounds.x = childPosition.x;
						child.bounds.y = childPosition.y;
						
						child.layout(true);
					}
					else
					{
						child.layout(true);
						//TODO : for child, should use margin box width and for containing block content width
						childPosition.y = floatsManager.getFirstAvailableYPosition(childPosition.y, child.bounds.width, bounds.width);
						
						childPosition.y += child.coreStyle.usedValues.marginTop;
						childPosition.x += child.coreStyle.usedValues.marginLeft;
					}
					
					childPosition.y += child.bounds.height;
					childPosition.y += child.coreStyle.usedValues.marginBottom;
				}
				else
				{
					child.layout(true);
					
					if (floatsManager.isAlreadyRegistered(child) == false)
					{
						//TODO : remove paddings from containing block width
						var floatBounds:RectangleVO = floatsManager.registerFloat(child, childPosition, containingBlock.bounds.width );
						
						child.bounds.x = floatBounds.x + child.coreStyle.usedValues.marginLeft;
						child.bounds.y = floatBounds.y + child.coreStyle.usedValues.marginTop;
						
						var xOffset:Float = 0;
						var yOffset:Float = 0;
						
						var blockFormattingRoot:ElementRenderer = this;
						
						while (blockFormattingRoot.establishesNewBlockFormattingContext() == false)
						{
							if (blockFormattingRoot.parentNode == null)
							{
								break;
							}
							blockFormattingRoot = blockFormattingRoot.parentNode;
						}
						
						//TODO : convert float in current space to block root space
						//blockFormattingRoot.addFloatedElementToBlockFormattingRoot(floatedElement);
						return true;
					}
				}
			}
			
			child = child.nextSibling;
		}
		
		return false;
	}
	
	//TODO : add final step where the bounds of all child are updated
	//based on the line box they created
	private function layoutInlineChildrenAndFloats():Bool
	{
		//var lineBoxPosition:PointVO = new PointVO(0, 0);
		//
		//var child:ElementRenderer = firstChild;
		//var lineBox:LineBox = new LineBox(child, width);
		//
		//var openedElementRendererStack:Array<ElementRenderer> = new Array<ElementRenderer>();
		return false;
	}
	/**
	private function doFormat(elementRenderer:ElementRenderer, lineBox:LineBox, inlineBox:InlineBox, openedElementRenderers:Array<ElementRenderer>, lineBoxPosition:PointVO):InlineBox
	{
		//loop in all the child of the container
		var child:ElementRenderer = elementRenderer.firstChild;
		while(child != null)
		{
			if (child.isPositioned() == true && child.isRelativePositioned() == false)
			{
				if (child.establishesNewBlockFormattingContext() == true || child.isReplaced() == true)
				{
					if (child.isReplaced() == false)
					{
						child.layout();
					}
					
					var inlineBox:InlineBox = child.inlineBoxes[0];
					inlineBox.bounds.width = child.bounds.width;
					inlineBox.marginLeft = child.coreStyle.usedValues.marginLeft;
					inlineBox.marginRight = child.coreStyle.usedValues.marginRight;
					
					var lineIsFull:Bool = lineBox.insert(inlineBox, parentInlineBox);
					
					if (lineIsFull == true)
					{
						lineBox = layoutLineBox(lineBox, lineBoxPosition, openedElementRenderers);
						lineBoxes.push(lineBox);
					}
				}
				//here the child is an inline box renderer, which will create one line box for each
				//line its children are in
				else if (child.firstChild != null)
				{
					//create the first line box for this inline box renderer
					var childInLineBox:InlineBox = new InlineBox(child);
					
					var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
					
					//the first line box created by an inline box renderer has a left margin and padding
					childInLineBox.marginLeft = childUsedValues.marginLeft;
					childInLineBox.paddingLeft = childUsedValues.paddingLeft;
					//the left margin and padding is added to the unbreakable width as the next line box in the line 
					//can't be separated from this margin and padding
					lineBox.addUnbreakeableWidth(childUsedValues.marginLeft + childUsedValues.paddingLeft);
					
					//attach the line box to its parent line box
					inlineBox.appendChild(childInLineBox);

					//store the inline box renderer, each time a new line is created
					//by laying out a child of this inline box renderer, a new line box
					//with a reference to this inline box renderer will be created, so that
					//each line into which this inline box renderer is laid out can be
					openedElementRenderers.push(child);
					
					//format all the children of the inline box renderer recursively
					//a reference to the last added line box is returned, so that it can
					//be used as a starting point when laying out the siblings of the 
					//inline box renderer
					inlineBox = doFormat(child, lineBox, childInLineBox, openedElementRenderers, lineBoxPosition);
					
					//now that all of the child of the inline box renderer as been laid out,
					//remove the reference to this inline box renderer so that when a new line
					//is created, no line box pointing to this inline box renderer is created
					openedElementRenderers.pop();
					
					//The current line box must also be set to the parent line box so that no more
					//line boxes are added to this line box as it is done formatting its child line boxes
					inlineBox = inlineBox.parentNode;
					
					//The right margin and padding is added to the last generated line box of the current inline
					//box renderer
					var lastInLineBox:InLineBox = child.inlineBoxes[child.inlineBoxes.length - 1];
					lastInLineBox.marginRight = childUsedValues.marginRight;
					lastInLineBox.paddingRight = childUsedValues.paddingRight;
					lineBox.addUnbreakeableWidth(childUsedValues.marginRight + childUsedValues.paddingRight);
				}
				//here the child is a TextRenderer, which has as many text line box
				//as needed to reperesent all the content of the TextRenderer
				else
				{
					//insert the array of created line boxes into the current line. It might create as many
					//new lines as necessary. Returns a reference to the last inserted line box, used as starting
					//point to lay out subsequent siblings and children
					var textLength:Int = child.inlineBoxes.length;
					for (j in 0...textLength)
					{
						lineBox = insertIntoLine(child.inlineBoxes[j], lineBox, openedElementRenderers);
					}
				}
			}
			
			child = child.nextSibling;
		}
	
		return inlineBox;
	}
	
	private function layoutLineBox(lineBox:LineBox, lineBoxPosition:PointVO, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		lineBox.layout();
						
		lineBox = new LineBox();

		var currentInlineBox:InlineBox = lineBox.rootInlineBox;
		//create new line boxes for all the inline box renderer which still have
		//children to format, and add them to the new line
		var length:Int = openedElementRenderers.length;
		for (j in 0...length)
		{
			//all line boxes are attached as child of the previous created line box
			//and not as sibling to respect the hierarchy of the previous line
			var childInLineBox:InlineBox = new InlineBox(openedElementRenderers[j]);
			currentInlineBox.appendChild(childInLineBox);
			currentInlineBox = childInLineBox;
		}
	}
	*/
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as BlockBoxRenderer can also create a new layer
	 * if the overflow x or y style value is different from visible
	 */
	override public function createOwnLayer():Bool
	{
		//check first wether it should create a new layer
		//anyway
		var createOwnLayer:Bool = super.createOwnLayer();
		
		if (createOwnLayer == true)
		{
			return true;
		}
		
		return canAlwaysOverflow() != true;
	}
	
	/**
	 * Determine wether the ElementRenderer
	 * establishes a new block formatting context for
	 * its children or participate in its
	 * parent block formatting context
	 */
	override public function establishesNewBlockFormattingContext():Bool
	{
		var establishesNewBlockFormattingContext:Bool = false;
		
		//floats always establishes new block formatting context
		if (isFloat() == true)
		{
			establishesNewBlockFormattingContext = true;
		}
		//block box renderer which may hide their overflowing
		//children always start a new block formatting context
		else if (canAlwaysOverflow() == false)
		{
			establishesNewBlockFormattingContext = true;
		}
		//positioned element which are not relative always establishes new block context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			establishesNewBlockFormattingContext = true;
		}
		else
		{
			switch (coreStyle.getKeyword(coreStyle.display))
			{
				//element with an inline-block display style
				//always establishes a new block formatting context
				case INLINE_BLOCK:
				establishesNewBlockFormattingContext = true; 
		
				default:
			}
		}
		
		//in the other cases, the block particpates in its parent's
		//block formatting context
		
		return establishesNewBlockFormattingContext;
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
	 * Overriden, has if this block box renderer has its own
	 * layer, it must not use the scrollLeft and scrollTop
	 * of its layer when rendering background, as they
	 * should only apply to child element renderers and layers
	 */
	override private function getBackgroundBounds(scrollOffset:PointVO):RectangleVO
	{
		var backgroundBounds:RectangleVO = super.getBackgroundBounds(scrollOffset);
		
		if (_hasOwnLayer == true)
		{
			backgroundBounds.x += layerRenderer.scrollLeft;
			backgroundBounds.y += layerRenderer.scrollTop;
		}
		
		return backgroundBounds;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether this BlockBoxRenderer always overflows
	 * in both x and y axis. If either overflow x or y
	 * is deifferent from visible, then it is considered to
	 * not always overflow
	 */
	private function canAlwaysOverflow():Bool
	{	
		switch (coreStyle.getKeyword(coreStyle.overflowX))
		{
			case VISIBLE:
				
			default:
				return false;
		}
		
		switch (coreStyle.getKeyword(coreStyle.overflowY))
		{
			case VISIBLE:
				
			default:
				return false;
		}
		
		return true;
	}
}