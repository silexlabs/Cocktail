#ifndef INCLUDED_core_style_AbstractStyle
#define INCLUDED_core_style_AbstractStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,LayerRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,BackgroundClip)
HX_DECLARE_CLASS2(core,style,BackgroundImage)
HX_DECLARE_CLASS2(core,style,BackgroundOrigin)
HX_DECLARE_CLASS2(core,style,BackgroundSize)
HX_DECLARE_CLASS2(core,style,CSSFloat)
HX_DECLARE_CLASS2(core,style,Clear)
HX_DECLARE_CLASS2(core,style,ConstrainedDimension)
HX_DECLARE_CLASS2(core,style,Cursor)
HX_DECLARE_CLASS2(core,style,Dimension)
HX_DECLARE_CLASS2(core,style,Display)
HX_DECLARE_CLASS2(core,style,FontFamily)
HX_DECLARE_CLASS2(core,style,FontSize)
HX_DECLARE_CLASS2(core,style,FontStyle)
HX_DECLARE_CLASS2(core,style,FontVariant)
HX_DECLARE_CLASS2(core,style,FontWeight)
HX_DECLARE_CLASS2(core,style,LetterSpacing)
HX_DECLARE_CLASS2(core,style,LineHeight)
HX_DECLARE_CLASS2(core,style,Margin)
HX_DECLARE_CLASS2(core,style,Overflow)
HX_DECLARE_CLASS2(core,style,Padding)
HX_DECLARE_CLASS2(core,style,Position)
HX_DECLARE_CLASS2(core,style,PositionOffset)
HX_DECLARE_CLASS2(core,style,TextAlign)
HX_DECLARE_CLASS2(core,style,TextIndent)
HX_DECLARE_CLASS2(core,style,TextTransform)
HX_DECLARE_CLASS2(core,style,Transform)
HX_DECLARE_CLASS2(core,style,VerticalAlign)
HX_DECLARE_CLASS2(core,style,Visibility)
HX_DECLARE_CLASS2(core,style,WhiteSpace)
HX_DECLARE_CLASS2(core,style,WordSpacing)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS3(core,style,formatter,FormattingContext)
HX_DECLARE_CLASS2(core,unit,CSSColor)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace core{
namespace style{


class AbstractStyle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractStyle_obj OBJ_;
		AbstractStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractStyle"); }

		::core::style::Display _display; /* REM */ 
		::core::style::Display display; /* REM */ 
		::core::style::Position _position; /* REM */ 
		::core::style::Position position; /* REM */ 
		::core::style::CSSFloat _cssFloat; /* REM */ 
		::core::style::CSSFloat cssFloat; /* REM */ 
		::core::style::Clear _clear; /* REM */ 
		::core::style::Clear clear; /* REM */ 
		Dynamic _transformOrigin; /* REM */ 
		Dynamic transformOrigin; /* REM */ 
		::core::style::Transform _transform; /* REM */ 
		::core::style::Transform transform; /* REM */ 
		::core::style::Margin _marginLeft; /* REM */ 
		::core::style::Margin marginLeft; /* REM */ 
		::core::style::Margin _marginRight; /* REM */ 
		::core::style::Margin marginRight; /* REM */ 
		::core::style::Margin _marginTop; /* REM */ 
		::core::style::Margin marginTop; /* REM */ 
		::core::style::Margin _marginBottom; /* REM */ 
		::core::style::Margin marginBottom; /* REM */ 
		::core::style::Padding _paddingLeft; /* REM */ 
		::core::style::Padding paddingLeft; /* REM */ 
		::core::style::Padding _paddingRight; /* REM */ 
		::core::style::Padding paddingRight; /* REM */ 
		::core::style::Padding _paddingTop; /* REM */ 
		::core::style::Padding paddingTop; /* REM */ 
		::core::style::Padding _paddingBottom; /* REM */ 
		::core::style::Padding paddingBottom; /* REM */ 
		::core::style::Dimension _width; /* REM */ 
		::core::style::Dimension width; /* REM */ 
		::core::style::Dimension _height; /* REM */ 
		::core::style::Dimension height; /* REM */ 
		::core::style::ConstrainedDimension _minHeight; /* REM */ 
		::core::style::ConstrainedDimension minHeight; /* REM */ 
		::core::style::ConstrainedDimension _maxHeight; /* REM */ 
		::core::style::ConstrainedDimension maxHeight; /* REM */ 
		::core::style::ConstrainedDimension _minWidth; /* REM */ 
		::core::style::ConstrainedDimension minWidth; /* REM */ 
		::core::style::ConstrainedDimension _maxWidth; /* REM */ 
		::core::style::ConstrainedDimension maxWidth; /* REM */ 
		::core::style::PositionOffset _top; /* REM */ 
		::core::style::PositionOffset top; /* REM */ 
		::core::style::PositionOffset _left; /* REM */ 
		::core::style::PositionOffset left; /* REM */ 
		::core::style::PositionOffset _bottom; /* REM */ 
		::core::style::PositionOffset bottom; /* REM */ 
		::core::style::PositionOffset _right; /* REM */ 
		::core::style::PositionOffset right; /* REM */ 
		::core::unit::CSSColor _backgroundColor; /* REM */ 
		::core::unit::CSSColor backgroundColor; /* REM */ 
		Array< ::core::style::BackgroundImage > _backgroundImage; /* REM */ 
		Array< ::core::style::BackgroundImage > backgroundImage; /* REM */ 
		Dynamic _backgroundRepeat; /* REM */ 
		Dynamic backgroundRepeat; /* REM */ 
		Array< ::core::style::BackgroundOrigin > _backgroundOrigin; /* REM */ 
		Array< ::core::style::BackgroundOrigin > backgroundOrigin; /* REM */ 
		Array< ::core::style::BackgroundSize > _backgroundSize; /* REM */ 
		Array< ::core::style::BackgroundSize > backgroundSize; /* REM */ 
		Dynamic _backgroundPosition; /* REM */ 
		Dynamic backgroundPosition; /* REM */ 
		Array< ::core::style::BackgroundClip > _backgroundClip; /* REM */ 
		Array< ::core::style::BackgroundClip > backgroundClip; /* REM */ 
		::core::style::FontSize _fontSize; /* REM */ 
		::core::style::FontSize fontSize; /* REM */ 
		::core::style::FontWeight _fontWeight; /* REM */ 
		::core::style::FontWeight fontWeight; /* REM */ 
		::core::style::FontStyle _fontStyle; /* REM */ 
		::core::style::FontStyle fontStyle; /* REM */ 
		Array< ::core::style::FontFamily > _fontFamily; /* REM */ 
		Array< ::core::style::FontFamily > fontFamily; /* REM */ 
		::core::style::FontVariant _fontVariant; /* REM */ 
		::core::style::FontVariant fontVariant; /* REM */ 
		::core::unit::CSSColor _color; /* REM */ 
		::core::unit::CSSColor color; /* REM */ 
		::core::style::LineHeight _lineHeight; /* REM */ 
		::core::style::LineHeight lineHeight; /* REM */ 
		::core::style::TextTransform _textTransform; /* REM */ 
		::core::style::TextTransform textTransform; /* REM */ 
		::core::style::LetterSpacing _letterSpacing; /* REM */ 
		::core::style::LetterSpacing letterSpacing; /* REM */ 
		::core::style::WordSpacing _wordSpacing; /* REM */ 
		::core::style::WordSpacing wordSpacing; /* REM */ 
		::core::style::WhiteSpace _whiteSpace; /* REM */ 
		::core::style::WhiteSpace whiteSpace; /* REM */ 
		::core::style::TextAlign _textAlign; /* REM */ 
		::core::style::TextAlign textAlign; /* REM */ 
		::core::style::TextIndent _textIndent; /* REM */ 
		::core::style::TextIndent textIndent; /* REM */ 
		::core::style::VerticalAlign _verticalAlign; /* REM */ 
		::core::style::VerticalAlign verticalAlign; /* REM */ 
		double _opacity; /* REM */ 
		double opacity; /* REM */ 
		::core::style::Visibility _visibility; /* REM */ 
		::core::style::Visibility visibility; /* REM */ 
		::core::style::Overflow _overflowX; /* REM */ 
		::core::style::Overflow overflowX; /* REM */ 
		::core::style::Overflow _overflowY; /* REM */ 
		::core::style::Overflow overflowY; /* REM */ 
		::core::style::Cursor _cursor; /* REM */ 
		::core::style::Cursor cursor; /* REM */ 
		Dynamic _computedStyle; /* REM */ 
		Dynamic computedStyle; /* REM */ 
		::port::flash_player::HTMLElement _htmlElement; /* REM */ 
		::port::flash_player::HTMLElement htmlElement; /* REM */ 
		Dynamic _fontMetrics; /* REM */ 
		Dynamic fontMetrics; /* REM */ 
		bool _isDirty; /* REM */ 
		::core::renderer::ElementRenderer _elementRenderer; /* REM */ 
		::core::renderer::ElementRenderer elementRenderer; /* REM */ 
		virtual Void initDefaultStyleValues( );
		Dynamic initDefaultStyleValues_dyn();

		virtual Void initComputedStyles( );
		Dynamic initComputedStyles_dyn();

		virtual Void applyDefaultHTMLStyles( );
		Dynamic applyDefaultHTMLStyles_dyn();

		virtual ::core::renderer::ElementRenderer createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual ::core::renderer::LayerRenderer getLayerRenderer( ::core::renderer::ElementRenderer elementRenderer,::core::renderer::ElementRenderer parentElementRenderer);
		Dynamic getLayerRenderer_dyn();

		virtual Void layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData);
		Dynamic layout_dyn();

		virtual Void flow( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext,::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic flow_dyn();

		virtual ::core::renderer::ElementRenderer positionElement( Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic staticPosition);
		Dynamic positionElement_dyn();

		virtual Void scheduleLayout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic scheduleLayout_dyn();

		virtual Void flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext);
		Dynamic flowChildren_dyn();

		virtual Void insertHTMLElement( ::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic insertHTMLElement_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void invalidateText( );
		Dynamic invalidateText_dyn();

		virtual Void invalidatePositionOffset( );
		Dynamic invalidatePositionOffset_dyn();

		virtual Void invalidateMargin( );
		Dynamic invalidateMargin_dyn();

		virtual bool isParentDirty( );
		Dynamic isParentDirty_dyn();

		virtual Void computeDisplayStyles( );
		Dynamic computeDisplayStyles_dyn();

		virtual Void computeBackgroundStyles( );
		Dynamic computeBackgroundStyles_dyn();

		virtual Void computeHTMLElementStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		Dynamic computeHTMLElementStyles_dyn();

		virtual Void computeVisualEffectStyles( );
		Dynamic computeVisualEffectStyles_dyn();

		virtual Void computeTextAndFontStyles( Dynamic containingHTMLElementData,Dynamic containingHTMLElementFontMetricsData);
		Dynamic computeTextAndFontStyles_dyn();

		virtual Void computeBoxModelStyles( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData);
		Dynamic computeBoxModelStyles_dyn();

		virtual ::core::style::computer::boxComputers::BoxStylesComputer getBoxStylesComputer( );
		Dynamic getBoxStylesComputer_dyn();

		virtual Dynamic getContainingHTMLElementData( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData);
		Dynamic getContainingHTMLElementData_dyn();

		virtual bool isFloat( );
		Dynamic isFloat_dyn();

		virtual bool isPositioned( );
		Dynamic isPositioned_dyn();

		virtual bool isRelativePositioned( );
		Dynamic isRelativePositioned_dyn();

		virtual bool childrenInline( );
		Dynamic childrenInline_dyn();

		virtual bool isInlineLevel( );
		Dynamic isInlineLevel_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

		virtual ::port::flash_player::HTMLElement getFirstPositionedAncestor( );
		Dynamic getFirstPositionedAncestor_dyn();

		virtual bool isClear( );
		Dynamic isClear_dyn();

		virtual bool isNotDisplayed( );
		Dynamic isNotDisplayed_dyn();

		virtual Dynamic getFirstPositionedAncestorData( );
		Dynamic getFirstPositionedAncestorData_dyn();

		virtual Dynamic getWindowData( );
		Dynamic getWindowData_dyn();

		virtual ::core::renderer::ElementRenderer getElementRenderer( );
		Dynamic getElementRenderer_dyn();

		virtual Dynamic getFontMetricsData( );
		Dynamic getFontMetricsData_dyn();

		virtual Dynamic getComputedStyle( );
		Dynamic getComputedStyle_dyn();

		virtual Dynamic setComputedStyle( Dynamic value);
		Dynamic setComputedStyle_dyn();

		virtual ::port::flash_player::HTMLElement get_htmlElement( );
		Dynamic get_htmlElement_dyn();

		virtual ::core::style::Dimension setWidth( ::core::style::Dimension value);
		Dynamic setWidth_dyn();

		virtual ::core::style::Margin setMarginLeft( ::core::style::Margin value);
		Dynamic setMarginLeft_dyn();

		virtual ::core::style::Margin setMarginRight( ::core::style::Margin value);
		Dynamic setMarginRight_dyn();

		virtual ::core::style::Margin setMarginTop( ::core::style::Margin value);
		Dynamic setMarginTop_dyn();

		virtual ::core::style::Margin setMarginBottom( ::core::style::Margin value);
		Dynamic setMarginBottom_dyn();

		virtual ::core::style::Padding setPaddingLeft( ::core::style::Padding value);
		Dynamic setPaddingLeft_dyn();

		virtual ::core::style::Padding setPaddingRight( ::core::style::Padding value);
		Dynamic setPaddingRight_dyn();

		virtual ::core::style::Padding setPaddingTop( ::core::style::Padding value);
		Dynamic setPaddingTop_dyn();

		virtual ::core::style::Padding setPaddingBottom( ::core::style::Padding value);
		Dynamic setPaddingBottom_dyn();

		virtual ::core::style::Display setDisplay( ::core::style::Display value);
		Dynamic setDisplay_dyn();

		virtual ::core::style::Position setPosition( ::core::style::Position value);
		Dynamic setPosition_dyn();

		virtual ::core::style::Dimension setHeight( ::core::style::Dimension value);
		Dynamic setHeight_dyn();

		virtual ::core::style::ConstrainedDimension setMinHeight( ::core::style::ConstrainedDimension value);
		Dynamic setMinHeight_dyn();

		virtual ::core::style::ConstrainedDimension setMaxHeight( ::core::style::ConstrainedDimension value);
		Dynamic setMaxHeight_dyn();

		virtual ::core::style::ConstrainedDimension setMinWidth( ::core::style::ConstrainedDimension value);
		Dynamic setMinWidth_dyn();

		virtual ::core::style::ConstrainedDimension setMaxWidth( ::core::style::ConstrainedDimension value);
		Dynamic setMaxWidth_dyn();

		virtual ::core::style::PositionOffset setTop( ::core::style::PositionOffset value);
		Dynamic setTop_dyn();

		virtual ::core::style::PositionOffset setLeft( ::core::style::PositionOffset value);
		Dynamic setLeft_dyn();

		virtual ::core::style::PositionOffset setBottom( ::core::style::PositionOffset value);
		Dynamic setBottom_dyn();

		virtual ::core::style::PositionOffset setRight( ::core::style::PositionOffset value);
		Dynamic setRight_dyn();

		virtual ::core::style::CSSFloat setCSSFloat( ::core::style::CSSFloat value);
		Dynamic setCSSFloat_dyn();

		virtual ::core::style::Clear setClear( ::core::style::Clear value);
		Dynamic setClear_dyn();

		virtual ::core::style::FontSize setFontSize( ::core::style::FontSize value);
		Dynamic setFontSize_dyn();

		virtual ::core::style::FontWeight setFontWeight( ::core::style::FontWeight value);
		Dynamic setFontWeight_dyn();

		virtual ::core::style::FontStyle setFontStyle( ::core::style::FontStyle value);
		Dynamic setFontStyle_dyn();

		virtual Array< ::core::style::FontFamily > setFontFamily( Array< ::core::style::FontFamily > value);
		Dynamic setFontFamily_dyn();

		virtual ::core::style::FontVariant setFontVariant( ::core::style::FontVariant value);
		Dynamic setFontVariant_dyn();

		virtual ::core::style::TextTransform setTextTransform( ::core::style::TextTransform value);
		Dynamic setTextTransform_dyn();

		virtual ::core::style::LetterSpacing setLetterSpacing( ::core::style::LetterSpacing value);
		Dynamic setLetterSpacing_dyn();

		virtual ::core::style::WordSpacing setWordSpacing( ::core::style::WordSpacing value);
		Dynamic setWordSpacing_dyn();

		virtual ::core::style::LineHeight setLineHeight( ::core::style::LineHeight value);
		Dynamic setLineHeight_dyn();

		virtual ::core::unit::CSSColor setColor( ::core::unit::CSSColor value);
		Dynamic setColor_dyn();

		virtual ::core::style::VerticalAlign setVerticalAlign( ::core::style::VerticalAlign value);
		Dynamic setVerticalAlign_dyn();

		virtual ::core::style::TextIndent setTextIndent( ::core::style::TextIndent value);
		Dynamic setTextIndent_dyn();

		virtual ::core::style::WhiteSpace setWhiteSpace( ::core::style::WhiteSpace value);
		Dynamic setWhiteSpace_dyn();

		virtual ::core::style::TextAlign setTextAlign( ::core::style::TextAlign value);
		Dynamic setTextAlign_dyn();

		virtual double setOpacity( double value);
		Dynamic setOpacity_dyn();

		virtual ::core::style::Visibility setVisibility( ::core::style::Visibility value);
		Dynamic setVisibility_dyn();

		virtual Dynamic setTransformOrigin( Dynamic value);
		Dynamic setTransformOrigin_dyn();

		virtual ::core::style::Transform setTransform( ::core::style::Transform value);
		Dynamic setTransform_dyn();

		virtual ::core::style::Overflow setOverflowX( ::core::style::Overflow value);
		Dynamic setOverflowX_dyn();

		virtual ::core::style::Overflow setOverflowY( ::core::style::Overflow value);
		Dynamic setOverflowY_dyn();

		virtual double getOpacity( );
		Dynamic getOpacity_dyn();

		virtual ::core::style::Visibility getVisibility( );
		Dynamic getVisibility_dyn();

		virtual ::core::style::Margin getMarginLeft( );
		Dynamic getMarginLeft_dyn();

		virtual ::core::style::Margin getMarginRight( );
		Dynamic getMarginRight_dyn();

		virtual ::core::style::Margin getMarginTop( );
		Dynamic getMarginTop_dyn();

		virtual ::core::style::Margin getMarginBottom( );
		Dynamic getMarginBottom_dyn();

		virtual ::core::style::Padding getPaddingLeft( );
		Dynamic getPaddingLeft_dyn();

		virtual ::core::style::Padding getPaddingRight( );
		Dynamic getPaddingRight_dyn();

		virtual ::core::style::Padding getPaddingTop( );
		Dynamic getPaddingTop_dyn();

		virtual ::core::style::Padding getPaddingBottom( );
		Dynamic getPaddingBottom_dyn();

		virtual ::core::style::Display getDisplay( );
		Dynamic getDisplay_dyn();

		virtual ::core::style::Position getPosition( );
		Dynamic getPosition_dyn();

		virtual ::core::style::Dimension getWidth( );
		Dynamic getWidth_dyn();

		virtual ::core::style::Dimension getHeight( );
		Dynamic getHeight_dyn();

		virtual ::core::style::ConstrainedDimension getMinHeight( );
		Dynamic getMinHeight_dyn();

		virtual ::core::style::ConstrainedDimension getMaxHeight( );
		Dynamic getMaxHeight_dyn();

		virtual ::core::style::ConstrainedDimension getMinWidth( );
		Dynamic getMinWidth_dyn();

		virtual ::core::style::ConstrainedDimension getMaxWidth( );
		Dynamic getMaxWidth_dyn();

		virtual ::core::style::PositionOffset getTop( );
		Dynamic getTop_dyn();

		virtual ::core::style::PositionOffset getLeft( );
		Dynamic getLeft_dyn();

		virtual ::core::style::PositionOffset getBottom( );
		Dynamic getBottom_dyn();

		virtual ::core::style::PositionOffset getRight( );
		Dynamic getRight_dyn();

		virtual ::core::style::CSSFloat getCSSFloat( );
		Dynamic getCSSFloat_dyn();

		virtual ::core::style::Clear getClear( );
		Dynamic getClear_dyn();

		virtual ::core::style::FontSize getFontSize( );
		Dynamic getFontSize_dyn();

		virtual ::core::style::FontWeight getFontWeight( );
		Dynamic getFontWeight_dyn();

		virtual ::core::style::FontStyle getFontStyle( );
		Dynamic getFontStyle_dyn();

		virtual Array< ::core::style::FontFamily > getFontFamily( );
		Dynamic getFontFamily_dyn();

		virtual ::core::style::FontVariant getFontVariant( );
		Dynamic getFontVariant_dyn();

		virtual ::core::style::TextTransform getTextTransform( );
		Dynamic getTextTransform_dyn();

		virtual ::core::style::LetterSpacing getLetterSpacing( );
		Dynamic getLetterSpacing_dyn();

		virtual ::core::unit::CSSColor getColor( );
		Dynamic getColor_dyn();

		virtual ::core::style::WordSpacing getWordSpacing( );
		Dynamic getWordSpacing_dyn();

		virtual ::core::style::LineHeight getLineHeight( );
		Dynamic getLineHeight_dyn();

		virtual ::core::style::VerticalAlign getVerticalAlign( );
		Dynamic getVerticalAlign_dyn();

		virtual ::core::style::TextIndent getTextIndent( );
		Dynamic getTextIndent_dyn();

		virtual ::core::style::WhiteSpace getWhiteSpace( );
		Dynamic getWhiteSpace_dyn();

		virtual ::core::style::TextAlign getTextAlign( );
		Dynamic getTextAlign_dyn();

		virtual ::core::style::Transform getTransform( );
		Dynamic getTransform_dyn();

		virtual Dynamic getTransformOrigin( );
		Dynamic getTransformOrigin_dyn();

		virtual ::core::unit::CSSColor setBackgroundColor( ::core::unit::CSSColor value);
		Dynamic setBackgroundColor_dyn();

		virtual ::core::unit::CSSColor getBackgroundColor( );
		Dynamic getBackgroundColor_dyn();

		virtual Array< ::core::style::BackgroundImage > setBackgroundImage( Array< ::core::style::BackgroundImage > value);
		Dynamic setBackgroundImage_dyn();

		virtual Array< ::core::style::BackgroundImage > getBackgroundImage( );
		Dynamic getBackgroundImage_dyn();

		virtual Dynamic setBackgroundRepeat( Dynamic value);
		Dynamic setBackgroundRepeat_dyn();

		virtual Dynamic getBackgroundRepeat( );
		Dynamic getBackgroundRepeat_dyn();

		virtual Array< ::core::style::BackgroundSize > setBackgroundSize( Array< ::core::style::BackgroundSize > value);
		Dynamic setBackgroundSize_dyn();

		virtual Array< ::core::style::BackgroundSize > getBackgroundSize( );
		Dynamic getBackgroundSize_dyn();

		virtual Array< ::core::style::BackgroundClip > setBackgroundClip( Array< ::core::style::BackgroundClip > value);
		Dynamic setBackgroundClip_dyn();

		virtual Array< ::core::style::BackgroundClip > getBackgroundClip( );
		Dynamic getBackgroundClip_dyn();

		virtual Dynamic setBackgroundPosition( Dynamic value);
		Dynamic setBackgroundPosition_dyn();

		virtual Dynamic getBackgroundPosition( );
		Dynamic getBackgroundPosition_dyn();

		virtual Array< ::core::style::BackgroundOrigin > setBackgroundOrigin( Array< ::core::style::BackgroundOrigin > value);
		Dynamic setBackgroundOrigin_dyn();

		virtual Array< ::core::style::BackgroundOrigin > getBackgroundOrigin( );
		Dynamic getBackgroundOrigin_dyn();

		virtual ::core::style::Overflow getOverflowX( );
		Dynamic getOverflowX_dyn();

		virtual ::core::style::Overflow getOverflowY( );
		Dynamic getOverflowY_dyn();

		virtual ::core::style::Cursor setCursor( ::core::style::Cursor value);
		Dynamic setCursor_dyn();

		virtual ::core::style::Cursor getCursor( );
		Dynamic getCursor_dyn();

		static Dynamic getDefaultStyle( );
		static Dynamic getDefaultStyle_dyn();

};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_AbstractStyle */ 
