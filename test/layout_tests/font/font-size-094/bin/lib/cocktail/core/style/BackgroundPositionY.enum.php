<?php

class cocktail_core_style_BackgroundPositionY extends Enum {
	public static $bottom;
	public static $center;
	public static function length($value) { return new cocktail_core_style_BackgroundPositionY("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_BackgroundPositionY("percent", 1, array($value)); }
	public static $top;
	public static $__constructors = array(4 => 'bottom', 3 => 'center', 0 => 'length', 1 => 'percent', 2 => 'top');
	}
cocktail_core_style_BackgroundPositionY::$bottom = new cocktail_core_style_BackgroundPositionY("bottom", 4);
cocktail_core_style_BackgroundPositionY::$center = new cocktail_core_style_BackgroundPositionY("center", 3);
cocktail_core_style_BackgroundPositionY::$top = new cocktail_core_style_BackgroundPositionY("top", 2);
