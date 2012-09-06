<?php

class cocktail_core_style_Cursor extends Enum {
	public static $crosshair;
	public static $cssAuto;
	public static $cssDefault;
	public static $pointer;
	public static $text;
	public static $__constructors = array(1 => 'crosshair', 0 => 'cssAuto', 2 => 'cssDefault', 3 => 'pointer', 4 => 'text');
	}
cocktail_core_style_Cursor::$crosshair = new cocktail_core_style_Cursor("crosshair", 1);
cocktail_core_style_Cursor::$cssAuto = new cocktail_core_style_Cursor("cssAuto", 0);
cocktail_core_style_Cursor::$cssDefault = new cocktail_core_style_Cursor("cssDefault", 2);
cocktail_core_style_Cursor::$pointer = new cocktail_core_style_Cursor("pointer", 3);
cocktail_core_style_Cursor::$text = new cocktail_core_style_Cursor("text", 4);
