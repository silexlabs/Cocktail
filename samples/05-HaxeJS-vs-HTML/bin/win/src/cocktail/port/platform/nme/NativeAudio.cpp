#include <hxcpp.h>

#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeAudio
#include <cocktail/port/platform/flash_player/NativeAudio.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeAudio
#include <cocktail/port/platform/nme/NativeAudio.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_media_Sound
#include <native/media/Sound.h>
#endif
#ifndef INCLUDED_nme_Assets
#include <nme/Assets.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace nme{

Void NativeAudio_obj::__construct()
{
HX_STACK_PUSH("NativeAudio::new","cocktail/port/platform/nme/NativeAudio.hx",24);
{
	HX_STACK_LINE(24)
	super::__construct();
}
;
	return null();
}

NativeAudio_obj::~NativeAudio_obj() { }

Dynamic NativeAudio_obj::__CreateEmpty() { return  new NativeAudio_obj; }
hx::ObjectPtr< NativeAudio_obj > NativeAudio_obj::__new()
{  hx::ObjectPtr< NativeAudio_obj > result = new NativeAudio_obj();
	result->__construct();
	return result;}

Dynamic NativeAudio_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeAudio_obj > result = new NativeAudio_obj();
	result->__construct();
	return result;}

Void NativeAudio_obj::initSound( ::String src){
{
		HX_STACK_PUSH("NativeAudio::initSound","cocktail/port/platform/nme/NativeAudio.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(src,"src");
		HX_STACK_LINE(38)
		::native::media::Sound asset = ::nme::Assets_obj::getSound(src);		HX_STACK_VAR(asset,"asset");
		HX_STACK_LINE(41)
		if (((asset != null()))){
			HX_STACK_LINE(43)
			this->_sound = asset;
			HX_STACK_LINE(44)
			this->onNativeLoadedMetaData();
		}
		else{
			HX_STACK_LINE(47)
			this->super::initSound(src);
		}
	}
return null();
}



NativeAudio_obj::NativeAudio_obj()
{
}

void NativeAudio_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeAudio);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeAudio_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeAudio_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"initSound") ) { return initSound_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeAudio_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeAudio_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initSound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeAudio_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeAudio_obj::__mClass,"__mClass");
};

Class NativeAudio_obj::__mClass;

void NativeAudio_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.nme.NativeAudio"), hx::TCanCast< NativeAudio_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeAudio_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme
