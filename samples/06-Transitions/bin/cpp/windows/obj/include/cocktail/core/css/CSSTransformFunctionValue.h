#ifndef INCLUDED_cocktail_core_css_CSSTransformFunctionValue
#define INCLUDED_cocktail_core_css_CSSTransformFunctionValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSAngleValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTransformFunctionValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTranslationValue)
namespace cocktail{
namespace core{
namespace css{


class CSSTransformFunctionValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSTransformFunctionValue_obj OBJ_;

	public:
		CSSTransformFunctionValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSTransformFunctionValue"); }
		::String __ToString() const { return HX_CSTRING("CSSTransformFunctionValue.") + tag; }

		static ::cocktail::core::css::CSSTransformFunctionValue MATRIX(Float a,Float b,Float c,Float d,Float e,Float f);
		static Dynamic MATRIX_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue ROTATE(::cocktail::core::css::CSSAngleValue angle);
		static Dynamic ROTATE_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SCALE(Float sx,Float sy);
		static Dynamic SCALE_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SCALE_X(Float sx);
		static Dynamic SCALE_X_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SCALE_Y(Float sy);
		static Dynamic SCALE_Y_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SKEW(::cocktail::core::css::CSSAngleValue angleX,::cocktail::core::css::CSSAngleValue angleY);
		static Dynamic SKEW_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SKEW_X(::cocktail::core::css::CSSAngleValue angle);
		static Dynamic SKEW_X_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue SKEW_Y(::cocktail::core::css::CSSAngleValue angle);
		static Dynamic SKEW_Y_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue TRANSLATE(::cocktail::core::css::CSSTranslationValue tx,::cocktail::core::css::CSSTranslationValue ty);
		static Dynamic TRANSLATE_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue TRANSLATE_X(::cocktail::core::css::CSSTranslationValue tx);
		static Dynamic TRANSLATE_X_dyn();
		static ::cocktail::core::css::CSSTransformFunctionValue TRANSLATE_Y(::cocktail::core::css::CSSTranslationValue ty);
		static Dynamic TRANSLATE_Y_dyn();
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSTransformFunctionValue */ 
