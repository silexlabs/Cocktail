<?php

class cocktail_core_renderer_InvalidationReason extends Enum {
	public static $backgroundImageLoaded;
	public static function childStyleChanged($styleName) { return new cocktail_core_renderer_InvalidationReason("childStyleChanged", 1, array($styleName)); }
	public static $needsImmediateLayout;
	public static $other;
	public static function positionedChildStyleChanged($styleName) { return new cocktail_core_renderer_InvalidationReason("positionedChildStyleChanged", 2, array($styleName)); }
	public static function styleChanged($styleName) { return new cocktail_core_renderer_InvalidationReason("styleChanged", 0, array($styleName)); }
	public static $windowResize;
	public static $__constructors = array(4 => 'backgroundImageLoaded', 1 => 'childStyleChanged', 3 => 'needsImmediateLayout', 6 => 'other', 2 => 'positionedChildStyleChanged', 0 => 'styleChanged', 5 => 'windowResize');
	}
cocktail_core_renderer_InvalidationReason::$backgroundImageLoaded = new cocktail_core_renderer_InvalidationReason("backgroundImageLoaded", 4);
cocktail_core_renderer_InvalidationReason::$needsImmediateLayout = new cocktail_core_renderer_InvalidationReason("needsImmediateLayout", 3);
cocktail_core_renderer_InvalidationReason::$other = new cocktail_core_renderer_InvalidationReason("other", 6);
cocktail_core_renderer_InvalidationReason::$windowResize = new cocktail_core_renderer_InvalidationReason("windowResize", 5);
