#ifndef INCLUDED_cocktail_core_html_HTMLConstants
#define INCLUDED_cocktail_core_html_HTMLConstants

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,html,HTMLConstants)
namespace cocktail{
namespace core{
namespace html{


class HTMLConstants_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HTMLConstants_obj OBJ_;
		HTMLConstants_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLConstants_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLConstants_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLConstants"); }

		static ::String HTML_BODY_TAG_NAME; /* REM */ 
		static ::String HTML_ANCHOR_TAG_NAME; /* REM */ 
		static ::String HTML_IMAGE_TAG_NAME; /* REM */ 
		static ::String HTML_INPUT_TAG_NAME; /* REM */ 
		static ::String HTML_HTML_TAG_NAME; /* REM */ 
		static ::String HTML_VIDEO_TAG_NAME; /* REM */ 
		static ::String HTML_AUDIO_TAG_NAME; /* REM */ 
		static ::String HTML_SOURCE_TAG_NAME; /* REM */ 
		static ::String HTML_DIV_TAG_NAME; /* REM */ 
		static ::String HTML_OBJECT_TAG_NAME; /* REM */ 
		static ::String HTML_PARAM_TAG_NAME; /* REM */ 
		static ::String HTML_ADRESS_TAG_NAME; /* REM */ 
		static ::String HTML_DD_TAG_NAME; /* REM */ 
		static ::String HTML_DL_TAG_NAME; /* REM */ 
		static ::String HTML_DT_TAG_NAME; /* REM */ 
		static ::String HTML_FIELDSET_TAG_NAME; /* REM */ 
		static ::String HTML_FORM_TAG_NAME; /* REM */ 
		static ::String HTML_FRAME_TAG_NAME; /* REM */ 
		static ::String HTML_FRAMESET_TAG_NAME; /* REM */ 
		static ::String HTML_NOFRAMES_TAG_NAME; /* REM */ 
		static ::String HTML_OL_TAG_NAME; /* REM */ 
		static ::String HTML_CENTER_TAG_NAME; /* REM */ 
		static ::String HTML_DIR_TAG_NAME; /* REM */ 
		static ::String HTML_HR_TAG_NAME; /* REM */ 
		static ::String HTML_MENU_TAG_NAME; /* REM */ 
		static ::String HTML_LI_TAG_NAME; /* REM */ 
		static ::String HTML_UL_TAG_NAME; /* REM */ 
		static ::String HTML_HEAD_TAG_NAME; /* REM */ 
		static ::String HTML_H1_TAG_NAME; /* REM */ 
		static ::String HTML_H2_TAG_NAME; /* REM */ 
		static ::String HTML_H3_TAG_NAME; /* REM */ 
		static ::String HTML_H4_TAG_NAME; /* REM */ 
		static ::String HTML_H5_TAG_NAME; /* REM */ 
		static ::String HTML_H6_TAG_NAME; /* REM */ 
		static ::String HTML_P_TAG_NAME; /* REM */ 
		static ::String HTML_PRE_TAG_NAME; /* REM */ 
		static ::String HTML_CODE_TAG_NAME; /* REM */ 
		static ::String HTML_I_TAG_NAME; /* REM */ 
		static ::String HTML_CITE_TAG_NAME; /* REM */ 
		static ::String HTML_EM_TAG_NAME; /* REM */ 
		static ::String HTML_VAR_TAG_NAME; /* REM */ 
		static ::String HTML_BLOCKQUOTE_TAG_NAME; /* REM */ 
		static ::String HTML_STRONG_TAG_NAME; /* REM */ 
		static ::String HTML_BIG_TAG_NAME; /* REM */ 
		static ::String HTML_SMALL_TAG_NAME; /* REM */ 
		static ::String HTML_SUB_TAG_NAME; /* REM */ 
		static ::String HTML_SUP_TAG_NAME; /* REM */ 
		static ::String HTML_LINK_TAG_NAME; /* REM */ 
		static ::String HTML_STYLE_TAG_NAME; /* REM */ 
		static ::String HTML_BR_TAG_NAME; /* REM */ 
		static ::String HTML_META_TAG_NAME; /* REM */ 
		static ::String HTML_ID_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_CLASS_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_HIDDEN_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_TAB_INDEX_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_STYLE_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_SRC_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_VALUE_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_AUTOPLAY_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_LOOP_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_TYPE_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_MEDIA_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_HREF_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_TARGET_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_DATA_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_HEIGHT_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_WIDTH_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_POSTER_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_NAME_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_REL_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_HREFLANG_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_DISABLED_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_CHECKED_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_MAXLENGTH_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_CONTENT_ATTRIBUTE_NAME; /* REM */ 
		static ::String HTML_PRELOAD_ATTRIBUTE_NAME; /* REM */ 
		static ::String PRELOAD_AUTO; /* REM */ 
		static ::String PRELOAD_NONE; /* REM */ 
		static ::String PRELOAD_METADATA; /* REM */ 
		static ::String TARGET_BLANK; /* REM */ 
		static ::String TARGET_SELF; /* REM */ 
		static ::String TARGET_PARENT; /* REM */ 
		static ::String TARGET_TOP; /* REM */ 
		static ::String HTML_TOKEN_LESS_THAN; /* REM */ 
		static ::String HTML_TOKEN_MORE_THAN; /* REM */ 
		static ::String HTML_TOKEN_SOLIDUS; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLConstants */ 
