#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_Sys
#include <cpp/Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace cpp{

Void Sys_obj::__construct()
{
	return null();
}

Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Array< ::String > Sys_obj::args( ){
	HX_SOURCE_PUSH("Sys_obj::args")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",5)
	return ::__get_args();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,args,return )

::String Sys_obj::getEnv( ::String s){
	HX_SOURCE_PUSH("Sys_obj::getEnv")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",10)
	::String v = ::cpp::Sys_obj::get_env(s);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",11)
	if (((v == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",12)
		return null();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",13)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,getEnv,return )

Void Sys_obj::putEnv( ::String s,::String v){
{
		HX_SOURCE_PUSH("Sys_obj::putEnv")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",16)
		::cpp::Sys_obj::put_env(s,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,putEnv,(void))

Void Sys_obj::sleep( double seconds){
{
		HX_SOURCE_PUSH("Sys_obj::sleep")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",20)
		::cpp::Sys_obj::_sleep(seconds);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,sleep,(void))

bool Sys_obj::setTimeLocale( ::String loc){
	HX_SOURCE_PUSH("Sys_obj::setTimeLocale")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",24)
	return ::cpp::Sys_obj::set_time_locale(loc);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setTimeLocale,return )

::String Sys_obj::getCwd( ){
	HX_SOURCE_PUSH("Sys_obj::getCwd")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",28)
	return ::String(::cpp::Sys_obj::get_cwd());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,getCwd,return )

Void Sys_obj::setCwd( ::String s){
{
		HX_SOURCE_PUSH("Sys_obj::setCwd")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",32)
		::cpp::Sys_obj::set_cwd(s);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setCwd,(void))

::String Sys_obj::systemName( ){
	HX_SOURCE_PUSH("Sys_obj::systemName")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",36)
	return ::cpp::Sys_obj::sys_string();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,systemName,return )

::String Sys_obj::escapeArgument( ::String arg){
	HX_SOURCE_PUSH("Sys_obj::escapeArgument")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",41)
	bool ok = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",42)
	{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",42)
		int _g1 = (int)0;
		int _g = arg.length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",42)
		while(((_g1 < _g))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",42)
			int i = (_g1)++;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",43)
			switch( (int)(arg.charCodeAt(i))){
				case (int)32: case (int)34: {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",44)
					ok = false;
				}
				;break;
				case (int)0: case (int)13: case (int)10: {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",46)
					arg = arg.substr((int)0,i);
				}
				;break;
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",49)
	if ((ok)){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",50)
		return arg;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",51)
	return ((HX_CSTRING("\"") + arg.split(HX_CSTRING("\""))->join(HX_CSTRING("\\\""))) + HX_CSTRING("\""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,escapeArgument,return )

int Sys_obj::command( ::String cmd,Array< ::String > args){
	HX_SOURCE_PUSH("Sys_obj::command")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",55)
	if (((args != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",56)
		cmd = ::cpp::Sys_obj::escapeArgument(cmd);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",57)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",57)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",57)
			while(((_g < args->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",57)
				::String a = args->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",57)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",58)
				hx::AddEq(cmd,(HX_CSTRING(" ") + ::cpp::Sys_obj::escapeArgument(a)));
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",60)
	return ::cpp::Sys_obj::sys_command(cmd);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,command,return )

Void Sys_obj::exit( int code){
{
		HX_SOURCE_PUSH("Sys_obj::exit")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",63)
		::cpp::Sys_obj::sys_exit(code);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,exit,(void))

double Sys_obj::time( ){
	HX_SOURCE_PUSH("Sys_obj::time")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",67)
	return ::cpp::Sys_obj::sys_time();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,time,return )

double Sys_obj::cpuTime( ){
	HX_SOURCE_PUSH("Sys_obj::cpuTime")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",71)
	return ::cpp::Sys_obj::sys_cpu_time();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,cpuTime,return )

::String Sys_obj::executablePath( ){
	HX_SOURCE_PUSH("Sys_obj::executablePath")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",75)
	return ::String(::cpp::Sys_obj::sys_exe_path());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,executablePath,return )

::Hash Sys_obj::environment( ){
	HX_SOURCE_PUSH("Sys_obj::environment")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",80)
	Array< ::String > vars = ::cpp::Sys_obj::sys_env();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",81)
	::Hash result = ::Hash_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",82)
	int i = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",83)
	while(((i < vars->length))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",84)
		result->set(vars->__get(i),vars->__get((i + (int)1)));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",85)
		hx::AddEq(i,(int)2);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",87)
	::haxe::Log_obj::trace(result,hx::SourceInfo(HX_CSTRING("Sys.hx"),87,HX_CSTRING("cpp.Sys"),HX_CSTRING("environment")));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/Sys.hx",88)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,environment,return )

Dynamic Sys_obj::get_env;

Dynamic Sys_obj::put_env;

Dynamic Sys_obj::_sleep;

Dynamic Sys_obj::set_time_locale;

Dynamic Sys_obj::get_cwd;

Dynamic Sys_obj::set_cwd;

Dynamic Sys_obj::sys_string;

Dynamic Sys_obj::sys_command;

Dynamic Sys_obj::sys_exit;

Dynamic Sys_obj::sys_time;

Dynamic Sys_obj::sys_cpu_time;

Dynamic Sys_obj::sys_exe_path;

Dynamic Sys_obj::sys_env;


Sys_obj::Sys_obj()
{
}

void Sys_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sys);
	HX_MARK_END_CLASS();
}

Dynamic Sys_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args_dyn(); }
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		if (HX_FIELD_EQ(inName,"time") ) { return time_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sleep") ) { return sleep_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"getEnv") ) { return getEnv_dyn(); }
		if (HX_FIELD_EQ(inName,"putEnv") ) { return putEnv_dyn(); }
		if (HX_FIELD_EQ(inName,"getCwd") ) { return getCwd_dyn(); }
		if (HX_FIELD_EQ(inName,"setCwd") ) { return setCwd_dyn(); }
		if (HX_FIELD_EQ(inName,"_sleep") ) { return _sleep; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"command") ) { return command_dyn(); }
		if (HX_FIELD_EQ(inName,"cpuTime") ) { return cpuTime_dyn(); }
		if (HX_FIELD_EQ(inName,"get_env") ) { return get_env; }
		if (HX_FIELD_EQ(inName,"put_env") ) { return put_env; }
		if (HX_FIELD_EQ(inName,"get_cwd") ) { return get_cwd; }
		if (HX_FIELD_EQ(inName,"set_cwd") ) { return set_cwd; }
		if (HX_FIELD_EQ(inName,"sys_env") ) { return sys_env; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { return sys_exit; }
		if (HX_FIELD_EQ(inName,"sys_time") ) { return sys_time; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"systemName") ) { return systemName_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_string") ) { return sys_string; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"environment") ) { return environment_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_command") ) { return sys_command; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_cpu_time") ) { return sys_cpu_time; }
		if (HX_FIELD_EQ(inName,"sys_exe_path") ) { return sys_exe_path; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setTimeLocale") ) { return setTimeLocale_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"escapeArgument") ) { return escapeArgument_dyn(); }
		if (HX_FIELD_EQ(inName,"executablePath") ) { return executablePath_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_time_locale") ) { return set_time_locale; }
	}
	return super::__Field(inName);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_sleep") ) { _sleep=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_env") ) { get_env=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"put_env") ) { put_env=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"get_cwd") ) { get_cwd=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"set_cwd") ) { set_cwd=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sys_env") ) { sys_env=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { sys_exit=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sys_time") ) { sys_time=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_string") ) { sys_string=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sys_command") ) { sys_command=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_cpu_time") ) { sys_cpu_time=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sys_exe_path") ) { sys_exe_path=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_time_locale") ) { set_time_locale=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("args"),
	HX_CSTRING("getEnv"),
	HX_CSTRING("putEnv"),
	HX_CSTRING("sleep"),
	HX_CSTRING("setTimeLocale"),
	HX_CSTRING("getCwd"),
	HX_CSTRING("setCwd"),
	HX_CSTRING("systemName"),
	HX_CSTRING("escapeArgument"),
	HX_CSTRING("command"),
	HX_CSTRING("exit"),
	HX_CSTRING("time"),
	HX_CSTRING("cpuTime"),
	HX_CSTRING("executablePath"),
	HX_CSTRING("environment"),
	HX_CSTRING("get_env"),
	HX_CSTRING("put_env"),
	HX_CSTRING("_sleep"),
	HX_CSTRING("set_time_locale"),
	HX_CSTRING("get_cwd"),
	HX_CSTRING("set_cwd"),
	HX_CSTRING("sys_string"),
	HX_CSTRING("sys_command"),
	HX_CSTRING("sys_exit"),
	HX_CSTRING("sys_time"),
	HX_CSTRING("sys_cpu_time"),
	HX_CSTRING("sys_exe_path"),
	HX_CSTRING("sys_env"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sys_obj::get_env,"get_env");
	HX_MARK_MEMBER_NAME(Sys_obj::put_env,"put_env");
	HX_MARK_MEMBER_NAME(Sys_obj::_sleep,"_sleep");
	HX_MARK_MEMBER_NAME(Sys_obj::set_time_locale,"set_time_locale");
	HX_MARK_MEMBER_NAME(Sys_obj::get_cwd,"get_cwd");
	HX_MARK_MEMBER_NAME(Sys_obj::set_cwd,"set_cwd");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_string,"sys_string");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_command,"sys_command");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_exit,"sys_exit");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_time,"sys_time");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_cpu_time,"sys_cpu_time");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_exe_path,"sys_exe_path");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_env,"sys_env");
};

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.Sys"), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sys_obj::__boot()
{
	hx::Static(get_env) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_env"),(int)1);
	hx::Static(put_env) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("put_env"),(int)2);
	hx::Static(_sleep) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_sleep"),(int)1);
	hx::Static(set_time_locale) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("set_time_locale"),(int)1);
	hx::Static(get_cwd) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_cwd"),(int)0);
	hx::Static(set_cwd) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("set_cwd"),(int)1);
	hx::Static(sys_string) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_string"),(int)0);
	hx::Static(sys_command) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_command"),(int)1);
	hx::Static(sys_exit) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exit"),(int)1);
	hx::Static(sys_time) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_time"),(int)0);
	hx::Static(sys_cpu_time) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_cpu_time"),(int)0);
	hx::Static(sys_exe_path) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exe_path"),(int)0);
	hx::Static(sys_env) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_env"),(int)0);
}

} // end namespace cpp
