#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_CubicBezier
#include <cocktail/core/geom/CubicBezier.h>
#endif
namespace cocktail{
namespace core{
namespace geom{

Void CubicBezier_obj::__construct()
{
HX_STACK_PUSH("CubicBezier::new","cocktail/core/geom/CubicBezier.hx",46);
{
}
;
	return null();
}

CubicBezier_obj::~CubicBezier_obj() { }

Dynamic CubicBezier_obj::__CreateEmpty() { return  new CubicBezier_obj; }
hx::ObjectPtr< CubicBezier_obj > CubicBezier_obj::__new()
{  hx::ObjectPtr< CubicBezier_obj > result = new CubicBezier_obj();
	result->__construct();
	return result;}

Dynamic CubicBezier_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CubicBezier_obj > result = new CubicBezier_obj();
	result->__construct();
	return result;}

Float CubicBezier_obj::bezierY( Float t){
	HX_STACK_PUSH("CubicBezier::bezierY","cocktail/core/geom/CubicBezier.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(72)
	return (t * ((this->_cy + (t * ((this->_by + (t * this->_ay)))))));
}


HX_DEFINE_DYNAMIC_FUNC1(CubicBezier_obj,bezierY,return )

Float CubicBezier_obj::bezierX( Float t){
	HX_STACK_PUSH("CubicBezier::bezierX","cocktail/core/geom/CubicBezier.hx",67);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(67)
	return (t * ((this->_cx + (t * ((this->_bx + (t * this->_ax)))))));
}


HX_DEFINE_DYNAMIC_FUNC1(CubicBezier_obj,bezierX,return )

Void CubicBezier_obj::init( Float x1,Float y1,Float x2,Float y2){
{
		HX_STACK_PUSH("CubicBezier::init","cocktail/core/geom/CubicBezier.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x1,"x1");
		HX_STACK_ARG(y1,"y1");
		HX_STACK_ARG(x2,"x2");
		HX_STACK_ARG(y2,"y2");
		HX_STACK_LINE(52)
		this->_x1 = x1;
		HX_STACK_LINE(53)
		this->_y1 = y1;
		HX_STACK_LINE(54)
		this->_x2 = x2;
		HX_STACK_LINE(55)
		this->_y2 = y2;
		HX_STACK_LINE(57)
		this->_cx = ((int)3 * this->_x1);
		HX_STACK_LINE(58)
		this->_bx = (((int)3 * ((this->_x2 - this->_x1))) - this->_cx);
		HX_STACK_LINE(59)
		this->_ax = (((int)1 - this->_cx) - this->_bx);
		HX_STACK_LINE(61)
		this->_cy = ((int)3 * this->_y1);
		HX_STACK_LINE(62)
		this->_by = (((int)3 * ((this->_y2 - this->_y1))) - this->_cy);
		HX_STACK_LINE(63)
		this->_ay = (((int)1 - this->_cy) - this->_by);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(CubicBezier_obj,init,(void))


CubicBezier_obj::CubicBezier_obj()
{
}

void CubicBezier_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CubicBezier);
	HX_MARK_MEMBER_NAME(_ay,"_ay");
	HX_MARK_MEMBER_NAME(_by,"_by");
	HX_MARK_MEMBER_NAME(_cy,"_cy");
	HX_MARK_MEMBER_NAME(_ax,"_ax");
	HX_MARK_MEMBER_NAME(_bx,"_bx");
	HX_MARK_MEMBER_NAME(_cx,"_cx");
	HX_MARK_MEMBER_NAME(_y2,"_y2");
	HX_MARK_MEMBER_NAME(_x2,"_x2");
	HX_MARK_MEMBER_NAME(_y1,"_y1");
	HX_MARK_MEMBER_NAME(_x1,"_x1");
	HX_MARK_END_CLASS();
}

void CubicBezier_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_ay,"_ay");
	HX_VISIT_MEMBER_NAME(_by,"_by");
	HX_VISIT_MEMBER_NAME(_cy,"_cy");
	HX_VISIT_MEMBER_NAME(_ax,"_ax");
	HX_VISIT_MEMBER_NAME(_bx,"_bx");
	HX_VISIT_MEMBER_NAME(_cx,"_cx");
	HX_VISIT_MEMBER_NAME(_y2,"_y2");
	HX_VISIT_MEMBER_NAME(_x2,"_x2");
	HX_VISIT_MEMBER_NAME(_y1,"_y1");
	HX_VISIT_MEMBER_NAME(_x1,"_x1");
}

Dynamic CubicBezier_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ay") ) { return _ay; }
		if (HX_FIELD_EQ(inName,"_by") ) { return _by; }
		if (HX_FIELD_EQ(inName,"_cy") ) { return _cy; }
		if (HX_FIELD_EQ(inName,"_ax") ) { return _ax; }
		if (HX_FIELD_EQ(inName,"_bx") ) { return _bx; }
		if (HX_FIELD_EQ(inName,"_cx") ) { return _cx; }
		if (HX_FIELD_EQ(inName,"_y2") ) { return _y2; }
		if (HX_FIELD_EQ(inName,"_x2") ) { return _x2; }
		if (HX_FIELD_EQ(inName,"_y1") ) { return _y1; }
		if (HX_FIELD_EQ(inName,"_x1") ) { return _x1; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bezierY") ) { return bezierY_dyn(); }
		if (HX_FIELD_EQ(inName,"bezierX") ) { return bezierX_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CubicBezier_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_ay") ) { _ay=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_by") ) { _by=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cy") ) { _cy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_ax") ) { _ax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bx") ) { _bx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cx") ) { _cx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_y2") ) { _y2=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_x2") ) { _x2=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_y1") ) { _y1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_x1") ) { _x1=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CubicBezier_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_ay"));
	outFields->push(HX_CSTRING("_by"));
	outFields->push(HX_CSTRING("_cy"));
	outFields->push(HX_CSTRING("_ax"));
	outFields->push(HX_CSTRING("_bx"));
	outFields->push(HX_CSTRING("_cx"));
	outFields->push(HX_CSTRING("_y2"));
	outFields->push(HX_CSTRING("_x2"));
	outFields->push(HX_CSTRING("_y1"));
	outFields->push(HX_CSTRING("_x1"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bezierY"),
	HX_CSTRING("bezierX"),
	HX_CSTRING("init"),
	HX_CSTRING("_ay"),
	HX_CSTRING("_by"),
	HX_CSTRING("_cy"),
	HX_CSTRING("_ax"),
	HX_CSTRING("_bx"),
	HX_CSTRING("_cx"),
	HX_CSTRING("_y2"),
	HX_CSTRING("_x2"),
	HX_CSTRING("_y1"),
	HX_CSTRING("_x1"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CubicBezier_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CubicBezier_obj::__mClass,"__mClass");
};

Class CubicBezier_obj::__mClass;

void CubicBezier_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.geom.CubicBezier"), hx::TCanCast< CubicBezier_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CubicBezier_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace geom
