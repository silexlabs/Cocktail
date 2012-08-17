<?php

class cocktail_core_dom_DOMConstants {
	public function __construct() { 
	}
	static $ELEMENT_NODE = 1;
	static $ATTRIBUTE_NODE = 2;
	static $TEXT_NODE = 3;
	static $CDATA_SECTION_NODE = 4;
	static $ENTITY_REFERENCE_NODE = 5;
	static $ENTITY_NODE = 6;
	static $PROCESSING_INSTRUCTION_NODE = 7;
	static $COMMENT_NODE = 8;
	static $DOCUMENT_NODE = 9;
	static $DOCUMENT_TYPE_NODE = 10;
	static $DOCUMENT_FRAGMENT_NODE = 11;
	static $NOTATION_NODE = 11;
	static $EVENT_INTERFACE = "Event";
	static $UI_EVENT_INTERFACE = "UIEvent";
	static $MOUSE_EVENT_INTERFACE = "MouseEvent";
	static $FOCUS_EVENT_INTERFACE = "FocusEvent";
	static $KEYBOARD_EVENT_INTERFACE = "KeyboardEvent";
	static $WHEEL_EVENT_INTERFACE = "WheelEvent";
	static $CUSTOM_EVENT_INTERFACE = "CustomEvent";
	static $TRANSITION_EVENT_INTERFACE = "TransitionEvent";
	static $MATCH_ALL_TAG_NAME = "*";
	static $TEXT_NODE_NAME = "#text";
	function __toString() { return 'cocktail.core.dom.DOMConstants'; }
}
