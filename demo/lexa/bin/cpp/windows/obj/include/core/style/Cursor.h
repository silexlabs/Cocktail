#ifndef INCLUDED_core_style_Cursor
#define INCLUDED_core_style_Cursor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Cursor)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Cursor"); }
		::String __ToString() const { return HX_CSTRING("Cursor.") + tag; }

		static ::core::style::Cursor _auto;
		static inline ::core::style::Cursor _auto_dyn() { return _auto; }
		static ::core::style::Cursor crosshair;
		static inline ::core::style::Cursor crosshair_dyn() { return crosshair; }
		static ::core::style::Cursor cssDefault;
		static inline ::core::style::Cursor cssDefault_dyn() { return cssDefault; }
		static ::core::style::Cursor pointer;
		static inline ::core::style::Cursor pointer_dyn() { return pointer; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Cursor */ 
