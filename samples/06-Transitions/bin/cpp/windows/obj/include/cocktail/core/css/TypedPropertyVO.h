#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#define INCLUDED_cocktail_core_css_TypedPropertyVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,TypedPropertyVO)
namespace cocktail{
namespace core{
namespace css{


class TypedPropertyVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TypedPropertyVO_obj OBJ_;
		TypedPropertyVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TypedPropertyVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TypedPropertyVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TypedPropertyVO"); }

		bool important; /* REM */ 
		::cocktail::core::css::CSSPropertyValue typedValue; /* REM */ 
		int index; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_TypedPropertyVO */ 
