<?php

class cocktail_Lib {
	public function __construct() { 
	}
	static $document;
	static $window;
	static function init() {
		cocktail_Lib::$window = new cocktail_core_window_Window();
		cocktail_Lib::$document = cocktail_Lib::get_window()->document;
	}
	static function get_document() {
		if(cocktail_Lib::$document === null) {
			cocktail_Lib::init();
		}
		return cocktail_Lib::$document;
	}
	static function get_window() {
		if(cocktail_Lib::$window === null) {
			cocktail_Lib::init();
		}
		return cocktail_Lib::$window;
	}
	static $__properties__ = array("get_window" => "get_window","get_document" => "get_document");
	function __toString() { return 'cocktail.Lib'; }
}
