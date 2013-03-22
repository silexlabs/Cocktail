#ifndef INCLUDED_neash_text_TextField
#define INCLUDED_neash_text_TextField

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/InteractiveObject.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,text,AntiAliasType)
HX_DECLARE_CLASS2(neash,text,TextField)
HX_DECLARE_CLASS2(neash,text,TextFieldAutoSize)
HX_DECLARE_CLASS2(neash,text,TextFieldType)
HX_DECLARE_CLASS2(neash,text,TextFormat)
namespace neash{
namespace text{


class TextField_obj : public ::neash::display::InteractiveObject_obj{
	public:
		typedef ::neash::display::InteractiveObject_obj super;
		typedef TextField_obj OBJ_;
		TextField_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextField_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextField_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextField"); }

		virtual bool nmeSetWordWrap( bool inVal);
		Dynamic nmeSetWordWrap_dyn();

		virtual bool nmeGetWordWrap( );
		Dynamic nmeGetWordWrap_dyn();

		virtual ::neash::text::TextFieldType nmeSetType( ::neash::text::TextFieldType inType);
		Dynamic nmeSetType_dyn();

		virtual ::neash::text::TextFieldType nmeGetType( );
		Dynamic nmeGetType_dyn();

		virtual Float nmeGetTextHeight( );
		Dynamic nmeGetTextHeight_dyn();

		virtual Float nmeGetTextWidth( );
		Dynamic nmeGetTextWidth_dyn();

		virtual int nmeSetTextColor( int inCol);
		Dynamic nmeSetTextColor_dyn();

		virtual int nmeGetTextColor( );
		Dynamic nmeGetTextColor_dyn();

		virtual ::String nmeSetText( ::String inText);
		Dynamic nmeSetText_dyn();

		virtual ::String nmeGetText( );
		Dynamic nmeGetText_dyn();

		virtual bool nmeSetSelectable( bool inSel);
		Dynamic nmeSetSelectable_dyn();

		virtual bool nmeGetSelectable( );
		Dynamic nmeGetSelectable_dyn();

		virtual int nmeSetScrollV( int inVal);
		Dynamic nmeSetScrollV_dyn();

		virtual int nmeGetScrollV( );
		Dynamic nmeGetScrollV_dyn();

		virtual int nmeSetScrollH( int inVal);
		Dynamic nmeSetScrollH_dyn();

		virtual int nmeGetScrollH( );
		Dynamic nmeGetScrollH_dyn();

		virtual int nmeGetNumLines( );
		Dynamic nmeGetNumLines_dyn();

		virtual bool nmeSetMultiline( bool inVal);
		Dynamic nmeSetMultiline_dyn();

		virtual bool nmeGetMultiline( );
		Dynamic nmeGetMultiline_dyn();

		virtual int nmeGetMaxScrollV( );
		Dynamic nmeGetMaxScrollV_dyn();

		virtual int nmeGetMaxScrollH( );
		Dynamic nmeGetMaxScrollH_dyn();

		virtual int nmeSetMaxChars( int inVal);
		Dynamic nmeSetMaxChars_dyn();

		virtual int nmeGetMaxChars( );
		Dynamic nmeGetMaxChars_dyn();

		virtual ::String nmeSetHTMLText( ::String inText);
		Dynamic nmeSetHTMLText_dyn();

		virtual ::String nmeGetHTMLText( );
		Dynamic nmeGetHTMLText_dyn();

		virtual bool nmeSetEmbedFonts( bool value);
		Dynamic nmeSetEmbedFonts_dyn();

		virtual bool nmeGetEmbedFonts( );
		Dynamic nmeGetEmbedFonts_dyn();

		virtual bool nmeSetDisplayAsPassword( bool inVal);
		Dynamic nmeSetDisplayAsPassword_dyn();

		virtual bool nmeGetDisplayAsPassword( );
		Dynamic nmeGetDisplayAsPassword_dyn();

		virtual ::neash::text::TextFormat nmeSetDefaultTextFormat( ::neash::text::TextFormat inFormat);
		Dynamic nmeSetDefaultTextFormat_dyn();

		virtual ::neash::text::TextFormat nmeGetDefaultTextFormat( );
		Dynamic nmeGetDefaultTextFormat_dyn();

		virtual int nmeGetBottomScrollV( );
		Dynamic nmeGetBottomScrollV_dyn();

		virtual int nmeSetBorderColor( int inVal);
		Dynamic nmeSetBorderColor_dyn();

		virtual int nmeGetBorderColor( );
		Dynamic nmeGetBorderColor_dyn();

		virtual bool nmeSetBorder( bool inVal);
		Dynamic nmeSetBorder_dyn();

		virtual bool nmeGetBorder( );
		Dynamic nmeGetBorder_dyn();

		virtual int nmeSetBackgroundColor( int inVal);
		Dynamic nmeSetBackgroundColor_dyn();

		virtual int nmeGetBackgroundColor( );
		Dynamic nmeGetBackgroundColor_dyn();

		virtual bool nmeSetBackground( bool inVal);
		Dynamic nmeSetBackground_dyn();

		virtual bool nmeGetBackground( );
		Dynamic nmeGetBackground_dyn();

		virtual ::neash::text::TextFieldAutoSize nmeSetAutoSize( ::neash::text::TextFieldAutoSize inVal);
		Dynamic nmeSetAutoSize_dyn();

		virtual ::neash::text::TextFieldAutoSize nmeGetAutoSize( );
		Dynamic nmeGetAutoSize_dyn();

		virtual ::String getLineText( int lineIndex);
		Dynamic getLineText_dyn();

		virtual int getLineOffset( int lineIndex);
		Dynamic getLineOffset_dyn();

		virtual Void setTextFormat( ::neash::text::TextFormat format,hx::Null< int >  beginIndex,hx::Null< int >  endIndex);
		Dynamic setTextFormat_dyn();

		virtual Void setSelection( int beginIndex,int endIndex);
		Dynamic setSelection_dyn();

		virtual Void appendText( ::String newText);
		Dynamic appendText_dyn();

		bool wordWrap; /* REM */ 
		::neash::text::TextFieldType type; /* REM */ 
		Float textWidth; /* REM */ 
		Float textHeight; /* REM */ 
		int textColor; /* REM */ 
		::String text; /* REM */ 
		bool selectable; /* REM */ 
		int scrollV; /* REM */ 
		int scrollH; /* REM */ 
		int numLines; /* REM */ 
		bool multiline; /* REM */ 
		int maxScrollV; /* REM */ 
		int maxScrollH; /* REM */ 
		int maxChars; /* REM */ 
		::String htmlText; /* REM */ 
		bool embedFonts; /* REM */ 
		bool displayAsPassword; /* REM */ 
		::neash::text::TextFormat defaultTextFormat; /* REM */ 
		int bottomScrollV; /* REM */ 
		int borderColor; /* REM */ 
		bool border; /* REM */ 
		int backgroundColor; /* REM */ 
		bool background; /* REM */ 
		::neash::text::TextFieldAutoSize autoSize; /* REM */ 
		::neash::text::AntiAliasType antiAliasType; /* REM */ 
		static Dynamic nme_text_field_create; /* REM */ 
		static Dynamic &nme_text_field_create_dyn() { return nme_text_field_create;}
		static Dynamic nme_text_field_get_text; /* REM */ 
		static Dynamic &nme_text_field_get_text_dyn() { return nme_text_field_get_text;}
		static Dynamic nme_text_field_set_text; /* REM */ 
		static Dynamic &nme_text_field_set_text_dyn() { return nme_text_field_set_text;}
		static Dynamic nme_text_field_get_html_text; /* REM */ 
		static Dynamic &nme_text_field_get_html_text_dyn() { return nme_text_field_get_html_text;}
		static Dynamic nme_text_field_set_html_text; /* REM */ 
		static Dynamic &nme_text_field_set_html_text_dyn() { return nme_text_field_set_html_text;}
		static Dynamic nme_text_field_get_text_color; /* REM */ 
		static Dynamic &nme_text_field_get_text_color_dyn() { return nme_text_field_get_text_color;}
		static Dynamic nme_text_field_set_text_color; /* REM */ 
		static Dynamic &nme_text_field_set_text_color_dyn() { return nme_text_field_set_text_color;}
		static Dynamic nme_text_field_get_selectable; /* REM */ 
		static Dynamic &nme_text_field_get_selectable_dyn() { return nme_text_field_get_selectable;}
		static Dynamic nme_text_field_set_selectable; /* REM */ 
		static Dynamic &nme_text_field_set_selectable_dyn() { return nme_text_field_set_selectable;}
		static Dynamic nme_text_field_get_display_as_password; /* REM */ 
		static Dynamic &nme_text_field_get_display_as_password_dyn() { return nme_text_field_get_display_as_password;}
		static Dynamic nme_text_field_set_display_as_password; /* REM */ 
		static Dynamic &nme_text_field_set_display_as_password_dyn() { return nme_text_field_set_display_as_password;}
		static Dynamic nme_text_field_get_def_text_format; /* REM */ 
		static Dynamic &nme_text_field_get_def_text_format_dyn() { return nme_text_field_get_def_text_format;}
		static Dynamic nme_text_field_set_def_text_format; /* REM */ 
		static Dynamic &nme_text_field_set_def_text_format_dyn() { return nme_text_field_set_def_text_format;}
		static Dynamic nme_text_field_get_auto_size; /* REM */ 
		static Dynamic &nme_text_field_get_auto_size_dyn() { return nme_text_field_get_auto_size;}
		static Dynamic nme_text_field_set_auto_size; /* REM */ 
		static Dynamic &nme_text_field_set_auto_size_dyn() { return nme_text_field_set_auto_size;}
		static Dynamic nme_text_field_get_type; /* REM */ 
		static Dynamic &nme_text_field_get_type_dyn() { return nme_text_field_get_type;}
		static Dynamic nme_text_field_set_type; /* REM */ 
		static Dynamic &nme_text_field_set_type_dyn() { return nme_text_field_set_type;}
		static Dynamic nme_text_field_get_multiline; /* REM */ 
		static Dynamic &nme_text_field_get_multiline_dyn() { return nme_text_field_get_multiline;}
		static Dynamic nme_text_field_set_multiline; /* REM */ 
		static Dynamic &nme_text_field_set_multiline_dyn() { return nme_text_field_set_multiline;}
		static Dynamic nme_text_field_get_word_wrap; /* REM */ 
		static Dynamic &nme_text_field_get_word_wrap_dyn() { return nme_text_field_get_word_wrap;}
		static Dynamic nme_text_field_set_word_wrap; /* REM */ 
		static Dynamic &nme_text_field_set_word_wrap_dyn() { return nme_text_field_set_word_wrap;}
		static Dynamic nme_text_field_get_border; /* REM */ 
		static Dynamic &nme_text_field_get_border_dyn() { return nme_text_field_get_border;}
		static Dynamic nme_text_field_set_border; /* REM */ 
		static Dynamic &nme_text_field_set_border_dyn() { return nme_text_field_set_border;}
		static Dynamic nme_text_field_get_border_color; /* REM */ 
		static Dynamic &nme_text_field_get_border_color_dyn() { return nme_text_field_get_border_color;}
		static Dynamic nme_text_field_set_border_color; /* REM */ 
		static Dynamic &nme_text_field_set_border_color_dyn() { return nme_text_field_set_border_color;}
		static Dynamic nme_text_field_get_background; /* REM */ 
		static Dynamic &nme_text_field_get_background_dyn() { return nme_text_field_get_background;}
		static Dynamic nme_text_field_set_background; /* REM */ 
		static Dynamic &nme_text_field_set_background_dyn() { return nme_text_field_set_background;}
		static Dynamic nme_text_field_get_background_color; /* REM */ 
		static Dynamic &nme_text_field_get_background_color_dyn() { return nme_text_field_get_background_color;}
		static Dynamic nme_text_field_set_background_color; /* REM */ 
		static Dynamic &nme_text_field_set_background_color_dyn() { return nme_text_field_set_background_color;}
		static Dynamic nme_text_field_get_text_width; /* REM */ 
		static Dynamic &nme_text_field_get_text_width_dyn() { return nme_text_field_get_text_width;}
		static Dynamic nme_text_field_get_text_height; /* REM */ 
		static Dynamic &nme_text_field_get_text_height_dyn() { return nme_text_field_get_text_height;}
		static Dynamic nme_text_field_set_text_format; /* REM */ 
		static Dynamic &nme_text_field_set_text_format_dyn() { return nme_text_field_set_text_format;}
		static Dynamic nme_text_field_get_max_scroll_v; /* REM */ 
		static Dynamic &nme_text_field_get_max_scroll_v_dyn() { return nme_text_field_get_max_scroll_v;}
		static Dynamic nme_text_field_get_max_scroll_h; /* REM */ 
		static Dynamic &nme_text_field_get_max_scroll_h_dyn() { return nme_text_field_get_max_scroll_h;}
		static Dynamic nme_text_field_get_bottom_scroll_v; /* REM */ 
		static Dynamic &nme_text_field_get_bottom_scroll_v_dyn() { return nme_text_field_get_bottom_scroll_v;}
		static Dynamic nme_text_field_get_scroll_h; /* REM */ 
		static Dynamic &nme_text_field_get_scroll_h_dyn() { return nme_text_field_get_scroll_h;}
		static Dynamic nme_text_field_set_scroll_h; /* REM */ 
		static Dynamic &nme_text_field_set_scroll_h_dyn() { return nme_text_field_set_scroll_h;}
		static Dynamic nme_text_field_get_scroll_v; /* REM */ 
		static Dynamic &nme_text_field_get_scroll_v_dyn() { return nme_text_field_get_scroll_v;}
		static Dynamic nme_text_field_set_scroll_v; /* REM */ 
		static Dynamic &nme_text_field_set_scroll_v_dyn() { return nme_text_field_set_scroll_v;}
		static Dynamic nme_text_field_get_num_lines; /* REM */ 
		static Dynamic &nme_text_field_get_num_lines_dyn() { return nme_text_field_get_num_lines;}
		static Dynamic nme_text_field_get_max_chars; /* REM */ 
		static Dynamic &nme_text_field_get_max_chars_dyn() { return nme_text_field_get_max_chars;}
		static Dynamic nme_text_field_set_max_chars; /* REM */ 
		static Dynamic &nme_text_field_set_max_chars_dyn() { return nme_text_field_set_max_chars;}
		static Dynamic nme_text_field_get_line_text; /* REM */ 
		static Dynamic &nme_text_field_get_line_text_dyn() { return nme_text_field_get_line_text;}
		static Dynamic nme_text_field_get_line_offset; /* REM */ 
		static Dynamic &nme_text_field_get_line_offset_dyn() { return nme_text_field_get_line_offset;}
};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_TextField */ 
