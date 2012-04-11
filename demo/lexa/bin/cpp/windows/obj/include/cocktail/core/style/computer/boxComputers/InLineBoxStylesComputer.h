#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,InLineBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class InLineBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef InLineBoxStylesComputer_obj OBJ_;
		InLineBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InLineBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InLineBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InLineBoxStylesComputer"); }

		virtual Void measureVerticalPaddings( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPaddings_dyn();

		virtual Void measureAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

		virtual int getComputedWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedWidth_dyn();

		virtual int getComputedHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedHeight_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer */ 
