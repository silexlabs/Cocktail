<?php

class cocktail_core_renderer_TextToken extends Enum {
	public static $lineFeed;
	public static $space;
	public static $tab;
	public static function word($value) { return new cocktail_core_renderer_TextToken("word", 0, array($value)); }
	public static $__constructors = array(3 => 'lineFeed', 1 => 'space', 2 => 'tab', 0 => 'word');
	}
cocktail_core_renderer_TextToken::$lineFeed = new cocktail_core_renderer_TextToken("lineFeed", 3);
cocktail_core_renderer_TextToken::$space = new cocktail_core_renderer_TextToken("space", 1);
cocktail_core_renderer_TextToken::$tab = new cocktail_core_renderer_TextToken("tab", 2);
