#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontManager
#include <cocktail/core/font/FontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_InlineBox
#include <cocktail/core/linebox/InlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_linebox_TextInlineBox
#include <cocktail/core/linebox/TextInlineBox.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextBase
#include <cocktail/port/base/NativeTextBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeText
#include <cocktail/port/platform/nme/NativeText.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
namespace cocktail{
namespace core{
namespace linebox{

Void TextInlineBox_obj::__construct(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,::String text,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily)
{
HX_STACK_PUSH("TextInlineBox::new","cocktail/core/linebox/TextInlineBox.hx",59);
{
	HX_STACK_LINE(60)
	super::__construct(elementRenderer,leadedAscent,leadedDescent);
	HX_STACK_LINE(62)
	this->isText = true;
	HX_STACK_LINE(64)
	this->_text = text;
	HX_STACK_LINE(65)
	this->initNativeTextElement(text,fontManager,elementRenderer->coreStyle,fontFamily);
	HX_STACK_LINE(68)
	this->bounds->width = this->_nativeText->get_width();
	HX_STACK_LINE(69)
	this->bounds->height = (leadedAscent + leadedDescent);
}
;
	return null();
}

TextInlineBox_obj::~TextInlineBox_obj() { }

Dynamic TextInlineBox_obj::__CreateEmpty() { return  new TextInlineBox_obj; }
hx::ObjectPtr< TextInlineBox_obj > TextInlineBox_obj::__new(::cocktail::core::renderer::ElementRenderer elementRenderer,Float leadedAscent,Float leadedDescent,::String text,::cocktail::core::font::FontMetricsVO fontMetrics,::cocktail::core::font::FontManager fontManager,::String fontFamily)
{  hx::ObjectPtr< TextInlineBox_obj > result = new TextInlineBox_obj();
	result->__construct(elementRenderer,leadedAscent,leadedDescent,text,fontMetrics,fontManager,fontFamily);
	return result;}

Dynamic TextInlineBox_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextInlineBox_obj > result = new TextInlineBox_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Float TextInlineBox_obj::getTextHeight( ){
	HX_STACK_PUSH("TextInlineBox::getTextHeight","cocktail/core/linebox/TextInlineBox.hx",141);
	HX_STACK_THIS(this);
	HX_STACK_LINE(141)
	return (this->leadedAscent + this->leadedDescent);
}


HX_DEFINE_DYNAMIC_FUNC0(TextInlineBox_obj,getTextHeight,return )

Float TextInlineBox_obj::getTextWidth( ){
	HX_STACK_PUSH("TextInlineBox::getTextWidth","cocktail/core/linebox/TextInlineBox.hx",132);
	HX_STACK_THIS(this);
	HX_STACK_LINE(132)
	return this->_nativeText->get_width();
}


HX_DEFINE_DYNAMIC_FUNC0(TextInlineBox_obj,getTextWidth,return )

::native::display::BitmapData TextInlineBox_obj::get_nativeTextBitmap( ){
	HX_STACK_PUSH("TextInlineBox::get_nativeTextBitmap","cocktail/core/linebox/TextInlineBox.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(121)
	if (((this->nativeTextBitmap == null()))){
		HX_STACK_LINE(122)
		this->initTextBitmap();
	}
	HX_STACK_LINE(125)
	return this->nativeTextBitmap;
}


HX_DEFINE_DYNAMIC_FUNC0(TextInlineBox_obj,get_nativeTextBitmap,return )

Void TextInlineBox_obj::initTextBitmap( ){
{
		HX_STACK_PUSH("TextInlineBox::initTextBitmap","cocktail/core/linebox/TextInlineBox.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds->y = this->leadedAscent;
		HX_STACK_LINE(103)
		::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds->width = this->bounds->width;
		HX_STACK_LINE(104)
		::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds->height = this->bounds->height;
		HX_STACK_LINE(107)
		if (((bool((::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds->width != (int)0)) && bool((::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds->height != (int)0))))){
			HX_STACK_LINE(108)
			this->nativeTextBitmap = this->_nativeText->getBitmap(::cocktail::core::linebox::TextInlineBox_obj::_bitmapBounds);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextInlineBox_obj,initTextBitmap,(void))

Void TextInlineBox_obj::initNativeTextElement( ::String text,::cocktail::core::font::FontManager fontManager,::cocktail::core::css::CoreStyle style,::String fontFamily){
{
		HX_STACK_PUSH("TextInlineBox::initNativeTextElement","cocktail/core/linebox/TextInlineBox.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(text,"text");
		HX_STACK_ARG(fontManager,"fontManager");
		HX_STACK_ARG(style,"style");
		HX_STACK_ARG(fontFamily,"fontFamily");
		HX_STACK_LINE(92)
		Dynamic nativeElement = fontManager->createNativeTextElement(text,style,fontFamily);		HX_STACK_VAR(nativeElement,"nativeElement");
		HX_STACK_LINE(94)
		this->_nativeText = ::cocktail::port::platform::nme::NativeText_obj::__new(nativeElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(TextInlineBox_obj,initNativeTextElement,(void))

Void TextInlineBox_obj::dispose( ){
{
		HX_STACK_PUSH("TextInlineBox::dispose","cocktail/core/linebox/TextInlineBox.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_LINE(77)
		this->super::dispose();
		HX_STACK_LINE(78)
		if (((this->_nativeText != null()))){
			HX_STACK_LINE(80)
			this->_nativeText->dispose();
			HX_STACK_LINE(81)
			this->_nativeText = null();
		}
	}
return null();
}


::cocktail::core::geom::RectangleVO TextInlineBox_obj::_bitmapBounds;


TextInlineBox_obj::TextInlineBox_obj()
{
}

void TextInlineBox_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextInlineBox);
	HX_MARK_MEMBER_NAME(_text,"_text");
	HX_MARK_MEMBER_NAME(nativeTextBitmap,"nativeTextBitmap");
	HX_MARK_MEMBER_NAME(_nativeText,"_nativeText");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextInlineBox_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_text,"_text");
	HX_VISIT_MEMBER_NAME(nativeTextBitmap,"nativeTextBitmap");
	HX_VISIT_MEMBER_NAME(_nativeText,"_nativeText");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TextInlineBox_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { return _text; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_nativeText") ) { return _nativeText; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTextWidth") ) { return getTextWidth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bitmapBounds") ) { return _bitmapBounds; }
		if (HX_FIELD_EQ(inName,"getTextHeight") ) { return getTextHeight_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initTextBitmap") ) { return initTextBitmap_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nativeTextBitmap") ) { return inCallProp ? get_nativeTextBitmap() : nativeTextBitmap; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_nativeTextBitmap") ) { return get_nativeTextBitmap_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"initNativeTextElement") ) { return initNativeTextElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextInlineBox_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { _text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_nativeText") ) { _nativeText=inValue.Cast< ::cocktail::port::platform::nme::NativeText >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_bitmapBounds") ) { _bitmapBounds=inValue.Cast< ::cocktail::core::geom::RectangleVO >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nativeTextBitmap") ) { nativeTextBitmap=inValue.Cast< ::native::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextInlineBox_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_text"));
	outFields->push(HX_CSTRING("nativeTextBitmap"));
	outFields->push(HX_CSTRING("_nativeText"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_bitmapBounds"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTextHeight"),
	HX_CSTRING("getTextWidth"),
	HX_CSTRING("get_nativeTextBitmap"),
	HX_CSTRING("initTextBitmap"),
	HX_CSTRING("initNativeTextElement"),
	HX_CSTRING("dispose"),
	HX_CSTRING("_text"),
	HX_CSTRING("nativeTextBitmap"),
	HX_CSTRING("_nativeText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextInlineBox_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(TextInlineBox_obj::_bitmapBounds,"_bitmapBounds");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextInlineBox_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextInlineBox_obj::_bitmapBounds,"_bitmapBounds");
};

Class TextInlineBox_obj::__mClass;

void TextInlineBox_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.linebox.TextInlineBox"), hx::TCanCast< TextInlineBox_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TextInlineBox_obj::__boot()
{
	_bitmapBounds= ::cocktail::core::geom::RectangleVO_obj::__new();
}

} // end namespace cocktail
} // end namespace core
} // end namespace linebox
