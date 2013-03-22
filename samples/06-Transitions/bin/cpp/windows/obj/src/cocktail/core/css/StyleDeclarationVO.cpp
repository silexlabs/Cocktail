#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleDeclarationVO
#include <cocktail/core/css/StyleDeclarationVO.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_ObjectPool
#include <cocktail/core/utils/ObjectPool.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void StyleDeclarationVO_obj::__construct()
{
HX_STACK_PUSH("StyleDeclarationVO::new","cocktail/core/css/CSSData.hx",77);
{
}
;
	return null();
}

StyleDeclarationVO_obj::~StyleDeclarationVO_obj() { }

Dynamic StyleDeclarationVO_obj::__CreateEmpty() { return  new StyleDeclarationVO_obj; }
hx::ObjectPtr< StyleDeclarationVO_obj > StyleDeclarationVO_obj::__new()
{  hx::ObjectPtr< StyleDeclarationVO_obj > result = new StyleDeclarationVO_obj();
	result->__construct();
	return result;}

Dynamic StyleDeclarationVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StyleDeclarationVO_obj > result = new StyleDeclarationVO_obj();
	result->__construct();
	return result;}

hx::Object *StyleDeclarationVO_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::utils::IPoolable_obj)) return operator ::cocktail::core::utils::IPoolable_obj *();
	return super::__ToInterface(inType);
}

Void StyleDeclarationVO_obj::reset( ){
{
		HX_STACK_PUSH("StyleDeclarationVO::reset","cocktail/core/css/CSSData.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_LINE(83)
		this->style = null();
		HX_STACK_LINE(84)
		this->selector = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StyleDeclarationVO_obj,reset,(void))

::cocktail::core::utils::ObjectPool StyleDeclarationVO_obj::_pool;

::cocktail::core::utils::ObjectPool StyleDeclarationVO_obj::getPool( ){
	HX_STACK_PUSH("StyleDeclarationVO::getPool","cocktail/core/css/CSSData.hx",68);
	HX_STACK_LINE(69)
	if (((::cocktail::core::css::StyleDeclarationVO_obj::_pool == null()))){
		HX_STACK_LINE(70)
		::cocktail::core::css::StyleDeclarationVO_obj::_pool = ::cocktail::core::utils::ObjectPool_obj::__new(hx::ClassOf< ::cocktail::core::css::StyleDeclarationVO >());
	}
	HX_STACK_LINE(73)
	return ::cocktail::core::css::StyleDeclarationVO_obj::_pool;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(StyleDeclarationVO_obj,getPool,return )


StyleDeclarationVO_obj::StyleDeclarationVO_obj()
{
}

void StyleDeclarationVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StyleDeclarationVO);
	HX_MARK_MEMBER_NAME(selector,"selector");
	HX_MARK_MEMBER_NAME(style,"style");
	HX_MARK_END_CLASS();
}

void StyleDeclarationVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(selector,"selector");
	HX_VISIT_MEMBER_NAME(style,"style");
}

Dynamic StyleDeclarationVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"style") ) { return style; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getPool") ) { return getPool_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selector") ) { return selector; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StyleDeclarationVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< ::cocktail::core::utils::ObjectPool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selector") ) { selector=inValue.Cast< ::cocktail::core::css::SelectorVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StyleDeclarationVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("selector"));
	outFields->push(HX_CSTRING("style"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("getPool"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("selector"),
	HX_CSTRING("style"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleDeclarationVO_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(StyleDeclarationVO_obj::_pool,"_pool");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleDeclarationVO_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StyleDeclarationVO_obj::_pool,"_pool");
};

Class StyleDeclarationVO_obj::__mClass;

void StyleDeclarationVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.StyleDeclarationVO"), hx::TCanCast< StyleDeclarationVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StyleDeclarationVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
