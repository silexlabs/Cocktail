<?php

class cocktail_core_style_Margin extends Enum {
	public static $cssAuto;
	public static function length($value) { return new cocktail_core_style_Margin("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_Margin("percent", 1, array($value)); }
	public static $__constructors = array(2 => 'cssAuto', 0 => 'length', 1 => 'percent');
	}
cocktail_core_style_Margin::$cssAuto = new cocktail_core_style_Margin("cssAuto", 2);
