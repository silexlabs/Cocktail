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
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#include <cocktail/core/invalidation/InvalidationManager.h>
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
#ifndef INCLUDED_cocktail_port_platform_flash_player_GraphicsContextImpl
#include <cocktail/port/platform/flash_player/GraphicsContextImpl.h>
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

Void GraphicsContext_obj::__construct(::cocktail::core::layer::LayerRenderer layerRenderer)
{
HX_STACK_PUSH("GraphicsContext::new","cocktail/core/graphics/GraphicsContext.hx",82);
{
	HX_STACK_LINE(83)
	super::__construct();
	HX_STACK_LINE(84)
	this->layerRenderer = layerRenderer;
	HX_STACK_LINE(85)
	this->_needsNativeLayerUpdate = true;
	HX_STACK_LINE(86)
	this->graphics = ::cocktail::port::platform::flash_player::GraphicsContextImpl_obj::__new();
}
;
	return null();
}

GraphicsContext_obj::~GraphicsContext_obj() { }

Dynamic GraphicsContext_obj::__CreateEmpty() { return  new GraphicsContext_obj; }
hx::ObjectPtr< GraphicsContext_obj > GraphicsContext_obj::__new(::cocktail::core::layer::LayerRenderer layerRenderer)
{  hx::ObjectPtr< GraphicsContext_obj > result = new GraphicsContext_obj();
	result->__construct(layerRenderer);
	return result;}

Dynamic GraphicsContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphicsContext_obj > result = new GraphicsContext_obj();
	result->__construct(inArgs[0]);
	return result;}

::neash::display::DisplayObjectContainer GraphicsContext_obj::get_nativeLayer( ){
	HX_STACK_PUSH("GraphicsContext::get_nativeLayer","cocktail/core/graphics/GraphicsContext.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_LINE(307)
	return this->graphics->get_nativeLayer();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,get_nativeLayer,return )

Void GraphicsContext_obj::doDetach( ){
{
		HX_STACK_PUSH("GraphicsContext::doDetach","cocktail/core/graphics/GraphicsContext.hx",298);
		HX_STACK_THIS(this);
		HX_STACK_LINE(298)
		this->graphics->detach(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,doDetach,(void))

Void GraphicsContext_obj::doAttach( ){
{
		HX_STACK_PUSH("GraphicsContext::doAttach","cocktail/core/graphics/GraphicsContext.hx",280);
		HX_STACK_THIS(this);
		HX_STACK_LINE(283)
		int index = (int)0;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(284)
		::cocktail::core::graphics::GraphicsContext previousGraphicsContextSibling = this->previousSibling;		HX_STACK_VAR(previousGraphicsContextSibling,"previousGraphicsContextSibling");
		HX_STACK_LINE(285)
		while(((previousGraphicsContextSibling != null()))){
			HX_STACK_LINE(287)
			(index)++;
			HX_STACK_LINE(288)
			previousGraphicsContextSibling = previousGraphicsContextSibling->previousSibling;
		}
		HX_STACK_LINE(291)
		this->graphics->attach(hx::ObjectPtr<OBJ_>(this),index);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,doAttach,(void))

Void GraphicsContext_obj::detach( ){
{
		HX_STACK_PUSH("GraphicsContext::detach","cocktail/core/graphics/GraphicsContext.hx",261);
		HX_STACK_THIS(this);
		HX_STACK_LINE(262)
		::cocktail::core::graphics::GraphicsContext child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(263)
		while(((child != null()))){
			HX_STACK_LINE(265)
			child->detach();
			HX_STACK_LINE(266)
			child = child->nextSibling;
		}
		HX_STACK_LINE(269)
		this->doDetach();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,detach,(void))

Void GraphicsContext_obj::attach( ){
{
		HX_STACK_PUSH("GraphicsContext::attach","cocktail/core/graphics/GraphicsContext.hx",244);
		HX_STACK_THIS(this);
		HX_STACK_LINE(245)
		this->doAttach();
		HX_STACK_LINE(247)
		::cocktail::core::graphics::GraphicsContext child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(248)
		while(((child != null()))){
			HX_STACK_LINE(250)
			child->attach();
			HX_STACK_LINE(251)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,attach,(void))

Void GraphicsContext_obj::invalidateBitmapSize( ){
{
		HX_STACK_PUSH("GraphicsContext::invalidateBitmapSize","cocktail/core/graphics/GraphicsContext.hx",233);
		HX_STACK_THIS(this);
		HX_STACK_LINE(234)
		::cocktail::core::html::HTMLDocument htmlDocument = this->layerRenderer->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(235)
		htmlDocument->invalidationManager->invalidateBitmapSizes();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,invalidateBitmapSize,(void))

Void GraphicsContext_obj::invalidateNativeLayer( ){
{
		HX_STACK_PUSH("GraphicsContext::invalidateNativeLayer","cocktail/core/graphics/GraphicsContext.hx",221);
		HX_STACK_THIS(this);
		HX_STACK_LINE(222)
		this->_needsNativeLayerUpdate = true;
		HX_STACK_LINE(223)
		::cocktail::core::html::HTMLDocument htmlDocument = this->layerRenderer->rootElementRenderer->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(224)
		htmlDocument->invalidationManager->invalidateNativeLayerTree();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,invalidateNativeLayer,(void))

Void GraphicsContext_obj::updateNativeLayer( ){
{
		HX_STACK_PUSH("GraphicsContext::updateNativeLayer","cocktail/core/graphics/GraphicsContext.hx",199);
		HX_STACK_THIS(this);
		HX_STACK_LINE(200)
		if (((this->_needsNativeLayerUpdate == true))){
			HX_STACK_LINE(202)
			this->_needsNativeLayerUpdate = false;
			HX_STACK_LINE(203)
			this->detach();
			HX_STACK_LINE(204)
			this->attach();
			HX_STACK_LINE(205)
			return null();
		}
		HX_STACK_LINE(208)
		::cocktail::core::graphics::GraphicsContext child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(209)
		while(((child != null()))){
			HX_STACK_LINE(211)
			child->updateNativeLayer();
			HX_STACK_LINE(212)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,updateNativeLayer,(void))

Void GraphicsContext_obj::updateGraphicsSize( int viewportWidth,int viewportHeight){
{
		HX_STACK_PUSH("GraphicsContext::updateGraphicsSize","cocktail/core/graphics/GraphicsContext.hx",178);
		HX_STACK_THIS(this);
		HX_STACK_ARG(viewportWidth,"viewportWidth");
		HX_STACK_ARG(viewportHeight,"viewportHeight");
		HX_STACK_LINE(180)
		if (((this->layerRenderer->needsBitmap() == true))){
			HX_STACK_LINE(181)
			this->graphics->initBitmapData(viewportWidth,viewportHeight);
		}
		HX_STACK_LINE(185)
		::cocktail::core::graphics::GraphicsContext child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(186)
		while(((child != null()))){
			HX_STACK_LINE(188)
			child->updateGraphicsSize(viewportWidth,viewportHeight);
			HX_STACK_LINE(189)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicsContext_obj,updateGraphicsSize,(void))

Void GraphicsContext_obj::removedFromGraphicsContextTree( ){
{
		HX_STACK_PUSH("GraphicsContext::removedFromGraphicsContextTree","cocktail/core/graphics/GraphicsContext.hx",162);
		HX_STACK_THIS(this);
		HX_STACK_LINE(163)
		this->detach();
		HX_STACK_LINE(164)
		this->invalidateNativeLayer();
		HX_STACK_LINE(165)
		this->invalidateBitmapSize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,removedFromGraphicsContextTree,(void))

Void GraphicsContext_obj::addedToGraphicsContextTree( ){
{
		HX_STACK_PUSH("GraphicsContext::addedToGraphicsContextTree","cocktail/core/graphics/GraphicsContext.hx",151);
		HX_STACK_THIS(this);
		HX_STACK_LINE(152)
		this->invalidateNativeLayer();
		HX_STACK_LINE(153)
		this->invalidateBitmapSize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,addedToGraphicsContextTree,(void))

Void GraphicsContext_obj::insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild){
{
		HX_STACK_PUSH("GraphicsContext::insertBefore","cocktail/core/graphics/GraphicsContext.hx",130);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_ARG(_tmp_refChild,"_tmp_refChild");
		HX_STACK_LINE(131)
		::cocktail::core::graphics::GraphicsContext newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		::cocktail::core::graphics::GraphicsContext refChild = _tmp_refChild;		HX_STACK_VAR(refChild,"refChild");
		HX_STACK_LINE(131)
		this->super::insertBefore(newChild,refChild);
		HX_STACK_LINE(133)
		if (((refChild == null()))){
			HX_STACK_LINE(134)
			return null();
		}
		HX_STACK_LINE(138)
		newChild->addedToGraphicsContextTree();
	}
return null();
}


Void GraphicsContext_obj::removeChild( Dynamic _tmp_oldChild){
{
		HX_STACK_PUSH("GraphicsContext::removeChild","cocktail/core/graphics/GraphicsContext.hx",120);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_oldChild,"_tmp_oldChild");
		HX_STACK_LINE(121)
		::cocktail::core::graphics::GraphicsContext oldChild = _tmp_oldChild;		HX_STACK_VAR(oldChild,"oldChild");
		HX_STACK_LINE(121)
		oldChild->removedFromGraphicsContextTree();
		HX_STACK_LINE(122)
		this->super::removeChild(oldChild);
	}
return null();
}


Void GraphicsContext_obj::appendChild( Dynamic _tmp_newChild){
{
		HX_STACK_PUSH("GraphicsContext::appendChild","cocktail/core/graphics/GraphicsContext.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_tmp_newChild,"_tmp_newChild");
		HX_STACK_LINE(110)
		::cocktail::core::graphics::GraphicsContext newChild = _tmp_newChild;		HX_STACK_VAR(newChild,"newChild");
		HX_STACK_LINE(110)
		this->super::appendChild(newChild);
		HX_STACK_LINE(111)
		newChild->addedToGraphicsContextTree();
	}
return null();
}


Void GraphicsContext_obj::dispose( ){
{
		HX_STACK_PUSH("GraphicsContext::dispose","cocktail/core/graphics/GraphicsContext.hx",94);
		HX_STACK_THIS(this);
		HX_STACK_LINE(95)
		this->graphics->dispose();
		HX_STACK_LINE(96)
		this->graphics = null();
		HX_STACK_LINE(97)
		this->layerRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicsContext_obj,dispose,(void))


GraphicsContext_obj::GraphicsContext_obj()
{
}

void GraphicsContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphicsContext);
	HX_MARK_MEMBER_NAME(_needsNativeLayerUpdate,"_needsNativeLayerUpdate");
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_MEMBER_NAME(layerRenderer,"layerRenderer");
	HX_MARK_MEMBER_NAME(nativeLayer,"nativeLayer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GraphicsContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_needsNativeLayerUpdate,"_needsNativeLayerUpdate");
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
	HX_VISIT_MEMBER_NAME(layerRenderer,"layerRenderer");
	HX_VISIT_MEMBER_NAME(nativeLayer,"nativeLayer");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic GraphicsContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"doDetach") ) { return doDetach_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttach") ) { return doAttach_dyn(); }
		if (HX_FIELD_EQ(inName,"graphics") ) { return graphics; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"nativeLayer") ) { return inCallProp ? get_nativeLayer() : nativeLayer; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"insertBefore") ) { return insertBefore_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { return layerRenderer; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_nativeLayer") ) { return get_nativeLayer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateNativeLayer") ) { return updateNativeLayer_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateGraphicsSize") ) { return updateGraphicsSize_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"invalidateBitmapSize") ) { return invalidateBitmapSize_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"invalidateNativeLayer") ) { return invalidateNativeLayer_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_needsNativeLayerUpdate") ) { return _needsNativeLayerUpdate; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"addedToGraphicsContextTree") ) { return addedToGraphicsContextTree_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"removedFromGraphicsContextTree") ) { return removedFromGraphicsContextTree_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GraphicsContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::cocktail::port::platform::flash_player::GraphicsContextImpl >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nativeLayer") ) { nativeLayer=inValue.Cast< ::neash::display::DisplayObjectContainer >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { layerRenderer=inValue.Cast< ::cocktail::core::layer::LayerRenderer >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_needsNativeLayerUpdate") ) { _needsNativeLayerUpdate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphicsContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_needsNativeLayerUpdate"));
	outFields->push(HX_CSTRING("graphics"));
	outFields->push(HX_CSTRING("layerRenderer"));
	outFields->push(HX_CSTRING("nativeLayer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_nativeLayer"),
	HX_CSTRING("doDetach"),
	HX_CSTRING("doAttach"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("invalidateBitmapSize"),
	HX_CSTRING("invalidateNativeLayer"),
	HX_CSTRING("updateNativeLayer"),
	HX_CSTRING("updateGraphicsSize"),
	HX_CSTRING("removedFromGraphicsContextTree"),
	HX_CSTRING("addedToGraphicsContextTree"),
	HX_CSTRING("insertBefore"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_needsNativeLayerUpdate"),
	HX_CSTRING("graphics"),
	HX_CSTRING("layerRenderer"),
	HX_CSTRING("nativeLayer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicsContext_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicsContext_obj::__mClass,"__mClass");
};

Class GraphicsContext_obj::__mClass;

void GraphicsContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.graphics.GraphicsContext"), hx::TCanCast< GraphicsContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void GraphicsContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace graphics
