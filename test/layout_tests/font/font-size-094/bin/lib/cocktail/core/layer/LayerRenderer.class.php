<?php

class cocktail_core_layer_LayerRenderer extends cocktail_core_dom_NodeBase {
	public function __construct($rootElementRenderer) {
		if(!php_Boot::$skip_constructor) {
		parent::__construct();
		$this->rootElementRenderer = $rootElementRenderer;
		$this->_zeroAndAutoZIndexChildLayerRenderers = new _hx_array(array());
		$this->_positiveZIndexChildLayerRenderers = new _hx_array(array());
		$this->_negativeZIndexChildLayerRenderers = new _hx_array(array());
		$this->hasOwnGraphicsContext = false;
		$this->_windowWidth = 0;
		$this->_windowHeight = 0;
	}}
	public function getChildRenderers() {
		$childRenderers = new _hx_array(array());
		{
			$_g1 = 0; $_g = $this->_negativeZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$childRenderer = $this->_negativeZIndexChildLayerRenderers[$i];
				$childRenderers->push($childRenderer->rootElementRenderer);
				unset($i,$childRenderer);
			}
		}
		{
			$_g1 = 0; $_g = $this->_zeroAndAutoZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$childRenderer = $this->_zeroAndAutoZIndexChildLayerRenderers[$i];
				$childRenderers->push($childRenderer->rootElementRenderer);
				unset($i,$childRenderer);
			}
		}
		{
			$_g1 = 0; $_g = $this->_positiveZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$childRenderer = $this->_positiveZIndexChildLayerRenderers[$i];
				$childRenderers->push($childRenderer->rootElementRenderer);
				unset($i,$childRenderer);
			}
		}
		return $childRenderers;
	}
	public function isWithinBounds($point, $bounds) {
		return $point->x >= $bounds->x && $point->x <= $bounds->x + $bounds->width && $point->y >= $bounds->y && $point->y <= $bounds->y + $bounds->height;
	}
	public function getElementRenderersAtPointInChildRenderers($point, $childRenderers, $scrollX, $scrollY) {
		$elementRenderersAtPointInChildRenderers = new _hx_array(array());
		$length = $childRenderers->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$elementRenderersAtPointInChildRenderer = new _hx_array(array());
				if(_hx_array_get($childRenderers, $i)->establishesNewStackingContext() === true) {
					if(_hx_array_get($childRenderers, $i)->isScrollBar() === true) {
						$elementRenderersAtPointInChildRenderer = _hx_array_get($childRenderers, $i)->layerRenderer->getElementRenderersAtPoint($point, $scrollX, $scrollY);
					} else {
						if(_hx_array_get($childRenderers, $i)->coreStyle->position == cocktail_core_style_Position::$fixed) {
							$elementRenderersAtPointInChildRenderer = _hx_array_get($childRenderers, $i)->layerRenderer->getElementRenderersAtPoint($point, $scrollX, $scrollY);
						} else {
							$elementRenderersAtPointInChildRenderer = _hx_array_get($childRenderers, $i)->layerRenderer->getElementRenderersAtPoint($point, $scrollX + $this->rootElementRenderer->get_scrollLeft(), $scrollY + $this->rootElementRenderer->get_scrollTop());
						}
					}
				}
				$childLength = $elementRenderersAtPointInChildRenderer->length;
				{
					$_g1 = 0;
					while($_g1 < $childLength) {
						$j = $_g1++;
						$elementRenderersAtPointInChildRenderers->push($elementRenderersAtPointInChildRenderer[$j]);
						unset($j);
					}
					unset($_g1);
				}
				unset($i,$elementRenderersAtPointInChildRenderer,$childLength);
			}
		}
		return $elementRenderersAtPointInChildRenderers;
	}
	public function getElementRenderersAtPointInLayer($renderer, $point, $scrollX, $scrollY) {
		$elementRenderersAtPointInLayer = new _hx_array(array());
		$scrolledPoint = _hx_anonymous(array("x" => $point->x + $scrollX, "y" => $point->y + $scrollY));
		if($this->isWithinBounds($scrolledPoint, $renderer->get_globalBounds()) === true) {
			$elementRenderersAtPointInLayer->push($renderer);
		}
		$scrollX += $renderer->get_scrollLeft();
		$scrollY += $renderer->get_scrollTop();
		$length = $renderer->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $renderer->childNodes[$i];
				if($child->layerRenderer === $this) {
					if($child->hasChildNodes() === true) {
						$childElementRenderersAtPointInLayer = $this->getElementRenderersAtPointInLayer($child, $point, $scrollX, $scrollY);
						$childLength = $childElementRenderersAtPointInLayer->length;
						{
							$_g1 = 0;
							while($_g1 < $childLength) {
								$j = $_g1++;
								$elementRenderersAtPointInLayer->push($childElementRenderersAtPointInLayer[$j]);
								unset($j);
							}
							unset($_g1);
						}
						unset($childLength,$childElementRenderersAtPointInLayer);
					} else {
						$scrolledPoint1 = _hx_anonymous(array("x" => $point->x + $scrollX, "y" => $point->y + $scrollY));
						if($this->isWithinBounds($scrolledPoint1, $child->get_globalBounds()) === true) {
							$elementRenderersAtPointInLayer->push($child);
						}
						unset($scrolledPoint1);
					}
				}
				unset($i,$child);
			}
		}
		return $elementRenderersAtPointInLayer;
	}
	public function getElementRenderersAtPoint($point, $scrollX, $scrollY) {
		$elementRenderersAtPoint = $this->getElementRenderersAtPointInLayer($this->rootElementRenderer, $point, $scrollX, $scrollY);
		if($this->rootElementRenderer->hasChildNodes() === true) {
			$childRenderers = $this->getChildRenderers();
			$elementRenderersAtPointInChildRenderers = $this->getElementRenderersAtPointInChildRenderers($point, $childRenderers, $scrollX, $scrollY);
			$length = $elementRenderersAtPointInChildRenderers->length;
			{
				$_g = 0;
				while($_g < $length) {
					$i = $_g++;
					$elementRenderersAtPoint->push($elementRenderersAtPointInChildRenderers[$i]);
					unset($i);
				}
			}
		}
		return $elementRenderersAtPoint;
	}
	public function getTopMostElementRendererAtPoint($point, $scrollX, $scrollY) {
		$elementRenderersAtPoint = $this->getElementRenderersAtPoint($point, $scrollX, $scrollY);
		$topMostElementRenderer = $elementRenderersAtPoint[$elementRenderersAtPoint->length - 1];
		return $topMostElementRenderer;
	}
	public function insertNegativeZIndexChildRenderer($childLayerRenderer, $rootElementRendererZIndex) {
		$newNegativeZIndexChildRenderers = new _hx_array(array());
		$isInserted = false;
		$length = $this->_negativeZIndexChildLayerRenderers->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$currentRendererZIndex = 0;
				$»t = (_hx_array_get($this->_negativeZIndexChildLayerRenderers, $i)->rootElementRenderer->coreStyle->computedStyle->zIndex);
				switch($»t->index) {
				case 1:
				$value = $»t->params[0];
				{
					$currentRendererZIndex = $value;
				}break;
				default:{
				}break;
				}
				if($currentRendererZIndex > $rootElementRendererZIndex && $isInserted === false) {
					$newNegativeZIndexChildRenderers->push($childLayerRenderer);
					$isInserted = true;
				}
				$newNegativeZIndexChildRenderers->push($this->_negativeZIndexChildLayerRenderers[$i]);
				unset($i,$currentRendererZIndex);
			}
		}
		if($isInserted === false) {
			$newNegativeZIndexChildRenderers->push($childLayerRenderer);
		}
		$this->_negativeZIndexChildLayerRenderers = $newNegativeZIndexChildRenderers;
	}
	public function insertPositiveZIndexChildRenderer($childLayerRenderer, $rootElementRendererZIndex) {
		$newPositiveZIndexChildRenderers = new _hx_array(array());
		$isInserted = false;
		$length = $this->_positiveZIndexChildLayerRenderers->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$currentRendererZIndex = 0;
				$»t = (_hx_array_get($this->_positiveZIndexChildLayerRenderers, $i)->rootElementRenderer->coreStyle->computedStyle->zIndex);
				switch($»t->index) {
				case 1:
				$value = $»t->params[0];
				{
					$currentRendererZIndex = $value;
				}break;
				default:{
				}break;
				}
				if($rootElementRendererZIndex < $currentRendererZIndex && $isInserted === false) {
					$newPositiveZIndexChildRenderers->push($childLayerRenderer);
					$isInserted = true;
				}
				$newPositiveZIndexChildRenderers->push($this->_positiveZIndexChildLayerRenderers[$i]);
				unset($i,$currentRendererZIndex);
			}
		}
		if($isInserted === false) {
			$newPositiveZIndexChildRenderers->push($childLayerRenderer);
		}
		$this->_positiveZIndexChildLayerRenderers = $newPositiveZIndexChildRenderers;
	}
	public function getRelativeOffset() {
		$relativeOffset = _hx_anonymous(array("x" => 0.0, "y" => 0.0));
		if($this->rootElementRenderer->isRelativePositioned() === true) {
			$coreStyle = $this->rootElementRenderer->coreStyle;
			if($coreStyle->left != cocktail_core_style_PositionOffset::$cssAuto) {
				$relativeOffset->x += $coreStyle->computedStyle->getLeft();
			} else {
				if($coreStyle->right != cocktail_core_style_PositionOffset::$cssAuto) {
					$relativeOffset->x -= $coreStyle->computedStyle->getRight();
				}
			}
			if($coreStyle->top != cocktail_core_style_PositionOffset::$cssAuto) {
				$relativeOffset->y += $coreStyle->computedStyle->getTop();
			} else {
				if($coreStyle->bottom != cocktail_core_style_PositionOffset::$cssAuto) {
					$relativeOffset->y -= $coreStyle->computedStyle->getBottom();
				}
			}
		}
		return $relativeOffset;
	}
	public function getConcatenatedMatrix($matrix, $relativeOffset) {
		$currentMatrix = new cocktail_core_geom_Matrix(null);
		$globalBounds = $this->rootElementRenderer->get_globalBounds();
		$currentMatrix->translate($globalBounds->x + $relativeOffset->x, $globalBounds->y + $relativeOffset->y);
		$currentMatrix->concatenate($matrix);
		$currentMatrix->translate(($globalBounds->x + $relativeOffset->x) * -1, ($globalBounds->y + $relativeOffset->y) * -1);
		return $currentMatrix;
	}
	public function getTransformationMatrix($graphicContext) {
		$relativeOffset = $this->getRelativeOffset();
		$concatenatedMatrix = $this->getConcatenatedMatrix($this->rootElementRenderer->coreStyle->computedStyle->transform, $relativeOffset);
		$concatenatedMatrix->translate($relativeOffset->x, $relativeOffset->y);
		return $concatenatedMatrix;
	}
	public function render($windowWidth, $windowHeight) {
		if($windowWidth !== $this->_windowWidth || $windowHeight !== $this->_windowHeight) {
			if($this->hasOwnGraphicsContext === true) {
				$this->graphicsContext->initBitmapData($windowWidth, $windowHeight);
			}
			$this->_windowWidth = $windowWidth;
			$this->_windowHeight = $windowHeight;
		}
		if($this->hasOwnGraphicsContext === true) {
			$this->graphicsContext->clear();
		}
		{
			$_g1 = 0; $_g = $this->_negativeZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				_hx_array_get($this->_negativeZIndexChildLayerRenderers, $i)->render($windowWidth, $windowHeight);
				unset($i);
			}
		}
		if($this->rootElementRenderer->isTransparent() === true) {
			$this->graphicsContext->beginTransparency($this->rootElementRenderer->coreStyle->computedStyle->getOpacity());
		}
		$this->rootElementRenderer->render($this->graphicsContext);
		if($this->rootElementRenderer->isTransparent() === true) {
			$this->graphicsContext->endTransparency();
		}
		{
			$_g1 = 0; $_g = $this->_zeroAndAutoZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				_hx_array_get($this->_zeroAndAutoZIndexChildLayerRenderers, $i)->render($windowWidth, $windowHeight);
				unset($i);
			}
		}
		{
			$_g1 = 0; $_g = $this->_positiveZIndexChildLayerRenderers->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				_hx_array_get($this->_positiveZIndexChildLayerRenderers, $i)->render($windowWidth, $windowHeight);
				unset($i);
			}
		}
		$this->rootElementRenderer->renderScrollBars($this->graphicsContext, $windowWidth, $windowHeight);
		if($this->rootElementRenderer->isTransformed() === true) {
			cocktail_core_style_computer_VisualEffectStylesComputer::compute($this->rootElementRenderer->coreStyle);
			$this->graphicsContext->transform($this->getTransformationMatrix($this->graphicsContext));
		}
	}
	public function establishesNewGraphicsContext() {
		return false;
	}
	public function createGraphicsContext($parentGraphicsContext) {
		if($this->establishesNewGraphicsContext() === true) {
			$this->graphicsContext = new cocktail_core_graphics_AbstractGraphicsContext($this, null);
			$parentGraphicsContext->appendChild($this->graphicsContext);
			$this->hasOwnGraphicsContext = true;
		} else {
			$this->graphicsContext = $parentGraphicsContext;
		}
	}
	public function detachGraphicsContext() {
		if($this->hasOwnGraphicsContext === true) {
			$this->parentNode->graphicsContext->removeChild($this->graphicsContext);
			$this->graphicsContext->dispose();
			$this->hasOwnGraphicsContext = false;
		}
		$this->graphicsContext = null;
	}
	public function attachGraphicsContext() {
		if($this->graphicsContext === null) {
			if($this->parentNode !== null) {
				if($this->parentNode->graphicsContext !== null) {
					$this->createGraphicsContext($this->parentNode->graphicsContext);
				}
			}
		}
	}
	public function detach() {
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $this->childNodes[$i];
				$child->detach();
				unset($i,$child);
			}
		}
		$this->detachGraphicsContext();
	}
	public function attach() {
		$this->attachGraphicsContext();
		$length = $this->childNodes->length;
		{
			$_g = 0;
			while($_g < $length) {
				$i = $_g++;
				$child = $this->childNodes[$i];
				$child->attach();
				unset($i,$child);
			}
		}
	}
	public function removeChild($oldChild) {
		$removed = false;
		$removed = $this->_zeroAndAutoZIndexChildLayerRenderers->remove($oldChild);
		if($removed === false) {
			$removed = $this->_positiveZIndexChildLayerRenderers->remove($oldChild);
			if($removed === false) {
				$this->_negativeZIndexChildLayerRenderers->remove($oldChild);
			}
		}
		$oldChild->detach();
		parent::removeChild($oldChild);
		return $oldChild;
	}
	public function appendChild($newChild) {
		parent::appendChild($newChild);
		$newChild->attach();
		$»t = ($newChild->rootElementRenderer->coreStyle->computedStyle->zIndex);
		switch($»t->index) {
		case 0:
		{
			$this->_zeroAndAutoZIndexChildLayerRenderers->push($newChild);
		}break;
		case 1:
		$value = $»t->params[0];
		{
			if($value === 0) {
				$this->_zeroAndAutoZIndexChildLayerRenderers->push($newChild);
			} else {
				if($value > 0) {
					$this->insertPositiveZIndexChildRenderer($newChild, $value);
				} else {
					if($value < 0) {
						$this->insertNegativeZIndexChildRenderer($newChild, $value);
					}
				}
			}
		}break;
		}
		return $newChild;
	}
	public $hasOwnGraphicsContext;
	public $_windowHeight;
	public $_windowWidth;
	public $graphicsContext;
	public $_negativeZIndexChildLayerRenderers;
	public $_positiveZIndexChildLayerRenderers;
	public $_zeroAndAutoZIndexChildLayerRenderers;
	public $rootElementRenderer;
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
	function __toString() { return 'cocktail.core.layer.LayerRenderer'; }
}
