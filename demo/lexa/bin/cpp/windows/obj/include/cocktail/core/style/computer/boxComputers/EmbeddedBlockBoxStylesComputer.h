#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class EmbeddedBlockBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef EmbeddedBlockBoxStylesComputer_obj OBJ_;
		EmbeddedBlockBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedBlockBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedBlockBoxStylesComputer"); }

		virtual Void measureAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoWidth_dyn();

		virtual int getComputedAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoWidth_dyn();

		virtual int getComputedAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedAutoHeight_dyn();

		virtual int getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer */ 
