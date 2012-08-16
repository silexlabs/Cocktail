<?php

class cocktail_core_unit_ImageValue extends Enum {
	public static function gradient($value) { return new cocktail_core_unit_ImageValue("gradient", 2, array($value)); }
	public static function imageList($value) { return new cocktail_core_unit_ImageValue("imageList", 1, array($value)); }
	public static function url($value) { return new cocktail_core_unit_ImageValue("url", 0, array($value)); }
	public static $__constructors = array(2 => 'gradient', 1 => 'imageList', 0 => 'url');
	}
