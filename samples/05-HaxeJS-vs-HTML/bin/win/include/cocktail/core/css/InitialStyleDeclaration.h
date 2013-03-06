#ifndef INCLUDED_cocktail_core_css_InitialStyleDeclaration
#define INCLUDED_cocktail_core_css_InitialStyleDeclaration

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/css/CSSStyleDeclaration.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,InitialStyleDeclaration)
namespace cocktail{
namespace core{
namespace css{


class InitialStyleDeclaration_obj : public ::cocktail::core::css::CSSStyleDeclaration_obj{
	public:
		typedef ::cocktail::core::css::CSSStyleDeclaration_obj super;
		typedef InitialStyleDeclaration_obj OBJ_;
		InitialStyleDeclaration_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< InitialStyleDeclaration_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InitialStyleDeclaration_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InitialStyleDeclaration"); }

		virtual Void pushComputedProperty( int index,::cocktail::core::css::CSSPropertyValue typedValue);
		Dynamic pushComputedProperty_dyn();

		virtual Void initComputedProperties( );
		Dynamic initComputedProperties_dyn();

		virtual Void pushProperty( int index,::cocktail::core::css::CSSPropertyValue typedValue);
		Dynamic pushProperty_dyn();

		virtual Void initProperties( );
		Dynamic initProperties_dyn();

		virtual Void initSupportedCSSProperties( );
		Dynamic initSupportedCSSProperties_dyn();

		virtual Void initColorCSSProperties( );
		Dynamic initColorCSSProperties_dyn();

		virtual Void initLengthCSSProperties( );
		Dynamic initLengthCSSProperties_dyn();

		::cocktail::core::css::CSSStyleDeclaration initialComputedStyleDeclaration; /* REM */ 
		Array< int > colorCSSProperties; /* REM */ 
		Array< int > lengthCSSProperties; /* REM */ 
		Array< int > supportedCSSProperties; /* REM */ 
		static ::cocktail::core::css::InitialStyleDeclaration _instance; /* REM */ 
		static ::cocktail::core::css::InitialStyleDeclaration getInstance( );
		static Dynamic getInstance_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_InitialStyleDeclaration */ 
