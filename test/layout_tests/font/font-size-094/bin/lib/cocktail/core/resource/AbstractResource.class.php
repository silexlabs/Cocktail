<?php

class cocktail_core_resource_AbstractResource extends cocktail_core_event_EventTarget {
	public function __construct($url) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->loaded = false;
		$this->loadedWithError = false;
		$this->load($url);
	}}
	public function onLoadError() {
		$this->loadedWithError = true;
		$errorEvent = new cocktail_core_event_UIEvent();
		$errorEvent->initUIEvent("error", false, false, null, 0.0);
		$this->dispatchEvent($errorEvent);
	}
	public function onLoadComplete() {
		$this->loaded = true;
		$loadEvent = new cocktail_core_event_UIEvent();
		$loadEvent->initUIEvent("load", false, false, null, 0.0);
		$this->dispatchEvent($loadEvent);
	}
	public function load($url) {
	}
	public $intrinsicRatio;
	public $intrinsicHeight;
	public $intrinsicWidth;
	public $nativeResource;
	public $loadedWithError;
	public $loaded;
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
	function __toString() { return 'cocktail.core.resource.AbstractResource'; }
}
