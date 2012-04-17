#ifndef INCLUDED_core_dom_Node
#define INCLUDED_core_dom_Node

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,NodeType)
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

		::core::dom::NodeType nodeType; /* REM */ 
		::String nodeValue; /* REM */ 
		::String nodeName; /* REM */ 
		::core::dom::Node _parentNode; /* REM */ 
		::core::dom::Node parentNode; /* REM */ 
		Array< ::core::dom::Node > _childNodes; /* REM */ 
		Array< ::core::dom::Node > childNodes; /* REM */ 
		::core::dom::Node firstChild; /* REM */ 
		::core::dom::Node lastChild; /* REM */ 
		::core::dom::Node nextSibling; /* REM */ 
		::core::dom::Node previousSibling; /* REM */ 
		bool hasChildNodes; /* REM */ 
		virtual ::core::dom::Node removeChild( ::core::dom::Node oldChild);
		Dynamic removeChild_dyn();

		virtual ::core::dom::Node appendChild( ::core::dom::Node newChild);
		Dynamic appendChild_dyn();

		virtual ::core::dom::Node get_firstChild( );
		Dynamic get_firstChild_dyn();

		virtual ::core::dom::Node get_lastChild( );
		Dynamic get_lastChild_dyn();

		virtual ::core::dom::Node get_nextSibling( );
		Dynamic get_nextSibling_dyn();

		virtual ::core::dom::Node get_previousSibling( );
		Dynamic get_previousSibling_dyn();

		virtual bool get_hasChildNodes( );
		Dynamic get_hasChildNodes_dyn();

		virtual ::core::dom::NodeType get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::core::dom::Node get_parentNode( );
		Dynamic get_parentNode_dyn();

		virtual ::core::dom::Node set_parentNode( ::core::dom::Node value);
		Dynamic set_parentNode_dyn();

		virtual Array< ::core::dom::Node > get_childNodes( );
		Dynamic get_childNodes_dyn();

		virtual ::String get_nodeValue( );
		Dynamic get_nodeValue_dyn();

		virtual ::String set_nodeValue( ::String value);
		Dynamic set_nodeValue_dyn();

		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_Node */ 
