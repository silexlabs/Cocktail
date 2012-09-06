<?php

class cocktail_core_style_computer_FontAndTextStylesComputer {
	public function __construct() { 
	}
	static function compute($style, $containingBlockData, $containingBlockFontMetricsData) {
		$computedStyle = $style->computedStyle;
		$fontMetrics = $style->get_fontMetricsData();
		$computedStyle->set_fontSize(cocktail_core_style_computer_FontAndTextStylesComputer::getComputedFontSize($style, $containingBlockFontMetricsData->fontSize, $containingBlockFontMetricsData->xHeight));
		$computedStyle->set_lineHeight(cocktail_core_style_computer_FontAndTextStylesComputer::getComputedLineHeight($style, $fontMetrics));
		$computedStyle->verticalAlign = cocktail_core_style_computer_FontAndTextStylesComputer::getComputedVerticalAlign($style, $containingBlockFontMetricsData, $fontMetrics);
		$computedStyle->set_letterSpacing(cocktail_core_style_computer_FontAndTextStylesComputer::getComputedLetterSpacing($style, $fontMetrics));
		$computedStyle->set_wordSpacing(cocktail_core_style_computer_FontAndTextStylesComputer::getComputedWordSpacing($style, $fontMetrics));
		$computedStyle->set_textIndent(cocktail_core_style_computer_FontAndTextStylesComputer::getComputedTextIndent($style, $containingBlockData, $fontMetrics));
		$computedStyle->color = cocktail_core_style_computer_FontAndTextStylesComputer::getComputedColor($style);
	}
	static function getComputedTextIndent($style, $containingBlockData, $fontMetrics) {
		$textIndent = null;
		$퍁 = ($style->textIndent);
		switch($퍁->index) {
		case 0:
		$value = $퍁->params[0];
		{
			$textIndent = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$textIndent = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $containingBlockData->width);
		}break;
		}
		return $textIndent;
	}
	static function getComputedVerticalAlign($style, $containingBlockFontMetricsData, $fontMetrics) {
		$verticalAlign = null;
		$퍁 = ($style->verticalAlign);
		switch($퍁->index) {
		case 0:
		{
			$verticalAlign = 0;
		}break;
		case 5:
		{
			$verticalAlign = 0;
		}break;
		case 1:
		{
			$verticalAlign = $containingBlockFontMetricsData->subscriptOffset;
		}break;
		case 2:
		{
			$verticalAlign = $containingBlockFontMetricsData->superscriptOffset;
		}break;
		case 4:
		{
			$verticalAlign = 0;
		}break;
		case 7:
		{
			$verticalAlign = 0;
		}break;
		case 8:
		$value = $퍁->params[0];
		{
			$verticalAlign = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $style->computedStyle->getLineHeight());
		}break;
		case 9:
		$value = $퍁->params[0];
		{
			$verticalAlign = cocktail_core_unit_UnitManager::getPixelFromLength($value, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		case 3:
		{
			$verticalAlign = 0;
		}break;
		case 6:
		{
			$verticalAlign = 0;
		}break;
		}
		return $verticalAlign;
	}
	static function getComputedColor($style) {
		return cocktail_core_unit_UnitManager::getColorDataFromCSSColor($style->color);
	}
	static function getComputedWordSpacing($style, $fontMetrics) {
		$wordSpacing = null;
		$퍁 = ($style->wordSpacing);
		switch($퍁->index) {
		case 0:
		{
			$wordSpacing = 0;
		}break;
		case 1:
		$unit = $퍁->params[0];
		{
			$wordSpacing = cocktail_core_unit_UnitManager::getPixelFromLength($unit, $style->computedStyle->getFontSize(), $fontMetrics->xHeight);
		}break;
		}
		return $wordSpacing;
	}
	static function getComputedLineHeight($style, $fontMetrics) {
		$lineHeight = null;
		$퍁 = ($style->lineHeight);
		switch($퍁->index) {
		case 2:
		$unit = $퍁->params[0];
		{
			$lineHeight = cocktail_core_unit_UnitManager::getPixelFromLength($unit, $style->computedStyle->getFontSize(), $fontMetrics->xHeight);
		}break;
		case 0:
		{
			$lineHeight = $style->computedStyle->getFontSize() * 1.2;
		}break;
		case 3:
		$value = $퍁->params[0];
		{
			$lineHeight = cocktail_core_unit_UnitManager::getPixelFromPercent($value, $style->computedStyle->getFontSize());
		}break;
		case 1:
		$value = $퍁->params[0];
		{
			$lineHeight = $style->computedStyle->getFontSize() * $value;
		}break;
		}
		return $lineHeight;
	}
	static function getComputedLetterSpacing($style, $fontMetrics) {
		$letterSpacing = null;
		$퍁 = ($style->letterSpacing);
		switch($퍁->index) {
		case 0:
		{
			$letterSpacing = 0.0;
		}break;
		case 1:
		$unit = $퍁->params[0];
		{
			$letterSpacing = cocktail_core_unit_UnitManager::getPixelFromLength($unit, $fontMetrics->fontSize, $fontMetrics->xHeight);
		}break;
		}
		return $letterSpacing;
	}
	static function getComputedFontSize($style, $parentFontSize, $parentXHeight) {
		$fontSize = null;
		$퍁 = ($style->fontSize);
		switch($퍁->index) {
		case 0:
		$unit = $퍁->params[0];
		{
			$fontSize = cocktail_core_unit_UnitManager::getPixelFromLength($unit, $parentFontSize, $parentXHeight);
		}break;
		case 1:
		$percent = $퍁->params[0];
		{
			$fontSize = cocktail_core_unit_UnitManager::getPixelFromPercent($percent, $parentFontSize);
		}break;
		case 2:
		$value = $퍁->params[0];
		{
			$fontSize = cocktail_core_unit_UnitManager::getFontSizeFromAbsoluteSizeValue($value);
		}break;
		case 3:
		$value = $퍁->params[0];
		{
			$fontSize = cocktail_core_unit_UnitManager::getFontSizeFromRelativeSizeValue($value, $parentFontSize);
		}break;
		}
		return $fontSize;
	}
	function __toString() { return 'cocktail.core.style.computer.FontAndTextStylesComputer'; }
}
