#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#define INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,EmbeddedPositionedBoxStylesComputer)
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class EmbeddedPositionedBoxStylesComputer_obj : public ::cocktail::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj{
	public:
		typedef ::cocktail::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj super;
		typedef EmbeddedPositionedBoxStylesComputer_obj OBJ_;
		EmbeddedPositionedBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedPositionedBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedPositionedBoxStylesComputer"); }

		virtual Void measurePositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureHorizontalPositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHorizontalPositionOffsets_dyn();

		virtual Void measureVerticalPositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPositionOffsets_dyn();

		virtual int getComputedStaticLeft( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticLeft_dyn();

		virtual int getComputedStaticTop( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticTop_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer */ 
