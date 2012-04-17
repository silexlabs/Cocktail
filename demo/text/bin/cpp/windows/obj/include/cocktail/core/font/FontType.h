#ifndef INCLUDED_cocktail_core_font_FontType
#define INCLUDED_cocktail_core_font_FontType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,font,FontType)
namespace cocktail{
namespace core{
namespace font{


class FontType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontType_obj OBJ_;

	public:
		FontType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.font.FontType"); }
		::String __ToString() const { return HX_CSTRING("FontType.") + tag; }

		static ::cocktail::core::font::FontType eot;
		static inline ::cocktail::core::font::FontType eot_dyn() { return eot; }
		static ::cocktail::core::font::FontType otf;
		static inline ::cocktail::core::font::FontType otf_dyn() { return otf; }
		static ::cocktail::core::font::FontType swf;
		static inline ::cocktail::core::font::FontType swf_dyn() { return swf; }
		static ::cocktail::core::font::FontType system;
		static inline ::cocktail::core::font::FontType system_dyn() { return system; }
		static ::cocktail::core::font::FontType ttf;
		static inline ::cocktail::core::font::FontType ttf_dyn() { return ttf; }
		static ::cocktail::core::font::FontType unknown;
		static inline ::cocktail::core::font::FontType unknown_dyn() { return unknown; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_FontType */ 
