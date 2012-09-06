<?php

class cocktail_core_html_HTMLDocument extends cocktail_core_dom_Document {
	public function __construct($window = null) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		if($window === null) {
			$window = new cocktail_core_window_Window();
		}
		$this->_window = $window;
		$this->_focusManager = new cocktail_core_focus_FocusManager();
		$this->_multiTouchManager = new cocktail_core_multitouch_MultiTouchManager();
		$this->documentElement = $this->createElement("HTML");
		$this->documentElement->attach();
		$this->initBody($this->createElement("BODY"));
		$this->documentElement->appendChild($this->body);
		$this->_shouldDispatchClickOnNextMouseUp = false;
		$this->_invalidationScheduled = false;
		$this->_documentNeedsLayout = true;
		$this->_documentNeedsRendering = true;
	}}
	public function get_activeElement() {
		return $this->_focusManager->activeElement;
	}
	public function set_activeElement($newActiveElement) {
		$this->_focusManager->setActiveElement($newActiveElement, $this->body);
		return $this->get_activeElement();
	}
	public function getFirstVerticallyScrollableHTMLElement($htmlElement, $scrollOffset) {
		while($htmlElement->isVerticallyScrollable($scrollOffset) === false) {
			$htmlElement = $htmlElement->parentNode;
			if($htmlElement === null) {
				return null;
			}
		}
		return $htmlElement;
	}
	public function getFirstElementRendererWhichCanDispatchMouseEvent($x, $y) {
		$x1 = $x;
		$y1 = $y;
		$elementRendererAtPoint = $this->body->elementRenderer->layerRenderer->getTopMostElementRendererAtPoint(_hx_anonymous(array("x" => $x1, "y" => $y1)), 0, 0);
		if($elementRendererAtPoint === null) {
			return $this->body->elementRenderer;
		}
		while($elementRendererAtPoint->domNode->get_nodeType() !== 1 || $elementRendererAtPoint->isAnonymousBlockBox() === true) {
			$elementRendererAtPoint = $elementRendererAtPoint->parentNode;
			if($elementRendererAtPoint === null) {
				return null;
			}
		}
		return $elementRendererAtPoint;
	}
	public function scheduleLayoutAndRender() {
		$onLayoutScheduleDelegate = (isset($this->onLayoutSchedule) ? $this->onLayoutSchedule: array($this, "onLayoutSchedule"));
	}
	public function startLayout($forceLayout) {
		$this->documentElement->elementRenderer->layout($forceLayout);
		$this->documentElement->elementRenderer->setGlobalOrigins(0, 0, 0, 0, 0, 0);
	}
	public function startPendingAnimation() {
		return $this->documentElement->elementRenderer->startPendingAnimation();
	}
	public function startRendering() {
		$this->documentElement->elementRenderer->layerRenderer->render($this->_window->get_innerWidth(), $this->_window->get_innerHeight());
	}
	public function onLayoutSchedule() {
		$this->layoutAndRender();
		$this->_invalidationScheduled = false;
	}
	public function layoutAndRender() {
		if($this->_documentNeedsLayout === true) {
			$this->startLayout(false);
			$this->_documentNeedsLayout = false;
			$atLeastOneAnimationStarted = $this->startPendingAnimation();
			if($atLeastOneAnimationStarted === true) {
				$this->startLayout(true);
			}
		}
		if($this->_documentNeedsRendering === true) {
			$this->startRendering();
			$this->_documentNeedsRendering = false;
		}
	}
	public function doInvalidate() {
		$this->_invalidationScheduled = true;
		$this->scheduleLayoutAndRender();
	}
	public function invalidate() {
		if($this->_invalidationScheduled === false) {
			$this->doInvalidate();
		}
	}
	public function invalidateRendering() {
		$this->_documentNeedsRendering = true;
		$this->invalidate();
	}
	public function invalidateLayout() {
		$this->_documentNeedsLayout = true;
		$this->invalidate();
	}
	public function set_fullscreenElement($value) {
		if($value === null) {
			$this->fullscreenElement = null;
			return $value;
		}
		if($this->fullscreenElement !== null) {
			return $this->fullscreenElement;
		}
		$this->fullscreenElement = $value;
		if($this->onEnterFullscreen !== null) {
			$this->onEnterFullscreen();
		}
		$fullscreenEvent = new cocktail_core_event_Event();
		$fullscreenEvent->initEvent("fullscreenchange", true, false);
		return $value;
	}
	public function get_fullscreenEnabled() {
		return $this->_window->platform->nativeWindow->fullScreenEnabled();
	}
	public function exitFullscreen() {
		if($this->fullscreenElement === null) {
			return;
		}
		$this->set_fullscreenElement(null);
		if($this->onExitFullscreen !== null) {
			$this->onExitFullscreen();
		}
		$fullscreenEvent = new cocktail_core_event_Event();
		$fullscreenEvent->initEvent("fullscreenchange", true, false);
	}
	public function setMouseCursor($cursor) {
		if($this->onSetMouseCursor !== null) {
			$this->onSetMouseCursor($cursor);
		}
	}
	public function dispatchClickEvent($mouseEvent) {
		$elementRendererAtPoint = $this->getFirstElementRendererWhichCanDispatchMouseEvent($mouseEvent->screenX, $mouseEvent->screenY);
		$htmlElement = $elementRendererAtPoint->domNode;
		$nearestActivatableElement = $htmlElement->getNearestActivatableElement();
		if($nearestActivatableElement !== null) {
			$nearestActivatableElement->runPreClickActivation();
		}
		$clickEvent = new cocktail_core_event_MouseEvent();
		$clickEvent->initMouseEvent("click", true, true, null, 0.0, $mouseEvent->screenX, $mouseEvent->screenY, $mouseEvent->clientX, $mouseEvent->clientY, $mouseEvent->ctrlKey, $mouseEvent->altKey, $mouseEvent->shiftKey, $mouseEvent->metaKey, $mouseEvent->button, null);
		$htmlElement->dispatchEvent($clickEvent);
		if($nearestActivatableElement !== null) {
			if($mouseEvent->defaultPrevented === true) {
				$nearestActivatableElement->runCanceledActivationStep();
			} else {
				$nearestActivatableElement->runPostClickActivationStep($mouseEvent);
			}
		}
	}
	public function onPlatformTouchEvent($touchEvent) {
		$touch = $touchEvent->touches->item(0);
		$elementAtTouchPoint = $this->getFirstElementRendererWhichCanDispatchMouseEvent($touch->screenX, $touch->screenY);
		$this->_multiTouchManager->setUpTouchEvent($touchEvent, $elementAtTouchPoint->domNode);
		$elementAtTouchPoint->domNode->dispatchEvent($touchEvent);
	}
	public function onPlatformResizeEvent($event) {
		$this->documentElement->invalidate(cocktail_core_renderer_InvalidationReason::$windowResize);
	}
	public function onPlatformKeyUpEvent($keyboardEvent) {
		$this->get_activeElement()->dispatchEvent($keyboardEvent);
	}
	public function onPlatformKeyDownEvent($keyboardEvent) {
		$this->get_activeElement()->dispatchEvent($keyboardEvent);
		switch(Std::parseInt($keyboardEvent->keyChar)) {
		case 9:{
			if($keyboardEvent->defaultPrevented === false) {
				$this->set_activeElement($this->_focusManager->getNextFocusedElement($keyboardEvent->shiftKey === true, $this->body, $this->get_activeElement()));
			}
		}break;
		case 13:case 32:{
			if($keyboardEvent->defaultPrevented === false) {
				$this->get_activeElement()->click();
			}
		}break;
		}
	}
	public function onPlatformMouseMoveEvent($mouseEvent) {
		$elementRendererAtPoint = $this->getFirstElementRendererWhichCanDispatchMouseEvent($mouseEvent->screenX, $mouseEvent->screenY);
		if($this->_hoveredElementRenderer !== $elementRendererAtPoint) {
			$mouseOutEvent = new cocktail_core_event_MouseEvent();
			$mouseOutEvent->initMouseEvent("mouseout", true, true, null, 0.0, $mouseEvent->screenX, $mouseEvent->screenY, $mouseEvent->clientX, $mouseEvent->clientY, $mouseEvent->ctrlKey, $mouseEvent->altKey, $mouseEvent->shiftKey, $mouseEvent->metaKey, $mouseEvent->button, $elementRendererAtPoint->domNode);
			$this->_hoveredElementRenderer->domNode->dispatchEvent($mouseOutEvent);
			$oldHoveredElementRenderer = $this->_hoveredElementRenderer;
			$this->_hoveredElementRenderer = $elementRendererAtPoint;
			$mouseOverEvent = new cocktail_core_event_MouseEvent();
			$mouseOverEvent->initMouseEvent("mouseover", true, true, null, 0.0, $mouseEvent->screenX, $mouseEvent->screenY, $mouseEvent->clientX, $mouseEvent->clientY, $mouseEvent->ctrlKey, $mouseEvent->shiftKey, $mouseEvent->altKey, $mouseEvent->metaKey, $mouseEvent->button, $oldHoveredElementRenderer->domNode);
			$elementRendererAtPoint->domNode->dispatchEvent($mouseOverEvent);
			$this->_shouldDispatchClickOnNextMouseUp = false;
			$this->setMouseCursor($elementRendererAtPoint->domNode->coreStyle->computedStyle->cursor);
		}
		$elementRendererAtPoint->domNode->dispatchEvent($mouseEvent);
	}
	public function onPlatformMouseWheelEvent($wheelEvent) {
		$elementRendererAtPoint = $this->getFirstElementRendererWhichCanDispatchMouseEvent($wheelEvent->screenX, $wheelEvent->screenY);
		$elementRendererAtPoint->domNode->dispatchEvent($wheelEvent);
		if($wheelEvent->defaultPrevented === false) {
			$htmlElement = $elementRendererAtPoint->domNode;
			$scrollOffset = Math::round($wheelEvent->deltaY * 10);
			$scrollableHTMLElement = $this->getFirstVerticallyScrollableHTMLElement($htmlElement, $scrollOffset);
			if($scrollableHTMLElement !== null) {
				$_g = $scrollableHTMLElement;
				$_g->set_scrollTop($_g->get_scrollTop() - $scrollOffset);
			}
		}
	}
	public function onPlatformMouseEvent($mouseEvent) {
		$eventType = $mouseEvent->type;
		$elementRendererAtPoint = $this->getFirstElementRendererWhichCanDispatchMouseEvent($mouseEvent->screenX, $mouseEvent->screenY);
		$elementRendererAtPoint->domNode->dispatchEvent($mouseEvent);
		switch($eventType) {
		case "mousedown":{
			$this->_shouldDispatchClickOnNextMouseUp = true;
		}break;
		case "mouseup":{
			if($this->_shouldDispatchClickOnNextMouseUp === true) {
				$this->dispatchClickEvent($mouseEvent);
			}
		}break;
		}
	}
	public function createElement($tagName) {
		$element = null;
		$tagName = strtoupper($tagName);
		switch($tagName) {
		case "IMG":{
			$element = new cocktail_core_html_HTMLImageElement();
		}break;
		case "INPUT":{
			$element = new cocktail_core_html_HTMLInputElement();
		}break;
		case "A":{
			$element = new cocktail_core_html_HTMLAnchorElement();
		}break;
		case "HTML":{
			$element = new cocktail_core_html_HTMLHtmlElement();
		}break;
		case "BODY":{
			$element = new cocktail_core_html_HTMLBodyElement();
		}break;
		case "VIDEO":{
			$element = new cocktail_core_html_HTMLVideoElement();
		}break;
		case "SOURCE":{
			$element = new cocktail_core_html_HTMLSourceElement();
		}break;
		case "OBJECT":{
			$element = new cocktail_core_html_HTMLObjectElement();
		}break;
		case "PARAM":{
			$element = new cocktail_core_html_HTMLParamElement();
		}break;
		case "LINK":{
			$element = new cocktail_core_html_HTMLLinkElement();
		}break;
		default:{
			$element = new cocktail_core_html_HTMLElement($tagName);
		}break;
		}
		$element->ownerDocument = $this;
		return $element;
	}
	public function initBody($htmlBodyElement) {
		$this->body = $htmlBodyElement;
		$this->documentElement->appendChild($this->body);
		$this->_hoveredElementRenderer = $this->body->elementRenderer;
		$this->set_activeElement($this->body);
	}
	public $_window;
	public $_multiTouchManager;
	public $_documentNeedsRendering;
	public $_documentNeedsLayout;
	public $_invalidationScheduled;
	public $_shouldDispatchClickOnNextMouseUp;
	public $onSetMouseCursor;
	public $onExitFullscreen;
	public $onEnterFullscreen;
	public $fullscreenElement;
	public $fullscreenEnabled;
	public $_hoveredElementRenderer;
	public $_focusManager;
	public $activeElement;
	public $body;
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
	static $TAB_KEY_CODE = 9;
	static $ENTER_KEY_CODE = 13;
	static $SPACE_KEY_CODE = 32;
	static $MOUSE_WHEEL_DELTA_MULTIPLIER = 10;
	static $INVALIDATION_INTERVAL = 20;
	static $__properties__ = array("set_activeElement" => "set_activeElement","get_activeElement" => "get_activeElement","get_fullscreenEnabled" => "get_fullscreenEnabled","set_fullscreenElement" => "set_fullscreenElement","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.html.HTMLDocument'; }
}
