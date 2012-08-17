<?php

class cocktail_core_html_HTMLImageElement extends cocktail_core_html_EmbeddedElement {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct("IMG");
	}}
	public function get_naturalWidth() {
		if($this->get_intrinsicWidth() === null) {
			return 0;
		}
		return Math::round($this->get_intrinsicWidth());
	}
	public function get_naturalHeight() {
		if($this->get_intrinsicHeight() === null) {
			return 0;
		}
		return Math::round($this->get_intrinsicHeight());
	}
	public function get_src() {
		return $this->getAttribute("src");
	}
	public function onLoadError() {
		$errorEvent = new cocktail_core_event_UIEvent();
		$errorEvent->initUIEvent("error", false, false, null, 0.0);
		$this->dispatchEvent($errorEvent);
	}
	public function onLoadComplete($resource) {
		$this->intrinsicHeight = $resource->intrinsicHeight;
		$this->intrinsicWidth = $resource->intrinsicWidth;
		$this->intrinsicRatio = $this->get_intrinsicHeight() / $this->get_intrinsicWidth();
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$other);
		$loadEvent = new cocktail_core_event_UIEvent();
		$loadEvent->initUIEvent("load", false, false, null, 0.0);
		$this->dispatchEvent($loadEvent);
	}
	public function removeListeners($resource) {
		$resource->removeEventListener("load", (isset($this->_resourceLoadedCallback) ? $this->_resourceLoadedCallback: array($this, "_resourceLoadedCallback")), null);
		$resource->removeEventListener("error", (isset($this->_resourceLoadError) ? $this->_resourceLoadError: array($this, "_resourceLoadError")), null);
	}
	public function onResourceLoadError($e) {
		$this->removeListeners($e->target);
		$this->onLoadError();
	}
	public function onResourceLoaded($e) {
		$this->removeListeners($e->target);
		$this->onLoadComplete($e->target);
	}
	public function set_src($value) {
		parent::setAttribute("src",$value);
		$resource = cocktail_core_resource_ResourceManager::getResource($value);
		if($resource->loaded === false) {
			$this->_resourceLoadedCallback = (isset($this->onResourceLoaded) ? $this->onResourceLoaded: array($this, "onResourceLoaded"));
			$this->_resourceLoadError = (isset($this->onResourceLoadError) ? $this->onResourceLoadError: array($this, "onResourceLoadError"));
			$resource->addEventListener("load", (isset($this->_resourceLoadedCallback) ? $this->_resourceLoadedCallback: array($this, "_resourceLoadedCallback")), null);
			$resource->addEventListener("error", (isset($this->_resourceLoadError) ? $this->_resourceLoadError: array($this, "_resourceLoadError")), null);
		} else {
			if($resource->loadedWithError === true) {
				$this->onLoadError();
			} else {
				$this->onLoadComplete($resource);
			}
		}
		return $value;
	}
	public function isVoidElement() {
		return true;
	}
	public function createElementRenderer() {
		$this->elementRenderer = new cocktail_core_renderer_ImageRenderer($this);
	}
	public function setAttribute($name, $value) {
		if($name === "src") {
			$this->set_src($value);
		} else {
			parent::setAttribute($name,$value);
		}
	}
	public $_resourceLoadError;
	public $_resourceLoadedCallback;
	public $naturalHeight;
	public $naturalWidth;
	public $src;
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
	static $__properties__ = array("set_src" => "set_src","get_src" => "get_src","get_naturalWidth" => "get_naturalWidth","get_naturalHeight" => "get_naturalHeight","set_height" => "set_height","get_height" => "get_height","set_width" => "set_width","get_width" => "get_width","get_intrinsicHeight" => "get_intrinsicHeight","get_intrinsicWidth" => "get_intrinsicWidth","get_intrinsicRatio" => "get_intrinsicRatio","set_tabIndex" => "set_tabIndex","get_tabIndex" => "get_tabIndex","set_id" => "set_id","get_id" => "get_id","set_className" => "set_className","get_className" => "get_className","set_hidden" => "set_hidden","get_hidden" => "get_hidden","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","get_scrollHeight" => "get_scrollHeight","get_scrollWidth" => "get_scrollWidth","set_innerHTML" => "set_innerHTML","get_innerHTML" => "get_innerHTML","get_offsetParent" => "get_offsetParent","get_offsetWidth" => "get_offsetWidth","get_offsetHeight" => "get_offsetHeight","get_offsetLeft" => "get_offsetLeft","get_offsetTop" => "get_offsetTop","get_clientWidth" => "get_clientWidth","get_clientHeight" => "get_clientHeight","get_clientLeft" => "get_clientLeft","get_clientTop" => "get_clientTop","get_firstElementChild" => "get_firstElementChild","get_lastElementChild" => "get_lastElementChild","get_previousElementSibling" => "get_previousElementSibling","get_nextElementSibling" => "get_nextElementSibling","get_childElementCount" => "get_childElementCount","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.html.HTMLImageElement'; }
}
