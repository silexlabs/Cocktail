#ifndef INCLUDED_nme_text_TextFieldType
#define INCLUDED_nme_text_TextFieldType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,text,TextFieldType)
namespace nme{
namespace text{


class TextFieldType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextFieldType_obj OBJ_;

	public:
		TextFieldType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.text.TextFieldType"); }
		::String __ToString() const { return HX_CSTRING("TextFieldType.") + tag; }

		static ::nme::text::TextFieldType DYNAMIC;
		static inline ::nme::text::TextFieldType DYNAMIC_dyn() { return DYNAMIC; }
		static ::nme::text::TextFieldType INPUT;
		static inline ::nme::text::TextFieldType INPUT_dyn() { return INPUT; }
};

} // end namespace nme
} // end namespace text

#endif /* INCLUDED_nme_text_TextFieldType */ 
