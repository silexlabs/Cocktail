#ifndef INCLUDED_core_style_TransformFunction
#define INCLUDED_core_style_TransformFunction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,TransformFunction)
HX_DECLARE_CLASS2(core,style,Translation)
HX_DECLARE_CLASS2(core,unit,Angle)
namespace core{
namespace style{


class TransformFunction_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TransformFunction_obj OBJ_;

	public:
		TransformFunction_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.style.TransformFunction"); }
		::String __ToString() const { return HX_CSTRING("TransformFunction.") + tag; }

		static ::core::style::TransformFunction matrix(Dynamic data);
		static Dynamic matrix_dyn();
		static ::core::style::TransformFunction rotate(::core::unit::Angle angle);
		static Dynamic rotate_dyn();
		static ::core::style::TransformFunction scale(double sx,double sy);
		static Dynamic scale_dyn();
		static ::core::style::TransformFunction scaleX(double sx);
		static Dynamic scaleX_dyn();
		static ::core::style::TransformFunction scaleY(double sy);
		static Dynamic scaleY_dyn();
		static ::core::style::TransformFunction skew(::core::unit::Angle angleX,::core::unit::Angle angleY);
		static Dynamic skew_dyn();
		static ::core::style::TransformFunction skewX(::core::unit::Angle angle);
		static Dynamic skewX_dyn();
		static ::core::style::TransformFunction skewY(::core::unit::Angle angle);
		static Dynamic skewY_dyn();
		static ::core::style::TransformFunction translate(::core::style::Translation tx,::core::style::Translation ty);
		static Dynamic translate_dyn();
		static ::core::style::TransformFunction translateX(::core::style::Translation tx);
		static Dynamic translateX_dyn();
		static ::core::style::TransformFunction translateY(::core::style::Translation ty);
		static Dynamic translateY_dyn();
};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_TransformFunction */ 
