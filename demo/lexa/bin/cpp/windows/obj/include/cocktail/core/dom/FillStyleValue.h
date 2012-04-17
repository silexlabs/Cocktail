#ifndef INCLUDED_cocktail_core_dom_FillStyleValue
#define INCLUDED_cocktail_core_dom_FillStyleValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,FillStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
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
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.dom.FillStyleValue"); }
		::String __ToString() const { return HX_CSTRING("FillStyleValue.") + tag; }

		static ::cocktail::core::dom::FillStyleValue bitmap(::cocktail::core::html::AbstractHTMLImageElement htmlImageElement,bool repeat);
		static Dynamic bitmap_dyn();
		static ::cocktail::core::dom::FillStyleValue gradient(Dynamic gradientStyle);
		static Dynamic gradient_dyn();
		static ::cocktail::core::dom::FillStyleValue monochrome(Dynamic colorStop);
		static Dynamic monochrome_dyn();
		static ::cocktail::core::dom::FillStyleValue none;
		static inline ::cocktail::core::dom::FillStyleValue none_dyn() { return none; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_FillStyleValue */ 
