#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_DimensionVO
#include <cocktail/core/geom/DimensionVO.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void DimensionVO_obj::__construct(Float width,Float height)
{
HX_STACK_PUSH("DimensionVO::new","cocktail/core/geom/GeomData.hx",83);
{
	HX_STACK_LINE(84)
	this->width = width;
	HX_STACK_LINE(85)
	this->height = height;
}
;
	return null();
}

DimensionVO_obj::~DimensionVO_obj() { }

Dynamic DimensionVO_obj::__CreateEmpty() { return  new DimensionVO_obj; }
hx::ObjectPtr< DimensionVO_obj > DimensionVO_obj::__new(Float width,Float height)
{  hx::ObjectPtr< DimensionVO_obj > result = new DimensionVO_obj();
	result->__construct(width,height);
	return result;}

Dynamic DimensionVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DimensionVO_obj > result = new DimensionVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


DimensionVO_obj::DimensionVO_obj()
{
}

void DimensionVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DimensionVO);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void DimensionVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic DimensionVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DimensionVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DimensionVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DimensionVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DimensionVO_obj::__mClass,"__mClass");
};

Class DimensionVO_obj::__mClass;

void DimensionVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.DimensionVO"), hx::TCanCast< DimensionVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DimensionVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
