#ifndef INCLUDED_cocktail_core_mouse_MouseCursorValue
#define INCLUDED_cocktail_core_mouse_MouseCursorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,mouse,MouseCursorValue)
HX_DECLARE_CLASS3(cocktail,core,mouse,NativeOSMouseCursorValue)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.mouse.MouseCursorValue"); }
		::String __ToString() const { return HX_CSTRING("MouseCursorValue.") + tag; }

		static ::cocktail::core::mouse::MouseCursorValue cssAuto;
		static inline ::cocktail::core::mouse::MouseCursorValue cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::mouse::MouseCursorValue custom(::cocktail::core::html::HTMLImageElement htmlImageElement,Dynamic hotSpot);
		static Dynamic custom_dyn();
		static ::cocktail::core::mouse::MouseCursorValue native(::cocktail::core::mouse::NativeOSMouseCursorValue nativeOSMouseCursorValue);
		static Dynamic native_dyn();
		static ::cocktail::core::mouse::MouseCursorValue none;
		static inline ::cocktail::core::mouse::MouseCursorValue none_dyn() { return none; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_cocktail_core_mouse_MouseCursorValue */ 
