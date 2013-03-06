#ifndef INCLUDED_native_ui_MultitouchInputMode
#define INCLUDED_native_ui_MultitouchInputMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,ui,MultitouchInputMode)
namespace native{
namespace ui{


class MultitouchInputMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MultitouchInputMode_obj OBJ_;

	public:
		MultitouchInputMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("native.ui.MultitouchInputMode"); }
		::String __ToString() const { return HX_CSTRING("MultitouchInputMode.") + tag; }

		static ::native::ui::MultitouchInputMode GESTURE;
		static inline ::native::ui::MultitouchInputMode GESTURE_dyn() { return GESTURE; }
		static ::native::ui::MultitouchInputMode NONE;
		static inline ::native::ui::MultitouchInputMode NONE_dyn() { return NONE; }
		static ::native::ui::MultitouchInputMode TOUCH_POINT;
		static inline ::native::ui::MultitouchInputMode TOUCH_POINT_dyn() { return TOUCH_POINT; }
};

} // end namespace native
} // end namespace ui

#endif /* INCLUDED_native_ui_MultitouchInputMode */ 
