#ifndef INCLUDED_native_text_TextField
#define INCLUDED_native_text_TextField

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <native/display/InteractiveObject.h>
HX_DECLARE_CLASS2(native,display,DisplayObject)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
HX_DECLARE_CLASS2(native,display,InteractiveObject)
HX_DECLARE_CLASS2(native,events,EventDispatcher)
HX_DECLARE_CLASS2(native,events,IEventDispatcher)
HX_DECLARE_CLASS2(native,text,AntiAliasType)
HX_DECLARE_CLASS2(native,text,TextField)
HX_DECLARE_CLASS2(native,text,TextFieldAutoSize)
HX_DECLARE_CLASS2(native,text,TextFieldType)
HX_DECLARE_CLASS2(native,text,TextFormat)
namespace native{
namespace text{


class TextField_obj : public ::native::display::InteractiveObject_obj{
	public:
		typedef ::native::display::InteractiveObject_obj super;
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

		virtual bool set_wordWrap( bool inVal);
		Dynamic set_wordWrap_dyn();

		virtual bool get_wordWrap( );
		Dynamic get_wordWrap_dyn();

		virtual ::native::text::TextFieldType set_type( ::native::text::TextFieldType inType);
		Dynamic set_type_dyn();

		virtual ::native::text::TextFieldType get_type( );
		Dynamic get_type_dyn();

		virtual Float get_textHeight( );
		Dynamic get_textHeight_dyn();

		virtual Float get_textWidth( );
		Dynamic get_textWidth_dyn();

		virtual int set_textColor( int inCol);
		Dynamic set_textColor_dyn();

		virtual int get_textColor( );
		Dynamic get_textColor_dyn();

		virtual ::String set_text( ::String inText);
		Dynamic set_text_dyn();

		virtual ::String get_text( );
		Dynamic get_text_dyn();

		virtual bool set_selectable( bool inSel);
		Dynamic set_selectable_dyn();

		virtual bool get_selectable( );
		Dynamic get_selectable_dyn();

		virtual int set_scrollV( int inVal);
		Dynamic set_scrollV_dyn();

		virtual int get_scrollV( );
		Dynamic get_scrollV_dyn();

		virtual int set_scrollH( int inVal);
		Dynamic set_scrollH_dyn();

		virtual int get_scrollH( );
		Dynamic get_scrollH_dyn();

		virtual int get_numLines( );
		Dynamic get_numLines_dyn();

		virtual bool set_multiline( bool inVal);
		Dynamic set_multiline_dyn();

		virtual bool get_multiline( );
		Dynamic get_multiline_dyn();

		virtual int get_maxScrollV( );
		Dynamic get_maxScrollV_dyn();

		virtual int get_maxScrollH( );
		Dynamic get_maxScrollH_dyn();

		virtual int set_maxChars( int inVal);
		Dynamic set_maxChars_dyn();

		virtual int get_maxChars( );
		Dynamic get_maxChars_dyn();

		virtual ::String set_htmlText( ::String inText);
		Dynamic set_htmlText_dyn();

		virtual ::String get_htmlText( );
		Dynamic get_htmlText_dyn();

		virtual bool set_embedFonts( bool value);
		Dynamic set_embedFonts_dyn();

		virtual bool get_embedFonts( );
		Dynamic get_embedFonts_dyn();

		virtual bool set_displayAsPassword( bool inVal);
		Dynamic set_displayAsPassword_dyn();

		virtual bool get_displayAsPassword( );
		Dynamic get_displayAsPassword_dyn();

		virtual ::native::text::TextFormat set_defaultTextFormat( ::native::text::TextFormat inFormat);
		Dynamic set_defaultTextFormat_dyn();

		virtual ::native::text::TextFormat get_defaultTextFormat( );
		Dynamic get_defaultTextFormat_dyn();

		virtual int get_bottomScrollV( );
		Dynamic get_bottomScrollV_dyn();

		virtual int set_borderColor( int inVal);
		Dynamic set_borderColor_dyn();

		virtual int get_borderColor( );
		Dynamic get_borderColor_dyn();

		virtual bool set_border( bool inVal);
		Dynamic set_border_dyn();

		virtual bool get_border( );
		Dynamic get_border_dyn();

		virtual int set_backgroundColor( int inVal);
		Dynamic set_backgroundColor_dyn();

		virtual int get_backgroundColor( );
		Dynamic get_backgroundColor_dyn();

		virtual bool set_background( bool inVal);
		Dynamic set_background_dyn();

		virtual bool get_background( );
		Dynamic get_background_dyn();

		virtual ::native::text::TextFieldAutoSize set_autoSize( ::native::text::TextFieldAutoSize inVal);
		Dynamic set_autoSize_dyn();

		virtual ::native::text::TextFieldAutoSize get_autoSize( );
		Dynamic get_autoSize_dyn();

		virtual Void setTextFormat( ::native::text::TextFormat format,hx::Null< int >  beginIndex,hx::Null< int >  endIndex);
		Dynamic setTextFormat_dyn();

		virtual Void setSelection( int beginIndex,int endIndex);
		Dynamic setSelection_dyn();

		virtual ::String getLineText( int lineIndex);
		Dynamic getLineText_dyn();

		virtual int getLineOffset( int lineIndex);
		Dynamic getLineOffset_dyn();

		virtual Void appendText( ::String newText);
		Dynamic appendText_dyn();

		bool wordWrap; /* REM */ 
		::native::text::TextFieldType type; /* REM */ 
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
		::native::text::TextFormat defaultTextFormat; /* REM */ 
		int bottomScrollV; /* REM */ 
		int borderColor; /* REM */ 
		bool border; /* REM */ 
		int backgroundColor; /* REM */ 
		bool background; /* REM */ 
		::native::text::TextFieldAutoSize autoSize; /* REM */ 
		::native::text::AntiAliasType antiAliasType; /* REM */ 
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

} // end namespace native
} // end namespace text

#endif /* INCLUDED_native_text_TextField */ 
