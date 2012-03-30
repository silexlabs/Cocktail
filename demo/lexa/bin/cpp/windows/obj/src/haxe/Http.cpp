#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_cpp_net_Host
#include <cpp/net/Host.h>
#endif
#ifndef INCLUDED_cpp_net_Socket
#include <cpp/net/Socket.h>
#endif
#ifndef INCLUDED_haxe_Http
#include <haxe/Http.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{

Void Http_obj::__construct(::String url)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",77)
	this->url = url;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",78)
	this->headers = ::Hash_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",79)
	this->params = ::Hash_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",83)
	this->cnxTimeout = (int)10;
}
;
	return null();
}

Http_obj::~Http_obj() { }

Dynamic Http_obj::__CreateEmpty() { return  new Http_obj; }
hx::ObjectPtr< Http_obj > Http_obj::__new(::String url)
{  hx::ObjectPtr< Http_obj > result = new Http_obj();
	result->__construct(url);
	return result;}

Dynamic Http_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Http_obj > result = new Http_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Http_obj::setHeader( ::String header,::String value){
{
		HX_SOURCE_PUSH("Http_obj::setHeader")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",90)
		this->headers->set(header,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setHeader,(void))

Void Http_obj::setParameter( ::String param,::String value){
{
		HX_SOURCE_PUSH("Http_obj::setParameter")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",94)
		this->params->set(param,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setParameter,(void))

Void Http_obj::setPostData( ::String data){
{
		HX_SOURCE_PUSH("Http_obj::setPostData")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",99)
		this->postData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,setPostData,(void))

Void Http_obj::request( bool post){
{
		HX_SOURCE_PUSH("Http_obj::request")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",105)
		::haxe::Http me = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",247)
		::haxe::Http me1 = hx::ObjectPtr<OBJ_>(this);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",248)
		::haxe::io::BytesOutput output = ::haxe::io::BytesOutput_obj::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",249)
		Dynamic old = Dynamic( Array_obj<Dynamic>::__new().Add(this->onError_dyn()));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",250)
		Array< bool > err = Array_obj< bool >::__new().Add(false);

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< bool >,err,Dynamic,old)
		Void run(::String e){
{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",252)
				err[(int)0] = true;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",253)
				old->__GetItem((int)0)(e).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",251)
		this->onError =  Dynamic(new _Function_1_1(err,old));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",255)
		this->customRequest(post,output,null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",256)
		if ((!(err->__get((int)0)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",260)
			me1->onData(output->getBytes()->toString());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,request,(void))

Void Http_obj::fileTransfert( ::String argname,::String filename,::haxe::io::Input file,int size){
{
		HX_SOURCE_PUSH("Http_obj::fileTransfert")
		struct _Function_1_1{
			inline static Dynamic Block( ::haxe::io::Input &file,int &size,::String &argname,::String &filename){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("param") , argname,false);
				__result->Add(HX_CSTRING("filename") , filename,false);
				__result->Add(HX_CSTRING("io") , file,false);
				__result->Add(HX_CSTRING("size") , size,false);
				return __result;
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",267)
		this->file = _Function_1_1::Block(file,size,argname,filename);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,fileTransfert,(void))

Void Http_obj::customRequest( bool post,::haxe::io::Output api,Dynamic sock,::String method){
{
		HX_SOURCE_PUSH("Http_obj::customRequest")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",272)
		::EReg url_regexp = ::EReg_obj::__new(HX_CSTRING("^(https?://)?([a-zA-Z\\.0-9-]+)(:[0-9]+)?(.*)$"),HX_CSTRING(""));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",273)
		if ((!(url_regexp->match(this->url)))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",274)
			this->onError(HX_CSTRING("Invalid URL"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",275)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",277)
		bool secure = (url_regexp->matched((int)1) == HX_CSTRING("https://"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",278)
		if (((sock == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",278)
			if ((secure)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",279)
				hx::Throw (HX_CSTRING("Https is only supported with -lib hxssl"));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",288)
				sock = ::cpp::net::Socket_obj::__new(null());
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",290)
		::String host = url_regexp->matched((int)2);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",291)
		::String portString = url_regexp->matched((int)3);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",292)
		::String request = url_regexp->matched((int)4);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",293)
		if (((request == HX_CSTRING("")))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",294)
			request = HX_CSTRING("/");
		}
		struct _Function_1_1{
			inline static int Block( bool &secure){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",295)
				return (  ((secure)) ? int((int)443) : int((int)80) );
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",295)
		Dynamic port = (  (((bool((portString == null())) || bool((portString == HX_CSTRING("")))))) ? Dynamic(_Function_1_1::Block(secure)) : Dynamic(::Std_obj::parseInt(portString.substr((int)1,(portString.length - (int)1)))) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",296)
		Dynamic data;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",298)
		bool multipart = (this->file != null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",299)
		::String boundary = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",300)
		::String uri = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",301)
		if ((multipart)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",302)
			post = true;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",303)
			boundary = (((::Std_obj::string(::Std_obj::random((int)1000)) + ::Std_obj::string(::Std_obj::random((int)1000))) + ::Std_obj::string(::Std_obj::random((int)1000))) + ::Std_obj::string(::Std_obj::random((int)1000)));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",304)
			while(((boundary.length < (int)38))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",305)
				boundary = (HX_CSTRING("-") + boundary);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",306)
			::StringBuf b = ::StringBuf_obj::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",307)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",308)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("--");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",309)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = boundary;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",310)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",311)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("Content-Disposition: form-data; name=\"");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",312)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = p;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",313)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\"");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",314)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",315)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",316)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = this->params->get(p);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",317)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
				}
;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",319)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("--");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",320)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = boundary;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",321)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",322)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("Content-Disposition: form-data; name=\"");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",323)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = this->file->__Field(HX_CSTRING("param"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",324)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\"; filename=\"");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",325)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = this->file->__Field(HX_CSTRING("filename"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",326)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\"");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",327)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",328)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = (((HX_CSTRING("Content-Type: ") + HX_CSTRING("application/octet-stream")) + HX_CSTRING("\r\n")) + HX_CSTRING("\r\n"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",329)
			uri = b->b->__Field(HX_CSTRING("join"))(HX_CSTRING(""));
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",330)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",332)
					if (((uri == null()))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",333)
						uri = HX_CSTRING("");
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",335)
						hx::AddEq(uri,HX_CSTRING("&"));
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",336)
					hx::AddEq(uri,((::StringTools_obj::urlEncode(p) + HX_CSTRING("=")) + ::StringTools_obj::urlEncode(this->params->get(p))));
				}
;
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",340)
		::StringBuf b = ::StringBuf_obj::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",341)
		if (((method != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",342)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = method;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",343)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(" ");
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",344)
			if ((post)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",345)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("POST ");
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",347)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("GET ");
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",349)
		if (((::haxe::Http_obj::PROXY != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",350)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("http://");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",351)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = host;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",352)
			if (((port != (int)80))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",353)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(":");
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",354)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = port;
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",357)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = request;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",359)
		if (((bool(!(post)) && bool((uri != null()))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",360)
			if (((request.indexOf(HX_CSTRING("?"),(int)0) >= (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",361)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("&");
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",363)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("?");
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",364)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = uri;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",366)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = ((HX_CSTRING(" HTTP/1.1\r\nHost: ") + host) + HX_CSTRING("\r\n"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",367)
		if (((bool((bool((this->postData == null())) && bool(post))) && bool((uri != null()))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",368)
			if (((bool(multipart) || bool((this->headers->get(HX_CSTRING("Content-Type")) == null()))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",369)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("Content-Type: ");
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",370)
				if ((multipart)){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",371)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("multipart/form-data");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",372)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("; boundary=");
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",373)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = boundary;
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",375)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("application/x-www-form-urlencoded");
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",376)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",378)
			if ((multipart)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",379)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = ((HX_CSTRING("Content-Length: ") + ((((uri.length + this->file->__Field(HX_CSTRING("size"))) + boundary.length) + (int)6))) + HX_CSTRING("\r\n"));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",381)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = ((HX_CSTRING("Content-Length: ") + uri.length) + HX_CSTRING("\r\n"));
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",383)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->headers->keys());  __it->hasNext(); ){
			::String h = __it->next();
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",384)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = h;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",385)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING(": ");
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",386)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = this->headers->get(h);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",387)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
			}
;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",389)
		if (((this->postData != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",390)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = this->postData;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",392)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = HX_CSTRING("\r\n");
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",393)
			if (((bool(post) && bool((uri != null()))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",394)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"))) = uri;
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",396)
		try{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",397)
			if (((::haxe::Http_obj::PROXY != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",398)
				sock->__Field(HX_CSTRING("connect"))(::cpp::net::Host_obj::__new(::haxe::Http_obj::PROXY->__Field(HX_CSTRING("host"))),::haxe::Http_obj::PROXY->__Field(HX_CSTRING("port")));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",400)
				sock->__Field(HX_CSTRING("connect"))(::cpp::net::Host_obj::__new(host),port);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",401)
			sock->__Field(HX_CSTRING("write"))(b->b->__Field(HX_CSTRING("join"))(HX_CSTRING("")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",402)
			if ((multipart)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",403)
				int bufsize = (int)4096;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",404)
				::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",405)
				while(((this->file->__Field(HX_CSTRING("size")) > (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",406)
					int size = (  (((this->file->__Field(HX_CSTRING("size")) > bufsize))) ? int(bufsize) : int(this->file->__Field(HX_CSTRING("size"))) );
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",407)
					int len = (int)0;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",408)
					try{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",408)
						len = this->file->__Field(HX_CSTRING("io"))->__Field(HX_CSTRING("readBytes"))(buf,(int)0,size);
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::haxe::io::Eof >() ){
							::haxe::io::Eof e = __e;{
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",410)
								break;
							}
						}
						else throw(__e);
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",411)
					sock->__Field(HX_CSTRING("output"))->__Field(HX_CSTRING("writeFullBytes"))(buf,(int)0,len);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",412)
					hx::SubEq(this->file->__FieldRef(HX_CSTRING("size")),len);
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",414)
				sock->__Field(HX_CSTRING("write"))(HX_CSTRING("\r\n"));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",415)
				sock->__Field(HX_CSTRING("write"))(HX_CSTRING("--"));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",416)
				sock->__Field(HX_CSTRING("write"))(boundary);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",417)
				sock->__Field(HX_CSTRING("write"))(HX_CSTRING("--"));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",419)
			this->readHttpResponse(api,sock);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",420)
			sock->__Field(HX_CSTRING("close"))();
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",422)
					try{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",422)
						sock->__Field(HX_CSTRING("close"))();
					}
					catch(Dynamic __e){
						{
							Dynamic e1 = __e;{
							}
						}
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",423)
					this->onError(::Std_obj::string(e));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,customRequest,(void))

Void Http_obj::readHttpResponse( ::haxe::io::Output api,Dynamic sock){
{
		HX_SOURCE_PUSH("Http_obj::readHttpResponse")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",429)
		::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",430)
		int k = (int)4;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",431)
		::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc((int)4);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",432)
		sock->__Field(HX_CSTRING("setTimeout"))(this->cnxTimeout);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",433)
		while((true)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",434)
			int p = sock->__Field(HX_CSTRING("input"))->__Field(HX_CSTRING("readBytes"))(s,(int)0,k);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",435)
			while(((p != k))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",436)
				hx::AddEq(p,sock->__Field(HX_CSTRING("input"))->__Field(HX_CSTRING("readBytes"))(s,p,(k - p)));
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
				if (((bool((k < (int)0)) || bool((k > s->length))))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
				Array< unsigned char > b1 = b->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
				Array< unsigned char > b2 = s->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
					int _g1 = (int)0;
					int _g = k;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",437)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",438)
			int _switch_1 = (k);
			if (  ( _switch_1==(int)1)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",440)
				int c = s->b->__get((int)0);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",441)
				if (((c == (int)10))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",442)
					break;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",443)
				if (((c == (int)13))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",444)
					k = (int)3;
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",446)
					k = (int)4;
				}
			}
			else if (  ( _switch_1==(int)2)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",448)
				int c = s->b->__get((int)1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",449)
				if (((c == (int)10))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",450)
					if (((s->b->__get((int)0) == (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",451)
						break;
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",452)
					k = (int)4;
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",453)
					if (((c == (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",454)
						k = (int)3;
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",456)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)3)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",458)
				int c = s->b->__get((int)2);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",459)
				if (((c == (int)10))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",459)
					if (((s->b->__get((int)1) != (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",461)
						k = (int)4;
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",462)
						if (((s->b->__get((int)0) != (int)10))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",463)
							k = (int)2;
						}
						else{
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",465)
							break;
						}
					}
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",466)
					if (((c == (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",466)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",468)
							k = (int)1;
						}
						else{
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",470)
							k = (int)3;
						}
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",472)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)4)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",474)
				int c = s->b->__get((int)3);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",475)
				if (((c == (int)10))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",475)
					if (((s->b->__get((int)2) != (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",477)
						continue;
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",478)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",479)
							k = (int)2;
						}
						else{
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",481)
							break;
						}
					}
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",482)
					if (((c == (int)13))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",482)
						if (((bool((s->b->__get((int)2) != (int)10)) || bool((s->b->__get((int)1) != (int)13))))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",484)
							k = (int)3;
						}
						else{
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",486)
							k = (int)1;
						}
					}
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",493)
		Array< ::String > headers = b->getBytes()->toString().split(HX_CSTRING("\r\n"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",495)
		::String response = headers->shift();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",496)
		Array< ::String > rp = response.split(HX_CSTRING(" "));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",497)
		Dynamic status = ::Std_obj::parseInt(rp->__get((int)1));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",498)
		if (((bool((status == (int)0)) || bool((status == null()))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",499)
			hx::Throw (HX_CSTRING("Response status error"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",502)
		headers->pop();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",503)
		headers->pop();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",504)
		this->responseHeaders = ::Hash_obj::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",505)
		Dynamic size = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",506)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",506)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",506)
			while(((_g < headers->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",506)
				::String hline = headers->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",506)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",507)
				Array< ::String > a = hline.split(HX_CSTRING(": "));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",508)
				::String hname = a->shift();
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",509)
				::String hval = (  (((a->length == (int)1))) ? ::String(a->__get((int)0)) : ::String(a->join(HX_CSTRING(": "))) );
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",510)
				this->responseHeaders->set(hname,hval);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",511)
				if (((hname.toLowerCase() == HX_CSTRING("content-length")))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",512)
					size = ::Std_obj::parseInt(hval);
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",515)
		this->onStatus(status);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",517)
		bool chunked = (this->responseHeaders->get(HX_CSTRING("Transfer-Encoding")) == HX_CSTRING("chunked"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",518)
		::EReg chunk_re = ::EReg_obj::__new(HX_CSTRING("^([0-9A-Fa-f]+)[ ]*\r\n"),HX_CSTRING("m"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",519)
		this->chunk_size = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",520)
		this->chunk_buf = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",522)
		int bufsize = (int)1024;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",523)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",524)
		if (((size == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",525)
			if ((!(this->noShutdown))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",526)
				sock->__Field(HX_CSTRING("shutdown"))(false,true);
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",527)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",527)
				while((true)){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",529)
					int len = sock->__Field(HX_CSTRING("input"))->__Field(HX_CSTRING("readBytes"))(buf,(int)0,bufsize);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",530)
					if ((chunked)){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",530)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",532)
							break;
						}
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",534)
						api->writeBytes(buf,(int)0,len);
					}
				}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					::haxe::io::Eof e = __e;{
					}
				}
				else throw(__e);
			}
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",539)
			api->prepare(size);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",540)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",540)
				while(((size > (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",542)
					int len = sock->__Field(HX_CSTRING("input"))->__Field(HX_CSTRING("readBytes"))(buf,(int)0,(  (((size > bufsize))) ? Dynamic(bufsize) : Dynamic(size) ));
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",543)
					if ((chunked)){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",543)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",545)
							break;
						}
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",547)
						api->writeBytes(buf,(int)0,len);
					}
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",548)
					hx::SubEq(size,len);
				}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					::haxe::io::Eof e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",550)
						hx::Throw (HX_CSTRING("Transfert aborted"));
					}
				}
				else throw(__e);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",554)
		if (((bool(chunked) && bool(((bool((this->chunk_size != null())) || bool((this->chunk_buf != null())))))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",555)
			hx::Throw (HX_CSTRING("Invalid chunk"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",556)
		if (((bool((status < (int)200)) || bool((status >= (int)400))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",557)
			hx::Throw ((HX_CSTRING("Http Error #") + status));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",558)
		api->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,readHttpResponse,(void))

bool Http_obj::readChunk( ::EReg chunk_re,::haxe::io::Output api,::haxe::io::Bytes buf,int len){
	HX_SOURCE_PUSH("Http_obj::readChunk")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",562)
	if (((this->chunk_size == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",563)
		if (((this->chunk_buf != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",564)
			::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
				::haxe::io::Bytes src = this->chunk_buf;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
				Array< unsigned char > b1 = b->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
				Array< unsigned char > b2 = src->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
					int _g1 = (int)0;
					int _g = src->length;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",565)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
			{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
				Array< unsigned char > b1 = b->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
				Array< unsigned char > b2 = buf->b;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
				{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
					int _g1 = (int)0;
					int _g = len;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
					while(((_g1 < _g))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
						int i = (_g1)++;
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",566)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",567)
			buf = b->getBytes();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",568)
			hx::AddEq(len,this->chunk_buf->length);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",569)
			this->chunk_buf = null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",574)
		if ((chunk_re->match(buf->toString()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",576)
			Dynamic p = chunk_re->matchedPos();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",577)
			if (((p->__Field(HX_CSTRING("len")) <= len))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",578)
				::String cstr = chunk_re->matched((int)1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",579)
				this->chunk_size = ::Std_obj::parseInt((HX_CSTRING("0x") + cstr));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",580)
				if (((cstr == HX_CSTRING("0")))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",581)
					this->chunk_size = null();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",582)
					this->chunk_buf = null();
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",583)
					return false;
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",585)
				hx::SubEq(len,p->__Field(HX_CSTRING("len")));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",586)
				return this->readChunk(chunk_re,api,buf->sub(p->__Field(HX_CSTRING("len")),len),len);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",590)
		if (((len > (int)10))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",591)
			this->onError(HX_CSTRING("Invalid chunk"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",592)
			return false;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",594)
		this->chunk_buf = buf->sub((int)0,len);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",595)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",597)
	if (((this->chunk_size > len))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",598)
		hx::SubEq(this->chunk_size,len);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",599)
		api->writeBytes(buf,(int)0,len);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",600)
		return true;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",602)
	int end = (this->chunk_size + (int)2);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",603)
	if (((len >= end))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",604)
		if (((this->chunk_size > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",605)
			api->writeBytes(buf,(int)0,this->chunk_size);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",606)
		hx::SubEq(len,end);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",607)
		this->chunk_size = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",608)
		if (((len == (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",609)
			return true;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",610)
		return this->readChunk(chunk_re,api,buf->sub(end,len),len);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",612)
	if (((this->chunk_size > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",613)
		api->writeBytes(buf,(int)0,this->chunk_size);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",614)
	hx::SubEq(this->chunk_size,len);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",615)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,readChunk,return )

HX_BEGIN_DEFAULT_FUNC(__default_onData,Http_obj)
Void run(::String data){
{
		HX_SOURCE_PUSH("Http_obj::onData")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onError,Http_obj)
Void run(::String msg){
{
		HX_SOURCE_PUSH("Http_obj::onError")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onStatus,Http_obj)
Void run(int status){
{
		HX_SOURCE_PUSH("Http_obj::onStatus")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Dynamic Http_obj::PROXY;

::String Http_obj::requestUrl( ::String url){
	HX_SOURCE_PUSH("Http_obj::requestUrl")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",631)
	::haxe::Http h = ::haxe::Http_obj::__new(url);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",635)
	Array< ::String > r = Array_obj< ::String >::__new().Add(null());

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,r)
	Void run(::String d){
{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",636)
			r[(int)0] = d;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",636)
	h->onData =  Dynamic(new _Function_1_1(r));

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::String e){
{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",639)
			hx::Throw (e);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",639)
	h->onError =  Dynamic(new _Function_1_2());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",642)
	h->request(false);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/haxe/Http.hx",643)
	return r->__get((int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Http_obj,requestUrl,return )


Http_obj::Http_obj()
{
	onData = new __default_onData(this);
	onError = new __default_onError(this);
	onStatus = new __default_onStatus(this);
}

void Http_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Http);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(noShutdown,"noShutdown");
	HX_MARK_MEMBER_NAME(cnxTimeout,"cnxTimeout");
	HX_MARK_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_MARK_MEMBER_NAME(postData,"postData");
	HX_MARK_MEMBER_NAME(chunk_size,"chunk_size");
	HX_MARK_MEMBER_NAME(chunk_buf,"chunk_buf");
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(headers,"headers");
	HX_MARK_MEMBER_NAME(params,"params");
	HX_MARK_MEMBER_NAME(onData,"onData");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(onStatus,"onStatus");
	HX_MARK_END_CLASS();
}

Dynamic Http_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return file; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PROXY") ) { return PROXY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { return params; }
		if (HX_FIELD_EQ(inName,"onData") ) { return onData; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"headers") ) { return headers; }
		if (HX_FIELD_EQ(inName,"request") ) { return request_dyn(); }
		if (HX_FIELD_EQ(inName,"onError") ) { return onError; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"postData") ) { return postData; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { return onStatus; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { return chunk_buf; }
		if (HX_FIELD_EQ(inName,"setHeader") ) { return setHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"readChunk") ) { return readChunk_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"requestUrl") ) { return requestUrl_dyn(); }
		if (HX_FIELD_EQ(inName,"noShutdown") ) { return noShutdown; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { return cnxTimeout; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { return chunk_size; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPostData") ) { return setPostData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setParameter") ) { return setParameter_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fileTransfert") ) { return fileTransfert_dyn(); }
		if (HX_FIELD_EQ(inName,"customRequest") ) { return customRequest_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { return responseHeaders; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"readHttpResponse") ) { return readHttpResponse_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Http_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PROXY") ) { PROXY=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { params=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onData") ) { onData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"headers") ) { headers=inValue.Cast< ::Hash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"postData") ) { postData=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { onStatus=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { chunk_buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"noShutdown") ) { noShutdown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { cnxTimeout=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { chunk_size=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { responseHeaders=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Http_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("noShutdown"));
	outFields->push(HX_CSTRING("cnxTimeout"));
	outFields->push(HX_CSTRING("responseHeaders"));
	outFields->push(HX_CSTRING("postData"));
	outFields->push(HX_CSTRING("chunk_size"));
	outFields->push(HX_CSTRING("chunk_buf"));
	outFields->push(HX_CSTRING("file"));
	outFields->push(HX_CSTRING("headers"));
	outFields->push(HX_CSTRING("params"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROXY"),
	HX_CSTRING("requestUrl"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("noShutdown"),
	HX_CSTRING("cnxTimeout"),
	HX_CSTRING("responseHeaders"),
	HX_CSTRING("postData"),
	HX_CSTRING("chunk_size"),
	HX_CSTRING("chunk_buf"),
	HX_CSTRING("file"),
	HX_CSTRING("headers"),
	HX_CSTRING("params"),
	HX_CSTRING("setHeader"),
	HX_CSTRING("setParameter"),
	HX_CSTRING("setPostData"),
	HX_CSTRING("request"),
	HX_CSTRING("fileTransfert"),
	HX_CSTRING("customRequest"),
	HX_CSTRING("readHttpResponse"),
	HX_CSTRING("readChunk"),
	HX_CSTRING("onData"),
	HX_CSTRING("onError"),
	HX_CSTRING("onStatus"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Http_obj::PROXY,"PROXY");
};

Class Http_obj::__mClass;

void Http_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Http"), hx::TCanCast< Http_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Http_obj::__boot()
{
	hx::Static(PROXY) = null();
}

} // end namespace haxe
