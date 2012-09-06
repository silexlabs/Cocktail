<?php

class cocktail_core_dom_Element extends cocktail_core_dom_Node {
	public function __construct($tagName) {
		if(!php_Boot::$skip_constructor) {
		$this->tagName = $tagName;
		$this->attributes = new cocktail_core_dom_NamedNodeMap();
		parent::__construct();
	}}
	public function get_childElementCount() {
		$childElementCount = 0;
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				if(_hx_array_get($this->childNodes, $i)->get_nodeType() === 1) {
					$childElementCount++;
				}
				unset($i);
			}
		}
		return $childElementCount;
	}
	public function get_previousElementSibling() {
		if($this->get_previousSibling() === null) {
			return null;
		}
		$previousElementSibling = $this->get_previousSibling();
		while($previousElementSibling->get_nodeType() !== 1) {
			$previousElementSibling = $previousElementSibling->get_previousSibling();
			if($previousElementSibling === null) {
				return null;
			}
		}
		return $previousElementSibling;
	}
	public function get_nextElementSibling() {
		if($this->get_nextSibling() === null) {
			return null;
		}
		$nextElementSibling = $this->get_nextSibling();
		while($nextElementSibling->get_nodeType() !== 1) {
			$nextElementSibling = $nextElementSibling->get_nextSibling();
			if($nextElementSibling === null) {
				return null;
			}
		}
		return $nextElementSibling;
	}
	public function get_lastElementChild() {
		if($this->hasChildNodes() === false) {
			return null;
		}
		if($this->get_lastChild()->get_nodeType() === 1) {
			return $this->get_lastChild();
		} else {
			$length = $this->childNodes->length;
			{
				$_g = $length;
				while($_g < 0) {
					$i = $_g++;
					if(_hx_array_get($this->childNodes, $i)->get_nodeType() === 1) {
						return $this->childNodes[$i];
					}
					unset($i);
				}
			}
		}
		return null;
	}
	public function get_firstElementChild() {
		if($this->hasChildNodes() === false) {
			return null;
		}
		if($this->get_firstChild()->get_nodeType() === 1) {
			return $this->get_firstChild();
		} else {
			$length = $this->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					if(_hx_array_get($this->childNodes, $i)->get_nodeType() === 1) {
						return $this->childNodes[$i];
					}
					unset($i);
				}
			}
		}
		return null;
	}
	public function get_nodeType() {
		return 1;
	}
	public function get_nodeName() {
		return $this->tagName;
	}
	public function hasAttributes() {
		return $this->attributes->get_length() > 0;
	}
	public function doGetElementsByClassName($node, $className, $elements) {
		if($node->hasChildNodes() === true) {
			$length = $node->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$childNode = $node->childNodes[$i];
					switch($childNode->get_nodeType()) {
					case 1:{
						$elementNode = $childNode;
						$elementClassName = $elementNode->getAttribute("class");
						if($elementClassName !== null) {
							$elementClassNames = _hx_explode(" ", $elementClassName);
							$foundFlag = false;
							{
								$_g2 = 0; $_g1 = $elementClassNames->length;
								while($_g2 < $_g1) {
									$j = $_g2++;
									if($elementClassNames[$j] === $className && $foundFlag === false) {
										$elements->push($elementNode);
										$foundFlag = true;
									}
									unset($j);
								}
							}
						}
					}break;
					}
					$this->doGetElementsByClassName($childNode, $className, $elements);
					unset($i,$childNode);
				}
			}
		}
	}
	public function doGetElementsByTagName($node, $tagName, $elements) {
		if($node->hasChildNodes() === true) {
			$length = $node->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$childNode = $node->childNodes[$i];
					if($childNode->get_nodeName() === $tagName) {
						$elements->push($childNode);
					} else {
						if($tagName === "*" && $childNode->get_nodeType() === 1) {
							$elements->push($childNode);
						}
					}
					$this->doGetElementsByTagName($childNode, $tagName, $elements);
					unset($i,$childNode);
				}
			}
		}
	}
	public function getElementsByClassName($className) {
		$elements = new _hx_array(array());
		$this->doGetElementsByClassName($this, $className, $elements);
		return $elements;
	}
	public function getElementsByTagName($tagName) {
		$elements = new _hx_array(array());
		$this->doGetElementsByTagName($this, $tagName, $elements);
		return $elements;
	}
	public function hasAttribute($name) {
		return $this->attributes->getNamedItem($name) !== null;
	}
	public function setIdAttributeNode($idAttr, $isId) {
		$idAttr->isId = $isId;
		$this->attributes->setNamedItem($idAttr);
	}
	public function setIdAttribute($name, $isId) {
		$idAttribute = $this->attributes->getNamedItem($name);
		if($idAttribute === null) {
			$idAttribute = new cocktail_core_dom_Attr($name);
			$this->attributes->setNamedItem($idAttribute);
			$idAttribute->ownerElement = $this;
		}
		$idAttribute->isId = $isId;
	}
	public function removeAttribute($name) {
		$removedAttribute = $this->attributes->removeNamedItem($name);
		if($removedAttribute !== null) {
			$removedAttribute->ownerElement = null;
		}
	}
	public function setAttributeNode($newAttr) {
		$newAttr->ownerElement = $this;
		return $this->attributes->setNamedItem($newAttr);
	}
	public function getAttributeNode($name) {
		$attribute = $this->attributes->getNamedItem($name);
		if($attribute !== null) {
			return $attribute;
		}
		return null;
	}
	public function setAttribute($name, $value) {
		$attribute = $this->attributes->getNamedItem($name);
		if($attribute === null) {
			$attribute = new cocktail_core_dom_Attr($name);
			$this->attributes->setNamedItem($attribute);
			$attribute->ownerElement = $this;
		}
		$attribute->set_value($value);
	}
	public function getAttribute($name) {
		$attribute = $this->getAttributeNode($name);
		if($attribute !== null) {
			return $attribute->get_value();
		} else {
			return null;
		}
	}
	public $childElementCount;
	public $nextElementSibling;
	public $previousElementSibling;
	public $lastElementChild;
	public $firstElementChild;
	public $tagName;
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
	static $__properties__ = array("get_firstElementChild" => "get_firstElementChild","get_lastElementChild" => "get_lastElementChild","get_previousElementSibling" => "get_previousElementSibling","get_nextElementSibling" => "get_nextElementSibling","get_childElementCount" => "get_childElementCount","get_nodeType" => "get_nodeType","set_nodeValue" => "set_nodeValue","get_nodeValue" => "get_nodeValue","get_nodeName" => "get_nodeName","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.dom.Element'; }
}
