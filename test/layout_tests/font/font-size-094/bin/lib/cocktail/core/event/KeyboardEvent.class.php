<?php

class cocktail_core_event_KeyboardEvent extends cocktail_core_event_UIEvent {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initKeyboardEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $charArg, $keyArg, $locationArg, $modifiersListArg, $repeatArg, $localeArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initUIEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, 0);
		$this->keyChar = $charArg;
		$this->key = $keyArg;
		$this->repeat = $repeatArg;
		$this->location = $locationArg;
		$this->locale = $localeArg;
	}
	public $repeat;
	public $metaKey;
	public $altKey;
	public $shiftKey;
	public $ctrlKey;
	public $locale;
	public $location;
	public $key;
	public $keyChar;
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
	static $KEY_DOWN = "keydown";
	static $KEY_UP = "keyup";
	static $DOM_KEY_LOCATION_STANDARD = 0;
	static $DOM_KEY_LOCATION_LEFT = 1;
	static $DOM_KEY_LOCATION_RIGHT = 2;
	static $DOM_KEY_LOCATION_NUMPAD = 3;
	static $DOM_KEY_LOCATION_MOBILE = 4;
	static $DOM_KEY_LOCATION_JOYSTICK = 5;
	function __toString() { return 'cocktail.core.event.KeyboardEvent'; }
}
