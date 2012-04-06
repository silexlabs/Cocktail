#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/FloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void FloatBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/FloatBoxStylesComputer.hx",26)
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

int FloatBoxStylesComputer_obj::getComputedAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("FloatBoxStylesComputer_obj::getComputedAutoWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/FloatBoxStylesComputer.hx",35)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(FloatBoxStylesComputer_obj,getComputedAutoWidth,return )


FloatBoxStylesComputer_obj::FloatBoxStylesComputer_obj()
{
}

void FloatBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FloatBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FloatBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
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
};

Class FloatBoxStylesComputer_obj::__mClass;

void FloatBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer"), hx::TCanCast< FloatBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FloatBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
