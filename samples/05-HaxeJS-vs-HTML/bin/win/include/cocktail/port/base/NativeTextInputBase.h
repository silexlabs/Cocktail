#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#define INCLUDED_cocktail_port_base_NativeTextInputBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
namespace cocktail{
namespace port{
namespace base{


class NativeTextInputBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeTextInputBase_obj OBJ_;
		NativeTextInputBase_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeTextInputBase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeTextInputBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeTextInputBase"); }

		virtual Float get_letterSpacing( );
		Dynamic get_letterSpacing_dyn();

		virtual Float set_letterSpacing( Float value);
		Dynamic set_letterSpacing_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual ::String set_value( ::String textValue);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual Float get_fontSize( );
		Dynamic get_fontSize_dyn();

		virtual Float set_fontSize( Float value);
		Dynamic set_fontSize_dyn();

		virtual ::String get_fontFamily( );
		Dynamic get_fontFamily_dyn();

		virtual ::String set_fontFamily( ::String value);
		Dynamic set_fontFamily_dyn();

		virtual int get_color( );
		Dynamic get_color_dyn();

		virtual int set_color( int value);
		Dynamic set_color_dyn();

		virtual bool set_bold( bool value);
		Dynamic set_bold_dyn();

		virtual bool get_bold( );
		Dynamic get_bold_dyn();

		virtual bool get_italic( );
		Dynamic get_italic_dyn();

		virtual bool set_italic( bool value);
		Dynamic set_italic_dyn();

		virtual ::cocktail::core::geom::RectangleVO set_clipRect( ::cocktail::core::geom::RectangleVO value);
		Dynamic set_clipRect_dyn();

		virtual ::cocktail::core::geom::RectangleVO get_clipRect( );
		Dynamic get_clipRect_dyn();

		virtual ::cocktail::core::geom::RectangleVO set_viewport( ::cocktail::core::geom::RectangleVO value);
		Dynamic set_viewport_dyn();

		virtual ::cocktail::core::geom::RectangleVO get_viewport( );
		Dynamic get_viewport_dyn();

		virtual Void focus( );
		Dynamic focus_dyn();

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicContext);
		Dynamic detach_dyn();

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicContext);
		Dynamic attach_dyn();

		Float fontSize; /* REM */ 
		Float letterSpacing; /* REM */ 
		::String fontFamily; /* REM */ 
		int color; /* REM */ 
		bool bold; /* REM */ 
		bool italic; /* REM */ 
		::cocktail::core::geom::RectangleVO clipRect; /* REM */ 
		::cocktail::core::geom::RectangleVO viewport; /* REM */ 
		int maxLength; /* REM */ 
		::String value; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeTextInputBase */ 
