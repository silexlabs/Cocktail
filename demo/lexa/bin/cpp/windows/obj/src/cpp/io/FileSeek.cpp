#include <hxcpp.h>

#ifndef INCLUDED_cpp_io_FileSeek
#include <cpp/io/FileSeek.h>
#endif
namespace cpp{
namespace io{

::cpp::io::FileSeek FileSeek_obj::SeekBegin;

::cpp::io::FileSeek FileSeek_obj::SeekCur;

::cpp::io::FileSeek FileSeek_obj::SeekEnd;

HX_DEFINE_CREATE_ENUM(FileSeek_obj)

int FileSeek_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("SeekBegin")) return 0;
	if (inName==HX_CSTRING("SeekCur")) return 1;
	if (inName==HX_CSTRING("SeekEnd")) return 2;
	return super::__FindIndex(inName);
}

int FileSeek_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("SeekBegin")) return 0;
	if (inName==HX_CSTRING("SeekCur")) return 0;
	if (inName==HX_CSTRING("SeekEnd")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FileSeek_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("SeekBegin")) return SeekBegin;
	if (inName==HX_CSTRING("SeekCur")) return SeekCur;
	if (inName==HX_CSTRING("SeekEnd")) return SeekEnd;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("SeekBegin"),
	HX_CSTRING("SeekCur"),
	HX_CSTRING("SeekEnd"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileSeek_obj::SeekBegin,"SeekBegin");
	HX_MARK_MEMBER_NAME(FileSeek_obj::SeekCur,"SeekCur");
	HX_MARK_MEMBER_NAME(FileSeek_obj::SeekEnd,"SeekEnd");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FileSeek_obj::__mClass;

Dynamic __Create_FileSeek_obj() { return new FileSeek_obj; }

void FileSeek_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.io.FileSeek"), hx::TCanCast< FileSeek_obj >,sStaticFields,sMemberFields,
	&__Create_FileSeek_obj, &__Create,
	&super::__SGetClass(), &CreateFileSeek_obj, sMarkStatics);
}

void FileSeek_obj::__boot()
{
Static(SeekBegin) = hx::CreateEnum< FileSeek_obj >(HX_CSTRING("SeekBegin"),0);
Static(SeekCur) = hx::CreateEnum< FileSeek_obj >(HX_CSTRING("SeekCur"),1);
Static(SeekEnd) = hx::CreateEnum< FileSeek_obj >(HX_CSTRING("SeekEnd"),2);
}


} // end namespace cpp
} // end namespace io
