#ifndef INCLUDED_native_net_URLRequest
#define INCLUDED_native_net_URLRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(native,net,URLRequest)
HX_DECLARE_CLASS2(native,net,URLRequestHeader)
HX_DECLARE_CLASS2(native,utils,ByteArray)
HX_DECLARE_CLASS2(native,utils,IDataInput)
HX_DECLARE_CLASS2(native,utils,IMemoryRange)
namespace native{
namespace net{


class URLRequest_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef URLRequest_obj OBJ_;
		URLRequest_obj();
		Void __construct(::String inURL);

	public:
		static hx::ObjectPtr< URLRequest_obj > __new(::String inURL);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~URLRequest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("URLRequest"); }

		virtual Void nmePrepare( );
		Dynamic nmePrepare_dyn();

		virtual Void digestAuth( ::String inUser,::String inPasswd);
		Dynamic digestAuth_dyn();

		virtual Void basicAuth( ::String inUser,::String inPasswd);
		Dynamic basicAuth_dyn();

		::native::utils::ByteArray nmeBytes; /* REM */ 
		::String credentials; /* REM */ 
		Dynamic data; /* REM */ 
		::String contentType; /* REM */ 
		::String method; /* REM */ 
		bool verbose; /* REM */ 
		::String cookieString; /* REM */ 
		int authType; /* REM */ 
		Array< ::native::net::URLRequestHeader > requestHeaders; /* REM */ 
		::String url; /* REM */ 
		static int AUTH_BASIC; /* REM */ 
		static int AUTH_DIGEST; /* REM */ 
		static int AUTH_GSSNEGOTIATE; /* REM */ 
		static int AUTH_NTLM; /* REM */ 
		static int AUTH_DIGEST_IE; /* REM */ 
		static int AUTH_DIGEST_ANY; /* REM */ 
};

} // end namespace native
} // end namespace net

#endif /* INCLUDED_native_net_URLRequest */ 
