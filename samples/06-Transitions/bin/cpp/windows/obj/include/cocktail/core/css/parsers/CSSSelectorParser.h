#ifndef INCLUDED_cocktail_core_css_parsers_CSSSelectorParser
#define INCLUDED_cocktail_core_css_parsers_CSSSelectorParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,SelectorComponentValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceItemValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceStartValue)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSSelectorParser)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class CSSSelectorParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSSelectorParser_obj OBJ_;
		CSSSelectorParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSSelectorParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSSelectorParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSSelectorParser"); }

		virtual ::String getFirstType( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getFirstType_dyn();

		virtual ::String getFirstId( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getFirstId_dyn();

		virtual bool getIsSimpleTypeSelector( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getIsSimpleTypeSelector_dyn();

		virtual bool getIsSimpleIdSelector( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getIsSimpleIdSelector_dyn();

		virtual bool getIsSimpleClassSelector( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getIsSimpleClassSelector_dyn();

		virtual ::String getFirstClass( Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic getFirstClass_dyn();

		virtual int parseAttributeSelector( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues);
		Dynamic parseAttributeSelector_dyn();

		virtual int parsePseudoElement( ::String selector,int position,::cocktail::core::css::SelectorVO selectorData);
		Dynamic parsePseudoElement_dyn();

		virtual int parsePseudoClass( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues);
		Dynamic parsePseudoClass_dyn();

		virtual Void flushSelectors( ::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStartValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues,Array< ::cocktail::core::css::SelectorComponentValue > components);
		Dynamic flushSelectors_dyn();

		virtual bool parseSelector( ::String selector,Array< ::cocktail::core::css::SelectorVO > typedSelectors);
		Dynamic parseSelector_dyn();

		static bool isOperatorChar( int c);
		static Dynamic isOperatorChar_dyn();

		static bool isAsciiChar( int c);
		static Dynamic isAsciiChar_dyn();

		static bool isSelectorChar( int c);
		static Dynamic isSelectorChar_dyn();

		static bool isPseudoClassChar( int c);
		static Dynamic isPseudoClassChar_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_CSSSelectorParser */ 
