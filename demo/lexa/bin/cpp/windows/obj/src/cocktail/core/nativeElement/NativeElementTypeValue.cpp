#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
namespace cocktail{
namespace core{
namespace nativeElement{

::cocktail::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::anchor;

::cocktail::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::canvas;

::cocktail::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::img;

::cocktail::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::input;

::cocktail::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::script;

::cocktail::core::nativeElement::NativeElementTypeValue  NativeElementTypeValue_obj::semantic(::String name)
	{ return hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("semantic"),5,hx::DynamicArray(0,1).Add(name)); }

HX_DEFINE_CREATE_ENUM(NativeElementTypeValue_obj)

int NativeElementTypeValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("anchor")) return 3;
	if (inName==HX_CSTRING("canvas")) return 0;
	if (inName==HX_CSTRING("img")) return 1;
	if (inName==HX_CSTRING("input")) return 4;
	if (inName==HX_CSTRING("script")) return 2;
	if (inName==HX_CSTRING("semantic")) return 5;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(NativeElementTypeValue_obj,semantic,return)

int NativeElementTypeValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("anchor")) return 0;
	if (inName==HX_CSTRING("canvas")) return 0;
	if (inName==HX_CSTRING("img")) return 0;
	if (inName==HX_CSTRING("input")) return 0;
	if (inName==HX_CSTRING("script")) return 0;
	if (inName==HX_CSTRING("semantic")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic NativeElementTypeValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("anchor")) return anchor;
	if (inName==HX_CSTRING("canvas")) return canvas;
	if (inName==HX_CSTRING("img")) return img;
	if (inName==HX_CSTRING("input")) return input;
	if (inName==HX_CSTRING("script")) return script;
	if (inName==HX_CSTRING("semantic")) return semantic_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("canvas"),
	HX_CSTRING("img"),
	HX_CSTRING("script"),
	HX_CSTRING("anchor"),
	HX_CSTRING("input"),
	HX_CSTRING("semantic"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::anchor,"anchor");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::canvas,"canvas");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::img,"img");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::input,"input");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::script,"script");
};

static ::String sMemberFields[] = { ::String(null()) };
Class NativeElementTypeValue_obj::__mClass;

Dynamic __Create_NativeElementTypeValue_obj() { return new NativeElementTypeValue_obj; }

void NativeElementTypeValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.nativeElement.NativeElementTypeValue"), hx::TCanCast< NativeElementTypeValue_obj >,sStaticFields,sMemberFields,
	&__Create_NativeElementTypeValue_obj, &__Create,
	&super::__SGetClass(), &CreateNativeElementTypeValue_obj, sMarkStatics);
}

void NativeElementTypeValue_obj::__boot()
{
Static(anchor) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("anchor"),3);
Static(canvas) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("canvas"),0);
Static(img) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("img"),1);
Static(input) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("input"),4);
Static(script) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("script"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement
