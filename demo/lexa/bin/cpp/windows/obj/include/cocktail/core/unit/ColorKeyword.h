#ifndef INCLUDED_cocktail_core_unit_ColorKeyword
#define INCLUDED_cocktail_core_unit_ColorKeyword

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,ColorKeyword)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.ColorKeyword"); }
		::String __ToString() const { return HX_CSTRING("ColorKeyword.") + tag; }

		static ::cocktail::core::unit::ColorKeyword aqua;
		static inline ::cocktail::core::unit::ColorKeyword aqua_dyn() { return aqua; }
		static ::cocktail::core::unit::ColorKeyword black;
		static inline ::cocktail::core::unit::ColorKeyword black_dyn() { return black; }
		static ::cocktail::core::unit::ColorKeyword blue;
		static inline ::cocktail::core::unit::ColorKeyword blue_dyn() { return blue; }
		static ::cocktail::core::unit::ColorKeyword fuchsia;
		static inline ::cocktail::core::unit::ColorKeyword fuchsia_dyn() { return fuchsia; }
		static ::cocktail::core::unit::ColorKeyword gray;
		static inline ::cocktail::core::unit::ColorKeyword gray_dyn() { return gray; }
		static ::cocktail::core::unit::ColorKeyword green;
		static inline ::cocktail::core::unit::ColorKeyword green_dyn() { return green; }
		static ::cocktail::core::unit::ColorKeyword lime;
		static inline ::cocktail::core::unit::ColorKeyword lime_dyn() { return lime; }
		static ::cocktail::core::unit::ColorKeyword maroon;
		static inline ::cocktail::core::unit::ColorKeyword maroon_dyn() { return maroon; }
		static ::cocktail::core::unit::ColorKeyword navy;
		static inline ::cocktail::core::unit::ColorKeyword navy_dyn() { return navy; }
		static ::cocktail::core::unit::ColorKeyword olive;
		static inline ::cocktail::core::unit::ColorKeyword olive_dyn() { return olive; }
		static ::cocktail::core::unit::ColorKeyword orange;
		static inline ::cocktail::core::unit::ColorKeyword orange_dyn() { return orange; }
		static ::cocktail::core::unit::ColorKeyword purple;
		static inline ::cocktail::core::unit::ColorKeyword purple_dyn() { return purple; }
		static ::cocktail::core::unit::ColorKeyword red;
		static inline ::cocktail::core::unit::ColorKeyword red_dyn() { return red; }
		static ::cocktail::core::unit::ColorKeyword silver;
		static inline ::cocktail::core::unit::ColorKeyword silver_dyn() { return silver; }
		static ::cocktail::core::unit::ColorKeyword teal;
		static inline ::cocktail::core::unit::ColorKeyword teal_dyn() { return teal; }
		static ::cocktail::core::unit::ColorKeyword white;
		static inline ::cocktail::core::unit::ColorKeyword white_dyn() { return white; }
		static ::cocktail::core::unit::ColorKeyword yellow;
		static inline ::cocktail::core::unit::ColorKeyword yellow_dyn() { return yellow; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_ColorKeyword */ 
