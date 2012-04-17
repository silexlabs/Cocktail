#ifndef INCLUDED_cocktail_core_style_CoreStyle
#define INCLUDED_cocktail_core_style_CoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundClip)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundImage)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundOrigin)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSize)
HX_DECLARE_CLASS3(cocktail,core,style,CSSFloat)
HX_DECLARE_CLASS3(cocktail,core,style,Clear)
HX_DECLARE_CLASS3(cocktail,core,style,ConstrainedDimension)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,Cursor)
HX_DECLARE_CLASS3(cocktail,core,style,Dimension)
HX_DECLARE_CLASS3(cocktail,core,style,Display)
HX_DECLARE_CLASS3(cocktail,core,style,FontSize)
HX_DECLARE_CLASS3(cocktail,core,style,FontStyle)
HX_DECLARE_CLASS3(cocktail,core,style,FontVariant)
HX_DECLARE_CLASS3(cocktail,core,style,FontWeight)
HX_DECLARE_CLASS3(cocktail,core,style,LetterSpacing)
HX_DECLARE_CLASS3(cocktail,core,style,LineHeight)
HX_DECLARE_CLASS3(cocktail,core,style,Margin)
HX_DECLARE_CLASS3(cocktail,core,style,Overflow)
HX_DECLARE_CLASS3(cocktail,core,style,Padding)
HX_DECLARE_CLASS3(cocktail,core,style,Position)
HX_DECLARE_CLASS3(cocktail,core,style,PositionOffset)
HX_DECLARE_CLASS3(cocktail,core,style,TextAlign)
HX_DECLARE_CLASS3(cocktail,core,style,TextIndent)
HX_DECLARE_CLASS3(cocktail,core,style,TextTransform)
HX_DECLARE_CLASS3(cocktail,core,style,Transform)
HX_DECLARE_CLASS3(cocktail,core,style,VerticalAlign)
HX_DECLARE_CLASS3(cocktail,core,style,Visibility)
HX_DECLARE_CLASS3(cocktail,core,style,WhiteSpace)
HX_DECLARE_CLASS3(cocktail,core,style,WordSpacing)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
HX_DECLARE_CLASS3(cocktail,core,unit,CSSColor)
namespace cocktail{
namespace core{
namespace style{


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
		::String __ToString() const { return HX_CSTRING("CoreStyle"); }

		::cocktail::core::style::Display _display; /* REM */ 
		::cocktail::core::style::Display display; /* REM */ 
		::cocktail::core::style::Position _position; /* REM */ 
		::cocktail::core::style::Position position; /* REM */ 
		::cocktail::core::style::CSSFloat _cssFloat; /* REM */ 
		::cocktail::core::style::CSSFloat cssFloat; /* REM */ 
		::cocktail::core::style::Clear _clear; /* REM */ 
		::cocktail::core::style::Clear clear; /* REM */ 
		Dynamic _transformOrigin; /* REM */ 
		Dynamic transformOrigin; /* REM */ 
		::cocktail::core::style::Transform _transform; /* REM */ 
		::cocktail::core::style::Transform transform; /* REM */ 
		::cocktail::core::style::Margin _marginLeft; /* REM */ 
		::cocktail::core::style::Margin marginLeft; /* REM */ 
		::cocktail::core::style::Margin _marginRight; /* REM */ 
		::cocktail::core::style::Margin marginRight; /* REM */ 
		::cocktail::core::style::Margin _marginTop; /* REM */ 
		::cocktail::core::style::Margin marginTop; /* REM */ 
		::cocktail::core::style::Margin _marginBottom; /* REM */ 
		::cocktail::core::style::Margin marginBottom; /* REM */ 
		::cocktail::core::style::Padding _paddingLeft; /* REM */ 
		::cocktail::core::style::Padding paddingLeft; /* REM */ 
		::cocktail::core::style::Padding _paddingRight; /* REM */ 
		::cocktail::core::style::Padding paddingRight; /* REM */ 
		::cocktail::core::style::Padding _paddingTop; /* REM */ 
		::cocktail::core::style::Padding paddingTop; /* REM */ 
		::cocktail::core::style::Padding _paddingBottom; /* REM */ 
		::cocktail::core::style::Padding paddingBottom; /* REM */ 
		::cocktail::core::style::Dimension _width; /* REM */ 
		::cocktail::core::style::Dimension width; /* REM */ 
		::cocktail::core::style::Dimension _height; /* REM */ 
		::cocktail::core::style::Dimension height; /* REM */ 
		::cocktail::core::style::ConstrainedDimension _minHeight; /* REM */ 
		::cocktail::core::style::ConstrainedDimension minHeight; /* REM */ 
		::cocktail::core::style::ConstrainedDimension _maxHeight; /* REM */ 
		::cocktail::core::style::ConstrainedDimension maxHeight; /* REM */ 
		::cocktail::core::style::ConstrainedDimension _minWidth; /* REM */ 
		::cocktail::core::style::ConstrainedDimension minWidth; /* REM */ 
		::cocktail::core::style::ConstrainedDimension _maxWidth; /* REM */ 
		::cocktail::core::style::ConstrainedDimension maxWidth; /* REM */ 
		::cocktail::core::style::PositionOffset _top; /* REM */ 
		::cocktail::core::style::PositionOffset top; /* REM */ 
		::cocktail::core::style::PositionOffset _left; /* REM */ 
		::cocktail::core::style::PositionOffset left; /* REM */ 
		::cocktail::core::style::PositionOffset _bottom; /* REM */ 
		::cocktail::core::style::PositionOffset bottom; /* REM */ 
		::cocktail::core::style::PositionOffset _right; /* REM */ 
		::cocktail::core::style::PositionOffset right; /* REM */ 
		::cocktail::core::unit::CSSColor _backgroundColor; /* REM */ 
		::cocktail::core::unit::CSSColor backgroundColor; /* REM */ 
		Array< ::cocktail::core::style::BackgroundImage > _backgroundImage; /* REM */ 
		Array< ::cocktail::core::style::BackgroundImage > backgroundImage; /* REM */ 
		Dynamic _backgroundRepeat; /* REM */ 
		Dynamic backgroundRepeat; /* REM */ 
		Array< ::cocktail::core::style::BackgroundOrigin > _backgroundOrigin; /* REM */ 
		Array< ::cocktail::core::style::BackgroundOrigin > backgroundOrigin; /* REM */ 
		Array< ::cocktail::core::style::BackgroundSize > _backgroundSize; /* REM */ 
		Array< ::cocktail::core::style::BackgroundSize > backgroundSize; /* REM */ 
		Dynamic _backgroundPosition; /* REM */ 
		Dynamic backgroundPosition; /* REM */ 
		Array< ::cocktail::core::style::BackgroundClip > _backgroundClip; /* REM */ 
		Array< ::cocktail::core::style::BackgroundClip > backgroundClip; /* REM */ 
		::cocktail::core::style::FontSize _fontSize; /* REM */ 
		::cocktail::core::style::FontSize fontSize; /* REM */ 
		::cocktail::core::style::FontWeight _fontWeight; /* REM */ 
		::cocktail::core::style::FontWeight fontWeight; /* REM */ 
		::cocktail::core::style::FontStyle _fontStyle; /* REM */ 
		::cocktail::core::style::FontStyle fontStyle; /* REM */ 
		Array< ::String > _fontFamily; /* REM */ 
		Array< ::String > fontFamily; /* REM */ 
		::cocktail::core::style::FontVariant _fontVariant; /* REM */ 
		::cocktail::core::style::FontVariant fontVariant; /* REM */ 
		::cocktail::core::unit::CSSColor _color; /* REM */ 
		::cocktail::core::unit::CSSColor color; /* REM */ 
		::cocktail::core::style::LineHeight _lineHeight; /* REM */ 
		::cocktail::core::style::LineHeight lineHeight; /* REM */ 
		::cocktail::core::style::TextTransform _textTransform; /* REM */ 
		::cocktail::core::style::TextTransform textTransform; /* REM */ 
		::cocktail::core::style::LetterSpacing _letterSpacing; /* REM */ 
		::cocktail::core::style::LetterSpacing letterSpacing; /* REM */ 
		::cocktail::core::style::WordSpacing _wordSpacing; /* REM */ 
		::cocktail::core::style::WordSpacing wordSpacing; /* REM */ 
		::cocktail::core::style::WhiteSpace _whiteSpace; /* REM */ 
		::cocktail::core::style::WhiteSpace whiteSpace; /* REM */ 
		::cocktail::core::style::TextAlign _textAlign; /* REM */ 
		::cocktail::core::style::TextAlign textAlign; /* REM */ 
		::cocktail::core::style::TextIndent _textIndent; /* REM */ 
		::cocktail::core::style::TextIndent textIndent; /* REM */ 
		::cocktail::core::style::VerticalAlign _verticalAlign; /* REM */ 
		::cocktail::core::style::VerticalAlign verticalAlign; /* REM */ 
		double _opacity; /* REM */ 
		double opacity; /* REM */ 
		::cocktail::core::style::Visibility _visibility; /* REM */ 
		::cocktail::core::style::Visibility visibility; /* REM */ 
		::cocktail::core::style::Overflow _overflowX; /* REM */ 
		::cocktail::core::style::Overflow overflowX; /* REM */ 
		::cocktail::core::style::Overflow _overflowY; /* REM */ 
		::cocktail::core::style::Overflow overflowY; /* REM */ 
		::cocktail::core::style::Cursor _cursor; /* REM */ 
		::cocktail::core::style::Cursor cursor; /* REM */ 
		Dynamic _computedStyle; /* REM */ 
		Dynamic computedStyle; /* REM */ 
		::cocktail::core::html::HTMLElement _htmlElement; /* REM */ 
		::cocktail::core::html::HTMLElement htmlElement; /* REM */ 
		Dynamic _fontMetrics; /* REM */ 
		Dynamic fontMetrics; /* REM */ 
		bool _isDirty; /* REM */ 
		::cocktail::core::renderer::ElementRenderer _elementRenderer; /* REM */ 
		::cocktail::core::renderer::ElementRenderer elementRenderer; /* REM */ 
		virtual Void initDefaultStyleValues( );
		Dynamic initDefaultStyleValues_dyn();

		virtual Void initComputedStyles( );
		Dynamic initComputedStyles_dyn();

		virtual Void applyDefaultHTMLStyles( );
		Dynamic applyDefaultHTMLStyles_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual ::cocktail::core::renderer::LayerRenderer getLayerRenderer( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::renderer::ElementRenderer parentElementRenderer);
		Dynamic getLayerRenderer_dyn();

		virtual Void flow( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext,::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic flow_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer positionElement( Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic staticPosition);
		Dynamic positionElement_dyn();

		virtual Void flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext);
		Dynamic flowChildren_dyn();

		virtual Void insertHTMLElement( ::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic insertHTMLElement_dyn();

		virtual Void invalidate( Dynamic immediate);
		Dynamic invalidate_dyn();

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

		virtual ::cocktail::core::style::computer::boxComputers::BoxStylesComputer getBoxStylesComputer( );
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

		virtual ::cocktail::core::html::HTMLElement getFirstPositionedAncestor( );
		Dynamic getFirstPositionedAncestor_dyn();

		virtual bool isOffsetParent( );
		Dynamic isOffsetParent_dyn();

		virtual bool isClear( );
		Dynamic isClear_dyn();

		virtual bool isDisplayed( );
		Dynamic isDisplayed_dyn();

		virtual Dynamic getFirstPositionedAncestorData( );
		Dynamic getFirstPositionedAncestorData_dyn();

		virtual Dynamic getWindowData( );
		Dynamic getWindowData_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer getElementRenderer( );
		Dynamic getElementRenderer_dyn();

		virtual Dynamic getFontMetricsData( );
		Dynamic getFontMetricsData_dyn();

		virtual Dynamic getComputedStyle( );
		Dynamic getComputedStyle_dyn();

		virtual Dynamic setComputedStyle( Dynamic value);
		Dynamic setComputedStyle_dyn();

		virtual ::cocktail::core::html::HTMLElement get_htmlElement( );
		Dynamic get_htmlElement_dyn();

		virtual ::cocktail::core::style::Dimension setWidth( ::cocktail::core::style::Dimension value);
		Dynamic setWidth_dyn();

		virtual ::cocktail::core::style::Margin setMarginLeft( ::cocktail::core::style::Margin value);
		Dynamic setMarginLeft_dyn();

		virtual ::cocktail::core::style::Margin setMarginRight( ::cocktail::core::style::Margin value);
		Dynamic setMarginRight_dyn();

		virtual ::cocktail::core::style::Margin setMarginTop( ::cocktail::core::style::Margin value);
		Dynamic setMarginTop_dyn();

		virtual ::cocktail::core::style::Margin setMarginBottom( ::cocktail::core::style::Margin value);
		Dynamic setMarginBottom_dyn();

		virtual ::cocktail::core::style::Padding setPaddingLeft( ::cocktail::core::style::Padding value);
		Dynamic setPaddingLeft_dyn();

		virtual ::cocktail::core::style::Padding setPaddingRight( ::cocktail::core::style::Padding value);
		Dynamic setPaddingRight_dyn();

		virtual ::cocktail::core::style::Padding setPaddingTop( ::cocktail::core::style::Padding value);
		Dynamic setPaddingTop_dyn();

		virtual ::cocktail::core::style::Padding setPaddingBottom( ::cocktail::core::style::Padding value);
		Dynamic setPaddingBottom_dyn();

		virtual ::cocktail::core::style::Display setDisplay( ::cocktail::core::style::Display value);
		Dynamic setDisplay_dyn();

		virtual ::cocktail::core::style::Position setPosition( ::cocktail::core::style::Position value);
		Dynamic setPosition_dyn();

		virtual ::cocktail::core::style::Dimension setHeight( ::cocktail::core::style::Dimension value);
		Dynamic setHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension setMinHeight( ::cocktail::core::style::ConstrainedDimension value);
		Dynamic setMinHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension setMaxHeight( ::cocktail::core::style::ConstrainedDimension value);
		Dynamic setMaxHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension setMinWidth( ::cocktail::core::style::ConstrainedDimension value);
		Dynamic setMinWidth_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension setMaxWidth( ::cocktail::core::style::ConstrainedDimension value);
		Dynamic setMaxWidth_dyn();

		virtual ::cocktail::core::style::PositionOffset setTop( ::cocktail::core::style::PositionOffset value);
		Dynamic setTop_dyn();

		virtual ::cocktail::core::style::PositionOffset setLeft( ::cocktail::core::style::PositionOffset value);
		Dynamic setLeft_dyn();

		virtual ::cocktail::core::style::PositionOffset setBottom( ::cocktail::core::style::PositionOffset value);
		Dynamic setBottom_dyn();

		virtual ::cocktail::core::style::PositionOffset setRight( ::cocktail::core::style::PositionOffset value);
		Dynamic setRight_dyn();

		virtual ::cocktail::core::style::CSSFloat setCSSFloat( ::cocktail::core::style::CSSFloat value);
		Dynamic setCSSFloat_dyn();

		virtual ::cocktail::core::style::Clear setClear( ::cocktail::core::style::Clear value);
		Dynamic setClear_dyn();

		virtual ::cocktail::core::style::FontSize setFontSize( ::cocktail::core::style::FontSize value);
		Dynamic setFontSize_dyn();

		virtual ::cocktail::core::style::FontWeight setFontWeight( ::cocktail::core::style::FontWeight value);
		Dynamic setFontWeight_dyn();

		virtual ::cocktail::core::style::FontStyle setFontStyle( ::cocktail::core::style::FontStyle value);
		Dynamic setFontStyle_dyn();

		virtual Array< ::String > setFontFamily( Array< ::String > value);
		Dynamic setFontFamily_dyn();

		virtual ::cocktail::core::style::FontVariant setFontVariant( ::cocktail::core::style::FontVariant value);
		Dynamic setFontVariant_dyn();

		virtual ::cocktail::core::style::TextTransform setTextTransform( ::cocktail::core::style::TextTransform value);
		Dynamic setTextTransform_dyn();

		virtual ::cocktail::core::style::LetterSpacing setLetterSpacing( ::cocktail::core::style::LetterSpacing value);
		Dynamic setLetterSpacing_dyn();

		virtual ::cocktail::core::style::WordSpacing setWordSpacing( ::cocktail::core::style::WordSpacing value);
		Dynamic setWordSpacing_dyn();

		virtual ::cocktail::core::style::LineHeight setLineHeight( ::cocktail::core::style::LineHeight value);
		Dynamic setLineHeight_dyn();

		virtual ::cocktail::core::unit::CSSColor setColor( ::cocktail::core::unit::CSSColor value);
		Dynamic setColor_dyn();

		virtual ::cocktail::core::style::VerticalAlign setVerticalAlign( ::cocktail::core::style::VerticalAlign value);
		Dynamic setVerticalAlign_dyn();

		virtual ::cocktail::core::style::TextIndent setTextIndent( ::cocktail::core::style::TextIndent value);
		Dynamic setTextIndent_dyn();

		virtual ::cocktail::core::style::WhiteSpace setWhiteSpace( ::cocktail::core::style::WhiteSpace value);
		Dynamic setWhiteSpace_dyn();

		virtual ::cocktail::core::style::TextAlign setTextAlign( ::cocktail::core::style::TextAlign value);
		Dynamic setTextAlign_dyn();

		virtual double setOpacity( double value);
		Dynamic setOpacity_dyn();

		virtual ::cocktail::core::style::Visibility setVisibility( ::cocktail::core::style::Visibility value);
		Dynamic setVisibility_dyn();

		virtual Dynamic setTransformOrigin( Dynamic value);
		Dynamic setTransformOrigin_dyn();

		virtual ::cocktail::core::style::Transform setTransform( ::cocktail::core::style::Transform value);
		Dynamic setTransform_dyn();

		virtual ::cocktail::core::style::Overflow setOverflowX( ::cocktail::core::style::Overflow value);
		Dynamic setOverflowX_dyn();

		virtual ::cocktail::core::style::Overflow setOverflowY( ::cocktail::core::style::Overflow value);
		Dynamic setOverflowY_dyn();

		virtual double getOpacity( );
		Dynamic getOpacity_dyn();

		virtual ::cocktail::core::style::Visibility getVisibility( );
		Dynamic getVisibility_dyn();

		virtual ::cocktail::core::style::Margin getMarginLeft( );
		Dynamic getMarginLeft_dyn();

		virtual ::cocktail::core::style::Margin getMarginRight( );
		Dynamic getMarginRight_dyn();

		virtual ::cocktail::core::style::Margin getMarginTop( );
		Dynamic getMarginTop_dyn();

		virtual ::cocktail::core::style::Margin getMarginBottom( );
		Dynamic getMarginBottom_dyn();

		virtual ::cocktail::core::style::Padding getPaddingLeft( );
		Dynamic getPaddingLeft_dyn();

		virtual ::cocktail::core::style::Padding getPaddingRight( );
		Dynamic getPaddingRight_dyn();

		virtual ::cocktail::core::style::Padding getPaddingTop( );
		Dynamic getPaddingTop_dyn();

		virtual ::cocktail::core::style::Padding getPaddingBottom( );
		Dynamic getPaddingBottom_dyn();

		virtual ::cocktail::core::style::Display getDisplay( );
		Dynamic getDisplay_dyn();

		virtual ::cocktail::core::style::Position getPosition( );
		Dynamic getPosition_dyn();

		virtual ::cocktail::core::style::Dimension getWidth( );
		Dynamic getWidth_dyn();

		virtual ::cocktail::core::style::Dimension getHeight( );
		Dynamic getHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension getMinHeight( );
		Dynamic getMinHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension getMaxHeight( );
		Dynamic getMaxHeight_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension getMinWidth( );
		Dynamic getMinWidth_dyn();

		virtual ::cocktail::core::style::ConstrainedDimension getMaxWidth( );
		Dynamic getMaxWidth_dyn();

		virtual ::cocktail::core::style::PositionOffset getTop( );
		Dynamic getTop_dyn();

		virtual ::cocktail::core::style::PositionOffset getLeft( );
		Dynamic getLeft_dyn();

		virtual ::cocktail::core::style::PositionOffset getBottom( );
		Dynamic getBottom_dyn();

		virtual ::cocktail::core::style::PositionOffset getRight( );
		Dynamic getRight_dyn();

		virtual ::cocktail::core::style::CSSFloat getCSSFloat( );
		Dynamic getCSSFloat_dyn();

		virtual ::cocktail::core::style::Clear getClear( );
		Dynamic getClear_dyn();

		virtual ::cocktail::core::style::FontSize getFontSize( );
		Dynamic getFontSize_dyn();

		virtual ::cocktail::core::style::FontWeight getFontWeight( );
		Dynamic getFontWeight_dyn();

		virtual ::cocktail::core::style::FontStyle getFontStyle( );
		Dynamic getFontStyle_dyn();

		virtual Array< ::String > getFontFamily( );
		Dynamic getFontFamily_dyn();

		virtual ::cocktail::core::style::FontVariant getFontVariant( );
		Dynamic getFontVariant_dyn();

		virtual ::cocktail::core::style::TextTransform getTextTransform( );
		Dynamic getTextTransform_dyn();

		virtual ::cocktail::core::style::LetterSpacing getLetterSpacing( );
		Dynamic getLetterSpacing_dyn();

		virtual ::cocktail::core::unit::CSSColor getColor( );
		Dynamic getColor_dyn();

		virtual ::cocktail::core::style::WordSpacing getWordSpacing( );
		Dynamic getWordSpacing_dyn();

		virtual ::cocktail::core::style::LineHeight getLineHeight( );
		Dynamic getLineHeight_dyn();

		virtual ::cocktail::core::style::VerticalAlign getVerticalAlign( );
		Dynamic getVerticalAlign_dyn();

		virtual ::cocktail::core::style::TextIndent getTextIndent( );
		Dynamic getTextIndent_dyn();

		virtual ::cocktail::core::style::WhiteSpace getWhiteSpace( );
		Dynamic getWhiteSpace_dyn();

		virtual ::cocktail::core::style::TextAlign getTextAlign( );
		Dynamic getTextAlign_dyn();

		virtual ::cocktail::core::style::Transform getTransform( );
		Dynamic getTransform_dyn();

		virtual Dynamic getTransformOrigin( );
		Dynamic getTransformOrigin_dyn();

		virtual ::cocktail::core::unit::CSSColor setBackgroundColor( ::cocktail::core::unit::CSSColor value);
		Dynamic setBackgroundColor_dyn();

		virtual ::cocktail::core::unit::CSSColor getBackgroundColor( );
		Dynamic getBackgroundColor_dyn();

		virtual Array< ::cocktail::core::style::BackgroundImage > setBackgroundImage( Array< ::cocktail::core::style::BackgroundImage > value);
		Dynamic setBackgroundImage_dyn();

		virtual Array< ::cocktail::core::style::BackgroundImage > getBackgroundImage( );
		Dynamic getBackgroundImage_dyn();

		virtual Dynamic setBackgroundRepeat( Dynamic value);
		Dynamic setBackgroundRepeat_dyn();

		virtual Dynamic getBackgroundRepeat( );
		Dynamic getBackgroundRepeat_dyn();

		virtual Array< ::cocktail::core::style::BackgroundSize > setBackgroundSize( Array< ::cocktail::core::style::BackgroundSize > value);
		Dynamic setBackgroundSize_dyn();

		virtual Array< ::cocktail::core::style::BackgroundSize > getBackgroundSize( );
		Dynamic getBackgroundSize_dyn();

		virtual Array< ::cocktail::core::style::BackgroundClip > setBackgroundClip( Array< ::cocktail::core::style::BackgroundClip > value);
		Dynamic setBackgroundClip_dyn();

		virtual Array< ::cocktail::core::style::BackgroundClip > getBackgroundClip( );
		Dynamic getBackgroundClip_dyn();

		virtual Dynamic setBackgroundPosition( Dynamic value);
		Dynamic setBackgroundPosition_dyn();

		virtual Dynamic getBackgroundPosition( );
		Dynamic getBackgroundPosition_dyn();

		virtual Array< ::cocktail::core::style::BackgroundOrigin > setBackgroundOrigin( Array< ::cocktail::core::style::BackgroundOrigin > value);
		Dynamic setBackgroundOrigin_dyn();

		virtual Array< ::cocktail::core::style::BackgroundOrigin > getBackgroundOrigin( );
		Dynamic getBackgroundOrigin_dyn();

		virtual ::cocktail::core::style::Overflow getOverflowX( );
		Dynamic getOverflowX_dyn();

		virtual ::cocktail::core::style::Overflow getOverflowY( );
		Dynamic getOverflowY_dyn();

		virtual ::cocktail::core::style::Cursor setCursor( ::cocktail::core::style::Cursor value);
		Dynamic setCursor_dyn();

		virtual ::cocktail::core::style::Cursor getCursor( );
		Dynamic getCursor_dyn();

		static Dynamic getDefaultStyle( );
		static Dynamic getDefaultStyle_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_CoreStyle */ 
