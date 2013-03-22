#ifndef INCLUDED_cocktail_core_url_URL
#define INCLUDED_cocktail_core_url_URL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,url,URL)
namespace cocktail{
namespace core{
namespace url{


class URL_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef URL_obj OBJ_;
		URL_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< URL_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~URL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("URL"); }

		::String fragment; /* REM */ 
		::String query; /* REM */ 
		::String file; /* REM */ 
		::String directory; /* REM */ 
		::String path; /* REM */ 
		::String relative; /* REM */ 
		::String port; /* REM */ 
		::String host; /* REM */ 
		::String password; /* REM */ 
		::String user; /* REM */ 
		::String userInfo; /* REM */ 
		::String authority; /* REM */ 
		::String scheme; /* REM */ 
		::String source; /* REM */ 
		::String url; /* REM */ 
		static Array< ::String > _parts; /* REM */ 
		static ::cocktail::core::url::URL fromString( ::String url);
		static Dynamic fromString_dyn();

		static ::String toString( ::cocktail::core::url::URL url);
		static Dynamic toString_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace url

#endif /* INCLUDED_cocktail_core_url_URL */ 
