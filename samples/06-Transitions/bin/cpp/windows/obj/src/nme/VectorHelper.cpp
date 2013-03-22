#include <hxcpp.h>

#ifndef INCLUDED_nme_VectorHelper
#include <nme/VectorHelper.h>
#endif
namespace nme{

Void VectorHelper_obj::__construct()
{
	return null();
}

VectorHelper_obj::~VectorHelper_obj() { }

Dynamic VectorHelper_obj::__CreateEmpty() { return  new VectorHelper_obj; }
hx::ObjectPtr< VectorHelper_obj > VectorHelper_obj::__new()
{  hx::ObjectPtr< VectorHelper_obj > result = new VectorHelper_obj();
	result->__construct();
	return result;}

Dynamic VectorHelper_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VectorHelper_obj > result = new VectorHelper_obj();
	result->__construct();
	return result;}

Dynamic VectorHelper_obj::ofArray( ::Class v,Dynamic array){
	HX_STACK_PUSH("VectorHelper::ofArray","nme/Vector.hx",13);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(13)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(VectorHelper_obj,ofArray,return )


VectorHelper_obj::VectorHelper_obj()
{
}

void VectorHelper_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VectorHelper);
	HX_MARK_END_CLASS();
}

void VectorHelper_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic VectorHelper_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"ofArray") ) { return ofArray_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VectorHelper_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void VectorHelper_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ofArray"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VectorHelper_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VectorHelper_obj::__mClass,"__mClass");
};

Class VectorHelper_obj::__mClass;

void VectorHelper_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.VectorHelper"), hx::TCanCast< VectorHelper_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void VectorHelper_obj::__boot()
{
}

} // end namespace nme
