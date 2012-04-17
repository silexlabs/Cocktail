#ifndef INCLUDED_cocktail_core_dom_GradientTypeValue
#define INCLUDED_cocktail_core_dom_GradientTypeValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,GradientTypeValue)
namespace cocktail{
namespace core{
namespace dom{


class GradientTypeValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GradientTypeValue_obj OBJ_;

	public:
		GradientTypeValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.dom.GradientTypeValue"); }
		::String __ToString() const { return HX_CSTRING("GradientTypeValue.") + tag; }

		static ::cocktail::core::dom::GradientTypeValue linear;
		static inline ::cocktail::core::dom::GradientTypeValue linear_dyn() { return linear; }
		static ::cocktail::core::dom::GradientTypeValue radial;
		static inline ::cocktail::core::dom::GradientTypeValue radial_dyn() { return radial; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_GradientTypeValue */ 