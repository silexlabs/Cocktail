#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLInputElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",64)
	super::__construct(HX_CSTRING("input"));
}
;
	return null();
}

HTMLInputElement_obj::~HTMLInputElement_obj() { }

Dynamic HTMLInputElement_obj::__CreateEmpty() { return  new HTMLInputElement_obj; }
hx::ObjectPtr< HTMLInputElement_obj > HTMLInputElement_obj::__new()
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLInputElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

Void HTMLInputElement_obj::init( ){
{
		HX_SOURCE_PUSH("HTMLInputElement_obj::init")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",80)
		this->super::init();
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",82)
		this->_disabled = false;
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",83)
		this->_value = HX_CSTRING("");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,init,(void))

Void HTMLInputElement_obj::initCoreStyle( ){
{
		HX_SOURCE_PUSH("HTMLInputElement_obj::initCoreStyle")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",93)
		this->_coreStyle = ::cocktail::core::style::CoreStyle_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,initCoreStyle,(void))

Dynamic HTMLInputElement_obj::set_onChange( Dynamic value){
	HX_SOURCE_PUSH("HTMLInputElement_obj::set_onChange")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",103)
	return this->_onChange = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_onChange,return )

Dynamic HTMLInputElement_obj::get_onChange( ){
	HX_SOURCE_PUSH("HTMLInputElement_obj::get_onChange")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",108)
	return this->_onChange_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_onChange,return )

Void HTMLInputElement_obj::onChangeCallback( ){
{
		HX_SOURCE_PUSH("HTMLInputElement_obj::onChangeCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",118)
		if (((this->_onChange_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",120)
			this->_onChange();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,onChangeCallback,(void))

bool HTMLInputElement_obj::set_disabled( bool value){
	HX_SOURCE_PUSH("HTMLInputElement_obj::set_disabled")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",130)
	return this->_disabled = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_disabled,return )

bool HTMLInputElement_obj::get_disabled( ){
	HX_SOURCE_PUSH("HTMLInputElement_obj::get_disabled")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",135)
	return this->_disabled;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_disabled,return )

int HTMLInputElement_obj::set_maxLength( int value){
	HX_SOURCE_PUSH("HTMLInputElement_obj::set_maxLength")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",140)
	return this->_maxLength = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_maxLength,return )

int HTMLInputElement_obj::get_maxLength( ){
	HX_SOURCE_PUSH("HTMLInputElement_obj::get_maxLength")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",145)
	return this->_maxLength;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_maxLength,return )

::String HTMLInputElement_obj::set_value( ::String value){
	HX_SOURCE_PUSH("HTMLInputElement_obj::set_value")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",150)
	return this->_value = value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLInputElement_obj,set_value,return )

::String HTMLInputElement_obj::get_value( ){
	HX_SOURCE_PUSH("HTMLInputElement_obj::get_value")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLInputElement.hx",155)
	return this->_value;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLInputElement_obj,get_value,return )

::String HTMLInputElement_obj::HTML_INPUT_TAG_NAME;


HTMLInputElement_obj::HTMLInputElement_obj()
{
}

void HTMLInputElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLInputElement);
	HX_MARK_MEMBER_NAME(_onChange,"_onChange");
	HX_MARK_MEMBER_NAME(onchange,"onchange");
	HX_MARK_MEMBER_NAME(_disabled,"_disabled");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(_maxLength,"_maxLength");
	HX_MARK_MEMBER_NAME(maxLength,"maxLength");
	HX_MARK_MEMBER_NAME(_value,"_value");
	HX_MARK_MEMBER_NAME(value,"value");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLInputElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return get_value(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { return _value; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onchange") ) { return get_onChange(); }
		if (HX_FIELD_EQ(inName,"disabled") ) { return get_disabled(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onChange") ) { return _onChange; }
		if (HX_FIELD_EQ(inName,"_disabled") ) { return _disabled; }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return get_maxLength(); }
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_maxLength") ) { return _maxLength; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_onChange") ) { return set_onChange_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onChange") ) { return get_onChange_dyn(); }
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"get_disabled") ) { return get_disabled_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxLength") ) { return set_maxLength_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxLength") ) { return get_maxLength_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onChangeCallback") ) { return onChangeCallback_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TAG_NAME") ) { return HTML_INPUT_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic HTMLInputElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return set_value(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_value") ) { _value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onchange") ) { return set_onChange(inValue); }
		if (HX_FIELD_EQ(inName,"disabled") ) { return set_disabled(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_onChange") ) { _onChange=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_disabled") ) { _disabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxLength") ) { return set_maxLength(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_maxLength") ) { _maxLength=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"HTML_INPUT_TAG_NAME") ) { HTML_INPUT_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLInputElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_disabled"));
	outFields->push(HX_CSTRING("disabled"));
	outFields->push(HX_CSTRING("_maxLength"));
	outFields->push(HX_CSTRING("maxLength"));
	outFields->push(HX_CSTRING("_value"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_INPUT_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onChange"),
	HX_CSTRING("onchange"),
	HX_CSTRING("_disabled"),
	HX_CSTRING("disabled"),
	HX_CSTRING("_maxLength"),
	HX_CSTRING("maxLength"),
	HX_CSTRING("_value"),
	HX_CSTRING("value"),
	HX_CSTRING("init"),
	HX_CSTRING("initCoreStyle"),
	HX_CSTRING("set_onChange"),
	HX_CSTRING("get_onChange"),
	HX_CSTRING("onChangeCallback"),
	HX_CSTRING("set_disabled"),
	HX_CSTRING("get_disabled"),
	HX_CSTRING("set_maxLength"),
	HX_CSTRING("get_maxLength"),
	HX_CSTRING("set_value"),
	HX_CSTRING("get_value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLInputElement_obj::HTML_INPUT_TAG_NAME,"HTML_INPUT_TAG_NAME");
};

Class HTMLInputElement_obj::__mClass;

void HTMLInputElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLInputElement"), hx::TCanCast< HTMLInputElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLInputElement_obj::__boot()
{
	hx::Static(HTML_INPUT_TAG_NAME) = HX_CSTRING("input");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
