<?php

class cocktail_core_style_TransformFunction extends Enum {
	public static function matrix($data) { return new cocktail_core_style_TransformFunction("matrix", 0, array($data)); }
	public static function rotate($angle) { return new cocktail_core_style_TransformFunction("rotate", 7, array($angle)); }
	public static function scale($sx, $sy) { return new cocktail_core_style_TransformFunction("scale", 4, array($sx, $sy)); }
	public static function scaleX($sx) { return new cocktail_core_style_TransformFunction("scaleX", 5, array($sx)); }
	public static function scaleY($sy) { return new cocktail_core_style_TransformFunction("scaleY", 6, array($sy)); }
	public static function skew($angleX, $angleY) { return new cocktail_core_style_TransformFunction("skew", 10, array($angleX, $angleY)); }
	public static function skewX($angle) { return new cocktail_core_style_TransformFunction("skewX", 8, array($angle)); }
	public static function skewY($angle) { return new cocktail_core_style_TransformFunction("skewY", 9, array($angle)); }
	public static function translate($tx, $ty) { return new cocktail_core_style_TransformFunction("translate", 1, array($tx, $ty)); }
	public static function translateX($tx) { return new cocktail_core_style_TransformFunction("translateX", 2, array($tx)); }
	public static function translateY($ty) { return new cocktail_core_style_TransformFunction("translateY", 3, array($ty)); }
	public static $__constructors = array(0 => 'matrix', 7 => 'rotate', 4 => 'scale', 5 => 'scaleX', 6 => 'scaleY', 10 => 'skew', 8 => 'skewX', 9 => 'skewY', 1 => 'translate', 2 => 'translateX', 3 => 'translateY');
	}
