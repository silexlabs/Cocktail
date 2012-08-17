<?php

class cocktail_core_multitouch_MultiTouchManager {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->_touches = new _hx_array(array());
	}}
	public function getTouchByIdentifier($identifier) {
		$length = $this->_touches->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$touch = $this->_touches[$i];
				if($touch->identifier === $identifier) {
					return $touch;
				}
				unset($touch,$i);
			}
		}
		return null;
	}
	public function getTouchesByTarget($target) {
		$targetTouches = new _hx_array(array());
		$length = $this->_touches->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$touch = $this->_touches[$i];
				if($touch->target === $target) {
					$targetTouches->push($touch);
				}
				unset($touch,$i);
			}
		}
		return new cocktail_core_event_TouchList($targetTouches);
	}
	public function initTouchEvent($touchEvent, $targetTouches, $changedTouches) {
		$touchEvent->initTouchEvent($touchEvent->type, true, true, null, 0.0, new cocktail_core_event_TouchList($this->_touches), $targetTouches, $changedTouches, false, false, false, false);
	}
	public function updatePagePosition($touch) {
	}
	public function updateStoredTouch($storedTouch, $touch) {
		$storedTouch->clientX = $touch->clientX;
		$storedTouch->clientY = $touch->clientY;
		$storedTouch->screenX = $touch->screenX;
		$storedTouch->screenY = $touch->screenY;
		$this->updatePagePosition($storedTouch);
	}
	public function updateTouch($touch, $touchEvent) {
		$storedTouch = $this->getTouchByIdentifier($touch->identifier);
		$this->updateStoredTouch($storedTouch, $touch);
		$this->initTouchEvent($touchEvent, $this->getTouchesByTarget($touch->target), new cocktail_core_event_TouchList(new _hx_array(array($touch))));
	}
	public function unregisterTouch($touch, $touchEvent) {
		$storedTouch = $this->getTouchByIdentifier($touch->identifier);
		$this->updateStoredTouch($storedTouch, $touch);
		$this->initTouchEvent($touchEvent, $this->getTouchesByTarget($touch->target), new cocktail_core_event_TouchList(new _hx_array(array($touch))));
		$this->_touches->remove($storedTouch);
	}
	public function registerTouch($touch, $touchEvent, $target) {
		$touch->target = $target;
		$this->updatePagePosition($touch);
		$this->_touches->push($touch);
		$this->initTouchEvent($touchEvent, $this->getTouchesByTarget($target), new cocktail_core_event_TouchList(new _hx_array(array($touch))));
	}
	public function setUpTouchEvent($touchEvent, $target) {
		$touch = $touchEvent->touches->item(0);
		switch($touchEvent->type) {
		case "touchstart":{
			$this->registerTouch($touch, $touchEvent, $target);
		}break;
		case "touchend":{
			$this->unregisterTouch($touch, $touchEvent);
		}break;
		case "touchmove":{
			$this->updateTouch($touch, $touchEvent);
		}break;
		}
	}
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
	function __toString() { return 'cocktail.core.multitouch.MultiTouchManager'; }
}
