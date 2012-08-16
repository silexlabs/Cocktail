<?php

class cocktail_core_style_TransformOriginY extends Enum {
	public static $bottom;
	public static $center;
	public static function length($value) { return new cocktail_core_style_TransformOriginY("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_TransformOriginY("percent", 1, array($value)); }
	public static $top;
	public static $__constructors = array(4 => 'bottom', 3 => 'center', 0 => 'length', 1 => 'percent', 2 => 'top');
	}
cocktail_core_style_TransformOriginY::$bottom = new cocktail_core_style_TransformOriginY("bottom", 4);
cocktail_core_style_TransformOriginY::$center = new cocktail_core_style_TransformOriginY("center", 3);
cocktail_core_style_TransformOriginY::$top = new cocktail_core_style_TransformOriginY("top", 2);
