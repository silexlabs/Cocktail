#ifndef INCLUDED_cocktail_core_http_XMLHTTPRequest
#define INCLUDED_cocktail_core_http_XMLHTTPRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,XMLHttpRequestEventTarget)
HX_DECLARE_CLASS3(cocktail,core,http,XMLHTTPRequest)
HX_DECLARE_CLASS3(cocktail,core,http,XMLHttpRequestUpload)
HX_DECLARE_CLASS3(cocktail,port,base,NativeHttpBase)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeHttp)
namespace cocktail{
namespace core{
namespace http{


class XMLHTTPRequest_obj : public ::cocktail::core::event::XMLHttpRequestEventTarget_obj{
	public:
		typedef ::cocktail::core::event::XMLHttpRequestEventTarget_obj super;
		typedef XMLHTTPRequest_obj OBJ_;
		XMLHTTPRequest_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< XMLHTTPRequest_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~XMLHTTPRequest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("XMLHTTPRequest"); }

		virtual Dynamic set_onReadyStateChange( Dynamic value);
		Dynamic set_onReadyStateChange_dyn();

		virtual ::String set_responseType( ::String value);
		Dynamic set_responseType_dyn();

		virtual ::cocktail::core::dom::Document get_responseXML( );
		Dynamic get_responseXML_dyn();

		virtual ::String get_responseText( );
		Dynamic get_responseText_dyn();

		virtual Dynamic get_response( );
		Dynamic get_response_dyn();

		virtual ::String get_statusText( );
		Dynamic get_statusText_dyn();

		virtual int get_status( );
		Dynamic get_status_dyn();

		virtual Void fireReadyStateChange( );
		Dynamic fireReadyStateChange_dyn();

		virtual Void setReadyState( int value);
		Dynamic setReadyState_dyn();

		virtual Void requestError( int error,::String event);
		Dynamic requestError_dyn();

		virtual Void makeUploadProgressNotification( );
		Dynamic makeUploadProgressNotification_dyn();

		virtual Void makeProgressNotification( );
		Dynamic makeProgressNotification_dyn();

		virtual Void onHttpProgressTick( Float timeStamp);
		Dynamic onHttpProgressTick_dyn();

		virtual Void setRequestHeader( ::String header,::String value);
		Dynamic setRequestHeader_dyn();

		virtual Void abort( );
		Dynamic abort_dyn();

		virtual Void send( ::String data);
		Dynamic send_dyn();

		virtual Void open( ::String method,::String url,hx::Null< bool >  async,::String user,::String password);
		Dynamic open_dyn();

		bool _uploadEvents; /* REM */ 
		bool _uploadComplete; /* REM */ 
		Dynamic _requestEntityBody; /* REM */ 
		::Hash _authorRequestHeaders; /* REM */ 
		::String _password; /* REM */ 
		::String _username; /* REM */ 
		bool _synchronous; /* REM */ 
		::String _url; /* REM */ 
		::String _method; /* REM */ 
		bool _error; /* REM */ 
		bool _send; /* REM */ 
		::Hash _responseHeaders; /* REM */ 
		::cocktail::port::platform::nme::NativeHttp _nativeHttp; /* REM */ 
		Dynamic onreadystatechange; /* REM */ 
		Dynamic &onreadystatechange_dyn() { return onreadystatechange;}
		::String statusText; /* REM */ 
		int status; /* REM */ 
		::cocktail::core::http::XMLHttpRequestUpload upload; /* REM */ 
		::String responseType; /* REM */ 
		::cocktail::core::dom::Document responseXML; /* REM */ 
		::String responseText; /* REM */ 
		Dynamic response; /* REM */ 
		int readyState; /* REM */ 
		static int PROGRESS_UPDATE_FREQUENCY; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace http

#endif /* INCLUDED_cocktail_core_http_XMLHTTPRequest */ 
