#ifndef INCLUDED_neash_text_FontStyle
#define INCLUDED_neash_text_FontStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,FontStyle)
namespace neash{
namespace text{


class FontStyle_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontStyle_obj OBJ_;

	public:
		FontStyle_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.text.FontStyle"); }
		::String __ToString() const { return HX_CSTRING("FontStyle.") + tag; }

		static ::neash::text::FontStyle BOLD;
		static inline ::neash::text::FontStyle BOLD_dyn() { return BOLD; }
		static ::neash::text::FontStyle BOLD_ITALIC;
		static inline ::neash::text::FontStyle BOLD_ITALIC_dyn() { return BOLD_ITALIC; }
		static ::neash::text::FontStyle ITALIC;
		static inline ::neash::text::FontStyle ITALIC_dyn() { return ITALIC; }
		static ::neash::text::FontStyle REGULAR;
		static inline ::neash::text::FontStyle REGULAR_dyn() { return REGULAR; }
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_FontStyle */ 
