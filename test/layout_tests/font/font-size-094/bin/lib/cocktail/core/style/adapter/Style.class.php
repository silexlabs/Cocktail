<?php

class cocktail_core_style_adapter_Style {
	public function __construct($coreStyle) {
		if(!php_Boot::$skip_constructor) {
		$this->_coreStyle = $coreStyle;
		$this->attributes = new cocktail_core_dom_NamedNodeMap();
	}}
	public function set_transformOrigin($value) {
		$this->setAttribute("transform-origin", $value);
		$this->_coreStyle->setTransformOrigin(cocktail_core_unit_UnitManager::getTransformOrigin($value));
		return $value;
	}
	public function get_transformOrigin() {
		return cocktail_core_unit_UnitManager::getCSSTransformOrigin($this->_coreStyle->transformOrigin);
	}
	public function set_transform($value) {
		$this->setAttribute("transform", $value);
		$this->_coreStyle->setTransform(cocktail_core_unit_UnitManager::getTransform($value));
		return $value;
	}
	public function get_transform() {
		return cocktail_core_unit_UnitManager::getCSSTransform($this->_coreStyle->transform);
	}
	public function set_transitionTimingFunction($value) {
		$this->setAttribute("transition-timing-function", $value);
		$this->_coreStyle->setTransitionTimingFunction(cocktail_core_unit_UnitManager::getTransitionTimingFunction($value));
		return $value;
	}
	public function get_transitionTimingFunction() {
		return cocktail_core_unit_UnitManager::getCSSTransitionTimingFunction($this->_coreStyle->transitionTimingFunction);
	}
	public function set_transitionDelay($value) {
		$this->setAttribute("transition-delay", $value);
		$this->_coreStyle->setTransitionDelay(cocktail_core_unit_UnitManager::getTransitionDelay($value));
		return $value;
	}
	public function get_transitionDelay() {
		return cocktail_core_unit_UnitManager::getCSSTransitionDelay($this->_coreStyle->transitionDelay);
	}
	public function set_transitionDuration($value) {
		$this->setAttribute("transition-duration", $value);
		$this->_coreStyle->setTransitionDuration(cocktail_core_unit_UnitManager::getTransitionDuration($value));
		return $value;
	}
	public function get_transitionDuration() {
		return cocktail_core_unit_UnitManager::getCSSTransitionDuration($this->_coreStyle->transitionDuration);
	}
	public function set_transitionProperty($value) {
		$this->setAttribute("transition-property", $value);
		$this->_coreStyle->setTransitionProperty(cocktail_core_unit_UnitManager::getTransitionProperty($value));
		return $value;
	}
	public function get_transitionProperty() {
		return cocktail_core_unit_UnitManager::getCSSTransitionProperty($this->_coreStyle->transitionProperty);
	}
	public function get_cursor() {
		return cocktail_core_unit_UnitManager::getCSSCursor($this->_coreStyle->cursor);
	}
	public function set_cursor($value) {
		$this->setAttribute("cursor", $value);
		$this->_coreStyle->setCursor(cocktail_core_unit_UnitManager::cursorEnum($value));
		return $value;
	}
	public function set_overflowY($value) {
		$this->setAttribute("overflow-y", $value);
		$this->_coreStyle->setOverflowY(cocktail_core_unit_UnitManager::overflowEnum($value));
		return cocktail_core_unit_UnitManager::getCSSOverflow($this->_coreStyle->overflowY);
	}
	public function get_overflowY() {
		return cocktail_core_unit_UnitManager::getCSSOverflow($this->_coreStyle->overflowY);
	}
	public function set_overflowX($value) {
		$this->setAttribute("overflow-x", $value);
		$this->_coreStyle->setOverflowX(cocktail_core_unit_UnitManager::overflowEnum($value));
		return $value;
	}
	public function get_overflowX() {
		return cocktail_core_unit_UnitManager::getCSSOverflow($this->_coreStyle->overflowX);
	}
	public function get_backgroundOrigin() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundOrigin($this->_coreStyle->backgroundOrigin);
	}
	public function set_backgroundOrigin($value) {
		$this->setAttribute("background-origin", $value);
		$this->_coreStyle->setBackgroundOrigin(cocktail_core_unit_UnitManager::backgroundOriginEnum($value));
		return $value;
	}
	public function get_backgroundPosition() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundPosition($this->_coreStyle->backgroundPosition);
	}
	public function set_backgroundPosition($value) {
		$this->setAttribute("background-position", $value);
		$this->_coreStyle->setBackgroundPosition(cocktail_core_unit_UnitManager::backgroundPositionEnum($value));
		return $value;
	}
	public function get_backgroundClip() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundClip($this->_coreStyle->backgroundClip);
	}
	public function set_backgroundClip($value) {
		$this->setAttribute("background-clip", $value);
		$this->_coreStyle->setBackgroundClip(cocktail_core_unit_UnitManager::backgroundClipEnum($value));
		return $value;
	}
	public function get_backgroundSize() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundSize($this->_coreStyle->backgroundSize);
	}
	public function set_backgroundSize($value) {
		$this->setAttribute("background-size", $value);
		$this->_coreStyle->setBackgroundSize(cocktail_core_unit_UnitManager::backgroundSizeEnum($value));
		return $value;
	}
	public function get_backgroundRepeat() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundRepeat($this->_coreStyle->backgroundRepeat);
	}
	public function set_backgroundRepeat($value) {
		$this->setAttribute("background-repeat", $value);
		$this->_coreStyle->setBackgroundRepeat(cocktail_core_unit_UnitManager::backgroundRepeatEnum($value));
		return $value;
	}
	public function get_backgroundImage() {
		return cocktail_core_unit_UnitManager::getCSSBackgroundImage($this->_coreStyle->backgroundImage);
	}
	public function set_backgroundImage($value) {
		$this->setAttribute("background-image", $value);
		$this->_coreStyle->setBackgroundImage(cocktail_core_unit_UnitManager::backgroundImageEnum($value));
		return $value;
	}
	public function get_backgroundColor() {
		return cocktail_core_unit_UnitManager::getCSSColor($this->_coreStyle->backgroundColor);
	}
	public function set_backgroundColor($value) {
		$this->setAttribute("background-color", $value);
		$this->_coreStyle->setBackgroundColor(cocktail_core_unit_UnitManager::colorEnum($value));
		return $value;
	}
	public function set_textAlign($value) {
		$this->setAttribute("text-align", $value);
		$this->_coreStyle->setTextAlign(cocktail_core_unit_UnitManager::textAlignEnum($value));
		return $value;
	}
	public function get_textAlign() {
		return cocktail_core_unit_UnitManager::getCSSTextAlign($this->_coreStyle->textAlign);
	}
	public function set_whiteSpace($value) {
		$this->setAttribute("white-space", $value);
		$this->_coreStyle->setWhiteSpace(cocktail_core_unit_UnitManager::whiteSpaceEnum($value));
		return $value;
	}
	public function get_whiteSpace() {
		return cocktail_core_unit_UnitManager::getCSSWhiteSpace($this->_coreStyle->whiteSpace);
	}
	public function set_textIndent($value) {
		$this->setAttribute("text-indent", $value);
		$this->_coreStyle->setTextIndent(cocktail_core_unit_UnitManager::textIndentEnum($value));
		return $value;
	}
	public function get_textIndent() {
		return cocktail_core_unit_UnitManager::getCSSTextIndent($this->_coreStyle->textIndent);
	}
	public function set_verticalAlign($value) {
		$this->setAttribute("vertical-align", $value);
		$this->_coreStyle->setVerticalAlign(cocktail_core_unit_UnitManager::verticalAlignEnum($value));
		return $value;
	}
	public function get_verticalAlign() {
		return cocktail_core_unit_UnitManager::getCSSVerticalAlign($this->_coreStyle->verticalAlign);
	}
	public function set_lineHeight($value) {
		$this->setAttribute("line-height", $value);
		$this->_coreStyle->setLineHeight(cocktail_core_unit_UnitManager::lineHeightEnum($value));
		return $value;
	}
	public function get_lineHeight() {
		return cocktail_core_unit_UnitManager::getCSSLineHeight($this->_coreStyle->lineHeight);
	}
	public function set_wordSpacing($value) {
		$this->setAttribute("word-spacing", $value);
		$this->_coreStyle->setWordSpacing(cocktail_core_unit_UnitManager::wordSpacingEnum($value));
		return $value;
	}
	public function get_wordSpacing() {
		return cocktail_core_unit_UnitManager::getCSSWordSpacing($this->_coreStyle->wordSpacing);
	}
	public function set_color($value) {
		$this->setAttribute("color", $value);
		$this->_coreStyle->setColor(cocktail_core_unit_UnitManager::colorEnum($value));
		return $value;
	}
	public function get_color() {
		return cocktail_core_unit_UnitManager::getCSSColor($this->_coreStyle->color);
	}
	public function set_letterSpacing($value) {
		$this->setAttribute("letter-spacing", $value);
		$this->_coreStyle->setLetterSpacing(cocktail_core_unit_UnitManager::letterSpacingEnum($value));
		return $value;
	}
	public function get_letterSpacing() {
		return cocktail_core_unit_UnitManager::getCSSLetterSpacing($this->_coreStyle->letterSpacing);
	}
	public function set_textTransform($value) {
		$this->setAttribute("text-tranform", $value);
		$this->_coreStyle->setTextTransform(cocktail_core_unit_UnitManager::textTransformEnum($value));
		return $value;
	}
	public function get_textTransform() {
		return cocktail_core_unit_UnitManager::getCSSTextTransform($this->_coreStyle->textTransform);
	}
	public function set_fontVariant($value) {
		$this->setAttribute("font-variant", $value);
		$this->_coreStyle->setFontVariant(cocktail_core_unit_UnitManager::fontVariantEnum($value));
		return $value;
	}
	public function get_fontVariant() {
		return cocktail_core_unit_UnitManager::getCSSFontVariant($this->_coreStyle->fontVariant);
	}
	public function set_fontFamily($value) {
		$this->setAttribute("font-family", $value);
		$this->_coreStyle->setFontFamily(cocktail_core_unit_UnitManager::fontFamilyEnum($value));
		return $value;
	}
	public function get_fontFamily() {
		return cocktail_core_unit_UnitManager::getCSSFontFamily($this->_coreStyle->fontFamily);
	}
	public function set_fontStyle($value) {
		$this->setAttribute("font-style", $value);
		$this->_coreStyle->setFontStyle(cocktail_core_unit_UnitManager::fontStyleEnum($value));
		return $value;
	}
	public function get_fontStyle() {
		return cocktail_core_unit_UnitManager::getCSSFontStyle($this->_coreStyle->fontStyle);
	}
	public function set_fontWeight($value) {
		$this->setAttribute("font-weight", $value);
		$this->_coreStyle->setFontWeight(cocktail_core_unit_UnitManager::fontWeightEnum($value));
		return $value;
	}
	public function get_fontWeight() {
		return cocktail_core_unit_UnitManager::getCSSFontWeight($this->_coreStyle->fontWeight);
	}
	public function set_fontSize($value) {
		$this->setAttribute("font-size", $value);
		$this->_coreStyle->setFontSize(cocktail_core_unit_UnitManager::fontSizeEnum($value));
		return $value;
	}
	public function get_fontSize() {
		return cocktail_core_unit_UnitManager::getCSSFontSize($this->_coreStyle->fontSize);
	}
	public function set_clear($value) {
		$this->setAttribute("clear", $value);
		$this->_coreStyle->setClear(cocktail_core_unit_UnitManager::clearEnum($value));
		return $value;
	}
	public function get_clear() {
		return cocktail_core_unit_UnitManager::getCSSClear($this->_coreStyle->clear);
	}
	public function set_CSSFloat($value) {
		$this->setAttribute("float", $value);
		$this->_coreStyle->setCSSFloat(cocktail_core_unit_UnitManager::cssFloatEnum($value));
		return $value;
	}
	public function get_CSSFloat() {
		return cocktail_core_unit_UnitManager::getCSSFloatAsString($this->_coreStyle->cssFloat);
	}
	public function set_right($value) {
		$this->setAttribute("right", $value);
		$this->_coreStyle->setRight(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.PositionOffset"), $value));
		return $value;
	}
	public function get_right() {
		return cocktail_core_unit_UnitManager::getCSSPositionOffset($this->_coreStyle->right);
	}
	public function set_bottom($value) {
		$this->setAttribute("bottom", $value);
		$this->_coreStyle->setBottom(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.PositionOffset"), $value));
		return $value;
	}
	public function get_bottom() {
		return cocktail_core_unit_UnitManager::getCSSPositionOffset($this->_coreStyle->bottom);
	}
	public function set_left($value) {
		$this->setAttribute("left", $value);
		$this->_coreStyle->setLeft(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.PositionOffset"), $value));
		return $value;
	}
	public function get_left() {
		return cocktail_core_unit_UnitManager::getCSSPositionOffset($this->_coreStyle->left);
	}
	public function set_top($value) {
		$this->setAttribute("top", $value);
		$this->_coreStyle->setTop(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.PositionOffset"), $value));
		return $value;
	}
	public function get_top() {
		return cocktail_core_unit_UnitManager::getCSSPositionOffset($this->_coreStyle->top);
	}
	public function set_maxWidth($value) {
		$this->setAttribute("max-width", $value);
		$this->_coreStyle->setMaxWidth(cocktail_core_unit_UnitManager::constrainedDimensionEnum($value));
		return $value;
	}
	public function get_maxWidth() {
		return cocktail_core_unit_UnitManager::getCSSConstrainedDimension($this->_coreStyle->maxWidth);
	}
	public function set_minWidth($value) {
		$this->setAttribute("min-width", $value);
		$this->_coreStyle->setMinWidth(cocktail_core_unit_UnitManager::constrainedDimensionEnum($value));
		return $value;
	}
	public function get_minWidth() {
		return cocktail_core_unit_UnitManager::getCSSConstrainedDimension($this->_coreStyle->minWidth);
	}
	public function set_maxHeight($value) {
		$this->setAttribute("max-height", $value);
		$this->_coreStyle->setMaxHeight(cocktail_core_unit_UnitManager::constrainedDimensionEnum($value));
		return $value;
	}
	public function get_maxHeight() {
		return cocktail_core_unit_UnitManager::getCSSConstrainedDimension($this->_coreStyle->maxHeight);
	}
	public function set_minHeight($value) {
		$this->setAttribute("min-height", $value);
		$this->_coreStyle->setMinHeight(cocktail_core_unit_UnitManager::constrainedDimensionEnum($value));
		return $value;
	}
	public function get_minHeight() {
		return cocktail_core_unit_UnitManager::getCSSConstrainedDimension($this->_coreStyle->minHeight);
	}
	public function set_height($value) {
		$this->setAttribute("height", $value);
		$this->_coreStyle->setHeight(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Dimension"), $value));
		return $value;
	}
	public function get_height() {
		return cocktail_core_unit_UnitManager::getCSSDimension($this->_coreStyle->height);
	}
	public function set_width($value) {
		$this->setAttribute("width", $value);
		$this->_coreStyle->setWidth(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Dimension"), $value));
		return $value;
	}
	public function get_width() {
		return cocktail_core_unit_UnitManager::getCSSDimension($this->_coreStyle->width);
	}
	public function set_zIndex($value) {
		$this->setAttribute("z-index", $value);
		$this->_coreStyle->setZIndex(cocktail_core_unit_UnitManager::zIndexEnum($value));
		return $value;
	}
	public function get_zIndex() {
		return cocktail_core_unit_UnitManager::getCSSZIndex($this->_coreStyle->zIndex);
	}
	public function set_position($value) {
		$this->setAttribute("position", $value);
		$this->_coreStyle->setPosition(cocktail_core_unit_UnitManager::positionEnum($value));
		return $value;
	}
	public function get_position() {
		return cocktail_core_unit_UnitManager::getCSSPosition($this->_coreStyle->position);
	}
	public function set_display($value) {
		$this->setAttribute("display", $value);
		$this->_coreStyle->setDisplay(cocktail_core_unit_UnitManager::displayEnum($value));
		return $value;
	}
	public function get_display() {
		return cocktail_core_unit_UnitManager::getCSSDisplay($this->_coreStyle->display);
	}
	public function set_paddingBottom($value) {
		$this->setAttribute("padding-bottom", $value);
		$this->_coreStyle->setPaddingBottom(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Padding"), $value));
		return $value;
	}
	public function get_paddingBottom() {
		return cocktail_core_unit_UnitManager::getCSSPadding($this->_coreStyle->paddingBottom);
	}
	public function set_paddingTop($value) {
		$this->setAttribute("padding-top", $value);
		$this->_coreStyle->setPaddingTop(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Padding"), $value));
		return $value;
	}
	public function get_paddingTop() {
		return cocktail_core_unit_UnitManager::getCSSPadding($this->_coreStyle->paddingTop);
	}
	public function set_paddingRight($value) {
		$this->setAttribute("padding-right", $value);
		$this->_coreStyle->setPaddingRight(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Padding"), $value));
		return $value;
	}
	public function get_paddingRight() {
		return cocktail_core_unit_UnitManager::getCSSPadding($this->_coreStyle->paddingRight);
	}
	public function set_paddingLeft($value) {
		$this->setAttribute("padding-left", $value);
		$this->_coreStyle->setPaddingLeft(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Padding"), $value));
		return $value;
	}
	public function get_paddingLeft() {
		return cocktail_core_unit_UnitManager::getCSSPadding($this->_coreStyle->paddingLeft);
	}
	public function set_marginBottom($value) {
		$this->setAttribute("margin-bottom", $value);
		$this->_coreStyle->setMarginBottom(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Margin"), $value));
		return $value;
	}
	public function get_marginBottom() {
		return cocktail_core_unit_UnitManager::getCSSMargin($this->_coreStyle->marginBottom);
	}
	public function set_marginTop($value) {
		$this->setAttribute("margin-top", $value);
		$this->_coreStyle->setMarginTop(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Margin"), $value));
		return $value;
	}
	public function get_marginTop() {
		return cocktail_core_unit_UnitManager::getCSSMargin($this->_coreStyle->marginTop);
	}
	public function set_marginRight($value) {
		$this->setAttribute("margin-right", $value);
		$this->_coreStyle->setMarginRight(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Margin"), $value));
		return $value;
	}
	public function get_marginRight() {
		return cocktail_core_unit_UnitManager::getCSSMargin($this->_coreStyle->marginRight);
	}
	public function set_marginLeft($value) {
		$this->setAttribute("margin-left", $value);
		$this->_coreStyle->setMarginLeft(cocktail_core_unit_UnitManager::boxStyleEnum(_hx_qtype("cocktail.core.style.Margin"), $value));
		return $value;
	}
	public function get_marginLeft() {
		return cocktail_core_unit_UnitManager::getCSSMargin($this->_coreStyle->marginLeft);
	}
	public function set_visibility($value) {
		$this->setAttribute("visibility", $value);
		$this->_coreStyle->setVisibility(cocktail_core_unit_UnitManager::visibilityEnum($value));
		return $value;
	}
	public function get_visibility() {
		return cocktail_core_unit_UnitManager::getCSSVisibility($this->_coreStyle->visibility);
	}
	public function set_opacity($value) {
		$this->setAttribute("opacity", $value);
		$this->_coreStyle->setOpacity(Std::parseFloat($value));
		return $value;
	}
	public function get_opacity() {
		return cocktail_core_unit_UnitManager::getCSSOpacity($this->_coreStyle->opacity);
	}
	public function setAttribute($name, $value) {
		if($value === null) {
			$this->attributes->removeNamedItem($name);
			return;
		}
		$attr = new cocktail_core_dom_Attr($name);
		$attr->set_value($value);
		$this->attributes->setNamedItem($attr);
	}
	public $attributes;
	public $_coreStyle;
	public $cursor;
	public $transformOrigin;
	public $transform;
	public $transitionDelay;
	public $transitionTimingFunction;
	public $transitionDuration;
	public $transitionProperty;
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
	static $__properties__ = array("set_display" => "set_display","get_display" => "get_display","set_position" => "set_position","get_position" => "get_position","set_cssFloat" => "set_CSSFloat","get_cssFloat" => "get_CSSFloat","set_clear" => "set_clear","get_clear" => "get_clear","set_zIndex" => "set_zIndex","get_zIndex" => "get_zIndex","set_marginLeft" => "set_marginLeft","get_marginLeft" => "get_marginLeft","set_marginRight" => "set_marginRight","get_marginRight" => "get_marginRight","set_marginTop" => "set_marginTop","get_marginTop" => "get_marginTop","set_marginBottom" => "set_marginBottom","get_marginBottom" => "get_marginBottom","set_paddingLeft" => "set_paddingLeft","get_paddingLeft" => "get_paddingLeft","set_paddingRight" => "set_paddingRight","get_paddingRight" => "get_paddingRight","set_paddingTop" => "set_paddingTop","get_paddingTop" => "get_paddingTop","set_paddingBottom" => "set_paddingBottom","get_paddingBottom" => "get_paddingBottom","set_width" => "set_width","get_width" => "get_width","set_height" => "set_height","get_height" => "get_height","set_minHeight" => "set_minHeight","get_minHeight" => "get_minHeight","set_maxHeight" => "set_maxHeight","get_maxHeight" => "get_maxHeight","set_minWidth" => "set_minWidth","get_minWidth" => "get_minWidth","set_maxWidth" => "set_maxWidth","get_maxWidth" => "get_maxWidth","set_top" => "set_top","get_top" => "get_top","set_left" => "set_left","get_left" => "get_left","set_bottom" => "set_bottom","get_bottom" => "get_bottom","set_right" => "set_right","get_right" => "get_right","set_backgroundColor" => "set_backgroundColor","get_backgroundColor" => "get_backgroundColor","set_backgroundImage" => "set_backgroundImage","get_backgroundImage" => "get_backgroundImage","set_backgroundRepeat" => "set_backgroundRepeat","get_backgroundRepeat" => "get_backgroundRepeat","set_backgroundOrigin" => "set_backgroundOrigin","get_backgroundOrigin" => "get_backgroundOrigin","set_backgroundSize" => "set_backgroundSize","get_backgroundSize" => "get_backgroundSize","set_backgroundPosition" => "set_backgroundPosition","get_backgroundPosition" => "get_backgroundPosition","set_backgroundClip" => "set_backgroundClip","get_backgroundClip" => "get_backgroundClip","set_fontSize" => "set_fontSize","get_fontSize" => "get_fontSize","set_fontWeight" => "set_fontWeight","get_fontWeight" => "get_fontWeight","set_fontStyle" => "set_fontStyle","get_fontStyle" => "get_fontStyle","set_fontFamily" => "set_fontFamily","get_fontFamily" => "get_fontFamily","set_fontVariant" => "set_fontVariant","get_fontVariant" => "get_fontVariant","set_color" => "set_color","get_color" => "get_color","set_lineHeight" => "set_lineHeight","get_lineHeight" => "get_lineHeight","set_textTransform" => "set_textTransform","get_textTransform" => "get_textTransform","set_letterSpacing" => "set_letterSpacing","get_letterSpacing" => "get_letterSpacing","set_wordSpacing" => "set_wordSpacing","get_wordSpacing" => "get_wordSpacing","set_whiteSpace" => "set_whiteSpace","get_whiteSpace" => "get_whiteSpace","set_textAlign" => "set_textAlign","get_textAlign" => "get_textAlign","set_textIndent" => "set_textIndent","get_textIndent" => "get_textIndent","set_verticalAlign" => "set_verticalAlign","get_verticalAlign" => "get_verticalAlign","set_opacity" => "set_opacity","get_opacity" => "get_opacity","set_visibility" => "set_visibility","get_visibility" => "get_visibility","set_overflowX" => "set_overflowX","get_overflowX" => "get_overflowX","set_overflowY" => "set_overflowY","get_overflowY" => "get_overflowY","set_transitionProperty" => "set_transitionProperty","get_transitionProperty" => "get_transitionProperty","set_transitionDuration" => "set_transitionDuration","get_transitionDuration" => "get_transitionDuration","set_transitionTimingFunction" => "set_transitionTimingFunction","get_transitionTimingFunction" => "get_transitionTimingFunction","set_transitionDelay" => "set_transitionDelay","get_transitionDelay" => "get_transitionDelay","set_transform" => "set_transform","get_transform" => "get_transform","set_transformOrigin" => "set_transformOrigin","get_transformOrigin" => "get_transformOrigin","set_cursor" => "set_cursor","get_cursor" => "get_cursor");
	function __toString() { return 'cocktail.core.style.adapter.Style'; }
}
