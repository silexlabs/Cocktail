#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_http_DataFormatValue
#include <cocktail/core/http/DataFormatValue.h>
#endif
namespace cocktail{
namespace core{
namespace http{

::cocktail::core::http::DataFormatValue DataFormatValue_obj::BINARY;

::cocktail::core::http::DataFormatValue DataFormatValue_obj::TEXT;

HX_DEFINE_CREATE_ENUM(DataFormatValue_obj)

int DataFormatValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BINARY")) return 0;
	if (inName==HX_CSTRING("TEXT")) return 1;
	return super::__FindIndex(inName);
}

int DataFormatValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BINARY")) return 0;
	if (inName==HX_CSTRING("TEXT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic DataFormatValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BINARY")) return BINARY;
	if (inName==HX_CSTRING("TEXT")) return TEXT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("BINARY"),
	HX_CSTRING("TEXT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DataFormatValue_obj::BINARY,"BINARY");
	HX_MARK_MEMBER_NAME(DataFormatValue_obj::TEXT,"TEXT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DataFormatValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DataFormatValue_obj::BINARY,"BINARY");
	HX_VISIT_MEMBER_NAME(DataFormatValue_obj::TEXT,"TEXT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class DataFormatValue_obj::__mClass;

Dynamic __Create_DataFormatValue_obj() { return new DataFormatValue_obj; }

void DataFormatValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.http.DataFormatValue"), hx::TCanCast< DataFormatValue_obj >,sStaticFields,sMemberFields,
	&__Create_DataFormatValue_obj, &__Create,
	&super::__SGetClass(), &CreateDataFormatValue_obj, sMarkStatics, sVisitStatic);
}

void DataFormatValue_obj::__boot()
{
Static(BINARY) = hx::CreateEnum< DataFormatValue_obj >(HX_CSTRING("BINARY"),0);
Static(TEXT) = hx::CreateEnum< DataFormatValue_obj >(HX_CSTRING("TEXT"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace http
