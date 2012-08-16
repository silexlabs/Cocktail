<?php

class cocktail_core_unit_Length extends Enum {
	public static function cm($value) { return new cocktail_core_unit_Length("cm", 1, array($value)); }
	public static function cssIn($value) { return new cocktail_core_unit_Length("cssIn", 5, array($value)); }
	public static function em($value) { return new cocktail_core_unit_Length("em", 6, array($value)); }
	public static function ex($value) { return new cocktail_core_unit_Length("ex", 7, array($value)); }
	public static function mm($value) { return new cocktail_core_unit_Length("mm", 2, array($value)); }
	public static function pc($value) { return new cocktail_core_unit_Length("pc", 4, array($value)); }
	public static function pt($value) { return new cocktail_core_unit_Length("pt", 3, array($value)); }
	public static function px($value) { return new cocktail_core_unit_Length("px", 0, array($value)); }
	public static $__constructors = array(1 => 'cm', 5 => 'cssIn', 6 => 'em', 7 => 'ex', 2 => 'mm', 4 => 'pc', 3 => 'pt', 0 => 'px');
	}
