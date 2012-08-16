<?php

class cocktail_core_renderer_ObjectRenderer extends cocktail_core_renderer_EmbeddedBoxRenderer {
	public function __construct($node) { if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
	}}
	public function getScaleMode() {
		$scaleMode = "showall";
		{
			$_g1 = 0; $_g = $this->domNode->childNodes->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$child = $this->domNode->childNodes[$i];
				if($child->tagName === "PARAM") {
					if($child->getAttribute("name") !== null) {
						if($child->getAttribute("name") === "scale") {
							if($child->getAttribute("value") !== null) {
								$scaleMode = $child->getAttribute("value");
							}
						}
					}
				}
				unset($i,$child);
			}
		}
		return $scaleMode;
	}
	public function renderEmbeddedAsset($graphicContext) {
	}
	public function createLayer($parentLayer) {
		$this->layerRenderer = new cocktail_core_layer_CompositingLayerRenderer($this);
		$parentLayer->appendChild($this->layerRenderer);
		$this->_hasOwnLayer = true;
	}
	public function establishesNewStackingContext() {
		return true;
	}
	static $NO_SCALE = "noscale";
	static $SHOW_ALL = "showall";
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.ObjectRenderer'; }
}
