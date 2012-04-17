#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
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
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_TextAlign
#include <core/style/TextAlign.h>
#endif
#ifndef INCLUDED_core_style_VerticalAlign
#include <core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_core_style_WhiteSpace
#include <core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_core_style_floats_FloatsManager
#include <core/style/floats/FloatsManager.h>
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
namespace core{
namespace style{
namespace formatter{

Void InlineFormattingContext_obj::__construct(::core::renderer::BlockBoxRenderer formattingContextRoot)
{
{
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",74)
	this->_elementsInLineBox = Array_obj< ::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",75)
	this->_unbreakableLineBoxElements = Array_obj< ::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",76)
	this->_unbreakableWidth = (int)0;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",77)
	this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",79)
	super::__construct(formattingContextRoot);
}
;
	return null();
}

InlineFormattingContext_obj::~InlineFormattingContext_obj() { }

Dynamic InlineFormattingContext_obj::__CreateEmpty() { return  new InlineFormattingContext_obj; }
hx::ObjectPtr< InlineFormattingContext_obj > InlineFormattingContext_obj::__new(::core::renderer::BlockBoxRenderer formattingContextRoot)
{  hx::ObjectPtr< InlineFormattingContext_obj > result = new InlineFormattingContext_obj();
	result->__construct(formattingContextRoot);
	return result;}

Dynamic InlineFormattingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineFormattingContext_obj > result = new InlineFormattingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InlineFormattingContext_obj::dispose( ){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::dispose")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",88)
		this->super::dispose();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",89)
		this->_unbreakableLineBoxElements = null();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",90)
		this->_elementsInLineBox = null();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",91)
		this->_currentInlineBoxesData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,dispose,(void))

Void InlineFormattingContext_obj::doFormat( Array< ::core::renderer::ElementRenderer > elementsInFormattingContext){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::doFormat")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",96)
		this->_elementsInLineBox = Array_obj< ::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",97)
		this->_unbreakableLineBoxElements = Array_obj< ::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",98)
		this->_unbreakableWidth = (int)0;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",100)
		this->_formattingContextRoot->removeLineBoxes();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",102)
		this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",105)
		this->super::doFormat(elementsInFormattingContext);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",107)
		this->insertBreakOpportunity(true,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,doFormat,(void))

int InlineFormattingContext_obj::getRemainingLineWidth( ){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::getRemainingLineWidth")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",116)
	return ((this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width")) - this->_formattingContextData->__Field(HX_CSTRING("x"))) - this->_floatsManager->getRightFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")),this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))));
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,getRemainingLineWidth,return )

Void InlineFormattingContext_obj::insertEmbeddedElement( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertEmbeddedElement")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",140)
		this->insertBreakOpportunity(false,null());
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",142)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",143)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",145)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",147)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertEmbeddedElement,(void))

Void InlineFormattingContext_obj::insertFormattingContextRootElement( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertFormattingContextRootElement")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",156)
		element->getBounds()->__FieldRef(HX_CSTRING("width")) = element->getStyle()->get_htmlElement()->get_offsetWidth();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",157)
		element->getBounds()->__FieldRef(HX_CSTRING("height")) = element->getStyle()->get_htmlElement()->get_offsetHeight();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",159)
		this->insertBreakOpportunity(false,null());
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",161)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",162)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",164)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",166)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertFormattingContextRootElement,(void))

Void InlineFormattingContext_obj::insertContainerElement( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertContainerElement")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",171)
		this->_unbreakableLineBoxElements->push(element);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertContainerElement,(void))

Void InlineFormattingContext_obj::insertText( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertText")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",180)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",181)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",183)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertText,(void))

Void InlineFormattingContext_obj::insertSpace( ::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertSpace")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",198)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",200)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",202)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",204)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertSpace,(void))

Void InlineFormattingContext_obj::insertHorizontalOffset( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertHorizontalOffset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertHorizontalOffset,(void))

Void InlineFormattingContext_obj::insertTab( ::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertTab")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertTab,(void))

Void InlineFormattingContext_obj::insertLineFeed( ::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertLineFeed")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertLineFeed,(void))

Void InlineFormattingContext_obj::insertBreakOpportunity( bool forced,Dynamic __o_isLastLine){
bool isLastLine = __o_isLastLine.Default(false);
	HX_SOURCE_PUSH("InlineFormattingContext_obj::insertBreakOpportunity");
{
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",299)
		int remainingLineWidth = this->getRemainingLineWidth();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",303)
		if (((isLastLine == true))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",304)
			this->insertBreakOpportunity(false,false);
		}
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",311)
		if (((bool(((remainingLineWidth - this->_unbreakableWidth) < (int)0)) || bool((forced == true))))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",312)
			this->startNewLine(this->_unbreakableWidth,isLastLine);
		}
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",319)
		{
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",319)
			int _g1 = (int)0;
			int _g = this->_unbreakableLineBoxElements->length;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",319)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",319)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",321)
				this->_elementsInLineBox->push(this->_unbreakableLineBoxElements->__get(i));
			}
		}
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",324)
		this->_unbreakableLineBoxElements = Array_obj< ::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",325)
		hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("x")),this->_unbreakableWidth);
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",327)
		this->_unbreakableWidth = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertBreakOpportunity,(void))

Void InlineFormattingContext_obj::addWidth( int width){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::addWidth")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",334)
		hx::AddEq(this->_unbreakableWidth,width);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,addWidth,(void))

bool InlineFormattingContext_obj::shouldTabBeConvertedToSpace( ::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::shouldTabBeConvertedToSpace")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",344)
	bool shouldTabBeConvertedToSpace;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",346)
	{
::core::style::WhiteSpace _switch_1 = (whiteSpace);
		switch((_switch_1)->GetIndex()){
			case 0: case 2: case 4: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",348)
				shouldTabBeConvertedToSpace = true;
			}
			;break;
			case 1: case 3: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",353)
				shouldTabBeConvertedToSpace = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",358)
	return shouldTabBeConvertedToSpace;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,shouldTabBeConvertedToSpace,return )

bool InlineFormattingContext_obj::isLineFeedAllowed( ::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::isLineFeedAllowed")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",367)
	bool lineFeedAllowed;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",369)
	{
::core::style::WhiteSpace _switch_2 = (whiteSpace);
		switch((_switch_2)->GetIndex()){
			case 0: case 2: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",371)
				lineFeedAllowed = false;
			}
			;break;
			case 1: case 3: case 4: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",375)
				lineFeedAllowed = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",381)
	return lineFeedAllowed;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,isLineFeedAllowed,return )

bool InlineFormattingContext_obj::shouldInsertSpace( ::core::style::WhiteSpace whiteSpace,bool isNexElementALineFeed){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::shouldInsertSpace")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",389)
	bool shouldInsertSpace;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",391)
	{
::core::style::WhiteSpace _switch_3 = (whiteSpace);
		switch((_switch_3)->GetIndex()){
			case 0: case 2: case 4: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",393)
				shouldInsertSpace = (isNexElementALineFeed == false);
			}
			;break;
			case 3: case 1: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",398)
				shouldInsertSpace = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",403)
	if (((shouldInsertSpace == true))){
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",404)
		(shouldInsertSpace != this->isCollapsed(this->_lastInsertedElement,whiteSpace));
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",409)
	return shouldInsertSpace;
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,shouldInsertSpace,return )

bool InlineFormattingContext_obj::isCollapsed( ::core::renderer::ElementRenderer lastInsertedElement,::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::isCollapsed")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",417)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,isCollapsed,return )

Dynamic InlineFormattingContext_obj::getParentInlineBoxesData( ::core::renderer::InlineBoxRenderer parent){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::getParentInlineBoxesData")
	struct _Function_1_1{
		inline static Dynamic Block( ::core::renderer::InlineBoxRenderer &parent){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("element") , parent,false);
			__result->Add(HX_CSTRING("children") , Array_obj< ::core::renderer::ElementRenderer >::__new(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",467)
	Dynamic inlineBoxData = _Function_1_1::Block(parent);
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",472)
	bool flagFound = false;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",473)
	{
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",473)
		int _g1 = (int)0;
		int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",473)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",473)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",475)
			if (((this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element")) == parent))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",477)
				inlineBoxData = this->_currentInlineBoxesData->__GetItem(i);
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",478)
				flagFound = true;
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",482)
	if (((flagFound == false))){
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",483)
		this->_currentInlineBoxesData->__Field(HX_CSTRING("push"))(inlineBoxData);
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",487)
	return inlineBoxData;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,getParentInlineBoxesData,return )

Void InlineFormattingContext_obj::startNewLine( int elementWidth,bool isLastLine){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::startNewLine")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",491)
		if (((this->_elementsInLineBox->length > (int)0))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",494)
			this->removeSpaces();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",495)
			int lineBoxHeight = this->computeLineBoxHeight();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",497)
			int lineWidth = this->alignLineBox(isLastLine);
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",499)
			if (((lineWidth > this->_formattingContextData->__Field(HX_CSTRING("maxWidth"))))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",500)
				this->_formattingContextData->__FieldRef(HX_CSTRING("maxWidth")) = lineWidth;
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",504)
			Array< ::core::renderer::ElementRenderer > lineBoxElements = Array_obj< ::core::renderer::ElementRenderer >::__new();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",506)
			this->_formattingContextRoot->addLineBox(lineBoxElements);
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",508)
			{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",508)
				int _g1 = (int)0;
				int _g = this->_elementsInLineBox->length;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",508)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",508)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",510)
					if (((this->_elementsInLineBox->__get(i)->get_parentNode() != this->_formattingContextRoot->getStyle()->getElementRenderer()))){
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",511)
						this->getParentInlineBoxesData(this->_elementsInLineBox->__get(i)->get_parentNode())->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("push"))(this->_elementsInLineBox->__get(i));
					}
					else{
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",516)
						lineBoxElements->push(this->_elementsInLineBox->__get(i));
					}
				}
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",521)
			{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",521)
				int _g1 = (int)0;
				int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",521)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",521)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",523)
					{
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",523)
						int _g3 = (int)0;
						int _g2 = this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("length"));
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",523)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",523)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",526)
							lineBoxElements->push(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))->__GetItem(j));
						}
					}
				}
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",532)
			Array< ::core::renderer::InlineBoxRenderer > inlineBoxes = Array_obj< ::core::renderer::InlineBoxRenderer >::__new();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",534)
			{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",534)
				int _g1 = (int)0;
				int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",534)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",534)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",537)
					::core::renderer::InlineBoxRenderer inlineBoxRenderer = ::core::renderer::InlineBoxRenderer_obj::__new(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element"))->__Field(HX_CSTRING("getStyle"))());
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",538)
					inlineBoxRenderer->setLayerRenderer(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element"))->__Field(HX_CSTRING("getLayerRenderer"))());
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",539)
					inlineBoxRenderer->setBounds(this->getBounds(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))));
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",540)
					inlineBoxes->push(inlineBoxRenderer);
				}
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",546)
			inlineBoxes->reverse();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",548)
			{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",548)
				int _g1 = (int)0;
				int _g = inlineBoxes->length;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",548)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",548)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",550)
					lineBoxElements->push(inlineBoxes->__get(i));
				}
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",555)
			this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",556)
			this->_elementsInLineBox = Array_obj< ::core::renderer::ElementRenderer >::__new();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",559)
			if (((isLastLine == false))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",561)
				hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),lineBoxHeight);
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",563)
				this->_formattingContextData->__FieldRef(HX_CSTRING("y")) = this->_floatsManager->getFirstAvailableY(this->_formattingContextData,elementWidth,this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width")));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",565)
				if ((((this->_formattingContextData->__Field(HX_CSTRING("y")) + lineBoxHeight) > this->_formattingContextData->__Field(HX_CSTRING("maxHeight"))))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",566)
					this->_formattingContextData->__FieldRef(HX_CSTRING("maxHeight")) = (this->_formattingContextData->__Field(HX_CSTRING("y")) + lineBoxHeight);
				}
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",571)
				this->_formattingContextData->__FieldRef(HX_CSTRING("x")) = this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")));
			}
			else{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",574)
				if (((this->_layOutLastLine == true))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",576)
					hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),lineBoxHeight);
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",578)
					this->_formattingContextData->__FieldRef(HX_CSTRING("y")) = this->_floatsManager->getFirstAvailableY(this->_formattingContextData,elementWidth,this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width")));
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",581)
					if (((this->_formattingContextData->__Field(HX_CSTRING("y")) > this->_formattingContextData->__Field(HX_CSTRING("maxHeight"))))){
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",582)
						this->_formattingContextData->__FieldRef(HX_CSTRING("maxHeight")) = this->_formattingContextData->__Field(HX_CSTRING("y"));
					}
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",586)
					this->_formattingContextData->__FieldRef(HX_CSTRING("x")) = this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,startNewLine,(void))

Void InlineFormattingContext_obj::removeSpaces( ){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::removeSpaces")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,removeSpaces,(void))

int InlineFormattingContext_obj::alignLineBox( bool isLastLine){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::alignLineBox")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",662)
	int concatenatedLength = (int)0;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",663)
	{
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",663)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",663)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",663)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",665)
			hx::AddEq(concatenatedLength,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",673)
	int remainingSpace;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",674)
	int flowX;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",676)
	remainingSpace = (((this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width")) - concatenatedLength) - this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")))) - this->_floatsManager->getRightFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")),this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))));
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",678)
	flowX = this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"));
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",681)
	hx::AddEq(flowX,this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y"))));
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",685)
	{
::core::style::TextAlign _switch_4 = (this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("textAlign")));
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",687)
				this->alignLeft(flowX);
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",690)
				this->alignRight(flowX,remainingSpace);
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",693)
				this->alignCenter(flowX,remainingSpace);
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",696)
				if (((isLastLine == true))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",701)
					this->alignLeft(flowX);
				}
				else{
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",708)
					concatenatedLength = this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("width"));
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",710)
					this->alignJustify(flowX,remainingSpace);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",714)
	return concatenatedLength;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,alignLineBox,return )

Void InlineFormattingContext_obj::alignLeft( int flowX){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignLeft")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",723)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",723)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",723)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",725)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = flowX;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",726)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,alignLeft,(void))

Void InlineFormattingContext_obj::alignCenter( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignCenter")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",739)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",739)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",739)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",741)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = (::Math_obj::round((double(remainingSpace) / double((int)2))) + flowX);
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",742)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignCenter,(void))

Void InlineFormattingContext_obj::alignRight( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignRight")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",755)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",755)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",755)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",757)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = (flowX + remainingSpace);
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",758)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignRight,(void))

Void InlineFormattingContext_obj::alignJustify( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignJustify")
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",772)
		int spacesNumber = (int)0;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",773)
		{
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",773)
			int _g1 = (int)0;
			int _g = this->_elementsInLineBox->length;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",773)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",773)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",775)
				if (((this->_elementsInLineBox->__get(i)->isSpace() == true))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",776)
					(spacesNumber)++;
				}
			}
		}
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",782)
		{
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",782)
			int _g1 = (int)0;
			int _g = this->_elementsInLineBox->length;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",782)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",782)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",784)
				if (((this->_elementsInLineBox->__get(i)->isSpace() == true))){
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",786)
					int spaceWidth = ::Math_obj::round((double(remainingSpace) / double(spacesNumber)));
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",787)
					(spacesNumber)--;
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",788)
					hx::SubEq(remainingSpace,spaceWidth);
					HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",789)
					hx::AddEq(flowX,spaceWidth);
				}
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",792)
				this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = flowX;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",793)
				hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignJustify,(void))

int InlineFormattingContext_obj::computeLineBoxHeight( ){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::computeLineBoxHeight")
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",817)
	double lineBoxAscent = (int)0;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",818)
	double lineBoxDescent = (int)0;
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",822)
	{
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",822)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",822)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",822)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",825)
			::port::flash_player::HTMLElement htmlElement = this->_elementsInLineBox->__get(i)->getStyle()->get_htmlElement();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",827)
			int htmlElementAscent;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",828)
			int htmlElementDescent;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",832)
			double htmlElementVerticalAlign = htmlElement->get_style()->getComputedStyle()->__Field(HX_CSTRING("verticalAlign"));
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",836)
			if (((bool((bool((this->_elementsInLineBox->__get(i)->isEmbedded() == true)) && bool((this->_elementsInLineBox->__get(i)->isText() == false)))) || bool((this->_elementsInLineBox->__get(i)->establishesNewFormattingContext() == true))))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",839)
				htmlElementAscent = ((htmlElement->get_offsetHeight() + this->_elementsInLineBox->__get(i)->getStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) + this->_elementsInLineBox->__get(i)->getStyle()->getComputedStyle()->__Field(HX_CSTRING("marginBottom")));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",841)
				htmlElementDescent = (int)0;
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",843)
				{
::core::style::VerticalAlign _switch_5 = (htmlElement->get_style()->getVerticalAlign());
					switch((_switch_5)->GetIndex()){
						case 3: {
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",846)
							htmlElementAscent = ::Math_obj::round(lineBoxAscent);
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",847)
							htmlElementDescent = ::Math_obj::round((htmlElement->get_offsetHeight() - lineBoxAscent));
						}
						;break;
						default: {
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",856)
				htmlElementAscent = htmlElement->get_style()->getFontMetricsData()->__Field(HX_CSTRING("ascent"));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",857)
				htmlElementDescent = htmlElement->get_style()->getFontMetricsData()->__Field(HX_CSTRING("descent"));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",861)
				double leading = (htmlElement->get_style()->getComputedStyle()->__Field(HX_CSTRING("lineHeight")) - ((htmlElementAscent + htmlElementDescent)));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",864)
				htmlElementAscent = ::Math_obj::round((htmlElementAscent + (double(leading) / double((int)2))));
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",865)
				htmlElementDescent = ::Math_obj::round((htmlElementDescent + (double(leading) / double((int)2))));
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",870)
			if ((((htmlElementAscent - htmlElementVerticalAlign) > lineBoxAscent))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",871)
				lineBoxAscent = (htmlElementAscent - htmlElementVerticalAlign);
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",875)
			if ((((htmlElementDescent + htmlElementVerticalAlign) > lineBoxDescent))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",876)
				lineBoxDescent = (htmlElementDescent + htmlElementVerticalAlign);
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",883)
	double lineBoxHeight = (lineBoxAscent + lineBoxDescent);
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",886)
	{
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",886)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",886)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",886)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",889)
			::port::flash_player::HTMLElement htmlElement = this->_elementsInLineBox->__get(i)->getStyle()->get_htmlElement();
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",891)
			double verticalAlign;
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",892)
			{
::core::style::VerticalAlign _switch_6 = (htmlElement->get_style()->getVerticalAlign());
				switch((_switch_6)->GetIndex()){
					case 3: {
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",894)
						verticalAlign = (int)0;
					}
					;break;
					case 6: {
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",898)
						verticalAlign = (int)0;
					}
					;break;
					default: {
						HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",901)
						verticalAlign = htmlElement->get_style()->getComputedStyle()->__Field(HX_CSTRING("verticalAlign"));
					}
				}
			}
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",905)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")) = (((::Math_obj::round(lineBoxAscent) + ::Math_obj::round(verticalAlign)) + this->_formattingContextData->__Field(HX_CSTRING("y"))) + this->_formattingContextRoot->getStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
			HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",913)
			if (((bool((bool((this->_elementsInLineBox->__get(i)->isEmbedded() == true)) && bool((this->_elementsInLineBox->__get(i)->isText() == false)))) || bool((this->_elementsInLineBox->__get(i)->establishesNewFormattingContext() == true))))){
				HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",915)
				{
::core::style::VerticalAlign _switch_7 = (htmlElement->get_style()->getVerticalAlign());
					switch((_switch_7)->GetIndex()){
						case 3: {
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",919)
							this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")) = this->_formattingContextData->__Field(HX_CSTRING("y"));
						}
						;break;
						default: {
							HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",922)
							hx::SubEq(this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")),((htmlElement->get_offsetHeight() + this->_elementsInLineBox->__get(i)->getStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) + this->_elementsInLineBox->__get(i)->getStyle()->getComputedStyle()->__Field(HX_CSTRING("marginBottom"))));
						}
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/formatter/InlineFormattingContext.hx",931)
	return ::Math_obj::round(lineBoxHeight);
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,computeLineBoxHeight,return )


InlineFormattingContext_obj::InlineFormattingContext_obj()
{
}

void InlineFormattingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineFormattingContext);
	HX_MARK_MEMBER_NAME(_elementsInLineBox,"_elementsInLineBox");
	HX_MARK_MEMBER_NAME(_unbreakableLineBoxElements,"_unbreakableLineBoxElements");
	HX_MARK_MEMBER_NAME(_unbreakableWidth,"_unbreakableWidth");
	HX_MARK_MEMBER_NAME(_currentInlineBoxesData,"_currentInlineBoxesData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InlineFormattingContext_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"doFormat") ) { return doFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"addWidth") ) { return addWidth_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"insertTab") ) { return insertTab_dyn(); }
		if (HX_FIELD_EQ(inName,"alignLeft") ) { return alignLeft_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"insertText") ) { return insertText_dyn(); }
		if (HX_FIELD_EQ(inName,"alignRight") ) { return alignRight_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"insertSpace") ) { return insertSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"isCollapsed") ) { return isCollapsed_dyn(); }
		if (HX_FIELD_EQ(inName,"alignCenter") ) { return alignCenter_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startNewLine") ) { return startNewLine_dyn(); }
		if (HX_FIELD_EQ(inName,"removeSpaces") ) { return removeSpaces_dyn(); }
		if (HX_FIELD_EQ(inName,"alignLineBox") ) { return alignLineBox_dyn(); }
		if (HX_FIELD_EQ(inName,"alignJustify") ) { return alignJustify_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"insertLineFeed") ) { return insertLineFeed_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_unbreakableWidth") ) { return _unbreakableWidth; }
		if (HX_FIELD_EQ(inName,"isLineFeedAllowed") ) { return isLineFeedAllowed_dyn(); }
		if (HX_FIELD_EQ(inName,"shouldInsertSpace") ) { return shouldInsertSpace_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_elementsInLineBox") ) { return _elementsInLineBox; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeLineBoxHeight") ) { return computeLineBoxHeight_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getRemainingLineWidth") ) { return getRemainingLineWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"insertEmbeddedElement") ) { return insertEmbeddedElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"insertContainerElement") ) { return insertContainerElement_dyn(); }
		if (HX_FIELD_EQ(inName,"insertHorizontalOffset") ) { return insertHorizontalOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBreakOpportunity") ) { return insertBreakOpportunity_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_currentInlineBoxesData") ) { return _currentInlineBoxesData; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getParentInlineBoxesData") ) { return getParentInlineBoxesData_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_unbreakableLineBoxElements") ) { return _unbreakableLineBoxElements; }
		if (HX_FIELD_EQ(inName,"shouldTabBeConvertedToSpace") ) { return shouldTabBeConvertedToSpace_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"insertFormattingContextRootElement") ) { return insertFormattingContextRootElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InlineFormattingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"_unbreakableWidth") ) { _unbreakableWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_elementsInLineBox") ) { _elementsInLineBox=inValue.Cast< Array< ::core::renderer::ElementRenderer > >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_currentInlineBoxesData") ) { _currentInlineBoxesData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_unbreakableLineBoxElements") ) { _unbreakableLineBoxElements=inValue.Cast< Array< ::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void InlineFormattingContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_elementsInLineBox"));
	outFields->push(HX_CSTRING("_unbreakableLineBoxElements"));
	outFields->push(HX_CSTRING("_unbreakableWidth"));
	outFields->push(HX_CSTRING("_currentInlineBoxesData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_elementsInLineBox"),
	HX_CSTRING("_unbreakableLineBoxElements"),
	HX_CSTRING("_unbreakableWidth"),
	HX_CSTRING("_currentInlineBoxesData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("doFormat"),
	HX_CSTRING("getRemainingLineWidth"),
	HX_CSTRING("insertEmbeddedElement"),
	HX_CSTRING("insertFormattingContextRootElement"),
	HX_CSTRING("insertContainerElement"),
	HX_CSTRING("insertText"),
	HX_CSTRING("insertSpace"),
	HX_CSTRING("insertHorizontalOffset"),
	HX_CSTRING("insertTab"),
	HX_CSTRING("insertLineFeed"),
	HX_CSTRING("insertBreakOpportunity"),
	HX_CSTRING("addWidth"),
	HX_CSTRING("shouldTabBeConvertedToSpace"),
	HX_CSTRING("isLineFeedAllowed"),
	HX_CSTRING("shouldInsertSpace"),
	HX_CSTRING("isCollapsed"),
	HX_CSTRING("getParentInlineBoxesData"),
	HX_CSTRING("startNewLine"),
	HX_CSTRING("removeSpaces"),
	HX_CSTRING("alignLineBox"),
	HX_CSTRING("alignLeft"),
	HX_CSTRING("alignCenter"),
	HX_CSTRING("alignRight"),
	HX_CSTRING("alignJustify"),
	HX_CSTRING("computeLineBoxHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InlineFormattingContext_obj::__mClass;

void InlineFormattingContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.formatter.InlineFormattingContext"), hx::TCanCast< InlineFormattingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InlineFormattingContext_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace formatter
