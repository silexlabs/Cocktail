#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#define INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceItemValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceStartValue)
HX_DECLARE_CLASS3(cocktail,core,css,SimpleSelectorSequenceVO)
namespace cocktail{
namespace core{
namespace css{


class SimpleSelectorSequenceVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleSelectorSequenceVO_obj OBJ_;
		SimpleSelectorSequenceVO_obj();
		Void __construct(::cocktail::core::css::SimpleSelectorSequenceStartValue startValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors);

	public:
		static hx::ObjectPtr< SimpleSelectorSequenceVO_obj > __new(::cocktail::core::css::SimpleSelectorSequenceStartValue startValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SimpleSelectorSequenceVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SimpleSelectorSequenceVO"); }

		Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors; /* REM */ 
		::cocktail::core::css::SimpleSelectorSequenceStartValue startValue; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO */ 
