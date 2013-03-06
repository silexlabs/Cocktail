#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#define INCLUDED_cocktail_port_platform_flash_player_Platform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/PlatformBase.h>
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,stacking,StackingContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class Platform_obj : public ::cocktail::port::base::PlatformBase_obj{
	public:
		typedef ::cocktail::port::base::PlatformBase_obj super;
		typedef Platform_obj OBJ_;
		Platform_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Platform_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Platform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Platform"); }

		virtual Void hitTestChildrenInSameStackingContext( ::cocktail::core::layer::LayerRenderer rootLayer);
		Dynamic hitTestChildrenInSameStackingContext_dyn();

		virtual Void doUpdateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext);
		Dynamic doUpdateHitTestingBounds_dyn();

		virtual Void hitTestLayer( ::cocktail::core::layer::LayerRenderer layerRenderer);
		Dynamic hitTestLayer_dyn();

		virtual Void fillHitTestingSprite( ::cocktail::core::geom::RectangleVO rect);
		Dynamic fillHitTestingSprite_dyn();

		virtual Void resetHitTestingSprite( );
		Dynamic resetHitTestingSprite_dyn();

		virtual int get_innerWidth( );

		virtual int get_innerHeight( );

		virtual Void updateHitTestingSprite( );
		Dynamic updateHitTestingSprite_dyn();

		virtual Void onNativeResize( Dynamic event);

		virtual ::cocktail::core::event::Event getEvent( Dynamic event);

		virtual ::cocktail::core::event::UIEvent getUIEvent( Dynamic event);

		virtual Void removeNativeListeners( );

		virtual Void setNativeListeners( );

		virtual Void updateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext);

		virtual ::native::display::DisplayObjectContainer getInitialNativeLayer( );

		virtual bool fullscreen( );

		virtual bool fullScreenEnabled( );

		virtual Void exitFullscreen( );

		virtual Void enterFullscreen( );

		virtual Void open( ::String url,::String name);

		virtual Void initDisplayList( );
		Dynamic initDisplayList_dyn();

		bool _foundObjectTag; /* REM */ 
		Array< ::cocktail::core::geom::RectangleVO > _objectTagsBounds; /* REM */ 
		::native::display::Sprite hitTestingSprite; /* REM */ 
		::native::display::Sprite _nativeLayersRootSprite; /* REM */ 
		::native::display::Sprite _rootSprite; /* REM */ 
		static ::String ALLOW_FULLSCREEN_ATTRIBUTE; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_Platform */ 
