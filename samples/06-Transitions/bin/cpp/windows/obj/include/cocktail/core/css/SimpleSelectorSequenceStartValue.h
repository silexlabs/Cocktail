#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#define INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceStartValue)
namespace cocktail{
namespace core{
namespace css{


class SimpleSelectorSequenceStartValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef SimpleSelectorSequenceStartValue_obj OBJ_;

	public:
		SimpleSelectorSequenceStartValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.SimpleSelectorSequenceStartValue"); }
		::String __ToString() const { return HX_CSTRING("SimpleSelectorSequenceStartValue.") + tag; }

		static ::cocktail::core::css::SimpleSelectorSequenceStartValue TYPE(::String value);
		static Dynamic TYPE_dyn();
		static ::cocktail::core::css::SimpleSelectorSequenceStartValue UNIVERSAL;
		static inline ::cocktail::core::css::SimpleSelectorSequenceStartValue UNIVERSAL_dyn() { return UNIVERSAL; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue */ 
