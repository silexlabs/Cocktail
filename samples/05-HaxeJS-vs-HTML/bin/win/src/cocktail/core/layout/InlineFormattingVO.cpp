#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_InlineFormattingVO
#include <cocktail/core/layout/InlineFormattingVO.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_LineBox
#include <cocktail/core/linebox/LineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace layout{

Void InlineFormattingVO_obj::__construct()
{
HX_STACK_PUSH("InlineFormattingVO::new","cocktail/core/layout/LayoutData.hx",146);
{
}
;
	return null();
}

InlineFormattingVO_obj::~InlineFormattingVO_obj() { }

Dynamic InlineFormattingVO_obj::__CreateEmpty() { return  new InlineFormattingVO_obj; }
hx::ObjectPtr< InlineFormattingVO_obj > InlineFormattingVO_obj::__new()
{  hx::ObjectPtr< InlineFormattingVO_obj > result = new InlineFormattingVO_obj();
	result->__construct();
	return result;}

Dynamic InlineFormattingVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineFormattingVO_obj > result = new InlineFormattingVO_obj();
	result->__construct();
	return result;}


InlineFormattingVO_obj::InlineFormattingVO_obj()
{
}

void InlineFormattingVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineFormattingVO);
	HX_MARK_MEMBER_NAME(lineBoxPosition,"lineBoxPosition");
	HX_MARK_MEMBER_NAME(openedElementRenderers,"openedElementRenderers");
	HX_MARK_MEMBER_NAME(inlineBox,"inlineBox");
	HX_MARK_MEMBER_NAME(lineBox,"lineBox");
	HX_MARK_END_CLASS();
}

void InlineFormattingVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lineBoxPosition,"lineBoxPosition");
	HX_VISIT_MEMBER_NAME(openedElementRenderers,"openedElementRenderers");
	HX_VISIT_MEMBER_NAME(inlineBox,"inlineBox");
	HX_VISIT_MEMBER_NAME(lineBox,"lineBox");
}

Dynamic InlineFormattingVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"lineBox") ) { return lineBox; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"inlineBox") ) { return inlineBox; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"lineBoxPosition") ) { return lineBoxPosition; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"openedElementRenderers") ) { return openedElementRenderers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InlineFormattingVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"lineBox") ) { lineBox=inValue.Cast< ::cocktail::core::linebox::LineBox >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"inlineBox") ) { inlineBox=inValue.Cast< ::cocktail::core::linebox::InlineBox >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"lineBoxPosition") ) { lineBoxPosition=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"openedElementRenderers") ) { openedElementRenderers=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InlineFormattingVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lineBoxPosition"));
	outFields->push(HX_CSTRING("openedElementRenderers"));
	outFields->push(HX_CSTRING("inlineBox"));
	outFields->push(HX_CSTRING("lineBox"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("lineBoxPosition"),
	HX_CSTRING("openedElementRenderers"),
	HX_CSTRING("inlineBox"),
	HX_CSTRING("lineBox"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InlineFormattingVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InlineFormattingVO_obj::__mClass,"__mClass");
};

Class InlineFormattingVO_obj::__mClass;

void InlineFormattingVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.InlineFormattingVO"), hx::TCanCast< InlineFormattingVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InlineFormattingVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
