/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

/**
 * This interface inherits from CharacterData and
 * represents the content of a comment, i.e., all the
 * characters between the starting '<!--' and ending '-->'.
 * Note that this is the definition of a comment
 * in XML, and, in practice, HTML, although some HTML 
 * tools may implement the full SGML comment structure.
 * 
 * No lexical check is done on the content of a comment 
 * and it is therefore possible to have the character 
 * sequence "--" (double-hyphen) in the content, which 
 * is illegal in a comment per section 2.5 of [XML 1.0].
 * The presence of this character sequence must generate
 * a fatal error during serialization.
 * 
 * @author Yannick DOMINGUEZ
 */
class Comment extends CharacterData
{
	/**
	 * class constructor
	 */
	public function new()
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING TREE METHODS
	//
	// overidden as this doesn't apply to Comment node, 
	// they only have this method because they inherit from
	// HTMLElement because of JS API
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function updateElementRenderer():Void
	{
		
	}
	
	override public function attach(recursive:Bool):Void
	{
		
	}
	
	override public function detach(recursive:Bool):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeType():Int
	{
		return DOMConstants.COMMENT_NODE;
	}
}