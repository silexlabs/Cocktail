#ifndef INCLUDED_cocktail_core_dom_Element
#define INCLUDED_cocktail_core_dom_Element

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Element"); }

		virtual int get_childElementCount( );
		Dynamic get_childElementCount_dyn();

		virtual Dynamic get_previousElementSibling( );
		Dynamic get_previousElementSibling_dyn();

		virtual Dynamic get_nextElementSibling( );
		Dynamic get_nextElementSibling_dyn();

		virtual Dynamic get_lastElementChild( );
		Dynamic get_lastElementChild_dyn();

		virtual Dynamic get_firstElementChild( );
		Dynamic get_firstElementChild_dyn();

		virtual int get_nodeType( );

		virtual ::String get_nodeName( );

		virtual bool hasAttributes( );

		virtual Void doGetElementsByClassName( ::cocktail::core::html::HTMLElement node,::String className,Array< ::cocktail::core::html::HTMLElement > elements);
		Dynamic doGetElementsByClassName_dyn();

		virtual Void doGetElementsByTagName( ::cocktail::core::html::HTMLElement node,::String tagName,Array< ::cocktail::core::html::HTMLElement > elements);
		Dynamic doGetElementsByTagName_dyn();

		virtual Dynamic doCloneNode( );

		virtual Array< ::cocktail::core::html::HTMLElement > getElementsByClassName( ::String className);
		Dynamic getElementsByClassName_dyn();

		virtual Array< ::cocktail::core::html::HTMLElement > getElementsByTagName( ::String tagName);
		Dynamic getElementsByTagName_dyn();

		virtual bool hasAttribute( ::String name);
		Dynamic hasAttribute_dyn();

		virtual Void setIdAttributeNode( ::cocktail::core::dom::Attr idAttr,bool isId);
		Dynamic setIdAttributeNode_dyn();

		virtual Void setIdAttribute( ::String name,bool isId);
		Dynamic setIdAttribute_dyn();

		virtual Void removeAttribute( ::String name);
		Dynamic removeAttribute_dyn();

		virtual ::cocktail::core::dom::Attr setAttributeNode( ::cocktail::core::dom::Attr newAttr);
		Dynamic setAttributeNode_dyn();

		virtual ::cocktail::core::dom::Attr getAttributeNode( ::String name);
		Dynamic getAttributeNode_dyn();

		virtual Void setAttribute( ::String name,::String value);
		Dynamic setAttribute_dyn();

		virtual ::String getAttribute( ::String name);
		Dynamic getAttribute_dyn();

		virtual Void initAttributes( );
		Dynamic initAttributes_dyn();

		int childElementCount; /* REM */ 
		Dynamic nextElementSibling; /* REM */ 
		Dynamic previousElementSibling; /* REM */ 
		Dynamic lastElementChild; /* REM */ 
		Dynamic firstElementChild; /* REM */ 
		::String tagName; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Element */ 
