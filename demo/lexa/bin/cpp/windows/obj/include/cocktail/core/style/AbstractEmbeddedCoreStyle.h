#ifndef INCLUDED_cocktail_core_style_AbstractEmbeddedCoreStyle
#define INCLUDED_cocktail_core_style_AbstractEmbeddedCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/CoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractEmbeddedCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace style{


class AbstractEmbeddedCoreStyle_obj : public ::cocktail::port::flash_player::CoreStyle_obj{
	public:
		typedef ::cocktail::port::flash_player::CoreStyle_obj super;
		typedef AbstractEmbeddedCoreStyle_obj OBJ_;
		AbstractEmbeddedCoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractEmbeddedCoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractEmbeddedCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractEmbeddedCoreStyle"); }

};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_AbstractEmbeddedCoreStyle */ 
