#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
namespace cocktail{
namespace core{
namespace layout{

Void ContainingBlockVO_obj::__construct(Float width,bool isWidthAuto,Float height,bool isHeightAuto)
{
HX_STACK_PUSH("ContainingBlockVO::new","cocktail/core/layout/LayoutData.hx",39);
{
	HX_STACK_LINE(40)
	this->width = width;
	HX_STACK_LINE(41)
	this->isWidthAuto = isWidthAuto;
	HX_STACK_LINE(42)
	this->height = height;
	HX_STACK_LINE(43)
	this->isHeightAuto = isHeightAuto;
}
;
	return null();
}

ContainingBlockVO_obj::~ContainingBlockVO_obj() { }

Dynamic ContainingBlockVO_obj::__CreateEmpty() { return  new ContainingBlockVO_obj; }
hx::ObjectPtr< ContainingBlockVO_obj > ContainingBlockVO_obj::__new(Float width,bool isWidthAuto,Float height,bool isHeightAuto)
{  hx::ObjectPtr< ContainingBlockVO_obj > result = new ContainingBlockVO_obj();
	result->__construct(width,isWidthAuto,height,isHeightAuto);
	return result;}

Dynamic ContainingBlockVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ContainingBlockVO_obj > result = new ContainingBlockVO_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


ContainingBlockVO_obj::ContainingBlockVO_obj()
{
}

void ContainingBlockVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ContainingBlockVO);
	HX_MARK_MEMBER_NAME(isHeightAuto,"isHeightAuto");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(isWidthAuto,"isWidthAuto");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void ContainingBlockVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(isHeightAuto,"isHeightAuto");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(isWidthAuto,"isWidthAuto");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic ContainingBlockVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isWidthAuto") ) { return isWidthAuto; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isHeightAuto") ) { return isHeightAuto; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ContainingBlockVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isWidthAuto") ) { isWidthAuto=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isHeightAuto") ) { isHeightAuto=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ContainingBlockVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isHeightAuto"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("isWidthAuto"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isHeightAuto"),
	HX_CSTRING("height"),
	HX_CSTRING("isWidthAuto"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ContainingBlockVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ContainingBlockVO_obj::__mClass,"__mClass");
};

Class ContainingBlockVO_obj::__mClass;

void ContainingBlockVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.ContainingBlockVO"), hx::TCanCast< ContainingBlockVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ContainingBlockVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
