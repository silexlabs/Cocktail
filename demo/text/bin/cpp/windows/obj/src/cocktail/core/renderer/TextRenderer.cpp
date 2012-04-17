#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_TextTokenValue
#include <cocktail/core/dom/TextTokenValue.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_TextRenderer
#include <cocktail/core/renderer/TextRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageScaleMode
#include <nme/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace cocktail{
namespace core{
namespace renderer{

Void TextRenderer_obj::__construct(::cocktail::core::style::CoreStyle style,Dynamic nativeElement,::cocktail::core::dom::TextTokenValue textToken)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",39)
	this->_textToken = textToken;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",41)
	this->_nativeElement = nativeElement;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",43)
	super::__construct(style);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",46)
	this->_bounds->__FieldRef(HX_CSTRING("width")) = this->getOffsetWidth();
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",47)
	this->_bounds->__FieldRef(HX_CSTRING("height")) = this->getOffsetHeight();
}
;
	return null();
}

TextRenderer_obj::~TextRenderer_obj() { }

Dynamic TextRenderer_obj::__CreateEmpty() { return  new TextRenderer_obj; }
hx::ObjectPtr< TextRenderer_obj > TextRenderer_obj::__new(::cocktail::core::style::CoreStyle style,Dynamic nativeElement,::cocktail::core::dom::TextTokenValue textToken)
{  hx::ObjectPtr< TextRenderer_obj > result = new TextRenderer_obj();
	result->__construct(style,nativeElement,textToken);
	return result;}

Dynamic TextRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextRenderer_obj > result = new TextRenderer_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void TextRenderer_obj::dispose( ){
{
		HX_SOURCE_PUSH("TextRenderer_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",59)
		this->super::dispose();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",61)
		this->_textToken = null();
		HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",62)
		this->_nativeElement = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,dispose,(void))

Dynamic TextRenderer_obj::render( ){
	HX_SOURCE_PUSH("TextRenderer_obj::render")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",71)
	Dynamic ret = Dynamic( Array_obj<Dynamic>::__new());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",76)
	this->_nativeElement->__FieldRef(HX_CSTRING("x")) = this->_bounds->__Field(HX_CSTRING("x"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",77)
	this->_nativeElement->__FieldRef(HX_CSTRING("y")) = (this->_bounds->__Field(HX_CSTRING("y")) - ((this->_coreStyle->getFontMetricsData()->__Field(HX_CSTRING("ascent")) + this->_coreStyle->getFontMetricsData()->__Field(HX_CSTRING("descent")))));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",80)
	ret->__Field(HX_CSTRING("push"))(this->_nativeElement);
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",82)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,render,return )

int TextRenderer_obj::getOffsetWidth( ){
	HX_SOURCE_PUSH("TextRenderer_obj::getOffsetWidth")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",121)
	::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeSetScaleMode(::nme::display::StageScaleMode_obj::NO_SCALE_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",123)
	int ret = this->_nativeElement->__Field(HX_CSTRING("textWidth"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",125)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,getOffsetWidth,return )

int TextRenderer_obj::getOffsetHeight( ){
	HX_SOURCE_PUSH("TextRenderer_obj::getOffsetHeight")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",139)
	double ascent = this->_coreStyle->getFontMetricsData()->__Field(HX_CSTRING("ascent"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",140)
	double descent = this->_coreStyle->getFontMetricsData()->__Field(HX_CSTRING("descent"));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",144)
	double leading = (this->_coreStyle->getComputedStyle()->__Field(HX_CSTRING("lineHeight")) - ((ascent + descent)));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",147)
	double leadedAscent = (ascent + (double(leading) / double((int)2)));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",148)
	double leadedDescent = (descent + (double(leading) / double((int)2)));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",150)
	return ::Math_obj::round((leadedAscent + leadedDescent));
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",152)
	return (int)50;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,getOffsetHeight,return )

bool TextRenderer_obj::isFloat( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isFloat")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",160)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isFloat,return )

bool TextRenderer_obj::isPositioned( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isPositioned")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",165)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isPositioned,return )

bool TextRenderer_obj::isText( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isText")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",170)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isText,return )

bool TextRenderer_obj::isSpace( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isSpace")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",176)
	bool isSpace;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",178)
	{
::cocktail::core::dom::TextTokenValue _switch_1 = (this->_textToken);
		switch((_switch_1)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",180)
				isSpace = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",183)
				isSpace = false;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",187)
	return isSpace;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isSpace,return )

bool TextRenderer_obj::isLineFeed( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isLineFeed")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",192)
	bool isLineFeed;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",194)
	{
::cocktail::core::dom::TextTokenValue _switch_2 = (this->_textToken);
		switch((_switch_2)->GetIndex()){
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",196)
				isLineFeed = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",199)
				isLineFeed = false;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",203)
	return isLineFeed;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isLineFeed,return )

bool TextRenderer_obj::isTab( ){
	HX_SOURCE_PUSH("TextRenderer_obj::isTab")
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",208)
	bool isTab;
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",210)
	{
::cocktail::core::dom::TextTokenValue _switch_3 = (this->_textToken);
		switch((_switch_3)->GetIndex()){
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",212)
				isTab = true;
			}
			;break;
			default: {
				HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",215)
				isTab = false;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/renderer/TextRenderer.hx",219)
	return isTab;
}


HX_DEFINE_DYNAMIC_FUNC0(TextRenderer_obj,isTab,return )


TextRenderer_obj::TextRenderer_obj()
{
}

void TextRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextRenderer);
	HX_MARK_MEMBER_NAME(_textToken,"_textToken");
	HX_MARK_MEMBER_NAME(_nativeElement,"_nativeElement");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TextRenderer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"isTab") ) { return isTab_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"isText") ) { return isText_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"isSpace") ) { return isSpace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_textToken") ) { return _textToken; }
		if (HX_FIELD_EQ(inName,"isLineFeed") ) { return isLineFeed_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPositioned") ) { return isPositioned_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { return _nativeElement; }
		if (HX_FIELD_EQ(inName,"getOffsetWidth") ) { return getOffsetWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getOffsetHeight") ) { return getOffsetHeight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TextRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"_textToken") ) { _textToken=inValue.Cast< ::cocktail::core::dom::TextTokenValue >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_nativeElement") ) { _nativeElement=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_textToken"));
	outFields->push(HX_CSTRING("_nativeElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_textToken"),
	HX_CSTRING("_nativeElement"),
	HX_CSTRING("dispose"),
	HX_CSTRING("render"),
	HX_CSTRING("getOffsetWidth"),
	HX_CSTRING("getOffsetHeight"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("isPositioned"),
	HX_CSTRING("isText"),
	HX_CSTRING("isSpace"),
	HX_CSTRING("isLineFeed"),
	HX_CSTRING("isTab"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TextRenderer_obj::__mClass;

void TextRenderer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.renderer.TextRenderer"), hx::TCanCast< TextRenderer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextRenderer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace renderer
