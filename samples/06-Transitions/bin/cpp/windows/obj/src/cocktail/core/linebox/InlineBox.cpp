#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
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
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace linebox{

Void InlineBox_obj::__construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent)
{
HX_STACK_PUSH("InlineBox::new","cocktail/core/linebox/InlineBox.hx",107);
{
	HX_STACK_LINE(108)
	super::__construct();
	HX_STACK_LINE(110)
	this->isSpace = false;
	HX_STACK_LINE(111)
	this->isText = false;
	HX_STACK_LINE(112)
	this->isEmbedded = false;
	HX_STACK_LINE(113)
	this->isLineFeed = false;
	HX_STACK_LINE(115)
	this->bounds = ::cocktail::core::geom::RectangleVO_obj::__new();
	HX_STACK_LINE(116)
	this->offsetFromParentInlineBox = ::cocktail::core::geom::PointVO_obj::__new((int)0,(int)0);
	HX_STACK_LINE(118)
	this->elementRenderer = elementRenderer;
	HX_STACK_LINE(120)
	this->marginLeft = (int)0;
	HX_STACK_LINE(121)
	this->marginRight = (int)0;
	HX_STACK_LINE(122)
	this->paddingLeft = (int)0;
	HX_STACK_LINE(123)
	this->paddingRight = (int)0;
	HX_STACK_LINE(124)
	this->borderLeft = (int)0;
	HX_STACK_LINE(125)
	this->borderRight = (int)0;
	HX_STACK_LINE(127)
	this->leadedAscent = leadedAscent;
	HX_STACK_LINE(128)
	this->leadedDescent = leadedDescent;
}
;
	return null();
}

InlineBox_obj::~InlineBox_obj() { }

Dynamic InlineBox_obj::__CreateEmpty() { return  new InlineBox_obj; }
hx::ObjectPtr< InlineBox_obj > InlineBox_obj::__new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent)
{  hx::ObjectPtr< InlineBox_obj > result = new InlineBox_obj();
	result->__construct(elementRenderer,leadedAscent,leadedDescent);
	return result;}

Dynamic InlineBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineBox_obj > result = new InlineBox_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void InlineBox_obj::dispose( ){
{
		HX_STACK_PUSH("InlineBox::dispose","cocktail/core/linebox/InlineBox.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_LINE(135)
		this->elementRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineBox_obj,dispose,(void))


InlineBox_obj::InlineBox_obj()
{
}

void InlineBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineBox);
	HX_MARK_MEMBER_NAME(offsetFromParentInlineBox,"offsetFromParentInlineBox");
	HX_MARK_MEMBER_NAME(lineBox,"lineBox");
	HX_MARK_MEMBER_NAME(borderRight,"borderRight");
	HX_MARK_MEMBER_NAME(borderLeft,"borderLeft");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(leadedDescent,"leadedDescent");
	HX_MARK_MEMBER_NAME(leadedAscent,"leadedAscent");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(elementRenderer,"elementRenderer");
	HX_MARK_MEMBER_NAME(isLineFeed,"isLineFeed");
	HX_MARK_MEMBER_NAME(isEmbedded,"isEmbedded");
	HX_MARK_MEMBER_NAME(isSpace,"isSpace");
	HX_MARK_MEMBER_NAME(isText,"isText");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InlineBox_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(offsetFromParentInlineBox,"offsetFromParentInlineBox");
	HX_VISIT_MEMBER_NAME(lineBox,"lineBox");
	HX_VISIT_MEMBER_NAME(borderRight,"borderRight");
	HX_VISIT_MEMBER_NAME(borderLeft,"borderLeft");
	HX_VISIT_MEMBER_NAME(paddingRight,"paddingRight");
	HX_VISIT_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_VISIT_MEMBER_NAME(marginRight,"marginRight");
	HX_VISIT_MEMBER_NAME(marginLeft,"marginLeft");
	HX_VISIT_MEMBER_NAME(leadedDescent,"leadedDescent");
	HX_VISIT_MEMBER_NAME(leadedAscent,"leadedAscent");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(elementRenderer,"elementRenderer");
	HX_VISIT_MEMBER_NAME(isLineFeed,"isLineFeed");
	HX_VISIT_MEMBER_NAME(isEmbedded,"isEmbedded");
	HX_VISIT_MEMBER_NAME(isSpace,"isSpace");
	HX_VISIT_MEMBER_NAME(isText,"isText");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InlineBox_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		if (HX_FIELD_EQ(inName,"isText") ) { return isText; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"lineBox") ) { return lineBox; }
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"borderLeft") ) { return borderLeft; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return marginLeft; }
		if (HX_FIELD_EQ(inName,"isLineFeed") ) { return isLineFeed; }
		if (HX_FIELD_EQ(inName,"isEmbedded") ) { return isEmbedded; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderRight") ) { return borderRight; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return paddingLeft; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return marginRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return paddingRight; }
		if (HX_FIELD_EQ(inName,"leadedAscent") ) { return leadedAscent; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"leadedDescent") ) { return leadedDescent; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { return elementRenderer; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"offsetFromParentInlineBox") ) { return offsetFromParentInlineBox; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InlineBox_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isText") ) { isText=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"lineBox") ) { lineBox=inValue.Cast< ::cocktail::core::linebox::LineBox >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isSpace") ) { isSpace=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"borderLeft") ) { borderLeft=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { marginLeft=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isLineFeed") ) { isLineFeed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isEmbedded") ) { isEmbedded=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"borderRight") ) { borderRight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { paddingLeft=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { marginRight=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"paddingRight") ) { paddingRight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"leadedAscent") ) { leadedAscent=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"leadedDescent") ) { leadedDescent=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { elementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"offsetFromParentInlineBox") ) { offsetFromParentInlineBox=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InlineBox_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("offsetFromParentInlineBox"));
	outFields->push(HX_CSTRING("lineBox"));
	outFields->push(HX_CSTRING("borderRight"));
	outFields->push(HX_CSTRING("borderLeft"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("leadedDescent"));
	outFields->push(HX_CSTRING("leadedAscent"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("elementRenderer"));
	outFields->push(HX_CSTRING("isLineFeed"));
	outFields->push(HX_CSTRING("isEmbedded"));
	outFields->push(HX_CSTRING("isSpace"));
	outFields->push(HX_CSTRING("isText"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("offsetFromParentInlineBox"),
	HX_CSTRING("lineBox"),
	HX_CSTRING("borderRight"),
	HX_CSTRING("borderLeft"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("leadedDescent"),
	HX_CSTRING("leadedAscent"),
	HX_CSTRING("bounds"),
	HX_CSTRING("elementRenderer"),
	HX_CSTRING("isLineFeed"),
	HX_CSTRING("isEmbedded"),
	HX_CSTRING("isSpace"),
	HX_CSTRING("isText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InlineBox_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InlineBox_obj::__mClass,"__mClass");
};

Class InlineBox_obj::__mClass;

void InlineBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.linebox.InlineBox"), hx::TCanCast< InlineBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InlineBox_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace linebox
