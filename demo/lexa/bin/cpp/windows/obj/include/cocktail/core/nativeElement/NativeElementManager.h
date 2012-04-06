#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#define INCLUDED_cocktail_core_nativeElement_NativeElementManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementCreator)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementPathManager)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementManager)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementTypeValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,NativeElementCreator)
HX_DECLARE_CLASS3(cocktail,port,flash_player,NativeElementPathManager)
namespace cocktail{
namespace core{
namespace nativeElement{


class NativeElementManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NativeElementManager_obj OBJ_;
		NativeElementManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeElementManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeElementManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeElementManager"); }

		static ::cocktail::port::flash_player::NativeElementCreator _nativeElementCreator; /* REM */ 
		static ::cocktail::port::flash_player::NativeElementPathManager _nativeElementPathManager; /* REM */ 
		static Dynamic getRoot( );
		static Dynamic getRoot_dyn();

		static Dynamic createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType);
		static Dynamic createNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_cocktail_core_nativeElement_NativeElementManager */ 
