#ifndef INCLUDED_core_style_LetterSpacing
#define INCLUDED_core_style_LetterSpacing

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,LetterSpacing)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class LetterSpacing_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LetterSpacing_obj OBJ_;

	public:
		LetterSpacing_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.LetterSpacing"); }
		::String __ToString() const { return HX_CSTRING("LetterSpacing.") + tag; }

		static ::core::style::LetterSpacing length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::LetterSpacing normal;
		static inline ::core::style::LetterSpacing normal_dyn() { return normal; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_LetterSpacing */ 
