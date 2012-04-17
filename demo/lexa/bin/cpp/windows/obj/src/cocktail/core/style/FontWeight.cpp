#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::FontWeight FontWeight_obj::bold;

::cocktail::core::style::FontWeight FontWeight_obj::bolder;

::cocktail::core::style::FontWeight FontWeight_obj::css100;

::cocktail::core::style::FontWeight FontWeight_obj::css200;

::cocktail::core::style::FontWeight FontWeight_obj::css300;

::cocktail::core::style::FontWeight FontWeight_obj::css400;

::cocktail::core::style::FontWeight FontWeight_obj::css500;

::cocktail::core::style::FontWeight FontWeight_obj::css600;

::cocktail::core::style::FontWeight FontWeight_obj::css700;

::cocktail::core::style::FontWeight FontWeight_obj::css800;

::cocktail::core::style::FontWeight FontWeight_obj::css900;

::cocktail::core::style::FontWeight FontWeight_obj::lighter;

::cocktail::core::style::FontWeight FontWeight_obj::normal;

HX_DEFINE_CREATE_ENUM(FontWeight_obj)

int FontWeight_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bold")) return 1;
	if (inName==HX_CSTRING("bolder")) return 2;
	if (inName==HX_CSTRING("css100")) return 4;
	if (inName==HX_CSTRING("css200")) return 5;
	if (inName==HX_CSTRING("css300")) return 6;
	if (inName==HX_CSTRING("css400")) return 7;
	if (inName==HX_CSTRING("css500")) return 8;
	if (inName==HX_CSTRING("css600")) return 9;
	if (inName==HX_CSTRING("css700")) return 10;
	if (inName==HX_CSTRING("css800")) return 11;
	if (inName==HX_CSTRING("css900")) return 12;
	if (inName==HX_CSTRING("lighter")) return 3;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindIndex(inName);
}

int FontWeight_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bold")) return 0;
	if (inName==HX_CSTRING("bolder")) return 0;
	if (inName==HX_CSTRING("css100")) return 0;
	if (inName==HX_CSTRING("css200")) return 0;
	if (inName==HX_CSTRING("css300")) return 0;
	if (inName==HX_CSTRING("css400")) return 0;
	if (inName==HX_CSTRING("css500")) return 0;
	if (inName==HX_CSTRING("css600")) return 0;
	if (inName==HX_CSTRING("css700")) return 0;
	if (inName==HX_CSTRING("css800")) return 0;
	if (inName==HX_CSTRING("css900")) return 0;
	if (inName==HX_CSTRING("lighter")) return 0;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontWeight_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bold")) return bold;
	if (inName==HX_CSTRING("bolder")) return bolder;
	if (inName==HX_CSTRING("css100")) return css100;
	if (inName==HX_CSTRING("css200")) return css200;
	if (inName==HX_CSTRING("css300")) return css300;
	if (inName==HX_CSTRING("css400")) return css400;
	if (inName==HX_CSTRING("css500")) return css500;
	if (inName==HX_CSTRING("css600")) return css600;
	if (inName==HX_CSTRING("css700")) return css700;
	if (inName==HX_CSTRING("css800")) return css800;
	if (inName==HX_CSTRING("css900")) return css900;
	if (inName==HX_CSTRING("lighter")) return lighter;
	if (inName==HX_CSTRING("normal")) return normal;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("bold"),
	HX_CSTRING("bolder"),
	HX_CSTRING("lighter"),
	HX_CSTRING("css100"),
	HX_CSTRING("css200"),
	HX_CSTRING("css300"),
	HX_CSTRING("css400"),
	HX_CSTRING("css500"),
	HX_CSTRING("css600"),
	HX_CSTRING("css700"),
	HX_CSTRING("css800"),
	HX_CSTRING("css900"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontWeight_obj::bold,"bold");
	HX_MARK_MEMBER_NAME(FontWeight_obj::bolder,"bolder");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css100,"css100");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css200,"css200");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css300,"css300");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css400,"css400");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css500,"css500");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css600,"css600");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css700,"css700");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css800,"css800");
	HX_MARK_MEMBER_NAME(FontWeight_obj::css900,"css900");
	HX_MARK_MEMBER_NAME(FontWeight_obj::lighter,"lighter");
	HX_MARK_MEMBER_NAME(FontWeight_obj::normal,"normal");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontWeight_obj::__mClass;

Dynamic __Create_FontWeight_obj() { return new FontWeight_obj; }

void FontWeight_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.FontWeight"), hx::TCanCast< FontWeight_obj >,sStaticFields,sMemberFields,
	&__Create_FontWeight_obj, &__Create,
	&super::__SGetClass(), &CreateFontWeight_obj, sMarkStatics);
}

void FontWeight_obj::__boot()
{
Static(bold) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("bold"),1);
Static(bolder) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("bolder"),2);
Static(css100) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css100"),4);
Static(css200) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css200"),5);
Static(css300) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css300"),6);
Static(css400) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css400"),7);
Static(css500) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css500"),8);
Static(css600) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css600"),9);
Static(css700) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css700"),10);
Static(css800) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css800"),11);
Static(css900) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("css900"),12);
Static(lighter) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("lighter"),3);
Static(normal) = hx::CreateEnum< FontWeight_obj >(HX_CSTRING("normal"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
