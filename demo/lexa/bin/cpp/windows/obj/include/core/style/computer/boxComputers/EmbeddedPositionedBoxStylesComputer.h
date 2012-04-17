#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedPositionedBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class EmbeddedPositionedBoxStylesComputer_obj : public ::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj super;
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

		virtual Void measurePositionOffsets( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measurePositionOffsets_dyn();

		virtual Void measureHorizontalPositionOffsets( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureHorizontalPositionOffsets_dyn();

		virtual Void measureVerticalPositionOffsets( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic measureVerticalPositionOffsets_dyn();

		virtual int getComputedStaticLeft( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticLeft_dyn();

		virtual int getComputedStaticTop( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		Dynamic getComputedStaticTop_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer */ 
