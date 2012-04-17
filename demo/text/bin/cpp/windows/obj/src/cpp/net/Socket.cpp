#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_Host
#include <cpp/net/Host.h>
#endif
#ifndef INCLUDED_cpp_net_Socket
#include <cpp/net/Socket.h>
#endif
#ifndef INCLUDED_cpp_net_SocketInput
#include <cpp/net/SocketInput.h>
#endif
#ifndef INCLUDED_cpp_net_SocketOutput
#include <cpp/net/SocketOutput.h>
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
namespace cpp{
namespace net{

Void Socket_obj::__construct(Dynamic s)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",39)
	this->__s = (  (((s == null()))) ? Dynamic(::cpp::net::Socket_obj::socket_new(false)) : Dynamic(s) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",40)
	this->input = ::cpp::net::SocketInput_obj::__new(this->__s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",41)
	this->output = ::cpp::net::SocketOutput_obj::__new(this->__s);
}
;
	return null();
}

Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new(Dynamic s)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(s);
	return result;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Socket_obj::close( ){
{
		HX_SOURCE_PUSH("Socket_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",45)
		::cpp::net::Socket_obj::socket_close(this->__s);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",46)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",47)
			this->input->__s = null();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",48)
			this->output->__s = null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",50)
		this->input->close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",51)
		this->output->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

::String Socket_obj::read( ){
	HX_SOURCE_PUSH("Socket_obj::read")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",55)
	Array< unsigned char > bytes = ::cpp::net::Socket_obj::socket_read(this->__s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",56)
	if (((bytes == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",56)
		return HX_CSTRING("");
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",57)
	return bytes->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,read,return )

Void Socket_obj::write( ::String content){
{
		HX_SOURCE_PUSH("Socket_obj::write")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",60)
		::cpp::net::Socket_obj::socket_write(this->__s,::haxe::io::Bytes_obj::ofString(content)->b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,write,(void))

Void Socket_obj::connect( ::cpp::net::Host host,int port){
{
		HX_SOURCE_PUSH("Socket_obj::connect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",64)
		try{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",65)
			::cpp::net::Socket_obj::socket_connect(this->__s,host->ip,port);
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::String >() ){
				::String s = __e;{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",67)
					if (((s == HX_CSTRING("std@socket_connect")))){
						struct _Function_3_1{
							inline static ::String Block( ::cpp::net::Host &host){
								HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",69)
								try{
									HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",69)
									return host->reverse();
								}
								catch(Dynamic __e){
									{
										Dynamic e = __e;{
											HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",69)
											return host->toString();
										}
									}
								}
							}
						};
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",69)
						hx::Throw ((((HX_CSTRING("Failed to connect on ") + _Function_3_1::Block(host)) + HX_CSTRING(":")) + port));
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",71)
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

Void Socket_obj::listen( int connections){
{
		HX_SOURCE_PUSH("Socket_obj::listen")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",75)
		::cpp::net::Socket_obj::socket_listen(this->__s,connections);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,listen,(void))

Void Socket_obj::shutdown( bool read,bool write){
{
		HX_SOURCE_PUSH("Socket_obj::shutdown")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",79)
		::cpp::net::Socket_obj::socket_shutdown(this->__s,read,write);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,shutdown,(void))

Void Socket_obj::bind( ::cpp::net::Host host,int port){
{
		HX_SOURCE_PUSH("Socket_obj::bind")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",83)
		::cpp::net::Socket_obj::socket_bind(this->__s,host->ip,port);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,bind,(void))

::cpp::net::Socket Socket_obj::accept( ){
	HX_SOURCE_PUSH("Socket_obj::accept")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",87)
	return ::cpp::net::Socket_obj::__new(::cpp::net::Socket_obj::socket_accept(this->__s));
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,accept,return )

Dynamic Socket_obj::peer( ){
	HX_SOURCE_PUSH("Socket_obj::peer")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",92)
	Dynamic a = ::cpp::net::Socket_obj::socket_peer(this->__s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",93)
	::cpp::net::Host h = ::cpp::net::Host_obj::__new(HX_CSTRING("127.0.0.1"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",94)
	h->ip = a->__GetItem((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::net::Host &h,Dynamic &a){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("host") , h,false);
			__result->Add(HX_CSTRING("port") , a->__GetItem((int)1),false);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",95)
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,peer,return )

Dynamic Socket_obj::host( ){
	HX_SOURCE_PUSH("Socket_obj::host")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",99)
	Dynamic a = ::cpp::net::Socket_obj::socket_host(this->__s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",100)
	::cpp::net::Host h = ::cpp::net::Host_obj::__new(HX_CSTRING("127.0.0.1"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",101)
	h->ip = a->__GetItem((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ::cpp::net::Host &h,Dynamic &a){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("host") , h,false);
			__result->Add(HX_CSTRING("port") , a->__GetItem((int)1),false);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",102)
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,host,return )

Void Socket_obj::setTimeout( double timeout){
{
		HX_SOURCE_PUSH("Socket_obj::setTimeout")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",105)
		::cpp::net::Socket_obj::socket_set_timeout(this->__s,timeout);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setTimeout,(void))

Void Socket_obj::waitForRead( ){
{
		HX_SOURCE_PUSH("Socket_obj::waitForRead")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",109)
		::cpp::net::Socket_obj::select(Array_obj< ::cpp::net::Socket >::__new().Add(hx::ObjectPtr<OBJ_>(this)),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,waitForRead,(void))

Void Socket_obj::setBlocking( bool b){
{
		HX_SOURCE_PUSH("Socket_obj::setBlocking")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",113)
		::cpp::net::Socket_obj::socket_set_blocking(this->__s,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setBlocking,(void))

::cpp::net::Socket Socket_obj::newUdpSocket( ){
	HX_SOURCE_PUSH("Socket_obj::newUdpSocket")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",117)
	return ::cpp::net::Socket_obj::__new(::cpp::net::Socket_obj::socket_new(true));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,newUdpSocket,return )

Dynamic Socket_obj::select( Array< ::cpp::net::Socket > read,Array< ::cpp::net::Socket > write,Array< ::cpp::net::Socket > others,Dynamic timeout){
	HX_SOURCE_PUSH("Socket_obj::select")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",123)
	Array< Array< ::cpp::net::Socket > > neko_array = ::cpp::net::Socket_obj::socket_select(read,write,others,timeout);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",124)
	if (((neko_array == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",125)
		hx::Throw (HX_CSTRING("Select error"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< Array< ::cpp::net::Socket > > &neko_array){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("read") , neko_array->__get((int)0),false);
			__result->Add(HX_CSTRING("write") , neko_array->__get((int)1),false);
			__result->Add(HX_CSTRING("others") , neko_array->__get((int)2),false);
			return __result;
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Socket.hx",126)
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
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_END_CLASS();
}

Dynamic Socket_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
		if (HX_FIELD_EQ(inName,"peer") ) { return peer_dyn(); }
		if (HX_FIELD_EQ(inName,"host") ) { return host_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { return select_dyn(); }
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		if (HX_FIELD_EQ(inName,"listen") ) { return listen_dyn(); }
		if (HX_FIELD_EQ(inName,"accept") ) { return accept_dyn(); }
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
		if (HX_FIELD_EQ(inName,"waitForRead") ) { return waitForRead_dyn(); }
		if (HX_FIELD_EQ(inName,"setBlocking") ) { return setBlocking_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"newUdpSocket") ) { return newUdpSocket_dyn(); }
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
	return super::__Field(inName);
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::cpp::net::SocketInput >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::cpp::net::SocketOutput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< Dynamic >(); return inValue; }
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
	return super::__SetField(inName,inValue);
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__s"));
	outFields->push(HX_CSTRING("input"));
	outFields->push(HX_CSTRING("output"));
	outFields->push(HX_CSTRING("custom"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("newUdpSocket"),
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
	HX_CSTRING("__s"),
	HX_CSTRING("input"),
	HX_CSTRING("output"),
	HX_CSTRING("custom"),
	HX_CSTRING("close"),
	HX_CSTRING("read"),
	HX_CSTRING("write"),
	HX_CSTRING("connect"),
	HX_CSTRING("listen"),
	HX_CSTRING("shutdown"),
	HX_CSTRING("bind"),
	HX_CSTRING("accept"),
	HX_CSTRING("peer"),
	HX_CSTRING("host"),
	HX_CSTRING("setTimeout"),
	HX_CSTRING("waitForRead"),
	HX_CSTRING("setBlocking"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
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

Class Socket_obj::__mClass;

void Socket_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.net.Socket"), hx::TCanCast< Socket_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Socket_obj::__boot()
{
	hx::Static(socket_new) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_new"),(int)1);
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	hx::Static(socket_write) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_write"),(int)2);
	hx::Static(socket_read) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_read"),(int)1);
	hx::Static(socket_connect) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_connect"),(int)3);
	hx::Static(socket_listen) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_listen"),(int)2);
	hx::Static(socket_select) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_select"),(int)4);
	hx::Static(socket_bind) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_bind"),(int)3);
	hx::Static(socket_accept) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_accept"),(int)1);
	hx::Static(socket_peer) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_peer"),(int)1);
	hx::Static(socket_host) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_host"),(int)1);
	hx::Static(socket_set_timeout) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_timeout"),(int)2);
	hx::Static(socket_shutdown) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_shutdown"),(int)3);
	hx::Static(socket_set_blocking) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_blocking"),(int)2);
}

} // end namespace cpp
} // end namespace net
