#ifndef INCLUDED_cocktail_core_style_WhiteSpace
#define INCLUDED_cocktail_core_style_WhiteSpace

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,WhiteSpace)
namespace cocktail{
namespace core{
namespace style{


class WhiteSpace_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef WhiteSpace_obj OBJ_;

	public:
		WhiteSpace_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.WhiteSpace"); }
		::String __ToString() const { return HX_CSTRING("WhiteSpace.") + tag; }

		static ::cocktail::core::style::WhiteSpace normal;
		static inline ::cocktail::core::style::WhiteSpace normal_dyn() { return normal; }
		static ::cocktail::core::style::WhiteSpace nowrap;
		static inline ::cocktail::core::style::WhiteSpace nowrap_dyn() { return nowrap; }
		static ::cocktail::core::style::WhiteSpace pre;
		static inline ::cocktail::core::style::WhiteSpace pre_dyn() { return pre; }
		static ::cocktail::core::style::WhiteSpace preLine;
		static inline ::cocktail::core::style::WhiteSpace preLine_dyn() { return preLine; }
		static ::cocktail::core::style::WhiteSpace preWrap;
		static inline ::cocktail::core::style::WhiteSpace preWrap_dyn() { return preWrap; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_WhiteSpace */ 
