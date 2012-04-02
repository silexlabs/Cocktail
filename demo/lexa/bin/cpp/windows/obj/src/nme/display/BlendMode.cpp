#include <hxcpp.h>

#ifndef INCLUDED_nme_display_BlendMode
#include <nme/display/BlendMode.h>
#endif
namespace nme{
namespace display{

::nme::display::BlendMode BlendMode_obj::ADD;

::nme::display::BlendMode BlendMode_obj::ALPHA;

::nme::display::BlendMode BlendMode_obj::DARKEN;

::nme::display::BlendMode BlendMode_obj::DIFFERENCE;

::nme::display::BlendMode BlendMode_obj::ERASE;

::nme::display::BlendMode BlendMode_obj::HARDLIGHT;

::nme::display::BlendMode BlendMode_obj::INVERT;

::nme::display::BlendMode BlendMode_obj::LAYER;

::nme::display::BlendMode BlendMode_obj::LIGHTEN;

::nme::display::BlendMode BlendMode_obj::MULTIPLY;

::nme::display::BlendMode BlendMode_obj::NORMAL;

::nme::display::BlendMode BlendMode_obj::OVERLAY;

::nme::display::BlendMode BlendMode_obj::SCREEN;

::nme::display::BlendMode BlendMode_obj::SUBTRACT;

HX_DEFINE_CREATE_ENUM(BlendMode_obj)

int BlendMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ADD")) return 7;
	if (inName==HX_CSTRING("ALPHA")) return 10;
	if (inName==HX_CSTRING("DARKEN")) return 5;
	if (inName==HX_CSTRING("DIFFERENCE")) return 6;
	if (inName==HX_CSTRING("ERASE")) return 11;
	if (inName==HX_CSTRING("HARDLIGHT")) return 13;
	if (inName==HX_CSTRING("INVERT")) return 9;
	if (inName==HX_CSTRING("LAYER")) return 1;
	if (inName==HX_CSTRING("LIGHTEN")) return 4;
	if (inName==HX_CSTRING("MULTIPLY")) return 2;
	if (inName==HX_CSTRING("NORMAL")) return 0;
	if (inName==HX_CSTRING("OVERLAY")) return 12;
	if (inName==HX_CSTRING("SCREEN")) return 3;
	if (inName==HX_CSTRING("SUBTRACT")) return 8;
	return super::__FindIndex(inName);
}

int BlendMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ADD")) return 0;
	if (inName==HX_CSTRING("ALPHA")) return 0;
	if (inName==HX_CSTRING("DARKEN")) return 0;
	if (inName==HX_CSTRING("DIFFERENCE")) return 0;
	if (inName==HX_CSTRING("ERASE")) return 0;
	if (inName==HX_CSTRING("HARDLIGHT")) return 0;
	if (inName==HX_CSTRING("INVERT")) return 0;
	if (inName==HX_CSTRING("LAYER")) return 0;
	if (inName==HX_CSTRING("LIGHTEN")) return 0;
	if (inName==HX_CSTRING("MULTIPLY")) return 0;
	if (inName==HX_CSTRING("NORMAL")) return 0;
	if (inName==HX_CSTRING("OVERLAY")) return 0;
	if (inName==HX_CSTRING("SCREEN")) return 0;
	if (inName==HX_CSTRING("SUBTRACT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BlendMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("ADD")) return ADD;
	if (inName==HX_CSTRING("ALPHA")) return ALPHA;
	if (inName==HX_CSTRING("DARKEN")) return DARKEN;
	if (inName==HX_CSTRING("DIFFERENCE")) return DIFFERENCE;
	if (inName==HX_CSTRING("ERASE")) return ERASE;
	if (inName==HX_CSTRING("HARDLIGHT")) return HARDLIGHT;
	if (inName==HX_CSTRING("INVERT")) return INVERT;
	if (inName==HX_CSTRING("LAYER")) return LAYER;
	if (inName==HX_CSTRING("LIGHTEN")) return LIGHTEN;
	if (inName==HX_CSTRING("MULTIPLY")) return MULTIPLY;
	if (inName==HX_CSTRING("NORMAL")) return NORMAL;
	if (inName==HX_CSTRING("OVERLAY")) return OVERLAY;
	if (inName==HX_CSTRING("SCREEN")) return SCREEN;
	if (inName==HX_CSTRING("SUBTRACT")) return SUBTRACT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("LAYER"),
	HX_CSTRING("MULTIPLY"),
	HX_CSTRING("SCREEN"),
	HX_CSTRING("LIGHTEN"),
	HX_CSTRING("DARKEN"),
	HX_CSTRING("DIFFERENCE"),
	HX_CSTRING("ADD"),
	HX_CSTRING("SUBTRACT"),
	HX_CSTRING("INVERT"),
	HX_CSTRING("ALPHA"),
	HX_CSTRING("ERASE"),
	HX_CSTRING("OVERLAY"),
	HX_CSTRING("HARDLIGHT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlendMode_obj::ADD,"ADD");
	HX_MARK_MEMBER_NAME(BlendMode_obj::ALPHA,"ALPHA");
	HX_MARK_MEMBER_NAME(BlendMode_obj::DARKEN,"DARKEN");
	HX_MARK_MEMBER_NAME(BlendMode_obj::DIFFERENCE,"DIFFERENCE");
	HX_MARK_MEMBER_NAME(BlendMode_obj::ERASE,"ERASE");
	HX_MARK_MEMBER_NAME(BlendMode_obj::HARDLIGHT,"HARDLIGHT");
	HX_MARK_MEMBER_NAME(BlendMode_obj::INVERT,"INVERT");
	HX_MARK_MEMBER_NAME(BlendMode_obj::LAYER,"LAYER");
	HX_MARK_MEMBER_NAME(BlendMode_obj::LIGHTEN,"LIGHTEN");
	HX_MARK_MEMBER_NAME(BlendMode_obj::MULTIPLY,"MULTIPLY");
	HX_MARK_MEMBER_NAME(BlendMode_obj::NORMAL,"NORMAL");
	HX_MARK_MEMBER_NAME(BlendMode_obj::OVERLAY,"OVERLAY");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SCREEN,"SCREEN");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SUBTRACT,"SUBTRACT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class BlendMode_obj::__mClass;

Dynamic __Create_BlendMode_obj() { return new BlendMode_obj; }

void BlendMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.BlendMode"), hx::TCanCast< BlendMode_obj >,sStaticFields,sMemberFields,
	&__Create_BlendMode_obj, &__Create,
	&super::__SGetClass(), &CreateBlendMode_obj, sMarkStatics);
}

void BlendMode_obj::__boot()
{
Static(ADD) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("ADD"),7);
Static(ALPHA) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("ALPHA"),10);
Static(DARKEN) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("DARKEN"),5);
Static(DIFFERENCE) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("DIFFERENCE"),6);
Static(ERASE) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("ERASE"),11);
Static(HARDLIGHT) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("HARDLIGHT"),13);
Static(INVERT) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("INVERT"),9);
Static(LAYER) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("LAYER"),1);
Static(LIGHTEN) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("LIGHTEN"),4);
Static(MULTIPLY) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("MULTIPLY"),2);
Static(NORMAL) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("NORMAL"),0);
Static(OVERLAY) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("OVERLAY"),12);
Static(SCREEN) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("SCREEN"),3);
Static(SUBTRACT) = hx::CreateEnum< BlendMode_obj >(HX_CSTRING("SUBTRACT"),8);
}


} // end namespace nme
} // end namespace display
