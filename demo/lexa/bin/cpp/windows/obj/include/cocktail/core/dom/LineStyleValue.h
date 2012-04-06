#ifndef INCLUDED_cocktail_core_dom_LineStyleValue
#define INCLUDED_cocktail_core_dom_LineStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,LineStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.dom.LineStyleValue"); }
		::String __ToString() const { return HX_CSTRING("LineStyleValue.") + tag; }

		static ::cocktail::core::dom::LineStyleValue bitmap(::cocktail::core::html::AbstractHTMLImageElement htmlImageElement,Dynamic lineStyle,bool repeat);
		static Dynamic bitmap_dyn();
		static ::cocktail::core::dom::LineStyleValue gradient(Dynamic gradientStyle,Dynamic lineStyle);
		static Dynamic gradient_dyn();
		static ::cocktail::core::dom::LineStyleValue monochrome(Dynamic color,Dynamic lineStyle);
		static Dynamic monochrome_dyn();
		static ::cocktail::core::dom::LineStyleValue none;
		static inline ::cocktail::core::dom::LineStyleValue none_dyn() { return none; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_LineStyleValue */ 
