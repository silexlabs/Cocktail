<?php

class cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer extends cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function getComputedStaticTop($style, $containingBlockData) {
		return $style->computedStyle->getMarginTop();
	}
	public function getComputedStaticLeft($style, $containingBlockData) {
		return $style->computedStyle->getMarginLeft();
	}
	public function measureVerticalPositionOffsets($style, $containingBlockData, $fontMetrics) {
		$computedStyle = $style->computedStyle;
		if($style->top == cocktail_core_style_PositionOffset::$cssAuto || $style->bottom == cocktail_core_style_PositionOffset::$cssAuto) {
			if($style->marginTop == cocktail_core_style_Margin::$cssAuto) {
				$style->computedStyle->set_marginTop(0);
			}
			if($style->marginBottom == cocktail_core_style_Margin::$cssAuto) {
				$style->computedStyle->set_marginBottom(0);
			}
			if($style->top == cocktail_core_style_PositionOffset::$cssAuto && $style->bottom == cocktail_core_style_PositionOffset::$cssAuto) {
				$style->computedStyle->set_top($this->getComputedStaticTop($style, $containingBlockData));
				$style->computedStyle->set_bottom($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getMarginTop() - $computedStyle->getMarginBottom() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getTop());
			} else {
				if($style->top == cocktail_core_style_PositionOffset::$cssAuto) {
					$style->computedStyle->set_bottom($this->getComputedPositionOffset($style->bottom, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
					$style->computedStyle->set_top($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getMarginTop() - $computedStyle->getMarginBottom() - $computedStyle->getBottom() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom());
				} else {
					if($style->bottom == cocktail_core_style_PositionOffset::$cssAuto) {
						$style->computedStyle->set_top($this->getComputedPositionOffset($style->top, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
						$style->computedStyle->set_bottom($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getMarginTop() - $computedStyle->getMarginBottom() - $computedStyle->getTop() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom());
					} else {
						$style->computedStyle->set_top($this->getComputedPositionOffset($style->top, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
						$style->computedStyle->set_bottom($this->getComputedPositionOffset($style->bottom, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
					}
				}
			}
		} else {
			$style->computedStyle->set_top($this->getComputedPositionOffset($style->top, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
			$style->computedStyle->set_bottom($this->getComputedPositionOffset($style->bottom, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
			if($style->marginTop == cocktail_core_style_Margin::$cssAuto && $style->marginBottom == cocktail_core_style_Margin::$cssAuto) {
				$margin = ($containingBlockData->height - $computedStyle->getTop() - $computedStyle->getBottom() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom()) / 2;
				$computedMargin = ($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getTop() - $computedStyle->getBottom()) / 2;
				if($computedMargin >= 0) {
					$style->computedStyle->set_marginTop($computedMargin);
					$style->computedStyle->set_marginBottom($computedMargin);
				} else {
					$style->computedStyle->set_marginTop(0);
					$style->computedStyle->set_marginBottom($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getTop() - $computedStyle->getBottom());
				}
			} else {
				if($style->marginTop == cocktail_core_style_Margin::$cssAuto) {
					$style->computedStyle->set_marginTop($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getTop() - $computedStyle->getBottom() - $computedStyle->getMarginBottom());
				} else {
					if($style->marginBottom == cocktail_core_style_Margin::$cssAuto) {
						$style->computedStyle->set_marginBottom($containingBlockData->height - $computedStyle->getHeight() - $computedStyle->getPaddingTop() - $computedStyle->getPaddingBottom() - $computedStyle->getTop() - $computedStyle->getBottom() - $computedStyle->getMarginTop());
					}
				}
			}
		}
	}
	public function measureHorizontalPositionOffsets($style, $containingBlockData, $fontMetrics) {
		$computedStyle = $style->computedStyle;
		if($style->left == cocktail_core_style_PositionOffset::$cssAuto || $style->right == cocktail_core_style_PositionOffset::$cssAuto) {
			if($style->marginLeft == cocktail_core_style_Margin::$cssAuto) {
				$style->computedStyle->set_marginLeft(0);
			}
			if($style->marginRight == cocktail_core_style_Margin::$cssAuto) {
				$style->computedStyle->set_marginRight(0);
			}
			if($style->left == cocktail_core_style_PositionOffset::$cssAuto && $style->right == cocktail_core_style_PositionOffset::$cssAuto) {
				$style->computedStyle->set_left($this->getComputedStaticLeft($style, $containingBlockData));
				$style->computedStyle->set_right($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getMarginLeft() - $computedStyle->getMarginRight() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getLeft());
			} else {
				if($style->left == cocktail_core_style_PositionOffset::$cssAuto) {
					$style->computedStyle->set_right($this->getComputedPositionOffset($style->right, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
					$style->computedStyle->set_left($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getMarginLeft() - $computedStyle->getMarginRight() - $computedStyle->getRight() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight());
				} else {
					if($style->right == cocktail_core_style_PositionOffset::$cssAuto) {
						$style->computedStyle->set_left($this->getComputedPositionOffset($style->left, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
						$style->computedStyle->set_right($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getMarginLeft() - $computedStyle->getMarginRight() - $computedStyle->getLeft() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight());
					}
				}
			}
		} else {
			$style->computedStyle->set_left($this->getComputedPositionOffset($style->left, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
			$style->computedStyle->set_right($this->getComputedPositionOffset($style->right, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
			if($style->marginLeft == cocktail_core_style_Margin::$cssAuto && $style->marginRight == cocktail_core_style_Margin::$cssAuto) {
				$margin = ($containingBlockData->width - $computedStyle->getLeft() - $computedStyle->getRight() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight()) / 2;
				$computedMargin = ($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getLeft() - $computedStyle->getRight()) / 2;
				if($computedMargin >= 0) {
					$style->computedStyle->set_marginLeft($computedMargin);
					$style->computedStyle->set_marginRight($computedMargin);
				} else {
					$style->computedStyle->set_marginLeft(0);
					$style->computedStyle->set_marginRight($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getLeft() - $computedStyle->getRight());
				}
				$style->computedStyle->set_marginLeft(0);
			} else {
				if($style->marginLeft == cocktail_core_style_Margin::$cssAuto) {
					$style->computedStyle->set_marginLeft($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getLeft() - $computedStyle->getRight() - $computedStyle->getMarginRight());
				} else {
					if($style->marginRight == cocktail_core_style_Margin::$cssAuto) {
						$style->computedStyle->set_marginRight($containingBlockData->width - $computedStyle->getWidth() - $computedStyle->getPaddingLeft() - $computedStyle->getPaddingRight() - $computedStyle->getLeft() - $computedStyle->getRight() - $computedStyle->getMarginLeft());
					}
				}
			}
		}
	}
	public function measurePositionOffsets($style, $containingBlockData, $fontMetrics) {
		$this->measureHorizontalPositionOffsets($style, $containingBlockData, $fontMetrics);
		$this->measureVerticalPositionOffsets($style, $containingBlockData, $fontMetrics);
	}
	function __toString() { return 'cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer'; }
}
