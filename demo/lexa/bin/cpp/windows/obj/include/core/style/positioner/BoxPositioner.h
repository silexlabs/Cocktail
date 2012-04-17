#ifndef INCLUDED_core_style_positioner_BoxPositioner
#define INCLUDED_core_style_positioner_BoxPositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(core,style,positioner,BoxPositioner)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace style{
namespace positioner{


class BoxPositioner_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BoxPositioner_obj OBJ_;
		BoxPositioner_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BoxPositioner_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoxPositioner_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoxPositioner"); }

		virtual ::core::renderer::ElementRenderer position( ::core::renderer::ElementRenderer elementRenderer,Dynamic containingHTMLElementData,Dynamic staticPosition);
		Dynamic position_dyn();

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

#endif /* INCLUDED_core_style_positioner_BoxPositioner */ 
