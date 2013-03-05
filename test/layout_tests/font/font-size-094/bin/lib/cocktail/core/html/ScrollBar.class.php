<?php

class cocktail_core_html_ScrollBar extends cocktail_core_html_HTMLElement {
	public function __construct($isVertical) {
		if(!php_Boot::$skip_constructor) {
		$this->_isVertical = $isVertical;
		parent::__construct("DIV");
		$this->_scrollThumb = cocktail_Lib::get_document()->createElement("DIV");
		$this->_upArrow = cocktail_Lib::get_document()->createElement("DIV");
		$this->_downArrow = cocktail_Lib::get_document()->createElement("DIV");
		$this->set_scroll(0);
		$this->set_maxScroll(0);
		$this->_mouseMoveStart = 0;
		$this->initScrollBar();
		if($this->_isVertical) {
			$this->initVerticalScrollBar();
		} else {
			$this->initHorizontalScrollBar();
		}
		$this->appendChild($this->_scrollThumb);
		$this->appendChild($this->_upArrow);
		$this->appendChild($this->_downArrow);
		$this->addEventListener("mousedown", (isset($this->onTrackMouseDown) ? $this->onTrackMouseDown: array($this, "onTrackMouseDown")), null);
		$this->_scrollThumb->addEventListener("mousedown", (isset($this->onThumbMouseDown) ? $this->onThumbMouseDown: array($this, "onThumbMouseDown")), null);
		$this->_downArrow->addEventListener("mousedown", (isset($this->onDownArrowMouseDown) ? $this->onDownArrowMouseDown: array($this, "onDownArrowMouseDown")), null);
		$this->_upArrow->addEventListener("mousedown", (isset($this->onUpArrowMouseDown) ? $this->onUpArrowMouseDown: array($this, "onUpArrowMouseDown")), null);
	}}
	public function set_scroll($value) {
		$this->scroll = $value;
		$this->updateScroll();
		return $value;
	}
	public function set_maxScroll($value) {
		$scrollPercent = $this->scroll / $this->maxScroll;
		if(_hx_equal($this->maxScroll, 0)) {
			$scrollPercent = 0;
		}
		$this->maxScroll = $value;
		$this->set_scroll($this->maxScroll * $scrollPercent);
		$this->updateThumbSize();
		return $value;
	}
	public function dispatchScrollEvent() {
		$scrollEvent = new cocktail_core_event_UIEvent();
		$scrollEvent->initUIEvent("scroll", false, false, null, 0.0);
		$this->dispatchEvent($scrollEvent);
	}
	public function updateThumbSize() {
		if($this->_isVertical === true) {
			$thumbHeight = $this->coreStyle->computedStyle->getHeight() - $this->_downArrow->coreStyle->computedStyle->getHeight() - $this->_upArrow->coreStyle->computedStyle->getHeight() - $this->maxScroll;
			if($thumbHeight < 16) {
				$thumbHeight = 16;
			}
			if($thumbHeight !== $this->_scrollThumb->coreStyle->computedStyle->getHeight()) {
				$this->_scrollThumb->style->set_height(_hx_string_rec($thumbHeight, "") . "px");
			}
		} else {
			$thumbWidth = $this->coreStyle->computedStyle->getWidth() - $this->_downArrow->coreStyle->computedStyle->getWidth() - $this->_upArrow->coreStyle->computedStyle->getWidth() - $this->maxScroll;
			if($thumbWidth < 16) {
				$thumbWidth = 16;
			}
			if($thumbWidth !== $this->_scrollThumb->coreStyle->computedStyle->getWidth()) {
				$this->_scrollThumb->style->set_width(_hx_string_rec($thumbWidth, "") . "px");
			}
		}
	}
	public function updateScroll() {
		if($this->scroll > $this->maxScroll) {
			$this->set_scroll($this->maxScroll);
		} else {
			if($this->scroll < 0) {
				$this->set_scroll(0);
			}
		}
		$progress = $this->scroll / $this->maxScroll;
		if($this->_isVertical === true) {
			$thumbY = Math::round($progress * ($this->coreStyle->computedStyle->getHeight() - $this->_upArrow->coreStyle->computedStyle->getHeight() - $this->_downArrow->coreStyle->computedStyle->getHeight() - $this->_scrollThumb->coreStyle->computedStyle->getHeight()) + $this->_upArrow->coreStyle->computedStyle->getHeight());
			$this->_scrollThumb->style->set_top(_hx_string_rec($thumbY, "") . "px");
		} else {
			$thumbX = Math::round($progress * ($this->coreStyle->computedStyle->getWidth() - $this->_upArrow->coreStyle->computedStyle->getWidth() - $this->_downArrow->coreStyle->computedStyle->getWidth() - $this->_scrollThumb->coreStyle->computedStyle->getWidth()) + $this->_upArrow->coreStyle->computedStyle->getWidth());
			$this->_scrollThumb->style->set_left(_hx_string_rec($thumbX, "") . "px");
		}
		$this->dispatchScrollEvent();
	}
	public function onTrackMouseDown($event) {
		if($this->_isVertical === true) {
			if($event->screenY > $this->_scrollThumb->elementRenderer->get_globalBounds()->y) {
				$_g = $this;
				$_g->set_scroll($_g->scroll + 50);
			} else {
				$_g = $this;
				$_g->set_scroll($_g->scroll - 50);
			}
		} else {
			if($event->screenX > $this->_scrollThumb->elementRenderer->get_globalBounds()->x) {
				$_g = $this;
				$_g->set_scroll($_g->scroll + 50);
			} else {
				$_g = $this;
				$_g->set_scroll($_g->scroll - 50);
			}
		}
	}
	public function onThumbMove($event) {
		if($this->_isVertical === true) {
			$thumbDelta = $event->screenY - $this->_mouseMoveStart;
			{
				$_g = $this;
				$_g->set_scroll($_g->scroll + $thumbDelta);
			}
			$this->_mouseMoveStart = $event->screenY;
		} else {
			$thumbDelta = $event->screenX - $this->_mouseMoveStart;
			{
				$_g = $this;
				$_g->set_scroll($_g->scroll + $thumbDelta);
			}
			$this->_mouseMoveStart = $event->screenX;
		}
	}
	public function onThumbMouseUp($event) {
		cocktail_Lib::get_document()->removeEventListener("mousemove", (isset($this->_thumbMoveDelegate) ? $this->_thumbMoveDelegate: array($this, "_thumbMoveDelegate")), null);
		cocktail_Lib::get_document()->removeEventListener("mouseup", (isset($this->_thumbUpDelegate) ? $this->_thumbUpDelegate: array($this, "_thumbUpDelegate")), null);
	}
	public function onThumbMouseDown($event) {
		if($this->_isVertical === true) {
			$this->_mouseMoveStart = $event->screenY;
		} else {
			$this->_mouseMoveStart = $event->screenX;
		}
		$event->stopPropagation();
		$this->_thumbMoveDelegate = (isset($this->onThumbMove) ? $this->onThumbMove: array($this, "onThumbMove"));
		$this->_thumbUpDelegate = (isset($this->onThumbMouseUp) ? $this->onThumbMouseUp: array($this, "onThumbMouseUp"));
		cocktail_Lib::get_document()->addEventListener("mousemove", (isset($this->_thumbMoveDelegate) ? $this->_thumbMoveDelegate: array($this, "_thumbMoveDelegate")), null);
		cocktail_Lib::get_document()->addEventListener("mouseup", (isset($this->_thumbUpDelegate) ? $this->_thumbUpDelegate: array($this, "_thumbUpDelegate")), null);
	}
	public function onUpArrowMouseDown($event) {
		{
			$_g = $this;
			$_g->set_scroll($_g->scroll - 10);
		}
		$event->stopPropagation();
	}
	public function onDownArrowMouseDown($event) {
		{
			$_g = $this;
			$_g->set_scroll($_g->scroll + 10);
		}
		$event->stopPropagation();
	}
	public function executeDefaultActionIfNeeded($defaultPrevented, $event) {
	}
	public function detachFromParentElementRenderer() {
	}
	public function attachToParentElementRenderer() {
	}
	public function isParentRendered() {
		return true;
	}
	public function createElementRenderer() {
		$this->elementRenderer = new cocktail_core_renderer_ScrollBarRenderer($this);
	}
	public function initHorizontalScrollBar() {
		$this->style->set_width("100%");
		$this->style->set_height(_hx_string_rec(16, "") . "px");
		$this->style->set_bottom("0");
		$this->style->set_left("0");
		$this->_downArrow->style->set_right("0");
		$this->_scrollThumb->style->set_left(_hx_string_rec(16, "") . "px");
	}
	public function initVerticalScrollBar() {
		$this->style->set_height("100%");
		$this->style->set_width(_hx_string_rec(16, "") . "px");
		$this->style->set_right("0");
		$this->style->set_top("0");
		$this->_downArrow->style->set_bottom("0");
		$this->_scrollThumb->style->set_top(_hx_string_rec(16, "") . "px");
	}
	public function initScrollBar() {
		$this->style->set_backgroundColor("#DDDDDD");
		$this->style->set_display("block");
		$this->style->set_position("absolute");
		$this->_scrollThumb->style->set_backgroundColor("#AAAAAA");
		$this->_scrollThumb->style->set_position("absolute");
		$this->_scrollThumb->style->set_display("block");
		$this->_scrollThumb->style->set_width(_hx_string_rec(16, "") . "px");
		$this->_scrollThumb->style->set_height(_hx_string_rec(16, "") . "px");
		$this->_upArrow->style->set_backgroundColor("#CCCCCC");
		$this->_upArrow->style->set_position("absolute");
		$this->_upArrow->style->set_display("block");
		$this->_upArrow->style->set_width(_hx_string_rec(16, "") . "px");
		$this->_upArrow->style->set_height(_hx_string_rec(16, "") . "px");
		$this->_downArrow->style->set_backgroundColor("#CCCCCC");
		$this->_downArrow->style->set_position("absolute");
		$this->_downArrow->style->set_display("block");
		$this->_downArrow->style->set_width(_hx_string_rec(16, "") . "px");
		$this->_downArrow->style->set_height(_hx_string_rec(16, "") . "px");
	}
	public $_thumbUpDelegate;
	public $_thumbMoveDelegate;
	public $_mouseMoveStart;
	public $_downArrow;
	public $_upArrow;
	public $_scrollThumb;
	public $maxScroll;
	public $scroll;
	public $_isVertical;
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
	static $ARROW_SCROLL_OFFSET = 10;
	static $TRACK_SCROLL_OFFSET = 50;
	static $THUMB_DEFAULT_DIMENSION = 16;
	static $ARROW_DEFAULT_DIMENSION = 16;
	static $TRACK_DEFAULT_DIMENSION = 16;
	static $__properties__ = array("set_scroll" => "set_scroll","set_maxScroll" => "set_maxScroll","set_tabIndex" => "set_tabIndex","get_tabIndex" => "get_tabIndex","set_id" => "set_id","get_id" => "get_id","set_className" => "set_className","get_className" => "get_className","set_hidden" => "set_hidden","get_hidden" => "get_hidden","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","get_scrollHeight" => "get_scrollHeight","get_scrollWidth" => "get_scrollWidth","set_innerHTML" => "set_innerHTML","get_innerHTML" => "get_innerHTML","get_offsetParent" => "get_offsetParent","get_offsetWidth" => "get_offsetWidth","get_offsetHeight" => "get_offsetHeight","get_offsetLeft" => "get_offsetLeft","get_offsetTop" => "get_offsetTop","get_clientWidth" => "get_clientWidth","get_clientHeight" => "get_clientHeight","get_clientLeft" => "get_clientLeft","get_clientTop" => "get_clientTop","get_firstElementChild" => "get_firstElementChild","get_lastElementChild" => "get_lastElementChild","get_previousElementSibling" => "get_previousElementSibling","get_nextElementSibling" => "get_nextElementSibling","get_childElementCount" => "get_childElementCount","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.html.ScrollBar'; }
}
