#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#include <cocktail/core/http/DataFormatValue.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#include <cocktail/port/base/NativeHttpBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeHttp
#include <cocktail/port/platform/nme/NativeHttp.h>
#endif
#ifndef INCLUDED_nme_Assets
#include <nme/Assets.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace nme{

Void NativeHttp_obj::__construct()
{
HX_STACK_PUSH("NativeHttp::new","cocktail/port/platform/nme/NativeHttp.hx",32);
{
	HX_STACK_LINE(32)
	super::__construct();
}
;
	return null();
}

NativeHttp_obj::~NativeHttp_obj() { }

Dynamic NativeHttp_obj::__CreateEmpty() { return  new NativeHttp_obj; }
hx::ObjectPtr< NativeHttp_obj > NativeHttp_obj::__new()
{  hx::ObjectPtr< NativeHttp_obj > result = new NativeHttp_obj();
	result->__construct();
	return result;}

Dynamic NativeHttp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeHttp_obj > result = new NativeHttp_obj();
	result->__construct();
	return result;}

Void NativeHttp_obj::doLoad( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat){
{
		HX_STACK_PUSH("NativeHttp::doLoad","cocktail/port/platform/nme/NativeHttp.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(method,"method");
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(authorRequestHeaders,"authorRequestHeaders");
		HX_STACK_ARG(dataFormat,"dataFormat");
		HX_STACK_LINE(45)
		::String asset = ::nme::Assets_obj::getText(url);		HX_STACK_VAR(asset,"asset");
		HX_STACK_LINE(48)
		if (((asset != null()))){
			HX_STACK_LINE(50)
			this->response = asset;
			HX_STACK_LINE(51)
			this->complete = true;
			HX_STACK_LINE(52)
			this->responseHeadersLoaded = true;
		}
		else{
			HX_STACK_LINE(56)
			this->super::doLoad(url,method,data,authorRequestHeaders,dataFormat);
		}
	}
return null();
}



NativeHttp_obj::NativeHttp_obj()
{
}

void NativeHttp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeHttp);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeHttp_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeHttp_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"doLoad") ) { return doLoad_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeHttp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeHttp_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doLoad"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeHttp_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeHttp_obj::__mClass,"__mClass");
};

Class NativeHttp_obj::__mClass;

void NativeHttp_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.nme.NativeHttp"), hx::TCanCast< NativeHttp_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeHttp_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme
