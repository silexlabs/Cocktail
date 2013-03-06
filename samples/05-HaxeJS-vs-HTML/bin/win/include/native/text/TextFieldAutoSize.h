#ifndef INCLUDED_native_text_TextFieldAutoSize
#define INCLUDED_native_text_TextFieldAutoSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,text,TextFieldAutoSize)
namespace native{
namespace text{


class TextFieldAutoSize_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextFieldAutoSize_obj OBJ_;

	public:
		TextFieldAutoSize_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("native.text.TextFieldAutoSize"); }
		::String __ToString() const { return HX_CSTRING("TextFieldAutoSize.") + tag; }

		static ::native::text::TextFieldAutoSize CENTER;
		static inline ::native::text::TextFieldAutoSize CENTER_dyn() { return CENTER; }
		static ::native::text::TextFieldAutoSize LEFT;
		static inline ::native::text::TextFieldAutoSize LEFT_dyn() { return LEFT; }
		static ::native::text::TextFieldAutoSize NONE;
		static inline ::native::text::TextFieldAutoSize NONE_dyn() { return NONE; }
		static ::native::text::TextFieldAutoSize RIGHT;
		static inline ::native::text::TextFieldAutoSize RIGHT_dyn() { return RIGHT; }
};

} // end namespace native
} // end namespace text

#endif /* INCLUDED_native_text_TextFieldAutoSize */ 
