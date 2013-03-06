#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_Graphics
#include <native/display/Graphics.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_MovieClip
#include <native/display/MovieClip.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFieldType
#include <native/text/TextFieldType.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void NativeTextInput_obj::__construct()
{
HX_STACK_PUSH("NativeTextInput::new","cocktail/port/platform/flash_player/NativeTextInput.hx",64);
{
	HX_STACK_LINE(65)
	super::__construct();
	HX_STACK_LINE(67)
	this->_textField = ::native::text::TextField_obj::__new();
	HX_STACK_LINE(69)
	this->_mask = ::native::display::Sprite_obj::__new();
	HX_STACK_LINE(70)
	this->_textField->set_mask(this->_mask);
	HX_STACK_LINE(78)
	this->_textField->set_type(::native::text::TextFieldType_obj::INPUT_dyn());
	HX_STACK_LINE(80)
	this->_textFormat = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(82)
	this->updateTextFormat();
}
;
	return null();
}

NativeTextInput_obj::~NativeTextInput_obj() { }

Dynamic NativeTextInput_obj::__CreateEmpty() { return  new NativeTextInput_obj; }
hx::ObjectPtr< NativeTextInput_obj > NativeTextInput_obj::__new()
{  hx::ObjectPtr< NativeTextInput_obj > result = new NativeTextInput_obj();
	result->__construct();
	return result;}

Dynamic NativeTextInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeTextInput_obj > result = new NativeTextInput_obj();
	result->__construct();
	return result;}

Float NativeTextInput_obj::get_letterSpacing( ){
	HX_STACK_PUSH("NativeTextInput::get_letterSpacing","cocktail/port/platform/flash_player/NativeTextInput.hx",276);
	HX_STACK_THIS(this);
	HX_STACK_LINE(276)
	return this->_textFormat->letterSpacing;
}


Float NativeTextInput_obj::set_letterSpacing( Float value){
	HX_STACK_PUSH("NativeTextInput::set_letterSpacing","cocktail/port/platform/flash_player/NativeTextInput.hx",268);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(269)
	this->_textFormat->letterSpacing = value;
	HX_STACK_LINE(270)
	this->updateTextFormat();
	HX_STACK_LINE(272)
	return value;
}


int NativeTextInput_obj::set_maxLength( int value){
	HX_STACK_PUSH("NativeTextInput::set_maxLength","cocktail/port/platform/flash_player/NativeTextInput.hx",263);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(263)
	return this->_textField->set_maxChars(value);
}


::String NativeTextInput_obj::set_value( ::String textValue){
	HX_STACK_PUSH("NativeTextInput::set_value","cocktail/port/platform/flash_player/NativeTextInput.hx",258);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textValue,"textValue");
	HX_STACK_LINE(258)
	return this->_textField->set_text(textValue);
}


::String NativeTextInput_obj::get_value( ){
	HX_STACK_PUSH("NativeTextInput::get_value","cocktail/port/platform/flash_player/NativeTextInput.hx",253);
	HX_STACK_THIS(this);
	HX_STACK_LINE(253)
	return this->_textField->get_text();
}


::String NativeTextInput_obj::get_fontFamily( ){
	HX_STACK_PUSH("NativeTextInput::get_fontFamily","cocktail/port/platform/flash_player/NativeTextInput.hx",248);
	HX_STACK_THIS(this);
	HX_STACK_LINE(248)
	return this->_textFormat->font;
}


::String NativeTextInput_obj::set_fontFamily( ::String value){
	HX_STACK_PUSH("NativeTextInput::set_fontFamily","cocktail/port/platform/flash_player/NativeTextInput.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(229)
	::String _switch_1 = (value);
	if (  ( _switch_1==HX_CSTRING("serif"))){
		HX_STACK_LINE(231)
		value = HX_CSTRING("_serif");
	}
	else if (  ( _switch_1==HX_CSTRING("sans"))){
		HX_STACK_LINE(234)
		value = HX_CSTRING("_sans");
	}
	else if (  ( _switch_1==HX_CSTRING("typewriter"))){
		HX_STACK_LINE(237)
		value = HX_CSTRING("_typewriter");
	}
	HX_STACK_LINE(241)
	this->_textFormat->font = value;
	HX_STACK_LINE(242)
	this->updateTextFormat();
	HX_STACK_LINE(244)
	return value;
}


int NativeTextInput_obj::get_color( ){
	HX_STACK_PUSH("NativeTextInput::get_color","cocktail/port/platform/flash_player/NativeTextInput.hx",219);
	HX_STACK_THIS(this);
	HX_STACK_LINE(219)
	return this->_textFormat->color;
}


int NativeTextInput_obj::set_color( int value){
	HX_STACK_PUSH("NativeTextInput::set_color","cocktail/port/platform/flash_player/NativeTextInput.hx",211);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(212)
	this->_textFormat->color = value;
	HX_STACK_LINE(213)
	this->updateTextFormat();
	HX_STACK_LINE(215)
	return value;
}


bool NativeTextInput_obj::set_bold( bool value){
	HX_STACK_PUSH("NativeTextInput::set_bold","cocktail/port/platform/flash_player/NativeTextInput.hx",203);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(204)
	this->_textFormat->bold = value;
	HX_STACK_LINE(205)
	this->updateTextFormat();
	HX_STACK_LINE(207)
	return value;
}


bool NativeTextInput_obj::get_bold( ){
	HX_STACK_PUSH("NativeTextInput::get_bold","cocktail/port/platform/flash_player/NativeTextInput.hx",198);
	HX_STACK_THIS(this);
	HX_STACK_LINE(198)
	return this->_textFormat->bold;
}


bool NativeTextInput_obj::get_italic( ){
	HX_STACK_PUSH("NativeTextInput::get_italic","cocktail/port/platform/flash_player/NativeTextInput.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_LINE(193)
	return this->_textFormat->italic;
}


bool NativeTextInput_obj::set_italic( bool value){
	HX_STACK_PUSH("NativeTextInput::set_italic","cocktail/port/platform/flash_player/NativeTextInput.hx",185);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(186)
	this->_textFormat->italic = value;
	HX_STACK_LINE(187)
	this->updateTextFormat();
	HX_STACK_LINE(189)
	return value;
}


Float NativeTextInput_obj::get_fontSize( ){
	HX_STACK_PUSH("NativeTextInput::get_fontSize","cocktail/port/platform/flash_player/NativeTextInput.hx",180);
	HX_STACK_THIS(this);
	HX_STACK_LINE(180)
	return this->_textFormat->size;
}


Float NativeTextInput_obj::set_fontSize( Float value){
	HX_STACK_PUSH("NativeTextInput::set_fontSize","cocktail/port/platform/flash_player/NativeTextInput.hx",172);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(173)
	this->_textFormat->size = value;
	HX_STACK_LINE(174)
	this->updateTextFormat();
	HX_STACK_LINE(176)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::set_clipRect( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInput::set_clipRect","cocktail/port/platform/flash_player/NativeTextInput.hx",162);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(163)
	this->_mask->get_graphics()->clear();
	HX_STACK_LINE(164)
	this->_mask->get_graphics()->beginFill((int)16711680,0.5);
	HX_STACK_LINE(165)
	this->_mask->get_graphics()->drawRect(value->x,value->y,value->width,value->height);
	HX_STACK_LINE(166)
	this->_mask->get_graphics()->endFill();
	HX_STACK_LINE(168)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::get_clipRect( ){
	HX_STACK_PUSH("NativeTextInput::get_clipRect","cocktail/port/platform/flash_player/NativeTextInput.hx",157);
	HX_STACK_THIS(this);
	HX_STACK_LINE(157)
	return this->clipRect;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::set_viewport( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeTextInput::set_viewport","cocktail/port/platform/flash_player/NativeTextInput.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(148)
	this->_textField->set_x(value->x);
	HX_STACK_LINE(149)
	this->_textField->set_y(value->y);
	HX_STACK_LINE(150)
	this->_textField->set_width(value->width);
	HX_STACK_LINE(151)
	this->_textField->set_height(value->height);
	HX_STACK_LINE(153)
	return value;
}


::cocktail::core::geom::RectangleVO NativeTextInput_obj::get_viewport( ){
	HX_STACK_PUSH("NativeTextInput::get_viewport","cocktail/port/platform/flash_player/NativeTextInput.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_LINE(138)
	::cocktail::core::geom::RectangleVO rect = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(139)
	rect->x = this->_textField->get_x();
	HX_STACK_LINE(140)
	rect->y = this->_textField->get_y();
	HX_STACK_LINE(141)
	rect->width = this->_textField->get_width();
	HX_STACK_LINE(142)
	rect->height = this->_textField->get_height();
	HX_STACK_LINE(143)
	return rect;
}


Void NativeTextInput_obj::updateTextFormat( ){
{
		HX_STACK_PUSH("NativeTextInput::updateTextFormat","cocktail/port/platform/flash_player/NativeTextInput.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_LINE(127)
		this->_textField->set_defaultTextFormat(this->_textFormat);
		HX_STACK_LINE(128)
		this->_textField->setTextFormat(this->_textFormat,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeTextInput_obj,updateTextFormat,(void))

Void NativeTextInput_obj::focus( ){
{
		HX_STACK_PUSH("NativeTextInput::focus","cocktail/port/platform/flash_player/NativeTextInput.hx",112);
		HX_STACK_THIS(this);
		HX_STACK_LINE(112)
		::nme::Lib_obj::get_current()->get_stage()->set_focus(this->_textField);
	}
return null();
}


Void NativeTextInput_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInput::detach","cocktail/port/platform/flash_player/NativeTextInput.hx",103);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_LINE(104)
		::native::display::DisplayObjectContainer containerGraphicContext = graphicContext->get_nativeLayer();		HX_STACK_VAR(containerGraphicContext,"containerGraphicContext");
		HX_STACK_LINE(105)
		containerGraphicContext->removeChild(this->_textField);
	}
return null();
}


Void NativeTextInput_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeTextInput::attach","cocktail/port/platform/flash_player/NativeTextInput.hx",93);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_LINE(94)
		::native::display::DisplayObjectContainer containerGraphicContext = graphicContext->get_nativeLayer();		HX_STACK_VAR(containerGraphicContext,"containerGraphicContext");
		HX_STACK_LINE(96)
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
		if (HX_FIELD_EQ(inName,"_mask") ) { _mask=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_textField") ) { _textField=inValue.Cast< ::native::text::TextField >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_textFormat") ) { _textFormat=inValue.Cast< ::native::text::TextFormat >(); return inValue; }
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
