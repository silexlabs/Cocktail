#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#define INCLUDED_cocktail_core_css_UserActionPseudoClassValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,UserActionPseudoClassValue)
namespace cocktail{
namespace core{
namespace css{


class UserActionPseudoClassValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef UserActionPseudoClassValue_obj OBJ_;

	public:
		UserActionPseudoClassValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.UserActionPseudoClassValue"); }
		::String __ToString() const { return HX_CSTRING("UserActionPseudoClassValue.") + tag; }

		static ::cocktail::core::css::UserActionPseudoClassValue ACTIVE;
		static inline ::cocktail::core::css::UserActionPseudoClassValue ACTIVE_dyn() { return ACTIVE; }
		static ::cocktail::core::css::UserActionPseudoClassValue FOCUS;
		static inline ::cocktail::core::css::UserActionPseudoClassValue FOCUS_dyn() { return FOCUS; }
		static ::cocktail::core::css::UserActionPseudoClassValue HOVER;
		static inline ::cocktail::core::css::UserActionPseudoClassValue HOVER_dyn() { return HOVER; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_UserActionPseudoClassValue */ 
