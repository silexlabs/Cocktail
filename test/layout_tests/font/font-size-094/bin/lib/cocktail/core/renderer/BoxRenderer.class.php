<?php

class cocktail_core_renderer_BoxRenderer extends cocktail_core_renderer_InvalidatingElementRenderer {
	public function __construct($domNode) { if(!php_Boot::$skip_constructor) {
		parent::__construct($domNode);
	}}
	public function getWindowData() {
		$window = cocktail_Lib::get_window();
		$width = $window->get_innerWidth();
		$height = $window->get_innerHeight();
		$windowData = _hx_anonymous(array("isHeightAuto" => false, "isWidthAuto" => false, "width" => $width, "height" => $height));
		return $windowData;
	}
	public function getContainerBlockData() {
		return _hx_anonymous(array("width" => $this->coreStyle->computedStyle->getWidth(), "isWidthAuto" => $this->coreStyle->width == cocktail_core_style_Dimension::$cssAuto, "height" => $this->coreStyle->computedStyle->getHeight(), "isHeightAuto" => $this->coreStyle->height == cocktail_core_style_Dimension::$cssAuto));
	}
	public function getBackgroundBounds() {
		$globalBounds = $this->get_globalBounds();
		$globalBounds->x -= $this->scrollOffset->x;
		$globalBounds->y -= $this->scrollOffset->y;
		return $globalBounds;
	}
	public function isClear() {
		return $this->coreStyle->computedStyle->clear != cocktail_core_style_Clear::$none;
	}
	public function isTransparent() {
		if($this->coreStyle->opacity !== 1.0) {
			return true;
		}
		return false;
	}
	public function isTransformed() {
		if($this->coreStyle->transform != cocktail_core_style_Transform::$none) {
			return true;
		}
		return false;
	}
	public function establishesNewStackingContext() {
		if($this->isTransformed() === true) {
			return true;
		} else {
			if($this->isPositioned() === true) {
				return true;
			} else {
				if($this->isTransparent() === true) {
					return true;
				}
			}
		}
		return false;
	}
	public function isInlineLevel() {
		$ret = false;
		$»t = ($this->coreStyle->computedStyle->display);
		switch($»t->index) {
		case 2:
		case 1:
		{
			$ret = true;
		}break;
		default:{
			$ret = false;
		}break;
		}
		return $ret;
	}
	public function isRelativePositioned() {
		return $this->coreStyle->computedStyle->position == cocktail_core_style_Position::$relative;
	}
	public function isPositioned() {
		return $this->coreStyle->computedStyle->position != cocktail_core_style_Position::$cssStatic;
	}
	public function isFloat() {
		return $this->coreStyle->computedStyle->cssFloat != cocktail_core_style_CSSFloat::$none;
	}
	public function getBoxStylesComputer() {
		return null;
	}
	public function computeBoxModelStyles($containingBlockDimensions) {
		$boxComputer = $this->getBoxStylesComputer();
		$boxComputer->measure($this->coreStyle, $containingBlockDimensions);
	}
	public function layoutSelf() {
		$containingBlockData = $this->_containingBlock->getContainerBlockData();
		$containingBlockFontMetricsData = $this->_containingBlock->coreStyle->get_fontMetricsData();
		cocktail_core_style_computer_FontAndTextStylesComputer::compute($this->coreStyle, $containingBlockData, $containingBlockFontMetricsData);
		$this->computeBoxModelStyles($containingBlockData);
	}
	public function layout($forceLayout) {
		$this->coreStyle->computedStyle->set_opacity($this->coreStyle->opacity);
		cocktail_core_style_computer_TransitionStylesComputer::compute($this->coreStyle);
		if($this->_needsLayout === true || $forceLayout === true) {
			$this->layoutSelf();
			$this->_needsLayout = false;
		}
	}
	public function renderChildren($graphicContext) {
	}
	public function renderBackground($graphicContext) {
		cocktail_core_style_computer_BackgroundStylesComputer::compute($this->coreStyle);
		$backgroundBounds = $this->getBackgroundBounds();
		cocktail_core_background_BackgroundManager::render($graphicContext, $backgroundBounds, $this->coreStyle, $this);
	}
	public function renderSelf($graphicContext) {
		$this->renderBackground($graphicContext);
	}
	public function render($parentGraphicContext) {
		$this->renderSelf($parentGraphicContext);
		$this->renderChildren($parentGraphicContext);
	}
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.BoxRenderer'; }
}
