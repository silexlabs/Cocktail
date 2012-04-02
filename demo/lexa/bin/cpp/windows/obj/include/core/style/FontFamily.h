#ifndef INCLUDED_core_style_FontFamily
#define INCLUDED_core_style_FontFamily

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,FontFamily)
HX_DECLARE_CLASS2(core,style,GenericFontFamily)
namespace core{
namespace style{


class FontFamily_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontFamily_obj OBJ_;

	public:
		FontFamily_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.FontFamily"); }
		::String __ToString() const { return HX_CSTRING("FontFamily.") + tag; }

		static ::core::style::FontFamily familyName(::String name);
		static Dynamic familyName_dyn();
		static ::core::style::FontFamily genericFamily(::core::style::GenericFontFamily genericName);
		static Dynamic genericFamily_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_FontFamily */ 
