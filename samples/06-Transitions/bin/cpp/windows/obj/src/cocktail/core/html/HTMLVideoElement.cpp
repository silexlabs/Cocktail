#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#include <cocktail/core/html/HTMLMediaElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLVideoElement
#include <cocktail/core/html/HTMLVideoElement.h>
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
#ifndef INCLUDED_cocktail_core_renderer_VideoRenderer
#include <cocktail/core/renderer/VideoRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLVideoElement_obj::__construct()
{
HX_STACK_PUSH("HTMLVideoElement::new","cocktail/core/html/HTMLVideoElement.hx",91);
{
	HX_STACK_LINE(92)
	super::__construct(HX_CSTRING("VIDEO"));
	HX_STACK_LINE(93)
	this->initPosterFrame();
}
;
	return null();
}

HTMLVideoElement_obj::~HTMLVideoElement_obj() { }

Dynamic HTMLVideoElement_obj::__CreateEmpty() { return  new HTMLVideoElement_obj; }
hx::ObjectPtr< HTMLVideoElement_obj > HTMLVideoElement_obj::__new()
{  hx::ObjectPtr< HTMLVideoElement_obj > result = new HTMLVideoElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLVideoElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLVideoElement_obj > result = new HTMLVideoElement_obj();
	result->__construct();
	return result;}

int HTMLVideoElement_obj::get_videoHeight( ){
	HX_STACK_PUSH("HTMLVideoElement::get_videoHeight","cocktail/core/html/HTMLVideoElement.hx",257);
	HX_STACK_THIS(this);
	HX_STACK_LINE(257)
	if (((this->nativeMedia->get_height() != null()))){
		HX_STACK_LINE(259)
		return ::Math_obj::round(this->nativeMedia->get_height());
	}
	else{
		HX_STACK_LINE(263)
		return (int)150;
	}
	HX_STACK_LINE(257)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,get_videoHeight,return )

int HTMLVideoElement_obj::get_videoWidth( ){
	HX_STACK_PUSH("HTMLVideoElement::get_videoWidth","cocktail/core/html/HTMLVideoElement.hx",242);
	HX_STACK_THIS(this);
	HX_STACK_LINE(242)
	if (((this->nativeMedia->get_width() != null()))){
		HX_STACK_LINE(244)
		return ::Math_obj::round(this->nativeMedia->get_width());
	}
	else{
		HX_STACK_LINE(248)
		return (int)300;
	}
	HX_STACK_LINE(242)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,get_videoWidth,return )

::String HTMLVideoElement_obj::get_poster( ){
	HX_STACK_PUSH("HTMLVideoElement::get_poster","cocktail/core/html/HTMLVideoElement.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_LINE(228)
	return this->getAttributeAsDOMString(HX_CSTRING("poster"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,get_poster,return )

::String HTMLVideoElement_obj::set_poster( ::String value){
	HX_STACK_PUSH("HTMLVideoElement::set_poster","cocktail/core/html/HTMLVideoElement.hx",216);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(217)
	this->super::setAttribute(HX_CSTRING("poster"),value);
	HX_STACK_LINE(219)
	this->_onPosterLoadComplete = this->onPosterLoadComplete_dyn();
	HX_STACK_LINE(220)
	this->_onPosterLoadError = this->onPosterLoadError_dyn();
	HX_STACK_LINE(221)
	this->_posterImage->addEventListener(HX_CSTRING("load"),this->_onPosterLoadComplete_dyn(),null());
	HX_STACK_LINE(222)
	this->_posterImage->addEventListener(HX_CSTRING("error"),this->_onPosterLoadError_dyn(),null());
	HX_STACK_LINE(223)
	this->_posterImage->set_src(value);
	HX_STACK_LINE(224)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLVideoElement_obj,set_poster,return )

Void HTMLVideoElement_obj::removeListeners( ){
{
		HX_STACK_PUSH("HTMLVideoElement::removeListeners","cocktail/core/html/HTMLVideoElement.hx",203);
		HX_STACK_THIS(this);
		HX_STACK_LINE(204)
		this->_posterImage->removeEventListener(HX_CSTRING("load"),this->_onPosterLoadComplete_dyn(),null());
		HX_STACK_LINE(205)
		this->_posterImage->removeEventListener(HX_CSTRING("error"),this->_onPosterLoadError_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,removeListeners,(void))

Void HTMLVideoElement_obj::onPosterLoadError( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLVideoElement::onPosterLoadError","cocktail/core/html/HTMLVideoElement.hx",195);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(195)
		this->removeListeners();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLVideoElement_obj,onPosterLoadError,(void))

Void HTMLVideoElement_obj::onPosterLoadComplete( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("HTMLVideoElement::onPosterLoadComplete","cocktail/core/html/HTMLVideoElement.hx",185);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(186)
		this->removeListeners();
		HX_STACK_LINE(187)
		this->invalidate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLVideoElement_obj,onPosterLoadComplete,(void))

bool HTMLVideoElement_obj::shouldRenderPosterFrame( ){
	HX_STACK_PUSH("HTMLVideoElement::shouldRenderPosterFrame","cocktail/core/html/HTMLVideoElement.hx",151);
	HX_STACK_THIS(this);
	HX_STACK_LINE(153)
	if (((this->get_poster() == HX_CSTRING("")))){
		HX_STACK_LINE(154)
		return false;
	}
	HX_STACK_LINE(158)
	switch( (int)(this->readyState)){
		case (int)0: case (int)1: {
			HX_STACK_LINE(161)
			return true;
		}
		;break;
	}
	HX_STACK_LINE(168)
	if (((bool((this->paused == true)) && bool((this->_currentPlaybackPosition == 0.0))))){
		HX_STACK_LINE(169)
		return true;
	}
	HX_STACK_LINE(173)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,shouldRenderPosterFrame,return )

Void HTMLVideoElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLVideoElement::createElementRenderer","cocktail/core/html/HTMLVideoElement.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_LINE(136)
		this->elementRenderer = ::cocktail::core::renderer::VideoRenderer_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Void HTMLVideoElement_obj::setAttribute( ::String name,::String value){
{
		HX_STACK_PUSH("HTMLVideoElement::setAttribute","cocktail/core/html/HTMLVideoElement.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_ARG(name,"name");
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(117)
		if (((name == HX_CSTRING("poster")))){
			HX_STACK_LINE(119)
			this->set_poster(value);
		}
		else{
			HX_STACK_LINE(123)
			this->super::setAttribute(name,value);
		}
	}
return null();
}


Void HTMLVideoElement_obj::initPosterFrame( ){
{
		HX_STACK_PUSH("HTMLVideoElement::initPosterFrame","cocktail/core/html/HTMLVideoElement.hx",108);
		HX_STACK_THIS(this);
		HX_STACK_LINE(108)
		this->_posterImage = ::cocktail::core::html::HTMLImageElement_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLVideoElement_obj,initPosterFrame,(void))

Void HTMLVideoElement_obj::initNativeMedia( ){
{
		HX_STACK_PUSH("HTMLVideoElement::initNativeMedia","cocktail/core/html/HTMLVideoElement.hx",100);
		HX_STACK_THIS(this);
		HX_STACK_LINE(100)
		this->nativeMedia = ::cocktail::port::base::NativeMedia_obj::__new();
	}
return null();
}


int HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_WIDTH;

int HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_HEIGHT;


HTMLVideoElement_obj::HTMLVideoElement_obj()
{
}

void HTMLVideoElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLVideoElement);
	HX_MARK_MEMBER_NAME(videoHeight,"videoHeight");
	HX_MARK_MEMBER_NAME(videoWidth,"videoWidth");
	HX_MARK_MEMBER_NAME(_onPosterLoadError,"_onPosterLoadError");
	HX_MARK_MEMBER_NAME(_onPosterLoadComplete,"_onPosterLoadComplete");
	HX_MARK_MEMBER_NAME(posterFrameEmbeddedAsset,"posterFrameEmbeddedAsset");
	HX_MARK_MEMBER_NAME(_posterImage,"_posterImage");
	HX_MARK_MEMBER_NAME(poster,"poster");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLVideoElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(videoHeight,"videoHeight");
	HX_VISIT_MEMBER_NAME(videoWidth,"videoWidth");
	HX_VISIT_MEMBER_NAME(_onPosterLoadError,"_onPosterLoadError");
	HX_VISIT_MEMBER_NAME(_onPosterLoadComplete,"_onPosterLoadComplete");
	HX_VISIT_MEMBER_NAME(posterFrameEmbeddedAsset,"posterFrameEmbeddedAsset");
	HX_VISIT_MEMBER_NAME(_posterImage,"_posterImage");
	HX_VISIT_MEMBER_NAME(poster,"poster");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLVideoElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"poster") ) { return inCallProp ? get_poster() : poster; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_poster") ) { return get_poster_dyn(); }
		if (HX_FIELD_EQ(inName,"set_poster") ) { return set_poster_dyn(); }
		if (HX_FIELD_EQ(inName,"videoWidth") ) { return inCallProp ? get_videoWidth() : videoWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"videoHeight") ) { return inCallProp ? get_videoHeight() : videoHeight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
		if (HX_FIELD_EQ(inName,"_posterImage") ) { return _posterImage; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_videoWidth") ) { return get_videoWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_videoHeight") ) { return get_videoHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"removeListeners") ) { return removeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"initPosterFrame") ) { return initPosterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"initNativeMedia") ) { return initNativeMedia_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onPosterLoadError") ) { return onPosterLoadError_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_onPosterLoadError") ) { return _onPosterLoadError; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"onPosterLoadComplete") ) { return onPosterLoadComplete_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
		if (HX_FIELD_EQ(inName,"_onPosterLoadComplete") ) { return _onPosterLoadComplete; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"shouldRenderPosterFrame") ) { return shouldRenderPosterFrame_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"HTML_VIDEO_DEFAULT_WIDTH") ) { return HTML_VIDEO_DEFAULT_WIDTH; }
		if (HX_FIELD_EQ(inName,"posterFrameEmbeddedAsset") ) { return posterFrameEmbeddedAsset; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"HTML_VIDEO_DEFAULT_HEIGHT") ) { return HTML_VIDEO_DEFAULT_HEIGHT; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLVideoElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"poster") ) { if (inCallProp) return set_poster(inValue);poster=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"videoWidth") ) { videoWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"videoHeight") ) { videoHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_posterImage") ) { _posterImage=inValue.Cast< ::cocktail::core::html::HTMLImageElement >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_onPosterLoadError") ) { _onPosterLoadError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_onPosterLoadComplete") ) { _onPosterLoadComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"HTML_VIDEO_DEFAULT_WIDTH") ) { HTML_VIDEO_DEFAULT_WIDTH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"posterFrameEmbeddedAsset") ) { posterFrameEmbeddedAsset=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"HTML_VIDEO_DEFAULT_HEIGHT") ) { HTML_VIDEO_DEFAULT_HEIGHT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLVideoElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("videoHeight"));
	outFields->push(HX_CSTRING("videoWidth"));
	outFields->push(HX_CSTRING("posterFrameEmbeddedAsset"));
	outFields->push(HX_CSTRING("_posterImage"));
	outFields->push(HX_CSTRING("poster"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_VIDEO_DEFAULT_WIDTH"),
	HX_CSTRING("HTML_VIDEO_DEFAULT_HEIGHT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_videoHeight"),
	HX_CSTRING("get_videoWidth"),
	HX_CSTRING("get_poster"),
	HX_CSTRING("set_poster"),
	HX_CSTRING("removeListeners"),
	HX_CSTRING("onPosterLoadError"),
	HX_CSTRING("onPosterLoadComplete"),
	HX_CSTRING("shouldRenderPosterFrame"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("initPosterFrame"),
	HX_CSTRING("initNativeMedia"),
	HX_CSTRING("videoHeight"),
	HX_CSTRING("videoWidth"),
	HX_CSTRING("_onPosterLoadError"),
	HX_CSTRING("_onPosterLoadComplete"),
	HX_CSTRING("posterFrameEmbeddedAsset"),
	HX_CSTRING("_posterImage"),
	HX_CSTRING("poster"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLVideoElement_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_WIDTH,"HTML_VIDEO_DEFAULT_WIDTH");
	HX_MARK_MEMBER_NAME(HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_HEIGHT,"HTML_VIDEO_DEFAULT_HEIGHT");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLVideoElement_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_WIDTH,"HTML_VIDEO_DEFAULT_WIDTH");
	HX_VISIT_MEMBER_NAME(HTMLVideoElement_obj::HTML_VIDEO_DEFAULT_HEIGHT,"HTML_VIDEO_DEFAULT_HEIGHT");
};

Class HTMLVideoElement_obj::__mClass;

void HTMLVideoElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLVideoElement"), hx::TCanCast< HTMLVideoElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLVideoElement_obj::__boot()
{
	HTML_VIDEO_DEFAULT_WIDTH= (int)300;
	HTML_VIDEO_DEFAULT_HEIGHT= (int)150;
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
