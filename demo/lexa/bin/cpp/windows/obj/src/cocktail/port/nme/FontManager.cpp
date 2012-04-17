#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManager
#include <cocktail/core/font/AbstractFontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontStyle
#include <cocktail/core/style/FontStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_port_nme_FontManager
#include <cocktail/port/nme/FontManager.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
#endif
#ifndef INCLUDED_nme_text_TextFieldAutoSize
#include <nme/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_nme_text_TextFormat
#include <nme/text/TextFormat.h>
#endif
namespace cocktail{
namespace port{
namespace nme{

Void FontManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",54)
	super::__construct();
}
;
	return null();
}

FontManager_obj::~FontManager_obj() { }

Dynamic FontManager_obj::__CreateEmpty() { return  new FontManager_obj; }
hx::ObjectPtr< FontManager_obj > FontManager_obj::__new()
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

Dynamic FontManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

Dynamic FontManager_obj::getFontMetrics( ::String fontFamily,double fontSize){
	HX_SOURCE_PUSH("FontManager_obj::getFontMetrics")
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",67)
	::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",68)
	textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",70)
	::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",71)
	textFormat->size = fontSize;
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",73)
	textFormat->font = fontFamily;
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",75)
	textField->setTextFormat(textFormat,null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",77)
	textField->nmeSetText(HX_CSTRING("x"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",79)
	double ascent = (double(textField->nmeGetTextHeight()) / double((int)2));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",80)
	::haxe::Log_obj::trace(ascent,hx::SourceInfo(HX_CSTRING("FontManager.hx"),80,HX_CSTRING("cocktail.port.nme.FontManager"),HX_CSTRING("getFontMetrics")));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",81)
	textField->nmeSetText(HX_CSTRING(","));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",83)
	double descent = (double(textField->nmeGetTextHeight()) / double((int)2));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",85)
	textField->nmeSetText(HX_CSTRING("x"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",87)
	int xHeight = ::Math_obj::round(textField->nmeGetTextHeight());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",89)
	textField->nmeSetText(HX_CSTRING("M"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",90)
	int spaceWidth = ::Math_obj::round(textField->nmeGetTextWidth());
	struct _Function_1_1{
		inline static Dynamic Block( double &ascent,int &xHeight,double &fontSize,int &spaceWidth,double &descent){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("fontSize") , fontSize,false);
			__result->Add(HX_CSTRING("ascent") , ::Math_obj::round(ascent),false);
			__result->Add(HX_CSTRING("descent") , ::Math_obj::round(descent),false);
			__result->Add(HX_CSTRING("xHeight") , xHeight,false);
			__result->Add(HX_CSTRING("spaceWidth") , spaceWidth,false);
			__result->Add(HX_CSTRING("superscriptOffset") , (int)1,false);
			__result->Add(HX_CSTRING("subscriptOffset") , (int)1,false);
			__result->Add(HX_CSTRING("underlineOffset") , (int)1,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",93)
	Dynamic fontMetrics = _Function_1_1::Block(ascent,xHeight,fontSize,spaceWidth,descent);
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",105)
	return fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC2(FontManager_obj,getFontMetrics,return )

Dynamic FontManager_obj::createNativeTextElement( ::String text,Dynamic computedStyle){
	HX_SOURCE_PUSH("FontManager_obj::createNativeTextElement")
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",112)
	text = this->applyTextTransform(text,computedStyle->__Field(HX_CSTRING("textTransform")));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",114)
	::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",115)
	textField->nmeSetText(text);
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",116)
	textField->nmeSetSelectable(false);
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",117)
	textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",118)
	textField->setTextFormat(this->getTextFormat(computedStyle),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",120)
	return textField;
}


HX_DEFINE_DYNAMIC_FUNC2(FontManager_obj,createNativeTextElement,return )

::String FontManager_obj::getNativeFontFamily( Array< ::String > value){
	HX_SOURCE_PUSH("FontManager_obj::getNativeFontFamily")
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",140)
	::String fontFamily = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",142)
	{
		HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",142)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",142)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",142)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",144)
			::String fontName = value->__get(i);
			HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",146)
			::String _switch_1 = (fontName);
			if (  ( _switch_1==HX_CSTRING("serif"))){
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",148)
				fontName = HX_CSTRING("_serif");
			}
			else if (  ( _switch_1==HX_CSTRING("sans"))){
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",151)
				fontName = HX_CSTRING("_sans");
			}
			else if (  ( _switch_1==HX_CSTRING("typewriter"))){
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",154)
				fontName = HX_CSTRING("_typewriter");
			}
			HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",158)
			hx::AddEq(fontFamily,fontName);
			HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",160)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",161)
				hx::AddEq(fontFamily,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",166)
	return fontFamily;
}


HX_DEFINE_DYNAMIC_FUNC1(FontManager_obj,getNativeFontFamily,return )

::nme::text::TextFormat FontManager_obj::getTextFormat( Dynamic computedStyle){
	HX_SOURCE_PUSH("FontManager_obj::getTextFormat")
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",172)
	::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",173)
	textFormat->font = this->getNativeFontFamily(computedStyle->__Field(HX_CSTRING("fontFamily")));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",175)
	textFormat->letterSpacing = computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",176)
	textFormat->size = computedStyle->__Field(HX_CSTRING("fontSize"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",178)
	bool bold;
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",180)
	{
::cocktail::core::style::FontWeight _switch_2 = (computedStyle->__Field(HX_CSTRING("fontWeight")));
		switch((_switch_2)->GetIndex()){
			case 3: case 0: case 4: case 5: case 6: case 7: {
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",182)
				bold = false;
			}
			;break;
			case 1: case 2: case 8: case 9: case 10: case 11: case 12: {
				HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",186)
				bold = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",191)
	textFormat->bold = bold;
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",192)
	textFormat->italic = (computedStyle->__Field(HX_CSTRING("fontStyle")) == ::cocktail::core::style::FontStyle_obj::italic_dyn());
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",194)
	textFormat->letterSpacing = computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",196)
	textFormat->color = computedStyle->__Field(HX_CSTRING("color"))->__Field(HX_CSTRING("color"));
	HX_SOURCE_POS("../../src/cocktail/port/nme/FontManager.hx",197)
	return textFormat;
}


HX_DEFINE_DYNAMIC_FUNC1(FontManager_obj,getTextFormat,return )

::String FontManager_obj::SERIF_GENERIC_FONT_NAME;

::String FontManager_obj::SERIF_FLASH_FONT_NAME;

::String FontManager_obj::SANS_SERIF_GENERIC_FONT_NAME;

::String FontManager_obj::SANS_SERIF_FLASH_FONT_NAME;

::String FontManager_obj::MONOSPACE_GENERIC_FONT_NAME;

::String FontManager_obj::MONOSPACE_FLASH_FONT_NAME;


FontManager_obj::FontManager_obj()
{
}

void FontManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontManager);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FontManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getTextFormat") ) { return getTextFormat_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFontMetrics") ) { return getFontMetrics_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { return SERIF_FLASH_FONT_NAME; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { return SERIF_GENERIC_FONT_NAME; }
		if (HX_FIELD_EQ(inName,"createNativeTextElement") ) { return createNativeTextElement_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { return MONOSPACE_FLASH_FONT_NAME; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { return SANS_SERIF_FLASH_FONT_NAME; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { return MONOSPACE_GENERIC_FONT_NAME; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { return SANS_SERIF_GENERIC_FONT_NAME; }
	}
	return super::__Field(inName);
}

Dynamic FontManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { MONOSPACE_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { SANS_SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { MONOSPACE_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { SANS_SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FontManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("MONOSPACE_GENERIC_FONT_NAME"),
	HX_CSTRING("MONOSPACE_FLASH_FONT_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getFontMetrics"),
	HX_CSTRING("createNativeTextElement"),
	HX_CSTRING("getNativeFontFamily"),
	HX_CSTRING("getTextFormat"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontManager_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManager_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManager_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManager_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManager_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManager_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

Class FontManager_obj::__mClass;

void FontManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.nme.FontManager"), hx::TCanCast< FontManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FontManager_obj::__boot()
{
	hx::Static(SERIF_GENERIC_FONT_NAME) = HX_CSTRING("serif");
	hx::Static(SERIF_FLASH_FONT_NAME) = HX_CSTRING("_serif");
	hx::Static(SANS_SERIF_GENERIC_FONT_NAME) = HX_CSTRING("sans");
	hx::Static(SANS_SERIF_FLASH_FONT_NAME) = HX_CSTRING("_sans");
	hx::Static(MONOSPACE_GENERIC_FONT_NAME) = HX_CSTRING("typewriter");
	hx::Static(MONOSPACE_FLASH_FONT_NAME) = HX_CSTRING("_typewriter");
}

} // end namespace cocktail
} // end namespace port
} // end namespace nme
