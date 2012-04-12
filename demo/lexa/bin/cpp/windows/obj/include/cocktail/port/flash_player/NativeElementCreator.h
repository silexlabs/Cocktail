#ifndef INCLUDED_cocktail_port_flash_player_NativeElementCreator
#define INCLUDED_cocktail_port_flash_player_NativeElementCreator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/nativeElement/AbstractNativeElementCreator.h>
HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementCreator)
HX_DECLARE_CLASS3(cocktail,core,nativeElement,NativeElementTypeValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,NativeElementCreator)
namespace cocktail{
namespace port{
namespace flash_player{


class NativeElementCreator_obj : public ::cocktail::core::nativeElement::AbstractNativeElementCreator_obj{
	public:
		typedef ::cocktail::core::nativeElement::AbstractNativeElementCreator_obj super;
		typedef NativeElementCreator_obj OBJ_;
		NativeElementCreator_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeElementCreator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeElementCreator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeElementCreator"); }

		virtual Dynamic createNativeElement( ::cocktail::core::nativeElement::NativeElementTypeValue nativeElementType);
		Dynamic createNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_NativeElementCreator */ 
