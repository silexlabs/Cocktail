#ifndef INCLUDED_cocktail_core_parser_DOMParser
#define INCLUDED_cocktail_core_parser_DOMParser

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,parser,DOMParser)
namespace cocktail{
namespace core{
namespace parser{


class DOMParser_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DOMParser_obj OBJ_;
		DOMParser_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< DOMParser_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DOMParser_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DOMParser"); }

		static ::cocktail::core::html::HTMLElement parse( ::String html,::cocktail::core::dom::Document ownerDocument);
		static Dynamic parse_dyn();

		static ::String serialize( ::cocktail::core::html::HTMLElement node);
		static Dynamic serialize_dyn();

		static ::cocktail::core::html::HTMLElement doSetInnerHTML( ::Xml xml,::cocktail::core::dom::Document ownerDocument);
		static Dynamic doSetInnerHTML_dyn();

		static ::Xml doGetInnerHTML( ::cocktail::core::html::HTMLElement node,::Xml xml);
		static Dynamic doGetInnerHTML_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace parser

#endif /* INCLUDED_cocktail_core_parser_DOMParser */ 
