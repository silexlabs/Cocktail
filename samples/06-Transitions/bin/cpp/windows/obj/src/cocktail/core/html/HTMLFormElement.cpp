#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLFormElement
#include <cocktail/core/html/HTMLFormElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLObjectElement
#include <cocktail/core/html/HTMLObjectElement.h>
#endif
#ifndef INCLUDED_cocktail_core_url_URL
#include <cocktail/core/url/URL.h>
#endif
#ifndef INCLUDED_cocktail_plugin_Plugin
#include <cocktail/plugin/Plugin.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLFormElement_obj::__construct()
{
HX_STACK_PUSH("HTMLFormElement::new","cocktail/core/html/HTMLFormElement.hx",74);
{
	HX_STACK_LINE(75)
	super::__construct(HX_CSTRING("FORM"));
	HX_STACK_LINE(76)
	this->elements = Array_obj< ::cocktail::core::html::HTMLElement >::__new();
	HX_STACK_LINE(77)
	this->_submittedFromSubmitMethod = false;
}
;
	return null();
}

HTMLFormElement_obj::~HTMLFormElement_obj() { }

Dynamic HTMLFormElement_obj::__CreateEmpty() { return  new HTMLFormElement_obj; }
hx::ObjectPtr< HTMLFormElement_obj > HTMLFormElement_obj::__new()
{  hx::ObjectPtr< HTMLFormElement_obj > result = new HTMLFormElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLFormElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLFormElement_obj > result = new HTMLFormElement_obj();
	result->__construct();
	return result;}

::String HTMLFormElement_obj::set_action( ::String value){
	HX_STACK_PUSH("HTMLFormElement::set_action","cocktail/core/html/HTMLFormElement.hx",575);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(576)
	this->setAttribute(HX_CSTRING("action"),value);
	HX_STACK_LINE(577)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,set_action,return )

::String HTMLFormElement_obj::get_action( ){
	HX_STACK_PUSH("HTMLFormElement::get_action","cocktail/core/html/HTMLFormElement.hx",570);
	HX_STACK_THIS(this);
	HX_STACK_LINE(570)
	return this->getAttributeAsDOMString(HX_CSTRING("action"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLFormElement_obj,get_action,return )

::String HTMLFormElement_obj::set_enctype( ::String value){
	HX_STACK_PUSH("HTMLFormElement::set_enctype","cocktail/core/html/HTMLFormElement.hx",564);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(565)
	this->setAttribute(HX_CSTRING("enctype"),value);
	HX_STACK_LINE(566)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,set_enctype,return )

::String HTMLFormElement_obj::get_enctype( ){
	HX_STACK_PUSH("HTMLFormElement::get_enctype","cocktail/core/html/HTMLFormElement.hx",558);
	HX_STACK_THIS(this);
	HX_STACK_LINE(558)
	return this->getEnumeratedAttributeAsDOMString(HX_CSTRING("enctype"),Array_obj< ::String >::__new().Add(HX_CSTRING("application/x-www-form-urlencoded")).Add(HX_CSTRING("multipart/form-data")).Add(HX_CSTRING("text/plain")),null(),HX_CSTRING("application/x-www-form-urlencoded"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLFormElement_obj,get_enctype,return )

::String HTMLFormElement_obj::set_method( ::String value){
	HX_STACK_PUSH("HTMLFormElement::set_method","cocktail/core/html/HTMLFormElement.hx",552);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(553)
	this->setAttribute(HX_CSTRING("method"),value);
	HX_STACK_LINE(554)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,set_method,return )

::String HTMLFormElement_obj::get_method( ){
	HX_STACK_PUSH("HTMLFormElement::get_method","cocktail/core/html/HTMLFormElement.hx",546);
	HX_STACK_THIS(this);
	HX_STACK_LINE(546)
	return this->getEnumeratedAttributeAsDOMString(HX_CSTRING("method"),Array_obj< ::String >::__new().Add(HX_CSTRING("GET")).Add(HX_CSTRING("POST")),null(),HX_CSTRING("GET"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLFormElement_obj,get_method,return )

int HTMLFormElement_obj::get_length( ){
	HX_STACK_PUSH("HTMLFormElement::get_length","cocktail/core/html/HTMLFormElement.hx",541);
	HX_STACK_THIS(this);
	HX_STACK_LINE(541)
	return this->elements->length;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLFormElement_obj,get_length,return )

::String HTMLFormElement_obj::getElementValue( ::cocktail::core::html::HTMLElement element){
	HX_STACK_PUSH("HTMLFormElement::getElementValue","cocktail/core/html/HTMLFormElement.hx",524);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_LINE(524)
	::String _switch_1 = (element->tagName);
	if (  ( _switch_1==HX_CSTRING("INPUT"))){
		HX_STACK_LINE(528)
		::cocktail::core::html::HTMLInputElement inputElement = element;		HX_STACK_VAR(inputElement,"inputElement");
		HX_STACK_LINE(529)
		return inputElement->get_value();
	}
	else  {
		HX_STACK_LINE(531)
		return HX_CSTRING("");
	}
;
;
	HX_STACK_LINE(524)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getElementValue,return )

::String HTMLFormElement_obj::getElementType( ::cocktail::core::html::HTMLElement element){
	HX_STACK_PUSH("HTMLFormElement::getElementType","cocktail/core/html/HTMLFormElement.hx",508);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_LINE(508)
	::String _switch_2 = (element->tagName);
	if (  ( _switch_2==HX_CSTRING("INPUT"))){
		HX_STACK_LINE(512)
		::cocktail::core::html::HTMLInputElement inputElement = element;		HX_STACK_VAR(inputElement,"inputElement");
		HX_STACK_LINE(513)
		return inputElement->get_type();
	}
	else  {
		HX_STACK_LINE(515)
		return HX_CSTRING("");
	}
;
;
	HX_STACK_LINE(508)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getElementType,return )

bool HTMLFormElement_obj::isUncheckedRadioOrCheckBox( ::cocktail::core::html::HTMLElement element){
	HX_STACK_PUSH("HTMLFormElement::isUncheckedRadioOrCheckBox","cocktail/core/html/HTMLFormElement.hx",480);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_LINE(481)
	if (((element->tagName == HX_CSTRING("INPUT")))){
		HX_STACK_LINE(483)
		::cocktail::core::html::HTMLInputElement inputElement = element;		HX_STACK_VAR(inputElement,"inputElement");
		HX_STACK_LINE(484)
		::String _switch_3 = (inputElement->get_type());
		if (  ( _switch_3==HX_CSTRING("radio")) ||  ( _switch_3==HX_CSTRING("checkbox"))){
			HX_STACK_LINE(486)
			return (inputElement->get_checked() == false);
		}
	}
	HX_STACK_LINE(491)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,isUncheckedRadioOrCheckBox,return )

bool HTMLFormElement_obj::isButton( ::cocktail::core::html::HTMLElement element){
	HX_STACK_PUSH("HTMLFormElement::isButton","cocktail/core/html/HTMLFormElement.hx",455);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_LINE(456)
	if (((element->tagName == HX_CSTRING("BUTTON")))){
		HX_STACK_LINE(457)
		return true;
	}
	else{
		HX_STACK_LINE(460)
		if (((element->tagName == HX_CSTRING("INPUT")))){
			HX_STACK_LINE(462)
			::cocktail::core::html::HTMLInputElement inputElement = element;		HX_STACK_VAR(inputElement,"inputElement");
			HX_STACK_LINE(463)
			::String _switch_4 = (inputElement->get_type());
			if (  ( _switch_4==HX_CSTRING("reset")) ||  ( _switch_4==HX_CSTRING("button")) ||  ( _switch_4==HX_CSTRING("submit"))){
				HX_STACK_LINE(465)
				return true;
			}
		}
	}
	HX_STACK_LINE(472)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,isButton,return )

bool HTMLFormElement_obj::canBeSubmitted( ::cocktail::core::html::HTMLElement element,::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::canBeSubmitted","cocktail/core/html/HTMLFormElement.hx",404);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(408)
	if (((element->getAttribute(HX_CSTRING("disabled")) != null()))){
		HX_STACK_LINE(409)
		return false;
	}
	HX_STACK_LINE(414)
	if (((this->isButton(element) == true))){
		HX_STACK_LINE(415)
		if (((element != submitter))){
			HX_STACK_LINE(417)
			return false;
		}
	}
	HX_STACK_LINE(423)
	if (((this->isUncheckedRadioOrCheckBox(element) == true))){
		HX_STACK_LINE(424)
		return false;
	}
	HX_STACK_LINE(428)
	if (((this->getElementType(element) != HX_CSTRING("image")))){
		HX_STACK_LINE(429)
		if (((bool((element->getAttribute(HX_CSTRING("name")) == null())) || bool((element->getAttribute(HX_CSTRING("name")) == HX_CSTRING("")))))){
			HX_STACK_LINE(432)
			return false;
		}
	}
	HX_STACK_LINE(437)
	if (((element->tagName == HX_CSTRING("OBJECT")))){
		HX_STACK_LINE(439)
		::cocktail::core::html::HTMLObjectElement objectElement = element;		HX_STACK_VAR(objectElement,"objectElement");
		HX_STACK_LINE(440)
		if (((objectElement->plugin == null()))){
			HX_STACK_LINE(441)
			return false;
		}
	}
	HX_STACK_LINE(446)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLFormElement_obj,canBeSubmitted,return )

Array< ::cocktail::core::html::HTMLElement > HTMLFormElement_obj::getSubmittablesElements( ::cocktail::core::html::HTMLElement rootElement,Array< ::cocktail::core::html::HTMLElement > submittableElements){
	HX_STACK_PUSH("HTMLFormElement::getSubmittablesElements","cocktail/core/html/HTMLFormElement.hx",378);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElement,"rootElement");
	HX_STACK_ARG(submittableElements,"submittableElements");
	HX_STACK_LINE(379)
	::cocktail::core::html::HTMLElement child = rootElement->get_firstChild();		HX_STACK_VAR(child,"child");
	HX_STACK_LINE(380)
	while(((child != null()))){
		HX_STACK_LINE(382)
		::String _switch_5 = (child->tagName);
		if (  ( _switch_5==HX_CSTRING("INPUT")) ||  ( _switch_5==HX_CSTRING("OBJECT"))){
			HX_STACK_LINE(384)
			submittableElements->push(child);
		}
		HX_STACK_LINE(389)
		this->getSubmittablesElements(child,submittableElements);
		HX_STACK_LINE(390)
		child = child->get_nextSibling();
	}
	HX_STACK_LINE(393)
	return submittableElements;
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLFormElement_obj,getSubmittablesElements,return )

Dynamic HTMLFormElement_obj::constructFormDataSet( ::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::constructFormDataSet","cocktail/core/html/HTMLFormElement.hx",311);
	HX_STACK_THIS(this);
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(312)
	Array< ::cocktail::core::html::HTMLElement > submittableElements = this->getSubmittablesElements(hx::ObjectPtr<OBJ_>(this),Array_obj< ::cocktail::core::html::HTMLElement >::__new());		HX_STACK_VAR(submittableElements,"submittableElements");
	HX_STACK_LINE(314)
	Dynamic formDataSet = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(formDataSet,"formDataSet");
	HX_STACK_LINE(316)
	int length = submittableElements->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(317)
	{
		HX_STACK_LINE(317)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(317)
		while(((_g < length))){
			HX_STACK_LINE(317)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(319)
			::cocktail::core::html::HTMLElement submittableElement = submittableElements->__get(i);		HX_STACK_VAR(submittableElement,"submittableElement");
			HX_STACK_LINE(321)
			if (((this->canBeSubmitted(submittableElement,submitter) == true))){
				HX_STACK_LINE(323)
				::String type = this->getElementType(submittableElement);		HX_STACK_VAR(type,"type");
				HX_STACK_LINE(327)
				::String name = submittableElement->getAttribute(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(329)
				if (((submittableElement->tagName == HX_CSTRING("SELECT")))){
				}
				else{
					HX_STACK_LINE(333)
					if (((bool((submittableElement->tagName == HX_CSTRING("INPUT"))) && bool(((bool((type == HX_CSTRING("checkbox"))) || bool((type == HX_CSTRING("radio"))))))))){
						HX_STACK_LINE(336)
						::cocktail::core::html::HTMLInputElement inputElement = submittableElement;		HX_STACK_VAR(inputElement,"inputElement");
						HX_STACK_LINE(337)
						::String value = inputElement->get_value();		HX_STACK_VAR(value,"value");
						HX_STACK_LINE(338)
						if (((value == HX_CSTRING("")))){
							HX_STACK_LINE(339)
							value = HX_CSTRING("on");
						}
						struct _Function_6_1{
							inline static Dynamic Block( ::String &value,::String &name,::String &type){
								HX_STACK_PUSH("*::closure","cocktail/core/html/HTMLFormElement.hx",343);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_CSTRING("name") , name,false);
									__result->Add(HX_CSTRING("type") , type,false);
									__result->Add(HX_CSTRING("value") , value,false);
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(343)
						formDataSet->__Field(HX_CSTRING("push"),true)(_Function_6_1::Block(value,name,type));
					}
					else{
						HX_STACK_LINE(345)
						if (((bool((submittableElement->tagName == HX_CSTRING("INPUT"))) && bool((type == HX_CSTRING("file")))))){
						}
						else{
							HX_STACK_LINE(350)
							if (((submittableElement->tagName == HX_CSTRING("OBJECT")))){
							}
							else{
								HX_STACK_LINE(356)
								::String value = this->getElementValue(submittableElement);		HX_STACK_VAR(value,"value");
								struct _Function_8_1{
									inline static Dynamic Block( ::String &value,::String &name,::String &type){
										HX_STACK_PUSH("*::closure","cocktail/core/html/HTMLFormElement.hx",357);
										{
											hx::Anon __result = hx::Anon_obj::Create();
											__result->Add(HX_CSTRING("name") , name,false);
											__result->Add(HX_CSTRING("value") , value,false);
											__result->Add(HX_CSTRING("type") , type,false);
											return __result;
										}
										return null();
									}
								};
								HX_STACK_LINE(357)
								formDataSet->__Field(HX_CSTRING("push"),true)(_Function_8_1::Block(value,name,type));
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(368)
	return formDataSet;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,constructFormDataSet,return )

::String HTMLFormElement_obj::getSubmitTarget( ::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::getSubmitTarget","cocktail/core/html/HTMLFormElement.hx",296);
	HX_STACK_THIS(this);
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(296)
	return this->getAttributeAsDOMString(HX_CSTRING("target"));
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getSubmitTarget,return )

::String HTMLFormElement_obj::getSubmitMethod( ::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::getSubmitMethod","cocktail/core/html/HTMLFormElement.hx",277);
	HX_STACK_THIS(this);
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(278)
	::String formMethod = this->get_method();		HX_STACK_VAR(formMethod,"formMethod");
	HX_STACK_LINE(282)
	if (((formMethod == HX_CSTRING("")))){
		HX_STACK_LINE(283)
		formMethod = HX_CSTRING("GET");
	}
	HX_STACK_LINE(287)
	return formMethod;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getSubmitMethod,return )

::String HTMLFormElement_obj::getSubmitEnctype( ::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::getSubmitEnctype","cocktail/core/html/HTMLFormElement.hx",267);
	HX_STACK_THIS(this);
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(267)
	return this->get_enctype();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getSubmitEnctype,return )

::String HTMLFormElement_obj::getSubmitAction( ::cocktail::core::html::HTMLElement submitter){
	HX_STACK_PUSH("HTMLFormElement::getSubmitAction","cocktail/core/html/HTMLFormElement.hx",257);
	HX_STACK_THIS(this);
	HX_STACK_ARG(submitter,"submitter");
	HX_STACK_LINE(257)
	return this->get_action();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,getSubmitAction,return )

::String HTMLFormElement_obj::encodeAsURLQuery( Dynamic formDataSet){
	HX_STACK_PUSH("HTMLFormElement::encodeAsURLQuery","cocktail/core/html/HTMLFormElement.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_ARG(formDataSet,"formDataSet");
	HX_STACK_LINE(232)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(234)
	int length = formDataSet->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(235)
	{
		HX_STACK_LINE(235)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(235)
		while(((_g < length))){
			HX_STACK_LINE(235)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(237)
			if (((result != HX_CSTRING("")))){
				HX_STACK_LINE(238)
				hx::AddEq(result,HX_CSTRING("&"));
			}
			HX_STACK_LINE(242)
			Dynamic formData = formDataSet->__GetItem(i);		HX_STACK_VAR(formData,"formData");
			HX_STACK_LINE(243)
			hx::AddEq(result,((::StringTools_obj::urlEncode(formData->__Field(HX_CSTRING("name"),true)) + HX_CSTRING("=")) + ::StringTools_obj::urlEncode(formData->__Field(HX_CSTRING("value"),true))));
		}
	}
	HX_STACK_LINE(246)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,encodeAsURLQuery,return )

Void HTMLFormElement_obj::submitAsEntityBody( Dynamic formDataSet,::String action,::String enctype){
{
		HX_STACK_PUSH("HTMLFormElement::submitAsEntityBody","cocktail/core/html/HTMLFormElement.hx",219);
		HX_STACK_THIS(this);
		HX_STACK_ARG(formDataSet,"formDataSet");
		HX_STACK_ARG(action,"action");
		HX_STACK_ARG(enctype,"enctype");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(HTMLFormElement_obj,submitAsEntityBody,(void))

Void HTMLFormElement_obj::mutateActionUrl( Dynamic formDataSet,::String action){
{
		HX_STACK_PUSH("HTMLFormElement::mutateActionUrl","cocktail/core/html/HTMLFormElement.hx",202);
		HX_STACK_THIS(this);
		HX_STACK_ARG(formDataSet,"formDataSet");
		HX_STACK_ARG(action,"action");
		HX_STACK_LINE(203)
		::String query = this->encodeAsURLQuery(formDataSet);		HX_STACK_VAR(query,"query");
		HX_STACK_LINE(206)
		::cocktail::core::url::URL actionURL = ::cocktail::core::url::URL_obj::fromString(action);		HX_STACK_VAR(actionURL,"actionURL");
		HX_STACK_LINE(207)
		actionURL->query = query;
		HX_STACK_LINE(208)
		::String destination = ::cocktail::core::url::URL_obj::toString(actionURL);		HX_STACK_VAR(destination,"destination");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLFormElement_obj,mutateActionUrl,(void))

Void HTMLFormElement_obj::doSubmit( ::cocktail::core::html::HTMLElement submitter){
{
		HX_STACK_PUSH("HTMLFormElement::doSubmit","cocktail/core/html/HTMLFormElement.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_ARG(submitter,"submitter");
		HX_STACK_LINE(148)
		if (((this->_submittedFromSubmitMethod == false))){
			HX_STACK_LINE(150)
			bool defaultPrevented = this->fireEvent(HX_CSTRING("submit"),false,true);		HX_STACK_VAR(defaultPrevented,"defaultPrevented");
			HX_STACK_LINE(151)
			if (((defaultPrevented == true))){
				HX_STACK_LINE(152)
				return null();
			}
		}
		HX_STACK_LINE(157)
		Dynamic formDataSet = this->constructFormDataSet(submitter);		HX_STACK_VAR(formDataSet,"formDataSet");
		HX_STACK_LINE(159)
		::String action = this->getSubmitAction(submitter);		HX_STACK_VAR(action,"action");
		HX_STACK_LINE(163)
		::String scheme = ::cocktail::core::url::URL_obj::fromString(action)->scheme;		HX_STACK_VAR(scheme,"scheme");
		HX_STACK_LINE(165)
		::String enctype = this->getSubmitEnctype(submitter);		HX_STACK_VAR(enctype,"enctype");
		HX_STACK_LINE(167)
		::String method = this->getSubmitMethod(submitter);		HX_STACK_VAR(method,"method");
		HX_STACK_LINE(169)
		::String target = this->getSubmitTarget(submitter);		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(182)
		::String _switch_6 = (scheme);
		if (  ( _switch_6==HX_CSTRING("http"))){
			HX_STACK_LINE(184)
			if (((method.toUpperCase() == HX_CSTRING("GET")))){
				HX_STACK_LINE(186)
				this->mutateActionUrl(formDataSet,action);
			}
			else{
				HX_STACK_LINE(189)
				if (((method.toUpperCase() == HX_CSTRING("POST")))){
					HX_STACK_LINE(190)
					this->submitAsEntityBody(formDataSet,action,enctype);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,doSubmit,(void))

Void HTMLFormElement_obj::reset( ){
{
		HX_STACK_PUSH("HTMLFormElement::reset","cocktail/core/html/HTMLFormElement.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_LINE(110)
		bool defaultPrevented = this->fireEvent(HX_CSTRING("reset"),false,true);		HX_STACK_VAR(defaultPrevented,"defaultPrevented");
		HX_STACK_LINE(113)
		if (((defaultPrevented == true))){
			HX_STACK_LINE(114)
			return null();
		}
		HX_STACK_LINE(119)
		{
			HX_STACK_LINE(119)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->get_length();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(119)
			while(((_g1 < _g))){
				HX_STACK_LINE(119)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(121)
				this->elements->__get(i)->reset();
			}
		}
	}
return null();
}


Void HTMLFormElement_obj::submitFrom( ::cocktail::core::html::HTMLElement submitter){
{
		HX_STACK_PUSH("HTMLFormElement::submitFrom","cocktail/core/html/HTMLFormElement.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_ARG(submitter,"submitter");
		HX_STACK_LINE(101)
		this->_submittedFromSubmitMethod = false;
		HX_STACK_LINE(102)
		this->doSubmit(submitter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLFormElement_obj,submitFrom,(void))

Void HTMLFormElement_obj::submit( ){
{
		HX_STACK_PUSH("HTMLFormElement::submit","cocktail/core/html/HTMLFormElement.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_LINE(91)
		this->_submittedFromSubmitMethod = true;
		HX_STACK_LINE(92)
		this->doSubmit(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLFormElement_obj,submit,(void))


HTMLFormElement_obj::HTMLFormElement_obj()
{
}

void HTMLFormElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLFormElement);
	HX_MARK_MEMBER_NAME(action,"action");
	HX_MARK_MEMBER_NAME(enctype,"enctype");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_MEMBER_NAME(_submittedFromSubmitMethod,"_submittedFromSubmitMethod");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(elements,"elements");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLFormElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(action,"action");
	HX_VISIT_MEMBER_NAME(enctype,"enctype");
	HX_VISIT_MEMBER_NAME(method,"method");
	HX_VISIT_MEMBER_NAME(_submittedFromSubmitMethod,"_submittedFromSubmitMethod");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(elements,"elements");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLFormElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"submit") ) { return submit_dyn(); }
		if (HX_FIELD_EQ(inName,"action") ) { return inCallProp ? get_action() : action; }
		if (HX_FIELD_EQ(inName,"method") ) { return inCallProp ? get_method() : method; }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enctype") ) { return inCallProp ? get_enctype() : enctype; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isButton") ) { return isButton_dyn(); }
		if (HX_FIELD_EQ(inName,"doSubmit") ) { return doSubmit_dyn(); }
		if (HX_FIELD_EQ(inName,"elements") ) { return elements; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_action") ) { return set_action_dyn(); }
		if (HX_FIELD_EQ(inName,"get_action") ) { return get_action_dyn(); }
		if (HX_FIELD_EQ(inName,"set_method") ) { return set_method_dyn(); }
		if (HX_FIELD_EQ(inName,"get_method") ) { return get_method_dyn(); }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"submitFrom") ) { return submitFrom_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_enctype") ) { return set_enctype_dyn(); }
		if (HX_FIELD_EQ(inName,"get_enctype") ) { return get_enctype_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getElementType") ) { return getElementType_dyn(); }
		if (HX_FIELD_EQ(inName,"canBeSubmitted") ) { return canBeSubmitted_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getElementValue") ) { return getElementValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getSubmitTarget") ) { return getSubmitTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"getSubmitMethod") ) { return getSubmitMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"getSubmitAction") ) { return getSubmitAction_dyn(); }
		if (HX_FIELD_EQ(inName,"mutateActionUrl") ) { return mutateActionUrl_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getSubmitEnctype") ) { return getSubmitEnctype_dyn(); }
		if (HX_FIELD_EQ(inName,"encodeAsURLQuery") ) { return encodeAsURLQuery_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"submitAsEntityBody") ) { return submitAsEntityBody_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"constructFormDataSet") ) { return constructFormDataSet_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getSubmittablesElements") ) { return getSubmittablesElements_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"isUncheckedRadioOrCheckBox") ) { return isUncheckedRadioOrCheckBox_dyn(); }
		if (HX_FIELD_EQ(inName,"_submittedFromSubmitMethod") ) { return _submittedFromSubmitMethod; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLFormElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"action") ) { if (inCallProp) return set_action(inValue);action=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"method") ) { if (inCallProp) return set_method(inValue);method=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enctype") ) { if (inCallProp) return set_enctype(inValue);enctype=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"elements") ) { elements=inValue.Cast< Array< ::cocktail::core::html::HTMLElement > >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"_submittedFromSubmitMethod") ) { _submittedFromSubmitMethod=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLFormElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("action"));
	outFields->push(HX_CSTRING("enctype"));
	outFields->push(HX_CSTRING("method"));
	outFields->push(HX_CSTRING("_submittedFromSubmitMethod"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("elements"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_action"),
	HX_CSTRING("get_action"),
	HX_CSTRING("set_enctype"),
	HX_CSTRING("get_enctype"),
	HX_CSTRING("set_method"),
	HX_CSTRING("get_method"),
	HX_CSTRING("get_length"),
	HX_CSTRING("getElementValue"),
	HX_CSTRING("getElementType"),
	HX_CSTRING("isUncheckedRadioOrCheckBox"),
	HX_CSTRING("isButton"),
	HX_CSTRING("canBeSubmitted"),
	HX_CSTRING("getSubmittablesElements"),
	HX_CSTRING("constructFormDataSet"),
	HX_CSTRING("getSubmitTarget"),
	HX_CSTRING("getSubmitMethod"),
	HX_CSTRING("getSubmitEnctype"),
	HX_CSTRING("getSubmitAction"),
	HX_CSTRING("encodeAsURLQuery"),
	HX_CSTRING("submitAsEntityBody"),
	HX_CSTRING("mutateActionUrl"),
	HX_CSTRING("doSubmit"),
	HX_CSTRING("reset"),
	HX_CSTRING("submitFrom"),
	HX_CSTRING("submit"),
	HX_CSTRING("action"),
	HX_CSTRING("enctype"),
	HX_CSTRING("method"),
	HX_CSTRING("_submittedFromSubmitMethod"),
	HX_CSTRING("length"),
	HX_CSTRING("elements"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLFormElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLFormElement_obj::__mClass,"__mClass");
};

Class HTMLFormElement_obj::__mClass;

void HTMLFormElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLFormElement"), hx::TCanCast< HTMLFormElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLFormElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
