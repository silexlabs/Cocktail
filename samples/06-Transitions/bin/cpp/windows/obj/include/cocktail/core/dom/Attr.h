#ifndef INCLUDED_cocktail_core_dom_Attr
#define INCLUDED_cocktail_core_dom_Attr

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Attr)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Attr"); }

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::String set_nodeValue( ::String value);

		virtual ::String get_nodeValue( );

		virtual int get_nodeType( );

		virtual ::String get_nodeName( );

		virtual Dynamic doCloneNode( );

		virtual Void initChildNodes( );

		Dynamic ownerElement; /* REM */ 
		bool isId; /* REM */ 
		bool specified; /* REM */ 
		::String value; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Attr */ 
