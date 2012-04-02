#ifndef INCLUDED_core_unit_FontSizeRelativeSize
#define INCLUDED_core_unit_FontSizeRelativeSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,FontSizeRelativeSize)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.FontSizeRelativeSize"); }
		::String __ToString() const { return HX_CSTRING("FontSizeRelativeSize.") + tag; }

		static ::core::unit::FontSizeRelativeSize larger;
		static inline ::core::unit::FontSizeRelativeSize larger_dyn() { return larger; }
		static ::core::unit::FontSizeRelativeSize smaller;
		static inline ::core::unit::FontSizeRelativeSize smaller_dyn() { return smaller; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_FontSizeRelativeSize */ 
