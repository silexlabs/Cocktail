#ifndef INCLUDED_cocktail_core_dom_Element
#define INCLUDED_cocktail_core_dom_Element

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,NamedNodeMap)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
namespace cocktail{
namespace core{
namespace dom{


class Element_obj : public ::cocktail::core::dom::Node_obj{
	public:
		typedef ::cocktail::core::dom::Node_obj super;
		typedef Element_obj OBJ_;
		Element_obj();
		Void __construct(::String tagName);

	public:
		static hx::ObjectPtr< Element_obj > __new(::String tagName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Element_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Element"); }

		::String _tagName; /* REM */ 
		::String tagName; /* REM */ 
		::cocktail::core::dom::Element firstElementChild; /* REM */ 
		::cocktail::core::dom::Element lastElementChild; /* REM */ 
		::cocktail::core::dom::Element previousElementSibling; /* REM */ 
		::cocktail::core::dom::Element nextElementSibling; /* REM */ 
		int childElementCount; /* REM */ 
		virtual ::String getAttribute( ::String name);
		Dynamic getAttribute_dyn();

		virtual Void setAttribute( ::String name,::String value);
		Dynamic setAttribute_dyn();

		virtual ::cocktail::core::dom::Attr getAttributeNode( ::String name);
		Dynamic getAttributeNode_dyn();

		virtual ::cocktail::core::dom::Attr setAttributeNode( ::cocktail::core::dom::Attr newAttr);
		Dynamic setAttributeNode_dyn();

		virtual Void removeAttribute( ::String name);
		Dynamic removeAttribute_dyn();

		virtual Void setIdAttribute( ::String name,bool isId);
		Dynamic setIdAttribute_dyn();

		virtual Void setIdAttributeNode( ::cocktail::core::dom::Attr idAttr,bool isId);
		Dynamic setIdAttributeNode_dyn();

		virtual bool hasAttribute( ::String name);
		Dynamic hasAttribute_dyn();

		virtual Array< ::cocktail::core::dom::Node > getElementsByTagName( ::String tagName);
		Dynamic getElementsByTagName_dyn();

		virtual Void doGetElementsByTagName( ::cocktail::core::dom::Node node,::String tagName,Array< ::cocktail::core::dom::Node > elements);
		Dynamic doGetElementsByTagName_dyn();

		virtual bool hasAttributes( );
		Dynamic hasAttributes_dyn();

		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

		virtual int get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::cocktail::core::dom::NamedNodeMap get_attributes( );
		Dynamic get_attributes_dyn();

		virtual ::cocktail::core::dom::Element get_firstElementChild( );
		Dynamic get_firstElementChild_dyn();

		virtual ::cocktail::core::dom::Element get_lastElementChild( );
		Dynamic get_lastElementChild_dyn();

		virtual ::cocktail::core::dom::Element get_nextElementSibling( );
		Dynamic get_nextElementSibling_dyn();

		virtual ::cocktail::core::dom::Element get_previousElementSibling( );
		Dynamic get_previousElementSibling_dyn();

		virtual int get_childElementCount( );
		Dynamic get_childElementCount_dyn();

		virtual ::String get_tagName( );
		Dynamic get_tagName_dyn();

		static ::String MATCH_ALL_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Element */ 
