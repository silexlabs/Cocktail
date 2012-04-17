#ifndef INCLUDED_cocktail_port_flash_player_NativeElementManagerImpl
#define INCLUDED_cocktail_port_flash_player_NativeElementManagerImpl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/nativeElement/AbstractNativeElementManagerImpl.h>
HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementManagerImpl)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementTypeValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,NativeElementManagerImpl)
namespace cocktail{
namespace port{
namespace flash_player{


class NativeElementManagerImpl_obj : public ::cocktail::core::nativeElement::AbstractNativeElementManagerImpl_obj{
	public:
		typedef ::cocktail::core::nativeElement::AbstractNativeElementManagerImpl_obj super;
		typedef NativeElementManagerImpl_obj OBJ_;
		NativeElementManagerImpl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeElementManagerImpl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeElementManagerImpl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeElementManagerImpl"); }

		virtual Dynamic getRoot( );
		Dynamic getRoot_dyn();

		virtual Dynamic createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType);
		Dynamic createNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_NativeElementManagerImpl */ 
