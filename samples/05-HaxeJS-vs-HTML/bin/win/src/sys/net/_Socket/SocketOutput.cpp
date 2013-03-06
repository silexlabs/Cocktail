#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_sys_net__Socket_SocketOutput
#include <sys/net/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace net{
namespace _Socket{

Void SocketOutput_obj::__construct(Dynamic s)
{
HX_STACK_PUSH("SocketOutput::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",84);
{
	HX_STACK_LINE(84)
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

Void SocketOutput_obj::close( ){
{
		HX_STACK_PUSH("SocketOutput::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",112);
		HX_STACK_THIS(this);
		HX_STACK_LINE(113)
		this->super::close();
		HX_STACK_LINE(114)
		if (((this->__s != null()))){
			HX_STACK_LINE(114)
			::sys::net::_Socket::SocketOutput_obj::socket_close(this->__s);
		}
	}
return null();
}


int SocketOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_PUSH("SocketOutput::writeBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",101);
	HX_STACK_THIS(this);
	HX_STACK_ARG(buf,"buf");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	struct _Function_1_1{
		inline static int Block( ::sys::net::_Socket::SocketOutput_obj *__this,::haxe::io::Bytes &buf,int &pos,int &len){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",102);
			{
				HX_STACK_LINE(102)
				try{
					HX_STACK_LINE(102)
					return ::sys::net::_Socket::SocketOutput_obj::socket_send(__this->__s,buf->b,pos,len);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(104)
							return (  (((e == HX_CSTRING("Blocking")))) ? int(hx::Throw (::haxe::io::Error_obj::Blocked_dyn())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(101)
	return _Function_1_1::Block(this,buf,pos,len);
}


Void SocketOutput_obj::writeByte( int c){
{
		HX_STACK_PUSH("SocketOutput::writeByte","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/net/Socket.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(89)
		if (((this->__s == null()))){
			HX_STACK_LINE(90)
			hx::Throw (HX_CSTRING("Invalid handle"));
		}
		HX_STACK_LINE(91)
		try{
			HX_STACK_LINE(91)
			::sys::net::_Socket::SocketOutput_obj::socket_send_char(this->__s,c);
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_STACK_LINE(93)
					if (((e == HX_CSTRING("Blocking")))){
						HX_STACK_LINE(95)
						hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
					}
					else{
						HX_STACK_LINE(97)
						hx::Throw (::haxe::io::Error_obj::Custom(e));
					}
				}
			}
		}
	}
return null();
}


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

void SocketOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SocketOutput_obj::__Field(const ::String &inName,bool inCallProp)
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
	return super::__Field(inName,inCallProp);
}

Dynamic SocketOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("close"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("__s"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

Class SocketOutput_obj::__mClass;

void SocketOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.net._Socket.SocketOutput"), hx::TCanCast< SocketOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SocketOutput_obj::__boot()
{
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	socket_send_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_send_char"),(int)2);
	socket_send= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_send"),(int)4);
}

} // end namespace sys
} // end namespace net
} // end namespace _Socket
