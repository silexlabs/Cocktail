#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_resource_AbstractResource
#include <cocktail/core/resource/AbstractResource.h>
#endif
namespace cocktail{
namespace core{
namespace resource{

Void AbstractResource_obj::__construct(::String url)
{
HX_STACK_PUSH("AbstractResource::new","cocktail/core/resource/AbstractResource.hx",56);
{
	HX_STACK_LINE(57)
	super::__construct();
	HX_STACK_LINE(59)
	this->loaded = false;
	HX_STACK_LINE(60)
	this->loadedWithError = false;
	HX_STACK_LINE(61)
	this->load(url);
}
;
	return null();
}

AbstractResource_obj::~AbstractResource_obj() { }

Dynamic AbstractResource_obj::__CreateEmpty() { return  new AbstractResource_obj; }
hx::ObjectPtr< AbstractResource_obj > AbstractResource_obj::__new(::String url)
{  hx::ObjectPtr< AbstractResource_obj > result = new AbstractResource_obj();
	result->__construct(url);
	return result;}

Dynamic AbstractResource_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractResource_obj > result = new AbstractResource_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractResource_obj::onLoadError( ){
{
		HX_STACK_PUSH("AbstractResource::onLoadError","cocktail/core/resource/AbstractResource.hx",101);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		this->loadedWithError = true;
		HX_STACK_LINE(104)
		::cocktail::core::event::UIEvent errorEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(errorEvent,"errorEvent");
		HX_STACK_LINE(105)
		errorEvent->initUIEvent(HX_CSTRING("error"),false,false,null(),0.0);
		HX_STACK_LINE(106)
		this->dispatchEvent(errorEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractResource_obj,onLoadError,(void))

Void AbstractResource_obj::onLoadComplete( ){
{
		HX_STACK_PUSH("AbstractResource::onLoadComplete","cocktail/core/resource/AbstractResource.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_LINE(88)
		this->loaded = true;
		HX_STACK_LINE(90)
		::cocktail::core::event::UIEvent loadEvent = ::cocktail::core::event::UIEvent_obj::__new();		HX_STACK_VAR(loadEvent,"loadEvent");
		HX_STACK_LINE(91)
		loadEvent->initUIEvent(HX_CSTRING("load"),false,false,null(),0.0);
		HX_STACK_LINE(92)
		this->dispatchEvent(loadEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractResource_obj,onLoadComplete,(void))

Void AbstractResource_obj::load( ::String url){
{
		HX_STACK_PUSH("AbstractResource::load","cocktail/core/resource/AbstractResource.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractResource_obj,load,(void))


AbstractResource_obj::AbstractResource_obj()
{
}

void AbstractResource_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractResource);
	HX_MARK_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	HX_MARK_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_MARK_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_MARK_MEMBER_NAME(nativeResource,"nativeResource");
	HX_MARK_MEMBER_NAME(loadedWithError,"loadedWithError");
	HX_MARK_MEMBER_NAME(loaded,"loaded");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AbstractResource_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(intrinsicRatio,"intrinsicRatio");
	HX_VISIT_MEMBER_NAME(intrinsicHeight,"intrinsicHeight");
	HX_VISIT_MEMBER_NAME(intrinsicWidth,"intrinsicWidth");
	HX_VISIT_MEMBER_NAME(nativeResource,"nativeResource");
	HX_VISIT_MEMBER_NAME(loadedWithError,"loadedWithError");
	HX_VISIT_MEMBER_NAME(loaded,"loaded");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AbstractResource_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { return loaded; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onLoadError") ) { return onLoadError_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onLoadComplete") ) { return onLoadComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { return intrinsicRatio; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { return intrinsicWidth; }
		if (HX_FIELD_EQ(inName,"nativeResource") ) { return nativeResource; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { return intrinsicHeight; }
		if (HX_FIELD_EQ(inName,"loadedWithError") ) { return loadedWithError; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AbstractResource_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"loaded") ) { loaded=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"intrinsicRatio") ) { intrinsicRatio=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"intrinsicWidth") ) { intrinsicWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nativeResource") ) { nativeResource=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"intrinsicHeight") ) { intrinsicHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"loadedWithError") ) { loadedWithError=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AbstractResource_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("intrinsicRatio"));
	outFields->push(HX_CSTRING("intrinsicHeight"));
	outFields->push(HX_CSTRING("intrinsicWidth"));
	outFields->push(HX_CSTRING("nativeResource"));
	outFields->push(HX_CSTRING("loadedWithError"));
	outFields->push(HX_CSTRING("loaded"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onLoadError"),
	HX_CSTRING("onLoadComplete"),
	HX_CSTRING("load"),
	HX_CSTRING("intrinsicRatio"),
	HX_CSTRING("intrinsicHeight"),
	HX_CSTRING("intrinsicWidth"),
	HX_CSTRING("nativeResource"),
	HX_CSTRING("loadedWithError"),
	HX_CSTRING("loaded"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractResource_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AbstractResource_obj::__mClass,"__mClass");
};

Class AbstractResource_obj::__mClass;

void AbstractResource_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.resource.AbstractResource"), hx::TCanCast< AbstractResource_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AbstractResource_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace resource
