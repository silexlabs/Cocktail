#ifndef INCLUDED_core_nativeElement_NativeElementManager
#define INCLUDED_core_nativeElement_NativeElementManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,nativeElement,AbstractNativeElementCreator)
HX_DECLARE_CLASS2(core,nativeElement,AbstractNativeElementPathManager)
HX_DECLARE_CLASS2(core,nativeElement,NativeElementManager)
HX_DECLARE_CLASS2(core,nativeElement,NativeElementTypeValue)
HX_DECLARE_CLASS2(port,flash_player,NativeElementCreator)
HX_DECLARE_CLASS2(port,flash_player,NativeElementPathManager)
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

		static ::port::flash_player::NativeElementCreator _nativeElementCreator; /* REM */ 
		static ::port::flash_player::NativeElementPathManager _nativeElementPathManager; /* REM */ 
		static Dynamic getRoot( );
		static Dynamic getRoot_dyn();

		static Dynamic createNativeElement( ::core::nativeElement::NativeElementTypeValue nativeElementType);
		static Dynamic createNativeElement_dyn();

};

} // end namespace core
} // end namespace nativeElement

#endif /* INCLUDED_core_nativeElement_NativeElementManager */ 
