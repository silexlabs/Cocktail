#ifndef INCLUDED_core_style_AbstractContainerStyle
#define INCLUDED_core_style_AbstractContainerStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/Style.h>
HX_DECLARE_CLASS2(core,dom,CharacterData)
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,dom,Text)
HX_DECLARE_CLASS2(core,dom,TextTokenValue)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,TextRenderer)
HX_DECLARE_CLASS2(core,style,AbstractContainerStyle)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS4(core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS3(core,style,formatter,FormattingContext)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Style)
HX_DECLARE_CLASS2(port,flash_player,Text)
namespace core{
namespace style{


class AbstractContainerStyle_obj : public ::port::flash_player::Style_obj{
	public:
		typedef ::port::flash_player::Style_obj super;
		typedef AbstractContainerStyle_obj OBJ_;
		AbstractContainerStyle_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< AbstractContainerStyle_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractContainerStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractContainerStyle"); }

		virtual ::core::renderer::ElementRenderer createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual Void layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData);
		Dynamic layout_dyn();

		virtual Void flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext);
		Dynamic flowChildren_dyn();

		virtual ::core::style::formatter::FormattingContext doFlowChildren( Dynamic childrenContainingHTMLElementData,Dynamic viewportData,Dynamic childLastPositionedHTMLElementData,Dynamic childrenContainingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext childrenFormattingContext);
		Dynamic doFlowChildren_dyn();

		virtual Void positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn();

		virtual Void doPositionAbsolutelyPositionedHTMLElements( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic doPositionAbsolutelyPositionedHTMLElements_dyn();

		virtual Array< ::core::renderer::TextRenderer > insertTextElement( ::port::flash_player::Text textElement,::core::style::formatter::FormattingContext formattingContext,Dynamic containingHTMLElementData);
		Dynamic insertTextElement_dyn();

		virtual ::core::renderer::TextRenderer createTextRendererFromTextFragment( Dynamic textFragment);
		Dynamic createTextRendererFromTextFragment_dyn();

		virtual Void shrinkToFitIfNeeded( Dynamic containingHTMLElementData,int minimumWidth,::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic shrinkToFitIfNeeded_dyn();

		virtual int applyContentHeightIfNeeded( Dynamic containingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeightIfNeeded_dyn();

		virtual ::core::style::computer::boxComputers::BoxStylesComputer getBoxStylesComputer( );
		Dynamic getBoxStylesComputer_dyn();

		virtual ::core::renderer::TextRenderer getTextRenderer( Dynamic textFragmentData,::String text);
		Dynamic getTextRenderer_dyn();

		virtual ::core::renderer::TextRenderer createTextRenderer( ::String text,::core::dom::TextTokenValue textToken);
		Dynamic createTextRenderer_dyn();

		virtual ::core::renderer::TextRenderer doCreateTextRenderer( ::String text,::core::dom::TextTokenValue textToken);
		Dynamic doCreateTextRenderer_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

		virtual bool childrenInline( );
		Dynamic childrenInline_dyn();

		virtual Dynamic getContainerHTMLElementData( );
		Dynamic getContainerHTMLElementData_dyn();

		virtual Dynamic getPositionedHTMLElementData( );
		Dynamic getPositionedHTMLElementData_dyn();

		virtual ::core::style::formatter::FormattingContext getformattingContext( ::core::style::formatter::FormattingContext previousformattingContext);
		Dynamic getformattingContext_dyn();

		virtual bool isChildInline( ::core::dom::Node child);
		Dynamic isChildInline_dyn();

		virtual Dynamic getChildLastPositionedHTMLElementData( Dynamic lastPositionedHTMLElementData);
		Dynamic getChildLastPositionedHTMLElementData_dyn();

		virtual bool isInlineContainer( );
		Dynamic isInlineContainer_dyn();

		virtual int getComputedHeight( );
		Dynamic getComputedHeight_dyn();

		virtual bool isElementNode( ::core::dom::Node node);
		Dynamic isElementNode_dyn();

};

} // end namespace core
} // end namespace style

#endif /* INCLUDED_core_style_AbstractContainerStyle */ 
