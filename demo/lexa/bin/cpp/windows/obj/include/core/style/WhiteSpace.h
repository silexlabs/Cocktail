#ifndef INCLUDED_core_style_WhiteSpace
#define INCLUDED_core_style_WhiteSpace

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,WhiteSpace)
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
		::String GetEnumName( ) const { return HX_CSTRING("core.style.WhiteSpace"); }
		::String __ToString() const { return HX_CSTRING("WhiteSpace.") + tag; }

		static ::core::style::WhiteSpace normal;
		static inline ::core::style::WhiteSpace normal_dyn() { return normal; }
		static ::core::style::WhiteSpace nowrap;
		static inline ::core::style::WhiteSpace nowrap_dyn() { return nowrap; }
		static ::core::style::WhiteSpace pre;
		static inline ::core::style::WhiteSpace pre_dyn() { return pre; }
		static ::core::style::WhiteSpace preLine;
		static inline ::core::style::WhiteSpace preLine_dyn() { return preLine; }
		static ::core::style::WhiteSpace preWrap;
		static inline ::core::style::WhiteSpace preWrap_dyn() { return preWrap; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_WhiteSpace */ 
