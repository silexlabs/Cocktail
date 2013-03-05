<?php

class cocktail_core_renderer_TextInputRenderer extends cocktail_core_renderer_EmbeddedBoxRenderer {
	public function __construct($node) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
		$this->_nativeTextInput = new cocktail_port_platform_input_AbstractNativeTextInput();
		$node->addEventListener("focus", (isset($this->onTextInputFocus) ? $this->onTextInputFocus: array($this, "onTextInputFocus")), null);
	}}
	public function set_value($value) {
		return $this->_nativeTextInput->set_value($value);
	}
	public function get_value() {
		return $this->_nativeTextInput->get_value();
	}
	public function updateNativeTextInput() {
		$globalBounds = $this->get_globalBounds();
		$this->_nativeTextInput->set_viewport(_hx_anonymous(array("x" => $globalBounds->x - $this->scrollOffset->x, "y" => $globalBounds->y + $globalBounds->height / 2 - $this->coreStyle->computedStyle->getFontSize() + $this->coreStyle->get_fontMetricsData()->ascent / 2 - $this->scrollOffset->y, "width" => $globalBounds->width, "height" => $globalBounds->height)));
		$this->_nativeTextInput->set_fontFamily($this->coreStyle->computedStyle->fontFamily[0]);
		$this->_nativeTextInput->set_letterSpacing($this->coreStyle->computedStyle->getLetterSpacing());
		$this->_nativeTextInput->set_fontSize($this->coreStyle->computedStyle->getFontSize());
		$bold = null;
		$»t = ($this->coreStyle->computedStyle->fontWeight);
		switch($»t->index) {
		case 3:
		case 0:
		case 4:
		case 5:
		case 6:
		case 7:
		{
			$bold = false;
		}break;
		case 1:
		case 2:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		{
			$bold = true;
		}break;
		}
		$this->_nativeTextInput->set_italic($bold);
		$this->_nativeTextInput->set_italic($this->coreStyle->computedStyle->fontStyle == cocktail_core_style_FontStyle::$italic);
		$this->_nativeTextInput->set_letterSpacing($this->coreStyle->computedStyle->getLetterSpacing());
		$this->_nativeTextInput->set_color($this->coreStyle->computedStyle->color->color);
	}
	public function onTextInputFocus($e) {
		$this->_nativeTextInput->focus();
	}
	public function renderEmbeddedAsset($graphicContext) {
		$this->updateNativeTextInput();
		$this->_nativeTextInput->attach($graphicContext);
	}
	public $value;
	public $_nativeTextInput;
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
	static $__properties__ = array("set_value" => "set_value","get_value" => "get_value","set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.TextInputRenderer'; }
}
