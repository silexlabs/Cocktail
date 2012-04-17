#ifndef INCLUDED_cocktail_core_style_Cursor
#define INCLUDED_cocktail_core_style_Cursor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,Cursor)
namespace cocktail{
namespace core{
namespace style{


class Cursor_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Cursor_obj OBJ_;

	public:
		Cursor_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.Cursor"); }
		::String __ToString() const { return HX_CSTRING("Cursor.") + tag; }

		static ::cocktail::core::style::Cursor crosshair;
		static inline ::cocktail::core::style::Cursor crosshair_dyn() { return crosshair; }
		static ::cocktail::core::style::Cursor cssAuto;
		static inline ::cocktail::core::style::Cursor cssAuto_dyn() { return cssAuto; }
		static ::cocktail::core::style::Cursor cssDefault;
		static inline ::cocktail::core::style::Cursor cssDefault_dyn() { return cssDefault; }
		static ::cocktail::core::style::Cursor pointer;
		static inline ::cocktail::core::style::Cursor pointer_dyn() { return pointer; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_Cursor */ 
