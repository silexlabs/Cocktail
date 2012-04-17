#ifndef INCLUDED_core_style_TextAlign
#define INCLUDED_core_style_TextAlign

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TextAlign)
namespace core{
namespace style{


class TextAlign_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextAlign_obj OBJ_;

	public:
		TextAlign_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TextAlign"); }
		::String __ToString() const { return HX_CSTRING("TextAlign.") + tag; }

		static ::core::style::TextAlign center;
		static inline ::core::style::TextAlign center_dyn() { return center; }
		static ::core::style::TextAlign justify;
		static inline ::core::style::TextAlign justify_dyn() { return justify; }
		static ::core::style::TextAlign left;
		static inline ::core::style::TextAlign left_dyn() { return left; }
		static ::core::style::TextAlign right;
		static inline ::core::style::TextAlign right_dyn() { return right; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TextAlign */ 
