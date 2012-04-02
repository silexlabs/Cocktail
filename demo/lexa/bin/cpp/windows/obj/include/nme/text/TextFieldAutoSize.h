#ifndef INCLUDED_nme_text_TextFieldAutoSize
#define INCLUDED_nme_text_TextFieldAutoSize

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,text,TextFieldAutoSize)
namespace nme{
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
		::String GetEnumName( ) const { return HX_CSTRING("nme.text.TextFieldAutoSize"); }
		::String __ToString() const { return HX_CSTRING("TextFieldAutoSize.") + tag; }

		static ::nme::text::TextFieldAutoSize CENTER;
		static inline ::nme::text::TextFieldAutoSize CENTER_dyn() { return CENTER; }
		static ::nme::text::TextFieldAutoSize LEFT;
		static inline ::nme::text::TextFieldAutoSize LEFT_dyn() { return LEFT; }
		static ::nme::text::TextFieldAutoSize NONE;
		static inline ::nme::text::TextFieldAutoSize NONE_dyn() { return NONE; }
		static ::nme::text::TextFieldAutoSize RIGHT;
		static inline ::nme::text::TextFieldAutoSize RIGHT_dyn() { return RIGHT; }
};

} // end namespace nme
} // end namespace text

#endif /* INCLUDED_nme_text_TextFieldAutoSize */ 
