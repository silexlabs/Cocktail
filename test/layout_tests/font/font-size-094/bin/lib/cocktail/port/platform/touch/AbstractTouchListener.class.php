<?php

class cocktail_port_platform_touch_AbstractTouchListener {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->setNativeListeners();
	}}
	public function getTouchEvent($event) {
		return null;
	}
	public function removeNativeListeners() {
	}
	public function setNativeListeners() {
	}
	public function onNativeTouchMove($event) {
		if($this->onTouchMove !== null) {
			$this->onTouchMove($this->getTouchEvent($event));
		}
	}
	public function onNativeTouchEnd($event) {
		if($this->onTouchEnd !== null) {
			$this->onTouchEnd($this->getTouchEvent($event));
		}
	}
	public function onNativeTouchStart($event) {
		if($this->onTouchStart !== null) {
			$this->onTouchStart($this->getTouchEvent($event));
		}
	}
	public $onTouchMove;
	public $onTouchEnd;
	public $onTouchStart;
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
	function __toString() { return 'cocktail.port.platform.touch.AbstractTouchListener'; }
}
