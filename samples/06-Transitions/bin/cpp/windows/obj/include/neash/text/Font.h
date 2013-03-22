#ifndef INCLUDED_neash_text_Font
#define INCLUDED_neash_text_Font

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,text,Font)
HX_DECLARE_CLASS2(neash,text,FontStyle)
HX_DECLARE_CLASS2(neash,text,FontType)
namespace neash{
namespace text{


class Font_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Font_obj OBJ_;
		Font_obj();
		Void __construct(::String inFilename);

	public:
		static hx::ObjectPtr< Font_obj > __new(::String inFilename);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Font_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Font"); }

		::neash::text::FontType fontType; /* REM */ 
		::neash::text::FontStyle fontStyle; /* REM */ 
		::String fontName; /* REM */ 
		static Dynamic load( ::String inFilename);
		static Dynamic load_dyn();

		static Dynamic freetype_import_font; /* REM */ 
		static Dynamic &freetype_import_font_dyn() { return freetype_import_font;}
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_Font */ 
