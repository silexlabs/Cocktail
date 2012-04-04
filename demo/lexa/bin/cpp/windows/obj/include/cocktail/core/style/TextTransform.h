#ifndef INCLUDED_cocktail_core_style_TextTransform
#define INCLUDED_cocktail_core_style_TextTransform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,TextTransform)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.TextTransform"); }
		::String __ToString() const { return HX_CSTRING("TextTransform.") + tag; }

		static ::cocktail::core::style::TextTransform capitalize;
		static inline ::cocktail::core::style::TextTransform capitalize_dyn() { return capitalize; }
		static ::cocktail::core::style::TextTransform lowercase;
		static inline ::cocktail::core::style::TextTransform lowercase_dyn() { return lowercase; }
		static ::cocktail::core::style::TextTransform none;
		static inline ::cocktail::core::style::TextTransform none_dyn() { return none; }
		static ::cocktail::core::style::TextTransform uppercase;
		static inline ::cocktail::core::style::TextTransform uppercase_dyn() { return uppercase; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_TextTransform */ 
