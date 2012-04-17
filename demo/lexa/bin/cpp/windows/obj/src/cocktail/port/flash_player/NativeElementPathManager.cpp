#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementPathManager
#include <cocktail/core/nativeElement/AbstractNativeElementPathManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementPathManager
#include <cocktail/port/flash_player/NativeElementPathManager.h>
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

Void NativeElementPathManager_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementPathManager.hx",26)
	super::__construct();
}
;
	return null();
}

NativeElementPathManager_obj::~NativeElementPathManager_obj() { }

Dynamic NativeElementPathManager_obj::__CreateEmpty() { return  new NativeElementPathManager_obj; }
hx::ObjectPtr< NativeElementPathManager_obj > NativeElementPathManager_obj::__new()
{  hx::ObjectPtr< NativeElementPathManager_obj > result = new NativeElementPathManager_obj();
	result->__construct();
	return result;}

Dynamic NativeElementPathManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeElementPathManager_obj > result = new NativeElementPathManager_obj();
	result->__construct();
	return result;}

Dynamic NativeElementPathManager_obj::getRoot( ){
	HX_SOURCE_PUSH("NativeElementPathManager_obj::getRoot")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementPathManager.hx",34)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeElementPathManager_obj,getRoot,return )


NativeElementPathManager_obj::NativeElementPathManager_obj()
{
}

void NativeElementPathManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeElementPathManager);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic NativeElementPathManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getRoot") ) { return getRoot_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NativeElementPathManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void NativeElementPathManager_obj::__GetFields(Array< ::String> &outFields)
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

Class NativeElementPathManager_obj::__mClass;

void NativeElementPathManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.NativeElementPathManager"), hx::TCanCast< NativeElementPathManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeElementPathManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
