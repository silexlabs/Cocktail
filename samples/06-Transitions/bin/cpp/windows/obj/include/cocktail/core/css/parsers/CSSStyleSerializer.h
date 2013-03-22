#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleSerializer
#define INCLUDED_cocktail_core_css_parsers_CSSStyleSerializer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSAngleValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorKeyword)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSFrequencyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSResolutionValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTimeValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTransformFunctionValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSTranslationValue)
HX_DECLARE_CLASS4(cocktail,core,css,parsers,CSSStyleSerializer)
namespace cocktail{
namespace core{
namespace css{
namespace parsers{


class CSSStyleSerializer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSStyleSerializer_obj OBJ_;
		CSSStyleSerializer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CSSStyleSerializer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSStyleSerializer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSStyleSerializer"); }

		static ::String serialize( ::cocktail::core::css::CSSPropertyValue property);
		static Dynamic serialize_dyn();

		static ::String serializeList( Array< ::cocktail::core::css::CSSPropertyValue > list);
		static Dynamic serializeList_dyn();

		static ::String serializeGroup( Array< ::cocktail::core::css::CSSPropertyValue > group);
		static Dynamic serializeGroup_dyn();

		static ::String serializeTransformFunction( ::cocktail::core::css::CSSTransformFunctionValue transformFunction);
		static Dynamic serializeTransformFunction_dyn();

		static ::String serializeTranslation( ::cocktail::core::css::CSSTranslationValue translation);
		static Dynamic serializeTranslation_dyn();

		static ::String serializeColor( ::cocktail::core::css::CSSColorValue color);
		static Dynamic serializeColor_dyn();

		static ::String serializeColorKeyword( ::cocktail::core::css::CSSColorKeyword keyword);
		static Dynamic serializeColorKeyword_dyn();

		static ::String serializeResolution( ::cocktail::core::css::CSSResolutionValue resolution);
		static Dynamic serializeResolution_dyn();

		static ::String serializeLength( ::cocktail::core::css::CSSLengthValue length);
		static Dynamic serializeLength_dyn();

		static ::String serializeFrequency( ::cocktail::core::css::CSSFrequencyValue frequency);
		static Dynamic serializeFrequency_dyn();

		static ::String serializeAngle( ::cocktail::core::css::CSSAngleValue angle);
		static Dynamic serializeAngle_dyn();

		static ::String serializeTime( ::cocktail::core::css::CSSTimeValue time);
		static Dynamic serializeTime_dyn();

		static ::String serializeKeyword( ::cocktail::core::css::CSSKeywordValue keyword);
		static Dynamic serializeKeyword_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers

#endif /* INCLUDED_cocktail_core_css_parsers_CSSStyleSerializer */ 
