<?php

class cocktail_core_dom_DOMException {
	public function __construct() { 
	}
	static $INDEX_SIZE_ERR = 1;
	static $DOMSTRING_SIZE_ERR = 2;
	static $HIERARCHY_REQUEST_ERR = 3;
	static $WRONG_DOCUMENT_ERR = 4;
	static $INVALID_CHARACTER_ERR = 5;
	static $NO_DATA_ALLOWED_ERR = 6;
	static $NO_MODIFICATION_ALLOWED_ERR = 7;
	static $NOT_FOUND_ERR = 8;
	static $NOT_SUPPORTED_ERR = 9;
	static $INUSE_ATTRIBUTE_ERR = 10;
	static $INVALID_STATE_ERR = 11;
	static $SYNTAX_ERR = 12;
	static $INVALID_MODIFICATION_ERR = 13;
	static $NAMESPACE_ERR = 14;
	static $INVALID_ACCESS_ERR = 15;
	static $VALIDATION_ERR = 16;
	static $TYPE_MISMATCH_ERR = 19;
	function __toString() { return 'cocktail.core.dom.DOMException'; }
}
