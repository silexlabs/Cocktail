#ifndef INCLUDED_cocktail_core_css_SelectorManager
#define INCLUDED_cocktail_core_css_SelectorManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,AttributeSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CombinatorValue)
HX_DECLARE_CLASS3(cocktail,core,css,LinkPseudoClassValue)
HX_DECLARE_CLASS3(cocktail,core,css,MatchedPseudoClassesVO)
HX_DECLARE_CLASS3(cocktail,core,css,PseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorComponentValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorManager)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorSpecificityVO)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceItemValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceStartValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceVO)
HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassArgumentValue)
HX_DECLARE_CLASS3(cocktail,core,css,StructuralPseudoClassSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,UIElementStatesValue)
HX_DECLARE_CLASS3(cocktail,core,css,UserActionPseudoClassValue)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace css{


class SelectorManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SelectorManager_obj OBJ_;
		SelectorManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SelectorManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SelectorManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SelectorManager"); }

		virtual Void getSimpleSelectorSequenceItemSpecificity( ::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequenceItem,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity);
		Dynamic getSimpleSelectorSequenceItemSpecificity_dyn();

		virtual Void getSimpleSelectorSequenceStartSpecificity( ::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStart,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity);
		Dynamic getSimpleSelectorSequenceStartSpecificity_dyn();

		virtual Void getSimpleSelectorSequenceSpecificity( ::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity);
		Dynamic getSimpleSelectorSequenceSpecificity_dyn();

		virtual int getSelectorSpecifity( ::cocktail::core::css::SelectorVO selector);
		Dynamic getSelectorSpecifity_dyn();

		virtual bool matchTargetPseudoClassSelector( ::cocktail::core::html::HTMLElement node);
		Dynamic matchTargetPseudoClassSelector_dyn();

		virtual bool matchUserActionPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::UserActionPseudoClassValue userActionPseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClass);
		Dynamic matchUserActionPseudoClassSelector_dyn();

		virtual bool matchLinkPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::LinkPseudoClassValue linkPseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClass);
		Dynamic matchLinkPseudoClassSelector_dyn();

		virtual bool matchOnlyOfType( ::cocktail::core::html::HTMLElement node);
		Dynamic matchOnlyOfType_dyn();

		virtual bool matchLastOfType( ::cocktail::core::html::HTMLElement node);
		Dynamic matchLastOfType_dyn();

		virtual bool matchFirstOfType( ::cocktail::core::html::HTMLElement node);
		Dynamic matchFirstOfType_dyn();

		virtual bool matchNthOfType( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		Dynamic matchNthOfType_dyn();

		virtual bool matchNthLastOfType( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		Dynamic matchNthLastOfType_dyn();

		virtual bool matchNthLastChild( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		Dynamic matchNthLastChild_dyn();

		virtual bool matchNthChild( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value);
		Dynamic matchNthChild_dyn();

		virtual bool matchStructuralPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassSelectorValue structuralPseudoClassSelector);
		Dynamic matchStructuralPseudoClassSelector_dyn();

		virtual bool matchLangPseudoClassSelector( ::cocktail::core::html::HTMLElement node,Array< ::String > lang);
		Dynamic matchLangPseudoClassSelector_dyn();

		virtual bool matchNegationPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO negationSimpleSelectorSequence);
		Dynamic matchNegationPseudoClassSelector_dyn();

		virtual bool matchUIElementStatesSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::UIElementStatesValue uiElementState,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchUIElementStatesSelector_dyn();

		virtual bool matchPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::PseudoClassSelectorValue pseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchPseudoClassSelector_dyn();

		virtual bool matchAttributeList( ::cocktail::core::html::HTMLElement node,::String name,::String value);
		Dynamic matchAttributeList_dyn();

		virtual bool matchAttributeBeginValue( ::cocktail::core::html::HTMLElement node,::String name,::String value);
		Dynamic matchAttributeBeginValue_dyn();

		virtual bool matchAttributeContainsValue( ::cocktail::core::html::HTMLElement node,::String name,::String value);
		Dynamic matchAttributeContainsValue_dyn();

		virtual bool matchAttributeEndValue( ::cocktail::core::html::HTMLElement node,::String name,::String value);
		Dynamic matchAttributeEndValue_dyn();

		virtual bool matchAttributeBeginsHyphenList( ::cocktail::core::html::HTMLElement node,::String name,::String value);
		Dynamic matchAttributeBeginsHyphenList_dyn();

		virtual bool matchAttributeSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::AttributeSelectorValue attributeSelector);
		Dynamic matchAttributeSelector_dyn();

		virtual bool matchSimpleSelectorSequence( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchSimpleSelectorSequence_dyn();

		virtual bool matchSimpleSelectorSequenceItem( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequenceItem,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchSimpleSelectorSequenceItem_dyn();

		virtual bool matchSimpleSelectorSequenceStart( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStart);
		Dynamic matchSimpleSelectorSequenceStart_dyn();

		virtual bool matchChildCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchChildCombinator_dyn();

		virtual bool matchDescendantCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchDescendantCombinator_dyn();

		virtual bool matchAdjacentSiblingCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchAdjacentSiblingCombinator_dyn();

		virtual bool matchGeneralSiblingCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchGeneralSiblingCombinator_dyn();

		virtual bool matchCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::CombinatorValue combinator,::cocktail::core::css::SelectorComponentValue nextSelectorComponent,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchCombinator_dyn();

		virtual bool matchSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SelectorVO selector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic matchSelector_dyn();

		::cocktail::core::css::SelectorSpecificityVO _selectorSpecificityVO; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SelectorManager */ 
