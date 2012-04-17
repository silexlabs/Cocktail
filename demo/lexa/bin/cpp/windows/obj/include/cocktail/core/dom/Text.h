#ifndef INCLUDED_cocktail_core_dom_Text
#define INCLUDED_cocktail_core_dom_Text

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/CharacterData.h>
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,core,dom,TextTokenValue)
namespace cocktail{
namespace core{
namespace dom{


class Text_obj : public ::cocktail::core::dom::CharacterData_obj{
	public:
		typedef ::cocktail::core::dom::CharacterData_obj super;
		typedef Text_obj OBJ_;
		Text_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Text_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Text_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Text"); }

		Dynamic _nativeElement; /* REM */ 
		Dynamic nativeElement; /* REM */ 
		Dynamic _textFragments; /* REM */ 
		virtual Void reset( );
		Dynamic reset_dyn();

		virtual Dynamic getTextFragments( ::String text);
		Dynamic getTextFragments_dyn();

		virtual Dynamic get_nativeElement( );
		Dynamic get_nativeElement_dyn();

		virtual ::String get_nodeValue( );
		Dynamic get_nodeValue_dyn();

		virtual ::String set_nodeValue( ::String value);
		Dynamic set_nodeValue_dyn();

		static Dynamic doGetTextFragments( ::String text);
		static Dynamic doGetTextFragments_dyn();

		static Dynamic insertTextToken( ::cocktail::core::dom::TextTokenValue textToken);
		static Dynamic insertTextToken_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace dom

#endif /* INCLUDED_cocktail_core_dom_Text */ 
