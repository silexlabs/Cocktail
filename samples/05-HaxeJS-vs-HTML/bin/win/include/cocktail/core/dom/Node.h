#ifndef INCLUDED_cocktail_core_dom_Node
#define INCLUDED_cocktail_core_dom_Node

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/event/EventCallback.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,NamedNodeMap)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
namespace cocktail{
namespace core{
namespace dom{


class Node_obj : public ::cocktail::core::event::EventCallback_obj{
	public:
		typedef ::cocktail::core::event::EventCallback_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Node"); }

		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

		virtual ::cocktail::core::dom::Document set_ownerDocument( ::cocktail::core::dom::Document value);
		Dynamic set_ownerDocument_dyn();

		virtual ::String set_nodeValue( ::String value);
		Dynamic set_nodeValue_dyn();

		virtual ::String get_nodeValue( );
		Dynamic get_nodeValue_dyn();

		virtual int get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual Dynamic get_previousSibling( );
		Dynamic get_previousSibling_dyn();

		virtual Dynamic get_nextSibling( );
		Dynamic get_nextSibling_dyn();

		virtual Dynamic get_lastChild( );
		Dynamic get_lastChild_dyn();

		virtual Dynamic get_firstChild( );
		Dynamic get_firstChild_dyn();

		virtual Void removeFromParentIfNecessary( Dynamic newChild);
		Dynamic removeFromParentIfNecessary_dyn();

		virtual Dynamic doCloneNode( );
		Dynamic doCloneNode_dyn();

		virtual Array< ::cocktail::core::event::EventTarget > getTargetAncestors( );

		virtual bool hasAttributes( );
		Dynamic hasAttributes_dyn();

		virtual Dynamic cloneNode( bool deep);
		Dynamic cloneNode_dyn();

		virtual bool hasChildNodes( );
		Dynamic hasChildNodes_dyn();

		virtual Dynamic replaceChild( Dynamic newChild,Dynamic oldChild);
		Dynamic replaceChild_dyn();

		virtual bool isSameNode( Dynamic other);
		Dynamic isSameNode_dyn();

		virtual Dynamic insertBefore( Dynamic newChild,Dynamic refChild);
		Dynamic insertBefore_dyn();

		virtual Dynamic appendChild( Dynamic newChild);
		Dynamic appendChild_dyn();

		virtual Dynamic removeChild( Dynamic oldChild);
		Dynamic removeChild_dyn();

		virtual Void initChildNodes( );
		Dynamic initChildNodes_dyn();

		::cocktail::core::dom::Document ownerDocument; /* REM */ 
		::cocktail::core::dom::NamedNodeMap attributes; /* REM */ 
		::String nodeName; /* REM */ 
		::String nodeValue; /* REM */ 
		int nodeType; /* REM */ 
		Dynamic previousSibling; /* REM */ 
		Dynamic nextSibling; /* REM */ 
		Dynamic lastChild; /* REM */ 
		Dynamic firstChild; /* REM */ 
		Dynamic childNodes; /* REM */ 
		Dynamic parentNode; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Node */ 
