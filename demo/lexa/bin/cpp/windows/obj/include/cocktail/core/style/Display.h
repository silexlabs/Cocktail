#ifndef INCLUDED_cocktail_core_style_Display
#define INCLUDED_cocktail_core_style_Display

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Display)
namespace cocktail{
namespace core{
namespace style{


class Display_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Display_obj OBJ_;

	public:
		Display_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Display"); }
		::String __ToString() const { return HX_CSTRING("Display.") + tag; }

		static ::cocktail::core::style::Display block;
		static inline ::cocktail::core::style::Display block_dyn() { return block; }
		static ::cocktail::core::style::Display cssInline;
		static inline ::cocktail::core::style::Display cssInline_dyn() { return cssInline; }
		static ::cocktail::core::style::Display inlineBlock;
		static inline ::cocktail::core::style::Display inlineBlock_dyn() { return inlineBlock; }
		static ::cocktail::core::style::Display none;
		static inline ::cocktail::core::style::Display none_dyn() { return none; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Display */ 
