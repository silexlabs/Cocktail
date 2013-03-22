#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_SpaceInlineBox
#include <cocktail/core/linebox/SpaceInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace linebox{

Void SpaceInlineBox_obj::__construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,Float spaceWidth)
{
HX_STACK_PUSH("SpaceInlineBox::new","cocktail/core/linebox/SpaceInlineBox.hx",36);
{
	HX_STACK_LINE(37)
	super::__construct(elementRenderer,leadedAscent,leadedDescent);
	HX_STACK_LINE(39)
	this->bounds->width = spaceWidth;
	HX_STACK_LINE(40)
	this->bounds->height = (leadedAscent + leadedDescent);
	HX_STACK_LINE(42)
	this->isSpace = true;
	HX_STACK_LINE(43)
	this->isText = true;
}
;
	return null();
}

SpaceInlineBox_obj::~SpaceInlineBox_obj() { }

Dynamic SpaceInlineBox_obj::__CreateEmpty() { return  new SpaceInlineBox_obj; }
hx::ObjectPtr< SpaceInlineBox_obj > SpaceInlineBox_obj::__new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,Float spaceWidth)
{  hx::ObjectPtr< SpaceInlineBox_obj > result = new SpaceInlineBox_obj();
	result->__construct(elementRenderer,leadedAscent,leadedDescent,spaceWidth);
	return result;}

Dynamic SpaceInlineBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpaceInlineBox_obj > result = new SpaceInlineBox_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


SpaceInlineBox_obj::SpaceInlineBox_obj()
{
}

void SpaceInlineBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpaceInlineBox);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SpaceInlineBox_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SpaceInlineBox_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic SpaceInlineBox_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SpaceInlineBox_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpaceInlineBox_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpaceInlineBox_obj::__mClass,"__mClass");
};

Class SpaceInlineBox_obj::__mClass;

void SpaceInlineBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.linebox.SpaceInlineBox"), hx::TCanCast< SpaceInlineBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpaceInlineBox_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace linebox
