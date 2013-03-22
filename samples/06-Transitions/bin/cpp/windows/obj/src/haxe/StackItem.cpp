#include <hxcpp.h>

#ifndef INCLUDED_haxe_StackItem
#include <haxe/StackItem.h>
#endif
namespace haxe{

::haxe::StackItem StackItem_obj::CFunction;

::haxe::StackItem  StackItem_obj::FilePos(::haxe::StackItem s,::String file,int line)
	{ return hx::CreateEnum< StackItem_obj >(HX_CSTRING("FilePos"),2,hx::DynamicArray(0,3).Add(s).Add(file).Add(line)); }

::haxe::StackItem  StackItem_obj::Lambda(int v)
	{ return hx::CreateEnum< StackItem_obj >(HX_CSTRING("Lambda"),4,hx::DynamicArray(0,1).Add(v)); }

::haxe::StackItem  StackItem_obj::Method(::String classname,::String method)
	{ return hx::CreateEnum< StackItem_obj >(HX_CSTRING("Method"),3,hx::DynamicArray(0,2).Add(classname).Add(method)); }

::haxe::StackItem  StackItem_obj::Module(::String m)
	{ return hx::CreateEnum< StackItem_obj >(HX_CSTRING("Module"),1,hx::DynamicArray(0,1).Add(m)); }

HX_DEFINE_CREATE_ENUM(StackItem_obj)

int StackItem_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CFunction")) return 0;
	if (inName==HX_CSTRING("FilePos")) return 2;
	if (inName==HX_CSTRING("Lambda")) return 4;
	if (inName==HX_CSTRING("Method")) return 3;
	if (inName==HX_CSTRING("Module")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC3(StackItem_obj,FilePos,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StackItem_obj,Lambda,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(StackItem_obj,Method,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(StackItem_obj,Module,return)

int StackItem_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CFunction")) return 0;
	if (inName==HX_CSTRING("FilePos")) return 3;
	if (inName==HX_CSTRING("Lambda")) return 1;
	if (inName==HX_CSTRING("Method")) return 2;
	if (inName==HX_CSTRING("Module")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic StackItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CFunction")) return CFunction;
	if (inName==HX_CSTRING("FilePos")) return FilePos_dyn();
	if (inName==HX_CSTRING("Lambda")) return Lambda_dyn();
	if (inName==HX_CSTRING("Method")) return Method_dyn();
	if (inName==HX_CSTRING("Module")) return Module_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("CFunction"),
	HX_CSTRING("Module"),
	HX_CSTRING("FilePos"),
	HX_CSTRING("Method"),
	HX_CSTRING("Lambda"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackItem_obj::CFunction,"CFunction");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackItem_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StackItem_obj::CFunction,"CFunction");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StackItem_obj::__mClass;

Dynamic __Create_StackItem_obj() { return new StackItem_obj; }

void StackItem_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.StackItem"), hx::TCanCast< StackItem_obj >,sStaticFields,sMemberFields,
	&__Create_StackItem_obj, &__Create,
	&super::__SGetClass(), &CreateStackItem_obj, sMarkStatics, sVisitStatic);
}

void StackItem_obj::__boot()
{
Static(CFunction) = hx::CreateEnum< StackItem_obj >(HX_CSTRING("CFunction"),0);
}


} // end namespace haxe
