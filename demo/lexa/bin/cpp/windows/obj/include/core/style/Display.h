#ifndef INCLUDED_core_style_Display
#define INCLUDED_core_style_Display

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Display)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Display"); }
		::String __ToString() const { return HX_CSTRING("Display.") + tag; }

		static ::core::style::Display block;
		static inline ::core::style::Display block_dyn() { return block; }
		static ::core::style::Display cssInline;
		static inline ::core::style::Display cssInline_dyn() { return cssInline; }
		static ::core::style::Display inlineBlock;
		static inline ::core::style::Display inlineBlock_dyn() { return inlineBlock; }
		static ::core::style::Display none;
		static inline ::core::style::Display none_dyn() { return none; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Display */ 
