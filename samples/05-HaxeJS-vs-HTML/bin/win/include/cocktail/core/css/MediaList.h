#ifndef INCLUDED_cocktail_core_css_MediaList
#define INCLUDED_cocktail_core_css_MediaList

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,MediaList)
namespace cocktail{
namespace core{
namespace css{


class MediaList_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MediaList_obj OBJ_;
		MediaList_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MediaList_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MediaList_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MediaList"); }

		virtual Void deleteMedium( ::String medium);
		Dynamic deleteMedium_dyn();

		virtual Void appendMedium( ::String medium);
		Dynamic appendMedium_dyn();

		virtual ::String item( int index);
		Dynamic item_dyn();

		int length; /* REM */ 
		::String mediaText; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_MediaList */ 
