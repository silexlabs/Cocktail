#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#define INCLUDED_cocktail_core_layout_LayoutStateValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
namespace cocktail{
namespace core{
namespace layout{


class LayoutStateValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LayoutStateValue_obj OBJ_;

	public:
		LayoutStateValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.layout.LayoutStateValue"); }
		::String __ToString() const { return HX_CSTRING("LayoutStateValue.") + tag; }

		static ::cocktail::core::layout::LayoutStateValue NORMAL;
		static inline ::cocktail::core::layout::LayoutStateValue NORMAL_dyn() { return NORMAL; }
		static ::cocktail::core::layout::LayoutStateValue SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH;
		static inline ::cocktail::core::layout::LayoutStateValue SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH_dyn() { return SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH; }
		static ::cocktail::core::layout::LayoutStateValue SHRINK_TO_FIT_PREFERED_WIDTH;
		static inline ::cocktail::core::layout::LayoutStateValue SHRINK_TO_FIT_PREFERED_WIDTH_dyn() { return SHRINK_TO_FIT_PREFERED_WIDTH; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace layout

#endif /* INCLUDED_cocktail_core_layout_LayoutStateValue */ 
