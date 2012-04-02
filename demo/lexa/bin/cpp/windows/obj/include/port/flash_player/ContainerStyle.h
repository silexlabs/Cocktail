#ifndef INCLUDED_port_flash_player_ContainerStyle
#define INCLUDED_port_flash_player_ContainerStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/AbstractContainerStyle.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,TextTokenValue)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,TextRenderer)
HX_DECLARE_CLASS2(core,style,AbstractContainerStyle)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(nme,text,TextFormat)
HX_DECLARE_CLASS2(port,flash_player,ContainerStyle)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace port{
namespace flash_player{


class ContainerStyle_obj : public ::core::style::AbstractContainerStyle_obj{
	public:
		typedef ::core::style::AbstractContainerStyle_obj super;
		typedef ContainerStyle_obj OBJ_;
		ContainerStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< ContainerStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ContainerStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ContainerStyle"); }

		virtual ::core::renderer::TextRenderer doCreateTextRenderer( ::String text,::core::dom::TextTokenValue textToken);
		Dynamic doCreateTextRenderer_dyn();

		virtual ::nme::text::TextFormat getTextFormat( );
		Dynamic getTextFormat_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_ContainerStyle */ 
