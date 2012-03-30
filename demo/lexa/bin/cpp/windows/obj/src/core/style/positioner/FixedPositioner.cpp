#include <hxcpp.h>

#ifndef INCLUDED_core_style_positioner_BoxPositioner
#include <core/style/positioner/BoxPositioner.h>
#endif
#ifndef INCLUDED_core_style_positioner_FixedPositioner
#include <core/style/positioner/FixedPositioner.h>
#endif
namespace core{
namespace style{
namespace positioner{

Void FixedPositioner_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/positioner/FixedPositioner.hx",23)
	super::__construct();
}
;
	return null();
}

FixedPositioner_obj::~FixedPositioner_obj() { }

Dynamic FixedPositioner_obj::__CreateEmpty() { return  new FixedPositioner_obj; }
hx::ObjectPtr< FixedPositioner_obj > FixedPositioner_obj::__new()
{  hx::ObjectPtr< FixedPositioner_obj > result = new FixedPositioner_obj();
	result->__construct();
	return result;}

Dynamic FixedPositioner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FixedPositioner_obj > result = new FixedPositioner_obj();
	result->__construct();
	return result;}


FixedPositioner_obj::FixedPositioner_obj()
{
}

void FixedPositioner_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FixedPositioner);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FixedPositioner_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic FixedPositioner_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FixedPositioner_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FixedPositioner_obj::__mClass;

void FixedPositioner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.positioner.FixedPositioner"), hx::TCanCast< FixedPositioner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FixedPositioner_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace positioner
