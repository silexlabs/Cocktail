<?php

class cocktail_core_style_ConstrainedDimension extends Enum {
	public static function length($value) { return new cocktail_core_style_ConstrainedDimension("length", 0, array($value)); }
	public static $none;
	public static function percent($value) { return new cocktail_core_style_ConstrainedDimension("percent", 1, array($value)); }
	public static $__constructors = array(0 => 'length', 2 => 'none', 1 => 'percent');
	}
cocktail_core_style_ConstrainedDimension::$none = new cocktail_core_style_ConstrainedDimension("none", 2);
