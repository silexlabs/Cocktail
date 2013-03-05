<?php

class haxe_StackItem extends Enum {
	public static $CFunction;
	public static function FilePos($s, $file, $line) { return new haxe_StackItem("FilePos", 2, array($s, $file, $line)); }
	public static function Lambda($v) { return new haxe_StackItem("Lambda", 4, array($v)); }
	public static function Method($classname, $method) { return new haxe_StackItem("Method", 3, array($classname, $method)); }
	public static function Module($m) { return new haxe_StackItem("Module", 1, array($m)); }
	public static $__constructors = array(0 => 'CFunction', 2 => 'FilePos', 4 => 'Lambda', 3 => 'Method', 1 => 'Module');
	}
haxe_StackItem::$CFunction = new haxe_StackItem("CFunction", 0);
