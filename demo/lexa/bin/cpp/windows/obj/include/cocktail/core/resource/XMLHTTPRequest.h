#ifndef INCLUDED_cocktail_core_resource_XMLHTTPRequest
#define INCLUDED_cocktail_core_resource_XMLHTTPRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/IEventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,XMLHTTPRequest)
HX_DECLARE_CLASS1(haxe,Http)
namespace cocktail{
namespace core{
namespace resource{


class XMLHTTPRequest_obj : public hx::Object{
	public:
		typedef hx::Object super;
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
		inline operator ::cocktail::core::event::IEventTarget_obj *()
			{ return new ::cocktail::core::event::IEventTarget_delegate_< XMLHTTPRequest_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("XMLHTTPRequest"); }

		int _readyState; /* REM */ 
		int readyState; /* REM */ 
		::String _responseText; /* REM */ 
		::String responseText; /* REM */ 
		int _status; /* REM */ 
		int status; /* REM */ 
		Dynamic onReadyStateChange; /* REM */ 
	Dynamic &onReadyStateChange_dyn() { return onReadyStateChange;}
		::haxe::Http _http; /* REM */ 
		::String _method; /* REM */ 
		virtual Void open( ::String method,::String url);
		Dynamic open_dyn();

		virtual Void send( ::String content);
		Dynamic send_dyn();

		virtual Void setRequestHeader( ::String name,::String value);
		Dynamic setRequestHeader_dyn();

		virtual Void onHTTPStatus( int status);
		Dynamic onHTTPStatus_dyn();

		virtual Void onHTTPData( ::String data);
		Dynamic onHTTPData_dyn();

		virtual Void onHTTPError( ::String data);
		Dynamic onHTTPError_dyn();

		virtual Void setReadyState( int value);
		Dynamic setReadyState_dyn();

		virtual int get_readyState( );
		Dynamic get_readyState_dyn();

		virtual int get_status( );
		Dynamic get_status_dyn();

		virtual ::String get_responseText( );
		Dynamic get_responseText_dyn();

		static int READY_STATE_UNSENT; /* REM */ 
		static int READY_STATE_OPENED; /* REM */ 
		static int READY_STATE_HEADERS_RECEIVED; /* REM */ 
		static int READY_STATE_LOADING; /* REM */ 
		static int READY_STATE_DONE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_XMLHTTPRequest */ 
