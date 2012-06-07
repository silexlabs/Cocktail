#ifndef INCLUDED_port_flash_player_NativeElementPathManager
#define INCLUDED_port_flash_player_NativeElementPathManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/nativeElement/AbstractNativeElementPathManager.h>
HX_DECLARE_CLASS2(core,nativeElement,AbstractNativeElementPathManager)
HX_DECLARE_CLASS2(port,flash_player,NativeElementPathManager)
namespace port{
namespace flash_player{


class NativeElementPathManager_obj : public ::core::nativeElement::AbstractNativeElementPathManager_obj{
	public:
		typedef ::core::nativeElement::AbstractNativeElementPathManager_obj super;
		typedef NativeElementPathManager_obj OBJ_;
		NativeElementPathManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NativeElementPathManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativeElementPathManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativeElementPathManager"); }

		virtual Dynamic getRoot( );
		Dynamic getRoot_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_NativeElementPathManager */ 
