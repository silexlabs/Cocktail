#ifndef INCLUDED_cocktail_core_dom_NamedNodeMap
#define INCLUDED_cocktail_core_dom_NamedNodeMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,NamedNodeMap)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
namespace cocktail{
namespace core{
namespace dom{


class NamedNodeMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef NamedNodeMap_obj OBJ_;
		NamedNodeMap_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< NamedNodeMap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~NamedNodeMap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("NamedNodeMap"); }

		Array< ::cocktail::core::dom::Node > _nodes; /* REM */ 
		int length; /* REM */ 
		virtual ::cocktail::core::dom::Node getNamedItem( ::String name);
		Dynamic getNamedItem_dyn();

		virtual ::cocktail::core::dom::Node setNamedItem( ::cocktail::core::dom::Node arg);
		Dynamic setNamedItem_dyn();

		virtual ::cocktail::core::dom::Node removeNamedItem( ::String name);
		Dynamic removeNamedItem_dyn();

		virtual ::cocktail::core::dom::Node item( int index);
		Dynamic item_dyn();

		virtual int get_length( );
		Dynamic get_length_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_NamedNodeMap */ 
