#ifndef INCLUDED_cocktail_core_font_AbstractFontLoader
#define INCLUDED_cocktail_core_font_AbstractFontLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,font,AbstractFontLoader)
namespace cocktail{
namespace core{
namespace font{


class AbstractFontLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractFontLoader_obj OBJ_;
		AbstractFontLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractFontLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractFontLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractFontLoader"); }

		Dynamic fontData; /* REM */ 
		Dynamic _successCallbackArray; /* REM */ 
		Dynamic _errorCallbackArray; /* REM */ 
		virtual Void load( ::String url,::String name);
		Dynamic load_dyn();

		virtual Void addCallback( Dynamic successCallback,Dynamic errorCallback);
		Dynamic addCallback_dyn();

		virtual Void _successCallback( );
		Dynamic _successCallback_dyn();

		virtual Void _errorCallback( ::String errorStr);
		Dynamic _errorCallback_dyn();

		virtual Void cleanup( );
		Dynamic cleanup_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace font

#endif /* INCLUDED_cocktail_core_font_AbstractFontLoader */ 
