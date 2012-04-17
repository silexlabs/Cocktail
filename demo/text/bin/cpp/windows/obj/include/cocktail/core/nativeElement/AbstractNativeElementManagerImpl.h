#ifndef INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl
#define INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementTypeValue)
namespace cocktail{
namespace core{
namespace nativeElement{


class AbstractNativeElementManagerImpl_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractNativeElementManagerImpl_obj OBJ_;
		AbstractNativeElementManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractNativeElementManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractNativeElementManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractNativeElementManagerImpl"); }

		virtual Dynamic getRoot( );
		Dynamic getRoot_dyn();

		virtual Dynamic createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType);
		Dynamic createNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_cocktail_core_nativeElement_AbstractNativeElementManagerImpl */ 
