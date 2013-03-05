<?php

class cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer extends cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer {
	public function __construct() { if(!php_Boot::$skip_constructor) {
		parent::__construct();
	}}
	public function getComputedAutoWidth($style, $containingBlockData, $fontMetrics) {
		return 0.0;
	}
	function __toString() { return 'cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer'; }
}
