#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_XMLHTTPRequest
#include <cocktail/core/resource/XMLHTTPRequest.h>
#endif
#ifndef INCLUDED_haxe_Http
#include <haxe/Http.h>
#endif
namespace cocktail{
namespace core{
namespace resource{

Void XMLHTTPRequest_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",97)
	this->_http = ::haxe::Http_obj::__new(HX_CSTRING(""));
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",99)
	this->_http->onData = this->onHTTPData_dyn();
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",100)
	this->_http->onStatus = this->onHTTPStatus_dyn();
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",101)
	this->_http->onError = this->onHTTPError_dyn();
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",102)
	this->setReadyState((int)0);
}
;
	return null();
}

XMLHTTPRequest_obj::~XMLHTTPRequest_obj() { }

Dynamic XMLHTTPRequest_obj::__CreateEmpty() { return  new XMLHTTPRequest_obj; }
hx::ObjectPtr< XMLHTTPRequest_obj > XMLHTTPRequest_obj::__new()
{  hx::ObjectPtr< XMLHTTPRequest_obj > result = new XMLHTTPRequest_obj();
	result->__construct();
	return result;}

Dynamic XMLHTTPRequest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< XMLHTTPRequest_obj > result = new XMLHTTPRequest_obj();
	result->__construct();
	return result;}

hx::Object *XMLHTTPRequest_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::event::IEventTarget_obj)) return operator ::cocktail::core::event::IEventTarget_obj *();
	return super::__ToInterface(inType);
}

Void XMLHTTPRequest_obj::open( ::String method,::String url){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::open")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",117)
		this->_http->url = url;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",118)
		this->_method = method;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",119)
		this->setReadyState((int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(XMLHTTPRequest_obj,open,(void))

Void XMLHTTPRequest_obj::send( ::String content){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::send")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",130)
		bool post = false;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",133)
		::String _switch_1 = (this->_method.toUpperCase());
		if (  ( _switch_1==HX_CSTRING("POST"))){
			HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",135)
			post = true;
		}
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",139)
		this->_http->request(post);
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",141)
		this->setReadyState((int)3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,send,(void))

Void XMLHTTPRequest_obj::setRequestHeader( ::String name,::String value){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::setRequestHeader")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",148)
		this->_http->setHeader(name,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(XMLHTTPRequest_obj,setRequestHeader,(void))

Void XMLHTTPRequest_obj::onHTTPStatus( int status){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::onHTTPStatus")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",160)
		this->_status = status;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,onHTTPStatus,(void))

Void XMLHTTPRequest_obj::onHTTPData( ::String data){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::onHTTPData")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",169)
		this->_responseText = data;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",170)
		this->setReadyState((int)4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,onHTTPData,(void))

Void XMLHTTPRequest_obj::onHTTPError( ::String data){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::onHTTPError")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",178)
		this->_responseText = data;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",179)
		this->setReadyState((int)4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,onHTTPError,(void))

Void XMLHTTPRequest_obj::setReadyState( int value){
{
		HX_SOURCE_PUSH("XMLHTTPRequest_obj::setReadyState")
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",188)
		this->_readyState = value;
		HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",189)
		if (((this->onReadyStateChange_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",190)
			this->onReadyStateChange(::cocktail::core::event::Event_obj::__new(HX_CSTRING("readystatechange"),hx::ObjectPtr<OBJ_>(this)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,setReadyState,(void))

int XMLHTTPRequest_obj::get_readyState( ){
	HX_SOURCE_PUSH("XMLHTTPRequest_obj::get_readyState")
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",200)
	return this->_readyState;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_readyState,return )

int XMLHTTPRequest_obj::get_status( ){
	HX_SOURCE_PUSH("XMLHTTPRequest_obj::get_status")
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",205)
	return this->_status;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_status,return )

::String XMLHTTPRequest_obj::get_responseText( ){
	HX_SOURCE_PUSH("XMLHTTPRequest_obj::get_responseText")
	HX_SOURCE_POS("../../src/cocktail/core/resource/XMLHTTPRequest.hx",210)
	return this->_responseText;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_responseText,return )

int XMLHTTPRequest_obj::READY_STATE_UNSENT;

int XMLHTTPRequest_obj::READY_STATE_OPENED;

int XMLHTTPRequest_obj::READY_STATE_HEADERS_RECEIVED;

int XMLHTTPRequest_obj::READY_STATE_LOADING;

int XMLHTTPRequest_obj::READY_STATE_DONE;


XMLHTTPRequest_obj::XMLHTTPRequest_obj()
{
}

void XMLHTTPRequest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLHTTPRequest);
	HX_MARK_MEMBER_NAME(_readyState,"_readyState");
	HX_MARK_MEMBER_NAME(readyState,"readyState");
	HX_MARK_MEMBER_NAME(_responseText,"_responseText");
	HX_MARK_MEMBER_NAME(responseText,"responseText");
	HX_MARK_MEMBER_NAME(_status,"_status");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(onReadyStateChange,"onReadyStateChange");
	HX_MARK_MEMBER_NAME(_http,"_http");
	HX_MARK_MEMBER_NAME(_method,"_method");
	HX_MARK_END_CLASS();
}

Dynamic XMLHTTPRequest_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		if (HX_FIELD_EQ(inName,"send") ) { return send_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_http") ) { return _http; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return get_status(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_status") ) { return _status; }
		if (HX_FIELD_EQ(inName,"_method") ) { return _method; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readyState") ) { return get_readyState(); }
		if (HX_FIELD_EQ(inName,"onHTTPData") ) { return onHTTPData_dyn(); }
		if (HX_FIELD_EQ(inName,"get_status") ) { return get_status_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_readyState") ) { return _readyState; }
		if (HX_FIELD_EQ(inName,"onHTTPError") ) { return onHTTPError_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"responseText") ) { return get_responseText(); }
		if (HX_FIELD_EQ(inName,"onHTTPStatus") ) { return onHTTPStatus_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_responseText") ) { return _responseText; }
		if (HX_FIELD_EQ(inName,"setReadyState") ) { return setReadyState_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_readyState") ) { return get_readyState_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"READY_STATE_DONE") ) { return READY_STATE_DONE; }
		if (HX_FIELD_EQ(inName,"setRequestHeader") ) { return setRequestHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"get_responseText") ) { return get_responseText_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_UNSENT") ) { return READY_STATE_UNSENT; }
		if (HX_FIELD_EQ(inName,"READY_STATE_OPENED") ) { return READY_STATE_OPENED; }
		if (HX_FIELD_EQ(inName,"onReadyStateChange") ) { return onReadyStateChange; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"READY_STATE_LOADING") ) { return READY_STATE_LOADING; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"READY_STATE_HEADERS_RECEIVED") ) { return READY_STATE_HEADERS_RECEIVED; }
	}
	return super::__Field(inName);
}

Dynamic XMLHTTPRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_http") ) { _http=inValue.Cast< ::haxe::Http >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_status") ) { _status=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_method") ) { _method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readyState") ) { readyState=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_readyState") ) { _readyState=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"responseText") ) { responseText=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_responseText") ) { _responseText=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"READY_STATE_DONE") ) { READY_STATE_DONE=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_UNSENT") ) { READY_STATE_UNSENT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"READY_STATE_OPENED") ) { READY_STATE_OPENED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onReadyStateChange") ) { onReadyStateChange=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"READY_STATE_LOADING") ) { READY_STATE_LOADING=inValue.Cast< int >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"READY_STATE_HEADERS_RECEIVED") ) { READY_STATE_HEADERS_RECEIVED=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void XMLHTTPRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_readyState"));
	outFields->push(HX_CSTRING("readyState"));
	outFields->push(HX_CSTRING("_responseText"));
	outFields->push(HX_CSTRING("responseText"));
	outFields->push(HX_CSTRING("_status"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("_http"));
	outFields->push(HX_CSTRING("_method"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("READY_STATE_UNSENT"),
	HX_CSTRING("READY_STATE_OPENED"),
	HX_CSTRING("READY_STATE_HEADERS_RECEIVED"),
	HX_CSTRING("READY_STATE_LOADING"),
	HX_CSTRING("READY_STATE_DONE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_readyState"),
	HX_CSTRING("readyState"),
	HX_CSTRING("_responseText"),
	HX_CSTRING("responseText"),
	HX_CSTRING("_status"),
	HX_CSTRING("status"),
	HX_CSTRING("onReadyStateChange"),
	HX_CSTRING("_http"),
	HX_CSTRING("_method"),
	HX_CSTRING("open"),
	HX_CSTRING("send"),
	HX_CSTRING("setRequestHeader"),
	HX_CSTRING("onHTTPStatus"),
	HX_CSTRING("onHTTPData"),
	HX_CSTRING("onHTTPError"),
	HX_CSTRING("setReadyState"),
	HX_CSTRING("get_readyState"),
	HX_CSTRING("get_status"),
	HX_CSTRING("get_responseText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::READY_STATE_UNSENT,"READY_STATE_UNSENT");
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::READY_STATE_OPENED,"READY_STATE_OPENED");
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::READY_STATE_HEADERS_RECEIVED,"READY_STATE_HEADERS_RECEIVED");
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::READY_STATE_LOADING,"READY_STATE_LOADING");
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::READY_STATE_DONE,"READY_STATE_DONE");
};

Class XMLHTTPRequest_obj::__mClass;

void XMLHTTPRequest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.resource.XMLHTTPRequest"), hx::TCanCast< XMLHTTPRequest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void XMLHTTPRequest_obj::__boot()
{
	hx::Static(READY_STATE_UNSENT) = (int)0;
	hx::Static(READY_STATE_OPENED) = (int)1;
	hx::Static(READY_STATE_HEADERS_RECEIVED) = (int)2;
	hx::Static(READY_STATE_LOADING) = (int)3;
	hx::Static(READY_STATE_DONE) = (int)4;
}

} // end namespace cocktail
} // end namespace core
} // end namespace resource
