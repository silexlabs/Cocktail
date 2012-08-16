<?php

class cocktail_core_renderer_VideoRenderer extends cocktail_core_renderer_ImageRenderer {
	public function __construct($domNode) { if(!php_Boot::$skip_constructor) {
		parent::__construct($domNode);
	}}
	public function renderPosterFrame($htmlVideoElement, $graphicContext) {
		$resource = cocktail_core_resource_ResourceManager::getResource($this->domNode->getAttribute("poster"));
		if($resource->loaded === false || $resource->loadedWithError === true) {
			return;
		}
		$posterBounds = $this->getAssetBounds($this->coreStyle->computedStyle->getWidth(), $this->coreStyle->computedStyle->getHeight(), $resource->intrinsicWidth, $resource->intrinsicHeight);
		$paintBounds = _hx_anonymous(array("x" => $this->get_globalBounds()->x + $this->coreStyle->computedStyle->getPaddingLeft() + $posterBounds->x - $this->scrollOffset->x, "y" => $this->get_globalBounds()->y + $this->coreStyle->computedStyle->getPaddingTop() + $posterBounds->y - $this->scrollOffset->y, "width" => $posterBounds->width, "height" => $posterBounds->height));
		$this->paintResource($graphicContext, $resource->nativeResource, $paintBounds, $resource->intrinsicWidth, $resource->intrinsicHeight);
	}
	public function renderVideo($htmlVideoElement, $graphicContext) {
		$videoBounds = $this->getAssetBounds($this->coreStyle->computedStyle->getWidth(), $this->coreStyle->computedStyle->getHeight(), $htmlVideoElement->get_videoWidth(), $htmlVideoElement->get_videoHeight());
		$globalBounds = $this->get_globalBounds();
		$nativeVideo = $htmlVideoElement->nativeMedia;
		$nativeVideo->set_viewport(_hx_anonymous(array("x" => $globalBounds->x + $this->coreStyle->computedStyle->getPaddingLeft() + $videoBounds->x - $this->scrollOffset->x, "y" => $globalBounds->y + $this->coreStyle->computedStyle->getPaddingTop() + $videoBounds->y - $this->scrollOffset->y, "width" => $videoBounds->width, "height" => $videoBounds->height)));
		$nativeVideo->attach($graphicContext);
	}
	public function renderEmbeddedAsset($graphicContext) {
		$htmlVideoElement = $this->domNode;
		if($htmlVideoElement->shouldRenderPosterFrame() === true) {
			$this->renderPosterFrame($htmlVideoElement, $graphicContext);
		} else {
			$this->renderVideo($htmlVideoElement, $graphicContext);
		}
	}
	public function createLayer($parentLayer) {
		$this->layerRenderer = new cocktail_core_layer_CompositingLayerRenderer($this);
		$parentLayer->appendChild($this->layerRenderer);
		$this->_hasOwnLayer = true;
	}
	public function establishesNewStackingContext() {
		return true;
	}
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.VideoRenderer'; }
}
