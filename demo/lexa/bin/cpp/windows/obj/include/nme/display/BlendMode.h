#ifndef INCLUDED_nme_display_BlendMode
#define INCLUDED_nme_display_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,BlendMode)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.BlendMode"); }
		::String __ToString() const { return HX_CSTRING("BlendMode.") + tag; }

		static ::nme::display::BlendMode ADD;
		static inline ::nme::display::BlendMode ADD_dyn() { return ADD; }
		static ::nme::display::BlendMode ALPHA;
		static inline ::nme::display::BlendMode ALPHA_dyn() { return ALPHA; }
		static ::nme::display::BlendMode DARKEN;
		static inline ::nme::display::BlendMode DARKEN_dyn() { return DARKEN; }
		static ::nme::display::BlendMode DIFFERENCE;
		static inline ::nme::display::BlendMode DIFFERENCE_dyn() { return DIFFERENCE; }
		static ::nme::display::BlendMode ERASE;
		static inline ::nme::display::BlendMode ERASE_dyn() { return ERASE; }
		static ::nme::display::BlendMode HARDLIGHT;
		static inline ::nme::display::BlendMode HARDLIGHT_dyn() { return HARDLIGHT; }
		static ::nme::display::BlendMode INVERT;
		static inline ::nme::display::BlendMode INVERT_dyn() { return INVERT; }
		static ::nme::display::BlendMode LAYER;
		static inline ::nme::display::BlendMode LAYER_dyn() { return LAYER; }
		static ::nme::display::BlendMode LIGHTEN;
		static inline ::nme::display::BlendMode LIGHTEN_dyn() { return LIGHTEN; }
		static ::nme::display::BlendMode MULTIPLY;
		static inline ::nme::display::BlendMode MULTIPLY_dyn() { return MULTIPLY; }
		static ::nme::display::BlendMode NORMAL;
		static inline ::nme::display::BlendMode NORMAL_dyn() { return NORMAL; }
		static ::nme::display::BlendMode OVERLAY;
		static inline ::nme::display::BlendMode OVERLAY_dyn() { return OVERLAY; }
		static ::nme::display::BlendMode SCREEN;
		static inline ::nme::display::BlendMode SCREEN_dyn() { return SCREEN; }
		static ::nme::display::BlendMode SUBTRACT;
		static inline ::nme::display::BlendMode SUBTRACT_dyn() { return SUBTRACT; }
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_BlendMode */ 
