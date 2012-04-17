#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
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
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Display
#include <cocktail/core/style/Display.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void LayerRenderer_obj::__construct(::cocktail::core::renderer::ElementRenderer rootRenderer)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",42)
	this->_rootRenderer = rootRenderer;
}
;
	return null();
}

LayerRenderer_obj::~LayerRenderer_obj() { }

Dynamic LayerRenderer_obj::__CreateEmpty() { return  new LayerRenderer_obj; }
hx::ObjectPtr< LayerRenderer_obj > LayerRenderer_obj::__new(::cocktail::core::renderer::ElementRenderer rootRenderer)
{  hx::ObjectPtr< LayerRenderer_obj > result = new LayerRenderer_obj();
	result->__construct(rootRenderer);
	return result;}

Dynamic LayerRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LayerRenderer_obj > result = new LayerRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void LayerRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("LayerRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",51)
		this->_rootRenderer = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,dispose,(void))

Dynamic LayerRenderer_obj::render( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",61)
	Dynamic nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",64)
	if (((bool((bool((this->_rootRenderer->canHaveChildren() == true)) && bool((this->_rootRenderer->getCoreStyle()->isInlineLevel() == false)))) || bool((this->_rootRenderer->getCoreStyle()->getDisplay() == ::cocktail::core::style::Display_obj::inlineBlock_dyn()))))){
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",68)
		Dynamic rootRendererBackground = this->_rootRenderer->renderBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",70)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",70)
			int _g1 = (int)0;
			int _g = rootRendererBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",70)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",70)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",72)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",75)
		Dynamic childrenBlockContainerBackground = this->renderChildrenBlockContainerBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",77)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",77)
			int _g1 = (int)0;
			int _g = childrenBlockContainerBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",77)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",77)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",79)
				nativeElements->__Field(HX_CSTRING("push"))(childrenBlockContainerBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",82)
		Dynamic inFlowChildren = this->renderInFlowChildren();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",84)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",84)
			int _g1 = (int)0;
			int _g = inFlowChildren->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",84)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",84)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",86)
				nativeElements->__Field(HX_CSTRING("push"))(inFlowChildren->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",90)
		Dynamic childLayers = this->renderChildLayer();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",92)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",92)
			int _g1 = (int)0;
			int _g = childLayers->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",92)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",92)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",94)
				nativeElements->__Field(HX_CSTRING("push"))(childLayers->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",98)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",98)
			int _g1 = (int)0;
			int _g = nativeElements->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",98)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",98)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",100)
				hx::AddEq(nativeElements->__GetItem(i)->__FieldRef(HX_CSTRING("x")),this->_rootRenderer->getBounds()->__Field(HX_CSTRING("x")));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",101)
				hx::AddEq(nativeElements->__GetItem(i)->__FieldRef(HX_CSTRING("y")),this->_rootRenderer->getBounds()->__Field(HX_CSTRING("y")));
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",113)
		Dynamic rootRendererBackground = this->_rootRenderer->renderBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",115)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",115)
			int _g1 = (int)0;
			int _g = rootRendererBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",115)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",115)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",117)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",120)
		Dynamic rootRendererElements = this->_rootRenderer->render();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",122)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",122)
			int _g1 = (int)0;
			int _g = rootRendererElements->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",122)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",122)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",124)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererElements->__GetItem(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",129)
	return nativeElements;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,render,return )

Dynamic LayerRenderer_obj::renderChildrenBlockContainerBackground( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderChildrenBlockContainerBackground")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",142)
	Array< ::cocktail::core::renderer::ElementRenderer > childrenBlockContainer = this->getBlockContainerChildren(this->_rootRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",144)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",146)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",146)
		int _g1 = (int)0;
		int _g = childrenBlockContainer->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",146)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",146)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",149)
			Dynamic nativeElements = childrenBlockContainer->__get(i)->renderBackground();
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",151)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",151)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",151)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",151)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",153)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",157)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderChildrenBlockContainerBackground,return )

Array< ::cocktail::core::renderer::ElementRenderer > LayerRenderer_obj::getBlockContainerChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getBlockContainerChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",169)
	Array< ::cocktail::core::renderer::ElementRenderer > ret = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",171)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",171)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",171)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",171)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",173)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",175)
			if (((child->getLayerRenderer() == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",176)
				if (((child->canHaveChildren() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",179)
					Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getBlockContainerChildren(child);
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",180)
					{
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",180)
						int _g3 = (int)0;
						int _g2 = childElementRenderer->length;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",180)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",180)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",182)
							ret->push(childElementRenderer->__get(j));
						}
					}
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",184)
					ret->push(child);
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",188)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getBlockContainerChildren,return )

Dynamic LayerRenderer_obj::renderChildLayer( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderChildLayer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",197)
	Array< ::cocktail::core::renderer::LayerRenderer > childLayers = this->getChildLayers(this->_rootRenderer,hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",200)
	childLayers->reverse();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",202)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",204)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",204)
		int _g1 = (int)0;
		int _g = childLayers->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",204)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",204)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",206)
			Dynamic nativeElements = childLayers->__get(i)->render();
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",207)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",207)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",207)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",207)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",209)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",213)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderChildLayer,return )

Array< ::cocktail::core::renderer::LayerRenderer > LayerRenderer_obj::getChildLayers( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer,::cocktail::core::renderer::LayerRenderer referenceLayer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getChildLayers")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",222)
	Array< ::cocktail::core::renderer::LayerRenderer > childLayers = Array_obj< ::cocktail::core::renderer::LayerRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",225)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",225)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",225)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",225)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",227)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",230)
			if (((child->getLayerRenderer() == referenceLayer))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",231)
				if (((bool((child->canHaveChildren() == true)) && bool((child->getCoreStyle()->getDisplay() != ::cocktail::core::style::Display_obj::inlineBlock_dyn()))))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",235)
					Array< ::cocktail::core::renderer::LayerRenderer > childElementRenderer = this->getChildLayers(child,referenceLayer);
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",236)
					{
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",236)
						int _g3 = (int)0;
						int _g2 = childElementRenderer->length;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",236)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",236)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",238)
							childLayers->push(childElementRenderer->__get(j));
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",244)
				childLayers->push(child->getLayerRenderer());
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",249)
	return childLayers;
}


HX_DEFINE_DYNAMIC_FUNC2(LayerRenderer_obj,getChildLayers,return )

Dynamic LayerRenderer_obj::renderInFlowChildren( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderInFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",259)
	Array< ::cocktail::core::renderer::ElementRenderer > inFlowChildren = this->getInFlowChildren(this->_rootRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",261)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",263)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",263)
		int _g1 = (int)0;
		int _g = inFlowChildren->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",263)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",263)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",265)
			Dynamic nativeElements = Dynamic( Array_obj<Dynamic>::__new());
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",266)
			if (((inFlowChildren->__get(i)->getCoreStyle()->getDisplay() == ::cocktail::core::style::Display_obj::inlineBlock_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",271)
				Array< ::cocktail::core::renderer::LayerRenderer > d = this->getChildLayers(inFlowChildren->__get(i),hx::ObjectPtr<OBJ_>(this));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",273)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",273)
					int _g3 = (int)0;
					int _g2 = d->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",273)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",273)
						int l = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",275)
						Dynamic ne = d->__get(l)->render();
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",276)
						{
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",276)
							int _g5 = (int)0;
							int _g4 = ne->__Field(HX_CSTRING("length"));
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",276)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",276)
								int m = (_g5)++;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",279)
								hx::AddEq(ne->__GetItem(m)->__FieldRef(HX_CSTRING("x")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("x")));
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",280)
								hx::AddEq(ne->__GetItem(m)->__FieldRef(HX_CSTRING("y")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("y")));
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",283)
								nativeElements->__Field(HX_CSTRING("push"))(ne->__GetItem(m));
							}
						}
					}
				}
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",288)
				Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getInFlowChildren(inFlowChildren->__get(i));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",289)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",289)
					int _g3 = (int)0;
					int _g2 = childElementRenderer->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",289)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",289)
						int l = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",291)
						hx::AddEq(childElementRenderer->__get(l)->getBounds()->__FieldRef(HX_CSTRING("x")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("x")));
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",292)
						hx::AddEq(childElementRenderer->__get(l)->getBounds()->__FieldRef(HX_CSTRING("y")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("y")));
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",294)
						Dynamic el = childElementRenderer->__get(l)->render();
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",296)
						{
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",296)
							int _g5 = (int)0;
							int _g4 = el->__Field(HX_CSTRING("length"));
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",296)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",296)
								int k = (_g5)++;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",298)
								nativeElements->__Field(HX_CSTRING("push"))(el->__GetItem(k));
							}
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",305)
				nativeElements = inFlowChildren->__get(i)->render();
			}
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",309)
			if (((bool((inFlowChildren->__get(i)->canHaveChildren() == false)) && bool((inFlowChildren->__get(i)->isText() == false))))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",312)
				Dynamic bg = inFlowChildren->__get(i)->renderBackground();
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",314)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",314)
					int _g3 = (int)0;
					int _g2 = bg->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",314)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",314)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",316)
						ret->__Field(HX_CSTRING("push"))(bg->__GetItem(j));
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",320)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",320)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",320)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",320)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",322)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",328)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderInFlowChildren,return )

Array< ::cocktail::core::renderer::ElementRenderer > LayerRenderer_obj::getInFlowChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getInFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",338)
	Array< ::cocktail::core::renderer::ElementRenderer > ret = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",340)
	if (((bool((rootRenderer->establishesNewFormattingContext() == true)) && bool((rootRenderer->getCoreStyle()->childrenInline() == true))))){
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",343)
		::cocktail::core::renderer::BlockBoxRenderer blockBoxRenderer = rootRenderer;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",345)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",345)
			int _g1 = (int)0;
			int _g = blockBoxRenderer->getLineBoxes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",345)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",345)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",347)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",347)
					int _g3 = (int)0;
					int _g2 = blockBoxRenderer->getLineBoxes()->__get(i)->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",347)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",347)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",349)
						if (((bool((blockBoxRenderer->getLineBoxes()->__get(i)->__get(j)->isPositioned() == false)) && bool((blockBoxRenderer->getLineBoxes()->__get(i)->__get(j)->isDisplayed() == true))))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",350)
							ret->push(blockBoxRenderer->getLineBoxes()->__get(i)->__get(j));
						}
					}
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",359)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",359)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",359)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",361)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",363)
			if (((child->isDisplayed() == true))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",364)
				if (((child->getLayerRenderer() == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",366)
					if (((child->isPositioned() == false))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",369)
						ret->push(child);
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",370)
						if (((child->canHaveChildren() == true))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",372)
							Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getInFlowChildren(child);
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",373)
							{
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",373)
								int _g3 = (int)0;
								int _g2 = childElementRenderer->length;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",373)
								while(((_g3 < _g2))){
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",373)
									int j = (_g3)++;
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",375)
									if (((child->establishesNewFormattingContext() == true))){
										HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",377)
										hx::AddEq(childElementRenderer->__get(j)->getBounds()->__FieldRef(HX_CSTRING("x")),child->getBounds()->__Field(HX_CSTRING("x")));
										HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",378)
										hx::AddEq(childElementRenderer->__get(j)->getBounds()->__FieldRef(HX_CSTRING("y")),child->getBounds()->__Field(HX_CSTRING("y")));
									}
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",381)
									ret->push(childElementRenderer->__get(j));
								}
							}
						}
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",391)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getInFlowChildren,return )

Void LayerRenderer_obj::setNativeMatrix( ::cocktail::core::geom::Matrix matrix){
{
		HX_SOURCE_PUSH("LayerRenderer_obj::setNativeMatrix")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,setNativeMatrix,(void))

::cocktail::core::geom::Matrix LayerRenderer_obj::getConcatenatedMatrix( ::cocktail::core::geom::Matrix matrix){
	HX_SOURCE_PUSH("LayerRenderer_obj::getConcatenatedMatrix")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",431)
	::cocktail::core::geom::Matrix currentMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",440)
	return currentMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getConcatenatedMatrix,return )

::cocktail::core::geom::Matrix LayerRenderer_obj::getConcatenatedMatrix2( ::cocktail::core::geom::Matrix matrix){
	HX_SOURCE_PUSH("LayerRenderer_obj::getConcatenatedMatrix2")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",453)
	::cocktail::core::geom::Matrix currentMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",456)
	return currentMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getConcatenatedMatrix2,return )


LayerRenderer_obj::LayerRenderer_obj()
{
}

void LayerRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LayerRenderer);
	HX_MARK_MEMBER_NAME(_rootRenderer,"_rootRenderer");
	HX_MARK_END_CLASS();
}

Dynamic LayerRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_rootRenderer") ) { return _rootRenderer; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getChildLayers") ) { return getChildLayers_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setNativeMatrix") ) { return setNativeMatrix_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"renderChildLayer") ) { return renderChildLayer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getInFlowChildren") ) { return getInFlowChildren_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"renderInFlowChildren") ) { return renderInFlowChildren_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getConcatenatedMatrix") ) { return getConcatenatedMatrix_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getConcatenatedMatrix2") ) { return getConcatenatedMatrix2_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getBlockContainerChildren") ) { return getBlockContainerChildren_dyn(); }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"renderChildrenBlockContainerBackground") ) { return renderChildrenBlockContainerBackground_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic LayerRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"_rootRenderer") ) { _rootRenderer=inValue.Cast< ::cocktail::core::renderer::ElementRenderer >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void LayerRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_rootRenderer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_rootRenderer"),
	HX_CSTRING("dispose"),
	HX_CSTRING("render"),
	HX_CSTRING("renderChildrenBlockContainerBackground"),
	HX_CSTRING("getBlockContainerChildren"),
	HX_CSTRING("renderChildLayer"),
	HX_CSTRING("getChildLayers"),
	HX_CSTRING("renderInFlowChildren"),
	HX_CSTRING("getInFlowChildren"),
	HX_CSTRING("setNativeMatrix"),
	HX_CSTRING("getConcatenatedMatrix"),
	HX_CSTRING("getConcatenatedMatrix2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class LayerRenderer_obj::__mClass;

void LayerRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.LayerRenderer"), hx::TCanCast< LayerRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void LayerRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
