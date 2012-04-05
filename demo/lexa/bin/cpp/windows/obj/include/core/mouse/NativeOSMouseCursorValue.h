#ifndef INCLUDED_core_mouse_NativeOSMouseCursorValue
#define INCLUDED_core_mouse_NativeOSMouseCursorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,mouse,NativeOSMouseCursorValue)
namespace core{
namespace mouse{


class NativeOSMouseCursorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef NativeOSMouseCursorValue_obj OBJ_;

	public:
		NativeOSMouseCursorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.mouse.NativeOSMouseCursorValue"); }
		::String __ToString() const { return HX_CSTRING("NativeOSMouseCursorValue.") + tag; }

		static ::core::mouse::NativeOSMouseCursorValue pointer;
		static inline ::core::mouse::NativeOSMouseCursorValue pointer_dyn() { return pointer; }
		static ::core::mouse::NativeOSMouseCursorValue text;
		static inline ::core::mouse::NativeOSMouseCursorValue text_dyn() { return text; }
};

} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_core_mouse_NativeOSMouseCursorValue */ 
