#ifndef INCLUDED_cocktail_port_base_NativeHttpBase
#define INCLUDED_cocktail_port_base_NativeHttpBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventTarget.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,http,DataFormatValue)
HX_DECLARE_CLASS3(cocktail,port,base,NativeHttpBase)
namespace cocktail{
namespace port{
namespace base{


class NativeHttpBase_obj : public ::cocktail::core::event::EventTarget_obj{
	public:
		typedef ::cocktail::core::event::EventTarget_obj super;
		typedef NativeHttpBase_obj OBJ_;
		NativeHttpBase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeHttpBase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeHttpBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeHttpBase"); }

		virtual int get_loaded( );
		Dynamic get_loaded_dyn();

		virtual int get_total( );
		Dynamic get_total_dyn();

		virtual Void onLoadProgress( Float time);
		Dynamic onLoadProgress_dyn();

		virtual Void doLoad( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat);
		Dynamic doLoad_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual Void load( ::String url,::String method,Dynamic data,::Hash authorRequestHeaders,::cocktail::core::http::DataFormatValue dataFormat);
		Dynamic load_dyn();

		bool _closed; /* REM */ 
		::String _url; /* REM */ 
		bool complete; /* REM */ 
		bool error; /* REM */ 
		bool responseHeadersLoaded; /* REM */ 
		Dynamic response; /* REM */ 
		::Hash responseHeaders; /* REM */ 
		int loaded; /* REM */ 
		int total; /* REM */ 
		int status; /* REM */ 
		static int PROGRESS_UPDATE_FREQUENCY; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeHttpBase */ 
