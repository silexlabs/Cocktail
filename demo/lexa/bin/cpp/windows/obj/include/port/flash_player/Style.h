#ifndef INCLUDED_port_flash_player_Style
#define INCLUDED_port_flash_player_Style

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/AbstractStyle.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,FontFamily)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace port{
namespace flash_player{


class Style_obj : public ::core::style::AbstractStyle_obj{
	public:
		typedef ::core::style::AbstractStyle_obj super;
		typedef Style_obj OBJ_;
		Style_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< Style_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Style_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Style"); }

		virtual Dynamic getFontMetricsData( );
		Dynamic getFontMetricsData_dyn();

		virtual ::String getNativeFontFamily( Array< ::core::style::FontFamily > value);
		Dynamic getNativeFontFamily_dyn();

		static ::String SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String SANS_SERIF_GENERIC_FONT_NAME; /* REM */ 
		static ::String MONOSPACE_GENERIC_FONT_NAME; /* REM */ 
};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_Style */ 
