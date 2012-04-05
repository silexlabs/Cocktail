#ifndef INCLUDED_nme_net_URLRequest
#define INCLUDED_nme_net_URLRequest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,net,URLRequest)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
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
		::String __ToString() const { return HX_CSTRING("URLRequest"); }

		int authType; /* REM */ 
		::String cookieString; /* REM */ 
		::String url; /* REM */ 
		::String userPassword; /* REM */ 
		bool verbose; /* REM */ 
		::String method; /* REM */ 
		::String contentType; /* REM */ 
		Dynamic data; /* REM */ 
		::nme::utils::ByteArray nmeBytes; /* REM */ 
		virtual Void basicAuth( ::String inUser,::String inPasswd);
		Dynamic basicAuth_dyn();

		virtual Void digestAuth( ::String inUser,::String inPasswd);
		Dynamic digestAuth_dyn();

		virtual Void nmePrepare( );
		Dynamic nmePrepare_dyn();

		static int AUTH_BASIC; /* REM */ 
		static int AUTH_DIGEST; /* REM */ 
		static int AUTH_GSSNEGOTIATE; /* REM */ 
		static int AUTH_NTLM; /* REM */ 
		static int AUTH_DIGEST_IE; /* REM */ 
		static int AUTH_DIGEST_ANY; /* REM */ 
};

} // end namespace nme
} // end namespace net

#endif /* INCLUDED_nme_net_URLRequest */ 
