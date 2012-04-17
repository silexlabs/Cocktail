#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_CSSFloat
#include <cocktail/core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Display
#include <cocktail/core/style/Display.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Position
#include <cocktail/core/style/Position.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_DisplayStylesComputer
#include <cocktail/core/style/computer/DisplayStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{

Void DisplayStylesComputer_obj::__construct()
{
{
}
;
	return null();
}

DisplayStylesComputer_obj::~DisplayStylesComputer_obj() { }

Dynamic DisplayStylesComputer_obj::__CreateEmpty() { return  new DisplayStylesComputer_obj; }
hx::ObjectPtr< DisplayStylesComputer_obj > DisplayStylesComputer_obj::__new()
{  hx::ObjectPtr< DisplayStylesComputer_obj > result = new DisplayStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic DisplayStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayStylesComputer_obj > result = new DisplayStylesComputer_obj();
	result->__construct();
	return result;}

Void DisplayStylesComputer_obj::compute( ::cocktail::core::style::CoreStyle style){
{
		HX_SOURCE_PUSH("DisplayStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",52)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",55)
		computedStyle->__FieldRef(HX_CSTRING("position")) = ::cocktail::core::style::computer::DisplayStylesComputer_obj::getComputedPosition(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",58)
		computedStyle->__FieldRef(HX_CSTRING("cssFloat")) = ::cocktail::core::style::computer::DisplayStylesComputer_obj::getComputedFloat(style,computedStyle->__Field(HX_CSTRING("position")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",61)
		computedStyle->__FieldRef(HX_CSTRING("display")) = ::cocktail::core::style::computer::DisplayStylesComputer_obj::getComputedDisplay(style,computedStyle->__Field(HX_CSTRING("cssFloat")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",64)
		computedStyle->__FieldRef(HX_CSTRING("clear")) = ::cocktail::core::style::computer::DisplayStylesComputer_obj::getComputedClear(style,computedStyle->__Field(HX_CSTRING("position")),computedStyle->__Field(HX_CSTRING("display")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DisplayStylesComputer_obj,compute,(void))

::cocktail::core::style::Position DisplayStylesComputer_obj::getComputedPosition( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",76)
	return style->getPosition();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DisplayStylesComputer_obj,getComputedPosition,return )

::cocktail::core::style::CSSFloat DisplayStylesComputer_obj::getComputedFloat( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::Position computedPosition){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",88)
	::cocktail::core::style::CSSFloat ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",94)
	if (((bool((computedPosition == ::cocktail::core::style::Position_obj::absolute_dyn())) || bool((computedPosition == ::cocktail::core::style::Position_obj::fixed_dyn()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",95)
		ret = ::cocktail::core::style::CSSFloat_obj::none_dyn();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",99)
		ret = style->getCSSFloat();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",103)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DisplayStylesComputer_obj,getComputedFloat,return )

::cocktail::core::style::Display DisplayStylesComputer_obj::getComputedDisplay( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::CSSFloat computedFloat){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedDisplay")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",115)
	::cocktail::core::style::Display ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",119)
	if (((computedFloat != ::cocktail::core::style::CSSFloat_obj::none_dyn()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",120)
		{
::cocktail::core::style::Display _switch_1 = (style->getDisplay());
			switch((_switch_1)->GetIndex()){
				case 2: case 1: {
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",124)
					ret = ::cocktail::core::style::Display_obj::block_dyn();
				}
				;break;
				default: {
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",128)
					ret = style->getDisplay();
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",133)
		ret = style->getDisplay();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",137)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DisplayStylesComputer_obj,getComputedDisplay,return )

::cocktail::core::style::Clear DisplayStylesComputer_obj::getComputedClear( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::Position computedPosition,::cocktail::core::style::Display computedDisplay){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedClear")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",153)
	::cocktail::core::style::Clear ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",155)
	if (((bool((computedDisplay == ::cocktail::core::style::Display_obj::cssInline_dyn())) || bool((computedDisplay == ::cocktail::core::style::Display_obj::inlineBlock_dyn()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",156)
		ret = ::cocktail::core::style::Clear_obj::none_dyn();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",159)
		if (((bool((computedPosition == ::cocktail::core::style::Position_obj::absolute_dyn())) || bool((computedPosition == ::cocktail::core::style::Position_obj::fixed_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",160)
			ret = ::cocktail::core::style::Clear_obj::none_dyn();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",164)
			ret = style->getClear();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/DisplayStylesComputer.hx",168)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(DisplayStylesComputer_obj,getComputedClear,return )


DisplayStylesComputer_obj::DisplayStylesComputer_obj()
{
}

void DisplayStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayStylesComputer);
	HX_MARK_END_CLASS();
}

Dynamic DisplayStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getComputedFloat") ) { return getComputedFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedClear") ) { return getComputedClear_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getComputedDisplay") ) { return getComputedDisplay_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getComputedPosition") ) { return getComputedPosition_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic DisplayStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void DisplayStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compute"),
	HX_CSTRING("getComputedPosition"),
	HX_CSTRING("getComputedFloat"),
	HX_CSTRING("getComputedDisplay"),
	HX_CSTRING("getComputedClear"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class DisplayStylesComputer_obj::__mClass;

void DisplayStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.DisplayStylesComputer"), hx::TCanCast< DisplayStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
