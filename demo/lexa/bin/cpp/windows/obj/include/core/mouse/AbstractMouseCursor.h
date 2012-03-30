#ifndef INCLUDED_core_mouse_AbstractMouseCursor
#define INCLUDED_core_mouse_AbstractMouseCursor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS2(core,html,EmbeddedElement)
HX_DECLARE_CLASS2(core,mouse,AbstractMouseCursor)
HX_DECLARE_CLASS2(core,mouse,MouseCursorValue)
HX_DECLARE_CLASS2(core,mouse,NativeOSMouseCursorValue)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace mouse{


class AbstractMouseCursor_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractMouseCursor_obj OBJ_;
		AbstractMouseCursor_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractMouseCursor_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractMouseCursor_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractMouseCursor"); }

		::core::mouse::MouseCursorValue _nativeMouseCursor; /* REM */ 
		::core::mouse::MouseCursorValue nativeMouseCursor; /* REM */ 
		virtual ::core::mouse::MouseCursorValue setNativeMouseCursor( ::core::mouse::MouseCursorValue value);
		Dynamic setNativeMouseCursor_dyn();

		virtual ::core::mouse::MouseCursorValue getNativeMouseCursor( );
		Dynamic getNativeMouseCursor_dyn();

		virtual Void setBitmapCursor( ::core::html::AbstractHTMLImageElement imageHTMLElement,Dynamic hotSpot);
		Dynamic setBitmapCursor_dyn();

		virtual Void hideCursor( );
		Dynamic hideCursor_dyn();

		virtual Void setDefaultCursor( );
		Dynamic setDefaultCursor_dyn();

		virtual Void setNativeOSCursor( ::core::mouse::NativeOSMouseCursorValue value);
		Dynamic setNativeOSCursor_dyn();

};

} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_core_mouse_AbstractMouseCursor */ 
