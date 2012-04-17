#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io_Process
#include <cpp/io/Process.h>
#endif
#ifndef INCLUDED_cpp_io__Process_Stdin
#include <cpp/io/_Process/Stdin.h>
#endif
#ifndef INCLUDED_cpp_io__Process_Stdout
#include <cpp/io/_Process/Stdout.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace io{

Void Process_obj::__construct(::String cmd,Array< ::String > args)
{
{
	struct _Function_1_1{
		inline static Dynamic Block( ::String &cmd,Array< ::String > &args){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",102)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",102)
				return ::cpp::io::Process_obj::_run(cmd,args);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",102)
						return hx::Throw ((HX_CSTRING("Process creation failure : ") + cmd));
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",102)
	this->p = _Function_1_1::Block(cmd,args);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",103)
	this->_stdin = ::cpp::io::_Process::Stdin_obj::__new(this->p);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",104)
	this->_stdout = ::cpp::io::_Process::Stdout_obj::__new(this->p,true);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",105)
	this->_stderr = ::cpp::io::_Process::Stdout_obj::__new(this->p,false);
}
;
	return null();
}

Process_obj::~Process_obj() { }

Dynamic Process_obj::__CreateEmpty() { return  new Process_obj; }
hx::ObjectPtr< Process_obj > Process_obj::__new(::String cmd,Array< ::String > args)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(cmd,args);
	return result;}

Dynamic Process_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Process_obj > result = new Process_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int Process_obj::getPid( ){
	HX_SOURCE_PUSH("Process_obj::getPid")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",108)
	return ::cpp::io::Process_obj::_pid(this->p);
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,getPid,return )

int Process_obj::exitCode( ){
	HX_SOURCE_PUSH("Process_obj::exitCode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",112)
	return ::cpp::io::Process_obj::_exit(this->p);
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,exitCode,return )

Void Process_obj::close( ){
{
		HX_SOURCE_PUSH("Process_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",116)
		::cpp::io::Process_obj::_close(this->p);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,close,(void))

Dynamic Process_obj::_run;

Dynamic Process_obj::_exit;

Dynamic Process_obj::_pid;

Dynamic Process_obj::_close;


Process_obj::Process_obj()
{
}

void Process_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Process);
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(_stdout,"stdout");
	HX_MARK_MEMBER_NAME(_stderr,"stderr");
	HX_MARK_MEMBER_NAME(_stdin,"stdin");
	HX_MARK_END_CLASS();
}

Dynamic Process_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_run") ) { return _run; }
		if (HX_FIELD_EQ(inName,"_pid") ) { return _pid; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_exit") ) { return _exit; }
		if (HX_FIELD_EQ(inName,"stdin") ) { return _stdin; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_close") ) { return _close; }
		if (HX_FIELD_EQ(inName,"stdout") ) { return _stdout; }
		if (HX_FIELD_EQ(inName,"stderr") ) { return _stderr; }
		if (HX_FIELD_EQ(inName,"getPid") ) { return getPid_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"exitCode") ) { return exitCode_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Process_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_run") ) { _run=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pid") ) { _pid=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_exit") ) { _exit=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stdin") ) { _stdin=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_close") ) { _close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stdout") ) { _stdout=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stderr") ) { _stderr=inValue.Cast< ::haxe::io::Input >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Process_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p"));
	outFields->push(HX_CSTRING("stdout"));
	outFields->push(HX_CSTRING("stderr"));
	outFields->push(HX_CSTRING("stdin"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_run"),
	HX_CSTRING("_exit"),
	HX_CSTRING("_pid"),
	HX_CSTRING("_close"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("p"),
	HX_CSTRING("stdout"),
	HX_CSTRING("stderr"),
	HX_CSTRING("stdin"),
	HX_CSTRING("getPid"),
	HX_CSTRING("exitCode"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Process_obj::_run,"_run");
	HX_MARK_MEMBER_NAME(Process_obj::_exit,"_exit");
	HX_MARK_MEMBER_NAME(Process_obj::_pid,"_pid");
	HX_MARK_MEMBER_NAME(Process_obj::_close,"_close");
};

Class Process_obj::__mClass;

void Process_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io.Process"), hx::TCanCast< Process_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Process_obj::__boot()
{
	hx::Static(_run) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_run"),(int)2);
	hx::Static(_exit) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_exit"),(int)1);
	hx::Static(_pid) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_pid"),(int)1);
	hx::Static(_close) = ::cpp::Lib_obj::loadLazy(HX_CSTRING("std"),HX_CSTRING("process_close"),(int)1);
}

} // end namespace cpp
} // end namespace io
