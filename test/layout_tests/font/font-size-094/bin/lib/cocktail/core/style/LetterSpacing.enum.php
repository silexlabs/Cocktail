<?php

class cocktail_core_style_LetterSpacing extends Enum {
	public static function length($value) { return new cocktail_core_style_LetterSpacing("length", 1, array($value)); }
	public static $normal;
	public static $__constructors = array(1 => 'length', 0 => 'normal');
	}
cocktail_core_style_LetterSpacing::$normal = new cocktail_core_style_LetterSpacing("normal", 0);
