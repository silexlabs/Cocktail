#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer
#define INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedBlockBoxStylesComputer)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,EmbeddedInlineBoxStylesComputer)
namespace core{
namespace style{
namespace computer{
namespace boxComputers{


class EmbeddedInlineBoxStylesComputer_obj : public ::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj{
	public:
		typedef ::core::style::computer::boxComputers::EmbeddedBlockBoxStylesComputer_obj super;
		typedef EmbeddedInlineBoxStylesComputer_obj OBJ_;
		EmbeddedInlineBoxStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EmbeddedInlineBoxStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedInlineBoxStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedInlineBoxStylesComputer"); }

		virtual int getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin);
		Dynamic getComputedAutoMargin_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers

#endif /* INCLUDED_core_style_computer_boxComputers_EmbeddedInlineBoxStylesComputer */ 
