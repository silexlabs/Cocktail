#include <hxcpp.h>

#ifndef INCLUDED_core_style_Display
#include <core/style/Display.h>
#endif
namespace core{
namespace style{

::core::style::Display Display_obj::block;

::core::style::Display Display_obj::cssInline;

::core::style::Display Display_obj::inlineBlock;

::core::style::Display Display_obj::none;

HX_DEFINE_CREATE_ENUM(Display_obj)

int Display_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("block")) return 0;
	if (inName==HX_CSTRING("cssInline")) return 2;
	if (inName==HX_CSTRING("inlineBlock")) return 1;
	if (inName==HX_CSTRING("none")) return 3;
	return super::__FindIndex(inName);
}

int Display_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("block")) return 0;
	if (inName==HX_CSTRING("cssInline")) return 0;
	if (inName==HX_CSTRING("inlineBlock")) return 0;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Display_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("block")) return block;
	if (inName==HX_CSTRING("cssInline")) return cssInline;
	if (inName==HX_CSTRING("inlineBlock")) return inlineBlock;
	if (inName==HX_CSTRING("none")) return none;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("block"),
	HX_CSTRING("inlineBlock"),
	HX_CSTRING("cssInline"),
	HX_CSTRING("none"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Display_obj::block,"block");
	HX_MARK_MEMBER_NAME(Display_obj::cssInline,"cssInline");
	HX_MARK_MEMBER_NAME(Display_obj::inlineBlock,"inlineBlock");
	HX_MARK_MEMBER_NAME(Display_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Display_obj::__mClass;

Dynamic __Create_Display_obj() { return new Display_obj; }

void Display_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Display"), hx::TCanCast< Display_obj >,sStaticFields,sMemberFields,
	&__Create_Display_obj, &__Create,
	&super::__SGetClass(), &CreateDisplay_obj, sMarkStatics);
}

void Display_obj::__boot()
{
Static(block) = hx::CreateEnum< Display_obj >(HX_CSTRING("block"),0);
Static(cssInline) = hx::CreateEnum< Display_obj >(HX_CSTRING("cssInline"),2);
Static(inlineBlock) = hx::CreateEnum< Display_obj >(HX_CSTRING("inlineBlock"),1);
Static(none) = hx::CreateEnum< Display_obj >(HX_CSTRING("none"),3);
}


} // end namespace core
} // end namespace style
