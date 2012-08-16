<?php

class cocktail_core_focus_FocusManager {
	public function __construct() {
		;
	}
	public function setActiveElement($newActiveElement, $body) {
		if($newActiveElement === null) {
			return $this->activeElement;
		}
		if($this->activeElement === null) {
			return $this->activeElement = $newActiveElement;
		}
		if($newActiveElement !== $this->activeElement) {
			$focusOutEvent = new cocktail_core_event_FocusEvent();
			$focusOutEvent->initFocusEvent("focusout", true, false, null, 0.0, $newActiveElement);
			$this->activeElement->dispatchEvent($focusOutEvent);
			$focusInEvent = new cocktail_core_event_FocusEvent();
			$focusInEvent->initFocusEvent("focusin", true, false, null, 0.0, $this->activeElement);
			$newActiveElement->dispatchEvent($focusInEvent);
			$oldActiveElement = $this->activeElement;
			if($newActiveElement->isFocusable() === true) {
				$this->activeElement = $newActiveElement;
			} else {
				$this->activeElement = $body;
			}
			$blurEvent = new cocktail_core_event_FocusEvent();
			$blurEvent->initFocusEvent("blur", false, false, null, 0.0, null);
			$oldActiveElement->dispatchEvent($blurEvent);
			$focusEvent = new cocktail_core_event_FocusEvent();
			$focusEvent->initFocusEvent("focus", false, false, null, 0.0, null);
			$newActiveElement->dispatchEvent($focusEvent);
			if($this->activeElement->onfocus !== null) {
				$focusEvent1 = new cocktail_core_event_FocusEvent();
				$focusEvent1->initFocusEvent("focus", true, false, null, 0.0, null);
				$this->activeElement->onfocus($focusEvent1);
			}
		}
		return $this->activeElement;
	}
	public function doBuildTabList($htmlElement, $orderedTabList, $indexedTabList) {
		$_g1 = 0; $_g = $htmlElement->childNodes->length;
		while($_g1 < $_g) {
			$i = $_g1++;
			if(_hx_array_get($htmlElement->childNodes, $i)->get_nodeType() === 1) {
				$child = $htmlElement->childNodes[$i];
				if($child->hasChildNodes() === true) {
					$this->doBuildTabList($child, $orderedTabList, $indexedTabList);
				}
				if($child->isFocusable() === true) {
					if($child->get_tabIndex() === 0) {
						$orderedTabList->push($child);
					} else {
						if($child->get_tabIndex() > 0) {
							if($indexedTabList->length === 0) {
								$indexedTabList->push($child);
							} else {
								$foundSpotFlag = false;
								{
									$_g3 = 0; $_g2 = $indexedTabList->length;
									while($_g3 < $_g2) {
										$j = $_g3++;
										if($child->get_tabIndex() < _hx_array_get($indexedTabList, $j)->get_tabIndex()) {
											$indexedTabList->insert($j, $child);
											$foundSpotFlag = true;
										}
										unset($j);
									}
									unset($_g3,$_g2);
								}
								if($foundSpotFlag === false) {
									$indexedTabList->push($child);
								}
								unset($foundSpotFlag);
							}
						}
					}
				}
				unset($child);
			}
			unset($i);
		}
	}
	public function buildTabList($rootElement) {
		$orderedTabList = new _hx_array(array());
		$indexedTabList = new _hx_array(array());
		$this->doBuildTabList($rootElement, $orderedTabList, $indexedTabList);
		{
			$_g1 = 0; $_g = $orderedTabList->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$indexedTabList->push($orderedTabList[$i]);
				unset($i);
			}
		}
		return $indexedTabList;
	}
	public function getElementTabListIndex($element, $tabList) {
		{
			$_g1 = 0; $_g = $tabList->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				if($tabList[$i] === $element) {
					return $i;
				}
				unset($i);
			}
		}
		return -1;
	}
	public function getNextFocusedElement($reverse, $rootElement, $activeElement) {
		$tabList = $this->buildTabList($rootElement);
		$tabListIndex = null;
		if($activeElement === $rootElement) {
			if($reverse === false) {
				$tabListIndex = 0;
			} else {
				$tabListIndex = $tabList->length - 1;
			}
		} else {
			$tabListIndex = $this->getElementTabListIndex($activeElement, $tabList);
			if($reverse === false) {
				$tabListIndex++;
			} else {
				$tabListIndex--;
			}
		}
		if($tabListIndex === $tabList->length) {
			$tabListIndex = 0;
		} else {
			if($tabListIndex === -1) {
				$tabListIndex = $tabList->length - 1;
			}
		}
		return $tabList[$tabListIndex];
	}
	public $activeElement;
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
	function __toString() { return 'cocktail.core.focus.FocusManager'; }
}
