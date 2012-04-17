#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
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
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_hxtml_HxtmlConverter
#include <cocktail/core/hxtml/HxtmlConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_keyboard_AbstractKeyboard
#include <cocktail/core/keyboard/AbstractKeyboard.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_AbstractMouse
#include <cocktail/core/mouse/AbstractMouse.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ContainerCoreStyle
#include <cocktail/core/style/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_adapter_AbstractStyle
#include <cocktail/core/style/adapter/AbstractStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Keyboard
#include <cocktail/port/flash_player/Keyboard.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Mouse
#include <cocktail/port/flash_player/Mouse.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void AbstractHTMLElement_obj::__construct(::String tagName)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",295)
	super::__construct(tagName);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",296)
	this->init();
}
;
	return null();
}

AbstractHTMLElement_obj::~AbstractHTMLElement_obj() { }

Dynamic AbstractHTMLElement_obj::__CreateEmpty() { return  new AbstractHTMLElement_obj; }
hx::ObjectPtr< AbstractHTMLElement_obj > AbstractHTMLElement_obj::__new(::String tagName)
{  hx::ObjectPtr< AbstractHTMLElement_obj > result = new AbstractHTMLElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic AbstractHTMLElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractHTMLElement_obj > result = new AbstractHTMLElement_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *AbstractHTMLElement_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::event::IEventTarget_obj)) return operator ::cocktail::core::event::IEventTarget_obj *();
	return super::__ToInterface(inType);
}

Void AbstractHTMLElement_obj::init( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::init")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",305)
		this->initNativeElement();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",308)
		this->initMouse();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",311)
		this->initKeyboard();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",314)
		this->initCoreStyle();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",317)
		this->initStyle();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",320)
		this->initId();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,init,(void))

Void AbstractHTMLElement_obj::initNativeElement( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initNativeElement")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",327)
		this->_nativeElement = ::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::semantic(this->_tagName));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initNativeElement,(void))

Void AbstractHTMLElement_obj::initMouse( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initMouse")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",336)
		this->_mouse = ::cocktail::port::flash_player::Mouse_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initMouse,(void))

Void AbstractHTMLElement_obj::initKeyboard( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initKeyboard")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",346)
		this->_keyboard = ::cocktail::port::flash_player::Keyboard_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initKeyboard,(void))

Void AbstractHTMLElement_obj::initCoreStyle( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initCoreStyle")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",356)
		this->_coreStyle = ::cocktail::core::style::ContainerCoreStyle_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initCoreStyle,(void))

Void AbstractHTMLElement_obj::initStyle( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initStyle")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",365)
		this->_style = ::cocktail::core::style::adapter::AbstractStyle_obj::__new(this->_coreStyle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initStyle,(void))

Void AbstractHTMLElement_obj::initId( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::initId")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",376)
		::cocktail::core::dom::Attr id = ::cocktail::core::dom::Attr_obj::__new(HX_CSTRING("id"));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",377)
		this->setIdAttributeNode(id,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,initId,(void))

::cocktail::core::dom::Node AbstractHTMLElement_obj::appendChild( ::cocktail::core::dom::Node newChild){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::appendChild")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",389)
	this->super::appendChild(newChild);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",390)
	this->_coreStyle->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",391)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,appendChild,return )

::cocktail::core::dom::Node AbstractHTMLElement_obj::removeChild( ::cocktail::core::dom::Node oldChild){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::removeChild")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",399)
	this->super::removeChild(oldChild);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",400)
	this->_coreStyle->invalidate(null());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",401)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,removeChild,return )

Dynamic AbstractHTMLElement_obj::set_onClick( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onClick")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",411)
	this->_onClick = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",413)
	if (((this->_onClick_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",414)
		this->_mouse->set_onClick(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",418)
		this->_mouse->set_onClick(this->onClickCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",422)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onClick,return )

Dynamic AbstractHTMLElement_obj::get_onClick( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onClick")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",426)
	return this->_onClick_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onClick,return )

Dynamic AbstractHTMLElement_obj::set_onMouseDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onMouseDown")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",432)
	this->_onMouseDown = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",434)
	if (((this->_onMouseDown_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",435)
		this->_mouse->setOnMouseDown(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",439)
		this->_mouse->setOnMouseDown(this->onMouseDownCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",443)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onMouseDown,return )

Dynamic AbstractHTMLElement_obj::get_onMouseDown( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onMouseDown")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",447)
	return this->_onMouseDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onMouseDown,return )

Dynamic AbstractHTMLElement_obj::set_onMouseUp( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onMouseUp")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",453)
	this->_onMouseUp = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",455)
	if (((this->_onMouseUp_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",456)
		this->_mouse->setOnMouseUp(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",460)
		this->_mouse->setOnMouseUp(this->onMouseUpCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",464)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onMouseUp,return )

Dynamic AbstractHTMLElement_obj::get_onMouseUp( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onMouseUp")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",468)
	return this->_onMouseUp_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onMouseUp,return )

Dynamic AbstractHTMLElement_obj::set_onMouseOver( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onMouseOver")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",474)
	this->_onMouseOver = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",476)
	if (((this->_onMouseOver_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",477)
		this->_mouse->setOnMouseOver(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",481)
		this->_mouse->setOnMouseOver(this->onMouseOverCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",485)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onMouseOver,return )

Dynamic AbstractHTMLElement_obj::get_onMouseOver( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onMouseOver")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",489)
	return this->_onMouseOver_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onMouseOver,return )

Dynamic AbstractHTMLElement_obj::set_onMouseOut( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onMouseOut")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",495)
	this->_onMouseOut = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",497)
	if (((this->_onMouseOut_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",498)
		this->_mouse->setOnMouseOut(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",502)
		this->_mouse->setOnMouseOut(this->onMouseOutCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",506)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onMouseOut,return )

Dynamic AbstractHTMLElement_obj::get_onMouseOut( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onMouseOut")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",510)
	return this->_onMouseOut_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onMouseOut,return )

Dynamic AbstractHTMLElement_obj::set_onMouseMove( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onMouseMove")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",516)
	this->_onMouseMove = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",518)
	if (((this->_onMouseMove_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",519)
		this->_mouse->setOnMouseMove(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",523)
		this->_mouse->setOnMouseMove(this->onMouseMoveCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",527)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onMouseMove,return )

Dynamic AbstractHTMLElement_obj::get_onMouseMove( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onMouseMove")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",531)
	return this->_onMouseMove_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onMouseMove,return )

Void AbstractHTMLElement_obj::onClickCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onClickCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",542)
		this->_onClick(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onClickCallback,(void))

Void AbstractHTMLElement_obj::onMouseDownCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onMouseDownCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",547)
		this->_onMouseDown(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onMouseDownCallback,(void))

Void AbstractHTMLElement_obj::onMouseUpCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onMouseUpCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",552)
		this->_onMouseUp(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onMouseUpCallback,(void))

Void AbstractHTMLElement_obj::onMouseMoveCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onMouseMoveCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",557)
		this->_onMouseMove(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onMouseMoveCallback,(void))

Void AbstractHTMLElement_obj::onMouseOverCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onMouseOverCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",562)
		this->_onMouseOver(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onMouseOverCallback,(void))

Void AbstractHTMLElement_obj::onMouseOutCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onMouseOutCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",567)
		this->_onMouseOut(mouseEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onMouseOutCallback,(void))

Dynamic AbstractHTMLElement_obj::set_onKeyDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onKeyDown")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",578)
	this->_onKeyDown = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",580)
	if (((this->_onKeyDown_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",581)
		this->_keyboard->setOnKeyDown(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",585)
		this->_keyboard->setOnKeyDown(this->onKeyDownCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",589)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onKeyDown,return )

Dynamic AbstractHTMLElement_obj::get_onKeyDown( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onKeyDown")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",593)
	return this->_keyboard->getOnKeyDown();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onKeyDown,return )

Dynamic AbstractHTMLElement_obj::set_onKeyUp( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onKeyUp")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",599)
	this->_onKeyUp = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",601)
	if (((this->_onKeyUp_dyn() == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",602)
		this->_keyboard->setOnKeyUp(null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",606)
		this->_keyboard->setOnKeyUp(this->onKeyUpCallback_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",610)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onKeyUp,return )

Dynamic AbstractHTMLElement_obj::get_onKeyUp( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onKeyUp")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",614)
	return this->_keyboard->getOnKeyUp();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onKeyUp,return )

Void AbstractHTMLElement_obj::onKeyDownCallback( ::cocktail::core::event::KeyboardEvent keyEventData){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onKeyDownCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",625)
		this->_onKeyDown(keyEventData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onKeyDownCallback,(void))

Void AbstractHTMLElement_obj::onKeyUpCallback( ::cocktail::core::event::KeyboardEvent keyEventData){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onKeyUpCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",630)
		this->_onKeyUp(keyEventData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onKeyUpCallback,(void))

Void AbstractHTMLElement_obj::focus( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::focus")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,focus,(void))

Void AbstractHTMLElement_obj::blur( ){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::blur")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,blur,(void))

bool AbstractHTMLElement_obj::get_isDefaultFocusable( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_isDefaultFocusable")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",670)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_isDefaultFocusable,return )

Dynamic AbstractHTMLElement_obj::set_onFocus( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onFocus")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",675)
	return this->_onFocus = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onFocus,return )

Dynamic AbstractHTMLElement_obj::get_onFocus( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onFocus")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",680)
	return this->_onFocus_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onFocus,return )

Dynamic AbstractHTMLElement_obj::set_onBlur( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onBlur")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",685)
	return this->_onBlur = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onBlur,return )

Dynamic AbstractHTMLElement_obj::get_onBlur( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onBlur")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",690)
	return this->_onBlur_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onBlur,return )

Dynamic AbstractHTMLElement_obj::set_tabIndex( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_tabIndex")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",700)
	return this->_tabIndex = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_tabIndex,return )

Dynamic AbstractHTMLElement_obj::get_tabIndex( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_tabIndex")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",706)
	return this->_tabIndex;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_tabIndex,return )

Dynamic AbstractHTMLElement_obj::set_onScroll( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_onScroll")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",715)
	return this->_onScroll = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_onScroll,return )

Dynamic AbstractHTMLElement_obj::get_onScroll( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_onScroll")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",720)
	return this->_onScroll_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_onScroll,return )

Void AbstractHTMLElement_obj::onScrollCallback( ::cocktail::core::event::Event event){
{
		HX_SOURCE_PUSH("AbstractHTMLElement_obj::onScrollCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",730)
		if (((this->_onScroll_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",732)
			this->_onScroll(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,onScrollCallback,(void))

int AbstractHTMLElement_obj::get_scrollHeight( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_scrollHeight")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",739)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_scrollHeight,return )

int AbstractHTMLElement_obj::get_scrollWidth( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_scrollWidth")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",744)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_scrollWidth,return )

int AbstractHTMLElement_obj::set_scrollLeft( int value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_scrollLeft")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",749)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_scrollLeft,return )

int AbstractHTMLElement_obj::get_scrollLeft( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_scrollLeft")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",754)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_scrollLeft,return )

int AbstractHTMLElement_obj::set_scrollTop( int value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_scrollTop")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",759)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_scrollTop,return )

int AbstractHTMLElement_obj::get_scrollTop( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_scrollTop")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",764)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_scrollTop,return )

Dynamic AbstractHTMLElement_obj::get_nativeElement( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_nativeElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",777)
	return this->_nativeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_nativeElement,return )

::String AbstractHTMLElement_obj::get_id( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_id")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",788)
	return this->getAttribute(HX_CSTRING("id"));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_id,return )

::String AbstractHTMLElement_obj::set_id( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_id")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",797)
	this->setAttribute(HX_CSTRING("id"),value);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",798)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_id,return )

::String AbstractHTMLElement_obj::set_innerHTML( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::set_innerHTML")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",810)
	{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",810)
		int _g1 = (int)0;
		int _g = this->_childNodes->length;
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",810)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",810)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",812)
			this->removeChild(this->_childNodes->__get(i));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",814)
	this->appendChild(::cocktail::core::hxtml::HxtmlConverter_obj::getNode(value));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",815)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLElement_obj,set_innerHTML,return )

::String AbstractHTMLElement_obj::get_innerHTML( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_innerHTML")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",825)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_innerHTML,return )

::cocktail::port::flash_player::HTMLElement AbstractHTMLElement_obj::get_offsetParent( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_offsetParent")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",841)
	return this->_coreStyle->getFirstPositionedAncestor();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_offsetParent,return )

int AbstractHTMLElement_obj::get_offsetWidth( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_offsetWidth")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",849)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",850)
	Dynamic computedStyle = this->_coreStyle->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",851)
	return ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_offsetWidth,return )

int AbstractHTMLElement_obj::get_offsetHeight( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_offsetHeight")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",856)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",857)
	Dynamic computedStyle = this->_coreStyle->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",858)
	return ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_offsetHeight,return )

int AbstractHTMLElement_obj::get_offsetLeft( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_offsetLeft")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",864)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",866)
	::cocktail::port::flash_player::HTMLElement firstPositionedAncestor = this->get_offsetParent();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",868)
	int offsetLeft = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",870)
	if (((firstPositionedAncestor != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",872)
		::cocktail::port::flash_player::HTMLElement parent = this->get_parentNode();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",873)
		offsetLeft = (parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")) + parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginLeft")));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",875)
		while(((parent != firstPositionedAncestor))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",877)
			hx::AddEq(offsetLeft,(parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")) + parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginLeft"))));
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",878)
			parent = parent->get_parentNode();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",882)
	return offsetLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_offsetLeft,return )

int AbstractHTMLElement_obj::get_offsetTop( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_offsetTop")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",887)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",889)
	::cocktail::port::flash_player::HTMLElement firstPositionedAncestor = this->get_offsetParent();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",891)
	int offsetTop = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",893)
	if (((firstPositionedAncestor != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",895)
		::cocktail::port::flash_player::HTMLElement parent = this->get_parentNode();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",896)
		offsetTop = (parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")) + parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop")));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",898)
		while(((parent != firstPositionedAncestor))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",900)
			hx::AddEq(offsetTop,(parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")) + parent->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"))));
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",901)
			parent = parent->get_parentNode();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",905)
	return offsetTop;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_offsetTop,return )

int AbstractHTMLElement_obj::get_clientWidth( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_clientWidth")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",912)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",913)
	Dynamic computedStyle = this->_coreStyle->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",914)
	return ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_clientWidth,return )

int AbstractHTMLElement_obj::get_clientHeight( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_clientHeight")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",919)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",920)
	Dynamic computedStyle = this->_coreStyle->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",921)
	return ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_clientHeight,return )

int AbstractHTMLElement_obj::get_clientTop( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_clientTop")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",927)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",928)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_clientTop,return )

int AbstractHTMLElement_obj::get_clientLeft( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_clientLeft")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",934)
	this->_coreStyle->invalidate(true);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",935)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_clientLeft,return )

::cocktail::core::style::CoreStyle AbstractHTMLElement_obj::get_coreStyle( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_coreStyle")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",943)
	return this->_coreStyle;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_coreStyle,return )

::cocktail::core::style::adapter::AbstractStyle AbstractHTMLElement_obj::get_style( ){
	HX_SOURCE_PUSH("AbstractHTMLElement_obj::get_style")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLElement.hx",948)
	return this->_style;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLElement_obj,get_style,return )

::String AbstractHTMLElement_obj::HTML_ID_ATTRIBUTE;


AbstractHTMLElement_obj::AbstractHTMLElement_obj()
{
}

void AbstractHTMLElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractHTMLElement);
	HX_MARK_MEMBER_NAME(_mouse,"_mouse");
	HX_MARK_MEMBER_NAME(_onClick,"_onClick");
	HX_MARK_MEMBER_NAME(onclick,"onclick");
	HX_MARK_MEMBER_NAME(_onMouseDown,"_onMouseDown");
	HX_MARK_MEMBER_NAME(onmousedown,"onmousedown");
	HX_MARK_MEMBER_NAME(_onMouseUp,"_onMouseUp");
	HX_MARK_MEMBER_NAME(onmouseup,"onmouseup");
	HX_MARK_MEMBER_NAME(_onMouseOver,"_onMouseOver");
	HX_MARK_MEMBER_NAME(onmouseover,"onmouseover");
	HX_MARK_MEMBER_NAME(_onMouseOut,"_onMouseOut");
	HX_MARK_MEMBER_NAME(onmouseout,"onmouseout");
	HX_MARK_MEMBER_NAME(_onMouseMove,"_onMouseMove");
	HX_MARK_MEMBER_NAME(onmousemove,"onmousemove");
	HX_MARK_MEMBER_NAME(_keyboard,"_keyboard");
	HX_MARK_MEMBER_NAME(_onKeyDown,"_onKeyDown");
	HX_MARK_MEMBER_NAME(onkeydown,"onkeydown");
	HX_MARK_MEMBER_NAME(_onKeyUp,"_onKeyUp");
	HX_MARK_MEMBER_NAME(onkeyup,"onkeyup");
	HX_MARK_MEMBER_NAME(_tabIndex,"_tabIndex");
	HX_MARK_MEMBER_NAME(tabIndex,"tabIndex");
	HX_MARK_MEMBER_NAME(isDefaultFocusable,"isDefaultFocusable");
	HX_MARK_MEMBER_NAME(_onFocus,"_onFocus");
	HX_MARK_MEMBER_NAME(onfocus,"onfocus");
	HX_MARK_MEMBER_NAME(_onBlur,"_onBlur");
	HX_MARK_MEMBER_NAME(onblur,"onblur");
	HX_MARK_MEMBER_NAME(_onScroll,"_onScroll");
	HX_MARK_MEMBER_NAME(onscroll,"onscroll");
	HX_MARK_MEMBER_NAME(scrollTop,"scrollTop");
	HX_MARK_MEMBER_NAME(scrollLeft,"scrollLeft");
	HX_MARK_MEMBER_NAME(scrollHeight,"scrollHeight");
	HX_MARK_MEMBER_NAME(scrollWidth,"scrollWidth");
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	HX_MARK_MEMBER_NAME(nativeElement,"nativeElement");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(innerHTML,"innerHTML");
	HX_MARK_MEMBER_NAME(offsetParent,"offsetParent");
	HX_MARK_MEMBER_NAME(offsetWidth,"offsetWidth");
	HX_MARK_MEMBER_NAME(offsetHeight,"offsetHeight");
	HX_MARK_MEMBER_NAME(offsetLeft,"offsetLeft");
	HX_MARK_MEMBER_NAME(offsetTop,"offsetTop");
	HX_MARK_MEMBER_NAME(clientWidth,"clientWidth");
	HX_MARK_MEMBER_NAME(clientHeight,"clientHeight");
	HX_MARK_MEMBER_NAME(clientLeft,"clientLeft");
	HX_MARK_MEMBER_NAME(clientTop,"clientTop");
	HX_MARK_MEMBER_NAME(_coreStyle,"_coreStyle");
	HX_MARK_MEMBER_NAME(coreStyle,"coreStyle");
	HX_MARK_MEMBER_NAME(_style,"_style");
	HX_MARK_MEMBER_NAME(style,"style");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractHTMLElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return get_id(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		if (HX_FIELD_EQ(inName,"blur") ) { return blur_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { return get_style(); }
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_mouse") ) { return _mouse; }
		if (HX_FIELD_EQ(inName,"onblur") ) { return get_onBlur(); }
		if (HX_FIELD_EQ(inName,"_style") ) { return _style; }
		if (HX_FIELD_EQ(inName,"initId") ) { return initId_dyn(); }
		if (HX_FIELD_EQ(inName,"get_id") ) { return get_id_dyn(); }
		if (HX_FIELD_EQ(inName,"set_id") ) { return set_id_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onclick") ) { return get_onClick(); }
		if (HX_FIELD_EQ(inName,"onkeyup") ) { return get_onKeyUp(); }
		if (HX_FIELD_EQ(inName,"onfocus") ) { return get_onFocus(); }
		if (HX_FIELD_EQ(inName,"_onBlur") ) { return _onBlur; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onClick") ) { return _onClick; }
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { return _onKeyUp; }
		if (HX_FIELD_EQ(inName,"tabIndex") ) { return get_tabIndex(); }
		if (HX_FIELD_EQ(inName,"_onFocus") ) { return _onFocus; }
		if (HX_FIELD_EQ(inName,"onscroll") ) { return get_onScroll(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onmouseup") ) { return get_onMouseUp(); }
		if (HX_FIELD_EQ(inName,"_keyboard") ) { return _keyboard; }
		if (HX_FIELD_EQ(inName,"onkeydown") ) { return get_onKeyDown(); }
		if (HX_FIELD_EQ(inName,"_tabIndex") ) { return _tabIndex; }
		if (HX_FIELD_EQ(inName,"_onScroll") ) { return _onScroll; }
		if (HX_FIELD_EQ(inName,"scrollTop") ) { return get_scrollTop(); }
		if (HX_FIELD_EQ(inName,"innerHTML") ) { return get_innerHTML(); }
		if (HX_FIELD_EQ(inName,"offsetTop") ) { return get_offsetTop(); }
		if (HX_FIELD_EQ(inName,"clientTop") ) { return get_clientTop(); }
		if (HX_FIELD_EQ(inName,"coreStyle") ) { return get_coreStyle(); }
		if (HX_FIELD_EQ(inName,"initMouse") ) { return initMouse_dyn(); }
		if (HX_FIELD_EQ(inName,"initStyle") ) { return initStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_style") ) { return get_style_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { return _onMouseUp; }
		if (HX_FIELD_EQ(inName,"onmouseout") ) { return get_onMouseOut(); }
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { return _onKeyDown; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { return get_scrollLeft(); }
		if (HX_FIELD_EQ(inName,"offsetLeft") ) { return get_offsetLeft(); }
		if (HX_FIELD_EQ(inName,"clientLeft") ) { return get_clientLeft(); }
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { return _coreStyle; }
		if (HX_FIELD_EQ(inName,"set_onBlur") ) { return set_onBlur_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onBlur") ) { return get_onBlur_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onmousedown") ) { return get_onMouseDown(); }
		if (HX_FIELD_EQ(inName,"onmouseover") ) { return get_onMouseOver(); }
		if (HX_FIELD_EQ(inName,"_onMouseOut") ) { return _onMouseOut; }
		if (HX_FIELD_EQ(inName,"onmousemove") ) { return get_onMouseMove(); }
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { return get_scrollWidth(); }
		if (HX_FIELD_EQ(inName,"offsetWidth") ) { return get_offsetWidth(); }
		if (HX_FIELD_EQ(inName,"clientWidth") ) { return get_clientWidth(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onClick") ) { return set_onClick_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onClick") ) { return get_onClick_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onKeyUp") ) { return set_onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onKeyUp") ) { return get_onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onFocus") ) { return set_onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onFocus") ) { return get_onFocus_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { return _onMouseDown; }
		if (HX_FIELD_EQ(inName,"_onMouseOver") ) { return _onMouseOver; }
		if (HX_FIELD_EQ(inName,"_onMouseMove") ) { return _onMouseMove; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { return get_scrollHeight(); }
		if (HX_FIELD_EQ(inName,"offsetParent") ) { return get_offsetParent(); }
		if (HX_FIELD_EQ(inName,"offsetHeight") ) { return get_offsetHeight(); }
		if (HX_FIELD_EQ(inName,"clientHeight") ) { return get_clientHeight(); }
		if (HX_FIELD_EQ(inName,"initKeyboard") ) { return initKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"set_tabIndex") ) { return set_tabIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_tabIndex") ) { return get_tabIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onScroll") ) { return set_onScroll_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onScroll") ) { return get_onScroll_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { return get_nativeElement(); }
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseUp") ) { return set_onMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onMouseUp") ) { return get_onMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onKeyDown") ) { return set_onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onKeyDown") ) { return get_onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollTop") ) { return set_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollTop") ) { return get_scrollTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_innerHTML") ) { return set_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"get_innerHTML") ) { return get_innerHTML_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetTop") ) { return get_offsetTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientTop") ) { return get_clientTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_coreStyle") ) { return get_coreStyle_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
		if (HX_FIELD_EQ(inName,"set_onMouseOut") ) { return set_onMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onMouseOut") ) { return get_onMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollLeft") ) { return set_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollLeft") ) { return get_scrollLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetLeft") ) { return get_offsetLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientLeft") ) { return get_clientLeft_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_onMouseDown") ) { return set_onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onMouseDown") ) { return get_onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseOver") ) { return set_onMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onMouseOver") ) { return get_onMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseMove") ) { return set_onMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onMouseMove") ) { return get_onMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"onClickCallback") ) { return onClickCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyUpCallback") ) { return onKeyUpCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollWidth") ) { return get_scrollWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetWidth") ) { return get_offsetWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientWidth") ) { return get_clientWidth_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onScrollCallback") ) { return onScrollCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollHeight") ) { return get_scrollHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetParent") ) { return get_offsetParent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_offsetHeight") ) { return get_offsetHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientHeight") ) { return get_clientHeight_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"HTML_ID_ATTRIBUTE") ) { return HTML_ID_ATTRIBUTE; }
		if (HX_FIELD_EQ(inName,"initNativeElement") ) { return initNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseUpCallback") ) { return onMouseUpCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyDownCallback") ) { return onKeyDownCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nativeElement") ) { return get_nativeElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return get_isDefaultFocusable(); }
		if (HX_FIELD_EQ(inName,"onMouseOutCallback") ) { return onMouseOutCallback_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onMouseDownCallback") ) { return onMouseDownCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseMoveCallback") ) { return onMouseMoveCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseOverCallback") ) { return onMouseOverCallback_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"get_isDefaultFocusable") ) { return get_isDefaultFocusable_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractHTMLElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return set_id(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< ::cocktail::core::style::adapter::AbstractStyle >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_mouse") ) { _mouse=inValue.Cast< ::cocktail::port::flash_player::Mouse >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onblur") ) { return set_onBlur(inValue); }
		if (HX_FIELD_EQ(inName,"_style") ) { _style=inValue.Cast< ::cocktail::core::style::adapter::AbstractStyle >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onclick") ) { return set_onClick(inValue); }
		if (HX_FIELD_EQ(inName,"onkeyup") ) { return set_onKeyUp(inValue); }
		if (HX_FIELD_EQ(inName,"onfocus") ) { return set_onFocus(inValue); }
		if (HX_FIELD_EQ(inName,"_onBlur") ) { _onBlur=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onClick") ) { _onClick=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { _onKeyUp=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tabIndex") ) { return set_tabIndex(inValue); }
		if (HX_FIELD_EQ(inName,"_onFocus") ) { _onFocus=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onscroll") ) { return set_onScroll(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onmouseup") ) { return set_onMouseUp(inValue); }
		if (HX_FIELD_EQ(inName,"_keyboard") ) { _keyboard=inValue.Cast< ::cocktail::port::flash_player::Keyboard >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onkeydown") ) { return set_onKeyDown(inValue); }
		if (HX_FIELD_EQ(inName,"_tabIndex") ) { _tabIndex=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onScroll") ) { _onScroll=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollTop") ) { return set_scrollTop(inValue); }
		if (HX_FIELD_EQ(inName,"innerHTML") ) { return set_innerHTML(inValue); }
		if (HX_FIELD_EQ(inName,"offsetTop") ) { offsetTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientTop") ) { clientTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coreStyle") ) { coreStyle=inValue.Cast< ::cocktail::core::style::CoreStyle >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { _onMouseUp=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmouseout") ) { return set_onMouseOut(inValue); }
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { _onKeyDown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollLeft") ) { return set_scrollLeft(inValue); }
		if (HX_FIELD_EQ(inName,"offsetLeft") ) { offsetLeft=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientLeft") ) { clientLeft=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { _coreStyle=inValue.Cast< ::cocktail::core::style::CoreStyle >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onmousedown") ) { return set_onMouseDown(inValue); }
		if (HX_FIELD_EQ(inName,"onmouseover") ) { return set_onMouseOver(inValue); }
		if (HX_FIELD_EQ(inName,"_onMouseOut") ) { _onMouseOut=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onmousemove") ) { return set_onMouseMove(inValue); }
		if (HX_FIELD_EQ(inName,"scrollWidth") ) { scrollWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetWidth") ) { offsetWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientWidth") ) { clientWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { _onMouseDown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onMouseOver") ) { _onMouseOver=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onMouseMove") ) { _onMouseMove=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollHeight") ) { scrollHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetParent") ) { offsetParent=inValue.Cast< ::cocktail::port::flash_player::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetHeight") ) { offsetHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientHeight") ) { clientHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nativeElement") ) { nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"HTML_ID_ATTRIBUTE") ) { HTML_ID_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { isDefaultFocusable=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractHTMLElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_mouse"));
	outFields->push(HX_CSTRING("_keyboard"));
	outFields->push(HX_CSTRING("_tabIndex"));
	outFields->push(HX_CSTRING("tabIndex"));
	outFields->push(HX_CSTRING("isDefaultFocusable"));
	outFields->push(HX_CSTRING("scrollTop"));
	outFields->push(HX_CSTRING("scrollLeft"));
	outFields->push(HX_CSTRING("scrollHeight"));
	outFields->push(HX_CSTRING("scrollWidth"));
	outFields->push(HX_CSTRING("_nativeElement"));
	outFields->push(HX_CSTRING("nativeElement"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("innerHTML"));
	outFields->push(HX_CSTRING("offsetParent"));
	outFields->push(HX_CSTRING("offsetWidth"));
	outFields->push(HX_CSTRING("offsetHeight"));
	outFields->push(HX_CSTRING("offsetLeft"));
	outFields->push(HX_CSTRING("offsetTop"));
	outFields->push(HX_CSTRING("clientWidth"));
	outFields->push(HX_CSTRING("clientHeight"));
	outFields->push(HX_CSTRING("clientLeft"));
	outFields->push(HX_CSTRING("clientTop"));
	outFields->push(HX_CSTRING("_coreStyle"));
	outFields->push(HX_CSTRING("coreStyle"));
	outFields->push(HX_CSTRING("_style"));
	outFields->push(HX_CSTRING("style"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_ID_ATTRIBUTE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_mouse"),
	HX_CSTRING("_onClick"),
	HX_CSTRING("onclick"),
	HX_CSTRING("_onMouseDown"),
	HX_CSTRING("onmousedown"),
	HX_CSTRING("_onMouseUp"),
	HX_CSTRING("onmouseup"),
	HX_CSTRING("_onMouseOver"),
	HX_CSTRING("onmouseover"),
	HX_CSTRING("_onMouseOut"),
	HX_CSTRING("onmouseout"),
	HX_CSTRING("_onMouseMove"),
	HX_CSTRING("onmousemove"),
	HX_CSTRING("_keyboard"),
	HX_CSTRING("_onKeyDown"),
	HX_CSTRING("onkeydown"),
	HX_CSTRING("_onKeyUp"),
	HX_CSTRING("onkeyup"),
	HX_CSTRING("_tabIndex"),
	HX_CSTRING("tabIndex"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("_onFocus"),
	HX_CSTRING("onfocus"),
	HX_CSTRING("_onBlur"),
	HX_CSTRING("onblur"),
	HX_CSTRING("_onScroll"),
	HX_CSTRING("onscroll"),
	HX_CSTRING("scrollTop"),
	HX_CSTRING("scrollLeft"),
	HX_CSTRING("scrollHeight"),
	HX_CSTRING("scrollWidth"),
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("nativeElement"),
	HX_CSTRING("id"),
	HX_CSTRING("innerHTML"),
	HX_CSTRING("offsetParent"),
	HX_CSTRING("offsetWidth"),
	HX_CSTRING("offsetHeight"),
	HX_CSTRING("offsetLeft"),
	HX_CSTRING("offsetTop"),
	HX_CSTRING("clientWidth"),
	HX_CSTRING("clientHeight"),
	HX_CSTRING("clientLeft"),
	HX_CSTRING("clientTop"),
	HX_CSTRING("_coreStyle"),
	HX_CSTRING("coreStyle"),
	HX_CSTRING("_style"),
	HX_CSTRING("style"),
	HX_CSTRING("init"),
	HX_CSTRING("initNativeElement"),
	HX_CSTRING("initMouse"),
	HX_CSTRING("initKeyboard"),
	HX_CSTRING("initCoreStyle"),
	HX_CSTRING("initStyle"),
	HX_CSTRING("initId"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("set_onClick"),
	HX_CSTRING("get_onClick"),
	HX_CSTRING("set_onMouseDown"),
	HX_CSTRING("get_onMouseDown"),
	HX_CSTRING("set_onMouseUp"),
	HX_CSTRING("get_onMouseUp"),
	HX_CSTRING("set_onMouseOver"),
	HX_CSTRING("get_onMouseOver"),
	HX_CSTRING("set_onMouseOut"),
	HX_CSTRING("get_onMouseOut"),
	HX_CSTRING("set_onMouseMove"),
	HX_CSTRING("get_onMouseMove"),
	HX_CSTRING("onClickCallback"),
	HX_CSTRING("onMouseDownCallback"),
	HX_CSTRING("onMouseUpCallback"),
	HX_CSTRING("onMouseMoveCallback"),
	HX_CSTRING("onMouseOverCallback"),
	HX_CSTRING("onMouseOutCallback"),
	HX_CSTRING("set_onKeyDown"),
	HX_CSTRING("get_onKeyDown"),
	HX_CSTRING("set_onKeyUp"),
	HX_CSTRING("get_onKeyUp"),
	HX_CSTRING("onKeyDownCallback"),
	HX_CSTRING("onKeyUpCallback"),
	HX_CSTRING("focus"),
	HX_CSTRING("blur"),
	HX_CSTRING("get_isDefaultFocusable"),
	HX_CSTRING("set_onFocus"),
	HX_CSTRING("get_onFocus"),
	HX_CSTRING("set_onBlur"),
	HX_CSTRING("get_onBlur"),
	HX_CSTRING("set_tabIndex"),
	HX_CSTRING("get_tabIndex"),
	HX_CSTRING("set_onScroll"),
	HX_CSTRING("get_onScroll"),
	HX_CSTRING("onScrollCallback"),
	HX_CSTRING("get_scrollHeight"),
	HX_CSTRING("get_scrollWidth"),
	HX_CSTRING("set_scrollLeft"),
	HX_CSTRING("get_scrollLeft"),
	HX_CSTRING("set_scrollTop"),
	HX_CSTRING("get_scrollTop"),
	HX_CSTRING("get_nativeElement"),
	HX_CSTRING("get_id"),
	HX_CSTRING("set_id"),
	HX_CSTRING("set_innerHTML"),
	HX_CSTRING("get_innerHTML"),
	HX_CSTRING("get_offsetParent"),
	HX_CSTRING("get_offsetWidth"),
	HX_CSTRING("get_offsetHeight"),
	HX_CSTRING("get_offsetLeft"),
	HX_CSTRING("get_offsetTop"),
	HX_CSTRING("get_clientWidth"),
	HX_CSTRING("get_clientHeight"),
	HX_CSTRING("get_clientTop"),
	HX_CSTRING("get_clientLeft"),
	HX_CSTRING("get_coreStyle"),
	HX_CSTRING("get_style"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLElement_obj::HTML_ID_ATTRIBUTE,"HTML_ID_ATTRIBUTE");
};

Class AbstractHTMLElement_obj::__mClass;

void AbstractHTMLElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.AbstractHTMLElement"), hx::TCanCast< AbstractHTMLElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLElement_obj::__boot()
{
	hx::Static(HTML_ID_ATTRIBUTE) = HX_CSTRING("id");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
