#ifndef INCLUDED_cocktail_core_css_SelectorVO
#define INCLUDED_cocktail_core_css_SelectorVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,PseudoElementSelectorValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorComponentValue)
HX_DECLARE_CLASS3(cocktail,core,css,SelectorVO)
namespace cocktail{
namespace core{
namespace css{


class SelectorVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SelectorVO_obj OBJ_;
		SelectorVO_obj();
		Void __construct(Array< ::cocktail::core::css::SelectorComponentValue > components,::cocktail::core::css::PseudoElementSelectorValue pseudoElement,bool beginsWithClass,::String firstClass,bool beginsWithId,::String firstId,bool beginsWithType,::String firstType,bool isSimpleClassSelector,bool isSimpleIdSelector,bool isSimpleTypeSelector);

	public:
		static hx::ObjectPtr< SelectorVO_obj > __new(Array< ::cocktail::core::css::SelectorComponentValue > components,::cocktail::core::css::PseudoElementSelectorValue pseudoElement,bool beginsWithClass,::String firstClass,bool beginsWithId,::String firstId,bool beginsWithType,::String firstType,bool isSimpleClassSelector,bool isSimpleIdSelector,bool isSimpleTypeSelector);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SelectorVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SelectorVO"); }

		bool isSimpleTypeSelector; /* REM */ 
		bool isSimpleIdSelector; /* REM */ 
		bool isSimpleClassSelector; /* REM */ 
		::String firstType; /* REM */ 
		bool beginsWithType; /* REM */ 
		::String firstId; /* REM */ 
		bool beginsWithId; /* REM */ 
		::String firstClass; /* REM */ 
		bool beginsWithClass; /* REM */ 
		::cocktail::core::css::PseudoElementSelectorValue pseudoElement; /* REM */ 
		Array< ::cocktail::core::css::SelectorComponentValue > components; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SelectorVO */ 
