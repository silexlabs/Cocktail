#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_events_ErrorEvent
#include <nme/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IOErrorEvent
#include <nme/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_ProgressEvent
#include <nme/events/ProgressEvent.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
#ifndef INCLUDED_nme_net_URLLoader
#include <nme/net/URLLoader.h>
#endif
#ifndef INCLUDED_nme_net_URLLoaderDataFormat
#include <nme/net/URLLoaderDataFormat.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_net_URLVariables
#include <nme/net/URLVariables.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace nme{
namespace net{

Void URLLoader_obj::__construct(::nme::net::URLRequest request)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",59)
	super::__construct(null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",60)
	this->nmeHandle = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",61)
	this->bytesLoaded = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",62)
	this->bytesTotal = (int)-1;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",63)
	this->state = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",64)
	this->dataFormat = ::nme::net::URLLoaderDataFormat_obj::TEXT_dyn();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",65)
	if (((request != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",66)
		this->load(request);
	}
}
;
	return null();
}

URLLoader_obj::~URLLoader_obj() { }

Dynamic URLLoader_obj::__CreateEmpty() { return  new URLLoader_obj; }
hx::ObjectPtr< URLLoader_obj > URLLoader_obj::__new(::nme::net::URLRequest request)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(request);
	return result;}

Dynamic URLLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLLoader_obj::close( ){
{
		HX_SOURCE_PUSH("URLLoader_obj::close")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,close,(void))

Array< ::String > URLLoader_obj::getCookies( ){
	HX_SOURCE_PUSH("URLLoader_obj::getCookies")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",77)
	return ::nme::net::URLLoader_obj::nme_curl_get_cookies(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,getCookies,return )

Void URLLoader_obj::load( ::nme::net::URLRequest request){
{
		HX_SOURCE_PUSH("URLLoader_obj::load")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",96)
		this->state = (int)1;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",97)
		::String pref = request->url.substr((int)0,(int)7);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",98)
		if (((bool((pref != HX_CSTRING("http://"))) && bool((pref != HX_CSTRING("https:/")))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",100)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",101)
				::nme::utils::ByteArray bytes = ::nme::utils::ByteArray_obj::readFile(request->url);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",102)
				{
::nme::net::URLLoaderDataFormat _switch_1 = (this->dataFormat);
					switch((_switch_1)->GetIndex()){
						case 1: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",104)
							this->data = bytes->asString();
						}
						;break;
						case 2: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",106)
							this->data = ::nme::net::URLVariables_obj::__new(bytes->asString());
						}
						;break;
						default: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",108)
							this->data = bytes;
						}
					}
				}
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",114)
						this->onError(e);
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",115)
						return null();
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",118)
			this->nmeDataComplete();
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",122)
			request->nmePrepare();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",123)
			this->nmeHandle = ::nme::net::URLLoader_obj::nme_curl_create(request);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",124)
			if (((this->nmeHandle == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",125)
				this->onError(HX_CSTRING("Could not open URL"));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",129)
				::nme::net::URLLoader_obj::activeLoaders->push(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,load,(void))

Void URLLoader_obj::nmeDataComplete( ){
{
		HX_SOURCE_PUSH("URLLoader_obj::nmeDataComplete")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",134)
		if (((this->nmeOnComplete_dyn() != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",136)
			if ((this->nmeOnComplete(this->data))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",138)
				this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::COMPLETE,null(),null()));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",140)
				this->DispatchIOErrorEvent();
			}
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",143)
			this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::COMPLETE,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,nmeDataComplete,(void))

Void URLLoader_obj::onError( ::String msg){
{
		HX_SOURCE_PUSH("URLLoader_obj::onError")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",180)
		this->dispatchEvent(::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,true,false,msg,null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,onError,(void))

Void URLLoader_obj::update( ){
{
		HX_SOURCE_PUSH("URLLoader_obj::update")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",186)
		if (((this->nmeHandle != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",189)
			int old_loaded = this->bytesLoaded;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",190)
			int old_total = this->bytesTotal;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",191)
			::nme::net::URLLoader_obj::nme_curl_update_loader(this->nmeHandle,hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",192)
			if (((bool((old_total < (int)0)) && bool((this->bytesTotal > (int)0))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",193)
				this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::OPEN,null(),null()));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",197)
			if (((bool((this->bytesTotal > (int)0)) && bool((this->bytesLoaded != old_loaded))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",198)
				this->dispatchEvent(::nme::events::ProgressEvent_obj::__new(HX_CSTRING("progress"),false,false,this->bytesLoaded,this->bytesTotal));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",202)
			int code = ::nme::net::URLLoader_obj::nme_curl_get_code(this->nmeHandle);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",203)
			if (((this->state == (int)3))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",204)
				if (((code < (int)400))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",207)
					::nme::utils::ByteArray bytes = ::nme::net::URLLoader_obj::nme_curl_get_data(this->nmeHandle);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",208)
					{
::nme::net::URLLoaderDataFormat _switch_2 = (this->dataFormat);
						switch((_switch_2)->GetIndex()){
							case 1: case 2: {
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",210)
								this->data = (  (((bytes == null()))) ? ::String(HX_CSTRING("")) : ::String(bytes->asString()) );
							}
							;break;
							default: {
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",212)
								this->data = bytes;
							}
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",215)
					this->nmeDataComplete();
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",220)
					::nme::events::IOErrorEvent evt = ::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,true,false,(HX_CSTRING("HTTP status code ") + ::Std_obj::string(code)),code);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",221)
					this->nmeHandle = null();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",222)
					this->dispatchEvent(evt);
				}
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",225)
				if (((this->state == (int)4))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",227)
					::nme::events::IOErrorEvent evt = ::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,true,false,::nme::net::URLLoader_obj::nme_curl_get_error_message(this->nmeHandle),code);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",228)
					this->nmeHandle = null();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",229)
					this->dispatchEvent(evt);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,update,(void))

::List URLLoader_obj::activeLoaders;

int URLLoader_obj::urlInvalid;

int URLLoader_obj::urlInit;

int URLLoader_obj::urlLoading;

int URLLoader_obj::urlComplete;

int URLLoader_obj::urlError;

bool URLLoader_obj::hasActive( ){
	HX_SOURCE_PUSH("URLLoader_obj::hasActive")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",83)
	return !(::nme::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,hasActive,return )

Void URLLoader_obj::initialize( ::String inCACertFilePath){
{
		HX_SOURCE_PUSH("URLLoader_obj::initialize")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",89)
		::nme::net::URLLoader_obj::nme_curl_initialize(inCACertFilePath);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,initialize,(void))

bool URLLoader_obj::nmeLoadPending( ){
	HX_SOURCE_PUSH("URLLoader_obj::nmeLoadPending")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",154)
	return !(::nme::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,nmeLoadPending,return )

Void URLLoader_obj::nmePollData( ){
{
		HX_SOURCE_PUSH("URLLoader_obj::nmePollData")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",163)
		if ((!(::nme::net::URLLoader_obj::activeLoaders->isEmpty()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",166)
			::nme::net::URLLoader_obj::nme_curl_process_loaders();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",167)
			::List oldLoaders = ::nme::net::URLLoader_obj::activeLoaders;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",168)
			::nme::net::URLLoader_obj::activeLoaders = ::List_obj::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",169)
			for(::cpp::FastIterator_obj< ::nme::net::URLLoader > *__it = ::cpp::CreateFastIterator< ::nme::net::URLLoader >(oldLoaders->iterator());  __it->hasNext(); ){
				::nme::net::URLLoader loader = __it->next();
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",171)
					loader->update();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",172)
					if (((loader->state == (int)2))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/net/URLLoader.hx",173)
						::nme::net::URLLoader_obj::activeLoaders->push(loader);
					}
				}
;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,nmePollData,(void))

Dynamic URLLoader_obj::nme_curl_create;

Dynamic URLLoader_obj::nme_curl_process_loaders;

Dynamic URLLoader_obj::nme_curl_update_loader;

Dynamic URLLoader_obj::nme_curl_get_code;

Dynamic URLLoader_obj::nme_curl_get_error_message;

Dynamic URLLoader_obj::nme_curl_get_data;

Dynamic URLLoader_obj::nme_curl_get_cookies;

Dynamic URLLoader_obj::nme_curl_initialize;


URLLoader_obj::URLLoader_obj()
{
}

void URLLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLLoader);
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(dataFormat,"dataFormat");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(nmeOnComplete,"nmeOnComplete");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic URLLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"urlInit") ) { return urlInit; }
		if (HX_FIELD_EQ(inName,"onError") ) { return onError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"urlError") ) { return urlError; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasActive") ) { return hasActive_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"urlInvalid") ) { return urlInvalid; }
		if (HX_FIELD_EQ(inName,"urlLoading") ) { return urlLoading; }
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		if (HX_FIELD_EQ(inName,"dataFormat") ) { return dataFormat; }
		if (HX_FIELD_EQ(inName,"getCookies") ) { return getCookies_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"urlComplete") ) { return urlComplete; }
		if (HX_FIELD_EQ(inName,"nmePollData") ) { return nmePollData_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { return activeLoaders; }
		if (HX_FIELD_EQ(inName,"nmeOnComplete") ) { return nmeOnComplete; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeLoadPending") ) { return nmeLoadPending_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_curl_create") ) { return nme_curl_create; }
		if (HX_FIELD_EQ(inName,"nmeDataComplete") ) { return nmeDataComplete_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_curl_get_code") ) { return nme_curl_get_code; }
		if (HX_FIELD_EQ(inName,"nme_curl_get_data") ) { return nme_curl_get_data; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_curl_initialize") ) { return nme_curl_initialize; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_curl_get_cookies") ) { return nme_curl_get_cookies; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_curl_update_loader") ) { return nme_curl_update_loader; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_curl_process_loaders") ) { return nme_curl_process_loaders; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_curl_get_error_message") ) { return nme_curl_get_error_message; }
	}
	return super::__Field(inName);
}

Dynamic URLLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"urlInit") ) { urlInit=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"urlError") ) { urlError=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"urlInvalid") ) { urlInvalid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"urlLoading") ) { urlLoading=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dataFormat") ) { dataFormat=inValue.Cast< ::nme::net::URLLoaderDataFormat >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"urlComplete") ) { urlComplete=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { activeLoaders=inValue.Cast< ::List >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeOnComplete") ) { nmeOnComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_curl_create") ) { nme_curl_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_curl_get_code") ) { nme_curl_get_code=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_curl_get_data") ) { nme_curl_get_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_curl_initialize") ) { nme_curl_initialize=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_curl_get_cookies") ) { nme_curl_get_cookies=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_curl_update_loader") ) { nme_curl_update_loader=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_curl_process_loaders") ) { nme_curl_process_loaders=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_curl_get_error_message") ) { nme_curl_get_error_message=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void URLLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("dataFormat"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("state"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("activeLoaders"),
	HX_CSTRING("urlInvalid"),
	HX_CSTRING("urlInit"),
	HX_CSTRING("urlLoading"),
	HX_CSTRING("urlComplete"),
	HX_CSTRING("urlError"),
	HX_CSTRING("hasActive"),
	HX_CSTRING("initialize"),
	HX_CSTRING("nmeLoadPending"),
	HX_CSTRING("nmePollData"),
	HX_CSTRING("nme_curl_create"),
	HX_CSTRING("nme_curl_process_loaders"),
	HX_CSTRING("nme_curl_update_loader"),
	HX_CSTRING("nme_curl_get_code"),
	HX_CSTRING("nme_curl_get_error_message"),
	HX_CSTRING("nme_curl_get_data"),
	HX_CSTRING("nme_curl_get_cookies"),
	HX_CSTRING("nme_curl_initialize"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("data"),
	HX_CSTRING("dataFormat"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("state"),
	HX_CSTRING("nmeOnComplete"),
	HX_CSTRING("close"),
	HX_CSTRING("getCookies"),
	HX_CSTRING("load"),
	HX_CSTRING("nmeDataComplete"),
	HX_CSTRING("onError"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLLoader_obj::activeLoaders,"activeLoaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInvalid,"urlInvalid");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInit,"urlInit");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlLoading,"urlLoading");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlComplete,"urlComplete");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlError,"urlError");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_create,"nme_curl_create");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_process_loaders,"nme_curl_process_loaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_update_loader,"nme_curl_update_loader");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_code,"nme_curl_get_code");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_error_message,"nme_curl_get_error_message");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_data,"nme_curl_get_data");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_cookies,"nme_curl_get_cookies");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_initialize,"nme_curl_initialize");
};

Class URLLoader_obj::__mClass;

void URLLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.net.URLLoader"), hx::TCanCast< URLLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLLoader_obj::__boot()
{
	hx::Static(activeLoaders) = ::List_obj::__new();
	hx::Static(urlInvalid) = (int)0;
	hx::Static(urlInit) = (int)1;
	hx::Static(urlLoading) = (int)2;
	hx::Static(urlComplete) = (int)3;
	hx::Static(urlError) = (int)4;
	hx::Static(nme_curl_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_create"),(int)1);
	hx::Static(nme_curl_process_loaders) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_process_loaders"),(int)0);
	hx::Static(nme_curl_update_loader) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_update_loader"),(int)2);
	hx::Static(nme_curl_get_code) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_code"),(int)1);
	hx::Static(nme_curl_get_error_message) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_error_message"),(int)1);
	hx::Static(nme_curl_get_data) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_data"),(int)1);
	hx::Static(nme_curl_get_cookies) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_cookies"),(int)1);
	hx::Static(nme_curl_initialize) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_initialize"),(int)1);
}

} // end namespace nme
} // end namespace net
