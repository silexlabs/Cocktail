#ifndef INCLUDED_core_style_GenericFontFamily
#define INCLUDED_core_style_GenericFontFamily

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,GenericFontFamily)
namespace core{
namespace style{


class GenericFontFamily_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GenericFontFamily_obj OBJ_;

	public:
		GenericFontFamily_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.GenericFontFamily"); }
		::String __ToString() const { return HX_CSTRING("GenericFontFamily.") + tag; }

		static ::core::style::GenericFontFamily monospace;
		static inline ::core::style::GenericFontFamily monospace_dyn() { return monospace; }
		static ::core::style::GenericFontFamily sansSerif;
		static inline ::core::style::GenericFontFamily sansSerif_dyn() { return sansSerif; }
		static ::core::style::GenericFontFamily serif;
		static inline ::core::style::GenericFontFamily serif_dyn() { return serif; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_GenericFontFamily */ 
