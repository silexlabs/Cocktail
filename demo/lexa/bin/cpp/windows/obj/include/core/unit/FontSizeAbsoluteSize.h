#ifndef INCLUDED_core_unit_FontSizeAbsoluteSize
#define INCLUDED_core_unit_FontSizeAbsoluteSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,unit,FontSizeAbsoluteSize)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.unit.FontSizeAbsoluteSize"); }
		::String __ToString() const { return HX_CSTRING("FontSizeAbsoluteSize.") + tag; }

		static ::core::unit::FontSizeAbsoluteSize large;
		static inline ::core::unit::FontSizeAbsoluteSize large_dyn() { return large; }
		static ::core::unit::FontSizeAbsoluteSize medium;
		static inline ::core::unit::FontSizeAbsoluteSize medium_dyn() { return medium; }
		static ::core::unit::FontSizeAbsoluteSize small;
		static inline ::core::unit::FontSizeAbsoluteSize small_dyn() { return small; }
		static ::core::unit::FontSizeAbsoluteSize xLarge;
		static inline ::core::unit::FontSizeAbsoluteSize xLarge_dyn() { return xLarge; }
		static ::core::unit::FontSizeAbsoluteSize xSmall;
		static inline ::core::unit::FontSizeAbsoluteSize xSmall_dyn() { return xSmall; }
		static ::core::unit::FontSizeAbsoluteSize xxLarge;
		static inline ::core::unit::FontSizeAbsoluteSize xxLarge_dyn() { return xxLarge; }
		static ::core::unit::FontSizeAbsoluteSize xxSmall;
		static inline ::core::unit::FontSizeAbsoluteSize xxSmall_dyn() { return xxSmall; }
};

} // end namespace core
} // end namespace unit

#endif /* INCLUDED_core_unit_FontSizeAbsoluteSize */ 
