#ifndef INCLUDED_core_style_TextTransform
#define INCLUDED_core_style_TextTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TextTransform)
namespace core{
namespace style{


class TextTransform_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextTransform_obj OBJ_;

	public:
		TextTransform_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TextTransform"); }
		::String __ToString() const { return HX_CSTRING("TextTransform.") + tag; }

		static ::core::style::TextTransform capitalize;
		static inline ::core::style::TextTransform capitalize_dyn() { return capitalize; }
		static ::core::style::TextTransform lowercase;
		static inline ::core::style::TextTransform lowercase_dyn() { return lowercase; }
		static ::core::style::TextTransform none;
		static inline ::core::style::TextTransform none_dyn() { return none; }
		static ::core::style::TextTransform uppercase;
		static inline ::core::style::TextTransform uppercase_dyn() { return uppercase; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TextTransform */ 
