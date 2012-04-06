#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_drawing_AbstractDrawingManager
#include <cocktail/core/drawing/AbstractDrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLCanvasElement
#include <cocktail/core/html/HTMLCanvasElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_DrawingManager
#include <cocktail/port/flash_player/DrawingManager.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLCanvasElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",34)
	super::__construct(HX_CSTRING("canvas"));
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",36)
	this->_intrinsicHeight = (int)150;
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",37)
	this->_intrinsicWidth = (int)300;
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",38)
	this->_intrinsicRatio = (double(this->_intrinsicWidth) / double(this->_intrinsicHeight));
}
;
	return null();
}

HTMLCanvasElement_obj::~HTMLCanvasElement_obj() { }

Dynamic HTMLCanvasElement_obj::__CreateEmpty() { return  new HTMLCanvasElement_obj; }
hx::ObjectPtr< HTMLCanvasElement_obj > HTMLCanvasElement_obj::__new()
{  hx::ObjectPtr< HTMLCanvasElement_obj > result = new HTMLCanvasElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLCanvasElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLCanvasElement_obj > result = new HTMLCanvasElement_obj();
	result->__construct();
	return result;}

Void HTMLCanvasElement_obj::initEmbeddedAsset( ){
{
		HX_SOURCE_PUSH("HTMLCanvasElement_obj::initEmbeddedAsset")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",44)
		this->_embeddedAsset = this->_nativeElement;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLCanvasElement_obj,initEmbeddedAsset,(void))

::cocktail::port::flash_player::DrawingManager HTMLCanvasElement_obj::getContext( ::String contextID){
	HX_SOURCE_PUSH("HTMLCanvasElement_obj::getContext")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",49)
	if (((contextID == HX_CSTRING("2d")))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",52)
		if (((this->_drawingManager == null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",53)
			this->_drawingManager = ::cocktail::port::flash_player::DrawingManager_obj::__new(this->_nativeElement,this->_intrinsicHeight,this->_intrinsicWidth);
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",56)
		return this->_drawingManager;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",59)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLCanvasElement_obj,getContext,return )

int HTMLCanvasElement_obj::set_width( int value){
	HX_SOURCE_PUSH("HTMLCanvasElement_obj::set_width")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",70)
	this->_drawingManager->setWidth(value);
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",71)
	return this->_width = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLCanvasElement_obj,set_width,return )

int HTMLCanvasElement_obj::set_height( int value){
	HX_SOURCE_PUSH("HTMLCanvasElement_obj::set_height")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",76)
	this->_drawingManager->setHeight(value);
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLCanvasElement.hx",77)
	return this->_height = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLCanvasElement_obj,set_height,return )

int HTMLCanvasElement_obj::CANVAS_INTRINSIC_HEIGHT;

int HTMLCanvasElement_obj::CANVAS_INTRINSIC_WIDTH;

::String HTMLCanvasElement_obj::HTML_CANVAS_TAG_NAME;

::String HTMLCanvasElement_obj::CANVAS_2D_CONTEXT;


HTMLCanvasElement_obj::HTMLCanvasElement_obj()
{
}

void HTMLCanvasElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLCanvasElement);
	HX_MARK_MEMBER_NAME(_drawingManager,"_drawingManager");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLCanvasElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getContext") ) { return getContext_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_drawingManager") ) { return _drawingManager; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"CANVAS_2D_CONTEXT") ) { return CANVAS_2D_CONTEXT; }
		if (HX_FIELD_EQ(inName,"initEmbeddedAsset") ) { return initEmbeddedAsset_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"HTML_CANVAS_TAG_NAME") ) { return HTML_CANVAS_TAG_NAME; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"CANVAS_INTRINSIC_WIDTH") ) { return CANVAS_INTRINSIC_WIDTH; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"CANVAS_INTRINSIC_HEIGHT") ) { return CANVAS_INTRINSIC_HEIGHT; }
	}
	return super::__Field(inName);
}

Dynamic HTMLCanvasElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"_drawingManager") ) { _drawingManager=inValue.Cast< ::cocktail::port::flash_player::DrawingManager >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"CANVAS_2D_CONTEXT") ) { CANVAS_2D_CONTEXT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"HTML_CANVAS_TAG_NAME") ) { HTML_CANVAS_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"CANVAS_INTRINSIC_WIDTH") ) { CANVAS_INTRINSIC_WIDTH=inValue.Cast< int >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"CANVAS_INTRINSIC_HEIGHT") ) { CANVAS_INTRINSIC_HEIGHT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLCanvasElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_drawingManager"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CANVAS_INTRINSIC_HEIGHT"),
	HX_CSTRING("CANVAS_INTRINSIC_WIDTH"),
	HX_CSTRING("HTML_CANVAS_TAG_NAME"),
	HX_CSTRING("CANVAS_2D_CONTEXT"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_drawingManager"),
	HX_CSTRING("initEmbeddedAsset"),
	HX_CSTRING("getContext"),
	HX_CSTRING("set_width"),
	HX_CSTRING("set_height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLCanvasElement_obj::CANVAS_INTRINSIC_HEIGHT,"CANVAS_INTRINSIC_HEIGHT");
	HX_MARK_MEMBER_NAME(HTMLCanvasElement_obj::CANVAS_INTRINSIC_WIDTH,"CANVAS_INTRINSIC_WIDTH");
	HX_MARK_MEMBER_NAME(HTMLCanvasElement_obj::HTML_CANVAS_TAG_NAME,"HTML_CANVAS_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLCanvasElement_obj::CANVAS_2D_CONTEXT,"CANVAS_2D_CONTEXT");
};

Class HTMLCanvasElement_obj::__mClass;

void HTMLCanvasElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLCanvasElement"), hx::TCanCast< HTMLCanvasElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLCanvasElement_obj::__boot()
{
	hx::Static(CANVAS_INTRINSIC_HEIGHT) = (int)150;
	hx::Static(CANVAS_INTRINSIC_WIDTH) = (int)300;
	hx::Static(HTML_CANVAS_TAG_NAME) = HX_CSTRING("canvas");
	hx::Static(CANVAS_2D_CONTEXT) = HX_CSTRING("2d");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
