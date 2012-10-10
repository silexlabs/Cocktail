/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.html.HTMLConstants;

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
	 * class constructor
	 */
	public function new() 
	{
		super(Lib.document.createElement(HTMLConstants.HTML_DIV_TAG_NAME));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An anonymous block has only one child, which is the 
	 * wrapped inlineBoxRenderer. When this child
	 * is removed form the DOM, the anonymous block must
	 * also be removed
	 */
	override public function removeChild(oldChild:ElementRenderer):Void
	{
		super.removeChild(oldChild);
		//removes itself
		parentNode.removeChild(this);
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