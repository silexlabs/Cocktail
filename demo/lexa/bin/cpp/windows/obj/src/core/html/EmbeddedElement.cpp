#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_style_AbstractEmbeddedStyle
#include <core/style/AbstractEmbeddedStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace html{

Void EmbeddedElement_obj::__construct(::String tagName)
{
{
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",75)
	super::__construct(tagName);
}
;
	return null();
}

EmbeddedElement_obj::~EmbeddedElement_obj() { }

Dynamic EmbeddedElement_obj::__CreateEmpty() { return  new EmbeddedElement_obj; }
hx::ObjectPtr< EmbeddedElement_obj > EmbeddedElement_obj::__new(::String tagName)
{  hx::ObjectPtr< EmbeddedElement_obj > result = new EmbeddedElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic EmbeddedElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedElement_obj > result = new EmbeddedElement_obj();
	result->__construct(inArgs[0]);
	return result;}

Void EmbeddedElement_obj::init( ){
{
		HX_SOURCE_PUSH("EmbeddedElement_obj::init")
		HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",81)
		this->initEmbeddedAsset();
		HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",82)
		this->super::init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,init,(void))

Void EmbeddedElement_obj::initEmbeddedAsset( ){
{
		HX_SOURCE_PUSH("EmbeddedElement_obj::initEmbeddedAsset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,initEmbeddedAsset,(void))

Void EmbeddedElement_obj::initStyle( ){
{
		HX_SOURCE_PUSH("EmbeddedElement_obj::initStyle")
		HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",98)
		this->_style = ::core::style::AbstractEmbeddedStyle_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,initStyle,(void))

::core::dom::Node EmbeddedElement_obj::appendChild( ::core::dom::Node newChild){
	HX_SOURCE_PUSH("EmbeddedElement_obj::appendChild")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",110)
	return newChild;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,appendChild,return )

::core::dom::Node EmbeddedElement_obj::removeChild( ::core::dom::Node oldChild){
	HX_SOURCE_PUSH("EmbeddedElement_obj::removeChild")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",120)
	return oldChild;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,removeChild,return )

Dynamic EmbeddedElement_obj::get_embeddedAsset( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_embeddedAsset")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",130)
	return this->_embeddedAsset;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_embeddedAsset,return )

Dynamic EmbeddedElement_obj::get_intrinsicHeight( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_intrinsicHeight")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",135)
	return this->_intrinsicHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicHeight,return )

Dynamic EmbeddedElement_obj::get_intrinsicWidth( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_intrinsicWidth")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",140)
	return this->_intrinsicWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicWidth,return )

Dynamic EmbeddedElement_obj::get_intrinsicRatio( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_intrinsicRatio")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",145)
	return this->_intrinsicRatio;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_intrinsicRatio,return )

int EmbeddedElement_obj::set_width( int value){
	HX_SOURCE_PUSH("EmbeddedElement_obj::set_width")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",152)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,set_width,return )

int EmbeddedElement_obj::get_width( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_width")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",157)
	return this->_width;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_width,return )

int EmbeddedElement_obj::set_height( int value){
	HX_SOURCE_PUSH("EmbeddedElement_obj::set_height")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",162)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(EmbeddedElement_obj,set_height,return )

int EmbeddedElement_obj::get_height( ){
	HX_SOURCE_PUSH("EmbeddedElement_obj::get_height")
	HX_SOURCE_POS("../../src/core/html/EmbeddedElement.hx",167)
	return this->_height;
}


HX_DEFINE_DYNAMIC_FUNC0(EmbeddedElement_obj,get_height,return )


EmbeddedElement_obj::EmbeddedElement_obj()
{
}

void EmbeddedElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedElement);
	HX_MARK_MEMBER_NAME(_intrinsicHeight,"_intrinsicHeight");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(_intrinsicWidth,"_intrinsicWidth");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(_intrinsicRatio,"_intrinsicRatio");
	HX_MARK_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(_embeddedAsset,"_embeddedAsset");
	HX_MARK_MEMBER_NAME(embeddedAsset,"embeddedAsset");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"initStyle") ) { return initStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"embeddedAsset") ) { return get_embeddedAsset(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return get_intrinsicWidth(); }
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { return get_intrinsicRatio(); }
		if (HX_FIELD_EQ(inName,"_embeddedAsset") ) { return _embeddedAsset; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return get_intrinsicHeight(); }
		if (HX_FIELD_EQ(inName,"_intrinsicWidth") ) { return _intrinsicWidth; }
		if (HX_FIELD_EQ(inName,"_intrinsicRatio") ) { return _intrinsicRatio; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intrinsicHeight") ) { return _intrinsicHeight; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initEmbeddedAsset") ) { return initEmbeddedAsset_dyn(); }
		if (HX_FIELD_EQ(inName,"get_embeddedAsset") ) { return get_embeddedAsset_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_intrinsicWidth") ) { return get_intrinsicWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_intrinsicRatio") ) { return get_intrinsicRatio_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_intrinsicHeight") ) { return get_intrinsicHeight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EmbeddedElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"embeddedAsset") ) { embeddedAsset=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { intrinsicRatio=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_embeddedAsset") ) { _embeddedAsset=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_intrinsicWidth") ) { _intrinsicWidth=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_intrinsicRatio") ) { _intrinsicRatio=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_intrinsicHeight") ) { _intrinsicHeight=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EmbeddedElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_intrinsicHeight"));
	outFields->push(HX_CSTRING("intrinsicHeight"));
	outFields->push(HX_CSTRING("_intrinsicWidth"));
	outFields->push(HX_CSTRING("intrinsicWidth"));
	outFields->push(HX_CSTRING("_intrinsicRatio"));
	outFields->push(HX_CSTRING("intrinsicRatio"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("_embeddedAsset"));
	outFields->push(HX_CSTRING("embeddedAsset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_intrinsicHeight"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("_intrinsicWidth"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("_intrinsicRatio"),
	HX_CSTRING("intrinsicRatio"),
	HX_CSTRING("_height"),
	HX_CSTRING("height"),
	HX_CSTRING("_width"),
	HX_CSTRING("width"),
	HX_CSTRING("_embeddedAsset"),
	HX_CSTRING("embeddedAsset"),
	HX_CSTRING("init"),
	HX_CSTRING("initEmbeddedAsset"),
	HX_CSTRING("initStyle"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("get_embeddedAsset"),
	HX_CSTRING("get_intrinsicHeight"),
	HX_CSTRING("get_intrinsicWidth"),
	HX_CSTRING("get_intrinsicRatio"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedElement_obj::__mClass;

void EmbeddedElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.html.EmbeddedElement"), hx::TCanCast< EmbeddedElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedElement_obj::__boot()
{
}

} // end namespace core
} // end namespace html
