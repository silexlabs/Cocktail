#ifndef INCLUDED_core_dom_NodeType
#define INCLUDED_core_dom_NodeType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,NodeType)
namespace core{
namespace dom{


class NodeType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef NodeType_obj OBJ_;

	public:
		NodeType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.NodeType"); }
		::String __ToString() const { return HX_CSTRING("NodeType.") + tag; }

		static ::core::dom::NodeType DOCUMENT_NODE;
		static inline ::core::dom::NodeType DOCUMENT_NODE_dyn() { return DOCUMENT_NODE; }
		static ::core::dom::NodeType ELEMENT_NODE;
		static inline ::core::dom::NodeType ELEMENT_NODE_dyn() { return ELEMENT_NODE; }
		static ::core::dom::NodeType TEXT_NODE;
		static inline ::core::dom::NodeType TEXT_NODE_dyn() { return TEXT_NODE; }
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_NodeType */ 
