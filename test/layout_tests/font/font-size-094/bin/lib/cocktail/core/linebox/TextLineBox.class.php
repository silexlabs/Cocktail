<?php

class cocktail_core_linebox_TextLineBox extends cocktail_core_linebox_LineBox {
	public function __construct($elementRenderer, $text, $fontMetrics, $fontManager) {
		if(!php_Boot::$skip_constructor) {
		$this->_fontMetrics = $fontMetrics;
		parent::__construct($elementRenderer);
		$this->initNativeTextElement($text, $fontManager, $elementRenderer->coreStyle->computedStyle);
		$this->get_bounds()->width = $this->getTextWidth();
		$this->get_bounds()->height = $this->getTextHeight();
		$this->initTextBitmap();
	}}
	public function getTextHeight() {
		return $this->leadedAscent + $this->leadedDescent;
	}
	public function getTextWidth() {
		return $this->_nativeText->get_width();
	}
	public function getLeadedDescent() {
		$ascent = $this->_fontMetrics->ascent;
		$descent = $this->_fontMetrics->descent;
		$leading = $this->elementRenderer->coreStyle->computedStyle->getLineHeight() - ($ascent + $descent);
		$leadedAscent = $ascent + $leading / 2;
		$leadedDescent = $descent + $leading / 2;
		return $leadedDescent;
	}
	public function getLeadedAscent() {
		$ascent = $this->_fontMetrics->ascent;
		$descent = $this->_fontMetrics->descent;
		$leading = $this->elementRenderer->coreStyle->computedStyle->getLineHeight() - ($ascent + $descent);
		$leadedAscent = $ascent + $leading / 2;
		$leadedDescent = $descent + $leading / 2;
		return $leadedAscent;
	}
	public function isText() {
		return true;
	}
	public function getBaselineOffset($parentBaselineOffset, $parentXHeight) {
		return $parentBaselineOffset;
	}
	public function render($graphicContext) {
		$rect = _hx_anonymous(array("x" => 0.0, "y" => 0.0, "width" => $this->get_bounds()->width, "height" => $this->get_bounds()->height));
		$destPoint = _hx_anonymous(array("x" => $this->get_bounds()->x + $this->elementRenderer->globalContainingBlockOrigin->x - $this->elementRenderer->scrollOffset->x, "y" => $this->get_bounds()->y + $this->elementRenderer->globalContainingBlockOrigin->y - $this->elementRenderer->scrollOffset->y));
		$graphicContext->copyPixels($this->_nativeTextBitmap, $rect, $destPoint);
	}
	public function initTextBitmap() {
		$bitmapBounds = _hx_anonymous(array("x" => 0.0, "y" => $this->leadedAscent, "height" => $this->get_bounds()->height, "width" => $this->get_bounds()->width));
		$this->_nativeTextBitmap = $this->_nativeText->getBitmap($bitmapBounds);
	}
	public function initNativeTextElement($text, $fontManager, $computedStyle) {
		$nativeElement = $fontManager->createNativeTextElement($text, $computedStyle);
		$this->_nativeText = new cocktail_port_platform_nativeText_AbstractNativeText($nativeElement);
	}
	public $_nativeTextBitmap;
	public $_nativeText;
	public $_fontMetrics;
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
	static $__properties__ = array("get_bounds" => "get_bounds","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.linebox.TextLineBox'; }
}
