<?php

class cocktail_core_resource_AbstractMediaLoader extends cocktail_core_resource_ResourceLoader {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function getIntrinsicRatio() {
		return $this->_intrinsicRatio;
	}
	public function getIntrinsicHeight() {
		return $this->_intrinsicHeight;
	}
	public function getIntrinsicWidth() {
		return $this->_intrinsicWidth;
	}
	public function getNativeElement() {
		return $this->_nativeElement;
	}
	public $intrinsicRatio;
	public $_intrinsicRatio;
	public $intrinsicHeight;
	public $_intrinsicHeight;
	public $intrinsicWidth;
	public $_intrinsicWidth;
	public $nativeElement;
	public $_nativeElement;
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
	static $__properties__ = array("get_nativeElement" => "getNativeElement","get_intrinsicWidth" => "getIntrinsicWidth","get_intrinsicHeight" => "getIntrinsicHeight","get_intrinsicRatio" => "getIntrinsicRatio");
	function __toString() { return 'cocktail.core.resource.AbstractMediaLoader'; }
}
