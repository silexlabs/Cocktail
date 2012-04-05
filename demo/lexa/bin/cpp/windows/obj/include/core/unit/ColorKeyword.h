#ifndef INCLUDED_core_unit_ColorKeyword
#define INCLUDED_core_unit_ColorKeyword

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,ColorKeyword)
namespace core{
namespace unit{


class ColorKeyword_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ColorKeyword_obj OBJ_;

	public:
		ColorKeyword_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.ColorKeyword"); }
		::String __ToString() const { return HX_CSTRING("ColorKeyword.") + tag; }

		static ::core::unit::ColorKeyword aqua;
		static inline ::core::unit::ColorKeyword aqua_dyn() { return aqua; }
		static ::core::unit::ColorKeyword black;
		static inline ::core::unit::ColorKeyword black_dyn() { return black; }
		static ::core::unit::ColorKeyword blue;
		static inline ::core::unit::ColorKeyword blue_dyn() { return blue; }
		static ::core::unit::ColorKeyword fuchsia;
		static inline ::core::unit::ColorKeyword fuchsia_dyn() { return fuchsia; }
		static ::core::unit::ColorKeyword gray;
		static inline ::core::unit::ColorKeyword gray_dyn() { return gray; }
		static ::core::unit::ColorKeyword green;
		static inline ::core::unit::ColorKeyword green_dyn() { return green; }
		static ::core::unit::ColorKeyword lime;
		static inline ::core::unit::ColorKeyword lime_dyn() { return lime; }
		static ::core::unit::ColorKeyword maroon;
		static inline ::core::unit::ColorKeyword maroon_dyn() { return maroon; }
		static ::core::unit::ColorKeyword navy;
		static inline ::core::unit::ColorKeyword navy_dyn() { return navy; }
		static ::core::unit::ColorKeyword olive;
		static inline ::core::unit::ColorKeyword olive_dyn() { return olive; }
		static ::core::unit::ColorKeyword orange;
		static inline ::core::unit::ColorKeyword orange_dyn() { return orange; }
		static ::core::unit::ColorKeyword purple;
		static inline ::core::unit::ColorKeyword purple_dyn() { return purple; }
		static ::core::unit::ColorKeyword red;
		static inline ::core::unit::ColorKeyword red_dyn() { return red; }
		static ::core::unit::ColorKeyword silver;
		static inline ::core::unit::ColorKeyword silver_dyn() { return silver; }
		static ::core::unit::ColorKeyword teal;
		static inline ::core::unit::ColorKeyword teal_dyn() { return teal; }
		static ::core::unit::ColorKeyword white;
		static inline ::core::unit::ColorKeyword white_dyn() { return white; }
		static ::core::unit::ColorKeyword yellow;
		static inline ::core::unit::ColorKeyword yellow_dyn() { return yellow; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_ColorKeyword */ 
