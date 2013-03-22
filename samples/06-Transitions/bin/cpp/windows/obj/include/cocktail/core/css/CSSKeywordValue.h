#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#define INCLUDED_cocktail_core_css_CSSKeywordValue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
namespace cocktail{
namespace core{
namespace css{


class CSSKeywordValue_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CSSKeywordValue_obj OBJ_;

	public:
		CSSKeywordValue_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cocktail.core.css.CSSKeywordValue"); }
		::String __ToString() const { return HX_CSTRING("CSSKeywordValue.") + tag; }

		static ::cocktail::core::css::CSSKeywordValue ABSOLUTE;
		static inline ::cocktail::core::css::CSSKeywordValue ABSOLUTE_dyn() { return ABSOLUTE; }
		static ::cocktail::core::css::CSSKeywordValue ALL;
		static inline ::cocktail::core::css::CSSKeywordValue ALL_dyn() { return ALL; }
		static ::cocktail::core::css::CSSKeywordValue AUTO;
		static inline ::cocktail::core::css::CSSKeywordValue AUTO_dyn() { return AUTO; }
		static ::cocktail::core::css::CSSKeywordValue BASELINE;
		static inline ::cocktail::core::css::CSSKeywordValue BASELINE_dyn() { return BASELINE; }
		static ::cocktail::core::css::CSSKeywordValue BLINK;
		static inline ::cocktail::core::css::CSSKeywordValue BLINK_dyn() { return BLINK; }
		static ::cocktail::core::css::CSSKeywordValue BLOCK;
		static inline ::cocktail::core::css::CSSKeywordValue BLOCK_dyn() { return BLOCK; }
		static ::cocktail::core::css::CSSKeywordValue BOLD;
		static inline ::cocktail::core::css::CSSKeywordValue BOLD_dyn() { return BOLD; }
		static ::cocktail::core::css::CSSKeywordValue BOLDER;
		static inline ::cocktail::core::css::CSSKeywordValue BOLDER_dyn() { return BOLDER; }
		static ::cocktail::core::css::CSSKeywordValue BORDER_BOX;
		static inline ::cocktail::core::css::CSSKeywordValue BORDER_BOX_dyn() { return BORDER_BOX; }
		static ::cocktail::core::css::CSSKeywordValue BOTH;
		static inline ::cocktail::core::css::CSSKeywordValue BOTH_dyn() { return BOTH; }
		static ::cocktail::core::css::CSSKeywordValue BOTTOM;
		static inline ::cocktail::core::css::CSSKeywordValue BOTTOM_dyn() { return BOTTOM; }
		static ::cocktail::core::css::CSSKeywordValue CAPITALIZE;
		static inline ::cocktail::core::css::CSSKeywordValue CAPITALIZE_dyn() { return CAPITALIZE; }
		static ::cocktail::core::css::CSSKeywordValue CENTER;
		static inline ::cocktail::core::css::CSSKeywordValue CENTER_dyn() { return CENTER; }
		static ::cocktail::core::css::CSSKeywordValue CONTAIN;
		static inline ::cocktail::core::css::CSSKeywordValue CONTAIN_dyn() { return CONTAIN; }
		static ::cocktail::core::css::CSSKeywordValue CONTENT_BOX;
		static inline ::cocktail::core::css::CSSKeywordValue CONTENT_BOX_dyn() { return CONTENT_BOX; }
		static ::cocktail::core::css::CSSKeywordValue COVER;
		static inline ::cocktail::core::css::CSSKeywordValue COVER_dyn() { return COVER; }
		static ::cocktail::core::css::CSSKeywordValue CROSSHAIR;
		static inline ::cocktail::core::css::CSSKeywordValue CROSSHAIR_dyn() { return CROSSHAIR; }
		static ::cocktail::core::css::CSSKeywordValue DASHED;
		static inline ::cocktail::core::css::CSSKeywordValue DASHED_dyn() { return DASHED; }
		static ::cocktail::core::css::CSSKeywordValue DEFAULT;
		static inline ::cocktail::core::css::CSSKeywordValue DEFAULT_dyn() { return DEFAULT; }
		static ::cocktail::core::css::CSSKeywordValue DOTTED;
		static inline ::cocktail::core::css::CSSKeywordValue DOTTED_dyn() { return DOTTED; }
		static ::cocktail::core::css::CSSKeywordValue DOUBLE;
		static inline ::cocktail::core::css::CSSKeywordValue DOUBLE_dyn() { return DOUBLE; }
		static ::cocktail::core::css::CSSKeywordValue EASE;
		static inline ::cocktail::core::css::CSSKeywordValue EASE_dyn() { return EASE; }
		static ::cocktail::core::css::CSSKeywordValue EASE_IN;
		static inline ::cocktail::core::css::CSSKeywordValue EASE_IN_dyn() { return EASE_IN; }
		static ::cocktail::core::css::CSSKeywordValue EASE_IN_OUT;
		static inline ::cocktail::core::css::CSSKeywordValue EASE_IN_OUT_dyn() { return EASE_IN_OUT; }
		static ::cocktail::core::css::CSSKeywordValue EASE_OUT;
		static inline ::cocktail::core::css::CSSKeywordValue EASE_OUT_dyn() { return EASE_OUT; }
		static ::cocktail::core::css::CSSKeywordValue END;
		static inline ::cocktail::core::css::CSSKeywordValue END_dyn() { return END; }
		static ::cocktail::core::css::CSSKeywordValue FIXED;
		static inline ::cocktail::core::css::CSSKeywordValue FIXED_dyn() { return FIXED; }
		static ::cocktail::core::css::CSSKeywordValue GROOVE;
		static inline ::cocktail::core::css::CSSKeywordValue GROOVE_dyn() { return GROOVE; }
		static ::cocktail::core::css::CSSKeywordValue HIDDEN;
		static inline ::cocktail::core::css::CSSKeywordValue HIDDEN_dyn() { return HIDDEN; }
		static ::cocktail::core::css::CSSKeywordValue INLINE;
		static inline ::cocktail::core::css::CSSKeywordValue INLINE_dyn() { return INLINE; }
		static ::cocktail::core::css::CSSKeywordValue INLINE_BLOCK;
		static inline ::cocktail::core::css::CSSKeywordValue INLINE_BLOCK_dyn() { return INLINE_BLOCK; }
		static ::cocktail::core::css::CSSKeywordValue INSET;
		static inline ::cocktail::core::css::CSSKeywordValue INSET_dyn() { return INSET; }
		static ::cocktail::core::css::CSSKeywordValue INVERT;
		static inline ::cocktail::core::css::CSSKeywordValue INVERT_dyn() { return INVERT; }
		static ::cocktail::core::css::CSSKeywordValue ITALIC;
		static inline ::cocktail::core::css::CSSKeywordValue ITALIC_dyn() { return ITALIC; }
		static ::cocktail::core::css::CSSKeywordValue JUSTIFY;
		static inline ::cocktail::core::css::CSSKeywordValue JUSTIFY_dyn() { return JUSTIFY; }
		static ::cocktail::core::css::CSSKeywordValue LARGE;
		static inline ::cocktail::core::css::CSSKeywordValue LARGE_dyn() { return LARGE; }
		static ::cocktail::core::css::CSSKeywordValue LARGER;
		static inline ::cocktail::core::css::CSSKeywordValue LARGER_dyn() { return LARGER; }
		static ::cocktail::core::css::CSSKeywordValue LEFT;
		static inline ::cocktail::core::css::CSSKeywordValue LEFT_dyn() { return LEFT; }
		static ::cocktail::core::css::CSSKeywordValue LIGHTER;
		static inline ::cocktail::core::css::CSSKeywordValue LIGHTER_dyn() { return LIGHTER; }
		static ::cocktail::core::css::CSSKeywordValue LINEAR;
		static inline ::cocktail::core::css::CSSKeywordValue LINEAR_dyn() { return LINEAR; }
		static ::cocktail::core::css::CSSKeywordValue LINE_THROUGH;
		static inline ::cocktail::core::css::CSSKeywordValue LINE_THROUGH_dyn() { return LINE_THROUGH; }
		static ::cocktail::core::css::CSSKeywordValue LOWERCASE;
		static inline ::cocktail::core::css::CSSKeywordValue LOWERCASE_dyn() { return LOWERCASE; }
		static ::cocktail::core::css::CSSKeywordValue MEDIUM;
		static inline ::cocktail::core::css::CSSKeywordValue MEDIUM_dyn() { return MEDIUM; }
		static ::cocktail::core::css::CSSKeywordValue MIDDLE;
		static inline ::cocktail::core::css::CSSKeywordValue MIDDLE_dyn() { return MIDDLE; }
		static ::cocktail::core::css::CSSKeywordValue NONE;
		static inline ::cocktail::core::css::CSSKeywordValue NONE_dyn() { return NONE; }
		static ::cocktail::core::css::CSSKeywordValue NORMAL;
		static inline ::cocktail::core::css::CSSKeywordValue NORMAL_dyn() { return NORMAL; }
		static ::cocktail::core::css::CSSKeywordValue NO_REPEAT;
		static inline ::cocktail::core::css::CSSKeywordValue NO_REPEAT_dyn() { return NO_REPEAT; }
		static ::cocktail::core::css::CSSKeywordValue NO_WRAP;
		static inline ::cocktail::core::css::CSSKeywordValue NO_WRAP_dyn() { return NO_WRAP; }
		static ::cocktail::core::css::CSSKeywordValue OBLIQUE;
		static inline ::cocktail::core::css::CSSKeywordValue OBLIQUE_dyn() { return OBLIQUE; }
		static ::cocktail::core::css::CSSKeywordValue OUTSET;
		static inline ::cocktail::core::css::CSSKeywordValue OUTSET_dyn() { return OUTSET; }
		static ::cocktail::core::css::CSSKeywordValue OVERLINE;
		static inline ::cocktail::core::css::CSSKeywordValue OVERLINE_dyn() { return OVERLINE; }
		static ::cocktail::core::css::CSSKeywordValue PADDING_BOX;
		static inline ::cocktail::core::css::CSSKeywordValue PADDING_BOX_dyn() { return PADDING_BOX; }
		static ::cocktail::core::css::CSSKeywordValue POINTER;
		static inline ::cocktail::core::css::CSSKeywordValue POINTER_dyn() { return POINTER; }
		static ::cocktail::core::css::CSSKeywordValue PRE;
		static inline ::cocktail::core::css::CSSKeywordValue PRE_dyn() { return PRE; }
		static ::cocktail::core::css::CSSKeywordValue PRE_LINE;
		static inline ::cocktail::core::css::CSSKeywordValue PRE_LINE_dyn() { return PRE_LINE; }
		static ::cocktail::core::css::CSSKeywordValue PRE_WRAP;
		static inline ::cocktail::core::css::CSSKeywordValue PRE_WRAP_dyn() { return PRE_WRAP; }
		static ::cocktail::core::css::CSSKeywordValue RELATIVE;
		static inline ::cocktail::core::css::CSSKeywordValue RELATIVE_dyn() { return RELATIVE; }
		static ::cocktail::core::css::CSSKeywordValue REPEAT;
		static inline ::cocktail::core::css::CSSKeywordValue REPEAT_dyn() { return REPEAT; }
		static ::cocktail::core::css::CSSKeywordValue REPEAT_X;
		static inline ::cocktail::core::css::CSSKeywordValue REPEAT_X_dyn() { return REPEAT_X; }
		static ::cocktail::core::css::CSSKeywordValue REPEAT_Y;
		static inline ::cocktail::core::css::CSSKeywordValue REPEAT_Y_dyn() { return REPEAT_Y; }
		static ::cocktail::core::css::CSSKeywordValue RIDGE;
		static inline ::cocktail::core::css::CSSKeywordValue RIDGE_dyn() { return RIDGE; }
		static ::cocktail::core::css::CSSKeywordValue RIGHT;
		static inline ::cocktail::core::css::CSSKeywordValue RIGHT_dyn() { return RIGHT; }
		static ::cocktail::core::css::CSSKeywordValue ROUND;
		static inline ::cocktail::core::css::CSSKeywordValue ROUND_dyn() { return ROUND; }
		static ::cocktail::core::css::CSSKeywordValue SCROLL;
		static inline ::cocktail::core::css::CSSKeywordValue SCROLL_dyn() { return SCROLL; }
		static ::cocktail::core::css::CSSKeywordValue SMALL;
		static inline ::cocktail::core::css::CSSKeywordValue SMALL_dyn() { return SMALL; }
		static ::cocktail::core::css::CSSKeywordValue SMALLER;
		static inline ::cocktail::core::css::CSSKeywordValue SMALLER_dyn() { return SMALLER; }
		static ::cocktail::core::css::CSSKeywordValue SMALL_CAPS;
		static inline ::cocktail::core::css::CSSKeywordValue SMALL_CAPS_dyn() { return SMALL_CAPS; }
		static ::cocktail::core::css::CSSKeywordValue SOLID;
		static inline ::cocktail::core::css::CSSKeywordValue SOLID_dyn() { return SOLID; }
		static ::cocktail::core::css::CSSKeywordValue SPACE;
		static inline ::cocktail::core::css::CSSKeywordValue SPACE_dyn() { return SPACE; }
		static ::cocktail::core::css::CSSKeywordValue START;
		static inline ::cocktail::core::css::CSSKeywordValue START_dyn() { return START; }
		static ::cocktail::core::css::CSSKeywordValue STATIC;
		static inline ::cocktail::core::css::CSSKeywordValue STATIC_dyn() { return STATIC; }
		static ::cocktail::core::css::CSSKeywordValue STEP_END;
		static inline ::cocktail::core::css::CSSKeywordValue STEP_END_dyn() { return STEP_END; }
		static ::cocktail::core::css::CSSKeywordValue STEP_START;
		static inline ::cocktail::core::css::CSSKeywordValue STEP_START_dyn() { return STEP_START; }
		static ::cocktail::core::css::CSSKeywordValue SUB;
		static inline ::cocktail::core::css::CSSKeywordValue SUB_dyn() { return SUB; }
		static ::cocktail::core::css::CSSKeywordValue SUPER;
		static inline ::cocktail::core::css::CSSKeywordValue SUPER_dyn() { return SUPER; }
		static ::cocktail::core::css::CSSKeywordValue TEXT;
		static inline ::cocktail::core::css::CSSKeywordValue TEXT_dyn() { return TEXT; }
		static ::cocktail::core::css::CSSKeywordValue TEXT_BOTTOM;
		static inline ::cocktail::core::css::CSSKeywordValue TEXT_BOTTOM_dyn() { return TEXT_BOTTOM; }
		static ::cocktail::core::css::CSSKeywordValue TEXT_TOP;
		static inline ::cocktail::core::css::CSSKeywordValue TEXT_TOP_dyn() { return TEXT_TOP; }
		static ::cocktail::core::css::CSSKeywordValue THICK;
		static inline ::cocktail::core::css::CSSKeywordValue THICK_dyn() { return THICK; }
		static ::cocktail::core::css::CSSKeywordValue THIN;
		static inline ::cocktail::core::css::CSSKeywordValue THIN_dyn() { return THIN; }
		static ::cocktail::core::css::CSSKeywordValue TOP;
		static inline ::cocktail::core::css::CSSKeywordValue TOP_dyn() { return TOP; }
		static ::cocktail::core::css::CSSKeywordValue UNDERLINE;
		static inline ::cocktail::core::css::CSSKeywordValue UNDERLINE_dyn() { return UNDERLINE; }
		static ::cocktail::core::css::CSSKeywordValue UPPERCASE;
		static inline ::cocktail::core::css::CSSKeywordValue UPPERCASE_dyn() { return UPPERCASE; }
		static ::cocktail::core::css::CSSKeywordValue VISIBLE;
		static inline ::cocktail::core::css::CSSKeywordValue VISIBLE_dyn() { return VISIBLE; }
		static ::cocktail::core::css::CSSKeywordValue XX_LARGE;
		static inline ::cocktail::core::css::CSSKeywordValue XX_LARGE_dyn() { return XX_LARGE; }
		static ::cocktail::core::css::CSSKeywordValue XX_SMALL;
		static inline ::cocktail::core::css::CSSKeywordValue XX_SMALL_dyn() { return XX_SMALL; }
		static ::cocktail::core::css::CSSKeywordValue X_LARGE;
		static inline ::cocktail::core::css::CSSKeywordValue X_LARGE_dyn() { return X_LARGE; }
		static ::cocktail::core::css::CSSKeywordValue X_SMALL;
		static inline ::cocktail::core::css::CSSKeywordValue X_SMALL_dyn() { return X_SMALL; }
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSKeywordValue */ 
