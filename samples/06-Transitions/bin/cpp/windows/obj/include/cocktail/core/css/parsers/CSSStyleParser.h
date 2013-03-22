#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleParser
#define INCLUDED_cocktail_core_css_parsers_CSSStyleParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,TypedPropertyVO)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSStyleParser)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class CSSStyleParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSStyleParser_obj OBJ_;
		CSSStyleParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSStyleParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSStyleParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSStyleParser"); }

		static int _position; /* REM */ 
		static Array< ::cocktail::core::css::TypedPropertyVO > _typedProperties; /* REM */ 
		static Array< ::cocktail::core::css::TypedPropertyVO > parseStyle( ::String styles);
		static Dynamic parseStyle_dyn();

		static ::cocktail::core::css::TypedPropertyVO parseStyleValue( ::String propertyName,::String styles,int position);
		static Dynamic parseStyleValue_dyn();

		static int parseImportant( ::String styles,int position);
		static Dynamic parseImportant_dyn();

		static int parseIntegerNumberDimensionOrPercentage( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseIntegerNumberDimensionOrPercentage_dyn();

		static int parseDimension( Float numberOrInteger,::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseDimension_dyn();

		static int parseString( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseString_dyn();

		static int parseIdentOrFunctionnalNotation( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseIdentOrFunctionnalNotation_dyn();

		static int parseHexaColor( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseHexaColor_dyn();

		static int parseFunctionnalNotation( ::String ident,::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseFunctionnalNotation_dyn();

		static ::cocktail::core::css::CSSPropertyValue getFunctionalNotation( ::String name,::cocktail::core::css::CSSPropertyValue value);
		static Dynamic getFunctionalNotation_dyn();

		static ::cocktail::core::css::CSSPropertyValue parseRGBOrRGBA( ::cocktail::core::css::CSSPropertyValue property,bool isRGBA);
		static Dynamic parseRGBOrRGBA_dyn();

		static Void parseIdent( ::String ident,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseIdent_dyn();

		static Void parseKeyword( ::String ident,Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		static Dynamic parseKeyword_dyn();

		static ::cocktail::core::css::CSSPropertyValue parseColorKeyword( ::String ident);
		static Dynamic parseColorKeyword_dyn();

		static ::cocktail::core::css::CSSPropertyValue parseColorKeyword2( ::String ident);
		static Dynamic parseColorKeyword2_dyn();

		static bool isHexaChar( int c);
		static Dynamic isHexaChar_dyn();

		static bool isIdentChar( int c);
		static Dynamic isIdentChar_dyn();

		static bool isNumChar( int c);
		static Dynamic isNumChar_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_CSSStyleParser */ 
