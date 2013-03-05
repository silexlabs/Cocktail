<?php

class cocktail_core_unit_GradientAngle extends Enum {
	public static function angle($value) { return new cocktail_core_unit_GradientAngle("angle", 0, array($value)); }
	public static function corner($value) { return new cocktail_core_unit_GradientAngle("corner", 2, array($value)); }
	public static function side($value) { return new cocktail_core_unit_GradientAngle("side", 1, array($value)); }
	public static $__constructors = array(0 => 'angle', 2 => 'corner', 1 => 'side');
	}
