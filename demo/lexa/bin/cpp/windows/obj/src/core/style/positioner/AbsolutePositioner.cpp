#include <hxcpp.h>

#ifndef INCLUDED_core_style_positioner_AbsolutePositioner
#include <core/style/positioner/AbsolutePositioner.h>
#endif
#ifndef INCLUDED_core_style_positioner_BoxPositioner
#include <core/style/positioner/BoxPositioner.h>
#endif
namespace core{
namespace style{
namespace positioner{

Void AbsolutePositioner_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/positioner/AbsolutePositioner.hx",24)
	super::__construct();
}
;
	return null();
}

AbsolutePositioner_obj::~AbsolutePositioner_obj() { }

Dynamic AbsolutePositioner_obj::__CreateEmpty() { return  new AbsolutePositioner_obj; }
hx::ObjectPtr< AbsolutePositioner_obj > AbsolutePositioner_obj::__new()
{  hx::ObjectPtr< AbsolutePositioner_obj > result = new AbsolutePositioner_obj();
	result->__construct();
	return result;}

Dynamic AbsolutePositioner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbsolutePositioner_obj > result = new AbsolutePositioner_obj();
	result->__construct();
	return result;}


AbsolutePositioner_obj::AbsolutePositioner_obj()
{
}

void AbsolutePositioner_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbsolutePositioner);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbsolutePositioner_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic AbsolutePositioner_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbsolutePositioner_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbsolutePositioner_obj::__mClass;

void AbsolutePositioner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.positioner.AbsolutePositioner"), hx::TCanCast< AbsolutePositioner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbsolutePositioner_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace positioner
