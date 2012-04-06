#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLImageElement
#include <cocktail/core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_style_adapter_Style
#include <cocktail/core/style/adapter/Style.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
#ifndef INCLUDED_org_lexa_demo_Lexa
#include <org/lexa/demo/Lexa.h>
#endif
namespace org{
namespace lexa{
namespace demo{

Void Lexa_obj::__construct()
{
{
}
;
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

Void Lexa_obj::prezCocktail( ){
{
		HX_SOURCE_PUSH("Lexa_obj::prezCocktail")
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",34)
		::cocktail::port::flash_player::HTMLElement title = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("h1"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",35)
		title->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Hello Cocktail")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",36)
		::cocktail::Lib_obj::get_document()->get_body()->appendChild(title);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",39)
		::cocktail::port::flash_player::HTMLElement paragraph = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("p"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",40)
		paragraph->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe.")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",41)
		::cocktail::Lib_obj::get_document()->get_body()->appendChild(paragraph);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",44)
		title->get_style()->set_wordSpacing(HX_CSTRING("10px"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",45)
		title->get_style()->set_color(HX_CSTRING("orange"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",46)
		title->get_style()->set_fontFamily(HX_CSTRING("arial"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",49)
		::cocktail::core::html::AbstractHTMLImageElement img = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("img"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",50)
		img->set_src(HX_CSTRING("cocktail.jpg"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",51)
		paragraph->appendChild(img);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",54)
		::cocktail::port::flash_player::HTMLElement site = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("div"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",55)
		site->appendChild(title);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",56)
		site->appendChild(paragraph);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",58)
		site->get_style()->set_width(HX_CSTRING("50%"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",59)
		site->get_style()->set_marginLeft(site->get_style()->set_marginRight(HX_CSTRING("auto")));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",61)
		::cocktail::Lib_obj::get_document()->get_body()->appendChild(site);
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",64)
		site->get_style()->set_backgroundColor(HX_CSTRING("rgba(255,255,255,0.5)"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",65)
		::cocktail::Lib_obj::get_document()->get_body()->get_style()->set_backgroundImage(HX_CSTRING("url(bg.png)"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Lexa_obj,prezCocktail,(void))

Void Lexa_obj::main( ){
{
		HX_SOURCE_PUSH("Lexa_obj::main")
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",22)
		::org::lexa::demo::Lexa lx = ::org::lexa::demo::Lexa_obj::__new();
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",23)
		lx->prezCocktail();
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
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"prezCocktail") ) { return prezCocktail_dyn(); }
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
	HX_CSTRING("prezCocktail"),
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
