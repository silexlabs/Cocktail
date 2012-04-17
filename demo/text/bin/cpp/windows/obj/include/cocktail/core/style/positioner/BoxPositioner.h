#ifndef INCLUDED_cocktail_core_style_positioner_BoxPositioner
#define INCLUDED_cocktail_core_style_positioner_BoxPositioner

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS4(cocktail,core,style,positioner,BoxPositioner)
namespace cocktail{
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

		virtual ::cocktail::core::renderer::ElementRenderer position( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic containingHTMLElementData,Dynamic staticPosition);
		Dynamic position_dyn();

		virtual int getLeftOffset( ::cocktail::core::html::HTMLElement htmlElement,int staticPosition);
		Dynamic getLeftOffset_dyn();

		virtual int getRightOffset( ::cocktail::core::html::HTMLElement htmlElement,int containingHTMLElementWidth,int staticPosition);
		Dynamic getRightOffset_dyn();

		virtual int getTopOffset( ::cocktail::core::html::HTMLElement htmlElement,int staticPosition);
		Dynamic getTopOffset_dyn();

		virtual int getBottomOffset( ::cocktail::core::html::HTMLElement htmlElement,int containingHTMLElementHeight,int staticPosition);
		Dynamic getBottomOffset_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace positioner

#endif /* INCLUDED_cocktail_core_style_positioner_BoxPositioner */ 
