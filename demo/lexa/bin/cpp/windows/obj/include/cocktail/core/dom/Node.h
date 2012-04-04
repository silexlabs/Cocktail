#ifndef INCLUDED_cocktail_core_dom_Node
#define INCLUDED_cocktail_core_dom_Node

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,NamedNodeMap)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
namespace cocktail{
namespace core{
namespace dom{


class Node_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Node_obj OBJ_;
		Node_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Node_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Node_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Node"); }

		int nodeType; /* REM */ 
		::String nodeValue; /* REM */ 
		::String nodeName; /* REM */ 
		::cocktail::core::dom::Node _parentNode; /* REM */ 
		::cocktail::core::dom::Node parentNode; /* REM */ 
		Array< ::cocktail::core::dom::Node > _childNodes; /* REM */ 
		Array< ::cocktail::core::dom::Node > childNodes; /* REM */ 
		::cocktail::core::dom::Node firstChild; /* REM */ 
		::cocktail::core::dom::Node lastChild; /* REM */ 
		::cocktail::core::dom::Node nextSibling; /* REM */ 
		::cocktail::core::dom::Node previousSibling; /* REM */ 
		::cocktail::core::dom::NamedNodeMap _attributes; /* REM */ 
		::cocktail::core::dom::NamedNodeMap attributes; /* REM */ 
		virtual ::cocktail::core::dom::Node removeChild( ::cocktail::core::dom::Node oldChild);
		Dynamic removeChild_dyn();

		virtual ::cocktail::core::dom::Node appendChild( ::cocktail::core::dom::Node newChild);
		Dynamic appendChild_dyn();

		virtual ::cocktail::core::dom::Node insertBefore( ::cocktail::core::dom::Node newChild,::cocktail::core::dom::Node refChild);
		Dynamic insertBefore_dyn();

		virtual ::cocktail::core::dom::Node replaceChild( ::cocktail::core::dom::Node newChild,::cocktail::core::dom::Node oldChild);
		Dynamic replaceChild_dyn();

		virtual bool isSameNode( ::cocktail::core::dom::Node other);
		Dynamic isSameNode_dyn();

		virtual bool hasChildNodes( );
		Dynamic hasChildNodes_dyn();

		virtual bool hasAttributes( );
		Dynamic hasAttributes_dyn();

		virtual Void removeFromParentIfNecessary( ::cocktail::core::dom::Node newChild);
		Dynamic removeFromParentIfNecessary_dyn();

		virtual ::cocktail::core::dom::Node get_firstChild( );
		Dynamic get_firstChild_dyn();

		virtual ::cocktail::core::dom::Node get_lastChild( );
		Dynamic get_lastChild_dyn();

		virtual ::cocktail::core::dom::Node get_nextSibling( );
		Dynamic get_nextSibling_dyn();

		virtual ::cocktail::core::dom::Node get_previousSibling( );
		Dynamic get_previousSibling_dyn();

		virtual int get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::cocktail::core::dom::Node get_parentNode( );
		Dynamic get_parentNode_dyn();

		virtual ::cocktail::core::dom::Node set_parentNode( ::cocktail::core::dom::Node value);
		Dynamic set_parentNode_dyn();

		virtual Array< ::cocktail::core::dom::Node > get_childNodes( );
		Dynamic get_childNodes_dyn();

		virtual ::String get_nodeValue( );
		Dynamic get_nodeValue_dyn();

		virtual ::String set_nodeValue( ::String value);
		Dynamic set_nodeValue_dyn();

		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

		virtual ::cocktail::core::dom::NamedNodeMap get_attributes( );
		Dynamic get_attributes_dyn();

		static int ELEMENT_NODE; /* REM */ 
		static int ATTRIBUTE_NODE; /* REM */ 
		static int TEXT_NODE; /* REM */ 
		static int CDATA_SECTION_NODE; /* REM */ 
		static int ENTITY_REFERENCE_NODE; /* REM */ 
		static int ENTITY_NODE; /* REM */ 
		static int PROCESSING_INSTRUCTION_NODE; /* REM */ 
		static int COMMENT_NODE; /* REM */ 
		static int DOCUMENT_NODE; /* REM */ 
		static int DOCUMENT_TYPE_NODE; /* REM */ 
		static int DOCUMENT_FRAGMENT_NODE; /* REM */ 
		static int NOTATION_NODE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Node */ 
