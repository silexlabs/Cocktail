<?php

class cocktail_core_unit_Angle extends Enum {
	public static function deg($value) { return new cocktail_core_unit_Angle("deg", 0, array($value)); }
	public static function grad($value) { return new cocktail_core_unit_Angle("grad", 1, array($value)); }
	public static function rad($value) { return new cocktail_core_unit_Angle("rad", 2, array($value)); }
	public static function turn($value) { return new cocktail_core_unit_Angle("turn", 3, array($value)); }
	public static $__constructors = array(0 => 'deg', 1 => 'grad', 2 => 'rad', 3 => 'turn');
	}
