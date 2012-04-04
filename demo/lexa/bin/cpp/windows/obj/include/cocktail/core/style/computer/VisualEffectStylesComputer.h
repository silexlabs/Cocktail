#ifndef INCLUDED_cocktail_core_style_computer_VisualEffectStylesComputer
#define INCLUDED_cocktail_core_style_computer_VisualEffectStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Translation)
HX_DECLARE_CLASS4(cocktail,core,style,computer,VisualEffectStylesComputer)
namespace cocktail{
namespace core{
namespace style{
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
		::String __ToString() const { return HX_CSTRING("VisualEffectStylesComputer"); }

		static Void compute( ::cocktail::core::style::AbstractCoreStyle style);
		static Dynamic compute_dyn();

		static bool getComputedVisibility( ::cocktail::core::style::AbstractCoreStyle style);
		static Dynamic getComputedVisibility_dyn();

		static Dynamic getComputedTransformOrigin( ::cocktail::core::style::AbstractCoreStyle style);
		static Dynamic getComputedTransformOrigin_dyn();

		static ::cocktail::core::geom::Matrix getComputedTransform( ::cocktail::core::style::AbstractCoreStyle style);
		static Dynamic getComputedTransform_dyn();

		static double getComputedTranslation( ::cocktail::core::style::AbstractCoreStyle style,::cocktail::core::style::Translation translation,int percentReference);
		static Dynamic getComputedTranslation_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_cocktail_core_style_computer_VisualEffectStylesComputer */ 
