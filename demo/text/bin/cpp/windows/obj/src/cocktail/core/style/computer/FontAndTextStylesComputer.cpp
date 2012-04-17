#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontSize
#include <cocktail/core/style/FontSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontStyle
#include <cocktail/core/style/FontStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontVariant
#include <cocktail/core/style/FontVariant.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LetterSpacing
#include <cocktail/core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LineHeight
#include <cocktail/core/style/LineHeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextAlign
#include <cocktail/core/style/TextAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextIndent
#include <cocktail/core/style/TextIndent.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_VerticalAlign
#include <cocktail/core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WhiteSpace
#include <cocktail/core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WordSpacing
#include <cocktail/core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_FontAndTextStylesComputer
#include <cocktail/core/style/computer/FontAndTextStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize
#include <cocktail/core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeRelativeSize
#include <cocktail/core/unit/FontSizeRelativeSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{

Void FontAndTextStylesComputer_obj::__construct()
{
{
}
;
	return null();
}

FontAndTextStylesComputer_obj::~FontAndTextStylesComputer_obj() { }

Dynamic FontAndTextStylesComputer_obj::__CreateEmpty() { return  new FontAndTextStylesComputer_obj; }
hx::ObjectPtr< FontAndTextStylesComputer_obj > FontAndTextStylesComputer_obj::__new()
{  hx::ObjectPtr< FontAndTextStylesComputer_obj > result = new FontAndTextStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic FontAndTextStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontAndTextStylesComputer_obj > result = new FontAndTextStylesComputer_obj();
	result->__construct();
	return result;}

Void FontAndTextStylesComputer_obj::compute( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",48)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",50)
		if (((containingHTMLElementFontMetricsData != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",51)
			computedStyle->__FieldRef(HX_CSTRING("fontSize")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedFontSize(style,containingHTMLElementFontMetricsData->__Field(HX_CSTRING("fontSize")),containingHTMLElementFontMetricsData->__Field(HX_CSTRING("xHeight")));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",56)
			computedStyle->__FieldRef(HX_CSTRING("fontSize")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedFontSize(style,12.0,10.0);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",62)
		computedStyle->__FieldRef(HX_CSTRING("lineHeight")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedLineHeight(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",65)
		computedStyle->__FieldRef(HX_CSTRING("verticalAlign")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedVerticalAlign(style,containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",68)
		computedStyle->__FieldRef(HX_CSTRING("fontWeight")) = style->getFontWeight();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",71)
		computedStyle->__FieldRef(HX_CSTRING("fontStyle")) = style->getFontStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",74)
		computedStyle->__FieldRef(HX_CSTRING("fontFamily")) = style->getFontFamily();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",77)
		computedStyle->__FieldRef(HX_CSTRING("fontVariant")) = style->getFontVariant();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",80)
		computedStyle->__FieldRef(HX_CSTRING("textTransform")) = style->getTextTransform();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",83)
		computedStyle->__FieldRef(HX_CSTRING("letterSpacing")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedLetterSpacing(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",86)
		computedStyle->__FieldRef(HX_CSTRING("wordSpacing")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedWordSpacing(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",89)
		computedStyle->__FieldRef(HX_CSTRING("textIndent")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedTextIndent(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",92)
		computedStyle->__FieldRef(HX_CSTRING("whiteSpace")) = style->getWhiteSpace();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",95)
		computedStyle->__FieldRef(HX_CSTRING("textAlign")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedTextAlign(style,computedStyle->__Field(HX_CSTRING("whiteSpace")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",98)
		computedStyle->__FieldRef(HX_CSTRING("color")) = ::cocktail::core::style::computer::FontAndTextStylesComputer_obj::getComputedColor(style);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FontAndTextStylesComputer_obj,compute,(void))

int FontAndTextStylesComputer_obj::getComputedTextIndent( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedTextIndent")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",111)
	double textIndent;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",113)
	{
::cocktail::core::style::TextIndent _switch_1 = (style->getTextIndent());
		switch((_switch_1)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",115)
					textIndent = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 1: {
				int value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",118)
					textIndent = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementData->__Field(HX_CSTRING("width")));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",122)
	return ::Math_obj::round(textIndent);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FontAndTextStylesComputer_obj,getComputedTextIndent,return )

double FontAndTextStylesComputer_obj::getComputedVerticalAlign( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedVerticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",131)
	double verticalAlign;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",133)
	{
::cocktail::core::style::VerticalAlign _switch_2 = (style->getVerticalAlign());
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",135)
				verticalAlign = (int)0;
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",139)
				int offsetHeight = ((style->getComputedStyle()->__Field(HX_CSTRING("height")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",140)
				verticalAlign = ((double(offsetHeight) / double((int)2)) + (double(containingHTMLElementFontMetricsData->__Field(HX_CSTRING("xHeight"))) / double((int)2)));
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",142)
				verticalAlign = containingHTMLElementFontMetricsData->__Field(HX_CSTRING("subscriptOffset"));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",145)
				verticalAlign = containingHTMLElementFontMetricsData->__Field(HX_CSTRING("superscriptOffset"));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",148)
				verticalAlign = (int)0;
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",152)
				verticalAlign = (int)0;
			}
			;break;
			case 8: {
				int value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",156)
					verticalAlign = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,::Math_obj::round(style->getComputedStyle()->__Field(HX_CSTRING("lineHeight"))));
				}
			}
			;break;
			case 9: {
				::cocktail::core::unit::Length value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",159)
					verticalAlign = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",162)
				verticalAlign = (int)0;
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",164)
				verticalAlign = (int)0;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",168)
	return verticalAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FontAndTextStylesComputer_obj,getComputedVerticalAlign,return )

::cocktail::core::style::TextAlign FontAndTextStylesComputer_obj::getComputedTextAlign( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::WhiteSpace computedWhiteSpace){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedTextAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",178)
	::cocktail::core::style::TextAlign textAlign = style->getTextAlign();
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",180)
	{
::cocktail::core::style::WhiteSpace _switch_3 = (computedWhiteSpace);
		switch((_switch_3)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",182)
				if (((style->getTextAlign() == ::cocktail::core::style::TextAlign_obj::justify_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",184)
					textAlign = ::cocktail::core::style::TextAlign_obj::left_dyn();
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",192)
	return textAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FontAndTextStylesComputer_obj,getComputedTextAlign,return )

Dynamic FontAndTextStylesComputer_obj::getComputedColor( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",199)
	return ::cocktail::core::unit::UnitManager_obj::getColorDataFromCSSColor(style->getColor());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedColor,return )

int FontAndTextStylesComputer_obj::getComputedWordSpacing( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedWordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",209)
	int wordSpacing;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",211)
	{
::cocktail::core::style::WordSpacing _switch_4 = (style->getWordSpacing());
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",213)
				wordSpacing = (int)0;
			}
			;break;
			case 1: {
				::cocktail::core::unit::Length unit = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",216)
					wordSpacing = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getComputedStyle()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight"))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",220)
	return wordSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedWordSpacing,return )

double FontAndTextStylesComputer_obj::getComputedLineHeight( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedLineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",229)
	double lineHeight;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",231)
	{
::cocktail::core::style::LineHeight _switch_5 = (style->getLineHeight());
		switch((_switch_5)->GetIndex()){
			case 2: {
				::cocktail::core::unit::Length unit = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",233)
					lineHeight = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getComputedStyle()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",236)
				lineHeight = (style->getComputedStyle()->__Field(HX_CSTRING("fontSize")) * 1.2);
			}
			;break;
			case 3: {
				int value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",239)
					lineHeight = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,::Math_obj::round(style->getComputedStyle()->__Field(HX_CSTRING("fontSize"))));
				}
			}
			;break;
			case 1: {
				double value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",242)
					lineHeight = (style->getComputedStyle()->__Field(HX_CSTRING("fontSize")) * value);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",246)
	return lineHeight;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedLineHeight,return )

int FontAndTextStylesComputer_obj::getComputedLetterSpacing( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedLetterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",256)
	int letterSpacing;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",258)
	{
::cocktail::core::style::LetterSpacing _switch_6 = (style->getLetterSpacing());
		switch((_switch_6)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",260)
				letterSpacing = (int)0;
			}
			;break;
			case 1: {
				::cocktail::core::unit::Length unit = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",263)
					letterSpacing = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight"))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",267)
	return letterSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedLetterSpacing,return )

double FontAndTextStylesComputer_obj::getComputedFontSize( ::cocktail::core::style::CoreStyle style,double parentFontSize,double parentXHeight){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",275)
	double fontSize;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",277)
	{
::cocktail::core::style::FontSize _switch_7 = (style->getFontSize());
		switch((_switch_7)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",279)
					fontSize = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(unit,parentFontSize,parentXHeight);
				}
			}
			;break;
			case 1: {
				int percent = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",282)
					fontSize = ::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(percent,::Math_obj::round(parentFontSize));
				}
			}
			;break;
			case 2: {
				::cocktail::core::unit::FontSizeAbsoluteSize value = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",285)
					fontSize = ::cocktail::core::unit::UnitManager_obj::getFontSizeFromAbsoluteSizeValue(value);
				}
			}
			;break;
			case 3: {
				::cocktail::core::unit::FontSizeRelativeSize value = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",288)
					fontSize = ::cocktail::core::unit::UnitManager_obj::getFontSizeFromRelativeSizeValue(value,parentFontSize);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/FontAndTextStylesComputer.hx",293)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FontAndTextStylesComputer_obj,getComputedFontSize,return )


FontAndTextStylesComputer_obj::FontAndTextStylesComputer_obj()
{
}

void FontAndTextStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontAndTextStylesComputer);
	HX_MARK_END_CLASS();
}

Dynamic FontAndTextStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getComputedColor") ) { return getComputedColor_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getComputedFontSize") ) { return getComputedFontSize_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedTextAlign") ) { return getComputedTextAlign_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedTextIndent") ) { return getComputedTextIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedLineHeight") ) { return getComputedLineHeight_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getComputedWordSpacing") ) { return getComputedWordSpacing_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getComputedVerticalAlign") ) { return getComputedVerticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedLetterSpacing") ) { return getComputedLetterSpacing_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FontAndTextStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FontAndTextStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compute"),
	HX_CSTRING("getComputedTextIndent"),
	HX_CSTRING("getComputedVerticalAlign"),
	HX_CSTRING("getComputedTextAlign"),
	HX_CSTRING("getComputedColor"),
	HX_CSTRING("getComputedWordSpacing"),
	HX_CSTRING("getComputedLineHeight"),
	HX_CSTRING("getComputedLetterSpacing"),
	HX_CSTRING("getComputedFontSize"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FontAndTextStylesComputer_obj::__mClass;

void FontAndTextStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.FontAndTextStylesComputer"), hx::TCanCast< FontAndTextStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontAndTextStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
