<?php

class cocktail_core_renderer_InitialBlockRenderer extends cocktail_core_renderer_BlockBoxRenderer {
	public function __construct($node) { if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
		$this->attach();
	}}
	public function get_globalBounds() {
		return $this->get_bounds();
	}
	public function get_bounds() {
		$containerBlockData = $this->getContainerBlockData();
		$width = $containerBlockData->width;
		$height = $containerBlockData->height;
		return _hx_anonymous(array("x" => 0.0, "y" => 0.0, "width" => $width, "height" => $height));
	}
	public function getContainingBlock() {
		return $this;
	}
	public function getContainerBlockData() {
		return $this->getWindowData();
	}
	public function getWindowData() {
		$width = cocktail_Lib::get_window()->get_innerWidth();
		$height = cocktail_Lib::get_window()->get_innerHeight();
		$windowData = _hx_anonymous(array("isHeightAuto" => false, "isWidthAuto" => false, "width" => $width, "height" => $height));
		if($this->_verticalScrollBar !== null) {
			$windowData->width -= $this->_verticalScrollBar->coreStyle->computedStyle->getWidth();
		}
		if($this->_horizontalScrollBar !== null) {
			$windowData->height -= $this->_horizontalScrollBar->coreStyle->computedStyle->getHeight();
		}
		return $windowData;
	}
	public function treatVisibleOverflowAsAuto() {
		return true;
	}
	public function mustBubbleScrollEvent() {
		return true;
	}
	public function getScrollbarContainerBlock() {
		$width = cocktail_Lib::get_window()->get_innerWidth();
		$height = cocktail_Lib::get_window()->get_innerHeight();
		$windowData = _hx_anonymous(array("isHeightAuto" => false, "isWidthAuto" => false, "width" => $width, "height" => $height));
		return $windowData;
	}
	public function establishesNewStackingContext() {
		return true;
	}
	public function establishesNewFormattingContext() {
		return true;
	}
	public function isPositioned() {
		return true;
	}
	public function invalidateContainingBlock($invalidationReason) {
		$this->invalidateDocumentLayoutAndRendering();
	}
	public function unregisterWithContainingBlock() {
	}
	public function registerWithContaininingBlock() {
	}
	public function detachLayer() {
		$this->layerRenderer = null;
	}
	public function attachLayer() {
		$this->layerRenderer = new cocktail_core_layer_InitialLayerRenderer($this);
	}
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.InitialBlockRenderer'; }
}
