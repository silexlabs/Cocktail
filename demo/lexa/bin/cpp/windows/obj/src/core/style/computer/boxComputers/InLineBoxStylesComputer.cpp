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
#ifndef INCLUDED_core_style_computer_boxComputers_InLineBoxStylesComputer
#include <core/style/computer/boxComputers/InLineBoxStylesComputer.h>
#endif
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void InLineBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",26)
	super::__construct();
}
;
	return null();
}

InLineBoxStylesComputer_obj::~InLineBoxStylesComputer_obj() { }

Dynamic InLineBoxStylesComputer_obj::__CreateEmpty() { return  new InLineBoxStylesComputer_obj; }
hx::ObjectPtr< InLineBoxStylesComputer_obj > InLineBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< InLineBoxStylesComputer_obj > result = new InLineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic InLineBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InLineBoxStylesComputer_obj > result = new InLineBoxStylesComputer_obj();
	result->__construct();
	return result;}

Void InLineBoxStylesComputer_obj::measureVerticalPaddings( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::measureVerticalPaddings")
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",36)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingTop")) = (int)0;
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",38)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingBottom")) = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InLineBoxStylesComputer_obj,measureVerticalPaddings,(void))

Void InLineBoxStylesComputer_obj::measureAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::measureAutoHeight")
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",47)
		this->setComputedHeight(style,this->getComputedAutoHeight(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",50)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",52)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InLineBoxStylesComputer_obj,measureAutoHeight,(void))

Void InLineBoxStylesComputer_obj::measureHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::measureHeight")
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",62)
		this->setComputedHeight(style,this->getComputedHeight(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",64)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",66)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InLineBoxStylesComputer_obj,measureHeight,(void))

int InLineBoxStylesComputer_obj::getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::getComputedAutoMargin")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",73)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC9(InLineBoxStylesComputer_obj,getComputedAutoMargin,return )

int InLineBoxStylesComputer_obj::getComputedWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::getComputedWidth")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",81)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(InLineBoxStylesComputer_obj,getComputedWidth,return )

int InLineBoxStylesComputer_obj::getComputedHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("InLineBoxStylesComputer_obj::getComputedHeight")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/InLineBoxStylesComputer.hx",89)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(InLineBoxStylesComputer_obj,getComputedHeight,return )


InLineBoxStylesComputer_obj::InLineBoxStylesComputer_obj()
{
}

void InLineBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InLineBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InLineBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getComputedWidth") ) { return getComputedWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedHeight") ) { return getComputedHeight_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"measureVerticalPaddings") ) { return measureVerticalPaddings_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InLineBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void InLineBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("measureVerticalPaddings"),
	HX_CSTRING("measureAutoHeight"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("getComputedWidth"),
	HX_CSTRING("getComputedHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InLineBoxStylesComputer_obj::__mClass;

void InLineBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.boxComputers.InLineBoxStylesComputer"), hx::TCanCast< InLineBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InLineBoxStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
