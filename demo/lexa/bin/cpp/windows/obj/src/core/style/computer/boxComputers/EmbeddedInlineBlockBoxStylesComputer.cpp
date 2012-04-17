#include <hxcpp.h>

#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void EmbeddedInlineBlockBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.hx",23)
	super::__construct();
}
;
	return null();
}

EmbeddedInlineBlockBoxStylesComputer_obj::~EmbeddedInlineBlockBoxStylesComputer_obj() { }

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedInlineBlockBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedInlineBlockBoxStylesComputer_obj > EmbeddedInlineBlockBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedInlineBlockBoxStylesComputer_obj > result = new EmbeddedInlineBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedInlineBlockBoxStylesComputer_obj > result = new EmbeddedInlineBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}


EmbeddedInlineBlockBoxStylesComputer_obj::EmbeddedInlineBlockBoxStylesComputer_obj()
{
}

void EmbeddedInlineBlockBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedInlineBlockBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EmbeddedInlineBlockBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedInlineBlockBoxStylesComputer_obj::__mClass;

void EmbeddedInlineBlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"), hx::TCanCast< EmbeddedInlineBlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedInlineBlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
