<?php

class cocktail_core_style_LineHeight extends Enum {
	public static function length($value) { return new cocktail_core_style_LineHeight("length", 2, array($value)); }
	public static $normal;
	public static function number($value) { return new cocktail_core_style_LineHeight("number", 1, array($value)); }
	public static function percentage($value) { return new cocktail_core_style_LineHeight("percentage", 3, array($value)); }
	public static $__constructors = array(2 => 'length', 0 => 'normal', 1 => 'number', 3 => 'percentage');
	}
cocktail_core_style_LineHeight::$normal = new cocktail_core_style_LineHeight("normal", 0);
