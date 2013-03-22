#include <hxcpp.h>

#ifndef INCLUDED_neash_errors_Error
#include <neash/errors/Error.h>
#endif
#ifndef INCLUDED_neash_errors_SecurityError
#include <neash/errors/SecurityError.h>
#endif
namespace neash{
namespace errors{

Void SecurityError_obj::__construct(::String __o_inMessage)
{
HX_STACK_PUSH("SecurityError::new","neash/errors/SecurityError.hx",8);
::String inMessage = __o_inMessage.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(8)
	super::__construct(inMessage,(int)0);
}
;
	return null();
}

SecurityError_obj::~SecurityError_obj() { }

Dynamic SecurityError_obj::__CreateEmpty() { return  new SecurityError_obj; }
hx::ObjectPtr< SecurityError_obj > SecurityError_obj::__new(::String __o_inMessage)
{  hx::ObjectPtr< SecurityError_obj > result = new SecurityError_obj();
	result->__construct(__o_inMessage);
	return result;}

Dynamic SecurityError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SecurityError_obj > result = new SecurityError_obj();
	result->__construct(inArgs[0]);
	return result;}


SecurityError_obj::SecurityError_obj()
{
}

void SecurityError_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SecurityError);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SecurityError_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SecurityError_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic SecurityError_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SecurityError_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SecurityError_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SecurityError_obj::__mClass,"__mClass");
};

Class SecurityError_obj::__mClass;

void SecurityError_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.errors.SecurityError"), hx::TCanCast< SecurityError_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SecurityError_obj::__boot()
{
}

} // end namespace neash
} // end namespace errors
