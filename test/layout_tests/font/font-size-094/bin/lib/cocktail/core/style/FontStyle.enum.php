<?php

class cocktail_core_style_FontStyle extends Enum {
	public static $italic;
	public static $normal;
	public static $oblique;
	public static $__constructors = array(1 => 'italic', 0 => 'normal', 2 => 'oblique');
	}
cocktail_core_style_FontStyle::$italic = new cocktail_core_style_FontStyle("italic", 1);
cocktail_core_style_FontStyle::$normal = new cocktail_core_style_FontStyle("normal", 0);
cocktail_core_style_FontStyle::$oblique = new cocktail_core_style_FontStyle("oblique", 2);
