<?php

class cocktail_core_style_WhiteSpace extends Enum {
	public static $normal;
	public static $nowrap;
	public static $pre;
	public static $preLine;
	public static $preWrap;
	public static $__constructors = array(0 => 'normal', 2 => 'nowrap', 1 => 'pre', 4 => 'preLine', 3 => 'preWrap');
	}
cocktail_core_style_WhiteSpace::$normal = new cocktail_core_style_WhiteSpace("normal", 0);
cocktail_core_style_WhiteSpace::$nowrap = new cocktail_core_style_WhiteSpace("nowrap", 2);
cocktail_core_style_WhiteSpace::$pre = new cocktail_core_style_WhiteSpace("pre", 1);
cocktail_core_style_WhiteSpace::$preLine = new cocktail_core_style_WhiteSpace("preLine", 4);
cocktail_core_style_WhiteSpace::$preWrap = new cocktail_core_style_WhiteSpace("preWrap", 3);
