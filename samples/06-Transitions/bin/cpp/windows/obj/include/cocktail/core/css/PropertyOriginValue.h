#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#define INCLUDED_cocktail_core_css_PropertyOriginValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,PropertyOriginValue)
namespace cocktail{
namespace core{
namespace css{


class PropertyOriginValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PropertyOriginValue_obj OBJ_;

	public:
		PropertyOriginValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.PropertyOriginValue"); }
		::String __ToString() const { return HX_CSTRING("PropertyOriginValue.") + tag; }

		static ::cocktail::core::css::PropertyOriginValue AUTHOR;
		static inline ::cocktail::core::css::PropertyOriginValue AUTHOR_dyn() { return AUTHOR; }
		static ::cocktail::core::css::PropertyOriginValue USER_AGENT;
		static inline ::cocktail::core::css::PropertyOriginValue USER_AGENT_dyn() { return USER_AGENT; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_PropertyOriginValue */ 
