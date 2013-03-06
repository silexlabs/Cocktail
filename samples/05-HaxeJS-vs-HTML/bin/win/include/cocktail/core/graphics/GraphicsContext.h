#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#define INCLUDED_cocktail_core_graphics_GraphicsContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/FastNode.h>
HX_DECLARE_CLASS3(cocktail,core,graphics,AbstractGraphicsContextImpl)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,GraphicsContextImpl)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace cocktail{
namespace core{
namespace graphics{


class GraphicsContext_obj : public ::cocktail::core::utils::FastNode_obj{
	public:
		typedef ::cocktail::core::utils::FastNode_obj super;
		typedef GraphicsContext_obj OBJ_;
		GraphicsContext_obj();
		Void __construct(::cocktail::core::layer::LayerRenderer layerRenderer);

	public:
		static hx::ObjectPtr< GraphicsContext_obj > __new(::cocktail::core::layer::LayerRenderer layerRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GraphicsContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphicsContext"); }

		virtual ::native::display::DisplayObjectContainer get_nativeLayer( );
		Dynamic get_nativeLayer_dyn();

		virtual Void doDetach( );
		Dynamic doDetach_dyn();

		virtual Void doAttach( );
		Dynamic doAttach_dyn();

		virtual Void detach( );
		Dynamic detach_dyn();

		virtual Void attach( );
		Dynamic attach_dyn();

		virtual Void invalidateBitmapSize( );
		Dynamic invalidateBitmapSize_dyn();

		virtual Void invalidateNativeLayer( );
		Dynamic invalidateNativeLayer_dyn();

		virtual Void updateNativeLayer( );
		Dynamic updateNativeLayer_dyn();

		virtual Void updateGraphicsSize( int viewportWidth,int viewportHeight);
		Dynamic updateGraphicsSize_dyn();

		virtual Void removedFromGraphicsContextTree( );
		Dynamic removedFromGraphicsContextTree_dyn();

		virtual Void addedToGraphicsContextTree( );
		Dynamic addedToGraphicsContextTree_dyn();

		virtual Void insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild);

		virtual Void removeChild( Dynamic _tmp_oldChild);

		virtual Void appendChild( Dynamic _tmp_newChild);

		virtual Void dispose( );
		Dynamic dispose_dyn();

		bool _needsNativeLayerUpdate; /* REM */ 
		::cocktail::port::platform::flash_player::GraphicsContextImpl graphics; /* REM */ 
		::cocktail::core::layer::LayerRenderer layerRenderer; /* REM */ 
		::native::display::DisplayObjectContainer nativeLayer; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace graphics

#endif /* INCLUDED_cocktail_core_graphics_GraphicsContext */ 
