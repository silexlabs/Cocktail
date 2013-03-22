#ifndef INCLUDED_neash_display_BlendMode
#define INCLUDED_neash_display_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,BlendMode)
namespace neash{
namespace display{


class BlendMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BlendMode_obj OBJ_;

	public:
		BlendMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.display.BlendMode"); }
		::String __ToString() const { return HX_CSTRING("BlendMode.") + tag; }

		static ::neash::display::BlendMode ADD;
		static inline ::neash::display::BlendMode ADD_dyn() { return ADD; }
		static ::neash::display::BlendMode ALPHA;
		static inline ::neash::display::BlendMode ALPHA_dyn() { return ALPHA; }
		static ::neash::display::BlendMode DARKEN;
		static inline ::neash::display::BlendMode DARKEN_dyn() { return DARKEN; }
		static ::neash::display::BlendMode DIFFERENCE;
		static inline ::neash::display::BlendMode DIFFERENCE_dyn() { return DIFFERENCE; }
		static ::neash::display::BlendMode ERASE;
		static inline ::neash::display::BlendMode ERASE_dyn() { return ERASE; }
		static ::neash::display::BlendMode HARDLIGHT;
		static inline ::neash::display::BlendMode HARDLIGHT_dyn() { return HARDLIGHT; }
		static ::neash::display::BlendMode INVERT;
		static inline ::neash::display::BlendMode INVERT_dyn() { return INVERT; }
		static ::neash::display::BlendMode LAYER;
		static inline ::neash::display::BlendMode LAYER_dyn() { return LAYER; }
		static ::neash::display::BlendMode LIGHTEN;
		static inline ::neash::display::BlendMode LIGHTEN_dyn() { return LIGHTEN; }
		static ::neash::display::BlendMode MULTIPLY;
		static inline ::neash::display::BlendMode MULTIPLY_dyn() { return MULTIPLY; }
		static ::neash::display::BlendMode NORMAL;
		static inline ::neash::display::BlendMode NORMAL_dyn() { return NORMAL; }
		static ::neash::display::BlendMode OVERLAY;
		static inline ::neash::display::BlendMode OVERLAY_dyn() { return OVERLAY; }
		static ::neash::display::BlendMode SCREEN;
		static inline ::neash::display::BlendMode SCREEN_dyn() { return SCREEN; }
		static ::neash::display::BlendMode SUBTRACT;
		static inline ::neash::display::BlendMode SUBTRACT_dyn() { return SUBTRACT; }
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_BlendMode */ 
