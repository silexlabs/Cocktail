<?php

class cocktail_port_platform_input_AbstractNativeTextInput {
	public function __construct() {
		;
	}
	public function get_letterSpacing() {
		return $this->letterSpacing;
	}
	public function set_letterSpacing($value) {
		return $this->letterSpacing = $value;
	}
	public function set_value($textValue) {
		return $this->value = $textValue;
	}
	public function get_value() {
		return $this->value;
	}
	public function get_fontSize() {
		return $this->fontSize;
	}
	public function set_fontSize($value) {
		return $this->fontSize = $value;
	}
	public function get_fontFamily() {
		return $this->fontFamily;
	}
	public function set_fontFamily($value) {
		return $this->fontFamily = $value;
	}
	public function get_color() {
		return $this->color;
	}
	public function set_color($value) {
		return $this->color = $value;
	}
	public function set_bold($value) {
		return $this->set_italic($value);
	}
	public function get_bold() {
		return $this->get_italic();
	}
	public function get_italic() {
		return $this->italic;
	}
	public function set_italic($value) {
		return $this->italic = $value;
	}
	public function set_viewport($value) {
		return $this->viewport = $value;
	}
	public function get_viewport() {
		return $this->viewport;
	}
	public function focus() {
	}
	public function attach($graphicContext) {
	}
	public $fontSize;
	public $letterSpacing;
	public $fontFamily;
	public $color;
	public $bold;
	public $italic;
	public $viewport;
	public $value;
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
	static $__properties__ = array("set_value" => "set_value","get_value" => "get_value","set_viewport" => "set_viewport","get_viewport" => "get_viewport","set_italic" => "set_italic","get_italic" => "get_italic","set_bold" => "set_italic","get_bold" => "get_italic","set_color" => "set_color","get_color" => "get_color","set_fontFamily" => "set_fontFamily","get_fontFamily" => "get_fontFamily","set_letterSpacing" => "set_letterSpacing","get_letterSpacing" => "get_letterSpacing","set_fontSize" => "set_fontSize","get_fontSize" => "get_fontSize");
	function __toString() { return 'cocktail.port.platform.input.AbstractNativeTextInput'; }
}
