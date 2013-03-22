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
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_graphics_GraphicsContext
#include <cocktail/core/graphics/GraphicsContext.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
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
namespace port{
namespace base{

Void NativeInputBase_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("NativeInputBase::new","cocktail/port/base/NativeInputBase.hx",96);
{
	HX_STACK_LINE(96)
	this->_node = node;
}
;
	return null();
}

NativeInputBase_obj::~NativeInputBase_obj() { }

Dynamic NativeInputBase_obj::__CreateEmpty() { return  new NativeInputBase_obj; }
hx::ObjectPtr< NativeInputBase_obj > NativeInputBase_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< NativeInputBase_obj > result = new NativeInputBase_obj();
	result->__construct(node);
	return result;}

Dynamic NativeInputBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeInputBase_obj > result = new NativeInputBase_obj();
	result->__construct(inArgs[0]);
	return result;}

int NativeInputBase_obj::get_intrinsicHeight( ){
	HX_STACK_PUSH("NativeInputBase::get_intrinsicHeight","cocktail/port/base/NativeInputBase.hx",218);
	HX_STACK_THIS(this);
	HX_STACK_LINE(218)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_intrinsicHeight,return )

int NativeInputBase_obj::get_intrinsicWidth( ){
	HX_STACK_PUSH("NativeInputBase::get_intrinsicWidth","cocktail/port/base/NativeInputBase.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_LINE(213)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_intrinsicWidth,return )

bool NativeInputBase_obj::set_readonly( bool value){
	HX_STACK_PUSH("NativeInputBase::set_readonly","cocktail/port/base/NativeInputBase.hx",208);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(208)
	return this->readonly = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_readonly,return )

bool NativeInputBase_obj::set_disabled( bool value){
	HX_STACK_PUSH("NativeInputBase::set_disabled","cocktail/port/base/NativeInputBase.hx",203);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(203)
	return this->disabled = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_disabled,return )

int NativeInputBase_obj::set_maxLength( int value){
	HX_STACK_PUSH("NativeInputBase::set_maxLength","cocktail/port/base/NativeInputBase.hx",198);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(198)
	return this->maxLength = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_maxLength,return )

bool NativeInputBase_obj::set_checked( bool value){
	HX_STACK_PUSH("NativeInputBase::set_checked","cocktail/port/base/NativeInputBase.hx",193);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(193)
	return this->checked = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_checked,return )

bool NativeInputBase_obj::get_checked( ){
	HX_STACK_PUSH("NativeInputBase::get_checked","cocktail/port/base/NativeInputBase.hx",188);
	HX_STACK_THIS(this);
	HX_STACK_LINE(188)
	return this->checked;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_checked,return )

::String NativeInputBase_obj::set_value( ::String textValue){
	HX_STACK_PUSH("NativeInputBase::set_value","cocktail/port/base/NativeInputBase.hx",183);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textValue,"textValue");
	HX_STACK_LINE(183)
	return this->value = textValue;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_value,return )

::String NativeInputBase_obj::get_value( ){
	HX_STACK_PUSH("NativeInputBase::get_value","cocktail/port/base/NativeInputBase.hx",178);
	HX_STACK_THIS(this);
	HX_STACK_LINE(178)
	return this->value;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_value,return )

::cocktail::core::geom::RectangleVO NativeInputBase_obj::set_clipRect( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeInputBase::set_clipRect","cocktail/port/base/NativeInputBase.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(173)
	return this->clipRect = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_clipRect,return )

::cocktail::core::geom::RectangleVO NativeInputBase_obj::get_clipRect( ){
	HX_STACK_PUSH("NativeInputBase::get_clipRect","cocktail/port/base/NativeInputBase.hx",168);
	HX_STACK_THIS(this);
	HX_STACK_LINE(168)
	return this->clipRect;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_clipRect,return )

::cocktail::core::geom::RectangleVO NativeInputBase_obj::set_viewport( ::cocktail::core::geom::RectangleVO value){
	HX_STACK_PUSH("NativeInputBase::set_viewport","cocktail/port/base/NativeInputBase.hx",163);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(163)
	return this->viewport = value;
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,set_viewport,return )

::cocktail::core::geom::RectangleVO NativeInputBase_obj::get_viewport( ){
	HX_STACK_PUSH("NativeInputBase::get_viewport","cocktail/port/base/NativeInputBase.hx",158);
	HX_STACK_THIS(this);
	HX_STACK_LINE(158)
	return this->viewport;
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,get_viewport,return )

Void NativeInputBase_obj::dispose( ){
{
		HX_STACK_PUSH("NativeInputBase::dispose","cocktail/port/base/NativeInputBase.hx",149);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,dispose,(void))

Void NativeInputBase_obj::blur( ){
{
		HX_STACK_PUSH("NativeInputBase::blur","cocktail/port/base/NativeInputBase.hx",140);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,blur,(void))

Void NativeInputBase_obj::focus( ){
{
		HX_STACK_PUSH("NativeInputBase::focus","cocktail/port/base/NativeInputBase.hx",129);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(NativeInputBase_obj,focus,(void))

Void NativeInputBase_obj::detach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeInputBase::detach","cocktail/port/base/NativeInputBase.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,detach,(void))

Void NativeInputBase_obj::attach( ::cocktail::core::graphics::GraphicsContext graphicContext){
{
		HX_STACK_PUSH("NativeInputBase::attach","cocktail/port/base/NativeInputBase.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(graphicContext,"graphicContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(NativeInputBase_obj,attach,(void))


NativeInputBase_obj::NativeInputBase_obj()
{
}

void NativeInputBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeInputBase);
	HX_MARK_MEMBER_NAME(_node,"_node");
	HX_MARK_MEMBER_NAME(onInput,"onInput");
	HX_MARK_MEMBER_NAME(onActivate,"onActivate");
	HX_MARK_MEMBER_NAME(clipRect,"clipRect");
	HX_MARK_MEMBER_NAME(viewport,"viewport");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(readonly,"readonly");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(checked,"checked");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void NativeInputBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_node,"_node");
	HX_VISIT_MEMBER_NAME(onInput,"onInput");
	HX_VISIT_MEMBER_NAME(onActivate,"onActivate");
	HX_VISIT_MEMBER_NAME(clipRect,"clipRect");
	HX_VISIT_MEMBER_NAME(viewport,"viewport");
	HX_VISIT_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_VISIT_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_VISIT_MEMBER_NAME(readonly,"readonly");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	HX_VISIT_MEMBER_NAME(maxLength,"maxLength");
	HX_VISIT_MEMBER_NAME(checked,"checked");
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic NativeInputBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"blur") ) { return blur_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"focus") ) { return focus_dyn(); }
		if (HX_FIELD_EQ(inName,"_node") ) { return _node; }
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"detach") ) { return detach_dyn(); }
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"onInput") ) { return onInput; }
		if (HX_FIELD_EQ(inName,"checked") ) { return inCallProp ? get_checked() : checked; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipRect") ) { return inCallProp ? get_clipRect() : clipRect; }
		if (HX_FIELD_EQ(inName,"viewport") ) { return inCallProp ? get_viewport() : viewport; }
		if (HX_FIELD_EQ(inName,"readonly") ) { return readonly; }
		if (HX_FIELD_EQ(inName,"disabled") ) { return disabled; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return maxLength; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onActivate") ) { return onActivate; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_checked") ) { return set_checked_dyn(); }
		if (HX_FIELD_EQ(inName,"get_checked") ) { return get_checked_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_readonly") ) { return set_readonly_dyn(); }
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clipRect") ) { return set_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clipRect") ) { return get_clipRect_dyn(); }
		if (HX_FIELD_EQ(inName,"set_viewport") ) { return set_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_viewport") ) { return get_viewport_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return inCallProp ? get_intrinsicWidth() : intrinsicWidth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return inCallProp ? get_intrinsicHeight() : intrinsicHeight; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeInputBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_node") ) { _node=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		if (HX_FIELD_EQ(inName,"value") ) { if (inCallProp) return set_value(inValue);value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onInput") ) { onInput=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"checked") ) { if (inCallProp) return set_checked(inValue);checked=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"clipRect") ) { if (inCallProp) return set_clipRect(inValue);clipRect=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"viewport") ) { if (inCallProp) return set_viewport(inValue);viewport=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		if (HX_FIELD_EQ(inName,"readonly") ) { if (inCallProp) return set_readonly(inValue);readonly=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disabled") ) { if (inCallProp) return set_disabled(inValue);disabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxLength") ) { if (inCallProp) return set_maxLength(inValue);maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onActivate") ) { onActivate=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeInputBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_node"));
	outFields->push(HX_CSTRING("clipRect"));
	outFields->push(HX_CSTRING("viewport"));
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
	HX_CSTRING("set_readonly"),
	HX_CSTRING("set_disabled"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("set_checked"),
	HX_CSTRING("get_checked"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("set_clipRect"),
	HX_CSTRING("get_clipRect"),
	HX_CSTRING("set_viewport"),
	HX_CSTRING("get_viewport"),
	HX_CSTRING("dispose"),
	HX_CSTRING("blur"),
	HX_CSTRING("focus"),
	HX_CSTRING("detach"),
	HX_CSTRING("attach"),
	HX_CSTRING("_node"),
	HX_CSTRING("onInput"),
	HX_CSTRING("onActivate"),
	HX_CSTRING("clipRect"),
	HX_CSTRING("viewport"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("readonly"),
	HX_CSTRING("disabled"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("checked"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeInputBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeInputBase_obj::__mClass,"__mClass");
};

Class NativeInputBase_obj::__mClass;

void NativeInputBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.NativeInputBase"), hx::TCanCast< NativeInputBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeInputBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
