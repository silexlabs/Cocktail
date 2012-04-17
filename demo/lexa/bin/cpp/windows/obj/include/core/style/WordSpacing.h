#ifndef INCLUDED_core_style_WordSpacing
#define INCLUDED_core_style_WordSpacing

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,WordSpacing)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class WordSpacing_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef WordSpacing_obj OBJ_;

	public:
		WordSpacing_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.WordSpacing"); }
		::String __ToString() const { return HX_CSTRING("WordSpacing.") + tag; }

		static ::core::style::WordSpacing length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::WordSpacing normal;
		static inline ::core::style::WordSpacing normal_dyn() { return normal; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_WordSpacing */ 
