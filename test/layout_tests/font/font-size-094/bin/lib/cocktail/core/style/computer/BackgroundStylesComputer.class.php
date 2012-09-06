<?php

class cocktail_core_style_computer_BackgroundStylesComputer {
	public function __construct() { 
	}
	static function compute($style) {
		$style->computedStyle->backgroundColor = cocktail_core_style_computer_BackgroundStylesComputer::getComputedBackgroundColor($style);
	}
	static function computeIndividualBackground($style, $backgroundBox, $intrinsicWidth, $intrinsicHeight, $intrinsicRatio, $backgroundPosition, $backgroundSize, $backgroundOrigin, $backgroundClip, $backgroundRepeat, $backgroundImage) {
		$fontMetrics = $style->get_fontMetricsData();
		$backgroundPositioningArea = cocktail_core_style_computer_BackgroundStylesComputer::getBackgroundPositioningArea($style, $backgroundOrigin, $backgroundBox);
		$computedBackgroundSize = cocktail_core_style_computer_BackgroundStylesComputer::getComputedBackgroundSize($backgroundSize, $backgroundPositioningArea, $intrinsicWidth, $intrinsicHeight, $intrinsicRatio, $fontMetrics->fontSize, $fontMetrics->xHeight);
		$computedBackgroundPosition = cocktail_core_style_computer_BackgroundStylesComputer::getComputedBackgroundPosition($backgroundPosition, $backgroundPositioningArea, $computedBackgroundSize, $fontMetrics->fontSize, $fontMetrics->xHeight);
		$computedBackgroundClip = cocktail_core_style_computer_BackgroundStylesComputer::getBackgroundPaintingArea($style, $backgroundClip, $backgroundBox);
		$computedBackgroundStyle = _hx_anonymous(array("backgroundOrigin" => $backgroundPositioningArea, "backgroundClip" => $computedBackgroundClip, "backgroundRepeat" => $backgroundRepeat, "backgroundImage" => $backgroundImage, "backgroundSize" => $computedBackgroundSize, "backgroundPosition" => $computedBackgroundPosition));
		return $computedBackgroundStyle;
	}
	static function getComputedBackgroundColor($style) {
		$computedColor = null;
		$computedColor = cocktail_core_unit_UnitManager::getColorDataFromCSSColor($style->backgroundColor);
		return $computedColor;
	}
	static function getComputedBackgroundPosition($backgroundPosition, $backgroundPositioningArea, $computedBackgroundSize, $emReference, $exReference) {
		$computedBackgroundXPosition = cocktail_core_style_computer_BackgroundStylesComputer::getComputedBackgroundXPosition($backgroundPosition->x, $backgroundPositioningArea->width, $computedBackgroundSize->width, $emReference, $exReference);
		$computedBackgroundYPosition = cocktail_core_style_computer_BackgroundStylesComputer::getComputedBackgroundYPosition($backgroundPosition->y, $backgroundPositioningArea->height, $computedBackgroundSize->height, $emReference, $exReference);
		$computedBackgroundPosition = _hx_anonymous(array("x" => $computedBackgroundXPosition, "y" => $computedBackgroundYPosition));
		return $computedBackgroundPosition;
	}
	static function getComputedBackgroundXPosition($backgroundPosition, $backgroundPositioningAreaDimension, $imageDimension, $emReference, $exReference) {
		$computedBackgroundXPosition = null;
		$퍁 = ($backgroundPosition);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedBackgroundXPosition = cocktail_core_unit_UnitManager::getPixelFromLength($value, $emReference, $exReference);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$computedBackgroundXPosition = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 3:
		{
			$computedBackgroundXPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(50, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 2:
		{
			$computedBackgroundXPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(0, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 4:
		{
			$computedBackgroundXPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(100, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		}
		return $computedBackgroundXPosition;
	}
	static function getComputedBackgroundYPosition($backgroundPosition, $backgroundPositioningAreaDimension, $imageDimension, $emReference, $exReference) {
		$computedBackgroundYPosition = null;
		$퍁 = ($backgroundPosition);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$computedBackgroundYPosition = cocktail_core_unit_UnitManager::getPixelFromLength($value, $emReference, $exReference);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$computedBackgroundYPosition = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 3:
		{
			$computedBackgroundYPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(50, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 2:
		{
			$computedBackgroundYPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(0, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		case 4:
		{
			$computedBackgroundYPosition = cocktail_core_unit_UnitManager::getPixelFromPercent(100, $backgroundPositioningAreaDimension - $imageDimension);
		}break;
		}
		return $computedBackgroundYPosition;
	}
	static function getComputedBackgroundSize($backgroundSize, $backgroundPositioningArea, $intrinsicWidth, $intrinsicHeight, $intrinsicRatio, $emReference, $exReference) {
		$computedBackgroundSize = null;
		$퍁 = ($backgroundSize);
		switch($퍁->index) {
		case 0:
		{
			if($intrinsicRatio !== null) {
				$ratio = $intrinsicRatio / ($backgroundPositioningArea->width / $backgroundPositioningArea->height);
				$computedBackgroundSize = _hx_anonymous(array("width" => $intrinsicWidth * $ratio, "height" => $intrinsicHeight * $ratio));
			} else {
				$computedBackgroundSize = _hx_anonymous(array("width" => $backgroundPositioningArea->width, "height" => $backgroundPositioningArea->height));
			}
		}break;
		case 1:
		{
			if($intrinsicRatio !== null) {
				$ratio = $backgroundPositioningArea->width / $backgroundPositioningArea->height / $intrinsicRatio;
				$computedBackgroundSize = _hx_anonymous(array("width" => $intrinsicWidth * $ratio, "height" => $intrinsicHeight * $ratio));
			} else {
				$computedBackgroundSize = _hx_anonymous(array("width" => $backgroundPositioningArea->width, "height" => $backgroundPositioningArea->height));
			}
		}break;
		case 2:
		$value = $퍁->params[0];
		{
			$computedBackgroundSize = _hx_anonymous(array("width" => cocktail_core_style_computer_BackgroundStylesComputer::getBackgroundSizeStyleDimensionData($value->x, $value->y, $backgroundPositioningArea->width, $backgroundPositioningArea->height, $intrinsicWidth, $intrinsicHeight, $intrinsicRatio, $emReference, $exReference), "height" => cocktail_core_style_computer_BackgroundStylesComputer::getBackgroundSizeStyleDimensionData($value->y, $value->x, $backgroundPositioningArea->height, $backgroundPositioningArea->width, $intrinsicHeight, $intrinsicWidth, $intrinsicRatio, $emReference, $exReference)));
		}break;
		}
		return $computedBackgroundSize;
	}
	static function getBackgroundSizeStyleDimensionData($value, $opositeBackgroundSizeValue, $backgroundPositioningAreaDimension, $opositeBackgroundAreaDimension, $intrinsicDimension, $opositeIntrinsicDimension, $intrinsicRatio, $emReference, $exReference) {
		$backgroundSizeStyleDimension = null;
		$퍁 = ($value);
		switch($퍁->index) {
		case 0:
		$value1 = $퍁->params[0];
		{
			$backgroundSizeStyleDimension = cocktail_core_unit_UnitManager::getPixelFromLength($value1, $emReference, $exReference);
		}break;
		case 1:
		$value1 = $퍁->params[0];
		{
			$backgroundSizeStyleDimension = cocktail_core_unit_UnitManager::getPixelFromPercent($value1, $backgroundPositioningAreaDimension);
		}break;
		case 2:
		{
			if($intrinsicDimension !== null && $opositeBackgroundSizeValue === cocktail_core_style_BackgroundSizeDimension::$cssAuto) {
				$backgroundSizeStyleDimension = $intrinsicDimension;
			} else {
				if($opositeIntrinsicDimension !== null && $intrinsicRatio !== null) {
					$opositeDimension = cocktail_core_style_computer_BackgroundStylesComputer::getBackgroundSizeStyleDimensionData($opositeBackgroundSizeValue, $value, $opositeBackgroundAreaDimension, $backgroundPositioningAreaDimension, $opositeIntrinsicDimension, $intrinsicDimension, $intrinsicRatio, $emReference, $exReference);
					$backgroundSizeStyleDimension = $opositeDimension * $intrinsicRatio;
				} else {
					$backgroundSizeStyleDimension = cocktail_core_unit_UnitManager::getPixelFromPercent(100, $backgroundPositioningAreaDimension);
				}
			}
		}break;
		}
		return $backgroundSizeStyleDimension;
	}
	static function getBackgroundPositioningArea($style, $backgroundOrigin, $backgroundBox) {
		$backgroundPositioningArea = null;
		$height = null;
		$width = null;
		$x = null;
		$y = null;
		$퍁 = ($backgroundOrigin);
		switch($퍁->index) {
		case 0:
		{
			$height = $backgroundBox->height;
			$width = $backgroundBox->width;
			$x = 0.0;
			$y = 0.0;
		}break;
		case 1:
		{
			$height = $backgroundBox->height;
			$width = $backgroundBox->width;
			$x = 0.0;
			$y = 0.0;
		}break;
		case 2:
		{
			$height = $backgroundBox->height - $style->computedStyle->getMarginTop() - $style->computedStyle->getMarginBottom() - $style->computedStyle->getPaddingTop() - $style->computedStyle->getPaddingBottom();
			$width = $backgroundBox->width - $style->computedStyle->getMarginLeft() - $style->computedStyle->getMarginRight() - $style->computedStyle->getPaddingLeft() - $style->computedStyle->getPaddingRight();
			$x = 0.0;
			$y = 0.0;
		}break;
		}
		$backgroundPositioningArea = _hx_anonymous(array("height" => $height, "width" => $width, "x" => $x, "y" => $y));
		return $backgroundPositioningArea;
	}
	static function getBackgroundPaintingArea($style, $backgroundClip, $backgroundBox) {
		$backgroundPaintingArea = null;
		$height = null;
		$width = null;
		$x = null;
		$y = null;
		$퍁 = ($backgroundClip);
		switch($퍁->index) {
		case 0:
		{
			$height = $backgroundBox->height;
			$width = $backgroundBox->width;
			$x = 0.0;
			$y = 0.0;
		}break;
		case 1:
		{
			$height = $backgroundBox->height;
			$width = $backgroundBox->width;
			$x = $style->computedStyle->getMarginLeft();
			$y = $style->computedStyle->getMarginTop();
		}break;
		case 2:
		{
			$height = $backgroundBox->height - $style->computedStyle->getMarginTop() - $style->computedStyle->getMarginBottom() - $style->computedStyle->getPaddingTop() - $style->computedStyle->getPaddingBottom();
			$width = $backgroundBox->width - $style->computedStyle->getMarginLeft() - $style->computedStyle->getMarginRight() - $style->computedStyle->getPaddingLeft() - $style->computedStyle->getPaddingRight();
			$x = $style->computedStyle->getMarginLeft() + $style->computedStyle->getPaddingLeft();
			$y = $style->computedStyle->getMarginTop() + $style->computedStyle->getPaddingTop();
		}break;
		}
		$backgroundPaintingArea = _hx_anonymous(array("height" => $height, "width" => $width, "x" => $x, "y" => $y));
		return $backgroundPaintingArea;
	}
	function __toString() { return 'cocktail.core.style.computer.BackgroundStylesComputer'; }
}
