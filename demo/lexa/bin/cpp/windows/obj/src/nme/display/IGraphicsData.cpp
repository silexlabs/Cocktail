#include <hxcpp.h>

#ifndef INCLUDED_nme_display_IGraphicsData
#include <nme/display/IGraphicsData.h>
#endif
namespace nme{
namespace display{

Void IGraphicsData_obj::__construct(Dynamic inHandle)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/IGraphicsData.hx",15)
	this->nmeHandle = inHandle;
}
;
	return null();
}

IGraphicsData_obj::~IGraphicsData_obj() { }

Dynamic IGraphicsData_obj::__CreateEmpty() { return  new IGraphicsData_obj; }
hx::ObjectPtr< IGraphicsData_obj > IGraphicsData_obj::__new(Dynamic inHandle)
{  hx::ObjectPtr< IGraphicsData_obj > result = new IGraphicsData_obj();
	result->__construct(inHandle);
	return result;}

Dynamic IGraphicsData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IGraphicsData_obj > result = new IGraphicsData_obj();
	result->__construct(inArgs[0]);
	return result;}


IGraphicsData_obj::IGraphicsData_obj()
{
}

void IGraphicsData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IGraphicsData);
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic IGraphicsData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
	}
	return super::__Field(inName);
}

Dynamic IGraphicsData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IGraphicsData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeHandle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class IGraphicsData_obj::__mClass;

void IGraphicsData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.IGraphicsData"), hx::TCanCast< IGraphicsData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IGraphicsData_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
