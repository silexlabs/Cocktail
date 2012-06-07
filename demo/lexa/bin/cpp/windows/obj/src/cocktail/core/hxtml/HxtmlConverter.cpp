#include <hxcpp.h>

#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Text
#include <cocktail/core/dom/Text.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_hxtml_HxtmlConverter
#include <cocktail/core/hxtml/HxtmlConverter.h>
#endif
#ifndef INCLUDED_cocktail_core_hxtml_StyleProxy
#include <cocktail/core/hxtml/StyleProxy.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#include <cocktail/port/flash_player/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
#ifndef INCLUDED_hxtml_Browser
#include <hxtml/Browser.h>
#endif
#ifndef INCLUDED_hxtml_IStyleProxy
#include <hxtml/IStyleProxy.h>
#endif
namespace cocktail{
namespace core{
namespace hxtml{

Void HxtmlConverter_obj::__construct()
{
	return null();
}

HxtmlConverter_obj::~HxtmlConverter_obj() { }

Dynamic HxtmlConverter_obj::__CreateEmpty() { return  new HxtmlConverter_obj; }
hx::ObjectPtr< HxtmlConverter_obj > HxtmlConverter_obj::__new()
{  hx::ObjectPtr< HxtmlConverter_obj > result = new HxtmlConverter_obj();
	result->__construct();
	return result;}

Dynamic HxtmlConverter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HxtmlConverter_obj > result = new HxtmlConverter_obj();
	result->__construct();
	return result;}

::cocktail::core::dom::Node HxtmlConverter_obj::getNode( ::String htmlString){
	HX_SOURCE_PUSH("HxtmlConverter_obj::getNode")
	HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",20)
	::cocktail::core::hxtml::StyleProxy s = ::cocktail::core::hxtml::StyleProxy_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",23)
	::hxtml::Browser browser;
	HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",26)
	browser = ::hxtml::Browser_obj::__new(::cocktail::Lib_obj::get_document()->createElement_dyn(),::cocktail::Lib_obj::get_document()->createTextNode_dyn(),::cocktail::core::hxtml::HxtmlConverter_obj::appendChild_dyn(),::cocktail::core::hxtml::HxtmlConverter_obj::setAttribute_dyn(),::cocktail::core::hxtml::HxtmlConverter_obj::invalidate_dyn(),s);
	HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",29)
	try{
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",29)
		browser->setHtml(htmlString);
	}
	catch(Dynamic __e){
		if (__e.IsClass< ::String >() ){
			::String e = __e;{
				HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",31)
				hx::Throw (HX_CSTRING("Error parsing HTML in HXTML"));
			}
		}
		else throw(__e);
	}
	HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",34)
	return browser->domRoot;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HxtmlConverter_obj,getNode,return )

Void HxtmlConverter_obj::appendChild( ::cocktail::core::dom::Node parent,::cocktail::core::dom::Node element){
{
		HX_SOURCE_PUSH("HxtmlConverter_obj::appendChild")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",40)
		parent->appendChild(element);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HxtmlConverter_obj,appendChild,(void))

Void HxtmlConverter_obj::invalidate( ){
{
		HX_SOURCE_PUSH("HxtmlConverter_obj::invalidate")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(HxtmlConverter_obj,invalidate,(void))

Void HxtmlConverter_obj::setAttribute( ::cocktail::core::dom::Node element,::String a,::String v){
{
		HX_SOURCE_PUSH("HxtmlConverter_obj::setAttribute")
		HX_SOURCE_POS("../../src/cocktail/core/hxtml/HxtmlConverter.hx",50)
		(hx::TCast< cocktail::port::flash_player::HTMLElement >::cast(element))->setAttribute(a,v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(HxtmlConverter_obj,setAttribute,(void))


HxtmlConverter_obj::HxtmlConverter_obj()
{
}

void HxtmlConverter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HxtmlConverter);
	HX_MARK_END_CLASS();
}

Dynamic HxtmlConverter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"getNode") ) { return getNode_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic HxtmlConverter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void HxtmlConverter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getNode"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("setAttribute"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class HxtmlConverter_obj::__mClass;

void HxtmlConverter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.hxtml.HxtmlConverter"), hx::TCanCast< HxtmlConverter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HxtmlConverter_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace hxtml
