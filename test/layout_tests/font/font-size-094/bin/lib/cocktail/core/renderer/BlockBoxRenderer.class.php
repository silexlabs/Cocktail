<?php

class cocktail_core_renderer_BlockBoxRenderer extends cocktail_core_renderer_ScrollableRenderer {
	public function __construct($node) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
		$this->_isMakingChildrenNonInline = false;
	}}
	public function getContainerBlockData() {
		$height = $this->coreStyle->computedStyle->getHeight();
		if($this->_horizontalScrollBar !== null) {
			$height -= $this->_horizontalScrollBar->coreStyle->computedStyle->getHeight();
		}
		$width = $this->coreStyle->computedStyle->getWidth();
		if($this->_verticalScrollBar !== null) {
			$width -= $this->_verticalScrollBar->coreStyle->computedStyle->getWidth();
		}
		return _hx_anonymous(array("width" => $width, "isWidthAuto" => $this->coreStyle->width == cocktail_core_style_Dimension::$cssAuto, "height" => $height, "isHeightAuto" => $this->coreStyle->height == cocktail_core_style_Dimension::$cssAuto));
	}
	public function rendersAsIfEstablishingStackingContext() {
		if($this->coreStyle->computedStyle->display == cocktail_core_style_Display::$inlineBlock) {
			return true;
		} else {
			if($this->isFloat() === true) {
				return true;
			}
		}
		return false;
	}
	public function isBlockContainer() {
		return true;
	}
	public function establishesNewFormattingContext() {
		$establishesNewFormattingContext = false;
		if($this->isFloat() === true) {
			$establishesNewFormattingContext = true;
		} else {
			if($this->canAlwaysOverflow() === false) {
				$establishesNewFormattingContext = true;
			} else {
				if($this->isPositioned() === true && $this->isRelativePositioned() === false) {
					$establishesNewFormattingContext = true;
				} else {
					if($this->isAnonymousBlockBox() === true) {
						$establishesNewFormattingContext = true;
					} else {
						$»t = ($this->coreStyle->computedStyle->display);
						switch($»t->index) {
						case 1:
						{
							$establishesNewFormattingContext = true;
						}break;
						case 0:
						{
							if($this->childrenInline() === true) {
								$establishesNewFormattingContext = true;
							}
						}break;
						default:{
						}break;
						}
					}
				}
			}
		}
		return $establishesNewFormattingContext;
	}
	public function establishesNewStackingContext() {
		$establishesNewStackingContext = parent::establishesNewStackingContext();
		if($establishesNewStackingContext === true) {
			return true;
		}
		return $this->canAlwaysOverflow() !== true;
	}
	public function doFormat() {
		if($this->childrenInline() === true) {
			_hx_deref(new cocktail_core_style_formatter_InlineFormattingContext($this))->format(new cocktail_core_style_floats_FloatsManager());
		} else {
			_hx_deref(new cocktail_core_style_formatter_BlockFormattingContext($this))->format(new cocktail_core_style_floats_FloatsManager());
		}
	}
	public function format() {
		if($this->establishesNewFormattingContext() === true) {
			if($this->isPositioned() === true && $this->isRelativePositioned() === false) {
				$this->doFormat();
			} else {
				if($this->isFloat() === true) {
					$this->doFormat();
				} else {
					if($this->coreStyle->computedStyle->display == cocktail_core_style_Display::$inlineBlock) {
						$this->doFormat();
					} else {
						if($this->childrenInline() === false) {
							$this->doFormat();
						}
					}
				}
			}
		}
	}
	public function layoutChildren() {
		parent::layoutChildren();
		$this->format();
	}
	public function getBlockContainerChildren($rootRenderer, $referenceLayer) {
		$ret = new _hx_array(array());
		$length = $rootRenderer->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $rootRenderer->childNodes[$i];
				if($child->layerRenderer === $referenceLayer) {
					if($child->isReplaced() === false && $child->coreStyle->display != cocktail_core_style_Display::$inlineBlock) {
						$ret->push($child);
						$childElementRenderer = $this->getBlockContainerChildren($child, $referenceLayer);
						$childLength = $childElementRenderer->length;
						{
							$_g1 = 0;
							while($_g1 < $childLength) {
								$j = $_g1++;
								$ret->push($childElementRenderer[$j]);
								unset($j);
							}
							unset($_g1);
						}
						unset($childLength,$childElementRenderer);
					}
				}
				unset($i,$child);
			}
		}
		return $ret;
	}
	public function getBlockReplacedChildren($rootRenderer, $referenceLayer) {
		$ret = new _hx_array(array());
		$length = $rootRenderer->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $rootRenderer->childNodes[$i];
				if($child->layerRenderer === $referenceLayer) {
					if($child->isReplaced() === false && $child->coreStyle->display == cocktail_core_style_Display::$block) {
						$childElementRenderer = $this->getBlockReplacedChildren($child, $referenceLayer);
						$childLength = $childElementRenderer->length;
						{
							$_g1 = 0;
							while($_g1 < $childLength) {
								$j = $_g1++;
								$ret->push($childElementRenderer[$j]);
								unset($j);
							}
							unset($_g1);
						}
						unset($childLength,$childElementRenderer);
					} else {
						if($child->coreStyle->display == cocktail_core_style_Display::$block) {
							$ret->push($child);
						}
					}
				}
				unset($i,$child);
			}
		}
		return $ret;
	}
	public function getChilrenLineBoxes($rootRenderer, $referenceLayer) {
		$ret = new _hx_array(array());
		if($rootRenderer->establishesNewFormattingContext() === true && $rootRenderer->childrenInline() === true) {
			$blockBoxRenderer = $rootRenderer;
			$length = $blockBoxRenderer->lineBoxes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$lineBoxes = $this->getLineBoxesInLine($blockBoxRenderer->lineBoxes[$i]);
					$childLength = $lineBoxes->length;
					{
						$_g1 = 0;
						while($_g1 < $childLength) {
							$j = $_g1++;
							if(_hx_array_get($lineBoxes, $j)->elementRenderer->layerRenderer === $referenceLayer) {
								$ret->push($lineBoxes[$j]);
							}
							unset($j);
						}
						unset($_g1);
					}
					unset($lineBoxes,$i,$childLength);
				}
			}
		} else {
			$length = $rootRenderer->childNodes->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$child = $rootRenderer->childNodes[$i];
					if($child->layerRenderer === $referenceLayer) {
						if($child->isReplaced() === false) {
							$childLineBoxes = $this->getChilrenLineBoxes($child, $referenceLayer);
							$childLength = $childLineBoxes->length;
							{
								$_g1 = 0;
								while($_g1 < $childLength) {
									$j = $_g1++;
									$ret->push($childLineBoxes[$j]);
									unset($j);
								}
								unset($_g1);
							}
							unset($childLineBoxes,$childLength);
						}
					}
					unset($i,$child);
				}
			}
		}
		return $ret;
	}
	public function renderScrollBars($graphicContext, $windowWidth, $windowHeight) {
		if($this->_horizontalScrollBar !== null) {
			$this->_horizontalScrollBar->elementRenderer->layerRenderer->render($windowWidth, $windowHeight);
		}
		if($this->_verticalScrollBar !== null) {
			$this->_verticalScrollBar->elementRenderer->layerRenderer->render($windowWidth, $windowHeight);
		}
	}
	public function renderBlockContainerChildren($graphicContext) {
		$childrenBlockContainer = $this->getBlockContainerChildren($this, $this->layerRenderer);
		$length = $childrenBlockContainer->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				_hx_array_get($childrenBlockContainer, $i)->render($graphicContext);
				unset($i);
			}
		}
	}
	public function renderBlockReplacedChildren($graphicContext) {
		$childrenBlockReplaced = $this->getBlockReplacedChildren($this, $this->layerRenderer);
		$length = $childrenBlockReplaced->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				_hx_array_get($childrenBlockReplaced, $i)->render($graphicContext);
				unset($i);
			}
		}
	}
	public function renderLineBoxes($graphicContext) {
		$lineBoxes = $this->getChilrenLineBoxes($this, $this->layerRenderer);
		$length = $lineBoxes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				_hx_array_get($lineBoxes, $i)->render($graphicContext);
				unset($i);
			}
		}
	}
	public function renderChildren($graphicContext) {
		parent::renderChildren($graphicContext);
		if($this->establishesNewStackingContext() === true || $this->rendersAsIfEstablishingStackingContext() === true) {
			$this->renderBlockContainerChildren($graphicContext);
			$this->renderBlockReplacedChildren($graphicContext);
			$this->renderLineBoxes($graphicContext);
		}
	}
	public function hasSignificantChild() {
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $this->childNodes[$i];
				if($child->isFloat() === false) {
					if($child->isPositioned() === false || $child->isRelativePositioned() === true) {
						return true;
					}
				}
				unset($i,$child);
			}
		}
		return false;
	}
	public function createAnonymousBlock($child) {
		$anonymousBlock = new cocktail_core_renderer_AnonymousBlockBoxRenderer();
		$anonymousBlock->appendChild($child);
		$anonymousBlock->coreStyle = $anonymousBlock->domNode->coreStyle;
		return $anonymousBlock;
	}
	public function makeChildrenNonInline() {
		$newChildNodes = new _hx_array(array());
		$i = $this->childNodes->length - 1;
		while($i >= 0) {
			$child = $this->childNodes[$i];
			if($child->isInlineLevel() === true) {
				$anonymousBlock = $this->createAnonymousBlock($child);
				$newChildNodes->push($anonymousBlock);
				unset($anonymousBlock);
			} else {
				$newChildNodes->push($child);
			}
			$i--;
			unset($child);
		}
		$newChildNodes->reverse();
		$length = $newChildNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i1 = $_g++;
				$this->appendChild($newChildNodes[$i1]);
				unset($i1);
			}
		}
	}
	public function appendChild($newChild) {
		$shouldMakeChildrenNonInline = false;
		$elementRendererChild = $newChild;
		if($this->childNodes->length > 0) {
			if($elementRendererChild->isPositioned() === false || $elementRendererChild->isRelativePositioned() === true) {
				if($this->hasSignificantChild() === true) {
					if($elementRendererChild->isInlineLevel() != $this->childrenInline()) {
						$shouldMakeChildrenNonInline = true;
					}
				}
			}
		}
		parent::appendChild($newChild);
		if($shouldMakeChildrenNonInline === true) {
			if($this->_isMakingChildrenNonInline === false) {
				$this->_isMakingChildrenNonInline = true;
				$this->makeChildrenNonInline();
				$this->_isMakingChildrenNonInline = false;
			}
		}
		return $newChild;
	}
	public $_isMakingChildrenNonInline;
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
	static $__properties__ = array("set_bounds" => "set_bounds","get_bounds" => "get_bounds","get_globalBounds" => "get_globalBounds","get_scrollableBounds" => "get_scrollableBounds","set_scrollLeft" => "set_scrollLeft","get_scrollLeft" => "get_scrollLeft","set_scrollTop" => "set_scrollTop","get_scrollTop" => "get_scrollTop","get_scrollWidth" => "get_scrollWidth","get_scrollHeight" => "get_scrollHeight","get_firstChild" => "get_firstChild","get_lastChild" => "get_lastChild","get_nextSibling" => "get_nextSibling","get_previousSibling" => "get_previousSibling","set_onclick" => "set_onClick","set_ondblclick" => "set_onDblClick","set_onmousedown" => "set_onMouseDown","set_onmouseup" => "set_onMouseUp","set_onmouseover" => "set_onMouseOver","set_onmouseout" => "set_onMouseOut","set_onmousemove" => "set_onMouseMove","set_onmousewheel" => "set_onMouseWheel","set_onkeydown" => "set_onKeyDown","set_onkeyup" => "set_onKeyUp","set_onfocus" => "set_onFocus","set_onblur" => "set_onBlur","set_onresize" => "set_onResize","set_onfullscreenchange" => "set_onFullScreenChange","set_onscroll" => "set_onScroll","set_onload" => "set_onLoad","set_onerror" => "set_onError","set_onloadstart" => "set_onLoadStart","set_onprogress" => "set_onProgress","set_onsuspend" => "set_onSuspend","set_onemptied" => "set_onEmptied","set_onstalled" => "set_onStalled","set_onloadedmetadata" => "set_onLoadedMetadata","set_onloadeddata" => "set_onLoadedData","set_oncanplay" => "set_onCanPlay","set_oncanplaythrough" => "set_onCanPlayThrough","set_onplaying" => "set_onPlaying","set_onwaiting" => "set_onWaiting","set_onseeking" => "set_onSeeking","set_onseeked" => "set_onSeeked","set_onended" => "set_onEnded","set_ondurationchange" => "set_onDurationChanged","set_ontimeupdate" => "set_onTimeUpdate","set_onplay" => "set_onPlay","set_onpause" => "set_onPause","set_onvolumechange" => "set_onVolumeChange","set_ontransitionend" => "set_onTransitionEnd");
	function __toString() { return 'cocktail.core.renderer.BlockBoxRenderer'; }
}
