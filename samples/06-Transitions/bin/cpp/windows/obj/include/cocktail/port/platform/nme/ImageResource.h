#ifndef INCLUDED_cocktail_port_platform_nme_ImageResource
#define INCLUDED_cocktail_port_platform_nme_ImageResource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/platform/flash_player/ImageResource.h>
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,ImageResource)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,ImageResource)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Loader)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace cocktail{
namespace port{
namespace platform{
namespace nme{


class ImageResource_obj : public ::cocktail::port::platform::flash_player::ImageResource_obj{
	public:
		typedef ::cocktail::port::platform::flash_player::ImageResource_obj super;
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

		virtual Void setIntrinsicDimensions( ::neash::display::Loader loader);

		virtual Void load( ::String url);

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme

#endif /* INCLUDED_cocktail_port_platform_nme_ImageResource */ 
