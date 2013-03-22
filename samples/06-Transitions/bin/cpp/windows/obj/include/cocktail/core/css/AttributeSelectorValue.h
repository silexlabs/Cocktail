#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#define INCLUDED_cocktail_core_css_AttributeSelectorValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,AttributeSelectorValue)
namespace cocktail{
namespace core{
namespace css{


class AttributeSelectorValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AttributeSelectorValue_obj OBJ_;

	public:
		AttributeSelectorValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.AttributeSelectorValue"); }
		::String __ToString() const { return HX_CSTRING("AttributeSelectorValue.") + tag; }

		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE(::String value);
		static Dynamic ATTRIBUTE_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_LIST(::String name,::String value);
		static Dynamic ATTRIBUTE_LIST_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_VALUE(::String name,::String value);
		static Dynamic ATTRIBUTE_VALUE_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_VALUE_BEGINS(::String name,::String value);
		static Dynamic ATTRIBUTE_VALUE_BEGINS_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(::String name,::String value);
		static Dynamic ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_VALUE_CONTAINS(::String name,::String value);
		static Dynamic ATTRIBUTE_VALUE_CONTAINS_dyn();
		static ::cocktail::core::css::AttributeSelectorValue ATTRIBUTE_VALUE_ENDS(::String name,::String value);
		static Dynamic ATTRIBUTE_VALUE_ENDS_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_AttributeSelectorValue */ 
