#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_sys_net__Socket_SocketInput
#include <sys/net/_Socket/SocketInput.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketOutput
#include <sys/net/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace net{

Void Socket_obj::__construct()
{
HX_STACK_PUSH("Socket::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",132);
{
	HX_STACK_LINE(133)
	this->__s = ::sys::net::Socket_obj::socket_new(false);
	HX_STACK_LINE(134)
	this->input = ::sys::net::_Socket::SocketInput_obj::__new(this->__s);
	HX_STACK_LINE(135)
	this->output = ::sys::net::_Socket::SocketOutput_obj::__new(this->__s);
}
;
	return null();
}

Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new()
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct();
	return result;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct();
	return result;}

Void Socket_obj::setFastSend( bool b){
{
		HX_STACK_PUSH("Socket::setFastSend","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",218);
		HX_STACK_THIS(this);
		HX_STACK_ARG(b,"b");
		HX_STACK_LINE(218)
		hx::Throw (HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setFastSend,(void))

Void Socket_obj::setBlocking( bool b){
{
		HX_STACK_PUSH("Socket::setBlocking","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",214);
		HX_STACK_THIS(this);
		HX_STACK_ARG(b,"b");
		HX_STACK_LINE(214)
		::sys::net::Socket_obj::socket_set_blocking(this->__s,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setBlocking,(void))

Void Socket_obj::waitForRead( ){
{
		HX_STACK_PUSH("Socket::waitForRead","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",210);
		HX_STACK_THIS(this);
		HX_STACK_LINE(210)
		::sys::net::Socket_obj::select(Array_obj< ::sys::net::Socket >::__new().Add(hx::ObjectPtr<OBJ_>(this)),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,waitForRead,(void))

Void Socket_obj::setTimeout( Float timeout){
{
		HX_STACK_PUSH("Socket::setTimeout","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",206);
		HX_STACK_THIS(this);
		HX_STACK_ARG(timeout,"timeout");
		HX_STACK_LINE(206)
		::sys::net::Socket_obj::socket_set_timeout(this->__s,timeout);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setTimeout,(void))

Dynamic Socket_obj::host( ){
	HX_STACK_PUSH("Socket::host","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",199);
	HX_STACK_THIS(this);
	HX_STACK_LINE(200)
	Dynamic a = ::sys::net::Socket_obj::socket_host(this->__s);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(201)
	::sys::net::Host h = ::sys::net::Host_obj::__new(HX_CSTRING("127.0.0.1"));		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(202)
	h->ip = a->__GetItem((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ::sys::net::Host &h,Dynamic &a){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",203);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("host") , h,false);
				__result->Add(HX_CSTRING("port") , a->__GetItem((int)1),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(203)
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,host,return )

Dynamic Socket_obj::peer( ){
	HX_STACK_PUSH("Socket::peer","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",192);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	Dynamic a = ::sys::net::Socket_obj::socket_peer(this->__s);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(194)
	::sys::net::Host h = ::sys::net::Host_obj::__new(HX_CSTRING("127.0.0.1"));		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(195)
	h->ip = a->__GetItem((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ::sys::net::Host &h,Dynamic &a){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",196);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("host") , h,false);
				__result->Add(HX_CSTRING("port") , a->__GetItem((int)1),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(196)
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,peer,return )

::sys::net::Socket Socket_obj::accept( ){
	HX_STACK_PUSH("Socket::accept","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",183);
	HX_STACK_THIS(this);
	HX_STACK_LINE(184)
	Dynamic c = ::sys::net::Socket_obj::socket_accept(this->__s);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(185)
	::sys::net::Socket s = ::Type_obj::createEmptyInstance(hx::ClassOf< ::sys::net::Socket >());		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(186)
	s->__s = c;
	HX_STACK_LINE(187)
	s->input = ::sys::net::_Socket::SocketInput_obj::__new(c);
	HX_STACK_LINE(188)
	s->output = ::sys::net::_Socket::SocketOutput_obj::__new(c);
	HX_STACK_LINE(189)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,accept,return )

Void Socket_obj::bind( ::sys::net::Host host,int port){
{
		HX_STACK_PUSH("Socket::bind","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",179);
		HX_STACK_THIS(this);
		HX_STACK_ARG(host,"host");
		HX_STACK_ARG(port,"port");
		HX_STACK_LINE(179)
		::sys::net::Socket_obj::socket_bind(this->__s,host->ip,port);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,bind,(void))

Void Socket_obj::shutdown( bool read,bool write){
{
		HX_STACK_PUSH("Socket::shutdown","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_ARG(read,"read");
		HX_STACK_ARG(write,"write");
		HX_STACK_LINE(175)
		::sys::net::Socket_obj::socket_shutdown(this->__s,read,write);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,shutdown,(void))

Void Socket_obj::listen( int connections){
{
		HX_STACK_PUSH("Socket::listen","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",171);
		HX_STACK_THIS(this);
		HX_STACK_ARG(connections,"connections");
		HX_STACK_LINE(171)
		::sys::net::Socket_obj::socket_listen(this->__s,connections);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,listen,(void))

Void Socket_obj::connect( ::sys::net::Host host,int port){
{
		HX_STACK_PUSH("Socket::connect","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_ARG(host,"host");
		HX_STACK_ARG(port,"port");
		HX_STACK_LINE(160)
		try{
			HX_STACK_LINE(161)
			::sys::net::Socket_obj::socket_connect(this->__s,host->ip,port);
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::String >() ){
				::String s = __e;{
					HX_STACK_LINE(163)
					if (((s == HX_CSTRING("std@socket_connect")))){
						struct _Function_3_1{
							inline static ::String Block( ::sys::net::Host &host){
								HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",165);
								{
									HX_STACK_LINE(165)
									try{
										HX_STACK_LINE(165)
										return host->reverse();
									}
									catch(Dynamic __e){
										{
											Dynamic e = __e;{
												HX_STACK_LINE(165)
												return host->toString();
											}
										}
									}
								}
								return null();
							}
						};
						HX_STACK_LINE(165)
						hx::Throw ((((HX_CSTRING("Failed to connect on ") + _Function_3_1::Block(host)) + HX_CSTRING(":")) + port));
					}
					else{
						HX_STACK_LINE(167)
						::cpp::Lib_obj::rethrow(s);
					}
				}
			}
			else throw(__e);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,connect,(void))

Void Socket_obj::write( ::String content){
{
		HX_STACK_PUSH("Socket::write","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_ARG(content,"content");
		HX_STACK_LINE(156)
		::sys::net::Socket_obj::socket_write(this->__s,::haxe::io::Bytes_obj::ofString(content)->b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,write,(void))

::String Socket_obj::read( ){
	HX_STACK_PUSH("Socket::read","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",150);
	HX_STACK_THIS(this);
	HX_STACK_LINE(151)
	Array< unsigned char > bytes = ::sys::net::Socket_obj::socket_read(this->__s);		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(152)
	if (((bytes == null()))){
		HX_STACK_LINE(152)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(153)
	return bytes->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,read,return )

Void Socket_obj::close( ){
{
		HX_STACK_PUSH("Socket::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_LINE(139)
		::sys::net::Socket_obj::socket_close(this->__s);
		HX_STACK_LINE(140)
		{
			HX_STACK_LINE(141)
			::sys::net::_Socket::SocketInput input = this->input;		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(142)
			::sys::net::_Socket::SocketOutput output = this->output;		HX_STACK_VAR(output,"output");
			HX_STACK_LINE(143)
			input->__s = null();
			HX_STACK_LINE(144)
			output->__s = null();
		}
		HX_STACK_LINE(146)
		this->input->close();
		HX_STACK_LINE(147)
		this->output->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

Dynamic Socket_obj::select( Array< ::sys::net::Socket > read,Array< ::sys::net::Socket > write,Array< ::sys::net::Socket > others,Dynamic timeout){
	HX_STACK_PUSH("Socket::select","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",222);
	HX_STACK_ARG(read,"read");
	HX_STACK_ARG(write,"write");
	HX_STACK_ARG(others,"others");
	HX_STACK_ARG(timeout,"timeout");
	HX_STACK_LINE(223)
	Array< Array< ::sys::net::Socket > > neko_array = ::sys::net::Socket_obj::socket_select(read,write,others,timeout);		HX_STACK_VAR(neko_array,"neko_array");
	HX_STACK_LINE(224)
	if (((neko_array == null()))){
		HX_STACK_LINE(225)
		hx::Throw (HX_CSTRING("Select error"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< ::sys::net::Socket > > &neko_array){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",226);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("read") , neko_array->__get((int)0),false);
				__result->Add(HX_CSTRING("write") , neko_array->__get((int)1),false);
				__result->Add(HX_CSTRING("others") , neko_array->__get((int)2),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(226)
	return _Function_1_1::Block(neko_array);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Socket_obj,select,return )

Dynamic Socket_obj::socket_new;

Dynamic Socket_obj::socket_close;

Dynamic Socket_obj::socket_write;

Dynamic Socket_obj::socket_read;

Dynamic Socket_obj::socket_connect;

Dynamic Socket_obj::socket_listen;

Dynamic Socket_obj::socket_select;

Dynamic Socket_obj::socket_bind;

Dynamic Socket_obj::socket_accept;

Dynamic Socket_obj::socket_peer;

Dynamic Socket_obj::socket_host;

Dynamic Socket_obj::socket_set_timeout;

Dynamic Socket_obj::socket_shutdown;

Dynamic Socket_obj::socket_set_blocking;


Socket_obj::Socket_obj()
{
}

void Socket_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Socket);
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_END_CLASS();
}

void Socket_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(custom,"custom");
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(__s,"__s");
}

Dynamic Socket_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { return host_dyn(); }
		if (HX_FIELD_EQ(inName,"peer") ) { return peer_dyn(); }
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { return select_dyn(); }
		if (HX_FIELD_EQ(inName,"accept") ) { return accept_dyn(); }
		if (HX_FIELD_EQ(inName,"listen") ) { return listen_dyn(); }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"shutdown") ) { return shutdown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"socket_new") ) { return socket_new; }
		if (HX_FIELD_EQ(inName,"setTimeout") ) { return setTimeout_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_read") ) { return socket_read; }
		if (HX_FIELD_EQ(inName,"socket_bind") ) { return socket_bind; }
		if (HX_FIELD_EQ(inName,"socket_peer") ) { return socket_peer; }
		if (HX_FIELD_EQ(inName,"socket_host") ) { return socket_host; }
		if (HX_FIELD_EQ(inName,"setFastSend") ) { return setFastSend_dyn(); }
		if (HX_FIELD_EQ(inName,"setBlocking") ) { return setBlocking_dyn(); }
		if (HX_FIELD_EQ(inName,"waitForRead") ) { return waitForRead_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		if (HX_FIELD_EQ(inName,"socket_write") ) { return socket_write; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"socket_listen") ) { return socket_listen; }
		if (HX_FIELD_EQ(inName,"socket_select") ) { return socket_select; }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { return socket_accept; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"socket_connect") ) { return socket_connect; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"socket_shutdown") ) { return socket_shutdown; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"socket_set_timeout") ) { return socket_set_timeout; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { return socket_set_blocking; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"socket_new") ) { socket_new=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_read") ) { socket_read=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_bind") ) { socket_bind=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_peer") ) { socket_peer=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_host") ) { socket_host=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_write") ) { socket_write=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"socket_listen") ) { socket_listen=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_select") ) { socket_select=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { socket_accept=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"socket_connect") ) { socket_connect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"socket_shutdown") ) { socket_shutdown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"socket_set_timeout") ) { socket_set_timeout=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { socket_set_blocking=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("custom"));
	outFields->push(HX_CSTRING("output"));
	outFields->push(HX_CSTRING("input"));
	outFields->push(HX_CSTRING("__s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("select"),
	HX_CSTRING("socket_new"),
	HX_CSTRING("socket_close"),
	HX_CSTRING("socket_write"),
	HX_CSTRING("socket_read"),
	HX_CSTRING("socket_connect"),
	HX_CSTRING("socket_listen"),
	HX_CSTRING("socket_select"),
	HX_CSTRING("socket_bind"),
	HX_CSTRING("socket_accept"),
	HX_CSTRING("socket_peer"),
	HX_CSTRING("socket_host"),
	HX_CSTRING("socket_set_timeout"),
	HX_CSTRING("socket_shutdown"),
	HX_CSTRING("socket_set_blocking"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setFastSend"),
	HX_CSTRING("setBlocking"),
	HX_CSTRING("waitForRead"),
	HX_CSTRING("setTimeout"),
	HX_CSTRING("host"),
	HX_CSTRING("peer"),
	HX_CSTRING("accept"),
	HX_CSTRING("bind"),
	HX_CSTRING("shutdown"),
	HX_CSTRING("listen"),
	HX_CSTRING("connect"),
	HX_CSTRING("write"),
	HX_CSTRING("read"),
	HX_CSTRING("close"),
	HX_CSTRING("custom"),
	HX_CSTRING("output"),
	HX_CSTRING("input"),
	HX_CSTRING("__s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_write,"socket_write");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_read,"socket_read");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_connect,"socket_connect");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_peer,"socket_peer");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_host,"socket_host");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_timeout,"socket_set_timeout");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_shutdown,"socket_shutdown");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_write,"socket_write");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_read,"socket_read");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_connect,"socket_connect");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_peer,"socket_peer");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_host,"socket_host");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_timeout,"socket_set_timeout");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_shutdown,"socket_shutdown");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
};

Class Socket_obj::__mClass;

void Socket_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.net.Socket"), hx::TCanCast< Socket_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Socket_obj::__boot()
{
	socket_new= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_new"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	socket_write= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_write"),(int)2);
	socket_read= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_read"),(int)1);
	socket_connect= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_connect"),(int)3);
	socket_listen= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_listen"),(int)2);
	socket_select= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_select"),(int)4);
	socket_bind= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_bind"),(int)3);
	socket_accept= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_accept"),(int)1);
	socket_peer= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_peer"),(int)1);
	socket_host= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_host"),(int)1);
	socket_set_timeout= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_timeout"),(int)2);
	socket_shutdown= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_shutdown"),(int)3);
	socket_set_blocking= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_blocking"),(int)2);
}

} // end namespace sys
} // end namespace net
