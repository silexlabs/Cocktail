#ifndef INCLUDED_cocktail_port_platform_flash_player_ImageResource
#define INCLUDED_cocktail_port_platform_flash_player_ImageResource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/resource/AbstractResource.h>
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,ImageResource)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Loader)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,ErrorEvent)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,IOErrorEvent)
HX_DECLARE_CLASS2(neash,events,TextEvent)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class ImageResource_obj : public ::cocktail::core::resource::AbstractResource_obj{
	public:
		typedef ::cocktail::core::resource::AbstractResource_obj super;
		typedef ImageResource_obj OBJ_;
		ImageResource_obj();
		Void __construct(::String url);

	public:
		static hx::ObjectPtr< ImageResource_obj > __new(::String url);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ImageResource_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ImageResource"); }

		virtual Void onChildAllowsParentTick( );
		Dynamic onChildAllowsParentTick_dyn();

		virtual Void getBitmapDataFromLoader( ::neash::display::Loader loader);
		Dynamic getBitmapDataFromLoader_dyn();

		virtual Void setNativeResource( ::neash::display::Loader loader);
		Dynamic setNativeResource_dyn();

		virtual Void setIntrinsicDimensions( ::neash::display::Loader loader);
		Dynamic setIntrinsicDimensions_dyn();

		virtual Void removeLoaderListeners( ::neash::display::Loader loader);
		Dynamic removeLoaderListeners_dyn();

		virtual Void onNativeLoadIOError( ::neash::events::IOErrorEvent event);
		Dynamic onNativeLoadIOError_dyn();

		virtual Void onNativeLoadComplete( ::neash::events::Event event);
		Dynamic onNativeLoadComplete_dyn();

		virtual Void load( ::String url);

		::neash::display::Loader _loader; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_ImageResource */ 
