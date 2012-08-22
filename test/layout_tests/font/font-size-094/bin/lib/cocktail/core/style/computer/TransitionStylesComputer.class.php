<?php

class cocktail_core_style_computer_TransitionStylesComputer {
	public function __construct() { 
	}
	static function compute($style) {
		$computedStyle = $style->computedStyle;
		$computedStyle->transitionDelay = cocktail_core_style_computer_TransitionStylesComputer::getComputedTransitionDelay($style);
		$computedStyle->transitionDuration = cocktail_core_style_computer_TransitionStylesComputer::getComputedTransitionDuration($style);
	}
	static function getComputedTransitionDuration($style) {
		$transitionDurations = new _hx_array(array());
		{
			$_g1 = 0; $_g = $style->transitionDuration->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$�t = ($style->transitionDuration[$i]);
				switch($�t->index) {
				case 0:
				$value = $�t->params[0];
				{
					$transitionDurations->push($value);
				}break;
				case 1:
				$value = $�t->params[0];
				{
					$transitionDurations->push($value / 1000);
				}break;
				}
				unset($i);
			}
		}
		return $transitionDurations;
	}
	static function getComputedTransitionDelay($style) {
		$transitionDelays = new _hx_array(array());
		{
			$_g1 = 0; $_g = $style->transitionDelay->length;
			while($_g1 < $_g) {
				$i = $_g1++;
				$�t = ($style->transitionDelay[$i]);
				switch($�t->index) {
				case 0:
				$value = $�t->params[0];
				{
					$transitionDelays->push($value);
				}break;
				case 1:
				$value = $�t->params[0];
				{
					$transitionDelays->push($value / 1000);
				}break;
				}
				unset($i);
			}
		}
		return $transitionDelays;
	}
	function __toString() { return 'cocktail.core.style.computer.TransitionStylesComputer'; }
}
