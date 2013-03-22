#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#define INCLUDED_cocktail_core_invalidation_InvalidationManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLDocument)
HX_DECLARE_CLASS3(cocktail,core,invalidation,InvalidationManager)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace invalidation{


class InvalidationManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef InvalidationManager_obj OBJ_;
		InvalidationManager_obj();
		Void __construct(::cocktail::core::html::HTMLDocument htmlDocument);

	public:
		static hx::ObjectPtr< InvalidationManager_obj > __new(::cocktail::core::html::HTMLDocument htmlDocument);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InvalidationManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InvalidationManager"); }

		virtual Void startLayout( bool forceLayout);
		Dynamic startLayout_dyn();

		virtual Void startCascade( bool programmaticChange);
		Dynamic startCascade_dyn();

		virtual Void onUpdateSchedule( Float timeStamp);
		Dynamic onUpdateSchedule_dyn();

		virtual Void updateDocument( );
		Dynamic updateDocument_dyn();

		virtual Void doInvalidate( );
		Dynamic doInvalidate_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void invalidateCascade( );
		Dynamic invalidateCascade_dyn();

		virtual Void invalidateGraphicsContextTree( bool force);
		Dynamic invalidateGraphicsContextTree_dyn();

		virtual Void invalidatePendingAnimations( );
		Dynamic invalidatePendingAnimations_dyn();

		virtual Void invalidateNativeLayerTree( );
		Dynamic invalidateNativeLayerTree_dyn();

		virtual Void invalidateStackingContexts( );
		Dynamic invalidateStackingContexts_dyn();

		virtual Void invalidateLayerTree( );
		Dynamic invalidateLayerTree_dyn();

		virtual Void invalidateRenderingTree( );
		Dynamic invalidateRenderingTree_dyn();

		virtual Void invalidateScrollOffset( );
		Dynamic invalidateScrollOffset_dyn();

		virtual Void invalidateRendering( ::cocktail::core::geom::RectangleVO dirtyRect);
		Dynamic invalidateRendering_dyn();

		virtual Void invalidateLayout( bool force);
		Dynamic invalidateLayout_dyn();

		virtual Void invalidateBitmapSizes( );
		Dynamic invalidateBitmapSizes_dyn();

		virtual Void invalidateViewportSize( );
		Dynamic invalidateViewportSize_dyn();

		virtual Void updateDocumentImmediately( );
		Dynamic updateDocumentImmediately_dyn();

		bool _firstDirtyRect; /* REM */ 
		bool _repaintWholeViewport; /* REM */ 
		::cocktail::core::geom::RectangleVO _dirtyRect; /* REM */ 
		::cocktail::core::geom::Matrix _initialMatrix; /* REM */ 
		::cocktail::core::html::HTMLDocument _htmlDocument; /* REM */ 
		bool _bitmapSizeNeedsUpdate; /* REM */ 
		bool _viewportResized; /* REM */ 
		bool _forceGraphicsContextUpdate; /* REM */ 
		bool _graphicsContextTreeNeedsUpdate; /* REM */ 
		bool _pendingAnimationsNeedUpdate; /* REM */ 
		bool _nativeLayerTreeNeedsUpdate; /* REM */ 
		bool _stackingContextsNeedUpdate; /* REM */ 
		bool _layerTreeNeedsUpdate; /* REM */ 
		bool _renderingTreeNeedsUpdate; /* REM */ 
		bool _documentNeedsCascading; /* REM */ 
		bool _scrollOffsetNeedsUpdate; /* REM */ 
		bool _documentNeedsRendering; /* REM */ 
		bool _forceLayout; /* REM */ 
		bool _documentNeedsLayout; /* REM */ 
		bool _invalidationScheduled; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace invalidation

#endif /* INCLUDED_cocktail_core_invalidation_InvalidationManager */ 
