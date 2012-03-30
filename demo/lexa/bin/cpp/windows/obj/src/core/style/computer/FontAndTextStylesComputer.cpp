#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_FontSize
#include <core/style/FontSize.h>
#endif
#ifndef INCLUDED_core_style_FontStyle
#include <core/style/FontStyle.h>
#endif
#ifndef INCLUDED_core_style_FontVariant
#include <core/style/FontVariant.h>
#endif
#ifndef INCLUDED_core_style_FontWeight
#include <core/style/FontWeight.h>
#endif
#ifndef INCLUDED_core_style_LetterSpacing
#include <core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_core_style_LineHeight
#include <core/style/LineHeight.h>
#endif
#ifndef INCLUDED_core_style_TextAlign
#include <core/style/TextAlign.h>
#endif
#ifndef INCLUDED_core_style_TextIndent
#include <core/style/TextIndent.h>
#endif
#ifndef INCLUDED_core_style_TextTransform
#include <core/style/TextTransform.h>
#endif
#ifndef INCLUDED_core_style_VerticalAlign
#include <core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_core_style_WhiteSpace
#include <core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_core_style_WordSpacing
#include <core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_core_style_computer_FontAndTextStylesComputer
#include <core/style/computer/FontAndTextStylesComputer.h>
#endif
#ifndef INCLUDED_core_unit_CSSColor
#include <core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_core_unit_FontSizeAbsoluteSize
#include <core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_core_unit_FontSizeRelativeSize
#include <core/unit/FontSizeRelativeSize.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
#ifndef INCLUDED_core_unit_UnitManager
#include <core/unit/UnitManager.h>
#endif
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

Void FontAndTextStylesComputer_obj::compute( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",47)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",49)
		if (((containingHTMLElementFontMetricsData != null()))){
			HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",50)
			computedStyle->__FieldRef(HX_CSTRING("fontSize")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedFontSize(style,containingHTMLElementFontMetricsData->__Field(HX_CSTRING("fontSize")),containingHTMLElementFontMetricsData->__Field(HX_CSTRING("xHeight")));
		}
		else{
			HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",55)
			computedStyle->__FieldRef(HX_CSTRING("fontSize")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedFontSize(style,12.0,10.0);
		}
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",61)
		computedStyle->__FieldRef(HX_CSTRING("lineHeight")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedLineHeight(style);
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",64)
		computedStyle->__FieldRef(HX_CSTRING("verticalAlign")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedVerticalAlign(style,containingHTMLElementData,containingHTMLElementFontMetricsData);
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",67)
		computedStyle->__FieldRef(HX_CSTRING("fontWeight")) = style->getFontWeight();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",70)
		computedStyle->__FieldRef(HX_CSTRING("fontStyle")) = style->getFontStyle();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",73)
		computedStyle->__FieldRef(HX_CSTRING("fontFamily")) = style->getFontFamily();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",76)
		computedStyle->__FieldRef(HX_CSTRING("fontVariant")) = style->getFontVariant();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",79)
		computedStyle->__FieldRef(HX_CSTRING("textTransform")) = style->getTextTransform();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",82)
		computedStyle->__FieldRef(HX_CSTRING("letterSpacing")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedLetterSpacing(style);
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",85)
		computedStyle->__FieldRef(HX_CSTRING("wordSpacing")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedWordSpacing(style);
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",88)
		computedStyle->__FieldRef(HX_CSTRING("textIndent")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedTextIndent(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",91)
		computedStyle->__FieldRef(HX_CSTRING("whiteSpace")) = style->getWhiteSpace();
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",94)
		computedStyle->__FieldRef(HX_CSTRING("textAlign")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedTextAlign(style,computedStyle->__Field(HX_CSTRING("whiteSpace")));
		HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",97)
		computedStyle->__FieldRef(HX_CSTRING("color")) = ::core::style::computer::FontAndTextStylesComputer_obj::getComputedColor(style);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FontAndTextStylesComputer_obj,compute,(void))

int FontAndTextStylesComputer_obj::getComputedTextIndent( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedTextIndent")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",110)
	double textIndent;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",112)
	{
::core::style::TextIndent _switch_1 = (style->getTextIndent());
		switch((_switch_1)->GetIndex()){
			case 0: {
				::core::unit::Length value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",114)
					textIndent = ::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 1: {
				int value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",117)
					textIndent = ::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementData->__Field(HX_CSTRING("width")));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",121)
	return ::Math_obj::round(textIndent);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FontAndTextStylesComputer_obj,getComputedTextIndent,return )

double FontAndTextStylesComputer_obj::getComputedVerticalAlign( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedVerticalAlign")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",130)
	double verticalAlign;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",132)
	{
::core::style::VerticalAlign _switch_2 = (style->getVerticalAlign());
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",134)
				verticalAlign = (int)0;
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",138)
				int offsetHeight = ((style->getComputedStyle()->__Field(HX_CSTRING("height")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom")));
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",139)
				verticalAlign = ((double(offsetHeight) / double((int)2)) + (double(containingHTMLElementFontMetricsData->__Field(HX_CSTRING("xHeight"))) / double((int)2)));
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",141)
				verticalAlign = containingHTMLElementFontMetricsData->__Field(HX_CSTRING("subscriptOffset"));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",144)
				verticalAlign = containingHTMLElementFontMetricsData->__Field(HX_CSTRING("superscriptOffset"));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",147)
				verticalAlign = (int)0;
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",151)
				verticalAlign = (int)0;
			}
			;break;
			case 8: {
				int value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",155)
					verticalAlign = ::core::unit::UnitManager_obj::getPixelFromPercent(value,::Math_obj::round(style->getComputedStyle()->__Field(HX_CSTRING("lineHeight"))));
				}
			}
			;break;
			case 9: {
				::core::unit::Length value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",158)
					verticalAlign = ::core::unit::UnitManager_obj::getPixelFromLength(value,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",161)
				verticalAlign = (int)0;
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",163)
				verticalAlign = (int)0;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",167)
	return verticalAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FontAndTextStylesComputer_obj,getComputedVerticalAlign,return )

::core::style::TextAlign FontAndTextStylesComputer_obj::getComputedTextAlign( ::core::style::AbstractStyle style,::core::style::WhiteSpace computedWhiteSpace){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedTextAlign")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",177)
	::core::style::TextAlign textAlign = style->getTextAlign();
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",179)
	{
::core::style::WhiteSpace _switch_3 = (computedWhiteSpace);
		switch((_switch_3)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",181)
				if (((style->getTextAlign() == ::core::style::TextAlign_obj::justify_dyn()))){
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",183)
					textAlign = ::core::style::TextAlign_obj::left_dyn();
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",191)
	return textAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FontAndTextStylesComputer_obj,getComputedTextAlign,return )

Dynamic FontAndTextStylesComputer_obj::getComputedColor( ::core::style::AbstractStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedColor")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",198)
	return ::core::unit::UnitManager_obj::getColorDataFromCSSColor(style->getColor());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedColor,return )

int FontAndTextStylesComputer_obj::getComputedWordSpacing( ::core::style::AbstractStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedWordSpacing")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",208)
	int wordSpacing;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",210)
	{
::core::style::WordSpacing _switch_4 = (style->getWordSpacing());
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",212)
				wordSpacing = (int)0;
			}
			;break;
			case 1: {
				::core::unit::Length unit = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",215)
					wordSpacing = ::Math_obj::round(::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getComputedStyle()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight"))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",219)
	return wordSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedWordSpacing,return )

double FontAndTextStylesComputer_obj::getComputedLineHeight( ::core::style::AbstractStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedLineHeight")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",228)
	double lineHeight;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",230)
	{
::core::style::LineHeight _switch_5 = (style->getLineHeight());
		switch((_switch_5)->GetIndex()){
			case 2: {
				::core::unit::Length unit = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",232)
					lineHeight = ::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getComputedStyle()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				}
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",235)
				lineHeight = (style->getComputedStyle()->__Field(HX_CSTRING("fontSize")) * 1.2);
			}
			;break;
			case 3: {
				int value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",238)
					lineHeight = ::core::unit::UnitManager_obj::getPixelFromPercent(value,::Math_obj::round(style->getComputedStyle()->__Field(HX_CSTRING("fontSize"))));
				}
			}
			;break;
			case 1: {
				double value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",241)
					lineHeight = (style->getComputedStyle()->__Field(HX_CSTRING("fontSize")) * value);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",245)
	return lineHeight;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedLineHeight,return )

int FontAndTextStylesComputer_obj::getComputedLetterSpacing( ::core::style::AbstractStyle style){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedLetterSpacing")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",255)
	int letterSpacing;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",257)
	{
::core::style::LetterSpacing _switch_6 = (style->getLetterSpacing());
		switch((_switch_6)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",259)
				letterSpacing = (int)0;
			}
			;break;
			case 1: {
				::core::unit::Length unit = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",262)
					letterSpacing = ::Math_obj::round(::core::unit::UnitManager_obj::getPixelFromLength(unit,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight"))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",266)
	return letterSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FontAndTextStylesComputer_obj,getComputedLetterSpacing,return )

double FontAndTextStylesComputer_obj::getComputedFontSize( ::core::style::AbstractStyle style,double parentFontSize,double parentXHeight){
	HX_SOURCE_PUSH("FontAndTextStylesComputer_obj::getComputedFontSize")
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",274)
	double fontSize;
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",276)
	{
::core::style::FontSize _switch_7 = (style->getFontSize());
		switch((_switch_7)->GetIndex()){
			case 0: {
				::core::unit::Length unit = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",278)
					fontSize = ::core::unit::UnitManager_obj::getPixelFromLength(unit,parentFontSize,parentXHeight);
				}
			}
			;break;
			case 1: {
				int percent = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",281)
					fontSize = ::core::unit::UnitManager_obj::getPixelFromPercent(percent,::Math_obj::round(parentFontSize));
				}
			}
			;break;
			case 2: {
				::core::unit::FontSizeAbsoluteSize value = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",284)
					fontSize = ::core::unit::UnitManager_obj::getFontSizeFromAbsoluteSizeValue(value);
				}
			}
			;break;
			case 3: {
				::core::unit::FontSizeRelativeSize value = _switch_7->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",287)
					fontSize = ::core::unit::UnitManager_obj::getFontSizeFromRelativeSizeValue(value,parentFontSize);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/FontAndTextStylesComputer.hx",292)
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.FontAndTextStylesComputer"), hx::TCanCast< FontAndTextStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontAndTextStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
