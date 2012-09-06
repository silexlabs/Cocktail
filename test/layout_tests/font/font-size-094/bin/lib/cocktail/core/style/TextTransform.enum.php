<?php

class cocktail_core_style_TextTransform extends Enum {
	public static $capitalize;
	public static $lowercase;
	public static $none;
	public static $uppercase;
	public static $__constructors = array(0 => 'capitalize', 2 => 'lowercase', 3 => 'none', 1 => 'uppercase');
	}
cocktail_core_style_TextTransform::$capitalize = new cocktail_core_style_TextTransform("capitalize", 0);
cocktail_core_style_TextTransform::$lowercase = new cocktail_core_style_TextTransform("lowercase", 2);
cocktail_core_style_TextTransform::$none = new cocktail_core_style_TextTransform("none", 3);
cocktail_core_style_TextTransform::$uppercase = new cocktail_core_style_TextTransform("uppercase", 1);
