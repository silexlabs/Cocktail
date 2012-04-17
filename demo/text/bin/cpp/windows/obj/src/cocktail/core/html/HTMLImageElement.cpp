#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Attr
#include <cocktail/core/dom/Attr.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_NamedNodeMap
#include <cocktail/core/dom/NamedNodeMap.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
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
#ifndef INCLUDED_cocktail_core_resource_AbstractImageLoader
#include <cocktail/core/resource/AbstractImageLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractMediaLoader
#include <cocktail/core/resource/AbstractMediaLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResourceLoader
#include <cocktail/core/resource/AbstractResourceLoader.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_MediaLoader
#include <cocktail/port/flash_player/MediaLoader.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLImageElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",97)
	this->_imageLoader = ::cocktail::core::resource::AbstractImageLoader_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",98)
	super::__construct(HX_CSTRING("img"));
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

Void HTMLImageElement_obj::initEmbeddedAsset( ){
{
		HX_SOURCE_PUSH("HTMLImageElement_obj::initEmbeddedAsset")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",105)
		this->_embeddedAsset = this->_imageLoader->getNativeElement();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,initEmbeddedAsset,(void))

Void HTMLImageElement_obj::setAttribute( ::String name,::String value){
{
		HX_SOURCE_PUSH("HTMLImageElement_obj::setAttribute")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",114)
		if (((name == HX_CSTRING("src")))){
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",116)
			this->set_src(value);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",120)
			this->super::setAttribute(name,value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(HTMLImageElement_obj,setAttribute,(void))

::String HTMLImageElement_obj::set_src( ::String value){
	HX_SOURCE_PUSH("HTMLImageElement_obj::set_src")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",134)
	::cocktail::core::dom::Node srcAttr = this->_attributes->getNamedItem(HX_CSTRING("src"));
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",135)
	if (((srcAttr == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",137)
		srcAttr = ::cocktail::core::dom::Attr_obj::__new(HX_CSTRING("src"));
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",138)
		this->_attributes->setNamedItem(srcAttr);
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",140)
	srcAttr->set_nodeValue(value);
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",142)
	this->_imageLoader->load(Array_obj< ::String >::__new().Add(value),this->onLoadComplete_dyn(),this->onLoadError_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",143)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,set_src,return )

Void HTMLImageElement_obj::onLoadComplete( Dynamic image){
{
		HX_SOURCE_PUSH("HTMLImageElement_obj::onLoadComplete")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",157)
		this->_intrinsicHeight = this->_imageLoader->getIntrinsicHeight();
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",158)
		this->_intrinsicWidth = this->_imageLoader->getIntrinsicWidth();
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",159)
		this->_intrinsicRatio = (double(this->_intrinsicHeight) / double(this->_intrinsicWidth));
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",161)
		this->_coreStyle->invalidate(null());
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",164)
		if (((this->onload_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",166)
			::cocktail::core::event::Event loadEvent = ::cocktail::core::event::Event_obj::__new(HX_CSTRING("load"),hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",167)
			this->onload(loadEvent);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,onLoadComplete,(void))

Void HTMLImageElement_obj::onLoadError( ::String message){
{
		HX_SOURCE_PUSH("HTMLImageElement_obj::onLoadError")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",178)
		if (((this->onError_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",180)
			this->onError(::cocktail::core::event::Event_obj::__new(HX_CSTRING("error"),hx::ObjectPtr<OBJ_>(this)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLImageElement_obj,onLoadError,(void))

::String HTMLImageElement_obj::get_src( ){
	HX_SOURCE_PUSH("HTMLImageElement_obj::get_src")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",190)
	return this->getAttribute(HX_CSTRING("src"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_src,return )

int HTMLImageElement_obj::get_naturalHeight( ){
	HX_SOURCE_PUSH("HTMLImageElement_obj::get_naturalHeight")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",196)
	if (((this->_intrinsicHeight == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",197)
		return (int)0;
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",200)
	return this->_intrinsicHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_naturalHeight,return )

int HTMLImageElement_obj::get_naturalWidth( ){
	HX_SOURCE_PUSH("HTMLImageElement_obj::get_naturalWidth")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",205)
	if (((this->_intrinsicWidth == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",206)
		return (int)0;
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLImageElement.hx",209)
	return this->_intrinsicWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLImageElement_obj,get_naturalWidth,return )

::String HTMLImageElement_obj::HTML_IMAGE_TAG_NAME;

::String HTMLImageElement_obj::HTML_IMAGE_SRC_ATTRIBUTE;


HTMLImageElement_obj::HTMLImageElement_obj()
{
}

void HTMLImageElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLImageElement);
	HX_MARK_MEMBER_NAME(onload,"onload");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(naturalWidth,"naturalWidth");
	HX_MARK_MEMBER_NAME(naturalHeight,"naturalHeight");
	HX_MARK_MEMBER_NAME(src,"src");
	HX_MARK_MEMBER_NAME(_imageLoader,"_imageLoader");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLImageElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return get_src(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onload") ) { return onload; }
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
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
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
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_SRC_ATTRIBUTE") ) { return HTML_IMAGE_SRC_ATTRIBUTE; }
	}
	return super::__Field(inName);
}

Dynamic HTMLImageElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"src") ) { return set_src(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onload") ) { onload=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"naturalWidth") ) { naturalWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_imageLoader") ) { _imageLoader=inValue.Cast< ::cocktail::core::resource::AbstractImageLoader >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"naturalHeight") ) { naturalHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_TAG_NAME") ) { HTML_IMAGE_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_SRC_ATTRIBUTE") ) { HTML_IMAGE_SRC_ATTRIBUTE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLImageElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("naturalWidth"));
	outFields->push(HX_CSTRING("naturalHeight"));
	outFields->push(HX_CSTRING("src"));
	outFields->push(HX_CSTRING("_imageLoader"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_IMAGE_TAG_NAME"),
	HX_CSTRING("HTML_IMAGE_SRC_ATTRIBUTE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onload"),
	HX_CSTRING("onError"),
	HX_CSTRING("naturalWidth"),
	HX_CSTRING("naturalHeight"),
	HX_CSTRING("src"),
	HX_CSTRING("_imageLoader"),
	HX_CSTRING("initEmbeddedAsset"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("set_src"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("onLoadError"),
	HX_CSTRING("get_src"),
	HX_CSTRING("get_naturalHeight"),
	HX_CSTRING("get_naturalWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLImageElement_obj::HTML_IMAGE_TAG_NAME,"HTML_IMAGE_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLImageElement_obj::HTML_IMAGE_SRC_ATTRIBUTE,"HTML_IMAGE_SRC_ATTRIBUTE");
};

Class HTMLImageElement_obj::__mClass;

void HTMLImageElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLImageElement"), hx::TCanCast< HTMLImageElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLImageElement_obj::__boot()
{
	hx::Static(HTML_IMAGE_TAG_NAME) = HX_CSTRING("img");
	hx::Static(HTML_IMAGE_SRC_ATTRIBUTE) = HX_CSTRING("src");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
