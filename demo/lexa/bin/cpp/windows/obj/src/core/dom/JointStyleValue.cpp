#include <hxcpp.h>

#ifndef INCLUDED_core_dom_JointStyleValue
#include <core/dom/JointStyleValue.h>
#endif
namespace core{
namespace dom{

::core::dom::JointStyleValue JointStyleValue_obj::bevel;

::core::dom::JointStyleValue JointStyleValue_obj::miter;

::core::dom::JointStyleValue JointStyleValue_obj::round;

HX_DEFINE_CREATE_ENUM(JointStyleValue_obj)

int JointStyleValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bevel")) return 2;
	if (inName==HX_CSTRING("miter")) return 0;
	if (inName==HX_CSTRING("round")) return 1;
	return super::__FindIndex(inName);
}

int JointStyleValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bevel")) return 0;
	if (inName==HX_CSTRING("miter")) return 0;
	if (inName==HX_CSTRING("round")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic JointStyleValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bevel")) return bevel;
	if (inName==HX_CSTRING("miter")) return miter;
	if (inName==HX_CSTRING("round")) return round;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("miter"),
	HX_CSTRING("round"),
	HX_CSTRING("bevel"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JointStyleValue_obj::bevel,"bevel");
	HX_MARK_MEMBER_NAME(JointStyleValue_obj::miter,"miter");
	HX_MARK_MEMBER_NAME(JointStyleValue_obj::round,"round");
};

static ::String sMemberFields[] = { ::String(null()) };
Class JointStyleValue_obj::__mClass;

Dynamic __Create_JointStyleValue_obj() { return new JointStyleValue_obj; }

void JointStyleValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.JointStyleValue"), hx::TCanCast< JointStyleValue_obj >,sStaticFields,sMemberFields,
	&__Create_JointStyleValue_obj, &__Create,
	&super::__SGetClass(), &CreateJointStyleValue_obj, sMarkStatics);
}

void JointStyleValue_obj::__boot()
{
Static(bevel) = hx::CreateEnum< JointStyleValue_obj >(HX_CSTRING("bevel"),2);
Static(miter) = hx::CreateEnum< JointStyleValue_obj >(HX_CSTRING("miter"),0);
Static(round) = hx::CreateEnum< JointStyleValue_obj >(HX_CSTRING("round"),1);
}


} // end namespace core
} // end namespace dom
