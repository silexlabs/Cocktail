#include <hxcpp.h>

#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
#endif
#ifndef INCLUDED_nme_errors_RangeError
#include <nme/errors/RangeError.h>
#endif
namespace nme{
namespace errors{

Void RangeError_obj::__construct(Dynamic __o_inMessage)
{
::String inMessage = __o_inMessage.Default(HX_CSTRING(""));
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/errors/RangeError.hx",8)
	super::__construct(inMessage,(int)0);
}
;
	return null();
}

RangeError_obj::~RangeError_obj() { }

Dynamic RangeError_obj::__CreateEmpty() { return  new RangeError_obj; }
hx::ObjectPtr< RangeError_obj > RangeError_obj::__new(Dynamic __o_inMessage)
{  hx::ObjectPtr< RangeError_obj > result = new RangeError_obj();
	result->__construct(__o_inMessage);
	return result;}

Dynamic RangeError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RangeError_obj > result = new RangeError_obj();
	result->__construct(inArgs[0]);
	return result;}


RangeError_obj::RangeError_obj()
{
}

void RangeError_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RangeError);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic RangeError_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic RangeError_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void RangeError_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class RangeError_obj::__mClass;

void RangeError_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.errors.RangeError"), hx::TCanCast< RangeError_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RangeError_obj::__boot()
{
}

} // end namespace nme
} // end namespace errors
