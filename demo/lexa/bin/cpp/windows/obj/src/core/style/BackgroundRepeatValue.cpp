#include <hxcpp.h>

#ifndef INCLUDED_core_style_BackgroundRepeatValue
#include <core/style/BackgroundRepeatValue.h>
#endif
namespace core{
namespace style{

::core::style::BackgroundRepeatValue BackgroundRepeatValue_obj::noRepeat;

::core::style::BackgroundRepeatValue BackgroundRepeatValue_obj::repeat;

::core::style::BackgroundRepeatValue BackgroundRepeatValue_obj::round;

::core::style::BackgroundRepeatValue BackgroundRepeatValue_obj::space;

HX_DEFINE_CREATE_ENUM(BackgroundRepeatValue_obj)

int BackgroundRepeatValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("noRepeat")) return 3;
	if (inName==HX_CSTRING("repeat")) return 0;
	if (inName==HX_CSTRING("round")) return 2;
	if (inName==HX_CSTRING("space")) return 1;
	return super::__FindIndex(inName);
}

int BackgroundRepeatValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("noRepeat")) return 0;
	if (inName==HX_CSTRING("repeat")) return 0;
	if (inName==HX_CSTRING("round")) return 0;
	if (inName==HX_CSTRING("space")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BackgroundRepeatValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("noRepeat")) return noRepeat;
	if (inName==HX_CSTRING("repeat")) return repeat;
	if (inName==HX_CSTRING("round")) return round;
	if (inName==HX_CSTRING("space")) return space;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("repeat"),
	HX_CSTRING("space"),
	HX_CSTRING("round"),
	HX_CSTRING("noRepeat"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundRepeatValue_obj::noRepeat,"noRepeat");
	HX_MARK_MEMBER_NAME(BackgroundRepeatValue_obj::repeat,"repeat");
	HX_MARK_MEMBER_NAME(BackgroundRepeatValue_obj::round,"round");
	HX_MARK_MEMBER_NAME(BackgroundRepeatValue_obj::space,"space");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BackgroundRepeatValue_obj::__mClass;

Dynamic __Create_BackgroundRepeatValue_obj() { return new BackgroundRepeatValue_obj; }

void BackgroundRepeatValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.BackgroundRepeatValue"), hx::TCanCast< BackgroundRepeatValue_obj >,sStaticFields,sMemberFields,
	&__Create_BackgroundRepeatValue_obj, &__Create,
	&super::__SGetClass(), &CreateBackgroundRepeatValue_obj, sMarkStatics);
}

void BackgroundRepeatValue_obj::__boot()
{
Static(noRepeat) = hx::CreateEnum< BackgroundRepeatValue_obj >(HX_CSTRING("noRepeat"),3);
Static(repeat) = hx::CreateEnum< BackgroundRepeatValue_obj >(HX_CSTRING("repeat"),0);
Static(round) = hx::CreateEnum< BackgroundRepeatValue_obj >(HX_CSTRING("round"),2);
Static(space) = hx::CreateEnum< BackgroundRepeatValue_obj >(HX_CSTRING("space"),1);
}


} // end namespace core
} // end namespace style
