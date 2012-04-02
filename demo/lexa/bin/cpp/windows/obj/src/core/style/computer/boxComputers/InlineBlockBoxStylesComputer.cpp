#include <hxcpp.h>

#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_Margin
#include <core/style/Margin.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#include <core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void InlineBlockBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",25)
	super::__construct();
}
;
	return null();
}

InlineBlockBoxStylesComputer_obj::~InlineBlockBoxStylesComputer_obj() { }

Dynamic InlineBlockBoxStylesComputer_obj::__CreateEmpty() { return  new InlineBlockBoxStylesComputer_obj; }
hx::ObjectPtr< InlineBlockBoxStylesComputer_obj > InlineBlockBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< InlineBlockBoxStylesComputer_obj > result = new InlineBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic InlineBlockBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineBlockBoxStylesComputer_obj > result = new InlineBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

int InlineBlockBoxStylesComputer_obj::getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("InlineBlockBoxStylesComputer_obj::getComputedAutoMargin")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",33)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC9(InlineBlockBoxStylesComputer_obj,getComputedAutoMargin,return )

int InlineBlockBoxStylesComputer_obj::shrinkToFit( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,int minimumWidth){
	HX_SOURCE_PUSH("InlineBlockBoxStylesComputer_obj::shrinkToFit")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",47)
	int shrinkedWidth;
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",52)
	if (((minimumWidth < containingHTMLElementData->__Field(HX_CSTRING("width"))))){
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",53)
		shrinkedWidth = minimumWidth;
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",57)
		shrinkedWidth = containingHTMLElementData->__Field(HX_CSTRING("width"));
	}
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.hx",61)
	return shrinkedWidth;
}


HX_DEFINE_DYNAMIC_FUNC3(InlineBlockBoxStylesComputer_obj,shrinkToFit,return )


InlineBlockBoxStylesComputer_obj::InlineBlockBoxStylesComputer_obj()
{
}

void InlineBlockBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineBlockBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InlineBlockBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"shrinkToFit") ) { return shrinkToFit_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InlineBlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void InlineBlockBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("shrinkToFit"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InlineBlockBoxStylesComputer_obj::__mClass;

void InlineBlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.boxComputers.InlineBlockBoxStylesComputer"), hx::TCanCast< InlineBlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InlineBlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
