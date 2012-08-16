<?php

class Test {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		$htmlContent = sys_io_File::getContent("../index.html");
		cocktail_Lib::get_document()->documentElement->set_innerHTML($htmlContent);
		php_Lib::hprint(cocktail_Lib::get_document()->documentElement->get_innerHTML());
	}}
	static function main() {
		new Test();
	}
	function __toString() { return 'Test'; }
}
