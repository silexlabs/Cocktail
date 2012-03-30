#ifndef INCLUDED_core_style_TransformOriginX
#define INCLUDED_core_style_TransformOriginX

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TransformOriginX)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class TransformOriginX_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TransformOriginX_obj OBJ_;

	public:
		TransformOriginX_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TransformOriginX"); }
		::String __ToString() const { return HX_CSTRING("TransformOriginX.") + tag; }

		static ::core::style::TransformOriginX center;
		static inline ::core::style::TransformOriginX center_dyn() { return center; }
		static ::core::style::TransformOriginX left;
		static inline ::core::style::TransformOriginX left_dyn() { return left; }
		static ::core::style::TransformOriginX length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::TransformOriginX percent(int value);
		static Dynamic percent_dyn();
		static ::core::style::TransformOriginX right;
		static inline ::core::style::TransformOriginX right_dyn() { return right; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TransformOriginX */ 
