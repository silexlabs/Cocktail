<?php

class cocktail_core_html_HTMLElement extends cocktail_core_dom_Element {
	public function __construct($tagName) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct($tagName);
		$this->init();
	}}
	public function get_clientLeft() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		return 0;
	}
	public function get_clientTop() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		return 0;
	}
	public function get_clientHeight() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		$computedStyle = $this->coreStyle->computedStyle;
		return Math::round($computedStyle->getHeight() + $computedStyle->getPaddingTop() + $computedStyle->getPaddingBottom());
	}
	public function get_clientWidth() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		$computedStyle = $this->coreStyle->computedStyle;
		return Math::round($computedStyle->getWidth() + $computedStyle->getPaddingLeft() + $computedStyle->getPaddingRight());
	}
	public function get_offsetTop() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		return Math::round($this->elementRenderer->positionedOrigin->y);
	}
	public function get_offsetLeft() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		return Math::round($this->elementRenderer->positionedOrigin->x);
	}
	public function get_offsetHeight() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		$computedStyle = $this->coreStyle->computedStyle;
		return Math::round($computedStyle->getHeight() + $computedStyle->getPaddingTop() + $computedStyle->getPaddingBottom());
	}
	public function get_offsetWidth() {
		$this->invalidate(cocktail_core_renderer_InvalidationReason::$needsImmediateLayout);
		$computedStyle = $this->coreStyle->computedStyle;
		return Math::round($computedStyle->getWidth() + $computedStyle->getPaddingLeft() + $computedStyle->getPaddingRight());
	}
	public function get_offsetParent() {
		if($this->parentNode === null) {
			return null;
		}
		$parent = $this->parentNode;
		$isOffsetParent = $parent->elementRenderer->isPositioned();
		while($isOffsetParent === false) {
			if($parent->parentNode !== null) {
				$parent = $parent->parentNode;
				$isOffsetParent = $parent->elementRenderer->isPositioned();
			} else {
				$isOffsetParent = true;
			}
		}
		return $parent;
	}
	public function isVoidElement() {
		return false;
	}
	public function doGetInnerHTML($node, $xml) {
		$length = $node->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $node->childNodes[$i];
				switch($child->get_nodeType()) {
				case 1:{
					$childXml = Xml::createElement($child->get_nodeName());
					$childAttributes = $child->attributes;
					$childAttributesLength = $childAttributes->get_length();
					{
						$_g1 = 0;
						while($_g1 < $childAttributesLength) {
							$j = $_g1++;
							$attribute = $childAttributes->item($j);
							if($attribute->specified === true) {
								$childXml->set($attribute->name, $attribute->get_value());
							}
							unset($j,$attribute);
						}
					}
					$htmlChild = $child;
					$styleAttributes = $htmlChild->style->attributes;
					$concatenatedStyles = "";
					$attributesLength = $styleAttributes->get_length();
					{
						$_g1 = 0;
						while($_g1 < $attributesLength) {
							$j = $_g1++;
							$attribute = $styleAttributes->item($j);
							if($attribute->specified === true) {
								$concatenatedStyles .= $attribute->name . ":" . $attribute->get_value() . ";";
							}
							unset($j,$attribute);
						}
					}
					if($concatenatedStyles !== "") {
						$childXml->set("style", $concatenatedStyles);
					}
					$xml->addChild($this->doGetInnerHTML($child, $childXml));
					if($childXml->firstChild() === null && $this->isVoidElement() === false) {
						$childXml->addChild(Xml::createPCData(""));
					}
				}break;
				case 3:{
					$text = Xml::createPCData($child->get_nodeValue());
					$xml->addChild($text);
				}break;
				case 8:{
					$comment = Xml::createComment($child->get_nodeValue());
					$xml->addChild($comment);
				}break;
				}
				unset($i,$child);
			}
		}
		return $xml;
	}
	public function get_innerHTML() {
		$xml = $this->doGetInnerHTML($this, Xml::createElement($this->get_nodeName()));
		$str = $xml->toString();
		$str = _hx_substr($str, _hx_index_of($str, ">", null) + 1, _hx_last_index_of($str, "<", null) - _hx_index_of($str, ">", null) - 1);
		return $str;
	}
	public function doSetInnerHTML($xml) {
		switch($xml->nodeType) {
		case Xml::$PCData:{
			return $this->ownerDocument->createTextNode($xml->getNodeValue());
		}break;
		case Xml::$Comment:{
			return $this->ownerDocument->createComment($xml->getNodeValue());
		}break;
		case Xml::$Element:{
			$htmlElement = null;
			$name = strtolower($xml->getNodeName());
			$htmlElement = $this->ownerDocument->createElement($name);
			if(null == $xml) throw new HException('null iterable');
			$»it = $xml->iterator();
			while($»it->hasNext()) {
				$child = $»it->next();
				switch($child->nodeType) {
				case Xml::$PCData:{
					if($child->getNodeValue() === "") {
						continue 2;
					}
				}break;
				}
				$childNode = $this->doSetInnerHTML($child);
				$htmlElement->appendChild($childNode);
				unset($childNode);
			}
			if(null == $xml) throw new HException('null iterable');
			$»it = $xml->attributes();
			while($»it->hasNext()) {
				$attribute = $»it->next();
				$attribute = strtolower($attribute);
				$value = $xml->get($attribute);
				$htmlElement->setAttribute($attribute, $value);
				unset($value);
			}
			return $htmlElement;
		}break;
		}
		return null;
	}
	public function set_innerHTML($value) {
		$childLength = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $childLength) {
				$i = $_g++;
				$this->removeChild($this->childNodes[0]);
				unset($i);
			}
		}
		$wrappedHTML = "<" . "DIV" . ">";
		$wrappedHTML .= $value;
		$wrappedHTML .= "<" . "/" . "DIV" . ">";
		$node = $this->doSetInnerHTML(haxe_xml_Parser::parse($wrappedHTML)->firstElement());
		if($node === null) {
			return $value;
		}
		$length = $node->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$this->appendChild($node->childNodes[0]);
				unset($i);
			}
		}
		return $value;
	}
	public function set_hidden($value) {
		parent::setAttribute("hidden",Std::string($value));
		return $value;
	}
	public function get_hidden() {
		if($this->getAttribute("hidden") !== null) {
			return true;
		} else {
			return false;
		}
	}
	public function set_className($value) {
		$this->setAttribute("class", $value);
		return $value;
	}
	public function get_className() {
		return $this->getAttribute("class");
	}
	public function set_id($value) {
		$this->setAttribute("id", $value);
		return $value;
	}
	public function get_id() {
		return $this->getAttribute("id");
	}
	public function get_tabIndex() {
		$tabIndex = parent::getAttribute("tabIndex");
		if($tabIndex === "") {
			if($this->isDefaultFocusable() === true) {
				return 0;
			} else {
				return -1;
			}
		} else {
			return Std::parseInt($tabIndex);
		}
	}
	public function set_tabIndex($value) {
		$this->setAttribute("tabIndex", Std::string($value));
		return $value;
	}
	public function get_scrollTop() {
		if($this->elementRenderer !== null) {
			return Math::round($this->elementRenderer->get_scrollTop());
		}
		return 0;
	}
	public function set_scrollTop($value) {
		if($this->elementRenderer !== null) {
			$this->elementRenderer->set_scrollTop($value);
		}
		return $value;
	}
	public function get_scrollLeft() {
		if($this->elementRenderer !== null) {
			return Math::round($this->elementRenderer->get_scrollLeft());
		}
		return 0;
	}
	public function set_scrollLeft($value) {
		if($this->elementRenderer !== null) {
			$this->elementRenderer->set_scrollLeft($value);
		}
		return $value;
	}
	public function get_scrollWidth() {
		if($this->elementRenderer !== null) {
			return Math::round($this->elementRenderer->get_scrollWidth());
		}
		return 0;
	}
	public function get_scrollHeight() {
		if($this->elementRenderer !== null) {
			return Math::round($this->elementRenderer->get_scrollHeight());
		}
		return 0;
	}
	public function isHorizontallyScrollable($scrollOffset = null) {
		if($scrollOffset === null) {
			$scrollOffset = 0;
		}
		if($this->elementRenderer !== null) {
			return $this->elementRenderer->isHorizontallyScrollable($scrollOffset);
		}
		return false;
	}
	public function isVerticallyScrollable($scrollOffset = null) {
		if($scrollOffset === null) {
			$scrollOffset = 0;
		}
		if($this->elementRenderer !== null) {
			return $this->elementRenderer->isVerticallyScrollable($scrollOffset);
		}
		return false;
	}
	public function getNearestActivatableElement() {
		$htmlElement = $this;
		while($htmlElement->hasActivationBehaviour() === false) {
			if($htmlElement->parentNode === null) {
				return null;
			}
			$htmlElement = $htmlElement->parentNode;
		}
		return $htmlElement;
	}
	public function runPostClickActivationStep($event) {
	}
	public function runCanceledActivationStep() {
	}
	public function runPreClickActivation() {
	}
	public function hasActivationBehaviour() {
		return false;
	}
	public function requestFullScreen() {
		$htmlDocument = $this->ownerDocument;
		$htmlDocument->set_fullscreenElement($this);
	}
	public function blur() {
		$htmlDocument = $this->ownerDocument;
		$htmlDocument->body->focus();
	}
	public function focus() {
		$htmlDocument = $this->ownerDocument;
		$htmlDocument->set_activeElement($this);
	}
	public function isDefaultFocusable() {
		return false;
	}
	public function isFocusable() {
		if($this->parentNode === null) {
			return false;
		} else {
			if($this->isDefaultFocusable() === true) {
				return true;
			} else {
				if($this->get_tabIndex() > 0) {
					return true;
				}
			}
		}
		return false;
	}
	public function fireEvent($eventTye, $bubbles, $cancelable) {
		$event = new cocktail_core_event_Event();
		$event->initEvent($eventTye, $bubbles, $cancelable);
		$this->dispatchEvent($event);
	}
	public function click() {
		$mouseEvent = new cocktail_core_event_MouseEvent();
		$mouseEvent->initMouseEvent("click", false, false, null, 0, 0, 0, 0, 0, false, false, false, false, 0, null);
		$this->dispatchEvent($mouseEvent);
	}
	public function isParentRendered() {
		if($this->parentNode === null) {
			return false;
		}
		$htmlParent = $this->parentNode;
		if($htmlParent->elementRenderer !== null) {
			return true;
		} else {
			return false;
		}
	}
	public function isRendered() {
		if($this->get_hidden() === true) {
			return false;
		}
		if($this->coreStyle->computedStyle->display == cocktail_core_style_Display::$none) {
			return false;
		}
		return true;
	}
	public function attachCoreStyle() {
		$this->elementRenderer->coreStyle = $this->coreStyle;
	}
	public function createElementRenderer() {
		$»t = ($this->coreStyle->computedStyle->display);
		switch($»t->index) {
		case 0:
		case 1:
		{
			$this->elementRenderer = new cocktail_core_renderer_BlockBoxRenderer($this);
		}break;
		case 2:
		{
			$this->elementRenderer = new cocktail_core_renderer_InlineBoxRenderer($this);
		}break;
		case 3:
		{
		}break;
		}
	}
	public function detachFromParentElementRenderer() {
		$this->elementRenderer->parentNode->removeChild($this->elementRenderer);
	}
	public function attachToParentElementRenderer() {
		$parent = $this->parentNode;
		$parent->elementRenderer->insertBefore($this->elementRenderer, $this->getNextElementRendererSibling());
	}
	public function getNextElementRendererSibling() {
		$nextSibling = $this->get_nextSibling();
		if($nextSibling === null) {
			return null;
		} else {
			while($nextSibling !== null) {
				if($nextSibling->elementRenderer !== null) {
					$elementRenderParent = $nextSibling->elementRenderer->parentNode;
					if($elementRenderParent->isAnonymousBlockBox() === true) {
						return $elementRenderParent;
					}
					return $nextSibling->elementRenderer;
					unset($elementRenderParent);
				}
				$nextSibling = $nextSibling->get_nextSibling();
			}
		}
		return null;
	}
	public function detach() {
		if($this->isParentRendered() === true) {
			$parent = $this->parentNode;
			if($this->elementRenderer !== null) {
				$length = $this->childNodes->length;
				{
					$_g = 0;
					while($_g < $length) {
						$i = $_g++;
						switch(_hx_array_get($this->childNodes, $i)->get_nodeType()) {
						case 1:{
							$child = $this->childNodes[$i];
							$child->detach();
						}break;
						case 3:{
							$child = $this->childNodes[$i];
							$child->detach();
						}break;
						}
						unset($i);
					}
				}
				$this->detachFromParentElementRenderer();
				$this->elementRenderer = null;
			}
		}
	}
	public function attach() {
		if($this->isParentRendered() === true) {
			cocktail_core_style_computer_DisplayStylesComputer::compute($this->coreStyle);
			if($this->elementRenderer === null && $this->isRendered() === true) {
				$this->createElementRenderer();
				if($this->elementRenderer !== null) {
					$this->attachCoreStyle();
				}
			}
			if($this->elementRenderer !== null) {
				$this->attachToParentElementRenderer();
				$length = $this->childNodes->length;
				{
					$_g = 0;
					while($_g < $length) {
						$i = $_g++;
						switch(_hx_array_get($this->childNodes, $i)->get_nodeType()) {
						case 1:{
							$child = $this->childNodes[$i];
							$child->attach();
						}break;
						case 3:{
							$child = $this->childNodes[$i];
							$child->attach();
						}break;
						}
						unset($i);
					}
				}
			}
		}
	}
	public function invalidatePositioningScheme() {
		if($this->parentNode !== null) {
			$this->parentNode->detach();
			$this->parentNode->attach();
		}
	}
	public function invalidate($invalidationReason) {
		if($this->elementRenderer !== null) {
			$this->elementRenderer->invalidate($invalidationReason);
		}
	}
	public function executeDefaultActionIfNeeded($defaultPrevented, $event) {
		if($defaultPrevented === false) {
			switch($event->type) {
			case "mousedown":{
				$this->focus();
			}break;
			}
		}
	}
	public function getTargetAncestors() {
		$targetAncestors = parent::getTargetAncestors();
		$targetAncestors->push(cocktail_Lib::get_document());
		$targetAncestors->push(cocktail_Lib::get_window());
		return $targetAncestors;
	}
	public function getAttribute($name) {
		if($name === "tabIndex") {
			return Std::string($this->get_tabIndex());
		} else {
			return parent::getAttribute($name);
		}
	}
	public function setAttribute($name, $value) {
		if($name === "style") {
			$styleProxy = new lib_hxtml_StyleProxy();
			_hx_deref(new lib_hxtml_CssParser())->parse($value, $this, $styleProxy);
			parent::setAttribute($name,$value);
		} else {
			parent::setAttribute($name,$value);
		}
	}
	public function getElementsByTagName($tagName) {
		return parent::getElementsByTagName(strtoupper($tagName));
	}
	public function removeChild($oldChild) {
		switch($oldChild->get_nodeType()) {
		case 1:{
			$htmlChild = $oldChild;
			$htmlChild->detach();
		}break;
		case 3:{
			$textChild = $oldChild;
			$textChild->detach();
		}break;
		}
		parent::removeChild($oldChild);
		return $oldChild;
	}
	public function appendChild($newChild) {
		parent::appendChild($newChild);
		switch($newChild->get_nodeType()) {
		case 1:{
			$htmlChild = $newChild;
			$htmlChild->attach();
		}break;
		case 3:{
			$textChild = $newChild;
			$textChild->attach();
		}break;
		}
		return $newChild;
	}
	public function initId() {
		$id = new cocktail_core_dom_Attr("id");
		$this->setIdAttributeNode($id, true);
	}
	public function initStyle() {
		$this->style = new cocktail_core_style_adapter_Style($this->coreStyle);
	}
	public function initCoreStyle() {
		$this->coreStyle = new cocktail_core_style_CoreStyle($this);
	}
	public function init() {
		$this->initCoreStyle();
		$this->initStyle();
		$this->initId();
	}
	public $style;
	public $coreStyle;
	public $clientTop;
	public $clientLeft;
	public $clientHeight;
	public $clientWidth;
	public $offsetTop;
	public $offsetLeft;
	public $offsetHeight;
	public $offsetWidth;
	public $offsetParent;
	public $elementRenderer;
	public $innerHTML;
	public $scrollWidth;
	public $scrollHeight;
	public $scrollLeft;
	public $scrollTop;
	public $hidden;
	public $className;
	public $id;
	public $tabIndex;
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
	static $__properties__ = array("set_tabIndex" => "set_tabIndex","get_tabIndex" => "get_tabIndex","set_id" => "set_id","get_id" => "get_id","set_className" => "set_className","get_className" => "get_className","set_hidden" => "set_hidden","get_hidden" => "get_hidden","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","get_scrollHeight" => "get_scrollHeight","get_scrollWidth" => "get_scrollWidth","set_innerHTML" => "set_innerHTML","get_innerHTML" => "get_innerHTML","get_offsetParent" => "get_offsetParent","get_offsetWidth" => "get_offsetWidth","get_offsetHeight" => "get_offsetHeight","get_offsetLeft" => "get_offsetLeft","get_offsetTop" => "get_offsetTop","get_clientWidth" => "get_clientWidth","get_clientHeight" => "get_clientHeight","get_clientLeft" => "get_clientLeft","get_clientTop" => "get_clientTop","get_firstElementChild" => "get_firstElementChild","get_lastElementChild" => "get_lastElementChild","get_previousElementSibling" => "get_previousElementSibling","get_nextElementSibling" => "get_nextElementSibling","get_childElementCount" => "get_childElementCount","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.html.HTMLElement'; }
}
