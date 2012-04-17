#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_core_dom_CharacterData
#include <core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_NodeType
#include <core/dom/NodeType.h>
#endif
#ifndef INCLUDED_core_dom_Text
#include <core/dom/Text.h>
#endif
#ifndef INCLUDED_core_dom_TextTokenValue
#include <core/dom/TextTokenValue.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_renderer_BlockBoxRenderer
#include <core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_BoxRenderer
#include <core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_FlowBoxRenderer
#include <core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_InlineBoxRenderer
#include <core/renderer/InlineBoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_LayerRenderer
#include <core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_TextRenderer
#include <core/renderer/TextRenderer.h>
#endif
#ifndef INCLUDED_core_style_AbstractContainerStyle
#include <core/style/AbstractContainerStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_Dimension
#include <core/style/Dimension.h>
#endif
#ifndef INCLUDED_core_style_Display
#include <core/style/Display.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_BlockBoxStylesComputer
#include <core/style/computer/boxComputers/BlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_FloatBoxStylesComputer
#include <core/style/computer/boxComputers/FloatBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_InLineBoxStylesComputer
#include <core/style/computer/boxComputers/InLineBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_InlineBlockBoxStylesComputer
#include <core/style/computer/boxComputers/InlineBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_PositionedBoxStylesComputer
#include <core/style/computer/boxComputers/PositionedBoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_formatter_BlockFormattingContext
#include <core/style/formatter/BlockFormattingContext.h>
#endif
#ifndef INCLUDED_core_style_formatter_FormattingContext
#include <core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_core_style_formatter_InlineFormattingContext
#include <core/style/formatter/InlineFormattingContext.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
#ifndef INCLUDED_port_flash_player_Text
#include <port/flash_player/Text.h>
#endif
namespace core{
namespace style{

Void AbstractContainerStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",64)
	super::__construct(htmlElement);
}
;
	return null();
}

AbstractContainerStyle_obj::~AbstractContainerStyle_obj() { }

Dynamic AbstractContainerStyle_obj::__CreateEmpty() { return  new AbstractContainerStyle_obj; }
hx::ObjectPtr< AbstractContainerStyle_obj > AbstractContainerStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractContainerStyle_obj > result = new AbstractContainerStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractContainerStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractContainerStyle_obj > result = new AbstractContainerStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::core::renderer::ElementRenderer AbstractContainerStyle_obj::createElementRenderer( ::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",79)
	::core::renderer::ElementRenderer elementRenderer;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",81)
	if (((bool((this->isInlineLevel() == true)) && bool((this->establishesNewFormattingContext() == false))))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",82)
		elementRenderer = ::core::renderer::InlineBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",86)
		elementRenderer = ::core::renderer::BlockBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",90)
	elementRenderer->setLayerRenderer(this->getLayerRenderer(elementRenderer,parentElementRenderer));
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",91)
	parentElementRenderer->appendChild(elementRenderer);
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",93)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,createElementRenderer,return )

Void AbstractContainerStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractContainerStyle_obj::layout")
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",105)
		this->flow(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractContainerStyle_obj,layout,(void))

Void AbstractContainerStyle_obj::flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext formattingContext){
{
		HX_SOURCE_PUSH("AbstractContainerStyle_obj::flowChildren")
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",124)
		{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",124)
			int _g1 = (int)0;
			int _g = this->_htmlElement->get_childNodes()->length;
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",124)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",124)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",130)
				if (((this->isElementNode(this->_htmlElement->get_childNodes()->__get(i)) == true))){
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",132)
					::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",133)
					childHTMLElement->get_style()->computeDisplayStyles();
				}
			}
		}
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",141)
		::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",147)
		Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",151)
		Dynamic childrenContainingHTMLElementFontMetricsData = this->getFontMetricsData();
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",155)
		Dynamic childLastPositionedHTMLElementData;
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",163)
		childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",167)
		childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext);
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",173)
		if (((this->_width == ::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",174)
			this->shrinkToFitIfNeeded(containingHTMLElementData,childrenFormattingContext->getMaxWidth(),formattingContext,lastPositionedHTMLElementData,viewportData);
		}
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",185)
		if (((this->_height == ::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",194)
			if (((this->establishesNewFormattingContext() == false))){
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",195)
				childrenFormattingContext->format();
			}
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",199)
			this->_computedStyle->__FieldRef(HX_CSTRING("height")) = this->applyContentHeightIfNeeded(containingHTMLElementData,childrenFormattingContext->getChildrenHeight(this->_elementRenderer));
		}
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",204)
		this->positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData,viewportData);
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",207)
		if (((this->establishesNewFormattingContext() == true))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",208)
			childrenFormattingContext->dispose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerStyle_obj,flowChildren,(void))

::core::style::formatter::FormattingContext AbstractContainerStyle_obj::doFlowChildren( Dynamic childrenContainingHTMLElementData,Dynamic viewportData,Dynamic childLastPositionedHTMLElementData,Dynamic childrenContainingHTMLElementFontMetricsData,::core::style::formatter::FormattingContext childrenFormattingContext){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::doFlowChildren")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",226)
	::core::renderer::FlowBoxRenderer flowBoxRenderer = this->_elementRenderer;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",229)
	{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",229)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",229)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",229)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",232)
			if (((this->isElementNode(this->_htmlElement->get_childNodes()->__get(i)) == true))){
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",234)
				::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",237)
				childHTMLElement->get_style()->flow(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext,this->_elementRenderer);
			}
			else{
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",243)
				::port::flash_player::Text childrenText = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",244)
				Array< ::core::renderer::TextRenderer > insertedText = this->insertTextElement(childrenText,childrenFormattingContext,childrenContainingHTMLElementData);
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",248)
				{
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",248)
					int _g3 = (int)0;
					int _g2 = insertedText->length;
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",248)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",248)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",250)
						flowBoxRenderer->appendChild(insertedText->__get(j));
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",262)
	if (((this->establishesNewFormattingContext() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",263)
		childrenFormattingContext->format();
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",267)
	return childrenFormattingContext;
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerStyle_obj,doFlowChildren,return )

Void AbstractContainerStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",274)
		if (((this->isPositioned() == true))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",276)
			this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Void AbstractContainerStyle_obj::doPositionAbsolutelyPositionedHTMLElements( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerStyle_obj::doPositionAbsolutelyPositionedHTMLElements")
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",290)
		childLastPositionedHTMLElementData->__FieldRef(HX_CSTRING("data")) = this->getPositionedHTMLElementData();
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",293)
		{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",293)
			int _g1 = (int)0;
			int _g = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",293)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",293)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",295)
				Dynamic positionedHTMLElementData = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__GetItem(i);
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",299)
				positionedHTMLElementData->__Field(HX_CSTRING("style"))->__Field(HX_CSTRING("positionElement"))(childLastPositionedHTMLElementData->__Field(HX_CSTRING("data")),viewportData,positionedHTMLElementData->__Field(HX_CSTRING("staticPosition")));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,doPositionAbsolutelyPositionedHTMLElements,(void))

Array< ::core::renderer::TextRenderer > AbstractContainerStyle_obj::insertTextElement( ::port::flash_player::Text textElement,::core::style::formatter::FormattingContext formattingContext,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::insertTextElement")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",317)
	Array< ::core::renderer::TextRenderer > rendereredText = Array_obj< ::core::renderer::TextRenderer >::__new();
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",320)
	::String text = textElement->get_nodeValue();
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",323)
	Dynamic textFragments = textElement->getTextFragments(text);
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",326)
	{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",326)
		int _g1 = (int)0;
		int _g = textFragments->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",326)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",326)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",328)
			::core::renderer::TextRenderer textRenderer = this->createTextRendererFromTextFragment(textFragments->__GetItem(i));
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",329)
			formattingContext->insertElement(textRenderer);
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",330)
			rendereredText->push(textRenderer);
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",333)
	return rendereredText;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractContainerStyle_obj,insertTextElement,return )

::core::renderer::TextRenderer AbstractContainerStyle_obj::createTextRendererFromTextFragment( Dynamic textFragment){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::createTextRendererFromTextFragment")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",342)
	::String text;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",344)
	{
::core::dom::TextTokenValue _switch_1 = (textFragment->__Field(HX_CSTRING("textToken")));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::String value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",346)
					text = value;
				}
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",349)
				text = HX_CSTRING(" ");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",353)
				text = HX_CSTRING("");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",356)
				text = HX_CSTRING("");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",360)
	::core::renderer::TextRenderer textRenderer = this->getTextRenderer(textFragment,text);
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",362)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,createTextRendererFromTextFragment,return )

Void AbstractContainerStyle_obj::shrinkToFitIfNeeded( Dynamic containingHTMLElementData,int minimumWidth,::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerStyle_obj::shrinkToFitIfNeeded")
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",381)
		::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",382)
		int shrinkedWidth = boxComputer->shrinkToFit(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,minimumWidth);
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",386)
		if (((this->_computedStyle->__Field(HX_CSTRING("width")) != shrinkedWidth))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",389)
			this->_computedStyle->__FieldRef(HX_CSTRING("width")) = shrinkedWidth;
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",392)
			::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",393)
			Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",394)
			Dynamic childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",395)
			childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,this->getFontMetricsData(),childrenFormattingContext);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerStyle_obj,shrinkToFitIfNeeded,(void))

int AbstractContainerStyle_obj::applyContentHeightIfNeeded( Dynamic containingHTMLElementData,int childrenHeight){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::applyContentHeightIfNeeded")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",410)
	::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",411)
	return boxComputer->applyContentHeight(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,childrenHeight);
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,applyContentHeightIfNeeded,return )

::core::style::computer::boxComputers::BoxStylesComputer AbstractContainerStyle_obj::getBoxStylesComputer( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getBoxStylesComputer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",425)
	::core::style::computer::boxComputers::BoxStylesComputer boxComputer;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",428)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",429)
		boxComputer = ::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__new();
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",434)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",435)
			boxComputer = ::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__new();
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",441)
			{
::core::style::Display _switch_2 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_2)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",444)
						boxComputer = ::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",447)
						boxComputer = ::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 3: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",451)
						boxComputer = null();
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",454)
						boxComputer = ::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__new();
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",459)
	return boxComputer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,getBoxStylesComputer,return )

::core::renderer::TextRenderer AbstractContainerStyle_obj::getTextRenderer( Dynamic textFragmentData,::String text){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getTextRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",473)
	::core::renderer::TextRenderer textRenderer;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",474)
	textRenderer = this->createTextRenderer(text,textFragmentData->__Field(HX_CSTRING("textToken")));
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",475)
	textRenderer->setLayerRenderer(this->_elementRenderer->getLayerRenderer());
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",476)
	textFragmentData->__FieldRef(HX_CSTRING("textRenderer")) = textRenderer;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",490)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,getTextRenderer,return )

::core::renderer::TextRenderer AbstractContainerStyle_obj::createTextRenderer( ::String text,::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::createTextRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",498)
	return this->doCreateTextRenderer(text,textToken);
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,createTextRenderer,return )

::core::renderer::TextRenderer AbstractContainerStyle_obj::doCreateTextRenderer( ::String text,::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::doCreateTextRenderer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",507)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerStyle_obj,doCreateTextRenderer,return )

bool AbstractContainerStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",522)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",525)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",526)
		ret = true;
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",530)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",531)
			ret = true;
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",537)
			{
::core::style::Display _switch_3 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_3)->GetIndex()){
					case 1: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",540)
						ret = true;
					}
					;break;
					case 0: {
						HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",546)
						if (((this->childrenInline() == true))){
							HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",548)
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
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",559)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,establishesNewFormattingContext,return )

bool AbstractContainerStyle_obj::childrenInline( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::childrenInline")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",575)
	if (((this->_htmlElement->get_childNodes()->length == (int)0))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",576)
		return false;
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",582)
	bool ret = this->isChildInline(this->_htmlElement->get_childNodes()->__get((int)0));
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",586)
	{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",586)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",586)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",586)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",588)
			if (((this->isChildInline(this->_htmlElement->get_childNodes()->__get(i)) != ret))){
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",594)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,childrenInline,return )

Dynamic AbstractContainerStyle_obj::getContainerHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getContainerHTMLElementData")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",607)
	int height;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",612)
	if (((this->isInlineLevel() == true))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",613)
		height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",618)
		if (((bool((this->establishesNewFormattingContext() == true)) && bool((this->childrenInline() == true))))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",619)
			height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",625)
			height = this->_computedStyle->__Field(HX_CSTRING("height"));
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::core::style::AbstractContainerStyle_obj *__this,int &height){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("width") , __this->_computedStyle->__Field(HX_CSTRING("width")),false);
			__result->Add(HX_CSTRING("isWidthAuto") , (__this->_width == ::core::style::Dimension_obj::cssAuto_dyn()),false);
			__result->Add(HX_CSTRING("height") , height,false);
			__result->Add(HX_CSTRING("isHeightAuto") , (__this->_height == ::core::style::Dimension_obj::cssAuto_dyn()),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",629)
	return _Function_1_1::Block(this,height);
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,getContainerHTMLElementData,return )

Dynamic AbstractContainerStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",648)
	Dynamic positionedHTMLElementData = this->getContainerHTMLElementData();
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",651)
	positionedHTMLElementData->__FieldRef(HX_CSTRING("height")) = this->getComputedHeight();
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",653)
	return positionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,getPositionedHTMLElementData,return )

::core::style::formatter::FormattingContext AbstractContainerStyle_obj::getformattingContext( ::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",674)
	::core::style::formatter::FormattingContext formattingContext;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",677)
	if (((bool((this->establishesNewFormattingContext() == true)) || bool((previousformattingContext == null()))))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",679)
		::core::renderer::BlockBoxRenderer formattingContextRoot = this->_elementRenderer;
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",683)
		if (((this->childrenInline() == true))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",684)
			formattingContext = ::core::style::formatter::InlineFormattingContext_obj::__new(formattingContextRoot);
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",688)
			formattingContext = ::core::style::formatter::BlockFormattingContext_obj::__new(formattingContextRoot);
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",693)
		formattingContext = previousformattingContext;
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",697)
	return formattingContext;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,getformattingContext,return )

bool AbstractContainerStyle_obj::isChildInline( ::core::dom::Node child){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::isChildInline")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",705)
	bool ret = true;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",708)
	if ((this->isElementNode(child))){
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",710)
		::port::flash_player::HTMLElement childHTMLElement = child;
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",712)
		if (((childHTMLElement->get_style()->getComputedStyle()->__Field(HX_CSTRING("display")) == ::core::style::Display_obj::block_dyn()))){
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",713)
			if (((childHTMLElement->get_style()->isFloat() == false))){
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",716)
				ret = false;
			}
			else{
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",720)
				if (((bool((childHTMLElement->get_style()->isPositioned() == false)) || bool((childHTMLElement->get_style()->isRelativePositioned() == true))))){
					HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",721)
					ret = false;
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",727)
			ret = true;
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",734)
		ret = true;
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",738)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,isChildInline,return )

Dynamic AbstractContainerStyle_obj::getChildLastPositionedHTMLElementData( Dynamic lastPositionedHTMLElementData){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getChildLastPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",748)
	Dynamic childLastPositionedHTMLElementData;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",750)
	if (((this->isPositioned() == true))){
		struct _Function_2_1{
			inline static Dynamic Block( ::core::style::AbstractContainerStyle_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("data") , __this->getContainerHTMLElementData(),false);
				__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",751)
		childLastPositionedHTMLElementData = _Function_2_1::Block(this);
	}
	else{
		HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",758)
		childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",762)
	return childLastPositionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,getChildLastPositionedHTMLElementData,return )

bool AbstractContainerStyle_obj::isInlineContainer( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::isInlineContainer")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",778)
	bool ret;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",780)
	{
::core::style::Display _switch_4 = (this->_computedStyle->__Field(HX_CSTRING("display")));
		switch((_switch_4)->GetIndex()){
			case 0: case 1: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",782)
				ret = false;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",785)
				ret = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",788)
				ret = true;
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",792)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,isInlineContainer,return )

int AbstractContainerStyle_obj::getComputedHeight( ){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::getComputedHeight")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",801)
	return this->_computedStyle->__Field(HX_CSTRING("height"));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerStyle_obj,getComputedHeight,return )

bool AbstractContainerStyle_obj::isElementNode( ::core::dom::Node node){
	HX_SOURCE_PUSH("AbstractContainerStyle_obj::isElementNode")
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",811)
	bool ret = false;
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",813)
	{
::core::dom::NodeType _switch_5 = (node->get_nodeType());
		switch((_switch_5)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",815)
				ret = true;
			}
			;break;
			case 1: case 2: {
				HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",818)
				ret = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/AbstractContainerStyle.hx",822)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerStyle_obj,isElementNode,return )


AbstractContainerStyle_obj::AbstractContainerStyle_obj()
{
}

void AbstractContainerStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractContainerStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractContainerStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"flowChildren") ) { return flowChildren_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isChildInline") ) { return isChildInline_dyn(); }
		if (HX_FIELD_EQ(inName,"isElementNode") ) { return isElementNode_dyn(); }
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
	case 18:
		if (HX_FIELD_EQ(inName,"createTextRenderer") ) { return createTextRenderer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"shrinkToFitIfNeeded") ) { return shrinkToFitIfNeeded_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getBoxStylesComputer") ) { return getBoxStylesComputer_dyn(); }
		if (HX_FIELD_EQ(inName,"doCreateTextRenderer") ) { return doCreateTextRenderer_dyn(); }
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

Dynamic AbstractContainerStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractContainerStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("layout"),
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
	HX_CSTRING("createTextRenderer"),
	HX_CSTRING("doCreateTextRenderer"),
	HX_CSTRING("establishesNewFormattingContext"),
	HX_CSTRING("childrenInline"),
	HX_CSTRING("getContainerHTMLElementData"),
	HX_CSTRING("getPositionedHTMLElementData"),
	HX_CSTRING("getformattingContext"),
	HX_CSTRING("isChildInline"),
	HX_CSTRING("getChildLastPositionedHTMLElementData"),
	HX_CSTRING("isInlineContainer"),
	HX_CSTRING("getComputedHeight"),
	HX_CSTRING("isElementNode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractContainerStyle_obj::__mClass;

void AbstractContainerStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.AbstractContainerStyle"), hx::TCanCast< AbstractContainerStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractContainerStyle_obj::__boot()
{
}

} // end namespace core
} // end namespace style
