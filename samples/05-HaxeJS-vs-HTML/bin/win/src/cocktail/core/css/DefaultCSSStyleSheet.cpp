#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_DefaultCSSStyleSheet
#include <cocktail/core/css/DefaultCSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
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

Void DefaultCSSStyleSheet_obj::__construct()
{
HX_STACK_PUSH("DefaultCSSStyleSheet::new","cocktail/core/css/DefaultCSSStyleSheet.hx",25);
{
	HX_STACK_LINE(25)
	super::__construct(this->getDefaultStyleSheet(),::cocktail::core::css::PropertyOriginValue_obj::USER_AGENT_dyn(),null(),null(),null(),null());
}
;
	return null();
}

DefaultCSSStyleSheet_obj::~DefaultCSSStyleSheet_obj() { }

Dynamic DefaultCSSStyleSheet_obj::__CreateEmpty() { return  new DefaultCSSStyleSheet_obj; }
hx::ObjectPtr< DefaultCSSStyleSheet_obj > DefaultCSSStyleSheet_obj::__new()
{  hx::ObjectPtr< DefaultCSSStyleSheet_obj > result = new DefaultCSSStyleSheet_obj();
	result->__construct();
	return result;}

Dynamic DefaultCSSStyleSheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DefaultCSSStyleSheet_obj > result = new DefaultCSSStyleSheet_obj();
	result->__construct();
	return result;}

::String DefaultCSSStyleSheet_obj::getDefaultStyleSheet( ){
	HX_STACK_PUSH("DefaultCSSStyleSheet::getDefaultStyleSheet","cocktail/core/css/DefaultCSSStyleSheet.hx",33);
	HX_STACK_THIS(this);
	HX_STACK_LINE(33)
	return HX_CSTRING("\r\n\t\t\t\thtml, address,\r\n\t\t\t\tblockquote,\r\n\t\t\t\tbody, dd, div,\r\n\t\t\t\tdl, dt, fieldset, form,\r\n\t\t\t\tframe, frameset,\r\n\t\t\t\th1, h2, h3, h4,\r\n\t\t\t\th5, h6, noframes,\r\n\t\t\t\tol, p, ul, center,\r\n\t\t\t\tdir, hr, menu, pre, nav   { display: block; unicode-bidi: embed }\r\n\t\t\t\tli              { display: block }\r\n\t\t\t\thead            { display: none }\r\n\t\t\t\ttable           { display: table }\r\n\t\t\t\ttr              { display: table-row }\r\n\t\t\t\tthead           { display: table-header-group }\r\n\t\t\t\ttbody           { display: table-row-group }\r\n\t\t\t\ttfoot           { display: table-footer-group }\r\n\t\t\t\tcol             { display: table-column }\r\n\t\t\t\tcolgroup        { display: table-column-group }\r\n\t\t\t\ttd, th          { display: table-cell }\r\n\t\t\t\tcaption         { display: table-caption }\r\n\t\t\t\tth              { font-weight: bolder; text-align: center }\r\n\t\t\t\tcaption         { text-align: center }\r\n\t\t\t\tbody            { margin: 8px }\r\n\t\t\t\th1              { font-size: 2em; margin: .67em 0 }\r\n\t\t\t\th2              { font-size: 1.5em; margin: .75em 0 }\r\n\t\t\t\th3              { font-size: 1.17em; margin: .83em 0 }\r\n\t\t\t\th4, p,\r\n\t\t\t\tblockquote, ul,\r\n\t\t\t\tfieldset, form,\r\n\t\t\t\tol, dl, dir,\r\n\t\t\t\tmenu            { margin: 1em 0 }\r\n\t\t\t\th5              { font-size: .83em; margin: 1.5em 0 }\r\n\t\t\t\th6              { font-size: .75em; margin: 1.67em 0 }\r\n\t\t\t\th1, h2, h3, h4,\r\n\t\t\t\th5, h6, b,\r\n\t\t\t\tstrong          { font-weight: bolder }\r\n\t\t\t\tblockquote      { margin-left: 40px; margin-right: 40px }\r\n\t\t\t\ti, cite, em,\r\n\t\t\t\tvar, address    { font-style: italic }\r\n\t\t\t\tpre, tt, code,\r\n\t\t\t\tkbd, samp       { font-family: monospace }\r\n\t\t\t\tpre             { white-space: pre }\r\n\t\t\t\tbutton, textarea,\r\n\t\t\t\tinput, select   { display: inline-block }\r\n\t\t\t\tbig             { font-size: 1.17em }\r\n\t\t\t\tsmall, sub, sup { font-size: .83em }\r\n\t\t\t\tsub             { vertical-align: sub }\r\n\t\t\t\tsup             { vertical-align: super }\r\n\t\t\t\ttable           { border-spacing: 2px; }\r\n\t\t\t\tthead, tbody,\r\n\t\t\t\ttfoot           { vertical-align: middle }\r\n\t\t\t\ttd, th, tr      { vertical-align: inherit }\r\n\t\t\t\ts, strike, del  { text-decoration: line-through }\r\n\t\t\t\thr              { border: 1px inset }\r\n\t\t\t\tol, ul, dir,\r\n\t\t\t\tmenu, dd        { margin-left: 40px }\r\n\t\t\t\tol              { list-style-type: decimal }\r\n\t\t\t\tol ul, ul ol,\r\n\t\t\t\tul ul, ol ol    { margin-top: 0; margin-bottom: 0 }\r\n\t\t\t\tu, ins          { text-decoration: underline }\r\n\t\t\t\t\r\n\t\t\t\tcenter          { text-align: center }\r\n\t\t\t\t:link, :visited { text-decoration: underline; cursor:pointer; }\r\n\t\t\t\t:focus          { outline: thin dotted invert }\r\n\t\t");
}


HX_DEFINE_DYNAMIC_FUNC0(DefaultCSSStyleSheet_obj,getDefaultStyleSheet,return )


DefaultCSSStyleSheet_obj::DefaultCSSStyleSheet_obj()
{
}

void DefaultCSSStyleSheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DefaultCSSStyleSheet);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DefaultCSSStyleSheet_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic DefaultCSSStyleSheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getDefaultStyleSheet") ) { return getDefaultStyleSheet_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DefaultCSSStyleSheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DefaultCSSStyleSheet_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getDefaultStyleSheet"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DefaultCSSStyleSheet_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DefaultCSSStyleSheet_obj::__mClass,"__mClass");
};

Class DefaultCSSStyleSheet_obj::__mClass;

void DefaultCSSStyleSheet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.DefaultCSSStyleSheet"), hx::TCanCast< DefaultCSSStyleSheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DefaultCSSStyleSheet_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
