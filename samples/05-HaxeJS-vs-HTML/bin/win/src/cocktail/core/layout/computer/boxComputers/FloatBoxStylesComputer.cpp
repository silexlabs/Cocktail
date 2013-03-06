#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_FloatBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/FloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_InlineBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void FloatBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("FloatBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/FloatBoxStylesComputer.hx",27);
{
	HX_STACK_LINE(27)
	super::__construct();
}
;
	return null();
}

FloatBoxStylesComputer_obj::~FloatBoxStylesComputer_obj() { }

Dynamic FloatBoxStylesComputer_obj::__CreateEmpty() { return  new FloatBoxStylesComputer_obj; }
hx::ObjectPtr< FloatBoxStylesComputer_obj > FloatBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< FloatBoxStylesComputer_obj > result = new FloatBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic FloatBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatBoxStylesComputer_obj > result = new FloatBoxStylesComputer_obj();
	result->__construct();
	return result;}

Float FloatBoxStylesComputer_obj::getComputedAutoWidth( ::cocktail::core::css::CoreStyle style,::cocktail::core::layout::ContainingBlockVO containingBlockData){
	HX_STACK_PUSH("FloatBoxStylesComputer::getComputedAutoWidth","cocktail/core/layout/computer/boxComputers/FloatBoxStylesComputer.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(containingBlockData,"containingBlockData");
	HX_STACK_LINE(36)
	return 0.0;
}



FloatBoxStylesComputer_obj::FloatBoxStylesComputer_obj()
{
}

void FloatBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FloatBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FloatBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedAutoWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatBoxStylesComputer_obj::__mClass,"__mClass");
};

Class FloatBoxStylesComputer_obj::__mClass;

void FloatBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.FloatBoxStylesComputer"), hx::TCanCast< FloatBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FloatBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
