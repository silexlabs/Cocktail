#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
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
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLStyleElement
#include <cocktail/core/html/HTMLStyleElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLStyleElement_obj::__construct()
{
HX_STACK_PUSH("HTMLStyleElement::new","cocktail/core/html/HTMLStyleElement.hx",42);
{
	HX_STACK_LINE(42)
	super::__construct(HX_CSTRING("STYLE"));
}
;
	return null();
}

HTMLStyleElement_obj::~HTMLStyleElement_obj() { }

Dynamic HTMLStyleElement_obj::__CreateEmpty() { return  new HTMLStyleElement_obj; }
hx::ObjectPtr< HTMLStyleElement_obj > HTMLStyleElement_obj::__new()
{  hx::ObjectPtr< HTMLStyleElement_obj > result = new HTMLStyleElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLStyleElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLStyleElement_obj > result = new HTMLStyleElement_obj();
	result->__construct();
	return result;}

bool HTMLStyleElement_obj::set_disabled( bool value){
	HX_STACK_PUSH("HTMLStyleElement::set_disabled","cocktail/core/html/HTMLStyleElement.hx",211);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(212)
	this->setAttribute(HX_CSTRING("disabled"),::Std_obj::string(value));
	HX_STACK_LINE(213)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLStyleElement_obj,set_disabled,return )

bool HTMLStyleElement_obj::get_disabled( ){
	HX_STACK_PUSH("HTMLStyleElement::get_disabled","cocktail/core/html/HTMLStyleElement.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_LINE(206)
	return this->getAttributeAsBool(HX_CSTRING("disabled"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLStyleElement_obj,get_disabled,return )

Void HTMLStyleElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLStyleElement::createElementRenderer","cocktail/core/html/HTMLStyleElement.hx",196);
		HX_STACK_THIS(this);
	}
return null();
}


::String HTMLStyleElement_obj::concatenateChildTextNode( ){
	HX_STACK_PUSH("HTMLStyleElement::concatenateChildTextNode","cocktail/core/html/HTMLStyleElement.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_LINE(174)
	::String content = HX_CSTRING("");		HX_STACK_VAR(content,"content");
	HX_STACK_LINE(176)
	int length = this->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(177)
	{
		HX_STACK_LINE(177)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(177)
		while(((_g < length))){
			HX_STACK_LINE(177)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(179)
			if (((this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeType"),true)() == (int)3))){
				HX_STACK_LINE(180)
				hx::AddEq(content,this->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeValue"),true)());
			}
		}
	}
	HX_STACK_LINE(185)
	return content;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLStyleElement_obj,concatenateChildTextNode,return )

Void HTMLStyleElement_obj::removeStyleSheet( ){
{
		HX_STACK_PUSH("HTMLStyleElement::removeStyleSheet","cocktail/core/html/HTMLStyleElement.hx",158);
		HX_STACK_THIS(this);
		HX_STACK_LINE(158)
		if (((this->sheet != null()))){
			HX_STACK_LINE(161)
			::cocktail::core::html::HTMLDocument htmlDocument = this->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
			HX_STACK_LINE(162)
			htmlDocument->removeStyleSheet(this->sheet);
			HX_STACK_LINE(163)
			this->sheet = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLStyleElement_obj,removeStyleSheet,(void))

Void HTMLStyleElement_obj::updateStyleSheet( ){
{
		HX_STACK_PUSH("HTMLStyleElement::updateStyleSheet","cocktail/core/html/HTMLStyleElement.hx",133);
		HX_STACK_THIS(this);
		HX_STACK_LINE(135)
		if (((this->sheet != null()))){
			HX_STACK_LINE(136)
			this->removeStyleSheet();
		}
		HX_STACK_LINE(140)
		if (((this->attachedToDOM == true))){
			HX_STACK_LINE(142)
			::String css = this->concatenateChildTextNode();		HX_STACK_VAR(css,"css");
			HX_STACK_LINE(143)
			if (((css != HX_CSTRING("")))){
				HX_STACK_LINE(146)
				this->sheet = ::cocktail::core::css::CSSStyleSheet_obj::__new(css,::cocktail::core::css::PropertyOriginValue_obj::AUTHOR_dyn(),hx::ObjectPtr<OBJ_>(this),null(),null(),null());
				HX_STACK_LINE(147)
				::cocktail::core::html::HTMLDocument htmlDocument = this->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
				HX_STACK_LINE(148)
				htmlDocument->addStyleSheet(this->sheet);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLStyleElement_obj,updateStyleSheet,(void))

Void HTMLStyleElement_obj::removedFromDOM( ){
{
		HX_STACK_PUSH("HTMLStyleElement::removedFromDOM","cocktail/core/html/HTMLStyleElement.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_LINE(118)
		this->super::removedFromDOM();
		HX_STACK_LINE(119)
		this->updateStyleSheet();
	}
return null();
}


Void HTMLStyleElement_obj::addedToDOM( ){
{
		HX_STACK_PUSH("HTMLStyleElement::addedToDOM","cocktail/core/html/HTMLStyleElement.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_LINE(107)
		this->super::addedToDOM();
		HX_STACK_LINE(108)
		this->updateStyleSheet();
	}
return null();
}


Dynamic HTMLStyleElement_obj::insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild){
	HX_STACK_PUSH("HTMLStyleElement::insertBefore","cocktail/core/html/HTMLStyleElement.hx",87);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
	HX_STACK_ARG(_tmp_refChild,"_tmp_refChild");
	HX_STACK_LINE(88)
	::cocktail::core::html::HTMLElement newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
	::cocktail::core::html::HTMLElement refChild = _tmp_refChild;		HX_STACK_VAR(refChild,"refChild");
	HX_STACK_LINE(88)
	this->super::insertBefore(newChild,refChild);
	HX_STACK_LINE(89)
	if (((refChild != null()))){
		HX_STACK_LINE(90)
		if (((newChild->get_nodeType() == (int)3))){
			HX_STACK_LINE(92)
			this->updateStyleSheet();
		}
	}
	HX_STACK_LINE(97)
	return newChild;
}


Dynamic HTMLStyleElement_obj::removeChild( Dynamic _tmp_oldChild){
	HX_STACK_PUSH("HTMLStyleElement::removeChild","cocktail/core/html/HTMLStyleElement.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
	HX_STACK_LINE(72)
	::cocktail::core::html::HTMLElement oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
	HX_STACK_LINE(72)
	this->super::removeChild(oldChild);
	HX_STACK_LINE(74)
	if (((oldChild->get_nodeType() == (int)3))){
		HX_STACK_LINE(75)
		this->updateStyleSheet();
	}
	HX_STACK_LINE(79)
	return oldChild;
}


Dynamic HTMLStyleElement_obj::appendChild( Dynamic _tmp_newChild){
	HX_STACK_PUSH("HTMLStyleElement::appendChild","cocktail/core/html/HTMLStyleElement.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
	HX_STACK_LINE(56)
	::cocktail::core::html::HTMLElement newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
	HX_STACK_LINE(56)
	this->super::appendChild(newChild);
	HX_STACK_LINE(58)
	if (((newChild->get_nodeType() == (int)3))){
		HX_STACK_LINE(59)
		this->updateStyleSheet();
	}
	HX_STACK_LINE(63)
	return newChild;
}



HTMLStyleElement_obj::HTMLStyleElement_obj()
{
}

void HTMLStyleElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLStyleElement);
	HX_MARK_MEMBER_NAME(sheet,"sheet");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLStyleElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(sheet,"sheet");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLStyleElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sheet") ) { return sheet; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"disabled") ) { return inCallProp ? get_disabled() : disabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addedToDOM") ) { return addedToDOM_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"get_disabled") ) { return get_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"removedFromDOM") ) { return removedFromDOM_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"removeStyleSheet") ) { return removeStyleSheet_dyn(); }
		if (HX_FIELD_EQ(inName,"updateStyleSheet") ) { return updateStyleSheet_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"concatenateChildTextNode") ) { return concatenateChildTextNode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLStyleElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"sheet") ) { sheet=inValue.Cast< ::cocktail::core::css::CSSStyleSheet >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"disabled") ) { if (inCallProp) return set_disabled(inValue);disabled=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLStyleElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("sheet"));
	outFields->push(HX_CSTRING("disabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_disabled"),
	HX_CSTRING("get_disabled"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("concatenateChildTextNode"),
	HX_CSTRING("removeStyleSheet"),
	HX_CSTRING("updateStyleSheet"),
	HX_CSTRING("removedFromDOM"),
	HX_CSTRING("addedToDOM"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("sheet"),
	HX_CSTRING("disabled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLStyleElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLStyleElement_obj::__mClass,"__mClass");
};

Class HTMLStyleElement_obj::__mClass;

void HTMLStyleElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLStyleElement"), hx::TCanCast< HTMLStyleElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLStyleElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
