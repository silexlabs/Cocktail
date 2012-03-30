#ifndef INCLUDED_core_dom_Element
#define INCLUDED_core_dom_Element

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/Node.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,NodeType)
namespace core{
namespace dom{


class Element_obj : public ::core::dom::Node_obj{
	public:
		typedef ::core::dom::Node_obj super;
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
		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

		virtual ::core::dom::NodeType get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::String get_tagName( );
		Dynamic get_tagName_dyn();

};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_Element */ 
