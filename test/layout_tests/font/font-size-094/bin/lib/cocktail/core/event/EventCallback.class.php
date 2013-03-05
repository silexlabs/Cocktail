<?php

class cocktail_core_event_EventCallback extends cocktail_core_event_EventTarget {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function set_onTransitionEnd($value) {
		$this->updateCallbackListener("transitionend", $value, (isset($this->ontransitionend) ? $this->ontransitionend: array($this, "ontransitionend")));
		return $this->ontransitionend = $value;
	}
	public function set_onVolumeChange($value) {
		$this->updateCallbackListener("volumechange", $value, (isset($this->onvolumechange) ? $this->onvolumechange: array($this, "onvolumechange")));
		return $this->onvolumechange = $value;
	}
	public function set_onPause($value) {
		$this->updateCallbackListener("pause", $value, (isset($this->onpause) ? $this->onpause: array($this, "onpause")));
		return $this->onpause = $value;
	}
	public function set_onPlay($value) {
		$this->updateCallbackListener("play", $value, (isset($this->onplay) ? $this->onplay: array($this, "onplay")));
		return $this->onplay = $value;
	}
	public function set_onTimeUpdate($value) {
		$this->updateCallbackListener("timeupdate", $value, (isset($this->ontimeupdate) ? $this->ontimeupdate: array($this, "ontimeupdate")));
		return $this->ontimeupdate = $value;
	}
	public function set_onDurationChanged($value) {
		$this->updateCallbackListener("durationchange", $value, (isset($this->ondurationchange) ? $this->ondurationchange: array($this, "ondurationchange")));
		return $this->ondurationchange = $value;
	}
	public function set_onEnded($value) {
		$this->updateCallbackListener("ended", $value, (isset($this->onended) ? $this->onended: array($this, "onended")));
		return $this->onended = $value;
	}
	public function set_onSeeked($value) {
		$this->updateCallbackListener("seeked", $value, (isset($this->onseeked) ? $this->onseeked: array($this, "onseeked")));
		return $this->onseeked = $value;
	}
	public function set_onSeeking($value) {
		$this->updateCallbackListener("seeking", $value, (isset($this->onseeking) ? $this->onseeking: array($this, "onseeking")));
		return $this->set_onWaiting($value);
	}
	public function set_onWaiting($value) {
		$this->updateCallbackListener("waiting", $value, (isset($this->onwaiting) ? $this->onwaiting: array($this, "onwaiting")));
		return $this->onwaiting = $value;
	}
	public function set_onPlaying($value) {
		$this->updateCallbackListener("playing", $value, (isset($this->onplaying) ? $this->onplaying: array($this, "onplaying")));
		return $this->onplaying = $value;
	}
	public function set_onCanPlayThrough($value) {
		$this->updateCallbackListener("canplaythrough", $value, (isset($this->oncanplaythrough) ? $this->oncanplaythrough: array($this, "oncanplaythrough")));
		return $this->oncanplaythrough = $value;
	}
	public function set_onCanPlay($value) {
		$this->updateCallbackListener("canplay", $value, (isset($this->oncanplay) ? $this->oncanplay: array($this, "oncanplay")));
		return $this->oncanplay = $value;
	}
	public function set_onLoadedData($value) {
		$this->updateCallbackListener("loadeddata", $value, (isset($this->onloadeddata) ? $this->onloadeddata: array($this, "onloadeddata")));
		return $this->onloadeddata = $value;
	}
	public function set_onLoadedMetadata($value) {
		$this->updateCallbackListener("loadedmetadata", $value, (isset($this->onloadedmetadata) ? $this->onloadedmetadata: array($this, "onloadedmetadata")));
		return $this->onloadedmetadata = $value;
	}
	public function set_onStalled($value) {
		$this->updateCallbackListener("stalled", $value, (isset($this->onstalled) ? $this->onstalled: array($this, "onstalled")));
		return $this->onstalled = $value;
	}
	public function set_onEmptied($value) {
		$this->updateCallbackListener("emptied", $value, (isset($this->onemptied) ? $this->onemptied: array($this, "onemptied")));
		return $this->onemptied = $value;
	}
	public function set_onSuspend($value) {
		$this->updateCallbackListener("suspend", $value, (isset($this->onsuspend) ? $this->onsuspend: array($this, "onsuspend")));
		return $this->onsuspend = $value;
	}
	public function set_onProgress($value) {
		$this->updateCallbackListener("progress", $value, (isset($this->onprogress) ? $this->onprogress: array($this, "onprogress")));
		return $this->onprogress = $value;
	}
	public function set_onLoadStart($value) {
		$this->updateCallbackListener("loadstart", $value, (isset($this->onloadstart) ? $this->onloadstart: array($this, "onloadstart")));
		return $this->onloadstart = $value;
	}
	public function set_onError($value) {
		$this->updateCallbackListener("error", $value, (isset($this->onerror) ? $this->onerror: array($this, "onerror")));
		return $this->onerror = $value;
	}
	public function set_onLoad($value) {
		$this->updateCallbackListener("load", $value, (isset($this->onload) ? $this->onload: array($this, "onload")));
		return $this->onload = $value;
	}
	public function set_onScroll($value) {
		$this->updateCallbackListener("scroll", $value, (isset($this->onscroll) ? $this->onscroll: array($this, "onscroll")));
		return $this->onscroll = $value;
	}
	public function set_onFullScreenChange($value) {
		$this->updateCallbackListener("fullscreenchange", $value, (isset($this->onfullscreenchange) ? $this->onfullscreenchange: array($this, "onfullscreenchange")));
		return $this->onfullscreenchange = $value;
	}
	public function set_onResize($value) {
		$this->updateCallbackListener("resize", $value, (isset($this->onresize) ? $this->onresize: array($this, "onresize")));
		return $this->onresize = $value;
	}
	public function set_onBlur($value) {
		$this->updateCallbackListener("blur", $value, (isset($this->onblur) ? $this->onblur: array($this, "onblur")));
		return $this->onblur = $value;
	}
	public function set_onFocus($value) {
		$this->updateCallbackListener("focus", $value, (isset($this->onfocus) ? $this->onfocus: array($this, "onfocus")));
		return $this->onfocus = $value;
	}
	public function set_onKeyUp($value) {
		$this->updateCallbackListener("keyup", $value, (isset($this->onkeyup) ? $this->onkeyup: array($this, "onkeyup")));
		return $this->onkeyup = $value;
	}
	public function set_onKeyDown($value) {
		$this->updateCallbackListener("keydown", $value, (isset($this->onkeydown) ? $this->onkeydown: array($this, "onkeydown")));
		return $this->onkeydown = $value;
	}
	public function set_onMouseWheel($value) {
		$this->updateCallbackListener("wheel", $value, (isset($this->onmousewheel) ? $this->onmousewheel: array($this, "onmousewheel")));
		return $this->onmousewheel = $value;
	}
	public function set_onMouseMove($value) {
		$this->updateCallbackListener("mousemove", $value, (isset($this->onmousemove) ? $this->onmousemove: array($this, "onmousemove")));
		return $this->onmousemove = $value;
	}
	public function set_onMouseOut($value) {
		$this->updateCallbackListener("mouseout", $value, (isset($this->onmouseout) ? $this->onmouseout: array($this, "onmouseout")));
		return $this->onmouseout = $value;
	}
	public function set_onMouseOver($value) {
		$this->updateCallbackListener("mouseover", $value, (isset($this->onmouseover) ? $this->onmouseover: array($this, "onmouseover")));
		return $this->onmouseover = $value;
	}
	public function set_onMouseUp($value) {
		$this->updateCallbackListener("mouseup", $value, (isset($this->onmouseup) ? $this->onmouseup: array($this, "onmouseup")));
		return $this->onmouseup = $value;
	}
	public function set_onMouseDown($value) {
		$this->updateCallbackListener("mousedown", $value, (isset($this->onmousedown) ? $this->onmousedown: array($this, "onmousedown")));
		return $this->onmousedown = $value;
	}
	public function set_onDblClick($value) {
		$this->updateCallbackListener("dblclick", $value, (isset($this->ondblclick) ? $this->ondblclick: array($this, "ondblclick")));
		return $this->ondblclick = $value;
	}
	public function set_onClick($value) {
		$this->updateCallbackListener("click", $value, (isset($this->onclick) ? $this->onclick: array($this, "onclick")));
		return $this->onclick = $value;
	}
	public function updateCallbackListener($eventType, $newListener, $oldListener) {
		if($oldListener !== null) {
			$this->removeEventListener($eventType, $oldListener, null);
		}
		if($newListener !== null) {
			$this->addEventListener($eventType, $newListener, null);
		}
	}
	public $ontransitionend;
	public $onvolumechange;
	public $onpause;
	public $onplay;
	public $ontimeupdate;
	public $ondurationchange;
	public $onended;
	public $onseeked;
	public $onseeking;
	public $onwaiting;
	public $onplaying;
	public $oncanplaythrough;
	public $oncanplay;
	public $onloadeddata;
	public $onloadedmetadata;
	public $onstalled;
	public $onemptied;
	public $onsuspend;
	public $onprogress;
	public $onloadstart;
	public $onerror;
	public $onload;
	public $onscroll;
	public $onfullscreenchange;
	public $onresize;
	public $onblur;
	public $onfocus;
	public $onkeyup;
	public $onkeydown;
	public $onmousewheel;
	public $onmousemove;
	public $onmouseout;
	public $onmouseover;
	public $onmouseup;
	public $onmousedown;
	public $ondblclick;
	public $onclick;
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
	static $__properties__ = array("set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.event.EventCallback'; }
}
