#ifndef INCLUDED_cocktail_plugin_swf_SWFPlugin
#define INCLUDED_cocktail_plugin_swf_SWFPlugin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/plugin/Plugin.h>
HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS2(cocktail,plugin,Plugin)
HX_DECLARE_CLASS3(cocktail,plugin,swf,SWFPlugin)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,display,Loader)
HX_DECLARE_CLASS2(native,display,Sprite)
HX_DECLARE_CLASS2(native,events,Event)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace cocktail{
namespace plugin{
namespace swf{


class SWFPlugin_obj : public ::cocktail::plugin::Plugin_obj{
	public:
		typedef ::cocktail::plugin::Plugin_obj super;
		typedef SWFPlugin_obj OBJ_;
		SWFPlugin_obj();
		Void __construct(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError);

	public:
		static hx::ObjectPtr< SWFPlugin_obj > __new(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SWFPlugin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SWFPlugin"); }

		virtual Void onLoaderReady( ::native::display::Loader loader);
		Dynamic onLoaderReady_dyn();

		virtual Void onSWFLoadComplete( ::native::events::Event event);
		Dynamic onSWFLoadComplete_dyn();

		virtual Void updateViewport( Float x,Float y,Float width,Float height);

		virtual bool isCompositedPlugin( );

		virtual Void dispose( );

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicsContext);

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicsContext);

		virtual Void parseQueryString( Dynamic data,::String queryString);
		Dynamic parseQueryString_dyn();

		virtual Dynamic getLoaderContextParams( );
		Dynamic getLoaderContextParams_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		bool _isAVM1swf; /* REM */ 
		bool _swfAddedToStage; /* REM */ 
		::native::display::Sprite _mask; /* REM */ 
		::native::display::Loader _loader; /* REM */ 
		Float _swfWidth; /* REM */ 
		Float _swfHeight; /* REM */ 
		::cocktail::core::geom::RectangleVO _swfBounds; /* REM */ 
		::native::display::DisplayObject _swf; /* REM */ 
		::String _scaleMode; /* REM */ 
		static ::String NO_SCALE; /* REM */ 
		static ::String SHOW_ALL; /* REM */ 
		static ::String EXACT_FIT; /* REM */ 
		static ::String SCALE_MODE; /* REM */ 
		static ::String DATA_ATTRIBUTE; /* REM */ 
		static ::String FLASHVARS_ATTRIBUTE; /* REM */ 
		static ::String WMODE_ATTRIBUTE; /* REM */ 
		static ::String WMODE_TRANSPARENT; /* REM */ 
};

} // end namespace cocktail
} // end namespace plugin
} // end namespace swf

#endif /* INCLUDED_cocktail_plugin_swf_SWFPlugin */ 
