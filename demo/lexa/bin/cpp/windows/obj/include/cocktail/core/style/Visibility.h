#ifndef INCLUDED_cocktail_core_style_Visibility
#define INCLUDED_cocktail_core_style_Visibility

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Visibility)
namespace cocktail{
namespace core{
namespace style{


class Visibility_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Visibility_obj OBJ_;

	public:
		Visibility_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Visibility"); }
		::String __ToString() const { return HX_CSTRING("Visibility.") + tag; }

		static ::cocktail::core::style::Visibility hidden;
		static inline ::cocktail::core::style::Visibility hidden_dyn() { return hidden; }
		static ::cocktail::core::style::Visibility visible;
		static inline ::cocktail::core::style::Visibility visible_dyn() { return visible; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Visibility */ 
