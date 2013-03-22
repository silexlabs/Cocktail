#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_linebox_EmbeddedInlineBox
#include <cocktail/core/linebox/EmbeddedInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace linebox{

Void EmbeddedInlineBox_obj::__construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent)
{
HX_STACK_PUSH("EmbeddedInlineBox::new","cocktail/core/linebox/EmbeddedInlineBox.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct(elementRenderer,leadedAscent,leadedDescent);
	HX_STACK_LINE(25)
	this->isEmbedded = true;
}
;
	return null();
}

EmbeddedInlineBox_obj::~EmbeddedInlineBox_obj() { }

Dynamic EmbeddedInlineBox_obj::__CreateEmpty() { return  new EmbeddedInlineBox_obj; }
hx::ObjectPtr< EmbeddedInlineBox_obj > EmbeddedInlineBox_obj::__new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent)
{  hx::ObjectPtr< EmbeddedInlineBox_obj > result = new EmbeddedInlineBox_obj();
	result->__construct(elementRenderer,leadedAscent,leadedDescent);
	return result;}

Dynamic EmbeddedInlineBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedInlineBox_obj > result = new EmbeddedInlineBox_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


EmbeddedInlineBox_obj::EmbeddedInlineBox_obj()
{
}

void EmbeddedInlineBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedInlineBox);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedInlineBox_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedInlineBox_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedInlineBox_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedInlineBox_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedInlineBox_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedInlineBox_obj::__mClass,"__mClass");
};

Class EmbeddedInlineBox_obj::__mClass;

void EmbeddedInlineBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.linebox.EmbeddedInlineBox"), hx::TCanCast< EmbeddedInlineBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedInlineBox_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace linebox
