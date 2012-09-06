<?php

class cocktail_core_event_EventTarget {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->_registeredEventListeners = new Hash();
	}}
	public function executeDefaultActionIfNeeded($defaultPrevented, $event) {
	}
	public function getTargetAncestors() {
		return new _hx_array(array());
	}
	public function endEventDispatching($evt) {
		$defaultPrevented = $evt->defaultPrevented;
		$this->executeDefaultActionIfNeeded($defaultPrevented, $evt);
		$evt->reset();
		return $defaultPrevented;
	}
	public function shouldStopEventPropagation($evt) {
		return $evt->propagationStopped === true || $evt->immediatePropagationStopped === true;
	}
	public function doDispatchEvent($eventListeners, $evt) {
		$length = $eventListeners->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$eventListener = $eventListeners[$i];
				if($evt->eventPhase === 1) {
					if($eventListener->useCapture === true) {
						$eventListener->handleEvent($evt);
					}
				} else {
					if($evt->eventPhase === 3) {
						if($eventListener->useCapture === false) {
							$eventListener->handleEvent($evt);
						}
					} else {
						if($evt->eventPhase === 2) {
							$eventListener->handleEvent($evt);
						}
					}
				}
				if($evt->immediatePropagationStopped === true) {
					return;
				}
				unset($i,$eventListener);
			}
		}
	}
	public function removeEventListener($type, $listener, $useCapture = null) {
		if($useCapture === null) {
			$useCapture = false;
		}
		if($this->_registeredEventListeners->exists($type) === true) {
			$registeredListeners = $this->_registeredEventListeners->get($type);
			$newEventListeners = new _hx_array(array());
			{
				$_g1 = 0; $_g = $registeredListeners->length;
				while($_g1 < $_g) {
					$i = $_g1++;
					$eventListener = $registeredListeners[$i];
					if($eventListener->eventType === $type && $eventListener->useCapture === $useCapture && $eventListener->listener == $listener) {
						$eventListener->dispose();
					} else {
						$newEventListeners->push($eventListener);
					}
					unset($i,$eventListener);
				}
			}
			$this->_registeredEventListeners->set($type, $newEventListeners);
		}
	}
	public function addEventListener($type, $listener, $useCapture = null) {
		if($useCapture === null) {
			$useCapture = false;
		}
		if($this->_registeredEventListeners->exists($type) === false) {
			$this->_registeredEventListeners->set($type, new _hx_array(array()));
		}
		$this->removeEventListener($type, $listener, $useCapture);
		$eventListener = new cocktail_core_event_EventListener($type, $listener, $useCapture);
		$this->_registeredEventListeners->get($type)->push($eventListener);
	}
	public function dispatchEvent($evt) {
		$evt->currentTarget = $this;
		if($evt->dispatched === false) {
			$evt->target = $this;
			$evt->dispatched = true;
			$targetAncestors = $this->getTargetAncestors();
			$evt->eventPhase = 1;
			$targetAncestors->reverse();
			{
				$_g1 = 0; $_g = $targetAncestors->length;
				while($_g1 < $_g) {
					$i = $_g1++;
					_hx_array_get($targetAncestors, $i)->dispatchEvent($evt);
					if($this->shouldStopEventPropagation($evt) === true) {
						return $this->endEventDispatching($evt);
					}
					unset($i);
				}
			}
			$evt->eventPhase = 2;
			$this->dispatchEvent($evt);
			if($this->shouldStopEventPropagation($evt) === true) {
				return $this->endEventDispatching($evt);
			}
			if($evt->bubbles === true) {
				$evt->eventPhase = 3;
				$targetAncestors->reverse();
				{
					$_g1 = 0; $_g = $targetAncestors->length;
					while($_g1 < $_g) {
						$i = $_g1++;
						_hx_array_get($targetAncestors, $i)->dispatchEvent($evt);
						if($this->shouldStopEventPropagation($evt) === true) {
							return $this->endEventDispatching($evt);
						}
						unset($i);
					}
				}
				return $this->endEventDispatching($evt);
			}
		} else {
			if($this->_registeredEventListeners->exists($evt->type) === true) {
				$this->doDispatchEvent($this->_registeredEventListeners->get($evt->type), $evt);
			}
		}
		return $evt->defaultPrevented;
	}
	public $_registeredEventListeners;
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
	function __toString() { return 'cocktail.core.event.EventTarget'; }
}
