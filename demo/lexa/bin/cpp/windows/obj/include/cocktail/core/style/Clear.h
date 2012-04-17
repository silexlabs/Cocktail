#ifndef INCLUDED_cocktail_core_style_Clear
#define INCLUDED_cocktail_core_style_Clear

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Clear)
namespace cocktail{
namespace core{
namespace style{


class Clear_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Clear_obj OBJ_;

	public:
		Clear_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Clear"); }
		::String __ToString() const { return HX_CSTRING("Clear.") + tag; }

		static ::cocktail::core::style::Clear both;
		static inline ::cocktail::core::style::Clear both_dyn() { return both; }
		static ::cocktail::core::style::Clear left;
		static inline ::cocktail::core::style::Clear left_dyn() { return left; }
		static ::cocktail::core::style::Clear none;
		static inline ::cocktail::core::style::Clear none_dyn() { return none; }
		static ::cocktail::core::style::Clear right;
		static inline ::cocktail::core::style::Clear right_dyn() { return right; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Clear */ 
