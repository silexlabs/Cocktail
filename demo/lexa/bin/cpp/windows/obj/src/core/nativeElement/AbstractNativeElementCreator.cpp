#include <hxcpp.h>

#ifndef INCLUDED_core_nativeElement_AbstractNativeElementCreator
#include <core/nativeElement/AbstractNativeElementCreator.h>
#endif
#ifndef INCLUDED_core_nativeElement_NativeElementTypeValue
#include <core/nativeElement/NativeElementTypeValue.h>
#endif
namespace core{
namespace nativeElement{

Void AbstractNativeElementCreator_obj::__construct()
{
{
}
;
	return null();
}

AbstractNativeElementCreator_obj::~AbstractNativeElementCreator_obj() { }

Dynamic AbstractNativeElementCreator_obj::__CreateEmpty() { return  new AbstractNativeElementCreator_obj; }
hx::ObjectPtr< AbstractNativeElementCreator_obj > AbstractNativeElementCreator_obj::__new()
{  hx::ObjectPtr< AbstractNativeElementCreator_obj > result = new AbstractNativeElementCreator_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementCreator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractNativeElementCreator_obj > result = new AbstractNativeElementCreator_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementCreator_obj::createNativeElement( ::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("AbstractNativeElementCreator_obj::createNativeElement")
	HX_SOURCE_POS("../../src/core/nativeElement/AbstractNativeElementCreator.hx",36)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractNativeElementCreator_obj,createNativeElement,return )


AbstractNativeElementCreator_obj::AbstractNativeElementCreator_obj()
{
}

void AbstractNativeElementCreator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractNativeElementCreator);
	HX_MARK_END_CLASS();
}

Dynamic AbstractNativeElementCreator_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"createNativeElement") ) { return createNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractNativeElementCreator_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractNativeElementCreator_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createNativeElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractNativeElementCreator_obj::__mClass;

void AbstractNativeElementCreator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.nativeElement.AbstractNativeElementCreator"), hx::TCanCast< AbstractNativeElementCreator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractNativeElementCreator_obj::__boot()
{
}

} // end namespace core
} // end namespace nativeElement
