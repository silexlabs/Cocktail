#ifndef INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl
#define INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,AbstractGraphicsContextImpl)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
namespace cocktail{
namespace core{
namespace graphics{


class AbstractGraphicsContextImpl_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractGraphicsContextImpl_obj OBJ_;
		AbstractGraphicsContextImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractGraphicsContextImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractGraphicsContextImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractGraphicsContextImpl"); }

		virtual ::native::display::DisplayObjectContainer get_nativeLayer( );
		Dynamic get_nativeLayer_dyn();

		virtual ::native::display::BitmapData get_nativeBitmapData( );
		Dynamic get_nativeBitmapData_dyn();

		virtual Void fillRect( ::cocktail::core::geom::RectangleVO rect,::cocktail::core::css::ColorVO color,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic fillRect_dyn();

		virtual Void copyPixels( ::native::display::BitmapData bitmapData,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::PointVO destPoint,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic copyPixels_dyn();

		virtual Void drawImage( ::native::display::BitmapData bitmapData,::cocktail::core::geom::Matrix matrix,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic drawImage_dyn();

		virtual Void endTransformations( );
		Dynamic endTransformations_dyn();

		virtual Void beginTransformations( ::cocktail::core::geom::Matrix matrix);
		Dynamic beginTransformations_dyn();

		virtual Void endTransparency( );
		Dynamic endTransparency_dyn();

		virtual Void copyRect( ::cocktail::core::geom::RectangleVO rect,Float x,Float y);
		Dynamic copyRect_dyn();

		virtual Void beginTransparency( Float alpha);
		Dynamic beginTransparency_dyn();

		virtual Void clear( Float x,Float y,Float width,Float height);
		Dynamic clear_dyn();

		virtual Void transform( ::cocktail::core::geom::Matrix matrix);
		Dynamic transform_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void detachFromRoot( );
		Dynamic detachFromRoot_dyn();

		virtual Void attachToRoot( ::native::display::DisplayObjectContainer rootLayer);
		Dynamic attachToRoot_dyn();

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicsContext);
		Dynamic detach_dyn();

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicsContext,int index);
		Dynamic attach_dyn();

		virtual Void initBitmapData( int width,int height);
		Dynamic initBitmapData_dyn();

		::cocktail::core::geom::Matrix _matrix; /* REM */ 
		bool _useTransformations; /* REM */ 
		Float _alpha; /* REM */ 
		bool _useTransparency; /* REM */ 
		::native::display::BitmapData nativeBitmapData; /* REM */ 
		::native::display::DisplayObjectContainer nativeLayer; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace graphics

#endif /* INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl */ 
