#ifndef INCLUDED_cocktail_core_resource_AbstractImageLoader
#define INCLUDED_cocktail_core_resource_AbstractImageLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/MediaLoader.h>
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractImageLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MediaLoader)
namespace cocktail{
namespace core{
namespace resource{


class AbstractImageLoader_obj : public ::cocktail::port::flash_player::MediaLoader_obj{
	public:
		typedef ::cocktail::port::flash_player::MediaLoader_obj super;
		typedef AbstractImageLoader_obj OBJ_;
		AbstractImageLoader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractImageLoader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractImageLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractImageLoader"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_AbstractImageLoader */ 
