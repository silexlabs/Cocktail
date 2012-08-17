<?php

class cocktail_port_platform_keyboard_AbstractKeyboard {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->setNativeListeners();
	}}
	public function getKeyData($event) {
		return null;
	}
	public function removeNativeListeners() {
	}
	public function setNativeListeners() {
	}
	public function onNativeKeyUp($event) {
		if($this->onKeyUp !== null) {
			$this->onKeyUp($this->getKeyData($event));
		}
	}
	public function onNativeKeyDown($event) {
		if($this->onKeyDown !== null) {
			$this->onKeyDown($this->getKeyData($event));
		}
	}
	public $onKeyUp;
	public $onKeyDown;
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
	function __toString() { return 'cocktail.port.platform.keyboard.AbstractKeyboard'; }
}
