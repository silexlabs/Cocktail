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
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Window
#include <cocktail/port/flash_player/Window.h>
#endif
namespace cocktail{

Void Lib_obj::__construct()
{
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

::cocktail::core::html::HTMLDocument Lib_obj::_document;

::cocktail::core::html::HTMLDocument Lib_obj::document;

::cocktail::port::flash_player::Window Lib_obj::_window;

::cocktail::port::flash_player::Window Lib_obj::window;

Void Lib_obj::init( ){
{
		HX_SOURCE_PUSH("Lib_obj::init")
		HX_SOURCE_POS("../../src/cocktail/Lib.hx",52)
		::cocktail::Lib_obj::_document = ::cocktail::core::html::HTMLDocument_obj::__new();
		HX_SOURCE_POS("../../src/cocktail/Lib.hx",53)
		::cocktail::Lib_obj::_window = ::cocktail::port::flash_player::Window_obj::__new(::cocktail::Lib_obj::_document);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,init,(void))

::cocktail::core::html::HTMLDocument Lib_obj::get_document( ){
	HX_SOURCE_PUSH("Lib_obj::get_document")
	HX_SOURCE_POS("../../src/cocktail/Lib.hx",62)
	if (((::cocktail::Lib_obj::_document == null()))){
		HX_SOURCE_POS("../../src/cocktail/Lib.hx",63)
		::cocktail::Lib_obj::init();
	}
	HX_SOURCE_POS("../../src/cocktail/Lib.hx",67)
	return ::cocktail::Lib_obj::_document;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,get_document,return )

::cocktail::port::flash_player::Window Lib_obj::get_window( ){
	HX_SOURCE_PUSH("Lib_obj::get_window")
	HX_SOURCE_POS("../../src/cocktail/Lib.hx",72)
	if (((::cocktail::Lib_obj::_window == null()))){
		HX_SOURCE_POS("../../src/cocktail/Lib.hx",73)
		::cocktail::Lib_obj::init();
	}
	HX_SOURCE_POS("../../src/cocktail/Lib.hx",76)
	return ::cocktail::Lib_obj::_window;
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

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return get_window(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { return _window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"document") ) { return get_document(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_document") ) { return _document; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_window") ) { return get_window_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_document") ) { return get_document_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast< ::cocktail::port::flash_player::Window >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { _window=inValue.Cast< ::cocktail::port::flash_player::Window >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"document") ) { document=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_document") ) { _document=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_document"),
	HX_CSTRING("document"),
	HX_CSTRING("_window"),
	HX_CSTRING("window"),
	HX_CSTRING("init"),
	HX_CSTRING("get_document"),
	HX_CSTRING("get_window"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lib_obj::_document,"_document");
	HX_MARK_MEMBER_NAME(Lib_obj::document,"document");
	HX_MARK_MEMBER_NAME(Lib_obj::_window,"_window");
	HX_MARK_MEMBER_NAME(Lib_obj::window,"window");
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
	hx::Static(_document);
	hx::Static(document);
	hx::Static(_window);
	hx::Static(window);
}

} // end namespace cocktail
