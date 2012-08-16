<?php

class cocktail_core_event_WheelEvent extends cocktail_core_event_MouseEvent {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initWheelEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg, $screenXArg, $screenYArg, $clientXArg, $clientYArg, $buttonArg, $relatedTargetArg, $modifiersListArg, $deltaXArg, $deltaYArg, $deltaZArg, $deltaModeArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initMouseEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $viewArg, $detailArg, $screenXArg, $screenYArg, $clientXArg, $clientYArg, false, false, false, false, $buttonArg, $relatedTargetArg);
		$this->deltaY = $deltaYArg;
		$this->deltaX = $deltaXArg;
		$this->deltaMode = $deltaModeArg;
		$this->deltaZ = $deltaZArg;
	}
	public $deltaMode;
	public $deltaZ;
	public $deltaY;
	public $deltaX;
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
	static $MOUSE_WHEEL = "wheel";
	static $DOM_DELTA_PIXEL = 0;
	static $DOM_DELTA_LINE = 1;
	static $DOM_DELTA_PAGE = 2;
	function __toString() { return 'cocktail.core.event.WheelEvent'; }
}
