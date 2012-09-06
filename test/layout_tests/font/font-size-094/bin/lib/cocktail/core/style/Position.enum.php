<?php

class cocktail_core_style_Position extends Enum {
	public static $absolute;
	public static $cssStatic;
	public static $fixed;
	public static $relative;
	public static $__constructors = array(2 => 'absolute', 0 => 'cssStatic', 3 => 'fixed', 1 => 'relative');
	}
cocktail_core_style_Position::$absolute = new cocktail_core_style_Position("absolute", 2);
cocktail_core_style_Position::$cssStatic = new cocktail_core_style_Position("cssStatic", 0);
cocktail_core_style_Position::$fixed = new cocktail_core_style_Position("fixed", 3);
cocktail_core_style_Position::$relative = new cocktail_core_style_Position("relative", 1);
