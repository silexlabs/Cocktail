#ifndef INCLUDED_core_style_CSSFloat
#define INCLUDED_core_style_CSSFloat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,CSSFloat)
namespace core{
namespace style{


class CSSFloat_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSFloat_obj OBJ_;

	public:
		CSSFloat_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.CSSFloat"); }
		::String __ToString() const { return HX_CSTRING("CSSFloat.") + tag; }

		static ::core::style::CSSFloat left;
		static inline ::core::style::CSSFloat left_dyn() { return left; }
		static ::core::style::CSSFloat none;
		static inline ::core::style::CSSFloat none_dyn() { return none; }
		static ::core::style::CSSFloat right;
		static inline ::core::style::CSSFloat right_dyn() { return right; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_CSSFloat */ 
