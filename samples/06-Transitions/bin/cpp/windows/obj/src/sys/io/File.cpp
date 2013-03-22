#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileInput
#include <sys/io/FileInput.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace sys{
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
	HX_STACK_PUSH("File::getContent","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",30);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(31)
	::haxe::io::Bytes b = ::sys::io::File_obj::getBytes(path);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(32)
	return b->toString();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getContent,return )

::haxe::io::Bytes File_obj::getBytes( ::String path){
	HX_STACK_PUSH("File::getBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",35);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(36)
	Array< unsigned char > data = ::sys::io::File_obj::file_contents(path);		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(37)
	return ::haxe::io::Bytes_obj::ofData(data);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(File_obj,getBytes,return )

Void File_obj::saveContent( ::String path,::String content){
{
		HX_STACK_PUSH("File::saveContent","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",40);
		HX_STACK_ARG(path,"path");
		HX_STACK_ARG(content,"content");
		HX_STACK_LINE(41)
		::sys::io::FileOutput f = ::sys::io::File_obj::write(path,null());		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(42)
		f->writeString(content);
		HX_STACK_LINE(43)
		f->close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,saveContent,(void))

Void File_obj::saveBytes( ::String path,::haxe::io::Bytes bytes){
{
		HX_STACK_PUSH("File::saveBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",46);
		HX_STACK_ARG(path,"path");
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_LINE(47)
		::sys::io::FileOutput f = ::sys::io::File_obj::write(path,null());		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(48)
		f->write(bytes);
		HX_STACK_LINE(49)
		f->close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,saveBytes,(void))

::sys::io::FileInput File_obj::read( ::String path,hx::Null< bool >  __o_binary){
bool binary = __o_binary.Default(true);
	HX_STACK_PUSH("File::read","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",52);
	HX_STACK_ARG(path,"path");
	HX_STACK_ARG(binary,"binary");
{
		HX_STACK_LINE(52)
		return ::sys::io::FileInput_obj::__new(::sys::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("rb")) : ::String(HX_CSTRING("r")) )));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,read,return )

::sys::io::FileOutput File_obj::write( ::String path,hx::Null< bool >  __o_binary){
bool binary = __o_binary.Default(true);
	HX_STACK_PUSH("File::write","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",56);
	HX_STACK_ARG(path,"path");
	HX_STACK_ARG(binary,"binary");
{
		HX_STACK_LINE(56)
		return ::sys::io::FileOutput_obj::__new(::sys::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("wb")) : ::String(HX_CSTRING("w")) )));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,write,return )

::sys::io::FileOutput File_obj::append( ::String path,hx::Null< bool >  __o_binary){
bool binary = __o_binary.Default(true);
	HX_STACK_PUSH("File::append","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",60);
	HX_STACK_ARG(path,"path");
	HX_STACK_ARG(binary,"binary");
{
		HX_STACK_LINE(60)
		return ::sys::io::FileOutput_obj::__new(::sys::io::File_obj::file_open(path,(  ((binary)) ? ::String(HX_CSTRING("ab")) : ::String(HX_CSTRING("a")) )));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,append,return )

Void File_obj::copy( ::String src,::String dst){
{
		HX_STACK_PUSH("File::copy","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/File.hx",64);
		HX_STACK_ARG(src,"src");
		HX_STACK_ARG(dst,"dst");
		HX_STACK_LINE(65)
		::sys::io::FileInput s = ::sys::io::File_obj::read(src,true);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(66)
		::sys::io::FileOutput d = ::sys::io::File_obj::write(dst,true);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(67)
		d->writeInput(s,null());
		HX_STACK_LINE(68)
		s->close();
		HX_STACK_LINE(69)
		d->close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(File_obj,copy,(void))

Dynamic File_obj::file_contents;

Dynamic File_obj::file_open;


File_obj::File_obj()
{
}

void File_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(File);
	HX_MARK_END_CLASS();
}

void File_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic File_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"append") ) { return append_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"saveBytes") ) { return saveBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"file_open") ) { return file_open; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContent") ) { return getContent_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"saveContent") ) { return saveContent_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"file_contents") ) { return file_contents; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic File_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"file_open") ) { file_open=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"file_contents") ) { file_contents=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void File_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getContent"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("saveContent"),
	HX_CSTRING("saveBytes"),
	HX_CSTRING("read"),
	HX_CSTRING("write"),
	HX_CSTRING("append"),
	HX_CSTRING("copy"),
	HX_CSTRING("file_contents"),
	HX_CSTRING("file_open"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(File_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(File_obj::file_contents,"file_contents");
	HX_MARK_MEMBER_NAME(File_obj::file_open,"file_open");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(File_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(File_obj::file_contents,"file_contents");
	HX_VISIT_MEMBER_NAME(File_obj::file_open,"file_open");
};

Class File_obj::__mClass;

void File_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.File"), hx::TCanCast< File_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void File_obj::__boot()
{
	file_contents= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_contents"),(int)1);
	file_open= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_open"),(int)2);
}

} // end namespace sys
} // end namespace io
