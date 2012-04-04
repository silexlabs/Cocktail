#ifndef INCLUDED_cocktail_core_style_TransformFunction
#define INCLUDED_cocktail_core_style_TransformFunction

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,TransformFunction)
HX_DECLARE_CLASS3(cocktail,core,style,Translation)
HX_DECLARE_CLASS3(cocktail,core,unit,Angle)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.style.TransformFunction"); }
		::String __ToString() const { return HX_CSTRING("TransformFunction.") + tag; }

		static ::cocktail::core::style::TransformFunction matrix(Dynamic data);
		static Dynamic matrix_dyn();
		static ::cocktail::core::style::TransformFunction rotate(::cocktail::core::unit::Angle angle);
		static Dynamic rotate_dyn();
		static ::cocktail::core::style::TransformFunction scale(double sx,double sy);
		static Dynamic scale_dyn();
		static ::cocktail::core::style::TransformFunction scaleX(double sx);
		static Dynamic scaleX_dyn();
		static ::cocktail::core::style::TransformFunction scaleY(double sy);
		static Dynamic scaleY_dyn();
		static ::cocktail::core::style::TransformFunction skew(::cocktail::core::unit::Angle angleX,::cocktail::core::unit::Angle angleY);
		static Dynamic skew_dyn();
		static ::cocktail::core::style::TransformFunction skewX(::cocktail::core::unit::Angle angle);
		static Dynamic skewX_dyn();
		static ::cocktail::core::style::TransformFunction skewY(::cocktail::core::unit::Angle angle);
		static Dynamic skewY_dyn();
		static ::cocktail::core::style::TransformFunction translate(::cocktail::core::style::Translation tx,::cocktail::core::style::Translation ty);
		static Dynamic translate_dyn();
		static ::cocktail::core::style::TransformFunction translateX(::cocktail::core::style::Translation tx);
		static Dynamic translateX_dyn();
		static ::cocktail::core::style::TransformFunction translateY(::cocktail::core::style::Translation ty);
		static Dynamic translateY_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_TransformFunction */ 
