#ifndef INCLUDED_neash_text_TextFieldType
#define INCLUDED_neash_text_TextFieldType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,TextFieldType)
namespace neash{
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
		::String GetEnumName( ) const { return HX_CSTRING("neash.text.TextFieldType"); }
		::String __ToString() const { return HX_CSTRING("TextFieldType.") + tag; }

		static ::neash::text::TextFieldType DYNAMIC;
		static inline ::neash::text::TextFieldType DYNAMIC_dyn() { return DYNAMIC; }
		static ::neash::text::TextFieldType INPUT;
		static inline ::neash::text::TextFieldType INPUT_dyn() { return INPUT; }
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFieldType */ 
