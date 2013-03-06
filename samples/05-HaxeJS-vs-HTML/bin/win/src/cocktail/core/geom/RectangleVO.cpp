#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_ObjectPool
#include <cocktail/core/utils/ObjectPool.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void RectangleVO_obj::__construct()
{
HX_STACK_PUSH("RectangleVO::new","cocktail/core/geom/GeomData.hx",46);
{
	HX_STACK_LINE(46)
	this->reset();
}
;
	return null();
}

RectangleVO_obj::~RectangleVO_obj() { }

Dynamic RectangleVO_obj::__CreateEmpty() { return  new RectangleVO_obj; }
hx::ObjectPtr< RectangleVO_obj > RectangleVO_obj::__new()
{  hx::ObjectPtr< RectangleVO_obj > result = new RectangleVO_obj();
	result->__construct();
	return result;}

Dynamic RectangleVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RectangleVO_obj > result = new RectangleVO_obj();
	result->__construct();
	return result;}

hx::Object *RectangleVO_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::utils::IPoolable_obj)) return operator ::cocktail::core::utils::IPoolable_obj *();
	return super::__ToInterface(inType);
}

Void RectangleVO_obj::reset( ){
{
		HX_STACK_PUSH("RectangleVO::reset","cocktail/core/geom/GeomData.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		this->x = (int)0;
		HX_STACK_LINE(53)
		this->y = (int)0;
		HX_STACK_LINE(54)
		this->width = (int)0;
		HX_STACK_LINE(55)
		this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RectangleVO_obj,reset,(void))

::cocktail::core::utils::ObjectPool RectangleVO_obj::_pool;

::cocktail::core::utils::ObjectPool RectangleVO_obj::getPool( ){
	HX_STACK_PUSH("RectangleVO::getPool","cocktail/core/geom/GeomData.hx",37);
	HX_STACK_LINE(38)
	if (((::cocktail::core::geom::RectangleVO_obj::_pool == null()))){
		HX_STACK_LINE(39)
		::cocktail::core::geom::RectangleVO_obj::_pool = ::cocktail::core::utils::ObjectPool_obj::__new(hx::ClassOf< ::cocktail::core::geom::RectangleVO >());
	}
	HX_STACK_LINE(42)
	return ::cocktail::core::geom::RectangleVO_obj::_pool;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RectangleVO_obj,getPool,return )


RectangleVO_obj::RectangleVO_obj()
{
}

void RectangleVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RectangleVO);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void RectangleVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic RectangleVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getPool") ) { return getPool_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RectangleVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< ::cocktail::core::utils::ObjectPool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RectangleVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("getPool"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RectangleVO_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(RectangleVO_obj::_pool,"_pool");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RectangleVO_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(RectangleVO_obj::_pool,"_pool");
};

Class RectangleVO_obj::__mClass;

void RectangleVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.RectangleVO"), hx::TCanCast< RectangleVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void RectangleVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
