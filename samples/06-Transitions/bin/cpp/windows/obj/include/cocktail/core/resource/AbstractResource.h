#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#define INCLUDED_cocktail_core_resource_AbstractResource

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventTarget.h>
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
namespace cocktail{
namespace core{
namespace resource{


class AbstractResource_obj : public ::cocktail::core::event::EventTarget_obj{
	public:
		typedef ::cocktail::core::event::EventTarget_obj super;
		typedef AbstractResource_obj OBJ_;
		AbstractResource_obj();
		Void __construct(::String url);

	public:
		static hx::ObjectPtr< AbstractResource_obj > __new(::String url);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractResource_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractResource"); }

		virtual Void onLoadError( );
		Dynamic onLoadError_dyn();

		virtual Void onLoadComplete( );
		Dynamic onLoadComplete_dyn();

		virtual Void load( ::String url);
		Dynamic load_dyn();

		Float intrinsicRatio; /* REM */ 
		Float intrinsicHeight; /* REM */ 
		Float intrinsicWidth; /* REM */ 
		Dynamic nativeResource; /* REM */ 
		bool loadedWithError; /* REM */ 
		bool loaded; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_AbstractResource */ 
