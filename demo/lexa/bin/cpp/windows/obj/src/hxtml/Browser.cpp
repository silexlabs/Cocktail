#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_XmlType
#include <XmlType.h>
#endif
#ifndef INCLUDED_hxtml_Browser
#include <hxtml/Browser.h>
#endif
#ifndef INCLUDED_hxtml_CssParser
#include <hxtml/CssParser.h>
#endif
#ifndef INCLUDED_hxtml_IStyleProxy
#include <hxtml/IStyleProxy.h>
#endif
namespace hxtml{

Void Browser_obj::__construct(Dynamic createElement,Dynamic createTextNode,Dynamic appendChild,Dynamic setAttribute,Dynamic invalidate,::hxtml::IStyleProxy styleProxy)
{
{
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",45)
	this->createElement = createElement;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",46)
	this->createTextNode = createTextNode;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",47)
	this->appendChild = appendChild;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",48)
	this->setAttribute = setAttribute;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",49)
	this->invalidate = invalidate;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",50)
	this->styleProxy = styleProxy;
}
;
	return null();
}

Browser_obj::~Browser_obj() { }

Dynamic Browser_obj::__CreateEmpty() { return  new Browser_obj; }
hx::ObjectPtr< Browser_obj > Browser_obj::__new(Dynamic createElement,Dynamic createTextNode,Dynamic appendChild,Dynamic setAttribute,Dynamic invalidate,::hxtml::IStyleProxy styleProxy)
{  hx::ObjectPtr< Browser_obj > result = new Browser_obj();
	result->__construct(createElement,createTextNode,appendChild,setAttribute,invalidate,styleProxy);
	return result;}

Dynamic Browser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Browser_obj > result = new Browser_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void Browser_obj::_register( ::String id,Dynamic d){
{
		HX_SOURCE_PUSH("Browser_obj::register")
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",53)
		this->ids->set(id,d);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Browser_obj,_register,(void))

Void Browser_obj::setHtml( ::String data){
{
		HX_SOURCE_PUSH("Browser_obj::setHtml")
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",58)
		::Xml x = ::Xml_obj::parse(data)->firstElement();
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",59)
		this->ids = ::Hash_obj::__new();
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",60)
		this->domRoot = this->make(x);
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",61)
		this->refresh();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Browser_obj,setHtml,(void))

Void Browser_obj::refresh( ){
{
		HX_SOURCE_PUSH("Browser_obj::refresh")
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",65)
		this->invalid = false;
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",66)
		if (((this->invalidate_dyn() != null()))){
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",67)
			this->invalidate();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Browser_obj,refresh,(void))

Dynamic Browser_obj::getById( ::String id){
	HX_SOURCE_PUSH("Browser_obj::getById")
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",70)
	return this->ids->get(id);
}


HX_DEFINE_DYNAMIC_FUNC1(Browser_obj,getById,return )

Dynamic Browser_obj::make( ::Xml x){
	HX_SOURCE_PUSH("Browser_obj::make")
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",76)
	::XmlType _switch_1 = (x->nodeType);
	if (  ( _switch_1==::Xml_obj::CData)){
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",77)
		hx::Throw (HX_CSTRING("assert"));
	}
	else if (  ( _switch_1==::Xml_obj::PCData) ||  ( _switch_1==::Xml_obj::Comment)){
		HX_SOURCE_POS("../../lib/hxtml/Browser.hx",79)
		return this->createTextNode(x->getNodeValue());
	}
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",82)
	Dynamic d;
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",83)
	::String name = x->getNodeName().toLowerCase();
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",84)
	d = this->createElement(name);
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",87)
	bool allowSpaces = !(((bool((bool((bool((bool((name == HX_CSTRING("head"))) || bool((name == HX_CSTRING("link"))))) || bool((name == HX_CSTRING("meta"))))) || bool((name == HX_CSTRING("title"))))) || bool((name == HX_CSTRING("html"))))));
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",88)
	bool allowComments = (name == HX_CSTRING("style"));
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",91)
	Dynamic prev = null();
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",93)
	for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(x->iterator());  __it->hasNext(); ){
		::Xml c = __it->next();
		{
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",95)
			::XmlType _switch_2 = (c->nodeType);
			if (  ( _switch_2==::Xml_obj::PCData)){
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",96)
				if ((::EReg_obj::__new(HX_CSTRING("^[ \n\r\t]*$"),HX_CSTRING(""))->match(c->getNodeValue()))){
					HX_SOURCE_POS("../../lib/hxtml/Browser.hx",97)
					if (((bool(!(allowSpaces)) || bool((prev == null()))))){
						HX_SOURCE_POS("../../lib/hxtml/Browser.hx",99)
						continue;
					}
				}
			}
			else if (  ( _switch_2==::Xml_obj::Comment)){
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",110)
				if ((!(allowComments))){
					HX_SOURCE_POS("../../lib/hxtml/Browser.hx",112)
					continue;
				}
			}
			else  {
			}
;
;
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",119)
			prev = this->make(c);
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",120)
			this->appendChild(d,prev);
		}
;
	}
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",123)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(x->attributes());  __it->hasNext(); ){
		::String a = __it->next();
		{
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",124)
			a = a.toLowerCase();
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",125)
			::String v = x->get(a);
			HX_SOURCE_POS("../../lib/hxtml/Browser.hx",126)
			::String _switch_3 = (a);
			if (  ( _switch_3==HX_CSTRING("id"))){
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",128)
				this->_register(v,d);
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",129)
				this->setAttribute(d,a,v);
			}
			else if (  ( _switch_3==HX_CSTRING("style"))){
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",130)
				::hxtml::CssParser_obj::__new()->parse(v,d,this->styleProxy);
			}
			else if (  ( _switch_3==HX_CSTRING("class"))){
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",132)
				hx::Throw (HX_CSTRING("'class' attribute not implemented yet"));
			}
			else  {
				HX_SOURCE_POS("../../lib/hxtml/Browser.hx",135)
				this->setAttribute(d,a,v);
			}
;
;
		}
;
	}
	HX_SOURCE_POS("../../lib/hxtml/Browser.hx",139)
	return d;
}


HX_DEFINE_DYNAMIC_FUNC1(Browser_obj,make,return )


Browser_obj::Browser_obj()
{
}

void Browser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Browser);
	HX_MARK_MEMBER_NAME(html,"html");
	HX_MARK_MEMBER_NAME(domRoot,"domRoot");
	HX_MARK_MEMBER_NAME(ids,"ids");
	HX_MARK_MEMBER_NAME(invalid,"invalid");
	HX_MARK_MEMBER_NAME(createElement,"createElement");
	HX_MARK_MEMBER_NAME(createTextNode,"createTextNode");
	HX_MARK_MEMBER_NAME(appendChild,"appendChild");
	HX_MARK_MEMBER_NAME(setAttribute,"setAttribute");
	HX_MARK_MEMBER_NAME(invalidate,"invalidate");
	HX_MARK_MEMBER_NAME(styleProxy,"styleProxy");
	HX_MARK_END_CLASS();
}

Dynamic Browser_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ids") ) { return ids; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"html") ) { return html; }
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"domRoot") ) { return domRoot; }
		if (HX_FIELD_EQ(inName,"invalid") ) { return invalid; }
		if (HX_FIELD_EQ(inName,"setHtml") ) { return setHtml_dyn(); }
		if (HX_FIELD_EQ(inName,"refresh") ) { return refresh_dyn(); }
		if (HX_FIELD_EQ(inName,"getById") ) { return getById_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"register") ) { return _register_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate; }
		if (HX_FIELD_EQ(inName,"styleProxy") ) { return styleProxy; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendChild") ) { return appendChild; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAttribute") ) { return setAttribute; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createTextNode") ) { return createTextNode; }
	}
	return super::__Field(inName);
}

Dynamic Browser_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ids") ) { ids=inValue.Cast< ::Hash >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"html") ) { html=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"domRoot") ) { domRoot=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"invalid") ) { invalid=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { invalidate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"styleProxy") ) { styleProxy=inValue.Cast< ::hxtml::IStyleProxy >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"appendChild") ) { appendChild=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setAttribute") ) { setAttribute=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { createElement=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"createTextNode") ) { createTextNode=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Browser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("html"));
	outFields->push(HX_CSTRING("domRoot"));
	outFields->push(HX_CSTRING("ids"));
	outFields->push(HX_CSTRING("invalid"));
	outFields->push(HX_CSTRING("styleProxy"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("html"),
	HX_CSTRING("domRoot"),
	HX_CSTRING("ids"),
	HX_CSTRING("invalid"),
	HX_CSTRING("createElement"),
	HX_CSTRING("createTextNode"),
	HX_CSTRING("appendChild"),
	HX_CSTRING("setAttribute"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("styleProxy"),
	HX_CSTRING("register"),
	HX_CSTRING("setHtml"),
	HX_CSTRING("refresh"),
	HX_CSTRING("getById"),
	HX_CSTRING("make"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Browser_obj::__mClass;

void Browser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("hxtml.Browser"), hx::TCanCast< Browser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Browser_obj::__boot()
{
}

} // end namespace hxtml
