#include <hxcpp.h>

#ifndef INCLUDED_core_background_BackgroundManager
#include <core/background/BackgroundManager.h>
#endif
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
#ifndef INCLUDED_core_renderer_BoxRenderer
#include <core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_core_renderer_ElementRenderer
#include <core/renderer/ElementRenderer.h>
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

Void BoxRenderer_obj::__construct(::port::flash_player::Style style)
{
{
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",35)
	super::__construct(style);
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",36)
	this->init();
}
;
	return null();
}

BoxRenderer_obj::~BoxRenderer_obj() { }

Dynamic BoxRenderer_obj::__CreateEmpty() { return  new BoxRenderer_obj; }
hx::ObjectPtr< BoxRenderer_obj > BoxRenderer_obj::__new(::port::flash_player::Style style)
{  hx::ObjectPtr< BoxRenderer_obj > result = new BoxRenderer_obj();
	result->__construct(style);
	return result;}

Dynamic BoxRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxRenderer_obj > result = new BoxRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BoxRenderer_obj::init( ){
{
		HX_SOURCE_PUSH("BoxRenderer_obj::init")
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",41)
		this->_backgroundManager = ::core::background::BackgroundManager_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,init,(void))

Void BoxRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("BoxRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",47)
		this->super::dispose();
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",49)
		this->_backgroundManager->dispose();
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",51)
		this->_backgroundManager = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,dispose,(void))

Dynamic BoxRenderer_obj::renderBackground( ){
	HX_SOURCE_PUSH("BoxRenderer_obj::renderBackground")
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",63)
	Dynamic backgrounds = this->_backgroundManager->render(this->_bounds,this->_style);
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",65)
	{
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",65)
		int _g1 = (int)0;
		int _g = backgrounds->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",65)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",65)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",68)
			backgrounds->__GetItem(i)->__FieldRef(HX_CSTRING("x")) = this->_bounds->__Field(HX_CSTRING("x"));
			HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",69)
			backgrounds->__GetItem(i)->__FieldRef(HX_CSTRING("y")) = this->_bounds->__Field(HX_CSTRING("y"));
		}
	}
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",75)
	if (((this->isInitialContainer() == false))){
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",78)
		::nme::display::Sprite nativeElement = this->_style->get_htmlElement()->get_nativeElement();
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",80)
		nativeElement->nmeGetGraphics()->clear();
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",81)
		nativeElement->nmeGetGraphics()->beginFill((int)65280,0.0);
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",82)
		nativeElement->nmeGetGraphics()->drawRect((this->_bounds->__Field(HX_CSTRING("x")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))),(this->_bounds->__Field(HX_CSTRING("y")) + this->_style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))),this->_bounds->__Field(HX_CSTRING("width")),this->_bounds->__Field(HX_CSTRING("height")));
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",84)
		nativeElement->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",88)
		backgrounds->__Field(HX_CSTRING("push"))(nativeElement);
	}
	HX_SOURCE_POS("../../src/core/renderer/BoxRenderer.hx",94)
	return backgrounds;
}


HX_DEFINE_DYNAMIC_FUNC0(BoxRenderer_obj,renderBackground,return )


BoxRenderer_obj::BoxRenderer_obj()
{
}

void BoxRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxRenderer);
	HX_MARK_MEMBER_NAME(_backgroundManager,"_backgroundManager");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BoxRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"renderBackground") ) { return renderBackground_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_backgroundManager") ) { return _backgroundManager; }
	}
	return super::__Field(inName);
}

Dynamic BoxRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"_backgroundManager") ) { _backgroundManager=inValue.Cast< ::core::background::BackgroundManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BoxRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_backgroundManager"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_backgroundManager"),
	HX_CSTRING("init"),
	HX_CSTRING("dispose"),
	HX_CSTRING("renderBackground"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BoxRenderer_obj::__mClass;

void BoxRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.renderer.BoxRenderer"), hx::TCanCast< BoxRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BoxRenderer_obj::__boot()
{
}

} // end namespace core
} // end namespace renderer
