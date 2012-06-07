#include <hxcpp.h>

#ifndef INCLUDED_core_style_TextTransform
#include <core/style/TextTransform.h>
#endif
namespace core{
namespace style{

::core::style::TextTransform TextTransform_obj::capitalize;

::core::style::TextTransform TextTransform_obj::lowercase;

::core::style::TextTransform TextTransform_obj::none;

::core::style::TextTransform TextTransform_obj::uppercase;

HX_DEFINE_CREATE_ENUM(TextTransform_obj)

int TextTransform_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("capitalize")) return 0;
	if (inName==HX_CSTRING("lowercase")) return 2;
	if (inName==HX_CSTRING("none")) return 3;
	if (inName==HX_CSTRING("uppercase")) return 1;
	return super::__FindIndex(inName);
}

int TextTransform_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("capitalize")) return 0;
	if (inName==HX_CSTRING("lowercase")) return 0;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("uppercase")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextTransform_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("capitalize")) return capitalize;
	if (inName==HX_CSTRING("lowercase")) return lowercase;
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("uppercase")) return uppercase;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("capitalize"),
	HX_CSTRING("uppercase"),
	HX_CSTRING("lowercase"),
	HX_CSTRING("none"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextTransform_obj::capitalize,"capitalize");
	HX_MARK_MEMBER_NAME(TextTransform_obj::lowercase,"lowercase");
	HX_MARK_MEMBER_NAME(TextTransform_obj::none,"none");
	HX_MARK_MEMBER_NAME(TextTransform_obj::uppercase,"uppercase");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextTransform_obj::__mClass;

Dynamic __Create_TextTransform_obj() { return new TextTransform_obj; }

void TextTransform_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.TextTransform"), hx::TCanCast< TextTransform_obj >,sStaticFields,sMemberFields,
	&__Create_TextTransform_obj, &__Create,
	&super::__SGetClass(), &CreateTextTransform_obj, sMarkStatics);
}

void TextTransform_obj::__boot()
{
Static(capitalize) = hx::CreateEnum< TextTransform_obj >(HX_CSTRING("capitalize"),0);
Static(lowercase) = hx::CreateEnum< TextTransform_obj >(HX_CSTRING("lowercase"),2);
Static(none) = hx::CreateEnum< TextTransform_obj >(HX_CSTRING("none"),3);
Static(uppercase) = hx::CreateEnum< TextTransform_obj >(HX_CSTRING("uppercase"),1);
}


} // end namespace core
} // end namespace style
