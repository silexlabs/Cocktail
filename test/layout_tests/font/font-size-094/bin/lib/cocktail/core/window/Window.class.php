<?php

class cocktail_core_window_Window extends cocktail_core_event_EventCallback {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->init();
	}}
	public function get_innerWidth() {
		return $this->platform->nativeWindow->get_innerWidth();
	}
	public function get_innerHeight() {
		return $this->platform->nativeWindow->get_innerHeight();
	}
	public function onDocumentSetMouseCursor($cursor) {
		$this->platform->mouse->setMouseCursor($cursor);
	}
	public function onDocumentExitFullscreen() {
		$this->platform->nativeWindow->exitFullscreen();
	}
	public function onDocumentEnterFullscreen() {
		$this->platform->nativeWindow->enterFullscreen();
	}
	public function onPlatformFullScreenChange($event) {
		if($this->platform->nativeWindow->fullscreen() === false) {
			$this->document->exitFullscreen();
		}
	}
	public function open($url, $name = null) {
		if($name === null) {
			$name = "_blank";
		}
		$this->platform->nativeWindow->open($url, $name);
	}
	public function init() {
		$this->platform = new cocktail_port_platform_Platform();
		$htmlDocument = new cocktail_core_html_HTMLDocument($this);
		$this->platform->mouse->onMouseDown = (isset($htmlDocument->onPlatformMouseEvent) ? $htmlDocument->onPlatformMouseEvent: array($htmlDocument, "onPlatformMouseEvent"));
		$this->platform->mouse->onMouseUp = (isset($htmlDocument->onPlatformMouseEvent) ? $htmlDocument->onPlatformMouseEvent: array($htmlDocument, "onPlatformMouseEvent"));
		$this->platform->mouse->onMouseMove = (isset($htmlDocument->onPlatformMouseMoveEvent) ? $htmlDocument->onPlatformMouseMoveEvent: array($htmlDocument, "onPlatformMouseMoveEvent"));
		$this->platform->mouse->onMouseWheel = (isset($htmlDocument->onPlatformMouseWheelEvent) ? $htmlDocument->onPlatformMouseWheelEvent: array($htmlDocument, "onPlatformMouseWheelEvent"));
		$this->platform->keyboard->onKeyDown = (isset($htmlDocument->onPlatformKeyDownEvent) ? $htmlDocument->onPlatformKeyDownEvent: array($htmlDocument, "onPlatformKeyDownEvent"));
		$this->platform->keyboard->onKeyUp = (isset($htmlDocument->onPlatformKeyUpEvent) ? $htmlDocument->onPlatformKeyUpEvent: array($htmlDocument, "onPlatformKeyUpEvent"));
		$this->platform->nativeWindow->onResize = (isset($htmlDocument->onPlatformResizeEvent) ? $htmlDocument->onPlatformResizeEvent: array($htmlDocument, "onPlatformResizeEvent"));
		$this->platform->touchListener->onTouchStart = (isset($htmlDocument->onPlatformTouchEvent) ? $htmlDocument->onPlatformTouchEvent: array($htmlDocument, "onPlatformTouchEvent"));
		$this->platform->touchListener->onTouchMove = (isset($htmlDocument->onPlatformTouchEvent) ? $htmlDocument->onPlatformTouchEvent: array($htmlDocument, "onPlatformTouchEvent"));
		$this->platform->touchListener->onTouchEnd = (isset($htmlDocument->onPlatformTouchEvent) ? $htmlDocument->onPlatformTouchEvent: array($htmlDocument, "onPlatformTouchEvent"));
		$htmlDocument->onEnterFullscreen = (isset($this->onDocumentEnterFullscreen) ? $this->onDocumentEnterFullscreen: array($this, "onDocumentEnterFullscreen"));
		$htmlDocument->onExitFullscreen = (isset($this->onDocumentExitFullscreen) ? $this->onDocumentExitFullscreen: array($this, "onDocumentExitFullscreen"));
		$this->platform->nativeWindow->onFullScreenChange = (isset($this->onPlatformFullScreenChange) ? $this->onPlatformFullScreenChange: array($this, "onPlatformFullScreenChange"));
		$htmlDocument->onSetMouseCursor = (isset($this->onDocumentSetMouseCursor) ? $this->onDocumentSetMouseCursor: array($this, "onDocumentSetMouseCursor"));
		$this->document = $htmlDocument;
	}
	public $platform;
	public $innerWidth;
	public $innerHeight;
	public $document;
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
	static $__properties__ = array("get_innerHeight" => "get_innerHeight","get_innerWidth" => "get_innerWidth","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.window.Window'; }
}
