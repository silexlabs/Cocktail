#ifndef INCLUDED_cocktail_core_layout_computer_VisualEffectStylesComputer
#define INCLUDED_cocktail_core_layout_computer_VisualEffectStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSAngleValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTranslationValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS4(cocktail,core,layout,computer,VisualEffectStylesComputer)
namespace cocktail{
namespace core{
namespace layout{
namespace computer{


class VisualEffectStylesComputer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VisualEffectStylesComputer_obj OBJ_;
		VisualEffectStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< VisualEffectStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VisualEffectStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VisualEffectStylesComputer"); }

		static Void compute( ::cocktail::core::css::CoreStyle style);
		static Dynamic compute_dyn();

		static ::cocktail::core::geom::PointVO getComputedTransformOrigin( ::cocktail::core::css::CoreStyle style);
		static Dynamic getComputedTransformOrigin_dyn();

		static ::cocktail::core::geom::Matrix getComputedTransform( ::cocktail::core::css::CoreStyle style);
		static Dynamic getComputedTransform_dyn();

		static Float getComputedTranslation( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSTranslationValue translation,Float percentReference);
		static Dynamic getComputedTranslation_dyn();

		static Float getRadFromAngle( ::cocktail::core::css::CSSAngleValue value);
		static Dynamic getRadFromAngle_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer

#endif /* INCLUDED_cocktail_core_layout_computer_VisualEffectStylesComputer */ 
