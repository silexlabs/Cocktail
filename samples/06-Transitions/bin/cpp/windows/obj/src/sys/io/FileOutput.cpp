#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
#ifndef INCLUDED_sys_io_FileSeek
#include <sys/io/FileSeek.h>
#endif
namespace sys{
namespace io{

Void FileOutput_obj::__construct(Dynamic f)
{
HX_STACK_PUSH("FileOutput::new","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",33);
{
	HX_STACK_LINE(33)
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

int FileOutput_obj::tell( ){
	HX_STACK_PUSH("FileOutput::tell","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_LINE(58)
	return ::sys::io::FileOutput_obj::file_tell(this->__f);
}


HX_DEFINE_DYNAMIC_FUNC0(FileOutput_obj,tell,return )

Void FileOutput_obj::seek( int p,::sys::io::FileSeek pos){
{
		HX_STACK_PUSH("FileOutput::seek","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(p,"p");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_LINE(54)
		::sys::io::FileOutput_obj::file_seek(this->__f,p,(  (((pos == ::sys::io::FileSeek_obj::SeekBegin_dyn()))) ? int((int)0) : int((  (((pos == ::sys::io::FileSeek_obj::SeekCur_dyn()))) ? int((int)1) : int((int)2) )) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FileOutput_obj,seek,(void))

Void FileOutput_obj::close( ){
{
		HX_STACK_PUSH("FileOutput::close","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",49);
		HX_STACK_THIS(this);
		HX_STACK_LINE(50)
		this->super::close();
		HX_STACK_LINE(51)
		::sys::io::FileOutput_obj::file_close(this->__f);
	}
return null();
}


Void FileOutput_obj::flush( ){
{
		HX_STACK_PUSH("FileOutput::flush","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",45);
		HX_STACK_THIS(this);
		HX_STACK_LINE(45)
		::sys::io::FileOutput_obj::file_flush(this->__f);
	}
return null();
}


int FileOutput_obj::writeBytes( ::haxe::io::Bytes s,int p,int l){
	HX_STACK_PUSH("FileOutput::writeBytes","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(l,"l");
	struct _Function_1_1{
		inline static int Block( ::sys::io::FileOutput_obj *__this,::haxe::io::Bytes &s,int &p,int &l){
			HX_STACK_PUSH("*::closure","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",42);
			{
				HX_STACK_LINE(42)
				try{
					HX_STACK_LINE(42)
					return ::sys::io::FileOutput_obj::file_write(__this->__f,s->b,p,l);
				}
				catch(Dynamic __e){
					{
						Dynamic e = __e;{
							HX_STACK_LINE(42)
							return hx::Throw (::haxe::io::Error_obj::Custom(e));
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(41)
	return _Function_1_1::Block(this,s,p,l);
}


Void FileOutput_obj::writeByte( int c){
{
		HX_STACK_PUSH("FileOutput::writeByte","C:\\Motion-Twin\\Haxe/std/cpp/_std/sys/io/FileOutput.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(37)
		try{
			HX_STACK_LINE(38)
			::sys::io::FileOutput_obj::file_write_char(this->__f,c);
		}
		catch(Dynamic __e){
			{
				Dynamic e = __e;{
					HX_STACK_LINE(38)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
return null();
}


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

void FileOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__f,"__f");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FileOutput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tell") ) { return tell_dyn(); }
		if (HX_FIELD_EQ(inName,"seek") ) { return seek_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
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
	return super::__Field(inName,inCallProp);
}

Dynamic FileOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_CSTRING("tell"),
	HX_CSTRING("seek"),
	HX_CSTRING("close"),
	HX_CSTRING("flush"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("__f"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileOutput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_close,"file_close");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_seek,"file_seek");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_tell,"file_tell");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_flush,"file_flush");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write,"file_write");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write_char,"file_write_char");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileOutput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_close,"file_close");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_seek,"file_seek");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_tell,"file_tell");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_flush,"file_flush");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_write,"file_write");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_write_char,"file_write_char");
};

Class FileOutput_obj::__mClass;

void FileOutput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.FileOutput"), hx::TCanCast< FileOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileOutput_obj::__boot()
{
	file_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
	file_seek= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_seek"),(int)3);
	file_tell= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_tell"),(int)1);
	file_flush= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_flush"),(int)1);
	file_write= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write"),(int)4);
	file_write_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write_char"),(int)2);
}

} // end namespace sys
} // end namespace io
