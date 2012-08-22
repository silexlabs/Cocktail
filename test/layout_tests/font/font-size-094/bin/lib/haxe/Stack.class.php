<?php

class haxe_Stack {
	public function __construct(){}
	static function callStack() {
		return haxe_Stack::makeStack("%s");
	}
	static function exceptionStack() {
		return haxe_Stack::makeStack("%e");
	}
	static function toString($stack) {
		$b = new StringBuf();
		{
			$_g = 0;
			while($_g < $stack->length) {
				$s = $stack[$_g];
				++$_g;
				$b->add("\x0ACalled from ");
				haxe_Stack::itemToString($b, $s);
				unset($s);
			}
		}
		return $b->b;
	}
	static function itemToString($b, $s) {
		$�t = ($s);
		switch($�t->index) {
		case 0:
		{
			$b->add("a C function");
		}break;
		case 1:
		$m = $�t->params[0];
		{
			$b->add("module ");
			$b->add($m);
		}break;
		case 2:
		$line = $�t->params[2]; $file = $�t->params[1]; $s1 = $�t->params[0];
		{
			if($s1 !== null) {
				haxe_Stack::itemToString($b, $s1);
				$b->add(" (");
			}
			$b->add($file);
			$b->add(" line ");
			$b->add($line);
			if($s1 !== null) {
				$b->add(")");
			}
		}break;
		case 3:
		$meth = $�t->params[1]; $cname = $�t->params[0];
		{
			$b->add($cname);
			$b->add(".");
			$b->add($meth);
		}break;
		case 4:
		$n = $�t->params[0];
		{
			$b->add("local function #");
			$b->add($n);
		}break;
		}
	}
	static function makeStack($s) {
		if(!isset($GLOBALS[$s])) {
			return new _hx_array(array());
		}
		$a = $GLOBALS[$s];
		$m = new _hx_array(array());
		{
			$_g1 = 0; $_g = $a->length - ((($s === "%s") ? 2 : 0));
			while($_g1 < $_g) {
				$i = $_g1++;
				$d = _hx_explode("::", $a[$i]);
				$m->unshift(haxe_StackItem::Method($d[0], $d[1]));
				unset($i,$d);
			}
		}
		return $m;
	}
	function __toString() { return 'haxe.Stack'; }
}
