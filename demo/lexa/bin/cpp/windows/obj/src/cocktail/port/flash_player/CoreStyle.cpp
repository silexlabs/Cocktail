#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
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
namespace flash_player{

Void CoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",81)
	super::__construct(htmlElement);
}
;
	return null();
}

CoreStyle_obj::~CoreStyle_obj() { }

Dynamic CoreStyle_obj::__CreateEmpty() { return  new CoreStyle_obj; }
hx::ObjectPtr< CoreStyle_obj > CoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< CoreStyle_obj > result = new CoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic CoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CoreStyle_obj > result = new CoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic CoreStyle_obj::getFontMetricsData( ){
	HX_SOURCE_PUSH("CoreStyle_obj::getFontMetricsData")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",249)
	if (((this->_fontMetrics == null()))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",251)
		::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",252)
		textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",254)
		::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",255)
		textFormat->size = this->_computedStyle->__Field(HX_CSTRING("fontSize"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",256)
		textFormat->font = this->getNativeFontFamily(this->_fontFamily);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",258)
		textField->setTextFormat(textFormat,null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",260)
		textField->nmeSetText(HX_CSTRING("x"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",262)
		double ascent = (double(textField->nmeGetTextHeight()) / double((int)2));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",263)
		::haxe::Log_obj::trace(ascent,hx::SourceInfo(HX_CSTRING("CoreStyle.hx"),263,HX_CSTRING("cocktail.port.flash_player.CoreStyle"),HX_CSTRING("getFontMetricsData")));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",264)
		textField->nmeSetText(HX_CSTRING(","));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",266)
		double descent = (double(textField->nmeGetTextHeight()) / double((int)2));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",268)
		textField->nmeSetText(HX_CSTRING("x"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",270)
		int xHeight = ::Math_obj::round(textField->nmeGetTextHeight());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",272)
		textField->nmeSetText(HX_CSTRING("M"));
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",273)
		int spaceWidth = ::Math_obj::round(textField->nmeGetTextWidth());
		struct _Function_2_1{
			inline static Dynamic Block( ::cocktail::port::flash_player::CoreStyle_obj *__this,double &ascent,int &xHeight,int &spaceWidth,double &descent){
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
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",276)
		this->_fontMetrics = _Function_2_1::Block(this,ascent,xHeight,spaceWidth,descent);
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",288)
	return this->_fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC0(CoreStyle_obj,getFontMetricsData,return )

::String CoreStyle_obj::getNativeFontFamily( Array< ::String > value){
	HX_SOURCE_PUSH("CoreStyle_obj::getNativeFontFamily")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",297)
	::String fontFamily = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",299)
	::String fontName = value->__get((int)0);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",301)
	::String _switch_1 = (fontName);
	if (  ( _switch_1==HX_CSTRING("serif"))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",303)
		fontName = HX_CSTRING("_serif");
	}
	else if (  ( _switch_1==HX_CSTRING("sans"))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",306)
		fontName = HX_CSTRING("_sans");
	}
	else if (  ( _switch_1==HX_CSTRING("typewriter"))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",309)
		fontName = HX_CSTRING("_typewriter");
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/CoreStyle.hx",313)
	return fontName;
}


HX_DEFINE_DYNAMIC_FUNC1(CoreStyle_obj,getNativeFontFamily,return )

::String CoreStyle_obj::SERIF_GENERIC_FONT_NAME;

::String CoreStyle_obj::SERIF_FLASH_FONT_NAME;

::String CoreStyle_obj::SANS_SERIF_GENERIC_FONT_NAME;

::String CoreStyle_obj::SANS_SERIF_FLASH_FONT_NAME;

::String CoreStyle_obj::MONOSPACE_GENERIC_FONT_NAME;

::String CoreStyle_obj::MONOSPACE_FLASH_FONT_NAME;


CoreStyle_obj::CoreStyle_obj()
{
}

void CoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic CoreStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"getFontMetricsData") ) { return getFontMetricsData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { return SERIF_FLASH_FONT_NAME; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { return SERIF_GENERIC_FONT_NAME; }
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

Dynamic CoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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

void CoreStyle_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("getFontMetricsData"),
	HX_CSTRING("getNativeFontFamily"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CoreStyle_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(CoreStyle_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(CoreStyle_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(CoreStyle_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(CoreStyle_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(CoreStyle_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

Class CoreStyle_obj::__mClass;

void CoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.CoreStyle"), hx::TCanCast< CoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void CoreStyle_obj::__boot()
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
} // end namespace flash_player
