<?php

class cocktail_core_style_VerticalAlign extends Enum {
	public static $baseline;
	public static $bottom;
	public static $cssSuper;
	public static function length($value) { return new cocktail_core_style_VerticalAlign("length", 9, array($value)); }
	public static $middle;
	public static function percent($value) { return new cocktail_core_style_VerticalAlign("percent", 8, array($value)); }
	public static $sub;
	public static $textBottom;
	public static $textTop;
	public static $top;
	public static $__constructors = array(0 => 'baseline', 6 => 'bottom', 2 => 'cssSuper', 9 => 'length', 5 => 'middle', 8 => 'percent', 1 => 'sub', 7 => 'textBottom', 4 => 'textTop', 3 => 'top');
	}
cocktail_core_style_VerticalAlign::$baseline = new cocktail_core_style_VerticalAlign("baseline", 0);
cocktail_core_style_VerticalAlign::$bottom = new cocktail_core_style_VerticalAlign("bottom", 6);
cocktail_core_style_VerticalAlign::$cssSuper = new cocktail_core_style_VerticalAlign("cssSuper", 2);
cocktail_core_style_VerticalAlign::$middle = new cocktail_core_style_VerticalAlign("middle", 5);
cocktail_core_style_VerticalAlign::$sub = new cocktail_core_style_VerticalAlign("sub", 1);
cocktail_core_style_VerticalAlign::$textBottom = new cocktail_core_style_VerticalAlign("textBottom", 7);
cocktail_core_style_VerticalAlign::$textTop = new cocktail_core_style_VerticalAlign("textTop", 4);
cocktail_core_style_VerticalAlign::$top = new cocktail_core_style_VerticalAlign("top", 3);
