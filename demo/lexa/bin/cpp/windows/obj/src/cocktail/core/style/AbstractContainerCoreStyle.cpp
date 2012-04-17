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
#ifndef INCLUDED_cocktail_core_style_AbstractContainerCoreStyle
#include <cocktail/core/style/AbstractContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
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
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void AbstractContainerCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",64)
	super::__construct(htmlElement);
}
;
	return null();
}

AbstractContainerCoreStyle_obj::~AbstractContainerCoreStyle_obj() { }

Dynamic AbstractContainerCoreStyle_obj::__CreateEmpty() { return  new AbstractContainerCoreStyle_obj; }
hx::ObjectPtr< AbstractContainerCoreStyle_obj > AbstractContainerCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractContainerCoreStyle_obj > result = new AbstractContainerCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractContainerCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractContainerCoreStyle_obj > result = new AbstractContainerCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::renderer::ElementRenderer AbstractContainerCoreStyle_obj::createElementRenderer( ::cocktail::core::renderer::FlowBoxRenderer parentElementRenderer){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::createElementRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",79)
	::cocktail::core::renderer::ElementRenderer elementRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",81)
	if (((bool((this->isInlineLevel() == true)) && bool((this->establishesNewFormattingContext() == false))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",82)
		elementRenderer = ::cocktail::core::renderer::InlineBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",86)
		elementRenderer = ::cocktail::core::renderer::BlockBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",90)
	elementRenderer->setLayerRenderer(this->getLayerRenderer(elementRenderer,parentElementRenderer));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",91)
	parentElementRenderer->appendChild(elementRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",93)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerCoreStyle_obj,createElementRenderer,return )

Void AbstractContainerCoreStyle_obj::layout( Dynamic containingHTMLElementData,Dynamic lastPositionedHTMLElementData,Dynamic viewportData,Dynamic containingHTMLElementFontMetricsData){
{
		HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::layout")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",105)
		this->flow(containingHTMLElementData,viewportData,lastPositionedHTMLElementData,null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(AbstractContainerCoreStyle_obj,layout,(void))

Void AbstractContainerCoreStyle_obj::flowChildren( Dynamic containingHTMLElementData,Dynamic viewportData,Dynamic lastPositionedHTMLElementData,Dynamic containingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext formattingContext){
{
		HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::flowChildren")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",124)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",124)
			int _g1 = (int)0;
			int _g = this->_htmlElement->get_childNodes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",124)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",124)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",130)
				if (((this->_htmlElement->get_childNodes()->__get(i)->get_nodeType() == (int)1))){
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",132)
					::cocktail::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",133)
					childHTMLElement->get_coreStyle()->computeDisplayStyles();
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",141)
		::cocktail::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",147)
		Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",151)
		Dynamic childrenContainingHTMLElementFontMetricsData = this->getFontMetricsData();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",155)
		Dynamic childLastPositionedHTMLElementData;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",163)
		childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",167)
		childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",173)
		if (((this->_width == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",174)
			this->shrinkToFitIfNeeded(containingHTMLElementData,childrenFormattingContext->getMaxWidth(),formattingContext,lastPositionedHTMLElementData,viewportData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",185)
		if (((this->_height == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",194)
			if (((this->establishesNewFormattingContext() == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",195)
				childrenFormattingContext->format();
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",199)
			this->_computedStyle->__FieldRef(HX_CSTRING("height")) = this->applyContentHeightIfNeeded(containingHTMLElementData,childrenFormattingContext->getChildrenHeight(this->_elementRenderer));
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",204)
		this->positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData,viewportData);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",207)
		if (((this->establishesNewFormattingContext() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",208)
			childrenFormattingContext->dispose();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerCoreStyle_obj,flowChildren,(void))

::cocktail::core::style::formatter::FormattingContext AbstractContainerCoreStyle_obj::doFlowChildren( Dynamic childrenContainingHTMLElementData,Dynamic viewportData,Dynamic childLastPositionedHTMLElementData,Dynamic childrenContainingHTMLElementFontMetricsData,::cocktail::core::style::formatter::FormattingContext childrenFormattingContext){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::doFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",226)
	::cocktail::core::renderer::FlowBoxRenderer flowBoxRenderer = this->_elementRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",229)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",229)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",229)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",229)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",232)
			if (((this->_htmlElement->get_childNodes()->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",234)
				::cocktail::port::flash_player::HTMLElement childHTMLElement = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",237)
				childHTMLElement->get_coreStyle()->flow(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,childrenContainingHTMLElementFontMetricsData,childrenFormattingContext,this->_elementRenderer);
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",243)
				::cocktail::port::flash_player::Text childrenText = this->_htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",244)
				Array< ::cocktail::core::renderer::TextRenderer > insertedText = this->insertTextElement(childrenText,childrenFormattingContext,childrenContainingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",248)
				{
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",248)
					int _g3 = (int)0;
					int _g2 = insertedText->length;
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",248)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",248)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",250)
						flowBoxRenderer->appendChild(insertedText->__get(j));
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",262)
	if (((this->establishesNewFormattingContext() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",263)
		childrenFormattingContext->format();
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",267)
	return childrenFormattingContext;
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerCoreStyle_obj,doFlowChildren,return )

Void AbstractContainerCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::positionAbsolutelyPositionedHTMLElementsIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",274)
		if (((this->isPositioned() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",276)
			this->doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData,viewportData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,positionAbsolutelyPositionedHTMLElementsIfNeeded,(void))

Void AbstractContainerCoreStyle_obj::doPositionAbsolutelyPositionedHTMLElements( Dynamic childLastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::doPositionAbsolutelyPositionedHTMLElements")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",290)
		childLastPositionedHTMLElementData->__FieldRef(HX_CSTRING("data")) = this->getPositionedHTMLElementData();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",293)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",293)
			int _g1 = (int)0;
			int _g = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",293)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",293)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",295)
				Dynamic positionedHTMLElementData = childLastPositionedHTMLElementData->__Field(HX_CSTRING("children"))->__GetItem(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",299)
				positionedHTMLElementData->__Field(HX_CSTRING("coreStyle"))->__Field(HX_CSTRING("positionElement"))(childLastPositionedHTMLElementData->__Field(HX_CSTRING("data")),viewportData,positionedHTMLElementData->__Field(HX_CSTRING("staticPosition")));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,doPositionAbsolutelyPositionedHTMLElements,(void))

Array< ::cocktail::core::renderer::TextRenderer > AbstractContainerCoreStyle_obj::insertTextElement( ::cocktail::port::flash_player::Text textElement,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::insertTextElement")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",317)
	Array< ::cocktail::core::renderer::TextRenderer > rendereredText = Array_obj< ::cocktail::core::renderer::TextRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",320)
	::String text = textElement->get_nodeValue();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",323)
	Dynamic textFragments = textElement->getTextFragments(text);
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",326)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",326)
		int _g1 = (int)0;
		int _g = textFragments->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",326)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",326)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",328)
			::cocktail::core::renderer::TextRenderer textRenderer = this->createTextRendererFromTextFragment(textFragments->__GetItem(i));
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",329)
			formattingContext->insertElement(textRenderer);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",330)
			rendereredText->push(textRenderer);
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",333)
	return rendereredText;
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractContainerCoreStyle_obj,insertTextElement,return )

::cocktail::core::renderer::TextRenderer AbstractContainerCoreStyle_obj::createTextRendererFromTextFragment( Dynamic textFragment){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::createTextRendererFromTextFragment")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",342)
	::String text;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",344)
	{
::cocktail::core::dom::TextTokenValue _switch_1 = (textFragment->__Field(HX_CSTRING("textToken")));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::String value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",346)
					text = value;
				}
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",349)
				text = HX_CSTRING(" ");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",353)
				text = HX_CSTRING("");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",356)
				text = HX_CSTRING("");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",360)
	::cocktail::core::renderer::TextRenderer textRenderer = this->getTextRenderer(textFragment,text);
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",362)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerCoreStyle_obj,createTextRendererFromTextFragment,return )

Void AbstractContainerCoreStyle_obj::shrinkToFitIfNeeded( Dynamic containingHTMLElementData,int minimumWidth,::cocktail::core::style::formatter::FormattingContext formattingContext,Dynamic lastPositionedHTMLElementData,Dynamic viewportData){
{
		HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::shrinkToFitIfNeeded")
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",381)
		::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",382)
		int shrinkedWidth = boxComputer->shrinkToFit(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,minimumWidth);
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",386)
		if (((this->_computedStyle->__Field(HX_CSTRING("width")) != shrinkedWidth))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",389)
			this->_computedStyle->__FieldRef(HX_CSTRING("width")) = shrinkedWidth;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",392)
			::cocktail::core::style::formatter::FormattingContext childrenFormattingContext = this->getformattingContext(formattingContext);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",393)
			Dynamic childrenContainingHTMLElementData = this->getContainerHTMLElementData();
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",394)
			Dynamic childLastPositionedHTMLElementData = this->getChildLastPositionedHTMLElementData(lastPositionedHTMLElementData);
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",395)
			childrenFormattingContext = this->doFlowChildren(childrenContainingHTMLElementData,viewportData,childLastPositionedHTMLElementData,this->getFontMetricsData(),childrenFormattingContext);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(AbstractContainerCoreStyle_obj,shrinkToFitIfNeeded,(void))

int AbstractContainerCoreStyle_obj::applyContentHeightIfNeeded( Dynamic containingHTMLElementData,int childrenHeight){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::applyContentHeightIfNeeded")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",410)
	::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer = this->getBoxStylesComputer();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",411)
	return boxComputer->applyContentHeight(hx::ObjectPtr<OBJ_>(this),containingHTMLElementData,childrenHeight);
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,applyContentHeightIfNeeded,return )

::cocktail::core::style::computer::boxComputers::BoxStylesComputer AbstractContainerCoreStyle_obj::getBoxStylesComputer( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getBoxStylesComputer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",425)
	::cocktail::core::style::computer::boxComputers::BoxStylesComputer boxComputer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",428)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",429)
		boxComputer = ::cocktail::core::style::computer::boxComputers::FloatBoxStylesComputer_obj::__new();
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",434)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",435)
			boxComputer = ::cocktail::core::style::computer::boxComputers::PositionedBoxStylesComputer_obj::__new();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",441)
			{
::cocktail::core::style::Display _switch_2 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_2)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",444)
						boxComputer = ::cocktail::core::style::computer::boxComputers::BlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",447)
						boxComputer = ::cocktail::core::style::computer::boxComputers::InlineBlockBoxStylesComputer_obj::__new();
					}
					;break;
					case 3: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",451)
						boxComputer = null();
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",454)
						boxComputer = ::cocktail::core::style::computer::boxComputers::InLineBoxStylesComputer_obj::__new();
					}
					;break;
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",459)
	return boxComputer;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,getBoxStylesComputer,return )

::cocktail::core::renderer::TextRenderer AbstractContainerCoreStyle_obj::getTextRenderer( Dynamic textFragmentData,::String text){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getTextRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",473)
	::cocktail::core::renderer::TextRenderer textRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",474)
	textRenderer = this->createTextRenderer(text,textFragmentData->__Field(HX_CSTRING("textToken")));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",475)
	textRenderer->setLayerRenderer(this->_elementRenderer->getLayerRenderer());
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",476)
	textFragmentData->__FieldRef(HX_CSTRING("textRenderer")) = textRenderer;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",490)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,getTextRenderer,return )

::cocktail::core::renderer::TextRenderer AbstractContainerCoreStyle_obj::createTextRenderer( ::String text,::cocktail::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::createTextRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",498)
	return this->doCreateTextRenderer(text,textToken);
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,createTextRenderer,return )

::cocktail::core::renderer::TextRenderer AbstractContainerCoreStyle_obj::doCreateTextRenderer( ::String text,::cocktail::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::doCreateTextRenderer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",507)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractContainerCoreStyle_obj,doCreateTextRenderer,return )

bool AbstractContainerCoreStyle_obj::establishesNewFormattingContext( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::establishesNewFormattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",522)
	bool ret = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",525)
	if (((this->isFloat() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",526)
		ret = true;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",530)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",531)
			ret = true;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",537)
			{
::cocktail::core::style::Display _switch_3 = (this->_computedStyle->__Field(HX_CSTRING("display")));
				switch((_switch_3)->GetIndex()){
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",540)
						ret = true;
					}
					;break;
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",546)
						if (((this->childrenInline() == true))){
							HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",548)
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
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",559)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,establishesNewFormattingContext,return )

bool AbstractContainerCoreStyle_obj::childrenInline( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::childrenInline")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",575)
	if (((this->_htmlElement->get_childNodes()->length == (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",576)
		return false;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",582)
	bool ret = this->isChildInline(this->_htmlElement->get_childNodes()->__get((int)0));
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",586)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",586)
		int _g1 = (int)0;
		int _g = this->_htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",586)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",586)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",588)
			if (((this->isChildInline(this->_htmlElement->get_childNodes()->__get(i)) != ret))){
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",594)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,childrenInline,return )

Dynamic AbstractContainerCoreStyle_obj::getContainerHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getContainerHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",607)
	int height;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",612)
	if (((this->isInlineLevel() == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",613)
		height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",618)
		if (((bool((this->establishesNewFormattingContext() == true)) && bool((this->childrenInline() == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",619)
			height = ::Math_obj::round(this->_computedStyle->__Field(HX_CSTRING("lineHeight")));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",625)
			height = this->_computedStyle->__Field(HX_CSTRING("height"));
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::style::AbstractContainerCoreStyle_obj *__this,int &height){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("width") , __this->_computedStyle->__Field(HX_CSTRING("width")),false);
			__result->Add(HX_CSTRING("isWidthAuto") , (__this->_width == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),false);
			__result->Add(HX_CSTRING("height") , height,false);
			__result->Add(HX_CSTRING("isHeightAuto") , (__this->_height == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",629)
	return _Function_1_1::Block(this,height);
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,getContainerHTMLElementData,return )

Dynamic AbstractContainerCoreStyle_obj::getPositionedHTMLElementData( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",648)
	Dynamic positionedHTMLElementData = this->getContainerHTMLElementData();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",651)
	positionedHTMLElementData->__FieldRef(HX_CSTRING("height")) = this->getComputedHeight();
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",653)
	return positionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,getPositionedHTMLElementData,return )

::cocktail::core::style::formatter::FormattingContext AbstractContainerCoreStyle_obj::getformattingContext( ::cocktail::core::style::formatter::FormattingContext previousformattingContext){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getformattingContext")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",674)
	::cocktail::core::style::formatter::FormattingContext formattingContext;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",677)
	if (((bool((this->establishesNewFormattingContext() == true)) || bool((previousformattingContext == null()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",679)
		::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot = this->_elementRenderer;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",683)
		if (((this->childrenInline() == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",684)
			formattingContext = ::cocktail::core::style::formatter::InlineFormattingContext_obj::__new(formattingContextRoot);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",688)
			formattingContext = ::cocktail::core::style::formatter::BlockFormattingContext_obj::__new(formattingContextRoot);
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",693)
		formattingContext = previousformattingContext;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",697)
	return formattingContext;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerCoreStyle_obj,getformattingContext,return )

bool AbstractContainerCoreStyle_obj::isChildInline( ::cocktail::core::dom::Node child){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::isChildInline")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",705)
	bool ret = true;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",708)
	if (((child->get_nodeType() == (int)1))){
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",710)
		::cocktail::port::flash_player::HTMLElement childHTMLElement = child;
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",712)
		if (((childHTMLElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("display")) == ::cocktail::core::style::Display_obj::block_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",713)
			if (((childHTMLElement->get_coreStyle()->isFloat() == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",716)
				ret = false;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",720)
				if (((bool((childHTMLElement->get_coreStyle()->isPositioned() == false)) || bool((childHTMLElement->get_coreStyle()->isRelativePositioned() == true))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",721)
					ret = false;
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",727)
			ret = true;
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",734)
		ret = true;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",738)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerCoreStyle_obj,isChildInline,return )

Dynamic AbstractContainerCoreStyle_obj::getChildLastPositionedHTMLElementData( Dynamic lastPositionedHTMLElementData){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getChildLastPositionedHTMLElementData")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",748)
	Dynamic childLastPositionedHTMLElementData;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",750)
	if (((this->isPositioned() == true))){
		struct _Function_2_1{
			inline static Dynamic Block( ::cocktail::core::style::AbstractContainerCoreStyle_obj *__this){
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("data") , __this->getContainerHTMLElementData(),false);
				__result->Add(HX_CSTRING("children") , Dynamic( Array_obj<Dynamic>::__new() ),false);
				return __result;
			}
		};
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",751)
		childLastPositionedHTMLElementData = _Function_2_1::Block(this);
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",758)
		childLastPositionedHTMLElementData = lastPositionedHTMLElementData;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",762)
	return childLastPositionedHTMLElementData;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractContainerCoreStyle_obj,getChildLastPositionedHTMLElementData,return )

bool AbstractContainerCoreStyle_obj::isInlineContainer( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::isInlineContainer")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",778)
	bool ret;
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",780)
	{
::cocktail::core::style::Display _switch_4 = (this->_computedStyle->__Field(HX_CSTRING("display")));
		switch((_switch_4)->GetIndex()){
			case 0: case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",782)
				ret = false;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",785)
				ret = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",788)
				ret = true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",792)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,isInlineContainer,return )

int AbstractContainerCoreStyle_obj::getComputedHeight( ){
	HX_SOURCE_PUSH("AbstractContainerCoreStyle_obj::getComputedHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractContainerCoreStyle.hx",801)
	return this->_computedStyle->__Field(HX_CSTRING("height"));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractContainerCoreStyle_obj,getComputedHeight,return )


AbstractContainerCoreStyle_obj::AbstractContainerCoreStyle_obj()
{
}

void AbstractContainerCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractContainerCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractContainerCoreStyle_obj::__Field(const ::String &inName)
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

Dynamic AbstractContainerCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractContainerCoreStyle_obj::__GetFields(Array< ::String> &outFields)
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
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractContainerCoreStyle_obj::__mClass;

void AbstractContainerCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.AbstractContainerCoreStyle"), hx::TCanCast< AbstractContainerCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractContainerCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
