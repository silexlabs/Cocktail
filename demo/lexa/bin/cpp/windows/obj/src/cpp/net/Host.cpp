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
namespace cpp{
namespace net{

Void Host_obj::__construct(::String name)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Host.hx",33)
	this->ip = ::cpp::net::Host_obj::host_resolve(name);
}
;
	return null();
}

Host_obj::~Host_obj() { }

Dynamic Host_obj::__CreateEmpty() { return  new Host_obj; }
hx::ObjectPtr< Host_obj > Host_obj::__new(::String name)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(name);
	return result;}

Dynamic Host_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(inArgs[0]);
	return result;}

void Host_obj::__init__(){
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Host.hx",49)
	::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_init"),(int)0)();
}


::String Host_obj::toString( ){
	HX_SOURCE_PUSH("Host_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Host.hx",37)
	return ::String(::cpp::net::Host_obj::host_to_string(this->ip));
}


HX_DEFINE_DYNAMIC_FUNC0(Host_obj,toString,return )

::String Host_obj::reverse( ){
	HX_SOURCE_PUSH("Host_obj::reverse")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Host.hx",41)
	return ::String(::cpp::net::Host_obj::host_reverse(this->ip));
}


HX_DEFINE_DYNAMIC_FUNC0(Host_obj,reverse,return )

::String Host_obj::localhost( ){
	HX_SOURCE_PUSH("Host_obj::localhost")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/net/Host.hx",45)
	return ::String(::cpp::net::Host_obj::host_local());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Host_obj,localhost,return )

Dynamic Host_obj::host_resolve;

Dynamic Host_obj::host_reverse;

Dynamic Host_obj::host_to_string;

Dynamic Host_obj::host_local;


Host_obj::Host_obj()
{
}

void Host_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Host);
	HX_MARK_MEMBER_NAME(ip,"ip");
	HX_MARK_END_CLASS();
}

Dynamic Host_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { return ip; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"reverse") ) { return reverse_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"localhost") ) { return localhost_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"host_local") ) { return host_local; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { return host_resolve; }
		if (HX_FIELD_EQ(inName,"host_reverse") ) { return host_reverse; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"host_to_string") ) { return host_to_string; }
	}
	return super::__Field(inName);
}

Dynamic Host_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { ip=inValue.Cast< ::cpp::CppInt32__ >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"host_local") ) { host_local=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { host_resolve=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"host_reverse") ) { host_reverse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"host_to_string") ) { host_to_string=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Host_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ip"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("localhost"),
	HX_CSTRING("host_resolve"),
	HX_CSTRING("host_reverse"),
	HX_CSTRING("host_to_string"),
	HX_CSTRING("host_local"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("ip"),
	HX_CSTRING("toString"),
	HX_CSTRING("reverse"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Host_obj::host_resolve,"host_resolve");
	HX_MARK_MEMBER_NAME(Host_obj::host_reverse,"host_reverse");
	HX_MARK_MEMBER_NAME(Host_obj::host_to_string,"host_to_string");
	HX_MARK_MEMBER_NAME(Host_obj::host_local,"host_local");
};

Class Host_obj::__mClass;

void Host_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.net.Host"), hx::TCanCast< Host_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Host_obj::__boot()
{
	hx::Static(host_resolve) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_resolve"),(int)1);
	hx::Static(host_reverse) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_reverse"),(int)1);
	hx::Static(host_to_string) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_to_string"),(int)1);
	hx::Static(host_local) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_local"),(int)0);
}

} // end namespace cpp
} // end namespace net
