<?php

class cocktail_core_style_BackgroundSizeDimension extends Enum {
	public static $cssAuto;
	public static function length($value) { return new cocktail_core_style_BackgroundSizeDimension("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_BackgroundSizeDimension("percent", 1, array($value)); }
	public static $__constructors = array(2 => 'cssAuto', 0 => 'length', 1 => 'percent');
	}
cocktail_core_style_BackgroundSizeDimension::$cssAuto = new cocktail_core_style_BackgroundSizeDimension("cssAuto", 2);
