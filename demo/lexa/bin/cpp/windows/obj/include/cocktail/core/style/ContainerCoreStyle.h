#ifndef INCLUDED_cocktail_core_style_ContainerCoreStyle
#define INCLUDED_cocktail_core_style_ContainerCoreStyle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/style/CoreStyle.h>
HX_DECLARE_CLASS3(cocktail,core,dom,CharacterData)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,dom,Text)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,TextRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,ContainerCoreStyle)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS5(cocktail,core,style,computer,boxComputers,BoxStylesComputer)
HX_DECLARE_CLASS4(cocktail,core,style,formatter,FormattingContext)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Text)
namespace cocktail{
namespace core{
namespace style{


class ContainerCoreStyle_obj : public ::cocktail::core::style::CoreStyle_obj{
	public:
		typedef ::cocktail::core::style::CoreStyle_obj super;
		typedef ContainerCoreStyle_obj OBJ_;
		ContainerCoreStyle_obj();
		Void __construct(::cocktail::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< ContainerCoreStyle_obj > __new(::cocktail::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ContainerCoreStyle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ContainerCoreStyle"); }

		virtual ::cocktail::core::renderer::ElementRenderer createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer);
		Dynamic createElementRenderer_dyn();

		virtual Void flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext);
		Dynamic flowChildren_dyn();

		virtual ::cocktail::core::style::formatter::FormattingContext doFlowChildren( Dynamic childrenContainingHTMLElementData,Dynamic viewportData,Dynamic childLastPositionedHTMLElementData,Dynamic childrenContainingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext childrenFormattingContext);
		Dynamic doFlowChildren_dyn();

		virtual Void positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn();

		virtual Void doPositionAbsolutelyPositionedHTMLElements( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic doPositionAbsolutelyPositionedHTMLElements_dyn();

		virtual Array< ::cocktail::core::renderer::TextRenderer > insertTextElement( ::cocktail::port::flash_player::Text textElement,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic containingHTMLElementData);
		Dynamic insertTextElement_dyn();

		virtual ::cocktail::core::renderer::TextRenderer createTextRendererFromTextFragment( Dynamic textFragment);
		Dynamic createTextRendererFromTextFragment_dyn();

		virtual Void shrinkToFitIfNeeded( Dynamic containingHTMLElementData,int minimumWidth,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData);
		Dynamic shrinkToFitIfNeeded_dyn();

		virtual int applyContentHeightIfNeeded( Dynamic containingHTMLElementData,int childrenHeight);
		Dynamic applyContentHeightIfNeeded_dyn();

		virtual ::cocktail::core::style::computer::boxComputers::BoxStylesComputer getBoxStylesComputer( );
		Dynamic getBoxStylesComputer_dyn();

		virtual ::cocktail::core::renderer::TextRenderer getTextRenderer( Dynamic textFragmentData,::String text);
		Dynamic getTextRenderer_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

		virtual bool childrenInline( );
		Dynamic childrenInline_dyn();

		virtual Dynamic getContainerHTMLElementData( );
		Dynamic getContainerHTMLElementData_dyn();

		virtual Dynamic getPositionedHTMLElementData( );
		Dynamic getPositionedHTMLElementData_dyn();

		virtual ::cocktail::core::style::formatter::FormattingContext getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext);
		Dynamic getformattingContext_dyn();

		virtual bool isChildInline( ::cocktail::core::dom::Node child);
		Dynamic isChildInline_dyn();

		virtual Dynamic getChildLastPositionedHTMLElementData( Dynamic lastPositionedHTMLElementData);
		Dynamic getChildLastPositionedHTMLElementData_dyn();

		virtual bool isInlineContainer( );
		Dynamic isInlineContainer_dyn();

		virtual int getComputedHeight( );
		Dynamic getComputedHeight_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace style

#endif /* INCLUDED_cocktail_core_style_ContainerCoreStyle */ 
