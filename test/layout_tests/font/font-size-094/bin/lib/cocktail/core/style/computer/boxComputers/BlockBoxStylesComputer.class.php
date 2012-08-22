<?php

class cocktail_core_style_computer_boxComputers_BlockBoxStylesComputer extends cocktail_core_style_computer_boxComputers_BoxStylesComputer {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	function __toString() { return 'cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer'; }
}
