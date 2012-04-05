#ifndef INCLUDED_core_style_computer_VisualEffectStylesComputer
#define INCLUDED_core_style_computer_VisualEffectStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,geom,Matrix)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,Translation)
HX_DECLARE_CLASS3(core,style,computer,VisualEffectStylesComputer)
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

		static Void compute( ::core::style::AbstractStyle style);
		static Dynamic compute_dyn();

		static bool getComputedVisibility( ::core::style::AbstractStyle style);
		static Dynamic getComputedVisibility_dyn();

		static Dynamic getComputedTransformOrigin( ::core::style::AbstractStyle style);
		static Dynamic getComputedTransformOrigin_dyn();

		static ::core::geom::Matrix getComputedTransform( ::core::style::AbstractStyle style);
		static Dynamic getComputedTransform_dyn();

		static double getComputedTranslation( ::core::style::AbstractStyle style,::core::style::Translation translation,int percentReference);
		static Dynamic getComputedTranslation_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_core_style_computer_VisualEffectStylesComputer */ 
