<?php

class cocktail_core_event_FocusEvent extends cocktail_core_event_UIEvent {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initFocusEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg, $relatedTargetArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initUIEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg);
		$this->relatedTarget = $relatedTargetArg;
	}
	public $relatedTarget;
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
	static $FOCUS = "focus";
	static $BLUR = "blur";
	static $FOCUS_IN = "focusin";
	static $FOCUS_OUT = "focusout";
	function __toString() { return 'cocktail.core.event.FocusEvent'; }
}
