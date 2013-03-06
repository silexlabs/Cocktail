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
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
namespace haxe{

Void Http_obj::__construct(::String url)
{
HX_STACK_PUSH("Http::new","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",69);
{
	HX_STACK_LINE(70)
	this->url = url;
	HX_STACK_LINE(71)
	this->headers = ::Hash_obj::__new();
	HX_STACK_LINE(72)
	this->params = ::Hash_obj::__new();
	HX_STACK_LINE(76)
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

HX_BEGIN_DEFAULT_FUNC(__default_onStatus,Http_obj)
Void run(int status){
{
		HX_STACK_PUSH("Http::onStatus","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",629);
		HX_STACK_THIS(this);
		HX_STACK_ARG(status,"status");
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onError,Http_obj)
Void run(::String msg){
{
		HX_STACK_PUSH("Http::onError","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",626);
		HX_STACK_THIS(this);
		HX_STACK_ARG(msg,"msg");
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onData,Http_obj)
Void run(::String data){
{
		HX_STACK_PUSH("Http::onData","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",623);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

bool Http_obj::readChunk( ::EReg chunk_re,::haxe::io::Output api,::haxe::io::Bytes buf,int len){
	HX_STACK_PUSH("Http::readChunk","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",564);
	HX_STACK_THIS(this);
	HX_STACK_ARG(chunk_re,"chunk_re");
	HX_STACK_ARG(api,"api");
	HX_STACK_ARG(buf,"buf");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(565)
	if (((this->chunk_size == null()))){
		HX_STACK_LINE(566)
		if (((this->chunk_buf != null()))){
			HX_STACK_LINE(567)
			::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(568)
			{
				HX_STACK_LINE(568)
				::haxe::io::Bytes src = this->chunk_buf;		HX_STACK_VAR(src,"src");
				HX_STACK_LINE(568)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(568)
				Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(568)
				{
					HX_STACK_LINE(568)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = src->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(568)
					while(((_g1 < _g))){
						HX_STACK_LINE(568)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(568)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(569)
			{
				HX_STACK_LINE(569)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_STACK_LINE(569)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_STACK_LINE(569)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(569)
				Array< unsigned char > b2 = buf->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(569)
				{
					HX_STACK_LINE(569)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = len;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(569)
					while(((_g1 < _g))){
						HX_STACK_LINE(569)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(569)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(570)
			buf = b->getBytes();
			HX_STACK_LINE(571)
			hx::AddEq(len,this->chunk_buf->length);
			HX_STACK_LINE(572)
			this->chunk_buf = null();
		}
		HX_STACK_LINE(577)
		if ((chunk_re->match(buf->toString()))){
			HX_STACK_LINE(579)
			Dynamic p = chunk_re->matchedPos();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(580)
			if (((p->__Field(HX_CSTRING("len"),true) <= len))){
				HX_STACK_LINE(581)
				::String cstr = chunk_re->matched((int)1);		HX_STACK_VAR(cstr,"cstr");
				HX_STACK_LINE(582)
				this->chunk_size = ::Std_obj::parseInt((HX_CSTRING("0x") + cstr));
				HX_STACK_LINE(583)
				if (((cstr == HX_CSTRING("0")))){
					HX_STACK_LINE(584)
					this->chunk_size = null();
					HX_STACK_LINE(585)
					this->chunk_buf = null();
					HX_STACK_LINE(586)
					return false;
				}
				HX_STACK_LINE(588)
				hx::SubEq(len,p->__Field(HX_CSTRING("len"),true));
				HX_STACK_LINE(589)
				return this->readChunk(chunk_re,api,buf->sub(p->__Field(HX_CSTRING("len"),true),len),len);
			}
		}
		HX_STACK_LINE(593)
		if (((len > (int)10))){
			HX_STACK_LINE(594)
			this->onError(HX_CSTRING("Invalid chunk"));
			HX_STACK_LINE(595)
			return false;
		}
		HX_STACK_LINE(597)
		this->chunk_buf = buf->sub((int)0,len);
		HX_STACK_LINE(598)
		return true;
	}
	HX_STACK_LINE(600)
	if (((this->chunk_size > len))){
		HX_STACK_LINE(601)
		hx::SubEq(this->chunk_size,len);
		HX_STACK_LINE(602)
		api->writeBytes(buf,(int)0,len);
		HX_STACK_LINE(603)
		return true;
	}
	HX_STACK_LINE(605)
	int end = (this->chunk_size + (int)2);		HX_STACK_VAR(end,"end");
	HX_STACK_LINE(606)
	if (((len >= end))){
		HX_STACK_LINE(607)
		if (((this->chunk_size > (int)0))){
			HX_STACK_LINE(608)
			api->writeBytes(buf,(int)0,this->chunk_size);
		}
		HX_STACK_LINE(609)
		hx::SubEq(len,end);
		HX_STACK_LINE(610)
		this->chunk_size = null();
		HX_STACK_LINE(611)
		if (((len == (int)0))){
			HX_STACK_LINE(612)
			return true;
		}
		HX_STACK_LINE(613)
		return this->readChunk(chunk_re,api,buf->sub(end,len),len);
	}
	HX_STACK_LINE(615)
	if (((this->chunk_size > (int)0))){
		HX_STACK_LINE(616)
		api->writeBytes(buf,(int)0,this->chunk_size);
	}
	HX_STACK_LINE(617)
	hx::SubEq(this->chunk_size,len);
	HX_STACK_LINE(618)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,readChunk,return )

Void Http_obj::readHttpResponse( ::haxe::io::Output api,Dynamic sock){
{
		HX_STACK_PUSH("Http::readHttpResponse","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",425);
		HX_STACK_THIS(this);
		HX_STACK_ARG(api,"api");
		HX_STACK_ARG(sock,"sock");
		HX_STACK_LINE(427)
		::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(428)
		int k = (int)4;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(429)
		::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc((int)4);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(430)
		sock->__Field(HX_CSTRING("setTimeout"),true)(this->cnxTimeout);
		HX_STACK_LINE(431)
		while((true)){
			HX_STACK_LINE(432)
			int p = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,(int)0,k);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(433)
			while(((p != k))){
				HX_STACK_LINE(434)
				hx::AddEq(p,sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,p,(k - p)));
			}
			HX_STACK_LINE(435)
			{
				HX_STACK_LINE(435)
				if (((bool((k < (int)0)) || bool((k > s->length))))){
					HX_STACK_LINE(435)
					hx::Throw (::haxe::io::Error_obj::OutsideBounds_dyn());
				}
				HX_STACK_LINE(435)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(435)
				Array< unsigned char > b2 = s->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(435)
				{
					HX_STACK_LINE(435)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					int _g = k;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(435)
					while(((_g1 < _g))){
						HX_STACK_LINE(435)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(435)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(436)
			int _switch_1 = (k);
			if (  ( _switch_1==(int)1)){
				HX_STACK_LINE(438)
				int c = s->b->__get((int)0);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(439)
				if (((c == (int)10))){
					HX_STACK_LINE(440)
					break;
				}
				HX_STACK_LINE(441)
				if (((c == (int)13))){
					HX_STACK_LINE(442)
					k = (int)3;
				}
				else{
					HX_STACK_LINE(444)
					k = (int)4;
				}
			}
			else if (  ( _switch_1==(int)2)){
				HX_STACK_LINE(446)
				int c = s->b->__get((int)1);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(447)
				if (((c == (int)10))){
					HX_STACK_LINE(448)
					if (((s->b->__get((int)0) == (int)13))){
						HX_STACK_LINE(449)
						break;
					}
					HX_STACK_LINE(450)
					k = (int)4;
				}
				else{
					HX_STACK_LINE(451)
					if (((c == (int)13))){
						HX_STACK_LINE(452)
						k = (int)3;
					}
					else{
						HX_STACK_LINE(454)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)3)){
				HX_STACK_LINE(456)
				int c = s->b->__get((int)2);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(457)
				if (((c == (int)10))){
					HX_STACK_LINE(457)
					if (((s->b->__get((int)1) != (int)13))){
						HX_STACK_LINE(459)
						k = (int)4;
					}
					else{
						HX_STACK_LINE(460)
						if (((s->b->__get((int)0) != (int)10))){
							HX_STACK_LINE(461)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(463)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(464)
					if (((c == (int)13))){
						HX_STACK_LINE(464)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(466)
							k = (int)1;
						}
						else{
							HX_STACK_LINE(468)
							k = (int)3;
						}
					}
					else{
						HX_STACK_LINE(470)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)4)){
				HX_STACK_LINE(472)
				int c = s->b->__get((int)3);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(473)
				if (((c == (int)10))){
					HX_STACK_LINE(473)
					if (((s->b->__get((int)2) != (int)13))){
						HX_STACK_LINE(475)
						continue;
					}
					else{
						HX_STACK_LINE(476)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(477)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(479)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(480)
					if (((c == (int)13))){
						HX_STACK_LINE(480)
						if (((bool((s->b->__get((int)2) != (int)10)) || bool((s->b->__get((int)1) != (int)13))))){
							HX_STACK_LINE(482)
							k = (int)3;
						}
						else{
							HX_STACK_LINE(484)
							k = (int)1;
						}
					}
				}
			}
		}
		HX_STACK_LINE(491)
		Array< ::String > headers = b->getBytes()->toString().split(HX_CSTRING("\r\n"));		HX_STACK_VAR(headers,"headers");
		HX_STACK_LINE(493)
		::String response = headers->shift();		HX_STACK_VAR(response,"response");
		HX_STACK_LINE(494)
		Array< ::String > rp = response.split(HX_CSTRING(" "));		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(495)
		Dynamic status = ::Std_obj::parseInt(rp->__get((int)1));		HX_STACK_VAR(status,"status");
		HX_STACK_LINE(496)
		if (((bool((status == (int)0)) || bool((status == null()))))){
			HX_STACK_LINE(497)
			hx::Throw (HX_CSTRING("Response status error"));
		}
		HX_STACK_LINE(500)
		headers->pop();
		HX_STACK_LINE(501)
		headers->pop();
		HX_STACK_LINE(502)
		this->responseHeaders = ::Hash_obj::__new();
		HX_STACK_LINE(503)
		Dynamic size = null();		HX_STACK_VAR(size,"size");
		HX_STACK_LINE(504)
		bool chunked = false;		HX_STACK_VAR(chunked,"chunked");
		HX_STACK_LINE(505)
		{
			HX_STACK_LINE(505)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(505)
			while(((_g < headers->length))){
				HX_STACK_LINE(505)
				::String hline = headers->__get(_g);		HX_STACK_VAR(hline,"hline");
				HX_STACK_LINE(505)
				++(_g);
				HX_STACK_LINE(506)
				Array< ::String > a = hline.split(HX_CSTRING(": "));		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(507)
				::String hname = a->shift();		HX_STACK_VAR(hname,"hname");
				HX_STACK_LINE(508)
				::String hval = (  (((a->length == (int)1))) ? ::String(a->__get((int)0)) : ::String(a->join(HX_CSTRING(": "))) );		HX_STACK_VAR(hval,"hval");
				HX_STACK_LINE(509)
				this->responseHeaders->set(hname,hval);
				HX_STACK_LINE(510)
				::String _switch_2 = (hname.toLowerCase());
				if (  ( _switch_2==HX_CSTRING("content-length"))){
					HX_STACK_LINE(512)
					size = ::Std_obj::parseInt(hval);
				}
				else if (  ( _switch_2==HX_CSTRING("transfer-encoding"))){
					HX_STACK_LINE(514)
					chunked = (hval.toLowerCase() == HX_CSTRING("chunked"));
				}
			}
		}
		HX_STACK_LINE(519)
		this->onStatus(status);
		HX_STACK_LINE(521)
		::EReg chunk_re = ::EReg_obj::__new(HX_CSTRING("^([0-9A-Fa-f]+)[ ]*\r\n"),HX_CSTRING("m"));		HX_STACK_VAR(chunk_re,"chunk_re");
		HX_STACK_LINE(522)
		this->chunk_size = null();
		HX_STACK_LINE(523)
		this->chunk_buf = null();
		HX_STACK_LINE(525)
		int bufsize = (int)1024;		HX_STACK_VAR(bufsize,"bufsize");
		HX_STACK_LINE(526)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
		HX_STACK_LINE(527)
		if (((size == null()))){
			HX_STACK_LINE(528)
			if ((!(this->noShutdown))){
				HX_STACK_LINE(529)
				sock->__Field(HX_CSTRING("shutdown"),true)(false,true);
			}
			HX_STACK_LINE(530)
			try{
				HX_STACK_LINE(530)
				while((true)){
					HX_STACK_LINE(532)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,bufsize);		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(533)
					if ((chunked)){
						HX_STACK_LINE(533)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(535)
							break;
						}
					}
					else{
						HX_STACK_LINE(537)
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
			HX_STACK_LINE(542)
			api->prepare(size);
			HX_STACK_LINE(543)
			try{
				HX_STACK_LINE(543)
				while(((size > (int)0))){
					HX_STACK_LINE(545)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,(  (((size > bufsize))) ? Dynamic(bufsize) : Dynamic(size) ));		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(546)
					if ((chunked)){
						HX_STACK_LINE(546)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(548)
							break;
						}
					}
					else{
						HX_STACK_LINE(550)
						api->writeBytes(buf,(int)0,len);
					}
					HX_STACK_LINE(551)
					hx::SubEq(size,len);
				}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					::haxe::io::Eof e = __e;{
						HX_STACK_LINE(553)
						hx::Throw (HX_CSTRING("Transfert aborted"));
					}
				}
				else throw(__e);
			}
		}
		HX_STACK_LINE(557)
		if (((bool(chunked) && bool(((bool((this->chunk_size != null())) || bool((this->chunk_buf != null())))))))){
			HX_STACK_LINE(558)
			hx::Throw (HX_CSTRING("Invalid chunk"));
		}
		HX_STACK_LINE(559)
		if (((bool((status < (int)200)) || bool((status >= (int)400))))){
			HX_STACK_LINE(560)
			hx::Throw ((HX_CSTRING("Http Error #") + status));
		}
		HX_STACK_LINE(561)
		api->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,readHttpResponse,(void))

Void Http_obj::customRequest( bool post,::haxe::io::Output api,Dynamic sock,::String method){
{
		HX_STACK_PUSH("Http::customRequest","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",269);
		HX_STACK_THIS(this);
		HX_STACK_ARG(post,"post");
		HX_STACK_ARG(api,"api");
		HX_STACK_ARG(sock,"sock");
		HX_STACK_ARG(method,"method");
		HX_STACK_LINE(270)
		::EReg url_regexp = ::EReg_obj::__new(HX_CSTRING("^(https?://)?([a-zA-Z\\.0-9-]+)(:[0-9]+)?(.*)$"),HX_CSTRING(""));		HX_STACK_VAR(url_regexp,"url_regexp");
		HX_STACK_LINE(271)
		if ((!(url_regexp->match(this->url)))){
			HX_STACK_LINE(272)
			this->onError(HX_CSTRING("Invalid URL"));
			HX_STACK_LINE(273)
			return null();
		}
		HX_STACK_LINE(275)
		bool secure = (url_regexp->matched((int)1) == HX_CSTRING("https://"));		HX_STACK_VAR(secure,"secure");
		HX_STACK_LINE(276)
		if (((sock == null()))){
			HX_STACK_LINE(276)
			if ((secure)){
				HX_STACK_LINE(277)
				hx::Throw (HX_CSTRING("Https is only supported with -lib hxssl"));
			}
			else{
				HX_STACK_LINE(286)
				sock = ::sys::net::Socket_obj::__new();
			}
		}
		HX_STACK_LINE(288)
		::String host = url_regexp->matched((int)2);		HX_STACK_VAR(host,"host");
		HX_STACK_LINE(289)
		::String portString = url_regexp->matched((int)3);		HX_STACK_VAR(portString,"portString");
		HX_STACK_LINE(290)
		::String request = url_regexp->matched((int)4);		HX_STACK_VAR(request,"request");
		HX_STACK_LINE(291)
		if (((request == HX_CSTRING("")))){
			HX_STACK_LINE(292)
			request = HX_CSTRING("/");
		}
		struct _Function_1_1{
			inline static int Block( bool &secure){
				HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",293);
				{
					HX_STACK_LINE(293)
					return (  ((secure)) ? int((int)443) : int((int)80) );
				}
				return null();
			}
		};
		HX_STACK_LINE(293)
		Dynamic port = (  (((bool((portString == null())) || bool((portString == HX_CSTRING("")))))) ? Dynamic(_Function_1_1::Block(secure)) : Dynamic(::Std_obj::parseInt(portString.substr((int)1,(portString.length - (int)1)))) );		HX_STACK_VAR(port,"port");
		HX_STACK_LINE(294)
		Dynamic data;		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(296)
		bool multipart = (this->file != null());		HX_STACK_VAR(multipart,"multipart");
		HX_STACK_LINE(297)
		::String boundary = null();		HX_STACK_VAR(boundary,"boundary");
		HX_STACK_LINE(298)
		::String uri = null();		HX_STACK_VAR(uri,"uri");
		HX_STACK_LINE(299)
		if ((multipart)){
			HX_STACK_LINE(300)
			post = true;
			HX_STACK_LINE(301)
			boundary = (((::Std_obj::string(::Std_obj::random((int)1000)) + ::Std_obj::string(::Std_obj::random((int)1000))) + ::Std_obj::string(::Std_obj::random((int)1000))) + ::Std_obj::string(::Std_obj::random((int)1000)));
			HX_STACK_LINE(302)
			while(((boundary.length < (int)38))){
				HX_STACK_LINE(303)
				boundary = (HX_CSTRING("-") + boundary);
			}
			HX_STACK_LINE(304)
			::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(305)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_STACK_LINE(306)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("--");
					HX_STACK_LINE(307)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = boundary;
					HX_STACK_LINE(308)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
					HX_STACK_LINE(309)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("Content-Disposition: form-data; name=\"");
					HX_STACK_LINE(310)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = p;
					HX_STACK_LINE(311)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\"");
					HX_STACK_LINE(312)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
					HX_STACK_LINE(313)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
					HX_STACK_LINE(314)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = this->params->get(p);
					HX_STACK_LINE(315)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
				}
;
			}
			HX_STACK_LINE(317)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("--");
			HX_STACK_LINE(318)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = boundary;
			HX_STACK_LINE(319)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
			HX_STACK_LINE(320)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("Content-Disposition: form-data; name=\"");
			HX_STACK_LINE(321)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = this->file->__Field(HX_CSTRING("param"),true);
			HX_STACK_LINE(322)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\"; filename=\"");
			HX_STACK_LINE(323)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = this->file->__Field(HX_CSTRING("filename"),true);
			HX_STACK_LINE(324)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\"");
			HX_STACK_LINE(325)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
			HX_STACK_LINE(326)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = (((HX_CSTRING("Content-Type: ") + HX_CSTRING("application/octet-stream")) + HX_CSTRING("\r\n")) + HX_CSTRING("\r\n"));
			HX_STACK_LINE(327)
			uri = b->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING(""));
		}
		else{
			HX_STACK_LINE(328)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_STACK_LINE(330)
					if (((uri == null()))){
						HX_STACK_LINE(331)
						uri = HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(333)
						hx::AddEq(uri,HX_CSTRING("&"));
					}
					HX_STACK_LINE(334)
					hx::AddEq(uri,((::StringTools_obj::urlEncode(p) + HX_CSTRING("=")) + ::StringTools_obj::urlEncode(this->params->get(p))));
				}
;
			}
		}
		HX_STACK_LINE(338)
		::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(339)
		if (((method != null()))){
			HX_STACK_LINE(340)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = method;
			HX_STACK_LINE(341)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(" ");
		}
		else{
			HX_STACK_LINE(342)
			if ((post)){
				HX_STACK_LINE(343)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("POST ");
			}
			else{
				HX_STACK_LINE(345)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("GET ");
			}
		}
		HX_STACK_LINE(347)
		if (((::haxe::Http_obj::PROXY != null()))){
			HX_STACK_LINE(348)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("http://");
			HX_STACK_LINE(349)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = host;
			HX_STACK_LINE(350)
			if (((port != (int)80))){
				HX_STACK_LINE(351)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(":");
				HX_STACK_LINE(352)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = port;
			}
		}
		HX_STACK_LINE(355)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = request;
		HX_STACK_LINE(357)
		if (((bool(!(post)) && bool((uri != null()))))){
			HX_STACK_LINE(358)
			if (((request.indexOf(HX_CSTRING("?"),(int)0) >= (int)0))){
				HX_STACK_LINE(359)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("&");
			}
			else{
				HX_STACK_LINE(361)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("?");
			}
			HX_STACK_LINE(362)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = uri;
		}
		HX_STACK_LINE(364)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = ((HX_CSTRING(" HTTP/1.1\r\nHost: ") + host) + HX_CSTRING("\r\n"));
		HX_STACK_LINE(365)
		if (((this->postData != null()))){
			HX_STACK_LINE(366)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = ((HX_CSTRING("Content-Length: ") + this->postData.length) + HX_CSTRING("\r\n"));
		}
		else{
			HX_STACK_LINE(367)
			if (((bool(post) && bool((uri != null()))))){
				HX_STACK_LINE(368)
				if (((bool(multipart) || bool((this->headers->get(HX_CSTRING("Content-Type")) == null()))))){
					HX_STACK_LINE(369)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("Content-Type: ");
					HX_STACK_LINE(370)
					if ((multipart)){
						HX_STACK_LINE(371)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("multipart/form-data");
						HX_STACK_LINE(372)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("; boundary=");
						HX_STACK_LINE(373)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = boundary;
					}
					else{
						HX_STACK_LINE(375)
						hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("application/x-www-form-urlencoded");
					}
					HX_STACK_LINE(376)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
				}
				HX_STACK_LINE(378)
				if ((multipart)){
					HX_STACK_LINE(379)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = ((HX_CSTRING("Content-Length: ") + ((((uri.length + this->file->__Field(HX_CSTRING("size"),true)) + boundary.length) + (int)6))) + HX_CSTRING("\r\n"));
				}
				else{
					HX_STACK_LINE(381)
					hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = ((HX_CSTRING("Content-Length: ") + uri.length) + HX_CSTRING("\r\n"));
				}
			}
		}
		HX_STACK_LINE(383)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->headers->keys());  __it->hasNext(); ){
			::String h = __it->next();
			{
				HX_STACK_LINE(384)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = h;
				HX_STACK_LINE(385)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING(": ");
				HX_STACK_LINE(386)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = this->headers->get(h);
				HX_STACK_LINE(387)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
			}
;
		}
		HX_STACK_LINE(389)
		hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = HX_CSTRING("\r\n");
		HX_STACK_LINE(390)
		if (((this->postData != null()))){
			HX_STACK_LINE(391)
			hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = this->postData;
		}
		else{
			HX_STACK_LINE(392)
			if (((bool(post) && bool((uri != null()))))){
				HX_STACK_LINE(393)
				hx::IndexRef((b->b).mPtr,b->b->__Field(HX_CSTRING("length"),true)) = uri;
			}
		}
		HX_STACK_LINE(394)
		try{
			HX_STACK_LINE(395)
			if (((::haxe::Http_obj::PROXY != null()))){
				HX_STACK_LINE(396)
				sock->__Field(HX_CSTRING("connect"),true)(::sys::net::Host_obj::__new(::haxe::Http_obj::PROXY->__Field(HX_CSTRING("host"),true)),::haxe::Http_obj::PROXY->__Field(HX_CSTRING("port"),true));
			}
			else{
				HX_STACK_LINE(398)
				sock->__Field(HX_CSTRING("connect"),true)(::sys::net::Host_obj::__new(host),port);
			}
			HX_STACK_LINE(399)
			sock->__Field(HX_CSTRING("write"),true)(b->b->__Field(HX_CSTRING("join"),true)(HX_CSTRING("")));
			HX_STACK_LINE(400)
			if ((multipart)){
				HX_STACK_LINE(401)
				int bufsize = (int)4096;		HX_STACK_VAR(bufsize,"bufsize");
				HX_STACK_LINE(402)
				::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
				HX_STACK_LINE(403)
				while(((this->file->__Field(HX_CSTRING("size"),true) > (int)0))){
					HX_STACK_LINE(404)
					int size = (  (((this->file->__Field(HX_CSTRING("size"),true) > bufsize))) ? int(bufsize) : int(this->file->__Field(HX_CSTRING("size"),true)) );		HX_STACK_VAR(size,"size");
					HX_STACK_LINE(405)
					int len = (int)0;		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(406)
					try{
						HX_STACK_LINE(406)
						len = this->file->__Field(HX_CSTRING("io"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,size);
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::haxe::io::Eof >() ){
							::haxe::io::Eof e = __e;{
								HX_STACK_LINE(408)
								break;
							}
						}
						else throw(__e);
					}
					HX_STACK_LINE(409)
					sock->__Field(HX_CSTRING("output"),true)->__Field(HX_CSTRING("writeFullBytes"),true)(buf,(int)0,len);
					HX_STACK_LINE(410)
					hx::SubEq(this->file->__FieldRef(HX_CSTRING("size")),len);
				}
				HX_STACK_LINE(412)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("\r\n"));
				HX_STACK_LINE(413)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
				HX_STACK_LINE(414)
				sock->__Field(HX_CSTRING("write"),true)(boundary);
				HX_STACK_LINE(415)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
			}
			HX_STACK_LINE(417)
			this->readHttpResponse(api,sock);
			HX_STACK_LINE(418)
			sock->__Field(HX_CSTRING("close"),true)();
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_STACK_LINE(420)
					try{
						HX_STACK_LINE(420)
						sock->__Field(HX_CSTRING("close"),true)();
					}
					catch(Dynamic __e){
						{
							Dynamic e1 = __e;{
							}
						}
					}
					HX_STACK_LINE(421)
					this->onError(::Std_obj::string(e));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,customRequest,(void))

Void Http_obj::fileTransfert( ::String argname,::String filename,::haxe::io::Input file,int size){
{
		HX_STACK_PUSH("Http::fileTransfert","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",265);
		HX_STACK_THIS(this);
		HX_STACK_ARG(argname,"argname");
		HX_STACK_ARG(filename,"filename");
		HX_STACK_ARG(file,"file");
		HX_STACK_ARG(size,"size");
		struct _Function_1_1{
			inline static Dynamic Block( ::haxe::io::Input &file,int &size,::String &argname,::String &filename){
				HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",266);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("param") , argname,false);
					__result->Add(HX_CSTRING("filename") , filename,false);
					__result->Add(HX_CSTRING("io") , file,false);
					__result->Add(HX_CSTRING("size") , size,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(265)
		this->file = _Function_1_1::Block(file,size,argname,filename);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,fileTransfert,(void))

Void Http_obj::request( bool post){
{
		HX_STACK_PUSH("Http::request","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(post,"post");
		HX_STACK_LINE(99)
		::haxe::Http me = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(me,"me");
		HX_STACK_LINE(245)
		::haxe::Http me1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(me1,"me1");
		HX_STACK_LINE(246)
		::haxe::io::BytesOutput output = ::haxe::io::BytesOutput_obj::__new();		HX_STACK_VAR(output,"output");
		HX_STACK_LINE(247)
		Dynamic old = Dynamic( Array_obj<Dynamic>::__new().Add(this->onError_dyn()));		HX_STACK_VAR(old,"old");
		HX_STACK_LINE(248)
		Array< bool > err = Array_obj< bool >::__new().Add(false);		HX_STACK_VAR(err,"err");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< bool >,err,Dynamic,old)
		Void run(::String e){
			HX_STACK_PUSH("*::_Function_1_1","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",249);
			HX_STACK_ARG(e,"e");
			{
				HX_STACK_LINE(250)
				err[(int)0] = true;
				HX_STACK_LINE(251)
				old->__GetItem((int)0)(e).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(249)
		this->onError =  Dynamic(new _Function_1_1(err,old));
		HX_STACK_LINE(253)
		this->customRequest(post,output,null(),null());
		HX_STACK_LINE(254)
		if ((!(err->__get((int)0)))){
			HX_STACK_LINE(258)
			me1->onData(output->getBytes()->toString());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,request,(void))

Void Http_obj::setPostData( ::String data){
{
		HX_STACK_PUSH("Http::setPostData","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",91);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_LINE(91)
		this->postData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,setPostData,(void))

Void Http_obj::setParameter( ::String param,::String value){
{
		HX_STACK_PUSH("Http::setParameter","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(param,"param");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(87)
		this->params->set(param,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setParameter,(void))

Void Http_obj::setHeader( ::String header,::String value){
{
		HX_STACK_PUSH("Http::setHeader","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_ARG(header,"header");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(83)
		this->headers->set(header,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setHeader,(void))

Dynamic Http_obj::PROXY;

::String Http_obj::requestUrl( ::String url){
	HX_STACK_PUSH("Http::requestUrl","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",633);
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(634)
	::haxe::Http h = ::haxe::Http_obj::__new(url);		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(638)
	Array< ::String > r = Array_obj< ::String >::__new().Add(null());		HX_STACK_VAR(r,"r");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,r)
	Void run(::String d){
		HX_STACK_PUSH("*::_Function_1_1","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",639);
		HX_STACK_ARG(d,"d");
		{
			HX_STACK_LINE(639)
			r[(int)0] = d;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(639)
	h->onData =  Dynamic(new _Function_1_1(r));

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::String e){
		HX_STACK_PUSH("*::_Function_1_2","C:\\Motion-Twin\\Haxe/std/haxe/Http.hx",642);
		HX_STACK_ARG(e,"e");
		{
			HX_STACK_LINE(642)
			hx::Throw (e);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(642)
	h->onError =  Dynamic(new _Function_1_2());
	HX_STACK_LINE(645)
	h->request(false);
	HX_STACK_LINE(646)
	return r->__get((int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Http_obj,requestUrl,return )


Http_obj::Http_obj()
{
	onStatus = new __default_onStatus(this);
	onError = new __default_onError(this);
	onData = new __default_onData(this);
}

void Http_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Http);
	HX_MARK_MEMBER_NAME(onStatus,"onStatus");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(onData,"onData");
	HX_MARK_MEMBER_NAME(params,"params");
	HX_MARK_MEMBER_NAME(headers,"headers");
	HX_MARK_MEMBER_NAME(postData,"postData");
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(chunk_buf,"chunk_buf");
	HX_MARK_MEMBER_NAME(chunk_size,"chunk_size");
	HX_MARK_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_MARK_MEMBER_NAME(cnxTimeout,"cnxTimeout");
	HX_MARK_MEMBER_NAME(noShutdown,"noShutdown");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_END_CLASS();
}

void Http_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onStatus,"onStatus");
	HX_VISIT_MEMBER_NAME(onError,"onError");
	HX_VISIT_MEMBER_NAME(onData,"onData");
	HX_VISIT_MEMBER_NAME(params,"params");
	HX_VISIT_MEMBER_NAME(headers,"headers");
	HX_VISIT_MEMBER_NAME(postData,"postData");
	HX_VISIT_MEMBER_NAME(file,"file");
	HX_VISIT_MEMBER_NAME(chunk_buf,"chunk_buf");
	HX_VISIT_MEMBER_NAME(chunk_size,"chunk_size");
	HX_VISIT_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_VISIT_MEMBER_NAME(cnxTimeout,"cnxTimeout");
	HX_VISIT_MEMBER_NAME(noShutdown,"noShutdown");
	HX_VISIT_MEMBER_NAME(url,"url");
}

Dynamic Http_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"onData") ) { return onData; }
		if (HX_FIELD_EQ(inName,"params") ) { return params; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { return onError; }
		if (HX_FIELD_EQ(inName,"request") ) { return request_dyn(); }
		if (HX_FIELD_EQ(inName,"headers") ) { return headers; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onStatus") ) { return onStatus; }
		if (HX_FIELD_EQ(inName,"postData") ) { return postData; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readChunk") ) { return readChunk_dyn(); }
		if (HX_FIELD_EQ(inName,"setHeader") ) { return setHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { return chunk_buf; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"requestUrl") ) { return requestUrl_dyn(); }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { return chunk_size; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { return cnxTimeout; }
		if (HX_FIELD_EQ(inName,"noShutdown") ) { return noShutdown; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPostData") ) { return setPostData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setParameter") ) { return setParameter_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"customRequest") ) { return customRequest_dyn(); }
		if (HX_FIELD_EQ(inName,"fileTransfert") ) { return fileTransfert_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { return responseHeaders; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"readHttpResponse") ) { return readHttpResponse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Http_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"onData") ) { onData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"params") ) { params=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"headers") ) { headers=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onStatus") ) { onStatus=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"postData") ) { postData=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { chunk_buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"chunk_size") ) { chunk_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { cnxTimeout=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"noShutdown") ) { noShutdown=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { responseHeaders=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Http_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("params"));
	outFields->push(HX_CSTRING("headers"));
	outFields->push(HX_CSTRING("postData"));
	outFields->push(HX_CSTRING("file"));
	outFields->push(HX_CSTRING("chunk_buf"));
	outFields->push(HX_CSTRING("chunk_size"));
	outFields->push(HX_CSTRING("responseHeaders"));
	outFields->push(HX_CSTRING("cnxTimeout"));
	outFields->push(HX_CSTRING("noShutdown"));
	outFields->push(HX_CSTRING("url"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROXY"),
	HX_CSTRING("requestUrl"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onStatus"),
	HX_CSTRING("onError"),
	HX_CSTRING("onData"),
	HX_CSTRING("readChunk"),
	HX_CSTRING("readHttpResponse"),
	HX_CSTRING("customRequest"),
	HX_CSTRING("fileTransfert"),
	HX_CSTRING("request"),
	HX_CSTRING("setPostData"),
	HX_CSTRING("setParameter"),
	HX_CSTRING("setHeader"),
	HX_CSTRING("params"),
	HX_CSTRING("headers"),
	HX_CSTRING("postData"),
	HX_CSTRING("file"),
	HX_CSTRING("chunk_buf"),
	HX_CSTRING("chunk_size"),
	HX_CSTRING("responseHeaders"),
	HX_CSTRING("cnxTimeout"),
	HX_CSTRING("noShutdown"),
	HX_CSTRING("url"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Http_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Http_obj::PROXY,"PROXY");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Http_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Http_obj::PROXY,"PROXY");
};

Class Http_obj::__mClass;

void Http_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Http"), hx::TCanCast< Http_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Http_obj::__boot()
{
	PROXY= null();
}

} // end namespace haxe
