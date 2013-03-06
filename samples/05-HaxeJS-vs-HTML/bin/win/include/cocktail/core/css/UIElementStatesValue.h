#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#define INCLUDED_cocktail_core_css_UIElementStatesValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,UIElementStatesValue)
namespace cocktail{
namespace core{
namespace css{


class UIElementStatesValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef UIElementStatesValue_obj OBJ_;

	public:
		UIElementStatesValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.UIElementStatesValue"); }
		::String __ToString() const { return HX_CSTRING("UIElementStatesValue.") + tag; }

		static ::cocktail::core::css::UIElementStatesValue CHECKED;
		static inline ::cocktail::core::css::UIElementStatesValue CHECKED_dyn() { return CHECKED; }
		static ::cocktail::core::css::UIElementStatesValue DISABLED;
		static inline ::cocktail::core::css::UIElementStatesValue DISABLED_dyn() { return DISABLED; }
		static ::cocktail::core::css::UIElementStatesValue ENABLED;
		static inline ::cocktail::core::css::UIElementStatesValue ENABLED_dyn() { return ENABLED; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_UIElementStatesValue */ 
