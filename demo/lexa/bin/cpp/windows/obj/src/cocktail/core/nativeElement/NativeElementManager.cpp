#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementCreator
#include <cocktail/core/nativeElement/AbstractNativeElementCreator.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementPathManager
#include <cocktail/core/nativeElement/AbstractNativeElementPathManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementCreator
#include <cocktail/port/flash_player/NativeElementCreator.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementPathManager
#include <cocktail/port/flash_player/NativeElementPathManager.h>
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

::cocktail::port::flash_player::NativeElementCreator NativeElementManager_obj::_nativeElementCreator;

::cocktail::port::flash_player::NativeElementPathManager NativeElementManager_obj::_nativeElementPathManager;

Dynamic NativeElementManager_obj::getRoot( ){
	HX_SOURCE_PUSH("NativeElementManager_obj::getRoot")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",72)
	if (((::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementPathManager == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",73)
		::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementPathManager = ::cocktail::port::flash_player::NativeElementPathManager_obj::__new();
	}
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",76)
	return ::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementPathManager->getRoot();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(NativeElementManager_obj,getRoot,return )

Dynamic NativeElementManager_obj::createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("NativeElementManager_obj::createNativeElement")
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",86)
	if (((::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementCreator == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",87)
		::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementCreator = ::cocktail::port::flash_player::NativeElementCreator_obj::__new();
	}
	HX_SOURCE_POS("../../src/cocktail/core/nativeElement/NativeElementManager.hx",91)
	return ::cocktail::core::nativeElement::NativeElementManager_obj::_nativeElementCreator->createNativeElement(nativeElementType);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(NativeElementManager_obj,createNativeElement,return )


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
	case 7:
		if (HX_FIELD_EQ(inName,"getRoot") ) { return getRoot_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"createNativeElement") ) { return createNativeElement_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_nativeElementCreator") ) { return _nativeElementCreator; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_nativeElementPathManager") ) { return _nativeElementPathManager; }
	}
	return super::__Field(inName);
}

Dynamic NativeElementManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"_nativeElementCreator") ) { _nativeElementCreator=inValue.Cast< ::cocktail::port::flash_player::NativeElementCreator >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_nativeElementPathManager") ) { _nativeElementPathManager=inValue.Cast< ::cocktail::port::flash_player::NativeElementPathManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void NativeElementManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_nativeElementCreator"),
	HX_CSTRING("_nativeElementPathManager"),
	HX_CSTRING("getRoot"),
	HX_CSTRING("createNativeElement"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeElementManager_obj::_nativeElementCreator,"_nativeElementCreator");
	HX_MARK_MEMBER_NAME(NativeElementManager_obj::_nativeElementPathManager,"_nativeElementPathManager");
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
	hx::Static(_nativeElementCreator);
	hx::Static(_nativeElementPathManager);
}

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement
