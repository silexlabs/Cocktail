#ifndef INCLUDED_cocktail_port_flash_player_NativeElementPathManager
#define INCLUDED_cocktail_port_flash_player_NativeElementPathManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/nativeElement/AbstractNativeElementPathManager.h>
HX_DECLARE_CLASS3(cocktail,core,nativeElement,AbstractNativeElementPathManager)
HX_DECLARE_CLASS3(cocktail,port,flash_player,NativeElementPathManager)
namespace cocktail{
namespace port{
namespace flash_player{


class NativeElementPathManager_obj : public ::cocktail::core::nativeElement::AbstractNativeElementPathManager_obj{
	public:
		typedef ::cocktail::core::nativeElement::AbstractNativeElementPathManager_obj super;
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

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_NativeElementPathManager */ 
