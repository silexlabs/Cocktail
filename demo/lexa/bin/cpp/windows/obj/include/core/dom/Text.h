#ifndef INCLUDED_core_dom_Text
#define INCLUDED_core_dom_Text

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/CharacterData.h>
HX_DECLARE_CLASS2(core,dom,CharacterData)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,Text)
HX_DECLARE_CLASS2(core,dom,TextTokenValue)
HX_DECLARE_CLASS2(core,style,TextTransform)
namespace core{
namespace dom{


class Text_obj : public ::core::dom::CharacterData_obj{
	public:
		typedef ::core::dom::CharacterData_obj super;
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

		static ::String applyTextTransform( ::String text,::core::style::TextTransform textTransform);
		static Dynamic applyTextTransform_dyn();

		static ::String capitalizeText( ::String text);
		static Dynamic capitalizeText_dyn();

		static Dynamic doGetTextFragments( ::String text);
		static Dynamic doGetTextFragments_dyn();

		static Dynamic insertTextToken( ::core::dom::TextTokenValue textToken);
		static Dynamic insertTextToken_dyn();

};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_Text */ 
