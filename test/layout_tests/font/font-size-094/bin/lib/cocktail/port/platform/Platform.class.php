<?php

class cocktail_port_platform_Platform {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->mouse = new cocktail_port_platform_mouse_AbstractMouse();
		$this->keyboard = new cocktail_port_platform_keyboard_AbstractKeyboard();
		$this->nativeWindow = new cocktail_port_platform_nativeWindow_AbstractNativeWindow();
		$this->touchListener = new cocktail_port_platform_touch_AbstractTouchListener();
	}}
	public $touchListener;
	public $nativeWindow;
	public $mouse;
	public $keyboard;
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
	function __toString() { return 'cocktail.port.platform.Platform'; }
}
