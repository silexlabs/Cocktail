<?php

class cocktail_core_style_ZIndex extends Enum {
	public static $cssAuto;
	public static function integer($value) { return new cocktail_core_style_ZIndex("integer", 1, array($value)); }
	public static $__constructors = array(0 => 'cssAuto', 1 => 'integer');
	}
cocktail_core_style_ZIndex::$cssAuto = new cocktail_core_style_ZIndex("cssAuto", 0);
