#ifndef INCLUDED_core_resource_AbstractImageLoader
#define INCLUDED_core_resource_AbstractImageLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/MediaLoader.h>
HX_DECLARE_CLASS2(core,resource,AbstractImageLoader)
HX_DECLARE_CLASS2(core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS2(core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS2(port,flash_player,MediaLoader)
namespace core{
namespace resource{


class AbstractImageLoader_obj : public ::port::flash_player::MediaLoader_obj{
	public:
		typedef ::port::flash_player::MediaLoader_obj super;
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

} // end namespace core
} // end namespace resource

#endif /* INCLUDED_core_resource_AbstractImageLoader */ 
