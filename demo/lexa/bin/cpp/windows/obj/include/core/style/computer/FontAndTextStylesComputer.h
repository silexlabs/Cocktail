#ifndef INCLUDED_core_style_computer_FontAndTextStylesComputer
#define INCLUDED_core_style_computer_FontAndTextStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,TextAlign)
HX_DECLARE_CLASS2(core,style,WhiteSpace)
HX_DECLARE_CLASS3(core,style,computer,FontAndTextStylesComputer)
namespace core{
namespace style{
namespace computer{


class FontAndTextStylesComputer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FontAndTextStylesComputer_obj OBJ_;
		FontAndTextStylesComputer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FontAndTextStylesComputer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontAndTextStylesComputer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontAndTextStylesComputer"); }

		static Void compute( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		static Dynamic compute_dyn();

		static int getComputedTextIndent( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData);
		static Dynamic getComputedTextIndent_dyn();

		static double getComputedVerticalAlign( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		static Dynamic getComputedVerticalAlign_dyn();

		static ::core::style::TextAlign getComputedTextAlign( ::core::style::AbstractStyle style,::core::style::WhiteSpace computedWhiteSpace);
		static Dynamic getComputedTextAlign_dyn();

		static Dynamic getComputedColor( ::core::style::AbstractStyle style);
		static Dynamic getComputedColor_dyn();

		static int getComputedWordSpacing( ::core::style::AbstractStyle style);
		static Dynamic getComputedWordSpacing_dyn();

		static double getComputedLineHeight( ::core::style::AbstractStyle style);
		static Dynamic getComputedLineHeight_dyn();

		static int getComputedLetterSpacing( ::core::style::AbstractStyle style);
		static Dynamic getComputedLetterSpacing_dyn();

		static double getComputedFontSize( ::core::style::AbstractStyle style,double parentFontSize,double parentXHeight);
		static Dynamic getComputedFontSize_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_core_style_computer_FontAndTextStylesComputer */ 
