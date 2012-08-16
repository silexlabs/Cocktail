<?php

class cocktail_core_font_FontManager {
	public function __construct() {
		if(!php_Boot::$skip_constructor) {
		$this->_fontManagerImpl = new cocktail_core_font_AbstractFontManagerImpl();
	}}
	public function createNativeTextElement($text, $computedStyle) {
		return $this->_fontManagerImpl->createNativeTextElement($text, $computedStyle);
	}
	public function getFontMetrics($fontFamily, $fontSize) {
		return $this->_fontManagerImpl->getFontMetrics($fontFamily, $fontSize);
	}
	public $_fontManagerImpl;
	public function __call($m, $a) {
		if(isset($this->$m) && is_callable($this->$m))
			return call_user_func_array($this->$m, $a);
		else if(isset($this->»dynamics[$m]) && is_callable($this->»dynamics[$m]))
			return call_user_func_array($this->»dynamics[$m], $a);
		else if('toString' == $m)
			return $this->__toString();
		else
			throw new HException('Unable to call «'.$m.'»');
	}
	static $_instance;
	static function getInstance() {
		if(cocktail_core_font_FontManager::$_instance === null) {
			cocktail_core_font_FontManager::$_instance = new cocktail_core_font_FontManager();
		}
		return cocktail_core_font_FontManager::$_instance;
	}
	function __toString() { return 'cocktail.core.font.FontManager'; }
}
