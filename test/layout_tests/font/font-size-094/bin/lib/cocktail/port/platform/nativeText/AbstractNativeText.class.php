<?php

class cocktail_port_platform_nativeText_AbstractNativeText {
	public function __construct($nativeElement) {
		if(!php_Boot::$skip_constructor) {
		$this->_nativeElement = $nativeElement;
	}}
	public function get_width() {
		return 0.0;
	}
	public function getBitmap($bounds) {
		return null;
	}
	public $_nativeElement;
	public $width;
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
	static $__properties__ = array("get_width" => "get_width");
	function __toString() { return 'cocktail.port.platform.nativeText.AbstractNativeText'; }
}
