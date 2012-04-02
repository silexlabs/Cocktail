#include <hxcpp.h>

#ifndef INCLUDED_core_unit_FontSizeAbsoluteSize
#include <core/unit/FontSizeAbsoluteSize.h>
#endif
namespace core{
namespace unit{

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::large;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::medium;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::small;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::xLarge;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::xSmall;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::xxLarge;

::core::unit::FontSizeAbsoluteSize FontSizeAbsoluteSize_obj::xxSmall;

HX_DEFINE_CREATE_ENUM(FontSizeAbsoluteSize_obj)

int FontSizeAbsoluteSize_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("large")) return 4;
	if (inName==HX_CSTRING("medium")) return 3;
	if (inName==HX_CSTRING("small")) return 2;
	if (inName==HX_CSTRING("xLarge")) return 5;
	if (inName==HX_CSTRING("xSmall")) return 1;
	if (inName==HX_CSTRING("xxLarge")) return 6;
	if (inName==HX_CSTRING("xxSmall")) return 0;
	return super::__FindIndex(inName);
}

int FontSizeAbsoluteSize_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("large")) return 0;
	if (inName==HX_CSTRING("medium")) return 0;
	if (inName==HX_CSTRING("small")) return 0;
	if (inName==HX_CSTRING("xLarge")) return 0;
	if (inName==HX_CSTRING("xSmall")) return 0;
	if (inName==HX_CSTRING("xxLarge")) return 0;
	if (inName==HX_CSTRING("xxSmall")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontSizeAbsoluteSize_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("large")) return large;
	if (inName==HX_CSTRING("medium")) return medium;
	if (inName==HX_CSTRING("small")) return small;
	if (inName==HX_CSTRING("xLarge")) return xLarge;
	if (inName==HX_CSTRING("xSmall")) return xSmall;
	if (inName==HX_CSTRING("xxLarge")) return xxLarge;
	if (inName==HX_CSTRING("xxSmall")) return xxSmall;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("xxSmall"),
	HX_CSTRING("xSmall"),
	HX_CSTRING("small"),
	HX_CSTRING("medium"),
	HX_CSTRING("large"),
	HX_CSTRING("xLarge"),
	HX_CSTRING("xxLarge"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::large,"large");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::medium,"medium");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::small,"small");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::xLarge,"xLarge");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::xSmall,"xSmall");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::xxLarge,"xxLarge");
	HX_MARK_MEMBER_NAME(FontSizeAbsoluteSize_obj::xxSmall,"xxSmall");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontSizeAbsoluteSize_obj::__mClass;

Dynamic __Create_FontSizeAbsoluteSize_obj() { return new FontSizeAbsoluteSize_obj; }

void FontSizeAbsoluteSize_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.unit.FontSizeAbsoluteSize"), hx::TCanCast< FontSizeAbsoluteSize_obj >,sStaticFields,sMemberFields,
	&__Create_FontSizeAbsoluteSize_obj, &__Create,
	&super::__SGetClass(), &CreateFontSizeAbsoluteSize_obj, sMarkStatics);
}

void FontSizeAbsoluteSize_obj::__boot()
{
Static(large) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("large"),4);
Static(medium) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("medium"),3);
Static(small) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("small"),2);
Static(xLarge) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("xLarge"),5);
Static(xSmall) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("xSmall"),1);
Static(xxLarge) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("xxLarge"),6);
Static(xxSmall) = hx::CreateEnum< FontSizeAbsoluteSize_obj >(HX_CSTRING("xxSmall"),0);
}


} // end namespace core
} // end namespace unit
