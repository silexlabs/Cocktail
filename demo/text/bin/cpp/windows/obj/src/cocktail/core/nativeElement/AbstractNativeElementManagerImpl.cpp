#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl
#include <cocktail/core/nativeElement/AbstractNativeElementManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
namespace cocktail{
namespace core{
namespace nativeElement{

Void AbstractNativeElementManagerImpl_obj::__construct()
{
{
}
;
	return null();
}

AbstractNativeElementManagerImpl_obj::~AbstractNativeElementManagerImpl_obj() { }

Dynamic AbstractNativeElementManagerImpl_obj::__CreateEmpty() { return  new AbstractNativeElementManagerImpl_obj; }
hx::ObjectPtr< AbstractNativeElementManagerImpl_obj > AbstractNativeElementManagerImpl_obj::__new()
{  hx::ObjectPtr< AbstractNativeElementManagerImpl_obj > result = new AbstractNativeElementManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractNativeElementManagerImpl_obj > result = new AbstractNativeElementManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic AbstractNativeElementManagerImpl_obj::getRoot( ){
	HX_SOURCE_PUSH("AbstractNativeElementManagerImpl_obj::getRoot")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/AbstractNativeElementManagerImpl.hx",34)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractNativeElementManagerImpl_obj,getRoot,return )

Dynamic AbstractNativeElementManagerImpl_obj::createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("AbstractNativeElementManagerImpl_obj::createNativeElement")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/AbstractNativeElementManagerImpl.hx",43)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractNativeElementManagerImpl_obj,createNativeElement,return )


AbstractNativeElementManagerImpl_obj::AbstractNativeElementManagerImpl_obj()
{
}

void AbstractNativeElementManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractNativeElementManagerImpl);
	HX_MARK_END_CLASS();
}

Dynamic AbstractNativeElementManagerImpl_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getRoot") ) { return getRoot_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createNativeElement") ) { return createNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractNativeElementManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractNativeElementManagerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getRoot"),
	HX_CSTRING("createNativeElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractNativeElementManagerImpl_obj::__mClass;

void AbstractNativeElementManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.nativeElement.AbstractNativeElementManagerImpl"), hx::TCanCast< AbstractNativeElementManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractNativeElementManagerImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement
