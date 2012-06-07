#include <hxcpp.h>

#ifndef INCLUDED_core_dom_CharacterData
#include <core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
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
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
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
#ifndef INCLUDED_core_style_FontFamily
#include <core/style/FontFamily.h>
#endif
#ifndef INCLUDED_core_style_FontStyle
#include <core/style/FontStyle.h>
#endif
#ifndef INCLUDED_core_style_FontWeight
#include <core/style/FontWeight.h>
#endif
#ifndef INCLUDED_core_style_TextTransform
#include <core/style/TextTransform.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_text_TextField
#include <nme/text/TextField.h>
#endif
#ifndef INCLUDED_nme_text_TextFieldAutoSize
#include <nme/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_nme_text_TextFormat
#include <nme/text/TextFormat.h>
#endif
#ifndef INCLUDED_port_flash_player_ContainerStyle
#include <port/flash_player/ContainerStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace port{
namespace flash_player{

Void ContainerStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",56)
	super::__construct(htmlElement);
}
;
	return null();
}

ContainerStyle_obj::~ContainerStyle_obj() { }

Dynamic ContainerStyle_obj::__CreateEmpty() { return  new ContainerStyle_obj; }
hx::ObjectPtr< ContainerStyle_obj > ContainerStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< ContainerStyle_obj > result = new ContainerStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic ContainerStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ContainerStyle_obj > result = new ContainerStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::core::renderer::TextRenderer ContainerStyle_obj::doCreateTextRenderer( ::String text,::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("ContainerStyle_obj::doCreateTextRenderer")
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",216)
	text = ::core::dom::Text_obj::applyTextTransform(text,this->_computedStyle->__Field(HX_CSTRING("textTransform")));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",218)
	::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",219)
	textField->nmeSetText(text);
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",220)
	textField->nmeSetSelectable(false);
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",221)
	textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",222)
	textField->setTextFormat(this->getTextFormat(),null(),null());
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",224)
	::core::renderer::TextRenderer textRenderer = ::core::renderer::TextRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this),textField,textToken);
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",227)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerStyle_obj,doCreateTextRenderer,return )

::nme::text::TextFormat ContainerStyle_obj::getTextFormat( ){
	HX_SOURCE_PUSH("ContainerStyle_obj::getTextFormat")
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",235)
	::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",236)
	textFormat->font = this->getNativeFontFamily(this->_computedStyle->__Field(HX_CSTRING("fontFamily")));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",238)
	textFormat->letterSpacing = this->_computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",239)
	textFormat->size = this->_computedStyle->__Field(HX_CSTRING("fontSize"));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",241)
	bool bold;
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",243)
	{
::core::style::FontWeight _switch_1 = (this->_computedStyle->__Field(HX_CSTRING("fontWeight")));
		switch((_switch_1)->GetIndex()){
			case 3: case 0: case 4: case 5: case 6: case 7: {
				HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",245)
				bold = false;
			}
			;break;
			case 1: case 2: case 8: case 9: case 10: case 11: case 12: {
				HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",249)
				bold = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",254)
	textFormat->bold = bold;
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",255)
	textFormat->italic = (this->_computedStyle->__Field(HX_CSTRING("fontStyle")) == ::core::style::FontStyle_obj::italic_dyn());
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",257)
	textFormat->letterSpacing = this->_computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",259)
	textFormat->color = this->_computedStyle->__Field(HX_CSTRING("color"))->__Field(HX_CSTRING("color"));
	HX_SOURCE_POS("../../src/port/flash_player/ContainerStyle.hx",260)
	return textFormat;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerStyle_obj,getTextFormat,return )


ContainerStyle_obj::ContainerStyle_obj()
{
}

void ContainerStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ContainerStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ContainerStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getTextFormat") ) { return getTextFormat_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"doCreateTextRenderer") ) { return doCreateTextRenderer_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ContainerStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ContainerStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doCreateTextRenderer"),
	HX_CSTRING("getTextFormat"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ContainerStyle_obj::__mClass;

void ContainerStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("port.flash_player.ContainerStyle"), hx::TCanCast< ContainerStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ContainerStyle_obj::__boot()
{
}

} // end namespace port
} // end namespace flash_player
