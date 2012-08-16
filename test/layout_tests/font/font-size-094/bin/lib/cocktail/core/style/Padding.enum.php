<?php

class cocktail_core_style_Padding extends Enum {
	public static function length($value) { return new cocktail_core_style_Padding("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_Padding("percent", 1, array($value)); }
	public static $__constructors = array(0 => 'length', 1 => 'percent');
	}
