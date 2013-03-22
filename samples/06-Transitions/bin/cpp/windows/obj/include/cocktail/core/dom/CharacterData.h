#ifndef INCLUDED_cocktail_core_dom_CharacterData
#define INCLUDED_cocktail_core_dom_CharacterData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,css,CascadeManager)
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace dom{


class CharacterData_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef CharacterData_obj OBJ_;
		CharacterData_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CharacterData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CharacterData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CharacterData"); }

		virtual ::String set_nodeValue( ::String value);

		virtual ::String get_nodeValue( );

		virtual Void endPendingAnimation( );

		virtual bool startPendingAnimation( );

		virtual Void init( );

		virtual Void getStyleDeclaration( );

		virtual bool hasAttributes( );

		virtual bool hasChildNodes( );

		virtual Void invalidateCascade( );

		virtual Void cascade( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange);

		virtual Void initAttributes( );

		virtual Void initChildNodes( );

		::String data; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_CharacterData */ 
