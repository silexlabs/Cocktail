#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#define INCLUDED_cocktail_port_flash_player_CoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/AbstractCoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace port{
namespace flash_player{


class CoreStyle_obj : public ::cocktail::core::style::AbstractCoreStyle_obj{
	public:
		typedef ::cocktail::core::style::AbstractCoreStyle_obj super;
		typedef CoreStyle_obj OBJ_;
		CoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< CoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("CoreStyle"); }

		virtual Dynamic getFontMetricsData( );
		Dynamic getFontMetricsData_dyn();

		virtual ::String getNativeFontFamily( Array< ::String > value);
		Dynamic getNativeFontFamily_dyn();

		static ::String SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_FLASH_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_GENERIC_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_FLASH_FONT_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_CoreStyle */ 
