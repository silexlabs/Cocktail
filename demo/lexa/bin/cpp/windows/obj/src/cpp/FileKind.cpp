#include <hxcpp.h>

#ifndef INCLUDED_cpp_FileKind
#include <cpp/FileKind.h>
#endif
namespace cpp{

::cpp::FileKind FileKind_obj::kdir;

::cpp::FileKind FileKind_obj::kfile;

::cpp::FileKind  FileKind_obj::kother(::String k)
	{ return hx::CreateEnum< FileKind_obj >(HX_CSTRING("kother"),2,hx::DynamicArray(0,1).Add(k)); }

HX_DEFINE_CREATE_ENUM(FileKind_obj)

int FileKind_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("kdir")) return 0;
	if (inName==HX_CSTRING("kfile")) return 1;
	if (inName==HX_CSTRING("kother")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileKind_obj,kother,return)

int FileKind_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("kdir")) return 0;
	if (inName==HX_CSTRING("kfile")) return 0;
	if (inName==HX_CSTRING("kother")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic FileKind_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("kdir")) return kdir;
	if (inName==HX_CSTRING("kfile")) return kfile;
	if (inName==HX_CSTRING("kother")) return kother_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("kdir"),
	HX_CSTRING("kfile"),
	HX_CSTRING("kother"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileKind_obj::kdir,"kdir");
	HX_MARK_MEMBER_NAME(FileKind_obj::kfile,"kfile");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FileKind_obj::__mClass;

Dynamic __Create_FileKind_obj() { return new FileKind_obj; }

void FileKind_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.FileKind"), hx::TCanCast< FileKind_obj >,sStaticFields,sMemberFields,
	&__Create_FileKind_obj, &__Create,
	&super::__SGetClass(), &CreateFileKind_obj, sMarkStatics);
}

void FileKind_obj::__boot()
{
Static(kdir) = hx::CreateEnum< FileKind_obj >(HX_CSTRING("kdir"),0);
Static(kfile) = hx::CreateEnum< FileKind_obj >(HX_CSTRING("kfile"),1);
}


} // end namespace cpp
