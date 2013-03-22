#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget
#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_http_XMLHttpRequestUpload
#include <cocktail/core/http/XMLHttpRequestUpload.h>
#endif
namespace cocktail{
namespace core{
namespace http{

Void XMLHttpRequestUpload_obj::__construct()
{
HX_STACK_PUSH("XMLHttpRequestUpload::new","cocktail/core/http/XMLHttpRequestUpload.hx",24);
{
	HX_STACK_LINE(24)
	super::__construct();
}
;
	return null();
}

XMLHttpRequestUpload_obj::~XMLHttpRequestUpload_obj() { }

Dynamic XMLHttpRequestUpload_obj::__CreateEmpty() { return  new XMLHttpRequestUpload_obj; }
hx::ObjectPtr< XMLHttpRequestUpload_obj > XMLHttpRequestUpload_obj::__new()
{  hx::ObjectPtr< XMLHttpRequestUpload_obj > result = new XMLHttpRequestUpload_obj();
	result->__construct();
	return result;}

Dynamic XMLHttpRequestUpload_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< XMLHttpRequestUpload_obj > result = new XMLHttpRequestUpload_obj();
	result->__construct();
	return result;}


XMLHttpRequestUpload_obj::XMLHttpRequestUpload_obj()
{
}

void XMLHttpRequestUpload_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLHttpRequestUpload);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void XMLHttpRequestUpload_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic XMLHttpRequestUpload_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic XMLHttpRequestUpload_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void XMLHttpRequestUpload_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(XMLHttpRequestUpload_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(XMLHttpRequestUpload_obj::__mClass,"__mClass");
};

Class XMLHttpRequestUpload_obj::__mClass;

void XMLHttpRequestUpload_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.http.XMLHttpRequestUpload"), hx::TCanCast< XMLHttpRequestUpload_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void XMLHttpRequestUpload_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace http
