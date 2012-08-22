<?php

class cocktail_core_renderer_InlineBoxRenderer extends cocktail_core_renderer_FlowBoxRenderer {
	public function __construct($node) { if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
	}}
	public function get_bounds() {
		$lineBoxesBounds = new _hx_array(array());
		$length = $this->lineBoxes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$lineBoxesBounds->push(_hx_array_get($this->lineBoxes, $i)->get_bounds());
				unset($i);
			}
		}
		return $this->getChildrenBounds($lineBoxesBounds);
	}
	public function renderChildLineBoxes($graphicContext) {
		$length = $this->lineBoxes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$childLineBoxes = $this->getLineBoxesInLine($this->lineBoxes[$i]);
				$childLength = $childLineBoxes->length;
				{
					$_g1 = 0;
					while($_g1 < $childLength) {
						$j = $_g1++;
						$childLineBox = $childLineBoxes[$j];
						if($childLineBox->elementRenderer->layerRenderer == $this->layerRenderer) {
							$childLineBox->render($graphicContext);
						}
						unset($j,$childLineBox);
					}
					unset($_g1);
				}
				unset($i,$childLineBoxes,$childLength);
			}
		}
	}
	public function renderChildren($graphicContext) {
		parent::renderChildren($graphicContext);
		$this->renderChildLineBoxes($graphicContext);
	}
	public function renderBackground($graphicContext) {
	}
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.InlineBoxRenderer'; }
}
