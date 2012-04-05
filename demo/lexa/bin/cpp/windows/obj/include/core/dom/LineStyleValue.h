#ifndef INCLUDED_core_dom_LineStyleValue
#define INCLUDED_core_dom_LineStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,LineStyleValue)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS2(core,html,EmbeddedElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace dom{


class LineStyleValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineStyleValue_obj OBJ_;

	public:
		LineStyleValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.LineStyleValue"); }
		::String __ToString() const { return HX_CSTRING("LineStyleValue.") + tag; }

		static ::core::dom::LineStyleValue bitmap(::core::html::AbstractHTMLImageElement htmlImageElement,Dynamic lineStyle,bool repeat);
		static Dynamic bitmap_dyn();
		static ::core::dom::LineStyleValue gradient(Dynamic gradientStyle,Dynamic lineStyle);
		static Dynamic gradient_dyn();
		static ::core::dom::LineStyleValue monochrome(Dynamic color,Dynamic lineStyle);
		static Dynamic monochrome_dyn();
		static ::core::dom::LineStyleValue none;
		static inline ::core::dom::LineStyleValue none_dyn() { return none; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_LineStyleValue */ 
