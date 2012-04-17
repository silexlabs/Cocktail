#include <hxcpp.h>

#ifndef INCLUDED_core_style_FontStyle
#include <core/style/FontStyle.h>
#endif
namespace core{
namespace style{

::core::style::FontStyle FontStyle_obj::italic;

::core::style::FontStyle FontStyle_obj::normal;

HX_DEFINE_CREATE_ENUM(FontStyle_obj)

int FontStyle_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("italic")) return 1;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindIndex(inName);
}

int FontStyle_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("italic")) return 0;
	if (inName==HX_CSTRING("normal")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontStyle_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("italic")) return italic;
	if (inName==HX_CSTRING("normal")) return normal;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("italic"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontStyle_obj::italic,"italic");
	HX_MARK_MEMBER_NAME(FontStyle_obj::normal,"normal");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontStyle_obj::__mClass;

Dynamic __Create_FontStyle_obj() { return new FontStyle_obj; }

void FontStyle_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.FontStyle"), hx::TCanCast< FontStyle_obj >,sStaticFields,sMemberFields,
	&__Create_FontStyle_obj, &__Create,
	&super::__SGetClass(), &CreateFontStyle_obj, sMarkStatics);
}

void FontStyle_obj::__boot()
{
Static(italic) = hx::CreateEnum< FontStyle_obj >(HX_CSTRING("italic"),1);
Static(normal) = hx::CreateEnum< FontStyle_obj >(HX_CSTRING("normal"),0);
}


} // end namespace core
} // end namespace style
