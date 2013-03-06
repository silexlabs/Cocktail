#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#define INCLUDED_cocktail_core_css_CSSStyleDeclaration

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSLengthValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSRule)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,TypedPropertyVO)
namespace cocktail{
namespace core{
namespace css{


class CSSStyleDeclaration_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CSSStyleDeclaration_obj OBJ_;
		CSSStyleDeclaration_obj();
		Void __construct(::cocktail::core::css::CSSRule parentRule,Dynamic onStyleChange);

	public:
		static hx::ObjectPtr< CSSStyleDeclaration_obj > __new(::cocktail::core::css::CSSRule parentRule,Dynamic onStyleChange);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CSSStyleDeclaration_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CSSStyleDeclaration"); }

		virtual ::String set_textDecoration( ::String value);
		Dynamic set_textDecoration_dyn();

		virtual ::String get_textDecoration( );
		Dynamic get_textDecoration_dyn();

		virtual ::String set_outlineStyle( ::String value);
		Dynamic set_outlineStyle_dyn();

		virtual ::String get_outlineStyle( );
		Dynamic get_outlineStyle_dyn();

		virtual ::String set_outlineColor( ::String value);
		Dynamic set_outlineColor_dyn();

		virtual ::String get_outlineColor( );
		Dynamic get_outlineColor_dyn();

		virtual ::String set_outlineWidth( ::String value);
		Dynamic set_outlineWidth_dyn();

		virtual ::String get_outlineWidth( );
		Dynamic get_outlineWidth_dyn();

		virtual ::String set_outline( ::String value);
		Dynamic set_outline_dyn();

		virtual ::String get_outline( );
		Dynamic get_outline_dyn();

		virtual ::String set_border( ::String value);
		Dynamic set_border_dyn();

		virtual ::String get_border( );
		Dynamic get_border_dyn();

		virtual ::String set_borderLeft( ::String value);
		Dynamic set_borderLeft_dyn();

		virtual ::String get_borderLeft( );
		Dynamic get_borderLeft_dyn();

		virtual ::String set_borderBottom( ::String value);
		Dynamic set_borderBottom_dyn();

		virtual ::String get_borderBottom( );
		Dynamic get_borderBottom_dyn();

		virtual ::String set_borderRight( ::String value);
		Dynamic set_borderRight_dyn();

		virtual ::String get_borderRight( );
		Dynamic get_borderRight_dyn();

		virtual ::String set_borderTop( ::String value);
		Dynamic set_borderTop_dyn();

		virtual ::String get_borderTop( );
		Dynamic get_borderTop_dyn();

		virtual ::String set_borderStyle( ::String value);
		Dynamic set_borderStyle_dyn();

		virtual ::String get_borderStyle( );
		Dynamic get_borderStyle_dyn();

		virtual ::String set_borderLeftStyle( ::String value);
		Dynamic set_borderLeftStyle_dyn();

		virtual ::String get_borderLeftStyle( );
		Dynamic get_borderLeftStyle_dyn();

		virtual ::String set_borderBottomStyle( ::String value);
		Dynamic set_borderBottomStyle_dyn();

		virtual ::String get_borderBottomStyle( );
		Dynamic get_borderBottomStyle_dyn();

		virtual ::String set_borderRightStyle( ::String value);
		Dynamic set_borderRightStyle_dyn();

		virtual ::String get_borderRightStyle( );
		Dynamic get_borderRightStyle_dyn();

		virtual ::String set_borderTopStyle( ::String value);
		Dynamic set_borderTopStyle_dyn();

		virtual ::String get_borderTopStyle( );
		Dynamic get_borderTopStyle_dyn();

		virtual ::String set_borderColor( ::String value);
		Dynamic set_borderColor_dyn();

		virtual ::String get_borderColor( );
		Dynamic get_borderColor_dyn();

		virtual ::String set_borderLeftColor( ::String value);
		Dynamic set_borderLeftColor_dyn();

		virtual ::String get_borderLeftColor( );
		Dynamic get_borderLeftColor_dyn();

		virtual ::String set_borderBottomColor( ::String value);
		Dynamic set_borderBottomColor_dyn();

		virtual ::String get_borderBottomColor( );
		Dynamic get_borderBottomColor_dyn();

		virtual ::String set_borderRightColor( ::String value);
		Dynamic set_borderRightColor_dyn();

		virtual ::String get_borderRightColor( );
		Dynamic get_borderRightColor_dyn();

		virtual ::String set_borderTopColor( ::String value);
		Dynamic set_borderTopColor_dyn();

		virtual ::String get_borderTopColor( );
		Dynamic get_borderTopColor_dyn();

		virtual ::String set_borderWidth( ::String value);
		Dynamic set_borderWidth_dyn();

		virtual ::String get_borderWidth( );
		Dynamic get_borderWidth_dyn();

		virtual ::String set_borderLeftWidth( ::String value);
		Dynamic set_borderLeftWidth_dyn();

		virtual ::String get_borderLeftWidth( );
		Dynamic get_borderLeftWidth_dyn();

		virtual ::String set_borderBottomWidth( ::String value);
		Dynamic set_borderBottomWidth_dyn();

		virtual ::String get_borderBottomWidth( );
		Dynamic get_borderBottomWidth_dyn();

		virtual ::String set_borderRightWidth( ::String value);
		Dynamic set_borderRightWidth_dyn();

		virtual ::String get_borderRightWidth( );
		Dynamic get_borderRightWidth_dyn();

		virtual ::String set_borderTopWidth( ::String value);
		Dynamic set_borderTopWidth_dyn();

		virtual ::String get_borderTopWidth( );
		Dynamic get_borderTopWidth_dyn();

		virtual ::String set_transformOrigin( ::String value);
		Dynamic set_transformOrigin_dyn();

		virtual ::String get_transformOrigin( );
		Dynamic get_transformOrigin_dyn();

		virtual ::String set_transform( ::String value);
		Dynamic set_transform_dyn();

		virtual ::String get_transform( );
		Dynamic get_transform_dyn();

		virtual ::String set_transitionTimingFunction( ::String value);
		Dynamic set_transitionTimingFunction_dyn();

		virtual ::String get_transitionTimingFunction( );
		Dynamic get_transitionTimingFunction_dyn();

		virtual ::String set_transitionDelay( ::String value);
		Dynamic set_transitionDelay_dyn();

		virtual ::String get_transitionDelay( );
		Dynamic get_transitionDelay_dyn();

		virtual ::String set_transitionDuration( ::String value);
		Dynamic set_transitionDuration_dyn();

		virtual ::String get_transitionDuration( );
		Dynamic get_transitionDuration_dyn();

		virtual ::String set_transitionProperty( ::String value);
		Dynamic set_transitionProperty_dyn();

		virtual ::String get_transitionProperty( );
		Dynamic get_transitionProperty_dyn();

		virtual ::String get_cursor( );
		Dynamic get_cursor_dyn();

		virtual ::String set_cursor( ::String value);
		Dynamic set_cursor_dyn();

		virtual ::String set_overflowY( ::String value);
		Dynamic set_overflowY_dyn();

		virtual ::String get_overflowY( );
		Dynamic get_overflowY_dyn();

		virtual ::String set_overflowX( ::String value);
		Dynamic set_overflowX_dyn();

		virtual ::String get_overflowX( );
		Dynamic get_overflowX_dyn();

		virtual ::String set_overflow( ::String value);
		Dynamic set_overflow_dyn();

		virtual ::String get_overflow( );
		Dynamic get_overflow_dyn();

		virtual ::String get_backgroundOrigin( );
		Dynamic get_backgroundOrigin_dyn();

		virtual ::String set_backgroundOrigin( ::String value);
		Dynamic set_backgroundOrigin_dyn();

		virtual ::String get_backgroundPosition( );
		Dynamic get_backgroundPosition_dyn();

		virtual ::String set_backgroundPosition( ::String value);
		Dynamic set_backgroundPosition_dyn();

		virtual ::String get_backgroundAttachment( );
		Dynamic get_backgroundAttachment_dyn();

		virtual ::String set_backgroundAttachment( ::String value);
		Dynamic set_backgroundAttachment_dyn();

		virtual ::String get_backgroundClip( );
		Dynamic get_backgroundClip_dyn();

		virtual ::String set_backgroundClip( ::String value);
		Dynamic set_backgroundClip_dyn();

		virtual ::String get_backgroundSize( );
		Dynamic get_backgroundSize_dyn();

		virtual ::String set_backgroundSize( ::String value);
		Dynamic set_backgroundSize_dyn();

		virtual ::String get_backgroundRepeat( );
		Dynamic get_backgroundRepeat_dyn();

		virtual ::String set_backgroundRepeat( ::String value);
		Dynamic set_backgroundRepeat_dyn();

		virtual ::String get_backgroundImage( );
		Dynamic get_backgroundImage_dyn();

		virtual ::String set_backgroundImage( ::String value);
		Dynamic set_backgroundImage_dyn();

		virtual ::String get_backgroundColor( );
		Dynamic get_backgroundColor_dyn();

		virtual ::String set_backgroundColor( ::String value);
		Dynamic set_backgroundColor_dyn();

		virtual ::String get_background( );
		Dynamic get_background_dyn();

		virtual ::String set_background( ::String value);
		Dynamic set_background_dyn();

		virtual ::String set_textAlign( ::String value);
		Dynamic set_textAlign_dyn();

		virtual ::String get_textAlign( );
		Dynamic get_textAlign_dyn();

		virtual ::String set_whiteSpace( ::String value);
		Dynamic set_whiteSpace_dyn();

		virtual ::String get_whiteSpace( );
		Dynamic get_whiteSpace_dyn();

		virtual ::String set_textIndent( ::String value);
		Dynamic set_textIndent_dyn();

		virtual ::String get_textIndent( );
		Dynamic get_textIndent_dyn();

		virtual ::String set_verticalAlign( ::String value);
		Dynamic set_verticalAlign_dyn();

		virtual ::String get_verticalAlign( );
		Dynamic get_verticalAlign_dyn();

		virtual ::String set_lineHeight( ::String value);
		Dynamic set_lineHeight_dyn();

		virtual ::String get_lineHeight( );
		Dynamic get_lineHeight_dyn();

		virtual ::String set_wordSpacing( ::String value);
		Dynamic set_wordSpacing_dyn();

		virtual ::String get_wordSpacing( );
		Dynamic get_wordSpacing_dyn();

		virtual ::String set_color( ::String value);
		Dynamic set_color_dyn();

		virtual ::String get_color( );
		Dynamic get_color_dyn();

		virtual ::String set_letterSpacing( ::String value);
		Dynamic set_letterSpacing_dyn();

		virtual ::String get_letterSpacing( );
		Dynamic get_letterSpacing_dyn();

		virtual ::String set_textTransform( ::String value);
		Dynamic set_textTransform_dyn();

		virtual ::String get_textTransform( );
		Dynamic get_textTransform_dyn();

		virtual ::String set_fontVariant( ::String value);
		Dynamic set_fontVariant_dyn();

		virtual ::String get_fontVariant( );
		Dynamic get_fontVariant_dyn();

		virtual ::String set_fontFamily( ::String value);
		Dynamic set_fontFamily_dyn();

		virtual ::String get_fontFamily( );
		Dynamic get_fontFamily_dyn();

		virtual ::String set_fontStyle( ::String value);
		Dynamic set_fontStyle_dyn();

		virtual ::String get_fontStyle( );
		Dynamic get_fontStyle_dyn();

		virtual ::String set_fontWeight( ::String value);
		Dynamic set_fontWeight_dyn();

		virtual ::String get_fontWeight( );
		Dynamic get_fontWeight_dyn();

		virtual ::String set_fontSize( ::String value);
		Dynamic set_fontSize_dyn();

		virtual ::String get_fontSize( );
		Dynamic get_fontSize_dyn();

		virtual ::String get_font( );
		Dynamic get_font_dyn();

		virtual ::String set_font( ::String value);
		Dynamic set_font_dyn();

		virtual ::String set_clear( ::String value);
		Dynamic set_clear_dyn();

		virtual ::String get_clear( );
		Dynamic get_clear_dyn();

		virtual ::String set_CSSFloat( ::String value);
		Dynamic set_CSSFloat_dyn();

		virtual ::String get_CSSFloat( );
		Dynamic get_CSSFloat_dyn();

		virtual ::String set_right( ::String value);
		Dynamic set_right_dyn();

		virtual ::String get_right( );
		Dynamic get_right_dyn();

		virtual ::String set_bottom( ::String value);
		Dynamic set_bottom_dyn();

		virtual ::String get_bottom( );
		Dynamic get_bottom_dyn();

		virtual ::String set_left( ::String value);
		Dynamic set_left_dyn();

		virtual ::String get_left( );
		Dynamic get_left_dyn();

		virtual ::String set_top( ::String value);
		Dynamic set_top_dyn();

		virtual ::String get_top( );
		Dynamic get_top_dyn();

		virtual ::String set_maxWidth( ::String value);
		Dynamic set_maxWidth_dyn();

		virtual ::String get_maxWidth( );
		Dynamic get_maxWidth_dyn();

		virtual ::String set_minWidth( ::String value);
		Dynamic set_minWidth_dyn();

		virtual ::String get_minWidth( );
		Dynamic get_minWidth_dyn();

		virtual ::String set_maxHeight( ::String value);
		Dynamic set_maxHeight_dyn();

		virtual ::String get_maxHeight( );
		Dynamic get_maxHeight_dyn();

		virtual ::String set_minHeight( ::String value);
		Dynamic set_minHeight_dyn();

		virtual ::String get_minHeight( );
		Dynamic get_minHeight_dyn();

		virtual ::String set_height( ::String value);
		Dynamic set_height_dyn();

		virtual ::String get_height( );
		Dynamic get_height_dyn();

		virtual ::String set_width( ::String value);
		Dynamic set_width_dyn();

		virtual ::String get_width( );
		Dynamic get_width_dyn();

		virtual ::String set_zIndex( ::String value);
		Dynamic set_zIndex_dyn();

		virtual ::String get_zIndex( );
		Dynamic get_zIndex_dyn();

		virtual ::String set_position( ::String value);
		Dynamic set_position_dyn();

		virtual ::String get_position( );
		Dynamic get_position_dyn();

		virtual ::String set_display( ::String value);
		Dynamic set_display_dyn();

		virtual ::String get_display( );
		Dynamic get_display_dyn();

		virtual ::String set_paddingBottom( ::String value);
		Dynamic set_paddingBottom_dyn();

		virtual ::String get_paddingBottom( );
		Dynamic get_paddingBottom_dyn();

		virtual ::String set_paddingTop( ::String value);
		Dynamic set_paddingTop_dyn();

		virtual ::String get_paddingTop( );
		Dynamic get_paddingTop_dyn();

		virtual ::String set_paddingRight( ::String value);
		Dynamic set_paddingRight_dyn();

		virtual ::String get_paddingRight( );
		Dynamic get_paddingRight_dyn();

		virtual ::String set_paddingLeft( ::String value);
		Dynamic set_paddingLeft_dyn();

		virtual ::String get_paddingLeft( );
		Dynamic get_paddingLeft_dyn();

		virtual ::String set_padding( ::String value);
		Dynamic set_padding_dyn();

		virtual ::String get_padding( );
		Dynamic get_padding_dyn();

		virtual ::String set_marginBottom( ::String value);
		Dynamic set_marginBottom_dyn();

		virtual ::String get_marginBottom( );
		Dynamic get_marginBottom_dyn();

		virtual ::String set_marginTop( ::String value);
		Dynamic set_marginTop_dyn();

		virtual ::String get_marginTop( );
		Dynamic get_marginTop_dyn();

		virtual ::String set_marginRight( ::String value);
		Dynamic set_marginRight_dyn();

		virtual ::String get_marginRight( );
		Dynamic get_marginRight_dyn();

		virtual ::String set_marginLeft( ::String value);
		Dynamic set_marginLeft_dyn();

		virtual ::String get_marginLeft( );
		Dynamic get_marginLeft_dyn();

		virtual ::String set_margin( ::String value);
		Dynamic set_margin_dyn();

		virtual ::String get_margin( );
		Dynamic get_margin_dyn();

		virtual ::String set_visibility( ::String value);
		Dynamic set_visibility_dyn();

		virtual ::String get_visibility( );
		Dynamic get_visibility_dyn();

		virtual ::String set_opacity( ::String value);
		Dynamic set_opacity_dyn();

		virtual ::String get_opacity( );
		Dynamic get_opacity_dyn();

		virtual ::String set_cssText( ::String value);
		Dynamic set_cssText_dyn();

		virtual ::String get_cssText( );
		Dynamic get_cssText_dyn();

		virtual ::String serializeStyleDeclaration( );
		Dynamic serializeStyleDeclaration_dyn();

		virtual bool isPositiveLength( ::cocktail::core::css::CSSLengthValue length);
		Dynamic isPositiveLength_dyn();

		virtual bool isValidPaddingProperty( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidPaddingProperty_dyn();

		virtual bool isValidMarginProperty( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidMarginProperty_dyn();

		virtual bool isValidOverflowValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidOverflowValue_dyn();

		virtual bool isValidOutlineStyleValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidOutlineStyleValue_dyn();

		virtual bool isValidOutlineColorValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidOutlineColorValue_dyn();

		virtual bool isValidBorderStyleValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBorderStyleValue_dyn();

		virtual bool isValidBorderColorValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBorderColorValue_dyn();

		virtual bool isValidBorderWidthValue( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBorderWidthValue_dyn();

		virtual bool isValidTransitionGroup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		Dynamic isValidTransitionGroup_dyn();

		virtual bool isValidFontGroup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues);
		Dynamic isValidFontGroup_dyn();

		virtual bool isValidFontShorthand( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidFontShorthand_dyn();

		virtual Void setFontShorthandGoup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues,bool important);
		Dynamic setFontShorthandGoup_dyn();

		virtual bool isValidTransitionShorthand( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidTransitionShorthand_dyn();

		virtual bool isValidBackgroundAttachment( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBackgroundAttachment_dyn();

		virtual bool isValidBackgroundRepeat( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBackgroundRepeat_dyn();

		virtual bool isValidBackgroundShorthand( ::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidBackgroundShorthand_dyn();

		virtual bool isValidShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidShorthand_dyn();

		virtual Void setTransitionShorthand( ::cocktail::core::css::CSSPropertyValue styleValue,bool useDelayForTime,Array< ::cocktail::core::css::CSSPropertyValue > transitionProperty,Array< ::cocktail::core::css::CSSPropertyValue > transitionDuration,Array< ::cocktail::core::css::CSSPropertyValue > transitionDelay,Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunction);
		Dynamic setTransitionShorthand_dyn();

		virtual Void setTransitionGroupShorthand( Array< ::cocktail::core::css::CSSPropertyValue > styleValues,Array< ::cocktail::core::css::CSSPropertyValue > transitionProperty,Array< ::cocktail::core::css::CSSPropertyValue > transitionDuration,Array< ::cocktail::core::css::CSSPropertyValue > transitionDelay,Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunction);
		Dynamic setTransitionGroupShorthand_dyn();

		virtual Void setTypedOutlineProperties( ::cocktail::core::css::CSSPropertyValue outlineWidth,::cocktail::core::css::CSSPropertyValue outlineColor,::cocktail::core::css::CSSPropertyValue outlineStyle,bool important);
		Dynamic setTypedOutlineProperties_dyn();

		virtual Void setTypedBorderProperties( int borderWidthPropertyIndex,::cocktail::core::css::CSSPropertyValue borderWidth,int borderColorPropertyIndex,::cocktail::core::css::CSSPropertyValue borderColor,int borderStylePropertyIndex,::cocktail::core::css::CSSPropertyValue borderStyle,bool important);
		Dynamic setTypedBorderProperties_dyn();

		virtual Void setTypedBordersProperties( int propertyIndex,::cocktail::core::css::CSSPropertyValue borderWidth,::cocktail::core::css::CSSPropertyValue borderColor,::cocktail::core::css::CSSPropertyValue borderStyle,bool important);
		Dynamic setTypedBordersProperties_dyn();

		virtual Void setBorderShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important);
		Dynamic setBorderShorthand_dyn();

		virtual Void setShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important);
		Dynamic setShorthand_dyn();

		virtual bool isShorthand( int propertyIndex);
		Dynamic isShorthand_dyn();

		virtual bool isValidBackgroundSize( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isValidBackgroundSize_dyn();

		virtual bool isValidBackgroundPosition( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isValidBackgroundPosition_dyn();

		virtual bool isValidTransitionDelayOrDuration( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isValidTransitionDelayOrDuration_dyn();

		virtual bool isValidTransitionProperty( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isValidTransitionProperty_dyn();

		virtual bool isValidTransitionTimingFunction( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isValidTransitionTimingFunction_dyn();

		virtual bool isValidProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue);
		Dynamic isValidProperty_dyn();

		virtual Void applyProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important);
		Dynamic applyProperty_dyn();

		virtual Void setTypedPropertyInitial( int propertyIndex,::cocktail::core::css::CSSPropertyValue typedValue,bool important);
		Dynamic setTypedPropertyInitial_dyn();

		virtual Void setTypedProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue typedValue,bool important);
		Dynamic setTypedProperty_dyn();

		virtual ::cocktail::core::css::TypedPropertyVO getTypedProperty( int propertyIndex);
		Dynamic getTypedProperty_dyn();

		virtual ::String getPropertyPriority( int propertyIndex);
		Dynamic getPropertyPriority_dyn();

		virtual int removeProperty( int index);
		Dynamic removeProperty_dyn();

		virtual Void setProperty( int index,::String value,::String priority);
		Dynamic setProperty_dyn();

		virtual ::String getPropertyValue( int propertyIndex);
		Dynamic getPropertyValue_dyn();

		virtual int item( int index);
		Dynamic item_dyn();

		virtual Void decrementPropertiesPositions( int removedPropertyIndex);
		Dynamic decrementPropertiesPositions_dyn();

		virtual Void resetPropertiesPositions( );
		Dynamic resetPropertiesPositions_dyn();

		virtual Void resetIndexedProperties( );
		Dynamic resetIndexedProperties_dyn();

		virtual Void reset( );
		Dynamic reset_dyn();

		Dynamic _onStyleChange; /* REM */ 
		Dynamic &_onStyleChange_dyn() { return _onStyleChange;}
		Array< int > _propertiesPositions; /* REM */ 
		Array< ::cocktail::core::css::TypedPropertyVO > _indexedProperties; /* REM */ 
		::cocktail::core::css::CSSRule parentRule; /* REM */ 
		int length; /* REM */ 
		::String cssText; /* REM */ 
		::String outlineStyle; /* REM */ 
		::String outlineColor; /* REM */ 
		::String outlineWidth; /* REM */ 
		::String outline; /* REM */ 
		::String cursor; /* REM */ 
		::String transformOrigin; /* REM */ 
		::String transform; /* REM */ 
		::String transitionDelay; /* REM */ 
		::String transitionTimingFunction; /* REM */ 
		::String transitionDuration; /* REM */ 
		::String transitionProperty; /* REM */ 
		::String overflowY; /* REM */ 
		::String overflowX; /* REM */ 
		::String overflow; /* REM */ 
		::String visibility; /* REM */ 
		::String opacity; /* REM */ 
		::String textDecoration; /* REM */ 
		::String verticalAlign; /* REM */ 
		::String textIndent; /* REM */ 
		::String textAlign; /* REM */ 
		::String whiteSpace; /* REM */ 
		::String wordSpacing; /* REM */ 
		::String letterSpacing; /* REM */ 
		::String textTransform; /* REM */ 
		::String lineHeight; /* REM */ 
		::String color; /* REM */ 
		::String fontVariant; /* REM */ 
		::String fontFamily; /* REM */ 
		::String fontStyle; /* REM */ 
		::String fontWeight; /* REM */ 
		::String fontSize; /* REM */ 
		::String font; /* REM */ 
		::String border; /* REM */ 
		::String borderLeft; /* REM */ 
		::String borderBottom; /* REM */ 
		::String borderRight; /* REM */ 
		::String borderTop; /* REM */ 
		::String borderStyle; /* REM */ 
		::String borderLeftStyle; /* REM */ 
		::String borderBottomStyle; /* REM */ 
		::String borderRightStyle; /* REM */ 
		::String borderTopStyle; /* REM */ 
		::String borderColor; /* REM */ 
		::String borderLeftColor; /* REM */ 
		::String borderBottomColor; /* REM */ 
		::String borderRightColor; /* REM */ 
		::String borderTopColor; /* REM */ 
		::String borderWidth; /* REM */ 
		::String borderLeftWidth; /* REM */ 
		::String borderBottomWidth; /* REM */ 
		::String borderRightWidth; /* REM */ 
		::String borderTopWidth; /* REM */ 
		::String backgroundAttachment; /* REM */ 
		::String backgroundClip; /* REM */ 
		::String backgroundPosition; /* REM */ 
		::String backgroundSize; /* REM */ 
		::String backgroundOrigin; /* REM */ 
		::String backgroundRepeat; /* REM */ 
		::String backgroundImage; /* REM */ 
		::String backgroundColor; /* REM */ 
		::String background; /* REM */ 
		::String right; /* REM */ 
		::String bottom; /* REM */ 
		::String left; /* REM */ 
		::String top; /* REM */ 
		::String maxWidth; /* REM */ 
		::String minWidth; /* REM */ 
		::String maxHeight; /* REM */ 
		::String minHeight; /* REM */ 
		::String height; /* REM */ 
		::String width; /* REM */ 
		::String paddingBottom; /* REM */ 
		::String paddingTop; /* REM */ 
		::String paddingRight; /* REM */ 
		::String paddingLeft; /* REM */ 
		::String padding; /* REM */ 
		::String marginBottom; /* REM */ 
		::String marginTop; /* REM */ 
		::String marginRight; /* REM */ 
		::String marginLeft; /* REM */ 
		::String margin; /* REM */ 
		::String zIndex; /* REM */ 
		::String clear; /* REM */ 
		::String cssFloat; /* REM */ 
		::String position; /* REM */ 
		::String display; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CSSStyleDeclaration */ 
