#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CascadeManager
#include <cocktail/core/css/CascadeManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_InitialStyleDeclaration
#include <cocktail/core/css/InitialStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#include <cocktail/core/invalidation/InvalidationManager.h>
#endif
#ifndef INCLUDED_cocktail_core_parser_DOMParser
#include <cocktail/core/parser/DOMParser.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLElement_obj::__construct(::String tagName)
{
HX_STACK_PUSH("HTMLElement::new","cocktail/core/html/HTMLElement.hx",325);
{
	HX_STACK_LINE(326)
	super::__construct(tagName);
	HX_STACK_LINE(327)
	this->init();
	HX_STACK_LINE(329)
	this->attachedToDOM = false;
	HX_STACK_LINE(330)
	this->_needsCascading = false;
	HX_STACK_LINE(331)
	this->_needsStyleDeclarationUpdate = false;
	HX_STACK_LINE(332)
	this->_shouldCascadeAllProperties = true;
	HX_STACK_LINE(333)
	this->_needsElementRendererUpdate = true;
	HX_STACK_LINE(334)
	this->_pendingChangedProperties = Array_obj< int >::__new();
	HX_STACK_LINE(336)
	this->_initialStyleDeclaration = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();
}
;
	return null();
}

HTMLElement_obj::~HTMLElement_obj() { }

Dynamic HTMLElement_obj::__CreateEmpty() { return  new HTMLElement_obj; }
hx::ObjectPtr< HTMLElement_obj > HTMLElement_obj::__new(::String tagName)
{  hx::ObjectPtr< HTMLElement_obj > result = new HTMLElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic HTMLElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLElement_obj > result = new HTMLElement_obj();
	result->__construct(inArgs[0]);
	return result;}

int HTMLElement_obj::get_clientLeft( ){
	HX_STACK_PUSH("HTMLElement::get_clientLeft","cocktail/core/html/HTMLElement.hx",1926);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1927)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1928)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1930)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1931)
		return ::Math_obj::round(usedValues->borderBottomWidth);
	}
	HX_STACK_LINE(1933)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_clientLeft,return )

int HTMLElement_obj::get_clientTop( ){
	HX_STACK_PUSH("HTMLElement::get_clientTop","cocktail/core/html/HTMLElement.hx",1915);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1916)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1917)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1919)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1920)
		return ::Math_obj::round(usedValues->borderTopWidth);
	}
	HX_STACK_LINE(1922)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_clientTop,return )

int HTMLElement_obj::get_clientHeight( ){
	HX_STACK_PUSH("HTMLElement::get_clientHeight","cocktail/core/html/HTMLElement.hx",1903);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1904)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1905)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1907)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1908)
		return ::Math_obj::round(((usedValues->height + usedValues->paddingTop) + usedValues->paddingBottom));
	}
	HX_STACK_LINE(1911)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_clientHeight,return )

int HTMLElement_obj::get_clientWidth( ){
	HX_STACK_PUSH("HTMLElement::get_clientWidth","cocktail/core/html/HTMLElement.hx",1891);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1892)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1893)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1895)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1896)
		return ::Math_obj::round(((usedValues->width + usedValues->paddingLeft) + usedValues->paddingRight));
	}
	HX_STACK_LINE(1899)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_clientWidth,return )

int HTMLElement_obj::get_offsetTop( ){
	HX_STACK_PUSH("HTMLElement::get_offsetTop","cocktail/core/html/HTMLElement.hx",1870);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1871)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1872)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1874)
		::cocktail::core::html::HTMLElement offsetParent = this->get_offsetParent();		HX_STACK_VAR(offsetParent,"offsetParent");
		HX_STACK_LINE(1876)
		if (((offsetParent == null()))){
			HX_STACK_LINE(1877)
			return ::Math_obj::round(this->elementRenderer->globalBounds->y);
		}
		else{
			HX_STACK_LINE(1882)
			return ::Math_obj::round((this->elementRenderer->globalBounds->y - offsetParent->elementRenderer->globalBounds->y));
		}
	}
	HX_STACK_LINE(1887)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_offsetTop,return )

int HTMLElement_obj::get_offsetLeft( ){
	HX_STACK_PUSH("HTMLElement::get_offsetLeft","cocktail/core/html/HTMLElement.hx",1849);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1850)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1851)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1853)
		::cocktail::core::html::HTMLElement offsetParent = this->get_offsetParent();		HX_STACK_VAR(offsetParent,"offsetParent");
		HX_STACK_LINE(1855)
		if (((offsetParent == null()))){
			HX_STACK_LINE(1856)
			return ::Math_obj::round(this->elementRenderer->globalBounds->x);
		}
		else{
			HX_STACK_LINE(1861)
			return ::Math_obj::round((this->elementRenderer->globalBounds->x - offsetParent->elementRenderer->globalBounds->x));
		}
	}
	HX_STACK_LINE(1866)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_offsetLeft,return )

int HTMLElement_obj::get_offsetHeight( ){
	HX_STACK_PUSH("HTMLElement::get_offsetHeight","cocktail/core/html/HTMLElement.hx",1837);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1838)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1839)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1841)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1842)
		return ::Math_obj::round(((((usedValues->height + usedValues->paddingTop) + usedValues->paddingBottom) + usedValues->borderTopWidth) + usedValues->borderBottomWidth));
	}
	HX_STACK_LINE(1845)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_offsetHeight,return )

int HTMLElement_obj::get_offsetWidth( ){
	HX_STACK_PUSH("HTMLElement::get_offsetWidth","cocktail/core/html/HTMLElement.hx",1823);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1826)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1827)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1829)
		::cocktail::core::css::UsedValuesVO usedValues = this->coreStyle->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
		HX_STACK_LINE(1830)
		return ::Math_obj::round(((((usedValues->width + usedValues->paddingLeft) + usedValues->paddingRight) + usedValues->borderLeftWidth) + usedValues->borderRightWidth));
	}
	HX_STACK_LINE(1833)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_offsetWidth,return )

::cocktail::core::html::HTMLElement HTMLElement_obj::get_offsetParent( ){
	HX_STACK_PUSH("HTMLElement::get_offsetParent","cocktail/core/html/HTMLElement.hx",1791);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1794)
	if (((this->elementRenderer == null()))){
		HX_STACK_LINE(1795)
		return null();
	}
	HX_STACK_LINE(1800)
	{
		::cocktail::core::css::CSSKeywordValue _switch_1 = (this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)1)));
		switch((_switch_1)->GetIndex()){
			case 35: {
				HX_STACK_LINE(1802)
				return null();
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1809)
	::cocktail::core::html::HTMLElement parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(1810)
	while(((parent != null()))){
		HX_STACK_LINE(1812)
		if (((bool((parent->elementRenderer->isPositioned() == true)) || bool((parent->tagName == HX_CSTRING("BODY")))))){
			HX_STACK_LINE(1813)
			return parent;
		}
		HX_STACK_LINE(1816)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(1819)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_offsetParent,return )

bool HTMLElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLElement::isVoidElement","cocktail/core/html/HTMLElement.hx",1775);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1775)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isVoidElement,return )

::String HTMLElement_obj::get_outerHTML( ){
	HX_STACK_PUSH("HTMLElement::get_outerHTML","cocktail/core/html/HTMLElement.hx",1761);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1763)
	::String str = ::cocktail::core::parser::DOMParser_obj::serialize(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(1765)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_outerHTML,return )

::String HTMLElement_obj::get_innerHTML( ){
	HX_STACK_PUSH("HTMLElement::get_innerHTML","cocktail/core/html/HTMLElement.hx",1745);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1747)
	::String str = ::cocktail::core::parser::DOMParser_obj::serialize(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(1751)
	str = str.substr((str.indexOf(HX_CSTRING(">"),null()) + (int)1),((str.lastIndexOf(HX_CSTRING("<"),null()) - str.indexOf(HX_CSTRING(">"),null())) - (int)1));
	HX_STACK_LINE(1753)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_innerHTML,return )

::String HTMLElement_obj::set_outerHTML( ::String value){
	HX_STACK_PUSH("HTMLElement::set_outerHTML","cocktail/core/html/HTMLElement.hx",1723);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1725)
	::cocktail::core::html::HTMLElement node = ::cocktail::core::parser::DOMParser_obj::parse(value,this->ownerDocument);		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(1727)
	::cocktail::core::html::HTMLElement oldNextSibling = this->get_nextSibling();		HX_STACK_VAR(oldNextSibling,"oldNextSibling");
	HX_STACK_LINE(1728)
	this->parentNode->__Field(HX_CSTRING("removeChild"),true)(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(1730)
	if (((node == null()))){
		HX_STACK_LINE(1731)
		return value;
	}
	HX_STACK_LINE(1735)
	this->parentNode->__Field(HX_CSTRING("insertBefore"),true)(node,oldNextSibling);
	HX_STACK_LINE(1737)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_outerHTML,return )

::String HTMLElement_obj::set_innerHTML( ::String value){
	HX_STACK_PUSH("HTMLElement::set_innerHTML","cocktail/core/html/HTMLElement.hx",1680);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1681)
	int childLength = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(childLength,"childLength");
	HX_STACK_LINE(1682)
	{
		HX_STACK_LINE(1682)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1682)
		while(((_g < childLength))){
			HX_STACK_LINE(1682)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1684)
			this->removeChild(this->childNodes->__GetItem((int)0));
		}
	}
	HX_STACK_LINE(1691)
	::String wrappedHTML = ((HX_CSTRING("<") + HX_CSTRING("DIV")) + HX_CSTRING(">"));		HX_STACK_VAR(wrappedHTML,"wrappedHTML");
	HX_STACK_LINE(1692)
	hx::AddEq(wrappedHTML,value);
	HX_STACK_LINE(1693)
	hx::AddEq(wrappedHTML,(((HX_CSTRING("<") + HX_CSTRING("/")) + HX_CSTRING("DIV")) + HX_CSTRING(">")));
	HX_STACK_LINE(1696)
	::cocktail::core::html::HTMLElement node = ::cocktail::core::parser::DOMParser_obj::parse(wrappedHTML,this->ownerDocument);		HX_STACK_VAR(node,"node");
	HX_STACK_LINE(1700)
	if (((node == null()))){
		HX_STACK_LINE(1701)
		return value;
	}
	HX_STACK_LINE(1706)
	int length = node->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(1707)
	{
		HX_STACK_LINE(1707)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1707)
		while(((_g < length))){
			HX_STACK_LINE(1707)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1709)
			this->appendChild(node->childNodes->__GetItem((int)0));
		}
	}
	HX_STACK_LINE(1712)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_innerHTML,return )

bool HTMLElement_obj::set_hidden( bool value){
	HX_STACK_PUSH("HTMLElement::set_hidden","cocktail/core/html/HTMLElement.hx",1663);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1664)
	this->super::setAttribute(HX_CSTRING("hidden"),::Std_obj::string(value));
	HX_STACK_LINE(1665)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_hidden,return )

bool HTMLElement_obj::get_hidden( ){
	HX_STACK_PUSH("HTMLElement::get_hidden","cocktail/core/html/HTMLElement.hx",1651);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1651)
	if (((this->getAttribute(HX_CSTRING("hidden")) != null()))){
		HX_STACK_LINE(1653)
		return true;
	}
	else{
		HX_STACK_LINE(1657)
		return false;
	}
	HX_STACK_LINE(1651)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_hidden,return )

::String HTMLElement_obj::set_className( ::String value){
	HX_STACK_PUSH("HTMLElement::set_className","cocktail/core/html/HTMLElement.hx",1637);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1638)
	this->super::setAttribute(HX_CSTRING("class"),value);
	HX_STACK_LINE(1641)
	this->classList = value.split(HX_CSTRING(" "));
	HX_STACK_LINE(1645)
	this->invalidateStyleDeclaration(true);
	HX_STACK_LINE(1647)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_className,return )

::String HTMLElement_obj::get_className( ){
	HX_STACK_PUSH("HTMLElement::get_className","cocktail/core/html/HTMLElement.hx",1628);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1628)
	return this->getAttribute(HX_CSTRING("class"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_className,return )

::String HTMLElement_obj::set_id( ::String value){
	HX_STACK_PUSH("HTMLElement::set_id","cocktail/core/html/HTMLElement.hx",1618);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1619)
	this->setAttribute(HX_CSTRING("id"),value);
	HX_STACK_LINE(1620)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_id,return )

::String HTMLElement_obj::get_id( ){
	HX_STACK_PUSH("HTMLElement::get_id","cocktail/core/html/HTMLElement.hx",1610);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1610)
	return this->getAttribute(HX_CSTRING("id"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_id,return )

int HTMLElement_obj::get_tabIndex( ){
	HX_STACK_PUSH("HTMLElement::get_tabIndex","cocktail/core/html/HTMLElement.hx",1581);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1582)
	::String tabIndex = this->super::getAttribute(HX_CSTRING("tabindex"));		HX_STACK_VAR(tabIndex,"tabIndex");
	HX_STACK_LINE(1584)
	if (((tabIndex == HX_CSTRING("")))){
		HX_STACK_LINE(1585)
		if (((this->isDefaultFocusable() == true))){
			HX_STACK_LINE(1589)
			return (int)0;
		}
		else{
			HX_STACK_LINE(1593)
			return (int)-1;
		}
	}
	else{
		HX_STACK_LINE(1598)
		return ::Std_obj::parseInt(tabIndex);
	}
	HX_STACK_LINE(1584)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_tabIndex,return )

int HTMLElement_obj::set_tabIndex( int value){
	HX_STACK_PUSH("HTMLElement::set_tabIndex","cocktail/core/html/HTMLElement.hx",1571);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1572)
	this->setAttribute(HX_CSTRING("tabindex"),::Std_obj::string(value));
	HX_STACK_LINE(1573)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_tabIndex,return )

int HTMLElement_obj::get_scrollTop( ){
	HX_STACK_PUSH("HTMLElement::get_scrollTop","cocktail/core/html/HTMLElement.hx",1556);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1557)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1559)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1560)
		return ::Math_obj::round(this->elementRenderer->get_scrollTop());
	}
	HX_STACK_LINE(1563)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_scrollTop,return )

int HTMLElement_obj::set_scrollTop( int value){
	HX_STACK_PUSH("HTMLElement::set_scrollTop","cocktail/core/html/HTMLElement.hx",1547);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1548)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1549)
		this->elementRenderer->set_scrollTop(value);
	}
	HX_STACK_LINE(1552)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_scrollTop,return )

int HTMLElement_obj::get_scrollLeft( ){
	HX_STACK_PUSH("HTMLElement::get_scrollLeft","cocktail/core/html/HTMLElement.hx",1536);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1537)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1539)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1540)
		return ::Math_obj::round(this->elementRenderer->get_scrollLeft());
	}
	HX_STACK_LINE(1543)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_scrollLeft,return )

int HTMLElement_obj::set_scrollLeft( int value){
	HX_STACK_PUSH("HTMLElement::set_scrollLeft","cocktail/core/html/HTMLElement.hx",1527);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(1528)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1529)
		this->elementRenderer->set_scrollLeft(value);
	}
	HX_STACK_LINE(1532)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,set_scrollLeft,return )

int HTMLElement_obj::get_scrollWidth( ){
	HX_STACK_PUSH("HTMLElement::get_scrollWidth","cocktail/core/html/HTMLElement.hx",1516);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1517)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1519)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1520)
		return ::Math_obj::round(this->elementRenderer->get_scrollWidth());
	}
	HX_STACK_LINE(1523)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_scrollWidth,return )

int HTMLElement_obj::get_scrollHeight( ){
	HX_STACK_PUSH("HTMLElement::get_scrollHeight","cocktail/core/html/HTMLElement.hx",1505);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1506)
	this->updateDocumentImmediately();
	HX_STACK_LINE(1508)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(1509)
		return ::Math_obj::round(this->elementRenderer->get_scrollHeight());
	}
	HX_STACK_LINE(1512)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,get_scrollHeight,return )

::cocktail::core::html::HTMLElement HTMLElement_obj::getNearestActivatableElement( ){
	HX_STACK_PUSH("HTMLElement::getNearestActivatableElement","cocktail/core/html/HTMLElement.hx",1486);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1487)
	::cocktail::core::html::HTMLElement htmlElement = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(htmlElement,"htmlElement");
	HX_STACK_LINE(1488)
	while(((htmlElement->hasActivationBehaviour() == false))){
		HX_STACK_LINE(1490)
		if (((htmlElement->parentNode == null()))){
			HX_STACK_LINE(1491)
			return null();
		}
		HX_STACK_LINE(1494)
		htmlElement = htmlElement->parentNode;
	}
	HX_STACK_LINE(1497)
	return htmlElement;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,getNearestActivatableElement,return )

Void HTMLElement_obj::runPostClickActivationStep( ::cocktail::core::event::MouseEvent event){
{
		HX_STACK_PUSH("HTMLElement::runPostClickActivationStep","cocktail/core/html/HTMLElement.hx",1476);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,runPostClickActivationStep,(void))

Void HTMLElement_obj::runCanceledActivationStep( ){
{
		HX_STACK_PUSH("HTMLElement::runCanceledActivationStep","cocktail/core/html/HTMLElement.hx",1468);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,runCanceledActivationStep,(void))

Void HTMLElement_obj::runPreClickActivation( ){
{
		HX_STACK_PUSH("HTMLElement::runPreClickActivation","cocktail/core/html/HTMLElement.hx",1460);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,runPreClickActivation,(void))

bool HTMLElement_obj::hasActivationBehaviour( ){
	HX_STACK_PUSH("HTMLElement::hasActivationBehaviour","cocktail/core/html/HTMLElement.hx",1452);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1452)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,hasActivationBehaviour,return )

Void HTMLElement_obj::requestFullScreen( ){
{
		HX_STACK_PUSH("HTMLElement::requestFullScreen","cocktail/core/html/HTMLElement.hx",1428);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1428)
		this->_ownerHTMLDocument->set_fullscreenElement(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,requestFullScreen,(void))

Void HTMLElement_obj::blur( ){
{
		HX_STACK_PUSH("HTMLElement::blur","cocktail/core/html/HTMLElement.hx",1411);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1411)
		this->_ownerHTMLDocument->body->focus();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,blur,(void))

Void HTMLElement_obj::focus( ){
{
		HX_STACK_PUSH("HTMLElement::focus","cocktail/core/html/HTMLElement.hx",1402);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1402)
		this->_ownerHTMLDocument->set_activeElement(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,focus,(void))

bool HTMLElement_obj::isDefaultFocusable( ){
	HX_STACK_PUSH("HTMLElement::isDefaultFocusable","cocktail/core/html/HTMLElement.hx",1392);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1392)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isDefaultFocusable,return )

bool HTMLElement_obj::isFocusable( ){
	HX_STACK_PUSH("HTMLElement::isFocusable","cocktail/core/html/HTMLElement.hx",1362);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1365)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(1366)
		return false;
	}
	else{
		HX_STACK_LINE(1372)
		if (((this->isDefaultFocusable() == true))){
			HX_STACK_LINE(1373)
			return true;
		}
		else{
			HX_STACK_LINE(1379)
			if (((this->get_tabIndex() > (int)0))){
				HX_STACK_LINE(1380)
				return true;
			}
		}
	}
	HX_STACK_LINE(1384)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isFocusable,return )

Void HTMLElement_obj::fireEvent( ::String eventType,bool bubbles,bool cancelable){
{
		HX_STACK_PUSH("HTMLElement::fireEvent","cocktail/core/html/HTMLElement.hx",1347);
		HX_STACK_THIS(this);
		HX_STACK_ARG(eventType,"eventType");
		HX_STACK_ARG(bubbles,"bubbles");
		HX_STACK_ARG(cancelable,"cancelable");
		HX_STACK_LINE(1348)
		::cocktail::core::event::Event event = ::cocktail::core::event::Event_obj::__new();		HX_STACK_VAR(event,"event");
		HX_STACK_LINE(1349)
		event->initEvent(eventType,bubbles,cancelable);
		HX_STACK_LINE(1350)
		this->dispatchEvent(event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(HTMLElement_obj,fireEvent,(void))

Void HTMLElement_obj::click( ){
{
		HX_STACK_PUSH("HTMLElement::click","cocktail/core/html/HTMLElement.hx",1331);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1332)
		::cocktail::core::event::MouseEvent mouseEvent = ::cocktail::core::event::MouseEvent_obj::__new();		HX_STACK_VAR(mouseEvent,"mouseEvent");
		HX_STACK_LINE(1333)
		mouseEvent->initMouseEvent(HX_CSTRING("click"),false,false,null(),(int)0,(int)0,(int)0,(int)0,(int)0,false,false,false,false,(int)0,null());
		HX_STACK_LINE(1335)
		this->dispatchEvent(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,click,(void))

Void HTMLElement_obj::endPendingAnimation( ){
{
		HX_STACK_PUSH("HTMLElement::endPendingAnimation","cocktail/core/html/HTMLElement.hx",1306);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1307)
		this->coreStyle->endPendingAnimation();
		HX_STACK_LINE(1309)
		int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(1310)
		{
			HX_STACK_LINE(1310)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1310)
			while(((_g < length))){
				HX_STACK_LINE(1310)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1312)
				this->childNodes->__GetItem(i)->__Field(HX_CSTRING("endPendingAnimation"),true)();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,endPendingAnimation,(void))

bool HTMLElement_obj::startPendingAnimation( ){
	HX_STACK_PUSH("HTMLElement::startPendingAnimation","cocktail/core/html/HTMLElement.hx",1278);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1279)
	bool atLeastOneAnimationStarted = false;		HX_STACK_VAR(atLeastOneAnimationStarted,"atLeastOneAnimationStarted");
	HX_STACK_LINE(1281)
	bool animationStarted = this->coreStyle->startPendingAnimations();		HX_STACK_VAR(animationStarted,"animationStarted");
	HX_STACK_LINE(1283)
	if (((animationStarted == true))){
		HX_STACK_LINE(1284)
		atLeastOneAnimationStarted = true;
	}
	HX_STACK_LINE(1287)
	int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(1288)
	{
		HX_STACK_LINE(1288)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1288)
		while(((_g < length))){
			HX_STACK_LINE(1288)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1290)
			bool animationStarted1 = this->childNodes->__GetItem(i)->__Field(HX_CSTRING("startPendingAnimation"),true)();		HX_STACK_VAR(animationStarted1,"animationStarted1");
			HX_STACK_LINE(1292)
			if (((animationStarted1 == true))){
				HX_STACK_LINE(1293)
				atLeastOneAnimationStarted = true;
			}
		}
	}
	HX_STACK_LINE(1298)
	return atLeastOneAnimationStarted;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,startPendingAnimation,return )

bool HTMLElement_obj::isParentRendered( ){
	HX_STACK_PUSH("HTMLElement::isParentRendered","cocktail/core/html/HTMLElement.hx",1260);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1261)
	if (((this->parentNode == null()))){
		HX_STACK_LINE(1262)
		return false;
	}
	HX_STACK_LINE(1265)
	return (this->parentNode->__Field(HX_CSTRING("elementRenderer"),true) != null());
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isParentRendered,return )

bool HTMLElement_obj::isRendered( ){
	HX_STACK_PUSH("HTMLElement::isRendered","cocktail/core/html/HTMLElement.hx",1239);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1241)
	if (((this->get_hidden() == true))){
		HX_STACK_LINE(1242)
		return false;
	}
	HX_STACK_LINE(1247)
	if ((this->coreStyle->isNone(this->coreStyle->getComputedOrInitialProperty((int)0)))){
		HX_STACK_LINE(1248)
		return false;
	}
	HX_STACK_LINE(1252)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isRendered,return )

Void HTMLElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::createElementRenderer","cocktail/core/html/HTMLElement.hx",1219);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1219)
		{
			::cocktail::core::css::CSSKeywordValue _switch_2 = (this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)0)));
			switch((_switch_2)->GetIndex()){
				case 28: case 29: {
					HX_STACK_LINE(1222)
					this->elementRenderer = ::cocktail::core::renderer::BlockBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
				}
				;break;
				case 30: {
					HX_STACK_LINE(1225)
					this->elementRenderer = ::cocktail::core::renderer::InlineBoxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
				}
				;break;
				case 18: {
				}
				;break;
				default: {
					HX_STACK_LINE(1230)
					hx::Throw (HX_CSTRING("Illegal value for display style"));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,createElementRenderer,(void))

Void HTMLElement_obj::detachFromParentElementRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::detachFromParentElementRenderer","cocktail/core/html/HTMLElement.hx",1209);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1209)
		this->elementRenderer->parentNode->__Field(HX_CSTRING("removeChild"),true)(this->elementRenderer);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,detachFromParentElementRenderer,(void))

Void HTMLElement_obj::attachToParentElementRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::attachToParentElementRenderer","cocktail/core/html/HTMLElement.hx",1200);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1200)
		this->parentNode->__Field(HX_CSTRING("elementRenderer"),true)->__Field(HX_CSTRING("insertBefore"),true)(this->elementRenderer,this->getNextElementRendererSibling());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,attachToParentElementRenderer,(void))

::cocktail::core::renderer::ElementRenderer HTMLElement_obj::getNextElementRendererSibling( ){
	HX_STACK_PUSH("HTMLElement::getNextElementRendererSibling","cocktail/core/html/HTMLElement.hx",1161);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1162)
	::cocktail::core::html::HTMLElement nextSibling = this->get_nextSibling();		HX_STACK_VAR(nextSibling,"nextSibling");
	HX_STACK_LINE(1164)
	if (((nextSibling == null()))){
		HX_STACK_LINE(1165)
		return null();
	}
	else{
		HX_STACK_LINE(1169)
		while(((nextSibling != null()))){
			HX_STACK_LINE(1172)
			if (((nextSibling->elementRenderer != null()))){
				HX_STACK_LINE(1174)
				::cocktail::core::renderer::ElementRenderer elementRenderParent = nextSibling->elementRenderer->parentNode;		HX_STACK_VAR(elementRenderParent,"elementRenderParent");
				HX_STACK_LINE(1178)
				if (((elementRenderParent->isAnonymousBlockBox() == true))){
					HX_STACK_LINE(1179)
					return elementRenderParent;
				}
				HX_STACK_LINE(1183)
				return nextSibling->elementRenderer;
			}
			HX_STACK_LINE(1186)
			nextSibling = nextSibling->get_nextSibling();
		}
	}
	HX_STACK_LINE(1190)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,getNextElementRendererSibling,return )

Void HTMLElement_obj::onInlineStyleChange( int changedPropertyIndex){
{
		HX_STACK_PUSH("HTMLElement::onInlineStyleChange","cocktail/core/html/HTMLElement.hx",1139);
		HX_STACK_THIS(this);
		HX_STACK_ARG(changedPropertyIndex,"changedPropertyIndex");
		HX_STACK_LINE(1142)
		if (((this->_shouldCascadeAllProperties == false))){
			HX_STACK_LINE(1143)
			this->_pendingChangedProperties->push(changedPropertyIndex);
		}
		HX_STACK_LINE(1147)
		this->invalidateCascade();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,onInlineStyleChange,(void))

Void HTMLElement_obj::cascadeSelf( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange){
{
		HX_STACK_PUSH("HTMLElement::cascadeSelf","cocktail/core/html/HTMLElement.hx",1071);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(programmaticChange,"programmaticChange");
		HX_STACK_LINE(1072)
		if (((this->parentNode != null()))){
			HX_STACK_LINE(1073)
			if (((this->parentNode->__Field(HX_CSTRING("styleManagerCSSDeclaration"),true) != null()))){
				HX_STACK_LINE(1076)
				if (((bool((this->_needsStyleDeclarationUpdate == true)) || bool((this->styleManagerCSSDeclaration == null()))))){
					HX_STACK_LINE(1078)
					this->getStyleDeclaration();
					HX_STACK_LINE(1079)
					this->_needsStyleDeclarationUpdate = false;
				}
				HX_STACK_LINE(1082)
				::cocktail::core::css::CSSStyleDeclaration parentStyleDeclaration = this->parentNode->__Field(HX_CSTRING("coreStyle"),true)->__Field(HX_CSTRING("computedValues"),true);		HX_STACK_VAR(parentStyleDeclaration,"parentStyleDeclaration");
				HX_STACK_LINE(1083)
				::cocktail::core::font::FontMetricsVO parentFontMetrics = this->parentNode->__Field(HX_CSTRING("coreStyle"),true)->__Field(HX_CSTRING("fontMetrics"),true);		HX_STACK_VAR(parentFontMetrics,"parentFontMetrics");
				HX_STACK_LINE(1085)
				if (((this->_shouldCascadeAllProperties == true))){
					HX_STACK_LINE(1086)
					cascadeManager->shouldCascadeAll();
				}
				else{
					HX_STACK_LINE(1091)
					int length = this->_pendingChangedProperties->length;		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(1092)
					{
						HX_STACK_LINE(1092)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(1092)
						while(((_g < length))){
							HX_STACK_LINE(1092)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(1094)
							cascadeManager->addPropertyToCascade(this->_pendingChangedProperties->__get(i));
						}
					}
				}
				HX_STACK_LINE(1098)
				this->coreStyle->cascade(cascadeManager,this->_initialStyleDeclaration,this->styleManagerCSSDeclaration,this->style,parentStyleDeclaration,parentFontMetrics->fontSize,parentFontMetrics->xHeight,programmaticChange);
			}
		}
		else{
			HX_STACK_LINE(1103)
			if (((bool((this->_needsStyleDeclarationUpdate == true)) || bool((this->styleManagerCSSDeclaration == null()))))){
				HX_STACK_LINE(1105)
				this->getStyleDeclaration();
				HX_STACK_LINE(1106)
				this->_needsStyleDeclarationUpdate = false;
			}
			HX_STACK_LINE(1109)
			if (((this->_shouldCascadeAllProperties == true))){
				HX_STACK_LINE(1110)
				cascadeManager->shouldCascadeAll();
			}
			else{
				HX_STACK_LINE(1115)
				int length = this->_pendingChangedProperties->length;		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(1116)
				{
					HX_STACK_LINE(1116)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(1116)
					while(((_g < length))){
						HX_STACK_LINE(1116)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(1118)
						cascadeManager->addPropertyToCascade(this->_pendingChangedProperties->__get(i));
					}
				}
			}
			HX_STACK_LINE(1122)
			this->coreStyle->cascade(cascadeManager,this->_initialStyleDeclaration,this->styleManagerCSSDeclaration,this->style,this->_initialStyleDeclaration,(int)12,(int)12,programmaticChange);
		}
		HX_STACK_LINE(1125)
		this->_shouldCascadeAllProperties = false;
		HX_STACK_LINE(1126)
		this->_pendingChangedProperties = ::cocktail::core::utils::Utils_obj::clear(this->_pendingChangedProperties);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLElement_obj,cascadeSelf,(void))

Void HTMLElement_obj::getStyleDeclaration( ){
{
		HX_STACK_PUSH("HTMLElement::getStyleDeclaration","cocktail/core/html/HTMLElement.hx",1049);
		HX_STACK_THIS(this);
		HX_STACK_LINE(1053)
		this->_shouldCascadeAllProperties = true;
		HX_STACK_LINE(1056)
		this->styleManagerCSSDeclaration = this->_ownerHTMLDocument->getStyleDeclaration(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,getStyleDeclaration,(void))

Void HTMLElement_obj::cascade( ::cocktail::core::css::CascadeManager cascadeManager,bool programmaticChange){
{
		HX_STACK_PUSH("HTMLElement::cascade","cocktail/core/html/HTMLElement.hx",999);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cascadeManager,"cascadeManager");
		HX_STACK_ARG(programmaticChange,"programmaticChange");
		HX_STACK_LINE(1006)
		if (((bool((this->_needsCascading == true)) || bool((cascadeManager->hasPropertiesToCascade == true))))){
			HX_STACK_LINE(1008)
			this->cascadeSelf(cascadeManager,programmaticChange);
			HX_STACK_LINE(1009)
			this->_needsCascading = false;
			HX_STACK_LINE(1014)
			if (((bool((bool((bool((bool((cascadeManager->hasDisplay == true)) || bool((cascadeManager->hasFloat == true)))) || bool((cascadeManager->hasOverflowX == true)))) || bool((cascadeManager->hasOverflowY == true)))) || bool((cascadeManager->hasPosition == true))))){
				HX_STACK_LINE(1018)
				this->detach(true);
				HX_STACK_LINE(1019)
				this->invalidateElementRenderer();
			}
			else{
				HX_STACK_LINE(1023)
				if (((bool((bool((cascadeManager->hasTransform == true)) || bool((cascadeManager->hasZIndex == true)))) || bool((cascadeManager->hasOpacity == true))))){
					HX_STACK_LINE(1024)
					this->invalidateLayerRenderer();
				}
			}
		}
		HX_STACK_LINE(1031)
		Array< ::cocktail::core::html::HTMLElement > childNodes = this->childNodes;		HX_STACK_VAR(childNodes,"childNodes");
		HX_STACK_LINE(1032)
		int childLength = childNodes->length;		HX_STACK_VAR(childLength,"childLength");
		HX_STACK_LINE(1033)
		{
			HX_STACK_LINE(1033)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1033)
			while(((_g < childLength))){
				HX_STACK_LINE(1033)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1035)
				::cocktail::core::html::HTMLElement childNode = childNodes->__get(i);		HX_STACK_VAR(childNode,"childNode");
				HX_STACK_LINE(1036)
				childNode->cascade(cascadeManager,programmaticChange);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLElement_obj,cascade,(void))

Void HTMLElement_obj::detach( bool recursive){
{
		HX_STACK_PUSH("HTMLElement::detach","cocktail/core/html/HTMLElement.hx",950);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
		HX_STACK_LINE(950)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(956)
			if (((recursive == true))){
				HX_STACK_LINE(957)
				if (((this->get_nodeType() == (int)1))){
					HX_STACK_LINE(960)
					int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(961)
					{
						HX_STACK_LINE(961)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(961)
						while(((_g < length))){
							HX_STACK_LINE(961)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(963)
							this->childNodes->__GetItem(i)->__Field(HX_CSTRING("detach"),true)(true);
						}
					}
				}
			}
			HX_STACK_LINE(970)
			this->detachFromParentElementRenderer();
			HX_STACK_LINE(977)
			this->elementRenderer = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,detach,(void))

Void HTMLElement_obj::attach( bool recursive){
{
		HX_STACK_PUSH("HTMLElement::attach","cocktail/core/html/HTMLElement.hx",896);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
		HX_STACK_LINE(900)
		if (((this->isParentRendered() == false))){
			HX_STACK_LINE(901)
			return null();
		}
		HX_STACK_LINE(906)
		if (((this->isRendered() == true))){
			HX_STACK_LINE(907)
			this->createElementRenderer();
		}
		HX_STACK_LINE(918)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(920)
			this->attachToParentElementRenderer();
			HX_STACK_LINE(923)
			if (((recursive == true))){
				HX_STACK_LINE(924)
				if (((this->get_nodeType() == (int)1))){
					HX_STACK_LINE(927)
					int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(928)
					{
						HX_STACK_LINE(928)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(928)
						while(((_g < length))){
							HX_STACK_LINE(928)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(930)
							this->childNodes->__GetItem(i)->__Field(HX_CSTRING("attach"),true)(true);
						}
					}
				}
			}
		}
		HX_STACK_LINE(937)
		this->_needsElementRendererUpdate = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,attach,(void))

Void HTMLElement_obj::updateElementRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::updateElementRenderer","cocktail/core/html/HTMLElement.hx",811);
		HX_STACK_THIS(this);
		HX_STACK_LINE(814)
		if (((this->_needsElementRendererUpdate == true))){
			HX_STACK_LINE(818)
			this->_needsElementRendererUpdate = false;
			HX_STACK_LINE(822)
			if (((this->isRendered() == false))){
				HX_STACK_LINE(823)
				if (((this->elementRenderer != null()))){
					HX_STACK_LINE(828)
					this->detach(true);
					HX_STACK_LINE(832)
					return null();
				}
			}
			else{
				HX_STACK_LINE(838)
				if (((this->elementRenderer == null()))){
					HX_STACK_LINE(843)
					this->attach(true);
					HX_STACK_LINE(846)
					return null();
				}
				else{
					HX_STACK_LINE(856)
					this->detach(false);
					HX_STACK_LINE(857)
					this->attach(false);
				}
			}
		}
		HX_STACK_LINE(871)
		if (((this->get_nodeType() == (int)1))){
			HX_STACK_LINE(875)
			int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
			HX_STACK_LINE(876)
			{
				HX_STACK_LINE(876)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(876)
				while(((_g < length))){
					HX_STACK_LINE(876)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(878)
					this->childNodes->__GetItem(i)->__Field(HX_CSTRING("updateElementRenderer"),true)();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,updateElementRenderer,(void))

bool HTMLElement_obj::isAttachedToDOM( ){
	HX_STACK_PUSH("HTMLElement::isAttachedToDOM","cocktail/core/html/HTMLElement.hx",776);
	HX_STACK_THIS(this);
	HX_STACK_LINE(777)
	::cocktail::core::html::HTMLElement parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(778)
	while(((parent != null()))){
		HX_STACK_LINE(780)
		if (((parent->get_nodeName() == HX_CSTRING("HTML")))){
			HX_STACK_LINE(781)
			return true;
		}
		HX_STACK_LINE(784)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(787)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,isAttachedToDOM,return )

Void HTMLElement_obj::removedFromDOM( ){
{
		HX_STACK_PUSH("HTMLElement::removedFromDOM","cocktail/core/html/HTMLElement.hx",750);
		HX_STACK_THIS(this);
		HX_STACK_LINE(750)
		switch( (int)(this->get_nodeType())){
			case (int)1: case (int)3: {
				HX_STACK_LINE(760)
				this->detach(true);
				HX_STACK_LINE(761)
				this->invalidateElementRenderer();
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,removedFromDOM,(void))

Void HTMLElement_obj::addedToDOM( ){
{
		HX_STACK_PUSH("HTMLElement::addedToDOM","cocktail/core/html/HTMLElement.hx",724);
		HX_STACK_THIS(this);
		HX_STACK_LINE(731)
		switch( (int)(this->get_nodeType())){
			case (int)1: case (int)3: {
				HX_STACK_LINE(733)
				this->invalidateElementRenderer();
			}
			;break;
		}
		HX_STACK_LINE(741)
		this->invalidateStyleDeclaration(true);
		HX_STACK_LINE(742)
		this->invalidateCascade();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,addedToDOM,(void))

Void HTMLElement_obj::removed( ){
{
		HX_STACK_PUSH("HTMLElement::removed","cocktail/core/html/HTMLElement.hx",704);
		HX_STACK_THIS(this);
		HX_STACK_LINE(705)
		this->attachedToDOM = false;
		HX_STACK_LINE(707)
		this->removedFromDOM();
		HX_STACK_LINE(711)
		::cocktail::core::html::HTMLElement child = this->get_firstChild();		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(712)
		while(((child != null()))){
			HX_STACK_LINE(714)
			child->removed();
			HX_STACK_LINE(715)
			child = child->get_nextSibling();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,removed,(void))

Void HTMLElement_obj::appended( ){
{
		HX_STACK_PUSH("HTMLElement::appended","cocktail/core/html/HTMLElement.hx",678);
		HX_STACK_THIS(this);
		HX_STACK_LINE(678)
		if (((this->attachedToDOM == false))){
			HX_STACK_LINE(681)
			if (((this->isAttachedToDOM() == true))){
				HX_STACK_LINE(684)
				this->attachedToDOM = true;
				HX_STACK_LINE(685)
				this->addedToDOM();
				HX_STACK_LINE(689)
				::cocktail::core::html::HTMLElement child = this->get_firstChild();		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(690)
				while(((child != null()))){
					HX_STACK_LINE(692)
					child->appended();
					HX_STACK_LINE(693)
					child = child->get_nextSibling();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,appended,(void))

Void HTMLElement_obj::updateDocumentImmediately( ){
{
		HX_STACK_PUSH("HTMLElement::updateDocumentImmediately","cocktail/core/html/HTMLElement.hx",662);
		HX_STACK_THIS(this);
		HX_STACK_LINE(662)
		this->_ownerHTMLDocument->invalidationManager->updateDocumentImmediately();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,updateDocumentImmediately,(void))

Void HTMLElement_obj::invalidateCascade( ){
{
		HX_STACK_PUSH("HTMLElement::invalidateCascade","cocktail/core/html/HTMLElement.hx",640);
		HX_STACK_THIS(this);
		HX_STACK_LINE(641)
		this->_needsCascading = true;
		HX_STACK_LINE(643)
		if (((this->_ownerHTMLDocument != null()))){
			HX_STACK_LINE(644)
			this->_ownerHTMLDocument->invalidationManager->invalidateCascade();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,invalidateCascade,(void))

Void HTMLElement_obj::invalidateStyleDeclaration( bool recursive){
{
		HX_STACK_PUSH("HTMLElement::invalidateStyleDeclaration","cocktail/core/html/HTMLElement.hx",615);
		HX_STACK_THIS(this);
		HX_STACK_ARG(recursive,"recursive");
		HX_STACK_LINE(616)
		this->_needsStyleDeclarationUpdate = true;
		HX_STACK_LINE(619)
		if (((recursive == true))){
			HX_STACK_LINE(620)
			if (((this->get_nodeType() == (int)1))){
				HX_STACK_LINE(623)
				int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(624)
				{
					HX_STACK_LINE(624)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(624)
					while(((_g < length))){
						HX_STACK_LINE(624)
						int i = (_g)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(626)
						this->childNodes->__GetItem(i)->__Field(HX_CSTRING("invalidateStyleDeclaration"),true)(true);
					}
				}
			}
		}
		HX_STACK_LINE(630)
		this->invalidateCascade();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,invalidateStyleDeclaration,(void))

Void HTMLElement_obj::invalidateLayerRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::invalidateLayerRenderer","cocktail/core/html/HTMLElement.hx",599);
		HX_STACK_THIS(this);
		HX_STACK_LINE(599)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(601)
			this->elementRenderer->invalidateLayerRenderer();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,invalidateLayerRenderer,(void))

Void HTMLElement_obj::invalidateElementRenderer( ){
{
		HX_STACK_PUSH("HTMLElement::invalidateElementRenderer","cocktail/core/html/HTMLElement.hx",585);
		HX_STACK_THIS(this);
		HX_STACK_LINE(586)
		this->_needsElementRendererUpdate = true;
		HX_STACK_LINE(587)
		if (((this->_ownerHTMLDocument != null()))){
			HX_STACK_LINE(588)
			this->_ownerHTMLDocument->invalidationManager->invalidateRenderingTree();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,invalidateElementRenderer,(void))

Void HTMLElement_obj::invalidateStyle( int styleIndex){
{
		HX_STACK_PUSH("HTMLElement::invalidateStyle","cocktail/core/html/HTMLElement.hx",572);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(572)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(574)
			this->elementRenderer->invalidateStyle(styleIndex);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLElement_obj,invalidateStyle,(void))

Void HTMLElement_obj::invalidate( ){
{
		HX_STACK_PUSH("HTMLElement::invalidate","cocktail/core/html/HTMLElement.hx",559);
		HX_STACK_THIS(this);
		HX_STACK_LINE(559)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(561)
			this->elementRenderer->invalidate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,invalidate,(void))

::cocktail::core::dom::Document HTMLElement_obj::set_ownerDocument( ::cocktail::core::dom::Document value){
	HX_STACK_PUSH("HTMLElement::set_ownerDocument","cocktail/core/html/HTMLElement.hx",543);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(544)
	this->super::set_ownerDocument(value);
	HX_STACK_LINE(545)
	this->_ownerHTMLDocument = value;
	HX_STACK_LINE(546)
	return value;
}


Void HTMLElement_obj::executeDefaultActionIfNeeded( bool defaultPrevented,::cocktail::core::event::Event event){
{
		HX_STACK_PUSH("HTMLElement::executeDefaultActionIfNeeded","cocktail/core/html/HTMLElement.hx",522);
		HX_STACK_THIS(this);
		HX_STACK_ARG(defaultPrevented,"defaultPrevented");
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(522)
		if (((defaultPrevented == false))){
			HX_STACK_LINE(524)
			::String _switch_3 = (event->type);
			if (  ( _switch_3==HX_CSTRING("mousedown"))){
				HX_STACK_LINE(529)
				this->focus();
			}
		}
	}
return null();
}


Array< ::cocktail::core::event::EventTarget > HTMLElement_obj::getTargetAncestors( ){
	HX_STACK_PUSH("HTMLElement::getTargetAncestors","cocktail/core/html/HTMLElement.hx",510);
	HX_STACK_THIS(this);
	HX_STACK_LINE(511)
	Array< ::cocktail::core::event::EventTarget > targetAncestors = this->super::getTargetAncestors();		HX_STACK_VAR(targetAncestors,"targetAncestors");
	HX_STACK_LINE(512)
	targetAncestors->push(::cocktail::Lib_obj::get_document());
	HX_STACK_LINE(513)
	targetAncestors->push(::cocktail::Lib_obj::get_window());
	HX_STACK_LINE(514)
	return targetAncestors;
}


::String HTMLElement_obj::getAttribute( ::String name){
	HX_STACK_PUSH("HTMLElement::getAttribute","cocktail/core/html/HTMLElement.hx",475);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_LINE(475)
	if (((name == HX_CSTRING("style")))){
		HX_STACK_LINE(479)
		return this->style->get_cssText();
	}
	else{
		HX_STACK_LINE(482)
		if (((name == HX_CSTRING("tabindex")))){
			HX_STACK_LINE(483)
			return ::Std_obj::string(this->get_tabIndex());
		}
		else{
			HX_STACK_LINE(489)
			if (((name == HX_CSTRING("style")))){
				HX_STACK_LINE(490)
				return this->style->get_cssText();
			}
			else{
				HX_STACK_LINE(495)
				return this->super::getAttribute(name);
			}
		}
	}
	HX_STACK_LINE(475)
	return null();
}


Void HTMLElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLElement::setAttribute","cocktail/core/html/HTMLElement.hx",449);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(449)
		if (((name == HX_CSTRING("style")))){
			HX_STACK_LINE(454)
			this->style->set_cssText(value);
			HX_STACK_LINE(455)
			this->invalidateCascade();
		}
		else{
			HX_STACK_LINE(459)
			if (((name == HX_CSTRING("class")))){
				HX_STACK_LINE(460)
				this->set_className(value);
			}
			else{
				HX_STACK_LINE(465)
				this->super::setAttribute(name,value);
				HX_STACK_LINE(466)
				this->invalidateStyleDeclaration(true);
			}
		}
	}
return null();
}


Array< ::cocktail::core::html::HTMLElement > HTMLElement_obj::getElementsByTagName( ::String tagName){
	HX_STACK_PUSH("HTMLElement::getElementsByTagName","cocktail/core/html/HTMLElement.hx",440);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tagName,"tagName");
	HX_STACK_LINE(440)
	return this->super::getElementsByTagName(tagName.toUpperCase());
}


Dynamic HTMLElement_obj::insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild){
	HX_STACK_PUSH("HTMLElement::insertBefore","cocktail/core/html/HTMLElement.hx",420);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
	HX_STACK_ARG(_tmp_refChild,"_tmp_refChild");
	HX_STACK_LINE(421)
	::cocktail::core::html::HTMLElement newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
	::cocktail::core::html::HTMLElement refChild = _tmp_refChild;		HX_STACK_VAR(refChild,"refChild");
	HX_STACK_LINE(421)
	this->super::insertBefore(newChild,refChild);
	HX_STACK_LINE(426)
	if (((refChild != null()))){
		HX_STACK_LINE(428)
		newChild->appended();
		HX_STACK_LINE(429)
		this->invalidateCascade();
	}
	HX_STACK_LINE(432)
	return newChild;
}


Dynamic HTMLElement_obj::removeChild( Dynamic _tmp_oldChild){
	HX_STACK_PUSH("HTMLElement::removeChild","cocktail/core/html/HTMLElement.hx",409);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
	HX_STACK_LINE(410)
	::cocktail::core::html::HTMLElement oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
	HX_STACK_LINE(410)
	this->super::removeChild(oldChild);
	HX_STACK_LINE(411)
	oldChild->removed();
	HX_STACK_LINE(412)
	return oldChild;
}


Dynamic HTMLElement_obj::appendChild( Dynamic _tmp_newChild){
	HX_STACK_PUSH("HTMLElement::appendChild","cocktail/core/html/HTMLElement.hx",391);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
	HX_STACK_LINE(392)
	::cocktail::core::html::HTMLElement newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
	HX_STACK_LINE(392)
	this->super::appendChild(newChild);
	HX_STACK_LINE(393)
	newChild->appended();
	HX_STACK_LINE(399)
	this->invalidateCascade();
	HX_STACK_LINE(400)
	return newChild;
}


Void HTMLElement_obj::initId( ){
{
		HX_STACK_PUSH("HTMLElement::initId","cocktail/core/html/HTMLElement.hx",377);
		HX_STACK_THIS(this);
		HX_STACK_LINE(378)
		::cocktail::core::dom::Attr id = ::cocktail::core::dom::Attr_obj::__new(HX_CSTRING("id"));		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(379)
		this->setIdAttributeNode(id,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,initId,(void))

Void HTMLElement_obj::initStyle( ){
{
		HX_STACK_PUSH("HTMLElement::initStyle","cocktail/core/html/HTMLElement.hx",367);
		HX_STACK_THIS(this);
		HX_STACK_LINE(367)
		this->style = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(null(),this->onInlineStyleChange_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,initStyle,(void))

Void HTMLElement_obj::initCoreStyle( ){
{
		HX_STACK_PUSH("HTMLElement::initCoreStyle","cocktail/core/html/HTMLElement.hx",359);
		HX_STACK_THIS(this);
		HX_STACK_LINE(359)
		this->coreStyle = ::cocktail::core::css::CoreStyle_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,initCoreStyle,(void))

Void HTMLElement_obj::init( ){
{
		HX_STACK_PUSH("HTMLElement::init","cocktail/core/html/HTMLElement.hx",343);
		HX_STACK_THIS(this);
		HX_STACK_LINE(345)
		this->initCoreStyle();
		HX_STACK_LINE(348)
		this->initStyle();
		HX_STACK_LINE(351)
		this->initId();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLElement_obj,init,(void))


HTMLElement_obj::HTMLElement_obj()
{
}

void HTMLElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLElement);
	HX_MARK_MEMBER_NAME(_initialStyleDeclaration,"_initialStyleDeclaration");
	HX_MARK_MEMBER_NAME(_ownerHTMLDocument,"_ownerHTMLDocument");
	HX_MARK_MEMBER_NAME(_shouldCascadeAllProperties,"_shouldCascadeAllProperties");
	HX_MARK_MEMBER_NAME(_pendingChangedProperties,"_pendingChangedProperties");
	HX_MARK_MEMBER_NAME(_needsElementRendererUpdate,"_needsElementRendererUpdate");
	HX_MARK_MEMBER_NAME(_needsStyleDeclarationUpdate,"_needsStyleDeclarationUpdate");
	HX_MARK_MEMBER_NAME(_needsCascading,"_needsCascading");
	HX_MARK_MEMBER_NAME(attachedToDOM,"attachedToDOM");
	HX_MARK_MEMBER_NAME(styleManagerCSSDeclaration,"styleManagerCSSDeclaration");
	HX_MARK_MEMBER_NAME(style,"style");
	HX_MARK_MEMBER_NAME(coreStyle,"coreStyle");
	HX_MARK_MEMBER_NAME(clientTop,"clientTop");
	HX_MARK_MEMBER_NAME(clientLeft,"clientLeft");
	HX_MARK_MEMBER_NAME(clientHeight,"clientHeight");
	HX_MARK_MEMBER_NAME(clientWidth,"clientWidth");
	HX_MARK_MEMBER_NAME(offsetTop,"offsetTop");
	HX_MARK_MEMBER_NAME(offsetLeft,"offsetLeft");
	HX_MARK_MEMBER_NAME(offsetHeight,"offsetHeight");
	HX_MARK_MEMBER_NAME(offsetWidth,"offsetWidth");
	HX_MARK_MEMBER_NAME(offsetParent,"offsetParent");
	HX_MARK_MEMBER_NAME(elementRenderer,"elementRenderer");
	HX_MARK_MEMBER_NAME(outerHTML,"outerHTML");
	HX_MARK_MEMBER_NAME(innerHTML,"innerHTML");
	HX_MARK_MEMBER_NAME(scrollWidth,"scrollWidth");
	HX_MARK_MEMBER_NAME(scrollHeight,"scrollHeight");
	HX_MARK_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_MARK_MEMBER_NAME(scrollTop,"scrollTop");
	HX_MARK_MEMBER_NAME(hidden,"hidden");
	HX_MARK_MEMBER_NAME(classList,"classList");
	HX_MARK_MEMBER_NAME(className,"className");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(tabIndex,"tabIndex");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_initialStyleDeclaration,"_initialStyleDeclaration");
	HX_VISIT_MEMBER_NAME(_ownerHTMLDocument,"_ownerHTMLDocument");
	HX_VISIT_MEMBER_NAME(_shouldCascadeAllProperties,"_shouldCascadeAllProperties");
	HX_VISIT_MEMBER_NAME(_pendingChangedProperties,"_pendingChangedProperties");
	HX_VISIT_MEMBER_NAME(_needsElementRendererUpdate,"_needsElementRendererUpdate");
	HX_VISIT_MEMBER_NAME(_needsStyleDeclarationUpdate,"_needsStyleDeclarationUpdate");
	HX_VISIT_MEMBER_NAME(_needsCascading,"_needsCascading");
	HX_VISIT_MEMBER_NAME(attachedToDOM,"attachedToDOM");
	HX_VISIT_MEMBER_NAME(styleManagerCSSDeclaration,"styleManagerCSSDeclaration");
	HX_VISIT_MEMBER_NAME(style,"style");
	HX_VISIT_MEMBER_NAME(coreStyle,"coreStyle");
	HX_VISIT_MEMBER_NAME(clientTop,"clientTop");
	HX_VISIT_MEMBER_NAME(clientLeft,"clientLeft");
	HX_VISIT_MEMBER_NAME(clientHeight,"clientHeight");
	HX_VISIT_MEMBER_NAME(clientWidth,"clientWidth");
	HX_VISIT_MEMBER_NAME(offsetTop,"offsetTop");
	HX_VISIT_MEMBER_NAME(offsetLeft,"offsetLeft");
	HX_VISIT_MEMBER_NAME(offsetHeight,"offsetHeight");
	HX_VISIT_MEMBER_NAME(offsetWidth,"offsetWidth");
	HX_VISIT_MEMBER_NAME(offsetParent,"offsetParent");
	HX_VISIT_MEMBER_NAME(elementRenderer,"elementRenderer");
	HX_VISIT_MEMBER_NAME(outerHTML,"outerHTML");
	HX_VISIT_MEMBER_NAME(innerHTML,"innerHTML");
	HX_VISIT_MEMBER_NAME(scrollWidth,"scrollWidth");
	HX_VISIT_MEMBER_NAME(scrollHeight,"scrollHeight");
	HX_VISIT_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_VISIT_MEMBER_NAME(scrollTop,"scrollTop");
	HX_VISIT_MEMBER_NAME(hidden,"hidden");
	HX_VISIT_MEMBER_NAME(classList,"classList");
	HX_VISIT_MEMBER_NAME(className,"className");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(tabIndex,"tabIndex");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return inCallProp ? get_id() : id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"blur") ) { return blur_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		if (HX_FIELD_EQ(inName,"click") ) { return click_dyn(); }
		if (HX_FIELD_EQ(inName,"style") ) { return style; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"set_id") ) { return set_id_dyn(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		if (HX_FIELD_EQ(inName,"initId") ) { return initId_dyn(); }
		if (HX_FIELD_EQ(inName,"hidden") ) { return inCallProp ? get_hidden() : hidden; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cascade") ) { return cascade_dyn(); }
		if (HX_FIELD_EQ(inName,"removed") ) { return removed_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"appended") ) { return appended_dyn(); }
		if (HX_FIELD_EQ(inName,"tabIndex") ) { return inCallProp ? get_tabIndex() : tabIndex; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fireEvent") ) { return fireEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"initStyle") ) { return initStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"coreStyle") ) { return coreStyle; }
		if (HX_FIELD_EQ(inName,"clientTop") ) { return inCallProp ? get_clientTop() : clientTop; }
		if (HX_FIELD_EQ(inName,"offsetTop") ) { return inCallProp ? get_offsetTop() : offsetTop; }
		if (HX_FIELD_EQ(inName,"outerHTML") ) { return inCallProp ? get_outerHTML() : outerHTML; }
		if (HX_FIELD_EQ(inName,"innerHTML") ) { return inCallProp ? get_innerHTML() : innerHTML; }
		if (HX_FIELD_EQ(inName,"scrollTop") ) { return inCallProp ? get_scrollTop() : scrollTop; }
		if (HX_FIELD_EQ(inName,"classList") ) { return classList; }
		if (HX_FIELD_EQ(inName,"className") ) { return inCallProp ? get_className() : className; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_hidden") ) { return set_hidden_dyn(); }
		if (HX_FIELD_EQ(inName,"get_hidden") ) { return get_hidden_dyn(); }
		if (HX_FIELD_EQ(inName,"isRendered") ) { return isRendered_dyn(); }
		if (HX_FIELD_EQ(inName,"addedToDOM") ) { return addedToDOM_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"clientLeft") ) { return inCallProp ? get_clientLeft() : clientLeft; }
		if (HX_FIELD_EQ(inName,"offsetLeft") ) { return inCallProp ? get_offsetLeft() : offsetLeft; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { return inCallProp ? get_scrollLeft() : scrollLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isFocusable") ) { return isFocusable_dyn(); }
		if (HX_FIELD_EQ(inName,"cascadeSelf") ) { return cascadeSelf_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"clientWidth") ) { return inCallProp ? get_clientWidth() : clientWidth; }
		if (HX_FIELD_EQ(inName,"offsetWidth") ) { return inCallProp ? get_offsetWidth() : offsetWidth; }
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { return inCallProp ? get_scrollWidth() : scrollWidth; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_tabIndex") ) { return get_tabIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"set_tabIndex") ) { return set_tabIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"getAttribute") ) { return getAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		if (HX_FIELD_EQ(inName,"clientHeight") ) { return inCallProp ? get_clientHeight() : clientHeight; }
		if (HX_FIELD_EQ(inName,"offsetHeight") ) { return inCallProp ? get_offsetHeight() : offsetHeight; }
		if (HX_FIELD_EQ(inName,"offsetParent") ) { return inCallProp ? get_offsetParent() : offsetParent; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { return inCallProp ? get_scrollHeight() : scrollHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_clientTop") ) { return get_clientTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetTop") ) { return get_offsetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outerHTML") ) { return get_outerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"get_innerHTML") ) { return get_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"set_outerHTML") ) { return set_outerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"set_innerHTML") ) { return set_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"set_className") ) { return set_className_dyn(); }
		if (HX_FIELD_EQ(inName,"get_className") ) { return get_className_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollTop") ) { return get_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollTop") ) { return set_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"attachedToDOM") ) { return attachedToDOM; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_clientLeft") ) { return get_clientLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetLeft") ) { return get_offsetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollLeft") ) { return get_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollLeft") ) { return set_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"removedFromDOM") ) { return removedFromDOM_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_clientWidth") ) { return get_clientWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetWidth") ) { return get_offsetWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollWidth") ) { return get_scrollWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"isAttachedToDOM") ) { return isAttachedToDOM_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateStyle") ) { return invalidateStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"_needsCascading") ) { return _needsCascading; }
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { return elementRenderer; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_clientHeight") ) { return get_clientHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetHeight") ) { return get_offsetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetParent") ) { return get_offsetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollHeight") ) { return get_scrollHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"isParentRendered") ) { return isParentRendered_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"requestFullScreen") ) { return requestFullScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateCascade") ) { return invalidateCascade_dyn(); }
		if (HX_FIELD_EQ(inName,"set_ownerDocument") ) { return set_ownerDocument_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return isDefaultFocusable_dyn(); }
		if (HX_FIELD_EQ(inName,"getTargetAncestors") ) { return getTargetAncestors_dyn(); }
		if (HX_FIELD_EQ(inName,"_ownerHTMLDocument") ) { return _ownerHTMLDocument; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"endPendingAnimation") ) { return endPendingAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"onInlineStyleChange") ) { return onInlineStyleChange_dyn(); }
		if (HX_FIELD_EQ(inName,"getStyleDeclaration") ) { return getStyleDeclaration_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getElementsByTagName") ) { return getElementsByTagName_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"runPreClickActivation") ) { return runPreClickActivation_dyn(); }
		if (HX_FIELD_EQ(inName,"startPendingAnimation") ) { return startPendingAnimation_dyn(); }
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"updateElementRenderer") ) { return updateElementRenderer_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"hasActivationBehaviour") ) { return hasActivationBehaviour_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"invalidateLayerRenderer") ) { return invalidateLayerRenderer_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_initialStyleDeclaration") ) { return _initialStyleDeclaration; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"runCanceledActivationStep") ) { return runCanceledActivationStep_dyn(); }
		if (HX_FIELD_EQ(inName,"updateDocumentImmediately") ) { return updateDocumentImmediately_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateElementRenderer") ) { return invalidateElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"_pendingChangedProperties") ) { return _pendingChangedProperties; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"runPostClickActivationStep") ) { return runPostClickActivationStep_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidateStyleDeclaration") ) { return invalidateStyleDeclaration_dyn(); }
		if (HX_FIELD_EQ(inName,"styleManagerCSSDeclaration") ) { return styleManagerCSSDeclaration; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_shouldCascadeAllProperties") ) { return _shouldCascadeAllProperties; }
		if (HX_FIELD_EQ(inName,"_needsElementRendererUpdate") ) { return _needsElementRendererUpdate; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getNearestActivatableElement") ) { return getNearestActivatableElement_dyn(); }
		if (HX_FIELD_EQ(inName,"executeDefaultActionIfNeeded") ) { return executeDefaultActionIfNeeded_dyn(); }
		if (HX_FIELD_EQ(inName,"_needsStyleDeclarationUpdate") ) { return _needsStyleDeclarationUpdate; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"attachToParentElementRenderer") ) { return attachToParentElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"getNextElementRendererSibling") ) { return getNextElementRendererSibling_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"detachFromParentElementRenderer") ) { return detachFromParentElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { if (inCallProp) return set_id(inValue);id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"hidden") ) { if (inCallProp) return set_hidden(inValue);hidden=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tabIndex") ) { if (inCallProp) return set_tabIndex(inValue);tabIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"coreStyle") ) { coreStyle=inValue.Cast< ::cocktail::core::css::CoreStyle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientTop") ) { clientTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetTop") ) { offsetTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outerHTML") ) { if (inCallProp) return set_outerHTML(inValue);outerHTML=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"innerHTML") ) { if (inCallProp) return set_innerHTML(inValue);innerHTML=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollTop") ) { if (inCallProp) return set_scrollTop(inValue);scrollTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"classList") ) { classList=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"className") ) { if (inCallProp) return set_className(inValue);className=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"clientLeft") ) { clientLeft=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetLeft") ) { offsetLeft=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { if (inCallProp) return set_scrollLeft(inValue);scrollLeft=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"clientWidth") ) { clientWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetWidth") ) { offsetWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { scrollWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clientHeight") ) { clientHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetHeight") ) { offsetHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetParent") ) { offsetParent=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { scrollHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"attachedToDOM") ) { attachedToDOM=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_needsCascading") ) { _needsCascading=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elementRenderer") ) { elementRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_ownerHTMLDocument") ) { _ownerHTMLDocument=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_initialStyleDeclaration") ) { _initialStyleDeclaration=inValue.Cast< ::cocktail::core::css::InitialStyleDeclaration >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_pendingChangedProperties") ) { _pendingChangedProperties=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"styleManagerCSSDeclaration") ) { styleManagerCSSDeclaration=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_shouldCascadeAllProperties") ) { _shouldCascadeAllProperties=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_needsElementRendererUpdate") ) { _needsElementRendererUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_needsStyleDeclarationUpdate") ) { _needsStyleDeclarationUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_initialStyleDeclaration"));
	outFields->push(HX_CSTRING("_ownerHTMLDocument"));
	outFields->push(HX_CSTRING("_shouldCascadeAllProperties"));
	outFields->push(HX_CSTRING("_pendingChangedProperties"));
	outFields->push(HX_CSTRING("_needsElementRendererUpdate"));
	outFields->push(HX_CSTRING("_needsStyleDeclarationUpdate"));
	outFields->push(HX_CSTRING("_needsCascading"));
	outFields->push(HX_CSTRING("attachedToDOM"));
	outFields->push(HX_CSTRING("styleManagerCSSDeclaration"));
	outFields->push(HX_CSTRING("style"));
	outFields->push(HX_CSTRING("coreStyle"));
	outFields->push(HX_CSTRING("clientTop"));
	outFields->push(HX_CSTRING("clientLeft"));
	outFields->push(HX_CSTRING("clientHeight"));
	outFields->push(HX_CSTRING("clientWidth"));
	outFields->push(HX_CSTRING("offsetTop"));
	outFields->push(HX_CSTRING("offsetLeft"));
	outFields->push(HX_CSTRING("offsetHeight"));
	outFields->push(HX_CSTRING("offsetWidth"));
	outFields->push(HX_CSTRING("offsetParent"));
	outFields->push(HX_CSTRING("elementRenderer"));
	outFields->push(HX_CSTRING("outerHTML"));
	outFields->push(HX_CSTRING("innerHTML"));
	outFields->push(HX_CSTRING("scrollWidth"));
	outFields->push(HX_CSTRING("scrollHeight"));
	outFields->push(HX_CSTRING("scrollLeft"));
	outFields->push(HX_CSTRING("scrollTop"));
	outFields->push(HX_CSTRING("hidden"));
	outFields->push(HX_CSTRING("classList"));
	outFields->push(HX_CSTRING("className"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("tabIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_clientLeft"),
	HX_CSTRING("get_clientTop"),
	HX_CSTRING("get_clientHeight"),
	HX_CSTRING("get_clientWidth"),
	HX_CSTRING("get_offsetTop"),
	HX_CSTRING("get_offsetLeft"),
	HX_CSTRING("get_offsetHeight"),
	HX_CSTRING("get_offsetWidth"),
	HX_CSTRING("get_offsetParent"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("get_outerHTML"),
	HX_CSTRING("get_innerHTML"),
	HX_CSTRING("set_outerHTML"),
	HX_CSTRING("set_innerHTML"),
	HX_CSTRING("set_hidden"),
	HX_CSTRING("get_hidden"),
	HX_CSTRING("set_className"),
	HX_CSTRING("get_className"),
	HX_CSTRING("set_id"),
	HX_CSTRING("get_id"),
	HX_CSTRING("get_tabIndex"),
	HX_CSTRING("set_tabIndex"),
	HX_CSTRING("get_scrollTop"),
	HX_CSTRING("set_scrollTop"),
	HX_CSTRING("get_scrollLeft"),
	HX_CSTRING("set_scrollLeft"),
	HX_CSTRING("get_scrollWidth"),
	HX_CSTRING("get_scrollHeight"),
	HX_CSTRING("getNearestActivatableElement"),
	HX_CSTRING("runPostClickActivationStep"),
	HX_CSTRING("runCanceledActivationStep"),
	HX_CSTRING("runPreClickActivation"),
	HX_CSTRING("hasActivationBehaviour"),
	HX_CSTRING("requestFullScreen"),
	HX_CSTRING("blur"),
	HX_CSTRING("focus"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("isFocusable"),
	HX_CSTRING("fireEvent"),
	HX_CSTRING("click"),
	HX_CSTRING("endPendingAnimation"),
	HX_CSTRING("startPendingAnimation"),
	HX_CSTRING("isParentRendered"),
	HX_CSTRING("isRendered"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("detachFromParentElementRenderer"),
	HX_CSTRING("attachToParentElementRenderer"),
	HX_CSTRING("getNextElementRendererSibling"),
	HX_CSTRING("onInlineStyleChange"),
	HX_CSTRING("cascadeSelf"),
	HX_CSTRING("getStyleDeclaration"),
	HX_CSTRING("cascade"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("updateElementRenderer"),
	HX_CSTRING("isAttachedToDOM"),
	HX_CSTRING("removedFromDOM"),
	HX_CSTRING("addedToDOM"),
	HX_CSTRING("removed"),
	HX_CSTRING("appended"),
	HX_CSTRING("updateDocumentImmediately"),
	HX_CSTRING("invalidateCascade"),
	HX_CSTRING("invalidateStyleDeclaration"),
	HX_CSTRING("invalidateLayerRenderer"),
	HX_CSTRING("invalidateElementRenderer"),
	HX_CSTRING("invalidateStyle"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("set_ownerDocument"),
	HX_CSTRING("executeDefaultActionIfNeeded"),
	HX_CSTRING("getTargetAncestors"),
	HX_CSTRING("getAttribute"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("getElementsByTagName"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("initId"),
	HX_CSTRING("initStyle"),
	HX_CSTRING("initCoreStyle"),
	HX_CSTRING("init"),
	HX_CSTRING("_initialStyleDeclaration"),
	HX_CSTRING("_ownerHTMLDocument"),
	HX_CSTRING("_shouldCascadeAllProperties"),
	HX_CSTRING("_pendingChangedProperties"),
	HX_CSTRING("_needsElementRendererUpdate"),
	HX_CSTRING("_needsStyleDeclarationUpdate"),
	HX_CSTRING("_needsCascading"),
	HX_CSTRING("attachedToDOM"),
	HX_CSTRING("styleManagerCSSDeclaration"),
	HX_CSTRING("style"),
	HX_CSTRING("coreStyle"),
	HX_CSTRING("clientTop"),
	HX_CSTRING("clientLeft"),
	HX_CSTRING("clientHeight"),
	HX_CSTRING("clientWidth"),
	HX_CSTRING("offsetTop"),
	HX_CSTRING("offsetLeft"),
	HX_CSTRING("offsetHeight"),
	HX_CSTRING("offsetWidth"),
	HX_CSTRING("offsetParent"),
	HX_CSTRING("elementRenderer"),
	HX_CSTRING("outerHTML"),
	HX_CSTRING("innerHTML"),
	HX_CSTRING("scrollWidth"),
	HX_CSTRING("scrollHeight"),
	HX_CSTRING("scrollLeft"),
	HX_CSTRING("scrollTop"),
	HX_CSTRING("hidden"),
	HX_CSTRING("classList"),
	HX_CSTRING("className"),
	HX_CSTRING("id"),
	HX_CSTRING("tabIndex"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLElement_obj::__mClass,"__mClass");
};

Class HTMLElement_obj::__mClass;

void HTMLElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLElement"), hx::TCanCast< HTMLElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
