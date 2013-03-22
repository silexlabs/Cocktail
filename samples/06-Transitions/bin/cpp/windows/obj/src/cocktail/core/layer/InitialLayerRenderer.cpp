#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_InitialGraphicsContext
#include <cocktail/core/graphics/InitialGraphicsContext.h>
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
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_stacking_StackingContext
#include <cocktail/core/stacking/StackingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace layer{

Void InitialLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("InitialLayerRenderer::new","cocktail/core/layer/InitialLayerRenderer.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

InitialLayerRenderer_obj::~InitialLayerRenderer_obj() { }

Dynamic InitialLayerRenderer_obj::__CreateEmpty() { return  new InitialLayerRenderer_obj; }
hx::ObjectPtr< InitialLayerRenderer_obj > InitialLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< InitialLayerRenderer_obj > result = new InitialLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic InitialLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialLayerRenderer_obj > result = new InitialLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool InitialLayerRenderer_obj::treatVisibleOverflowAsAuto( ){
	HX_STACK_PUSH("InitialLayerRenderer::treatVisibleOverflowAsAuto","cocktail/core/layer/InitialLayerRenderer.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_LINE(119)
	return true;
}


bool InitialLayerRenderer_obj::hasCompositingLayerSibling( ){
	HX_STACK_PUSH("InitialLayerRenderer::hasCompositingLayerSibling","cocktail/core/layer/InitialLayerRenderer.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_LINE(105)
	return false;
}


bool InitialLayerRenderer_obj::establishesNewStackingContext( ){
	HX_STACK_PUSH("InitialLayerRenderer::establishesNewStackingContext","cocktail/core/layer/InitialLayerRenderer.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_LINE(97)
	return true;
}


bool InitialLayerRenderer_obj::establishesNewGraphicsContext( ){
	HX_STACK_PUSH("InitialLayerRenderer::establishesNewGraphicsContext","cocktail/core/layer/InitialLayerRenderer.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_LINE(84)
	return true;
}


Void InitialLayerRenderer_obj::doDetachStackingContext( ){
{
		HX_STACK_PUSH("InitialLayerRenderer::doDetachStackingContext","cocktail/core/layer/InitialLayerRenderer.hx",71);
		HX_STACK_THIS(this);
		HX_STACK_LINE(72)
		this->stackingContext = null();
		HX_STACK_LINE(73)
		this->hasOwnStackingContext = false;
	}
return null();
}


Void InitialLayerRenderer_obj::doAttachStackingContext( ){
{
		HX_STACK_PUSH("InitialLayerRenderer::doAttachStackingContext","cocktail/core/layer/InitialLayerRenderer.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_LINE(63)
		this->stackingContext = ::cocktail::core::stacking::StackingContext_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(64)
		this->hasOwnStackingContext = true;
	}
return null();
}


Void InitialLayerRenderer_obj::doDetachGraphicsContext( ){
{
		HX_STACK_PUSH("InitialLayerRenderer::doDetachGraphicsContext","cocktail/core/layer/InitialLayerRenderer.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_LINE(51)
		this->graphicsContext->removedFromGraphicsContextTree();
		HX_STACK_LINE(52)
		this->graphicsContext->dispose();
		HX_STACK_LINE(53)
		this->hasOwnGraphicsContext = false;
		HX_STACK_LINE(54)
		this->graphicsContext = null();
	}
return null();
}


Void InitialLayerRenderer_obj::doAttachGraphicsContext( ){
{
		HX_STACK_PUSH("InitialLayerRenderer::doAttachGraphicsContext","cocktail/core/layer/InitialLayerRenderer.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		this->graphicsContext = ::cocktail::core::graphics::InitialGraphicsContext_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(43)
		this->hasOwnGraphicsContext = true;
	}
return null();
}



InitialLayerRenderer_obj::InitialLayerRenderer_obj()
{
}

void InitialLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InitialLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InitialLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 23:
		if (HX_FIELD_EQ(inName,"doDetachStackingContext") ) { return doDetachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttachStackingContext") ) { return doAttachStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doDetachGraphicsContext") ) { return doDetachGraphicsContext_dyn(); }
		if (HX_FIELD_EQ(inName,"doAttachGraphicsContext") ) { return doAttachGraphicsContext_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"treatVisibleOverflowAsAuto") ) { return treatVisibleOverflowAsAuto_dyn(); }
		if (HX_FIELD_EQ(inName,"hasCompositingLayerSibling") ) { return hasCompositingLayerSibling_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"establishesNewStackingContext") ) { return establishesNewStackingContext_dyn(); }
		if (HX_FIELD_EQ(inName,"establishesNewGraphicsContext") ) { return establishesNewGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InitialLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InitialLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("treatVisibleOverflowAsAuto"),
	HX_CSTRING("hasCompositingLayerSibling"),
	HX_CSTRING("establishesNewStackingContext"),
	HX_CSTRING("establishesNewGraphicsContext"),
	HX_CSTRING("doDetachStackingContext"),
	HX_CSTRING("doAttachStackingContext"),
	HX_CSTRING("doDetachGraphicsContext"),
	HX_CSTRING("doAttachGraphicsContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InitialLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InitialLayerRenderer_obj::__mClass,"__mClass");
};

Class InitialLayerRenderer_obj::__mClass;

void InitialLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.InitialLayerRenderer"), hx::TCanCast< InitialLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InitialLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
