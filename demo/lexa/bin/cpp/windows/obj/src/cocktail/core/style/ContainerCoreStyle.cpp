#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_TextTokenValue
#include <cocktail/core/dom/TextTokenValue.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManager
#include <cocktail/core/font/AbstractFontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InlineBoxRenderer
#include <cocktail/core/renderer/InlineBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#include <cocktail/core/renderer/TextRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ContainerCoreStyle
#include <cocktail/core/style/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Dimension
#include <cocktail/core/style/Dimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Display
#include <cocktail/core/style/Display.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_FloatBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/FloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_InLineBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/InLineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_BlockFormattingContext
#include <cocktail/core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_InlineFormattingContext
#include <cocktail/core/style/formatter/InlineFormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
#ifndef INCLUDED_cocktail_port_nme_FontManager
#include <cocktail/port/nme/FontManager.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void ContainerCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",59)
	super::__construct(htmlElement);
}
;
	return null();
}

ContainerCoreStyle_obj::~ContainerCoreStyle_obj() { }

Dynamic ContainerCoreStyle_obj::__CreateEmpty() { return  new ContainerCoreStyle_obj; }
hx::ObjectPtr< ContainerCoreStyle_obj > ContainerCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< ContainerCoreStyle_obj > result = new ContainerCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic ContainerCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ContainerCoreStyle_obj > result = new ContainerCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::renderer::ElementRenderer ContainerCoreStyle_obj::createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",74)
	::cocktail::core::renderer::ElementRenderer elementRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",76)
	if (((bool((this->isInlineLevel() == true)) && bool((this->establishesNewFormattingContext() == false))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",77)
		elementRenderer = ::cocktail::core::renderer::InlineBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",81)
		elementRenderer = ::cocktail::core::renderer::BlockBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",85)
	elementRenderer->setLayerRenderer(this->getLayerRenderer(elementRenderer,parentElementRenderer));
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",86)
	parentElementRenderer->appendChild(elementRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",88)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(ContainerCoreStyle_obj,createElementRenderer,return )

Void ContainerCoreStyle_obj::flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext){
{
		HX_SOURCE_PUSH("ContainerCoreStyle_obj::flowChildren")
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",106)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",106)
			int _g1 = (int)0;
			int _g = this->_htmlElement->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",106)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",106)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",112)
				if (((this->_htmlElement->get_childNodes()->__get(i)->get_nodeType() == (int)1))){
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",114)
					::cocktail::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",115)
					childHTMLElement->get_coreStyle()->computeDisplayStyles();
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",123)
		::cocktail::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",129)
		Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",133)
		Dynamic childrenContainingHTMLElementFontMetricsData = this->getFontMetricsData();
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",137)
		Dynamic childLastPositionedHTMLElementData;
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",145)
		childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",149)
		childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",155)
		if (((this->_width == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",156)
			this->shrinkToFitIfNeeded(containingHTMLElementData,childrenFormattingContext->getMaxWidth(),formattingContext,lastPositionedHTMLElementData,viewportData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",167)
		if (((this->_height == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",176)
			if (((this->establishesNewFormattingContext() == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",177)
				childrenFormattingContext->format();
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",181)
			this->_computedStyle->__FieldRef(HX_CSTRING("height")) = this->applyContentHeightIfNeeded(containingHTMLElementData,childrenFormattingContext->getChildrenHeight(this->_elementRenderer));
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",186)
		this->positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData,viewportData);
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",189)
		if (((this->establishesNewFormattingContext() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",190)
			childrenFormattingContext->dispose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ContainerCoreStyle_obj,flowChildren,(void))

::cocktail::core::style::formatter::FormattingContext ContainerCoreStyle_obj::doFlowChildren( Dynamic childrenContainingHTMLElementData,Dynamic viewportData,Dynamic childLastPositionedHTMLElementData,Dynamic childrenContainingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext childrenFormattingContext){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::doFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",210)
	::cocktail::core::renderer::FlowBoxRenderer flowBoxRenderer = this->_elementRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",213)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",213)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",213)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",213)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",216)
			if (((this->_htmlElement->get_childNodes()->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",218)
				::cocktail::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",221)
				childHTMLElement->get_coreStyle()->flow(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext,this->_elementRenderer);
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",227)
				::cocktail::port::flash_player::Text childrenText = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",228)
				Array< ::cocktail::core::renderer::TextRenderer > insertedText = this->insertTextElement(childrenText,childrenFormattingContext,childrenContainingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",232)
				{
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",232)
					int _g3 = (int)0;
					int _g2 = insertedText->length;
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",232)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",232)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",234)
						flowBoxRenderer->appendChild(insertedText->__get(j));
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",246)
	if (((this->establishesNewFormattingContext() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",247)
		childrenFormattingContext->format();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",251)
	return childrenFormattingContext;
}


HX_DEFINE_DYNAMIC_FUNC5(ContainerCoreStyle_obj,doFlowChildren,return )

Void ContainerCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("ContainerCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",258)
		if (((this->isPositioned() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",260)
			this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerCoreStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Void ContainerCoreStyle_obj::doPositionAbsolutelyPositionedHTMLElements( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("ContainerCoreStyle_obj::doPositionAbsolutelyPositionedHTMLElements")
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",274)
		childLastPositionedHTMLElementData->__FieldRef(HX_CSTRING("data")) = this->getPositionedHTMLElementData();
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",277)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",277)
			int _g1 = (int)0;
			int _g = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",277)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",277)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",279)
				Dynamic positionedHTMLElementData = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__GetItem(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",283)
				positionedHTMLElementData->__Field(HX_CSTRING("coreStyle"))->__Field(HX_CSTRING("positionElement"))(childLastPositionedHTMLElementData->__Field(HX_CSTRING("data")),viewportData,positionedHTMLElementData->__Field(HX_CSTRING("staticPosition")));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerCoreStyle_obj,doPositionAbsolutelyPositionedHTMLElements,(void))

Array< ::cocktail::core::renderer::TextRenderer > ContainerCoreStyle_obj::insertTextElement( ::cocktail::port::flash_player::Text textElement,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::insertTextElement")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",301)
	Array< ::cocktail::core::renderer::TextRenderer > rendereredText = Array_obj< ::cocktail::core::renderer::TextRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",304)
	::String text = textElement->get_nodeValue();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",307)
	Dynamic textFragments = textElement->getTextFragments(text);
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",310)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",310)
		int _g1 = (int)0;
		int _g = textFragments->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",310)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",310)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",312)
			::cocktail::core::renderer::TextRenderer textRenderer = this->createTextRendererFromTextFragment(textFragments->__GetItem(i));
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",313)
			formattingContext->insertElement(textRenderer);
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",314)
			rendereredText->push(textRenderer);
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",317)
	return rendereredText;
}


HX_DEFINE_DYNAMIC_FUNC3(ContainerCoreStyle_obj,insertTextElement,return )

::cocktail::core::renderer::TextRenderer ContainerCoreStyle_obj::createTextRendererFromTextFragment( Dynamic textFragment){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::createTextRendererFromTextFragment")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",326)
	::String text;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",328)
	{
::cocktail::core::dom::TextTokenValue _switch_1 = (textFragment->__Field(HX_CSTRING("textToken")));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::String value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",330)
					text = value;
				}
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",333)
				text = HX_CSTRING(" ");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",337)
				text = HX_CSTRING("");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",340)
				text = HX_CSTRING("");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",344)
	::cocktail::core::renderer::TextRenderer textRenderer = this->getTextRenderer(textFragment,text);
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",346)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(ContainerCoreStyle_obj,createTextRendererFromTextFragment,return )

Void ContainerCoreStyle_obj::shrinkToFitIfNeeded( Dynamic containingHTMLElementData,int minimumWidth,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("ContainerCoreStyle_obj::shrinkToFitIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",365)
		::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",366)
		int shrinkedWidth = boxComputer->shrinkToFit(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,minimumWidth);
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",370)
		if (((this->_computedStyle->__Field(HX_CSTRING("width")) != shrinkedWidth))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",373)
			this->_computedStyle->__FieldRef(HX_CSTRING("width")) = shrinkedWidth;
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",376)
			::cocktail::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",377)
			Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",378)
			Dynamic childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",379)
			childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,this->getFontMetricsData(),childrenFormattingContext);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(ContainerCoreStyle_obj,shrinkToFitIfNeeded,(void))

int ContainerCoreStyle_obj::applyContentHeightIfNeeded( Dynamic containingHTMLElementData,int childrenHeight){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::applyContentHeightIfNeeded")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",394)
	::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",395)
	return boxComputer->applyContentHeight(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,childrenHeight);
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerCoreStyle_obj,applyContentHeightIfNeeded,return )

::cocktail::core::style::computer::boxComputers::BoxStylesComputer ContainerCoreStyle_obj::getBoxStylesComputer( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getBoxStylesComputer")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",409)
	::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",412)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",413)
		boxComputer = ::cocktail::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__new();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",418)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",419)
			boxComputer = ::cocktail::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__new();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",425)
			{
::cocktail::core::style::Display _switch_2 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_2)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",428)
						boxComputer = ::cocktail::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",431)
						boxComputer = ::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 3: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",435)
						boxComputer = null();
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",438)
						boxComputer = ::cocktail::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__new();
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",443)
	return boxComputer;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,getBoxStylesComputer,return )

::cocktail::core::renderer::TextRenderer ContainerCoreStyle_obj::getTextRenderer( Dynamic textFragmentData,::String text){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getTextRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",457)
	::cocktail::port::nme::FontManager fontManager = ::cocktail::port::nme::FontManager_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",458)
	Dynamic nativeTextElement = fontManager->createNativeTextElement(text,this->_computedStyle);
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",460)
	::cocktail::core::renderer::TextRenderer textRenderer = ::cocktail::core::renderer::TextRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this),nativeTextElement,textFragmentData->__Field(HX_CSTRING("textToken")));
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",462)
	textRenderer->setLayerRenderer(this->_elementRenderer->getLayerRenderer());
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",463)
	textFragmentData->__FieldRef(HX_CSTRING("textRenderer")) = textRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",477)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerCoreStyle_obj,getTextRenderer,return )

bool ContainerCoreStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",491)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",494)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",495)
		ret = true;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",499)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",500)
			ret = true;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",506)
			{
::cocktail::core::style::Display _switch_3 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_3)->GetIndex()){
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",509)
						ret = true;
					}
					;break;
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",515)
						if (((this->childrenInline() == true))){
							HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",517)
							ret = true;
						}
					}
					;break;
					default: {
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",528)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,establishesNewFormattingContext,return )

bool ContainerCoreStyle_obj::childrenInline( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::childrenInline")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",544)
	if (((this->_htmlElement->get_childNodes()->length == (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",545)
		return false;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",551)
	bool ret = this->isChildInline(this->_htmlElement->get_childNodes()->__get((int)0));
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",555)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",555)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",555)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",555)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",557)
			if (((this->isChildInline(this->_htmlElement->get_childNodes()->__get(i)) != ret))){
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",563)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,childrenInline,return )

Dynamic ContainerCoreStyle_obj::getContainerHTMLElementData( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getContainerHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",576)
	int height;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",581)
	if (((this->isInlineLevel() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",582)
		height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",587)
		if (((bool((this->establishesNewFormattingContext() == true)) && bool((this->childrenInline() == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",588)
			height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",594)
			height = this->_computedStyle->__Field(HX_CSTRING("height"));
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::style::ContainerCoreStyle_obj *__this,int &height){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("width") , __this->_computedStyle->__Field(HX_CSTRING("width")),false);
			__result->Add(HX_CSTRING("isWidthAuto") , (__this->_width == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),false);
			__result->Add(HX_CSTRING("height") , height,false);
			__result->Add(HX_CSTRING("isHeightAuto") , (__this->_height == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",598)
	return _Function_1_1::Block(this,height);
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,getContainerHTMLElementData,return )

Dynamic ContainerCoreStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",617)
	Dynamic positionedHTMLElementData = this->getContainerHTMLElementData();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",620)
	positionedHTMLElementData->__FieldRef(HX_CSTRING("height")) = this->getComputedHeight();
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",622)
	return positionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,getPositionedHTMLElementData,return )

::cocktail::core::style::formatter::FormattingContext ContainerCoreStyle_obj::getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",643)
	::cocktail::core::style::formatter::FormattingContext formattingContext;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",646)
	if (((bool((this->establishesNewFormattingContext() == true)) || bool((previousformattingContext == null()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",648)
		::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot = this->_elementRenderer;
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",652)
		if (((this->childrenInline() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",653)
			formattingContext = ::cocktail::core::style::formatter::InlineFormattingContext_obj::__new(formattingContextRoot);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",657)
			formattingContext = ::cocktail::core::style::formatter::BlockFormattingContext_obj::__new(formattingContextRoot);
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",662)
		formattingContext = previousformattingContext;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",666)
	return formattingContext;
}


HX_DEFINE_DYNAMIC_FUNC1(ContainerCoreStyle_obj,getformattingContext,return )

bool ContainerCoreStyle_obj::isChildInline( ::cocktail::core::dom::Node child){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::isChildInline")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",674)
	bool ret = true;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",677)
	if (((child->get_nodeType() == (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",679)
		::cocktail::port::flash_player::HTMLElement childHTMLElement = child;
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",681)
		if (((childHTMLElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("display")) == ::cocktail::core::style::Display_obj::block_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",682)
			if (((childHTMLElement->get_coreStyle()->isFloat() == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",685)
				ret = false;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",689)
				if (((bool((childHTMLElement->get_coreStyle()->isPositioned() == false)) || bool((childHTMLElement->get_coreStyle()->isRelativePositioned() == true))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",690)
					ret = false;
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",696)
			ret = true;
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",703)
		ret = true;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",707)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(ContainerCoreStyle_obj,isChildInline,return )

Dynamic ContainerCoreStyle_obj::getChildLastPositionedHTMLElementData( Dynamic lastPositionedHTMLElementData){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getChildLastPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",717)
	Dynamic childLastPositionedHTMLElementData;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",719)
	if (((this->isPositioned() == true))){
		struct _Function_2_1{
			inline static Dynamic Block( ::cocktail::core::style::ContainerCoreStyle_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("data") , __this->getContainerHTMLElementData(),false);
				__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",720)
		childLastPositionedHTMLElementData = _Function_2_1::Block(this);
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",727)
		childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",731)
	return childLastPositionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC1(ContainerCoreStyle_obj,getChildLastPositionedHTMLElementData,return )

bool ContainerCoreStyle_obj::isInlineContainer( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::isInlineContainer")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",747)
	bool ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",749)
	{
::cocktail::core::style::Display _switch_4 = (this->_computedStyle->__Field(HX_CSTRING("display")));
		switch((_switch_4)->GetIndex()){
			case 0: case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",751)
				ret = false;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",754)
				ret = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",757)
				ret = true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",761)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,isInlineContainer,return )

int ContainerCoreStyle_obj::getComputedHeight( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getComputedHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/ContainerCoreStyle.hx",770)
	return this->_computedStyle->__Field(HX_CSTRING("height"));
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,getComputedHeight,return )


ContainerCoreStyle_obj::ContainerCoreStyle_obj()
{
}

void ContainerCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ContainerCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ContainerCoreStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"flowChildren") ) { return flowChildren_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isChildInline") ) { return isChildInline_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"doFlowChildren") ) { return doFlowChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"childrenInline") ) { return childrenInline_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getTextRenderer") ) { return getTextRenderer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"insertTextElement") ) { return insertTextElement_dyn(); }
		if (HX_FIELD_EQ(inName,"isInlineContainer") ) { return isInlineContainer_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedHeight") ) { return getComputedHeight_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"shrinkToFitIfNeeded") ) { return shrinkToFitIfNeeded_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getBoxStylesComputer") ) { return getBoxStylesComputer_dyn(); }
		if (HX_FIELD_EQ(inName,"getformattingContext") ) { return getformattingContext_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"applyContentHeightIfNeeded") ) { return applyContentHeightIfNeeded_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"getContainerHTMLElementData") ) { return getContainerHTMLElementData_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getPositionedHTMLElementData") ) { return getPositionedHTMLElementData_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"establishesNewFormattingContext") ) { return establishesNewFormattingContext_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"createTextRendererFromTextFragment") ) { return createTextRendererFromTextFragment_dyn(); }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"getChildLastPositionedHTMLElementData") ) { return getChildLastPositionedHTMLElementData_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"doPositionAbsolutelyPositionedHTMLElements") ) { return doPositionAbsolutelyPositionedHTMLElements_dyn(); }
		break;
	case 48:
		if (HX_FIELD_EQ(inName,"positionAbsolutelyPositionedHTMLElementsIfNeeded") ) { return positionAbsolutelyPositionedHTMLElementsIfNeeded_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ContainerCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ContainerCoreStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("flowChildren"),
	HX_CSTRING("doFlowChildren"),
	HX_CSTRING("positionAbsolutelyPositionedHTMLElementsIfNeeded"),
	HX_CSTRING("doPositionAbsolutelyPositionedHTMLElements"),
	HX_CSTRING("insertTextElement"),
	HX_CSTRING("createTextRendererFromTextFragment"),
	HX_CSTRING("shrinkToFitIfNeeded"),
	HX_CSTRING("applyContentHeightIfNeeded"),
	HX_CSTRING("getBoxStylesComputer"),
	HX_CSTRING("getTextRenderer"),
	HX_CSTRING("establishesNewFormattingContext"),
	HX_CSTRING("childrenInline"),
	HX_CSTRING("getContainerHTMLElementData"),
	HX_CSTRING("getPositionedHTMLElementData"),
	HX_CSTRING("getformattingContext"),
	HX_CSTRING("isChildInline"),
	HX_CSTRING("getChildLastPositionedHTMLElementData"),
	HX_CSTRING("isInlineContainer"),
	HX_CSTRING("getComputedHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ContainerCoreStyle_obj::__mClass;

void ContainerCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.ContainerCoreStyle"), hx::TCanCast< ContainerCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ContainerCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
