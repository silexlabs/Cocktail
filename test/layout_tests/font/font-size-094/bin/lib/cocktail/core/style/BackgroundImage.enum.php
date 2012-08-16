<?php

class cocktail_core_style_BackgroundImage extends Enum {
	public static function image($value) { return new cocktail_core_style_BackgroundImage("image", 1, array($value)); }
	public static $none;
	public static $__constructors = array(1 => 'image', 0 => 'none');
	}
cocktail_core_style_BackgroundImage::$none = new cocktail_core_style_BackgroundImage("none", 0);
