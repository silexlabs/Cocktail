#ifndef INCLUDED_nme_net_URLLoader
#define INCLUDED_nme_net_URLLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/EventDispatcher.h>
HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,net,URLLoader)
HX_DECLARE_CLASS2(nme,net,URLLoaderDataFormat)
HX_DECLARE_CLASS2(nme,net,URLRequest)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
namespace net{


class URLLoader_obj : public ::nme::events::EventDispatcher_obj{
	public:
		typedef ::nme::events::EventDispatcher_obj super;
		typedef URLLoader_obj OBJ_;
		URLLoader_obj();
		Void __construct(::nme::net::URLRequest request);

	public:
		static hx::ObjectPtr< URLLoader_obj > __new(::nme::net::URLRequest request);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~URLLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("URLLoader"); }

		int bytesLoaded; /* REM */ 
		int bytesTotal; /* REM */ 
		Dynamic data; /* REM */ 
		::nme::net::URLLoaderDataFormat dataFormat; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		int state; /* REM */ 
		Dynamic nmeOnComplete; /* REM */ 
	Dynamic &nmeOnComplete_dyn() { return nmeOnComplete;}
		virtual Void close( );
		Dynamic close_dyn();

		virtual Array< ::String > getCookies( );
		Dynamic getCookies_dyn();

		virtual Void load( ::nme::net::URLRequest request);
		Dynamic load_dyn();

		virtual Void nmeDataComplete( );
		Dynamic nmeDataComplete_dyn();

		virtual Void onError( ::String msg);
		Dynamic onError_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		static ::List activeLoaders; /* REM */ 
		static int urlInvalid; /* REM */ 
		static int urlInit; /* REM */ 
		static int urlLoading; /* REM */ 
		static int urlComplete; /* REM */ 
		static int urlError; /* REM */ 
		static bool hasActive( );
		static Dynamic hasActive_dyn();

		static Void initialize( ::String inCACertFilePath);
		static Dynamic initialize_dyn();

		static bool nmeLoadPending( );
		static Dynamic nmeLoadPending_dyn();

		static Void nmePollData( );
		static Dynamic nmePollData_dyn();

		static Dynamic nme_curl_create; /* REM */ 
	Dynamic &nme_curl_create_dyn() { return nme_curl_create;}
		static Dynamic nme_curl_process_loaders; /* REM */ 
	Dynamic &nme_curl_process_loaders_dyn() { return nme_curl_process_loaders;}
		static Dynamic nme_curl_update_loader; /* REM */ 
	Dynamic &nme_curl_update_loader_dyn() { return nme_curl_update_loader;}
		static Dynamic nme_curl_get_code; /* REM */ 
	Dynamic &nme_curl_get_code_dyn() { return nme_curl_get_code;}
		static Dynamic nme_curl_get_error_message; /* REM */ 
	Dynamic &nme_curl_get_error_message_dyn() { return nme_curl_get_error_message;}
		static Dynamic nme_curl_get_data; /* REM */ 
	Dynamic &nme_curl_get_data_dyn() { return nme_curl_get_data;}
		static Dynamic nme_curl_get_cookies; /* REM */ 
	Dynamic &nme_curl_get_cookies_dyn() { return nme_curl_get_cookies;}
		static Dynamic nme_curl_initialize; /* REM */ 
	Dynamic &nme_curl_initialize_dyn() { return nme_curl_initialize;}
};

} // end namespace nme
} // end namespace net

#endif /* INCLUDED_nme_net_URLLoader */ 
