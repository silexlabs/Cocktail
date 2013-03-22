#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#define INCLUDED_cocktail_core_layer_LayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/ScrollableView.h>
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,stacking,StackingContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace layer{


class LayerRenderer_obj : public ::cocktail::core::layer::ScrollableView_obj{
	public:
		typedef ::cocktail::core::layer::ScrollableView_obj super;
		typedef LayerRenderer_obj OBJ_;
		LayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< LayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("LayerRenderer"); }

		virtual Void dispatchScrollEvent( Float timestamp);
		Dynamic dispatchScrollEvent_dyn();

		virtual bool establishesNewStackingContext( );
		Dynamic establishesNewStackingContext_dyn();

		virtual ::cocktail::core::geom::PointVO getRelativeOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer);
		Dynamic getRelativeOffset_dyn();

		virtual Void getConcatenatedMatrix( ::cocktail::core::geom::Matrix matrix,::cocktail::core::geom::PointVO relativeOffset);
		Dynamic getConcatenatedMatrix_dyn();

		virtual ::cocktail::core::geom::Matrix getTransformationMatrix( );
		Dynamic getTransformationMatrix_dyn();

		virtual Void doClear( Float x,Float y,Float width,Float height);
		Dynamic doClear_dyn();

		virtual Void updateScrollRegion( ::cocktail::core::geom::RectangleVO dirtyRect);
		Dynamic updateScrollRegion_dyn();

		virtual Void render( ::cocktail::core::geom::RectangleVO dirtyRect);
		Dynamic render_dyn();

		virtual Void clear( Float x,Float y,Float width,Float height);
		Dynamic clear_dyn();

		virtual Void scrollChanged( );

		virtual Void updateBounds( );

		virtual bool needsBitmap( );
		Dynamic needsBitmap_dyn();

		virtual bool isCompositingLayer( );
		Dynamic isCompositingLayer_dyn();

		virtual bool hasZeroOrAutoCompositingLayerSibling( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::layer::LayerRenderer referenceLayer);
		Dynamic hasZeroOrAutoCompositingLayerSibling_dyn();

		virtual bool hasCompositingLayerSibling( );
		Dynamic hasCompositingLayerSibling_dyn();

		virtual bool hasCompositingLayerDescendant( ::cocktail::core::layer::LayerRenderer rootLayerRenderer);
		Dynamic hasCompositingLayerDescendant_dyn();

		virtual int getZIndex( ::cocktail::core::layer::LayerRenderer layerRenderer);
		Dynamic getZIndex_dyn();

		virtual Void createStackingContext( ::cocktail::core::stacking::StackingContext parentStackingContext);
		Dynamic createStackingContext_dyn();

		virtual bool establishesNewGraphicsContext( );
		Dynamic establishesNewGraphicsContext_dyn();

		virtual ::cocktail::core::layer::LayerRenderer getNextSiblingWithGraphicsContext( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::layer::LayerRenderer referenceLayer,bool hasFoundSelf);
		Dynamic getNextSiblingWithGraphicsContext_dyn();

		virtual Void createGraphicsContext( ::cocktail::core::graphics::GraphicsContext parentGraphicsContext);
		Dynamic createGraphicsContext_dyn();

		virtual Void doDetachStackingContext( );
		Dynamic doDetachStackingContext_dyn();

		virtual Void doAttachStackingContext( );
		Dynamic doAttachStackingContext_dyn();

		virtual Void doDetachGraphicsContext( );
		Dynamic doDetachGraphicsContext_dyn();

		virtual Void doAttachGraphicsContext( );
		Dynamic doAttachGraphicsContext_dyn();

		virtual Void detachStackingContext( );
		Dynamic detachStackingContext_dyn();

		virtual Void attachStackingContext( );
		Dynamic attachStackingContext_dyn();

		virtual Void detachGraphicsContext( );
		Dynamic detachGraphicsContext_dyn();

		virtual Void attachGraphicsContext( );
		Dynamic attachGraphicsContext_dyn();

		virtual Void removedFromLayerTree( );
		Dynamic removedFromLayerTree_dyn();

		virtual Void addedToLayerTree( );
		Dynamic addedToLayerTree_dyn();

		virtual Void removeChild( Dynamic _tmp_oldChild);

		virtual Void insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild);

		virtual Void appendChild( Dynamic _tmp_newChild);

		virtual Void invalidateStackingContext( );
		Dynamic invalidateStackingContext_dyn();

		virtual Void invalidateRendering( );
		Dynamic invalidateRendering_dyn();

		virtual Void invalidateGraphicsContext( bool force);
		Dynamic invalidateGraphicsContext_dyn();

		virtual Void updateStackingContext( );
		Dynamic updateStackingContext_dyn();

		virtual Void updateLayerAlpha( Float parentAlpha);
		Dynamic updateLayerAlpha_dyn();

		virtual Void updateLayerMatrix( ::cocktail::core::geom::Matrix parentMatrix);
		Dynamic updateLayerMatrix_dyn();

		virtual Void updateGraphicsContext( bool force);
		Dynamic updateGraphicsContext_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		bool _canUpdateScrollRegion; /* REM */ 
		::cocktail::core::geom::Matrix _currentMatrix; /* REM */ 
		::cocktail::core::geom::RectangleVO _layerDirtyRect; /* REM */ 
		::cocktail::core::geom::PointVO _relativeOffset; /* REM */ 
		::cocktail::core::geom::Matrix matrix; /* REM */ 
		Float alpha; /* REM */ 
		bool _needsStackingContextUpdate; /* REM */ 
		bool _needsGraphicsContextUpdate; /* REM */ 
		bool hasOwnStackingContext; /* REM */ 
		bool hasOwnGraphicsContext; /* REM */ 
		::cocktail::core::graphics::GraphicsContext graphicsContext; /* REM */ 
		::cocktail::core::stacking::StackingContext stackingContext; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_LayerRenderer */ 
