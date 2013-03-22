#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#define INCLUDED_cocktail_port_base_NativeTextInputBase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/NativeInputBase.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
namespace cocktail{
namespace port{
namespace base{


class NativeTextInputBase_obj : public ::cocktail::port::base::NativeInputBase_obj{
	public:
		typedef ::cocktail::port::base::NativeInputBase_obj super;
		typedef NativeTextInputBase_obj OBJ_;
		NativeTextInputBase_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< NativeTextInputBase_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeTextInputBase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeTextInputBase"); }

		virtual int get_intrinsicHeight( );

		virtual int get_intrinsicWidth( );

		virtual Float get_letterSpacing( );
		Dynamic get_letterSpacing_dyn();

		virtual Float set_letterSpacing( Float value);
		Dynamic set_letterSpacing_dyn();

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

		Float fontSize; /* REM */ 
		Float letterSpacing; /* REM */ 
		::String fontFamily; /* REM */ 
		int color; /* REM */ 
		bool bold; /* REM */ 
		bool italic; /* REM */ 
		static int INPUT_TEXT_INTRINSIC_WIDTH; /* REM */ 
		static Float INPUT_TEXT_INTRINSIC_HEIGHT; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace base

#endif /* INCLUDED_cocktail_port_base_NativeTextInputBase */ 
