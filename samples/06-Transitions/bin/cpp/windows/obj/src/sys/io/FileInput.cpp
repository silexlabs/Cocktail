#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_sys_io_FileInput
#include <sys/io/FileInput.h>
#endif
#ifndef INCLUDED_sys_io_FileSeek
#include <sys/io/FileSeek.h>
#endif
namespace sys{
namespace io{

Void FileInput_obj::__construct(Dynamic f)
{
HX_STACK_PUSH("FileInput::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",33);
{
	HX_STACK_LINE(33)
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

bool FileInput_obj::eof( ){
	HX_STACK_PUSH("FileInput::eof","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(73)
	return ::sys::io::FileInput_obj::file_eof(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,eof,return )

int FileInput_obj::tell( ){
	HX_STACK_PUSH("FileInput::tell","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_LINE(68)
	return ::sys::io::FileInput_obj::file_tell(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileInput_obj,tell,return )

Void FileInput_obj::seek( int p,::sys::io::FileSeek pos){
{
		HX_STACK_PUSH("FileInput::seek","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",64);
		HX_STACK_THIS(this);
		HX_STACK_ARG(p,"p");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(64)
		::sys::io::FileInput_obj::file_seek(this->__f,p,(  (((pos == ::sys::io::FileSeek_obj::SeekBegin_dyn()))) ? int((int)0) : int((  (((pos == ::sys::io::FileSeek_obj::SeekCur_dyn()))) ? int((int)1) : int((int)2) )) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FileInput_obj,seek,(void))

Void FileInput_obj::close( ){
{
		HX_STACK_PUSH("FileInput::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",59);
		HX_STACK_THIS(this);
		HX_STACK_LINE(60)
		this->super::close();
		HX_STACK_LINE(61)
		::sys::io::FileInput_obj::file_close(this->__f);
	}
return null();
}


int FileInput_obj::readBytes( ::haxe::io::Bytes s,int p,int l){
	HX_STACK_PUSH("FileInput::readBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(l,"l");
	struct _Function_1_1{
		inline static int Block( ::sys::io::FileInput_obj *__this,::haxe::io::Bytes &s,int &p,int &l){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",49);
			{
				HX_STACK_LINE(49)
				try{
					HX_STACK_LINE(49)
					return ::sys::io::FileInput_obj::file_read(__this->__f,s->b,p,l);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(51)
							return (  ((e->__IsArray())) ? int(hx::Throw (::haxe::io::Eof_obj::__new())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(48)
	return _Function_1_1::Block(this,s,p,l);
}


int FileInput_obj::readByte( ){
	HX_STACK_PUSH("FileInput::readByte","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",37);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static int Block( ::sys::io::FileInput_obj *__this){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileInput.hx",38);
			{
				HX_STACK_LINE(38)
				try{
					HX_STACK_LINE(38)
					return ::sys::io::FileInput_obj::file_read_char(__this->__f);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(40)
							return (  ((e->__IsArray())) ? int(hx::Throw (::haxe::io::Eof_obj::__new())) : int(hx::Throw (::haxe::io::Error_obj::Custom(e))) );
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(37)
	return _Function_1_1::Block(this);
}


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

void FileInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__f,"__f");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FileInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"eof") ) { return eof_dyn(); }
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tell") ) { return tell_dyn(); }
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
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
	return super::__Field(inName,inCallProp);
}

Dynamic FileInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("eof"),
	HX_CSTRING("tell"),
	HX_CSTRING("seek"),
	HX_CSTRING("close"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readByte"),
	HX_CSTRING("__f"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_eof,"file_eof");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_read,"file_read");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_read_char,"file_read_char");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_close,"file_close");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_seek,"file_seek");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_tell,"file_tell");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_eof,"file_eof");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_read,"file_read");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_read_char,"file_read_char");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_close,"file_close");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_seek,"file_seek");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_tell,"file_tell");
};

Class FileInput_obj::__mClass;

void FileInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.FileInput"), hx::TCanCast< FileInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileInput_obj::__boot()
{
	file_eof= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_eof"),(int)1);
	file_read= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_read"),(int)4);
	file_read_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_read_char"),(int)1);
	file_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
	file_seek= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_seek"),(int)3);
	file_tell= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_tell"),(int)1);
}

} // end namespace sys
} // end namespace io
