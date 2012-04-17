#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl
#include <cocktail/core/nativeElement/AbstractNativeElementManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementManagerImpl
#include <cocktail/port/flash_player/NativeElementManagerImpl.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Loader
#include <nme/display/Loader.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void NativeElementManagerImpl_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",29)
	super::__construct();
}
;
	return null();
}

NativeElementManagerImpl_obj::~NativeElementManagerImpl_obj() { }

Dynamic NativeElementManagerImpl_obj::__CreateEmpty() { return  new NativeElementManagerImpl_obj; }
hx::ObjectPtr< NativeElementManagerImpl_obj > NativeElementManagerImpl_obj::__new()
{  hx::ObjectPtr< NativeElementManagerImpl_obj > result = new NativeElementManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic NativeElementManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeElementManagerImpl_obj > result = new NativeElementManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic NativeElementManagerImpl_obj::getRoot( ){
	HX_SOURCE_PUSH("NativeElementManagerImpl_obj::getRoot")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",37)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeElementManagerImpl_obj,getRoot,return )

Dynamic NativeElementManagerImpl_obj::createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("NativeElementManagerImpl_obj::createNativeElement")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",47)
	Dynamic nativeElement;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",49)
	{
::cocktail::core::nativeElement::NativeElementTypeValue _switch_1 = (nativeElementType);
		switch((_switch_1)->GetIndex()){
			case 1: case 2: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",53)
				nativeElement = ::nme::display::Loader_obj::__new();
			}
			;break;
			case 0: case 3: case 4: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",57)
				nativeElement = ::nme::display::Sprite_obj::__new();
			}
			;break;
			case 5: {
				::String name = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",59)
					nativeElement = ::nme::display::Sprite_obj::__new();
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementManagerImpl.hx",64)
	return nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeElementManagerImpl_obj,createNativeElement,return )


NativeElementManagerImpl_obj::NativeElementManagerImpl_obj()
{
}

void NativeElementManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeElementManagerImpl);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic NativeElementManagerImpl_obj::__Field(const ::String &inName)
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

Dynamic NativeElementManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void NativeElementManagerImpl_obj::__GetFields(Array< ::String> &outFields)
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

Class NativeElementManagerImpl_obj::__mClass;

void NativeElementManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.NativeElementManagerImpl"), hx::TCanCast< NativeElementManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeElementManagerImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
