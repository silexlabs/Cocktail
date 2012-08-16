<?php

class cocktail_core_unit_TimeValue extends Enum {
	public static function milliSeconds($value) { return new cocktail_core_unit_TimeValue("milliSeconds", 1, array($value)); }
	public static function seconds($value) { return new cocktail_core_unit_TimeValue("seconds", 0, array($value)); }
	public static $__constructors = array(1 => 'milliSeconds', 0 => 'seconds');
	}
