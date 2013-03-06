#ifndef INCLUDED_native_ui_Multitouch
#define INCLUDED_native_ui_Multitouch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,ui,Multitouch)
HX_DECLARE_CLASS2(native,ui,MultitouchInputMode)
namespace native{
namespace ui{


class Multitouch_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Multitouch_obj OBJ_;
		Multitouch_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Multitouch_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Multitouch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		static void __init__();

		::String __ToString() const { return HX_CSTRING("Multitouch"); }

		static ::native::ui::MultitouchInputMode inputMode; /* REM */ 
		static int maxTouchPoints; /* REM */ 
		static Array< ::String > supportedGestures; /* REM */ 
		static bool supportsGestureEvents; /* REM */ 
		static bool supportsTouchEvents; /* REM */ 
		static ::native::ui::MultitouchInputMode get_inputMode( );
		static Dynamic get_inputMode_dyn();

		static ::native::ui::MultitouchInputMode set_inputMode( ::native::ui::MultitouchInputMode inMode);
		static Dynamic set_inputMode_dyn();

		static bool get_supportsTouchEvents( );
		static Dynamic get_supportsTouchEvents_dyn();

		static Dynamic nme_stage_get_multitouch_supported; /* REM */ 
		static Dynamic &nme_stage_get_multitouch_supported_dyn() { return nme_stage_get_multitouch_supported;}
		static Dynamic nme_stage_get_multitouch_active; /* REM */ 
		static Dynamic &nme_stage_get_multitouch_active_dyn() { return nme_stage_get_multitouch_active;}
		static Dynamic nme_stage_set_multitouch_active; /* REM */ 
		static Dynamic &nme_stage_set_multitouch_active_dyn() { return nme_stage_set_multitouch_active;}
};

} // end namespace native
} // end namespace ui

#endif /* INCLUDED_native_ui_Multitouch */ 
