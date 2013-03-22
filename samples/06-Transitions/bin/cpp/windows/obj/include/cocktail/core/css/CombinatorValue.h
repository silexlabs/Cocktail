#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#define INCLUDED_cocktail_core_css_CombinatorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CombinatorValue)
namespace cocktail{
namespace core{
namespace css{


class CombinatorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CombinatorValue_obj OBJ_;

	public:
		CombinatorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CombinatorValue"); }
		::String __ToString() const { return HX_CSTRING("CombinatorValue.") + tag; }

		static ::cocktail::core::css::CombinatorValue ADJACENT_SIBLING;
		static inline ::cocktail::core::css::CombinatorValue ADJACENT_SIBLING_dyn() { return ADJACENT_SIBLING; }
		static ::cocktail::core::css::CombinatorValue CHILD;
		static inline ::cocktail::core::css::CombinatorValue CHILD_dyn() { return CHILD; }
		static ::cocktail::core::css::CombinatorValue DESCENDANT;
		static inline ::cocktail::core::css::CombinatorValue DESCENDANT_dyn() { return DESCENDANT; }
		static ::cocktail::core::css::CombinatorValue GENERAL_SIBLING;
		static inline ::cocktail::core::css::CombinatorValue GENERAL_SIBLING_dyn() { return GENERAL_SIBLING; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CombinatorValue */ 
