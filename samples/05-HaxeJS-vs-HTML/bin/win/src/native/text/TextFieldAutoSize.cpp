#include <hxcpp.h>

#ifndef INCLUDED_native_text_TextFieldAutoSize
#include <native/text/TextFieldAutoSize.h>
#endif
namespace native{
namespace text{

::native::text::TextFieldAutoSize TextFieldAutoSize_obj::CENTER;

::native::text::TextFieldAutoSize TextFieldAutoSize_obj::LEFT;

::native::text::TextFieldAutoSize TextFieldAutoSize_obj::NONE;

::native::text::TextFieldAutoSize TextFieldAutoSize_obj::RIGHT;

HX_DEFINE_CREATE_ENUM(TextFieldAutoSize_obj)

int TextFieldAutoSize_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CENTER")) return 0;
	if (inName==HX_CSTRING("LEFT")) return 1;
	if (inName==HX_CSTRING("NONE")) return 2;
	if (inName==HX_CSTRING("RIGHT")) return 3;
	return super::__FindIndex(inName);
}

int TextFieldAutoSize_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CENTER")) return 0;
	if (inName==HX_CSTRING("LEFT")) return 0;
	if (inName==HX_CSTRING("NONE")) return 0;
	if (inName==HX_CSTRING("RIGHT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TextFieldAutoSize_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CENTER")) return CENTER;
	if (inName==HX_CSTRING("LEFT")) return LEFT;
	if (inName==HX_CSTRING("NONE")) return NONE;
	if (inName==HX_CSTRING("RIGHT")) return RIGHT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("CENTER"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("NONE"),
	HX_CSTRING("RIGHT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextFieldAutoSize_obj::CENTER,"CENTER");
	HX_MARK_MEMBER_NAME(TextFieldAutoSize_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(TextFieldAutoSize_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(TextFieldAutoSize_obj::RIGHT,"RIGHT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextFieldAutoSize_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TextFieldAutoSize_obj::CENTER,"CENTER");
	HX_VISIT_MEMBER_NAME(TextFieldAutoSize_obj::LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(TextFieldAutoSize_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(TextFieldAutoSize_obj::RIGHT,"RIGHT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TextFieldAutoSize_obj::__mClass;

Dynamic __Create_TextFieldAutoSize_obj() { return new TextFieldAutoSize_obj; }

void TextFieldAutoSize_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.text.TextFieldAutoSize"), hx::TCanCast< TextFieldAutoSize_obj >,sStaticFields,sMemberFields,
	&__Create_TextFieldAutoSize_obj, &__Create,
	&super::__SGetClass(), &CreateTextFieldAutoSize_obj, sMarkStatics, sVisitStatic);
}

void TextFieldAutoSize_obj::__boot()
{
Static(CENTER) = hx::CreateEnum< TextFieldAutoSize_obj >(HX_CSTRING("CENTER"),0);
Static(LEFT) = hx::CreateEnum< TextFieldAutoSize_obj >(HX_CSTRING("LEFT"),1);
Static(NONE) = hx::CreateEnum< TextFieldAutoSize_obj >(HX_CSTRING("NONE"),2);
Static(RIGHT) = hx::CreateEnum< TextFieldAutoSize_obj >(HX_CSTRING("RIGHT"),3);
}


} // end namespace native
} // end namespace text
