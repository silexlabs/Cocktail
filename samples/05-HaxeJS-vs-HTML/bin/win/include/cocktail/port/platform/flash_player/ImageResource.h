#ifndef INCLUDED_cocktail_port_platform_flash_player_ImageResource
#define INCLUDED_cocktail_port_platform_flash_player_ImageResource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/resource/AbstractResource.h>
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,ImageResource)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Loader)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,ErrorEvent)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,events,IOErrorEvent)
HX_DECLARE_CLASS2(native,events,TextEvent)
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

		virtual Void getBitmapDataFromLoader( ::native::display::Loader loader);
		Dynamic getBitmapDataFromLoader_dyn();

		virtual Void setNativeResource( ::native::display::Loader loader);
		Dynamic setNativeResource_dyn();

		virtual Void setIntrinsicDimensions( ::native::display::Loader loader);
		Dynamic setIntrinsicDimensions_dyn();

		virtual Void removeLoaderListeners( ::native::display::Loader loader);
		Dynamic removeLoaderListeners_dyn();

		virtual Void onNativeLoadIOError( ::native::events::IOErrorEvent event);
		Dynamic onNativeLoadIOError_dyn();

		virtual Void onNativeLoadComplete( ::native::events::Event event);
		Dynamic onNativeLoadComplete_dyn();

		virtual Void load( ::String url);

		::native::display::Loader _loader; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_ImageResource */ 
