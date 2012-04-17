#ifndef INCLUDED_cocktail_core_dom_Attr
#define INCLUDED_cocktail_core_dom_Attr

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
namespace cocktail{
namespace core{
namespace dom{


class Attr_obj : public ::cocktail::core::dom::Node_obj{
	public:
		typedef ::cocktail::core::dom::Node_obj super;
		typedef Attr_obj OBJ_;
		Attr_obj();
		Void __construct(::String name);

	public:
		static hx::ObjectPtr< Attr_obj > __new(::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Attr_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Attr"); }

		::String _name; /* REM */ 
		::String name; /* REM */ 
		::String _value; /* REM */ 
		::String value; /* REM */ 
		bool _specified; /* REM */ 
		bool specified; /* REM */ 
		bool _isId; /* REM */ 
		bool isId; /* REM */ 
		::cocktail::core::dom::Element _ownerElement; /* REM */ 
		::cocktail::core::dom::Element ownerElement; /* REM */ 
		virtual ::String get_nodeName( );
		Dynamic get_nodeName_dyn();

		virtual int get_nodeType( );
		Dynamic get_nodeType_dyn();

		virtual ::String get_nodeValue( );
		Dynamic get_nodeValue_dyn();

		virtual ::String set_nodeValue( ::String value);
		Dynamic set_nodeValue_dyn();

		virtual ::cocktail::core::dom::Element get_ownerElement( );
		Dynamic get_ownerElement_dyn();

		virtual ::cocktail::core::dom::Element set_ownerElement( ::cocktail::core::dom::Element value);
		Dynamic set_ownerElement_dyn();

		virtual bool get_isId( );
		Dynamic get_isId_dyn();

		virtual bool set_isId( bool value);
		Dynamic set_isId_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual bool get_specified( );
		Dynamic get_specified_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Attr */ 
