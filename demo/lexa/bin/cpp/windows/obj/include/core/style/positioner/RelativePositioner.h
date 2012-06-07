#ifndef INCLUDED_core_style_positioner_RelativePositioner
#define INCLUDED_core_style_positioner_RelativePositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/style/positioner/BoxPositioner.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(core,style,positioner,BoxPositioner)
HX_DECLARE_CLASS3(core,style,positioner,RelativePositioner)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace style{
namespace positioner{


class RelativePositioner_obj : public ::core::style::positioner::BoxPositioner_obj{
	public:
		typedef ::core::style::positioner::BoxPositioner_obj super;
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

		virtual int getLeftOffset( ::port::flash_player::HTMLElement htmlElement,int staticPosition);
		Dynamic getLeftOffset_dyn();

		virtual int getRightOffset( ::port::flash_player::HTMLElement htmlElement,int containingHTMLElementWidth,int staticPosition);
		Dynamic getRightOffset_dyn();

		virtual int getTopOffset( ::port::flash_player::HTMLElement htmlElement,int staticPosition);
		Dynamic getTopOffset_dyn();

		virtual int getBottomOffset( ::port::flash_player::HTMLElement htmlElement,int containingHTMLElementHeight,int staticPosition);
		Dynamic getBottomOffset_dyn();

};

} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_core_style_positioner_RelativePositioner */ 
