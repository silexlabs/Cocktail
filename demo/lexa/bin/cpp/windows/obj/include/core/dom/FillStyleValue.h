#ifndef INCLUDED_core_dom_FillStyleValue
#define INCLUDED_core_dom_FillStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,FillStyleValue)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS2(core,html,EmbeddedElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace dom{


class FillStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FillStyleValue_obj OBJ_;

	public:
		FillStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.FillStyleValue"); }
		::String __ToString() const { return HX_CSTRING("FillStyleValue.") + tag; }

		static ::core::dom::FillStyleValue bitmap(::core::html::AbstractHTMLImageElement htmlImageElement,bool repeat);
		static Dynamic bitmap_dyn();
		static ::core::dom::FillStyleValue gradient(Dynamic gradientStyle);
		static Dynamic gradient_dyn();
		static ::core::dom::FillStyleValue monochrome(Dynamic colorStop);
		static Dynamic monochrome_dyn();
		static ::core::dom::FillStyleValue none;
		static inline ::core::dom::FillStyleValue none_dyn() { return none; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_FillStyleValue */ 
