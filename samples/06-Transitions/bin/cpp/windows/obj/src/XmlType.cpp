#include <hxcpp.h>

#ifndef INCLUDED_XmlType
#include <XmlType.h>
#endif

HX_DEFINE_CREATE_ENUM(XmlType_obj)

int XmlType_obj::__FindIndex(::String inName)
{
	return super::__FindIndex(inName);
}

int XmlType_obj::__FindArgCount(::String inName)
{
	return super::__FindArgCount(inName);
}

Dynamic XmlType_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(XmlType_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class XmlType_obj::__mClass;

Dynamic __Create_XmlType_obj() { return new XmlType_obj; }

void XmlType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("XmlType"), hx::TCanCast< XmlType_obj >,sStaticFields,sMemberFields,
	&__Create_XmlType_obj, &__Create,
	&super::__SGetClass(), &CreateXmlType_obj, sMarkStatics, sVisitStatic);
}

void XmlType_obj::__boot()
{
}


