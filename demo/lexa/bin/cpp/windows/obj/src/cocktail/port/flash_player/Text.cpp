#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_CharacterData
#include <cocktail/core/dom/CharacterData.h>
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
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Text
#include <cocktail/port/flash_player/Text.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void Text_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",26)
	super::__construct();
}
;
	return null();
}

Text_obj::~Text_obj() { }

Dynamic Text_obj::__CreateEmpty() { return  new Text_obj; }
hx::ObjectPtr< Text_obj > Text_obj::__new()
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

Dynamic Text_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Text_obj > result = new Text_obj();
	result->__construct();
	return result;}

::String Text_obj::set_data( ::String value){
	HX_SOURCE_PUSH("Text_obj::set_data")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",37)
	this->super::set_data(value);
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",39)
	this->reset();
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",40)
	this->_textFragments = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",42)
	if (((this->_parentNode != null()))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",44)
		::cocktail::port::flash_player::HTMLElement parent = this->_parentNode;
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",45)
		parent->get_coreStyle()->invalidateText();
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Text.hx",48)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Text_obj,set_data,return )


Text_obj::Text_obj()
{
}

void Text_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Text);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Text_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"set_data") ) { return set_data_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Text_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Text_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Text_obj::__mClass;

void Text_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.Text"), hx::TCanCast< Text_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Text_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
