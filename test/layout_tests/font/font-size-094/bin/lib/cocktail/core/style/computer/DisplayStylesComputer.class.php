<?php

class cocktail_core_style_computer_DisplayStylesComputer {
	public function __construct() { 
	}
	static function compute($style) {
		$computedStyle = $style->computedStyle;
		$computedStyle->cssFloat = cocktail_core_style_computer_DisplayStylesComputer::getComputedFloat($style, $computedStyle->position);
		$computedStyle->display = cocktail_core_style_computer_DisplayStylesComputer::getComputedDisplay($style, $computedStyle->cssFloat, $computedStyle->position);
		$computedStyle->clear = cocktail_core_style_computer_DisplayStylesComputer::getComputedClear($style, $computedStyle->position, $computedStyle->display);
	}
	static function getComputedFloat($style, $computedPosition) {
		$ret = null;
		if($computedPosition === cocktail_core_style_Position::$absolute || $computedPosition === cocktail_core_style_Position::$fixed) {
			$ret = cocktail_core_style_CSSFloat::$none;
		} else {
			$ret = $style->cssFloat;
		}
		return $ret;
	}
	static function getComputedDisplay($style, $computedFloat, $computedPosition) {
		$ret = null;
		if($computedFloat !== cocktail_core_style_CSSFloat::$none) {
			$퍁 = ($style->display);
			switch($퍁->index) {
			case 2:
			case 1:
			{
				$ret = cocktail_core_style_Display::$block;
			}break;
			default:{
				$ret = $style->display;
			}break;
			}
		} else {
			if($computedPosition === cocktail_core_style_Position::$absolute || $computedPosition === cocktail_core_style_Position::$fixed) {
				$퍁 = ($style->display);
				switch($퍁->index) {
				case 2:
				case 1:
				{
					$ret = cocktail_core_style_Display::$block;
				}break;
				default:{
					$ret = $style->display;
				}break;
				}
			} else {
				$ret = $style->display;
			}
		}
		return $ret;
	}
	static function getComputedClear($style, $computedPosition, $computedDisplay) {
		$ret = null;
		if($computedDisplay === cocktail_core_style_Display::$cssInline || $computedDisplay === cocktail_core_style_Display::$inlineBlock) {
			$ret = cocktail_core_style_Clear::$none;
		} else {
			if($computedPosition === cocktail_core_style_Position::$absolute || $computedPosition === cocktail_core_style_Position::$fixed) {
				$ret = cocktail_core_style_Clear::$none;
			} else {
				$ret = $style->clear;
			}
		}
		return $ret;
	}
	function __toString() { return 'cocktail.core.style.computer.DisplayStylesComputer'; }
}
