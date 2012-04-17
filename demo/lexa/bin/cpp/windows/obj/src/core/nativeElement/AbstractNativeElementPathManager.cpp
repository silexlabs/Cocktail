#include <hxcpp.h>

#ifndef INCLUDED_core_nativeElement_AbstractNativeElementPathManager
#include <core/nativeElement/AbstractNativeElementPathManager.h>
#endif
namespace core{
namespace nativeElement{

Void AbstractNativeElementPathManager_obj::__construct()
{
{
}
;
	return null();
}

AbstractNativeElementPathManager_obj::~AbstractNativeElementPathManager_obj() { }

Dynamic AbstractNativeElementPathManager_obj::__CreateEmpty() { return  new AbstractNativeElementPathManager_obj; }
hx::ObjectPtr< AbstractNativeElementPathManager_obj > AbstractNativeElementPathManager_obj::__new()
{  hx::ObjectPtr< AbstractNativeElementPathManager_obj > result = new AbstractNativeElementPathManager_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementPathManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractNativeElementPathManager_obj > result = new AbstractNativeElementPathManager_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementPathManager_obj::getRoot( ){
	HX_SOURCE_PUSH("AbstractNativeElementPathManager_obj::getRoot")
	HX_SOURCE_POS("../../src/core/nativeElement/AbstractNativeElementPathManager.hx",33)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractNativeElementPathManager_obj,getRoot,return )


AbstractNativeElementPathManager_obj::AbstractNativeElementPathManager_obj()
{
}

void AbstractNativeElementPathManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractNativeElementPathManager);
	HX_MARK_END_CLASS();
}

Dynamic AbstractNativeElementPathManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getRoot") ) { return getRoot_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractNativeElementPathManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractNativeElementPathManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getRoot"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractNativeElementPathManager_obj::__mClass;

void AbstractNativeElementPathManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.nativeElement.AbstractNativeElementPathManager"), hx::TCanCast< AbstractNativeElementPathManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractNativeElementPathManager_obj::__boot()
{
}

} // end namespace core
} // end namespace nativeElement
