#ifndef INCLUDED_core_style_FontVariant
#define INCLUDED_core_style_FontVariant

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,FontVariant)
namespace core{
namespace style{


class FontVariant_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontVariant_obj OBJ_;

	public:
		FontVariant_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.FontVariant"); }
		::String __ToString() const { return HX_CSTRING("FontVariant.") + tag; }

		static ::core::style::FontVariant normal;
		static inline ::core::style::FontVariant normal_dyn() { return normal; }
		static ::core::style::FontVariant smallCaps;
		static inline ::core::style::FontVariant smallCaps_dyn() { return smallCaps; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_FontVariant */ 
