#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io__Process_Stdin
#include <cpp/io/_Process/Stdin.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace io{
namespace _Process{

Void Stdin_obj::__construct(Dynamic p)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",33)
	this->p = p;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",34)
	this->buf = ::haxe::io::Bytes_obj::alloc((int)1);
}
;
	return null();
}

Stdin_obj::~Stdin_obj() { }

Dynamic Stdin_obj::__CreateEmpty() { return  new Stdin_obj; }
hx::ObjectPtr< Stdin_obj > Stdin_obj::__new(Dynamic p)
{  hx::ObjectPtr< Stdin_obj > result = new Stdin_obj();
	result->__construct(p);
	return result;}

Dynamic Stdin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stdin_obj > result = new Stdin_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Stdin_obj::close( ){
{
		HX_SOURCE_PUSH("Stdin_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",38)
		this->super::close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",39)
		::cpp::io::_Process::Stdin_obj::_stdin_close(this->p);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stdin_obj,close,(void))

Void Stdin_obj::writeByte( int c){
{
		HX_SOURCE_PUSH("Stdin_obj::writeByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",43)
		this->buf->b[(int)0] = c;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",44)
		this->writeBytes(this->buf,(int)0,(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stdin_obj,writeByte,(void))

int Stdin_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_SOURCE_PUSH("Stdin_obj::writeBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",47)
	try{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",48)
		return ::cpp::io::_Process::Stdin_obj::_stdin_write(this->p,buf->b,pos,len);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/Process.hx",50)
				hx::Throw (::haxe::io::Eof_obj::__new());
			}
		}
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Stdin_obj,writeBytes,return )

Dynamic Stdin_obj::_stdin_write;

Dynamic Stdin_obj::_stdin_close;


Stdin_obj::Stdin_obj()
{
}

void Stdin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stdin);
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(buf,"buf");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Stdin_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
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
	case 12:
		if (HX_FIELD_EQ(inName,"_stdin_write") ) { return _stdin_write; }
		if (HX_FIELD_EQ(inName,"_stdin_close") ) { return _stdin_close; }
	}
	return super::__Field(inName);
}

Dynamic Stdin_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_stdin_write") ) { _stdin_write=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stdin_close") ) { _stdin_close=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Stdin_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_stdin_write"),
	HX_CSTRING("_stdin_close"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("p"),
	HX_CSTRING("buf"),
	HX_CSTRING("close"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stdin_obj::_stdin_write,"_stdin_write");
	HX_MARK_MEMBER_NAME(Stdin_obj::_stdin_close,"_stdin_close");
};

Class Stdin_obj::__mClass;

void Stdin_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io._Process.Stdin"), hx::TCanCast< Stdin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stdin_obj::__boot()
{
	hx::Static(_stdin_write) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_stdin_write"),(int)4);
	hx::Static(_stdin_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("process_stdin_close"),(int)1);
}

} // end namespace cpp
} // end namespace io
} // end namespace _Process
