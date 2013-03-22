#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_renderer_TextToken
#include <cocktail/core/renderer/TextToken.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

::cocktail::core::renderer::TextToken TextToken_obj::lineFeed;

::cocktail::core::renderer::TextToken TextToken_obj::space;

::cocktail::core::renderer::TextToken TextToken_obj::tab;

::cocktail::core::renderer::TextToken  TextToken_obj::word(::String value)
	{ return hx::CreateEnum< TextToken_obj >(HX_CSTRING("word"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(TextToken_obj)

int TextToken_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("lineFeed")) return 3;
	if (inName==HX_CSTRING("space")) return 1;
	if (inName==HX_CSTRING("tab")) return 2;
	if (inName==HX_CSTRING("word")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextToken_obj,word,return)

int TextToken_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("lineFeed")) return 0;
	if (inName==HX_CSTRING("space")) return 0;
	if (inName==HX_CSTRING("tab")) return 0;
	if (inName==HX_CSTRING("word")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic TextToken_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("lineFeed")) return lineFeed;
	if (inName==HX_CSTRING("space")) return space;
	if (inName==HX_CSTRING("tab")) return tab;
	if (inName==HX_CSTRING("word")) return word_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("word"),
	HX_CSTRING("space"),
	HX_CSTRING("tab"),
	HX_CSTRING("lineFeed"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextToken_obj::lineFeed,"lineFeed");
	HX_MARK_MEMBER_NAME(TextToken_obj::space,"space");
	HX_MARK_MEMBER_NAME(TextToken_obj::tab,"tab");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextToken_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextToken_obj::lineFeed,"lineFeed");
	HX_VISIT_MEMBER_NAME(TextToken_obj::space,"space");
	HX_VISIT_MEMBER_NAME(TextToken_obj::tab,"tab");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextToken_obj::__mClass;

Dynamic __Create_TextToken_obj() { return new TextToken_obj; }

void TextToken_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.TextToken"), hx::TCanCast< TextToken_obj >,sStaticFields,sMemberFields,
	&__Create_TextToken_obj, &__Create,
	&super::__SGetClass(), &CreateTextToken_obj, sMarkStatics, sVisitStatic);
}

void TextToken_obj::__boot()
{
Static(lineFeed) = hx::CreateEnum< TextToken_obj >(HX_CSTRING("lineFeed"),3);
Static(space) = hx::CreateEnum< TextToken_obj >(HX_CSTRING("space"),1);
Static(tab) = hx::CreateEnum< TextToken_obj >(HX_CSTRING("tab"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace renderer
