#ifndef INCLUDED_cocktail_core_dom_CapsStyleValue
#define INCLUDED_cocktail_core_dom_CapsStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,CapsStyleValue)
namespace cocktail{
namespace core{
namespace dom{


class CapsStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CapsStyleValue_obj OBJ_;

	public:
		CapsStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.dom.CapsStyleValue"); }
		::String __ToString() const { return HX_CSTRING("CapsStyleValue.") + tag; }

		static ::cocktail::core::dom::CapsStyleValue none;
		static inline ::cocktail::core::dom::CapsStyleValue none_dyn() { return none; }
		static ::cocktail::core::dom::CapsStyleValue round;
		static inline ::cocktail::core::dom::CapsStyleValue round_dyn() { return round; }
		static ::cocktail::core::dom::CapsStyleValue square;
		static inline ::cocktail::core::dom::CapsStyleValue square_dyn() { return square; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_CapsStyleValue */ 
