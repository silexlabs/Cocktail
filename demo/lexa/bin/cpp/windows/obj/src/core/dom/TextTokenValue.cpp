#include <hxcpp.h>

#ifndef INCLUDED_core_dom_TextTokenValue
#include <core/dom/TextTokenValue.h>
#endif
namespace core{
namespace dom{

::core::dom::TextTokenValue TextTokenValue_obj::lineFeed;

::core::dom::TextTokenValue TextTokenValue_obj::space;

::core::dom::TextTokenValue TextTokenValue_obj::tab;

::core::dom::TextTokenValue  TextTokenValue_obj::word(::String value)
	{ return hx::CreateEnum< TextTokenValue_obj >(HX_CSTRING("word"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(TextTokenValue_obj)

int TextTokenValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("lineFeed")) return 3;
	if (inName==HX_CSTRING("space")) return 1;
	if (inName==HX_CSTRING("tab")) return 2;
	if (inName==HX_CSTRING("word")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextTokenValue_obj,word,return)

int TextTokenValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("lineFeed")) return 0;
	if (inName==HX_CSTRING("space")) return 0;
	if (inName==HX_CSTRING("tab")) return 0;
	if (inName==HX_CSTRING("word")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic TextTokenValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("lineFeed")) return lineFeed;
	if (inName==HX_CSTRING("space")) return space;
	if (inName==HX_CSTRING("tab")) return tab;
	if (inName==HX_CSTRING("word")) return word_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("word"),
	HX_CSTRING("space"),
	HX_CSTRING("tab"),
	HX_CSTRING("lineFeed"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextTokenValue_obj::lineFeed,"lineFeed");
	HX_MARK_MEMBER_NAME(TextTokenValue_obj::space,"space");
	HX_MARK_MEMBER_NAME(TextTokenValue_obj::tab,"tab");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextTokenValue_obj::__mClass;

Dynamic __Create_TextTokenValue_obj() { return new TextTokenValue_obj; }

void TextTokenValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.TextTokenValue"), hx::TCanCast< TextTokenValue_obj >,sStaticFields,sMemberFields,
	&__Create_TextTokenValue_obj, &__Create,
	&super::__SGetClass(), &CreateTextTokenValue_obj, sMarkStatics);
}

void TextTokenValue_obj::__boot()
{
Static(lineFeed) = hx::CreateEnum< TextTokenValue_obj >(HX_CSTRING("lineFeed"),3);
Static(space) = hx::CreateEnum< TextTokenValue_obj >(HX_CSTRING("space"),1);
Static(tab) = hx::CreateEnum< TextTokenValue_obj >(HX_CSTRING("tab"),2);
}


} // end namespace core
} // end namespace dom
