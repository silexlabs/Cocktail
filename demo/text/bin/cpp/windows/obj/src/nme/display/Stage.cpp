#include <hxcpp.h>

#ifndef INCLUDED_IntHash
#include <IntHash.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageAlign
#include <nme/display/StageAlign.h>
#endif
#ifndef INCLUDED_nme_display_StageDisplayState
#include <nme/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_nme_display_StageQuality
#include <nme/display/StageQuality.h>
#endif
#ifndef INCLUDED_nme_display_StageScaleMode
#include <nme/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_TouchInfo
#include <nme/display/TouchInfo.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_FocusEvent
#include <nme/events/FocusEvent.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_JoystickEvent
#include <nme/events/JoystickEvent.h>
#endif
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_events_TouchEvent
#include <nme/events/TouchEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_media_SoundChannel
#include <nme/media/SoundChannel.h>
#endif
#ifndef INCLUDED_nme_net_URLLoader
#include <nme/net/URLLoader.h>
#endif
namespace nme{
namespace display{

Void Stage_obj::__construct(Dynamic inHandle,int inWidth,int inHeight)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",86)
	super::__construct(inHandle,HX_CSTRING("Stage"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",87)
	this->nmeMouseOverObjects = Array_obj< ::nme::display::InteractiveObject >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",88)
	this->nmeFocusOverObjects = Array_obj< ::nme::display::InteractiveObject >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",89)
	this->active = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",90)
	this->pauseWhenDeactivated = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",95)
	this->renderRequest = null();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",98)
	::nme::display::Stage_obj::nme_set_stage_handler(this->nmeHandle,this->nmeProcessStageEvent_dyn(),inWidth,inHeight);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",99)
	this->nmeInvalid = false;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",100)
	this->nmeLastRender = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",101)
	this->nmeLastDown = Array_obj< ::nme::display::InteractiveObject >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",102)
	this->nmeLastClickTime = 0.0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",103)
	this->nmeSetFrameRate((int)100);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",104)
	this->nmeTouchInfo = ::IntHash_obj::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",105)
	this->nmeJoyAxisData = ::IntHash_obj::__new();
}
;
	return null();
}

Stage_obj::~Stage_obj() { }

Dynamic Stage_obj::__CreateEmpty() { return  new Stage_obj; }
hx::ObjectPtr< Stage_obj > Stage_obj::__new(Dynamic inHandle,int inWidth,int inHeight)
{  hx::ObjectPtr< Stage_obj > result = new Stage_obj();
	result->__construct(inHandle,inWidth,inHeight);
	return result;}

Dynamic Stage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stage_obj > result = new Stage_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Stage_obj::invalidate( ){
{
		HX_SOURCE_PUSH("Stage_obj::invalidate")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",116)
		this->nmeInvalid = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,invalidate,(void))

Void Stage_obj::nmeCheckFocusInOuts( Dynamic inEvent,Array< ::nme::display::InteractiveObject > inStack){
{
		HX_SOURCE_PUSH("Stage_obj::nmeCheckFocusInOuts")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",124)
		int new_n = inStack->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",125)
		::nme::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::nme::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::nme::display::InteractiveObject(null()) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",126)
		int old_n = this->nmeFocusOverObjects->length;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",127)
		::nme::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::nme::display::InteractiveObject(this->nmeFocusOverObjects->__get((old_n - (int)1))) : ::nme::display::InteractiveObject(null()) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",129)
		if (((new_obj != old_obj))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",132)
			int common = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",133)
			while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == this->nmeFocusOverObjects->__get(common)))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",134)
				(common)++;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",136)
			::nme::events::FocusEvent focusOut = ::nme::events::FocusEvent_obj::__new(::nme::events::FocusEvent_obj::FOCUS_OUT,false,false,new_obj,(inEvent->__Field(HX_CSTRING("flags")) > (int)0),inEvent->__Field(HX_CSTRING("code")),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",138)
			int i = (old_n - (int)1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",139)
			while(((i >= common))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",141)
				this->nmeFocusOverObjects->__get(i)->nmeDispatchEvent(focusOut);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",142)
				(i)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",145)
			::nme::events::FocusEvent focusIn = ::nme::events::FocusEvent_obj::__new(::nme::events::FocusEvent_obj::FOCUS_IN,false,false,old_obj,(inEvent->__Field(HX_CSTRING("flags")) > (int)0),inEvent->__Field(HX_CSTRING("code")),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",146)
			int i1 = (new_n - (int)1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",148)
			while(((i1 >= common))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",150)
				inStack->__get(i1)->nmeDispatchEvent(focusIn);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",151)
				(i1)--;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",154)
			this->nmeFocusOverObjects = inStack;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeCheckFocusInOuts,(void))

bool Stage_obj::nmeCheckInOuts( ::nme::events::MouseEvent inEvent,Array< ::nme::display::InteractiveObject > inStack,::nme::display::TouchInfo touchInfo){
	HX_SOURCE_PUSH("Stage_obj::nmeCheckInOuts")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",161)
	Array< ::nme::display::InteractiveObject > prev = (  (((touchInfo == null()))) ? Array< ::nme::display::InteractiveObject >(this->nmeMouseOverObjects) : Array< ::nme::display::InteractiveObject >(touchInfo->touchOverObjects) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",162)
	Array< ::String > events = (  (((touchInfo == null()))) ? Array< ::String >(::nme::display::Stage_obj::nmeMouseChanges) : Array< ::String >(::nme::display::Stage_obj::nmeTouchChanges) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",164)
	int new_n = inStack->length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",165)
	::nme::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::nme::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::nme::display::InteractiveObject(null()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",166)
	int old_n = prev->length;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",167)
	::nme::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::nme::display::InteractiveObject(prev->__get((old_n - (int)1))) : ::nme::display::InteractiveObject(null()) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",169)
	if (((new_obj != old_obj))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",172)
		if (((old_obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",173)
			old_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)0),new_obj,old_obj));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",175)
		if (((new_obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",176)
			new_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)1),old_obj,null()));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",179)
		int common = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",180)
		while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == prev->__get(common)))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",181)
			(common)++;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",183)
		::nme::events::MouseEvent rollOut = inEvent->nmeCreateSimilar(events->__get((int)2),new_obj,old_obj);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",184)
		int i = (old_n - (int)1);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",185)
		while(((i >= common))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",187)
			prev->__get(i)->nmeDispatchEvent(rollOut);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",188)
			(i)--;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",191)
		::nme::events::MouseEvent rollOver = inEvent->nmeCreateSimilar(events->__get((int)3),old_obj,null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",192)
		int i1 = (new_n - (int)1);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",193)
		while(((i1 >= common))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",195)
			inStack->__get(i1)->nmeDispatchEvent(rollOver);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",196)
			(i1)--;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",199)
		if (((touchInfo == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",200)
			this->nmeMouseOverObjects = inStack;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",202)
			touchInfo->touchOverObjects = inStack;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",204)
		return false;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",207)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeCheckInOuts,return )

Void Stage_obj::nmeCheckRender( ){
{
		HX_SOURCE_PUSH("Stage_obj::nmeCheckRender")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",212)
		if (((this->frameRate > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",216)
			double now = ::haxe::Timer_obj::stamp();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",217)
			if (((now >= (this->nmeLastRender + this->nmeFramePeriod)))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",219)
				this->nmeLastRender = now;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",220)
				if (((this->renderRequest_dyn() != null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",221)
					this->renderRequest();
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",223)
					this->nmeRender(true);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeCheckRender,(void))

double Stage_obj::nmeDoProcessStageEvent( Dynamic inEvent){
	HX_SOURCE_PUSH("Stage_obj::nmeDoProcessStageEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",231)
	double result = 0.0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",233)
	int type = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("type")));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",235)
	switch( (int)(type)){
		case (int)2: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",237)
			if (((this->onKey_dyn() != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",239)
				this->onKey(inEvent->__Field(HX_CSTRING("code")),inEvent->__Field(HX_CSTRING("down")),inEvent->__Field(HX_CSTRING("char")),inEvent->__Field(HX_CSTRING("flags")));
			}
		}
		;break;
		case (int)1: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",241)
			this->nmeOnKey(inEvent,::nme::events::KeyboardEvent_obj::KEY_DOWN);
		}
		;break;
		case (int)3: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",244)
			this->nmeOnKey(inEvent,::nme::events::KeyboardEvent_obj::KEY_UP);
		}
		;break;
		case (int)4: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",247)
			this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::MOUSE_MOVE,true);
		}
		;break;
		case (int)5: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",250)
			this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::MOUSE_DOWN,true);
		}
		;break;
		case (int)6: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",253)
			this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::CLICK,true);
		}
		;break;
		case (int)7: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",256)
			this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::MOUSE_UP,true);
		}
		;break;
		case (int)8: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",260)
			this->nmeOnResize(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",261)
			if (((this->renderRequest_dyn() == null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",262)
				this->nmeRender(false);
			}
		}
		;break;
		case (int)9: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",264)
			this->nmePollTimers();
		}
		;break;
		case (int)10: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",267)
			if (((this->onQuit_dyn() != null()))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",269)
				this->onQuit();
			}
		}
		;break;
		case (int)11: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",271)
			this->nmeOnFocus(inEvent);
		}
		;break;
		case (int)12: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",274)
			if ((::nme::display::Stage_obj::shouldRotateInterface(inEvent->__Field(HX_CSTRING("value"))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",276)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)2;
			}
		}
		;break;
		case (int)14: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",278)
			this->nmeRender(true);
		}
		;break;
		case (int)15: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",282)
			::nme::display::TouchInfo touchInfo = ::nme::display::TouchInfo_obj::__new();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",283)
			this->nmeTouchInfo->set(inEvent->__Field(HX_CSTRING("value")),touchInfo);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",284)
			this->nmeOnTouch(inEvent,::nme::events::TouchEvent_obj::TOUCH_BEGIN,touchInfo);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",286)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"))) & int((int)32768))) > (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",287)
				this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::MOUSE_DOWN,false);
			}
		}
		;break;
		case (int)16: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",290)
			::nme::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",291)
			this->nmeOnTouch(inEvent,::nme::events::TouchEvent_obj::TOUCH_MOVE,touchInfo);
		}
		;break;
		case (int)17: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",294)
			::nme::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",295)
			this->nmeOnTouch(inEvent,::nme::events::TouchEvent_obj::TOUCH_END,touchInfo);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",296)
			this->nmeTouchInfo->remove(inEvent->__Field(HX_CSTRING("value")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",298)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"))) & int((int)32768))) > (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",299)
				this->nmeOnMouse(inEvent,::nme::events::MouseEvent_obj::MOUSE_UP,false);
			}
		}
		;break;
		case (int)18: {
		}
		;break;
		case (int)19: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",304)
			this->nmeOnChange(inEvent);
		}
		;break;
		case (int)20: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",307)
			this->nmeSetActive(true);
		}
		;break;
		case (int)21: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",310)
			this->nmeSetActive(false);
		}
		;break;
		case (int)22: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",314)
			::nme::events::Event evt = ::nme::events::Event_obj::__new(::nme::events::Event_obj::GOT_INPUT_FOCUS,null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",315)
			this->nmeBroadcast(evt);
		}
		;break;
		case (int)23: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",318)
			::nme::events::Event evt = ::nme::events::Event_obj::__new(::nme::events::Event_obj::LOST_INPUT_FOCUS,null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",319)
			this->nmeBroadcast(evt);
		}
		;break;
		case (int)24: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",321)
			this->nmeOnJoystick(inEvent,::nme::events::JoystickEvent_obj::AXIS_MOVE);
		}
		;break;
		case (int)25: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",324)
			this->nmeOnJoystick(inEvent,::nme::events::JoystickEvent_obj::BALL_MOVE);
		}
		;break;
		case (int)26: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",327)
			this->nmeOnJoystick(inEvent,::nme::events::JoystickEvent_obj::HAT_MOVE);
		}
		;break;
		case (int)27: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",330)
			this->nmeOnJoystick(inEvent,::nme::events::JoystickEvent_obj::BUTTON_DOWN);
		}
		;break;
		case (int)28: {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",333)
			this->nmeOnJoystick(inEvent,::nme::events::JoystickEvent_obj::BUTTON_UP);
		}
		;break;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",339)
	result = this->nmeUpdateNextWake();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",342)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDoProcessStageEvent,return )

Void Stage_obj::dummyTrace( ){
{
		HX_SOURCE_PUSH("Stage_obj::dummyTrace")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",345)
		::haxe::Log_obj::trace(HX_CSTRING(""),hx::SourceInfo(HX_CSTRING("Stage.hx"),345,HX_CSTRING("nme.display.Stage"),HX_CSTRING("dummyTrace")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,dummyTrace,(void))

Dynamic Stage_obj::nmeProcessStageEvent( Dynamic inEvent){
	HX_SOURCE_PUSH("Stage_obj::nmeProcessStageEvent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",353)
	this->nmeDoProcessStageEvent(inEvent);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",354)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeProcessStageEvent,return )

Void Stage_obj::nmeDrag( ::nme::geom::Point inMouse){
{
		HX_SOURCE_PUSH("Stage_obj::nmeDrag")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",360)
		::nme::display::DisplayObjectContainer p = this->nmeDragObject->nmeGetParent();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",361)
		if (((p != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",362)
			inMouse = p->globalToLocal(inMouse);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",364)
		double x = (inMouse->x + this->nmeDragOffsetX);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",365)
		double y = (inMouse->y + this->nmeDragOffsetY);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",367)
		if (((this->nmeDragBounds != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",369)
			if (((x < this->nmeDragBounds->x))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",369)
				x = this->nmeDragBounds->x;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",370)
				if (((x > this->nmeDragBounds->nmeGetRight()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",370)
					x = this->nmeDragBounds->nmeGetRight();
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",372)
			if (((y < this->nmeDragBounds->y))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",372)
				y = this->nmeDragBounds->y;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",373)
				if (((y > this->nmeDragBounds->nmeGetBottom()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",373)
					y = this->nmeDragBounds->nmeGetBottom();
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",376)
		this->nmeDragObject->nmeSetX(x);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",377)
		this->nmeDragObject->nmeSetY(y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDrag,(void))

::nme::display::Stage Stage_obj::nmeGetStage( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetStage")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",385)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStage,return )

double Stage_obj::nmeNextFrameDue( double inOtherTimers){
	HX_SOURCE_PUSH("Stage_obj::nmeNextFrameDue")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",392)
	if (((bool(!(this->active)) && bool(this->pauseWhenDeactivated)))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",393)
		return inOtherTimers;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",394)
	if (((this->frameRate > (int)0))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",396)
		double next = (((this->nmeLastRender + this->nmeFramePeriod) - ::haxe::Timer_obj::stamp()) - ::nme::display::Stage_obj::nmeEarlyWakeup);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",397)
		if (((next < inOtherTimers))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",398)
			return next;
		}
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",400)
	return inOtherTimers;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeNextFrameDue,return )

Void Stage_obj::nmeOnChange( Dynamic inEvent){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnChange")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",406)
		::nme::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",407)
		if (((obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",408)
			obj->nmeFireEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::CHANGE,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnChange,(void))

Void Stage_obj::nmeOnFocus( Dynamic inEvent){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnFocus")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",414)
		Array< ::nme::display::InteractiveObject > stack = Array_obj< ::nme::display::InteractiveObject >::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",415)
		::nme::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",416)
		if (((obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",417)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",418)
		if (((bool((stack->length > (int)0)) && bool(((bool((inEvent->__Field(HX_CSTRING("value")) == (int)1)) || bool((inEvent->__Field(HX_CSTRING("value")) == (int)2)))))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",420)
			::nme::display::InteractiveObject obj1 = stack->__get((int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",421)
			::nme::events::FocusEvent evt = ::nme::events::FocusEvent_obj::__new((  (((inEvent->__Field(HX_CSTRING("value")) == (int)1))) ? ::String(::nme::events::FocusEvent_obj::MOUSE_FOCUS_CHANGE) : ::String(::nme::events::FocusEvent_obj::KEY_FOCUS_CHANGE) ),true,true,(  (((this->nmeFocusOverObjects->length == (int)0))) ? ::nme::display::InteractiveObject(null()) : ::nme::display::InteractiveObject(this->nmeFocusOverObjects->__get((int)0)) ),(inEvent->__Field(HX_CSTRING("flags")) > (int)0),inEvent->__Field(HX_CSTRING("code")),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",422)
			obj1->nmeFireEvent(evt);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",423)
			if ((evt->nmeGetIsCancelled())){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",425)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",426)
				return null();
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",430)
		stack->reverse();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",432)
		this->nmeCheckFocusInOuts(inEvent,stack);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnFocus,(void))

Void Stage_obj::nmeOnJoystick( Dynamic inEvent,::String inType){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnJoystick")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",438)
		::nme::events::JoystickEvent evt = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",439)
		::String _switch_1 = (inType);
		if (  ( _switch_1==::nme::events::JoystickEvent_obj::AXIS_MOVE)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",442)
			Dynamic data = this->nmeJoyAxisData->get(inEvent->__Field(HX_CSTRING("id")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",443)
			if (((data == null()))){
				struct _Function_3_1{
					inline static Dynamic Block( ){
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("x") , 0.0,false);
						__result->Add(HX_CSTRING("y") , 0.0,false);
						__result->Add(HX_CSTRING("z") , 0.0,false);
						return __result;
					}
				};
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",444)
				data = _Function_3_1::Block();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",448)
			double value = (double(inEvent->__Field(HX_CSTRING("value"))) / double((int)32767));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",449)
			if (((value < (int)-1))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",449)
				value = (int)-1;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",451)
			switch( (int)(inEvent->__Field(HX_CSTRING("code")))){
				case (int)0: {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",453)
					data->__FieldRef(HX_CSTRING("x")) = value;
				}
				;break;
				case (int)1: {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",454)
					data->__FieldRef(HX_CSTRING("y")) = value;
				}
				;break;
				case (int)2: {
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",455)
					data->__FieldRef(HX_CSTRING("z")) = value;
				}
				;break;
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",458)
			evt = ::nme::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id")),(int)0,data->__Field(HX_CSTRING("x")),data->__Field(HX_CSTRING("y")),data->__Field(HX_CSTRING("z")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",460)
			this->nmeJoyAxisData->set(inEvent->__Field(HX_CSTRING("id")),data);
		}
		else if (  ( _switch_1==::nme::events::JoystickEvent_obj::BALL_MOVE)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",462)
			evt = ::nme::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id")),inEvent->__Field(HX_CSTRING("code")),inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y")),null());
		}
		else if (  ( _switch_1==::nme::events::JoystickEvent_obj::HAT_MOVE)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",466)
			int x = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",467)
			int y = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",469)
			if (((((int(inEvent->__Field(HX_CSTRING("value"))) & int((int)1))) != (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",470)
				y = (int)-1;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",473)
				if (((((int(inEvent->__Field(HX_CSTRING("value"))) & int((int)4))) != (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",474)
					y = (int)1;
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",478)
			if (((((int(inEvent->__Field(HX_CSTRING("value"))) & int((int)2))) != (int)0))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",479)
				x = (int)1;
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",482)
				if (((((int(inEvent->__Field(HX_CSTRING("value"))) & int((int)8))) != (int)0))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",483)
					x = (int)-1;
				}
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",487)
			evt = ::nme::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id")),inEvent->__Field(HX_CSTRING("code")),x,y,null());
		}
		else  {
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",489)
			evt = ::nme::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id")),inEvent->__Field(HX_CSTRING("code")),null(),null(),null());
		}
;
;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",492)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnJoystick,(void))

Void Stage_obj::nmeOnKey( Dynamic inEvent,::String inType){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnKey")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",498)
		Array< ::nme::display::InteractiveObject > stack = Array_obj< ::nme::display::InteractiveObject >::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",499)
		::nme::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",500)
		if (((obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",501)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",502)
		if (((stack->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",504)
			::nme::display::InteractiveObject obj1 = stack->__get((int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",505)
			int flags = inEvent->__Field(HX_CSTRING("flags"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",506)
			::nme::events::KeyboardEvent evt = ::nme::events::KeyboardEvent_obj::__new(inType,true,true,inEvent->__Field(HX_CSTRING("code")),inEvent->__Field(HX_CSTRING("value")),(  (((((int(flags) & int(::nme::display::Stage_obj::efLocationRight))) == (int)0))) ? int((int)1) : int((int)0) ),(((int(flags) & int(::nme::display::Stage_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::nme::display::Stage_obj::efAltDown))) != (int)0),(((int(flags) & int(::nme::display::Stage_obj::efShiftDown))) != (int)0),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",507)
			obj1->nmeFireEvent(evt);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",508)
			if ((evt->nmeGetIsCancelled())){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",509)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnKey,(void))

Void Stage_obj::nmeOnMouse( Dynamic inEvent,::String inType,bool inFromMouse){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnMouse")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",516)
		::String type = inType;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",517)
		int button = inEvent->__Field(HX_CSTRING("value"));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",518)
		if ((!(inFromMouse))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",519)
			button = (int)0;
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",520)
		int wheel = (int)0;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",521)
		if (((inType == ::nme::events::MouseEvent_obj::MOUSE_DOWN))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",523)
			if (((button > (int)2))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",524)
				return null();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",525)
			type = ::nme::display::Stage_obj::sDownEvents->__get(button);
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",527)
			if (((inType == ::nme::events::MouseEvent_obj::MOUSE_UP))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",528)
				if (((button > (int)2))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",531)
					type = ::nme::events::MouseEvent_obj::MOUSE_WHEEL;
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",532)
					wheel = (  (((button == (int)3))) ? int((int)1) : int((int)-1) );
				}
				else{
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",536)
					type = ::nme::display::Stage_obj::sUpEvents->__get(button);
				}
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",539)
		if (((this->nmeDragObject != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",540)
			this->nmeDrag(::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y"))));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",542)
		Array< ::nme::display::InteractiveObject > stack = Array_obj< ::nme::display::InteractiveObject >::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",543)
		::nme::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",544)
		if (((obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",545)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",547)
		::nme::geom::Point local = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",548)
		if (((stack->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",550)
			::nme::display::InteractiveObject obj1 = stack->__get((int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",551)
			stack->reverse();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",552)
			local = obj1->globalToLocal(::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y"))));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",553)
			::nme::events::MouseEvent evt = ::nme::events::MouseEvent_obj::nmeCreate(type,inEvent,local,obj1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",554)
			evt->delta = wheel;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",555)
			if ((inFromMouse)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",556)
				this->nmeCheckInOuts(evt,stack,null());
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",557)
			obj1->nmeFireEvent(evt);
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",562)
			local = ::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y")));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",563)
			::nme::events::MouseEvent evt = ::nme::events::MouseEvent_obj::nmeCreate(type,inEvent,local,null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",564)
			evt->delta = wheel;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",565)
			if ((inFromMouse)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",566)
				this->nmeCheckInOuts(evt,stack,null());
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",569)
		::nme::display::InteractiveObject click_obj = (  (((stack->length > (int)0))) ? ::nme::display::InteractiveObject(stack->__get((stack->length - (int)1))) : ::nme::display::InteractiveObject(hx::ObjectPtr<OBJ_>(this)) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",570)
		if (((bool((inType == ::nme::events::MouseEvent_obj::MOUSE_DOWN)) && bool((button < (int)3))))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",571)
			this->nmeLastDown[button] = click_obj;
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",574)
			if (((bool((inType == ::nme::events::MouseEvent_obj::MOUSE_UP)) && bool((button < (int)3))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",576)
				if (((click_obj == this->nmeLastDown->__get(button)))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",578)
					::nme::events::MouseEvent evt = ::nme::events::MouseEvent_obj::nmeCreate(::nme::display::Stage_obj::sClickEvents->__get(button),inEvent,local,click_obj);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",579)
					click_obj->nmeFireEvent(evt);
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",581)
					if (((bool((button == (int)0)) && bool(click_obj->doubleClickEnabled)))){
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",583)
						double now = ::haxe::Timer_obj::stamp();
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",584)
						if ((((now - this->nmeLastClickTime) < 0.25))){
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",586)
							::nme::events::MouseEvent evt1 = ::nme::events::MouseEvent_obj::nmeCreate(::nme::events::MouseEvent_obj::DOUBLE_CLICK,inEvent,local,click_obj);
							HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",587)
							click_obj->nmeFireEvent(evt1);
						}
						HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",589)
						this->nmeLastClickTime = now;
					}
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",592)
				this->nmeLastDown[button] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnMouse,(void))

Void Stage_obj::nmeOnResize( double inW,double inH){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnResize")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",599)
		::nme::events::Event evt = ::nme::events::Event_obj::__new(::nme::events::Event_obj::RESIZE,null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",600)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnResize,(void))

Void Stage_obj::nmeOnTouch( Dynamic inEvent,::String inType,::nme::display::TouchInfo touchInfo){
{
		HX_SOURCE_PUSH("Stage_obj::nmeOnTouch")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",606)
		Array< ::nme::display::InteractiveObject > stack = Array_obj< ::nme::display::InteractiveObject >::__new();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",607)
		::nme::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id")));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",608)
		if (((obj != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",609)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",611)
		if (((stack->length > (int)0))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",613)
			::nme::display::InteractiveObject obj1 = stack->__get((int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",614)
			stack->reverse();
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",615)
			::nme::geom::Point local = obj1->globalToLocal(::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y"))));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",616)
			::nme::events::TouchEvent evt = ::nme::events::TouchEvent_obj::nmeCreate(inType,inEvent,local,obj1);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",617)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",618)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"))) & int((int)32768))) > (int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",620)
			this->nmeCheckInOuts(evt,stack,touchInfo);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",621)
			obj1->nmeFireEvent(evt);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",622)
			if (((bool(evt->isPrimaryTouchPoint) && bool((inType == ::nme::events::TouchEvent_obj::TOUCH_MOVE))))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",624)
				if (((this->nmeDragObject != null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",625)
					this->nmeDrag(::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y"))));
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",627)
				::nme::events::MouseEvent evt1 = ::nme::events::MouseEvent_obj::nmeCreate(::nme::events::MouseEvent_obj::MOUSE_MOVE,inEvent,local,obj1);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",628)
				obj1->nmeFireEvent(evt1);
			}
		}
		else{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",634)
			::nme::events::TouchEvent evt = ::nme::events::TouchEvent_obj::nmeCreate(inType,inEvent,::nme::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x")),inEvent->__Field(HX_CSTRING("y"))),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",635)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"));
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",636)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"))) & int((int)32768))) > (int)0);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",638)
			this->nmeCheckInOuts(evt,stack,touchInfo);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnTouch,(void))

Void Stage_obj::nmePollTimers( ){
{
		HX_SOURCE_PUSH("Stage_obj::nmePollTimers")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",649)
		::haxe::Timer_obj::nmeCheckTimers();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",650)
		::nme::media::SoundChannel_obj::nmePollComplete();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",651)
		::nme::net::URLLoader_obj::nmePollData();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",652)
		this->nmeCheckRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmePollTimers,(void))

Void Stage_obj::nmeRender( bool inSendEnterFrame){
{
		HX_SOURCE_PUSH("Stage_obj::nmeRender")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",661)
		if ((!(this->active))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",662)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",665)
		if ((inSendEnterFrame)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",666)
			this->nmeBroadcast(::nme::events::Event_obj::__new(::nme::events::Event_obj::ENTER_FRAME,null(),null()));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",669)
		if ((this->nmeInvalid)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",671)
			this->nmeInvalid = false;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",672)
			this->nmeBroadcast(::nme::events::Event_obj::__new(::nme::events::Event_obj::RENDER,null(),null()));
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",674)
		::nme::display::Stage_obj::nme_render_stage(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeRender,(void))

Void Stage_obj::nmeSetActive( bool inActive){
{
		HX_SOURCE_PUSH("Stage_obj::nmeSetActive")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",682)
		if (((inActive != this->active))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",686)
			this->active = inActive;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",687)
			if ((!(this->active))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",688)
				this->nmeLastRender = ::haxe::Timer_obj::stamp();
			}
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",690)
			::nme::events::Event evt = ::nme::events::Event_obj::__new((  ((inActive)) ? ::String(::nme::events::Event_obj::ACTIVATE) : ::String(::nme::events::Event_obj::DEACTIVATE) ),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",691)
			this->nmeBroadcast(evt);
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",692)
			if ((inActive)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",693)
				this->nmePollTimers();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetActive,(void))

Void Stage_obj::nmeStartDrag( ::nme::display::Sprite sprite,bool lockCenter,::nme::geom::Rectangle bounds){
{
		HX_SOURCE_PUSH("Stage_obj::nmeStartDrag")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",703)
		this->nmeDragBounds = (  (((bounds == null()))) ? ::nme::geom::Rectangle(null()) : ::nme::geom::Rectangle(bounds->clone()) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",704)
		this->nmeDragObject = sprite;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",706)
		if (((this->nmeDragObject != null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",707)
			if ((lockCenter)){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",710)
				this->nmeDragOffsetX = (double(-(this->nmeDragObject->nmeGetWidth())) / double((int)2));
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",711)
				this->nmeDragOffsetY = (double(-(this->nmeDragObject->nmeGetHeight())) / double((int)2));
			}
			else{
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",715)
				::nme::geom::Point mouse = ::nme::geom::Point_obj::__new(this->nmeGetMouseX(),this->nmeGetMouseY());
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",716)
				::nme::display::DisplayObjectContainer p = this->nmeDragObject->nmeGetParent();
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",717)
				if (((p != null()))){
					HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",718)
					mouse = p->globalToLocal(mouse);
				}
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",720)
				this->nmeDragOffsetX = (this->nmeDragObject->nmeGetX() - mouse->x);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",721)
				this->nmeDragOffsetY = (this->nmeDragObject->nmeGetY() - mouse->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeStartDrag,(void))

Void Stage_obj::nmeStopDrag( ::nme::display::Sprite sprite){
{
		HX_SOURCE_PUSH("Stage_obj::nmeStopDrag")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",732)
		this->nmeDragBounds = null();
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",733)
		this->nmeDragObject = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeStopDrag,(void))

double Stage_obj::nmeUpdateNextWake( ){
	HX_SOURCE_PUSH("Stage_obj::nmeUpdateNextWake")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",743)
	double next_wake = ::haxe::Timer_obj::nmeNextWake(315000000.0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",744)
	if (((bool((next_wake > 0.02)) && bool(((bool(::nme::media::SoundChannel_obj::nmeCompletePending()) || bool(::nme::net::URLLoader_obj::nmeLoadPending()))))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",745)
		next_wake = (  (((bool(this->active) || bool(!(this->pauseWhenDeactivated))))) ? double(0.020) : double(0.500) );
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",748)
	next_wake = this->nmeNextFrameDue(next_wake);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",749)
	::nme::display::Stage_obj::nme_stage_set_next_wake(this->nmeHandle,next_wake);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",750)
	return next_wake;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeUpdateNextWake,return )

Void Stage_obj::showCursor( bool inShow){
{
		HX_SOURCE_PUSH("Stage_obj::showCursor")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",768)
		::nme::display::Stage_obj::nme_stage_show_cursor(this->nmeHandle,inShow);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,showCursor,(void))

::nme::display::StageAlign Stage_obj::nmeGetAlign( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetAlign")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",780)
	int i = ::nme::display::Stage_obj::nme_stage_get_align(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",781)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::nme::display::StageAlign >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetAlign,return )

::nme::display::StageAlign Stage_obj::nmeSetAlign( ::nme::display::StageAlign inMode){
	HX_SOURCE_PUSH("Stage_obj::nmeSetAlign")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",787)
	::nme::display::Stage_obj::nme_stage_set_align(this->nmeHandle,inMode->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",788)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetAlign,return )

::nme::display::StageDisplayState Stage_obj::nmeGetDisplayState( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetDisplayState")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",794)
	int i = ::nme::display::Stage_obj::nme_stage_get_display_state(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",795)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::nme::display::StageDisplayState >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetDisplayState,return )

::nme::display::StageDisplayState Stage_obj::nmeSetDisplayState( ::nme::display::StageDisplayState inState){
	HX_SOURCE_PUSH("Stage_obj::nmeSetDisplayState")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",801)
	::nme::display::Stage_obj::nme_stage_set_display_state(this->nmeHandle,inState->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",802)
	return inState;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetDisplayState,return )

double Stage_obj::nmeGetDPIScale( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetDPIScale")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",807)
	return ::nme::display::Stage_obj::nme_stage_get_dpi_scale(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetDPIScale,return )

::nme::display::InteractiveObject Stage_obj::nmeGetFocus( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetFocus")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",814)
	int id = ::nme::display::Stage_obj::nme_stage_get_focus_id(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",815)
	::nme::display::DisplayObject obj = this->nmeFindByID(id);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",816)
	return obj;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetFocus,return )

::nme::display::InteractiveObject Stage_obj::nmeSetFocus( ::nme::display::InteractiveObject inObject){
	HX_SOURCE_PUSH("Stage_obj::nmeSetFocus")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",822)
	if (((inObject == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",823)
		::nme::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,null(),(int)0);
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",825)
		::nme::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,inObject->nmeHandle,(int)0);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",826)
	return inObject;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetFocus,return )

double Stage_obj::nmeSetFrameRate( double inRate){
	HX_SOURCE_PUSH("Stage_obj::nmeSetFrameRate")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",832)
	this->frameRate = inRate;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",833)
	this->nmeFramePeriod = (  (((this->frameRate <= (int)0))) ? double(this->frameRate) : double((double(1.0) / double(this->frameRate))) );
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",834)
	return inRate;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetFrameRate,return )

bool Stage_obj::nmeIsOpenGL( ){
	HX_SOURCE_PUSH("Stage_obj::nmeIsOpenGL")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",839)
	return ::nme::display::Stage_obj::nme_stage_is_opengl(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeIsOpenGL,return )

::nme::display::StageQuality Stage_obj::nmeGetQuality( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetQuality")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",846)
	int i = ::nme::display::Stage_obj::nme_stage_get_quality(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",847)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::nme::display::StageQuality >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetQuality,return )

::nme::display::StageQuality Stage_obj::nmeSetQuality( ::nme::display::StageQuality inQuality){
	HX_SOURCE_PUSH("Stage_obj::nmeSetQuality")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",853)
	::nme::display::Stage_obj::nme_stage_set_quality(this->nmeHandle,inQuality->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",854)
	return inQuality;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetQuality,return )

::nme::display::StageScaleMode Stage_obj::nmeGetScaleMode( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetScaleMode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",860)
	int i = ::nme::display::Stage_obj::nme_stage_get_scale_mode(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",861)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::nme::display::StageScaleMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetScaleMode,return )

::nme::display::StageScaleMode Stage_obj::nmeSetScaleMode( ::nme::display::StageScaleMode inMode){
	HX_SOURCE_PUSH("Stage_obj::nmeSetScaleMode")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",867)
	::nme::display::Stage_obj::nme_stage_set_scale_mode(this->nmeHandle,inMode->__Index());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",868)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetScaleMode,return )

bool Stage_obj::nmeGetStageFocusRect( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetStageFocusRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",872)
	return ::nme::display::Stage_obj::nme_stage_get_focus_rect(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageFocusRect,return )

bool Stage_obj::nmeSetStageFocusRect( bool inVal){
	HX_SOURCE_PUSH("Stage_obj::nmeSetStageFocusRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",875)
	::nme::display::Stage_obj::nme_stage_set_focus_rect(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",876)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetStageFocusRect,return )

int Stage_obj::nmeGetStageHeight( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetStageHeight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",881)
	return ::nme::display::Stage_obj::nme_stage_get_stage_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageHeight,return )

int Stage_obj::nmeGetStageWidth( ){
	HX_SOURCE_PUSH("Stage_obj::nmeGetStageWidth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",887)
	return ::nme::display::Stage_obj::nme_stage_get_stage_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageWidth,return )

double Stage_obj::nmeEarlyWakeup;

int Stage_obj::OrientationPortrait;

int Stage_obj::OrientationPortraitUpsideDown;

int Stage_obj::OrientationLandscapeRight;

int Stage_obj::OrientationLandscapeLeft;

int Stage_obj::OrientationFaceUp;

int Stage_obj::OrientationFaceDown;

int Stage_obj::efLeftDown;

int Stage_obj::efShiftDown;

int Stage_obj::efCtrlDown;

int Stage_obj::efAltDown;

int Stage_obj::efCommandDown;

int Stage_obj::efLocationRight;

int Stage_obj::efNoNativeClick;

Array< ::String > Stage_obj::nmeMouseChanges;

Array< ::String > Stage_obj::nmeTouchChanges;

Array< ::String > Stage_obj::sClickEvents;

Array< ::String > Stage_obj::sDownEvents;

Array< ::String > Stage_obj::sUpEvents;

HX_BEGIN_DEFAULT_FUNC(__default_getOrientation,Stage_obj)
int run(){
	HX_SOURCE_PUSH("Stage_obj::getOrientation")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",110)
	return ::nme::display::Stage_obj::nme_stage_get_orientation();
}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::getOrientation;

Void Stage_obj::setFixedOrientation( int inOrientation){
{
		HX_SOURCE_PUSH("Stage_obj::setFixedOrientation")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",755)
		::nme::display::Stage_obj::nme_stage_set_fixed_orientation(inOrientation);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,setFixedOrientation,(void))

HX_BEGIN_DEFAULT_FUNC(__default_shouldRotateInterface,Stage_obj)
bool run(int inOrientation){
	HX_SOURCE_PUSH("Stage_obj::shouldRotateInterface")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Stage.hx",762)
	return (inOrientation == ::nme::display::Stage_obj::OrientationPortrait);
}
HX_END_LOCAL_FUNC1(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::shouldRotateInterface;

Dynamic Stage_obj::nme_set_stage_handler;

Dynamic Stage_obj::nme_render_stage;

Dynamic Stage_obj::nme_stage_get_focus_id;

Dynamic Stage_obj::nme_stage_set_focus;

Dynamic Stage_obj::nme_stage_get_focus_rect;

Dynamic Stage_obj::nme_stage_set_focus_rect;

Dynamic Stage_obj::nme_stage_is_opengl;

Dynamic Stage_obj::nme_stage_get_stage_width;

Dynamic Stage_obj::nme_stage_get_stage_height;

Dynamic Stage_obj::nme_stage_get_dpi_scale;

Dynamic Stage_obj::nme_stage_get_scale_mode;

Dynamic Stage_obj::nme_stage_set_scale_mode;

Dynamic Stage_obj::nme_stage_get_align;

Dynamic Stage_obj::nme_stage_set_align;

Dynamic Stage_obj::nme_stage_get_quality;

Dynamic Stage_obj::nme_stage_set_quality;

Dynamic Stage_obj::nme_stage_get_display_state;

Dynamic Stage_obj::nme_stage_set_display_state;

Dynamic Stage_obj::nme_stage_set_next_wake;

Dynamic Stage_obj::nme_stage_request_render;

Dynamic Stage_obj::nme_stage_show_cursor;

Dynamic Stage_obj::nme_stage_set_fixed_orientation;

Dynamic Stage_obj::nme_stage_get_orientation;


Stage_obj::Stage_obj()
{
}

void Stage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stage);
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_MEMBER_NAME(displayState,"displayState");
	HX_MARK_MEMBER_NAME(dpiScale,"dpiScale");
	HX_MARK_MEMBER_NAME(focus,"focus");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(isOpenGL,"isOpenGL");
	HX_MARK_MEMBER_NAME(onKey,"onKey");
	HX_MARK_MEMBER_NAME(onQuit,"onQuit");
	HX_MARK_MEMBER_NAME(pauseWhenDeactivated,"pauseWhenDeactivated");
	HX_MARK_MEMBER_NAME(quality,"quality");
	HX_MARK_MEMBER_NAME(renderRequest,"renderRequest");
	HX_MARK_MEMBER_NAME(scaleMode,"scaleMode");
	HX_MARK_MEMBER_NAME(stageFocusRect,"stageFocusRect");
	HX_MARK_MEMBER_NAME(stageHeight,"stageHeight");
	HX_MARK_MEMBER_NAME(stageWidth,"stageWidth");
	HX_MARK_MEMBER_NAME(nmeJoyAxisData,"nmeJoyAxisData");
	HX_MARK_MEMBER_NAME(nmeDragBounds,"nmeDragBounds");
	HX_MARK_MEMBER_NAME(nmeDragObject,"nmeDragObject");
	HX_MARK_MEMBER_NAME(nmeDragOffsetX,"nmeDragOffsetX");
	HX_MARK_MEMBER_NAME(nmeDragOffsetY,"nmeDragOffsetY");
	HX_MARK_MEMBER_NAME(nmeFocusOverObjects,"nmeFocusOverObjects");
	HX_MARK_MEMBER_NAME(nmeFramePeriod,"nmeFramePeriod");
	HX_MARK_MEMBER_NAME(nmeInvalid,"nmeInvalid");
	HX_MARK_MEMBER_NAME(nmeLastClickTime,"nmeLastClickTime");
	HX_MARK_MEMBER_NAME(nmeLastDown,"nmeLastDown");
	HX_MARK_MEMBER_NAME(nmeLastRender,"nmeLastRender");
	HX_MARK_MEMBER_NAME(nmeMouseOverObjects,"nmeMouseOverObjects");
	HX_MARK_MEMBER_NAME(nmeTouchInfo,"nmeTouchInfo");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Stage_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return nmeGetAlign(); }
		if (HX_FIELD_EQ(inName,"focus") ) { return nmeGetFocus(); }
		if (HX_FIELD_EQ(inName,"onKey") ) { return onKey; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"onQuit") ) { return onQuit; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { return nmeGetQuality(); }
		if (HX_FIELD_EQ(inName,"nmeDrag") ) { return nmeDrag_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dpiScale") ) { return nmeGetDPIScale(); }
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { return nmeIsOpenGL(); }
		if (HX_FIELD_EQ(inName,"nmeOnKey") ) { return nmeOnKey_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { return sUpEvents; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { return nmeGetScaleMode(); }
		if (HX_FIELD_EQ(inName,"nmeRender") ) { return nmeRender_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { return efLeftDown; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { return efCtrlDown; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return nmeGetStageWidth(); }
		if (HX_FIELD_EQ(inName,"nmeInvalid") ) { return nmeInvalid; }
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"dummyTrace") ) { return dummyTrace_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnFocus") ) { return nmeOnFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnMouse") ) { return nmeOnMouse_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnTouch") ) { return nmeOnTouch_dyn(); }
		if (HX_FIELD_EQ(inName,"showCursor") ) { return showCursor_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"sDownEvents") ) { return sDownEvents; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return nmeGetStageHeight(); }
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { return nmeLastDown; }
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnChange") ) { return nmeOnChange_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnResize") ) { return nmeOnResize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeStopDrag") ) { return nmeStopDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetAlign") ) { return nmeGetAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAlign") ) { return nmeSetAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetFocus") ) { return nmeGetFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFocus") ) { return nmeSetFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeIsOpenGL") ) { return nmeIsOpenGL_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { return sClickEvents; }
		if (HX_FIELD_EQ(inName,"displayState") ) { return nmeGetDisplayState(); }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { return nmeTouchInfo; }
		if (HX_FIELD_EQ(inName,"nmeSetActive") ) { return nmeSetActive_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeStartDrag") ) { return nmeStartDrag_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		if (HX_FIELD_EQ(inName,"renderRequest") ) { return renderRequest; }
		if (HX_FIELD_EQ(inName,"nmeDragBounds") ) { return nmeDragBounds; }
		if (HX_FIELD_EQ(inName,"nmeDragObject") ) { return nmeDragObject; }
		if (HX_FIELD_EQ(inName,"nmeLastRender") ) { return nmeLastRender; }
		if (HX_FIELD_EQ(inName,"nmeOnJoystick") ) { return nmeOnJoystick_dyn(); }
		if (HX_FIELD_EQ(inName,"nmePollTimers") ) { return nmePollTimers_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetQuality") ) { return nmeGetQuality_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetQuality") ) { return nmeSetQuality_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeEarlyWakeup") ) { return nmeEarlyWakeup; }
		if (HX_FIELD_EQ(inName,"getOrientation") ) { return getOrientation; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { return nmeGetStageFocusRect(); }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { return nmeJoyAxisData; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { return nmeDragOffsetX; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { return nmeDragOffsetY; }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { return nmeFramePeriod; }
		if (HX_FIELD_EQ(inName,"nmeCheckInOuts") ) { return nmeCheckInOuts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeCheckRender") ) { return nmeCheckRender_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetDPIScale") ) { return nmeGetDPIScale_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { return efLocationRight; }
		if (HX_FIELD_EQ(inName,"efNoNativeClick") ) { return efNoNativeClick; }
		if (HX_FIELD_EQ(inName,"nmeMouseChanges") ) { return nmeMouseChanges; }
		if (HX_FIELD_EQ(inName,"nmeTouchChanges") ) { return nmeTouchChanges; }
		if (HX_FIELD_EQ(inName,"nmeNextFrameDue") ) { return nmeNextFrameDue_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFrameRate") ) { return nmeSetFrameRate_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleMode") ) { return nmeGetScaleMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetScaleMode") ) { return nmeSetScaleMode_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_render_stage") ) { return nme_render_stage; }
		if (HX_FIELD_EQ(inName,"nmeLastClickTime") ) { return nmeLastClickTime; }
		if (HX_FIELD_EQ(inName,"nmeGetStageWidth") ) { return nmeGetStageWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OrientationFaceUp") ) { return OrientationFaceUp; }
		if (HX_FIELD_EQ(inName,"nmeUpdateNextWake") ) { return nmeUpdateNextWake_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStageHeight") ) { return nmeGetStageHeight_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nmeGetDisplayState") ) { return nmeGetDisplayState_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetDisplayState") ) { return nmeSetDisplayState_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"OrientationPortrait") ) { return OrientationPortrait; }
		if (HX_FIELD_EQ(inName,"OrientationFaceDown") ) { return OrientationFaceDown; }
		if (HX_FIELD_EQ(inName,"setFixedOrientation") ) { return setFixedOrientation_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_stage_set_focus") ) { return nme_stage_set_focus; }
		if (HX_FIELD_EQ(inName,"nme_stage_is_opengl") ) { return nme_stage_is_opengl; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_align") ) { return nme_stage_get_align; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_align") ) { return nme_stage_set_align; }
		if (HX_FIELD_EQ(inName,"nmeFocusOverObjects") ) { return nmeFocusOverObjects; }
		if (HX_FIELD_EQ(inName,"nmeMouseOverObjects") ) { return nmeMouseOverObjects; }
		if (HX_FIELD_EQ(inName,"nmeCheckFocusInOuts") ) { return nmeCheckFocusInOuts_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"pauseWhenDeactivated") ) { return pauseWhenDeactivated; }
		if (HX_FIELD_EQ(inName,"nmeProcessStageEvent") ) { return nmeProcessStageEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStageFocusRect") ) { return nmeGetStageFocusRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetStageFocusRect") ) { return nmeSetStageFocusRect_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"shouldRotateInterface") ) { return shouldRotateInterface; }
		if (HX_FIELD_EQ(inName,"nme_set_stage_handler") ) { return nme_set_stage_handler; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_quality") ) { return nme_stage_get_quality; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_quality") ) { return nme_stage_set_quality; }
		if (HX_FIELD_EQ(inName,"nme_stage_show_cursor") ) { return nme_stage_show_cursor; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_stage_get_focus_id") ) { return nme_stage_get_focus_id; }
		if (HX_FIELD_EQ(inName,"nmeDoProcessStageEvent") ) { return nmeDoProcessStageEvent_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_stage_get_dpi_scale") ) { return nme_stage_get_dpi_scale; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_next_wake") ) { return nme_stage_set_next_wake; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"OrientationLandscapeLeft") ) { return OrientationLandscapeLeft; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_focus_rect") ) { return nme_stage_get_focus_rect; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_focus_rect") ) { return nme_stage_set_focus_rect; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_scale_mode") ) { return nme_stage_get_scale_mode; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_scale_mode") ) { return nme_stage_set_scale_mode; }
		if (HX_FIELD_EQ(inName,"nme_stage_request_render") ) { return nme_stage_request_render; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"OrientationLandscapeRight") ) { return OrientationLandscapeRight; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_stage_width") ) { return nme_stage_get_stage_width; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_orientation") ) { return nme_stage_get_orientation; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_stage_get_stage_height") ) { return nme_stage_get_stage_height; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_stage_get_display_state") ) { return nme_stage_get_display_state; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_display_state") ) { return nme_stage_set_display_state; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"OrientationPortraitUpsideDown") ) { return OrientationPortraitUpsideDown; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_set_fixed_orientation") ) { return nme_stage_set_fixed_orientation; }
	}
	return super::__Field(inName);
}

Dynamic Stage_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return nmeSetAlign(inValue); }
		if (HX_FIELD_EQ(inName,"focus") ) { return nmeSetFocus(inValue); }
		if (HX_FIELD_EQ(inName,"onKey") ) { onKey=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onQuit") ) { onQuit=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { return nmeSetQuality(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"dpiScale") ) { dpiScale=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { isOpenGL=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { sUpEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { return nmeSetFrameRate(inValue); }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { return nmeSetScaleMode(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { efLeftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { efCtrlDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { stageWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeInvalid") ) { nmeInvalid=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { efShiftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sDownEvents") ) { sDownEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { nmeLastDown=inValue.Cast< Array< ::nme::display::InteractiveObject > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { sClickEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"displayState") ) { return nmeSetDisplayState(inValue); }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { nmeTouchInfo=inValue.Cast< ::IntHash >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderRequest") ) { renderRequest=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragBounds") ) { nmeDragBounds=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragObject") ) { nmeDragObject=inValue.Cast< ::nme::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastRender") ) { nmeLastRender=inValue.Cast< double >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeEarlyWakeup") ) { nmeEarlyWakeup=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"getOrientation") ) { getOrientation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { return nmeSetStageFocusRect(inValue); }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { nmeJoyAxisData=inValue.Cast< ::IntHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { nmeDragOffsetX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { nmeDragOffsetY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { nmeFramePeriod=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { efLocationRight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efNoNativeClick") ) { efNoNativeClick=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeMouseChanges") ) { nmeMouseChanges=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeTouchChanges") ) { nmeTouchChanges=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_render_stage") ) { nme_render_stage=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastClickTime") ) { nmeLastClickTime=inValue.Cast< double >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OrientationFaceUp") ) { OrientationFaceUp=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"OrientationPortrait") ) { OrientationPortrait=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OrientationFaceDown") ) { OrientationFaceDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_focus") ) { nme_stage_set_focus=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_is_opengl") ) { nme_stage_is_opengl=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_align") ) { nme_stage_get_align=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_align") ) { nme_stage_set_align=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFocusOverObjects") ) { nmeFocusOverObjects=inValue.Cast< Array< ::nme::display::InteractiveObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeMouseOverObjects") ) { nmeMouseOverObjects=inValue.Cast< Array< ::nme::display::InteractiveObject > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"pauseWhenDeactivated") ) { pauseWhenDeactivated=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"shouldRotateInterface") ) { shouldRotateInterface=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_set_stage_handler") ) { nme_set_stage_handler=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_quality") ) { nme_stage_get_quality=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_quality") ) { nme_stage_set_quality=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_show_cursor") ) { nme_stage_show_cursor=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_stage_get_focus_id") ) { nme_stage_get_focus_id=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_stage_get_dpi_scale") ) { nme_stage_get_dpi_scale=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_next_wake") ) { nme_stage_set_next_wake=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"OrientationLandscapeLeft") ) { OrientationLandscapeLeft=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_focus_rect") ) { nme_stage_get_focus_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_focus_rect") ) { nme_stage_set_focus_rect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_scale_mode") ) { nme_stage_get_scale_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_scale_mode") ) { nme_stage_set_scale_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_request_render") ) { nme_stage_request_render=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"OrientationLandscapeRight") ) { OrientationLandscapeRight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_stage_width") ) { nme_stage_get_stage_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_orientation") ) { nme_stage_get_orientation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_stage_get_stage_height") ) { nme_stage_get_stage_height=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_stage_get_display_state") ) { nme_stage_get_display_state=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_display_state") ) { nme_stage_set_display_state=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"OrientationPortraitUpsideDown") ) { OrientationPortraitUpsideDown=inValue.Cast< int >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_stage_set_fixed_orientation") ) { nme_stage_set_fixed_orientation=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Stage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("align"));
	outFields->push(HX_CSTRING("displayState"));
	outFields->push(HX_CSTRING("dpiScale"));
	outFields->push(HX_CSTRING("focus"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("isOpenGL"));
	outFields->push(HX_CSTRING("pauseWhenDeactivated"));
	outFields->push(HX_CSTRING("quality"));
	outFields->push(HX_CSTRING("scaleMode"));
	outFields->push(HX_CSTRING("stageFocusRect"));
	outFields->push(HX_CSTRING("stageHeight"));
	outFields->push(HX_CSTRING("stageWidth"));
	outFields->push(HX_CSTRING("nmeJoyAxisData"));
	outFields->push(HX_CSTRING("nmeDragBounds"));
	outFields->push(HX_CSTRING("nmeDragObject"));
	outFields->push(HX_CSTRING("nmeDragOffsetX"));
	outFields->push(HX_CSTRING("nmeDragOffsetY"));
	outFields->push(HX_CSTRING("nmeFocusOverObjects"));
	outFields->push(HX_CSTRING("nmeFramePeriod"));
	outFields->push(HX_CSTRING("nmeInvalid"));
	outFields->push(HX_CSTRING("nmeLastClickTime"));
	outFields->push(HX_CSTRING("nmeLastDown"));
	outFields->push(HX_CSTRING("nmeLastRender"));
	outFields->push(HX_CSTRING("nmeMouseOverObjects"));
	outFields->push(HX_CSTRING("nmeTouchInfo"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nmeEarlyWakeup"),
	HX_CSTRING("OrientationPortrait"),
	HX_CSTRING("OrientationPortraitUpsideDown"),
	HX_CSTRING("OrientationLandscapeRight"),
	HX_CSTRING("OrientationLandscapeLeft"),
	HX_CSTRING("OrientationFaceUp"),
	HX_CSTRING("OrientationFaceDown"),
	HX_CSTRING("efLeftDown"),
	HX_CSTRING("efShiftDown"),
	HX_CSTRING("efCtrlDown"),
	HX_CSTRING("efAltDown"),
	HX_CSTRING("efCommandDown"),
	HX_CSTRING("efLocationRight"),
	HX_CSTRING("efNoNativeClick"),
	HX_CSTRING("nmeMouseChanges"),
	HX_CSTRING("nmeTouchChanges"),
	HX_CSTRING("sClickEvents"),
	HX_CSTRING("sDownEvents"),
	HX_CSTRING("sUpEvents"),
	HX_CSTRING("getOrientation"),
	HX_CSTRING("setFixedOrientation"),
	HX_CSTRING("shouldRotateInterface"),
	HX_CSTRING("nme_set_stage_handler"),
	HX_CSTRING("nme_render_stage"),
	HX_CSTRING("nme_stage_get_focus_id"),
	HX_CSTRING("nme_stage_set_focus"),
	HX_CSTRING("nme_stage_get_focus_rect"),
	HX_CSTRING("nme_stage_set_focus_rect"),
	HX_CSTRING("nme_stage_is_opengl"),
	HX_CSTRING("nme_stage_get_stage_width"),
	HX_CSTRING("nme_stage_get_stage_height"),
	HX_CSTRING("nme_stage_get_dpi_scale"),
	HX_CSTRING("nme_stage_get_scale_mode"),
	HX_CSTRING("nme_stage_set_scale_mode"),
	HX_CSTRING("nme_stage_get_align"),
	HX_CSTRING("nme_stage_set_align"),
	HX_CSTRING("nme_stage_get_quality"),
	HX_CSTRING("nme_stage_set_quality"),
	HX_CSTRING("nme_stage_get_display_state"),
	HX_CSTRING("nme_stage_set_display_state"),
	HX_CSTRING("nme_stage_set_next_wake"),
	HX_CSTRING("nme_stage_request_render"),
	HX_CSTRING("nme_stage_show_cursor"),
	HX_CSTRING("nme_stage_set_fixed_orientation"),
	HX_CSTRING("nme_stage_get_orientation"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("active"),
	HX_CSTRING("align"),
	HX_CSTRING("displayState"),
	HX_CSTRING("dpiScale"),
	HX_CSTRING("focus"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("isOpenGL"),
	HX_CSTRING("onKey"),
	HX_CSTRING("onQuit"),
	HX_CSTRING("pauseWhenDeactivated"),
	HX_CSTRING("quality"),
	HX_CSTRING("renderRequest"),
	HX_CSTRING("scaleMode"),
	HX_CSTRING("stageFocusRect"),
	HX_CSTRING("stageHeight"),
	HX_CSTRING("stageWidth"),
	HX_CSTRING("nmeJoyAxisData"),
	HX_CSTRING("nmeDragBounds"),
	HX_CSTRING("nmeDragObject"),
	HX_CSTRING("nmeDragOffsetX"),
	HX_CSTRING("nmeDragOffsetY"),
	HX_CSTRING("nmeFocusOverObjects"),
	HX_CSTRING("nmeFramePeriod"),
	HX_CSTRING("nmeInvalid"),
	HX_CSTRING("nmeLastClickTime"),
	HX_CSTRING("nmeLastDown"),
	HX_CSTRING("nmeLastRender"),
	HX_CSTRING("nmeMouseOverObjects"),
	HX_CSTRING("nmeTouchInfo"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("nmeCheckFocusInOuts"),
	HX_CSTRING("nmeCheckInOuts"),
	HX_CSTRING("nmeCheckRender"),
	HX_CSTRING("nmeDoProcessStageEvent"),
	HX_CSTRING("dummyTrace"),
	HX_CSTRING("nmeProcessStageEvent"),
	HX_CSTRING("nmeDrag"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("nmeNextFrameDue"),
	HX_CSTRING("nmeOnChange"),
	HX_CSTRING("nmeOnFocus"),
	HX_CSTRING("nmeOnJoystick"),
	HX_CSTRING("nmeOnKey"),
	HX_CSTRING("nmeOnMouse"),
	HX_CSTRING("nmeOnResize"),
	HX_CSTRING("nmeOnTouch"),
	HX_CSTRING("nmePollTimers"),
	HX_CSTRING("nmeRender"),
	HX_CSTRING("nmeSetActive"),
	HX_CSTRING("nmeStartDrag"),
	HX_CSTRING("nmeStopDrag"),
	HX_CSTRING("nmeUpdateNextWake"),
	HX_CSTRING("showCursor"),
	HX_CSTRING("nmeGetAlign"),
	HX_CSTRING("nmeSetAlign"),
	HX_CSTRING("nmeGetDisplayState"),
	HX_CSTRING("nmeSetDisplayState"),
	HX_CSTRING("nmeGetDPIScale"),
	HX_CSTRING("nmeGetFocus"),
	HX_CSTRING("nmeSetFocus"),
	HX_CSTRING("nmeSetFrameRate"),
	HX_CSTRING("nmeIsOpenGL"),
	HX_CSTRING("nmeGetQuality"),
	HX_CSTRING("nmeSetQuality"),
	HX_CSTRING("nmeGetScaleMode"),
	HX_CSTRING("nmeSetScaleMode"),
	HX_CSTRING("nmeGetStageFocusRect"),
	HX_CSTRING("nmeSetStageFocusRect"),
	HX_CSTRING("nmeGetStageHeight"),
	HX_CSTRING("nmeGetStageWidth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stage_obj::nmeEarlyWakeup,"nmeEarlyWakeup");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationPortrait,"OrientationPortrait");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationPortraitUpsideDown,"OrientationPortraitUpsideDown");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationLandscapeRight,"OrientationLandscapeRight");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationLandscapeLeft,"OrientationLandscapeLeft");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationFaceUp,"OrientationFaceUp");
	HX_MARK_MEMBER_NAME(Stage_obj::OrientationFaceDown,"OrientationFaceDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efLeftDown,"efLeftDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efShiftDown,"efShiftDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efCtrlDown,"efCtrlDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efAltDown,"efAltDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efCommandDown,"efCommandDown");
	HX_MARK_MEMBER_NAME(Stage_obj::efLocationRight,"efLocationRight");
	HX_MARK_MEMBER_NAME(Stage_obj::efNoNativeClick,"efNoNativeClick");
	HX_MARK_MEMBER_NAME(Stage_obj::nmeMouseChanges,"nmeMouseChanges");
	HX_MARK_MEMBER_NAME(Stage_obj::nmeTouchChanges,"nmeTouchChanges");
	HX_MARK_MEMBER_NAME(Stage_obj::sClickEvents,"sClickEvents");
	HX_MARK_MEMBER_NAME(Stage_obj::sDownEvents,"sDownEvents");
	HX_MARK_MEMBER_NAME(Stage_obj::sUpEvents,"sUpEvents");
	HX_MARK_MEMBER_NAME(Stage_obj::getOrientation,"getOrientation");
	HX_MARK_MEMBER_NAME(Stage_obj::shouldRotateInterface,"shouldRotateInterface");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_set_stage_handler,"nme_set_stage_handler");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_render_stage,"nme_render_stage");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_focus_id,"nme_stage_get_focus_id");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_focus,"nme_stage_set_focus");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_focus_rect,"nme_stage_get_focus_rect");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_focus_rect,"nme_stage_set_focus_rect");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_is_opengl,"nme_stage_is_opengl");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_stage_width,"nme_stage_get_stage_width");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_stage_height,"nme_stage_get_stage_height");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_dpi_scale,"nme_stage_get_dpi_scale");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_scale_mode,"nme_stage_get_scale_mode");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_scale_mode,"nme_stage_set_scale_mode");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_align,"nme_stage_get_align");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_align,"nme_stage_set_align");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_quality,"nme_stage_get_quality");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_quality,"nme_stage_set_quality");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_display_state,"nme_stage_get_display_state");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_display_state,"nme_stage_set_display_state");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_next_wake,"nme_stage_set_next_wake");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_request_render,"nme_stage_request_render");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_show_cursor,"nme_stage_show_cursor");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_set_fixed_orientation,"nme_stage_set_fixed_orientation");
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_orientation,"nme_stage_get_orientation");
};

Class Stage_obj::__mClass;

void Stage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Stage"), hx::TCanCast< Stage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stage_obj::__boot()
{
	hx::Static(nmeEarlyWakeup) = 0.005;
	hx::Static(OrientationPortrait) = (int)1;
	hx::Static(OrientationPortraitUpsideDown) = (int)2;
	hx::Static(OrientationLandscapeRight) = (int)3;
	hx::Static(OrientationLandscapeLeft) = (int)4;
	hx::Static(OrientationFaceUp) = (int)5;
	hx::Static(OrientationFaceDown) = (int)6;
	hx::Static(efLeftDown) = (int)1;
	hx::Static(efShiftDown) = (int)2;
	hx::Static(efCtrlDown) = (int)4;
	hx::Static(efAltDown) = (int)8;
	hx::Static(efCommandDown) = (int)16;
	hx::Static(efLocationRight) = (int)16384;
	hx::Static(efNoNativeClick) = (int)65536;
	hx::Static(nmeMouseChanges) = Array_obj< ::String >::__new().Add(::nme::events::MouseEvent_obj::MOUSE_OUT).Add(::nme::events::MouseEvent_obj::MOUSE_OVER).Add(::nme::events::MouseEvent_obj::ROLL_OUT).Add(::nme::events::MouseEvent_obj::ROLL_OVER);
	hx::Static(nmeTouchChanges) = Array_obj< ::String >::__new().Add(::nme::events::TouchEvent_obj::TOUCH_OUT).Add(::nme::events::TouchEvent_obj::TOUCH_OVER).Add(::nme::events::TouchEvent_obj::TOUCH_ROLL_OUT).Add(::nme::events::TouchEvent_obj::TOUCH_ROLL_OVER);
	hx::Static(sClickEvents) = Array_obj< ::String >::__new().Add(HX_CSTRING("click")).Add(HX_CSTRING("middleClick")).Add(HX_CSTRING("rightClick"));
	hx::Static(sDownEvents) = Array_obj< ::String >::__new().Add(HX_CSTRING("mouseDown")).Add(HX_CSTRING("middleMouseDown")).Add(HX_CSTRING("rightMouseDown"));
	hx::Static(sUpEvents) = Array_obj< ::String >::__new().Add(HX_CSTRING("mouseUp")).Add(HX_CSTRING("middleMouseUp")).Add(HX_CSTRING("rightMouseUp"));
	hx::Static(getOrientation) = new __default_getOrientation;

	hx::Static(shouldRotateInterface) = new __default_shouldRotateInterface;

	hx::Static(nme_set_stage_handler) = ::nme::Loader_obj::load(HX_CSTRING("nme_set_stage_handler"),(int)4);
	hx::Static(nme_render_stage) = ::nme::Loader_obj::load(HX_CSTRING("nme_render_stage"),(int)1);
	hx::Static(nme_stage_get_focus_id) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_id"),(int)1);
	hx::Static(nme_stage_set_focus) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_focus"),(int)3);
	hx::Static(nme_stage_get_focus_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_rect"),(int)1);
	hx::Static(nme_stage_set_focus_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_focus_rect"),(int)2);
	hx::Static(nme_stage_is_opengl) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_is_opengl"),(int)1);
	hx::Static(nme_stage_get_stage_width) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_width"),(int)1);
	hx::Static(nme_stage_get_stage_height) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_height"),(int)1);
	hx::Static(nme_stage_get_dpi_scale) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_dpi_scale"),(int)1);
	hx::Static(nme_stage_get_scale_mode) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_scale_mode"),(int)1);
	hx::Static(nme_stage_set_scale_mode) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_scale_mode"),(int)2);
	hx::Static(nme_stage_get_align) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_align"),(int)1);
	hx::Static(nme_stage_set_align) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_align"),(int)2);
	hx::Static(nme_stage_get_quality) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_quality"),(int)1);
	hx::Static(nme_stage_set_quality) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_quality"),(int)2);
	hx::Static(nme_stage_get_display_state) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_display_state"),(int)1);
	hx::Static(nme_stage_set_display_state) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_display_state"),(int)2);
	hx::Static(nme_stage_set_next_wake) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_next_wake"),(int)2);
	hx::Static(nme_stage_request_render) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_request_render"),(int)0);
	hx::Static(nme_stage_show_cursor) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_show_cursor"),(int)2);
	hx::Static(nme_stage_set_fixed_orientation) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_set_fixed_orientation"),(int)1);
	hx::Static(nme_stage_get_orientation) = ::nme::Loader_obj::load(HX_CSTRING("nme_stage_get_orientation"),(int)0);
}

} // end namespace nme
} // end namespace display
