<?php

class cocktail_core_style_ComputedStyle {
	public function __construct($coreStyle) {
		if(!php_Boot::$skip_constructor) {
		$this->_coreStyle = $coreStyle;
	}}
	public function getTextIndent() {
		return $this->getTransitionablePropertyValue("text-indent", $this->textIndent);
	}
	public function getLineHeight() {
		return $this->getTransitionablePropertyValue("line-height", $this->lineHeight);
	}
	public function getWordSpacing() {
		return $this->getTransitionablePropertyValue("word-spacing", $this->wordSpacing);
	}
	public function getLetterSpacing() {
		return $this->getTransitionablePropertyValue("letter-spacing", $this->letterSpacing);
	}
	public function getFontSize() {
		return $this->getTransitionablePropertyValue("font-size", $this->fontSize);
	}
	public function getRight() {
		return $this->getTransitionablePropertyValue("right", $this->right);
	}
	public function getBottom() {
		return $this->getTransitionablePropertyValue("bottom", $this->bottom);
	}
	public function getLeft() {
		return $this->getTransitionablePropertyValue("left", $this->left);
	}
	public function getTop() {
		return $this->getTransitionablePropertyValue("top", $this->top);
	}
	public function getMaxWidth() {
		return $this->getTransitionablePropertyValue("max-width", $this->maxWidth);
	}
	public function getMinWidth() {
		return $this->getTransitionablePropertyValue("min-width", $this->minWidth);
	}
	public function getMaxHeight() {
		return $this->getTransitionablePropertyValue("max-height", $this->maxHeight);
	}
	public function getMinHeight() {
		return $this->getTransitionablePropertyValue("min-height", $this->minHeight);
	}
	public function getHeight() {
		return $this->getTransitionablePropertyValue("height", $this->height);
	}
	public function getWidth() {
		return $this->getTransitionablePropertyValue("width", $this->width);
	}
	public function getPaddingBottom() {
		return $this->getTransitionablePropertyValue("padding-bottom", $this->paddingBottom);
	}
	public function getPaddingTop() {
		return $this->getTransitionablePropertyValue("padding-top", $this->paddingTop);
	}
	public function getPaddingRight() {
		return $this->getTransitionablePropertyValue("padding-right", $this->paddingRight);
	}
	public function getPaddingLeft() {
		return $this->getTransitionablePropertyValue("padding-left", $this->paddingLeft);
	}
	public function getMarginBottom() {
		return $this->getTransitionablePropertyValue("margin-bottom", $this->marginBottom);
	}
	public function getMarginTop() {
		return $this->getTransitionablePropertyValue("margin-top", $this->marginTop);
	}
	public function getMarginRight() {
		return $this->getTransitionablePropertyValue("margin-right", $this->marginRight);
	}
	public function getMarginLeft() {
		return $this->getTransitionablePropertyValue("margin-left", $this->marginLeft);
	}
	public function getOpacity() {
		return $this->getTransitionablePropertyValue("opacity", $this->opacity);
	}
	public function set_opacity($value) {
		return $this->opacity = $value;
	}
	public function set_textIndent($value) {
		return $this->textIndent = $value;
	}
	public function set_wordSpacing($value) {
		return $this->wordSpacing = $value;
	}
	public function set_letterSpacing($value) {
		return $this->letterSpacing = $value;
	}
	public function set_lineHeight($value) {
		return $this->lineHeight = $value;
	}
	public function set_fontSize($value) {
		return $this->fontSize = $value;
	}
	public function set_right($value) {
		return $this->right = $value;
	}
	public function set_left($value) {
		return $this->left = $value;
	}
	public function set_bottom($value) {
		return $this->bottom = $value;
	}
	public function set_top($value) {
		return $this->top = $value;
	}
	public function set_maxWidth($value) {
		return $this->maxWidth = $value;
	}
	public function set_maxHeight($value) {
		return $this->maxHeight = $value;
	}
	public function set_minWidth($value) {
		return $this->minWidth = $value;
	}
	public function set_minHeight($value) {
		return $this->minHeight = $value;
	}
	public function set_paddingRight($value) {
		return $this->paddingRight = $value;
	}
	public function set_paddingLeft($value) {
		return $this->paddingLeft = $value;
	}
	public function set_paddingBottom($value) {
		return $this->paddingBottom = $value;
	}
	public function set_paddingTop($value) {
		return $this->paddingTop = $value;
	}
	public function set_marginRight($value) {
		return $this->marginRight = $value;
	}
	public function set_marginBottom($value) {
		return $this->marginBottom = $value;
	}
	public function set_marginTop($value) {
		return $this->marginTop = $value;
	}
	public function set_marginLeft($value) {
		return $this->marginLeft = $value;
	}
	public function set_height($value) {
		return $this->height = $value;
	}
	public function set_width($value) {
		return $this->width = $value;
	}
	public function getTransitionablePropertyValue($propertyName, $propertyValue) {
		$transition = cocktail_core_style_transition_TransitionManager::getInstance()->getTransition($propertyName, $this);
		if($transition !== null) {
			return $transition->get_currentValue();
		} else {
			return $propertyValue;
		}
	}
	public function init() {
		$this->set_minHeight(0.0);
		$this->set_maxHeight(0.0);
		$this->set_minWidth(0.0);
		$this->set_maxWidth(0.0);
		$this->set_width(0.0);
		$this->set_height(0.0);
		$this->set_marginLeft(0.0);
		$this->set_marginRight(0.0);
		$this->set_marginTop(0.0);
		$this->set_marginBottom(0.0);
		$this->set_paddingLeft(0.0);
		$this->set_paddingRight(0.0);
		$this->set_paddingTop(0.0);
		$this->set_paddingBottom(0.0);
		$this->set_left(0.0);
		$this->set_right(0.0);
		$this->set_top(0.0);
		$this->set_bottom(0.0);
		$this->clear = cocktail_core_style_Clear::$none;
		$this->cssFloat = cocktail_core_style_CSSFloat::$none;
		$this->display = cocktail_core_style_Display::$cssInline;
		$this->position = cocktail_core_style_Position::$cssStatic;
		$this->verticalAlign = 0.0;
		$this->set_fontSize(16.0);
		$this->set_lineHeight(14.0);
		$this->fontWeight = cocktail_core_style_FontWeight::$normal;
		$this->fontStyle = cocktail_core_style_FontStyle::$normal;
		$this->fontFamily = new _hx_array(array("serif"));
		$this->fontVariant = cocktail_core_style_FontVariant::$normal;
		$this->textTransform = cocktail_core_style_TextTransform::$none;
		$this->set_letterSpacing(0);
		$this->set_wordSpacing(0);
		$this->set_textIndent(0);
		$this->whiteSpace = cocktail_core_style_WhiteSpace::$normal;
		$this->textAlign = cocktail_core_style_TextAlign::$left;
		$this->color = _hx_anonymous(array("color" => 0, "alpha" => 1.0));
		$this->visibility = cocktail_core_style_Visibility::$visible;
		$this->zIndex = cocktail_core_style_ZIndex::$cssAuto;
		$this->set_opacity(1.0);
		$this->overflowX = cocktail_core_style_Overflow::$visible;
		$this->overflowY = cocktail_core_style_Overflow::$visible;
		$this->transformOrigin = _hx_anonymous(array("x" => 0.0, "y" => 0.0));
		$this->transform = new cocktail_core_geom_Matrix(null);
		$this->backgroundColor = _hx_anonymous(array("color" => 0, "alpha" => 1.0));
		$this->backgroundSize = new _hx_array(array());
		$this->backgroundOrigin = new _hx_array(array());
		$this->backgroundImage = new _hx_array(array());
		$this->backgroundClip = new _hx_array(array());
		$this->backgroundPosition = new _hx_array(array());
		$this->backgroundRepeat = new _hx_array(array());
		$this->cursor = cocktail_core_style_Cursor::$cssDefault;
		$this->transitionDelay = new _hx_array(array(0.0));
		$this->transitionDuration = new _hx_array(array(0.0));
		$this->transitionProperty = cocktail_core_style_TransitionProperty::$all;
		$this->transitionTimingFunction = new _hx_array(array(cocktail_core_style_TransitionTimingFunctionValue::$ease));
	}
	public $_coreStyle;
	public $transitionTimingFunction;
	public $transitionDelay;
	public $transitionDuration;
	public $transitionProperty;
	public $cursor;
	public $overflowY;
	public $overflowX;
	public $visibility;
	public $opacity;
	public $verticalAlign;
	public $textIndent;
	public $textAlign;
	public $whiteSpace;
	public $wordSpacing;
	public $letterSpacing;
	public $textTransform;
	public $lineHeight;
	public $color;
	public $fontVariant;
	public $fontFamily;
	public $fontStyle;
	public $fontWeight;
	public $fontSize;
	public $backgroundClip;
	public $backgroundPosition;
	public $backgroundSize;
	public $backgroundOrigin;
	public $backgroundRepeat;
	public $backgroundImage;
	public $backgroundColor;
	public $right;
	public $bottom;
	public $left;
	public $top;
	public $maxWidth;
	public $minWidth;
	public $maxHeight;
	public $minHeight;
	public $height;
	public $width;
	public $paddingBottom;
	public $paddingTop;
	public $paddingRight;
	public $paddingLeft;
	public $marginBottom;
	public $marginTop;
	public $marginRight;
	public $marginLeft;
	public $transform;
	public $transformOrigin;
	public $zIndex;
	public $clear;
	public $cssFloat;
	public $position;
	public $display;
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
	static $__properties__ = array("set_marginLeft" => "set_marginLeft","get_marginLeft" => "getMarginLeft","set_marginRight" => "set_marginRight","get_marginRight" => "getMarginRight","set_marginTop" => "set_marginTop","get_marginTop" => "getMarginTop","set_marginBottom" => "set_marginBottom","get_marginBottom" => "getMarginBottom","set_paddingLeft" => "set_paddingLeft","get_paddingLeft" => "getPaddingLeft","set_paddingRight" => "set_paddingRight","get_paddingRight" => "getPaddingRight","set_paddingTop" => "set_paddingTop","get_paddingTop" => "getPaddingTop","set_paddingBottom" => "set_paddingBottom","get_paddingBottom" => "getPaddingBottom","set_width" => "set_width","get_width" => "getWidth","set_height" => "set_height","get_height" => "getHeight","set_minHeight" => "set_minHeight","get_minHeight" => "getMinHeight","set_maxHeight" => "set_maxHeight","get_maxHeight" => "getMaxHeight","set_minWidth" => "set_minWidth","get_minWidth" => "getMinWidth","set_maxWidth" => "set_maxWidth","get_maxWidth" => "getMaxWidth","set_top" => "set_top","get_top" => "getTop","set_left" => "set_left","get_left" => "getLeft","set_bottom" => "set_bottom","get_bottom" => "getBottom","set_right" => "set_right","get_right" => "getRight","set_fontSize" => "set_fontSize","get_fontSize" => "getFontSize","set_lineHeight" => "set_lineHeight","get_lineHeight" => "getLineHeight","set_letterSpacing" => "set_letterSpacing","get_letterSpacing" => "getLetterSpacing","set_wordSpacing" => "set_wordSpacing","get_wordSpacing" => "getWordSpacing","set_textIndent" => "set_textIndent","get_textIndent" => "getTextIndent","set_opacity" => "set_opacity","get_opacity" => "getOpacity");
	function __toString() { return 'cocktail.core.style.ComputedStyle'; }
}
