#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace utils{

Void Utils_obj::__construct()
{
HX_STACK_PUSH("Utils::new","cocktail/core/utils/Utils.hx",12);
{
}
;
	return null();
}

Utils_obj::~Utils_obj() { }

Dynamic Utils_obj::__CreateEmpty() { return  new Utils_obj; }
hx::ObjectPtr< Utils_obj > Utils_obj::__new()
{  hx::ObjectPtr< Utils_obj > result = new Utils_obj();
	result->__construct();
	return result;}

Dynamic Utils_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Utils_obj > result = new Utils_obj();
	result->__construct();
	return result;}

Dynamic Utils_obj::clear( Dynamic array){
	HX_STACK_PUSH("Utils::clear","cocktail/core/utils/Utils.hx",17);
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(21)
	array = Dynamic( Array_obj<Dynamic>::__new());
	HX_STACK_LINE(23)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Utils_obj,clear,return )


Utils_obj::Utils_obj()
{
}

void Utils_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Utils);
	HX_MARK_END_CLASS();
}

void Utils_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Utils_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Utils_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Utils_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("clear"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Utils_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Utils_obj::__mClass,"__mClass");
};

Class Utils_obj::__mClass;

void Utils_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.utils.Utils"), hx::TCanCast< Utils_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Utils_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace utils
