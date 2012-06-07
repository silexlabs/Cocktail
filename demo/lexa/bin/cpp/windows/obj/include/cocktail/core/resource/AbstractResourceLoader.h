#ifndef INCLUDED_cocktail_core_resource_AbstractResourceLoader
#define INCLUDED_cocktail_core_resource_AbstractResourceLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
namespace cocktail{
namespace core{
namespace resource{


class AbstractResourceLoader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractResourceLoader_obj OBJ_;
		AbstractResourceLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractResourceLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractResourceLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractResourceLoader"); }

		Dynamic _onLoadCompleteCallback; /* REM */ 
	Dynamic &_onLoadCompleteCallback_dyn() { return _onLoadCompleteCallback;}
		Dynamic _onLoadErrorCallback; /* REM */ 
	Dynamic &_onLoadErrorCallback_dyn() { return _onLoadErrorCallback;}
		int _urlToLoadIdx; /* REM */ 
		Array< ::String > _urls; /* REM */ 
		virtual Void load( Array< ::String > urls,Dynamic onLoadComplete,Dynamic onLoadError);
		Dynamic load_dyn();

		virtual Void doLoad( ::String url);
		Dynamic doLoad_dyn();

		virtual Void onLoadComplete( Dynamic data);
		Dynamic onLoadComplete_dyn();

		virtual Void onLoadError( ::String msg);
		Dynamic onLoadError_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_AbstractResourceLoader */ 
