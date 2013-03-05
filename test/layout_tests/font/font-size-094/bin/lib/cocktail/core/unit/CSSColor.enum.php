<?php

class cocktail_core_unit_CSSColor extends Enum {
	public static function hex($value) { return new cocktail_core_unit_CSSColor("hex", 2, array($value)); }
	public static function keyword($value) { return new cocktail_core_unit_CSSColor("keyword", 3, array($value)); }
	public static function rgb($red, $green, $blue) { return new cocktail_core_unit_CSSColor("rgb", 0, array($red, $green, $blue)); }
	public static function rgba($red, $green, $blue, $alpha) { return new cocktail_core_unit_CSSColor("rgba", 1, array($red, $green, $blue, $alpha)); }
	public static $transparent;
	public static $__constructors = array(2 => 'hex', 3 => 'keyword', 0 => 'rgb', 1 => 'rgba', 4 => 'transparent');
	}
cocktail_core_unit_CSSColor::$transparent = new cocktail_core_unit_CSSColor("transparent", 4);
