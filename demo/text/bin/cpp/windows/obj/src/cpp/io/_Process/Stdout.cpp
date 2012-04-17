#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io__Process_Stdout
#include <cpp/io/_Process/Stdout.h>
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
namespace io{
namespace _Process{

Void Stdout_obj::__construct(Dynamic p,bool out)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",67)
	this->p = p;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",68)
	this->out = out;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",69)
	this->buf = ::haxe::io::Bytes_obj::alloc((int)1);
}
;
	return null();
}

Stdout_obj::~Stdout_obj() { }

Dynamic Stdout_obj::__CreateEmpty() { return  new Stdout_obj; }
hx::ObjectPtr< Stdout_obj > Stdout_obj::__new(Dynamic p,bool out)
{  hx::ObjectPtr< Stdout_obj > result = new Stdout_obj();
	result->__construct(p,out);
	return result;}

Dynamic Stdout_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stdout_obj > result = new Stdout_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int Stdout_obj::readByte( ){
	HX_SOURCE_PUSH("Stdout_obj::readByte")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",73)
	if (((this->readBytes(this->buf,(int)0,(int)1) == (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",74)
		hx::Throw (::haxe::io::Error_obj::Blocked_dyn());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",75)
	return this->buf->b->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(Stdout_obj,readByte,return )

int Stdout_obj::readBytes( ::haxe::io::Bytes str,int pos,int len){
	HX_SOURCE_PUSH("Stdout_obj::readBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",79)
	int result;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",80)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",80)
		result = ((  ((this->out)) ? Dynamic(::cpp::io::_Process::Stdout_obj::_stdout_read_dyn()) : Dynamic(::cpp::io::_Process::Stdout_obj::_stderr_read_dyn()) ))(this->p,str->b,pos,len).Cast< int >();
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",82)
				hx::Throw (::haxe::io::Eof_obj::__new());
			}
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",85)
	if (((result == (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",85)
		hx::Throw (::haxe::io::Eof_obj::__new());
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",86)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC3(Stdout_obj,readBytes,return )

Dynamic Stdout_obj::_stdout_read;

Dynamic Stdout_obj::_stderr_read;


Stdout_obj::Stdout_obj()
{
}

void Stdout_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stdout);
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(out,"out");
	HX_MARK_MEMBER_NAME(buf,"buf");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Stdout_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"out") ) { return out; }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_stdout_read") ) { return _stdout_read; }
		if (HX_FIELD_EQ(inName,"_stderr_read") ) { return _stderr_read; }
	}
	return super::__Field(inName);
}

Dynamic Stdout_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"out") ) { out=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_stdout_read") ) { _stdout_read=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stderr_read") ) { _stderr_read=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Stdout_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p"));
	outFields->push(HX_CSTRING("out"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_stdout_read"),
	HX_CSTRING("_stderr_read"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("p"),
	HX_CSTRING("out"),
	HX_CSTRING("buf"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stdout_obj::_stdout_read,"_stdout_read");
	HX_MARK_MEMBER_NAME(Stdout_obj::_stderr_read,"_stderr_read");
};

Class Stdout_obj::__mClass;

void Stdout_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io._Process.Stdout"), hx::TCanCast< Stdout_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stdout_obj::__boot()
{
	hx::Static(_stdout_read) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_stdout_read"),(int)4);
	hx::Static(_stderr_read) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_stderr_read"),(int)4);
}

} // end namespace cpp
} // end namespace io
} // end namespace _Process
