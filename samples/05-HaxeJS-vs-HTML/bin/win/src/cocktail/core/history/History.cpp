#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_cocktail_Lib
#include <cocktail/Lib.h>
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
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_PopStateEvent
#include <cocktail/core/event/PopStateEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_history_History
#include <cocktail/core/history/History.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
namespace cocktail{
namespace core{
namespace history{

Void History_obj::__construct()
{
HX_STACK_PUSH("History::new","cocktail/core/history/History.hx",47);
{
	HX_STACK_LINE(49)
	this->stateDataArray = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(50)
	this->currentIdx = (int)0;
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","cocktail/core/history/History.hx",54);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("state") , null(),false);
				__result->Add(HX_CSTRING("title") , HX_CSTRING(""),false);
				__result->Add(HX_CSTRING("url") , null(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(54)
	this->stateDataArray->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block());
}
;
	return null();
}

History_obj::~History_obj() { }

Dynamic History_obj::__CreateEmpty() { return  new History_obj; }
hx::ObjectPtr< History_obj > History_obj::__new()
{  hx::ObjectPtr< History_obj > result = new History_obj();
	result->__construct();
	return result;}

Dynamic History_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< History_obj > result = new History_obj();
	result->__construct();
	return result;}

::String History_obj::resolveUrl( ::String url,::String base){
	HX_STACK_PUSH("History::resolveUrl","cocktail/core/history/History.hx",205);
	HX_STACK_THIS(this);
	HX_STACK_ARG(url,"url");
	HX_STACK_ARG(base,"base");
	HX_STACK_LINE(208)
	if (((base == null()))){
		HX_STACK_LINE(211)
		Array< ::cocktail::core::html::HTMLElement > tags = ::cocktail::Lib_obj::get_document()->getElementsByTagName(HX_CSTRING("base"));		HX_STACK_VAR(tags,"tags");
		HX_STACK_LINE(212)
		{
			HX_STACK_LINE(212)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = tags->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(212)
			while(((_g1 < _g))){
				HX_STACK_LINE(212)
				int idx = (_g1)++;		HX_STACK_VAR(idx,"idx");
				HX_STACK_LINE(214)
				if ((tags->__get(idx)->hasAttribute(HX_CSTRING("href")))){
					HX_STACK_LINE(216)
					base = tags->__get(idx)->getAttribute(HX_CSTRING("href"));
					HX_STACK_LINE(217)
					break;
				}
			}
		}
		HX_STACK_LINE(221)
		if (((base == null()))){
			HX_STACK_LINE(222)
			base = HX_CSTRING("");
		}
	}
	HX_STACK_LINE(230)
	url = ::StringTools_obj::replace(url,HX_CSTRING("\\"),HX_CSTRING("/"));
	HX_STACK_LINE(233)
	int idxBase = url.indexOf(HX_CSTRING("http"),null());		HX_STACK_VAR(idxBase,"idxBase");
	HX_STACK_LINE(234)
	if (((idxBase != (int)0))){
		HX_STACK_LINE(235)
		url = (base + url);
	}
	HX_STACK_LINE(240)
	Array< ::String > urlArray = url.split(HX_CSTRING("/"));		HX_STACK_VAR(urlArray,"urlArray");
	HX_STACK_LINE(241)
	Array< ::String > absoluteUrlArray = Array_obj< ::String >::__new();		HX_STACK_VAR(absoluteUrlArray,"absoluteUrlArray");
	HX_STACK_LINE(242)
	{
		HX_STACK_LINE(242)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = urlArray->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(242)
		while(((_g1 < _g))){
			HX_STACK_LINE(242)
			int idx = (_g1)++;		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(245)
			if (((urlArray->__get(idx) == HX_CSTRING("..")))){
				HX_STACK_LINE(245)
				absoluteUrlArray->pop();
			}
			else{
				HX_STACK_LINE(249)
				absoluteUrlArray->push(urlArray->__get(idx));
			}
		}
	}
	HX_STACK_LINE(254)
	url = absoluteUrlArray->join(HX_CSTRING("/"));
	HX_STACK_LINE(257)
	return url;
}


HX_DEFINE_DYNAMIC_FUNC2(History_obj,resolveUrl,return )

Dynamic History_obj::computeStateData( Dynamic data,::String title,::String url){
	HX_STACK_PUSH("History::computeStateData","cocktail/core/history/History.hx",171);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_ARG(title,"title");
	HX_STACK_ARG(url,"url");
	HX_STACK_LINE(173)
	Dynamic clonedData;		HX_STACK_VAR(clonedData,"clonedData");
	HX_STACK_LINE(174)
	try{
		HX_STACK_LINE(175)
		clonedData = this->cloneData(data);
	}
	catch(Dynamic __e){
		{
			Dynamic e = __e;{
				HX_STACK_LINE(179)
				hx::Throw ((HX_CSTRING("SecurityError - Error duplicating the data passed to History::replaceState or History::pushState. The error is: ") + ::Std_obj::string(e)));
			}
		}
	}
	HX_STACK_LINE(183)
	if (((url != null()))){
		HX_STACK_LINE(184)
		url = this->resolveUrl(url,null());
	}
	else{
		HX_STACK_LINE(190)
		url = this->stateDataArray->__GetItem(this->currentIdx)->__Field(HX_CSTRING("url"),true);
	}
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &clonedData,::String &title,::String &url){
			HX_STACK_PUSH("*::closure","cocktail/core/history/History.hx",194);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("state") , clonedData,false);
				__result->Add(HX_CSTRING("title") , title,false);
				__result->Add(HX_CSTRING("url") , url,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(194)
	return _Function_1_1::Block(clonedData,title,url);
}


HX_DEFINE_DYNAMIC_FUNC3(History_obj,computeStateData,return )

Dynamic History_obj::cloneData( Dynamic data){
	HX_STACK_PUSH("History::cloneData","cocktail/core/history/History.hx",162);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_LINE(162)
	return ::haxe::Unserializer_obj::run(::haxe::Serializer_obj::run(data));
}


HX_DEFINE_DYNAMIC_FUNC1(History_obj,cloneData,return )

Void History_obj::onPopState( Dynamic stateData){
{
		HX_STACK_PUSH("History::onPopState","cocktail/core/history/History.hx",142);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stateData,"stateData");
		HX_STACK_LINE(144)
		Dynamic clonedState = this->cloneData(stateData->__Field(HX_CSTRING("state"),true));		HX_STACK_VAR(clonedState,"clonedState");
		HX_STACK_LINE(147)
		::cocktail::core::event::PopStateEvent event = ::cocktail::core::event::PopStateEvent_obj::__new();		HX_STACK_VAR(event,"event");
		HX_STACK_LINE(148)
		event->initPopStateEvent(HX_CSTRING("popstate"),true,false,null(),0.0,clonedState);
		HX_STACK_LINE(150)
		::cocktail::Lib_obj::get_window()->dispatchEvent(event);
		HX_STACK_LINE(153)
		if (((::cocktail::Lib_obj::get_window()->onpopstate_dyn() != null()))){
			HX_STACK_LINE(154)
			::cocktail::Lib_obj::get_window()->onpopstate(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(History_obj,onPopState,(void))

Void History_obj::replaceState( Dynamic data,::String title,::String url){
{
		HX_STACK_PUSH("History::replaceState","cocktail/core/history/History.hx",129);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(title,"title");
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(130)
		Dynamic newStateData = this->computeStateData(data,title,url);		HX_STACK_VAR(newStateData,"newStateData");
		HX_STACK_LINE(131)
		hx::IndexRef((this->stateDataArray).mPtr,this->currentIdx) = newStateData;
		HX_STACK_LINE(135)
		this->state = this->cloneData(newStateData->__Field(HX_CSTRING("state"),true));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(History_obj,replaceState,(void))

Void History_obj::pushState( Dynamic data,::String title,::String url){
{
		HX_STACK_PUSH("History::pushState","cocktail/core/history/History.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(title,"title");
		HX_STACK_ARG(url,"url");
		HX_STACK_LINE(111)
		while(((this->stateDataArray->__Field(HX_CSTRING("length"),true) > (this->currentIdx + (int)1)))){
			HX_STACK_LINE(112)
			this->stateDataArray->__Field(HX_CSTRING("pop"),true)();
		}
		HX_STACK_LINE(117)
		Dynamic newStateData = this->computeStateData(data,title,url);		HX_STACK_VAR(newStateData,"newStateData");
		HX_STACK_LINE(118)
		this->stateDataArray->__Field(HX_CSTRING("push"),true)(newStateData);
		HX_STACK_LINE(119)
		(this->currentIdx)++;
		HX_STACK_LINE(123)
		this->state = this->cloneData(newStateData->__Field(HX_CSTRING("state"),true));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(History_obj,pushState,(void))

Void History_obj::forward( ){
{
		HX_STACK_PUSH("History::forward","cocktail/core/history/History.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		this->go((int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(History_obj,forward,(void))

Void History_obj::back( ){
{
		HX_STACK_PUSH("History::back","cocktail/core/history/History.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_LINE(95)
		this->go((int)-1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(History_obj,back,(void))

Void History_obj::go( int delta){
{
		HX_STACK_PUSH("History::go","cocktail/core/history/History.hx",72);
		HX_STACK_THIS(this);
		HX_STACK_ARG(delta,"delta");
		HX_STACK_LINE(74)
		int newIndex = (this->currentIdx + delta);		HX_STACK_VAR(newIndex,"newIndex");
		HX_STACK_LINE(77)
		if (((bool((newIndex < (int)0)) || bool((newIndex >= this->stateDataArray->__Field(HX_CSTRING("length"),true)))))){
			HX_STACK_LINE(78)
			return null();
		}
		HX_STACK_LINE(81)
		this->currentIdx = newIndex;
		HX_STACK_LINE(82)
		this->state = this->cloneData(this->stateDataArray->__GetItem(this->currentIdx)->__Field(HX_CSTRING("state"),true));
		struct _Function_1_1{
			inline static Dynamic Block( ::cocktail::core::history::History_obj *__this){
				HX_STACK_PUSH("*::closure","cocktail/core/history/History.hx",85);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("state") , __this->state,false);
					__result->Add(HX_CSTRING("title") , __this->stateDataArray->__GetItem(__this->currentIdx)->__Field(HX_CSTRING("title"),true),false);
					__result->Add(HX_CSTRING("url") , __this->stateDataArray->__GetItem(__this->currentIdx)->__Field(HX_CSTRING("url"),true),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(85)
		this->onPopState(_Function_1_1::Block(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(History_obj,go,(void))

int History_obj::getLength( ){
	HX_STACK_PUSH("History::getLength","cocktail/core/history/History.hx",64);
	HX_STACK_THIS(this);
	HX_STACK_LINE(64)
	return this->stateDataArray->__Field(HX_CSTRING("length"),true);
}


HX_DEFINE_DYNAMIC_FUNC0(History_obj,getLength,return )


History_obj::History_obj()
{
}

void History_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(History);
	HX_MARK_MEMBER_NAME(currentIdx,"currentIdx");
	HX_MARK_MEMBER_NAME(stateDataArray,"stateDataArray");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void History_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(currentIdx,"currentIdx");
	HX_VISIT_MEMBER_NAME(stateDataArray,"stateDataArray");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic History_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"go") ) { return go_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"back") ) { return back_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? getLength() : length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"forward") ) { return forward_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"cloneData") ) { return cloneData_dyn(); }
		if (HX_FIELD_EQ(inName,"pushState") ) { return pushState_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"resolveUrl") ) { return resolveUrl_dyn(); }
		if (HX_FIELD_EQ(inName,"onPopState") ) { return onPopState_dyn(); }
		if (HX_FIELD_EQ(inName,"currentIdx") ) { return currentIdx; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"replaceState") ) { return replaceState_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"stateDataArray") ) { return stateDataArray; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"computeStateData") ) { return computeStateData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic History_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"currentIdx") ) { currentIdx=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"stateDataArray") ) { stateDataArray=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void History_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentIdx"));
	outFields->push(HX_CSTRING("stateDataArray"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("resolveUrl"),
	HX_CSTRING("computeStateData"),
	HX_CSTRING("cloneData"),
	HX_CSTRING("onPopState"),
	HX_CSTRING("replaceState"),
	HX_CSTRING("pushState"),
	HX_CSTRING("forward"),
	HX_CSTRING("back"),
	HX_CSTRING("go"),
	HX_CSTRING("getLength"),
	HX_CSTRING("currentIdx"),
	HX_CSTRING("stateDataArray"),
	HX_CSTRING("state"),
	HX_CSTRING("length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(History_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(History_obj::__mClass,"__mClass");
};

Class History_obj::__mClass;

void History_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.history.History"), hx::TCanCast< History_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void History_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace history
