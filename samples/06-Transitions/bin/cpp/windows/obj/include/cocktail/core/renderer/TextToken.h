#ifndef INCLUDED_cocktail_core_renderer_TextToken
#define INCLUDED_cocktail_core_renderer_TextToken

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,renderer,TextToken)
namespace cocktail{
namespace core{
namespace renderer{


class TextToken_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextToken_obj OBJ_;

	public:
		TextToken_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.renderer.TextToken"); }
		::String __ToString() const { return HX_CSTRING("TextToken.") + tag; }

		static ::cocktail::core::renderer::TextToken lineFeed;
		static inline ::cocktail::core::renderer::TextToken lineFeed_dyn() { return lineFeed; }
		static ::cocktail::core::renderer::TextToken space;
		static inline ::cocktail::core::renderer::TextToken space_dyn() { return space; }
		static ::cocktail::core::renderer::TextToken tab;
		static inline ::cocktail::core::renderer::TextToken tab_dyn() { return tab; }
		static ::cocktail::core::renderer::TextToken word(::String value);
		static Dynamic word_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_TextToken */ 
