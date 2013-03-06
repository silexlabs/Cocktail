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
#ifndef INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget
#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#include <cocktail/core/http/DataFormatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_http_XMLHTTPRequest
#include <cocktail/core/http/XMLHTTPRequest.h>
#endif
#ifndef INCLUDED_cocktail_core_http_XMLHttpRequestUpload
#include <cocktail/core/http/XMLHttpRequestUpload.h>
#endif
#ifndef INCLUDED_cocktail_core_timer_Timer
#include <cocktail/core/timer/Timer.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#include <cocktail/port/base/NativeHttpBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeHttp
#include <cocktail/port/platform/nme/NativeHttp.h>
#endif
namespace cocktail{
namespace core{
namespace http{

Void XMLHTTPRequest_obj::__construct()
{
HX_STACK_PUSH("XMLHTTPRequest::new","cocktail/core/http/XMLHTTPRequest.hx",166);
{
	HX_STACK_LINE(167)
	super::__construct();
	HX_STACK_LINE(169)
	this->_nativeHttp = ::cocktail::port::platform::nme::NativeHttp_obj::__new();
	HX_STACK_LINE(172)
	this->set_responseType(HX_CSTRING(""));
	HX_STACK_LINE(175)
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

Dynamic XMLHTTPRequest_obj::set_onReadyStateChange( Dynamic value){
	HX_STACK_PUSH("XMLHTTPRequest::set_onReadyStateChange","cocktail/core/http/XMLHTTPRequest.hx",770);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(771)
	this->updateCallbackListener(HX_CSTRING("readystatechange"),value,this->onreadystatechange_dyn());
	HX_STACK_LINE(772)
	return this->onreadystatechange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,set_onReadyStateChange,return )

::String XMLHTTPRequest_obj::set_responseType( ::String value){
	HX_STACK_PUSH("XMLHTTPRequest::set_responseType","cocktail/core/http/XMLHTTPRequest.hx",752);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(753)
	switch( (int)(this->readyState)){
		case (int)3: case (int)4: {
			HX_STACK_LINE(756)
			hx::Throw ((int)11);
			HX_STACK_LINE(757)
			return null();
		}
		;break;
		default: {
		}
	}
	HX_STACK_LINE(766)
	return this->responseType = value;
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,set_responseType,return )

::cocktail::core::dom::Document XMLHTTPRequest_obj::get_responseXML( ){
	HX_STACK_PUSH("XMLHTTPRequest::get_responseXML","cocktail/core/http/XMLHTTPRequest.hx",725);
	HX_STACK_THIS(this);
	HX_STACK_LINE(726)
	if (((bool((this->responseType != HX_CSTRING(""))) && bool((this->responseType != HX_CSTRING("document")))))){
		HX_STACK_LINE(728)
		hx::Throw ((int)11);
		HX_STACK_LINE(729)
		return null();
	}
	HX_STACK_LINE(732)
	if (((this->readyState != (int)4))){
		HX_STACK_LINE(733)
		return null();
	}
	HX_STACK_LINE(737)
	if (((this->_error == true))){
		HX_STACK_LINE(738)
		return null();
	}
	HX_STACK_LINE(742)
	return this->responseXML;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_responseXML,return )

::String XMLHTTPRequest_obj::get_responseText( ){
	HX_STACK_PUSH("XMLHTTPRequest::get_responseText","cocktail/core/http/XMLHTTPRequest.hx",697);
	HX_STACK_THIS(this);
	HX_STACK_LINE(698)
	if (((bool((this->responseType != HX_CSTRING(""))) && bool((this->responseType != HX_CSTRING("text")))))){
		HX_STACK_LINE(700)
		hx::Throw ((int)11);
		HX_STACK_LINE(701)
		return null();
	}
	HX_STACK_LINE(704)
	switch( (int)(this->readyState)){
		case (int)3: case (int)4: {
		}
		;break;
		default: {
			HX_STACK_LINE(708)
			return HX_CSTRING("");
		}
	}
	HX_STACK_LINE(712)
	if (((this->_error == true))){
		HX_STACK_LINE(713)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(717)
	return this->responseText;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_responseText,return )

Dynamic XMLHTTPRequest_obj::get_response( ){
	HX_STACK_PUSH("XMLHTTPRequest::get_response","cocktail/core/http/XMLHTTPRequest.hx",649);
	HX_STACK_THIS(this);
	HX_STACK_LINE(649)
	if (((bool((this->responseType == HX_CSTRING(""))) && bool((this->responseType == HX_CSTRING("text")))))){
		HX_STACK_LINE(652)
		switch( (int)(this->readyState)){
			case (int)3: case (int)4: {
			}
			;break;
			default: {
				HX_STACK_LINE(656)
				return HX_CSTRING("");
			}
		}
		HX_STACK_LINE(660)
		if (((this->_error == true))){
			HX_STACK_LINE(661)
			return HX_CSTRING("");
		}
		HX_STACK_LINE(665)
		return this->get_responseText();
	}
	else{
		HX_STACK_LINE(669)
		if (((this->readyState != (int)4))){
			HX_STACK_LINE(670)
			return null();
		}
		HX_STACK_LINE(674)
		if (((this->_error == true))){
			HX_STACK_LINE(675)
			return null();
		}
		HX_STACK_LINE(688)
		return null();
	}
	HX_STACK_LINE(649)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_response,return )

::String XMLHTTPRequest_obj::get_statusText( ){
	HX_STACK_PUSH("XMLHTTPRequest::get_statusText","cocktail/core/http/XMLHTTPRequest.hx",627);
	HX_STACK_THIS(this);
	HX_STACK_LINE(628)
	switch( (int)(this->readyState)){
		case (int)0: case (int)1: {
			HX_STACK_LINE(630)
			return HX_CSTRING("");
		}
		;break;
		default: {
		}
	}
	HX_STACK_LINE(636)
	if (((this->_error == true))){
		HX_STACK_LINE(637)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(641)
	return this->statusText;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_statusText,return )

int XMLHTTPRequest_obj::get_status( ){
	HX_STACK_PUSH("XMLHTTPRequest::get_status","cocktail/core/http/XMLHTTPRequest.hx",605);
	HX_STACK_THIS(this);
	HX_STACK_LINE(606)
	switch( (int)(this->readyState)){
		case (int)0: case (int)1: {
			HX_STACK_LINE(608)
			return (int)0;
		}
		;break;
		default: {
		}
	}
	HX_STACK_LINE(614)
	if (((this->_error == true))){
		HX_STACK_LINE(615)
		return (int)0;
	}
	HX_STACK_LINE(619)
	return this->status;
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,get_status,return )

Void XMLHTTPRequest_obj::fireReadyStateChange( ){
{
		HX_STACK_PUSH("XMLHTTPRequest::fireReadyStateChange","cocktail/core/http/XMLHTTPRequest.hx",590);
		HX_STACK_THIS(this);
		HX_STACK_LINE(591)
		::cocktail::core::event::Event readyStateChangeEvent = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(readyStateChangeEvent,"readyStateChangeEvent");
		HX_STACK_LINE(592)
		readyStateChangeEvent->initEvent(HX_CSTRING("readystatechange"),false,false);
		HX_STACK_LINE(593)
		this->dispatchEvent(readyStateChangeEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,fireReadyStateChange,(void))

Void XMLHTTPRequest_obj::setReadyState( int value){
{
		HX_STACK_PUSH("XMLHTTPRequest::setReadyState","cocktail/core/http/XMLHTTPRequest.hx",580);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(581)
		this->readyState = value;
		HX_STACK_LINE(582)
		this->fireReadyStateChange();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,setReadyState,(void))

Void XMLHTTPRequest_obj::requestError( int error,::String event){
{
		HX_STACK_PUSH("XMLHTTPRequest::requestError","cocktail/core/http/XMLHTTPRequest.hx",534);
		HX_STACK_THIS(this);
		HX_STACK_ARG(error,"error");
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(535)
		this->_nativeHttp->close();
		HX_STACK_LINE(537)
		this->_error = true;
		HX_STACK_LINE(539)
		this->readyState = (int)4;
		HX_STACK_LINE(541)
		if (((this->_synchronous == true))){
			HX_STACK_LINE(543)
			hx::Throw (error);
			HX_STACK_LINE(544)
			return null();
		}
		HX_STACK_LINE(547)
		this->fireReadyStateChange();
		HX_STACK_LINE(549)
		if (((this->_uploadComplete == false))){
			HX_STACK_LINE(551)
			this->_uploadComplete = true;
			HX_STACK_LINE(553)
			::cocktail::core::event::ProgressEvent errorEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
			HX_STACK_LINE(554)
			errorEvent->initEvent(event,false,false);
			HX_STACK_LINE(556)
			this->upload->dispatchEvent(errorEvent);
			HX_STACK_LINE(558)
			::cocktail::core::event::ProgressEvent loadEnd = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(loadEnd,"loadEnd");
			HX_STACK_LINE(559)
			loadEnd->initEvent(HX_CSTRING("loadend"),false,false);
			HX_STACK_LINE(561)
			this->upload->dispatchEvent(loadEnd);
		}
		HX_STACK_LINE(564)
		::cocktail::core::event::ProgressEvent errorEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
		HX_STACK_LINE(565)
		errorEvent->initEvent(event,false,false);
		HX_STACK_LINE(567)
		this->dispatchEvent(errorEvent);
		HX_STACK_LINE(569)
		::cocktail::core::event::ProgressEvent loadEnd = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(loadEnd,"loadEnd");
		HX_STACK_LINE(570)
		loadEnd->initEvent(HX_CSTRING("loadend"),false,false);
		HX_STACK_LINE(572)
		this->dispatchEvent(loadEnd);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(XMLHTTPRequest_obj,requestError,(void))

Void XMLHTTPRequest_obj::makeUploadProgressNotification( ){
{
		HX_STACK_PUSH("XMLHTTPRequest::makeUploadProgressNotification","cocktail/core/http/XMLHTTPRequest.hx",518);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,makeUploadProgressNotification,(void))

Void XMLHTTPRequest_obj::makeProgressNotification( ){
{
		HX_STACK_PUSH("XMLHTTPRequest::makeProgressNotification","cocktail/core/http/XMLHTTPRequest.hx",508);
		HX_STACK_THIS(this);
		HX_STACK_LINE(509)
		::cocktail::core::event::ProgressEvent progressEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(progressEvent,"progressEvent");
		HX_STACK_LINE(510)
		progressEvent->initProgressEvent(HX_CSTRING("progress"),false,false,(this->_nativeHttp->get_total() != (int)0),this->_nativeHttp->get_loaded(),this->_nativeHttp->get_total());
		HX_STACK_LINE(511)
		this->dispatchEvent(progressEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,makeProgressNotification,(void))

Void XMLHTTPRequest_obj::onHttpProgressTick( Float timeStamp){
{
		HX_STACK_PUSH("XMLHTTPRequest::onHttpProgressTick","cocktail/core/http/XMLHTTPRequest.hx",413);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeStamp,"timeStamp");
		HX_STACK_LINE(415)
		this->status = this->_nativeHttp->status;
		HX_STACK_LINE(419)
		if (((this->_error == true))){
			HX_STACK_LINE(420)
			return null();
		}
		HX_STACK_LINE(425)
		this->makeProgressNotification();
		HX_STACK_LINE(426)
		this->makeUploadProgressNotification();
		HX_STACK_LINE(429)
		if (((this->readyState == (int)1))){
			HX_STACK_LINE(430)
			if (((bool((this->_nativeHttp->responseHeadersLoaded == true)) && bool((this->_synchronous == false))))){
				HX_STACK_LINE(438)
				this->_responseHeaders = this->_nativeHttp->responseHeaders;
				HX_STACK_LINE(439)
				this->setReadyState((int)2);
			}
		}
		HX_STACK_LINE(443)
		if (((this->readyState == (int)2))){
			HX_STACK_LINE(444)
			if (((this->_synchronous == false))){
				HX_STACK_LINE(448)
				if (((this->_nativeHttp->get_loaded() > (int)0))){
					HX_STACK_LINE(451)
					this->setReadyState((int)3);
				}
			}
		}
		HX_STACK_LINE(461)
		if (((bool((this->readyState == (int)3)) || bool((this->_nativeHttp->complete == true))))){
			HX_STACK_LINE(462)
			if (((this->_nativeHttp->complete == true))){
				HX_STACK_LINE(472)
				this->_synchronous = false;
				HX_STACK_LINE(476)
				this->response = this->_nativeHttp->response;
				HX_STACK_LINE(477)
				this->responseText = this->_nativeHttp->response;
				HX_STACK_LINE(480)
				this->setReadyState((int)4);
				HX_STACK_LINE(483)
				::cocktail::core::event::ProgressEvent loadEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(loadEvent,"loadEvent");
				HX_STACK_LINE(484)
				loadEvent->initEvent(HX_CSTRING("load"),false,false);
				HX_STACK_LINE(485)
				this->dispatchEvent(loadEvent);
				HX_STACK_LINE(487)
				::cocktail::core::event::ProgressEvent loadEndEvent = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(loadEndEvent,"loadEndEvent");
				HX_STACK_LINE(488)
				loadEndEvent->initEvent(HX_CSTRING("loadend"),false,false);
				HX_STACK_LINE(489)
				this->dispatchEvent(loadEndEvent);
				HX_STACK_LINE(493)
				return null();
			}
		}
		HX_STACK_LINE(498)
		::cocktail::Lib_obj::get_document()->timer->delay(this->onHttpProgressTick_dyn(),(int)50);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,onHttpProgressTick,(void))

Void XMLHTTPRequest_obj::setRequestHeader( ::String header,::String value){
{
		HX_STACK_PUSH("XMLHTTPRequest::setRequestHeader","cocktail/core/http/XMLHTTPRequest.hx",359);
		HX_STACK_THIS(this);
		HX_STACK_ARG(header,"header");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(360)
		if (((bool((this->readyState != (int)1)) || bool((this->_send == true))))){
			HX_STACK_LINE(362)
			hx::Throw ((int)11);
			HX_STACK_LINE(363)
			return null();
		}
		HX_STACK_LINE(376)
		::String _switch_1 = (header.toLowerCase());
		if (  ( _switch_1==HX_CSTRING("accept-charset")) ||  ( _switch_1==HX_CSTRING("accept-encoding")) ||  ( _switch_1==HX_CSTRING("access-control-request-headers")) ||  ( _switch_1==HX_CSTRING("access-control-request-method")) ||  ( _switch_1==HX_CSTRING("connection")) ||  ( _switch_1==HX_CSTRING("content-length")) ||  ( _switch_1==HX_CSTRING("cookie")) ||  ( _switch_1==HX_CSTRING("cookie2")) ||  ( _switch_1==HX_CSTRING("content-transfer-encoding")) ||  ( _switch_1==HX_CSTRING("date")) ||  ( _switch_1==HX_CSTRING("expect")) ||  ( _switch_1==HX_CSTRING("host")) ||  ( _switch_1==HX_CSTRING("keep-alive")) ||  ( _switch_1==HX_CSTRING("origin")) ||  ( _switch_1==HX_CSTRING("referer")) ||  ( _switch_1==HX_CSTRING("te")) ||  ( _switch_1==HX_CSTRING("trailer")) ||  ( _switch_1==HX_CSTRING("transfer-encoding")) ||  ( _switch_1==HX_CSTRING("upgrade")) ||  ( _switch_1==HX_CSTRING("user-agent")) ||  ( _switch_1==HX_CSTRING("via"))){
			HX_STACK_LINE(378)
			return null();
		}
		HX_STACK_LINE(387)
		if (((bool((header.toLowerCase().substr((int)0,(int)6) == HX_CSTRING("proxy-"))) || bool((header.toLowerCase().substr((int)0,(int)4) == HX_CSTRING("sec-")))))){
			HX_STACK_LINE(388)
			return null();
		}
		HX_STACK_LINE(392)
		if (((this->_authorRequestHeaders->exists(header) == false))){
			HX_STACK_LINE(393)
			this->_authorRequestHeaders->set(header,value);
		}
		else{
			HX_STACK_LINE(397)
			this->_authorRequestHeaders->set(header,value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(XMLHTTPRequest_obj,setRequestHeader,(void))

Void XMLHTTPRequest_obj::abort( ){
{
		HX_STACK_PUSH("XMLHTTPRequest::abort","cocktail/core/http/XMLHTTPRequest.hx",346);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(XMLHTTPRequest_obj,abort,(void))

Void XMLHTTPRequest_obj::send( ::String data){
{
		HX_STACK_PUSH("XMLHTTPRequest::send","cocktail/core/http/XMLHTTPRequest.hx",261);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_LINE(262)
		if (((bool((this->readyState != (int)1)) || bool((this->_send == true))))){
			HX_STACK_LINE(264)
			hx::Throw ((int)11);
			HX_STACK_LINE(265)
			return null();
		}
		HX_STACK_LINE(268)
		bool useRequestEntityBody = (data != null());		HX_STACK_VAR(useRequestEntityBody,"useRequestEntityBody");
		HX_STACK_LINE(272)
		::String _switch_2 = (this->_method);
		if (  ( _switch_2==HX_CSTRING("GET")) ||  ( _switch_2==HX_CSTRING("HEAD"))){
			HX_STACK_LINE(274)
			useRequestEntityBody = false;
		}
		HX_STACK_LINE(278)
		if (((useRequestEntityBody == true))){
		}
		HX_STACK_LINE(304)
		if (((this->_synchronous == true))){
		}
		else{
			HX_STACK_LINE(308)
			if (((this->_registeredEventListeners != null()))){
				HX_STACK_LINE(309)
				this->_uploadEvents = true;
			}
		}
		HX_STACK_LINE(313)
		this->_error = false;
		HX_STACK_LINE(315)
		if (((bool((useRequestEntityBody == false)) || bool((data == null()))))){
			HX_STACK_LINE(316)
			this->_uploadComplete = true;
		}
		HX_STACK_LINE(320)
		if (((this->_synchronous == false))){
			HX_STACK_LINE(322)
			this->_send = true;
			HX_STACK_LINE(324)
			this->fireReadyStateChange();
			HX_STACK_LINE(326)
			::cocktail::core::event::ProgressEvent loadStart = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(loadStart,"loadStart");
			HX_STACK_LINE(327)
			loadStart->initEvent(HX_CSTRING("loadstart"),false,false);
			HX_STACK_LINE(328)
			this->dispatchEvent(loadStart);
			HX_STACK_LINE(330)
			if (((this->_uploadComplete == false))){
				HX_STACK_LINE(332)
				::cocktail::core::event::ProgressEvent uploadLoadStart = ::cocktail::core::event::ProgressEvent_obj::__new();		HX_STACK_VAR(uploadLoadStart,"uploadLoadStart");
				HX_STACK_LINE(333)
				uploadLoadStart->initEvent(HX_CSTRING("loadstart"),false,false);
				HX_STACK_LINE(334)
				this->upload->dispatchEvent(uploadLoadStart);
			}
		}
		HX_STACK_LINE(338)
		this->_nativeHttp->load(this->_url,this->_method,data,this->_authorRequestHeaders,::cocktail::core::http::DataFormatValue_obj::TEXT_dyn());
		HX_STACK_LINE(339)
		this->onHttpProgressTick((int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(XMLHTTPRequest_obj,send,(void))

Void XMLHTTPRequest_obj::open( ::String method,::String url,hx::Null< bool >  __o_async,::String user,::String password){
bool async = __o_async.Default(true);
	HX_STACK_PUSH("XMLHTTPRequest::open","cocktail/core/http/XMLHTTPRequest.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_ARG(method,"method");
	HX_STACK_ARG(url,"url");
	HX_STACK_ARG(async,"async");
	HX_STACK_ARG(user,"user");
	HX_STACK_ARG(password,"password");
{
		HX_STACK_LINE(198)
		::String _switch_3 = (method.toUpperCase());
		if (  ( _switch_3==HX_CSTRING("DELETE")) ||  ( _switch_3==HX_CSTRING("GET")) ||  ( _switch_3==HX_CSTRING("HEAD")) ||  ( _switch_3==HX_CSTRING("OPTIONS")) ||  ( _switch_3==HX_CSTRING("POST")) ||  ( _switch_3==HX_CSTRING("PUT"))){
		}
		else if (  ( _switch_3==HX_CSTRING("CONNECT")) ||  ( _switch_3==HX_CSTRING("TRACE")) ||  ( _switch_3==HX_CSTRING("TRACK"))){
			HX_STACK_LINE(206)
			hx::Throw ((int)18);
			HX_STACK_LINE(207)
			return null();
		}
		else  {
			HX_STACK_LINE(211)
			hx::Throw ((int)12);
			HX_STACK_LINE(212)
			return null();
		}
;
;
		HX_STACK_LINE(231)
		this->_method = method;
		HX_STACK_LINE(232)
		this->_url = url;
		HX_STACK_LINE(234)
		if (((async == false))){
			HX_STACK_LINE(235)
			this->_synchronous = true;
		}
		HX_STACK_LINE(243)
		this->_authorRequestHeaders = ::Hash_obj::__new();
		HX_STACK_LINE(244)
		this->_send = false;
		HX_STACK_LINE(245)
		this->response = null();
		HX_STACK_LINE(247)
		this->setReadyState((int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(XMLHTTPRequest_obj,open,(void))

int XMLHTTPRequest_obj::PROGRESS_UPDATE_FREQUENCY;


XMLHTTPRequest_obj::XMLHTTPRequest_obj()
{
}

void XMLHTTPRequest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(XMLHTTPRequest);
	HX_MARK_MEMBER_NAME(_uploadEvents,"_uploadEvents");
	HX_MARK_MEMBER_NAME(_uploadComplete,"_uploadComplete");
	HX_MARK_MEMBER_NAME(_requestEntityBody,"_requestEntityBody");
	HX_MARK_MEMBER_NAME(_authorRequestHeaders,"_authorRequestHeaders");
	HX_MARK_MEMBER_NAME(_password,"_password");
	HX_MARK_MEMBER_NAME(_username,"_username");
	HX_MARK_MEMBER_NAME(_synchronous,"_synchronous");
	HX_MARK_MEMBER_NAME(_url,"_url");
	HX_MARK_MEMBER_NAME(_method,"_method");
	HX_MARK_MEMBER_NAME(_error,"_error");
	HX_MARK_MEMBER_NAME(_send,"_send");
	HX_MARK_MEMBER_NAME(_responseHeaders,"_responseHeaders");
	HX_MARK_MEMBER_NAME(_nativeHttp,"_nativeHttp");
	HX_MARK_MEMBER_NAME(onreadystatechange,"onreadystatechange");
	HX_MARK_MEMBER_NAME(statusText,"statusText");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(upload,"upload");
	HX_MARK_MEMBER_NAME(responseType,"responseType");
	HX_MARK_MEMBER_NAME(responseXML,"responseXML");
	HX_MARK_MEMBER_NAME(responseText,"responseText");
	HX_MARK_MEMBER_NAME(response,"response");
	HX_MARK_MEMBER_NAME(readyState,"readyState");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void XMLHTTPRequest_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_uploadEvents,"_uploadEvents");
	HX_VISIT_MEMBER_NAME(_uploadComplete,"_uploadComplete");
	HX_VISIT_MEMBER_NAME(_requestEntityBody,"_requestEntityBody");
	HX_VISIT_MEMBER_NAME(_authorRequestHeaders,"_authorRequestHeaders");
	HX_VISIT_MEMBER_NAME(_password,"_password");
	HX_VISIT_MEMBER_NAME(_username,"_username");
	HX_VISIT_MEMBER_NAME(_synchronous,"_synchronous");
	HX_VISIT_MEMBER_NAME(_url,"_url");
	HX_VISIT_MEMBER_NAME(_method,"_method");
	HX_VISIT_MEMBER_NAME(_error,"_error");
	HX_VISIT_MEMBER_NAME(_send,"_send");
	HX_VISIT_MEMBER_NAME(_responseHeaders,"_responseHeaders");
	HX_VISIT_MEMBER_NAME(_nativeHttp,"_nativeHttp");
	HX_VISIT_MEMBER_NAME(onreadystatechange,"onreadystatechange");
	HX_VISIT_MEMBER_NAME(statusText,"statusText");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(upload,"upload");
	HX_VISIT_MEMBER_NAME(responseType,"responseType");
	HX_VISIT_MEMBER_NAME(responseXML,"responseXML");
	HX_VISIT_MEMBER_NAME(responseText,"responseText");
	HX_VISIT_MEMBER_NAME(response,"response");
	HX_VISIT_MEMBER_NAME(readyState,"readyState");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic XMLHTTPRequest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"send") ) { return send_dyn(); }
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		if (HX_FIELD_EQ(inName,"_url") ) { return _url; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"abort") ) { return abort_dyn(); }
		if (HX_FIELD_EQ(inName,"_send") ) { return _send; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_error") ) { return _error; }
		if (HX_FIELD_EQ(inName,"status") ) { return inCallProp ? get_status() : status; }
		if (HX_FIELD_EQ(inName,"upload") ) { return upload; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_method") ) { return _method; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { return inCallProp ? get_response() : response; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_password") ) { return _password; }
		if (HX_FIELD_EQ(inName,"_username") ) { return _username; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_status") ) { return get_status_dyn(); }
		if (HX_FIELD_EQ(inName,"statusText") ) { return inCallProp ? get_statusText() : statusText; }
		if (HX_FIELD_EQ(inName,"readyState") ) { return readyState; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_nativeHttp") ) { return _nativeHttp; }
		if (HX_FIELD_EQ(inName,"responseXML") ) { return inCallProp ? get_responseXML() : responseXML; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_response") ) { return get_response_dyn(); }
		if (HX_FIELD_EQ(inName,"requestError") ) { return requestError_dyn(); }
		if (HX_FIELD_EQ(inName,"_synchronous") ) { return _synchronous; }
		if (HX_FIELD_EQ(inName,"responseType") ) { return responseType; }
		if (HX_FIELD_EQ(inName,"responseText") ) { return inCallProp ? get_responseText() : responseText; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setReadyState") ) { return setReadyState_dyn(); }
		if (HX_FIELD_EQ(inName,"_uploadEvents") ) { return _uploadEvents; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_statusText") ) { return get_statusText_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_responseXML") ) { return get_responseXML_dyn(); }
		if (HX_FIELD_EQ(inName,"_uploadComplete") ) { return _uploadComplete; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_responseType") ) { return set_responseType_dyn(); }
		if (HX_FIELD_EQ(inName,"get_responseText") ) { return get_responseText_dyn(); }
		if (HX_FIELD_EQ(inName,"setRequestHeader") ) { return setRequestHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"_responseHeaders") ) { return _responseHeaders; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onHttpProgressTick") ) { return onHttpProgressTick_dyn(); }
		if (HX_FIELD_EQ(inName,"_requestEntityBody") ) { return _requestEntityBody; }
		if (HX_FIELD_EQ(inName,"onreadystatechange") ) { return onreadystatechange; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"fireReadyStateChange") ) { return fireReadyStateChange_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_authorRequestHeaders") ) { return _authorRequestHeaders; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"set_onReadyStateChange") ) { return set_onReadyStateChange_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"makeProgressNotification") ) { return makeProgressNotification_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"PROGRESS_UPDATE_FREQUENCY") ) { return PROGRESS_UPDATE_FREQUENCY; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"makeUploadProgressNotification") ) { return makeUploadProgressNotification_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic XMLHTTPRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_url") ) { _url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_send") ) { _send=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_error") ) { _error=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upload") ) { upload=inValue.Cast< ::cocktail::core::http::XMLHttpRequestUpload >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_method") ) { _method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { response=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_password") ) { _password=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_username") ) { _username=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"statusText") ) { statusText=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"readyState") ) { readyState=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_nativeHttp") ) { _nativeHttp=inValue.Cast< ::cocktail::port::platform::nme::NativeHttp >(); return inValue; }
		if (HX_FIELD_EQ(inName,"responseXML") ) { responseXML=inValue.Cast< ::cocktail::core::dom::Document >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_synchronous") ) { _synchronous=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"responseType") ) { if (inCallProp) return set_responseType(inValue);responseType=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"responseText") ) { responseText=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_uploadEvents") ) { _uploadEvents=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_uploadComplete") ) { _uploadComplete=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_responseHeaders") ) { _responseHeaders=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_requestEntityBody") ) { _requestEntityBody=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onreadystatechange") ) { if (inCallProp) return set_onReadyStateChange(inValue);onreadystatechange=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_authorRequestHeaders") ) { _authorRequestHeaders=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"PROGRESS_UPDATE_FREQUENCY") ) { PROGRESS_UPDATE_FREQUENCY=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void XMLHTTPRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_uploadEvents"));
	outFields->push(HX_CSTRING("_uploadComplete"));
	outFields->push(HX_CSTRING("_requestEntityBody"));
	outFields->push(HX_CSTRING("_authorRequestHeaders"));
	outFields->push(HX_CSTRING("_password"));
	outFields->push(HX_CSTRING("_username"));
	outFields->push(HX_CSTRING("_synchronous"));
	outFields->push(HX_CSTRING("_url"));
	outFields->push(HX_CSTRING("_method"));
	outFields->push(HX_CSTRING("_error"));
	outFields->push(HX_CSTRING("_send"));
	outFields->push(HX_CSTRING("_responseHeaders"));
	outFields->push(HX_CSTRING("_nativeHttp"));
	outFields->push(HX_CSTRING("statusText"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("upload"));
	outFields->push(HX_CSTRING("responseType"));
	outFields->push(HX_CSTRING("responseXML"));
	outFields->push(HX_CSTRING("responseText"));
	outFields->push(HX_CSTRING("response"));
	outFields->push(HX_CSTRING("readyState"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROGRESS_UPDATE_FREQUENCY"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_onReadyStateChange"),
	HX_CSTRING("set_responseType"),
	HX_CSTRING("get_responseXML"),
	HX_CSTRING("get_responseText"),
	HX_CSTRING("get_response"),
	HX_CSTRING("get_statusText"),
	HX_CSTRING("get_status"),
	HX_CSTRING("fireReadyStateChange"),
	HX_CSTRING("setReadyState"),
	HX_CSTRING("requestError"),
	HX_CSTRING("makeUploadProgressNotification"),
	HX_CSTRING("makeProgressNotification"),
	HX_CSTRING("onHttpProgressTick"),
	HX_CSTRING("setRequestHeader"),
	HX_CSTRING("abort"),
	HX_CSTRING("send"),
	HX_CSTRING("open"),
	HX_CSTRING("_uploadEvents"),
	HX_CSTRING("_uploadComplete"),
	HX_CSTRING("_requestEntityBody"),
	HX_CSTRING("_authorRequestHeaders"),
	HX_CSTRING("_password"),
	HX_CSTRING("_username"),
	HX_CSTRING("_synchronous"),
	HX_CSTRING("_url"),
	HX_CSTRING("_method"),
	HX_CSTRING("_error"),
	HX_CSTRING("_send"),
	HX_CSTRING("_responseHeaders"),
	HX_CSTRING("_nativeHttp"),
	HX_CSTRING("onreadystatechange"),
	HX_CSTRING("statusText"),
	HX_CSTRING("status"),
	HX_CSTRING("upload"),
	HX_CSTRING("responseType"),
	HX_CSTRING("responseXML"),
	HX_CSTRING("responseText"),
	HX_CSTRING("response"),
	HX_CSTRING("readyState"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(XMLHTTPRequest_obj::PROGRESS_UPDATE_FREQUENCY,"PROGRESS_UPDATE_FREQUENCY");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(XMLHTTPRequest_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(XMLHTTPRequest_obj::PROGRESS_UPDATE_FREQUENCY,"PROGRESS_UPDATE_FREQUENCY");
};

Class XMLHTTPRequest_obj::__mClass;

void XMLHTTPRequest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.http.XMLHTTPRequest"), hx::TCanCast< XMLHTTPRequest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void XMLHTTPRequest_obj::__boot()
{
	PROGRESS_UPDATE_FREQUENCY= (int)50;
}

} // end namespace cocktail
} // end namespace core
} // end namespace http
