<?php

class cocktail_core_drawing_FillStyleValue extends Enum {
	public static function bitmap($nativeElement, $repeat) { return new cocktail_core_drawing_FillStyleValue("bitmap", 3, array($nativeElement, $repeat)); }
	public static function gradient($gradientStyle) { return new cocktail_core_drawing_FillStyleValue("gradient", 2, array($gradientStyle)); }
	public static function monochrome($colorStop) { return new cocktail_core_drawing_FillStyleValue("monochrome", 1, array($colorStop)); }
	public static $none;
	public static $__constructors = array(3 => 'bitmap', 2 => 'gradient', 1 => 'monochrome', 0 => 'none');
	}
cocktail_core_drawing_FillStyleValue::$none = new cocktail_core_drawing_FillStyleValue("none", 0);
