<?php

class cocktail_core_style_BackgroundSize extends Enum {
	public static $contain;
	public static $cover;
	public static function dimensions($value) { return new cocktail_core_style_BackgroundSize("dimensions", 2, array($value)); }
	public static $__constructors = array(0 => 'contain', 1 => 'cover', 2 => 'dimensions');
	}
cocktail_core_style_BackgroundSize::$contain = new cocktail_core_style_BackgroundSize("contain", 0);
cocktail_core_style_BackgroundSize::$cover = new cocktail_core_style_BackgroundSize("cover", 1);
