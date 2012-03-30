#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_cpp_io_FileOutput
#include <cpp/io/FileOutput.h>
#endif
#ifndef INCLUDED_cpp_io_FileSeek
#include <cpp/io/FileSeek.h>
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
namespace cpp{
namespace io{

Void FileOutput_obj::__construct(Dynamic f)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",35)
	this->__f = f;
}
;
	return null();
}

FileOutput_obj::~FileOutput_obj() { }

Dynamic FileOutput_obj::__CreateEmpty() { return  new FileOutput_obj; }
hx::ObjectPtr< FileOutput_obj > FileOutput_obj::__new(Dynamic f)
{  hx::ObjectPtr< FileOutput_obj > result = new FileOutput_obj();
	result->__construct(f);
	return result;}

Dynamic FileOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileOutput_obj > result = new FileOutput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FileOutput_obj::writeByte( int c){
{
		HX_SOURCE_PUSH("FileOutput_obj::writeByte")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",39)
		try{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",40)
			::cpp::io::FileOutput_obj::file_write_char(this->__f,c);
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",40)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FileOutput_obj,writeByte,(void))

int FileOutput_obj::writeBytes( ::haxe::io::Bytes s,int p,int l){
	HX_SOURCE_PUSH("FileOutput_obj::writeBytes")
	struct _Function_1_1{
		inline static int Block( ::cpp::io::FileOutput_obj *__this,::haxe::io::Bytes &s,int &p,int &l){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",44)
			try{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",44)
				return ::cpp::io::FileOutput_obj::file_write(__this->__f,s->b,p,l);
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",44)
						return hx::Throw (::haxe::io::Error_obj::Custom(e));
					}
				}
			}
		}
	};
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",43)
	return _Function_1_1::Block(this,s,p,l);
}


HX_DEFINE_DYNAMIC_FUNC3(FileOutput_obj,writeBytes,return )

Void FileOutput_obj::flush( ){
{
		HX_SOURCE_PUSH("FileOutput_obj::flush")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",47)
		::cpp::io::FileOutput_obj::file_flush(this->__f);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FileOutput_obj,flush,(void))

Void FileOutput_obj::close( ){
{
		HX_SOURCE_PUSH("FileOutput_obj::close")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",52)
		this->super::close();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",53)
		::cpp::io::FileOutput_obj::file_close(this->__f);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FileOutput_obj,close,(void))

Void FileOutput_obj::seek( int p,::cpp::io::FileSeek pos){
{
		HX_SOURCE_PUSH("FileOutput_obj::seek")
		struct _Function_1_1{
			inline static int Block( ::cpp::io::FileSeek &pos){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",57)
				{
::cpp::io::FileSeek _switch_1 = (pos);
					switch((_switch_1)->GetIndex()){
						case 0: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",57)
							return (int)0;
						}
						;break;
						case 1: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",57)
							return (int)1;
						}
						;break;
						case 2: {
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",57)
							return (int)2;
						}
						;break;
					}
				}
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",56)
		::cpp::io::FileOutput_obj::file_seek(this->__f,p,_Function_1_1::Block(pos));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FileOutput_obj,seek,(void))

int FileOutput_obj::tell( ){
	HX_SOURCE_PUSH("FileOutput_obj::tell")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe/std/cpp/io/FileOutput.hx",60)
	return ::cpp::io::FileOutput_obj::file_tell(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileOutput_obj,tell,return )

Dynamic FileOutput_obj::file_close;

Dynamic FileOutput_obj::file_seek;

Dynamic FileOutput_obj::file_tell;

Dynamic FileOutput_obj::file_flush;

Dynamic FileOutput_obj::file_write;

Dynamic FileOutput_obj::file_write_char;


FileOutput_obj::FileOutput_obj()
{
}

void FileOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileOutput);
	HX_MARK_MEMBER_NAME(__f,"__f");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FileOutput_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		if (HX_FIELD_EQ(inName,"tell") ) { return tell_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_seek") ) { return file_seek; }
		if (HX_FIELD_EQ(inName,"file_tell") ) { return file_tell; }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { return file_close; }
		if (HX_FIELD_EQ(inName,"file_flush") ) { return file_flush; }
		if (HX_FIELD_EQ(inName,"file_write") ) { return file_write; }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"file_write_char") ) { return file_write_char; }
	}
	return super::__Field(inName);
}

Dynamic FileOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { __f=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"file_seek") ) { file_seek=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_tell") ) { file_tell=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { file_close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_flush") ) { file_flush=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_write") ) { file_write=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"file_write_char") ) { file_write_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FileOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__f"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("file_close"),
	HX_CSTRING("file_seek"),
	HX_CSTRING("file_tell"),
	HX_CSTRING("file_flush"),
	HX_CSTRING("file_write"),
	HX_CSTRING("file_write_char"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__f"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("flush"),
	HX_CSTRING("close"),
	HX_CSTRING("seek"),
	HX_CSTRING("tell"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_close,"file_close");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_seek,"file_seek");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_tell,"file_tell");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_flush,"file_flush");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write,"file_write");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write_char,"file_write_char");
};

Class FileOutput_obj::__mClass;

void FileOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io.FileOutput"), hx::TCanCast< FileOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FileOutput_obj::__boot()
{
	hx::Static(file_close) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
	hx::Static(file_seek) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_seek"),(int)3);
	hx::Static(file_tell) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_tell"),(int)1);
	hx::Static(file_flush) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_flush"),(int)1);
	hx::Static(file_write) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write"),(int)4);
	hx::Static(file_write_char) = ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write_char"),(int)2);
}

} // end namespace cpp
} // end namespace io
