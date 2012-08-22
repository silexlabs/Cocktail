<?php

class cocktail_core_style_WordSpacing extends Enum {
	public static function length($value) { return new cocktail_core_style_WordSpacing("length", 1, array($value)); }
	public static $normal;
	public static $__constructors = array(1 => 'length', 0 => 'normal');
	}
cocktail_core_style_WordSpacing::$normal = new cocktail_core_style_WordSpacing("normal", 0);
