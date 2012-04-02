#ifndef INCLUDED_core_style_TransformOriginY
#define INCLUDED_core_style_TransformOriginY

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TransformOriginY)
HX_DECLARE_CLASS2(core,unit,Length)
namespace core{
namespace style{


class TransformOriginY_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TransformOriginY_obj OBJ_;

	public:
		TransformOriginY_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TransformOriginY"); }
		::String __ToString() const { return HX_CSTRING("TransformOriginY.") + tag; }

		static ::core::style::TransformOriginY bottom;
		static inline ::core::style::TransformOriginY bottom_dyn() { return bottom; }
		static ::core::style::TransformOriginY center;
		static inline ::core::style::TransformOriginY center_dyn() { return center; }
		static ::core::style::TransformOriginY length(::core::unit::Length value);
		static Dynamic length_dyn();
		static ::core::style::TransformOriginY percent(int value);
		static Dynamic percent_dyn();
		static ::core::style::TransformOriginY top;
		static inline ::core::style::TransformOriginY top_dyn() { return top; }
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TransformOriginY */ 
