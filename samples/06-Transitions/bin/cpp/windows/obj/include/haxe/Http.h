#ifndef INCLUDED_haxe_Http
#define INCLUDED_haxe_Http

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS1(haxe,Http)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(haxe,io,Output)
namespace haxe{


class Http_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Http_obj OBJ_;
		Http_obj();
		Void __construct(::String url);

	public:
		static hx::ObjectPtr< Http_obj > __new(::String url);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Http_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Http"); }

		Dynamic onStatus;
		inline Dynamic &onStatus_dyn() {return onStatus; }

		Dynamic onError;
		inline Dynamic &onError_dyn() {return onError; }

		Dynamic onData;
		inline Dynamic &onData_dyn() {return onData; }

		virtual bool readChunk( ::EReg chunk_re,::haxe::io::Output api,::haxe::io::Bytes buf,int len);
		Dynamic readChunk_dyn();

		virtual Void readHttpResponse( ::haxe::io::Output api,Dynamic sock);
		Dynamic readHttpResponse_dyn();

		virtual Void customRequest( bool post,::haxe::io::Output api,Dynamic sock,::String method);
		Dynamic customRequest_dyn();

		virtual Void fileTransfert( ::String argname,::String filename,::haxe::io::Input file,int size);
		Dynamic fileTransfert_dyn();

		virtual Void request( bool post);
		Dynamic request_dyn();

		virtual Void setPostData( ::String data);
		Dynamic setPostData_dyn();

		virtual Void setParameter( ::String param,::String value);
		Dynamic setParameter_dyn();

		virtual Void setHeader( ::String header,::String value);
		Dynamic setHeader_dyn();

		::Hash params; /* REM */ 
		::Hash headers; /* REM */ 
		::String postData; /* REM */ 
		Dynamic file; /* REM */ 
		::haxe::io::Bytes chunk_buf; /* REM */ 
		Dynamic chunk_size; /* REM */ 
		::Hash responseHeaders; /* REM */ 
		Float cnxTimeout; /* REM */ 
		bool noShutdown; /* REM */ 
		::String url; /* REM */ 
		static Dynamic PROXY; /* REM */ 
		static ::String requestUrl( ::String url);
		static Dynamic requestUrl_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Http */ 
