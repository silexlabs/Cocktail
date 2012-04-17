#include <hxcpp.h>

#ifndef INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl
#include <cocktailCore/focus/abstract/AbstractFocusManagerImpl.h>
#endif
#ifndef INCLUDED_cocktailCore_focus_as3_FocusManagerImpl
#include <cocktailCore/focus/as3/FocusManagerImpl.h>
#endif
namespace cocktailCore{
namespace focus{
namespace as3{

Void FocusManagerImpl_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktailCore/focus/as3/FocusManagerImpl.hx",24)
	super::__construct();
}
;
	return null();
}

FocusManagerImpl_obj::~FocusManagerImpl_obj() { }

Dynamic FocusManagerImpl_obj::__CreateEmpty() { return  new FocusManagerImpl_obj; }
hx::ObjectPtr< FocusManagerImpl_obj > FocusManagerImpl_obj::__new()
{  hx::ObjectPtr< FocusManagerImpl_obj > result = new FocusManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic FocusManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusManagerImpl_obj > result = new FocusManagerImpl_obj();
	result->__construct();
	return result;}


FocusManagerImpl_obj::FocusManagerImpl_obj()
{
}

void FocusManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusManagerImpl);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FocusManagerImpl_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic FocusManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FocusManagerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FocusManagerImpl_obj::__mClass;

void FocusManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktailCore.focus.as3.FocusManagerImpl"), hx::TCanCast< FocusManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FocusManagerImpl_obj::__boot()
{
}

} // end namespace cocktailCore
} // end namespace focus
} // end namespace as3
