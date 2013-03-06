#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",31);
{
	HX_STACK_LINE(33)
	this->buildDomHaxeJS();
	HX_STACK_LINE(38)
	this->addInteractivity();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::addInteractivity( ){
{
		HX_STACK_PUSH("Main::addInteractivity","Main.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_LINE(99)
		::cocktail::core::html::HTMLElement pic = ::cocktail::Lib_obj::get_document()->getElementById(HX_CSTRING("pic"));		HX_STACK_VAR(pic,"pic");

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(::cocktail::core::event::MouseEvent e){
			HX_STACK_PUSH("*::_Function_1_1","Main.hx",100);
			HX_STACK_ARG(e,"e");
			{
				HX_STACK_LINE(100)
				::cocktail::Lib_obj::get_document()->body->style->set_backgroundImage(HX_CSTRING("url(assets/bg.png)"));
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(100)
		pic->set_onClick( Dynamic(new _Function_1_1()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,addInteractivity,(void))

Void Main_obj::buildDomHtml( ){
{
		HX_STACK_PUSH("Main::buildDomHtml","Main.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_LINE(88)
		::cocktail::Lib_obj::get_document()->body->set_innerHTML(HX_CSTRING("<div style=\"width: 50%; margin-right: auto; margin-left: auto; background-color: rgba(255, 255, 255, 0.5);\"><h1 style=\"word-spacing: 10px; color: orange; font-family: arial;\">Hello Cocktail</h1><p>Cocktail is a HTML rendering engine.<img id=\"pic\" src=\"assets/cocktail.png\" /></p></div>"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,buildDomHtml,(void))

Void Main_obj::buildDomHaxeJS( ){
{
		HX_STACK_PUSH("Main::buildDomHaxeJS","Main.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(49)
		::cocktail::core::html::HTMLElement title = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("h1"));		HX_STACK_VAR(title,"title");
		HX_STACK_LINE(50)
		title->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Hello Cocktail")));
		HX_STACK_LINE(51)
		::cocktail::Lib_obj::get_document()->body->appendChild(title);
		HX_STACK_LINE(54)
		::cocktail::core::html::HTMLElement paragraph = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("p"));		HX_STACK_VAR(paragraph,"paragraph");
		HX_STACK_LINE(55)
		paragraph->appendChild(::cocktail::Lib_obj::get_document()->createTextNode(HX_CSTRING("Cocktail is a HTML rendering engine.")));
		HX_STACK_LINE(56)
		::cocktail::Lib_obj::get_document()->body->appendChild(paragraph);
		HX_STACK_LINE(59)
		title->style->set_wordSpacing(HX_CSTRING("10px"));
		HX_STACK_LINE(60)
		title->style->set_color(HX_CSTRING("orange"));
		HX_STACK_LINE(61)
		title->style->set_fontFamily(HX_CSTRING("arial"));
		HX_STACK_LINE(64)
		::cocktail::core::html::HTMLImageElement img = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("img"));		HX_STACK_VAR(img,"img");
		HX_STACK_LINE(65)
		img->set_id(HX_CSTRING("pic"));
		HX_STACK_LINE(66)
		img->set_src(HX_CSTRING("assets/cocktail.png"));
		HX_STACK_LINE(67)
		paragraph->appendChild(img);
		HX_STACK_LINE(70)
		::cocktail::core::html::HTMLElement site = ::cocktail::Lib_obj::get_document()->createElement(HX_CSTRING("div"));		HX_STACK_VAR(site,"site");
		HX_STACK_LINE(71)
		site->appendChild(title);
		HX_STACK_LINE(72)
		site->appendChild(paragraph);
		HX_STACK_LINE(74)
		site->style->set_width(HX_CSTRING("50%"));
		HX_STACK_LINE(75)
		site->style->set_marginLeft(site->style->set_marginRight(HX_CSTRING("auto")));
		HX_STACK_LINE(77)
		::cocktail::Lib_obj::get_document()->body->appendChild(site);
		HX_STACK_LINE(80)
		site->style->set_backgroundColor(HX_CSTRING("rgba(255,255,255,0.5)"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,buildDomHaxeJS,(void))

Void Main_obj::main( ){
{
		HX_STACK_PUSH("Main::main","Main.hx",21);

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_1","Main.hx",23);
			{
				HX_STACK_LINE(23)
				::Main_obj::__new();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(21)
		::nme::Lib_obj::create( Dynamic(new _Function_1_1()),(int)1024,(int)768,(int)60,(int)16777215,(int(::nme::Lib_obj::HARDWARE) | int(::nme::Lib_obj::RESIZABLE)),null(),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"buildDomHtml") ) { return buildDomHtml_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"buildDomHaxeJS") ) { return buildDomHaxeJS_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"addInteractivity") ) { return addInteractivity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("addInteractivity"),
	HX_CSTRING("buildDomHtml"),
	HX_CSTRING("buildDomHaxeJS"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

