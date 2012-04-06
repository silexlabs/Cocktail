#ifndef INCLUDED_cocktail_core_style_computer_FontAndTextStylesComputer
#define INCLUDED_cocktail_core_style_computer_FontAndTextStylesComputer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,TextAlign)
HX_DECLARE_CLASS3(cocktail,core,style,WhiteSpace)
HX_DECLARE_CLASS4(cocktail,core,style,computer,FontAndTextStylesComputer)
namespace cocktail{
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

		static Void compute( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		static Dynamic compute_dyn();

		static int getComputedTextIndent( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData);
		static Dynamic getComputedTextIndent_dyn();

		static double getComputedVerticalAlign( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		static Dynamic getComputedVerticalAlign_dyn();

		static ::cocktail::core::style::TextAlign getComputedTextAlign( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::WhiteSpace computedWhiteSpace);
		static Dynamic getComputedTextAlign_dyn();

		static Dynamic getComputedColor( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedColor_dyn();

		static int getComputedWordSpacing( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedWordSpacing_dyn();

		static double getComputedLineHeight( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedLineHeight_dyn();

		static int getComputedLetterSpacing( ::cocktail::core::style::CoreStyle style);
		static Dynamic getComputedLetterSpacing_dyn();

		static double getComputedFontSize( ::cocktail::core::style::CoreStyle style,double parentFontSize,double parentXHeight);
		static Dynamic getComputedFontSize_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer

#endif /* INCLUDED_cocktail_core_style_computer_FontAndTextStylesComputer */ 
