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
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_Matrix
#include <cocktail/core/geom/Matrix.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_CompositingLayerRenderer
#include <cocktail/core/layer/CompositingLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_InputLayerRenderer
#include <cocktail/core/layer/InputLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
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
#ifndef INCLUDED_cocktail_core_renderer_InputRenderer
#include <cocktail/core/renderer/InputRenderer.h>
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
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void InputRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("InputRenderer::new","cocktail/core/renderer/InputRenderer.hx",86);
{
	HX_STACK_LINE(87)
	super::__construct(node);
	HX_STACK_LINE(89)
	this->createNativeInput();
	HX_STACK_LINE(90)
	this->setNativeInputCallbacks();
}
;
	return null();
}

InputRenderer_obj::~InputRenderer_obj() { }

Dynamic InputRenderer_obj::__CreateEmpty() { return  new InputRenderer_obj; }
hx::ObjectPtr< InputRenderer_obj > InputRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< InputRenderer_obj > result = new InputRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic InputRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InputRenderer_obj > result = new InputRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

int InputRenderer_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("InputRenderer::get_intrinsicHeight","cocktail/core/renderer/InputRenderer.hx",250);
	HX_STACK_THIS(this);
	HX_STACK_LINE(250)
	return this->nativeInput->get_intrinsicHeight();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,get_intrinsicHeight,return )

int InputRenderer_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("InputRenderer::get_intrinsicWidth","cocktail/core/renderer/InputRenderer.hx",245);
	HX_STACK_THIS(this);
	HX_STACK_LINE(245)
	return this->nativeInput->get_intrinsicWidth();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,get_intrinsicWidth,return )

bool InputRenderer_obj::set_checked( bool value){
	HX_STACK_PUSH("InputRenderer::set_checked","cocktail/core/renderer/InputRenderer.hx",240);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(240)
	return this->nativeInput->set_checked(value);
}


HX_DEFINE_DYNAMIC_FUNC1(InputRenderer_obj,set_checked,return )

bool InputRenderer_obj::get_checked( ){
	HX_STACK_PUSH("InputRenderer::get_checked","cocktail/core/renderer/InputRenderer.hx",235);
	HX_STACK_THIS(this);
	HX_STACK_LINE(235)
	return this->nativeInput->get_checked();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,get_checked,return )

bool InputRenderer_obj::set_readonly( bool value){
	HX_STACK_PUSH("InputRenderer::set_readonly","cocktail/core/renderer/InputRenderer.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(230)
	return this->nativeInput->set_readonly(value);
}


HX_DEFINE_DYNAMIC_FUNC1(InputRenderer_obj,set_readonly,return )

bool InputRenderer_obj::set_disabled( bool value){
	HX_STACK_PUSH("InputRenderer::set_disabled","cocktail/core/renderer/InputRenderer.hx",225);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(225)
	return this->nativeInput->set_disabled(value);
}


HX_DEFINE_DYNAMIC_FUNC1(InputRenderer_obj,set_disabled,return )

int InputRenderer_obj::set_maxLength( int value){
	HX_STACK_PUSH("InputRenderer::set_maxLength","cocktail/core/renderer/InputRenderer.hx",220);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(220)
	return this->nativeInput->set_maxLength(value);
}


HX_DEFINE_DYNAMIC_FUNC1(InputRenderer_obj,set_maxLength,return )

::String InputRenderer_obj::set_value( ::String value){
	HX_STACK_PUSH("InputRenderer::set_value","cocktail/core/renderer/InputRenderer.hx",215);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(215)
	return this->nativeInput->set_value(value);
}


HX_DEFINE_DYNAMIC_FUNC1(InputRenderer_obj,set_value,return )

::String InputRenderer_obj::get_value( ){
	HX_STACK_PUSH("InputRenderer::get_value","cocktail/core/renderer/InputRenderer.hx",210);
	HX_STACK_THIS(this);
	HX_STACK_LINE(210)
	return this->nativeInput->get_value();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,get_value,return )

Void InputRenderer_obj::updateNativeInputViewport( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("InputRenderer::updateNativeInputViewport","cocktail/core/renderer/InputRenderer.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(174)
		::cocktail::core::geom::RectangleVO globalBounds = this->globalBounds;		HX_STACK_VAR(globalBounds,"globalBounds");
		HX_STACK_LINE(178)
		Float x = ((globalBounds->x + this->coreStyle->usedValues->borderLeftWidth) - scrollOffset->x);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(179)
		Float y = (((((globalBounds->y + this->coreStyle->usedValues->borderTopWidth) + (Float((((globalBounds->height - this->coreStyle->usedValues->borderTopWidth) - this->coreStyle->usedValues->borderBottomWidth))) / Float((int)2))) - this->coreStyle->fontMetrics->fontSize) + (Float(this->coreStyle->fontMetrics->ascent) / Float((int)2))) - scrollOffset->y);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(184)
		::cocktail::core::geom::Matrix layerMatrix = this->layerRenderer->matrix;		HX_STACK_VAR(layerMatrix,"layerMatrix");
		HX_STACK_LINE(185)
		hx::AddEq(x,layerMatrix->e);
		HX_STACK_LINE(186)
		hx::AddEq(y,layerMatrix->f);
		HX_STACK_LINE(188)
		Float width = ((globalBounds->width - this->coreStyle->usedValues->borderLeftWidth) - this->coreStyle->usedValues->borderRightWidth);		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(189)
		Float height = ((globalBounds->height - this->coreStyle->usedValues->borderTopWidth) - this->coreStyle->usedValues->borderBottomWidth);		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(190)
		::cocktail::core::geom::RectangleVO viewport = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(viewport,"viewport");
		HX_STACK_LINE(191)
		viewport->x = x;
		HX_STACK_LINE(192)
		viewport->y = y;
		HX_STACK_LINE(193)
		viewport->width = width;
		HX_STACK_LINE(194)
		viewport->height = height;
		HX_STACK_LINE(195)
		this->nativeInput->set_viewport(viewport);
		HX_STACK_LINE(202)
		this->nativeInput->set_clipRect(this->layerRenderer->clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputRenderer_obj,updateNativeInputViewport,(void))

Void InputRenderer_obj::renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("InputRenderer::renderSelf","cocktail/core/renderer/InputRenderer.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(161)
		this->super::renderSelf(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(162)
		this->updateNativeInputViewport(scrollOffset,clipRect);
	}
return null();
}


Void InputRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("InputRenderer::doCreateLayer","cocktail/core/renderer/InputRenderer.hx",152);
		HX_STACK_THIS(this);
		HX_STACK_LINE(152)
		this->layerRenderer = ::cocktail::core::layer::InputLayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool InputRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("InputRenderer::createOwnLayer","cocktail/core/renderer/InputRenderer.hx",143);
	HX_STACK_THIS(this);
	HX_STACK_LINE(143)
	return true;
}


Void InputRenderer_obj::blur( ){
{
		HX_STACK_PUSH("InputRenderer::blur","cocktail/core/renderer/InputRenderer.hx",129);
		HX_STACK_THIS(this);
		HX_STACK_LINE(129)
		this->nativeInput->blur();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,blur,(void))

Void InputRenderer_obj::focus( ){
{
		HX_STACK_PUSH("InputRenderer::focus","cocktail/core/renderer/InputRenderer.hx",121);
		HX_STACK_THIS(this);
		HX_STACK_LINE(121)
		this->nativeInput->focus();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,focus,(void))

Void InputRenderer_obj::setNativeInputCallbacks( ){
{
		HX_STACK_PUSH("InputRenderer::setNativeInputCallbacks","cocktail/core/renderer/InputRenderer.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_LINE(106)
		Array< ::cocktail::core::renderer::InputRenderer > _g = Array_obj< ::cocktail::core::renderer::InputRenderer >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::cocktail::core::renderer::InputRenderer >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_1","cocktail/core/renderer/InputRenderer.hx",109);
			{
				HX_STACK_LINE(109)
				_g->__get((int)0)->onActivate();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(109)
		this->nativeInput->onActivate =  Dynamic(new _Function_1_1(_g));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::cocktail::core::renderer::InputRenderer >,_g)
		Void run(){
			HX_STACK_PUSH("*::_Function_1_2","cocktail/core/renderer/InputRenderer.hx",110);
			{
				HX_STACK_LINE(110)
				_g->__get((int)0)->onInput();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(110)
		this->nativeInput->onInput =  Dynamic(new _Function_1_2(_g));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,setNativeInputCallbacks,(void))

Void InputRenderer_obj::createNativeInput( ){
{
		HX_STACK_PUSH("InputRenderer::createNativeInput","cocktail/core/renderer/InputRenderer.hx",98);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputRenderer_obj,createNativeInput,(void))


InputRenderer_obj::InputRenderer_obj()
{
}

void InputRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InputRenderer);
	HX_MARK_MEMBER_NAME(onInput,"onInput");
	HX_MARK_MEMBER_NAME(onActivate,"onActivate");
	HX_MARK_MEMBER_NAME(nativeInput,"nativeInput");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(readonly,"readonly");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(checked,"checked");
	HX_MARK_MEMBER_NAME(value,"value");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InputRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(onInput,"onInput");
	HX_VISIT_MEMBER_NAME(onActivate,"onActivate");
	HX_VISIT_MEMBER_NAME(nativeInput,"nativeInput");
	HX_VISIT_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_VISIT_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_VISIT_MEMBER_NAME(readonly,"readonly");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(checked,"checked");
	HX_VISIT_MEMBER_NAME(value,"value");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InputRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"blur") ) { return blur_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onInput") ) { return onInput; }
		if (HX_FIELD_EQ(inName,"checked") ) { return inCallProp ? get_checked() : checked; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readonly") ) { return readonly; }
		if (HX_FIELD_EQ(inName,"disabled") ) { return disabled; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return maxLength; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderSelf") ) { return renderSelf_dyn(); }
		if (HX_FIELD_EQ(inName,"onActivate") ) { return onActivate; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_checked") ) { return set_checked_dyn(); }
		if (HX_FIELD_EQ(inName,"get_checked") ) { return get_checked_dyn(); }
		if (HX_FIELD_EQ(inName,"nativeInput") ) { return nativeInput; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_readonly") ) { return set_readonly_dyn(); }
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"doCreateLayer") ) { return doCreateLayer_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return inCallProp ? get_intrinsicWidth() : intrinsicWidth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return inCallProp ? get_intrinsicHeight() : intrinsicHeight; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"createNativeInput") ) { return createNativeInput_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"setNativeInputCallbacks") ) { return setNativeInputCallbacks_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"updateNativeInputViewport") ) { return updateNativeInputViewport_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onInput") ) { onInput=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"checked") ) { if (inCallProp) return set_checked(inValue);checked=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readonly") ) { if (inCallProp) return set_readonly(inValue);readonly=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disabled") ) { if (inCallProp) return set_disabled(inValue);disabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onActivate") ) { onActivate=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nativeInput") ) { nativeInput=inValue.Cast< ::cocktail::port::base::NativeInputBase >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InputRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nativeInput"));
	outFields->push(HX_CSTRING("intrinsicHeight"));
	outFields->push(HX_CSTRING("intrinsicWidth"));
	outFields->push(HX_CSTRING("readonly"));
	outFields->push(HX_CSTRING("disabled"));
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("checked"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("set_checked"),
	HX_CSTRING("get_checked"),
	HX_CSTRING("set_readonly"),
	HX_CSTRING("set_disabled"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("updateNativeInputViewport"),
	HX_CSTRING("renderSelf"),
	HX_CSTRING("doCreateLayer"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("blur"),
	HX_CSTRING("focus"),
	HX_CSTRING("setNativeInputCallbacks"),
	HX_CSTRING("createNativeInput"),
	HX_CSTRING("onInput"),
	HX_CSTRING("onActivate"),
	HX_CSTRING("nativeInput"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("readonly"),
	HX_CSTRING("disabled"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("checked"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InputRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InputRenderer_obj::__mClass,"__mClass");
};

Class InputRenderer_obj::__mClass;

void InputRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.InputRenderer"), hx::TCanCast< InputRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InputRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
