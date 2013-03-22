#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_ImageResource
#include <cocktail/port/platform/flash_player/ImageResource.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_BitmapData
#include <neash/display/BitmapData.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Loader
#include <neash/display/Loader.h>
#endif
#ifndef INCLUDED_neash_display_LoaderInfo
#include <neash/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_events_ErrorEvent
#include <neash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IOErrorEvent
#include <neash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_neash_events_TextEvent
#include <neash/events/TextEvent.h>
#endif
#ifndef INCLUDED_neash_net_URLLoader
#include <neash/net/URLLoader.h>
#endif
#ifndef INCLUDED_neash_net_URLRequest
#include <neash/net/URLRequest.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void ImageResource_obj::__construct(::String url)
{
HX_STACK_PUSH("ImageResource::new","cocktail/port/platform/flash_player/ImageResource.hx",46);
{
	HX_STACK_LINE(47)
	this->_loader = ::neash::display::Loader_obj::__new();
	HX_STACK_LINE(48)
	super::__construct(url);
}
;
	return null();
}

ImageResource_obj::~ImageResource_obj() { }

Dynamic ImageResource_obj::__CreateEmpty() { return  new ImageResource_obj; }
hx::ObjectPtr< ImageResource_obj > ImageResource_obj::__new(::String url)
{  hx::ObjectPtr< ImageResource_obj > result = new ImageResource_obj();
	result->__construct(url);
	return result;}

Dynamic ImageResource_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ImageResource_obj > result = new ImageResource_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ImageResource_obj::onChildAllowsParentTick( ){
{
		HX_STACK_PUSH("ImageResource::onChildAllowsParentTick","cocktail/port/platform/flash_player/ImageResource.hx",194);
		HX_STACK_THIS(this);
		HX_STACK_LINE(193)
		Array< ::cocktail::port::platform::flash_player::ImageResource > _g = Array_obj< ::cocktail::port::platform::flash_player::ImageResource >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(197)
		if (((this->_loader->contentLoaderInfo->childAllowsParent == false))){

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::cocktail::port::platform::flash_player::ImageResource >,_g)
			Void run(){
				HX_STACK_PUSH("*::_Function_2_1","cocktail/port/platform/flash_player/ImageResource.hx",199);
				{
					HX_STACK_LINE(199)
					_g->__get((int)0)->onChildAllowsParentTick();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0((void))

			HX_STACK_LINE(198)
			::haxe::Timer_obj::delay( Dynamic(new _Function_2_1(_g)),(int)50);
		}
		else{
			HX_STACK_LINE(203)
			this->getBitmapDataFromLoader(this->_loader);
			HX_STACK_LINE(204)
			this->onLoadComplete();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ImageResource_obj,onChildAllowsParentTick,(void))

Void ImageResource_obj::getBitmapDataFromLoader( ::neash::display::Loader loader){
{
		HX_STACK_PUSH("ImageResource::getBitmapDataFromLoader","cocktail/port/platform/flash_player/ImageResource.hx",182);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(183)
		::neash::display::Bitmap bitmap = loader->content;		HX_STACK_VAR(bitmap,"bitmap");
		HX_STACK_LINE(184)
		this->nativeResource = bitmap->bitmapData;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,getBitmapDataFromLoader,(void))

Void ImageResource_obj::setNativeResource( ::neash::display::Loader loader){
{
		HX_STACK_PUSH("ImageResource::setNativeResource","cocktail/port/platform/flash_player/ImageResource.hx",150);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(150)
		if (((loader->contentLoaderInfo->childAllowsParent == true))){
			HX_STACK_LINE(156)
			this->getBitmapDataFromLoader(loader);
			HX_STACK_LINE(157)
			this->onLoadComplete();
		}
		else{
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,setNativeResource,(void))

Void ImageResource_obj::setIntrinsicDimensions( ::neash::display::Loader loader){
{
		HX_STACK_PUSH("ImageResource::setIntrinsicDimensions","cocktail/port/platform/flash_player/ImageResource.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(137)
		this->intrinsicHeight = ::Math_obj::round(loader->contentLoaderInfo->height);
		HX_STACK_LINE(138)
		this->intrinsicWidth = ::Math_obj::round(loader->contentLoaderInfo->width);
		HX_STACK_LINE(139)
		this->intrinsicRatio = (Float(this->intrinsicWidth) / Float(this->intrinsicHeight));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,setIntrinsicDimensions,(void))

Void ImageResource_obj::removeLoaderListeners( ::neash::display::Loader loader){
{
		HX_STACK_PUSH("ImageResource::removeLoaderListeners","cocktail/port/platform/flash_player/ImageResource.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(127)
		loader->contentLoaderInfo->removeEventListener(::neash::events::Event_obj::COMPLETE,this->onNativeLoadComplete_dyn(),null());
		HX_STACK_LINE(128)
		loader->contentLoaderInfo->removeEventListener(::neash::events::IOErrorEvent_obj::IO_ERROR,this->onNativeLoadIOError_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,removeLoaderListeners,(void))

Void ImageResource_obj::onNativeLoadIOError( ::neash::events::IOErrorEvent event){
{
		HX_STACK_PUSH("ImageResource::onNativeLoadIOError","cocktail/port/platform/flash_player/ImageResource.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(114)
		this->removeLoaderListeners(this->_loader);
		HX_STACK_LINE(115)
		this->onLoadError();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,onNativeLoadIOError,(void))

Void ImageResource_obj::onNativeLoadComplete( ::neash::events::Event event){
{
		HX_STACK_PUSH("ImageResource::onNativeLoadComplete","cocktail/port/platform/flash_player/ImageResource.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(103)
		this->removeLoaderListeners(this->_loader);
		HX_STACK_LINE(104)
		this->setIntrinsicDimensions(this->_loader);
		HX_STACK_LINE(105)
		this->setNativeResource(this->_loader);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ImageResource_obj,onNativeLoadComplete,(void))

Void ImageResource_obj::load( ::String url){
{
		HX_STACK_PUSH("ImageResource::load","cocktail/port/platform/flash_player/ImageResource.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(61)
		this->_loader->unload();
		HX_STACK_LINE(64)
		this->_loader->contentLoaderInfo->addEventListener(::neash::events::Event_obj::COMPLETE,this->onNativeLoadComplete_dyn(),null(),null(),null());
		HX_STACK_LINE(65)
		this->_loader->contentLoaderInfo->addEventListener(::neash::events::IOErrorEvent_obj::IO_ERROR,this->onNativeLoadIOError_dyn(),null(),null(),null());
		HX_STACK_LINE(68)
		::neash::net::URLRequest request = ::neash::net::URLRequest_obj::__new(url);		HX_STACK_VAR(request,"request");
		HX_STACK_LINE(88)
		this->_loader->load(request);
	}
return null();
}



ImageResource_obj::ImageResource_obj()
{
}

void ImageResource_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ImageResource);
	HX_MARK_MEMBER_NAME(_loader,"_loader");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ImageResource_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_loader,"_loader");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ImageResource_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_loader") ) { return _loader; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setNativeResource") ) { return setNativeResource_dyn(); }
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
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"onChildAllowsParentTick") ) { return onChildAllowsParentTick_dyn(); }
		if (HX_FIELD_EQ(inName,"getBitmapDataFromLoader") ) { return getBitmapDataFromLoader_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ImageResource_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_loader") ) { _loader=inValue.Cast< ::neash::display::Loader >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ImageResource_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_loader"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onChildAllowsParentTick"),
	HX_CSTRING("getBitmapDataFromLoader"),
	HX_CSTRING("setNativeResource"),
	HX_CSTRING("setIntrinsicDimensions"),
	HX_CSTRING("removeLoaderListeners"),
	HX_CSTRING("onNativeLoadIOError"),
	HX_CSTRING("onNativeLoadComplete"),
	HX_CSTRING("load"),
	HX_CSTRING("_loader"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ImageResource_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ImageResource_obj::__mClass,"__mClass");
};

Class ImageResource_obj::__mClass;

void ImageResource_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.ImageResource"), hx::TCanCast< ImageResource_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ImageResource_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
