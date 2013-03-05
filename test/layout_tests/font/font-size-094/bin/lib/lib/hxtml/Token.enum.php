<?php

class lib_hxtml_Token extends Enum {
	public static $TBrClose;
	public static $TBrOpen;
	public static $TComma;
	public static $TDblDot;
	public static $TDot;
	public static $TEof;
	public static $TExclam;
	public static function TFloat($f) { return new lib_hxtml_Token("TFloat", 3, array($f)); }
	public static function TIdent($i) { return new lib_hxtml_Token("TIdent", 0, array($i)); }
	public static function TInt($i) { return new lib_hxtml_Token("TInt", 2, array($i)); }
	public static $TPClose;
	public static $TPOpen;
	public static $TPercent;
	public static $TSemicolon;
	public static $TSharp;
	public static $TSlash;
	public static $TSpaces;
	public static function TString($s) { return new lib_hxtml_Token("TString", 1, array($s)); }
	public static $__constructors = array(14 => 'TBrClose', 13 => 'TBrOpen', 9 => 'TComma', 4 => 'TDblDot', 15 => 'TDot', 10 => 'TEof', 8 => 'TExclam', 3 => 'TFloat', 0 => 'TIdent', 2 => 'TInt', 7 => 'TPClose', 6 => 'TPOpen', 11 => 'TPercent', 12 => 'TSemicolon', 5 => 'TSharp', 17 => 'TSlash', 16 => 'TSpaces', 1 => 'TString');
	}
lib_hxtml_Token::$TBrClose = new lib_hxtml_Token("TBrClose", 14);
lib_hxtml_Token::$TBrOpen = new lib_hxtml_Token("TBrOpen", 13);
lib_hxtml_Token::$TComma = new lib_hxtml_Token("TComma", 9);
lib_hxtml_Token::$TDblDot = new lib_hxtml_Token("TDblDot", 4);
lib_hxtml_Token::$TDot = new lib_hxtml_Token("TDot", 15);
lib_hxtml_Token::$TEof = new lib_hxtml_Token("TEof", 10);
lib_hxtml_Token::$TExclam = new lib_hxtml_Token("TExclam", 8);
lib_hxtml_Token::$TPClose = new lib_hxtml_Token("TPClose", 7);
lib_hxtml_Token::$TPOpen = new lib_hxtml_Token("TPOpen", 6);
lib_hxtml_Token::$TPercent = new lib_hxtml_Token("TPercent", 11);
lib_hxtml_Token::$TSemicolon = new lib_hxtml_Token("TSemicolon", 12);
lib_hxtml_Token::$TSharp = new lib_hxtml_Token("TSharp", 5);
lib_hxtml_Token::$TSlash = new lib_hxtml_Token("TSlash", 17);
lib_hxtml_Token::$TSpaces = new lib_hxtml_Token("TSpaces", 16);
