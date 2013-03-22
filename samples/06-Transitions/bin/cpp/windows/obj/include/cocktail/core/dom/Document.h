#ifndef INCLUDED_cocktail_core_dom_Document
#define INCLUDED_cocktail_core_dom_Document

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Comment)
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Document"); }

		virtual int get_nodeType( );

		virtual Array< ::cocktail::core::html::HTMLElement > getElementsByClassName( ::String className);
		Dynamic getElementsByClassName_dyn();

		virtual Array< ::cocktail::core::html::HTMLElement > getElementsByTagName( ::String tagName);
		Dynamic getElementsByTagName_dyn();

		virtual ::cocktail::core::html::HTMLElement doGetElementById( ::cocktail::core::html::HTMLElement node,::String elementId);
		Dynamic doGetElementById_dyn();

		virtual ::cocktail::core::html::HTMLElement getElementById( ::String elementId);
		Dynamic getElementById_dyn();

		virtual ::cocktail::core::event::Event createEvent( ::String eventInterface);
		Dynamic createEvent_dyn();

		virtual ::cocktail::core::dom::Attr createAttribute( ::String name);
		Dynamic createAttribute_dyn();

		virtual ::cocktail::core::dom::Comment createComment( ::String data);
		Dynamic createComment_dyn();

		virtual ::cocktail::core::dom::Text createTextNode( ::String data);
		Dynamic createTextNode_dyn();

		virtual ::cocktail::core::html::HTMLElement createElement( ::String tagName);
		Dynamic createElement_dyn();

		::cocktail::core::html::HTMLElement documentElement; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Document */ 
