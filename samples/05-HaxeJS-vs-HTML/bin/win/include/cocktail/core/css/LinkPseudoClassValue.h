#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#define INCLUDED_cocktail_core_css_LinkPseudoClassValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,LinkPseudoClassValue)
namespace cocktail{
namespace core{
namespace css{


class LinkPseudoClassValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LinkPseudoClassValue_obj OBJ_;

	public:
		LinkPseudoClassValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.LinkPseudoClassValue"); }
		::String __ToString() const { return HX_CSTRING("LinkPseudoClassValue.") + tag; }

		static ::cocktail::core::css::LinkPseudoClassValue LINK;
		static inline ::cocktail::core::css::LinkPseudoClassValue LINK_dyn() { return LINK; }
		static ::cocktail::core::css::LinkPseudoClassValue VISITED;
		static inline ::cocktail::core::css::LinkPseudoClassValue VISITED_dyn() { return VISITED; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_LinkPseudoClassValue */ 
