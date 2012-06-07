#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractMediaLoader
#include <cocktail/core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResourceLoader
#include <cocktail/core/resource/AbstractResourceLoader.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_MediaLoader
#include <cocktail/port/flash_player/MediaLoader.h>
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
#ifndef INCLUDED_nme_display_LoaderInfo
#include <nme/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_ErrorEvent
#include <nme/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IOErrorEvent
#include <nme/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
#ifndef INCLUDED_nme_net_URLLoader
#include <nme/net/URLLoader.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void MediaLoader_obj::__construct(Dynamic nativeElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",38)
	super::__construct(nativeElement);
}
;
	return null();
}

MediaLoader_obj::~MediaLoader_obj() { }

Dynamic MediaLoader_obj::__CreateEmpty() { return  new MediaLoader_obj; }
hx::ObjectPtr< MediaLoader_obj > MediaLoader_obj::__new(Dynamic nativeElement)
{  hx::ObjectPtr< MediaLoader_obj > result = new MediaLoader_obj();
	result->__construct(nativeElement);
	return result;}

Dynamic MediaLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MediaLoader_obj > result = new MediaLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

Void MediaLoader_obj::doLoad( ::String url){
{
		HX_SOURCE_PUSH("MediaLoader_obj::doLoad")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",52)
		::nme::display::Loader loader = this->_nativeElement;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",54)
		loader->unload();
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",57)
		loader->contentLoaderInfo->addEventListener(::nme::events::Event_obj::COMPLETE,this->onNativeLoadComplete_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",58)
		loader->contentLoaderInfo->addEventListener(::nme::events::IOErrorEvent_obj::IO_ERROR,this->onNativeLoadIOError_dyn(),null(),null(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",61)
		::nme::net::URLRequest request = ::nme::net::URLRequest_obj::__new(url);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",73)
		loader->load(request);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaLoader_obj,doLoad,(void))

Void MediaLoader_obj::onNativeLoadComplete( ::nme::events::Event event){
{
		HX_SOURCE_PUSH("MediaLoader_obj::onNativeLoadComplete")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",88)
		::nme::display::Loader loader = this->_nativeElement;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",89)
		this->removeLoaderListeners(loader);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",90)
		this->setIntrinsicDimensions(loader);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",91)
		this->onLoadComplete(loader);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaLoader_obj,onNativeLoadComplete,(void))

Void MediaLoader_obj::onNativeLoadIOError( ::nme::events::IOErrorEvent event){
{
		HX_SOURCE_PUSH("MediaLoader_obj::onNativeLoadIOError")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",101)
		::nme::display::Loader loader = this->_nativeElement;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",102)
		this->removeLoaderListeners(loader);
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",103)
		this->onLoadError(event->toString());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaLoader_obj,onNativeLoadIOError,(void))

Void MediaLoader_obj::removeLoaderListeners( ::nme::display::Loader loader){
{
		HX_SOURCE_PUSH("MediaLoader_obj::removeLoaderListeners")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",115)
		loader->contentLoaderInfo->removeEventListener(::nme::events::Event_obj::COMPLETE,this->onNativeLoadComplete_dyn(),null());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",116)
		loader->contentLoaderInfo->removeEventListener(::nme::events::IOErrorEvent_obj::IO_ERROR,this->onNativeLoadIOError_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaLoader_obj,removeLoaderListeners,(void))

Void MediaLoader_obj::setIntrinsicDimensions( ::nme::display::Loader loader){
{
		HX_SOURCE_PUSH("MediaLoader_obj::setIntrinsicDimensions")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",125)
		this->_intrinsicHeight = ::Math_obj::round(loader->content->nmeGetHeight());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",126)
		this->_intrinsicWidth = ::Math_obj::round(loader->content->nmeGetWidth());
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/MediaLoader.hx",127)
		this->_intrinsicRatio = (double(this->_intrinsicWidth) / double(this->_intrinsicHeight));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MediaLoader_obj,setIntrinsicDimensions,(void))


MediaLoader_obj::MediaLoader_obj()
{
}

void MediaLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MediaLoader);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MediaLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"doLoad") ) { return doLoad_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onNativeLoadIOError") ) { return onNativeLoadIOError_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onNativeLoadComplete") ) { return onNativeLoadComplete_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeLoaderListeners") ) { return removeLoaderListeners_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"setIntrinsicDimensions") ) { return setIntrinsicDimensions_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MediaLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void MediaLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doLoad"),
	HX_CSTRING("onNativeLoadComplete"),
	HX_CSTRING("onNativeLoadIOError"),
	HX_CSTRING("removeLoaderListeners"),
	HX_CSTRING("setIntrinsicDimensions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MediaLoader_obj::__mClass;

void MediaLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.MediaLoader"), hx::TCanCast< MediaLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MediaLoader_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
