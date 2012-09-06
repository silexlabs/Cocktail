<?php

class cocktail_core_style_transition_TransitionManager {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->_transitions = new Hash();
		$this->_currentTransitionsNumber = 0;
		$this->_lastTick = 0;
	}}
	public function onTransitionTick() {
		$tick = Date::now()->getTime();
		$interval = $tick - $this->_lastTick;
		$this->_lastTick = $tick;
		if(null == $this->_transitions) throw new HException('null iterable');
		$»it = $this->_transitions->iterator();
		while($»it->hasNext()) {
			$propertyTransitions = $»it->next();
			$completedTransitions = new _hx_array(array());
			$length = $propertyTransitions->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$transition = $propertyTransitions[$i];
					$transition->updateTime($interval);
					if($transition->get_complete() === true) {
						$transition->onComplete($transition);
						$completedTransitions->push($transition);
					} else {
						$transition->onUpdate($transition);
					}
					unset($transition,$i);
				}
				unset($_g);
			}
			$completedTransitionsLength = $completedTransitions->length;
			{
				$_g = 0;
				while($_g < $completedTransitionsLength) {
					$i = $_g++;
					$this->stopTransition($completedTransitions[$i]);
					unset($i);
				}
				unset($_g);
			}
			unset($length,$completedTransitionsLength,$completedTransitions);
		}
		if($this->_currentTransitionsNumber > 0) {
		}
	}
	public function startTransitionTimer() {
		$this->_lastTick = Date::now()->getTime();
	}
	public function stopTransition($transition) {
		$propertyTransitions = $this->_transitions->get($transition->propertyName);
		$propertyTransitions->remove($transition);
		$transition->dispose();
		$this->_currentTransitionsNumber--;
	}
	public function startTransition($target, $propertyName, $startValue, $endValue, $transitionDuration, $transitionDelay, $transitionTimingFunction, $onComplete, $onUpdate, $invalidationReason) {
		$transition = new cocktail_core_style_transition_Transition($propertyName, $target, $transitionDuration, $transitionDelay, $transitionTimingFunction, $startValue, $endValue, $onComplete, $onUpdate, $invalidationReason);
		if($this->_transitions->exists($propertyName) === false) {
			$this->_transitions->set($propertyName, new _hx_array(array()));
		}
		$propertyTransitions = $this->_transitions->get($propertyName);
		$propertyTransitions->push($transition);
		if($this->_currentTransitionsNumber === 0) {
			$this->startTransitionTimer();
		}
		$this->_currentTransitionsNumber++;
	}
	public function getTransition($propertyName, $style) {
		if($this->_currentTransitionsNumber === 0) {
			return null;
		}
		if($this->_transitions->exists($propertyName)) {
			$propertyTransitions = $this->_transitions->get($propertyName);
			$length = $propertyTransitions->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					if(_hx_array_get($propertyTransitions, $i)->target === $style) {
						return $propertyTransitions[$i];
					}
					unset($i);
				}
			}
		}
		return null;
	}
	public $_lastTick;
	public $_currentTransitionsNumber;
	public $_transitions;
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
	static $_instance;
	static $TRANSITION_UPDATE_SPEED = 20;
	static function getInstance() {
		if(cocktail_core_style_transition_TransitionManager::$_instance === null) {
			cocktail_core_style_transition_TransitionManager::$_instance = new cocktail_core_style_transition_TransitionManager();
		}
		return cocktail_core_style_transition_TransitionManager::$_instance;
	}
	function __toString() { return 'cocktail.core.style.transition.TransitionManager'; }
}
