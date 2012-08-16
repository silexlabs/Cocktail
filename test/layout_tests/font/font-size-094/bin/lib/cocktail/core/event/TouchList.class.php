<?php

class cocktail_core_event_TouchList {
	public function __construct($touches) {
		if(!php_Boot::$skip_constructor) {
		$this->_touches = $touches;
	}}
	public function get_length() {
		return $this->_touches->length;
	}
	public function identifiedTouch($identifier) {
		{
			$_g1 = 0; $_g = $this->get_length();
			while($_g1 < $_g) {
				$i = $_g1++;
				if(_hx_array_get($this->_touches, $i)->identifier === $identifier) {
					return $this->_touches[$i];
				}
				unset($i);
			}
		}
		return null;
	}
	public function item($index) {
		return $this->_touches[$index];
	}
	public $length;
	public $_touches;
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
	static $__properties__ = array("get_length" => "get_length");
	function __toString() { return 'cocktail.core.event.TouchList'; }
}
