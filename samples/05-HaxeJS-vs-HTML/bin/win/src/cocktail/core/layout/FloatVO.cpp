#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_FloatVO
#include <cocktail/core/layout/FloatVO.h>
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
namespace layout{

Void FloatVO_obj::__construct(::cocktail::core::renderer::ElementRenderer node,::cocktail::core::geom::RectangleVO bounds)
{
HX_STACK_PUSH("FloatVO::new","cocktail/core/layout/LayoutData.hx",174);
{
	HX_STACK_LINE(175)
	this->node = node;
	HX_STACK_LINE(176)
	this->bounds = bounds;
}
;
	return null();
}

FloatVO_obj::~FloatVO_obj() { }

Dynamic FloatVO_obj::__CreateEmpty() { return  new FloatVO_obj; }
hx::ObjectPtr< FloatVO_obj > FloatVO_obj::__new(::cocktail::core::renderer::ElementRenderer node,::cocktail::core::geom::RectangleVO bounds)
{  hx::ObjectPtr< FloatVO_obj > result = new FloatVO_obj();
	result->__construct(node,bounds);
	return result;}

Dynamic FloatVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatVO_obj > result = new FloatVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


FloatVO_obj::FloatVO_obj()
{
}

void FloatVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatVO);
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(node,"node");
	HX_MARK_END_CLASS();
}

void FloatVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(node,"node");
}

Dynamic FloatVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { return node; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { node=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("node"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bounds"),
	HX_CSTRING("node"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatVO_obj::__mClass,"__mClass");
};

Class FloatVO_obj::__mClass;

void FloatVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.FloatVO"), hx::TCanCast< FloatVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FloatVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
