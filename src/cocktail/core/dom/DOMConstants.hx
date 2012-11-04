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
 * Lists constants for DOM nodes
 * @author Yannick DOMINGUEZ
 */
class DOMConstants 
{
	//node types
	
	public static inline var ELEMENT_NODE:Int = 1;
	
	public static inline var ATTRIBUTE_NODE:Int = 2;
	
	public static inline var TEXT_NODE:Int = 3;
	
	public static inline var CDATA_SECTION_NODE:Int = 4;
	
	public static inline var ENTITY_REFERENCE_NODE:Int = 5;
	
	public static inline var ENTITY_NODE:Int = 6;
	
	public static inline var PROCESSING_INSTRUCTION_NODE:Int = 7;
	
	public static inline var COMMENT_NODE:Int = 8;
	
	public static inline var DOCUMENT_NODE:Int = 9;

	public static inline var DOCUMENT_TYPE_NODE:Int = 10;
	
	public static inline var DOCUMENT_FRAGMENT_NODE:Int = 11;

	public static inline var NOTATION_NODE:Int = 11;
	
	//Document event interfaces

	public static inline var EVENT_INTERFACE:String = "Event";
	
	public static inline var UI_EVENT_INTERFACE:String = "UIEvent";
	
	public static inline var MOUSE_EVENT_INTERFACE:String = "MouseEvent";
	
	public static inline var FOCUS_EVENT_INTERFACE:String = "FocusEvent";
	
	public static inline var KEYBOARD_EVENT_INTERFACE:String = "KeyboardEvent";
	
	public static inline var WHEEL_EVENT_INTERFACE:String = "WheelEvent";
	
	public static inline var CUSTOM_EVENT_INTERFACE:String = "CustomEvent";
	
	public static inline var TRANSITION_EVENT_INTERFACE:String = "TransitionEvent";

	public static inline var POPSTATE_EVENT_INTERFACE:String = "PopStateEvent";
	
	//Element const
	
	/**
	 * When using getElementsByTagName, this value
	 * used as tagName returns all the child elements
	 */
	public static inline var MATCH_ALL_TAG_NAME:String = "*";
	
	//Text const
	
	public static inline var TEXT_NODE_NAME:String = "#text";
	
	private function new() 
	{
		
	}
	
}