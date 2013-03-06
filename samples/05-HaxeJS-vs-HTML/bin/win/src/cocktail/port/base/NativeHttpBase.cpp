#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
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
#ifndef INCLUDED_cocktail_core_event_ProgressEvent
#include <cocktail/core/event/ProgressEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#include <cocktail/core/http/DataFormatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#include <cocktail/port/base/NativeHttpBase.h>
#endif
namespace cocktail{
namespace port{
namespace base{

Void NativeHttpBase_obj::__construct()
{
HX_STACK_PUSH("NativeHttpBase::new","cocktail/port/base/NativeHttpBase.hx",91);
{
	HX_STACK_LINE(91)
	super::__construct();
}
;
	return null();
}

NativeHttpBase_obj::~NativeHttpBase_obj() { }

Dynamic NativeHttpBase_obj::__CreateEmpty() { return  new NativeHttpBase_obj; }
hx::ObjectPtr< NativeHttpBase_obj > NativeHttpBase_obj::__new()
{  hx::ObjectPtr< NativeHttpBase_obj > result = new NativeHttpBase_obj();
	result->__construct();
	return result;}

Dynamic NativeHttpBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeHttpBase_obj > result = new NativeHttpBase_obj();
	result->__construct();
	return result;}

int NativeHttpBase_obj::get_loaded( ){
	HX_STACK_PUSH("NativeHttpBase::get_loaded","cocktail/port/base/NativeHttpBase.hx",197);
	HX_STACK_THIS(this);
	HX_STACK_LINE(197)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeHttpBase_obj,get_loaded,return )

int NativeHttpBase_obj::get_total( ){
	HX_STACK_PUSH("NativeHttpBase::get_total","cocktail/port/base/NativeHttpBase.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeHttpBase_obj,get_total,return )

Void NativeHttpBase_obj::onLoadProgress( Float time){
{
		HX_STACK_PUSH("NativeHttpBase::onLoadProgress","cocktail/port/base/NativeHttpBase.hx",159);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(159)
		if (((this->error == true))){
			HX_STACK_LINE(164)
			::cocktail::core::event::Event errorEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
			HX_STACK_LINE(165)
			errorEvent->initEvent(HX_CSTRING("error"),false,false);
			HX_STACK_LINE(166)
			this->dispatchEvent(errorEvent);
		}
		else{
			HX_STACK_LINE(169)
			if (((this->complete == true))){
				HX_STACK_LINE(171)
				::cocktail::core::event::Event loadEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(loadEvent,"loadEvent");
				HX_STACK_LINE(172)
				loadEvent->initEvent(HX_CSTRING("load"),false,false);
				HX_STACK_LINE(173)
				this->dispatchEvent(loadEvent);
			}
			else{
				HX_STACK_LINE(178)
				if (((this->_closed == false))){
					HX_STACK_LINE(180)
					::cocktail::core::event::ProgressEvent progressEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(progressEvent,"progressEvent");
					HX_STACK_LINE(181)
					progressEvent->initProgressEvent(HX_CSTRING("progress"),false,false,false,this->get_loaded(),this->get_total());
					HX_STACK_LINE(182)
					this->dispatchEvent(progressEvent);
					HX_STACK_LINE(184)
					::cocktail::Lib_obj::get_document()->timer->delay(this->onLoadProgress_dyn(),(int)50);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeHttpBase_obj,onLoadProgress,(void))

Void NativeHttpBase_obj::doLoad( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat){
{
		HX_STACK_PUSH("NativeHttpBase::doLoad","cocktail/port/base/NativeHttpBase.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(method,"method");
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(authorRequestHeaders,"authorRequestHeaders");
		HX_STACK_ARG(dataFormat,"dataFormat");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(NativeHttpBase_obj,doLoad,(void))

Void NativeHttpBase_obj::close( ){
{
		HX_STACK_PUSH("NativeHttpBase::close","cocktail/port/base/NativeHttpBase.hx",134);
		HX_STACK_THIS(this);
		HX_STACK_LINE(134)
		this->_closed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeHttpBase_obj,close,(void))

Void NativeHttpBase_obj::load( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat){
{
		HX_STACK_PUSH("NativeHttpBase::load","cocktail/port/base/NativeHttpBase.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(method,"method");
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(authorRequestHeaders,"authorRequestHeaders");
		HX_STACK_ARG(dataFormat,"dataFormat");
		HX_STACK_LINE(112)
		this->status = (int)0;
		HX_STACK_LINE(113)
		this->total = (int)0;
		HX_STACK_LINE(114)
		this->loaded = (int)0;
		HX_STACK_LINE(115)
		this->responseHeaders = ::Hash_obj::__new();
		HX_STACK_LINE(116)
		this->responseHeadersLoaded = false;
		HX_STACK_LINE(117)
		this->response = null();
		HX_STACK_LINE(118)
		this->error = false;
		HX_STACK_LINE(119)
		this->complete = false;
		HX_STACK_LINE(120)
		this->_closed = false;
		HX_STACK_LINE(122)
		this->_url = url;
		HX_STACK_LINE(124)
		this->doLoad(url,method,data,authorRequestHeaders,dataFormat);
		HX_STACK_LINE(127)
		::cocktail::Lib_obj::get_document()->timer->delay(this->onLoadProgress_dyn(),(int)50);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(NativeHttpBase_obj,load,(void))

int NativeHttpBase_obj::PROGRESS_UPDATE_FREQUENCY;


NativeHttpBase_obj::NativeHttpBase_obj()
{
}

void NativeHttpBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeHttpBase);
	HX_MARK_MEMBER_NAME(_closed,"_closed");
	HX_MARK_MEMBER_NAME(_url,"_url");
	HX_MARK_MEMBER_NAME(complete,"complete");
	HX_MARK_MEMBER_NAME(error,"error");
	HX_MARK_MEMBER_NAME(responseHeadersLoaded,"responseHeadersLoaded");
	HX_MARK_MEMBER_NAME(response,"response");
	HX_MARK_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_MARK_MEMBER_NAME(loaded,"loaded");
	HX_MARK_MEMBER_NAME(total,"total");
	HX_MARK_MEMBER_NAME(status,"status");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeHttpBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_closed,"_closed");
	HX_VISIT_MEMBER_NAME(_url,"_url");
	HX_VISIT_MEMBER_NAME(complete,"complete");
	HX_VISIT_MEMBER_NAME(error,"error");
	HX_VISIT_MEMBER_NAME(responseHeadersLoaded,"responseHeadersLoaded");
	HX_VISIT_MEMBER_NAME(response,"response");
	HX_VISIT_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_VISIT_MEMBER_NAME(loaded,"loaded");
	HX_VISIT_MEMBER_NAME(total,"total");
	HX_VISIT_MEMBER_NAME(status,"status");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeHttpBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"_url") ) { return _url; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"error") ) { return error; }
		if (HX_FIELD_EQ(inName,"total") ) { return inCallProp ? get_total() : total; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doLoad") ) { return doLoad_dyn(); }
		if (HX_FIELD_EQ(inName,"loaded") ) { return inCallProp ? get_loaded() : loaded; }
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_closed") ) { return _closed; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { return complete; }
		if (HX_FIELD_EQ(inName,"response") ) { return response; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_total") ) { return get_total_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_loaded") ) { return get_loaded_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadProgress") ) { return onLoadProgress_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { return responseHeaders; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"responseHeadersLoaded") ) { return responseHeadersLoaded; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"PROGRESS_UPDATE_FREQUENCY") ) { return PROGRESS_UPDATE_FREQUENCY; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeHttpBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_url") ) { _url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { error=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"total") ) { total=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { loaded=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_closed") ) { _closed=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { complete=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"response") ) { response=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { responseHeaders=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"responseHeadersLoaded") ) { responseHeadersLoaded=inValue.Cast< bool >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"PROGRESS_UPDATE_FREQUENCY") ) { PROGRESS_UPDATE_FREQUENCY=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeHttpBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_closed"));
	outFields->push(HX_CSTRING("_url"));
	outFields->push(HX_CSTRING("complete"));
	outFields->push(HX_CSTRING("error"));
	outFields->push(HX_CSTRING("responseHeadersLoaded"));
	outFields->push(HX_CSTRING("response"));
	outFields->push(HX_CSTRING("responseHeaders"));
	outFields->push(HX_CSTRING("loaded"));
	outFields->push(HX_CSTRING("total"));
	outFields->push(HX_CSTRING("status"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROGRESS_UPDATE_FREQUENCY"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_loaded"),
	HX_CSTRING("get_total"),
	HX_CSTRING("onLoadProgress"),
	HX_CSTRING("doLoad"),
	HX_CSTRING("close"),
	HX_CSTRING("load"),
	HX_CSTRING("_closed"),
	HX_CSTRING("_url"),
	HX_CSTRING("complete"),
	HX_CSTRING("error"),
	HX_CSTRING("responseHeadersLoaded"),
	HX_CSTRING("response"),
	HX_CSTRING("responseHeaders"),
	HX_CSTRING("loaded"),
	HX_CSTRING("total"),
	HX_CSTRING("status"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeHttpBase_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NativeHttpBase_obj::PROGRESS_UPDATE_FREQUENCY,"PROGRESS_UPDATE_FREQUENCY");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeHttpBase_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NativeHttpBase_obj::PROGRESS_UPDATE_FREQUENCY,"PROGRESS_UPDATE_FREQUENCY");
};

Class NativeHttpBase_obj::__mClass;

void NativeHttpBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.NativeHttpBase"), hx::TCanCast< NativeHttpBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeHttpBase_obj::__boot()
{
	PROGRESS_UPDATE_FREQUENCY= (int)50;
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
