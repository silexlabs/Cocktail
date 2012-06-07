#ifndef INCLUDED_core_style_Clear
#define INCLUDED_core_style_Clear

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,Clear)
namespace core{
namespace style{


class Clear_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Clear_obj OBJ_;

	public:
		Clear_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.Clear"); }
		::String __ToString() const { return HX_CSTRING("Clear.") + tag; }

		static ::core::style::Clear both;
		static inline ::core::style::Clear both_dyn() { return both; }
		static ::core::style::Clear left;
		static inline ::core::style::Clear left_dyn() { return left; }
		static ::core::style::Clear none;
		static inline ::core::style::Clear none_dyn() { return none; }
		static ::core::style::Clear right;
		static inline ::core::style::Clear right_dyn() { return right; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_Clear */ 
