#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void PointVO_obj::__construct(Float x,Float y)
{
HX_STACK_PUSH("PointVO::new","cocktail/core/geom/GeomData.hx",67);
{
	HX_STACK_LINE(68)
	this->x = x;
	HX_STACK_LINE(69)
	this->y = y;
}
;
	return null();
}

PointVO_obj::~PointVO_obj() { }

Dynamic PointVO_obj::__CreateEmpty() { return  new PointVO_obj; }
hx::ObjectPtr< PointVO_obj > PointVO_obj::__new(Float x,Float y)
{  hx::ObjectPtr< PointVO_obj > result = new PointVO_obj();
	result->__construct(x,y);
	return result;}

Dynamic PointVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PointVO_obj > result = new PointVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


PointVO_obj::PointVO_obj()
{
}

void PointVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PointVO);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void PointVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic PointVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PointVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PointVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PointVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PointVO_obj::__mClass,"__mClass");
};

Class PointVO_obj::__mClass;

void PointVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.PointVO"), hx::TCanCast< PointVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PointVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
