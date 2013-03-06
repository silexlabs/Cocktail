#include <hxcpp.h>

#ifndef INCLUDED_native_net_URLRequestMethod
#include <native/net/URLRequestMethod.h>
#endif
namespace native{
namespace net{

Void URLRequestMethod_obj::__construct()
{
	return null();
}

URLRequestMethod_obj::~URLRequestMethod_obj() { }

Dynamic URLRequestMethod_obj::__CreateEmpty() { return  new URLRequestMethod_obj; }
hx::ObjectPtr< URLRequestMethod_obj > URLRequestMethod_obj::__new()
{  hx::ObjectPtr< URLRequestMethod_obj > result = new URLRequestMethod_obj();
	result->__construct();
	return result;}

Dynamic URLRequestMethod_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLRequestMethod_obj > result = new URLRequestMethod_obj();
	result->__construct();
	return result;}

::String URLRequestMethod_obj::DELETE;

::String URLRequestMethod_obj::GET;

::String URLRequestMethod_obj::HEAD;

::String URLRequestMethod_obj::OPTIONS;

::String URLRequestMethod_obj::POST;

::String URLRequestMethod_obj::PUT;


URLRequestMethod_obj::URLRequestMethod_obj()
{
}

void URLRequestMethod_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLRequestMethod);
	HX_MARK_END_CLASS();
}

void URLRequestMethod_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic URLRequestMethod_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"GET") ) { return GET; }
		if (HX_FIELD_EQ(inName,"PUT") ) { return PUT; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"HEAD") ) { return HEAD; }
		if (HX_FIELD_EQ(inName,"POST") ) { return POST; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"DELETE") ) { return DELETE; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OPTIONS") ) { return OPTIONS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic URLRequestMethod_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"GET") ) { GET=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PUT") ) { PUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"HEAD") ) { HEAD=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POST") ) { POST=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"DELETE") ) { DELETE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OPTIONS") ) { OPTIONS=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void URLRequestMethod_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DELETE"),
	HX_CSTRING("GET"),
	HX_CSTRING("HEAD"),
	HX_CSTRING("OPTIONS"),
	HX_CSTRING("POST"),
	HX_CSTRING("PUT"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::DELETE,"DELETE");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::GET,"GET");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::HEAD,"HEAD");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::OPTIONS,"OPTIONS");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::POST,"POST");
	HX_MARK_MEMBER_NAME(URLRequestMethod_obj::PUT,"PUT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::DELETE,"DELETE");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::GET,"GET");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::HEAD,"HEAD");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::OPTIONS,"OPTIONS");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::POST,"POST");
	HX_VISIT_MEMBER_NAME(URLRequestMethod_obj::PUT,"PUT");
};

Class URLRequestMethod_obj::__mClass;

void URLRequestMethod_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.net.URLRequestMethod"), hx::TCanCast< URLRequestMethod_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void URLRequestMethod_obj::__boot()
{
	DELETE= HX_CSTRING("DELETE");
	GET= HX_CSTRING("GET");
	HEAD= HX_CSTRING("HEAD");
	OPTIONS= HX_CSTRING("OPTIONS");
	POST= HX_CSTRING("POST");
	PUT= HX_CSTRING("PUT");
}

} // end namespace native
} // end namespace net
