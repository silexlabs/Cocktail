<?php

class cocktail_core_renderer_FlowBoxRenderer extends cocktail_core_renderer_BoxRenderer {
	public function __construct($node) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct($node);
		$this->_positionedChildren = new _hx_array(array());
	}}
	public function childrenInline() {
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $this->childNodes[$i];
				if($child->isInlineLevel() === true) {
					if($child->isFloat() === false) {
						if($child->isPositioned() === false || $child->isRelativePositioned() === true) {
							return true;
						}
					}
				}
				unset($i,$child);
			}
		}
		return false;
	}
	public function getBottomOffset($elementRenderer, $containingHTMLElementHeight) {
		$computedStyle = $elementRenderer->coreStyle->computedStyle;
		return $containingHTMLElementHeight - $computedStyle->getHeight() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getBottom();
	}
	public function getTopOffset($elementRenderer) {
		$computedStyle = $elementRenderer->coreStyle->computedStyle;
		return $computedStyle->getTop() + $computedStyle->getMarginTop();
	}
	public function getRightOffset($elementRenderer, $containingHTMLElementWidth) {
		$computedStyle = $elementRenderer->coreStyle->computedStyle;
		return $containingHTMLElementWidth - $computedStyle->getWidth() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getRight() - $computedStyle->getMarginRight();
	}
	public function getLeftOffset($elementRenderer) {
		$computedStyle = $elementRenderer->coreStyle->computedStyle;
		return $computedStyle->getLeft() + $computedStyle->getMarginLeft();
	}
	public function doLayoutPositionedChild($elementRenderer, $containingBlockData) {
		$elementCoreStyle = $elementRenderer->coreStyle;
		if($elementCoreStyle->left != cocktail_core_style_PositionOffset::$cssAuto) {
			$elementRenderer->positionedOrigin->x = $this->getLeftOffset($elementRenderer);
		} else {
			if($elementCoreStyle->right != cocktail_core_style_PositionOffset::$cssAuto) {
				$elementRenderer->positionedOrigin->x = $this->getRightOffset($elementRenderer, $containingBlockData->width);
			}
		}
		if($elementCoreStyle->top != cocktail_core_style_PositionOffset::$cssAuto) {
			$elementRenderer->positionedOrigin->y = $this->getTopOffset($elementRenderer);
		} else {
			if($elementCoreStyle->bottom != cocktail_core_style_PositionOffset::$cssAuto) {
				$elementRenderer->positionedOrigin->y = $this->getBottomOffset($elementRenderer, $containingBlockData->height);
			}
		}
	}
	public function layoutPositionedChild($elementRenderer, $firstPositionedAncestorData, $viewportData) {
		$»t = ($elementRenderer->coreStyle->computedStyle->position);
		switch($»t->index) {
		case 3:
		{
			$this->doLayoutPositionedChild($elementRenderer, $viewportData);
		}break;
		case 2:
		{
			$this->doLayoutPositionedChild($elementRenderer, $firstPositionedAncestorData);
		}break;
		default:{
		}break;
		}
	}
	public function layoutPositionedChildren() {
		$containerBlockData = $this->getContainerBlockData();
		$windowData = $this->getWindowData();
		$length = $this->_positionedChildren->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$this->layoutPositionedChild($this->_positionedChildren[$i], $containerBlockData, $windowData);
				unset($i);
			}
		}
	}
	public function layoutChildren() {
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				_hx_array_get($this->childNodes, $i)->layout($this->_childrenNeedLayout);
				unset($i);
			}
		}
	}
	public function getBoxStylesComputer() {
		$boxComputer = null;
		if($this->coreStyle->computedStyle->cssFloat == cocktail_core_style_CSSFloat::$left || $this->coreStyle->computedStyle->cssFloat == cocktail_core_style_CSSFloat::$right) {
			$boxComputer = new cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer();
		} else {
			if($this->coreStyle->computedStyle->position == cocktail_core_style_Position::$fixed || $this->coreStyle->computedStyle->position == cocktail_core_style_Position::$absolute) {
				$boxComputer = new cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer();
			} else {
				$»t = ($this->coreStyle->computedStyle->display);
				switch($»t->index) {
				case 0:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_BlockBoxStylesComputer();
				}break;
				case 1:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer();
				}break;
				case 3:
				{
					$boxComputer = null;
				}break;
				case 2:
				{
					$boxComputer = new cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer();
				}break;
				}
			}
		}
		return $boxComputer;
	}
	public function layout($forceLayout) {
		parent::layout($forceLayout);
		$this->layoutChildren();
		if($this->_positionedChildrenNeedLayout === true || $forceLayout === true) {
			if($this->isPositioned() === true) {
				$this->layoutPositionedChildren();
			}
			$this->_positionedChildrenNeedLayout = false;
		}
	}
	public function removePositionedChild($element) {
		$this->_positionedChildren->remove($element);
	}
	public function addPositionedChildren($element) {
		$this->_positionedChildren->push($element);
	}
	public function getLineBoxesInLine($rootLineBox) {
		$ret = new _hx_array(array());
		$length = $rootLineBox->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $rootLineBox->childNodes[$i];
				$ret->push($child);
				if($child->hasChildNodes() === true) {
					$childLineBoxes = $this->getLineBoxesInLine($child);
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
				unset($i,$child);
			}
		}
		return $ret;
	}
	public $_positionedChildren;
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
	function __toString() { return 'cocktail.core.renderer.FlowBoxRenderer'; }
}
