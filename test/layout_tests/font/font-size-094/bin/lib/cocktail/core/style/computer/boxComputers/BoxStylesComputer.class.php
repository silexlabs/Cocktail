<?php

class cocktail_core_style_computer_boxComputers_BoxStylesComputer {
	public function __construct() { 
	}
	public function constrainHeight($style, $computedHeight) {
		$computedStyle = $style->computedStyle;
		if($style->maxHeight != cocktail_core_style_ConstrainedDimension::$none) {
			if($computedHeight > $computedStyle->getMaxHeight()) {
				$computedHeight = $computedStyle->getMaxHeight();
			}
		}
		if($computedHeight < $computedStyle->getMinHeight()) {
			$computedHeight = $computedStyle->getMinHeight();
		}
		return $computedHeight;
	}
	public function constrainWidth($style, $computedWidth) {
		$computedStyle = $style->computedStyle;
		if($style->maxWidth != cocktail_core_style_ConstrainedDimension::$none) {
			if($computedWidth > $computedStyle->getMaxWidth()) {
				$computedWidth = $computedStyle->getMaxWidth();
			}
		}
		if($computedWidth < $computedStyle->getMinWidth()) {
			$computedWidth = $computedStyle->getMinWidth();
		}
		return $computedWidth;
	}
	public function getComputedPadding($paddingStyleValue, $containingHTMLElementDimension, $fontSize, $xHeight) {
		$computedPaddingValue = null;
		$퍁 = ($paddingStyleValue);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedPaddingValue = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontSize, $xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$computedPaddingValue = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingHTMLElementDimension);
		}break;
		}
		return $computedPaddingValue;
	}
	public function getComputedDimension($dimensionStyleValue, $containingHTMLElementDimension, $isContainingDimensionAuto, $fontSize, $xHeight) {
		$computedDimensions = null;
		$퍁 = ($dimensionStyleValue);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedDimensions = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontSize, $xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$computedDimensions = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingHTMLElementDimension);
		}break;
		case 2:
		{
			$computedDimensions = 0;
		}break;
		}
		return $computedDimensions;
	}
	public function getComputedPositionOffset($positionOffsetStyleValue, $containingHTMLElementDimension, $fontSize, $xHeight) {
		$computedPositionOffset = null;
		$퍁 = ($positionOffsetStyleValue);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedPositionOffset = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontSize, $xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$computedPositionOffset = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingHTMLElementDimension);
		}break;
		case 2:
		{
			$computedPositionOffset = 0.0;
		}break;
		}
		return $computedPositionOffset;
	}
	public function getComputedConstrainedDimension($constrainedDimension, $containingHTMLElementDimension, $isContainingDimensionAuto, $fontSize, $xHeight, $isMinConstraint = null) {
		if($isMinConstraint === null) {
			$isMinConstraint = false;
		}
		$computedConstraintDimension = null;
		$퍁 = ($constrainedDimension);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedConstraintDimension = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontSize, $xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			if($isContainingDimensionAuto === true) {
				if($isMinConstraint === true) {
					$computedConstraintDimension = 0;
				} else {
					$computedConstraintDimension = Math::$POSITIVE_INFINITY;
				}
			} else {
				$computedConstraintDimension = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingHTMLElementDimension);
			}
		}break;
		case 2:
		{
			if($isMinConstraint === true) {
				$computedConstraintDimension = 0.0;
			} else {
				$computedConstraintDimension = Math::$POSITIVE_INFINITY;
			}
		}break;
		}
		return $computedConstraintDimension;
	}
	public function getComputedAutoMargin($marginStyleValue, $opositeMargin, $containingHTMLElementDimension, $computedDimension, $isDimensionAuto, $computedPaddingsDimension, $fontSize, $xHeight, $isHorizontalMargin) {
		$computedMargin = null;
		if($isHorizontalMargin === false || $isDimensionAuto === true) {
			$computedMargin = 0.0;
		} else {
			$퍁 = ($opositeMargin);
			switch($퍁->index) {
			case 2:
			{
				$computedMargin = ($containingHTMLElementDimension - $computedDimension - $computedPaddingsDimension) / 2;
			}break;
			default:{
				$opositeComputedMargin = $this->getComputedMargin($opositeMargin, $marginStyleValue, $containingHTMLElementDimension, $computedDimension, $isDimensionAuto, $computedPaddingsDimension, $fontSize, $xHeight, $isHorizontalMargin);
				$computedMargin = $containingHTMLElementDimension - $computedDimension - $computedPaddingsDimension - $opositeComputedMargin;
			}break;
			}
		}
		return $computedMargin;
	}
	public function getComputedMargin($marginStyleValue, $opositeMargin, $containingHTMLElementDimension, $computedDimension, $isDimensionAuto, $computedPaddingsDimension, $fontSize, $xHeight, $isHorizontalMargin) {
		$computedMargin = null;
		$퍁 = ($marginStyleValue);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedMargin = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontSize, $xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			if($isDimensionAuto === true) {
				$computedMargin = 0.0;
			} else {
				$computedMargin = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingHTMLElementDimension);
			}
		}break;
		case 2:
		{
			$computedMargin = $this->getComputedAutoMargin($marginStyleValue, $opositeMargin, $containingHTMLElementDimension, $computedDimension, $isDimensionAuto, $computedPaddingsDimension, $fontSize, $xHeight, $isHorizontalMargin);
		}break;
		}
		return $computedMargin;
	}
	public function getComputedMarginBottom($style, $computedHeight, $containingBlockData, $fontMetrics) {
		return $this->getComputedMargin($style->marginBottom, $style->marginTop, $containingBlockData->height, $computedHeight, $style->height == cocktail_core_style_Dimension::$cssAuto, $style->computedStyle->getPaddingTop() + $style->computedStyle->getPaddingBottom(), $fontMetrics->fontSize, $fontMetrics->xHeight, false);
	}
	public function getComputedMarginTop($style, $computedHeight, $containingBlockData, $fontMetrics) {
		return $this->getComputedMargin($style->marginTop, $style->marginBottom, $containingBlockData->height, $computedHeight, $style->height == cocktail_core_style_Dimension::$cssAuto, $style->computedStyle->getPaddingTop() + $style->computedStyle->getPaddingBottom(), $fontMetrics->fontSize, $fontMetrics->xHeight, false);
	}
	public function getComputedMarginRight($style, $computedWidth, $containingBlockData, $fontMetrics) {
		return $this->getComputedMargin($style->marginRight, $style->marginLeft, $containingBlockData->width, $computedWidth, $style->width == cocktail_core_style_Dimension::$cssAuto, $style->computedStyle->getPaddingRight() + $style->computedStyle->getPaddingLeft(), $fontMetrics->fontSize, $fontMetrics->xHeight, true);
	}
	public function getComputedMarginLeft($style, $computedWidth, $containingBlockData, $fontMetrics) {
		return $this->getComputedMargin($style->marginLeft, $style->marginRight, $containingBlockData->width, $computedWidth, $style->width == cocktail_core_style_Dimension::$cssAuto, $style->computedStyle->getPaddingRight() + $style->computedStyle->getPaddingLeft(), $fontMetrics->fontSize, $fontMetrics->xHeight, true);
	}
	public function getComputedAutoHeight($style, $containingBlockData, $fontMetrics) {
		return 0;
	}
	public function getComputedHeight($style, $containingBlockData, $fontMetrics) {
		return $this->getComputedDimension($style->height, $containingBlockData->height, $containingBlockData->isHeightAuto, $fontMetrics->fontSize, $fontMetrics->xHeight);
	}
	public function getComputedAutoWidth($style, $containingBlockData, $fontMetrics) {
		return $containingBlockData->width - $style->computedStyle->getPaddingLeft() - $style->computedStyle->getPaddingRight() - $style->computedStyle->getMarginLeft() - $style->computedStyle->getMarginRight();
	}
	public function getComputedWidth($style, $containingBlockData, $fontMetrics) {
		return $this->getComputedDimension($style->width, $containingBlockData->width, $containingBlockData->isWidthAuto, $fontMetrics->fontSize, $fontMetrics->xHeight);
	}
	public function measureHeight($style, $containingBlockData, $fontMetrics) {
		$computedHeight = $this->getComputedHeight($style, $containingBlockData, $fontMetrics);
		$style->computedStyle->set_marginTop($this->getComputedMarginTop($style, $computedHeight, $containingBlockData, $fontMetrics));
		$style->computedStyle->set_marginBottom($this->getComputedMarginBottom($style, $computedHeight, $containingBlockData, $fontMetrics));
		return $computedHeight;
	}
	public function measureAutoHeight($style, $containingBlockData, $fontMetrics) {
		$computedHeight = $this->getComputedAutoHeight($style, $containingBlockData, $fontMetrics);
		$style->computedStyle->set_marginTop($this->getComputedMarginTop($style, $computedHeight, $containingBlockData, $fontMetrics));
		$style->computedStyle->set_marginBottom($this->getComputedMarginBottom($style, $computedHeight, $containingBlockData, $fontMetrics));
		return $computedHeight;
	}
	public function measureHeightAndVerticalMargins($style, $containingBlockData, $fontMetrics) {
		if($style->height == cocktail_core_style_Dimension::$cssAuto) {
			return $this->measureAutoHeight($style, $containingBlockData, $fontMetrics);
		} else {
			return $this->measureHeight($style, $containingBlockData, $fontMetrics);
		}
	}
	public function measureWidth($style, $containingBlockData, $fontMetrics) {
		$computedWidth = $this->getComputedWidth($style, $containingBlockData, $fontMetrics);
		$style->computedStyle->set_marginLeft($this->getComputedMarginLeft($style, $computedWidth, $containingBlockData, $fontMetrics));
		$style->computedStyle->set_marginRight($this->getComputedMarginRight($style, $computedWidth, $containingBlockData, $fontMetrics));
		return $computedWidth;
	}
	public function measureAutoWidth($style, $containingBlockData, $fontMetrics) {
		$computedWidth = 0.0;
		$style->computedStyle->set_marginLeft($this->getComputedMarginLeft($style, $computedWidth, $containingBlockData, $fontMetrics));
		$style->computedStyle->set_marginRight($this->getComputedMarginRight($style, $computedWidth, $containingBlockData, $fontMetrics));
		return $this->getComputedAutoWidth($style, $containingBlockData, $fontMetrics);
	}
	public function measureWidthAndHorizontalMargins($style, $containingBlockData, $fontMetrics) {
		if($style->width == cocktail_core_style_Dimension::$cssAuto) {
			return $this->measureAutoWidth($style, $containingBlockData, $fontMetrics);
		} else {
			return $this->measureWidth($style, $containingBlockData, $fontMetrics);
		}
	}
	public function measureHorizontalPaddings($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_paddingLeft($this->getComputedPadding($style->paddingLeft, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
		$style->computedStyle->set_paddingRight($this->getComputedPadding($style->paddingRight, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
	}
	public function measureVerticalPaddings($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_paddingTop($this->getComputedPadding($style->paddingTop, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
		$style->computedStyle->set_paddingBottom($this->getComputedPadding($style->paddingBottom, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
	}
	public function measureDimensionsAndMargins($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_width($this->constrainWidth($style, $this->measureWidthAndHorizontalMargins($style, $containingBlockData, $fontMetrics)));
		$style->computedStyle->set_height($this->constrainHeight($style, $this->measureHeightAndVerticalMargins($style, $containingBlockData, $fontMetrics)));
	}
	public function measurePositionOffsets($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_left($this->getComputedPositionOffset($style->left, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
		$style->computedStyle->set_right($this->getComputedPositionOffset($style->right, $containingBlockData->width, $fontMetrics->fontSize, $fontMetrics->xHeight));
		$style->computedStyle->set_top($this->getComputedPositionOffset($style->top, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
		$style->computedStyle->set_bottom($this->getComputedPositionOffset($style->bottom, $containingBlockData->height, $fontMetrics->fontSize, $fontMetrics->xHeight));
	}
	public function measureDimensionsConstraints($style, $containingBlockData, $fontMetrics) {
		$style->computedStyle->set_maxHeight($this->getComputedConstrainedDimension($style->maxHeight, $containingBlockData->height, $containingBlockData->isHeightAuto, $fontMetrics->fontSize, $fontMetrics->xHeight, null));
		$style->computedStyle->set_minHeight($this->getComputedConstrainedDimension($style->minHeight, $containingBlockData->height, $containingBlockData->isHeightAuto, $fontMetrics->fontSize, $fontMetrics->xHeight, true));
		$style->computedStyle->set_maxWidth($this->getComputedConstrainedDimension($style->maxWidth, $containingBlockData->width, $containingBlockData->isWidthAuto, $fontMetrics->fontSize, $fontMetrics->xHeight, null));
		$style->computedStyle->set_minWidth($this->getComputedConstrainedDimension($style->minWidth, $containingBlockData->width, $containingBlockData->isWidthAuto, $fontMetrics->fontSize, $fontMetrics->xHeight, true));
	}
	public function measure($style, $containingBlockData) {
		$fontMetrics = $style->get_fontMetricsData();
		$this->measureHorizontalPaddings($style, $containingBlockData, $fontMetrics);
		$this->measureVerticalPaddings($style, $containingBlockData, $fontMetrics);
		$this->measureDimensionsConstraints($style, $containingBlockData, $fontMetrics);
		$this->measureDimensionsAndMargins($style, $containingBlockData, $fontMetrics);
		$this->measurePositionOffsets($style, $containingBlockData, $fontMetrics);
	}
	function __toString() { return 'cocktail.core.style.computer.boxComputers.BoxStylesComputer'; }
}
