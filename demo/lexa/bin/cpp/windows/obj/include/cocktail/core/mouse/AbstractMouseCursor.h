#ifndef INCLUDED_cocktail_core_mouse_AbstractMouseCursor
#define INCLUDED_cocktail_core_mouse_AbstractMouseCursor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,mouse,AbstractMouseCursor)
HX_DECLARE_CLASS3(cocktail,core,mouse,MouseCursorValue)
HX_DECLARE_CLASS3(cocktail,core,mouse,NativeOSMouseCursorValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
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

		::cocktail::core::mouse::MouseCursorValue _nativeMouseCursor; /* REM */ 
		::cocktail::core::mouse::MouseCursorValue nativeMouseCursor; /* REM */ 
		virtual ::cocktail::core::mouse::MouseCursorValue setNativeMouseCursor( ::cocktail::core::mouse::MouseCursorValue value);
		Dynamic setNativeMouseCursor_dyn();

		virtual ::cocktail::core::mouse::MouseCursorValue getNativeMouseCursor( );
		Dynamic getNativeMouseCursor_dyn();

		virtual Void setBitmapCursor( ::cocktail::core::html::AbstractHTMLImageElement imageHTMLElement,Dynamic hotSpot);
		Dynamic setBitmapCursor_dyn();

		virtual Void hideCursor( );
		Dynamic hideCursor_dyn();

		virtual Void setDefaultCursor( );
		Dynamic setDefaultCursor_dyn();

		virtual Void setNativeOSCursor( ::cocktail::core::mouse::NativeOSMouseCursorValue value);
		Dynamic setNativeOSCursor_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_cocktail_core_mouse_AbstractMouseCursor */ 
