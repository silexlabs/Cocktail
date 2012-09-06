<?php

class cocktail_core_style_PositionOffset extends Enum {
	public static $cssAuto;
	public static function length($value) { return new cocktail_core_style_PositionOffset("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_PositionOffset("percent", 1, array($value)); }
	public static $__constructors = array(2 => 'cssAuto', 0 => 'length', 1 => 'percent');
	}
cocktail_core_style_PositionOffset::$cssAuto = new cocktail_core_style_PositionOffset("cssAuto", 2);
