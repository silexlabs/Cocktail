#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
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
#ifndef INCLUDED_cocktail_core_style_FontStyle
#include <cocktail/core/style/FontStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_ContainerCoreStyle
#include <cocktail/port/flash_player/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
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
namespace cocktail{
namespace port{
namespace flash_player{

Void ContainerCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",56)
	super::__construct(htmlElement);
}
;
	return null();
}

ContainerCoreStyle_obj::~ContainerCoreStyle_obj() { }

Dynamic ContainerCoreStyle_obj::__CreateEmpty() { return  new ContainerCoreStyle_obj; }
hx::ObjectPtr< ContainerCoreStyle_obj > ContainerCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< ContainerCoreStyle_obj > result = new ContainerCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic ContainerCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ContainerCoreStyle_obj > result = new ContainerCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::renderer::TextRenderer ContainerCoreStyle_obj::doCreateTextRenderer( ::String text,::cocktail::core::dom::TextTokenValue textToken){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::doCreateTextRenderer")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",216)
	text = ::cocktail::core::dom::Text_obj::applyTextTransform(text,this->_computedStyle->__Field(HX_CSTRING("textTransform")));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",218)
	::nme::text::TextField textField = ::nme::text::TextField_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",219)
	textField->nmeSetText(text);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",220)
	textField->nmeSetSelectable(false);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",221)
	textField->nmeSetAutoSize(::nme::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",222)
	textField->setTextFormat(this->getTextFormat(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",224)
	::cocktail::core::renderer::TextRenderer textRenderer = ::cocktail::core::renderer::TextRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this),textField,textToken);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",227)
	return textRenderer;
}


HX_DEFINE_DYNAMIC_FUNC2(ContainerCoreStyle_obj,doCreateTextRenderer,return )

::nme::text::TextFormat ContainerCoreStyle_obj::getTextFormat( ){
	HX_SOURCE_PUSH("ContainerCoreStyle_obj::getTextFormat")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",235)
	::nme::text::TextFormat textFormat = ::nme::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",236)
	textFormat->font = this->getNativeFontFamily(this->_computedStyle->__Field(HX_CSTRING("fontFamily")));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",238)
	textFormat->letterSpacing = this->_computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",239)
	textFormat->size = this->_computedStyle->__Field(HX_CSTRING("fontSize"));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",241)
	bool bold;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",243)
	{
::cocktail::core::style::FontWeight _switch_1 = (this->_computedStyle->__Field(HX_CSTRING("fontWeight")));
		switch((_switch_1)->GetIndex()){
			case 3: case 0: case 4: case 5: case 6: case 7: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",245)
				bold = false;
			}
			;break;
			case 1: case 2: case 8: case 9: case 10: case 11: case 12: {
				HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",249)
				bold = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",254)
	textFormat->bold = bold;
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",255)
	textFormat->italic = (this->_computedStyle->__Field(HX_CSTRING("fontStyle")) == ::cocktail::core::style::FontStyle_obj::italic_dyn());
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",257)
	textFormat->letterSpacing = this->_computedStyle->__Field(HX_CSTRING("letterSpacing"));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",259)
	textFormat->color = this->_computedStyle->__Field(HX_CSTRING("color"))->__Field(HX_CSTRING("color"));
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/ContainerCoreStyle.hx",260)
	return textFormat;
}


HX_DEFINE_DYNAMIC_FUNC0(ContainerCoreStyle_obj,getTextFormat,return )


ContainerCoreStyle_obj::ContainerCoreStyle_obj()
{
}

void ContainerCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ContainerCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ContainerCoreStyle_obj::__Field(const ::String &inName)
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

Dynamic ContainerCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void ContainerCoreStyle_obj::__GetFields(Array< ::String> &outFields)
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

Class ContainerCoreStyle_obj::__mClass;

void ContainerCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.ContainerCoreStyle"), hx::TCanCast< ContainerCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ContainerCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
