#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl
#include <cocktail/core/nativeElement/AbstractNativeElementManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementManagerImpl
#include <cocktail/port/flash_player/NativeElementManagerImpl.h>
#endif
namespace cocktail{
namespace core{
namespace nativeElement{

Void NativeElementManager_obj::__construct()
{
{
}
;
	return null();
}

NativeElementManager_obj::~NativeElementManager_obj() { }

Dynamic NativeElementManager_obj::__CreateEmpty() { return  new NativeElementManager_obj; }
hx::ObjectPtr< NativeElementManager_obj > NativeElementManager_obj::__new()
{  hx::ObjectPtr< NativeElementManager_obj > result = new NativeElementManager_obj();
	result->__construct();
	return result;}

Dynamic NativeElementManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeElementManager_obj > result = new NativeElementManager_obj();
	result->__construct();
	return result;}

::cocktail::port::flash_player::NativeElementManagerImpl NativeElementManager_obj::_nativeElementManagerImpl;

Dynamic NativeElementManager_obj::getRoot( ){
	HX_SOURCE_PUSH("NativeElementManager_obj::getRoot")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",48)
	if (((::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementManagerImpl == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",49)
		::cocktail::core::nativeElement::NativeElementManager_obj::init();
	}
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",52)
	return ::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementManagerImpl->getRoot();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NativeElementManager_obj,getRoot,return )

Dynamic NativeElementManager_obj::createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("NativeElementManager_obj::createNativeElement")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",62)
	if (((::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementManagerImpl == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",63)
		::cocktail::core::nativeElement::NativeElementManager_obj::init();
	}
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",66)
	return ::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementManagerImpl->createNativeElement(nativeElementType);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NativeElementManager_obj,createNativeElement,return )

Void NativeElementManager_obj::init( ){
{
		HX_SOURCE_PUSH("NativeElementManager_obj::init")
		HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",74)
		::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementManagerImpl = ::cocktail::port::flash_player::NativeElementManagerImpl_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NativeElementManager_obj,init,(void))


NativeElementManager_obj::NativeElementManager_obj()
{
}

void NativeElementManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeElementManager);
	HX_MARK_END_CLASS();
}

Dynamic NativeElementManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getRoot") ) { return getRoot_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createNativeElement") ) { return createNativeElement_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_nativeElementManagerImpl") ) { return _nativeElementManagerImpl; }
	}
	return super::__Field(inName);
}

Dynamic NativeElementManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 25:
		if (HX_FIELD_EQ(inName,"_nativeElementManagerImpl") ) { _nativeElementManagerImpl=inValue.Cast< ::cocktail::port::flash_player::NativeElementManagerImpl >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NativeElementManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_nativeElementManagerImpl"),
	HX_CSTRING("getRoot"),
	HX_CSTRING("createNativeElement"),
	HX_CSTRING("init"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeElementManager_obj::_nativeElementManagerImpl,"_nativeElementManagerImpl");
};

Class NativeElementManager_obj::__mClass;

void NativeElementManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.nativeElement.NativeElementManager"), hx::TCanCast< NativeElementManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeElementManager_obj::__boot()
{
	hx::Static(_nativeElementManagerImpl);
}

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement
