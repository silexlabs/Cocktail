#ifndef INCLUDED_cocktail_core_dom_JointStyleValue
#define INCLUDED_cocktail_core_dom_JointStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,JointStyleValue)
namespace cocktail{
namespace core{
namespace dom{


class JointStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef JointStyleValue_obj OBJ_;

	public:
		JointStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.dom.JointStyleValue"); }
		::String __ToString() const { return HX_CSTRING("JointStyleValue.") + tag; }

		static ::cocktail::core::dom::JointStyleValue bevel;
		static inline ::cocktail::core::dom::JointStyleValue bevel_dyn() { return bevel; }
		static ::cocktail::core::dom::JointStyleValue miter;
		static inline ::cocktail::core::dom::JointStyleValue miter_dyn() { return miter; }
		static ::cocktail::core::dom::JointStyleValue round;
		static inline ::cocktail::core::dom::JointStyleValue round_dyn() { return round; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_JointStyleValue */ 
