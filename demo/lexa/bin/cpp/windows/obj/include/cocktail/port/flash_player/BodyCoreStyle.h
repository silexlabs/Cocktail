#ifndef INCLUDED_cocktail_port_flash_player_BodyCoreStyle
#define INCLUDED_cocktail_port_flash_player_BodyCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/AbstractBodyCoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractBodyCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,BodyCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,ContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace port{
namespace flash_player{


class BodyCoreStyle_obj : public ::cocktail::core::style::AbstractBodyCoreStyle_obj{
	public:
		typedef ::cocktail::core::style::AbstractBodyCoreStyle_obj super;
		typedef BodyCoreStyle_obj OBJ_;
		BodyCoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< BodyCoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BodyCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BodyCoreStyle"); }

		virtual Void attachNativeElement( Dynamic nativeElement);
		Dynamic attachNativeElement_dyn();

		virtual Void detachNativeElement( Dynamic nativeElement);
		Dynamic detachNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_BodyCoreStyle */ 
