<?php

class cocktail_core_event_EventListener {
	public function __construct($eventType, $listener, $useCapture) {
		if(!php_Boot::$skip_constructor) {
		$this->listener = $listener;
		$this->useCapture = $useCapture;
		$this->eventType = $eventType;
	}}
	public function dispose() {
		$this->listener = null;
	}
	public function handleEvent($evt) {
		$this->listener($evt);
	}
	public $eventType;
	public $listener;
	public $useCapture;
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
	function __toString() { return 'cocktail.core.event.EventListener'; }
}
