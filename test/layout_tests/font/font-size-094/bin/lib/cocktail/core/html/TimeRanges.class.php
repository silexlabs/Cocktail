<?php

class cocktail_core_html_TimeRanges {
	public function __construct($ranges) {
		if(!php_Boot::$skip_constructor) {
		$this->_ranges = $ranges;
	}}
	public function get_length() {
		return $this->_ranges->length;
	}
	public function end($index) {
		return _hx_array_get($this->_ranges, $index)->end;
	}
	public function start($index) {
		return _hx_array_get($this->_ranges, $index)->start;
	}
	public $_ranges;
	public $length;
	public function __call($m, $a) {
		if(isset($this->$m) && is_callable($this->$m))
			return call_user_func_array($this->$m, $a);
		else if(isset($this->»dynamics[$m]) && is_callable($this->»dynamics[$m]))
			return call_user_func_array($this->»dynamics[$m], $a);
		else if('toString' == $m)
			return $this->__toString();
		else
			throw new HException('Unable to call «'.$m.'»');
	}
	static $__properties__ = array("get_length" => "get_length");
	function __toString() { return 'cocktail.core.html.TimeRanges'; }
}
