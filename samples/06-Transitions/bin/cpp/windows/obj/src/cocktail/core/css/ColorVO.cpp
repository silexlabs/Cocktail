#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void ColorVO_obj::__construct(int color,Float alpha)
{
HX_STACK_PUSH("ColorVO::new","cocktail/core/css/CSSData.hx",234);
{
	HX_STACK_LINE(235)
	this->color = color;
	HX_STACK_LINE(236)
	this->alpha = alpha;
}
;
	return null();
}

ColorVO_obj::~ColorVO_obj() { }

Dynamic ColorVO_obj::__CreateEmpty() { return  new ColorVO_obj; }
hx::ObjectPtr< ColorVO_obj > ColorVO_obj::__new(int color,Float alpha)
{  hx::ObjectPtr< ColorVO_obj > result = new ColorVO_obj();
	result->__construct(color,alpha);
	return result;}

Dynamic ColorVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorVO_obj > result = new ColorVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


ColorVO_obj::ColorVO_obj()
{
}

void ColorVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColorVO);
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_END_CLASS();
}

void ColorVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(color,"color");
}

Dynamic ColorVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColorVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColorVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("color"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("alpha"),
	HX_CSTRING("color"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColorVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColorVO_obj::__mClass,"__mClass");
};

Class ColorVO_obj::__mClass;

void ColorVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.ColorVO"), hx::TCanCast< ColorVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ColorVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
