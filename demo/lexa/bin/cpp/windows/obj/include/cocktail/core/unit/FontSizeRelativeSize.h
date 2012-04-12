#ifndef INCLUDED_cocktail_core_unit_FontSizeRelativeSize
#define INCLUDED_cocktail_core_unit_FontSizeRelativeSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,unit,FontSizeRelativeSize)
namespace cocktail{
namespace core{
namespace unit{


class FontSizeRelativeSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontSizeRelativeSize_obj OBJ_;

	public:
		FontSizeRelativeSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.unit.FontSizeRelativeSize"); }
		::String __ToString() const { return HX_CSTRING("FontSizeRelativeSize.") + tag; }

		static ::cocktail::core::unit::FontSizeRelativeSize larger;
		static inline ::cocktail::core::unit::FontSizeRelativeSize larger_dyn() { return larger; }
		static ::cocktail::core::unit::FontSizeRelativeSize smaller;
		static inline ::cocktail::core::unit::FontSizeRelativeSize smaller_dyn() { return smaller; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace unit

#endif /* INCLUDED_cocktail_core_unit_FontSizeRelativeSize */ 
