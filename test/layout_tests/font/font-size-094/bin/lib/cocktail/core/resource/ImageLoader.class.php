<?php

class cocktail_core_resource_ImageLoader extends cocktail_core_resource_AbstractMediaLoader {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	static $__properties__ = array("get_nativeElement" => "getNativeElement","get_intrinsicWidth" => "getIntrinsicWidth","get_intrinsicHeight" => "getIntrinsicHeight","get_intrinsicRatio" => "getIntrinsicRatio");
	function __toString() { return 'cocktail.core.resource.ImageLoader'; }
}
