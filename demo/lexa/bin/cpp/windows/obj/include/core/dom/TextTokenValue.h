#ifndef INCLUDED_core_dom_TextTokenValue
#define INCLUDED_core_dom_TextTokenValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,TextTokenValue)
namespace core{
namespace dom{


class TextTokenValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextTokenValue_obj OBJ_;

	public:
		TextTokenValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("core.dom.TextTokenValue"); }
		::String __ToString() const { return HX_CSTRING("TextTokenValue.") + tag; }

		static ::core::dom::TextTokenValue lineFeed;
		static inline ::core::dom::TextTokenValue lineFeed_dyn() { return lineFeed; }
		static ::core::dom::TextTokenValue space;
		static inline ::core::dom::TextTokenValue space_dyn() { return space; }
		static ::core::dom::TextTokenValue tab;
		static inline ::core::dom::TextTokenValue tab_dyn() { return tab; }
		static ::core::dom::TextTokenValue word(::String value);
		static Dynamic word_dyn();
};

} // end namespace core
} // end namespace dom

#endif /* INCLUDED_core_dom_TextTokenValue */ 
