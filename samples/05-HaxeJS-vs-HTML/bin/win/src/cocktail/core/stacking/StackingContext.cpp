#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
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
namespace cocktail{
namespace core{
namespace stacking{

Void StackingContext_obj::__construct(::cocktail::core::layer::LayerRenderer layerRenderer)
{
HX_STACK_PUSH("StackingContext::new","cocktail/core/stacking/StackingContext.hx",54);
{
	HX_STACK_LINE(55)
	super::__construct();
	HX_STACK_LINE(56)
	this->layerRenderer = layerRenderer;
}
;
	return null();
}

StackingContext_obj::~StackingContext_obj() { }

Dynamic StackingContext_obj::__CreateEmpty() { return  new StackingContext_obj; }
hx::ObjectPtr< StackingContext_obj > StackingContext_obj::__new(::cocktail::core::layer::LayerRenderer layerRenderer)
{  hx::ObjectPtr< StackingContext_obj > result = new StackingContext_obj();
	result->__construct(layerRenderer);
	return result;}

Dynamic StackingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StackingContext_obj > result = new StackingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void StackingContext_obj::renderChildrenInSameStackingContext( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::geom::RectangleVO dirtyRect){
{
		HX_STACK_PUSH("StackingContext::renderChildrenInSameStackingContext","cocktail/core/stacking/StackingContext.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rootLayer,"rootLayer");
		HX_STACK_ARG(dirtyRect,"dirtyRect");
		HX_STACK_LINE(137)
		::cocktail::core::layer::LayerRenderer child = rootLayer->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(138)
		while(((child != null()))){
			HX_STACK_LINE(140)
			if (((child->hasOwnStackingContext == false))){
				HX_STACK_LINE(142)
				child->render(dirtyRect);
				HX_STACK_LINE(145)
				this->renderChildrenInSameStackingContext(child,dirtyRect);
			}
			else{
				HX_STACK_LINE(148)
				{
					::cocktail::core::css::CSSPropertyValue _switch_1 = (child->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
					switch((_switch_1)->GetIndex()){
						case 0: {
							int value = _switch_1->__Param(0);
{
								HX_STACK_LINE(151)
								if (((value == (int)0))){
									HX_STACK_LINE(153)
									child->stackingContext->render(dirtyRect);
								}
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			HX_STACK_LINE(163)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StackingContext_obj,renderChildrenInSameStackingContext,(void))

Void StackingContext_obj::render( ::cocktail::core::geom::RectangleVO dirtyRect){
{
		HX_STACK_PUSH("StackingContext::render","cocktail/core/stacking/StackingContext.hx",78);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dirtyRect,"dirtyRect");
		HX_STACK_LINE(79)
		this->layerRenderer->render(dirtyRect);
		HX_STACK_LINE(81)
		::cocktail::core::stacking::StackingContext child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(85)
		bool hasRenderedAutoAndZeroLayers = false;		HX_STACK_VAR(hasRenderedAutoAndZeroLayers,"hasRenderedAutoAndZeroLayers");
		HX_STACK_LINE(87)
		while(((child != null()))){
			HX_STACK_LINE(91)
			{
				::cocktail::core::css::CSSPropertyValue _switch_2 = (child->layerRenderer->rootElementRenderer->coreStyle->getComputedOrInitialProperty((int)4));
				switch((_switch_2)->GetIndex()){
					case 0: {
						int value = _switch_2->__Param(0);
{
							HX_STACK_LINE(93)
							if (((value == (int)0))){
							}
							else{
								HX_STACK_LINE(106)
								if (((bool((value > (int)0)) && bool((hasRenderedAutoAndZeroLayers == false))))){
									HX_STACK_LINE(108)
									this->renderChildrenInSameStackingContext(this->layerRenderer,dirtyRect);
									HX_STACK_LINE(109)
									hasRenderedAutoAndZeroLayers = true;
								}
								HX_STACK_LINE(112)
								child->render(dirtyRect);
							}
						}
					}
					;break;
					default: {
					}
				}
			}
			HX_STACK_LINE(118)
			child = child->nextSibling;
		}
		HX_STACK_LINE(124)
		if (((hasRenderedAutoAndZeroLayers == false))){
			HX_STACK_LINE(125)
			this->renderChildrenInSameStackingContext(this->layerRenderer,dirtyRect);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StackingContext_obj,render,(void))


StackingContext_obj::StackingContext_obj()
{
}

void StackingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StackingContext);
	HX_MARK_MEMBER_NAME(layerRenderer,"layerRenderer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void StackingContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(layerRenderer,"layerRenderer");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic StackingContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { return layerRenderer; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"renderChildrenInSameStackingContext") ) { return renderChildrenInSameStackingContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StackingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"layerRenderer") ) { layerRenderer=inValue.Cast< ::cocktail::core::layer::LayerRenderer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StackingContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("layerRenderer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderChildrenInSameStackingContext"),
	HX_CSTRING("render"),
	HX_CSTRING("layerRenderer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StackingContext_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StackingContext_obj::__mClass,"__mClass");
};

Class StackingContext_obj::__mClass;

void StackingContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.stacking.StackingContext"), hx::TCanCast< StackingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StackingContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace stacking
