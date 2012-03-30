#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_GenericFontFamily
#include <core/style/GenericFontFamily.h>
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
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace port{
namespace flash_player{

Void Style_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",76)
	super::__construct(htmlElement);
}
;
	return null();
}

Style_obj::~Style_obj() { }

Dynamic Style_obj::__CreateEmpty() { return  new Style_obj; }
hx::ObjectPtr< Style_obj > Style_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic Style_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Style_obj::getFontMetricsData( ){
	HX_SOURCE_PUSH("Style_obj::getFontMetricsData")
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",248)
	if (((this->_fontMetrics == null()))){
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",250)
		::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",251)
		textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",253)
		::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",254)
		textFormat->size = this->_computedStyle->__Field(HX_CSTRING("fontSize"));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",255)
		textFormat->font = this->getNativeFontFamily(this->_fontFamily);
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",257)
		textField->setTextFormat(textFormat,null(),null());
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",259)
		textField->nmeSetText(HX_CSTRING("x"));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",261)
		double ascent = (double(textField->nmeGetTextHeight()) / double((int)2));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",262)
		::haxe::Log_obj::trace(ascent,hx::SourceInfo(HX_CSTRING("Style.hx"),262,HX_CSTRING("port.flash_player.Style"),HX_CSTRING("getFontMetricsData")));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",263)
		textField->nmeSetText(HX_CSTRING(","));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",265)
		double descent = (double(textField->nmeGetTextHeight()) / double((int)2));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",267)
		textField->nmeSetText(HX_CSTRING("x"));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",269)
		int xHeight = ::Math_obj::round(textField->nmeGetTextHeight());
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",271)
		textField->nmeSetText(HX_CSTRING("M"));
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",272)
		int spaceWidth = ::Math_obj::round(textField->nmeGetTextWidth());
		struct _Function_2_1{
			inline static Dynamic Block( ::port::flash_player::Style_obj *__this,double &ascent,int &xHeight,int &spaceWidth,double &descent){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("fontSize") , __this->_computedStyle->__Field(HX_CSTRING("fontSize")),false);
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
		HX_SOURCE_POS("../../src/port/flash_player/Style.hx",275)
		this->_fontMetrics = _Function_2_1::Block(this,ascent,xHeight,spaceWidth,descent);
	}
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",287)
	return this->_fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,getFontMetricsData,return )

::String Style_obj::getNativeFontFamily( Array< ::core::style::FontFamily > value){
	HX_SOURCE_PUSH("Style_obj::getNativeFontFamily")
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",296)
	::String fontFamily = HX_CSTRING("");
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",299)
	::String fontName;
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",301)
	{
::core::style::FontFamily _switch_1 = (value->__get((int)0));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::String name = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/port/flash_player/Style.hx",303)
					fontName = name;
				}
			}
			;break;
			case 1: {
				::core::style::GenericFontFamily genericName = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/port/flash_player/Style.hx",306)
					{
::core::style::GenericFontFamily _switch_2 = (genericName);
						switch((_switch_2)->GetIndex()){
							case 0: {
								HX_SOURCE_POS("../../src/port/flash_player/Style.hx",309)
								fontName = HX_CSTRING("_serif");
							}
							;break;
							case 1: {
								HX_SOURCE_POS("../../src/port/flash_player/Style.hx",312)
								fontName = HX_CSTRING("_sans");
							}
							;break;
							case 2: {
								HX_SOURCE_POS("../../src/port/flash_player/Style.hx",315)
								fontName = HX_CSTRING("_typewriter");
							}
							;break;
						}
					}
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/port/flash_player/Style.hx",322)
	return fontName;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,getNativeFontFamily,return )

::String Style_obj::SERIF_GENERIC_FONT_NAME;

::String Style_obj::SANS_SERIF_GENERIC_FONT_NAME;

::String Style_obj::MONOSPACE_GENERIC_FONT_NAME;


Style_obj::Style_obj()
{
}

void Style_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Style);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Style_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"getFontMetricsData") ) { return getFontMetricsData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { return SERIF_GENERIC_FONT_NAME; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { return MONOSPACE_GENERIC_FONT_NAME; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { return SANS_SERIF_GENERIC_FONT_NAME; }
	}
	return super::__Field(inName);
}

Dynamic Style_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { MONOSPACE_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { SANS_SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Style_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("MONOSPACE_GENERIC_FONT_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getFontMetricsData"),
	HX_CSTRING("getNativeFontFamily"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Style_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(Style_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(Style_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
};

Class Style_obj::__mClass;

void Style_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("port.flash_player.Style"), hx::TCanCast< Style_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Style_obj::__boot()
{
	hx::Static(SERIF_GENERIC_FONT_NAME) = HX_CSTRING("_serif");
	hx::Static(SANS_SERIF_GENERIC_FONT_NAME) = HX_CSTRING("_sans");
	hx::Static(MONOSPACE_GENERIC_FONT_NAME) = HX_CSTRING("_typewriter");
}

} // end namespace port
} // end namespace flash_player
