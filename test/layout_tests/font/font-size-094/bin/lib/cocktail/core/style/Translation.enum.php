<?php

class cocktail_core_style_Translation extends Enum {
	public static function length($value) { return new cocktail_core_style_Translation("length", 0, array($value)); }
	public static function percent($value) { return new cocktail_core_style_Translation("percent", 1, array($value)); }
	public static $__constructors = array(0 => 'length', 1 => 'percent');
	}
