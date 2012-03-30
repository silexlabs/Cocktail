#ifndef INCLUDED_port_flash_player_NativeElementCreator
#define INCLUDED_port_flash_player_NativeElementCreator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/nativeElement/AbstractNativeElementCreator.h>
HX_DECLARE_CLASS2(core,nativeElement,AbstractNativeElementCreator)
HX_DECLARE_CLASS2(core,nativeElement,NativeElementTypeValue)
HX_DECLARE_CLASS2(port,flash_player,NativeElementCreator)
namespace port{
namespace flash_player{


class NativeElementCreator_obj : public ::core::nativeElement::AbstractNativeElementCreator_obj{
	public:
		typedef ::core::nativeElement::AbstractNativeElementCreator_obj super;
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

		virtual Dynamic createNativeElement( ::core::nativeElement::NativeElementTypeValue nativeElementType);
		Dynamic createNativeElement_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_NativeElementCreator */ 
