#ifndef INCLUDED_cocktail_core_style_positioner_RelativePositioner
#define INCLUDED_cocktail_core_style_positioner_RelativePositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/positioner/BoxPositioner.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS4(cocktail,core,style,positioner,BoxPositioner)
HX_DECLARE_CLASS4(cocktail,core,style,positioner,RelativePositioner)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace style{
namespace positioner{


class RelativePositioner_obj : public ::cocktail::core::style::positioner::BoxPositioner_obj{
	public:
		typedef ::cocktail::core::style::positioner::BoxPositioner_obj super;
		typedef RelativePositioner_obj OBJ_;
		RelativePositioner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< RelativePositioner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RelativePositioner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("RelativePositioner"); }

		virtual int getLeftOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int staticPosition);
		Dynamic getLeftOffset_dyn();

		virtual int getRightOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int containingHTMLElementWidth,int staticPosition);
		Dynamic getRightOffset_dyn();

		virtual int getTopOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int staticPosition);
		Dynamic getTopOffset_dyn();

		virtual int getBottomOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int containingHTMLElementHeight,int staticPosition);
		Dynamic getBottomOffset_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_cocktail_core_style_positioner_RelativePositioner */ 
