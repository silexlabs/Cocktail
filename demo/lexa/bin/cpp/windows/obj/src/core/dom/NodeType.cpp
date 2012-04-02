#include <hxcpp.h>

#ifndef INCLUDED_core_dom_NodeType
#include <core/dom/NodeType.h>
#endif
namespace core{
namespace dom{

::core::dom::NodeType NodeType_obj::DOCUMENT_NODE;

::core::dom::NodeType NodeType_obj::ELEMENT_NODE;

::core::dom::NodeType NodeType_obj::TEXT_NODE;

HX_DEFINE_CREATE_ENUM(NodeType_obj)

int NodeType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("DOCUMENT_NODE")) return 2;
	if (inName==HX_CSTRING("ELEMENT_NODE")) return 0;
	if (inName==HX_CSTRING("TEXT_NODE")) return 1;
	return super::__FindIndex(inName);
}

int NodeType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("DOCUMENT_NODE")) return 0;
	if (inName==HX_CSTRING("ELEMENT_NODE")) return 0;
	if (inName==HX_CSTRING("TEXT_NODE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic NodeType_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("DOCUMENT_NODE")) return DOCUMENT_NODE;
	if (inName==HX_CSTRING("ELEMENT_NODE")) return ELEMENT_NODE;
	if (inName==HX_CSTRING("TEXT_NODE")) return TEXT_NODE;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ELEMENT_NODE"),
	HX_CSTRING("TEXT_NODE"),
	HX_CSTRING("DOCUMENT_NODE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NodeType_obj::DOCUMENT_NODE,"DOCUMENT_NODE");
	HX_MARK_MEMBER_NAME(NodeType_obj::ELEMENT_NODE,"ELEMENT_NODE");
	HX_MARK_MEMBER_NAME(NodeType_obj::TEXT_NODE,"TEXT_NODE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class NodeType_obj::__mClass;

Dynamic __Create_NodeType_obj() { return new NodeType_obj; }

void NodeType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.NodeType"), hx::TCanCast< NodeType_obj >,sStaticFields,sMemberFields,
	&__Create_NodeType_obj, &__Create,
	&super::__SGetClass(), &CreateNodeType_obj, sMarkStatics);
}

void NodeType_obj::__boot()
{
Static(DOCUMENT_NODE) = hx::CreateEnum< NodeType_obj >(HX_CSTRING("DOCUMENT_NODE"),2);
Static(ELEMENT_NODE) = hx::CreateEnum< NodeType_obj >(HX_CSTRING("ELEMENT_NODE"),0);
Static(TEXT_NODE) = hx::CreateEnum< NodeType_obj >(HX_CSTRING("TEXT_NODE"),1);
}


} // end namespace core
} // end namespace dom
