#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#define INCLUDED_cocktail_port_base_NativeInputBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
namespace cocktail{
namespace port{
namespace base{


class NativeInputBase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeInputBase_obj OBJ_;
		NativeInputBase_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< NativeInputBase_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeInputBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeInputBase"); }

		virtual int get_intrinsicHeight( );
		Dynamic get_intrinsicHeight_dyn();

		virtual int get_intrinsicWidth( );
		Dynamic get_intrinsicWidth_dyn();

		virtual bool set_readonly( bool value);
		Dynamic set_readonly_dyn();

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual bool set_checked( bool value);
		Dynamic set_checked_dyn();

		virtual bool get_checked( );
		Dynamic get_checked_dyn();

		virtual ::String set_value( ::String textValue);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::cocktail::core::geom::RectangleVO set_clipRect( ::cocktail::core::geom::RectangleVO value);
		Dynamic set_clipRect_dyn();

		virtual ::cocktail::core::geom::RectangleVO get_clipRect( );
		Dynamic get_clipRect_dyn();

		virtual ::cocktail::core::geom::RectangleVO set_viewport( ::cocktail::core::geom::RectangleVO value);
		Dynamic set_viewport_dyn();

		virtual ::cocktail::core::geom::RectangleVO get_viewport( );
		Dynamic get_viewport_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void blur( );
		Dynamic blur_dyn();

		virtual Void focus( );
		Dynamic focus_dyn();

		virtual Void detach( ::cocktail::core::graphics::GraphicsContext graphicContext);
		Dynamic detach_dyn();

		virtual Void attach( ::cocktail::core::graphics::GraphicsContext graphicContext);
		Dynamic attach_dyn();

		::cocktail::core::html::HTMLElement _node; /* REM */ 
		Dynamic onInput; /* REM */ 
		Dynamic &onInput_dyn() { return onInput;}
		Dynamic onActivate; /* REM */ 
		Dynamic &onActivate_dyn() { return onActivate;}
		::cocktail::core::geom::RectangleVO clipRect; /* REM */ 
		::cocktail::core::geom::RectangleVO viewport; /* REM */ 
		int intrinsicHeight; /* REM */ 
		int intrinsicWidth; /* REM */ 
		bool readonly; /* REM */ 
		bool disabled; /* REM */ 
		int maxLength; /* REM */ 
		bool checked; /* REM */ 
		::String value; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeInputBase */ 
