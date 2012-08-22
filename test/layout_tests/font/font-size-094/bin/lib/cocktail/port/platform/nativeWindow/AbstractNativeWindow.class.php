<?php

class cocktail_port_platform_nativeWindow_AbstractNativeWindow {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->setNativeListeners();
	}}
	public function get_innerWidth() {
		return -1;
	}
	public function get_innerHeight() {
		return -1;
	}
	public function getEvent($event) {
		return null;
	}
	public function getUIEvent($event) {
		return null;
	}
	public function removeNativeListeners() {
	}
	public function setNativeListeners() {
	}
	public function onNativeFullScreenChange($event) {
		if($this->onFullScreenChange !== null) {
			$this->onFullScreenChange($this->getEvent($event));
		}
	}
	public function onNativeResize($event) {
		if($this->onResize !== null) {
			$this->onResize($this->getUIEvent($event));
		}
	}
	public function getInitialNativeLayer() {
		return null;
	}
	public function fullscreen() {
		return false;
	}
	public function fullScreenEnabled() {
		return false;
	}
	public function exitFullscreen() {
	}
	public function enterFullscreen() {
	}
	public function open($url, $name) {
	}
	public $innerWidth;
	public $innerHeight;
	public $onFullScreenChange;
	public $onResize;
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
	static $__properties__ = array("get_innerHeight" => "get_innerHeight","get_innerWidth" => "get_innerWidth");
	function __toString() { return 'cocktail.port.platform.nativeWindow.AbstractNativeWindow'; }
}
