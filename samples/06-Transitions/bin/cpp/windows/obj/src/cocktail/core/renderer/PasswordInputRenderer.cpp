#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_renderer_PasswordInputRenderer
#include <cocktail/core/renderer/PasswordInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextInputRenderer
#include <cocktail/core/renderer/TextInputRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativePasswordInput
#include <cocktail/port/platform/flash_player/NativePasswordInput.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void PasswordInputRenderer_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("PasswordInputRenderer::new","cocktail/core/renderer/PasswordInputRenderer.hx",26);
{
	HX_STACK_LINE(26)
	super::__construct(node);
}
;
	return null();
}

PasswordInputRenderer_obj::~PasswordInputRenderer_obj() { }

Dynamic PasswordInputRenderer_obj::__CreateEmpty() { return  new PasswordInputRenderer_obj; }
hx::ObjectPtr< PasswordInputRenderer_obj > PasswordInputRenderer_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< PasswordInputRenderer_obj > result = new PasswordInputRenderer_obj();
	result->__construct(node);
	return result;}

Dynamic PasswordInputRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PasswordInputRenderer_obj > result = new PasswordInputRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PasswordInputRenderer_obj::createNativeInput( ){
{
		HX_STACK_PUSH("PasswordInputRenderer::createNativeInput","cocktail/core/renderer/PasswordInputRenderer.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_LINE(35)
		this->nativeTextInput = ::cocktail::port::platform::flash_player::NativePasswordInput_obj::__new(this->domNode);
		HX_STACK_LINE(36)
		this->nativeInput = this->nativeTextInput;
	}
return null();
}



PasswordInputRenderer_obj::PasswordInputRenderer_obj()
{
}

void PasswordInputRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PasswordInputRenderer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PasswordInputRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic PasswordInputRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"createNativeInput") ) { return createNativeInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PasswordInputRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PasswordInputRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createNativeInput"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PasswordInputRenderer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PasswordInputRenderer_obj::__mClass,"__mClass");
};

Class PasswordInputRenderer_obj::__mClass;

void PasswordInputRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.PasswordInputRenderer"), hx::TCanCast< PasswordInputRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PasswordInputRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
