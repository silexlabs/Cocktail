#include <hxcpp.h>

#ifndef INCLUDED_nme_text_TextFieldType
#include <nme/text/TextFieldType.h>
#endif
namespace nme{
namespace text{

::nme::text::TextFieldType TextFieldType_obj::DYNAMIC;

::nme::text::TextFieldType TextFieldType_obj::INPUT;

HX_DEFINE_CREATE_ENUM(TextFieldType_obj)

int TextFieldType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("DYNAMIC")) return 0;
	if (inName==HX_CSTRING("INPUT")) return 1;
	return super::__FindIndex(inName);
}

int TextFieldType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("DYNAMIC")) return 0;
	if (inName==HX_CSTRING("INPUT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextFieldType_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("DYNAMIC")) return DYNAMIC;
	if (inName==HX_CSTRING("INPUT")) return INPUT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("DYNAMIC"),
	HX_CSTRING("INPUT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextFieldType_obj::DYNAMIC,"DYNAMIC");
	HX_MARK_MEMBER_NAME(TextFieldType_obj::INPUT,"INPUT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextFieldType_obj::__mClass;

Dynamic __Create_TextFieldType_obj() { return new TextFieldType_obj; }

void TextFieldType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.text.TextFieldType"), hx::TCanCast< TextFieldType_obj >,sStaticFields,sMemberFields,
	&__Create_TextFieldType_obj, &__Create,
	&super::__SGetClass(), &CreateTextFieldType_obj, sMarkStatics);
}

void TextFieldType_obj::__boot()
{
Static(DYNAMIC) = hx::CreateEnum< TextFieldType_obj >(HX_CSTRING("DYNAMIC"),0);
Static(INPUT) = hx::CreateEnum< TextFieldType_obj >(HX_CSTRING("INPUT"),1);
}


} // end namespace nme
} // end namespace text
