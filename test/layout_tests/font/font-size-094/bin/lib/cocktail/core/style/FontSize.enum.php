<?php

class cocktail_core_style_FontSize extends Enum {
	public static function absoluteSize($value) { return new cocktail_core_style_FontSize("absoluteSize", 2, array($value)); }
	public static function length($value) { return new cocktail_core_style_FontSize("length", 0, array($value)); }
	public static function percentage($value) { return new cocktail_core_style_FontSize("percentage", 1, array($value)); }
	public static function relativeSize($value) { return new cocktail_core_style_FontSize("relativeSize", 3, array($value)); }
	public static $__constructors = array(2 => 'absoluteSize', 0 => 'length', 1 => 'percentage', 3 => 'relativeSize');
	}
