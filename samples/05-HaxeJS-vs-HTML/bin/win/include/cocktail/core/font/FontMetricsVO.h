#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#define INCLUDED_cocktail_core_font_FontMetricsVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
namespace cocktail{
namespace core{
namespace font{


class FontMetricsVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FontMetricsVO_obj OBJ_;
		FontMetricsVO_obj();
		Void __construct(Float fontSize,Float ascent,Float descent,Float xHeight,Float subscriptOffset,Float superscriptOffset,Float underlineOffset,Float spaceWidth);

	public:
		static hx::ObjectPtr< FontMetricsVO_obj > __new(Float fontSize,Float ascent,Float descent,Float xHeight,Float subscriptOffset,Float superscriptOffset,Float underlineOffset,Float spaceWidth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FontMetricsVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FontMetricsVO"); }

		Float spaceWidth; /* REM */ 
		Float underlineOffset; /* REM */ 
		Float superscriptOffset; /* REM */ 
		Float subscriptOffset; /* REM */ 
		Float xHeight; /* REM */ 
		Float descent; /* REM */ 
		Float ascent; /* REM */ 
		Float fontSize; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_FontMetricsVO */ 
