#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#define INCLUDED_cocktail_core_css_UsedValuesVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
HX_DECLARE_CLASS3(cocktail,core,css,UsedValuesVO)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
namespace cocktail{
namespace core{
namespace css{


class UsedValuesVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef UsedValuesVO_obj OBJ_;
		UsedValuesVO_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< UsedValuesVO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~UsedValuesVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UsedValuesVO"); }

		::cocktail::core::css::ColorVO outlineColor; /* REM */ 
		Float outlineWidth; /* REM */ 
		::cocktail::core::css::ColorVO borderLeftColor; /* REM */ 
		::cocktail::core::css::ColorVO borderBottomColor; /* REM */ 
		::cocktail::core::css::ColorVO borderRightColor; /* REM */ 
		::cocktail::core::css::ColorVO borderTopColor; /* REM */ 
		Float borderBottomWidth; /* REM */ 
		Float borderTopWidth; /* REM */ 
		Float borderRightWidth; /* REM */ 
		Float borderLeftWidth; /* REM */ 
		::cocktail::core::css::ColorVO backgroundColor; /* REM */ 
		::cocktail::core::geom::Matrix transform; /* REM */ 
		::cocktail::core::geom::PointVO transformOrigin; /* REM */ 
		Float letterSpacing; /* REM */ 
		Float lineHeight; /* REM */ 
		::cocktail::core::css::ColorVO color; /* REM */ 
		Float textIndent; /* REM */ 
		Float bottom; /* REM */ 
		Float top; /* REM */ 
		Float right; /* REM */ 
		Float left; /* REM */ 
		Float paddingBottom; /* REM */ 
		Float paddingTop; /* REM */ 
		Float paddingRight; /* REM */ 
		Float paddingLeft; /* REM */ 
		Float marginBottom; /* REM */ 
		Float marginTop; /* REM */ 
		Float marginRight; /* REM */ 
		Float marginLeft; /* REM */ 
		Float height; /* REM */ 
		Float maxWidth; /* REM */ 
		Float minWidth; /* REM */ 
		Float maxHeight; /* REM */ 
		Float minHeight; /* REM */ 
		Float width; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_UsedValuesVO */ 
