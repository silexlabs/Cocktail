#ifndef INCLUDED_native_text_TextFieldType
#define INCLUDED_native_text_TextFieldType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,text,TextFieldType)
namespace native{
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
		::String GetEnumName( ) const { return HX_CSTRING("native.text.TextFieldType"); }
		::String __ToString() const { return HX_CSTRING("TextFieldType.") + tag; }

		static ::native::text::TextFieldType DYNAMIC;
		static inline ::native::text::TextFieldType DYNAMIC_dyn() { return DYNAMIC; }
		static ::native::text::TextFieldType INPUT;
		static inline ::native::text::TextFieldType INPUT_dyn() { return INPUT; }
};

} // end namespace native
} // end namespace text

#endif /* INCLUDED_native_text_TextFieldType */ 
