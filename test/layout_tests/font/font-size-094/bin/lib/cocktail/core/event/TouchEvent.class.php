<?php

class cocktail_core_event_TouchEvent extends cocktail_core_event_UIEvent {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initTouchEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg, $touchesArg, $targetTouchesArg, $changedTouchesArg, $altKeyArg, $metaKeyArg, $ctrlKeyArg, $shiftKeyArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initUIEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg);
		$this->touches = $touchesArg;
		$targetTouchesArg = $this->targetTouches;
		$this->changedTouches = $changedTouchesArg;
		$this->altKey = $altKeyArg;
		$this->metaKey = $metaKeyArg;
		$this->ctrlKey = $ctrlKeyArg;
		$this->shiftKey = $shiftKeyArg;
	}
	public $shiftKey;
	public $ctrlKey;
	public $metaKey;
	public $altKey;
	public $changedTouches;
	public $targetTouches;
	public $touches;
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
	static $TOUCH_START = "touchstart";
	static $TOUCH_END = "touchend";
	static $TOUCH_MOVE = "touchmove";
	static $TOUCH_CANCEL = "touchcancel";
	function __toString() { return 'cocktail.core.event.TouchEvent'; }
}
