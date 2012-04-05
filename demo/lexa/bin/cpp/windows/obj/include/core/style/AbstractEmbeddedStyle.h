#ifndef INCLUDED_core_style_AbstractEmbeddedStyle
#define INCLUDED_core_style_AbstractEmbeddedStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/Style.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,style,AbstractEmbeddedStyle)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace style{


class AbstractEmbeddedStyle_obj : public ::port::flash_player::Style_obj{
	public:
		typedef ::port::flash_player::Style_obj super;
		typedef AbstractEmbeddedStyle_obj OBJ_;
		AbstractEmbeddedStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractEmbeddedStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractEmbeddedStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractEmbeddedStyle"); }

};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_AbstractEmbeddedStyle */ 
