<?php

class cocktail_port_platform_mouse_AbstractMouse {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->setNativeListeners();
	}}
	public function getWheelEvent($event) {
		return null;
	}
	public function getMouseEvent($event) {
		return null;
	}
	public function removeNativeListeners() {
	}
	public function setNativeListeners() {
	}
	public function onNativeMouseWheel($event) {
		if($this->onMouseWheel !== null) {
			$this->onMouseWheel($this->getWheelEvent($event));
		}
	}
	public function onNativeMouseMove($event) {
		if($this->onMouseMove !== null) {
			$this->onMouseMove($this->getMouseEvent($event));
		}
	}
	public function onNativeMouseUp($event) {
		if($this->onMouseUp !== null) {
			$this->onMouseUp($this->getMouseEvent($event));
		}
	}
	public function onNativeMouseDown($event) {
		if($this->onMouseDown !== null) {
			$this->onMouseDown($this->getMouseEvent($event));
		}
	}
	public function setMouseCursor($cursor) {
	}
	public $onMouseWheel;
	public $onMouseMove;
	public $onMouseUp;
	public $onMouseDown;
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
	function __toString() { return 'cocktail.port.platform.mouse.AbstractMouse'; }
}
