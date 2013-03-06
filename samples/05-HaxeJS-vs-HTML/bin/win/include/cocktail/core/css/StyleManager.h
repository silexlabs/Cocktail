#ifndef INCLUDED_cocktail_core_css_StyleManager
#define INCLUDED_cocktail_core_css_StyleManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,MatchedPseudoClassesVO)
HX_DECLARE_CLASS3(cocktail,core,css,PropertyVO)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorManager)
HX_DECLARE_CLASS3(cocktail,core,css,StyleDeclarationVO)
HX_DECLARE_CLASS3(cocktail,core,css,StyleManager)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace css{


class StyleManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StyleManager_obj OBJ_;
		StyleManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< StyleManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StyleManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StyleManager"); }

		virtual Array< ::cocktail::core::css::PropertyVO > getSortedMatchingPropertiesBySpecificity( Array< ::cocktail::core::css::PropertyVO > matchingProperties);
		Dynamic getSortedMatchingPropertiesBySpecificity_dyn();

		virtual Array< ::cocktail::core::css::PropertyVO > getSortedMatchingPropertiesByPriority( Array< ::cocktail::core::css::PropertyVO > matchingProperties);
		Dynamic getSortedMatchingPropertiesByPriority_dyn();

		virtual Void applyMatchingProperty( int propertyIndex,Array< ::cocktail::core::css::StyleDeclarationVO > matchingStyleDeclarations,::cocktail::core::css::CSSStyleDeclaration nodeStyleDeclaration);
		Dynamic applyMatchingProperty_dyn();

		virtual Array< ::cocktail::core::css::StyleDeclarationVO > getMatchingStyleDeclarations( ::cocktail::core::html::HTMLElement node,Array< ::cocktail::core::css::CSSStyleSheet > styleSheets,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic getMatchingStyleDeclarations_dyn();

		virtual bool alreadyMatched( int propertyIndex,Array< int > matchedProperties);
		Dynamic alreadyMatched_dyn();

		virtual Void applyStyleSheets( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::CSSStyleDeclaration nodeStyleDeclaration,Array< ::cocktail::core::css::CSSStyleSheet > styleSheets,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic applyStyleSheets_dyn();

		virtual ::cocktail::core::css::CSSStyleDeclaration getStyleDeclaration( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses);
		Dynamic getStyleDeclaration_dyn();

		virtual Void removeStyleSheet( ::cocktail::core::css::CSSStyleSheet styleSheet);
		Dynamic removeStyleSheet_dyn();

		virtual Void addStyleSheet( ::cocktail::core::css::CSSStyleSheet styleSheet);
		Dynamic addStyleSheet_dyn();

		Array< ::cocktail::core::css::PropertyVO > _authorImportantDeclarations; /* REM */ 
		Array< ::cocktail::core::css::PropertyVO > _authorNormalDeclarations; /* REM */ 
		Array< ::cocktail::core::css::PropertyVO > _userAgentDeclarations; /* REM */ 
		Array< ::cocktail::core::css::PropertyVO > _mostSpecificMatchingProperties; /* REM */ 
		Array< ::cocktail::core::css::PropertyVO > _matchingProperties; /* REM */ 
		Array< ::cocktail::core::css::StyleDeclarationVO > _matchingStyleDeclaration; /* REM */ 
		Array< int > _matchedProperties; /* REM */ 
		::cocktail::core::css::SelectorManager _selectorManager; /* REM */ 
		Array< ::cocktail::core::css::CSSStyleSheet > _styleSheets; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_StyleManager */ 
