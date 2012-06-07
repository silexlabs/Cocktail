#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_net_SocketOutput
#include <cpp/net/SocketOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace net{

Void SocketOutput_obj::__construct(Dynamic s)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",33)
	this->__s = s;
}
;
	return null();
}

SocketOutput_obj::~SocketOutput_obj() { }

Dynamic SocketOutput_obj::__CreateEmpty() { return  new SocketOutput_obj; }
hx::ObjectPtr< SocketOutput_obj > SocketOutput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(s);
	return result;}

Dynamic SocketOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SocketOutput_obj::writeByte( int c){
{
		HX_SOURCE_PUSH("SocketOutput_obj::writeByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",38)
		if (((this->__s == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",39)
			hx::Throw (HX_CSTRING("Invalid handle"));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",40)
		try{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",40)
			::cpp::net::SocketOutput_obj::socket_send_char(this->__s,c);
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",42)
					if (((e == HX_CSTRING("Blocking")))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",44)
						hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
					}
					else{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",46)
						hx::Throw (::haxe::io::Error_obj::Custom(e));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SocketOutput_obj,writeByte,(void))

int SocketOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_SOURCE_PUSH("SocketOutput_obj::writeBytes")
	struct _Function_1_1{
		inline static int Block( ::cpp::net::SocketOutput_obj *__this,::haxe::io::Bytes &buf,int &pos,int &len){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",51)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",51)
				return ::cpp::net::SocketOutput_obj::socket_send(__this->__s,buf->b,pos,len);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",53)
						return (  (((e == HX_CSTRING("Blocking")))) ? int(hx::Throw (::haxe::io::Error_obj::Blocked_dyn())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",50)
	return _Function_1_1::Block(this,buf,pos,len);
}


HX_DEFINE_DYNAMIC_FUNC3(SocketOutput_obj,writeBytes,return )

Void SocketOutput_obj::close( ){
{
		HX_SOURCE_PUSH("SocketOutput_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",62)
		this->super::close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",63)
		if (((this->__s != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/SocketOutput.hx",63)
			::cpp::net::SocketOutput_obj::socket_close(this->__s);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SocketOutput_obj,close,(void))

Dynamic SocketOutput_obj::socket_close;

Dynamic SocketOutput_obj::socket_send_char;

Dynamic SocketOutput_obj::socket_send;


SocketOutput_obj::SocketOutput_obj()
{
}

void SocketOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketOutput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic SocketOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { return socket_send; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { return socket_send_char; }
	}
	return super::__Field(inName);
}

Dynamic SocketOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { socket_send=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { socket_send_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void SocketOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__s"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("socket_close"),
	HX_CSTRING("socket_send_char"),
	HX_CSTRING("socket_send"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__s"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

Class SocketOutput_obj::__mClass;

void SocketOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.net.SocketOutput"), hx::TCanCast< SocketOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void SocketOutput_obj::__boot()
{
	hx::Static(socket_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	hx::Static(socket_send_char) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_send_char"),(int)2);
	hx::Static(socket_send) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_send"),(int)4);
}

} // end namespace cpp
} // end namespace net
