#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void BlockBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BlockBoxStylesComputer.hx",26)
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

Dynamic BlockBoxStylesComputer_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic BlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
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
};

Class BlockBoxStylesComputer_obj::__mClass;

void BlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer"), hx::TCanCast< BlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
