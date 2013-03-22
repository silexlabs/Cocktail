#include <hxcpp.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
#ifndef INCLUDED_neash_text_TextFormat
#include <neash/text/TextFormat.h>
#endif
#ifndef INCLUDED_nme_display_FPS
#include <nme/display/FPS.h>
#endif
namespace nme{
namespace display{

Void FPS_obj::__construct(hx::Null< Float >  __o_inX,hx::Null< Float >  __o_inY,hx::Null< int >  __o_inCol)
{
HX_STACK_PUSH("FPS::new","nme/display/FPS.hx",17);
Float inX = __o_inX.Default(10.0);
Float inY = __o_inY.Default(10.0);
int inCol = __o_inCol.Default(0);
{
	HX_STACK_LINE(18)
	super::__construct();
	HX_STACK_LINE(20)
	this->nmeSetX(inX);
	HX_STACK_LINE(21)
	this->nmeSetY(inY);
	HX_STACK_LINE(22)
	this->nmeSetSelectable(false);
	HX_STACK_LINE(24)
	this->nmeSetDefaultTextFormat(::neash::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,inCol,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(26)
	this->nmeSetText(HX_CSTRING("FPS: "));
	HX_STACK_LINE(28)
	this->times = Array_obj< Float >::__new();
	HX_STACK_LINE(29)
	this->addEventListener(::neash::events::Event_obj::ENTER_FRAME,this->onEnter_dyn(),null(),null(),null());
}
;
	return null();
}

FPS_obj::~FPS_obj() { }

Dynamic FPS_obj::__CreateEmpty() { return  new FPS_obj; }
hx::ObjectPtr< FPS_obj > FPS_obj::__new(hx::Null< Float >  __o_inX,hx::Null< Float >  __o_inY,hx::Null< int >  __o_inCol)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(__o_inX,__o_inY,__o_inCol);
	return result;}

Dynamic FPS_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FPS_obj::onEnter( Dynamic _){
{
		HX_STACK_PUSH("FPS::onEnter","nme/display/FPS.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(_,"_");
		HX_STACK_LINE(40)
		Float now = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(now,"now");
		HX_STACK_LINE(41)
		this->times->push(now);
		HX_STACK_LINE(43)
		while(((this->times->__get((int)0) < (now - (int)1)))){
			HX_STACK_LINE(44)
			this->times->shift();
		}
		HX_STACK_LINE(46)
		if ((this->nmeGetVisible())){
			HX_STACK_LINE(47)
			this->nmeSetText((HX_CSTRING("FPS: ") + this->times->length));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FPS_obj,onEnter,(void))


FPS_obj::FPS_obj()
{
}

void FPS_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPS);
	HX_MARK_MEMBER_NAME(times,"times");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FPS_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(times,"times");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FPS_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { return times; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onEnter") ) { return onEnter_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FPS_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { times=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FPS_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("times"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onEnter"),
	HX_CSTRING("times"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

Class FPS_obj::__mClass;

void FPS_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.FPS"), hx::TCanCast< FPS_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FPS_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
