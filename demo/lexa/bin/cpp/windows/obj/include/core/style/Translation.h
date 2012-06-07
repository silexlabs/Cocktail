#ifndef INCLUDED_core_style_Translation
#define INCLUDED_core_style_Translation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Translation)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class Translation_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Translation_obj OBJ_;

	public:
		Translation_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Translation"); }
		::String __ToString() const { return HX_CSTRING("Translation.") + tag; }

		static ::core::style::Translation length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::Translation percent(int value);
		static Dynamic percent_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Translation */ 
