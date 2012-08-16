<?php

class cocktail_core_style_formatter_FormattingContext {
	public function __construct($formattingContextRoot) {
		if(!php_Boot::$skip_constructor) {
		$this->_formattingContextRoot = $formattingContextRoot;
	}}
	public function applyShrinkToFitIfNeeded($elementRenderer, $minimumWidth) {
		$shrinkedWidth = $elementRenderer->coreStyle->computedStyle->getWidth();
		if($elementRenderer->coreStyle->width == cocktail_core_style_Dimension::$cssAuto) {
			if($elementRenderer->isFloat() === true || $elementRenderer->coreStyle->computedStyle->display == cocktail_core_style_Display::$inlineBlock) {
				$shrinkedWidth = $minimumWidth;
			} else {
				if($elementRenderer->isPositioned() === true && $elementRenderer->isRelativePositioned() === false) {
					$style = $elementRenderer->coreStyle;
					if($style->left == cocktail_core_style_PositionOffset::$cssAuto || $style->right == cocktail_core_style_PositionOffset::$cssAuto) {
						$computedStyle = $style->computedStyle;
						$shrinkedWidth = $minimumWidth;
					}
				}
			}
		} else {
			$shrinkedWidth = $elementRenderer->coreStyle->computedStyle->getWidth();
		}
		$elementRenderer->coreStyle->computedStyle->set_width($shrinkedWidth);
	}
	public function startFormatting() {
	}
	public function format($floatsManager) {
		$this->_floatsManager = $floatsManager;
		$this->initFormattingContextData();
		$this->startFormatting();
		$this->applyShrinkToFitIfNeeded($this->_formattingContextRoot, $this->_formattingContextData->width);
	}
	public function initFormattingContextData() {
		$x = $this->_formattingContextRoot->coreStyle->computedStyle->getPaddingLeft();
		$y = $this->_formattingContextRoot->coreStyle->computedStyle->getPaddingTop();
		$this->_formattingContextData = _hx_anonymous(array("x" => $x, "y" => $y, "height" => 0.0, "width" => 0.0));
	}
	public $_formattingContextData;
	public $_floatsManager;
	public $_formattingContextRoot;
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
	function __toString() { return 'cocktail.core.style.formatter.FormattingContext'; }
}
