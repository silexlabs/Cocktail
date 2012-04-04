#ifndef INCLUDED_cocktail_core_dom_Document
#define INCLUDED_cocktail_core_dom_Document

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Text)
namespace cocktail{
namespace core{
namespace dom{


class Document_obj : public ::cocktail::core::dom::Node_obj{
	public:
		typedef ::cocktail::core::dom::Node_obj super;
		typedef Document_obj OBJ_;
		Document_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Document_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Document_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Document"); }

		::cocktail::core::dom::Element _documentElement; /* REM */ 
		::cocktail::core::dom::Element documentElement; /* REM */ 
		virtual ::cocktail::port::flash_player::HTMLElement createElement( ::String tagName);
		Dynamic createElement_dyn();

		virtual ::cocktail::port::flash_player::Text createTextNode( ::String data);
		Dynamic createTextNode_dyn();

		virtual ::cocktail::core::dom::Attr createAttribute( ::String name);
		Dynamic createAttribute_dyn();

		virtual ::cocktail::core::dom::Element getElementById( ::String elementId);
		Dynamic getElementById_dyn();

		virtual ::cocktail::core::dom::Element doGetElementById( ::cocktail::core::dom::Node node,::String elementId);
		Dynamic doGetElementById_dyn();

		virtual Array< ::cocktail::core::dom::Node > getElementsByTagName( ::String tagName);
		Dynamic getElementsByTagName_dyn();

		virtual int get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::cocktail::core::dom::Element get_documentElement( );
		Dynamic get_documentElement_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Document */ 
