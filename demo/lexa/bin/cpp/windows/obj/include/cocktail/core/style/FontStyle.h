#ifndef INCLUDED_cocktail_core_style_FontStyle
#define INCLUDED_cocktail_core_style_FontStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,FontStyle)
namespace cocktail{
namespace core{
namespace style{


class FontStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontStyle_obj OBJ_;

	public:
		FontStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.FontStyle"); }
		::String __ToString() const { return HX_CSTRING("FontStyle.") + tag; }

		static ::cocktail::core::style::FontStyle italic;
		static inline ::cocktail::core::style::FontStyle italic_dyn() { return italic; }
		static ::cocktail::core::style::FontStyle normal;
		static inline ::cocktail::core::style::FontStyle normal_dyn() { return normal; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_FontStyle */ 
