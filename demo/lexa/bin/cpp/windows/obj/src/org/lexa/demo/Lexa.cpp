#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_core_dom_CharacterData
#include <core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_core_dom_Document
#include <core/dom/Document.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_Text
#include <core/dom/Text.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLAnchorElement
#include <core/html/AbstractHTMLAnchorElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLImageElement
#include <core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_html_HTMLDocument
#include <core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_Dimension
#include <core/style/Dimension.h>
#endif
#ifndef INCLUDED_core_style_Display
#include <core/style/Display.h>
#endif
#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_FontSize
#include <core/style/FontSize.h>
#endif
#ifndef INCLUDED_core_style_Margin
#include <core/style/Margin.h>
#endif
#ifndef INCLUDED_core_style_Padding
#include <core/style/Padding.h>
#endif
#ifndef INCLUDED_core_style_TextAlign
#include <core/style/TextAlign.h>
#endif
#ifndef INCLUDED_core_unit_CSSColor
#include <core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_core_unit_ColorKeyword
#include <core/unit/ColorKeyword.h>
#endif
#ifndef INCLUDED_core_unit_Length
#include <core/unit/Length.h>
#endif
#ifndef INCLUDED_org_lexa_demo_Lexa
#include <org/lexa/demo/Lexa.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLAnchorElement
#include <port/flash_player/HTMLAnchorElement.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
#ifndef INCLUDED_port_flash_player_Text
#include <port/flash_player/Text.h>
#endif
namespace org{
namespace lexa{
namespace demo{

Void Lexa_obj::__construct()
{
	return null();
}

Lexa_obj::~Lexa_obj() { }

Dynamic Lexa_obj::__CreateEmpty() { return  new Lexa_obj; }
hx::ObjectPtr< Lexa_obj > Lexa_obj::__new()
{  hx::ObjectPtr< Lexa_obj > result = new Lexa_obj();
	result->__construct();
	return result;}

Dynamic Lexa_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lexa_obj > result = new Lexa_obj();
	result->__construct();
	return result;}

Void Lexa_obj::main( ){
{
		HX_SOURCE_PUSH("Lexa_obj::main")
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",27)
		::port::flash_player::HTMLElement site = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("div"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",29)
		site->get_style()->setWidth(::core::style::Dimension_obj::percent((int)30));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",30)
		site->get_style()->setMarginLeft(site->get_style()->setMarginRight(::core::style::Margin_obj::cssAuto_dyn()));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",32)
		::port::flash_player::HTMLElement title = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("h1"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",33)
		title->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Cocktail")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",34)
		title->get_style()->setColor(::core::unit::CSSColor_obj::keyword(::core::unit::ColorKeyword_obj::orange_dyn()));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",35)
		title->get_style()->setFontSize(::core::style::FontSize_obj::length(::core::unit::Length_obj::px((int)48)));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",36)
		title->get_style()->setTextAlign(::core::style::TextAlign_obj::center_dyn());
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",38)
		::port::flash_player::HTMLElement subTitle = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("h2"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",39)
		subTitle->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("cross-platform haXe UIs")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",40)
		subTitle->get_style()->setFontSize(::core::style::FontSize_obj::length(::core::unit::Length_obj::px((int)36)));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",41)
		subTitle->get_style()->setTextAlign(::core::style::TextAlign_obj::center_dyn());
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",44)
		title->get_style()->setFontFamily(subTitle->get_style()->setFontFamily(Array_obj< ::core::style::FontFamily >::__new().Add(::core::style::FontFamily_obj::familyName(HX_CSTRING("arial")))));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",46)
		::core::html::AbstractHTMLImageElement logo = ::core::html::AbstractHTMLImageElement_obj::__new();
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",47)
		logo->set_src(HX_CSTRING("cocktail.jpg"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",48)
		logo->get_style()->setBackgroundColor(::core::unit::CSSColor_obj::keyword(::core::unit::ColorKeyword_obj::gray_dyn()));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",50)
		::port::flash_player::HTMLElement text = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("p"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",51)
		text->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe.")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",52)
		text->get_style()->setBackgroundColor(::core::unit::CSSColor_obj::keyword(::core::unit::ColorKeyword_obj::orange_dyn()));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",53)
		text->get_style()->setColor(::core::unit::CSSColor_obj::hex(HX_CSTRING("#FFFFFF")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",54)
		text->get_style()->setPaddingLeft(text->get_style()->setPaddingTop(text->get_style()->setPaddingBottom(text->get_style()->setPaddingRight(::core::style::Padding_obj::length(::core::unit::Length_obj::px((int)10))))));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",56)
		::port::flash_player::HTMLAnchorElement logoContainer = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("a"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",57)
		logoContainer->get_style()->setTextAlign(::core::style::TextAlign_obj::center_dyn());
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",58)
		logoContainer->appendChild(logo);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",59)
		logoContainer->get_style()->setDisplay(::core::style::Display_obj::block_dyn());
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",60)
		logoContainer->set_href(HX_CSTRING("http://www.silexlabs.org/groups/labs/cocktail/"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",62)
		site->appendChild(title);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",63)
		site->appendChild(subTitle);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",64)
		site->appendChild(text);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",65)
		site->appendChild(logoContainer);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",67)
		::cocktail::Lib_obj::get_document()->get_body()->appendChild(site);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lexa_obj,main,(void))


Lexa_obj::Lexa_obj()
{
}

void Lexa_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lexa);
	HX_MARK_END_CLASS();
}

Dynamic Lexa_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lexa_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Lexa_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Lexa_obj::__mClass;

void Lexa_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("org.lexa.demo.Lexa"), hx::TCanCast< Lexa_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lexa_obj::__boot()
{
}

} // end namespace org
} // end namespace lexa
} // end namespace demo
