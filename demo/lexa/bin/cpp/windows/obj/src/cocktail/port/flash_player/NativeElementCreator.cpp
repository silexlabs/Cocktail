#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementCreator
#include <cocktail/core/nativeElement/AbstractNativeElementCreator.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_NativeElementCreator
#include <cocktail/port/flash_player/NativeElementCreator.h>
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
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
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

Void NativeElementCreator_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",31)
	super::__construct();
}
;
	return null();
}

NativeElementCreator_obj::~NativeElementCreator_obj() { }

Dynamic NativeElementCreator_obj::__CreateEmpty() { return  new NativeElementCreator_obj; }
hx::ObjectPtr< NativeElementCreator_obj > NativeElementCreator_obj::__new()
{  hx::ObjectPtr< NativeElementCreator_obj > result = new NativeElementCreator_obj();
	result->__construct();
	return result;}

Dynamic NativeElementCreator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeElementCreator_obj > result = new NativeElementCreator_obj();
	result->__construct();
	return result;}

Dynamic NativeElementCreator_obj::createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType){
	HX_SOURCE_PUSH("NativeElementCreator_obj::createNativeElement")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",41)
	Dynamic nativeElement;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",43)
	{
::cocktail::core::nativeElement::NativeElementTypeValue _switch_1 = (nativeElementType);
		switch((_switch_1)->GetIndex()){
			case 3: case 4: case 5: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",46)
				nativeElement = ::nme::display::Loader_obj::__new();
			}
			;break;
			case 2: case 1: case 0: case 6: case 7: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",50)
				nativeElement = ::nme::display::Sprite_obj::__new();
			}
			;break;
			case 8: {
				::String name = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",52)
					nativeElement = ::nme::display::Sprite_obj::__new();
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/NativeElementCreator.hx",57)
	return nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeElementCreator_obj,createNativeElement,return )


NativeElementCreator_obj::NativeElementCreator_obj()
{
}

void NativeElementCreator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeElementCreator);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic NativeElementCreator_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"createNativeElement") ) { return createNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic NativeElementCreator_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void NativeElementCreator_obj::__GetFields(Array< ::String> &outFields)
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

Class NativeElementCreator_obj::__mClass;

void NativeElementCreator_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.NativeElementCreator"), hx::TCanCast< NativeElementCreator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void NativeElementCreator_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
