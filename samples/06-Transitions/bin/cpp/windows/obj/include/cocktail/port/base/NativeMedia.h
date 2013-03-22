#ifndef INCLUDED_cocktail_port_base_NativeMedia
#define INCLUDED_cocktail_port_base_NativeMedia

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeMedia)
namespace cocktail{
namespace port{
namespace base{


class NativeMedia_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeMedia_obj OBJ_;
		NativeMedia_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeMedia_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeMedia_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeMedia"); }

		virtual Float set_alpha( Float value);
		Dynamic set_alpha_dyn();

		virtual Float get_alpha( );
		Dynamic get_alpha_dyn();

		virtual ::cocktail::core::geom::Matrix set_matrix( ::cocktail::core::geom::Matrix value);
		Dynamic set_matrix_dyn();

		virtual ::cocktail::core::geom::Matrix get_matrix( );
		Dynamic get_matrix_dyn();

		virtual ::cocktail::core::geom::RectangleVO set_viewport( ::cocktail::core::geom::RectangleVO value);
		Dynamic set_viewport_dyn();

		virtual ::cocktail::core::geom::RectangleVO get_viewport( );
		Dynamic get_viewport_dyn();

		virtual Float set_volume( Float value);
		Dynamic set_volume_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual Float get_duration( );
		Dynamic get_duration_dyn();

		virtual Dynamic get_width( );
		Dynamic get_width_dyn();

		virtual Dynamic get_height( );
		Dynamic get_height_dyn();

		virtual Float get_currentTime( );
		Dynamic get_currentTime_dyn();

		virtual Float get_bytesLoaded( );
		Dynamic get_bytesLoaded_dyn();

		virtual Float get_bytesTotal( );
		Dynamic get_bytesTotal_dyn();

		virtual Void onNativeLoadedMetaData( );
		Dynamic onNativeLoadedMetaData_dyn();

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicsContext);
		Dynamic detach_dyn();

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicsContext);
		Dynamic attach_dyn();

		virtual ::String canPlayType( ::String type);
		Dynamic canPlayType_dyn();

		virtual Void seek( Float time);
		Dynamic seek_dyn();

		virtual Void pause( );
		Dynamic pause_dyn();

		virtual Void play( );
		Dynamic play_dyn();

		Float alpha; /* REM */ 
		::cocktail::core::geom::Matrix matrix; /* REM */ 
		::cocktail::core::geom::RectangleVO viewport; /* REM */ 
		Dynamic onLoadedMetaData; /* REM */ 
		Dynamic &onLoadedMetaData_dyn() { return onLoadedMetaData;}
		Float bytesTotal; /* REM */ 
		Float bytesLoaded; /* REM */ 
		Float currentTime; /* REM */ 
		Dynamic height; /* REM */ 
		Dynamic width; /* REM */ 
		::String src; /* REM */ 
		Float volume; /* REM */ 
		Float duration; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeMedia */ 
