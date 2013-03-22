#ifndef INCLUDED_neash_text_TextFieldAutoSize
#define INCLUDED_neash_text_TextFieldAutoSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,TextFieldAutoSize)
namespace neash{
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
		::String GetEnumName( ) const { return HX_CSTRING("neash.text.TextFieldAutoSize"); }
		::String __ToString() const { return HX_CSTRING("TextFieldAutoSize.") + tag; }

		static ::neash::text::TextFieldAutoSize CENTER;
		static inline ::neash::text::TextFieldAutoSize CENTER_dyn() { return CENTER; }
		static ::neash::text::TextFieldAutoSize LEFT;
		static inline ::neash::text::TextFieldAutoSize LEFT_dyn() { return LEFT; }
		static ::neash::text::TextFieldAutoSize NONE;
		static inline ::neash::text::TextFieldAutoSize NONE_dyn() { return NONE; }
		static ::neash::text::TextFieldAutoSize RIGHT;
		static inline ::neash::text::TextFieldAutoSize RIGHT_dyn() { return RIGHT; }
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextFieldAutoSize */ 
