#include <hxcpp.h>

#ifndef INCLUDED_Cocktail
#include <Cocktail.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
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
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif

Void Cocktail_obj::__construct()
{
	return null();
}

Cocktail_obj::~Cocktail_obj() { }

Dynamic Cocktail_obj::__CreateEmpty() { return  new Cocktail_obj; }
hx::ObjectPtr< Cocktail_obj > Cocktail_obj::__new()
{  hx::ObjectPtr< Cocktail_obj > result = new Cocktail_obj();
	result->__construct();
	return result;}

Dynamic Cocktail_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Cocktail_obj > result = new Cocktail_obj();
	result->__construct();
	return result;}

::String Cocktail_obj::htmlSourcePath;

::String Cocktail_obj::htmlSource;

::String Cocktail_obj::customClassName;

Void Cocktail_obj::main( ){
{
		HX_STACK_PUSH("Cocktail::main","Cocktail.hx",54);
		HX_STACK_LINE(14)
		hx::ClassOf< ::Main >();
		HX_STACK_LINE(55)
		::cocktail::Lib_obj::get_document()->documentElement->set_innerHTML(HX_CSTRING("<html>\r\n\t<head>\r\n\t\t<title>CSS transitions with Cocktail</title>\r\n\t\t<link href=\"app.css\" type=\"text/css\" rel=\"stylesheet\"></link>\r\n\t</head>\r\n\t<body>\r\n\t\t<h1>Click on boxes to add more</h1>\r\n\t\t<div id=\"container\">\r\n\t\t</div>\r\n\t</body>\r\n</html>"));
		HX_STACK_LINE(57)
		{
		}
		HX_STACK_LINE(60)
		::Class customClass = ::Type_obj::resolveClass(HX_CSTRING("Main"));		HX_STACK_VAR(customClass,"customClass");
		HX_STACK_LINE(62)
		if (((customClass != null()))){
			HX_STACK_LINE(63)
			::Type_obj::createInstance(customClass,Dynamic( Array_obj<Dynamic>::__new()));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Cocktail_obj,main,(void))


Cocktail_obj::Cocktail_obj()
{
}

void Cocktail_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Cocktail);
	HX_MARK_END_CLASS();
}

void Cocktail_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Cocktail_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"htmlSource") ) { return htmlSource; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"htmlSourcePath") ) { return htmlSourcePath; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customClassName") ) { return customClassName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Cocktail_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"htmlSource") ) { htmlSource=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"htmlSourcePath") ) { htmlSourcePath=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customClassName") ) { customClassName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Cocktail_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("htmlSourcePath"),
	HX_CSTRING("htmlSource"),
	HX_CSTRING("customClassName"),
	HX_CSTRING("main"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Cocktail_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Cocktail_obj::htmlSourcePath,"htmlSourcePath");
	HX_MARK_MEMBER_NAME(Cocktail_obj::htmlSource,"htmlSource");
	HX_MARK_MEMBER_NAME(Cocktail_obj::customClassName,"customClassName");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Cocktail_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Cocktail_obj::htmlSourcePath,"htmlSourcePath");
	HX_VISIT_MEMBER_NAME(Cocktail_obj::htmlSource,"htmlSource");
	HX_VISIT_MEMBER_NAME(Cocktail_obj::customClassName,"customClassName");
};

Class Cocktail_obj::__mClass;

void Cocktail_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Cocktail"), hx::TCanCast< Cocktail_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Cocktail_obj::__boot()
{
	htmlSourcePath= HX_CSTRING("index.html");
}

