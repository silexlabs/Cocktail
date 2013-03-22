#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_Graphics
#include <neash/display/Graphics.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_MovieClip
#include <neash/display/MovieClip.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_TextEvent
#include <neash/events/TextEvent.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
#ifndef INCLUDED_neash_text_TextFieldType
#include <neash/text/TextFieldType.h>
#endif
#ifndef INCLUDED_neash_text_TextFormat
#include <neash/text/TextFormat.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void NativeTextInput_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("NativeTextInput::new","cocktail/port/platform/flash_player/NativeTextInput.hx",65);
{
	HX_STACK_LINE(64)
	Array< ::cocktail::port::platform::flash_player::NativeTextInput > _g = Array_obj< ::cocktail::port::platform::flash_player::NativeTextInput >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(66)
	super::__construct(node);
	HX_STACK_LINE(68)
	this->_textField = ::neash::text::TextField_obj::__new();
	HX_STACK_LINE(70)
	this->_mask = ::neash::display::Sprite_obj::__new();
	HX_STACK_LINE(71)
	this->_textField->nmeSetMask(this->_mask);
	HX_STACK_LINE(79)
	this->_textField->nmeSetType(::neash::text::TextFieldType_obj::INPUT_dyn());

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::cocktail::port::platform::flash_player::NativeTextInput >,_g)
	Void run(Dynamic e){
		HX_STACK_PUSH("*::_Function_1_1","cocktail/port/platform/flash_player/NativeTextInput.hx",82);
		HX_STACK_ARG(e,"e");
		{
			HX_STACK_LINE(82)
			_g->__get((int)0)->onInput();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(82)
	this->_textField->addEventListener(::neash::events::TextEvent_obj::TEXT_INPUT, Dynamic(new _Function_1_1(_g)),null(),null(),null());
	HX_STACK_LINE(84)
	this->_textFormat = ::neash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(86)
	this->updateTextFormat();
}
;
	return null();
}

NativeTextInput_obj::~NativeTextInput_obj() { }

Dynamic NativeTextInput_obj::__CreateEmpty() { return  new NativeTextInput_obj; }
hx::ObjectPtr< NativeTextInput_obj > NativeTextInput_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< NativeTextInput_obj > result = new NativeTextInput_obj();
	result->__construct(node);
	return result;}

Dynamic NativeTextInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextInput_obj > result = new NativeTextInput_obj();
	result->__construct(inArgs[0]);
	return result;}

Float NativeTextInput_obj::get_letterSpacing( ){
	HX_STACK_PUSH("NativeTextInput::get_letterSpacing","cocktail/port/platform/flash_player/NativeTextInput.hx",295);
	HX_STACK_THIS(this);
	HX_STACK_LINE(295)
	return this->_textFormat->letterSpacing;
}


Float NativeTextInput_obj::set_letterSpacing( Float value){
	HX_STACK_PUSH("NativeTextInput::set_letterSpacing","cocktail/port/platform/flash_player/NativeTextInput.hx",287);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(288)
	this->_textFormat->letterSpacing = value;
	HX_STACK_LINE(289)
	this->updateTextFormat();
	HX_STACK_LINE(291)
	return value;
}


int NativeTextInput_obj::set_maxLength( int value){
	HX_STACK_PUSH("NativeTextInput::set_maxLength","cocktail/port/platform/flash_player/NativeTextInput.hx",276);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(279)
	if (((value == (int)-1))){
		HX_STACK_LINE(280)
		value = (int)0;
	}
	HX_STACK_LINE(283)
	return this->_textField->nmeSetMaxChars(value);
}


::String NativeTextInput_obj::set_value( ::String textValue){
	HX_STACK_PUSH("NativeTextInput::set_value","cocktail/port/platform/flash_player/NativeTextInput.hx",271);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textValue,"textValue");
	HX_STACK_LINE(271)
	return this->_textField->nmeSetText(textValue);
}


::String NativeTextInput_obj::get_value( ){
	HX_STACK_PUSH("NativeTextInput::get_value","cocktail/port/platform/flash_player/NativeTextInput.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_LINE(266)
	return this->_textField->nmeGetText();
}


::String NativeTextInput_obj::get_fontFamily( ){
	HX_STACK_PUSH("NativeTextInput::get_fontFamily","cocktail/port/platform/flash_player/NativeTextInput.hx",261);
	HX_STACK_THIS(this);
	HX_STACK_LINE(261)
	return this->_textFormat->font;
}


::String NativeTextInput_obj::set_fontFamily( ::String value){
	HX_STACK_PUSH("NativeTextInput::set_fontFamily","cocktail/port/platform/flash_player/NativeTextInput.hx",241);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(242)
	::String _switch_1 = (value);
	if (  ( _switch_1==HX_CSTRING("serif"))){
		HX_STACK_LINE(244)
		value = HX_CSTRING("_serif");
	}
	else if (  ( _switch_1==HX_CSTRING("sans"))){
		HX_STACK_LINE(247)
		value = HX_CSTRING("_sans");
	}
	else if (  ( _switch_1==HX_CSTRING("typewriter"))){
		HX_STACK_LINE(250)
		value = HX_CSTRING("_typewriter");
	}
	HX_STACK_LINE(254)
	this->_textFormat->font = value;
	HX_STACK_LINE(255)
	this->updateTextFormat();
	HX_STACK_LINE(257)
	return value;
}


int NativeTextInput_obj::get_color( ){
	HX_STACK_PUSH("NativeTextInput::get_color","cocktail/port/platform/flash_player/NativeTextInput.hx",232);
	HX_STACK_THIS(this);
	HX_STACK_LINE(232)
	return this->_textFormat->color;
}


int NativeTextInput_obj::set_color( int value){
	HX_STACK_PUSH("NativeTextInput::set_color","cocktail/port/platform/flash_player/NativeTextInput.hx",224);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(225)
	this->_textFormat->color = value;
	HX_STACK_LINE(226)
	this->updateTextFormat();
	HX_STACK_LINE(228)
	return value;
}


bool NativeTextInput_obj::set_bold( bool value){
	HX_STACK_PUSH("NativeTextInput::set_bold","cocktail/port/platform/flash_player/NativeTextInput.hx",216);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(217)
	this->_textFormat->bold = value;
	HX_STACK_LINE(218)
	this->updateTextFormat();
	HX_STACK_LINE(220)
	return value;
}


bool NativeTextInput_obj::get_bold( ){
	HX_STACK_PUSH("NativeTextInput::get_bold","cocktail/port/platform/flash_player/NativeTextInput.hx",211);
	HX_STACK_THIS(this);
	HX_STACK_LINE(211)
	return this->_textFormat->bold;
}


bool NativeTextInput_obj::get_italic( ){
	HX_STACK_PUSH("NativeTextInput::get_italic","cocktail/port/platform/flash_player/NativeTextInput.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_LINE(206)
	return this->_textFormat->italic;
}


bool NativeTextInput_obj::set_italic( bool value){
	HX_STACK_PUSH("NativeTextInput::set_italic","cocktail/port/platform/flash_player/NativeTextInput.hx",198);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(199)
	this->_textFormat->italic = value;
	HX_STACK_LINE(200)
	this->updateTextFormat();
	HX_STACK_LINE(202)
	return value;
}


Float NativeTextInput_obj::get_fontSize( ){
	HX_STACK_PUSH("NativeTextInput::get_fontSize","cocktail/port/platform/flash_player/NativeTextInput.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	return this->_textFormat->size;
}


Float NativeTextInput_obj::set_fontSize( Float value){
	HX_STACK_PUSH("NativeTextInput::set_fontSize","cocktail/port/platform/flash_player/NativeTextInput.hx",185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(186)
	this->_textFormat->size = value;
	HX_STACK_LINE(187)
	this->updateTextFormat();
	HX_STACK_LINE(189)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::set_clipRect( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInput::set_clipRect","cocktail/port/platform/flash_player/NativeTextInput.hx",176);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(177)
	this->_mask->nmeGetGraphics()->clear();
	HX_STACK_LINE(178)
	this->_mask->nmeGetGraphics()->beginFill((int)16711680,0.5);
	HX_STACK_LINE(179)
	this->_mask->nmeGetGraphics()->drawRect(value->x,value->y,value->width,value->height);
	HX_STACK_LINE(180)
	this->_mask->nmeGetGraphics()->endFill();
	HX_STACK_LINE(181)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::get_clipRect( ){
	HX_STACK_PUSH("NativeTextInput::get_clipRect","cocktail/port/platform/flash_player/NativeTextInput.hx",171);
	HX_STACK_THIS(this);
	HX_STACK_LINE(171)
	return this->clipRect;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::set_viewport( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInput::set_viewport","cocktail/port/platform/flash_player/NativeTextInput.hx",161);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(162)
	this->_textField->nmeSetX(value->x);
	HX_STACK_LINE(163)
	this->_textField->nmeSetY(value->y);
	HX_STACK_LINE(164)
	this->_textField->nmeSetWidth(value->width);
	HX_STACK_LINE(165)
	this->_textField->nmeSetHeight(value->height);
	HX_STACK_LINE(167)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::get_viewport( ){
	HX_STACK_PUSH("NativeTextInput::get_viewport","cocktail/port/platform/flash_player/NativeTextInput.hx",151);
	HX_STACK_THIS(this);
	HX_STACK_LINE(152)
	::cocktail::core::geom::RectangleVO rect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(153)
	rect->x = this->_textField->nmeGetX();
	HX_STACK_LINE(154)
	rect->y = this->_textField->nmeGetY();
	HX_STACK_LINE(155)
	rect->width = this->_textField->nmeGetWidth();
	HX_STACK_LINE(156)
	rect->height = this->_textField->nmeGetHeight();
	HX_STACK_LINE(157)
	return rect;
}


Void NativeTextInput_obj::updateTextFormat( ){
{
		HX_STACK_PUSH("NativeTextInput::updateTextFormat","cocktail/port/platform/flash_player/NativeTextInput.hx",140);
		HX_STACK_THIS(this);
		HX_STACK_LINE(141)
		this->_textField->nmeSetDefaultTextFormat(this->_textFormat);
		HX_STACK_LINE(142)
		this->_textField->setTextFormat(this->_textFormat,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInput_obj,updateTextFormat,(void))

Void NativeTextInput_obj::blur( ){
{
		HX_STACK_PUSH("NativeTextInput::blur","cocktail/port/platform/flash_player/NativeTextInput.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_LINE(126)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetFocus(null());
	}
return null();
}


Void NativeTextInput_obj::focus( ){
{
		HX_STACK_PUSH("NativeTextInput::focus","cocktail/port/platform/flash_player/NativeTextInput.hx",116);
		HX_STACK_THIS(this);
		HX_STACK_LINE(116)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetFocus(this->_textField);
	}
return null();
}


Void NativeTextInput_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInput::detach","cocktail/port/platform/flash_player/NativeTextInput.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_LINE(108)
		::neash::display::DisplayObjectContainer containerGraphicContext = graphicContext->get_nativeLayer();		HX_STACK_VAR(containerGraphicContext,"containerGraphicContext");
		HX_STACK_LINE(109)
		containerGraphicContext->removeChild(this->_textField);
	}
return null();
}


Void NativeTextInput_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInput::attach","cocktail/port/platform/flash_player/NativeTextInput.hx",97);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_LINE(98)
		::neash::display::DisplayObjectContainer containerGraphicContext = graphicContext->get_nativeLayer();		HX_STACK_VAR(containerGraphicContext,"containerGraphicContext");
		HX_STACK_LINE(100)
		containerGraphicContext->addChild(this->_textField);
	}
return null();
}


::String NativeTextInput_obj::SERIF_GENERIC_FONT_NAME;

::String NativeTextInput_obj::SERIF_FLASH_FONT_NAME;

::String NativeTextInput_obj::SANS_SERIF_GENERIC_FONT_NAME;

::String NativeTextInput_obj::SANS_SERIF_FLASH_FONT_NAME;

::String NativeTextInput_obj::MONOSPACE_GENERIC_FONT_NAME;

::String NativeTextInput_obj::MONOSPACE_FLASH_FONT_NAME;


NativeTextInput_obj::NativeTextInput_obj()
{
}

void NativeTextInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeTextInput);
	HX_MARK_MEMBER_NAME(_mask,"_mask");
	HX_MARK_MEMBER_NAME(_textFormat,"_textFormat");
	HX_MARK_MEMBER_NAME(_textField,"_textField");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeTextInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_mask,"_mask");
	HX_VISIT_MEMBER_NAME(_textFormat,"_textFormat");
	HX_VISIT_MEMBER_NAME(_textField,"_textField");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeTextInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"blur") ) { return blur_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		if (HX_FIELD_EQ(inName,"_mask") ) { return _mask; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_bold") ) { return set_bold_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bold") ) { return get_bold_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_italic") ) { return get_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"set_italic") ) { return set_italic_dyn(); }
		if (HX_FIELD_EQ(inName,"_textField") ) { return _textField; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_textFormat") ) { return _textFormat; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontSize") ) { return set_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clipRect") ) { return set_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clipRect") ) { return get_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"set_viewport") ) { return set_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_viewport") ) { return get_viewport_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontFamily") ) { return set_fontFamily_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updateTextFormat") ) { return updateTextFormat_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_letterSpacing") ) { return set_letterSpacing_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { return SERIF_FLASH_FONT_NAME; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { return SERIF_GENERIC_FONT_NAME; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { return MONOSPACE_FLASH_FONT_NAME; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { return SANS_SERIF_FLASH_FONT_NAME; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { return MONOSPACE_GENERIC_FONT_NAME; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { return SANS_SERIF_GENERIC_FONT_NAME; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeTextInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_mask") ) { _mask=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_textField") ) { _textField=inValue.Cast< ::neash::text::TextField >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_textFormat") ) { _textFormat=inValue.Cast< ::neash::text::TextFormat >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { MONOSPACE_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { SANS_SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { MONOSPACE_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { SANS_SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeTextInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_mask"));
	outFields->push(HX_CSTRING("_textFormat"));
	outFields->push(HX_CSTRING("_textField"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("MONOSPACE_GENERIC_FONT_NAME"),
	HX_CSTRING("MONOSPACE_FLASH_FONT_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("set_letterSpacing"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("get_fontFamily"),
	HX_CSTRING("set_fontFamily"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_color"),
	HX_CSTRING("set_bold"),
	HX_CSTRING("get_bold"),
	HX_CSTRING("get_italic"),
	HX_CSTRING("set_italic"),
	HX_CSTRING("get_fontSize"),
	HX_CSTRING("set_fontSize"),
	HX_CSTRING("set_clipRect"),
	HX_CSTRING("get_clipRect"),
	HX_CSTRING("set_viewport"),
	HX_CSTRING("get_viewport"),
	HX_CSTRING("updateTextFormat"),
	HX_CSTRING("blur"),
	HX_CSTRING("focus"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("_mask"),
	HX_CSTRING("_textFormat"),
	HX_CSTRING("_textField"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(NativeTextInput_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(NativeTextInput_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

Class NativeTextInput_obj::__mClass;

void NativeTextInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.NativeTextInput"), hx::TCanCast< NativeTextInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeTextInput_obj::__boot()
{
	SERIF_GENERIC_FONT_NAME= HX_CSTRING("serif");
	SERIF_FLASH_FONT_NAME= HX_CSTRING("_serif");
	SANS_SERIF_GENERIC_FONT_NAME= HX_CSTRING("sans");
	SANS_SERIF_FLASH_FONT_NAME= HX_CSTRING("_sans");
	MONOSPACE_GENERIC_FONT_NAME= HX_CSTRING("typewriter");
	MONOSPACE_FLASH_FONT_NAME= HX_CSTRING("_typewriter");
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
