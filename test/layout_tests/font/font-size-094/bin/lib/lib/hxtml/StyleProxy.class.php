<?php

class lib_hxtml_StyleProxy implements lib_hxtml_IStyleProxy{
	public function __construct() { 
	}
	public function setTransitionTimingFunction($element, $value) {
		$element->style->set_transitionTimingFunction($value);
	}
	public function setTransitionProperty($element, $value) {
		$element->style->set_transitionProperty($value);
	}
	public function setTransitionDelay($element, $value) {
		$element->style->set_transitionDelay($value);
	}
	public function setTransitionDuration($element, $value) {
		$element->style->set_transitionDuration($value);
	}
	public function setOverflowY($element, $value) {
		$element->style->set_overflowY($value);
	}
	public function setOverflowX($element, $value) {
		$element->style->set_overflowX($value);
	}
	public function setZIndex($element, $value) {
		$element->style->set_zIndex($value);
	}
	public function setWhiteSpace($element, $value) {
		$element->style->set_whiteSpace($value);
	}
	public function setVerticalAlignKey($element, $value) {
		$element->style->set_verticalAlign($value);
	}
	public function setVerticalAlignNum($element, $value, $unit) {
		$element->style->set_verticalAlign(_hx_string_rec($value, "") . $unit);
	}
	public function setTextAlign($element, $value) {
		$element->style->set_textAlign($value);
	}
	public function setTextIndent($element, $value, $unit) {
		$element->style->set_textIndent(_hx_string_rec($value, "") . $unit);
	}
	public function setWordSpacingKey($element, $value) {
		$element->style->set_wordSpacing($value);
	}
	public function setWordSpacingNum($element, $value, $unit) {
		$element->style->set_wordSpacing(_hx_string_rec($value, "") . $unit);
	}
	public function setLetterSpacingKey($element, $value) {
		$element->style->set_letterSpacing($value);
	}
	public function setLetterSpacingNum($element, $value, $unit) {
		$element->style->set_letterSpacing(_hx_string_rec($value, "") . $unit);
	}
	public function setTextTransform($element, $value) {
		$element->style->set_textTransform($value);
	}
	public function setLineHeightNum($element, $value, $unit) {
		$element->style->set_lineHeight(_hx_string_rec($value, "") . $unit);
	}
	public function setLineHeightZero($element) {
		$element->style->set_lineHeight("0");
	}
	public function setLineHeightKey($element, $value) {
		$element->style->set_lineHeight($value);
	}
	public function setTextDecoration($element, $value) {
	}
	public function setTextColorRGB($element, $value) {
		$element->style->set_color("rgb(" . $value . ")");
	}
	public function setTextColorRGBA($element, $value) {
		$element->style->set_color("rgba(" . $value . ")");
	}
	public function setTextColorNum($element, $value) {
		$element->style->set_color("#" . Std::string($value));
	}
	public function setTextColorKey($element, $value) {
		$element->style->set_color($value);
	}
	public function setFontVariant($element, $value) {
		$element->style->set_fontVariant($value);
	}
	public function setFontFamily($element, $value) {
		if($value->length > 0) {
			$element->style->set_fontFamily($value->join(","));
		} else {
			$element->style->set_fontFamily("");
		}
	}
	public function setFontStyle($element, $value) {
		$element->style->set_fontStyle($value);
	}
	public function setFontWeightKey($element, $value) {
		$element->style->set_fontWeight($value);
	}
	public function setFontWeightNum($element, $value) {
		$element->style->set_fontWeight(Std::string($value));
	}
	public function setFontSizeKey($element, $value) {
		$element->style->set_fontSize($value);
	}
	public function setFontSizeNum($element, $value, $unit) {
		$element->style->set_fontSize(_hx_string_rec($value, "") . $unit);
	}
	public function setBgPos($element, $value) {
		$element->style->set_backgroundPosition($value);
	}
	public function setBgRepeat($element, $value) {
		$element->style->set_backgroundRepeat($value->join(","));
	}
	public function setBgAttachment($element, $value) {
	}
	public function setBgImage($element, $value) {
		if($value->length === 1) {
			$element->style->set_backgroundImage("url(" . $value[0] . ")");
		} else {
			$element->style->set_backgroundImage("");
		}
	}
	public function setBgColorKey($element, $value) {
		$element->style->set_backgroundColor($value);
	}
	public function setBgColorRGB($element, $value) {
		$element->style->set_backgroundColor("rgb(" . $value . ")");
	}
	public function setBgColorRGBA($element, $value) {
		$element->style->set_backgroundColor("rgba(" . $value . ")");
	}
	public function setBgColorHex($element, $value) {
		$element->style->set_backgroundColor("#" . Std::string($value));
	}
	public function setRightKey($element, $value) {
		$element->style->set_right($value);
	}
	public function setBottomKey($element, $value) {
		$element->style->set_bottom($value);
	}
	public function setLeftKey($element, $value) {
		$element->style->set_left($value);
	}
	public function setTopKey($element, $value) {
		$element->style->set_top($value);
	}
	public function setRightZero($element) {
		$element->style->set_right("0");
	}
	public function setRight($element, $value, $unit) {
		$element->style->set_right(_hx_string_rec($value, "") . $unit);
	}
	public function setBottomZero($element) {
		$element->style->set_bottom("0");
	}
	public function setBottom($element, $value, $unit) {
		$element->style->set_bottom(_hx_string_rec($value, "") . $unit);
	}
	public function setLeftZero($element) {
		$element->style->set_left("0");
	}
	public function setLeft($element, $value, $unit) {
		$element->style->set_left(_hx_string_rec($value, "") . $unit);
	}
	public function setTopZero($element) {
		$element->style->set_top("0");
	}
	public function setTop($element, $value, $unit) {
		$element->style->set_top(_hx_string_rec($value, "") . $unit);
	}
	public function setMaxHeightKey($element, $value) {
		$element->style->set_maxHeight($value);
	}
	public function setMaxWidthKey($element, $value) {
		$element->style->set_maxWidth($value);
	}
	public function setMaxHeightZero($element) {
		$element->style->set_maxHeight("0");
	}
	public function setMinHeightZero($element) {
		$element->style->set_minHeight("0");
	}
	public function setMaxWidthZero($element) {
		$element->style->set_maxWidth("0");
	}
	public function setMinWidthZero($element) {
		$element->style->set_minWidth("0");
	}
	public function setMaxHeight($element, $value, $unit) {
		$element->style->set_maxHeight(_hx_string_rec($value, "") . $unit);
	}
	public function setMaxWidth($element, $value, $unit) {
		$element->style->set_maxWidth(_hx_string_rec($value, "") . $unit);
	}
	public function setMinHeight($element, $value, $unit) {
		$element->style->set_minHeight(_hx_string_rec($value, "") . $unit);
	}
	public function setMinWidth($element, $value, $unit) {
		$element->style->set_minWidth(_hx_string_rec($value, "") . $unit);
	}
	public function setHeightKey($element, $value) {
		$element->style->set_height($value);
	}
	public function setHeightZero($element) {
		$element->style->set_height("0");
	}
	public function setHeight($element, $value, $unit) {
		$element->style->set_height(_hx_string_rec($value, "") . $unit);
	}
	public function setWidthKey($element, $value) {
		$element->style->set_width($value);
	}
	public function setWidthZero($element) {
		$element->style->set_width("0");
	}
	public function setWidth($element, $value, $unit) {
		$element->style->set_width(_hx_string_rec($value, "") . $unit);
	}
	public function setPaddingBottom($element, $value, $unit) {
		$element->style->set_paddingBottom(_hx_string_rec($value, "") . $unit);
	}
	public function setPaddingRight($element, $value, $unit) {
		$element->style->set_paddingRight(_hx_string_rec($value, "") . $unit);
	}
	public function setPaddingTop($element, $value, $unit) {
		$element->style->set_paddingTop(_hx_string_rec($value, "") . $unit);
	}
	public function setPaddingLeft($element, $value, $unit) {
		$element->style->set_paddingLeft(_hx_string_rec($value, "") . $unit);
	}
	public function setMarginRightZero($element) {
		$element->style->set_marginRight("0");
	}
	public function setMarginTopZero($element) {
		$element->style->set_marginTop("0");
	}
	public function setMarginLeftZero($element) {
		$element->style->set_marginLeft("0");
	}
	public function setMarginBottomZero($element) {
		$element->style->set_marginBottom("0");
	}
	public function setMarginBottomKey($element, $value) {
		$element->style->set_marginBottom($value);
	}
	public function setMarginBottomNum($element, $value, $unit) {
		$element->style->set_marginBottom(_hx_string_rec($value, "") . $unit);
	}
	public function setMarginRightKey($element, $value) {
		$element->style->set_marginRight($value);
	}
	public function setMarginRightNum($element, $value, $unit) {
		$element->style->set_marginRight(_hx_string_rec($value, "") . $unit);
	}
	public function setMarginTopKey($element, $value) {
		$element->style->set_marginTop($value);
	}
	public function setMarginTopNum($element, $value, $unit) {
		$element->style->set_marginTop(_hx_string_rec($value, "") . $unit);
	}
	public function setMarginLeftKey($element, $value) {
		$element->style->set_marginLeft($value);
	}
	public function setMarginLeftNum($element, $value, $unit) {
		$element->style->set_marginLeft(_hx_string_rec($value, "") . $unit);
	}
	public function setTransformOrigin($element, $value) {
		$element->style->set_transformOrigin($value);
	}
	public function setTransform($element, $value) {
		$element->style->set_transform($value);
	}
	public function setClear($element, $value) {
		$element->style->set_clear($value);
	}
	public function setCssFloat($element, $value) {
		$element->style->set_CSSFloat($value);
	}
	public function setPosition($element, $value) {
		$element->style->set_position($value);
	}
	public function setDisplay($element, $value) {
		$element->style->set_display($value);
	}
	function __toString() { return 'lib.hxtml.StyleProxy'; }
}
