#ifndef INCLUDED_core_dom_Document
#define INCLUDED_core_dom_Document

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/Node.h>
HX_DECLARE_CLASS2(core,dom,CharacterData)
HX_DECLARE_CLASS2(core,dom,Document)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,Text)
HX_DECLARE_CLASS2(port,flash_player,Text)
namespace core{
namespace dom{


class Document_obj : public ::core::dom::Node_obj{
	public:
		typedef ::core::dom::Node_obj super;
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

		virtual ::core::dom::Element createElement( ::String tagName);
		Dynamic createElement_dyn();

		virtual ::port::flash_player::Text createTextNode( ::String data);
		Dynamic createTextNode_dyn();

};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_Document */ 
