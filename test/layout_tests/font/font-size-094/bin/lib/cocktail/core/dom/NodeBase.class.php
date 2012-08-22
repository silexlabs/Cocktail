<?php

class cocktail_core_dom_NodeBase extends cocktail_core_event_EventCallback {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->childNodes = new _hx_array(array());
	}}
	public function get_previousSibling() {
		if($this->parentNode === null) {
			return null;
		} else {
			if($this->parentNode->get_firstChild() != $this) {
				$length = $this->parentNode->childNodes->length;
				{
					$_g = 0;
					while($_g < $length) {
						$i = $_g++;
						if($this->parentNode->childNodes[$i] == $this) {
							return $this->parentNode->childNodes[$i - 1];
						}
						unset($i);
					}
				}
			}
		}
		return null;
	}
	public function get_nextSibling() {
		if($this->parentNode === null) {
			return null;
		} else {
			if($this->parentNode->get_lastChild() != $this) {
				$length = $this->parentNode->childNodes->length;
				{
					$_g = 0;
					while($_g < $length) {
						$i = $_g++;
						if(($this->parentNode->childNodes[$i] === $this)) {
							return $this->parentNode->childNodes[$i + 1];
						}
						unset($i);
					}
				}
			}
		}
		return null;
	}
	public function get_lastChild() {
		if($this->hasChildNodes() === true) {
			return $this->childNodes[$this->childNodes->length - 1];
		} else {
			return null;
		}
	}
	public function get_firstChild() {
		if($this->hasChildNodes() === true) {
			return $this->childNodes[0];
		} else {
			return null;
		}
	}
	public function removeFromParentIfNecessary($newChild) {
		if($newChild->parentNode !== null) {
			$parentNode = $newChild->parentNode;
			$parentNode->removeChild($newChild);
		}
	}
	public function getTargetAncestors() {
		$parent = $this->parentNode;
		$targetAncestors = new _hx_array(array());
		while($parent !== null) {
			$targetAncestors->push($parent);
			$parent = $parent->parentNode;
		}
		return $targetAncestors;
	}
	public function hasChildNodes() {
		return $this->childNodes->length > 0;
	}
	public function replaceChild($newChild, $oldChild) {
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				if($this->childNodes[$i] == $oldChild) {
					$this->removeChild($oldChild);
					$this->appendChild($newChild);
				}
				unset($i);
			}
		}
		return $oldChild;
	}
	public function isSameNode($other) {
		return $other == $this;
	}
	public function insertBefore($newChild, $refChild) {
		if($refChild === null) {
			$this->appendChild($newChild);
		} else {
			$newChildNodes = new _hx_array(array());
			$length = $this->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					if($this->childNodes[$i] == $refChild) {
						$newChildNodes->push($newChild);
					}
					$newChildNodes->push($this->childNodes[$i]);
					unset($i);
				}
			}
			{
				$_g1 = 0; $_g = $newChildNodes->length;
				while($_g1 < $_g) {
					$i = $_g1++;
					$this->appendChild($newChildNodes[$i]);
					unset($i);
				}
			}
		}
		return $newChild;
	}
	public function appendChild($newChild) {
		$this->removeFromParentIfNecessary($newChild);
		$newChild->parentNode = $this;
		$this->childNodes->push($newChild);
		return $newChild;
	}
	public function removeChild($oldChild) {
		$oldChild->parentNode = null;
		$this->childNodes->remove($oldChild);
		return $oldChild;
	}
	public $previousSibling;
	public $nextSibling;
	public $lastChild;
	public $firstChild;
	public $childNodes;
	public $parentNode;
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
	static $__properties__ = array("get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.dom.NodeBase'; }
}
