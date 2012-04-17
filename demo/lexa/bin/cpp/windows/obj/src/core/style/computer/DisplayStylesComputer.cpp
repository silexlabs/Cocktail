#include <hxcpp.h>

#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_CSSFloat
#include <core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_core_style_Clear
#include <core/style/Clear.h>
#endif
#ifndef INCLUDED_core_style_Display
#include <core/style/Display.h>
#endif
#ifndef INCLUDED_core_style_Position
#include <core/style/Position.h>
#endif
#ifndef INCLUDED_core_style_computer_DisplayStylesComputer
#include <core/style/computer/DisplayStylesComputer.h>
#endif
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

Void DisplayStylesComputer_obj::compute( ::core::style::AbstractStyle style){
{
		HX_SOURCE_PUSH("DisplayStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",53)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",56)
		computedStyle->__FieldRef(HX_CSTRING("position")) = ::core::style::computer::DisplayStylesComputer_obj::getComputedPosition(style);
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",59)
		computedStyle->__FieldRef(HX_CSTRING("cssFloat")) = ::core::style::computer::DisplayStylesComputer_obj::getComputedFloat(style,computedStyle->__Field(HX_CSTRING("position")));
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",62)
		computedStyle->__FieldRef(HX_CSTRING("display")) = ::core::style::computer::DisplayStylesComputer_obj::getComputedDisplay(style,computedStyle->__Field(HX_CSTRING("cssFloat")));
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",65)
		computedStyle->__FieldRef(HX_CSTRING("clear")) = ::core::style::computer::DisplayStylesComputer_obj::getComputedClear(style,computedStyle->__Field(HX_CSTRING("position")),computedStyle->__Field(HX_CSTRING("display")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DisplayStylesComputer_obj,compute,(void))

::core::style::Position DisplayStylesComputer_obj::getComputedPosition( ::core::style::AbstractStyle style){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedPosition")
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",77)
	return style->getPosition();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(DisplayStylesComputer_obj,getComputedPosition,return )

::core::style::CSSFloat DisplayStylesComputer_obj::getComputedFloat( ::core::style::AbstractStyle style,::core::style::Position computedPosition){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedFloat")
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",89)
	::core::style::CSSFloat ret;
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",95)
	if (((bool((computedPosition == ::core::style::Position_obj::absolute_dyn())) || bool((computedPosition == ::core::style::Position_obj::fixed_dyn()))))){
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",96)
		ret = ::core::style::CSSFloat_obj::none_dyn();
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",100)
		ret = style->getCSSFloat();
	}
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",104)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DisplayStylesComputer_obj,getComputedFloat,return )

::core::style::Display DisplayStylesComputer_obj::getComputedDisplay( ::core::style::AbstractStyle style,::core::style::CSSFloat computedFloat){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedDisplay")
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",116)
	::core::style::Display ret;
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",120)
	if (((computedFloat != ::core::style::CSSFloat_obj::none_dyn()))){
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",121)
		{
::core::style::Display _switch_1 = (style->getDisplay());
			switch((_switch_1)->GetIndex()){
				case 2: case 1: {
					HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",125)
					ret = ::core::style::Display_obj::block_dyn();
				}
				;break;
				default: {
					HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",129)
					ret = style->getDisplay();
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",134)
		ret = style->getDisplay();
	}
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",138)
	return ret;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(DisplayStylesComputer_obj,getComputedDisplay,return )

::core::style::Clear DisplayStylesComputer_obj::getComputedClear( ::core::style::AbstractStyle style,::core::style::Position computedPosition,::core::style::Display computedDisplay){
	HX_SOURCE_PUSH("DisplayStylesComputer_obj::getComputedClear")
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",154)
	::core::style::Clear ret;
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",156)
	if (((bool((computedDisplay == ::core::style::Display_obj::cssInline_dyn())) || bool((computedDisplay == ::core::style::Display_obj::inlineBlock_dyn()))))){
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",157)
		ret = ::core::style::Clear_obj::none_dyn();
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",160)
		if (((bool((computedPosition == ::core::style::Position_obj::absolute_dyn())) || bool((computedPosition == ::core::style::Position_obj::fixed_dyn()))))){
			HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",161)
			ret = ::core::style::Clear_obj::none_dyn();
		}
		else{
			HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",165)
			ret = style->getClear();
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/DisplayStylesComputer.hx",169)
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.DisplayStylesComputer"), hx::TCanCast< DisplayStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
