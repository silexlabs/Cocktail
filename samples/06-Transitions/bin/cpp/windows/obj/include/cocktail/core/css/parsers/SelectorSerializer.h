#ifndef INCLUDED_cocktail_core_css_parsers_SelectorSerializer
#define INCLUDED_cocktail_core_css_parsers_SelectorSerializer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,AttributeSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CombinatorValue)
HX_DECLARE_CLASS3(cocktail,core,css,LinkPseudoClassValue)
HX_DECLARE_CLASS3(cocktail,core,css,PseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,PseudoElementSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceItemValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceStartValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceVO)
HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,UIElementStatesValue)
HX_DECLARE_CLASS3(cocktail,core,css,UserActionPseudoClassValue)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,SelectorSerializer)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class SelectorSerializer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SelectorSerializer_obj OBJ_;
		SelectorSerializer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SelectorSerializer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SelectorSerializer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SelectorSerializer"); }

		static ::String serialize( ::cocktail::core::css::SelectorVO selector);
		static Dynamic serialize_dyn();

		static ::String serializePseudoElement( ::cocktail::core::css::PseudoElementSelectorValue pseudoElement);
		static Dynamic serializePseudoElement_dyn();

		static ::String serializeSimpleSelectorSequence( ::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence);
		static Dynamic serializeSimpleSelectorSequence_dyn();

		static ::String serializeCombinator( ::cocktail::core::css::CombinatorValue combinator);
		static Dynamic serializeCombinator_dyn();

		static ::String serializeStartValue( ::cocktail::core::css::SimpleSelectorSequenceStartValue selectorStartValue);
		static Dynamic serializeStartValue_dyn();

		static ::String serializeSimpleSelector( ::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelector);
		static Dynamic serializeSimpleSelector_dyn();

		static ::String serializeAttributeSelector( ::cocktail::core::css::AttributeSelectorValue attributeSelector);
		static Dynamic serializeAttributeSelector_dyn();

		static ::String serializePseudoClassSelector( ::cocktail::core::css::PseudoClassSelectorValue pseudoClassSelector);
		static Dynamic serializePseudoClassSelector_dyn();

		static ::String serializeUIElementStatePseudoClass( ::cocktail::core::css::UIElementStatesValue uiElementStateSelector);
		static Dynamic serializeUIElementStatePseudoClass_dyn();

		static ::String serializeLangPseudoClassSelector( Array< ::String > langs);
		static Dynamic serializeLangPseudoClassSelector_dyn();

		static ::String serializeLinkPseudoClassSelector( ::cocktail::core::css::LinkPseudoClassValue linkPseudoClassSelector);
		static Dynamic serializeLinkPseudoClassSelector_dyn();

		static ::String serializeUserActionPseudoClassSelector( ::cocktail::core::css::UserActionPseudoClassValue userActionPseudoClassSelector);
		static Dynamic serializeUserActionPseudoClassSelector_dyn();

		static ::String serializeStructuralPseudoClassSelector( ::cocktail::core::css::StructuralPseudoClassSelectorValue structuralpseudoClassSelector);
		static Dynamic serializeStructuralPseudoClassSelector_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_SelectorSerializer */ 
