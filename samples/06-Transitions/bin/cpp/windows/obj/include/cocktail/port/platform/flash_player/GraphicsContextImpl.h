#ifndef INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl
#define INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,AbstractGraphicsContextImpl)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,GraphicsContextImpl)
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,display,Sprite)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,ColorTransform)
HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class GraphicsContextImpl_obj : public ::cocktail::core::graphics::AbstractGraphicsContextImpl_obj{
	public:
		typedef ::cocktail::core::graphics::AbstractGraphicsContextImpl_obj super;
		typedef GraphicsContextImpl_obj OBJ_;
		GraphicsContextImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GraphicsContextImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GraphicsContextImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphicsContextImpl"); }

		virtual ::neash::display::DisplayObjectContainer get_nativeLayer( );

		virtual ::neash::display::BitmapData get_nativeBitmapData( );

		virtual Void copyRect( ::cocktail::core::geom::RectangleVO rect,Float x,Float y);

		virtual Void fillRect( ::cocktail::core::geom::RectangleVO rect,::cocktail::core::css::ColorVO color,::cocktail::core::geom::RectangleVO clipRect);

		virtual Void copyPixels( ::neash::display::BitmapData bitmapData,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::PointVO destPoint,::cocktail::core::geom::RectangleVO clipRect);

		virtual Void drawImage( ::neash::display::BitmapData bitmapData,::cocktail::core::geom::Matrix matrix,::cocktail::core::geom::RectangleVO sourceRect,::cocktail::core::geom::RectangleVO clipRect);

		virtual Void detachFromRoot( );

		virtual Void attachToRoot( ::neash::display::DisplayObjectContainer rootLayer);

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicsContext);

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicsContext,int index);

		virtual Void transform( ::cocktail::core::geom::Matrix matrix);

		virtual Void dispose( );

		virtual Void beginTransparency( Float alpha);

		virtual Void clear( Float x,Float y,Float width,Float height);

		virtual Void initBitmapData( int width,int height);

		int _height; /* REM */ 
		int _width; /* REM */ 
		::neash::display::Sprite _childrenNativeLayer; /* REM */ 
		::neash::display::Sprite _bitmapContainer; /* REM */ 
		::neash::display::Sprite _nativeLayer; /* REM */ 
		::neash::display::Bitmap _nativeBitmap; /* REM */ 
		static ::neash::geom::Rectangle _flashRectangle; /* REM */ 
		static ::neash::geom::Point _flashPoint; /* REM */ 
		static ::neash::geom::Point _flashAlphaPoint; /* REM */ 
		static ::neash::geom::Matrix _flashMatrix; /* REM */ 
		static ::neash::geom::ColorTransform _flashColorTransform; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _fillRectRectangle; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _clippedRectRectangle; /* REM */ 
		static ::cocktail::core::geom::PointVO _fillRectPoint; /* REM */ 
		static Void roundFlashRect( );
		static Dynamic roundFlashRect_dyn();

		static Void roundFlashPoint( );
		static Dynamic roundFlashPoint_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl */ 
