#include <hxcpp.h>

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
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_renderer_BoxRenderer
#include <core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_EmbeddedBoxRenderer
#include <core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace renderer{

Void EmbeddedBoxRenderer_obj::__construct(::port::flash_player::Style style)
{
{
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",32)
	super::__construct(style);
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",33)
	this->_bounds->__FieldRef(HX_CSTRING("width")) = style->get_htmlElement()->get_offsetWidth();
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",34)
	this->_bounds->__FieldRef(HX_CSTRING("height")) = style->get_htmlElement()->get_offsetHeight();
}
;
	return null();
}

EmbeddedBoxRenderer_obj::~EmbeddedBoxRenderer_obj() { }

Dynamic EmbeddedBoxRenderer_obj::__CreateEmpty() { return  new EmbeddedBoxRenderer_obj; }
hx::ObjectPtr< EmbeddedBoxRenderer_obj > EmbeddedBoxRenderer_obj::__new(::port::flash_player::Style style)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic EmbeddedBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic EmbeddedBoxRenderer_obj::render( ){
	HX_SOURCE_PUSH("EmbeddedBoxRenderer_obj::render")
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",44)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",52)
	::nme::display::Sprite nativeElement = this->_style->get_htmlElement()->get_nativeElement();
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",54)
	nativeElement->nmeGetGraphics()->clear();
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",55)
	nativeElement->nmeGetGraphics()->beginFill((int)65280,0.0);
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",56)
	nativeElement->nmeGetGraphics()->drawRect((this->_bounds->__Field(HX_CSTRING("x")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))),(this->_bounds->__Field(HX_CSTRING("y")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))),this->_bounds->__Field(HX_CSTRING("width")),this->_bounds->__Field(HX_CSTRING("height")));
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",58)
	nativeElement->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",62)
	ret->__Field(HX_CSTRING("push"))(nativeElement);
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",65)
	::core::html::EmbeddedElement embeddedHTMLElement = this->_style->get_htmlElement();
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",66)
	ret->__Field(HX_CSTRING("push"))(embeddedHTMLElement->get_embeddedAsset());
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",69)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("x")) = (this->_bounds->__Field(HX_CSTRING("x")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")));
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",70)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("y")) = (this->_bounds->__Field(HX_CSTRING("y")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",72)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("width")) = this->_style->getComputedStyle()->__Field(HX_CSTRING("width"));
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",73)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("height")) = this->_style->getComputedStyle()->__Field(HX_CSTRING("height"));
	HX_SOURCE_POS("../../src/core/renderer/EmbeddedBoxRenderer.hx",83)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedBoxRenderer_obj,render,return )


EmbeddedBoxRenderer_obj::EmbeddedBoxRenderer_obj()
{
}

void EmbeddedBoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedBoxRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedBoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EmbeddedBoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EmbeddedBoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedBoxRenderer_obj::__mClass;

void EmbeddedBoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.renderer.EmbeddedBoxRenderer"), hx::TCanCast< EmbeddedBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedBoxRenderer_obj::__boot()
{
}

} // end namespace core
} // end namespace renderer
