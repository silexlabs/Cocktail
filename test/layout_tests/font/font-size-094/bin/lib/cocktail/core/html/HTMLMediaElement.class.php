<?php

class cocktail_core_html_HTMLMediaElement extends cocktail_core_html_EmbeddedElement {
	public function __construct($tagName) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct($tagName);
		$this->networkState = 0;
		$this->ended = false;
		$this->duration = 0;
		$this->paused = true;
		$this->seeking = false;
		$this->readyState = 0;
		$this->_autoplaying = true;
		$this->set_muted(false);
		$this->set_volume(1.0);
		$this->_loadedDataWasDispatched = false;
		$this->_defaultPlaybackStartPosition = 0;
		$this->_officialPlaybackPosition = 0;
		$this->_currentPlaybackPosition = 0;
		$this->_initialPlaybackPosition = 0;
		$this->_earliestPossiblePosition = 0;
	}}
	public function set_currentTime($value) {
		switch($this->readyState) {
		case 0:{
			$this->_defaultPlaybackStartPosition = $value;
		}break;
		default:{
			$this->_officialPlaybackPosition = $value;
			$this->seek($value);
		}break;
		}
		return $value;
	}
	public function get_currentTime() {
		if(!_hx_equal($this->_defaultPlaybackStartPosition, 0)) {
			return $this->_defaultPlaybackStartPosition;
		}
		return $this->_officialPlaybackPosition;
	}
	public function get_buffered() {
		$ranges = new _hx_array(array());
		$ranges->push(_hx_anonymous(array("start" => 0.0, "end" => $this->duration * ($this->nativeMedia->get_bytesLoaded() / $this->nativeMedia->get_bytesTotal()))));
		$timeRanges = new cocktail_core_html_TimeRanges($ranges);
		return $timeRanges;
	}
	public function set_volume($value) {
		if($this->muted === false) {
			$this->nativeMedia->set_volume($value);
		}
		$this->volume = $value;
		$this->fireEvent("volumechange", false, false);
		return $value;
	}
	public function set_muted($value) {
		if($value === false) {
			$this->nativeMedia->set_volume($this->volume);
		} else {
			$this->nativeMedia->set_volume(0);
		}
		$this->muted = $value;
		$this->fireEvent("volumechange", false, false);
		return $value;
	}
	public function set_loop($value) {
		parent::setAttribute("loop",Std::string($value));
		return $value;
	}
	public function get_loop() {
		if($this->getAttribute("loop") !== null) {
			return true;
		} else {
			return false;
		}
	}
	public function set_autoplay($value) {
		parent::setAttribute("autoplay",Std::string($value));
		return $value;
	}
	public function get_autoplay() {
		if($this->getAttribute("autoplay") !== null) {
			return true;
		} else {
			return false;
		}
	}
	public function set_src($value) {
		parent::setAttribute("src",$value);
		$this->loadResource();
		return $value;
	}
	public function get_src() {
		return $this->getAttribute("src");
	}
	public function onProgressTick() {
		$this->fireEvent("progress", false, false);
		if($this->nativeMedia->get_bytesLoaded() >= $this->nativeMedia->get_bytesTotal()) {
			$this->setReadyState(4);
			$this->networkState = 1;
			$this->fireEvent("suspend", false, false);
			return;
		}
		if($this->readyState === 1) {
			$this->setReadyState(3);
		}
	}
	public function onTimeUpdateTick() {
		if($this->paused === true) {
			return;
		}
		$this->_currentPlaybackPosition = $this->nativeMedia->get_currentTime();
		$this->_officialPlaybackPosition = $this->_currentPlaybackPosition;
		if($this->duration - $this->_currentPlaybackPosition < 0.2) {
			if($this->get_loop() === true) {
				$this->seek(0);
				return;
			}
			$this->ended = true;
			$this->_currentPlaybackPosition = $this->duration;
			$this->_officialPlaybackPosition = $this->_currentPlaybackPosition;
			$this->fireEvent("timeupdate", false, false);
			if($this->paused === false) {
				$this->paused = true;
				$this->fireEvent("pause", false, false);
			}
			$this->fireEvent("ended", false, false);
			return;
		}
		$this->fireEvent("timeupdate", false, false);
	}
	public function onLoadedMetaData($e) {
		$this->intrinsicHeight = $this->nativeMedia->get_height();
		$this->intrinsicWidth = $this->nativeMedia->get_width();
		$this->intrinsicRatio = $this->get_intrinsicHeight() / $this->get_intrinsicWidth();
		$this->establishMediaTimeline();
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$other);
		$this->onProgressTick();
	}
	public function onLoadingError($error) {
		$this->selectResource();
	}
	public function hasChildSourceElement() {
		{
			$_g1 = 0; $_g = $this->childNodes->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				if(_hx_array_get($this->childNodes, $i)->get_nodeName() === "SOURCE") {
					return true;
				}
				unset($i);
			}
		}
		return false;
	}
	public function establishMediaTimeline() {
		$this->_currentPlaybackPosition = 0;
		$this->_initialPlaybackPosition = 0;
		$this->_officialPlaybackPosition = 0;
		$this->duration = $this->nativeMedia->get_duration();
		$this->fireEvent("durationchange", false, false);
		$this->setReadyState(1);
		$jumped = false;
		if($this->_defaultPlaybackStartPosition > 0) {
			$this->seek($this->_defaultPlaybackStartPosition);
			$jumped = true;
		}
		$this->_defaultPlaybackStartPosition = 0;
	}
	public function isPotentiallyPlaying() {
		if($this->paused === true) {
			return false;
		}
		if($this->ended === true) {
			return false;
		}
		return true;
	}
	public function setReadyState($newReadyState) {
		if($this->readyState === 0 && $newReadyState === 1) {
			$this->fireEvent("loadedmetadata", false, false);
		}
		if($this->readyState === 1 && ($newReadyState === 2 || $newReadyState === 4 || $newReadyState === 3)) {
			if($this->_loadedDataWasDispatched === false) {
				$this->fireEvent("loadeddata", false, false);
				$this->_loadedDataWasDispatched = true;
			}
			if($newReadyState === 4 || $newReadyState === 3) {
				if($this->readyState >= 3 && $newReadyState <= 2) {
					if($this->isPotentiallyPlaying() === true) {
						$this->fireEvent("timeupdate", false, false);
						$this->fireEvent("waiting", false, false);
					}
				}
				if($this->readyState <= 2 && $newReadyState === 3) {
					$this->fireEvent("canplay", false, false);
					if($this->paused === false) {
						$this->fireEvent("playing", false, false);
					}
				}
				if($newReadyState === 4) {
					if($this->readyState === 2) {
						$this->fireEvent("canplay", false, false);
						if($this->paused === false) {
							$this->fireEvent("playing", false, false);
						}
					}
					if($this->_autoplaying === true) {
						if($this->paused === true) {
							if($this->get_autoplay() === true) {
								$this->paused = false;
								$this->fireEvent("play", false, false);
								$this->play();
								$this->fireEvent("playing", false, false);
							}
						}
					}
					$this->fireEvent("canplaythrough", false, false);
				}
			}
		}
		$this->readyState = $newReadyState;
	}
	public function seek($newPlaybackPosition) {
		if($this->readyState === 0) {
			return;
		}
		if($this->seeking === true) {
		}
		$this->seeking = true;
		if($newPlaybackPosition > $this->duration) {
			$newPlaybackPosition = $this->duration;
		}
		if($newPlaybackPosition < $this->_earliestPossiblePosition) {
			$newPlaybackPosition = 0;
		}
		$this->fireEvent("seeking", false, false);
		$this->_currentPlaybackPosition = $newPlaybackPosition;
		$this->nativeMedia->seek($newPlaybackPosition);
		$this->fireEvent("timeupdate", false, false);
		$this->fireEvent("seeked", false, false);
	}
	public function fetchResource($url) {
		$this->nativeMedia->onLoadedMetaData = (isset($this->onLoadedMetaData) ? $this->onLoadedMetaData: array($this, "onLoadedMetaData"));
		$this->nativeMedia->set_src($url);
	}
	public function selectResource() {
		$this->networkState = 3;
		$mode = null;
		$candidate = null;
		if($this->get_src() !== null) {
			$mode = 0;
		} else {
			if($this->hasChildSourceElement() === true) {
				$mode = 1;
				{
					$_g1 = 0; $_g = $this->childNodes->length;
					while($_g1 < $_g) {
						$i = $_g1++;
						if(_hx_array_get($this->childNodes, $i)->get_nodeName() === "SOURCE") {
							$candidate = $this->childNodes[$i];
							break;
						}
						unset($i);
					}
				}
			} else {
				$this->networkState = 0;
				return;
			}
		}
		$this->networkState = 2;
		$this->fireEvent("loadstart", false, false);
		if($mode === 0) {
			if($this->get_src() === "") {
				$this->networkState = 3;
				$this->fireEvent("error", false, false);
				return;
			}
			$this->currentSrc = $this->get_src();
			$this->fetchResource($this->currentSrc);
		} else {
			if($mode === 1) {
				{
					$_g1 = 0; $_g = $this->childNodes->length;
					while($_g1 < $_g) {
						$i = $_g1++;
						if(_hx_array_get($this->childNodes, $i)->get_nodeName() === "SOURCE") {
							$sourceChild = $this->childNodes[$i];
							if($sourceChild->get_type() !== null) {
								if($this->canPlayType($sourceChild->get_type()) === "probably") {
									$this->currentSrc = $sourceChild->get_src();
									$this->fetchResource($this->currentSrc);
									return;
								}
							} else {
								if($sourceChild->get_src() !== null) {
									if($this->canPlayType($sourceChild->get_src()) === "probably") {
										$this->currentSrc = $sourceChild->get_src();
										$this->fetchResource($this->currentSrc);
										return;
									}
								}
							}
							unset($sourceChild);
						}
						unset($i);
					}
				}
				$this->networkState = 0;
			}
		}
	}
	public function loadResource() {
		switch($this->networkState) {
		case 2:case 1:{
			$this->fireEvent("abort", false, false);
		}break;
		}
		if($this->networkState !== 0) {
			$this->fireEvent("emptied", false, false);
			$this->nativeMedia->set_src(null);
			$this->networkState = 0;
			$this->readyState = 0;
			$this->paused = true;
			$this->seeking = false;
			$this->_currentPlaybackPosition = 0;
			if($this->_officialPlaybackPosition > 0) {
				$this->_officialPlaybackPosition = 0;
				$this->fireEvent("timeupdate", false, false);
			} else {
				$this->_officialPlaybackPosition = 0;
			}
			$this->_initialPlaybackPosition = 0;
			$this->duration = Math::$NaN;
		}
		$this->_loadedDataWasDispatched = false;
		$this->selectResource();
	}
	public function canPlayType($type) {
		return $this->nativeMedia->canPlayType($type);
	}
	public function pause() {
		if($this->networkState === 0) {
			$this->selectResource();
		}
		$this->_autoplaying = false;
		if($this->paused === false) {
			$this->paused = true;
			$this->fireEvent("timeupdate", false, false);
			$this->fireEvent("pause", false, false);
			$this->_officialPlaybackPosition = $this->_currentPlaybackPosition;
		}
		$this->nativeMedia->pause();
	}
	public function play() {
		if($this->networkState === 0) {
			$this->selectResource();
		}
		if($this->ended === true) {
			$this->ended = false;
			$this->seek(0);
		}
		if($this->paused === true) {
			$this->paused = false;
			$this->fireEvent("play", false, false);
			switch($this->readyState) {
			case 0:case 1:case 2:{
				$this->fireEvent("waiting", false, false);
			}break;
			case 3:case 4:{
				$this->fireEvent("playing", false, false);
			}break;
			}
		}
		$this->_autoplaying = false;
		$this->nativeMedia->play();
		$this->onTimeUpdateTick();
	}
	public function setAttribute($name, $value) {
		if($name === "src") {
			$this->set_src($value);
		} else {
			parent::setAttribute($name,$value);
		}
	}
	public function appendChild($newChild) {
		parent::appendChild($newChild);
		if($this->get_src() === null && $this->networkState === 0) {
			if($newChild->get_nodeName() === "SOURCE") {
				$this->selectResource();
			}
		}
		return $newChild;
	}
	public function initNativeMedia() {
	}
	public function init() {
		$this->initNativeMedia();
		parent::init();
	}
	public $_autoplaying;
	public $_loadedDataWasDispatched;
	public $_earliestPossiblePosition;
	public $_defaultPlaybackStartPosition;
	public $_currentPlaybackPosition;
	public $_officialPlaybackPosition;
	public $_initialPlaybackPosition;
	public $nativeMedia;
	public $volume;
	public $muted;
	public $ended;
	public $paused;
	public $buffered;
	public $duration;
	public $currentSrc;
	public $currentTime;
	public $seeking;
	public $readyState;
	public $networkState;
	public $loop;
	public $autoplay;
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
	static $RESOURCE_SELECTION_ATTRIBUTE_MODE = 0;
	static $RESOURCE_SELECTION_CHILDREN_MODE = 1;
	static $TIME_UPDATE_FREQUENCY = 15;
	static $PROGRESS_FREQUENCY = 350;
	static $PLAYBACK_END_DELTA = 0.2;
	static $NETWORK_EMPTY = 0;
	static $NETWORK_IDLE = 1;
	static $NETWORK_LOADING = 2;
	static $NETWORK_NO_SOURCE = 3;
	static $CAN_PLAY_TYPE_MAYBE = "maybe";
	static $CAN_PLAY_TYPE_PROBABLY = "probably";
	static $HAVE_NOTHING = 0;
	static $HAVE_METADATA = 1;
	static $HAVE_CURRENT_DATA = 2;
	static $HAVE_FUTURE_DATA = 3;
	static $HAVE_ENOUGH_DATA = 4;
	static $__properties__ = array("set_src" => "set_src","get_src" => "get_src","set_autoplay" => "set_autoplay","get_autoplay" => "get_autoplay","set_loop" => "set_loop","get_loop" => "get_loop","set_currentTime" => "set_currentTime","get_currentTime" => "get_currentTime","get_buffered" => "get_buffered","set_muted" => "set_muted","set_volume" => "set_volume","set_height" => "set_height","get_height" => "get_height","set_width" => "set_width","get_width" => "get_width","get_intrinsicHeight" => "get_intrinsicHeight","get_intrinsicWidth" => "get_intrinsicWidth","get_intrinsicRatio" => "get_intrinsicRatio","set_tabIndex" => "set_tabIndex","get_tabIndex" => "get_tabIndex","set_id" => "set_id","get_id" => "get_id","set_className" => "set_className","get_className" => "get_className","set_hidden" => "set_hidden","get_hidden" => "get_hidden","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","get_scrollHeight" => "get_scrollHeight","get_scrollWidth" => "get_scrollWidth","set_innerHTML" => "set_innerHTML","get_innerHTML" => "get_innerHTML","get_offsetParent" => "get_offsetParent","get_offsetWidth" => "get_offsetWidth","get_offsetHeight" => "get_offsetHeight","get_offsetLeft" => "get_offsetLeft","get_offsetTop" => "get_offsetTop","get_clientWidth" => "get_clientWidth","get_clientHeight" => "get_clientHeight","get_clientLeft" => "get_clientLeft","get_clientTop" => "get_clientTop","get_firstElementChild" => "get_firstElementChild","get_lastElementChild" => "get_lastElementChild","get_previousElementSibling" => "get_previousElementSibling","get_nextElementSibling" => "get_nextElementSibling","get_childElementCount" => "get_childElementCount","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.html.HTMLMediaElement'; }
}
