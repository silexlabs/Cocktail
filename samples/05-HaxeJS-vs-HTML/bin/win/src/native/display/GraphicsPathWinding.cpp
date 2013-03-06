#include <hxcpp.h>

#ifndef INCLUDED_native_display_GraphicsPathWinding
#include <native/display/GraphicsPathWinding.h>
#endif
namespace native{
namespace display{

Void GraphicsPathWinding_obj::__construct()
{
	return null();
}

GraphicsPathWinding_obj::~GraphicsPathWinding_obj() { }

Dynamic GraphicsPathWinding_obj::__CreateEmpty() { return  new GraphicsPathWinding_obj; }
hx::ObjectPtr< GraphicsPathWinding_obj > GraphicsPathWinding_obj::__new()
{  hx::ObjectPtr< GraphicsPathWinding_obj > result = new GraphicsPathWinding_obj();
	result->__construct();
	return result;}

Dynamic GraphicsPathWinding_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphicsPathWinding_obj > result = new GraphicsPathWinding_obj();
	result->__construct();
	return result;}

::String GraphicsPathWinding_obj::EVEN_ODD;

::String GraphicsPathWinding_obj::NON_ZERO;


GraphicsPathWinding_obj::GraphicsPathWinding_obj()
{
}

void GraphicsPathWinding_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphicsPathWinding);
	HX_MARK_END_CLASS();
}

void GraphicsPathWinding_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic GraphicsPathWinding_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"EVEN_ODD") ) { return EVEN_ODD; }
		if (HX_FIELD_EQ(inName,"NON_ZERO") ) { return NON_ZERO; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GraphicsPathWinding_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"EVEN_ODD") ) { EVEN_ODD=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NON_ZERO") ) { NON_ZERO=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphicsPathWinding_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("EVEN_ODD"),
	HX_CSTRING("NON_ZERO"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicsPathWinding_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GraphicsPathWinding_obj::EVEN_ODD,"EVEN_ODD");
	HX_MARK_MEMBER_NAME(GraphicsPathWinding_obj::NON_ZERO,"NON_ZERO");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::EVEN_ODD,"EVEN_ODD");
	HX_VISIT_MEMBER_NAME(GraphicsPathWinding_obj::NON_ZERO,"NON_ZERO");
};

Class GraphicsPathWinding_obj::__mClass;

void GraphicsPathWinding_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.display.GraphicsPathWinding"), hx::TCanCast< GraphicsPathWinding_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GraphicsPathWinding_obj::__boot()
{
	EVEN_ODD= HX_CSTRING("evenOdd");
	NON_ZERO= HX_CSTRING("nonZero");
}

} // end namespace native
} // end namespace display
