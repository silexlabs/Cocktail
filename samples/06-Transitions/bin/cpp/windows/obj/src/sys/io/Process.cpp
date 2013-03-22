#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_Process
#include <sys/io/Process.h>
#endif
#ifndef INCLUDED_sys_io__Process_Stdin
#include <sys/io/_Process/Stdin.h>
#endif
#ifndef INCLUDED_sys_io__Process_Stdout
#include <sys/io/_Process/Stdout.h>
#endif
namespace sys{
namespace io{

Void Process_obj::__construct(::String cmd,Array< ::String > args)
{
HX_STACK_PUSH("Process::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",103);
{
	struct _Function_1_1{
		inline static Dynamic Block( ::String &cmd,Array< ::String > &args){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",104);
			{
				HX_STACK_LINE(104)
				try{
					HX_STACK_LINE(104)
					return ::sys::io::Process_obj::_run(cmd,args);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(104)
							return hx::Throw ((HX_CSTRING("Process creation failure : ") + cmd));
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(104)
	this->p = _Function_1_1::Block(cmd,args);
	HX_STACK_LINE(105)
	this->_stdin = ::sys::io::_Process::Stdin_obj::__new(this->p);
	HX_STACK_LINE(106)
	this->_stdout = ::sys::io::_Process::Stdout_obj::__new(this->p,true);
	HX_STACK_LINE(107)
	this->_stderr = ::sys::io::_Process::Stdout_obj::__new(this->p,false);
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

Void Process_obj::kill( ){
{
		HX_STACK_PUSH("Process::kill","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",122);
		HX_STACK_THIS(this);
		HX_STACK_LINE(122)
		hx::Throw (HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,kill,(void))

Void Process_obj::close( ){
{
		HX_STACK_PUSH("Process::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_LINE(118)
		::sys::io::Process_obj::_close(this->p);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,close,(void))

int Process_obj::exitCode( ){
	HX_STACK_PUSH("Process::exitCode","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",114);
	HX_STACK_THIS(this);
	HX_STACK_LINE(114)
	return ::sys::io::Process_obj::_exit(this->p);
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,exitCode,return )

int Process_obj::getPid( ){
	HX_STACK_PUSH("Process::getPid","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/Process.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_LINE(110)
	return ::sys::io::Process_obj::_pid(this->p);
}


HX_DEFINE_DYNAMIC_FUNC0(Process_obj,getPid,return )

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
	HX_MARK_MEMBER_NAME(_stdin,"stdin");
	HX_MARK_MEMBER_NAME(_stderr,"stderr");
	HX_MARK_MEMBER_NAME(_stdout,"stdout");
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_END_CLASS();
}

void Process_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_stdin,"stdin");
	HX_VISIT_MEMBER_NAME(_stderr,"stderr");
	HX_VISIT_MEMBER_NAME(_stdout,"stdout");
	HX_VISIT_MEMBER_NAME(p,"p");
}

Dynamic Process_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_run") ) { return _run; }
		if (HX_FIELD_EQ(inName,"_pid") ) { return _pid; }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_exit") ) { return _exit; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"stdin") ) { return _stdin; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_close") ) { return _close; }
		if (HX_FIELD_EQ(inName,"getPid") ) { return getPid_dyn(); }
		if (HX_FIELD_EQ(inName,"stderr") ) { return _stderr; }
		if (HX_FIELD_EQ(inName,"stdout") ) { return _stdout; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"exitCode") ) { return exitCode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Process_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"stderr") ) { _stderr=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stdout") ) { _stdout=inValue.Cast< ::haxe::io::Input >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Process_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("stdin"));
	outFields->push(HX_CSTRING("stderr"));
	outFields->push(HX_CSTRING("stdout"));
	outFields->push(HX_CSTRING("p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_run"),
	HX_CSTRING("_exit"),
	HX_CSTRING("_pid"),
	HX_CSTRING("_close"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("kill"),
	HX_CSTRING("close"),
	HX_CSTRING("exitCode"),
	HX_CSTRING("getPid"),
	HX_CSTRING("stdin"),
	HX_CSTRING("stderr"),
	HX_CSTRING("stdout"),
	HX_CSTRING("p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Process_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Process_obj::_run,"_run");
	HX_MARK_MEMBER_NAME(Process_obj::_exit,"_exit");
	HX_MARK_MEMBER_NAME(Process_obj::_pid,"_pid");
	HX_MARK_MEMBER_NAME(Process_obj::_close,"_close");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Process_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Process_obj::_run,"_run");
	HX_VISIT_MEMBER_NAME(Process_obj::_exit,"_exit");
	HX_VISIT_MEMBER_NAME(Process_obj::_pid,"_pid");
	HX_VISIT_MEMBER_NAME(Process_obj::_close,"_close");
};

Class Process_obj::__mClass;

void Process_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.Process"), hx::TCanCast< Process_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Process_obj::__boot()
{
	_run= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_run"),(int)2);
	_exit= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_exit"),(int)1);
	_pid= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_pid"),(int)1);
	_close= ::cpp::Lib_obj::loadLazy(HX_CSTRING("std"),HX_CSTRING("process_close"),(int)1);
}

} // end namespace sys
} // end namespace io
