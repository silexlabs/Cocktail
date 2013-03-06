#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InLineBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void InLineBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("InLineBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct();
}
;
	return null();
}

InLineBoxStylesComputer_obj::~InLineBoxStylesComputer_obj() { }

Dynamic InLineBoxStylesComputer_obj::__CreateEmpty() { return  new InLineBoxStylesComputer_obj; }
hx::ObjectPtr< InLineBoxStylesComputer_obj > InLineBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< InLineBoxStylesComputer_obj > result = new InLineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic InLineBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InLineBoxStylesComputer_obj > result = new InLineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float InLineBoxStylesComputer_obj::getComputedHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("InLineBoxStylesComputer::getComputedHeight","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(84)
	return 0.0;
}


Float InLineBoxStylesComputer_obj::getComputedWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("InLineBoxStylesComputer::getComputedWidth","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(76)
	return 0.0;
}


Float InLineBoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin){
	HX_STACK_PUSH("InLineBoxStylesComputer::getComputedAutoMargin","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_ARG(marginStyleValue,"marginStyleValue");
	HX_STACK_ARG(opositeMargin,"opositeMargin");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(computedDimension,"computedDimension");
	HX_STACK_ARG(isDimensionAuto,"isDimensionAuto");
	HX_STACK_ARG(computedPaddingsAndBordersDimension,"computedPaddingsAndBordersDimension");
	HX_STACK_ARG(isHorizontalMargin,"isHorizontalMargin");
	HX_STACK_LINE(68)
	return 0.0;
}


Float InLineBoxStylesComputer_obj::measureHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("InLineBoxStylesComputer::measureHeight","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(54)
	Float computedHeight = this->getComputedHeight(style,containingBlockData);		HX_STACK_VAR(computedHeight,"computedHeight");
	HX_STACK_LINE(57)
	style->usedValues->marginTop = 0.0;
	HX_STACK_LINE(59)
	style->usedValues->marginBottom = 0.0;
	HX_STACK_LINE(61)
	return computedHeight;
}


Float InLineBoxStylesComputer_obj::measureAutoHeight( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("InLineBoxStylesComputer::measureAutoHeight","cocktail/core/layout/computer/boxComputers/InLineBoxStylesComputer.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(38)
	Float computedHeight = this->getComputedAutoHeight(style,containingBlockData);		HX_STACK_VAR(computedHeight,"computedHeight");
	HX_STACK_LINE(41)
	style->usedValues->marginTop = 0.0;
	HX_STACK_LINE(43)
	style->usedValues->marginBottom = 0.0;
	HX_STACK_LINE(45)
	return computedHeight;
}



InLineBoxStylesComputer_obj::InLineBoxStylesComputer_obj()
{
}

void InLineBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InLineBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InLineBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InLineBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getComputedWidth") ) { return getComputedWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getComputedHeight") ) { return getComputedHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InLineBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InLineBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedHeight"),
	HX_CSTRING("getComputedWidth"),
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("measureAutoHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InLineBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InLineBoxStylesComputer_obj::__mClass,"__mClass");
};

Class InLineBoxStylesComputer_obj::__mClass;

void InLineBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.InLineBoxStylesComputer"), hx::TCanCast< InLineBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InLineBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
