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
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",67)
		Dynamic rootRendererBackground = this->_rootRenderer->renderBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",69)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",69)
			int _g1 = (int)0;
			int _g = rootRendererBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",69)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",69)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",71)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",74)
		Dynamic childrenBlockContainerBackground = this->renderChildrenBlockContainerBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",76)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",76)
			int _g1 = (int)0;
			int _g = childrenBlockContainerBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",76)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",76)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",78)
				nativeElements->__Field(HX_CSTRING("push"))(childrenBlockContainerBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",81)
		Dynamic inFlowChildren = this->renderInFlowChildren();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",83)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",83)
			int _g1 = (int)0;
			int _g = inFlowChildren->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",83)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",83)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",85)
				nativeElements->__Field(HX_CSTRING("push"))(inFlowChildren->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",89)
		Dynamic childLayers = this->renderChildLayer();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",91)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",91)
			int _g1 = (int)0;
			int _g = childLayers->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",91)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",92)
				int i = (_g1)++;
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",97)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",97)
			int _g1 = (int)0;
			int _g = nativeElements->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",97)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",97)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",99)
				hx::AddEq(nativeElements->__GetItem(i)->__FieldRef(HX_CSTRING("x")),this->_rootRenderer->getBounds()->__Field(HX_CSTRING("x")));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",100)
				hx::AddEq(nativeElements->__GetItem(i)->__FieldRef(HX_CSTRING("y")),this->_rootRenderer->getBounds()->__Field(HX_CSTRING("y")));
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",115)
		Dynamic rootRendererBackground = this->_rootRenderer->renderBackground();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",117)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",117)
			int _g1 = (int)0;
			int _g = rootRendererBackground->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",117)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",117)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",119)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererBackground->__GetItem(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",122)
		Dynamic rootRendererElements = this->_rootRenderer->render();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",124)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",124)
			int _g1 = (int)0;
			int _g = rootRendererElements->__Field(HX_CSTRING("length"));
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",124)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",124)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",126)
				nativeElements->__Field(HX_CSTRING("push"))(rootRendererElements->__GetItem(i));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",133)
	return nativeElements;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,render,return )

Dynamic LayerRenderer_obj::renderChildrenBlockContainerBackground( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderChildrenBlockContainerBackground")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",146)
	Array< ::cocktail::core::renderer::ElementRenderer > childrenBlockContainer = this->getBlockContainerChildren(this->_rootRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",148)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",150)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",150)
		int _g1 = (int)0;
		int _g = childrenBlockContainer->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",150)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",150)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",153)
			Dynamic nativeElements = childrenBlockContainer->__get(i)->renderBackground();
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",155)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",155)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",155)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",155)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",157)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",161)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderChildrenBlockContainerBackground,return )

Array< ::cocktail::core::renderer::ElementRenderer > LayerRenderer_obj::getBlockContainerChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getBlockContainerChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",173)
	Array< ::cocktail::core::renderer::ElementRenderer > ret = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",175)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",175)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",175)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",175)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",177)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",179)
			if (((child->getLayerRenderer() == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",180)
				if (((child->canHaveChildren() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",183)
					Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getBlockContainerChildren(child);
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",184)
					{
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",184)
						int _g3 = (int)0;
						int _g2 = childElementRenderer->length;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",184)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",184)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",186)
							ret->push(childElementRenderer->__get(j));
						}
					}
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",188)
					ret->push(child);
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",192)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getBlockContainerChildren,return )

Dynamic LayerRenderer_obj::renderChildLayer( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderChildLayer")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",201)
	Array< ::cocktail::core::renderer::LayerRenderer > childLayers = this->getChildLayers(this->_rootRenderer,hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",204)
	childLayers->reverse();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",206)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",208)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",208)
		int _g1 = (int)0;
		int _g = childLayers->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",208)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",208)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",210)
			Dynamic nativeElements = childLayers->__get(i)->render();
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",211)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",211)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",211)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",211)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",213)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",217)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderChildLayer,return )

Array< ::cocktail::core::renderer::LayerRenderer > LayerRenderer_obj::getChildLayers( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer,::cocktail::core::renderer::LayerRenderer referenceLayer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getChildLayers")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",226)
	Array< ::cocktail::core::renderer::LayerRenderer > childLayers = Array_obj< ::cocktail::core::renderer::LayerRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",229)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",229)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",229)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",229)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",231)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",234)
			if (((child->getLayerRenderer() == referenceLayer))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",235)
				if (((bool((child->canHaveChildren() == true)) && bool((child->getCoreStyle()->getDisplay() != ::cocktail::core::style::Display_obj::inlineBlock_dyn()))))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",239)
					Array< ::cocktail::core::renderer::LayerRenderer > childElementRenderer = this->getChildLayers(child,referenceLayer);
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",240)
					{
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",240)
						int _g3 = (int)0;
						int _g2 = childElementRenderer->length;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",240)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",240)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",242)
							childLayers->push(childElementRenderer->__get(j));
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",248)
				childLayers->push(child->getLayerRenderer());
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",253)
	return childLayers;
}


HX_DEFINE_DYNAMIC_FUNC2(LayerRenderer_obj,getChildLayers,return )

Dynamic LayerRenderer_obj::renderInFlowChildren( ){
	HX_SOURCE_PUSH("LayerRenderer_obj::renderInFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",263)
	Array< ::cocktail::core::renderer::ElementRenderer > inFlowChildren = this->getInFlowChildren(this->_rootRenderer);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",265)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",267)
	{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",267)
		int _g1 = (int)0;
		int _g = inFlowChildren->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",267)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",267)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",269)
			Dynamic nativeElements = Dynamic( Array_obj<Dynamic>::__new());
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",270)
			if (((inFlowChildren->__get(i)->getCoreStyle()->getDisplay() == ::cocktail::core::style::Display_obj::inlineBlock_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",275)
				Array< ::cocktail::core::renderer::LayerRenderer > d = this->getChildLayers(inFlowChildren->__get(i),hx::ObjectPtr<OBJ_>(this));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",277)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",277)
					int _g3 = (int)0;
					int _g2 = d->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",277)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",277)
						int l = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",279)
						Dynamic ne = d->__get(l)->render();
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",280)
						{
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",280)
							int _g5 = (int)0;
							int _g4 = ne->__Field(HX_CSTRING("length"));
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",280)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",280)
								int m = (_g5)++;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",283)
								hx::AddEq(ne->__GetItem(m)->__FieldRef(HX_CSTRING("x")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("x")));
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",284)
								hx::AddEq(ne->__GetItem(m)->__FieldRef(HX_CSTRING("y")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("y")));
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",287)
								nativeElements->__Field(HX_CSTRING("push"))(ne->__GetItem(m));
							}
						}
					}
				}
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",292)
				Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getInFlowChildren(inFlowChildren->__get(i));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",293)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",293)
					int _g3 = (int)0;
					int _g2 = childElementRenderer->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",293)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",293)
						int l = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",295)
						hx::AddEq(childElementRenderer->__get(l)->getBounds()->__FieldRef(HX_CSTRING("x")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("x")));
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",296)
						hx::AddEq(childElementRenderer->__get(l)->getBounds()->__FieldRef(HX_CSTRING("y")),inFlowChildren->__get(i)->getBounds()->__Field(HX_CSTRING("y")));
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",298)
						Dynamic el = childElementRenderer->__get(l)->render();
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",300)
						{
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",300)
							int _g5 = (int)0;
							int _g4 = el->__Field(HX_CSTRING("length"));
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",300)
							while(((_g5 < _g4))){
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",300)
								int k = (_g5)++;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",302)
								nativeElements->__Field(HX_CSTRING("push"))(el->__GetItem(k));
							}
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",309)
				nativeElements = inFlowChildren->__get(i)->render();
			}
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",313)
			if (((bool((inFlowChildren->__get(i)->canHaveChildren() == false)) && bool((inFlowChildren->__get(i)->isText() == false))))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",316)
				Dynamic bg = inFlowChildren->__get(i)->renderBackground();
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",318)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",318)
					int _g3 = (int)0;
					int _g2 = bg->__Field(HX_CSTRING("length"));
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",318)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",318)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",320)
						ret->__Field(HX_CSTRING("push"))(bg->__GetItem(j));
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",324)
			{
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",324)
				int _g3 = (int)0;
				int _g2 = nativeElements->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",324)
				while(((_g3 < _g2))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",324)
					int j = (_g3)++;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",326)
					ret->__Field(HX_CSTRING("push"))(nativeElements->__GetItem(j));
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",332)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(LayerRenderer_obj,renderInFlowChildren,return )

Array< ::cocktail::core::renderer::ElementRenderer > LayerRenderer_obj::getInFlowChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer){
	HX_SOURCE_PUSH("LayerRenderer_obj::getInFlowChildren")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",342)
	Array< ::cocktail::core::renderer::ElementRenderer > ret = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",344)
	if (((bool((rootRenderer->establishesNewFormattingContext() == true)) && bool((rootRenderer->getCoreStyle()->childrenInline() == true))))){
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",347)
		::cocktail::core::renderer::BlockBoxRenderer blockBoxRenderer = rootRenderer;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",349)
		{
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",349)
			int _g1 = (int)0;
			int _g = blockBoxRenderer->getLineBoxes()->length;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",349)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",349)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",351)
				{
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",351)
					int _g3 = (int)0;
					int _g2 = blockBoxRenderer->getLineBoxes()->__get(i)->length;
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",351)
					while(((_g3 < _g2))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",351)
						int j = (_g3)++;
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",353)
						if (((bool((blockBoxRenderer->getLineBoxes()->__get(i)->__get(j)->isPositioned() == false)) && bool((blockBoxRenderer->getLineBoxes()->__get(i)->__get(j)->isDisplayed() == true))))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",354)
							ret->push(blockBoxRenderer->getLineBoxes()->__get(i)->__get(j));
						}
					}
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",363)
		int _g1 = (int)0;
		int _g = rootRenderer->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",363)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",363)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",365)
			::cocktail::core::renderer::ElementRenderer child = rootRenderer->get_childNodes()->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",367)
			if (((child->isDisplayed() == true))){
				HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",368)
				if (((child->getLayerRenderer() == hx::ObjectPtr<OBJ_>(this)))){
					HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",370)
					if (((child->isPositioned() == false))){
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",373)
						ret->push(child);
						HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",374)
						if (((child->canHaveChildren() == true))){
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",376)
							Array< ::cocktail::core::renderer::ElementRenderer > childElementRenderer = this->getInFlowChildren(child);
							HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",377)
							{
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",377)
								int _g3 = (int)0;
								int _g2 = childElementRenderer->length;
								HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",377)
								while(((_g3 < _g2))){
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",377)
									int j = (_g3)++;
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",379)
									if (((child->establishesNewFormattingContext() == true))){
										HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",381)
										hx::AddEq(childElementRenderer->__get(j)->getBounds()->__FieldRef(HX_CSTRING("x")),child->getBounds()->__Field(HX_CSTRING("x")));
										HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",382)
										hx::AddEq(childElementRenderer->__get(j)->getBounds()->__FieldRef(HX_CSTRING("y")),child->getBounds()->__Field(HX_CSTRING("y")));
									}
									HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",385)
									ret->push(childElementRenderer->__get(j));
								}
							}
						}
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",395)
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
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",435)
	::cocktail::core::geom::Matrix currentMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",444)
	return currentMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(LayerRenderer_obj,getConcatenatedMatrix,return )

::cocktail::core::geom::Matrix LayerRenderer_obj::getConcatenatedMatrix2( ::cocktail::core::geom::Matrix matrix){
	HX_SOURCE_PUSH("LayerRenderer_obj::getConcatenatedMatrix2")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",457)
	::cocktail::core::geom::Matrix currentMatrix = ::cocktail::core::geom::Matrix_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/LayerRenderer.hx",460)
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
