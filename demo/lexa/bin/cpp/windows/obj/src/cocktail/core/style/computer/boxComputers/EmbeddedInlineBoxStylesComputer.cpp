#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void EmbeddedInlineBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.hx",27)
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

int EmbeddedInlineBoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("EmbeddedInlineBoxStylesComputer_obj::getComputedAutoMargin")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedInlineBoxStylesComputer.hx",35)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC9(EmbeddedInlineBoxStylesComputer_obj,getComputedAutoMargin,return )


EmbeddedInlineBoxStylesComputer_obj::EmbeddedInlineBoxStylesComputer_obj()
{
}

void EmbeddedInlineBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedInlineBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedInlineBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EmbeddedInlineBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
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
};

Class EmbeddedInlineBoxStylesComputer_obj::__mClass;

void EmbeddedInlineBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer"), hx::TCanCast< EmbeddedInlineBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedInlineBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
