#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
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
#ifndef INCLUDED_cocktail_core_html_ValueModeValue
#include <cocktail/core/html/ValueModeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_CheckboxRenderer
#include <cocktail/core/renderer/CheckboxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InputButtonRenderer
#include <cocktail/core/renderer/InputButtonRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InputRenderer
#include <cocktail/core/renderer/InputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_PasswordInputRenderer
#include <cocktail/core/renderer/PasswordInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_RadioRenderer
#include <cocktail/core/renderer/RadioRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#include <cocktail/core/renderer/TextInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLInputElement_obj::__construct()
{
HX_STACK_PUSH("HTMLInputElement::new","cocktail/core/html/HTMLInputElement.hx",141);
{
	HX_STACK_LINE(142)
	super::__construct(HX_CSTRING("INPUT"));
	HX_STACK_LINE(144)
	this->_valueIsDirty = false;
	HX_STACK_LINE(145)
	this->_checkednessIsDirty = false;
	HX_STACK_LINE(146)
	this->_valueMode = ::cocktail::core::html::ValueModeValue_obj::VALUE_dyn();
	HX_STACK_LINE(147)
	this->_value = HX_CSTRING("");
	HX_STACK_LINE(148)
	this->_checkedness = false;
}
;
	return null();
}

HTMLInputElement_obj::~HTMLInputElement_obj() { }

Dynamic HTMLInputElement_obj::__CreateEmpty() { return  new HTMLInputElement_obj; }
hx::ObjectPtr< HTMLInputElement_obj > HTMLInputElement_obj::__new()
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLInputElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

::String HTMLInputElement_obj::set_name( ::String value){
	HX_STACK_PUSH("HTMLInputElement::set_name","cocktail/core/html/HTMLInputElement.hx",907);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(908)
	this->setAttribute(HX_CSTRING("name"),value);
	HX_STACK_LINE(909)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_name,return )

::String HTMLInputElement_obj::get_name( ){
	HX_STACK_PUSH("HTMLInputElement::get_name","cocktail/core/html/HTMLInputElement.hx",902);
	HX_STACK_THIS(this);
	HX_STACK_LINE(902)
	return this->getAttributeAsDOMString(HX_CSTRING("name"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_name,return )

::String HTMLInputElement_obj::set_type( ::String value){
	HX_STACK_PUSH("HTMLInputElement::set_type","cocktail/core/html/HTMLInputElement.hx",894);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(895)
	::String oldType = this->get_type();		HX_STACK_VAR(oldType,"oldType");
	HX_STACK_LINE(896)
	this->setAttribute(HX_CSTRING("type"),value);
	HX_STACK_LINE(897)
	this->updateInputType(oldType);
	HX_STACK_LINE(898)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_type,return )

::String HTMLInputElement_obj::get_type( ){
	HX_STACK_PUSH("HTMLInputElement::get_type","cocktail/core/html/HTMLInputElement.hx",889);
	HX_STACK_THIS(this);
	HX_STACK_LINE(889)
	return this->getEnumeratedAttributeAsDOMString(HX_CSTRING("type"),Array_obj< ::String >::__new().Add(HX_CSTRING("hidden")).Add(HX_CSTRING("text")).Add(HX_CSTRING("password")).Add(HX_CSTRING("checkbox")).Add(HX_CSTRING("radio")).Add(HX_CSTRING("submit")).Add(HX_CSTRING("reset")).Add(HX_CSTRING("button")).Add(HX_CSTRING("file")).Add(HX_CSTRING("image")),HX_CSTRING("text"),null());
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_type,return )

bool HTMLInputElement_obj::set_disabled( bool value){
	HX_STACK_PUSH("HTMLInputElement::set_disabled","cocktail/core/html/HTMLInputElement.hx",883);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(884)
	this->setAttributeAsBool(HX_CSTRING("disabled"),value);
	HX_STACK_LINE(885)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_disabled,return )

bool HTMLInputElement_obj::get_disabled( ){
	HX_STACK_PUSH("HTMLInputElement::get_disabled","cocktail/core/html/HTMLInputElement.hx",878);
	HX_STACK_THIS(this);
	HX_STACK_LINE(878)
	return this->getAttributeAsBool(HX_CSTRING("disabled"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_disabled,return )

bool HTMLInputElement_obj::set_readonly( bool value){
	HX_STACK_PUSH("HTMLInputElement::set_readonly","cocktail/core/html/HTMLInputElement.hx",872);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(873)
	this->setAttributeAsBool(HX_CSTRING("readonly"),value);
	HX_STACK_LINE(874)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_readonly,return )

bool HTMLInputElement_obj::get_readonly( ){
	HX_STACK_PUSH("HTMLInputElement::get_readonly","cocktail/core/html/HTMLInputElement.hx",867);
	HX_STACK_THIS(this);
	HX_STACK_LINE(867)
	return this->getAttributeAsBool(HX_CSTRING("readonly"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_readonly,return )

bool HTMLInputElement_obj::set_checked( bool value){
	HX_STACK_PUSH("HTMLInputElement::set_checked","cocktail/core/html/HTMLInputElement.hx",860);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(861)
	this->_checkednessIsDirty = true;
	HX_STACK_LINE(862)
	this->updateCheckedness(value);
	HX_STACK_LINE(863)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_checked,return )

bool HTMLInputElement_obj::get_checked( ){
	HX_STACK_PUSH("HTMLInputElement::get_checked","cocktail/core/html/HTMLInputElement.hx",855);
	HX_STACK_THIS(this);
	HX_STACK_LINE(855)
	return this->_checkedness;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_checked,return )

int HTMLInputElement_obj::get_maxLength( ){
	HX_STACK_PUSH("HTMLInputElement::get_maxLength","cocktail/core/html/HTMLInputElement.hx",850);
	HX_STACK_THIS(this);
	HX_STACK_LINE(850)
	return this->getAttributeAsPositiveSignedInteger(HX_CSTRING("maxlength"),null());
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_maxLength,return )

int HTMLInputElement_obj::set_maxLength( int value){
	HX_STACK_PUSH("HTMLInputElement::set_maxLength","cocktail/core/html/HTMLInputElement.hx",844);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(845)
	this->setAttribute(HX_CSTRING("maxlength"),::Std_obj::string(value));
	HX_STACK_LINE(846)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_maxLength,return )

::String HTMLInputElement_obj::get_value( ){
	HX_STACK_PUSH("HTMLInputElement::get_value","cocktail/core/html/HTMLInputElement.hx",815);
	HX_STACK_THIS(this);
	HX_STACK_LINE(815)
	{
		::cocktail::core::html::ValueModeValue _switch_1 = (this->_valueMode);
		switch((_switch_1)->GetIndex()){
			case 0: {
				HX_STACK_LINE(818)
				return this->_value;
			}
			;break;
			case 1: {
				HX_STACK_LINE(821)
				return this->getAttributeAsDOMString(HX_CSTRING("value"));
			}
			;break;
			case 2: {
				HX_STACK_LINE(825)
				::String value = this->getAttributeAsDOMString(HX_CSTRING("value"));		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(826)
				if (((value == HX_CSTRING("")))){
					HX_STACK_LINE(827)
					return HX_CSTRING("on");
				}
				else{
					HX_STACK_LINE(831)
					return value;
				}
			}
			;break;
			case 3: {
				HX_STACK_LINE(835)
				return HX_CSTRING("");
			}
			;break;
		}
	}
	HX_STACK_LINE(815)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_value,return )

::String HTMLInputElement_obj::set_value( ::String value){
	HX_STACK_PUSH("HTMLInputElement::set_value","cocktail/core/html/HTMLInputElement.hx",794);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(795)
	this->_valueIsDirty = true;
	HX_STACK_LINE(797)
	{
		::cocktail::core::html::ValueModeValue _switch_2 = (this->_valueMode);
		switch((_switch_2)->GetIndex()){
			case 0: {
				HX_STACK_LINE(799)
				this->_value = value;
			}
			;break;
			case 1: case 2: {
				HX_STACK_LINE(802)
				this->setAttribute(HX_CSTRING("value"),value);
			}
			;break;
			case 3: {
			}
			;break;
		}
	}
	HX_STACK_LINE(811)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_value,return )

Dynamic HTMLInputElement_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("HTMLInputElement::get_intrinsicHeight","cocktail/core/html/HTMLInputElement.hx",779);
	HX_STACK_THIS(this);
	HX_STACK_LINE(780)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(782)
		::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
		HX_STACK_LINE(783)
		return inputRenderer->get_intrinsicHeight();
	}
	HX_STACK_LINE(786)
	return (int)0;
}


Dynamic HTMLInputElement_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("HTMLInputElement::get_intrinsicWidth","cocktail/core/html/HTMLInputElement.hx",768);
	HX_STACK_THIS(this);
	HX_STACK_LINE(769)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(771)
		::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
		HX_STACK_LINE(772)
		return inputRenderer->get_intrinsicWidth();
	}
	HX_STACK_LINE(775)
	return (int)0;
}


Void HTMLInputElement_obj::onUserInput( ){
{
		HX_STACK_PUSH("HTMLInputElement::onUserInput","cocktail/core/html/HTMLInputElement.hx",753);
		HX_STACK_THIS(this);
		HX_STACK_LINE(754)
		this->_valueIsDirty = true;
		HX_STACK_LINE(757)
		::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
		HX_STACK_LINE(758)
		this->_value = inputRenderer->get_value();
		HX_STACK_LINE(760)
		this->fireEvent(HX_CSTRING("input"),true,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,onUserInput,(void))

Void HTMLInputElement_obj::onUserActivation( ){
{
		HX_STACK_PUSH("HTMLInputElement::onUserActivation","cocktail/core/html/HTMLInputElement.hx",743);
		HX_STACK_THIS(this);
		HX_STACK_LINE(743)
		this->triggerActivationBehaviour(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,onUserActivation,(void))

::String HTMLInputElement_obj::getElementRendererValue( ){
	HX_STACK_PUSH("HTMLInputElement::getElementRendererValue","cocktail/core/html/HTMLInputElement.hx",707);
	HX_STACK_THIS(this);
	HX_STACK_LINE(708)
	::String _switch_3 = (this->get_type());
	if (  ( _switch_3==HX_CSTRING("reset")) ||  ( _switch_3==HX_CSTRING("submit"))){
		HX_STACK_LINE(713)
		::String valueAttribute = this->getAttribute(HX_CSTRING("value"));		HX_STACK_VAR(valueAttribute,"valueAttribute");
		HX_STACK_LINE(714)
		if (((valueAttribute == null()))){
			HX_STACK_LINE(715)
			if (((this->get_type() == HX_CSTRING("reset")))){
				HX_STACK_LINE(717)
				return HX_CSTRING("Reset");
			}
			else{
				HX_STACK_LINE(721)
				return HX_CSTRING("Submit");
			}
		}
	}
	HX_STACK_LINE(728)
	return this->get_value();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,getElementRendererValue,return )

Void HTMLInputElement_obj::dissociateFormElement( ::cocktail::core::html::HTMLFormElement form){
{
		HX_STACK_PUSH("HTMLInputElement::dissociateFormElement","cocktail/core/html/HTMLInputElement.hx",697);
		HX_STACK_THIS(this);
		HX_STACK_ARG(form,"form");
		HX_STACK_LINE(697)
		form->elements->remove(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,dissociateFormElement,(void))

Void HTMLInputElement_obj::associateFormElement( ::cocktail::core::html::HTMLFormElement form){
{
		HX_STACK_PUSH("HTMLInputElement::associateFormElement","cocktail/core/html/HTMLInputElement.hx",689);
		HX_STACK_THIS(this);
		HX_STACK_ARG(form,"form");
		HX_STACK_LINE(689)
		form->elements->push(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,associateFormElement,(void))

::cocktail::core::html::HTMLFormElement HTMLInputElement_obj::getFirstFormAncestor( ){
	HX_STACK_PUSH("HTMLInputElement::getFirstFormAncestor","cocktail/core/html/HTMLInputElement.hx",671);
	HX_STACK_THIS(this);
	HX_STACK_LINE(672)
	::cocktail::core::html::HTMLElement parent = this->parentNode;		HX_STACK_VAR(parent,"parent");
	HX_STACK_LINE(673)
	while(((parent != null()))){
		HX_STACK_LINE(675)
		if (((parent->tagName == HX_CSTRING("FORM")))){
			HX_STACK_LINE(676)
			return parent;
		}
		HX_STACK_LINE(679)
		parent = parent->parentNode;
	}
	HX_STACK_LINE(682)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,getFirstFormAncestor,return )

Void HTMLInputElement_obj::resetFormOwner( ){
{
		HX_STACK_PUSH("HTMLInputElement::resetFormOwner","cocktail/core/html/HTMLInputElement.hx",633);
		HX_STACK_THIS(this);
		HX_STACK_LINE(634)
		::cocktail::core::html::HTMLFormElement firstFormAncestor = this->getFirstFormAncestor();		HX_STACK_VAR(firstFormAncestor,"firstFormAncestor");
		HX_STACK_LINE(638)
		if (((firstFormAncestor == this->form))){
			HX_STACK_LINE(639)
			return null();
		}
		HX_STACK_LINE(644)
		if (((this->form != null()))){
			HX_STACK_LINE(646)
			this->dissociateFormElement(this->form);
			HX_STACK_LINE(647)
			this->form = null();
		}
		HX_STACK_LINE(651)
		if (((firstFormAncestor != null()))){
			HX_STACK_LINE(653)
			this->form = firstFormAncestor;
			HX_STACK_LINE(654)
			this->associateFormElement(this->form);
			HX_STACK_LINE(658)
			if (((bool((this->_checkedness == true)) && bool((this->get_type() == HX_CSTRING("radio")))))){
				HX_STACK_LINE(659)
				this->updateRadioButtonGroup();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,resetFormOwner,(void))

Void HTMLInputElement_obj::updateRadioButtonGroup( ){
{
		HX_STACK_PUSH("HTMLInputElement::updateRadioButtonGroup","cocktail/core/html/HTMLInputElement.hx",590);
		HX_STACK_THIS(this);
		HX_STACK_LINE(592)
		if (((this->get_name() == HX_CSTRING("")))){
			HX_STACK_LINE(593)
			return null();
		}
		HX_STACK_LINE(599)
		Array< ::cocktail::core::html::HTMLElement > inputElements = this->_ownerHTMLDocument->getElementsByTagName(HX_CSTRING("INPUT"));		HX_STACK_VAR(inputElements,"inputElements");
		HX_STACK_LINE(601)
		int inputLength = inputElements->length;		HX_STACK_VAR(inputLength,"inputLength");
		HX_STACK_LINE(602)
		{
			HX_STACK_LINE(602)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(602)
			while(((_g < inputLength))){
				HX_STACK_LINE(602)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(604)
				::cocktail::core::html::HTMLInputElement input = inputElements->__get(i);		HX_STACK_VAR(input,"input");
				HX_STACK_LINE(605)
				if (((bool((input->get_type() == HX_CSTRING("radio"))) && bool((input != hx::ObjectPtr<OBJ_>(this)))))){
					HX_STACK_LINE(606)
					if (((input->form == this->form))){
						HX_STACK_LINE(610)
						if (((input->get_name() == this->get_name()))){
							HX_STACK_LINE(613)
							input->set_checked(false);
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,updateRadioButtonGroup,(void))

Void HTMLInputElement_obj::updateCheckedness( bool value){
{
		HX_STACK_PUSH("HTMLInputElement::updateCheckedness","cocktail/core/html/HTMLInputElement.hx",569);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(570)
		this->_checkedness = value;
		HX_STACK_LINE(574)
		this->invalidateStyleDeclaration(false);
		HX_STACK_LINE(579)
		if (((bool((this->_checkedness == true)) && bool((this->get_type() == HX_CSTRING("radio")))))){
			HX_STACK_LINE(580)
			this->updateRadioButtonGroup();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,updateCheckedness,(void))

bool HTMLInputElement_obj::readonlyApplies( ){
	HX_STACK_PUSH("HTMLInputElement::readonlyApplies","cocktail/core/html/HTMLInputElement.hx",549);
	HX_STACK_THIS(this);
	HX_STACK_LINE(549)
	::String _switch_4 = (this->get_type());
	if (  ( _switch_4==HX_CSTRING("text")) ||  ( _switch_4==HX_CSTRING("password"))){
		HX_STACK_LINE(553)
		return true;
	}
	else  {
		HX_STACK_LINE(556)
		return false;
	}
;
;
	HX_STACK_LINE(549)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,readonlyApplies,return )

bool HTMLInputElement_obj::isMutable( ){
	HX_STACK_PUSH("HTMLInputElement::isMutable","cocktail/core/html/HTMLInputElement.hx",531);
	HX_STACK_THIS(this);
	HX_STACK_LINE(532)
	if (((this->get_disabled() == true))){
		HX_STACK_LINE(533)
		return false;
	}
	else{
		HX_STACK_LINE(536)
		if (((this->readonlyApplies() == true))){
			HX_STACK_LINE(537)
			return (this->get_readonly() == false);
		}
	}
	HX_STACK_LINE(541)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,isMutable,return )

::String HTMLInputElement_obj::applyValueSanitization( ::String value,::String type){
	HX_STACK_PUSH("HTMLInputElement::applyValueSanitization","cocktail/core/html/HTMLInputElement.hx",515);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(517)
	::String _switch_5 = (type);
	if (  ( _switch_5==HX_CSTRING("text")) ||  ( _switch_5==HX_CSTRING("password"))){
		HX_STACK_LINE(519)
		return ::StringTools_obj::replace(value,HX_CSTRING("\n"),HX_CSTRING(""));
	}
	HX_STACK_LINE(523)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLInputElement_obj,applyValueSanitization,return )

bool HTMLInputElement_obj::useDefaultOrDefaultOnMode( ::String type){
	HX_STACK_PUSH("HTMLInputElement::useDefaultOrDefaultOnMode","cocktail/core/html/HTMLInputElement.hx",498);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(498)
	::String _switch_6 = (type);
	if (  ( _switch_6==HX_CSTRING("text")) ||  ( _switch_6==HX_CSTRING("password"))){
		HX_STACK_LINE(502)
		return false;
	}
	else  {
		HX_STACK_LINE(505)
		return true;
	}
;
;
	HX_STACK_LINE(498)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,useDefaultOrDefaultOnMode,return )

bool HTMLInputElement_obj::useValueMode( ::String type){
	HX_STACK_PUSH("HTMLInputElement::useValueMode","cocktail/core/html/HTMLInputElement.hx",479);
	HX_STACK_THIS(this);
	HX_STACK_ARG(type,"type");
	HX_STACK_LINE(479)
	::String _switch_7 = (type);
	if (  ( _switch_7==HX_CSTRING("hidden")) ||  ( _switch_7==HX_CSTRING("checkbox")) ||  ( _switch_7==HX_CSTRING("radio"))){
		HX_STACK_LINE(483)
		return false;
	}
	else  {
		HX_STACK_LINE(487)
		return true;
	}
;
;
	HX_STACK_LINE(479)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,useValueMode,return )

Void HTMLInputElement_obj::updateInputType( ::String oldType){
{
		HX_STACK_PUSH("HTMLInputElement::updateInputType","cocktail/core/html/HTMLInputElement.hx",448);
		HX_STACK_THIS(this);
		HX_STACK_ARG(oldType,"oldType");
		HX_STACK_LINE(450)
		if (((oldType == this->get_type()))){
			HX_STACK_LINE(451)
			return null();
		}
		HX_STACK_LINE(455)
		if (((bool((this->useValueMode(oldType) == true)) && bool((this->useDefaultOrDefaultOnMode(this->get_type()) == true))))){
			HX_STACK_LINE(456)
			if (((this->_value != HX_CSTRING("")))){
				HX_STACK_LINE(458)
				this->setAttribute(HX_CSTRING("value"),this->_value);
			}
		}
		else{
			HX_STACK_LINE(462)
			if (((bool((this->useValueMode(oldType) == false)) && bool((this->useValueMode(this->get_type()) == true))))){
				HX_STACK_LINE(464)
				this->_value = this->getAttributeAsDOMString(HX_CSTRING("value"));
				HX_STACK_LINE(465)
				this->_valueIsDirty = false;
			}
		}
		HX_STACK_LINE(468)
		this->invalidateElementRenderer();
		HX_STACK_LINE(470)
		this->_value = this->applyValueSanitization(this->_value,this->get_type());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,updateInputType,(void))

Void HTMLInputElement_obj::updateInputRendererState( ){
{
		HX_STACK_PUSH("HTMLInputElement::updateInputRendererState","cocktail/core/html/HTMLInputElement.hx",424);
		HX_STACK_THIS(this);
		HX_STACK_LINE(424)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(427)
			::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
			HX_STACK_LINE(428)
			inputRenderer->set_readonly(this->get_readonly());
			HX_STACK_LINE(429)
			inputRenderer->set_disabled(this->get_disabled());
			HX_STACK_LINE(430)
			inputRenderer->set_maxLength(this->get_maxLength());
			HX_STACK_LINE(431)
			inputRenderer->set_value(this->getElementRendererValue());
			HX_STACK_LINE(432)
			inputRenderer->set_checked(this->_checkedness);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,updateInputRendererState,(void))

Void HTMLInputElement_obj::runPostClickActivationStep( ::cocktail::core::event::MouseEvent event){
{
		HX_STACK_PUSH("HTMLInputElement::runPostClickActivationStep","cocktail/core/html/HTMLInputElement.hx",400);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(402)
		if (((this->isMutable() == false))){
			HX_STACK_LINE(403)
			return null();
		}
		HX_STACK_LINE(407)
		::String _switch_8 = (this->get_type());
		if (  ( _switch_8==HX_CSTRING("checkbox")) ||  ( _switch_8==HX_CSTRING("radio"))){
			HX_STACK_LINE(410)
			this->fireEvent(HX_CSTRING("change"),false,false);
		}
	}
return null();
}


Void HTMLInputElement_obj::runPreClickActivation( ){
{
		HX_STACK_PUSH("HTMLInputElement::runPreClickActivation","cocktail/core/html/HTMLInputElement.hx",362);
		HX_STACK_THIS(this);
		HX_STACK_LINE(364)
		if (((this->isMutable() == false))){
			HX_STACK_LINE(365)
			return null();
		}
		HX_STACK_LINE(369)
		::String _switch_9 = (this->get_type());
		if (  ( _switch_9==HX_CSTRING("checkbox"))){
			HX_STACK_LINE(372)
			this->updateCheckedness(!(this->_checkedness));
		}
		else if (  ( _switch_9==HX_CSTRING("radio"))){
			HX_STACK_LINE(377)
			this->updateCheckedness(true);
		}
		else if (  ( _switch_9==HX_CSTRING("reset"))){
			HX_STACK_LINE(381)
			if (((this->form != null()))){
				HX_STACK_LINE(383)
				this->form->reset();
			}
		}
		else if (  ( _switch_9==HX_CSTRING("submit"))){
			HX_STACK_LINE(388)
			if (((this->form != null()))){
				HX_STACK_LINE(390)
				this->form->submitFrom(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


bool HTMLInputElement_obj::hasActivationBehaviour( ){
	HX_STACK_PUSH("HTMLInputElement::hasActivationBehaviour","cocktail/core/html/HTMLInputElement.hx",345);
	HX_STACK_THIS(this);
	HX_STACK_LINE(345)
	::String _switch_10 = (this->get_type());
	if (  ( _switch_10==HX_CSTRING("button")) ||  ( _switch_10==HX_CSTRING("checkbox")) ||  ( _switch_10==HX_CSTRING("radio")) ||  ( _switch_10==HX_CSTRING("reset")) ||  ( _switch_10==HX_CSTRING("submit"))){
		HX_STACK_LINE(348)
		return true;
	}
	else  {
		HX_STACK_LINE(353)
		return false;
	}
;
;
	HX_STACK_LINE(345)
	return false;
}


Void HTMLInputElement_obj::removed( ){
{
		HX_STACK_PUSH("HTMLInputElement::removed","cocktail/core/html/HTMLInputElement.hx",332);
		HX_STACK_THIS(this);
		HX_STACK_LINE(333)
		this->super::removed();
		HX_STACK_LINE(334)
		this->resetFormOwner();
	}
return null();
}


Void HTMLInputElement_obj::appended( ){
{
		HX_STACK_PUSH("HTMLInputElement::appended","cocktail/core/html/HTMLInputElement.hx",322);
		HX_STACK_THIS(this);
		HX_STACK_LINE(323)
		this->super::appended();
		HX_STACK_LINE(324)
		this->resetFormOwner();
	}
return null();
}


bool HTMLInputElement_obj::isDefaultFocusable( ){
	HX_STACK_PUSH("HTMLInputElement::isDefaultFocusable","cocktail/core/html/HTMLInputElement.hx",309);
	HX_STACK_THIS(this);
	HX_STACK_LINE(309)
	return true;
}


Void HTMLInputElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLInputElement::createElementRenderer","cocktail/core/html/HTMLInputElement.hx",266);
		HX_STACK_THIS(this);
		HX_STACK_LINE(267)
		::String _switch_11 = (this->get_type());
		if (  ( _switch_11==HX_CSTRING("text"))){
			HX_STACK_LINE(269)
			this->elementRenderer = ::cocktail::core::renderer::TextInputRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
		else if (  ( _switch_11==HX_CSTRING("password"))){
			HX_STACK_LINE(272)
			this->elementRenderer = ::cocktail::core::renderer::PasswordInputRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
		else if (  ( _switch_11==HX_CSTRING("checkbox"))){
			HX_STACK_LINE(275)
			this->elementRenderer = ::cocktail::core::renderer::CheckboxRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
		else if (  ( _switch_11==HX_CSTRING("radio"))){
			HX_STACK_LINE(278)
			this->elementRenderer = ::cocktail::core::renderer::RadioRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
		else if (  ( _switch_11==HX_CSTRING("button")) ||  ( _switch_11==HX_CSTRING("reset")) ||  ( _switch_11==HX_CSTRING("submit"))){
			HX_STACK_LINE(281)
			this->elementRenderer = ::cocktail::core::renderer::InputButtonRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		}
		else  {
		}
;
;
		HX_STACK_LINE(290)
		if (((this->elementRenderer != null()))){
			HX_STACK_LINE(292)
			::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
			HX_STACK_LINE(293)
			inputRenderer->onActivate = this->onUserActivation_dyn();
			HX_STACK_LINE(294)
			inputRenderer->onInput = this->onUserInput_dyn();
			HX_STACK_LINE(296)
			this->updateInputRendererState();
		}
	}
return null();
}


Void HTMLInputElement_obj::reset( ){
{
		HX_STACK_PUSH("HTMLInputElement::reset","cocktail/core/html/HTMLInputElement.hx",243);
		HX_STACK_THIS(this);
		HX_STACK_LINE(244)
		this->_valueIsDirty = false;
		HX_STACK_LINE(245)
		this->_checkednessIsDirty = false;
		HX_STACK_LINE(246)
		this->_value = this->getAttributeAsDOMString(HX_CSTRING("value"));
		HX_STACK_LINE(247)
		this->updateCheckedness(this->getAttributeAsBool(HX_CSTRING("checked")));
		HX_STACK_LINE(251)
		this->applyValueSanitization(this->get_value(),this->get_type());
		HX_STACK_LINE(254)
		this->updateInputRendererState();
	}
return null();
}


Void HTMLInputElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLInputElement::setAttribute","cocktail/core/html/HTMLInputElement.hx",202);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(203)
		this->super::setAttribute(name,value);
		HX_STACK_LINE(209)
		if (((name == HX_CSTRING("value")))){
			HX_STACK_LINE(210)
			if (((this->_valueIsDirty == false))){
				HX_STACK_LINE(212)
				this->_value = value;
			}
		}
		else{
			HX_STACK_LINE(217)
			if (((name == HX_CSTRING("checked")))){
				HX_STACK_LINE(218)
				if (((this->_checkednessIsDirty == false))){
					HX_STACK_LINE(220)
					this->updateCheckedness(this->get_checked());
				}
			}
			else{
				HX_STACK_LINE(226)
				if (((name == HX_CSTRING("name")))){
					HX_STACK_LINE(227)
					if (((bool((this->_checkedness == true)) && bool((this->get_type() == HX_CSTRING("radio")))))){
						HX_STACK_LINE(229)
						this->updateRadioButtonGroup();
					}
				}
			}
		}
	}
return null();
}


bool HTMLInputElement_obj::dispatchEvent( ::cocktail::core::event::Event evt){
	HX_STACK_PUSH("HTMLInputElement::dispatchEvent","cocktail/core/html/HTMLInputElement.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(evt,"evt");
	HX_STACK_LINE(174)
	bool defaultPrevented = this->super::dispatchEvent(evt);		HX_STACK_VAR(defaultPrevented,"defaultPrevented");
	HX_STACK_LINE(176)
	if (((this->elementRenderer != null()))){
		HX_STACK_LINE(177)
		if (((evt->type == HX_CSTRING("focus")))){
			HX_STACK_LINE(180)
			::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
			HX_STACK_LINE(181)
			inputRenderer->focus();
		}
		else{
			HX_STACK_LINE(183)
			if (((evt->type == HX_CSTRING("blur")))){
				HX_STACK_LINE(185)
				::cocktail::core::renderer::InputRenderer inputRenderer = this->elementRenderer;		HX_STACK_VAR(inputRenderer,"inputRenderer");
				HX_STACK_LINE(186)
				inputRenderer->blur();
			}
		}
	}
	HX_STACK_LINE(190)
	return defaultPrevented;
}


bool HTMLInputElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLInputElement::isVoidElement","cocktail/core/html/HTMLInputElement.hx",160);
	HX_STACK_THIS(this);
	HX_STACK_LINE(160)
	return true;
}



HTMLInputElement_obj::HTMLInputElement_obj()
{
}

void HTMLInputElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLInputElement);
	HX_MARK_MEMBER_NAME(form,"form");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(readOnly,"readOnly");
	HX_MARK_MEMBER_NAME(checked,"checked");
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(_checkednessIsDirty,"_checkednessIsDirty");
	HX_MARK_MEMBER_NAME(_checkedness,"_checkedness");
	HX_MARK_MEMBER_NAME(_valueIsDirty,"_valueIsDirty");
	HX_MARK_MEMBER_NAME(_valueMode,"_valueMode");
	HX_MARK_MEMBER_NAME(_value,"_value");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLInputElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(form,"form");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	HX_VISIT_MEMBER_NAME(readOnly,"readOnly");
	HX_VISIT_MEMBER_NAME(checked,"checked");
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(_checkednessIsDirty,"_checkednessIsDirty");
	HX_VISIT_MEMBER_NAME(_checkedness,"_checkedness");
	HX_VISIT_MEMBER_NAME(_valueIsDirty,"_valueIsDirty");
	HX_VISIT_MEMBER_NAME(_valueMode,"_valueMode");
	HX_VISIT_MEMBER_NAME(_value,"_value");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLInputElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"form") ) { return form; }
		if (HX_FIELD_EQ(inName,"name") ) { return inCallProp ? get_name() : name; }
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { return _value; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"removed") ) { return removed_dyn(); }
		if (HX_FIELD_EQ(inName,"checked") ) { return inCallProp ? get_checked() : checked; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"appended") ) { return appended_dyn(); }
		if (HX_FIELD_EQ(inName,"disabled") ) { return inCallProp ? get_disabled() : disabled; }
		if (HX_FIELD_EQ(inName,"readOnly") ) { return inCallProp ? get_readonly() : readOnly; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"isMutable") ) { return isMutable_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return inCallProp ? get_maxLength() : maxLength; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_valueMode") ) { return _valueMode; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_checked") ) { return set_checked_dyn(); }
		if (HX_FIELD_EQ(inName,"get_checked") ) { return get_checked_dyn(); }
		if (HX_FIELD_EQ(inName,"onUserInput") ) { return onUserInput_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"get_disabled") ) { return get_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_readonly") ) { return set_readonly_dyn(); }
		if (HX_FIELD_EQ(inName,"get_readonly") ) { return get_readonly_dyn(); }
		if (HX_FIELD_EQ(inName,"useValueMode") ) { return useValueMode_dyn(); }
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"_checkedness") ) { return _checkedness; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_maxLength") ) { return get_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		if (HX_FIELD_EQ(inName,"_valueIsDirty") ) { return _valueIsDirty; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"resetFormOwner") ) { return resetFormOwner_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"readonlyApplies") ) { return readonlyApplies_dyn(); }
		if (HX_FIELD_EQ(inName,"updateInputType") ) { return updateInputType_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onUserActivation") ) { return onUserActivation_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateCheckedness") ) { return updateCheckedness_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return isDefaultFocusable_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"_checkednessIsDirty") ) { return _checkednessIsDirty; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"associateFormElement") ) { return associateFormElement_dyn(); }
		if (HX_FIELD_EQ(inName,"getFirstFormAncestor") ) { return getFirstFormAncestor_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"dissociateFormElement") ) { return dissociateFormElement_dyn(); }
		if (HX_FIELD_EQ(inName,"runPreClickActivation") ) { return runPreClickActivation_dyn(); }
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateRadioButtonGroup") ) { return updateRadioButtonGroup_dyn(); }
		if (HX_FIELD_EQ(inName,"applyValueSanitization") ) { return applyValueSanitization_dyn(); }
		if (HX_FIELD_EQ(inName,"hasActivationBehaviour") ) { return hasActivationBehaviour_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getElementRendererValue") ) { return getElementRendererValue_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"updateInputRendererState") ) { return updateInputRendererState_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"useDefaultOrDefaultOnMode") ) { return useDefaultOrDefaultOnMode_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"runPostClickActivationStep") ) { return runPostClickActivationStep_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLInputElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"form") ) { form=inValue.Cast< ::cocktail::core::html::HTMLFormElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { if (inCallProp) return set_name(inValue);name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { _value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"checked") ) { if (inCallProp) return set_checked(inValue);checked=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"disabled") ) { if (inCallProp) return set_disabled(inValue);disabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"readOnly") ) { if (inCallProp) return set_readonly(inValue);readOnly=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_valueMode") ) { _valueMode=inValue.Cast< ::cocktail::core::html::ValueModeValue >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_checkedness") ) { _checkedness=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_valueIsDirty") ) { _valueIsDirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_checkednessIsDirty") ) { _checkednessIsDirty=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLInputElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("form"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("disabled"));
	outFields->push(HX_CSTRING("readOnly"));
	outFields->push(HX_CSTRING("checked"));
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("_checkednessIsDirty"));
	outFields->push(HX_CSTRING("_checkedness"));
	outFields->push(HX_CSTRING("_valueIsDirty"));
	outFields->push(HX_CSTRING("_valueMode"));
	outFields->push(HX_CSTRING("_value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_name"),
	HX_CSTRING("get_name"),
	HX_CSTRING("set_type"),
	HX_CSTRING("get_type"),
	HX_CSTRING("set_disabled"),
	HX_CSTRING("get_disabled"),
	HX_CSTRING("set_readonly"),
	HX_CSTRING("get_readonly"),
	HX_CSTRING("set_checked"),
	HX_CSTRING("get_checked"),
	HX_CSTRING("get_maxLength"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("onUserInput"),
	HX_CSTRING("onUserActivation"),
	HX_CSTRING("getElementRendererValue"),
	HX_CSTRING("dissociateFormElement"),
	HX_CSTRING("associateFormElement"),
	HX_CSTRING("getFirstFormAncestor"),
	HX_CSTRING("resetFormOwner"),
	HX_CSTRING("updateRadioButtonGroup"),
	HX_CSTRING("updateCheckedness"),
	HX_CSTRING("readonlyApplies"),
	HX_CSTRING("isMutable"),
	HX_CSTRING("applyValueSanitization"),
	HX_CSTRING("useDefaultOrDefaultOnMode"),
	HX_CSTRING("useValueMode"),
	HX_CSTRING("updateInputType"),
	HX_CSTRING("updateInputRendererState"),
	HX_CSTRING("runPostClickActivationStep"),
	HX_CSTRING("runPreClickActivation"),
	HX_CSTRING("hasActivationBehaviour"),
	HX_CSTRING("removed"),
	HX_CSTRING("appended"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("reset"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("form"),
	HX_CSTRING("name"),
	HX_CSTRING("type"),
	HX_CSTRING("disabled"),
	HX_CSTRING("readOnly"),
	HX_CSTRING("checked"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("value"),
	HX_CSTRING("_checkednessIsDirty"),
	HX_CSTRING("_checkedness"),
	HX_CSTRING("_valueIsDirty"),
	HX_CSTRING("_valueMode"),
	HX_CSTRING("_value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLInputElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLInputElement_obj::__mClass,"__mClass");
};

Class HTMLInputElement_obj::__mClass;

void HTMLInputElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLInputElement"), hx::TCanCast< HTMLInputElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLInputElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
