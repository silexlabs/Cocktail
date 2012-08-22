<?php

class cocktail_core_style_Display extends Enum {
	public static $block;
	public static $cssInline;
	public static $inlineBlock;
	public static $none;
	public static $__constructors = array(0 => 'block', 2 => 'cssInline', 1 => 'inlineBlock', 3 => 'none');
	}
cocktail_core_style_Display::$block = new cocktail_core_style_Display("block", 0);
cocktail_core_style_Display::$cssInline = new cocktail_core_style_Display("cssInline", 2);
cocktail_core_style_Display::$inlineBlock = new cocktail_core_style_Display("inlineBlock", 1);
cocktail_core_style_Display::$none = new cocktail_core_style_Display("none", 3);
