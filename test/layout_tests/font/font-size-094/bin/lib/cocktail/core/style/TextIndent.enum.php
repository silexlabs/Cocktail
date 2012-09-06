<?php

class cocktail_core_style_TextIndent extends Enum {
	public static function length($value) { return new cocktail_core_style_TextIndent("length", 0, array($value)); }
	public static function percentage($value) { return new cocktail_core_style_TextIndent("percentage", 1, array($value)); }
	public static $__constructors = array(0 => 'length', 1 => 'percentage');
	}
