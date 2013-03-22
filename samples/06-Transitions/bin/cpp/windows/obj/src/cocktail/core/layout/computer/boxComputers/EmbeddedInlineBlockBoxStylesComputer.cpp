#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedInlineBlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void EmbeddedInlineBlockBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("EmbeddedInlineBlockBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/EmbeddedInlineBlockBoxStylesComputer.hx",23);
{
	HX_STACK_LINE(23)
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

void EmbeddedInlineBlockBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic EmbeddedInlineBlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
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
	HX_MARK_MEMBER_NAME(EmbeddedInlineBlockBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EmbeddedInlineBlockBoxStylesComputer_obj::__mClass,"__mClass");
};

Class EmbeddedInlineBlockBoxStylesComputer_obj::__mClass;

void EmbeddedInlineBlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer"), hx::TCanCast< EmbeddedInlineBlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EmbeddedInlineBlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
