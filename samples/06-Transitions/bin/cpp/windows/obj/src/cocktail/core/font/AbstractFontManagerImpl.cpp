#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_font_AbstractFontManagerImpl
#include <cocktail/core/font/AbstractFontManagerImpl.h>
#endif
#ifndef INCLUDED_cocktail_core_font_FontMetricsVO
#include <cocktail/core/font/FontMetricsVO.h>
#endif
namespace cocktail{
namespace core{
namespace font{

Void AbstractFontManagerImpl_obj::__construct()
{
HX_STACK_PUSH("AbstractFontManagerImpl::new","cocktail/core/font/AbstractFontManagerImpl.hx",35);
{
	HX_STACK_LINE(35)
	this->_computedFontMetrics = ::Hash_obj::__new();
}
;
	return null();
}

AbstractFontManagerImpl_obj::~AbstractFontManagerImpl_obj() { }

Dynamic AbstractFontManagerImpl_obj::__CreateEmpty() { return  new AbstractFontManagerImpl_obj; }
hx::ObjectPtr< AbstractFontManagerImpl_obj > AbstractFontManagerImpl_obj::__new()
{  hx::ObjectPtr< AbstractFontManagerImpl_obj > result = new AbstractFontManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic AbstractFontManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractFontManagerImpl_obj > result = new AbstractFontManagerImpl_obj();
	result->__construct();
	return result;}

::cocktail::core::font::FontMetricsVO AbstractFontManagerImpl_obj::doGetFontMetrics( ::String fontFamily,Float fontSize){
	HX_STACK_PUSH("AbstractFontManagerImpl::doGetFontMetrics","cocktail/core/font/AbstractFontManagerImpl.hx",106);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_LINE(106)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManagerImpl_obj,doGetFontMetrics,return )

::String AbstractFontManagerImpl_obj::getNativeFontFamily( Array< ::String > fontFamily){
	HX_STACK_PUSH("AbstractFontManagerImpl::getNativeFontFamily","cocktail/core/font/AbstractFontManagerImpl.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(93)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFontManagerImpl_obj,getNativeFontFamily,return )

Dynamic AbstractFontManagerImpl_obj::createNativeTextElement( ::String text,::cocktail::core::css::CoreStyle style,::String fontFamily){
	HX_STACK_PUSH("AbstractFontManagerImpl::createNativeTextElement","cocktail/core/font/AbstractFontManagerImpl.hx",83);
	HX_STACK_THIS(this);
	HX_STACK_ARG(text,"text");
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_LINE(83)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractFontManagerImpl_obj,createNativeTextElement,return )

::cocktail::core::font::FontMetricsVO AbstractFontManagerImpl_obj::getFontMetrics( ::String fontFamily,Float fontSize){
	HX_STACK_PUSH("AbstractFontManagerImpl::getFontMetrics","cocktail/core/font/AbstractFontManagerImpl.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fontFamily,"fontFamily");
	HX_STACK_ARG(fontSize,"fontSize");
	HX_STACK_LINE(49)
	::cocktail::core::font::FontMetricsVO fontMetrics;		HX_STACK_VAR(fontMetrics,"fontMetrics");
	HX_STACK_LINE(53)
	::IntHash fontSizeHash = this->_computedFontMetrics->get(fontFamily);		HX_STACK_VAR(fontSizeHash,"fontSizeHash");
	HX_STACK_LINE(54)
	if (((fontSizeHash != null()))){
		HX_STACK_LINE(56)
		fontMetrics = fontSizeHash->get(::Math_obj::round(fontSize));
		HX_STACK_LINE(57)
		if (((fontMetrics == null()))){
			HX_STACK_LINE(59)
			fontMetrics = this->doGetFontMetrics(fontFamily,fontSize);
			HX_STACK_LINE(60)
			fontSizeHash->set(::Math_obj::round(fontSize),fontMetrics);
			HX_STACK_LINE(61)
			this->_computedFontMetrics->set(fontFamily,fontSizeHash);
		}
	}
	else{
		HX_STACK_LINE(66)
		fontMetrics = this->doGetFontMetrics(fontFamily,fontSize);
		HX_STACK_LINE(67)
		fontSizeHash = ::IntHash_obj::__new();
		HX_STACK_LINE(68)
		fontSizeHash->set(::Math_obj::round(fontSize),fontMetrics);
		HX_STACK_LINE(70)
		this->_computedFontMetrics->set(fontFamily,fontSizeHash);
	}
	HX_STACK_LINE(73)
	return fontMetrics;
}


HX_DEFINE_DYNAMIC_FUNC2(AbstractFontManagerImpl_obj,getFontMetrics,return )


AbstractFontManagerImpl_obj::AbstractFontManagerImpl_obj()
{
}

void AbstractFontManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractFontManagerImpl);
	HX_MARK_MEMBER_NAME(_computedFontMetrics,"_computedFontMetrics");
	HX_MARK_END_CLASS();
}

void AbstractFontManagerImpl_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_computedFontMetrics,"_computedFontMetrics");
}

Dynamic AbstractFontManagerImpl_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"getFontMetrics") ) { return getFontMetrics_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"doGetFontMetrics") ) { return doGetFontMetrics_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getNativeFontFamily") ) { return getNativeFontFamily_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_computedFontMetrics") ) { return _computedFontMetrics; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"createNativeTextElement") ) { return createNativeTextElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AbstractFontManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"_computedFontMetrics") ) { _computedFontMetrics=inValue.Cast< ::Hash >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AbstractFontManagerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_computedFontMetrics"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("doGetFontMetrics"),
	HX_CSTRING("getNativeFontFamily"),
	HX_CSTRING("createNativeTextElement"),
	HX_CSTRING("getFontMetrics"),
	HX_CSTRING("_computedFontMetrics"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractFontManagerImpl_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AbstractFontManagerImpl_obj::__mClass,"__mClass");
};

Class AbstractFontManagerImpl_obj::__mClass;

void AbstractFontManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.font.AbstractFontManagerImpl"), hx::TCanCast< AbstractFontManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AbstractFontManagerImpl_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace font
