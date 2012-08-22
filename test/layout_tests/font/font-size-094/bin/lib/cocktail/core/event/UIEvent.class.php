<?php

class cocktail_core_event_UIEvent extends cocktail_core_event_Event {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initUIEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initEvent($eventTypeArg, $canBubbleArg, $cancelableArg);
		$this->view = $viewArg;
		$this->detail = $detailArg;
	}
	public $detail;
	public $view;
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
	static $SCROLL = "scroll";
	static $RESIZE = "resize";
	static $LOAD = "load";
	static $ERROR = "error";
	function __toString() { return 'cocktail.core.event.UIEvent'; }
}
