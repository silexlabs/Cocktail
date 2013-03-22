#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#define INCLUDED_cocktail_core_resource_ResourceManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Hash)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
HX_DECLARE_CLASS3(cocktail,core,resource,ResourceManager)
HX_DECLARE_CLASS3(cocktail,port,base,NativeHttpBase)
HX_DECLARE_CLASS4(cocktail,port,platform,nme,NativeHttp)
namespace cocktail{
namespace core{
namespace resource{


class ResourceManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ResourceManager_obj OBJ_;
		ResourceManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ResourceManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ResourceManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ResourceManager"); }

		static ::Hash _resources; /* REM */ 
		static ::Hash _binaryResources; /* REM */ 
		static ::cocktail::core::resource::AbstractResource getImageResource( ::String url);
		static Dynamic getImageResource_dyn();

		static Void removeImageResource( ::String url);
		static Dynamic removeImageResource_dyn();

		static ::cocktail::port::platform::nme::NativeHttp getBinaryResource( ::String url);
		static Dynamic getBinaryResource_dyn();

		static Void removeBinaryResource( ::String url);
		static Dynamic removeBinaryResource_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_ResourceManager */ 
