#ifndef INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize
#define INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeAbsoluteSize)
namespace cocktail{
namespace core{
namespace unit{


class FontSizeAbsoluteSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontSizeAbsoluteSize_obj OBJ_;

	public:
		FontSizeAbsoluteSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.FontSizeAbsoluteSize"); }
		::String __ToString() const { return HX_CSTRING("FontSizeAbsoluteSize.") + tag; }

		static ::cocktail::core::unit::FontSizeAbsoluteSize large;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize large_dyn() { return large; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize medium;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize medium_dyn() { return medium; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize small;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize small_dyn() { return small; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize xLarge;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize xLarge_dyn() { return xLarge; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize xSmall;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize xSmall_dyn() { return xSmall; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize xxLarge;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize xxLarge_dyn() { return xxLarge; }
		static ::cocktail::core::unit::FontSizeAbsoluteSize xxSmall;
		static inline ::cocktail::core::unit::FontSizeAbsoluteSize xxSmall_dyn() { return xxSmall; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize */ 
