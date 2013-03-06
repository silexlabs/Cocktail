#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
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
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#include <cocktail/core/invalidation/InvalidationManager.h>
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
#ifndef INCLUDED_cocktail_core_renderer_ImageRenderer
#include <cocktail/core/renderer/ImageRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_ResourceManager
#include <cocktail/core/resource/ResourceManager.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLImageElement_obj::__construct()
{
HX_STACK_PUSH("HTMLImageElement::new","cocktail/core/html/HTMLImageElement.hx",86);
{
	HX_STACK_LINE(86)
	super::__construct(HX_CSTRING("IMG"));
}
;
	return null();
}

HTMLImageElement_obj::~HTMLImageElement_obj() { }

Dynamic HTMLImageElement_obj::__CreateEmpty() { return  new HTMLImageElement_obj; }
hx::ObjectPtr< HTMLImageElement_obj > HTMLImageElement_obj::__new()
{  hx::ObjectPtr< HTMLImageElement_obj > result = new HTMLImageElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLImageElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLImageElement_obj > result = new HTMLImageElement_obj();
	result->__construct();
	return result;}

int HTMLImageElement_obj::get_naturalWidth( ){
	HX_STACK_PUSH("HTMLImageElement::get_naturalWidth","cocktail/core/html/HTMLImageElement.hx",237);
	HX_STACK_THIS(this);
	HX_STACK_LINE(238)
	if (((this->get_intrinsicWidth() == null()))){
		HX_STACK_LINE(239)
		return (int)0;
	}
	HX_STACK_LINE(242)
	return ::Math_obj::round(this->get_intrinsicWidth());
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_naturalWidth,return )

int HTMLImageElement_obj::get_naturalHeight( ){
	HX_STACK_PUSH("HTMLImageElement::get_naturalHeight","cocktail/core/html/HTMLImageElement.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_LINE(229)
	if (((this->get_intrinsicHeight() == null()))){
		HX_STACK_LINE(230)
		return (int)0;
	}
	HX_STACK_LINE(233)
	return ::Math_obj::round(this->get_intrinsicHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_naturalHeight,return )

::String HTMLImageElement_obj::get_src( ){
	HX_STACK_PUSH("HTMLImageElement::get_src","cocktail/core/html/HTMLImageElement.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_LINE(223)
	return this->getAttribute(HX_CSTRING("src"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_src,return )

Void HTMLImageElement_obj::onLoadError( ){
{
		HX_STACK_PUSH("HTMLImageElement::onLoadError","cocktail/core/html/HTMLImageElement.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_LINE(213)
		::cocktail::core::event::UIEvent errorEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
		HX_STACK_LINE(214)
		errorEvent->initUIEvent(HX_CSTRING("error"),false,false,null(),0.0);
		HX_STACK_LINE(215)
		this->dispatchEvent(errorEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,onLoadError,(void))

Void HTMLImageElement_obj::onLoadComplete( ::cocktail::core::resource::AbstractResource resource){
{
		HX_STACK_PUSH("HTMLImageElement::onLoadComplete","cocktail/core/html/HTMLImageElement.hx",185);
		HX_STACK_THIS(this);
		HX_STACK_ARG(resource,"resource");
		HX_STACK_LINE(186)
		this->intrinsicHeight = resource->intrinsicHeight;
		HX_STACK_LINE(187)
		this->intrinsicWidth = resource->intrinsicWidth;
		HX_STACK_LINE(188)
		this->intrinsicRatio = (Float(this->get_intrinsicHeight()) / Float(this->get_intrinsicWidth()));
		HX_STACK_LINE(192)
		if (((bool((this->getAttribute(HX_CSTRING("height")) != null())) && bool((this->getAttribute(HX_CSTRING("width")) != null()))))){
			HX_STACK_LINE(193)
			if (((this->elementRenderer != null()))){
				HX_STACK_LINE(195)
				this->_ownerHTMLDocument->invalidationManager->invalidateRendering(this->elementRenderer->hitTestingBounds);
			}
		}
		else{
			HX_STACK_LINE(202)
			this->invalidate();
		}
		HX_STACK_LINE(206)
		::cocktail::core::event::UIEvent loadEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(loadEvent,"loadEvent");
		HX_STACK_LINE(207)
		loadEvent->initUIEvent(HX_CSTRING("load"),false,false,null(),0.0);
		HX_STACK_LINE(208)
		this->dispatchEvent(loadEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,onLoadComplete,(void))

Void HTMLImageElement_obj::removeListeners( ::cocktail::core::event::EventTarget resource){
{
		HX_STACK_PUSH("HTMLImageElement::removeListeners","cocktail/core/html/HTMLImageElement.hx",179);
		HX_STACK_THIS(this);
		HX_STACK_ARG(resource,"resource");
		HX_STACK_LINE(180)
		resource->removeEventListener(HX_CSTRING("load"),this->_resourceLoadedCallback_dyn(),null());
		HX_STACK_LINE(181)
		resource->removeEventListener(HX_CSTRING("error"),this->_resourceLoadError_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,removeListeners,(void))

Void HTMLImageElement_obj::onResourceLoadError( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLImageElement::onResourceLoadError","cocktail/core/html/HTMLImageElement.hx",173);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(174)
		this->removeListeners(e->target);
		HX_STACK_LINE(175)
		this->onLoadError();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,onResourceLoadError,(void))

Void HTMLImageElement_obj::onResourceLoaded( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLImageElement::onResourceLoaded","cocktail/core/html/HTMLImageElement.hx",167);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(168)
		this->removeListeners(e->target);
		HX_STACK_LINE(169)
		this->onLoadComplete(e->target);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,onResourceLoaded,(void))

::String HTMLImageElement_obj::set_src( ::String value){
	HX_STACK_PUSH("HTMLImageElement::set_src","cocktail/core/html/HTMLImageElement.hx",139);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(140)
	this->super::setAttribute(HX_CSTRING("src"),value);
	HX_STACK_LINE(142)
	::cocktail::core::resource::AbstractResource resource = ::cocktail::core::resource::ResourceManager_obj::getImageResource(value);		HX_STACK_VAR(resource,"resource");
	HX_STACK_LINE(144)
	if (((resource->loaded == false))){
		HX_STACK_LINE(146)
		this->_resourceLoadedCallback = this->onResourceLoaded_dyn();
		HX_STACK_LINE(147)
		this->_resourceLoadError = this->onResourceLoadError_dyn();
		HX_STACK_LINE(148)
		resource->addEventListener(HX_CSTRING("load"),this->_resourceLoadedCallback_dyn(),null());
		HX_STACK_LINE(149)
		resource->addEventListener(HX_CSTRING("error"),this->_resourceLoadError_dyn(),null());
	}
	else{
		HX_STACK_LINE(152)
		if (((resource->loadedWithError == true))){
			HX_STACK_LINE(154)
			this->onLoadError();
		}
		else{
			HX_STACK_LINE(158)
			this->onLoadComplete(resource);
		}
	}
	HX_STACK_LINE(163)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,set_src,return )

bool HTMLImageElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLImageElement::isVoidElement","cocktail/core/html/HTMLImageElement.hx",127);
	HX_STACK_THIS(this);
	HX_STACK_LINE(127)
	return true;
}


Void HTMLImageElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLImageElement::createElementRenderer","cocktail/core/html/HTMLImageElement.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_LINE(114)
		this->elementRenderer = ::cocktail::core::renderer::ImageRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Void HTMLImageElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLImageElement::setAttribute","cocktail/core/html/HTMLImageElement.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(95)
		if (((name == HX_CSTRING("src")))){
			HX_STACK_LINE(97)
			this->set_src(value);
		}
		else{
			HX_STACK_LINE(101)
			this->super::setAttribute(name,value);
		}
	}
return null();
}



HTMLImageElement_obj::HTMLImageElement_obj()
{
}

void HTMLImageElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLImageElement);
	HX_MARK_MEMBER_NAME(_resourceLoadError,"_resourceLoadError");
	HX_MARK_MEMBER_NAME(_resourceLoadedCallback,"_resourceLoadedCallback");
	HX_MARK_MEMBER_NAME(naturalHeight,"naturalHeight");
	HX_MARK_MEMBER_NAME(naturalWidth,"naturalWidth");
	HX_MARK_MEMBER_NAME(src,"src");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLImageElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_resourceLoadError,"_resourceLoadError");
	HX_VISIT_MEMBER_NAME(_resourceLoadedCallback,"_resourceLoadedCallback");
	HX_VISIT_MEMBER_NAME(naturalHeight,"naturalHeight");
	HX_VISIT_MEMBER_NAME(naturalWidth,"naturalWidth");
	HX_VISIT_MEMBER_NAME(src,"src");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLImageElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return inCallProp ? get_src() : src; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_src") ) { return get_src_dyn(); }
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onLoadError") ) { return onLoadError_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"naturalWidth") ) { return inCallProp ? get_naturalWidth() : naturalWidth; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
		if (HX_FIELD_EQ(inName,"naturalHeight") ) { return inCallProp ? get_naturalHeight() : naturalHeight; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadComplete") ) { return onLoadComplete_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"removeListeners") ) { return removeListeners_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_naturalWidth") ) { return get_naturalWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"onResourceLoaded") ) { return onResourceLoaded_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_naturalHeight") ) { return get_naturalHeight_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_resourceLoadError") ) { return _resourceLoadError; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onResourceLoadError") ) { return onResourceLoadError_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_resourceLoadedCallback") ) { return _resourceLoadedCallback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLImageElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { if (inCallProp) return set_src(inValue);src=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"naturalWidth") ) { naturalWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"naturalHeight") ) { naturalHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_resourceLoadError") ) { _resourceLoadError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_resourceLoadedCallback") ) { _resourceLoadedCallback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLImageElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("naturalHeight"));
	outFields->push(HX_CSTRING("naturalWidth"));
	outFields->push(HX_CSTRING("src"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_naturalWidth"),
	HX_CSTRING("get_naturalHeight"),
	HX_CSTRING("get_src"),
	HX_CSTRING("onLoadError"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("removeListeners"),
	HX_CSTRING("onResourceLoadError"),
	HX_CSTRING("onResourceLoaded"),
	HX_CSTRING("set_src"),
	HX_CSTRING("isVoidElement"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("_resourceLoadError"),
	HX_CSTRING("_resourceLoadedCallback"),
	HX_CSTRING("naturalHeight"),
	HX_CSTRING("naturalWidth"),
	HX_CSTRING("src"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLImageElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLImageElement_obj::__mClass,"__mClass");
};

Class HTMLImageElement_obj::__mClass;

void HTMLImageElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLImageElement"), hx::TCanCast< HTMLImageElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLImageElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
