#ifndef INCLUDED_cocktail_core_css_ColorVO
#define INCLUDED_cocktail_core_css_ColorVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
namespace cocktail{
namespace core{
namespace css{


class ColorVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColorVO_obj OBJ_;
		ColorVO_obj();
		Void __construct(int color,Float alpha);

	public:
		static hx::ObjectPtr< ColorVO_obj > __new(int color,Float alpha);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ColorVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColorVO"); }

		Float alpha; /* REM */ 
		int color; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_ColorVO */ 
