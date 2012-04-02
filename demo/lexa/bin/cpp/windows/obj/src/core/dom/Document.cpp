#include <hxcpp.h>

#ifndef INCLUDED_core_dom_CharacterData
#include <core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_core_dom_Document
#include <core/dom/Document.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_dom_Text
#include <core/dom/Text.h>
#endif
#ifndef INCLUDED_port_flash_player_Text
#include <port/flash_player/Text.h>
#endif
namespace core{
namespace dom{

Void Document_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/dom/Document.hx",32)
	super::__construct();
}
;
	return null();
}

Document_obj::~Document_obj() { }

Dynamic Document_obj::__CreateEmpty() { return  new Document_obj; }
hx::ObjectPtr< Document_obj > Document_obj::__new()
{  hx::ObjectPtr< Document_obj > result = new Document_obj();
	result->__construct();
	return result;}

Dynamic Document_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Document_obj > result = new Document_obj();
	result->__construct();
	return result;}

::core::dom::Element Document_obj::createElement( ::String tagName){
	HX_SOURCE_PUSH("Document_obj::createElement")
	HX_SOURCE_POS("../../src/core/dom/Document.hx",58)
	::core::dom::Element element = ::core::dom::Element_obj::__new(tagName);
	HX_SOURCE_POS("../../src/core/dom/Document.hx",59)
	return element;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createElement,return )

::port::flash_player::Text Document_obj::createTextNode( ::String data){
	HX_SOURCE_PUSH("Document_obj::createTextNode")
	HX_SOURCE_POS("../../src/core/dom/Document.hx",69)
	::port::flash_player::Text text = ::port::flash_player::Text_obj::__new();
	HX_SOURCE_POS("../../src/core/dom/Document.hx",70)
	text->set_nodeValue(data);
	HX_SOURCE_POS("../../src/core/dom/Document.hx",71)
	return text;
}


HX_DEFINE_DYNAMIC_FUNC1(Document_obj,createTextNode,return )


Document_obj::Document_obj()
{
}

void Document_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Document);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Document_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createTextNode") ) { return createTextNode_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Document_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Document_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createElement"),
	HX_CSTRING("createTextNode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Document_obj::__mClass;

void Document_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.dom.Document"), hx::TCanCast< Document_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Document_obj::__boot()
{
}

} // end namespace core
} // end namespace dom
