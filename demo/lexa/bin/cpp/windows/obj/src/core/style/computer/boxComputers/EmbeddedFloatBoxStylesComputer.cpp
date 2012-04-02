#include <hxcpp.h>

#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedFloatBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void EmbeddedFloatBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedFloatBoxStylesComputer.hx",23)
	super::__construct();
}
;
	return null();
}

EmbeddedFloatBoxStylesComputer_obj::~EmbeddedFloatBoxStylesComputer_obj() { }

Dynamic EmbeddedFloatBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedFloatBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedFloatBoxStylesComputer_obj > EmbeddedFloatBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedFloatBoxStylesComputer_obj > result = new EmbeddedFloatBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedFloatBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedFloatBoxStylesComputer_obj > result = new EmbeddedFloatBoxStylesComputer_obj();
	result->__construct();
	return result;}


EmbeddedFloatBoxStylesComputer_obj::EmbeddedFloatBoxStylesComputer_obj()
{
}

void EmbeddedFloatBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedFloatBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedFloatBoxStylesComputer_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic EmbeddedFloatBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EmbeddedFloatBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedFloatBoxStylesComputer_obj::__mClass;

void EmbeddedFloatBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer"), hx::TCanCast< EmbeddedFloatBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedFloatBoxStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
