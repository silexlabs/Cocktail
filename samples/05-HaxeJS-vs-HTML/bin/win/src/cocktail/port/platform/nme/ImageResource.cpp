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
#ifndef INCLUDED_cocktail_port_platform_nme_ImageResource
#include <cocktail/port/platform/nme/ImageResource.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Loader
#include <native/display/Loader.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_Assets
#include <nme/Assets.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace nme{

Void ImageResource_obj::__construct(::String url)
{
HX_STACK_PUSH("ImageResource::new","cocktail/port/platform/nme/ImageResource.hx",25);
{
	HX_STACK_LINE(25)
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

Void ImageResource_obj::setIntrinsicDimensions( ::native::display::Loader loader){
{
		HX_STACK_PUSH("ImageResource::setIntrinsicDimensions","cocktail/port/platform/nme/ImageResource.hx",65);
		HX_STACK_THIS(this);
		HX_STACK_ARG(loader,"loader");
		HX_STACK_LINE(66)
		this->intrinsicHeight = ::Math_obj::round(loader->get_height());
		HX_STACK_LINE(67)
		this->intrinsicWidth = ::Math_obj::round(loader->get_width());
		HX_STACK_LINE(68)
		this->intrinsicRatio = (Float(this->intrinsicWidth) / Float(this->intrinsicHeight));
	}
return null();
}


Void ImageResource_obj::load( ::String url){
{
		HX_STACK_PUSH("ImageResource::load","cocktail/port/platform/nme/ImageResource.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(39)
		::native::display::BitmapData asset = ::nme::Assets_obj::getBitmapData(url,null());		HX_STACK_VAR(asset,"asset");
		HX_STACK_LINE(43)
		if (((asset != null()))){
			HX_STACK_LINE(45)
			this->nativeResource = asset;
			HX_STACK_LINE(46)
			this->intrinsicHeight = asset->get_height();
			HX_STACK_LINE(47)
			this->intrinsicWidth = asset->get_width();
			HX_STACK_LINE(48)
			this->intrinsicRatio = (Float(this->intrinsicWidth) / Float(this->intrinsicHeight));
			HX_STACK_LINE(49)
			this->onLoadComplete();
		}
		else{
			HX_STACK_LINE(52)
			this->super::load(url);
		}
	}
return null();
}



ImageResource_obj::ImageResource_obj()
{
}

void ImageResource_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ImageResource);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ImageResource_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ImageResource_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"setIntrinsicDimensions") ) { return setIntrinsicDimensions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ImageResource_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void ImageResource_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setIntrinsicDimensions"),
	HX_CSTRING("load"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.nme.ImageResource"), hx::TCanCast< ImageResource_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ImageResource_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme
