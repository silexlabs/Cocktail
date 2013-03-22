#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BlockBoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/layout/computer/boxComputers/BoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{
namespace boxComputers{

Void BlockBoxStylesComputer_obj::__construct()
{
HX_STACK_PUSH("BlockBoxStylesComputer::new","cocktail/core/layout/computer/boxComputers/BlockBoxStylesComputer.hx",26);
{
	HX_STACK_LINE(26)
	super::__construct();
}
;
	return null();
}

BlockBoxStylesComputer_obj::~BlockBoxStylesComputer_obj() { }

Dynamic BlockBoxStylesComputer_obj::__CreateEmpty() { return  new BlockBoxStylesComputer_obj; }
hx::ObjectPtr< BlockBoxStylesComputer_obj > BlockBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< BlockBoxStylesComputer_obj > result = new BlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic BlockBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlockBoxStylesComputer_obj > result = new BlockBoxStylesComputer_obj();
	result->__construct();
	return result;}


BlockBoxStylesComputer_obj::BlockBoxStylesComputer_obj()
{
}

void BlockBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlockBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BlockBoxStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BlockBoxStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic BlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BlockBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlockBoxStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BlockBoxStylesComputer_obj::__mClass,"__mClass");
};

Class BlockBoxStylesComputer_obj::__mClass;

void BlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.boxComputers.BlockBoxStylesComputer"), hx::TCanCast< BlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
} // end namespace boxComputers
