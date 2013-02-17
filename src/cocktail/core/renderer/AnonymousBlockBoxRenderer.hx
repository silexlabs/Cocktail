/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.dom.Document;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;

/**
 * Anonmymous block are used to wrap inlineBoxRenderer
 * which are children of a block box establishing or particpating
 * in a block formatting context.
 * 
 * Wrapping the inlineBoxRenderer in an anonymous block allows to 
 * keep the invariant of CSS where all the children of a block box
 * must be blocks or all the children must be inline
 * 
 * @author Yannick DOMINGUEZ
 */
class AnonymousBlockBoxRenderer extends BlockBoxRenderer
{
	/**
	 * a "dummy" html element reused for all
	 * anonymous blocks
	 */
	private static var _node:HTMLElement;
	
	/**
	 * class constructor
	 */
	public function new(document:Document) 
	{
		//create dummy node first time
		if (_node == null)
		{
			_node = document.createElement(HTMLConstants.HTML_DIV_TAG_NAME);
		}
		
		super(_node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When all children of an anonymous block
	 * are removed, it must also remove itself
	 */
	override public function removeChild(oldChild:ElementRenderer):Void
	{
		super.removeChild(oldChild);
		
		if (firstChild == null)
		{
			parentNode.removeChild(this);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	override public function isPositioned():Bool
	{
		return false;
	}
	
	override public function isAnonymousBlockBox():Bool
	{
		return true;
	}
	
	override public function createOwnLayer():Bool
	{
		return false;
	}
	
	override public function isInlineLevel():Bool
	{
		return false;
	}
}