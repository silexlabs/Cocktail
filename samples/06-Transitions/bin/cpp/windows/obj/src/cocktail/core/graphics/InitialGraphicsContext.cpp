#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_graphics_AbstractGraphicsContextImpl
#include <cocktail/core/graphics/AbstractGraphicsContextImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_InitialGraphicsContext
#include <cocktail/core/graphics/InitialGraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl
#include <cocktail/port/platform/flash_player/GraphicsContextImpl.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
namespace cocktail{
namespace core{
namespace graphics{

Void InitialGraphicsContext_obj::__construct(::cocktail::core::layer::LayerRenderer layerRenderer)
{
HX_STACK_PUSH("InitialGraphicsContext::new","cocktail/core/graphics/InitialGraphicsContext.hx",35);
{
	HX_STACK_LINE(36)
	super::__construct(layerRenderer);
	HX_STACK_LINE(41)
	this->invalidateNativeLayer();
}
;
	return null();
}

InitialGraphicsContext_obj::~InitialGraphicsContext_obj() { }

Dynamic InitialGraphicsContext_obj::__CreateEmpty() { return  new InitialGraphicsContext_obj; }
hx::ObjectPtr< InitialGraphicsContext_obj > InitialGraphicsContext_obj::__new(::cocktail::core::layer::LayerRenderer layerRenderer)
{  hx::ObjectPtr< InitialGraphicsContext_obj > result = new InitialGraphicsContext_obj();
	result->__construct(layerRenderer);
	return result;}

Dynamic InitialGraphicsContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialGraphicsContext_obj > result = new InitialGraphicsContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InitialGraphicsContext_obj::doDetach( ){
{
		HX_STACK_PUSH("InitialGraphicsContext::doDetach","cocktail/core/graphics/InitialGraphicsContext.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		this->graphics->detachFromRoot();
	}
return null();
}


Void InitialGraphicsContext_obj::doAttach( ){
{
		HX_STACK_PUSH("InitialGraphicsContext::doAttach","cocktail/core/graphics/InitialGraphicsContext.hx",55);
		HX_STACK_THIS(this);
		HX_STACK_LINE(57)
		::cocktail::core::html::HTMLDocument htmlDocument = this->layerRenderer->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(58)
		::neash::display::DisplayObjectContainer rootNativeLayer = htmlDocument->window->platform->getInitialNativeLayer();		HX_STACK_VAR(rootNativeLayer,"rootNativeLayer");
		HX_STACK_LINE(59)
		this->graphics->attachToRoot(rootNativeLayer);
		HX_STACK_LINE(64)
		this->invalidateBitmapSize();
	}
return null();
}



InitialGraphicsContext_obj::InitialGraphicsContext_obj()
{
}

void InitialGraphicsContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialGraphicsContext);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InitialGraphicsContext_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InitialGraphicsContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"doDetach") ) { return doDetach_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttach") ) { return doAttach_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InitialGraphicsContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InitialGraphicsContext_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doDetach"),
	HX_CSTRING("doAttach"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InitialGraphicsContext_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InitialGraphicsContext_obj::__mClass,"__mClass");
};

Class InitialGraphicsContext_obj::__mClass;

void InitialGraphicsContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.graphics.InitialGraphicsContext"), hx::TCanCast< InitialGraphicsContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InitialGraphicsContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace graphics
