#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void UsedValuesVO_obj::__construct()
{
HX_STACK_PUSH("UsedValuesVO::new","cocktail/core/css/CSSData.hx",185);
{
	HX_STACK_LINE(186)
	this->minHeight = 0.0;
	HX_STACK_LINE(187)
	this->maxHeight = 0.0;
	HX_STACK_LINE(188)
	this->minWidth = 0.0;
	HX_STACK_LINE(189)
	this->maxWidth = 0.0;
	HX_STACK_LINE(190)
	this->width = 0.0;
	HX_STACK_LINE(191)
	this->height = 0.0;
	HX_STACK_LINE(192)
	this->marginLeft = 0.0;
	HX_STACK_LINE(193)
	this->marginRight = 0.0;
	HX_STACK_LINE(194)
	this->marginTop = 0.0;
	HX_STACK_LINE(195)
	this->marginBottom = 0.0;
	HX_STACK_LINE(196)
	this->paddingLeft = 0.0;
	HX_STACK_LINE(197)
	this->paddingRight = 0.0;
	HX_STACK_LINE(198)
	this->paddingTop = 0.0;
	HX_STACK_LINE(199)
	this->paddingBottom = 0.0;
	HX_STACK_LINE(200)
	this->left = 0.0;
	HX_STACK_LINE(201)
	this->right = 0.0;
	HX_STACK_LINE(202)
	this->top = 0.0;
	HX_STACK_LINE(203)
	this->bottom = 0.0;
	HX_STACK_LINE(204)
	this->textIndent = (int)0;
	HX_STACK_LINE(205)
	this->lineHeight = 0.0;
	HX_STACK_LINE(206)
	this->letterSpacing = 0.0;
	HX_STACK_LINE(207)
	this->color = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
	HX_STACK_LINE(208)
	this->transformOrigin = ::cocktail::core::geom::PointVO_obj::__new(0.0,0.0);
	HX_STACK_LINE(209)
	this->transform = ::cocktail::core::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(210)
	this->backgroundColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,0.0);
	HX_STACK_LINE(211)
	this->borderLeftWidth = 0.0;
	HX_STACK_LINE(212)
	this->borderRightWidth = 0.0;
	HX_STACK_LINE(213)
	this->borderTopWidth = 0.0;
	HX_STACK_LINE(214)
	this->borderBottomWidth = 0.0;
	HX_STACK_LINE(215)
	this->borderLeftColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
	HX_STACK_LINE(216)
	this->borderRightColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
	HX_STACK_LINE(217)
	this->borderTopColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
	HX_STACK_LINE(218)
	this->borderBottomColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
	HX_STACK_LINE(219)
	this->outlineWidth = 0.0;
	HX_STACK_LINE(220)
	this->outlineColor = ::cocktail::core::css::ColorVO_obj::__new((int)0,1.0);
}
;
	return null();
}

UsedValuesVO_obj::~UsedValuesVO_obj() { }

Dynamic UsedValuesVO_obj::__CreateEmpty() { return  new UsedValuesVO_obj; }
hx::ObjectPtr< UsedValuesVO_obj > UsedValuesVO_obj::__new()
{  hx::ObjectPtr< UsedValuesVO_obj > result = new UsedValuesVO_obj();
	result->__construct();
	return result;}

Dynamic UsedValuesVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UsedValuesVO_obj > result = new UsedValuesVO_obj();
	result->__construct();
	return result;}


UsedValuesVO_obj::UsedValuesVO_obj()
{
}

void UsedValuesVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UsedValuesVO);
	HX_MARK_MEMBER_NAME(outlineColor,"outlineColor");
	HX_MARK_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_MARK_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_MARK_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_MARK_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_MARK_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_MARK_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_MARK_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_MARK_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_MARK_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(lineHeight,"lineHeight");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(textIndent,"textIndent");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_MARK_MEMBER_NAME(paddingTop,"paddingTop");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(marginBottom,"marginBottom");
	HX_MARK_MEMBER_NAME(marginTop,"marginTop");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(minWidth,"minWidth");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(minHeight,"minHeight");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void UsedValuesVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(outlineColor,"outlineColor");
	HX_VISIT_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_VISIT_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_VISIT_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_VISIT_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_VISIT_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_VISIT_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_VISIT_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_VISIT_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_VISIT_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_VISIT_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_VISIT_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_VISIT_MEMBER_NAME(lineHeight,"lineHeight");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(textIndent,"textIndent");
	HX_VISIT_MEMBER_NAME(bottom,"bottom");
	HX_VISIT_MEMBER_NAME(top,"top");
	HX_VISIT_MEMBER_NAME(right,"right");
	HX_VISIT_MEMBER_NAME(left,"left");
	HX_VISIT_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_VISIT_MEMBER_NAME(paddingTop,"paddingTop");
	HX_VISIT_MEMBER_NAME(paddingRight,"paddingRight");
	HX_VISIT_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_VISIT_MEMBER_NAME(marginBottom,"marginBottom");
	HX_VISIT_MEMBER_NAME(marginTop,"marginTop");
	HX_VISIT_MEMBER_NAME(marginRight,"marginRight");
	HX_VISIT_MEMBER_NAME(marginLeft,"marginLeft");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(maxWidth,"maxWidth");
	HX_VISIT_MEMBER_NAME(minWidth,"minWidth");
	HX_VISIT_MEMBER_NAME(maxHeight,"maxHeight");
	HX_VISIT_MEMBER_NAME(minHeight,"minHeight");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic UsedValuesVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"right") ) { return right; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { return bottom; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return maxWidth; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return minWidth; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return marginTop; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return maxHeight; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return minHeight; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return lineHeight; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return textIndent; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return paddingTop; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return marginLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return paddingLeft; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return marginRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"outlineColor") ) { return outlineColor; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { return outlineWidth; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return paddingRight; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return marginBottom; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return letterSpacing; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return paddingBottom; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { return borderTopColor; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { return borderTopWidth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { return borderLeftColor; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { return borderLeftWidth; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return backgroundColor; }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return transformOrigin; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { return borderRightColor; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { return borderRightWidth; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { return borderBottomColor; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { return borderBottomWidth; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UsedValuesVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { top=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { left=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { right=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bottom") ) { bottom=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxWidth") ) { maxWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { minWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::cocktail::core::geom::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { marginTop=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { maxHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { minHeight=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lineHeight") ) { lineHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { textIndent=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { paddingTop=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { marginLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { paddingLeft=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { marginRight=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"outlineColor") ) { outlineColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { outlineWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { paddingRight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { marginBottom=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { letterSpacing=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { paddingBottom=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { borderTopColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { borderTopWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { borderLeftColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { borderLeftWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { backgroundColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { transformOrigin=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { borderRightColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { borderRightWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { borderBottomColor=inValue.Cast< ::cocktail::core::css::ColorVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { borderBottomWidth=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UsedValuesVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("outlineColor"));
	outFields->push(HX_CSTRING("outlineWidth"));
	outFields->push(HX_CSTRING("borderLeftColor"));
	outFields->push(HX_CSTRING("borderBottomColor"));
	outFields->push(HX_CSTRING("borderRightColor"));
	outFields->push(HX_CSTRING("borderTopColor"));
	outFields->push(HX_CSTRING("borderBottomWidth"));
	outFields->push(HX_CSTRING("borderTopWidth"));
	outFields->push(HX_CSTRING("borderRightWidth"));
	outFields->push(HX_CSTRING("borderLeftWidth"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("transformOrigin"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("lineHeight"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("textIndent"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("paddingBottom"));
	outFields->push(HX_CSTRING("paddingTop"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("marginBottom"));
	outFields->push(HX_CSTRING("marginTop"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("minWidth"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("minHeight"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("outlineColor"),
	HX_CSTRING("outlineWidth"),
	HX_CSTRING("borderLeftColor"),
	HX_CSTRING("borderBottomColor"),
	HX_CSTRING("borderRightColor"),
	HX_CSTRING("borderTopColor"),
	HX_CSTRING("borderBottomWidth"),
	HX_CSTRING("borderTopWidth"),
	HX_CSTRING("borderRightWidth"),
	HX_CSTRING("borderLeftWidth"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("transform"),
	HX_CSTRING("transformOrigin"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("lineHeight"),
	HX_CSTRING("color"),
	HX_CSTRING("textIndent"),
	HX_CSTRING("bottom"),
	HX_CSTRING("top"),
	HX_CSTRING("right"),
	HX_CSTRING("left"),
	HX_CSTRING("paddingBottom"),
	HX_CSTRING("paddingTop"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("marginBottom"),
	HX_CSTRING("marginTop"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("height"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("minWidth"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("minHeight"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UsedValuesVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UsedValuesVO_obj::__mClass,"__mClass");
};

Class UsedValuesVO_obj::__mClass;

void UsedValuesVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.UsedValuesVO"), hx::TCanCast< UsedValuesVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void UsedValuesVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
