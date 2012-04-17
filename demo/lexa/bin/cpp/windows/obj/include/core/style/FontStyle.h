#ifndef INCLUDED_core_style_FontStyle
#define INCLUDED_core_style_FontStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,FontStyle)
namespace core{
namespace style{


class FontStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontStyle_obj OBJ_;

	public:
		FontStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.FontStyle"); }
		::String __ToString() const { return HX_CSTRING("FontStyle.") + tag; }

		static ::core::style::FontStyle italic;
		static inline ::core::style::FontStyle italic_dyn() { return italic; }
		static ::core::style::FontStyle normal;
		static inline ::core::style::FontStyle normal_dyn() { return normal; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_FontStyle */ 
