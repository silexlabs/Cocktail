#ifndef INCLUDED_neash_ui_MultitouchInputMode
#define INCLUDED_neash_ui_MultitouchInputMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,ui,MultitouchInputMode)
namespace neash{
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
		::String GetEnumName( ) const { return HX_CSTRING("neash.ui.MultitouchInputMode"); }
		::String __ToString() const { return HX_CSTRING("MultitouchInputMode.") + tag; }

		static ::neash::ui::MultitouchInputMode GESTURE;
		static inline ::neash::ui::MultitouchInputMode GESTURE_dyn() { return GESTURE; }
		static ::neash::ui::MultitouchInputMode NONE;
		static inline ::neash::ui::MultitouchInputMode NONE_dyn() { return NONE; }
		static ::neash::ui::MultitouchInputMode TOUCH_POINT;
		static inline ::neash::ui::MultitouchInputMode TOUCH_POINT_dyn() { return TOUCH_POINT; }
};

} // end namespace neash
} // end namespace ui

#endif /* INCLUDED_neash_ui_MultitouchInputMode */ 
