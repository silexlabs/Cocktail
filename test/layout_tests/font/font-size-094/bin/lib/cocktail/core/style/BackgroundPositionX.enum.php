<?php

class cocktail_core_style_BackgroundPositionX extends Enum {
	public static $center;
	public static $left;
	public static function length($value) { return new cocktail_core_style_BackgroundPositionX("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_BackgroundPositionX("percent", 1, array($value)); }
	public static $right;
	public static $__constructors = array(3 => 'center', 2 => 'left', 0 => 'length', 1 => 'percent', 4 => 'right');
	}
cocktail_core_style_BackgroundPositionX::$center = new cocktail_core_style_BackgroundPositionX("center", 3);
cocktail_core_style_BackgroundPositionX::$left = new cocktail_core_style_BackgroundPositionX("left", 2);
cocktail_core_style_BackgroundPositionX::$right = new cocktail_core_style_BackgroundPositionX("right", 4);
