<?php

class cocktail_core_dom_Document extends cocktail_core_dom_Node {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function get_nodeType() {
		return 9;
	}
	public function getElementsByClassName($className) {
		return $this->documentElement->getElementsByClassName($className);
	}
	public function getElementsByTagName($tagName) {
		return $this->documentElement->getElementsByTagName($tagName);
	}
	public function doGetElementById($node, $elementId) {
		if($node->hasChildNodes() === true && $node->get_nodeType() === 1) {
			$length = $node->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$matchingElement = $this->doGetElementById($node->childNodes[$i], $elementId);
					if($matchingElement !== null) {
						return $matchingElement;
					}
					unset($matchingElement,$i);
				}
			}
		}
		if($node->hasAttributes() === true) {
			$attributes = $node->attributes;
			$element = $node;
			$attributesLength = $attributes->get_length();
			{
				$_g = 0;
				while($_g < $attributesLength) {
					$i = $_g++;
					$attribute = $element->getAttributeNode($attributes->item($i)->get_nodeName());
					if($attribute->isId === true && $attribute->specified === true) {
						if($attribute->get_value() === $elementId) {
							return $element;
						}
					}
					unset($i,$attribute);
				}
			}
		}
		return null;
	}
	public function getElementById($elementId) {
		return $this->doGetElementById($this->documentElement, $elementId);
	}
	public function createEvent($eventInterface) {
		switch($eventInterface) {
		case "Event":{
			return new cocktail_core_event_Event();
		}break;
		case "UIEvent":{
			return new cocktail_core_event_UIEvent();
		}break;
		case "CustomEvent":{
			return new cocktail_core_event_CustomEvent();
		}break;
		case "MouseEvent":{
			return new cocktail_core_event_MouseEvent();
		}break;
		case "KeyboardEvent":{
			return new cocktail_core_event_KeyboardEvent();
		}break;
		case "FocusEvent":{
			return new cocktail_core_event_FocusEvent();
		}break;
		case "WheelEvent":{
			return new cocktail_core_event_WheelEvent();
		}break;
		case "TransitionEvent":{
			return new cocktail_core_event_TransitionEvent();
		}break;
		default:{
			throw new HException(9);
		}break;
		}
		return null;
	}
	public function createAttribute($name) {
		$attribute = new cocktail_core_dom_Attr($name);
		return $attribute;
	}
	public function createComment($data) {
		$comment = new cocktail_core_dom_Comment();
		$comment->set_nodeValue($data);
		return $comment;
	}
	public function createTextNode($data) {
		$text = new cocktail_core_dom_Text();
		$text->set_nodeValue($data);
		return $text;
	}
	public function createElement($tagName) {
		return null;
	}
	public $documentElement;
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
	static $__properties__ = array("get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.dom.Document'; }
}
