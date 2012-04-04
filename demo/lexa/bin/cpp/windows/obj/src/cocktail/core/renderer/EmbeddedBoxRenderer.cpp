#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
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
namespace cocktail{
namespace core{
namespace renderer{

Void EmbeddedBoxRenderer_obj::__construct(::cocktail::port::flash_player::CoreStyle style)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",32)
	super::__construct(style);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",33)
	Dynamic computedStyle = style->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",34)
	this->_bounds->__FieldRef(HX_CSTRING("width")) = ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",35)
	this->_bounds->__FieldRef(HX_CSTRING("height")) = ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
}
;
	return null();
}

EmbeddedBoxRenderer_obj::~EmbeddedBoxRenderer_obj() { }

Dynamic EmbeddedBoxRenderer_obj::__CreateEmpty() { return  new EmbeddedBoxRenderer_obj; }
hx::ObjectPtr< EmbeddedBoxRenderer_obj > EmbeddedBoxRenderer_obj::__new(::cocktail::port::flash_player::CoreStyle style)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic EmbeddedBoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedBoxRenderer_obj > result = new EmbeddedBoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic EmbeddedBoxRenderer_obj::render( ){
	HX_SOURCE_PUSH("EmbeddedBoxRenderer_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",45)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",53)
	::nme::display::Sprite nativeElement = this->_coreStyle->get_htmlElement()->get_nativeElement();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",55)
	nativeElement->nmeGetGraphics()->clear();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",56)
	nativeElement->nmeGetGraphics()->beginFill((int)65280,0.0);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",57)
	nativeElement->nmeGetGraphics()->drawRect((this->_bounds->__Field(HX_CSTRING("x")) + this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))),(this->_bounds->__Field(HX_CSTRING("y")) + this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))),this->_bounds->__Field(HX_CSTRING("width")),this->_bounds->__Field(HX_CSTRING("height")));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",59)
	nativeElement->nmeGetGraphics()->endFill();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",63)
	ret->__Field(HX_CSTRING("push"))(nativeElement);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",66)
	::cocktail::core::html::EmbeddedElement embeddedHTMLElement = this->_coreStyle->get_htmlElement();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",67)
	ret->__Field(HX_CSTRING("push"))(embeddedHTMLElement->get_embeddedAsset());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",70)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("x")) = (this->_bounds->__Field(HX_CSTRING("x")) + this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",71)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("y")) = (this->_bounds->__Field(HX_CSTRING("y")) + this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",73)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("width")) = this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("width"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",74)
	embeddedHTMLElement->get_embeddedAsset()->__FieldRef(HX_CSTRING("height")) = this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("height"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/EmbeddedBoxRenderer.hx",84)
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.EmbeddedBoxRenderer"), hx::TCanCast< EmbeddedBoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedBoxRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
