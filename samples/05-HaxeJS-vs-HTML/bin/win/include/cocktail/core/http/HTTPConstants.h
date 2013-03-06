#ifndef INCLUDED_cocktail_core_http_HTTPConstants
#define INCLUDED_cocktail_core_http_HTTPConstants

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,http,HTTPConstants)
namespace cocktail{
namespace core{
namespace http{


class HTTPConstants_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HTTPConstants_obj OBJ_;
		HTTPConstants_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTTPConstants_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTTPConstants_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTTPConstants"); }

		static int UNSENT; /* REM */ 
		static int OPENED; /* REM */ 
		static int HEADERS_RECEIVED; /* REM */ 
		static int LOADING; /* REM */ 
		static int DONE; /* REM */ 
		static ::String CONNECT; /* REM */ 
		static ::String DELETE; /* REM */ 
		static ::String GET; /* REM */ 
		static ::String HEAD; /* REM */ 
		static ::String OPTIONS; /* REM */ 
		static ::String POST; /* REM */ 
		static ::String PUT; /* REM */ 
		static ::String TRACE; /* REM */ 
		static ::String TRACK; /* REM */ 
		static ::String TYPE_TEXT; /* REM */ 
		static ::String TYPE_ARRAY_BUFFER; /* REM */ 
		static ::String TYPE_BLOB; /* REM */ 
		static ::String TYPE_DOCUMENT; /* REM */ 
		static ::String TYPE_JSON; /* REM */ 
		static ::String ACCEPT_CHARSET; /* REM */ 
		static ::String ACCEPT_ENCODING; /* REM */ 
		static ::String ACCESS_CONTROL_REQUEST_HEADERS; /* REM */ 
		static ::String ACCESS_CONTROL_REQUEST_METHOD; /* REM */ 
		static ::String CONNECTION; /* REM */ 
		static ::String CONTENT_LENGTH; /* REM */ 
		static ::String COOKIE; /* REM */ 
		static ::String COOKIE_2; /* REM */ 
		static ::String CONTENT_TRANSFER_ENCODING; /* REM */ 
		static ::String DATE; /* REM */ 
		static ::String EXPECT; /* REM */ 
		static ::String HOST; /* REM */ 
		static ::String KEEP_ALIVE; /* REM */ 
		static ::String ORIGIN; /* REM */ 
		static ::String REFERER; /* REM */ 
		static ::String TE; /* REM */ 
		static ::String TRAILER; /* REM */ 
		static ::String TRANSFER_ENCODING; /* REM */ 
		static ::String UPGRADE; /* REM */ 
		static ::String USER_AGENT; /* REM */ 
		static ::String VIA; /* REM */ 
		static ::String PROXY; /* REM */ 
		static ::String SEC; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace http

#endif /* INCLUDED_cocktail_core_http_HTTPConstants */ 
