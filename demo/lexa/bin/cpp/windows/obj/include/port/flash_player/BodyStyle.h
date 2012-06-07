#ifndef INCLUDED_port_flash_player_BodyStyle
#define INCLUDED_port_flash_player_BodyStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/AbstractBodyStyle.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,style,AbstractBodyStyle)
HX_DECLARE_CLASS2(core,style,AbstractContainerStyle)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,BodyStyle)
HX_DECLARE_CLASS2(port,flash_player,ContainerStyle)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace port{
namespace flash_player{


class BodyStyle_obj : public ::core::style::AbstractBodyStyle_obj{
	public:
		typedef ::core::style::AbstractBodyStyle_obj super;
		typedef BodyStyle_obj OBJ_;
		BodyStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< BodyStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BodyStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BodyStyle"); }

		virtual Void attachNativeElement( Dynamic nativeElement);
		Dynamic attachNativeElement_dyn();

		virtual Void detachNativeElement( Dynamic nativeElement);
		Dynamic detachNativeElement_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_BodyStyle */ 
