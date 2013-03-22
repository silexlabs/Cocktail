#ifndef INCLUDED_cocktail_port_platform_flash_player_NativePasswordInput
#define INCLUDED_cocktail_port_platform_flash_player_NativePasswordInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/platform/flash_player/NativeTextInput.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,base,NativeInputBase)
HX_DECLARE_CLASS3(cocktail,port,base,NativeTextInputBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativePasswordInput)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,NativeTextInput)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class NativePasswordInput_obj : public ::cocktail::port::platform::flash_player::NativeTextInput_obj{
	public:
		typedef ::cocktail::port::platform::flash_player::NativeTextInput_obj super;
		typedef NativePasswordInput_obj OBJ_;
		NativePasswordInput_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< NativePasswordInput_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NativePasswordInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NativePasswordInput"); }

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_NativePasswordInput */ 
