<?php

class cocktail_core_event_TransitionEvent extends cocktail_core_event_Event {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function initTransitionEvent($eventTypeArg, $canBubbleArg, $cancelableArg, $propertyNameArg, $elapsedTimeArg, $pseudoElementArg) {
		if($this->dispatched === true) {
			return;
		}
		$this->initEvent($eventTypeArg, $canBubbleArg, $cancelableArg);
		$this->propertyName = $propertyNameArg;
		$this->elapsedTime = $elapsedTimeArg;
		$this->pseudoElement = $pseudoElementArg;
	}
	public $pseudoElement;
	public $elapsedTime;
	public $propertyName;
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
	static $TRANSITION_END = "transitionend";
	function __toString() { return 'cocktail.core.event.TransitionEvent'; }
}
