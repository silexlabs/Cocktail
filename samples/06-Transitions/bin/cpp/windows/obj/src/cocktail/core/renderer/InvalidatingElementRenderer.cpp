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
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InvalidatingElementRenderer_obj::__construct(::cocktail::core::html::HTMLElement domNode)
{
HX_STACK_PUSH("InvalidatingElementRenderer::new","cocktail/core/renderer/InvalidatingElementRenderer.hx",45);
{
	HX_STACK_LINE(46)
	super::__construct(domNode);
	HX_STACK_LINE(48)
	this->_needsLayout = true;
	HX_STACK_LINE(49)
	this->_childrenNeedLayout = true;
	HX_STACK_LINE(50)
	this->_positionedChildrenNeedLayout = true;
}
;
	return null();
}

InvalidatingElementRenderer_obj::~InvalidatingElementRenderer_obj() { }

Dynamic InvalidatingElementRenderer_obj::__CreateEmpty() { return  new InvalidatingElementRenderer_obj; }
hx::ObjectPtr< InvalidatingElementRenderer_obj > InvalidatingElementRenderer_obj::__new(::cocktail::core::html::HTMLElement domNode)
{  hx::ObjectPtr< InvalidatingElementRenderer_obj > result = new InvalidatingElementRenderer_obj();
	result->__construct(domNode);
	return result;}

Dynamic InvalidatingElementRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InvalidatingElementRenderer_obj > result = new InvalidatingElementRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InvalidatingElementRenderer_obj::invalidateText( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateText","cocktail/core/renderer/InvalidatingElementRenderer.hx",326);
		HX_STACK_THIS(this);
		HX_STACK_LINE(327)
		::cocktail::core::renderer::ElementRenderer child = this->firstChild;		HX_STACK_VAR(child,"child");
		HX_STACK_LINE(328)
		while(((child != null()))){
			HX_STACK_LINE(330)
			if (((child->isText == true))){
				HX_STACK_LINE(331)
				child->invalidate();
			}
			HX_STACK_LINE(334)
			child = child->nextSibling;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidatingElementRenderer_obj,invalidateText,(void))

Void InvalidatingElementRenderer_obj::invalidateLayoutAndRendering( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateLayoutAndRendering","cocktail/core/renderer/InvalidatingElementRenderer.hx",308);
		HX_STACK_THIS(this);
		HX_STACK_LINE(309)
		this->_needsLayout = true;
		HX_STACK_LINE(311)
		::cocktail::core::html::HTMLDocument htmlDocument = this->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(312)
		htmlDocument->invalidationManager->invalidateLayout(false);
		HX_STACK_LINE(316)
		if (((this->layerRenderer != null()))){
			HX_STACK_LINE(317)
			this->layerRenderer->invalidateRendering();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidatingElementRenderer_obj,invalidateLayoutAndRendering,(void))

Void InvalidatingElementRenderer_obj::invalidateLayout( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateLayout","cocktail/core/renderer/InvalidatingElementRenderer.hx",295);
		HX_STACK_THIS(this);
		HX_STACK_LINE(296)
		this->_needsLayout = true;
		HX_STACK_LINE(297)
		::cocktail::core::html::HTMLDocument htmlDocument = this->domNode->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(298)
		if (((htmlDocument != null()))){
			HX_STACK_LINE(299)
			htmlDocument->invalidationManager->invalidateLayout(false);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidatingElementRenderer_obj,invalidateLayout,(void))

Void InvalidatingElementRenderer_obj::invalidatedPositionedChildStyle( int styleIndex){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidatedPositionedChildStyle","cocktail/core/renderer/InvalidatingElementRenderer.hx",274);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(274)
		switch( (int)(styleIndex)){
			case (int)25: case (int)31: case (int)26: case (int)30: case (int)28: case (int)27: case (int)29: {
			}
			;break;
			default: {
				HX_STACK_LINE(282)
				this->_positionedChildrenNeedLayout = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidatingElementRenderer_obj,invalidatedPositionedChildStyle,(void))

Void InvalidatingElementRenderer_obj::invalidatedChildStyle( int styleIndex){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidatedChildStyle","cocktail/core/renderer/InvalidatingElementRenderer.hx",254);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(254)
		switch( (int)(styleIndex)){
			case (int)25: case (int)31: case (int)26: case (int)30: case (int)28: case (int)27: case (int)29: {
			}
			;break;
			default: {
				HX_STACK_LINE(265)
				this->_childrenNeedLayout = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidatingElementRenderer_obj,invalidatedChildStyle,(void))

Void InvalidatingElementRenderer_obj::invalidatedStyle( int styleIndex){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidatedStyle","cocktail/core/renderer/InvalidatingElementRenderer.hx",201);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(201)
		switch( (int)(styleIndex)){
			case (int)22: case (int)23: case (int)21: case (int)24: {
				HX_STACK_LINE(206)
				if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
					HX_STACK_LINE(211)
					this->invalidateLayoutAndRendering();
					HX_STACK_LINE(212)
					this->invalidateContainingBlock(styleIndex);
				}
				else{
					HX_STACK_LINE(217)
					this->invalidateRendering();
				}
			}
			;break;
			case (int)40: case (int)37: case (int)34: case (int)38: case (int)36: case (int)35: case (int)43: case (int)42: case (int)45: {
				HX_STACK_LINE(225)
				this->invalidateText();
				HX_STACK_LINE(226)
				this->invalidateLayoutAndRendering();
				HX_STACK_LINE(227)
				this->invalidateContainingBlock(styleIndex);
			}
			;break;
			case (int)53: case (int)49: {
				HX_STACK_LINE(231)
				this->invalidateRendering();
			}
			;break;
			case (int)25: case (int)31: case (int)26: case (int)30: case (int)28: case (int)27: case (int)29: {
				HX_STACK_LINE(236)
				this->invalidateRendering();
			}
			;break;
			default: {
				HX_STACK_LINE(245)
				this->invalidateLayout();
				HX_STACK_LINE(246)
				this->invalidateContainingBlock(styleIndex);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidatingElementRenderer_obj,invalidatedStyle,(void))

Void InvalidatingElementRenderer_obj::invalidateContainingBlock( int styleIndex){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateContainingBlock","cocktail/core/renderer/InvalidatingElementRenderer.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(177)
		if (((this->containingBlock == null()))){
			HX_STACK_LINE(178)
			return null();
		}
		HX_STACK_LINE(186)
		if (((bool((this->isPositioned() == true)) && bool((this->isRelativePositioned() == false))))){
			HX_STACK_LINE(187)
			this->containingBlock->invalidatedChildStyle(styleIndex);
		}
		else{
			HX_STACK_LINE(191)
			this->containingBlock->invalidatedPositionedChildStyle(styleIndex);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InvalidatingElementRenderer_obj,invalidateContainingBlock,(void))

Void InvalidatingElementRenderer_obj::positionedChildInvalidated( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::positionedChildInvalidated","cocktail/core/renderer/InvalidatingElementRenderer.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(165)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidatingElementRenderer_obj,positionedChildInvalidated,(void))

Void InvalidatingElementRenderer_obj::childInvalidated( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::childInvalidated","cocktail/core/renderer/InvalidatingElementRenderer.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_LINE(157)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InvalidatingElementRenderer_obj,childInvalidated,(void))

Void InvalidatingElementRenderer_obj::invalidateStyle( int styleIndex){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateStyle","cocktail/core/renderer/InvalidatingElementRenderer.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleIndex,"styleIndex");
		HX_STACK_LINE(100)
		switch( (int)(styleIndex)){
			case (int)22: case (int)23: case (int)21: case (int)24: {
				HX_STACK_LINE(105)
				if (((this->isAbsolutelyPositioned() == true))){
					HX_STACK_LINE(110)
					this->invalidateLayoutAndRendering();
					HX_STACK_LINE(111)
					this->invalidateContainingBlock(styleIndex);
				}
				else{
					HX_STACK_LINE(116)
					this->invalidateRendering();
				}
			}
			;break;
			case (int)40: case (int)37: case (int)34: case (int)38: case (int)36: case (int)35: case (int)43: case (int)42: case (int)45: {
				HX_STACK_LINE(124)
				this->invalidateText();
				HX_STACK_LINE(125)
				this->invalidateLayoutAndRendering();
				HX_STACK_LINE(126)
				this->invalidateContainingBlock(styleIndex);
			}
			;break;
			case (int)53: case (int)49: {
				HX_STACK_LINE(130)
				this->invalidateRendering();
			}
			;break;
			case (int)25: case (int)31: case (int)26: case (int)30: case (int)28: case (int)27: case (int)29: {
				HX_STACK_LINE(135)
				this->invalidateRendering();
			}
			;break;
			default: {
				HX_STACK_LINE(144)
				this->invalidateLayoutAndRendering();
				HX_STACK_LINE(145)
				this->invalidateContainingBlock(styleIndex);
			}
		}
	}
return null();
}


Void InvalidatingElementRenderer_obj::invalidateRendering( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidateRendering","cocktail/core/renderer/InvalidatingElementRenderer.hx",85);
		HX_STACK_THIS(this);
		HX_STACK_LINE(85)
		if (((this->layerRenderer != null()))){
			HX_STACK_LINE(89)
			this->layerRenderer->invalidateRendering();
		}
	}
return null();
}


Void InvalidatingElementRenderer_obj::invalidate( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::invalidate","cocktail/core/renderer/InvalidatingElementRenderer.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_LINE(76)
		this->_childrenNeedLayout = true;
		HX_STACK_LINE(77)
		this->_positionedChildrenNeedLayout = true;
		HX_STACK_LINE(78)
		this->invalidateLayoutAndRendering();
	}
return null();
}


Void InvalidatingElementRenderer_obj::addedToRenderingTree( ){
{
		HX_STACK_PUSH("InvalidatingElementRenderer::addedToRenderingTree","cocktail/core/renderer/InvalidatingElementRenderer.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_LINE(63)
		this->super::addedToRenderingTree();
		HX_STACK_LINE(64)
		this->invalidateLayout();
	}
return null();
}



InvalidatingElementRenderer_obj::InvalidatingElementRenderer_obj()
{
}

void InvalidatingElementRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InvalidatingElementRenderer);
	HX_MARK_MEMBER_NAME(_positionedChildrenNeedLayout,"_positionedChildrenNeedLayout");
	HX_MARK_MEMBER_NAME(_childrenNeedLayout,"_childrenNeedLayout");
	HX_MARK_MEMBER_NAME(_needsLayout,"_needsLayout");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InvalidatingElementRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_positionedChildrenNeedLayout,"_positionedChildrenNeedLayout");
	HX_VISIT_MEMBER_NAME(_childrenNeedLayout,"_childrenNeedLayout");
	HX_VISIT_MEMBER_NAME(_needsLayout,"_needsLayout");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InvalidatingElementRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_needsLayout") ) { return _needsLayout; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"invalidateText") ) { return invalidateText_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"invalidateStyle") ) { return invalidateStyle_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"invalidateLayout") ) { return invalidateLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidatedStyle") ) { return invalidatedStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"childInvalidated") ) { return childInvalidated_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"invalidateRendering") ) { return invalidateRendering_dyn(); }
		if (HX_FIELD_EQ(inName,"_childrenNeedLayout") ) { return _childrenNeedLayout; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"addedToRenderingTree") ) { return addedToRenderingTree_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"invalidatedChildStyle") ) { return invalidatedChildStyle_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"invalidateContainingBlock") ) { return invalidateContainingBlock_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"positionedChildInvalidated") ) { return positionedChildInvalidated_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"invalidateLayoutAndRendering") ) { return invalidateLayoutAndRendering_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_positionedChildrenNeedLayout") ) { return _positionedChildrenNeedLayout; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"invalidatedPositionedChildStyle") ) { return invalidatedPositionedChildStyle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InvalidatingElementRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_needsLayout") ) { _needsLayout=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_childrenNeedLayout") ) { _childrenNeedLayout=inValue.Cast< bool >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"_positionedChildrenNeedLayout") ) { _positionedChildrenNeedLayout=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InvalidatingElementRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_positionedChildrenNeedLayout"));
	outFields->push(HX_CSTRING("_childrenNeedLayout"));
	outFields->push(HX_CSTRING("_needsLayout"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("invalidateText"),
	HX_CSTRING("invalidateLayoutAndRendering"),
	HX_CSTRING("invalidateLayout"),
	HX_CSTRING("invalidatedPositionedChildStyle"),
	HX_CSTRING("invalidatedChildStyle"),
	HX_CSTRING("invalidatedStyle"),
	HX_CSTRING("invalidateContainingBlock"),
	HX_CSTRING("positionedChildInvalidated"),
	HX_CSTRING("childInvalidated"),
	HX_CSTRING("invalidateStyle"),
	HX_CSTRING("invalidateRendering"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("addedToRenderingTree"),
	HX_CSTRING("_positionedChildrenNeedLayout"),
	HX_CSTRING("_childrenNeedLayout"),
	HX_CSTRING("_needsLayout"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InvalidatingElementRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InvalidatingElementRenderer_obj::__mClass,"__mClass");
};

Class InvalidatingElementRenderer_obj::__mClass;

void InvalidatingElementRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InvalidatingElementRenderer"), hx::TCanCast< InvalidatingElementRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InvalidatingElementRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
