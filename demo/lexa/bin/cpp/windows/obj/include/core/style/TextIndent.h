#ifndef INCLUDED_core_style_TextIndent
#define INCLUDED_core_style_TextIndent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TextIndent)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class TextIndent_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextIndent_obj OBJ_;

	public:
		TextIndent_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TextIndent"); }
		::String __ToString() const { return HX_CSTRING("TextIndent.") + tag; }

		static ::core::style::TextIndent length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::TextIndent percentage(int value);
		static Dynamic percentage_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TextIndent */ 
