#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_adapter_AbstractStyle
#include <cocktail/core/style/adapter/AbstractStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#include <cocktail/port/flash_player/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
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
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",69)
		::cocktail::Lib_obj::get_document()->get_body()->set_innerHTML(HX_CSTRING("<div style=\"width: 50%; margin-right: auto; margin-left: auto; background-color: rgba(255, 255, 255, 0.5);\"><h1 style=\"word-spacing: 10px; color: orange; font-family: arial;\">Hello Cocktail</h1><p>Cocktail is a cross-platform library for the haXe programming language. It focuses on UIs and bridges the gap between all the targets supported by haXe.<img id=\"pic\" src=\"cocktail.jpg\" /></p></div>"));
		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",71)
		::cocktail::port::flash_player::HTMLElement pic = ::cocktail::Lib_obj::get_document()->getElementById(HX_CSTRING("pic"));

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(::cocktail::core::event::MouseEvent e){
{
				HX_SOURCE_POS("org/lexa/demo/Lexa.hx",72)
				::cocktail::Lib_obj::get_document()->get_body()->get_style()->set_backgroundImage(HX_CSTRING("url(bg.png)"));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_SOURCE_POS("org/lexa/demo/Lexa.hx",72)
		pic->set_onClick( Dynamic(new _Function_1_1()));
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
