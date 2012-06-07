#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io_FileInput
#include <cpp/io/FileInput.h>
#endif
#ifndef INCLUDED_cpp_io_FileSeek
#include <cpp/io/FileSeek.h>
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

Void FileInput_obj::__construct(Dynamic f)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",35)
	this->__f = f;
}
;
	return null();
}

FileInput_obj::~FileInput_obj() { }

Dynamic FileInput_obj::__CreateEmpty() { return  new FileInput_obj; }
hx::ObjectPtr< FileInput_obj > FileInput_obj::__new(Dynamic f)
{  hx::ObjectPtr< FileInput_obj > result = new FileInput_obj();
	result->__construct(f);
	return result;}

Dynamic FileInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileInput_obj > result = new FileInput_obj();
	result->__construct(inArgs[0]);
	return result;}

int FileInput_obj::readByte( ){
	HX_SOURCE_PUSH("FileInput_obj::readByte")
	struct _Function_1_1{
		inline static int Block( ::cpp::io::FileInput_obj *__this){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",40)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",40)
				return ::cpp::io::FileInput_obj::file_read_char(__this->__f);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",42)
						return (  ((e->__IsArray())) ? int(hx::Throw (::haxe::io::Eof_obj::__new())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",39)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,readByte,return )

int FileInput_obj::readBytes( ::haxe::io::Bytes s,int p,int l){
	HX_SOURCE_PUSH("FileInput_obj::readBytes")
	struct _Function_1_1{
		inline static int Block( ::cpp::io::FileInput_obj *__this,::haxe::io::Bytes &s,int &p,int &l){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",51)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",51)
				return ::cpp::io::FileInput_obj::file_read(__this->__f,s->b,p,l);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",53)
						return (  ((e->__IsArray())) ? int(hx::Throw (::haxe::io::Eof_obj::__new())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",50)
	return _Function_1_1::Block(this,s,p,l);
}


HX_DEFINE_DYNAMIC_FUNC3(FileInput_obj,readBytes,return )

Void FileInput_obj::close( ){
{
		HX_SOURCE_PUSH("FileInput_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",62)
		this->super::close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",63)
		::cpp::io::FileInput_obj::file_close(this->__f);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,close,(void))

Void FileInput_obj::seek( int p,::cpp::io::FileSeek pos){
{
		HX_SOURCE_PUSH("FileInput_obj::seek")
		struct _Function_1_1{
			inline static int Block( ::cpp::io::FileSeek &pos){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",67)
				{
::cpp::io::FileSeek _switch_1 = (pos);
					switch((_switch_1)->GetIndex()){
						case 0: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",67)
							return (int)0;
						}
						;break;
						case 1: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",67)
							return (int)1;
						}
						;break;
						case 2: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",67)
							return (int)2;
						}
						;break;
					}
				}
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",66)
		::cpp::io::FileInput_obj::file_seek(this->__f,p,_Function_1_1::Block(pos));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FileInput_obj,seek,(void))

int FileInput_obj::tell( ){
	HX_SOURCE_PUSH("FileInput_obj::tell")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",70)
	return ::cpp::io::FileInput_obj::file_tell(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,tell,return )

bool FileInput_obj::eof( ){
	HX_SOURCE_PUSH("FileInput_obj::eof")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileInput.hx",75)
	return ::cpp::io::FileInput_obj::file_eof(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,eof,return )

Dynamic FileInput_obj::file_eof;

Dynamic FileInput_obj::file_read;

Dynamic FileInput_obj::file_read_char;

Dynamic FileInput_obj::file_close;

Dynamic FileInput_obj::file_seek;

Dynamic FileInput_obj::file_tell;


FileInput_obj::FileInput_obj()
{
}

void FileInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileInput);
	HX_MARK_MEMBER_NAME(__f,"__f");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FileInput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		if (HX_FIELD_EQ(inName,"eof") ) { return eof_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		if (HX_FIELD_EQ(inName,"tell") ) { return tell_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"file_eof") ) { return file_eof; }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_read") ) { return file_read; }
		if (HX_FIELD_EQ(inName,"file_seek") ) { return file_seek; }
		if (HX_FIELD_EQ(inName,"file_tell") ) { return file_tell; }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { return file_close; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_read_char") ) { return file_read_char; }
	}
	return super::__Field(inName);
}

Dynamic FileInput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { __f=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"file_eof") ) { file_eof=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_read") ) { file_read=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_seek") ) { file_seek=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_tell") ) { file_tell=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { file_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_read_char") ) { file_read_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FileInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__f"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("file_eof"),
	HX_CSTRING("file_read"),
	HX_CSTRING("file_read_char"),
	HX_CSTRING("file_close"),
	HX_CSTRING("file_seek"),
	HX_CSTRING("file_tell"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__f"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("close"),
	HX_CSTRING("seek"),
	HX_CSTRING("tell"),
	HX_CSTRING("eof"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileInput_obj::file_eof,"file_eof");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_read,"file_read");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_read_char,"file_read_char");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_close,"file_close");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_seek,"file_seek");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_tell,"file_tell");
};

Class FileInput_obj::__mClass;

void FileInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io.FileInput"), hx::TCanCast< FileInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FileInput_obj::__boot()
{
	hx::Static(file_eof) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_eof"),(int)1);
	hx::Static(file_read) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_read"),(int)4);
	hx::Static(file_read_char) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_read_char"),(int)1);
	hx::Static(file_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
	hx::Static(file_seek) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_seek"),(int)3);
	hx::Static(file_tell) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_tell"),(int)1);
}

} // end namespace cpp
} // end namespace io
