#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementPathManager
#define INCLUDED_cocktail_core_nativeElement_AbstractNativeElementPathManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementPathManager)
namespace cocktail{
namespace core{
namespace nativeElement{


class AbstractNativeElementPathManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractNativeElementPathManager_obj OBJ_;
		AbstractNativeElementPathManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractNativeElementPathManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractNativeElementPathManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractNativeElementPathManager"); }

		virtual Dynamic getRoot( );
		Dynamic getRoot_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_cocktail_core_nativeElement_AbstractNativeElementPathManager */ 
