#ifndef INCLUDED_core_style_FontSize
#define INCLUDED_core_style_FontSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,FontSize)
HX_DECLARE_CLASS2(core,unit,FontSizeAbsoluteSize)
HX_DECLARE_CLASS2(core,unit,FontSizeRelativeSize)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class FontSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontSize_obj OBJ_;

	public:
		FontSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.FontSize"); }
		::String __ToString() const { return HX_CSTRING("FontSize.") + tag; }

		static ::core::style::FontSize absoluteSize(::core::unit::FontSizeAbsoluteSize value);
		static Dynamic absoluteSize_dyn();
		static ::core::style::FontSize length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::FontSize percentage(int value);
		static Dynamic percentage_dyn();
		static ::core::style::FontSize relativeSize(::core::unit::FontSizeRelativeSize value);
		static Dynamic relativeSize_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_FontSize */ 
