<?php

class lib_hxtml_Value extends Enum {
	public static function VFloat($v) { return new lib_hxtml_Value("VFloat", 5, array($v)); }
	public static function VGroup($l) { return new lib_hxtml_Value("VGroup", 9, array($l)); }
	public static function VHex($v) { return new lib_hxtml_Value("VHex", 7, array($v)); }
	public static function VIdent($i) { return new lib_hxtml_Value("VIdent", 0, array($i)); }
	public static function VInt($v) { return new lib_hxtml_Value("VInt", 6, array($v)); }
	public static function VLabel($v, $val) { return new lib_hxtml_Value("VLabel", 11, array($v, $val)); }
	public static function VList($l) { return new lib_hxtml_Value("VList", 8, array($l)); }
	public static function VRGB($v) { return new lib_hxtml_Value("VRGB", 4, array($v)); }
	public static function VRGBA($v) { return new lib_hxtml_Value("VRGBA", 3, array($v)); }
	public static $VSlash;
	public static function VString($s) { return new lib_hxtml_Value("VString", 1, array($s)); }
	public static function VUnit($v, $unit) { return new lib_hxtml_Value("VUnit", 2, array($v, $unit)); }
	public static function VUrl($v) { return new lib_hxtml_Value("VUrl", 10, array($v)); }
	public static $__constructors = array(5 => 'VFloat', 9 => 'VGroup', 7 => 'VHex', 0 => 'VIdent', 6 => 'VInt', 11 => 'VLabel', 8 => 'VList', 4 => 'VRGB', 3 => 'VRGBA', 12 => 'VSlash', 1 => 'VString', 2 => 'VUnit', 10 => 'VUrl');
	}
lib_hxtml_Value::$VSlash = new lib_hxtml_Value("VSlash", 12);
