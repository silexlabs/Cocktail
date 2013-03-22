#ifndef INCLUDED_neash_text_FontType
#define INCLUDED_neash_text_FontType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,FontType)
namespace neash{
namespace text{


class FontType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FontType_obj OBJ_;

	public:
		FontType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("neash.text.FontType"); }
		::String __ToString() const { return HX_CSTRING("FontType.") + tag; }

		static ::neash::text::FontType DEVICE;
		static inline ::neash::text::FontType DEVICE_dyn() { return DEVICE; }
		static ::neash::text::FontType EMBEDDED;
		static inline ::neash::text::FontType EMBEDDED_dyn() { return EMBEDDED; }
		static ::neash::text::FontType EMBEDDED_CFF;
		static inline ::neash::text::FontType EMBEDDED_CFF_dyn() { return EMBEDDED_CFF; }
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_FontType */ 
