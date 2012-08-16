<?php

class cocktail_core_style_Transform extends Enum {
	public static $none;
	public static function transformFunctions($transformFunctions) { return new cocktail_core_style_Transform("transformFunctions", 1, array($transformFunctions)); }
	public static $__constructors = array(0 => 'none', 1 => 'transformFunctions');
	}
cocktail_core_style_Transform::$none = new cocktail_core_style_Transform("none", 0);
