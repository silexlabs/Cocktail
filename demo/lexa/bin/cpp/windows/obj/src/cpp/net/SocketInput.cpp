#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_SocketInput
#include <cpp/net/SocketInput.h>
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
namespace cpp{
namespace net{

Void SocketInput_obj::__construct(Dynamic s)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",33)
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

int SocketInput_obj::readByte( ){
	HX_SOURCE_PUSH("SocketInput_obj::readByte")
	struct _Function_1_1{
		inline static int Block( ::cpp::net::SocketInput_obj *__this){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",38)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",38)
				return ::cpp::net::SocketInput_obj::socket_recv_char(__this->__s);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",40)
						return (  (((e == HX_CSTRING("Blocking")))) ? int(hx::Throw (::haxe::io::Error_obj::Blocked_dyn())) : int((  (((__this->__s == null()))) ? int(hx::Throw (::haxe::io::Error_obj::Custom(e))) : int(hx::Throw (::haxe::io::Eof_obj::__new())) )) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",37)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(SocketInput_obj,readByte,return )

int SocketInput_obj::readBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_SOURCE_PUSH("SocketInput_obj::readBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",51)
	int r;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",52)
	if (((this->__s == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",53)
		hx::Throw (HX_CSTRING("Invalid handle"));
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",54)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",54)
		r = ::cpp::net::SocketInput_obj::socket_recv(this->__s,buf->b,pos,len);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",56)
				if (((e == HX_CSTRING("Blocking")))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",58)
					hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",60)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",62)
	if (((r == (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",63)
		hx::Throw (::haxe::io::Eof_obj::__new());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",64)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC3(SocketInput_obj,readBytes,return )

Void SocketInput_obj::close( ){
{
		HX_SOURCE_PUSH("SocketInput_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",68)
		this->super::close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",69)
		if (((this->__s != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketInput.hx",69)
			::cpp::net::SocketInput_obj::socket_close(this->__s);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SocketInput_obj,close,(void))

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

Dynamic SocketInput_obj::__Field(const ::String &inName)
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
	return super::__Field(inName);
}

Dynamic SocketInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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
	return super::__SetField(inName,inValue);
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
	HX_CSTRING("__s"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv,"socket_recv");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

Class SocketInput_obj::__mClass;

void SocketInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.net.SocketInput"), hx::TCanCast< SocketInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SocketInput_obj::__boot()
{
	hx::Static(socket_recv) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_recv"),(int)4);
	hx::Static(socket_recv_char) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_recv_char"),(int)1);
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
}

} // end namespace cpp
} // end namespace net
