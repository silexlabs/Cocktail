#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
namespace cocktail{

Void Lib_obj::__construct()
{
HX_STACK_PUSH("Lib::new","cocktail/Lib.hx",37);
{
}
;
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

::cocktail::core::html::HTMLDocument Lib_obj::document;

::cocktail::core::window::Window Lib_obj::window;

Void Lib_obj::init( ){
{
		HX_STACK_PUSH("Lib::init","cocktail/Lib.hx",50);
		HX_STACK_LINE(51)
		::cocktail::Lib_obj::window = ::cocktail::core::window::Window_obj::__new();
		HX_STACK_LINE(52)
		::cocktail::Lib_obj::document = ::cocktail::Lib_obj::get_window()->document;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,init,(void))

::cocktail::core::html::HTMLDocument Lib_obj::get_document( ){
	HX_STACK_PUSH("Lib::get_document","cocktail/Lib.hx",60);
	HX_STACK_LINE(61)
	if (((::cocktail::Lib_obj::document == null()))){
		HX_STACK_LINE(62)
		::cocktail::Lib_obj::init();
	}
	HX_STACK_LINE(66)
	return ::cocktail::Lib_obj::document;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,get_document,return )

::cocktail::core::window::Window Lib_obj::get_window( ){
	HX_STACK_PUSH("Lib::get_window","cocktail/Lib.hx",70);
	HX_STACK_LINE(71)
	if (((::cocktail::Lib_obj::window == null()))){
		HX_STACK_LINE(72)
		::cocktail::Lib_obj::init();
	}
	HX_STACK_LINE(75)
	return ::cocktail::Lib_obj::window;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,get_window,return )


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lib);
	HX_MARK_END_CLASS();
}

void Lib_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Lib_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return inCallProp ? get_window() : window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"document") ) { return inCallProp ? get_document() : document; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_window") ) { return get_window_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_document") ) { return get_document_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast< ::cocktail::core::window::Window >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"document") ) { document=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("document"),
	HX_CSTRING("window"),
	HX_CSTRING("init"),
	HX_CSTRING("get_document"),
	HX_CSTRING("get_window"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lib_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Lib_obj::document,"document");
	HX_MARK_MEMBER_NAME(Lib_obj::window,"window");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Lib_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Lib_obj::document,"document");
	HX_VISIT_MEMBER_NAME(Lib_obj::window,"window");
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Lib_obj::__boot()
{
}

} // end namespace cocktail
