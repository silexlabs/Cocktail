#ifndef INCLUDED_neash_display_LineScaleMode
#define INCLUDED_neash_display_LineScaleMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,LineScaleMode)
namespace neash{
namespace display{


class LineScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineScaleMode_obj OBJ_;

	public:
		LineScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.LineScaleMode"); }
		::String __ToString() const { return HX_CSTRING("LineScaleMode.") + tag; }

		static ::neash::display::LineScaleMode HORIZONTAL;
		static inline ::neash::display::LineScaleMode HORIZONTAL_dyn() { return HORIZONTAL; }
		static ::neash::display::LineScaleMode NONE;
		static inline ::neash::display::LineScaleMode NONE_dyn() { return NONE; }
		static ::neash::display::LineScaleMode NORMAL;
		static inline ::neash::display::LineScaleMode NORMAL_dyn() { return NORMAL; }
		static ::neash::display::LineScaleMode OPENGL;
		static inline ::neash::display::LineScaleMode OPENGL_dyn() { return OPENGL; }
		static ::neash::display::LineScaleMode VERTICAL;
		static inline ::neash::display::LineScaleMode VERTICAL_dyn() { return VERTICAL; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_LineScaleMode */ 
