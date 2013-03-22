#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_ProgressEvent
#include <cocktail/core/event/ProgressEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget
#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void XMLHttpRequestEventTarget_obj::__construct()
{
HX_STACK_PUSH("XMLHttpRequestEventTarget::new","cocktail/core/event/XMLHttpRequestEventTarget.hx",65);
{
	HX_STACK_LINE(65)
	super::__construct();
}
;
	return null();
}

XMLHttpRequestEventTarget_obj::~XMLHttpRequestEventTarget_obj() { }

Dynamic XMLHttpRequestEventTarget_obj::__CreateEmpty() { return  new XMLHttpRequestEventTarget_obj; }
hx::ObjectPtr< XMLHttpRequestEventTarget_obj > XMLHttpRequestEventTarget_obj::__new()
{  hx::ObjectPtr< XMLHttpRequestEventTarget_obj > result = new XMLHttpRequestEventTarget_obj();
	result->__construct();
	return result;}

Dynamic XMLHttpRequestEventTarget_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< XMLHttpRequestEventTarget_obj > result = new XMLHttpRequestEventTarget_obj();
	result->__construct();
	return result;}

Dynamic XMLHttpRequestEventTarget_obj::set_onLoadEnd( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onLoadEnd","cocktail/core/event/XMLHttpRequestEventTarget.hx",136);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(137)
	this->updateCallbackListener(HX_CSTRING("loadend"),value,this->onloadend_dyn());
	HX_STACK_LINE(138)
	return this->onloadend = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onLoadEnd,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onTimeout( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onTimeout","cocktail/core/event/XMLHttpRequestEventTarget.hx",130);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(131)
	this->updateCallbackListener(HX_CSTRING("timeout"),value,this->ontimeout_dyn());
	HX_STACK_LINE(132)
	return this->ontimeout = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onTimeout,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onLoad( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onLoad","cocktail/core/event/XMLHttpRequestEventTarget.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(125)
	this->updateCallbackListener(HX_CSTRING("load"),value,this->onload_dyn());
	HX_STACK_LINE(126)
	return this->onload = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onLoad,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onError( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onError","cocktail/core/event/XMLHttpRequestEventTarget.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(119)
	this->updateCallbackListener(HX_CSTRING("error"),value,this->onerror_dyn());
	HX_STACK_LINE(120)
	return this->onerror = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onError,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onAbort( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onAbort","cocktail/core/event/XMLHttpRequestEventTarget.hx",112);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(113)
	this->updateCallbackListener(HX_CSTRING("abort"),value,this->onabort_dyn());
	HX_STACK_LINE(114)
	return this->onabort = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onAbort,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onProgress( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onProgress","cocktail/core/event/XMLHttpRequestEventTarget.hx",106);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(107)
	this->updateCallbackListener(HX_CSTRING("progress"),value,this->onprogress_dyn());
	HX_STACK_LINE(108)
	return this->onprogress = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onProgress,return )

Dynamic XMLHttpRequestEventTarget_obj::set_onLoadStart( Dynamic value){
	HX_STACK_PUSH("XMLHttpRequestEventTarget::set_onLoadStart","cocktail/core/event/XMLHttpRequestEventTarget.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(101)
	this->updateCallbackListener(HX_CSTRING("loadstart"),value,this->onloadStart_dyn());
	HX_STACK_LINE(102)
	return this->onloadStart = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHttpRequestEventTarget_obj,set_onLoadStart,return )

Void XMLHttpRequestEventTarget_obj::updateCallbackListener( ::String eventType,Dynamic newListener,Dynamic oldListener){
{
		HX_STACK_PUSH("XMLHttpRequestEventTarget::updateCallbackListener","cocktail/core/event/XMLHttpRequestEventTarget.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventType,"eventType");
		HX_STACK_ARG(newListener,"newListener");
		HX_STACK_ARG(oldListener,"oldListener");
		HX_STACK_LINE(83)
		if (((oldListener != null()))){
			HX_STACK_LINE(84)
			this->removeEventListener(eventType,oldListener,null());
		}
		HX_STACK_LINE(89)
		if (((newListener != null()))){
			HX_STACK_LINE(90)
			this->addEventListener(eventType,newListener,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(XMLHttpRequestEventTarget_obj,updateCallbackListener,(void))


XMLHttpRequestEventTarget_obj::XMLHttpRequestEventTarget_obj()
{
}

void XMLHttpRequestEventTarget_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLHttpRequestEventTarget);
	HX_MARK_MEMBER_NAME(onloadend,"onloadend");
	HX_MARK_MEMBER_NAME(ontimeout,"ontimeout");
	HX_MARK_MEMBER_NAME(onload,"onload");
	HX_MARK_MEMBER_NAME(onerror,"onerror");
	HX_MARK_MEMBER_NAME(onabort,"onabort");
	HX_MARK_MEMBER_NAME(onprogress,"onprogress");
	HX_MARK_MEMBER_NAME(onloadStart,"onloadStart");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void XMLHttpRequestEventTarget_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onloadend,"onloadend");
	HX_VISIT_MEMBER_NAME(ontimeout,"ontimeout");
	HX_VISIT_MEMBER_NAME(onload,"onload");
	HX_VISIT_MEMBER_NAME(onerror,"onerror");
	HX_VISIT_MEMBER_NAME(onabort,"onabort");
	HX_VISIT_MEMBER_NAME(onprogress,"onprogress");
	HX_VISIT_MEMBER_NAME(onloadStart,"onloadStart");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic XMLHttpRequestEventTarget_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onload") ) { return onload; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onerror") ) { return onerror; }
		if (HX_FIELD_EQ(inName,"onabort") ) { return onabort; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onloadend") ) { return onloadend; }
		if (HX_FIELD_EQ(inName,"ontimeout") ) { return ontimeout; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_onLoad") ) { return set_onLoad_dyn(); }
		if (HX_FIELD_EQ(inName,"onprogress") ) { return onprogress; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_onError") ) { return set_onError_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onAbort") ) { return set_onAbort_dyn(); }
		if (HX_FIELD_EQ(inName,"onloadStart") ) { return onloadStart; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_onLoadEnd") ) { return set_onLoadEnd_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onTimeout") ) { return set_onTimeout_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_onProgress") ) { return set_onProgress_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_onLoadStart") ) { return set_onLoadStart_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateCallbackListener") ) { return updateCallbackListener_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic XMLHttpRequestEventTarget_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onload") ) { if (inCallProp) return set_onLoad(inValue);onload=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onerror") ) { if (inCallProp) return set_onError(inValue);onerror=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onabort") ) { if (inCallProp) return set_onAbort(inValue);onabort=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onloadend") ) { if (inCallProp) return set_onLoadEnd(inValue);onloadend=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ontimeout") ) { if (inCallProp) return set_onTimeout(inValue);ontimeout=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onprogress") ) { if (inCallProp) return set_onProgress(inValue);onprogress=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onloadStart") ) { if (inCallProp) return set_onLoadStart(inValue);onloadStart=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void XMLHttpRequestEventTarget_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_onLoadEnd"),
	HX_CSTRING("set_onTimeout"),
	HX_CSTRING("set_onLoad"),
	HX_CSTRING("set_onError"),
	HX_CSTRING("set_onAbort"),
	HX_CSTRING("set_onProgress"),
	HX_CSTRING("set_onLoadStart"),
	HX_CSTRING("updateCallbackListener"),
	HX_CSTRING("onloadend"),
	HX_CSTRING("ontimeout"),
	HX_CSTRING("onload"),
	HX_CSTRING("onerror"),
	HX_CSTRING("onabort"),
	HX_CSTRING("onprogress"),
	HX_CSTRING("onloadStart"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(XMLHttpRequestEventTarget_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(XMLHttpRequestEventTarget_obj::__mClass,"__mClass");
};

Class XMLHttpRequestEventTarget_obj::__mClass;

void XMLHttpRequestEventTarget_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.XMLHttpRequestEventTarget"), hx::TCanCast< XMLHttpRequestEventTarget_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void XMLHttpRequestEventTarget_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
