<?php

class cocktail_core_style_BackgroundRepeatValue extends Enum {
	public static $noRepeat;
	public static $repeat;
	public static $round;
	public static $space;
	public static $__constructors = array(3 => 'noRepeat', 0 => 'repeat', 2 => 'round', 1 => 'space');
	}
cocktail_core_style_BackgroundRepeatValue::$noRepeat = new cocktail_core_style_BackgroundRepeatValue("noRepeat", 3);
cocktail_core_style_BackgroundRepeatValue::$repeat = new cocktail_core_style_BackgroundRepeatValue("repeat", 0);
cocktail_core_style_BackgroundRepeatValue::$round = new cocktail_core_style_BackgroundRepeatValue("round", 2);
cocktail_core_style_BackgroundRepeatValue::$space = new cocktail_core_style_BackgroundRepeatValue("space", 1);
