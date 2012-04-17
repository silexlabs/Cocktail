#ifndef INCLUDED_cocktail_port_flash_player_ContainerCoreStyle
#define INCLUDED_cocktail_port_flash_player_ContainerCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/AbstractContainerCoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,TextTokenValue)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,ContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(nme,text,TextFormat)
namespace cocktail{
namespace port{
namespace flash_player{


class ContainerCoreStyle_obj : public ::cocktail::core::style::AbstractContainerCoreStyle_obj{
	public:
		typedef ::cocktail::core::style::AbstractContainerCoreStyle_obj super;
		typedef ContainerCoreStyle_obj OBJ_;
		ContainerCoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< ContainerCoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ContainerCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ContainerCoreStyle"); }

		virtual ::cocktail::core::renderer::TextRenderer doCreateTextRenderer( ::String text,::cocktail::core::dom::TextTokenValue textToken);
		Dynamic doCreateTextRenderer_dyn();

		virtual ::nme::text::TextFormat getTextFormat( );
		Dynamic getTextFormat_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_ContainerCoreStyle */ 
