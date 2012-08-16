<?php

class cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer extends cocktail_core_style_computer_boxComputers_BoxStylesComputer {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function getComputedHeight($style, $containingBlockData, $fontMetrics) {
		return 0.0;
	}
	public function getComputedWidth($style, $containingBlockData, $fontMetrics) {
		return 0.0;
	}
	public function getComputedAutoMargin($marginStyleValue, $opositeMargin, $containingHTMLElementDimension, $computedDimension, $isDimensionAuto, $computedPaddingsDimension, $fontSize, $xHeight, $isHorizontalMargin) {
		return 0.0;
	}
	public function measureHeight($style, $containingBlockData, $fontMetrics) {
		$computedHeight = $this->getComputedHeight($style, $containingBlockData, $fontMetrics);
		$style->computedStyle->set_marginTop(0.0);
		$style->computedStyle->set_marginBottom(0.0);
		return $computedHeight;
	}
	public function measureAutoHeight($style, $containingBlockData, $fontMetrics) {
		$computedHeight = $this->getComputedAutoHeight($style, $containingBlockData, $fontMetrics);
		$style->computedStyle->set_marginTop(0.0);
		$style->computedStyle->set_marginBottom(0.0);
		return $computedHeight;
	}
	public function measureVerticalPaddings($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_paddingTop(0);
		$style->computedStyle->set_paddingBottom(0);
	}
	function __toString() { return 'cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer'; }
}
