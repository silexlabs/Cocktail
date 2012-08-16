<?php

class cocktail_core_style_TextAlign extends Enum {
	public static $center;
	public static $justify;
	public static $left;
	public static $right;
	public static $__constructors = array(2 => 'center', 3 => 'justify', 0 => 'left', 1 => 'right');
	}
cocktail_core_style_TextAlign::$center = new cocktail_core_style_TextAlign("center", 2);
cocktail_core_style_TextAlign::$justify = new cocktail_core_style_TextAlign("justify", 3);
cocktail_core_style_TextAlign::$left = new cocktail_core_style_TextAlign("left", 0);
cocktail_core_style_TextAlign::$right = new cocktail_core_style_TextAlign("right", 1);
