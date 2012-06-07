#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_font_FontType
#include <cocktail/core/font/FontType.h>
#endif
namespace cocktail{
namespace core{
namespace font{

::cocktail::core::font::FontType FontType_obj::eot;

::cocktail::core::font::FontType FontType_obj::otf;

::cocktail::core::font::FontType FontType_obj::swf;

::cocktail::core::font::FontType FontType_obj::system;

::cocktail::core::font::FontType FontType_obj::ttf;

::cocktail::core::font::FontType FontType_obj::unknown;

HX_DEFINE_CREATE_ENUM(FontType_obj)

int FontType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("eot")) return 2;
	if (inName==HX_CSTRING("otf")) return 1;
	if (inName==HX_CSTRING("swf")) return 3;
	if (inName==HX_CSTRING("system")) return 4;
	if (inName==HX_CSTRING("ttf")) return 0;
	if (inName==HX_CSTRING("unknown")) return 5;
	return super::__FindIndex(inName);
}

int FontType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("eot")) return 0;
	if (inName==HX_CSTRING("otf")) return 0;
	if (inName==HX_CSTRING("swf")) return 0;
	if (inName==HX_CSTRING("system")) return 0;
	if (inName==HX_CSTRING("ttf")) return 0;
	if (inName==HX_CSTRING("unknown")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontType_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("eot")) return eot;
	if (inName==HX_CSTRING("otf")) return otf;
	if (inName==HX_CSTRING("swf")) return swf;
	if (inName==HX_CSTRING("system")) return system;
	if (inName==HX_CSTRING("ttf")) return ttf;
	if (inName==HX_CSTRING("unknown")) return unknown;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ttf"),
	HX_CSTRING("otf"),
	HX_CSTRING("eot"),
	HX_CSTRING("swf"),
	HX_CSTRING("system"),
	HX_CSTRING("unknown"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontType_obj::eot,"eot");
	HX_MARK_MEMBER_NAME(FontType_obj::otf,"otf");
	HX_MARK_MEMBER_NAME(FontType_obj::swf,"swf");
	HX_MARK_MEMBER_NAME(FontType_obj::system,"system");
	HX_MARK_MEMBER_NAME(FontType_obj::ttf,"ttf");
	HX_MARK_MEMBER_NAME(FontType_obj::unknown,"unknown");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontType_obj::__mClass;

Dynamic __Create_FontType_obj() { return new FontType_obj; }

void FontType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.FontType"), hx::TCanCast< FontType_obj >,sStaticFields,sMemberFields,
	&__Create_FontType_obj, &__Create,
	&super::__SGetClass(), &CreateFontType_obj, sMarkStatics);
}

void FontType_obj::__boot()
{
Static(eot) = hx::CreateEnum< FontType_obj >(HX_CSTRING("eot"),2);
Static(otf) = hx::CreateEnum< FontType_obj >(HX_CSTRING("otf"),1);
Static(swf) = hx::CreateEnum< FontType_obj >(HX_CSTRING("swf"),3);
Static(system) = hx::CreateEnum< FontType_obj >(HX_CSTRING("system"),4);
Static(ttf) = hx::CreateEnum< FontType_obj >(HX_CSTRING("ttf"),0);
Static(unknown) = hx::CreateEnum< FontType_obj >(HX_CSTRING("unknown"),5);
}


} // end namespace cocktail
} // end namespace core
} // end namespace font
