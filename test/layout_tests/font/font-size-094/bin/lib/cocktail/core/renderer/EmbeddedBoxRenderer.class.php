<?php

class cocktail_core_renderer_EmbeddedBoxRenderer extends cocktail_core_renderer_BoxRenderer {
	public function __construct($node) { if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
	}}
	public function getAssetBounds($availableWidth, $availableHeight, $assetWidth, $assetHeight) {
		$width = null;
		$height = null;
		if($availableWidth > $availableHeight) {
			$ratio = $assetHeight / $availableHeight;
			if($assetWidth / $ratio < $availableWidth) {
				$width = $assetWidth / $ratio;
				$height = $availableHeight;
			} else {
				$ratio = $assetWidth / $availableWidth;
				$width = $availableWidth;
				$height = $assetHeight / $ratio;
			}
		} else {
			$ratio = $assetWidth / $availableWidth;
			if($assetHeight / $ratio < $availableHeight) {
				$height = $assetHeight / $ratio;
				$width = $availableWidth;
			} else {
				$ratio = $assetHeight / $availableHeight;
				$width = $assetWidth / $ratio;
				$height = $availableHeight;
			}
		}
		$xOffset = ($availableWidth - $width) / 2;
		$yOffset = ($availableHeight - $height) / 2;
		return _hx_anonymous(array("width" => $width, "height" => $height, "x" => $xOffset, "y" => $yOffset));
	}
	public function renderEmbeddedAsset($graphicContext) {
	}
	public function isReplaced() {
		return true;
	}
	public function getBoxStylesComputer() {
		$boxComputer = null;
		if($this->coreStyle->computedStyle->cssFloat == cocktail_core_style_CSSFloat::$left || $this->coreStyle->computedStyle->cssFloat == cocktail_core_style_CSSFloat::$right) {
			$boxComputer = new cocktail_core_style_computer_boxComputers_EmbeddedFloatBoxStylesComputer();
		} else {
			if($this->coreStyle->computedStyle->position == cocktail_core_style_Position::$fixed || $this->coreStyle->computedStyle->position == cocktail_core_style_Position::$absolute) {
				$boxComputer = new cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer();
			} else {
				$»t = ($this->coreStyle->computedStyle->display);
				switch($»t->index) {
				case 0:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer();
				}break;
				case 1:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer();
				}break;
				case 3:
				{
					$boxComputer = null;
				}break;
				case 2:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer();
				}break;
				}
			}
		}
		return $boxComputer;
	}
	public function renderSelf($graphicContext) {
		parent::renderSelf($graphicContext);
		$this->renderEmbeddedAsset($graphicContext);
	}
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.EmbeddedBoxRenderer'; }
}
