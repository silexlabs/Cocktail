#include <hxcpp.h>

#ifndef INCLUDED_core_nativeElement_NativeElementTypeValue
#include <core/nativeElement/NativeElementTypeValue.h>
#endif
namespace core{
namespace nativeElement{

::core::nativeElement::NativeElementTypeValue  NativeElementTypeValue_obj::custom(::String name)
	{ return hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("custom"),8,hx::DynamicArray(0,1).Add(name)); }

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::graphic;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::image;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::library;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::link;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::neutral;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::skin;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::text;

::core::nativeElement::NativeElementTypeValue NativeElementTypeValue_obj::textInput;

HX_DEFINE_CREATE_ENUM(NativeElementTypeValue_obj)

int NativeElementTypeValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("custom")) return 8;
	if (inName==HX_CSTRING("graphic")) return 1;
	if (inName==HX_CSTRING("image")) return 3;
	if (inName==HX_CSTRING("library")) return 4;
	if (inName==HX_CSTRING("link")) return 6;
	if (inName==HX_CSTRING("neutral")) return 0;
	if (inName==HX_CSTRING("skin")) return 5;
	if (inName==HX_CSTRING("text")) return 2;
	if (inName==HX_CSTRING("textInput")) return 7;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(NativeElementTypeValue_obj,custom,return)

int NativeElementTypeValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("custom")) return 1;
	if (inName==HX_CSTRING("graphic")) return 0;
	if (inName==HX_CSTRING("image")) return 0;
	if (inName==HX_CSTRING("library")) return 0;
	if (inName==HX_CSTRING("link")) return 0;
	if (inName==HX_CSTRING("neutral")) return 0;
	if (inName==HX_CSTRING("skin")) return 0;
	if (inName==HX_CSTRING("text")) return 0;
	if (inName==HX_CSTRING("textInput")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic NativeElementTypeValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("custom")) return custom_dyn();
	if (inName==HX_CSTRING("graphic")) return graphic;
	if (inName==HX_CSTRING("image")) return image;
	if (inName==HX_CSTRING("library")) return library;
	if (inName==HX_CSTRING("link")) return link;
	if (inName==HX_CSTRING("neutral")) return neutral;
	if (inName==HX_CSTRING("skin")) return skin;
	if (inName==HX_CSTRING("text")) return text;
	if (inName==HX_CSTRING("textInput")) return textInput;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("neutral"),
	HX_CSTRING("graphic"),
	HX_CSTRING("text"),
	HX_CSTRING("image"),
	HX_CSTRING("library"),
	HX_CSTRING("skin"),
	HX_CSTRING("link"),
	HX_CSTRING("textInput"),
	HX_CSTRING("custom"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::graphic,"graphic");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::image,"image");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::library,"library");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::link,"link");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::neutral,"neutral");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::skin,"skin");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::text,"text");
	HX_MARK_MEMBER_NAME(NativeElementTypeValue_obj::textInput,"textInput");
};

static ::String sMemberFields[] = { ::String(null()) };
Class NativeElementTypeValue_obj::__mClass;

Dynamic __Create_NativeElementTypeValue_obj() { return new NativeElementTypeValue_obj; }

void NativeElementTypeValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.nativeElement.NativeElementTypeValue"), hx::TCanCast< NativeElementTypeValue_obj >,sStaticFields,sMemberFields,
	&__Create_NativeElementTypeValue_obj, &__Create,
	&super::__SGetClass(), &CreateNativeElementTypeValue_obj, sMarkStatics);
}

void NativeElementTypeValue_obj::__boot()
{
Static(graphic) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("graphic"),1);
Static(image) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("image"),3);
Static(library) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("library"),4);
Static(link) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("link"),6);
Static(neutral) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("neutral"),0);
Static(skin) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("skin"),5);
Static(text) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("text"),2);
Static(textInput) = hx::CreateEnum< NativeElementTypeValue_obj >(HX_CSTRING("textInput"),7);
}


} // end namespace core
} // end namespace nativeElement
