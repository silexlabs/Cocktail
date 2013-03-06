#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSValueConverter
#include <cocktail/core/css/CSSValueConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
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
#ifndef INCLUDED_cocktail_core_layer_LayerRenderer
#include <cocktail/core/layer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#include <cocktail/core/layer/ScrollableView.h>
#endif
#ifndef INCLUDED_cocktail_core_layer_TextInputLayerRenderer
#include <cocktail/core/layer/TextInputLayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#include <cocktail/core/renderer/TextInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void TextInputRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("TextInputRenderer::new","cocktail/core/renderer/TextInputRenderer.hx",65);
{
	HX_STACK_LINE(66)
	super::__construct(node);
	HX_STACK_LINE(68)
	this->nativeTextInput = ::cocktail::port::platform::flash_player::NativeTextInput_obj::__new();
	HX_STACK_LINE(71)
	node->addEventListener(HX_CSTRING("focus"),this->onTextInputFocus_dyn(),null());
}
;
	return null();
}

TextInputRenderer_obj::~TextInputRenderer_obj() { }

Dynamic TextInputRenderer_obj::__CreateEmpty() { return  new TextInputRenderer_obj; }
hx::ObjectPtr< TextInputRenderer_obj > TextInputRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< TextInputRenderer_obj > result = new TextInputRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic TextInputRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextInputRenderer_obj > result = new TextInputRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

int TextInputRenderer_obj::set_maxLength( int value){
	HX_STACK_PUSH("TextInputRenderer::set_maxLength","cocktail/core/renderer/TextInputRenderer.hx",205);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(205)
	return this->nativeTextInput->set_maxLength(value);
}


HX_DEFINE_DYNAMIC_FUNC1(TextInputRenderer_obj,set_maxLength,return )

::String TextInputRenderer_obj::set_value( ::String value){
	HX_STACK_PUSH("TextInputRenderer::set_value","cocktail/core/renderer/TextInputRenderer.hx",200);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(200)
	return this->nativeTextInput->set_value(value);
}


HX_DEFINE_DYNAMIC_FUNC1(TextInputRenderer_obj,set_value,return )

::String TextInputRenderer_obj::get_value( ){
	HX_STACK_PUSH("TextInputRenderer::get_value","cocktail/core/renderer/TextInputRenderer.hx",195);
	HX_STACK_THIS(this);
	HX_STACK_LINE(195)
	return this->nativeTextInput->get_value();
}


HX_DEFINE_DYNAMIC_FUNC0(TextInputRenderer_obj,get_value,return )

Void TextInputRenderer_obj::updateNativeTextInput( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("TextInputRenderer::updateNativeTextInput","cocktail/core/renderer/TextInputRenderer.hx",123);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(124)
		::cocktail::core::geom::RectangleVO globalBounds = this->globalBounds;		HX_STACK_VAR(globalBounds,"globalBounds");
		HX_STACK_LINE(128)
		Float x = (globalBounds->x - scrollOffset->x);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(129)
		Float y = ((((globalBounds->y + (Float(globalBounds->height) / Float((int)2))) - this->coreStyle->fontMetrics->fontSize) + (Float(this->coreStyle->fontMetrics->ascent) / Float((int)2))) - scrollOffset->y);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(134)
		::cocktail::core::geom::Matrix layerMatrix = this->layerRenderer->matrix;		HX_STACK_VAR(layerMatrix,"layerMatrix");
		HX_STACK_LINE(135)
		hx::AddEq(x,layerMatrix->e);
		HX_STACK_LINE(136)
		hx::AddEq(y,layerMatrix->f);
		HX_STACK_LINE(138)
		Float width = globalBounds->width;		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(139)
		Float height = globalBounds->height;		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(140)
		::cocktail::core::geom::RectangleVO viewport = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(viewport,"viewport");
		HX_STACK_LINE(141)
		viewport->x = x;
		HX_STACK_LINE(142)
		viewport->y = y;
		HX_STACK_LINE(143)
		viewport->width = width;
		HX_STACK_LINE(144)
		viewport->height = height;
		HX_STACK_LINE(145)
		this->nativeTextInput->set_viewport(viewport);
		HX_STACK_LINE(152)
		this->nativeTextInput->set_clipRect(this->layerRenderer->clipRect);
		HX_STACK_LINE(157)
		this->nativeTextInput->set_fontFamily(::cocktail::core::css::CSSValueConverter_obj::getFontFamilyAsStringArray(this->coreStyle->getComputedOrInitialProperty((int)37))->__get((int)0));
		HX_STACK_LINE(158)
		this->nativeTextInput->set_letterSpacing(this->coreStyle->usedValues->letterSpacing);
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::renderer::TextInputRenderer_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextInputRenderer.hx",159);
				{
					HX_STACK_LINE(159)
					::cocktail::core::css::CoreStyle _this = __this->coreStyle;		HX_STACK_VAR(_this,"_this");
					struct _Function_2_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &_this){
							HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextInputRenderer.hx",159);
							{
								HX_STACK_LINE(159)
								::cocktail::core::animation::Transition transition = _this->_transitionManager->getTransition((int)34,_this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(159)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(159)
					return (  (((_this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((_this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(_this)) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(159)
		this->nativeTextInput->set_fontSize(this->coreStyle->getAbsoluteLength(_Function_1_1::Block(this)));
		HX_STACK_LINE(161)
		bool bold = false;		HX_STACK_VAR(bold,"bold");
		HX_STACK_LINE(162)
		{
			::cocktail::core::css::CSSPropertyValue _switch_1 = (this->coreStyle->getComputedOrInitialProperty((int)35));
			switch((_switch_1)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(164)
						{
							::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
							switch((_switch_2)->GetIndex()){
								case 3: case 0: {
									HX_STACK_LINE(167)
									bold = false;
								}
								;break;
								case 2: case 1: {
									HX_STACK_LINE(170)
									bold = true;
								}
								;break;
								default: {
									HX_STACK_LINE(173)
									hx::Throw (HX_CSTRING("Illegal keyword for bold style"));
								}
							}
						}
					}
				}
				;break;
				case 0: {
					int value = _switch_1->__Param(0);
{
						HX_STACK_LINE(177)
						bold = (value > (int)400);
					}
				}
				;break;
				default: {
					HX_STACK_LINE(180)
					hx::Throw (HX_CSTRING("Illegal value for bold style"));
				}
			}
		}
		HX_STACK_LINE(184)
		this->nativeTextInput->set_italic(bold);
		HX_STACK_LINE(185)
		this->nativeTextInput->set_italic((this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)36)) == ::cocktail::core::css::CSSKeywordValue_obj::ITALIC_dyn()));
		HX_STACK_LINE(186)
		this->nativeTextInput->set_letterSpacing(this->coreStyle->usedValues->letterSpacing);
		HX_STACK_LINE(187)
		this->nativeTextInput->set_color(this->coreStyle->usedValues->color->color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextInputRenderer_obj,updateNativeTextInput,(void))

Void TextInputRenderer_obj::onTextInputFocus( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("TextInputRenderer::onTextInputFocus","cocktail/core/renderer/TextInputRenderer.hx",115);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(115)
		this->nativeTextInput->focus();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextInputRenderer_obj,onTextInputFocus,(void))

Void TextInputRenderer_obj::renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("TextInputRenderer::renderEmbeddedAsset","cocktail/core/renderer/TextInputRenderer.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(101)
		this->updateNativeTextInput(scrollOffset,clipRect);
	}
return null();
}


Void TextInputRenderer_obj::doCreateLayer( ){
{
		HX_STACK_PUSH("TextInputRenderer::doCreateLayer","cocktail/core/renderer/TextInputRenderer.hx",93);
		HX_STACK_THIS(this);
		HX_STACK_LINE(93)
		this->layerRenderer = ::cocktail::core::layer::TextInputLayerRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool TextInputRenderer_obj::createOwnLayer( ){
	HX_STACK_PUSH("TextInputRenderer::createOwnLayer","cocktail/core/renderer/TextInputRenderer.hx",84);
	HX_STACK_THIS(this);
	HX_STACK_LINE(84)
	return true;
}



TextInputRenderer_obj::TextInputRenderer_obj()
{
}

void TextInputRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextInputRenderer);
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_MEMBER_NAME(nativeTextInput,"nativeTextInput");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextInputRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(value,"value");
	HX_VISIT_MEMBER_NAME(nativeTextInput,"nativeTextInput");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextInputRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return maxLength; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"doCreateLayer") ) { return doCreateLayer_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createOwnLayer") ) { return createOwnLayer_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nativeTextInput") ) { return nativeTextInput; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onTextInputFocus") ) { return onTextInputFocus_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"renderEmbeddedAsset") ) { return renderEmbeddedAsset_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updateNativeTextInput") ) { return updateNativeTextInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextInputRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nativeTextInput") ) { nativeTextInput=inValue.Cast< ::cocktail::port::platform::flash_player::NativeTextInput >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextInputRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("value"));
	outFields->push(HX_CSTRING("nativeTextInput"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("updateNativeTextInput"),
	HX_CSTRING("onTextInputFocus"),
	HX_CSTRING("renderEmbeddedAsset"),
	HX_CSTRING("doCreateLayer"),
	HX_CSTRING("createOwnLayer"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("value"),
	HX_CSTRING("nativeTextInput"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextInputRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextInputRenderer_obj::__mClass,"__mClass");
};

Class TextInputRenderer_obj::__mClass;

void TextInputRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.TextInputRenderer"), hx::TCanCast< TextInputRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextInputRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
