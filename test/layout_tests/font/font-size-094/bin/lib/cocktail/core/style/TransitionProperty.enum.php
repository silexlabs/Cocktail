<?php

class cocktail_core_style_TransitionProperty extends Enum {
	public static $all;
	public static function cssList($value) { return new cocktail_core_style_TransitionProperty("cssList", 2, array($value)); }
	public static $none;
	public static $__constructors = array(1 => 'all', 2 => 'cssList', 0 => 'none');
	}
cocktail_core_style_TransitionProperty::$all = new cocktail_core_style_TransitionProperty("all", 1);
cocktail_core_style_TransitionProperty::$none = new cocktail_core_style_TransitionProperty("none", 0);
