#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void EmbeddedInlineBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("EmbeddedInlineBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct();
}
;
	return null();
}

EmbeddedInlineBoxStylesComputer_obj::~EmbeddedInlineBoxStylesComputer_obj() { }

Dynamic EmbeddedInlineBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedInlineBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedInlineBoxStylesComputer_obj > EmbeddedInlineBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedInlineBoxStylesComputer_obj > result = new EmbeddedInlineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedInlineBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedInlineBoxStylesComputer_obj > result = new EmbeddedInlineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float EmbeddedInlineBoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::css::CSSPropertyValue marginStyleValue,::cocktail::core::css::CSSPropertyValue opositeMargin,Float containingHTMLElementDimension,Float computedDimension,bool isDimensionAuto,Float computedPaddingsAndBordersDimension,bool isHorizontalMargin){
	HX_STACK_PUSH("EmbeddedInlineBoxStylesComputer::getComputedAutoMargin","cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_ARG(marginStyleValue,"marginStyleValue");
	HX_STACK_ARG(opositeMargin,"opositeMargin");
	HX_STACK_ARG(containingHTMLElementDimension,"containingHTMLElementDimension");
	HX_STACK_ARG(computedDimension,"computedDimension");
	HX_STACK_ARG(isDimensionAuto,"isDimensionAuto");
	HX_STACK_ARG(computedPaddingsAndBordersDimension,"computedPaddingsAndBordersDimension");
	HX_STACK_ARG(isHorizontalMargin,"isHorizontalMargin");
	HX_STACK_LINE(36)
	return 0.0;
}



EmbeddedInlineBoxStylesComputer_obj::EmbeddedInlineBoxStylesComputer_obj()
{
}

void EmbeddedInlineBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedInlineBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EmbeddedInlineBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedInlineBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedInlineBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void EmbeddedInlineBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedAutoMargin"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EmbeddedInlineBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedInlineBoxStylesComputer_obj::__mClass,"__mClass");
};

Class EmbeddedInlineBoxStylesComputer_obj::__mClass;

void EmbeddedInlineBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.EmbeddedInlineBoxStylesComputer"), hx::TCanCast< EmbeddedInlineBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedInlineBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
