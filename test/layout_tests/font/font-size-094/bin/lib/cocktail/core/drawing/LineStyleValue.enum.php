<?php

class cocktail_core_drawing_LineStyleValue extends Enum {
	public static function bitmap($nativeElement, $lineStyle, $repeat) { return new cocktail_core_drawing_LineStyleValue("bitmap", 3, array($nativeElement, $lineStyle, $repeat)); }
	public static function gradient($gradientStyle, $lineStyle) { return new cocktail_core_drawing_LineStyleValue("gradient", 2, array($gradientStyle, $lineStyle)); }
	public static function monochrome($color, $lineStyle) { return new cocktail_core_drawing_LineStyleValue("monochrome", 1, array($color, $lineStyle)); }
	public static $none;
	public static $__constructors = array(3 => 'bitmap', 2 => 'gradient', 1 => 'monochrome', 0 => 'none');
	}
cocktail_core_drawing_LineStyleValue::$none = new cocktail_core_drawing_LineStyleValue("none", 0);
