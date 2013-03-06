#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManagerImpl
#include <cocktail/core/font/AbstractFontManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontManager
#include <cocktail/core/font/FontManager.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_FontManagerImpl
#include <cocktail/port/platform/nme/FontManagerImpl.h>
#endif
namespace cocktail{
namespace core{
namespace font{

Void FontManager_obj::__construct()
{
HX_STACK_PUSH("FontManager::new","cocktail/core/font/FontManager.hx",45);
{
	HX_STACK_LINE(45)
	this->_fontManagerImpl = ::cocktail::port::platform::nme::FontManagerImpl_obj::__new();
}
;
	return null();
}

FontManager_obj::~FontManager_obj() { }

Dynamic FontManager_obj::__CreateEmpty() { return  new FontManager_obj; }
hx::ObjectPtr< FontManager_obj > FontManager_obj::__new()
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

Dynamic FontManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontManager_obj > result = new FontManager_obj();
	result->__construct();
	return result;}

::String FontManager_obj::getNativeFontFamily( Array< ::String > fontFamily){
	HX_STACK_PUSH("FontManager::getNativeFontFamily","cocktail/core/font/FontManager.hx",91);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(91)
	return this->_fontManagerImpl->getNativeFontFamily(fontFamily);
}


HX_DEFINE_DYNAMIC_FUNC1(FontManager_obj,getNativeFontFamily,return )

Dynamic FontManager_obj::createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily){
	HX_STACK_PUSH("FontManager::createNativeTextElement","cocktail/core/font/FontManager.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(81)
	return this->_fontManagerImpl->createNativeTextElement(text,style,fontFamily);
}


HX_DEFINE_DYNAMIC_FUNC3(FontManager_obj,createNativeTextElement,return )

::cocktail::core::font::FontMetricsVO FontManager_obj::getFontMetrics( ::String fontFamily,Float fontSize){
	HX_STACK_PUSH("FontManager::getFontMetrics","cocktail/core/font/FontManager.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_LINE(70)
	return this->_fontManagerImpl->getFontMetrics(fontFamily,fontSize);
}


HX_DEFINE_DYNAMIC_FUNC2(FontManager_obj,getFontMetrics,return )

::cocktail::core::font::FontManager FontManager_obj::_instance;

::cocktail::core::font::FontManager FontManager_obj::getInstance( ){
	HX_STACK_PUSH("FontManager::getInstance","cocktail/core/font/FontManager.hx",53);
	HX_STACK_LINE(54)
	if (((::cocktail::core::font::FontManager_obj::_instance == null()))){
		HX_STACK_LINE(55)
		::cocktail::core::font::FontManager_obj::_instance = ::cocktail::core::font::FontManager_obj::__new();
	}
	HX_STACK_LINE(58)
	return ::cocktail::core::font::FontManager_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FontManager_obj,getInstance,return )


FontManager_obj::FontManager_obj()
{
}

void FontManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FontManager);
	HX_MARK_MEMBER_NAME(_fontManagerImpl,"_fontManagerImpl");
	HX_MARK_END_CLASS();
}

void FontManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_fontManagerImpl,"_fontManagerImpl");
}

Dynamic FontManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getFontMetrics") ) { return getFontMetrics_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fontManagerImpl") ) { return _fontManagerImpl; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"createNativeTextElement") ) { return createNativeTextElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FontManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::cocktail::core::font::FontManager >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fontManagerImpl") ) { _fontManagerImpl=inValue.Cast< ::cocktail::port::platform::nme::FontManagerImpl >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FontManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_fontManagerImpl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getNativeFontFamily"),
	HX_CSTRING("createNativeTextElement"),
	HX_CSTRING("getFontMetrics"),
	HX_CSTRING("_fontManagerImpl"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FontManager_obj::_instance,"_instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FontManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FontManager_obj::_instance,"_instance");
};

Class FontManager_obj::__mClass;

void FontManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.FontManager"), hx::TCanCast< FontManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FontManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace font
