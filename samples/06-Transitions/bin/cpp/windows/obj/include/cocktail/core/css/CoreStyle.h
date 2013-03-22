#ifndef INCLUDED_cocktail_core_css_CoreStyle
#define INCLUDED_cocktail_core_css_CoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,animation,Animator)
HX_DECLARE_CLASS3(cocktail,core,animation,Transition)
HX_DECLARE_CLASS3(cocktail,core,animation,TransitionManager)
HX_DECLARE_CLASS3(cocktail,core,css,CSSColorValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,CascadeManager)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,css,InitialStyleDeclaration)
HX_DECLARE_CLASS3(cocktail,core,css,TypedPropertyVO)
HX_DECLARE_CLASS3(cocktail,core,css,UsedValuesVO)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,TransitionEvent)
HX_DECLARE_CLASS3(cocktail,core,font,FontManager)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace css{


class CoreStyle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CoreStyle_obj OBJ_;
		CoreStyle_obj();
		Void __construct(::cocktail::core::html::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< CoreStyle_obj > __new(::cocktail::core::html::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CoreStyle"); }

		virtual ::cocktail::core::css::CSSPropertyValue get_textDecoration( );
		Dynamic get_textDecoration_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_outlineColor( );
		Dynamic get_outlineColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_outlineStyle( );
		Dynamic get_outlineStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_outlineWidth( );
		Dynamic get_outlineWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderLeftStyle( );
		Dynamic get_borderLeftStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderBottomStyle( );
		Dynamic get_borderBottomStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderRightStyle( );
		Dynamic get_borderRightStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderTopStyle( );
		Dynamic get_borderTopStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderLeftColor( );
		Dynamic get_borderLeftColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderBottomColor( );
		Dynamic get_borderBottomColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderRightColor( );
		Dynamic get_borderRightColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderTopColor( );
		Dynamic get_borderTopColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderLeftWidth( );
		Dynamic get_borderLeftWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderBottomWidth( );
		Dynamic get_borderBottomWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderRightWidth( );
		Dynamic get_borderRightWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_borderTopWidth( );
		Dynamic get_borderTopWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transitionDelay( );
		Dynamic get_transitionDelay_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transitionTimingFunction( );
		Dynamic get_transitionTimingFunction_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transitionDuration( );
		Dynamic get_transitionDuration_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transitionProperty( );
		Dynamic get_transitionProperty_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_cursor( );
		Dynamic get_cursor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transform( );
		Dynamic get_transform_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_transformOrigin( );
		Dynamic get_transformOrigin_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_overflowY( );
		Dynamic get_overflowY_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_overflowX( );
		Dynamic get_overflowX_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_visibility( );
		Dynamic get_visibility_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_verticalAlign( );
		Dynamic get_verticalAlign_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_textIndent( );
		Dynamic get_textIndent_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_textAlign( );
		Dynamic get_textAlign_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_whiteSpace( );
		Dynamic get_whiteSpace_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_wordSpacing( );
		Dynamic get_wordSpacing_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_letterSpacing( );
		Dynamic get_letterSpacing_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_textTransform( );
		Dynamic get_textTransform_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_lineHeight( );
		Dynamic get_lineHeight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_color( );
		Dynamic get_color_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_fontVariant( );
		Dynamic get_fontVariant_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_fontFamily( );
		Dynamic get_fontFamily_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_fontStyle( );
		Dynamic get_fontStyle_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_fontWeight( );
		Dynamic get_fontWeight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundPosition( );
		Dynamic get_backgroundPosition_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundSize( );
		Dynamic get_backgroundSize_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundRepeat( );
		Dynamic get_backgroundRepeat_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundAttachment( );
		Dynamic get_backgroundAttachment_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundClip( );
		Dynamic get_backgroundClip_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundOrigin( );
		Dynamic get_backgroundOrigin_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundImage( );
		Dynamic get_backgroundImage_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_backgroundColor( );
		Dynamic get_backgroundColor_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_zIndex( );
		Dynamic get_zIndex_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_clear( );
		Dynamic get_clear_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_cssFloat( );
		Dynamic get_cssFloat_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_position( );
		Dynamic get_position_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_display( );
		Dynamic get_display_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_fontSize( );
		Dynamic get_fontSize_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_right( );
		Dynamic get_right_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_bottom( );
		Dynamic get_bottom_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_left( );
		Dynamic get_left_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_top( );
		Dynamic get_top_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_maxWidth( );
		Dynamic get_maxWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_minWidth( );
		Dynamic get_minWidth_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_maxHeight( );
		Dynamic get_maxHeight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_minHeight( );
		Dynamic get_minHeight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_height( );
		Dynamic get_height_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_width( );
		Dynamic get_width_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_paddingBottom( );
		Dynamic get_paddingBottom_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_paddingTop( );
		Dynamic get_paddingTop_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_paddingRight( );
		Dynamic get_paddingRight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_paddingLeft( );
		Dynamic get_paddingLeft_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_marginBottom( );
		Dynamic get_marginBottom_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_marginTop( );
		Dynamic get_marginTop_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_marginRight( );
		Dynamic get_marginRight_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_marginLeft( );
		Dynamic get_marginLeft_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue get_opacity( );
		Dynamic get_opacity_dyn();

		virtual bool isNone( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isNone_dyn();

		virtual bool isAuto( ::cocktail::core::css::CSSPropertyValue property);
		Dynamic isAuto_dyn();

		virtual ::cocktail::core::css::CSSColorValue getColor( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getColor_dyn();

		virtual Float getAbsoluteLength( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getAbsoluteLength_dyn();

		virtual Array< ::cocktail::core::css::CSSPropertyValue > getList( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getList_dyn();

		virtual Float getNumber( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getNumber_dyn();

		virtual ::cocktail::core::css::CSSKeywordValue getKeyword( ::cocktail::core::css::CSSPropertyValue value);
		Dynamic getKeyword_dyn();

		virtual bool hasNoneOrHiddenBorderStyle( int propertyIndex);
		Dynamic hasNoneOrHiddenBorderStyle_dyn();

		virtual bool isInherited( int propertyIndex);
		Dynamic isInherited_dyn();

		virtual Float getAnimatablePropertyValue( int propertyIndex);
		Dynamic getAnimatablePropertyValue_dyn();

		virtual bool isAnimatable( int propertyIndex);
		Dynamic isAnimatable_dyn();

		virtual ::String getIDLName( int propertyIndex);
		Dynamic getIDLName_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue getComputedOrInitialProperty( int propertyIndex);
		Dynamic getComputedOrInitialProperty_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue getTransitionablePropertyValue( int properyIndex);
		Dynamic getTransitionablePropertyValue_dyn();

		virtual Void onTransitionUpdate( ::cocktail::core::animation::Transition transition);
		Dynamic onTransitionUpdate_dyn();

		virtual Void onTransitionComplete( ::cocktail::core::animation::Transition transition);
		Dynamic onTransitionComplete_dyn();

		virtual Void endPendingAnimation( );
		Dynamic endPendingAnimation_dyn();

		virtual bool startPendingAnimations( );
		Dynamic startPendingAnimations_dyn();

		virtual Void applyNoneOutlineWidth( );
		Dynamic applyNoneOutlineWidth_dyn();

		virtual Void applyHiddenBordersWidth( );
		Dynamic applyHiddenBordersWidth_dyn();

		virtual Void applyPositionFloatAndDisplayRelationship( );
		Dynamic applyPositionFloatAndDisplayRelationship_dyn();

		virtual ::cocktail::core::css::CSSPropertyValue getComputedProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue property,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,::cocktail::core::css::CSSColorValue parentColor);
		Dynamic getComputedProperty_dyn();

		virtual bool setProperty( int propertyIndex,::cocktail::core::css::TypedPropertyVO cascadedProperty,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSColorValue parentColor,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,bool programmaticChange,bool isInherited,bool isInitial);
		Dynamic setProperty_dyn();

		virtual bool setInitialProperty( int propertyIndex);
		Dynamic setInitialProperty_dyn();

		virtual bool cascadeProperty( int propertyIndex,::cocktail::core::css::CSSStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration styleSheetDeclaration,::cocktail::core::css::CSSStyleDeclaration inlineStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,::cocktail::core::css::CSSColorValue parentColor,Float parentFontSize,Float parentXHeight,Float fontSize,Float xHeight,bool programmaticChange,bool hasInlineStyle,bool hasStyleSheetStyle);
		Dynamic cascadeProperty_dyn();

		virtual Void setUsedLineHeight( );
		Dynamic setUsedLineHeight_dyn();

		virtual Void updateCoreStyleAttribute( ::cocktail::core::css::CascadeManager cascadeManager,bool isFirstCascade);
		Dynamic updateCoreStyleAttribute_dyn();

		virtual Void cascade( ::cocktail::core::css::CascadeManager cascadeManager,::cocktail::core::css::InitialStyleDeclaration initialStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration styleSheetDeclaration,::cocktail::core::css::CSSStyleDeclaration inlineStyleDeclaration,::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration,Float parentFontSize,Float parentXHeight,bool programmaticChange);
		Dynamic cascade_dyn();

		virtual Void initAnimator( );
		Dynamic initAnimator_dyn();

		virtual Void initPendingComputedValues( );
		Dynamic initPendingComputedValues_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		bool hasTransitionnableProperties; /* REM */ 
		bool hasAutoMarginBottom; /* REM */ 
		bool hasAutoMarginTop; /* REM */ 
		bool hasAutoMarginRight; /* REM */ 
		bool hasAutoMarginLeft; /* REM */ 
		bool hasAutoRight; /* REM */ 
		bool hasAutoLeft; /* REM */ 
		bool hasAutoBottom; /* REM */ 
		bool hasAutoTop; /* REM */ 
		bool isLeftAligned; /* REM */ 
		bool hasMaxHeight; /* REM */ 
		bool hasMaxWidth; /* REM */ 
		bool hasAutoHeight; /* REM */ 
		bool hasAutoWidth; /* REM */ 
		bool hasNormalWhiteSpace; /* REM */ 
		bool hasPreWrapWhiteSpace; /* REM */ 
		bool hasPreLineWhiteSpace; /* REM */ 
		bool hasNoWrapWhiteSpace; /* REM */ 
		bool hasPreWhiteSpace; /* REM */ 
		bool canHaveClearance; /* REM */ 
		bool isBaselineAligned; /* REM */ 
		bool isBottomAligned; /* REM */ 
		bool isTopAligned; /* REM */ 
		bool hasBackgroundColor; /* REM */ 
		bool hasBackgroundImage; /* REM */ 
		bool isTransparent; /* REM */ 
		bool hasCSSTransform; /* REM */ 
		bool isTransformed; /* REM */ 
		bool hasHiddenOrScrollOverflowY; /* REM */ 
		bool hasHiddenOrScrollOverflowX; /* REM */ 
		bool canAlwaysOverflow; /* REM */ 
		bool isAbsolutelyPositioned; /* REM */ 
		bool isFixedPositioned; /* REM */ 
		bool isRelativePositioned; /* REM */ 
		bool isPositioned; /* REM */ 
		bool isVisible; /* REM */ 
		bool isBlock; /* REM */ 
		bool isInline; /* REM */ 
		bool isInlineBlock; /* REM */ 
		bool isInlineLevel; /* REM */ 
		bool isFloat; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration _initialComputedStyleDeclaration; /* REM */ 
		::cocktail::core::css::InitialStyleDeclaration _initialStyleDeclaration; /* REM */ 
		::cocktail::core::html::HTMLElement htmlElement; /* REM */ 
		bool _isFirstCascade; /* REM */ 
		Array< int > _changedProperties; /* REM */ 
		::cocktail::core::font::FontManager _fontManager; /* REM */ 
		::cocktail::core::font::FontMetricsVO fontMetrics; /* REM */ 
		Array< ::cocktail::core::css::TypedPropertyVO > _pendingComputedValues; /* REM */ 
		Array< ::cocktail::core::event::TransitionEvent > _pendingTransitionEndEvents; /* REM */ 
		::cocktail::core::animation::TransitionManager _transitionManager; /* REM */ 
		::cocktail::core::animation::Animator _animator; /* REM */ 
		::cocktail::core::css::UsedValuesVO usedValues; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration computedValues; /* REM */ 
		::cocktail::core::css::CSSStyleDeclaration specifiedValues; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transitionTimingFunction; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transitionDelay; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transitionDuration; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transitionProperty; /* REM */ 
		::cocktail::core::css::CSSPropertyValue outlineStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue outlineColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue outlineWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue cursor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transform; /* REM */ 
		::cocktail::core::css::CSSPropertyValue transformOrigin; /* REM */ 
		::cocktail::core::css::CSSPropertyValue overflowY; /* REM */ 
		::cocktail::core::css::CSSPropertyValue overflowX; /* REM */ 
		::cocktail::core::css::CSSPropertyValue visibility; /* REM */ 
		::cocktail::core::css::CSSPropertyValue opacity; /* REM */ 
		::cocktail::core::css::CSSPropertyValue textDecoration; /* REM */ 
		::cocktail::core::css::CSSPropertyValue verticalAlign; /* REM */ 
		::cocktail::core::css::CSSPropertyValue textIndent; /* REM */ 
		::cocktail::core::css::CSSPropertyValue textAlign; /* REM */ 
		::cocktail::core::css::CSSPropertyValue whiteSpace; /* REM */ 
		::cocktail::core::css::CSSPropertyValue wordSpacing; /* REM */ 
		::cocktail::core::css::CSSPropertyValue letterSpacing; /* REM */ 
		::cocktail::core::css::CSSPropertyValue textTransform; /* REM */ 
		::cocktail::core::css::CSSPropertyValue lineHeight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue color; /* REM */ 
		::cocktail::core::css::CSSPropertyValue fontVariant; /* REM */ 
		::cocktail::core::css::CSSPropertyValue fontFamily; /* REM */ 
		::cocktail::core::css::CSSPropertyValue fontStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue fontWeight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue fontSize; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderLeftStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderBottomStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderRightStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderTopStyle; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderLeftColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderBottomColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderRightColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderTopColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderLeftWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderBottomWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderRightWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue borderTopWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundAttachment; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundClip; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundPosition; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundSize; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundOrigin; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundRepeat; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundImage; /* REM */ 
		::cocktail::core::css::CSSPropertyValue backgroundColor; /* REM */ 
		::cocktail::core::css::CSSPropertyValue right; /* REM */ 
		::cocktail::core::css::CSSPropertyValue bottom; /* REM */ 
		::cocktail::core::css::CSSPropertyValue left; /* REM */ 
		::cocktail::core::css::CSSPropertyValue top; /* REM */ 
		::cocktail::core::css::CSSPropertyValue maxWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue minWidth; /* REM */ 
		::cocktail::core::css::CSSPropertyValue maxHeight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue minHeight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue height; /* REM */ 
		::cocktail::core::css::CSSPropertyValue width; /* REM */ 
		::cocktail::core::css::CSSPropertyValue paddingBottom; /* REM */ 
		::cocktail::core::css::CSSPropertyValue paddingTop; /* REM */ 
		::cocktail::core::css::CSSPropertyValue paddingRight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue paddingLeft; /* REM */ 
		::cocktail::core::css::CSSPropertyValue marginBottom; /* REM */ 
		::cocktail::core::css::CSSPropertyValue marginTop; /* REM */ 
		::cocktail::core::css::CSSPropertyValue marginRight; /* REM */ 
		::cocktail::core::css::CSSPropertyValue marginLeft; /* REM */ 
		::cocktail::core::css::CSSPropertyValue zIndex; /* REM */ 
		::cocktail::core::css::CSSPropertyValue clear; /* REM */ 
		::cocktail::core::css::CSSPropertyValue cssFloat; /* REM */ 
		::cocktail::core::css::CSSPropertyValue position; /* REM */ 
		::cocktail::core::css::CSSPropertyValue display; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace css

#endif /* INCLUDED_cocktail_core_css_CoreStyle */ 
