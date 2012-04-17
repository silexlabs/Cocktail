#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_Event
#include <core/event/Event.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLImageElement
#include <core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_resource_AbstractImageLoader
#include <core/resource/AbstractImageLoader.h>
#endif
#ifndef INCLUDED_core_resource_AbstractMediaLoader
#include <core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_core_resource_AbstractResourceLoader
#include <core/resource/AbstractResourceLoader.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_MediaLoader
#include <port/flash_player/MediaLoader.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace html{

Void AbstractHTMLImageElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",87)
	this->_imageLoader = ::core::resource::AbstractImageLoader_obj::__new();
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",88)
	super::__construct(HX_CSTRING("img"));
}
;
	return null();
}

AbstractHTMLImageElement_obj::~AbstractHTMLImageElement_obj() { }

Dynamic AbstractHTMLImageElement_obj::__CreateEmpty() { return  new AbstractHTMLImageElement_obj; }
hx::ObjectPtr< AbstractHTMLImageElement_obj > AbstractHTMLImageElement_obj::__new()
{  hx::ObjectPtr< AbstractHTMLImageElement_obj > result = new AbstractHTMLImageElement_obj();
	result->__construct();
	return result;}

Dynamic AbstractHTMLImageElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractHTMLImageElement_obj > result = new AbstractHTMLImageElement_obj();
	result->__construct();
	return result;}

Void AbstractHTMLImageElement_obj::initEmbeddedAsset( ){
{
		HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::initEmbeddedAsset")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",95)
		this->_embeddedAsset = this->_imageLoader->getNativeElement();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLImageElement_obj,initEmbeddedAsset,(void))

::String AbstractHTMLImageElement_obj::set_src( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::set_src")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",108)
	this->_src = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",109)
	this->_imageLoader->load(Array_obj< ::String >::__new().Add(value),this->onLoadComplete_dyn(),this->onLoadError_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",110)
	return this->_src;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLImageElement_obj,set_src,return )

Void AbstractHTMLImageElement_obj::onLoadComplete( Dynamic image){
{
		HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::onLoadComplete")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",124)
		this->_intrinsicHeight = this->_imageLoader->getIntrinsicHeight();
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",125)
		this->_intrinsicWidth = this->_imageLoader->getIntrinsicWidth();
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",126)
		this->_intrinsicRatio = (double(this->_intrinsicHeight) / double(this->_intrinsicWidth));
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",128)
		this->_style->invalidate();
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",131)
		if (((this->onLoad_dyn() != null()))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",133)
			::core::event::Event loadEvent = ::core::event::Event_obj::__new(HX_CSTRING("load"),hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",134)
			this->onLoad(loadEvent);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLImageElement_obj,onLoadComplete,(void))

Void AbstractHTMLImageElement_obj::onLoadError( ::String message){
{
		HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::onLoadError")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",147)
		if (((this->onError_dyn() != null()))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",149)
			this->onError(::core::event::Event_obj::__new(HX_CSTRING("error"),hx::ObjectPtr<OBJ_>(this)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLImageElement_obj,onLoadError,(void))

::String AbstractHTMLImageElement_obj::get_src( ){
	HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::get_src")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",159)
	return this->_src;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLImageElement_obj,get_src,return )

Dynamic AbstractHTMLImageElement_obj::get_naturalHeight( ){
	HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::get_naturalHeight")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",164)
	return this->_intrinsicHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLImageElement_obj,get_naturalHeight,return )

Dynamic AbstractHTMLImageElement_obj::get_naturalWidth( ){
	HX_SOURCE_PUSH("AbstractHTMLImageElement_obj::get_naturalWidth")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLImageElement.hx",169)
	return this->_intrinsicWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLImageElement_obj,get_naturalWidth,return )

::String AbstractHTMLImageElement_obj::HTML_IMAGE_TAG_NAME;


AbstractHTMLImageElement_obj::AbstractHTMLImageElement_obj()
{
}

void AbstractHTMLImageElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractHTMLImageElement);
	HX_MARK_MEMBER_NAME(onLoad,"onLoad");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(naturalWidth,"naturalWidth");
	HX_MARK_MEMBER_NAME(naturalHeight,"naturalHeight");
	HX_MARK_MEMBER_NAME(_src,"_src");
	HX_MARK_MEMBER_NAME(src,"src");
	HX_MARK_MEMBER_NAME(_imageLoader,"_imageLoader");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractHTMLImageElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return get_src(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_src") ) { return _src; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onLoad") ) { return onLoad; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { return onError; }
		if (HX_FIELD_EQ(inName,"set_src") ) { return set_src_dyn(); }
		if (HX_FIELD_EQ(inName,"get_src") ) { return get_src_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onLoadError") ) { return onLoadError_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"naturalWidth") ) { return get_naturalWidth(); }
		if (HX_FIELD_EQ(inName,"_imageLoader") ) { return _imageLoader; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"naturalHeight") ) { return get_naturalHeight(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadComplete") ) { return onLoadComplete_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_naturalWidth") ) { return get_naturalWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initEmbeddedAsset") ) { return initEmbeddedAsset_dyn(); }
		if (HX_FIELD_EQ(inName,"get_naturalHeight") ) { return get_naturalHeight_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_TAG_NAME") ) { return HTML_IMAGE_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic AbstractHTMLImageElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return set_src(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_src") ) { _src=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onLoad") ) { onLoad=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"naturalWidth") ) { naturalWidth=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_imageLoader") ) { _imageLoader=inValue.Cast< ::core::resource::AbstractImageLoader >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"naturalHeight") ) { naturalHeight=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_TAG_NAME") ) { HTML_IMAGE_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractHTMLImageElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("naturalWidth"));
	outFields->push(HX_CSTRING("naturalHeight"));
	outFields->push(HX_CSTRING("_src"));
	outFields->push(HX_CSTRING("src"));
	outFields->push(HX_CSTRING("_imageLoader"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_IMAGE_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onLoad"),
	HX_CSTRING("onError"),
	HX_CSTRING("naturalWidth"),
	HX_CSTRING("naturalHeight"),
	HX_CSTRING("_src"),
	HX_CSTRING("src"),
	HX_CSTRING("_imageLoader"),
	HX_CSTRING("initEmbeddedAsset"),
	HX_CSTRING("set_src"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("onLoadError"),
	HX_CSTRING("get_src"),
	HX_CSTRING("get_naturalHeight"),
	HX_CSTRING("get_naturalWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLImageElement_obj::HTML_IMAGE_TAG_NAME,"HTML_IMAGE_TAG_NAME");
};

Class AbstractHTMLImageElement_obj::__mClass;

void AbstractHTMLImageElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.html.AbstractHTMLImageElement"), hx::TCanCast< AbstractHTMLImageElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLImageElement_obj::__boot()
{
	hx::Static(HTML_IMAGE_TAG_NAME) = HX_CSTRING("img");
}

} // end namespace core
} // end namespace html
