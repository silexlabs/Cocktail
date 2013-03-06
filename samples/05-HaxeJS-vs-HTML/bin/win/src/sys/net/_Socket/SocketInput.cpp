#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
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
#ifndef INCLUDED_sys_net__Socket_SocketInput
#include <sys/net/_Socket/SocketInput.h>
#endif
namespace sys{
namespace net{
namespace _Socket{

Void SocketInput_obj::__construct(Dynamic s)
{
HX_STACK_PUSH("SocketInput::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",35);
{
	HX_STACK_LINE(35)
	this->__s = s;
}
;
	return null();
}

SocketInput_obj::~SocketInput_obj() { }

Dynamic SocketInput_obj::__CreateEmpty() { return  new SocketInput_obj; }
hx::ObjectPtr< SocketInput_obj > SocketInput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(s);
	return result;}

Dynamic SocketInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SocketInput_obj::close( ){
{
		HX_STACK_PUSH("SocketInput::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_LINE(70)
		this->super::close();
		HX_STACK_LINE(71)
		if (((this->__s != null()))){
			HX_STACK_LINE(71)
			::sys::net::_Socket::SocketInput_obj::socket_close(this->__s);
		}
	}
return null();
}


int SocketInput_obj::readBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_PUSH("SocketInput::readBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buf,"buf");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(53)
	int r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(54)
	if (((this->__s == null()))){
		HX_STACK_LINE(55)
		hx::Throw (HX_CSTRING("Invalid handle"));
	}
	HX_STACK_LINE(56)
	try{
		HX_STACK_LINE(56)
		r = ::sys::net::_Socket::SocketInput_obj::socket_recv(this->__s,buf->b,pos,len);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_STACK_LINE(58)
				if (((e == HX_CSTRING("Blocking")))){
					HX_STACK_LINE(60)
					hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
				}
				else{
					HX_STACK_LINE(62)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	HX_STACK_LINE(64)
	if (((r == (int)0))){
		HX_STACK_LINE(65)
		hx::Throw (::haxe::io::Eof_obj::__new());
	}
	HX_STACK_LINE(66)
	return r;
}


int SocketInput_obj::readByte( ){
	HX_STACK_PUSH("SocketInput::readByte","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",39);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static int Block( ::sys::net::_Socket::SocketInput_obj *__this){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",40);
			{
				HX_STACK_LINE(40)
				try{
					HX_STACK_LINE(40)
					return ::sys::net::_Socket::SocketInput_obj::socket_recv_char(__this->__s);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(42)
							return (  (((e == HX_CSTRING("Blocking")))) ? int(hx::Throw (::haxe::io::Error_obj::Blocked_dyn())) : int((  (((__this->__s == null()))) ? int(hx::Throw (::haxe::io::Error_obj::Custom(e))) : int(hx::Throw (::haxe::io::Eof_obj::__new())) )) );
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(39)
	return _Function_1_1::Block(this);
}


Dynamic SocketInput_obj::socket_recv;

Dynamic SocketInput_obj::socket_recv_char;

Dynamic SocketInput_obj::socket_close;


SocketInput_obj::SocketInput_obj()
{
}

void SocketInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketInput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SocketInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SocketInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_recv") ) { return socket_recv; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { return socket_recv_char; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SocketInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_recv") ) { socket_recv=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { socket_recv_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SocketInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("socket_recv"),
	HX_CSTRING("socket_recv_char"),
	HX_CSTRING("socket_close"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("close"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readByte"),
	HX_CSTRING("__s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv,"socket_recv");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_recv,"socket_recv");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

Class SocketInput_obj::__mClass;

void SocketInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.net._Socket.SocketInput"), hx::TCanCast< SocketInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SocketInput_obj::__boot()
{
	socket_recv= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_recv"),(int)4);
	socket_recv_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_recv_char"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
}

} // end namespace sys
} // end namespace net
} // end namespace _Socket
