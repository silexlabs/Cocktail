#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#define INCLUDED_cocktail_core_renderer_TextRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,font,FontManager)
HX_DECLARE_CLASS3(cocktail,core,font,FontMetricsVO)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextToken)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class TextRenderer_obj : public ::cocktail::core::renderer::InvalidatingElementRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::InvalidatingElementRenderer_obj super;
		typedef TextRenderer_obj OBJ_;
		TextRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< TextRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextRenderer"); }

		virtual bool isInlineLevel( );

		virtual bool isPositioned( );

		virtual bool isFloat( );

		virtual ::cocktail::core::linebox::InlineBox createInlineBoxFromTextToken( ::cocktail::core::renderer::TextToken textToken,Float leadedAscent,Float leadedDescent,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily,Float spaceWidth);
		Dynamic createInlineBoxFromTextToken_dyn();

		virtual Void createTextLines( );
		Dynamic createTextLines_dyn();

		virtual ::String capitalizeText( ::String sourceText);
		Dynamic capitalizeText_dyn();

		virtual ::String applyTextTransform( ::String text,::cocktail::core::css::CSSKeywordValue textTransform);
		Dynamic applyTextTransform_dyn();

		virtual ::String convertTabToSpaces( ::String sourceText);
		Dynamic convertTabToSpaces_dyn();

		virtual ::String convertLineFeedsToSpaces( ::String sourceText);
		Dynamic convertLineFeedsToSpaces_dyn();

		virtual ::String concatenateSpaces( ::String sourceText);
		Dynamic concatenateSpaces_dyn();

		virtual ::String removeControlCharactersSurroundingLineFeed( ::String sourceText);
		Dynamic removeControlCharactersSurroundingLineFeed_dyn();

		virtual ::String applyWhiteSpaceProcessing( ::String text,::cocktail::core::css::CSSKeywordValue whiteSpace);
		Dynamic applyWhiteSpaceProcessing_dyn();

		virtual Array< ::cocktail::core::renderer::TextToken > doGetTextTokens( ::String text);
		Dynamic doGetTextTokens_dyn();

		virtual Void invalidate( );

		virtual Void updateTextDecorations( bool inheritUnderline,bool inheritOverline,bool inheritLineThrough,bool inheritBlink);

		virtual Void render( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void updateText( );

		virtual Void initCoreStyle( );

		bool _hasBlink; /* REM */ 
		bool _hasLineThrough; /* REM */ 
		bool _hasOverline; /* REM */ 
		bool _hasUnderline; /* REM */ 
		bool _textTokensNeedParsing; /* REM */ 
		bool _textNeedsRendering; /* REM */ 
		::cocktail::core::dom::Text _text; /* REM */ 
		Array< ::cocktail::core::renderer::TextToken > _textTokens; /* REM */ 
		static int COPY; /* REM */ 
		static int BUFFER; /* REM */ 
		static int AFTER_LINE_FEED; /* REM */ 
		static int CONCATENATE; /* REM */ 
		static int CAPITALIZE_STATE; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _intersectBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_TextRenderer */ 
