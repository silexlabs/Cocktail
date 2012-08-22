<?php

class cocktail_core_style_computer_VisualEffectStylesComputer {
	public function __construct() { 
	}
	static function compute($style) {
		$computedStyle = $style->computedStyle;
		$fontMetrics = $style->get_fontMetricsData();
		$computedStyle->transformOrigin = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTransformOrigin($style, $fontMetrics);
		$computedStyle->transform = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTransform($style, $fontMetrics);
	}
	static function getComputedTransformOrigin($style, $fontMetrics) {
		$x = null;
		$y = null;
		$�t = ($style->transformOrigin->x);
		switch($�t->index) {
		case 0:
		$value = $�t->params[0];
		{
			$x = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		case 1:
		$value = $�t->params[0];
		{
			$x = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $style->computedStyle->getWidth());
		}break;
		case 2:
		{
			$x = cocktail_core_unit_UnitManager::getPixelFromPercent(0, $style->computedStyle->getWidth());
		}break;
		case 3:
		{
			$x = cocktail_core_unit_UnitManager::getPixelFromPercent(50, $style->computedStyle->getWidth());
		}break;
		case 4:
		{
			$x = cocktail_core_unit_UnitManager::getPixelFromPercent(100, $style->computedStyle->getWidth());
		}break;
		}
		$�t = ($style->transformOrigin->y);
		switch($�t->index) {
		case 0:
		$value = $�t->params[0];
		{
			$y = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		case 1:
		$value = $�t->params[0];
		{
			$y = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $style->computedStyle->getWidth());
		}break;
		case 2:
		{
			$y = cocktail_core_unit_UnitManager::getPixelFromPercent(0, $style->computedStyle->getWidth());
		}break;
		case 3:
		{
			$y = cocktail_core_unit_UnitManager::getPixelFromPercent(50, $style->computedStyle->getWidth());
		}break;
		case 4:
		{
			$y = cocktail_core_unit_UnitManager::getPixelFromPercent(100, $style->computedStyle->getWidth());
		}break;
		}
		$transformOriginPoint = _hx_anonymous(array("x" => $x, "y" => $y));
		return $transformOriginPoint;
	}
	static function getComputedTransform($style, $fontMetrics) {
		$transformFunctions = null;
		$transformOrigin = $style->computedStyle->transformOrigin;
		$matrix = new cocktail_core_geom_Matrix(null);
		$�t = ($style->transform);
		switch($�t->index) {
		case 1:
		$value = $�t->params[0];
		{
			$transformFunctions = $value;
		}break;
		case 0:
		{
			$transformFunctions = new _hx_array(array());
		}break;
		}
		$matrix->translate($transformOrigin->x, $transformOrigin->y);
		{
			$_g1 = 0; $_g = $transformFunctions->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$transformFunction = $transformFunctions[$i];
				$�t = ($transformFunction);
				switch($�t->index) {
				case 0:
				$data = $�t->params[0];
				{
					$matrix->concatenate(new cocktail_core_geom_Matrix($data));
				}break;
				case 7:
				$value = $�t->params[0];
				{
					$angle = cocktail_core_unit_UnitManager::getRadFromAngle($value);
					$matrix->rotate($angle);
				}break;
				case 4:
				$sy = $�t->params[1]; $sx = $�t->params[0];
				{
					$matrix->scale($sx, $sy);
				}break;
				case 5:
				$sx = $�t->params[0];
				{
					$matrix->scale($sx, 1);
				}break;
				case 6:
				$sy = $�t->params[0];
				{
					$matrix->scale(1, $sy);
				}break;
				case 10:
				$angleY = $�t->params[1]; $angleX = $�t->params[0];
				{
					$skewX = cocktail_core_unit_UnitManager::getRadFromAngle($angleX);
					$skewY = cocktail_core_unit_UnitManager::getRadFromAngle($angleY);
					$matrix->skew($skewX, $skewY);
				}break;
				case 8:
				$angleX = $�t->params[0];
				{
					$skewX = cocktail_core_unit_UnitManager::getRadFromAngle($angleX);
					$matrix->skew($skewX, 0);
				}break;
				case 9:
				$angleY = $�t->params[0];
				{
					$skewY = cocktail_core_unit_UnitManager::getRadFromAngle($angleY);
					$matrix->skew(0, $skewY);
				}break;
				case 1:
				$ty = $�t->params[1]; $tx = $�t->params[0];
				{
					$translationX = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTranslation($style, $tx, $style->computedStyle->getWidth(), $fontMetrics);
					$translationY = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTranslation($style, $ty, $style->computedStyle->getHeight(), $fontMetrics);
					$matrix->translate($translationX, $translationY);
				}break;
				case 2:
				$tx = $�t->params[0];
				{
					$translationX = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTranslation($style, $tx, $style->computedStyle->getWidth(), $fontMetrics);
					$matrix->translate($translationX, 0.0);
				}break;
				case 3:
				$ty = $�t->params[0];
				{
					$translationY = cocktail_core_style_computer_VisualEffectStylesComputer::getComputedTranslation($style, $ty, $style->computedStyle->getHeight(), $fontMetrics);
					$matrix->translate(0.0, $translationY);
				}break;
				}
				unset($transformFunction,$i);
			}
		}
		$matrix->translate($transformOrigin->x * -1, $transformOrigin->y * -1);
		return $matrix;
	}
	static function getComputedTranslation($style, $translation, $percentReference, $fontMetrics) {
		$computedTranslation = null;
		$�t = ($translation);
		switch($�t->index) {
		case 0:
		$value = $�t->params[0];
		{
			$computedTranslation = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		case 1:
		$value = $�t->params[0];
		{
			$computedTranslation = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $percentReference);
		}break;
		}
		return $computedTranslation;
	}
	function __toString() { return 'cocktail.core.style.computer.VisualEffectStylesComputer'; }
}
