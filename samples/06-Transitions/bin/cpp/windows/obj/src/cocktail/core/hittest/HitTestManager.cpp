#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_hittest_HitTestManager
#include <cocktail/core/hittest/HitTestManager.h>
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
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace hittest{

Void HitTestManager_obj::__construct()
{
HX_STACK_PUSH("HitTestManager::new","cocktail/core/hittest/HitTestManager.hx",49);
{
	HX_STACK_LINE(50)
	this->_targetPoint = ::cocktail::core::geom::PointVO_obj::__new(0.0,0.0);
	HX_STACK_LINE(51)
	this->_elementRenderersAtPoint = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
}
;
	return null();
}

HitTestManager_obj::~HitTestManager_obj() { }

Dynamic HitTestManager_obj::__CreateEmpty() { return  new HitTestManager_obj; }
hx::ObjectPtr< HitTestManager_obj > HitTestManager_obj::__new()
{  hx::ObjectPtr< HitTestManager_obj > result = new HitTestManager_obj();
	result->__construct();
	return result;}

Dynamic HitTestManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HitTestManager_obj > result = new HitTestManager_obj();
	result->__construct();
	return result;}

bool HitTestManager_obj::isWithinBounds( ::cocktail::core::geom::PointVO point,::cocktail::core::geom::RectangleVO bounds){
	HX_STACK_PUSH("HitTestManager::isWithinBounds","cocktail/core/hittest/HitTestManager.hx",180);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_ARG(bounds,"bounds");
	HX_STACK_LINE(180)
	return (bool((bool((bool((point->x >= bounds->x)) && bool((point->x <= (bounds->x + bounds->width))))) && bool((point->y >= bounds->y)))) && bool((point->y <= (bounds->y + bounds->height))));
}


HX_DEFINE_DYNAMIC_FUNC2(HitTestManager_obj,isWithinBounds,return )

Void HitTestManager_obj::hitTestElementRenderer( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::PointVO point){
{
		HX_STACK_PUSH("HitTestManager::hitTestElementRenderer","cocktail/core/hittest/HitTestManager.hx",163);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderersAtPoint,"elementRenderersAtPoint");
		HX_STACK_ARG(elementRenderer,"elementRenderer");
		HX_STACK_ARG(point,"point");
		struct _Function_1_1{
			inline static bool Block( ::cocktail::core::renderer::ElementRenderer &elementRenderer,::cocktail::core::geom::PointVO &point){
				HX_STACK_PUSH("*::closure","cocktail/core/hittest/HitTestManager.hx",164);
				{
					HX_STACK_LINE(164)
					::cocktail::core::geom::RectangleVO bounds = elementRenderer->hitTestingBounds;		HX_STACK_VAR(bounds,"bounds");
					HX_STACK_LINE(164)
					return (bool((bool((bool((point->x >= bounds->x)) && bool((point->x <= (bounds->x + bounds->width))))) && bool((point->y >= bounds->y)))) && bool((point->y <= (bounds->y + bounds->height))));
				}
				return null();
			}
		};
		HX_STACK_LINE(163)
		if (((_Function_1_1::Block(elementRenderer,point) == true))){
			HX_STACK_LINE(165)
			if (((elementRenderer->isVisible() == true))){
				HX_STACK_LINE(169)
				elementRenderersAtPoint->push(elementRenderer);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(HitTestManager_obj,hitTestElementRenderer,(void))

Void HitTestManager_obj::getElementRenderersAtPointInLayer( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::layer::LayerRenderer layer,::cocktail::core::renderer::ElementRenderer renderer,::cocktail::core::geom::PointVO point){
{
		HX_STACK_PUSH("HitTestManager::getElementRenderersAtPointInLayer","cocktail/core/hittest/HitTestManager.hx",133);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderersAtPoint,"elementRenderersAtPoint");
		HX_STACK_ARG(layer,"layer");
		HX_STACK_ARG(renderer,"renderer");
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(135)
		this->hitTestElementRenderer(elementRenderersAtPoint,renderer,point);
		HX_STACK_LINE(137)
		::cocktail::core::renderer::ElementRenderer child = renderer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(139)
		while(((child != null()))){
			HX_STACK_LINE(141)
			if (((child->layerRenderer == layer))){
				HX_STACK_LINE(142)
				if (((child->firstChild != null()))){
					HX_STACK_LINE(145)
					this->getElementRenderersAtPointInLayer(elementRenderersAtPoint,layer,child,point);
				}
				else{
					HX_STACK_LINE(149)
					this->hitTestElementRenderer(elementRenderersAtPoint,child,point);
				}
			}
			HX_STACK_LINE(154)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(HitTestManager_obj,getElementRenderersAtPointInLayer,(void))

Void HitTestManager_obj::getElementRenderersAtPointInLayers( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::layer::LayerRenderer layer,::cocktail::core::geom::PointVO point){
{
		HX_STACK_PUSH("HitTestManager::getElementRenderersAtPointInLayers","cocktail/core/hittest/HitTestManager.hx",112);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderersAtPoint,"elementRenderersAtPoint");
		HX_STACK_ARG(layer,"layer");
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(113)
		this->getElementRenderersAtPointInLayer(elementRenderersAtPoint,layer,layer->rootElementRenderer,point);
		HX_STACK_LINE(115)
		::cocktail::core::layer::LayerRenderer child = layer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(116)
		while(((child != null()))){
			HX_STACK_LINE(118)
			if (((child->hasOwnStackingContext == false))){
				HX_STACK_LINE(119)
				this->getElementRenderersAtPointInLayers(elementRenderersAtPoint,child,point);
			}
			HX_STACK_LINE(123)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(HitTestManager_obj,getElementRenderersAtPointInLayers,(void))

Void HitTestManager_obj::getElementRenderersAtPointInStackingContext( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::stacking::StackingContext stackingContext,::cocktail::core::geom::PointVO point){
{
		HX_STACK_PUSH("HitTestManager::getElementRenderersAtPointInStackingContext","cocktail/core/hittest/HitTestManager.hx",93);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elementRenderersAtPoint,"elementRenderersAtPoint");
		HX_STACK_ARG(stackingContext,"stackingContext");
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(94)
		this->getElementRenderersAtPointInLayers(elementRenderersAtPoint,stackingContext->layerRenderer,point);
		HX_STACK_LINE(96)
		::cocktail::core::stacking::StackingContext child = stackingContext->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(97)
		while(((child != null()))){
			HX_STACK_LINE(99)
			this->getElementRenderersAtPointInStackingContext(elementRenderersAtPoint,child,point);
			HX_STACK_LINE(100)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(HitTestManager_obj,getElementRenderersAtPointInStackingContext,(void))

::cocktail::core::renderer::ElementRenderer HitTestManager_obj::getTopMostElementRendererAtPoint( ::cocktail::core::stacking::StackingContext stackingContext,Float x,Float y){
	HX_STACK_PUSH("HitTestManager::getTopMostElementRendererAtPoint","cocktail/core/hittest/HitTestManager.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_ARG(stackingContext,"stackingContext");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(72)
	this->_targetPoint->x = x;
	HX_STACK_LINE(73)
	this->_targetPoint->y = y;
	HX_STACK_LINE(75)
	this->_elementRenderersAtPoint = ::cocktail::core::utils::Utils_obj::clear(this->_elementRenderersAtPoint);
	HX_STACK_LINE(78)
	this->getElementRenderersAtPointInStackingContext(this->_elementRenderersAtPoint,stackingContext,this->_targetPoint);
	HX_STACK_LINE(80)
	return this->_elementRenderersAtPoint->__get((this->_elementRenderersAtPoint->length - (int)1));
}


HX_DEFINE_DYNAMIC_FUNC3(HitTestManager_obj,getTopMostElementRendererAtPoint,return )


HitTestManager_obj::HitTestManager_obj()
{
}

void HitTestManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HitTestManager);
	HX_MARK_MEMBER_NAME(_targetPoint,"_targetPoint");
	HX_MARK_MEMBER_NAME(_elementRenderersAtPoint,"_elementRenderersAtPoint");
	HX_MARK_END_CLASS();
}

void HitTestManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_targetPoint,"_targetPoint");
	HX_VISIT_MEMBER_NAME(_elementRenderersAtPoint,"_elementRenderersAtPoint");
}

Dynamic HitTestManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_targetPoint") ) { return _targetPoint; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isWithinBounds") ) { return isWithinBounds_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"hitTestElementRenderer") ) { return hitTestElementRenderer_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_elementRenderersAtPoint") ) { return _elementRenderersAtPoint; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"getTopMostElementRendererAtPoint") ) { return getTopMostElementRendererAtPoint_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"getElementRenderersAtPointInLayer") ) { return getElementRenderersAtPointInLayer_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"getElementRenderersAtPointInLayers") ) { return getElementRenderersAtPointInLayers_dyn(); }
		break;
	case 43:
		if (HX_FIELD_EQ(inName,"getElementRenderersAtPointInStackingContext") ) { return getElementRenderersAtPointInStackingContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HitTestManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_targetPoint") ) { _targetPoint=inValue.Cast< ::cocktail::core::geom::PointVO >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"_elementRenderersAtPoint") ) { _elementRenderersAtPoint=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HitTestManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_targetPoint"));
	outFields->push(HX_CSTRING("_elementRenderersAtPoint"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isWithinBounds"),
	HX_CSTRING("hitTestElementRenderer"),
	HX_CSTRING("getElementRenderersAtPointInLayer"),
	HX_CSTRING("getElementRenderersAtPointInLayers"),
	HX_CSTRING("getElementRenderersAtPointInStackingContext"),
	HX_CSTRING("getTopMostElementRendererAtPoint"),
	HX_CSTRING("_targetPoint"),
	HX_CSTRING("_elementRenderersAtPoint"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HitTestManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HitTestManager_obj::__mClass,"__mClass");
};

Class HitTestManager_obj::__mClass;

void HitTestManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.hittest.HitTestManager"), hx::TCanCast< HitTestManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HitTestManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace hittest
