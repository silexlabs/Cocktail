<?php

class cocktail_core_resource_ResourceLoader {
	public function __construct() {
		;
	}
	public function onLoadError($msg) {
		$this->_urlToLoadIdx++;
		if($this->_urlToLoadIdx < $this->_urls->length - 1) {
			$this->doLoad($this->_urls[$this->_urlToLoadIdx]);
		} else {
			$this->_onLoadErrorCallback($msg);
		}
	}
	public function onLoadComplete($data) {
		$this->_onLoadCompleteCallback($data);
	}
	public function doLoad($url) {
	}
	public function load($urls, $onLoadComplete, $onLoadError) {
		$this->_onLoadCompleteCallback = $onLoadComplete;
		$this->_onLoadErrorCallback = $onLoadError;
		$this->_urls = $urls;
		$this->_urlToLoadIdx = 0;
		$this->doLoad($this->_urls[$this->_urlToLoadIdx]);
	}
	public $_urls;
	public $_urlToLoadIdx;
	public $_onLoadErrorCallback;
	public $_onLoadCompleteCallback;
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
	function __toString() { return 'cocktail.core.resource.ResourceLoader'; }
}
