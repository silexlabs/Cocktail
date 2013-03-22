#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyVO
#include <cocktail/core/css/PropertyVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
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

Void PropertyVO_obj::__construct()
{
HX_STACK_PUSH("PropertyVO::new","cocktail/core/css/CSSData.hx",47);
{
	HX_STACK_LINE(47)
	this->reset();
}
;
	return null();
}

PropertyVO_obj::~PropertyVO_obj() { }

Dynamic PropertyVO_obj::__CreateEmpty() { return  new PropertyVO_obj; }
hx::ObjectPtr< PropertyVO_obj > PropertyVO_obj::__new()
{  hx::ObjectPtr< PropertyVO_obj > result = new PropertyVO_obj();
	result->__construct();
	return result;}

Dynamic PropertyVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PropertyVO_obj > result = new PropertyVO_obj();
	result->__construct();
	return result;}

hx::Object *PropertyVO_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::cocktail::core::utils::IPoolable_obj)) return operator ::cocktail::core::utils::IPoolable_obj *();
	return super::__ToInterface(inType);
}

Void PropertyVO_obj::reset( ){
{
		HX_STACK_PUSH("PropertyVO::reset","cocktail/core/css/CSSData.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_LINE(53)
		this->important = false;
		HX_STACK_LINE(54)
		this->origin = null();
		HX_STACK_LINE(55)
		this->typedValue = null();
		HX_STACK_LINE(56)
		this->selector = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PropertyVO_obj,reset,(void))

::cocktail::core::utils::ObjectPool PropertyVO_obj::_pool;

::cocktail::core::utils::ObjectPool PropertyVO_obj::getPool( ){
	HX_STACK_PUSH("PropertyVO::getPool","cocktail/core/css/CSSData.hx",38);
	HX_STACK_LINE(39)
	if (((::cocktail::core::css::PropertyVO_obj::_pool == null()))){
		HX_STACK_LINE(40)
		::cocktail::core::css::PropertyVO_obj::_pool = ::cocktail::core::utils::ObjectPool_obj::__new(hx::ClassOf< ::cocktail::core::css::PropertyVO >());
	}
	HX_STACK_LINE(43)
	return ::cocktail::core::css::PropertyVO_obj::_pool;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PropertyVO_obj,getPool,return )


PropertyVO_obj::PropertyVO_obj()
{
}

void PropertyVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PropertyVO);
	HX_MARK_MEMBER_NAME(selector,"selector");
	HX_MARK_MEMBER_NAME(typedValue,"typedValue");
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(important,"important");
	HX_MARK_END_CLASS();
}

void PropertyVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(selector,"selector");
	HX_VISIT_MEMBER_NAME(typedValue,"typedValue");
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(important,"important");
}

Dynamic PropertyVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getPool") ) { return getPool_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selector") ) { return selector; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"important") ) { return important; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"typedValue") ) { return typedValue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PropertyVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< ::cocktail::core::utils::ObjectPool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< ::cocktail::core::css::PropertyOriginValue >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selector") ) { selector=inValue.Cast< ::cocktail::core::css::SelectorVO >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"important") ) { important=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"typedValue") ) { typedValue=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PropertyVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("selector"));
	outFields->push(HX_CSTRING("typedValue"));
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("important"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("getPool"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("selector"),
	HX_CSTRING("typedValue"),
	HX_CSTRING("origin"),
	HX_CSTRING("important"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PropertyVO_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PropertyVO_obj::_pool,"_pool");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PropertyVO_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PropertyVO_obj::_pool,"_pool");
};

Class PropertyVO_obj::__mClass;

void PropertyVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.PropertyVO"), hx::TCanCast< PropertyVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PropertyVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
