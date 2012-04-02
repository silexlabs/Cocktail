#ifndef INCLUDED_core_mouse_MouseCursorValue
#define INCLUDED_core_mouse_MouseCursorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS2(core,html,EmbeddedElement)
HX_DECLARE_CLASS2(core,mouse,MouseCursorValue)
HX_DECLARE_CLASS2(core,mouse,NativeOSMouseCursorValue)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace mouse{


class MouseCursorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MouseCursorValue_obj OBJ_;

	public:
		MouseCursorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.mouse.MouseCursorValue"); }
		::String __ToString() const { return HX_CSTRING("MouseCursorValue.") + tag; }

		static ::core::mouse::MouseCursorValue cssAuto;
		static inline ::core::mouse::MouseCursorValue cssAuto_dyn() { return cssAuto; }
		static ::core::mouse::MouseCursorValue custom(::core::html::AbstractHTMLImageElement htmlImageElement,Dynamic hotSpot);
		static Dynamic custom_dyn();
		static ::core::mouse::MouseCursorValue native(::core::mouse::NativeOSMouseCursorValue nativeOSMouseCursorValue);
		static Dynamic native_dyn();
		static ::core::mouse::MouseCursorValue none;
		static inline ::core::mouse::MouseCursorValue none_dyn() { return none; }
};

} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_core_mouse_MouseCursorValue */ 
