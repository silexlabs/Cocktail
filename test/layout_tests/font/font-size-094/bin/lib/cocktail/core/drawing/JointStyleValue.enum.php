<?php

class cocktail_core_drawing_JointStyleValue extends Enum {
	public static $bevel;
	public static $miter;
	public static $round;
	public static $__constructors = array(2 => 'bevel', 0 => 'miter', 1 => 'round');
	}
cocktail_core_drawing_JointStyleValue::$bevel = new cocktail_core_drawing_JointStyleValue("bevel", 2);
cocktail_core_drawing_JointStyleValue::$miter = new cocktail_core_drawing_JointStyleValue("miter", 0);
cocktail_core_drawing_JointStyleValue::$round = new cocktail_core_drawing_JointStyleValue("round", 1);
