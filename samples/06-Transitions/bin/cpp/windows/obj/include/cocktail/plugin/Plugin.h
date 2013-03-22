#ifndef INCLUDED_cocktail_plugin_Plugin
#define INCLUDED_cocktail_plugin_Plugin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS2(cocktail,plugin,Plugin)
namespace cocktail{
namespace plugin{


class Plugin_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Plugin_obj OBJ_;
		Plugin_obj();
		Void __construct(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError);

	public:
		static hx::ObjectPtr< Plugin_obj > __new(::Hash elementAttributes,::Hash params,Dynamic loadComplete,Dynamic loadError);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Plugin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Plugin"); }

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicsContext);
		Dynamic detach_dyn();

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicsContext);
		Dynamic attach_dyn();

		virtual bool isCompositedPlugin( );
		Dynamic isCompositedPlugin_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void updateViewport( Float x,Float y,Float width,Float height);
		Dynamic updateViewport_dyn();

		::Hash _params; /* REM */ 
		::Hash _elementAttributes; /* REM */ 
		Dynamic _loadError; /* REM */ 
		Dynamic &_loadError_dyn() { return _loadError;}
		Dynamic _loadComplete; /* REM */ 
		Dynamic &_loadComplete_dyn() { return _loadComplete;}
		::cocktail::core::geom::RectangleVO viewport; /* REM */ 
};

} // end namespace cocktail
} // end namespace plugin

#endif /* INCLUDED_cocktail_plugin_Plugin */ 
