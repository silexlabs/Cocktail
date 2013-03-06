#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_MediaList
#include <cocktail/core/css/MediaList.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void StyleSheet_obj::__construct(::String stylesheet,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet)
{
HX_STACK_PUSH("StyleSheet::new","cocktail/core/css/StyleSheet.hx",67);
{
	HX_STACK_LINE(68)
	this->ownerNode = ownerNode;
	HX_STACK_LINE(69)
	this->href = href;
	HX_STACK_LINE(70)
	this->parentStyleSheet = parentStyleSheet;
}
;
	return null();
}

StyleSheet_obj::~StyleSheet_obj() { }

Dynamic StyleSheet_obj::__CreateEmpty() { return  new StyleSheet_obj; }
hx::ObjectPtr< StyleSheet_obj > StyleSheet_obj::__new(::String stylesheet,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet)
{  hx::ObjectPtr< StyleSheet_obj > result = new StyleSheet_obj();
	result->__construct(stylesheet,ownerNode,href,parentStyleSheet);
	return result;}

Dynamic StyleSheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StyleSheet_obj > result = new StyleSheet_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


StyleSheet_obj::StyleSheet_obj()
{
}

void StyleSheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StyleSheet);
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	HX_MARK_MEMBER_NAME(media,"media");
	HX_MARK_MEMBER_NAME(title,"title");
	HX_MARK_MEMBER_NAME(parentStyleSheet,"parentStyleSheet");
	HX_MARK_MEMBER_NAME(ownerNode,"ownerNode");
	HX_MARK_MEMBER_NAME(href,"href");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_END_CLASS();
}

void StyleSheet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	HX_VISIT_MEMBER_NAME(media,"media");
	HX_VISIT_MEMBER_NAME(title,"title");
	HX_VISIT_MEMBER_NAME(parentStyleSheet,"parentStyleSheet");
	HX_VISIT_MEMBER_NAME(ownerNode,"ownerNode");
	HX_VISIT_MEMBER_NAME(href,"href");
	HX_VISIT_MEMBER_NAME(type,"type");
}

Dynamic StyleSheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { return href; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { return media; }
		if (HX_FIELD_EQ(inName,"title") ) { return title; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"disabled") ) { return disabled; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ownerNode") ) { return ownerNode; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parentStyleSheet") ) { return parentStyleSheet; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StyleSheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { href=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { media=inValue.Cast< ::cocktail::core::css::MediaList >(); return inValue; }
		if (HX_FIELD_EQ(inName,"title") ) { title=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"disabled") ) { disabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ownerNode") ) { ownerNode=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parentStyleSheet") ) { parentStyleSheet=inValue.Cast< ::cocktail::core::css::StyleSheet >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StyleSheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("disabled"));
	outFields->push(HX_CSTRING("media"));
	outFields->push(HX_CSTRING("title"));
	outFields->push(HX_CSTRING("parentStyleSheet"));
	outFields->push(HX_CSTRING("ownerNode"));
	outFields->push(HX_CSTRING("href"));
	outFields->push(HX_CSTRING("type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("disabled"),
	HX_CSTRING("media"),
	HX_CSTRING("title"),
	HX_CSTRING("parentStyleSheet"),
	HX_CSTRING("ownerNode"),
	HX_CSTRING("href"),
	HX_CSTRING("type"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleSheet_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleSheet_obj::__mClass,"__mClass");
};

Class StyleSheet_obj::__mClass;

void StyleSheet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.StyleSheet"), hx::TCanCast< StyleSheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StyleSheet_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
