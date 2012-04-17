#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,PositionedBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class PositionedBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::BoxStylesComputer_obj super;
		typedef PositionedBoxStylesComputer_obj OBJ_;
		PositionedBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PositionedBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PositionedBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PositionedBoxStylesComputer"); }

		virtual int shrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic shrinkToFit_dyn();

		virtual int applyContentHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeight_dyn();

		virtual Void measurePositionOffsets( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoWidth_dyn();

		virtual Void measureWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureWidth_dyn();

		virtual Void measureAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureAutoHeight_dyn();

		virtual Void measureHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHeight_dyn();

		virtual int getComputedStaticLeft( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticLeft_dyn();

		virtual int getComputedStaticTop( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticTop_dyn();

		virtual int doShrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth);
		Dynamic doShrinkToFit_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer */ 
