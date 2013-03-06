#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_CompositingLayerRenderer
#include <cocktail/core/layer/CompositingLayerRenderer.h>
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
namespace cocktail{
namespace core{
namespace layer{

Void CompositingLayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{
HX_STACK_PUSH("CompositingLayerRenderer::new","cocktail/core/layer/CompositingLayerRenderer.hx",30);
{
	HX_STACK_LINE(30)
	super::__construct(rootElementRenderer);
}
;
	return null();
}

CompositingLayerRenderer_obj::~CompositingLayerRenderer_obj() { }

Dynamic CompositingLayerRenderer_obj::__CreateEmpty() { return  new CompositingLayerRenderer_obj; }
hx::ObjectPtr< CompositingLayerRenderer_obj > CompositingLayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootElementRenderer)
{  hx::ObjectPtr< CompositingLayerRenderer_obj > result = new CompositingLayerRenderer_obj();
	result->__construct(rootElementRenderer);
	return result;}

Dynamic CompositingLayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CompositingLayerRenderer_obj > result = new CompositingLayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

bool CompositingLayerRenderer_obj::isCompositingLayer( ){
	HX_STACK_PUSH("CompositingLayerRenderer::isCompositingLayer","cocktail/core/layer/CompositingLayerRenderer.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_LINE(62)
	return true;
}


bool CompositingLayerRenderer_obj::establishesNewGraphicsContext( ){
	HX_STACK_PUSH("CompositingLayerRenderer::establishesNewGraphicsContext","cocktail/core/layer/CompositingLayerRenderer.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	if (((::cocktail::core::config::Config_obj::getInstance()->enableCompositing == true))){
		HX_STACK_LINE(44)
		if (((this->isCompositingLayer() == true))){
			HX_STACK_LINE(46)
			return true;
		}
		else{
			HX_STACK_LINE(50)
			return this->super::establishesNewGraphicsContext();
		}
	}
	HX_STACK_LINE(54)
	return false;
}



CompositingLayerRenderer_obj::CompositingLayerRenderer_obj()
{
}

void CompositingLayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CompositingLayerRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CompositingLayerRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CompositingLayerRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"isCompositingLayer") ) { return isCompositingLayer_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"establishesNewGraphicsContext") ) { return establishesNewGraphicsContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CompositingLayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CompositingLayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isCompositingLayer"),
	HX_CSTRING("establishesNewGraphicsContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CompositingLayerRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CompositingLayerRenderer_obj::__mClass,"__mClass");
};

Class CompositingLayerRenderer_obj::__mClass;

void CompositingLayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layer.CompositingLayerRenderer"), hx::TCanCast< CompositingLayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CompositingLayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layer
