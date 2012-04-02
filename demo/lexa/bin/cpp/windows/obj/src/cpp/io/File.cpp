#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io_File
#include <cpp/io/File.h>
#endif
#ifndef INCLUDED_cpp_io_FileInput
#include <cpp/io/FileInput.h>
#endif
#ifndef INCLUDED_cpp_io_FileOutput
#include <cpp/io/FileOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace cpp{
namespace io{

Void File_obj::__construct()
{
	return null();
}

File_obj::~File_obj() { }

Dynamic File_obj::__CreateEmpty() { return  new File_obj; }
hx::ObjectPtr< File_obj > File_obj::__new()
{  hx::ObjectPtr< File_obj > result = new File_obj();
	result->__construct();
	return result;}

Dynamic File_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< File_obj > result = new File_obj();
	result->__construct();
	return result;}

::String File_obj::getContent( ::String path){
	HX_SOURCE_PUSH("File_obj::getContent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",41)
	::haxe::io::Bytes b = ::cpp::io::File_obj::getBytes(path);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",42)
	return b->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getContent,return )

::haxe::io::Bytes File_obj::getBytes( ::String path){
	HX_SOURCE_PUSH("File_obj::getBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",46)
	Array< unsigned char > data = ::cpp::io::File_obj::file_contents(path);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",47)
	return ::haxe::io::Bytes_obj::ofData(data);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getBytes,return )

::cpp::io::FileInput File_obj::read( ::String path,bool binary){
	HX_SOURCE_PUSH("File_obj::read")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",50)
	return ::cpp::io::FileInput_obj::__new(::cpp::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("rb")) : ::String(HX_CSTRING("r")) )));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,read,return )

::cpp::io::FileOutput File_obj::write( ::String path,bool binary){
	HX_SOURCE_PUSH("File_obj::write")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",54)
	return ::cpp::io::FileOutput_obj::__new(::cpp::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("wb")) : ::String(HX_CSTRING("w")) )));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,write,return )

::cpp::io::FileOutput File_obj::append( ::String path,bool binary){
	HX_SOURCE_PUSH("File_obj::append")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",58)
	return ::cpp::io::FileOutput_obj::__new(::cpp::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("ab")) : ::String(HX_CSTRING("a")) )));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,append,return )

Void File_obj::copy( ::String src,::String dst){
{
		HX_SOURCE_PUSH("File_obj::copy")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",63)
		::cpp::io::FileInput s = ::cpp::io::File_obj::read(src,true);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",64)
		::cpp::io::FileOutput d = ::cpp::io::File_obj::write(dst,true);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",65)
		d->writeInput(s,null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",66)
		s->close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",67)
		d->close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,copy,(void))

::cpp::io::FileInput File_obj::_stdin( ){
	HX_SOURCE_PUSH("File_obj::stdin")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",70)
	return ::cpp::io::FileInput_obj::__new(::cpp::io::File_obj::file_stdin());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(File_obj,_stdin,return )

::cpp::io::FileOutput File_obj::_stdout( ){
	HX_SOURCE_PUSH("File_obj::stdout")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",74)
	return ::cpp::io::FileOutput_obj::__new(::cpp::io::File_obj::file_stdout());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(File_obj,_stdout,return )

::cpp::io::FileOutput File_obj::_stderr( ){
	HX_SOURCE_PUSH("File_obj::stderr")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",78)
	return ::cpp::io::FileOutput_obj::__new(::cpp::io::File_obj::file_stderr());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(File_obj,_stderr,return )

int File_obj::getChar( bool echo){
	HX_SOURCE_PUSH("File_obj::getChar")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/File.hx",82)
	return ::cpp::io::File_obj::getch(echo);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getChar,return )

Dynamic File_obj::file_stdin;

Dynamic File_obj::file_stdout;

Dynamic File_obj::file_stderr;

Dynamic File_obj::file_contents;

Dynamic File_obj::file_open;

Dynamic File_obj::getch;


File_obj::File_obj()
{
}

void File_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(File);
	HX_MARK_END_CLASS();
}

Dynamic File_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		if (HX_FIELD_EQ(inName,"stdin") ) { return _stdin_dyn(); }
		if (HX_FIELD_EQ(inName,"getch") ) { return getch; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"append") ) { return append_dyn(); }
		if (HX_FIELD_EQ(inName,"stdout") ) { return _stdout_dyn(); }
		if (HX_FIELD_EQ(inName,"stderr") ) { return _stderr_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getChar") ) { return getChar_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_open") ) { return file_open; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContent") ) { return getContent_dyn(); }
		if (HX_FIELD_EQ(inName,"file_stdin") ) { return file_stdin; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"file_stdout") ) { return file_stdout; }
		if (HX_FIELD_EQ(inName,"file_stderr") ) { return file_stderr; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"file_contents") ) { return file_contents; }
	}
	return super::__Field(inName);
}

Dynamic File_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"getch") ) { getch=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_open") ) { file_open=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_stdin") ) { file_stdin=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"file_stdout") ) { file_stdout=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_stderr") ) { file_stderr=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"file_contents") ) { file_contents=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void File_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getContent"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("read"),
	HX_CSTRING("write"),
	HX_CSTRING("append"),
	HX_CSTRING("copy"),
	HX_CSTRING("stdin"),
	HX_CSTRING("stdout"),
	HX_CSTRING("stderr"),
	HX_CSTRING("getChar"),
	HX_CSTRING("file_stdin"),
	HX_CSTRING("file_stdout"),
	HX_CSTRING("file_stderr"),
	HX_CSTRING("file_contents"),
	HX_CSTRING("file_open"),
	HX_CSTRING("getch"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(File_obj::file_stdin,"file_stdin");
	HX_MARK_MEMBER_NAME(File_obj::file_stdout,"file_stdout");
	HX_MARK_MEMBER_NAME(File_obj::file_stderr,"file_stderr");
	HX_MARK_MEMBER_NAME(File_obj::file_contents,"file_contents");
	HX_MARK_MEMBER_NAME(File_obj::file_open,"file_open");
	HX_MARK_MEMBER_NAME(File_obj::getch,"getch");
};

Class File_obj::__mClass;

void File_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io.File"), hx::TCanCast< File_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void File_obj::__boot()
{
	hx::Static(file_stdin) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_stdin"),(int)0);
	hx::Static(file_stdout) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_stdout"),(int)0);
	hx::Static(file_stderr) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_stderr"),(int)0);
	hx::Static(file_contents) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_contents"),(int)1);
	hx::Static(file_open) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_open"),(int)2);
	hx::Static(getch) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_getch"),(int)1);
}

} // end namespace cpp
} // end namespace io
