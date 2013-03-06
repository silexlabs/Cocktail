#ifndef INCLUDED_cocktail_core_html_TimeRanges
#define INCLUDED_cocktail_core_html_TimeRanges

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,html,TimeRanges)
namespace cocktail{
namespace core{
namespace html{


class TimeRanges_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TimeRanges_obj OBJ_;
		TimeRanges_obj();
		Void __construct(Dynamic ranges);

	public:
		static hx::ObjectPtr< TimeRanges_obj > __new(Dynamic ranges);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimeRanges_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TimeRanges"); }

		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual Float end( int index);
		Dynamic end_dyn();

		virtual Float start( int index);
		Dynamic start_dyn();

		Dynamic _ranges; /* REM */ 
		int length; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_TimeRanges */ 
