#ifndef INCLUDED_cocktail_core_css_SelectorSpecificityVO
#define INCLUDED_cocktail_core_css_SelectorSpecificityVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,SelectorSpecificityVO)
namespace cocktail{
namespace core{
namespace css{


class SelectorSpecificityVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SelectorSpecificityVO_obj OBJ_;
		SelectorSpecificityVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SelectorSpecificityVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SelectorSpecificityVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SelectorSpecificityVO"); }

		int typeAndPseudoElementsNumber; /* REM */ 
		int classAttributesAndPseudoClassesNumber; /* REM */ 
		int idSelectorsNumber; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_SelectorSpecificityVO */ 
