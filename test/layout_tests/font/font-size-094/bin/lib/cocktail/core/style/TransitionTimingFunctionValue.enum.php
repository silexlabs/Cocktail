<?php

class cocktail_core_style_TransitionTimingFunctionValue extends Enum {
	public static function cubicBezier($x1, $y1, $x2, $y2) { return new cocktail_core_style_TransitionTimingFunctionValue("cubicBezier", 8, array($x1, $y1, $x2, $y2)); }
	public static $ease;
	public static $easeIn;
	public static $easeInOut;
	public static $easeOut;
	public static $linear;
	public static $stepEnd;
	public static $stepStart;
	public static function steps($intervalNumbers, $intervalChange) { return new cocktail_core_style_TransitionTimingFunctionValue("steps", 7, array($intervalNumbers, $intervalChange)); }
	public static $__constructors = array(8 => 'cubicBezier', 0 => 'ease', 2 => 'easeIn', 4 => 'easeInOut', 3 => 'easeOut', 1 => 'linear', 6 => 'stepEnd', 5 => 'stepStart', 7 => 'steps');
	}
cocktail_core_style_TransitionTimingFunctionValue::$ease = new cocktail_core_style_TransitionTimingFunctionValue("ease", 0);
cocktail_core_style_TransitionTimingFunctionValue::$easeIn = new cocktail_core_style_TransitionTimingFunctionValue("easeIn", 2);
cocktail_core_style_TransitionTimingFunctionValue::$easeInOut = new cocktail_core_style_TransitionTimingFunctionValue("easeInOut", 4);
cocktail_core_style_TransitionTimingFunctionValue::$easeOut = new cocktail_core_style_TransitionTimingFunctionValue("easeOut", 3);
cocktail_core_style_TransitionTimingFunctionValue::$linear = new cocktail_core_style_TransitionTimingFunctionValue("linear", 1);
cocktail_core_style_TransitionTimingFunctionValue::$stepEnd = new cocktail_core_style_TransitionTimingFunctionValue("stepEnd", 6);
cocktail_core_style_TransitionTimingFunctionValue::$stepStart = new cocktail_core_style_TransitionTimingFunctionValue("stepStart", 5);
