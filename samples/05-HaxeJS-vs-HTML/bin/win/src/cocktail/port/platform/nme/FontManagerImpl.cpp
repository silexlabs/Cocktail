#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_animation_TransitionManager
#include <cocktail/core/animation/TransitionManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_ColorVO
#include <cocktail/core/css/ColorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManagerImpl
#include <cocktail/core/font/AbstractFontManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_FontManagerImpl
#include <cocktail/port/platform/nme/FontManagerImpl.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_text_TextField
#include <native/text/TextField.h>
#endif
#ifndef INCLUDED_native_text_TextFieldAutoSize
#include <native/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_native_text_TextFormat
#include <native/text/TextFormat.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace nme{

Void FontManagerImpl_obj::__construct()
{
HX_STACK_PUSH("FontManagerImpl::new","cocktail/port/platform/nme/FontManagerImpl.hx",57);
{
	HX_STACK_LINE(57)
	super::__construct();
}
;
	return null();
}

FontManagerImpl_obj::~FontManagerImpl_obj() { }

Dynamic FontManagerImpl_obj::__CreateEmpty() { return  new FontManagerImpl_obj; }
hx::ObjectPtr< FontManagerImpl_obj > FontManagerImpl_obj::__new()
{  hx::ObjectPtr< FontManagerImpl_obj > result = new FontManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic FontManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontManagerImpl_obj > result = new FontManagerImpl_obj();
	result->__construct();
	return result;}

::native::text::TextFormat FontManagerImpl_obj::getTextFormat( ::cocktail::core::css::CoreStyle style,::String fontFamily){
	HX_STACK_PUSH("FontManagerImpl::getTextFormat","cocktail/port/platform/nme/FontManagerImpl.hx",163);
	HX_STACK_THIS(this);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(165)
	::cocktail::core::css::UsedValuesVO usedValues = style->usedValues;		HX_STACK_VAR(usedValues,"usedValues");
	HX_STACK_LINE(167)
	::native::text::TextFormat textFormat = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(textFormat,"textFormat");
	HX_STACK_LINE(168)
	textFormat->font = fontFamily;
	HX_STACK_LINE(170)
	textFormat->letterSpacing = usedValues->letterSpacing;
	struct _Function_1_1{
		inline static ::cocktail::core::css::CSSPropertyValue Block( ::cocktail::core::css::CoreStyle &style){
			HX_STACK_PUSH("*::closure","cocktail/port/platform/nme/FontManagerImpl.hx",171);
			{
				HX_STACK_LINE(171)
				::cocktail::core::animation::Transition transition = style->_transitionManager->getTransition((int)34,style);		HX_STACK_VAR(transition,"transition");
				HX_STACK_LINE(171)
				return (  (((transition != null()))) ? ::cocktail::core::css::CSSPropertyValue(::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(transition->get_currentValue())) : ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)34)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(171)
	textFormat->size = style->getAbsoluteLength((  (((style->hasTransitionnableProperties == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue((  (((style->_transitionManager->hasTransitionsInProgress == false))) ? ::cocktail::core::css::CSSPropertyValue(style->getComputedOrInitialProperty((int)34)) : ::cocktail::core::css::CSSPropertyValue(_Function_1_1::Block(style)) )) ));
	HX_STACK_LINE(173)
	bool bold = false;		HX_STACK_VAR(bold,"bold");
	HX_STACK_LINE(175)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (style->getComputedOrInitialProperty((int)35));
		switch((_switch_1)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(177)
					{
						::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
						switch((_switch_2)->GetIndex()){
							case 1: case 2: {
								HX_STACK_LINE(180)
								bold = true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 0: {
				int value = _switch_1->__Param(0);
{
					HX_STACK_LINE(186)
					if (((value > (int)400))){
						HX_STACK_LINE(188)
						bold = true;
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(195)
	textFormat->bold = bold;
	HX_STACK_LINE(197)
	::cocktail::core::css::CSSKeywordValue fontStyle = style->getKeyword(style->getComputedOrInitialProperty((int)36));		HX_STACK_VAR(fontStyle,"fontStyle");
	HX_STACK_LINE(199)
	textFormat->italic = (bool((fontStyle == ::cocktail::core::css::CSSKeywordValue_obj::ITALIC_dyn())) || bool((fontStyle == ::cocktail::core::css::CSSKeywordValue_obj::OBLIQUE_dyn())));
	HX_STACK_LINE(201)
	textFormat->color = usedValues->color->color;
	HX_STACK_LINE(202)
	return textFormat;
}


HX_DEFINE_DYNAMIC_FUNC2(FontManagerImpl_obj,getTextFormat,return )

::String FontManagerImpl_obj::getNativeFontFamily( Array< ::String > value){
	HX_STACK_PUSH("FontManagerImpl::getNativeFontFamily","cocktail/port/platform/nme/FontManagerImpl.hx",124);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(125)
	::String fontFamily = HX_CSTRING("");		HX_STACK_VAR(fontFamily,"fontFamily");
	HX_STACK_LINE(127)
	{
		HX_STACK_LINE(127)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = value->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(127)
		while(((_g1 < _g))){
			HX_STACK_LINE(127)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(129)
			::String fontName = value->__get(i);		HX_STACK_VAR(fontName,"fontName");
			HX_STACK_LINE(131)
			::String _switch_3 = (fontName);
			if (  ( _switch_3==HX_CSTRING("serif"))){
				HX_STACK_LINE(133)
				fontName = HX_CSTRING("_serif");
			}
			else if (  ( _switch_3==HX_CSTRING("sans"))){
				HX_STACK_LINE(136)
				fontName = HX_CSTRING("_sans");
			}
			else if (  ( _switch_3==HX_CSTRING("typewriter"))){
				HX_STACK_LINE(139)
				fontName = HX_CSTRING("_typewriter");
			}
			HX_STACK_LINE(143)
			hx::AddEq(fontFamily,fontName);
			HX_STACK_LINE(145)
			if (((i < (value->length - (int)1)))){
				HX_STACK_LINE(146)
				hx::AddEq(fontFamily,HX_CSTRING(","));
			}
		}
	}
	HX_STACK_LINE(151)
	return fontFamily;
}


Dynamic FontManagerImpl_obj::createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily){
	HX_STACK_PUSH("FontManagerImpl::createNativeTextElement","cocktail/port/platform/nme/FontManagerImpl.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(105)
	::native::text::TextField textField = ::native::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(106)
	textField->set_text(text);
	HX_STACK_LINE(107)
	textField->set_selectable(false);
	HX_STACK_LINE(108)
	textField->set_autoSize(::native::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_STACK_LINE(109)
	textField->setTextFormat(this->getTextFormat(style,fontFamily),null(),null());
	HX_STACK_LINE(111)
	return textField;
}


::cocktail::core::font::FontMetricsVO FontManagerImpl_obj::getFontMetrics( ::String fontFamily,Float fontSize){
	HX_STACK_PUSH("FontManagerImpl::getFontMetrics","cocktail/port/platform/nme/FontManagerImpl.hx",71);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_LINE(73)
	::native::text::TextField textField = ::native::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(74)
	textField->set_autoSize(::native::text::TextFieldAutoSize_obj::LEFT_dyn());
	HX_STACK_LINE(76)
	::native::text::TextFormat textFormat = ::native::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(textFormat,"textFormat");
	HX_STACK_LINE(77)
	textFormat->size = fontSize;
	HX_STACK_LINE(78)
	textFormat->font = fontFamily;
	HX_STACK_LINE(80)
	textField->setTextFormat(textFormat,null(),null());
	HX_STACK_LINE(82)
	textField->set_text(HX_CSTRING("x"));
	HX_STACK_LINE(84)
	Float ascent = (Float(textField->get_height()) / Float((int)2));		HX_STACK_VAR(ascent,"ascent");
	HX_STACK_LINE(86)
	textField->set_text(HX_CSTRING(","));
	HX_STACK_LINE(88)
	Float descent = (Float(textField->get_height()) / Float((int)2));		HX_STACK_VAR(descent,"descent");
	HX_STACK_LINE(90)
	textField->set_text(HX_CSTRING("x"));
	HX_STACK_LINE(92)
	Float xHeight = textField->get_height();		HX_STACK_VAR(xHeight,"xHeight");
	HX_STACK_LINE(94)
	textField->set_text(HX_CSTRING(" "));
	HX_STACK_LINE(95)
	Float spaceWidth = textField->get_width();		HX_STACK_VAR(spaceWidth,"spaceWidth");
	HX_STACK_LINE(97)
	return ::cocktail::core::font::FontMetricsVO_obj::__new(fontSize,ascent,descent,xHeight,1.0,1.0,1.0,spaceWidth);
}


::String FontManagerImpl_obj::SERIF_GENERIC_FONT_NAME;

::String FontManagerImpl_obj::SERIF_FLASH_FONT_NAME;

::String FontManagerImpl_obj::SANS_SERIF_GENERIC_FONT_NAME;

::String FontManagerImpl_obj::SANS_SERIF_FLASH_FONT_NAME;

::String FontManagerImpl_obj::MONOSPACE_GENERIC_FONT_NAME;

::String FontManagerImpl_obj::MONOSPACE_FLASH_FONT_NAME;


FontManagerImpl_obj::FontManagerImpl_obj()
{
}

void FontManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontManagerImpl);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FontManagerImpl_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FontManagerImpl_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"getTextFormat") ) { return getTextFormat_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFontMetrics") ) { return getFontMetrics_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { return SERIF_FLASH_FONT_NAME; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { return SERIF_GENERIC_FONT_NAME; }
		if (HX_FIELD_EQ(inName,"createNativeTextElement") ) { return createNativeTextElement_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { return MONOSPACE_FLASH_FONT_NAME; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { return SANS_SERIF_FLASH_FONT_NAME; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { return MONOSPACE_GENERIC_FONT_NAME; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { return SANS_SERIF_GENERIC_FONT_NAME; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FontManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"SERIF_FLASH_FONT_NAME") ) { SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"SERIF_GENERIC_FONT_NAME") ) { SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"MONOSPACE_FLASH_FONT_NAME") ) { MONOSPACE_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_FLASH_FONT_NAME") ) { SANS_SERIF_FLASH_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"MONOSPACE_GENERIC_FONT_NAME") ) { MONOSPACE_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SANS_SERIF_GENERIC_FONT_NAME") ) { SANS_SERIF_GENERIC_FONT_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FontManagerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_GENERIC_FONT_NAME"),
	HX_CSTRING("SANS_SERIF_FLASH_FONT_NAME"),
	HX_CSTRING("MONOSPACE_GENERIC_FONT_NAME"),
	HX_CSTRING("MONOSPACE_FLASH_FONT_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTextFormat"),
	HX_CSTRING("getNativeFontFamily"),
	HX_CSTRING("createNativeTextElement"),
	HX_CSTRING("getFontMetrics"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_MARK_MEMBER_NAME(FontManagerImpl_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::SERIF_GENERIC_FONT_NAME,"SERIF_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::SERIF_FLASH_FONT_NAME,"SERIF_FLASH_FONT_NAME");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::SANS_SERIF_GENERIC_FONT_NAME,"SANS_SERIF_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::SANS_SERIF_FLASH_FONT_NAME,"SANS_SERIF_FLASH_FONT_NAME");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::MONOSPACE_GENERIC_FONT_NAME,"MONOSPACE_GENERIC_FONT_NAME");
	HX_VISIT_MEMBER_NAME(FontManagerImpl_obj::MONOSPACE_FLASH_FONT_NAME,"MONOSPACE_FLASH_FONT_NAME");
};

Class FontManagerImpl_obj::__mClass;

void FontManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.nme.FontManagerImpl"), hx::TCanCast< FontManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FontManagerImpl_obj::__boot()
{
	SERIF_GENERIC_FONT_NAME= HX_CSTRING("serif");
	SERIF_FLASH_FONT_NAME= HX_CSTRING("_serif");
	SANS_SERIF_GENERIC_FONT_NAME= HX_CSTRING("sans");
	SANS_SERIF_FLASH_FONT_NAME= HX_CSTRING("_sans");
	MONOSPACE_GENERIC_FONT_NAME= HX_CSTRING("typewriter");
	MONOSPACE_FLASH_FONT_NAME= HX_CSTRING("_typewriter");
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace nme
