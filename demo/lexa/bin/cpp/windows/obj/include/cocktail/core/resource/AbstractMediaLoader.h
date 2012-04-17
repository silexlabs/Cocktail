#ifndef INCLUDED_cocktail_core_resource_AbstractMediaLoader
#define INCLUDED_cocktail_core_resource_AbstractMediaLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/resource/AbstractResourceLoader.h>
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
namespace cocktail{
namespace core{
namespace resource{


class AbstractMediaLoader_obj : public ::cocktail::core::resource::AbstractResourceLoader_obj{
	public:
		typedef ::cocktail::core::resource::AbstractResourceLoader_obj super;
		typedef AbstractMediaLoader_obj OBJ_;
		AbstractMediaLoader_obj();
		Void __construct(Dynamic nativeElement);

	public:
		static hx::ObjectPtr< AbstractMediaLoader_obj > __new(Dynamic nativeElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractMediaLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractMediaLoader"); }

		Dynamic _nativeElement; /* REM */ 
		Dynamic nativeElement; /* REM */ 
		int _intrinsicWidth; /* REM */ 
		int intrinsicWidth; /* REM */ 
		int _intrinsicHeight; /* REM */ 
		int intrinsicHeight; /* REM */ 
		double _intrinsicRatio; /* REM */ 
		double intrinsicRatio; /* REM */ 
		virtual Dynamic getNativeElement( );
		Dynamic getNativeElement_dyn();

		virtual int getIntrinsicWidth( );
		Dynamic getIntrinsicWidth_dyn();

		virtual int getIntrinsicHeight( );
		Dynamic getIntrinsicHeight_dyn();

		virtual double getIntrinsicRatio( );
		Dynamic getIntrinsicRatio_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace resource

#endif /* INCLUDED_cocktail_core_resource_AbstractMediaLoader */ 
