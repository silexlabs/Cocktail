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
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
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
#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#include <cocktail/core/renderer/TextInputRenderer.h>
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
HX_STACK_PUSH("TextInputRenderer::new","cocktail/core/renderer/TextInputRenderer.hx",46);
{
	HX_STACK_LINE(46)
	super::__construct(node);
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

Void TextInputRenderer_obj::updateNativeTextInput( ::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect){
{
		HX_STACK_PUSH("TextInputRenderer::updateNativeTextInput","cocktail/core/renderer/TextInputRenderer.hx",80);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_LINE(84)
		this->nativeTextInput->set_fontFamily(::cocktail::core::css::CSSValueConverter_obj::getFontFamilyAsStringArray(this->coreStyle->getComputedOrInitialProperty((int)37))->__get((int)0));
		HX_STACK_LINE(85)
		this->nativeTextInput->set_letterSpacing(this->coreStyle->usedValues->letterSpacing);
		struct _Function_1_1{
			inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::renderer::TextInputRenderer_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextInputRenderer.hx",86);
				{
					HX_STACK_LINE(86)
					::cocktail::core::css::CoreStyle _this = __this->coreStyle;		HX_STACK_VAR(_this,"_this");
					struct _Function_2_1{
						inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &_this){
							HX_STACK_PUSH("*::closure","cocktail/core/renderer/TextInputRenderer.hx",86);
							{
								HX_STACK_LINE(86)
								::cocktail::core::animation::Transition transition = _this->_transitionManager->getTransition((int)34,_this);		HX_STACK_VAR(transition,"transition");
								HX_STACK_LINE(86)
								return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) );
							}
							return null();
						}
					};
					HX_STACK_LINE(86)
					return (  (((_this->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((_this->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(_this->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_2_1::Block(_this)) )) );
				}
				return null();
			}
		};
		HX_STACK_LINE(86)
		this->nativeTextInput->set_fontSize(this->coreStyle->getAbsoluteLength(_Function_1_1::Block(this)));
		HX_STACK_LINE(88)
		bool bold = false;		HX_STACK_VAR(bold,"bold");
		HX_STACK_LINE(89)
		{
			::cocktail::core::css::CSSPropertyValue _switch_1 = (this->coreStyle->getComputedOrInitialProperty((int)35));
			switch((_switch_1)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(91)
						{
							::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
							switch((_switch_2)->GetIndex()){
								case 3: case 0: {
									HX_STACK_LINE(94)
									bold = false;
								}
								;break;
								case 2: case 1: {
									HX_STACK_LINE(97)
									bold = true;
								}
								;break;
								default: {
									HX_STACK_LINE(100)
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
						HX_STACK_LINE(104)
						bold = (value > (int)400);
					}
				}
				;break;
				default: {
					HX_STACK_LINE(107)
					hx::Throw (HX_CSTRING("Illegal value for bold style"));
				}
			}
		}
		HX_STACK_LINE(111)
		this->nativeTextInput->set_italic(bold);
		HX_STACK_LINE(112)
		this->nativeTextInput->set_italic((this->coreStyle->getKeyword(this->coreStyle->getComputedOrInitialProperty((int)36)) == ::cocktail::core::css::CSSKeywordValue_obj::ITALIC_dyn()));
		HX_STACK_LINE(113)
		this->nativeTextInput->set_letterSpacing(this->coreStyle->usedValues->letterSpacing);
		HX_STACK_LINE(114)
		this->nativeTextInput->set_color(this->coreStyle->usedValues->color->color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextInputRenderer_obj,updateNativeTextInput,(void))

Void TextInputRenderer_obj::renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset){
{
		HX_STACK_PUSH("TextInputRenderer::renderSelf","cocktail/core/renderer/TextInputRenderer.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(scrollOffset,"scrollOffset");
		HX_STACK_LINE(68)
		this->super::renderSelf(graphicContext,clipRect,scrollOffset);
		HX_STACK_LINE(69)
		this->updateNativeTextInput(scrollOffset,clipRect);
	}
return null();
}


Void TextInputRenderer_obj::createNativeInput( ){
{
		HX_STACK_PUSH("TextInputRenderer::createNativeInput","cocktail/core/renderer/TextInputRenderer.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_LINE(55)
		this->nativeTextInput = ::cocktail::port::platform::flash_player::NativeTextInput_obj::__new(this->domNode);
		HX_STACK_LINE(56)
		this->nativeInput = this->nativeTextInput;
	}
return null();
}



TextInputRenderer_obj::TextInputRenderer_obj()
{
}

void TextInputRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextInputRenderer);
	HX_MARK_MEMBER_NAME(nativeTextInput,"nativeTextInput");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextInputRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nativeTextInput,"nativeTextInput");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextInputRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"renderSelf") ) { return renderSelf_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nativeTextInput") ) { return nativeTextInput; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"createNativeInput") ) { return createNativeInput_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updateNativeTextInput") ) { return updateNativeTextInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextInputRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"nativeTextInput") ) { nativeTextInput=inValue.Cast< ::cocktail::port::platform::flash_player::NativeTextInput >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextInputRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nativeTextInput"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateNativeTextInput"),
	HX_CSTRING("renderSelf"),
	HX_CSTRING("createNativeInput"),
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
