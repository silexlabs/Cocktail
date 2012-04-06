#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#define INCLUDED_cocktail_core_style_BackgroundSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSize)
namespace cocktail{
namespace core{
namespace style{


class BackgroundSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BackgroundSize_obj OBJ_;

	public:
		BackgroundSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.BackgroundSize"); }
		::String __ToString() const { return HX_CSTRING("BackgroundSize.") + tag; }

		static ::cocktail::core::style::BackgroundSize contain;
		static inline ::cocktail::core::style::BackgroundSize contain_dyn() { return contain; }
		static ::cocktail::core::style::BackgroundSize cover;
		static inline ::cocktail::core::style::BackgroundSize cover_dyn() { return cover; }
		static ::cocktail::core::style::BackgroundSize dimensions(Dynamic value);
		static Dynamic dimensions_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_BackgroundSize */ 
