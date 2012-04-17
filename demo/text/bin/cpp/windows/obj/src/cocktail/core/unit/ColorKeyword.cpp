#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_ColorKeyword
#include <cocktail/core/unit/ColorKeyword.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::aqua;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::black;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::blue;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::fuchsia;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::gray;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::green;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::lime;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::maroon;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::navy;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::olive;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::orange;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::purple;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::red;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::silver;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::teal;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::white;

::cocktail::core::unit::ColorKeyword ColorKeyword_obj::yellow;

HX_DEFINE_CREATE_ENUM(ColorKeyword_obj)

int ColorKeyword_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("aqua")) return 0;
	if (inName==HX_CSTRING("black")) return 1;
	if (inName==HX_CSTRING("blue")) return 2;
	if (inName==HX_CSTRING("fuchsia")) return 3;
	if (inName==HX_CSTRING("gray")) return 4;
	if (inName==HX_CSTRING("green")) return 5;
	if (inName==HX_CSTRING("lime")) return 6;
	if (inName==HX_CSTRING("maroon")) return 7;
	if (inName==HX_CSTRING("navy")) return 8;
	if (inName==HX_CSTRING("olive")) return 9;
	if (inName==HX_CSTRING("orange")) return 10;
	if (inName==HX_CSTRING("purple")) return 11;
	if (inName==HX_CSTRING("red")) return 12;
	if (inName==HX_CSTRING("silver")) return 13;
	if (inName==HX_CSTRING("teal")) return 14;
	if (inName==HX_CSTRING("white")) return 15;
	if (inName==HX_CSTRING("yellow")) return 16;
	return super::__FindIndex(inName);
}

int ColorKeyword_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("aqua")) return 0;
	if (inName==HX_CSTRING("black")) return 0;
	if (inName==HX_CSTRING("blue")) return 0;
	if (inName==HX_CSTRING("fuchsia")) return 0;
	if (inName==HX_CSTRING("gray")) return 0;
	if (inName==HX_CSTRING("green")) return 0;
	if (inName==HX_CSTRING("lime")) return 0;
	if (inName==HX_CSTRING("maroon")) return 0;
	if (inName==HX_CSTRING("navy")) return 0;
	if (inName==HX_CSTRING("olive")) return 0;
	if (inName==HX_CSTRING("orange")) return 0;
	if (inName==HX_CSTRING("purple")) return 0;
	if (inName==HX_CSTRING("red")) return 0;
	if (inName==HX_CSTRING("silver")) return 0;
	if (inName==HX_CSTRING("teal")) return 0;
	if (inName==HX_CSTRING("white")) return 0;
	if (inName==HX_CSTRING("yellow")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ColorKeyword_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("aqua")) return aqua;
	if (inName==HX_CSTRING("black")) return black;
	if (inName==HX_CSTRING("blue")) return blue;
	if (inName==HX_CSTRING("fuchsia")) return fuchsia;
	if (inName==HX_CSTRING("gray")) return gray;
	if (inName==HX_CSTRING("green")) return green;
	if (inName==HX_CSTRING("lime")) return lime;
	if (inName==HX_CSTRING("maroon")) return maroon;
	if (inName==HX_CSTRING("navy")) return navy;
	if (inName==HX_CSTRING("olive")) return olive;
	if (inName==HX_CSTRING("orange")) return orange;
	if (inName==HX_CSTRING("purple")) return purple;
	if (inName==HX_CSTRING("red")) return red;
	if (inName==HX_CSTRING("silver")) return silver;
	if (inName==HX_CSTRING("teal")) return teal;
	if (inName==HX_CSTRING("white")) return white;
	if (inName==HX_CSTRING("yellow")) return yellow;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("aqua"),
	HX_CSTRING("black"),
	HX_CSTRING("blue"),
	HX_CSTRING("fuchsia"),
	HX_CSTRING("gray"),
	HX_CSTRING("green"),
	HX_CSTRING("lime"),
	HX_CSTRING("maroon"),
	HX_CSTRING("navy"),
	HX_CSTRING("olive"),
	HX_CSTRING("orange"),
	HX_CSTRING("purple"),
	HX_CSTRING("red"),
	HX_CSTRING("silver"),
	HX_CSTRING("teal"),
	HX_CSTRING("white"),
	HX_CSTRING("yellow"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::aqua,"aqua");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::black,"black");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::blue,"blue");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::fuchsia,"fuchsia");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::gray,"gray");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::green,"green");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::lime,"lime");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::maroon,"maroon");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::navy,"navy");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::olive,"olive");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::orange,"orange");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::purple,"purple");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::red,"red");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::silver,"silver");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::teal,"teal");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::white,"white");
	HX_MARK_MEMBER_NAME(ColorKeyword_obj::yellow,"yellow");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ColorKeyword_obj::__mClass;

Dynamic __Create_ColorKeyword_obj() { return new ColorKeyword_obj; }

void ColorKeyword_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.ColorKeyword"), hx::TCanCast< ColorKeyword_obj >,sStaticFields,sMemberFields,
	&__Create_ColorKeyword_obj, &__Create,
	&super::__SGetClass(), &CreateColorKeyword_obj, sMarkStatics);
}

void ColorKeyword_obj::__boot()
{
Static(aqua) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("aqua"),0);
Static(black) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("black"),1);
Static(blue) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("blue"),2);
Static(fuchsia) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("fuchsia"),3);
Static(gray) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("gray"),4);
Static(green) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("green"),5);
Static(lime) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("lime"),6);
Static(maroon) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("maroon"),7);
Static(navy) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("navy"),8);
Static(olive) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("olive"),9);
Static(orange) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("orange"),10);
Static(purple) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("purple"),11);
Static(red) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("red"),12);
Static(silver) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("silver"),13);
Static(teal) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("teal"),14);
Static(white) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("white"),15);
Static(yellow) = hx::CreateEnum< ColorKeyword_obj >(HX_CSTRING("yellow"),16);
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit
