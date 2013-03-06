#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
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
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_InitialLayerRenderer
#include <cocktail/core/layer/InitialLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_ContainingBlockVO
#include <cocktail/core/layout/ContainingBlockVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InitialBlockRenderer
#include <cocktail/core/renderer/InitialBlockRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InitialBlockRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("InitialBlockRenderer::new","cocktail/core/renderer/InitialBlockRenderer.hx",37);
{
	HX_STACK_LINE(38)
	super::__construct(node);
	HX_STACK_LINE(47)
	this->containingBlock = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

InitialBlockRenderer_obj::~InitialBlockRenderer_obj() { }

Dynamic InitialBlockRenderer_obj::__CreateEmpty() { return  new InitialBlockRenderer_obj; }
hx::ObjectPtr< InitialBlockRenderer_obj > InitialBlockRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic InitialBlockRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialBlockRenderer_obj > result = new InitialBlockRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::cocktail::core::renderer::FlowBoxRenderer InitialBlockRenderer_obj::getContainingBlock( ){
	HX_STACK_PUSH("InitialBlockRenderer::getContainingBlock","cocktail/core/renderer/InitialBlockRenderer.hx",191);
	HX_STACK_THIS(this);
	HX_STACK_LINE(191)
	return hx::ObjectPtr<OBJ_>(this);
}


::cocktail::core::layout::ContainingBlockVO InitialBlockRenderer_obj::getContainerBlockData( ){
	HX_STACK_PUSH("InitialBlockRenderer::getContainerBlockData","cocktail/core/renderer/InitialBlockRenderer.hx",182);
	HX_STACK_THIS(this);
	HX_STACK_LINE(182)
	return this->getWindowData();
}


bool InitialBlockRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("InitialBlockRenderer::createOwnLayer","cocktail/core/renderer/InitialBlockRenderer.hx",169);
	HX_STACK_THIS(this);
	HX_STACK_LINE(169)
	return true;
}


bool InitialBlockRenderer_obj::establishesNewBlockFormattingContext( ){
	HX_STACK_PUSH("InitialBlockRenderer::establishesNewBlockFormattingContext","cocktail/core/renderer/InitialBlockRenderer.hx",159);
	HX_STACK_THIS(this);
	HX_STACK_LINE(159)
	return true;
}


bool InitialBlockRenderer_obj::isPositioned( ){
	HX_STACK_PUSH("InitialBlockRenderer::isPositioned","cocktail/core/renderer/InitialBlockRenderer.hx",150);
	HX_STACK_THIS(this);
	HX_STACK_LINE(150)
	return true;
}


Void InitialBlockRenderer_obj::applyShrinkToFitIfNeeded( ::cocktail::core::layout::LayoutStateValue layoutState){
{
		HX_STACK_PUSH("InitialBlockRenderer::applyShrinkToFitIfNeeded","cocktail/core/renderer/InitialBlockRenderer.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_ARG(layoutState,"layoutState");
	}
return null();
}


Void InitialBlockRenderer_obj::layoutSelfIfNeeded( bool forceLayout){
{
		HX_STACK_PUSH("InitialBlockRenderer::layoutSelfIfNeeded","cocktail/core/renderer/InitialBlockRenderer.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_ARG(forceLayout,"forceLayout");
		HX_STACK_LINE(115)
		::cocktail::core::layout::ContainingBlockVO viewportData = this->getWindowData();		HX_STACK_VAR(viewportData,"viewportData");
		HX_STACK_LINE(117)
		this->coreStyle->usedValues->width = viewportData->width;
		HX_STACK_LINE(118)
		this->coreStyle->usedValues->height = viewportData->height;
		HX_STACK_LINE(120)
		this->bounds->x = (int)0;
		HX_STACK_LINE(121)
		this->bounds->y = (int)0;
		HX_STACK_LINE(122)
		this->bounds->width = viewportData->width;
		HX_STACK_LINE(123)
		this->bounds->height = viewportData->height;
		HX_STACK_LINE(124)
		this->globalBounds->x = (int)0;
		HX_STACK_LINE(125)
		this->globalBounds->y = (int)0;
		HX_STACK_LINE(126)
		this->globalBounds->width = viewportData->width;
		HX_STACK_LINE(127)
		this->globalBounds->height = viewportData->height;
	}
return null();
}


Void InitialBlockRenderer_obj::invalidateContainingBlock( int styleIndex){
{
		HX_STACK_PUSH("InitialBlockRenderer::invalidateContainingBlock","cocktail/core/renderer/InitialBlockRenderer.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
	}
return null();
}


Void InitialBlockRenderer_obj::unregisterWithContainingBlock( ){
{
		HX_STACK_PUSH("InitialBlockRenderer::unregisterWithContainingBlock","cocktail/core/renderer/InitialBlockRenderer.hx",88);
		HX_STACK_THIS(this);
	}
return null();
}


Void InitialBlockRenderer_obj::registerWithContaininingBlock( ){
{
		HX_STACK_PUSH("InitialBlockRenderer::registerWithContaininingBlock","cocktail/core/renderer/InitialBlockRenderer.hx",80);
		HX_STACK_THIS(this);
	}
return null();
}


Void InitialBlockRenderer_obj::detachLayer( ){
{
		HX_STACK_PUSH("InitialBlockRenderer::detachLayer","cocktail/core/renderer/InitialBlockRenderer.hx",68);
		HX_STACK_THIS(this);
		HX_STACK_LINE(69)
		this->layerRenderer->removedFromLayerTree();
		HX_STACK_LINE(70)
		this->_hasOwnLayer = false;
		HX_STACK_LINE(71)
		this->layerRenderer->dispose();
		HX_STACK_LINE(72)
		this->layerRenderer = null();
	}
return null();
}


Void InitialBlockRenderer_obj::attachLayer( ){
{
		HX_STACK_PUSH("InitialBlockRenderer::attachLayer","cocktail/core/renderer/InitialBlockRenderer.hx",59);
		HX_STACK_THIS(this);
		HX_STACK_LINE(60)
		this->layerRenderer = ::cocktail::core::layer::InitialLayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(61)
		this->_hasOwnLayer = true;
	}
return null();
}



InitialBlockRenderer_obj::InitialBlockRenderer_obj()
{
}

void InitialBlockRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialBlockRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InitialBlockRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InitialBlockRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"detachLayer") ) { return detachLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"attachLayer") ) { return attachLayer_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getContainingBlock") ) { return getContainingBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"layoutSelfIfNeeded") ) { return layoutSelfIfNeeded_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getContainerBlockData") ) { return getContainerBlockData_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"applyShrinkToFitIfNeeded") ) { return applyShrinkToFitIfNeeded_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"invalidateContainingBlock") ) { return invalidateContainingBlock_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"unregisterWithContainingBlock") ) { return unregisterWithContainingBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"registerWithContaininingBlock") ) { return registerWithContaininingBlock_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"establishesNewBlockFormattingContext") ) { return establishesNewBlockFormattingContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InitialBlockRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InitialBlockRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getContainingBlock"),
	HX_CSTRING("getContainerBlockData"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("establishesNewBlockFormattingContext"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("applyShrinkToFitIfNeeded"),
	HX_CSTRING("layoutSelfIfNeeded"),
	HX_CSTRING("invalidateContainingBlock"),
	HX_CSTRING("unregisterWithContainingBlock"),
	HX_CSTRING("registerWithContaininingBlock"),
	HX_CSTRING("detachLayer"),
	HX_CSTRING("attachLayer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InitialBlockRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InitialBlockRenderer_obj::__mClass,"__mClass");
};

Class InitialBlockRenderer_obj::__mClass;

void InitialBlockRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InitialBlockRenderer"), hx::TCanCast< InitialBlockRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InitialBlockRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
