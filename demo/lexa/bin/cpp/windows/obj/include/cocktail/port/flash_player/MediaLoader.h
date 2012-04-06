#ifndef INCLUDED_cocktail_port_flash_player_MediaLoader
#define INCLUDED_cocktail_port_flash_player_MediaLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/resource/AbstractMediaLoader.h>
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MediaLoader)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Loader)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,ErrorEvent)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,IOErrorEvent)
HX_DECLARE_CLASS2(nme,events,TextEvent)
namespace cocktail{
namespace port{
namespace flash_player{


class MediaLoader_obj : public ::cocktail::core::resource::AbstractMediaLoader_obj{
	public:
		typedef ::cocktail::core::resource::AbstractMediaLoader_obj super;
		typedef MediaLoader_obj OBJ_;
		MediaLoader_obj();
		Void __construct(Dynamic nativeElement);

	public:
		static hx::ObjectPtr< MediaLoader_obj > __new(Dynamic nativeElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MediaLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MediaLoader"); }

		virtual Void doLoad( ::String url);
		Dynamic doLoad_dyn();

		virtual Void onNativeLoadComplete( ::nme::events::Event event);
		Dynamic onNativeLoadComplete_dyn();

		virtual Void onNativeLoadIOError( ::nme::events::IOErrorEvent event);
		Dynamic onNativeLoadIOError_dyn();

		virtual Void removeLoaderListeners( ::nme::display::Loader loader);
		Dynamic removeLoaderListeners_dyn();

		virtual Void setIntrinsicDimensions( ::nme::display::Loader loader);
		Dynamic setIntrinsicDimensions_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_MediaLoader */ 
