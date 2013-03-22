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
#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
#endif
#ifndef INCLUDED_neash_display_Stage
#include <neash/display/Stage.h>
#endif
#ifndef INCLUDED_neash_display_StageAlign
#include <neash/display/StageAlign.h>
#endif
#ifndef INCLUDED_neash_display_StageDisplayState
#include <neash/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_neash_display_StageQuality
#include <neash/display/StageQuality.h>
#endif
#ifndef INCLUDED_neash_display_StageScaleMode
#include <neash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_neash_display_TouchInfo
#include <neash/display/TouchInfo.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_FocusEvent
#include <neash/events/FocusEvent.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_JoystickEvent
#include <neash/events/JoystickEvent.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_neash_events_TouchEvent
#include <neash/events/TouchEvent.h>
#endif
#ifndef INCLUDED_neash_geom_Point
#include <neash/geom/Point.h>
#endif
#ifndef INCLUDED_neash_geom_Rectangle
#include <neash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_neash_media_SoundChannel
#include <neash/media/SoundChannel.h>
#endif
#ifndef INCLUDED_neash_net_URLLoader
#include <neash/net/URLLoader.h>
#endif
namespace neash{
namespace display{

Void Stage_obj::__construct(Dynamic inHandle,int inWidth,int inHeight)
{
HX_STACK_PUSH("Stage::new","neash/display/Stage.hx",85);
{
	HX_STACK_LINE(86)
	super::__construct(inHandle,HX_CSTRING("Stage"));
	HX_STACK_LINE(87)
	this->nmeMouseOverObjects = Array_obj< ::neash::display::InteractiveObject >::__new();
	HX_STACK_LINE(88)
	this->nmeFocusOverObjects = Array_obj< ::neash::display::InteractiveObject >::__new();
	HX_STACK_LINE(89)
	this->active = true;
	HX_STACK_LINE(90)
	this->pauseWhenDeactivated = true;
	HX_STACK_LINE(95)
	this->renderRequest = null();
	HX_STACK_LINE(98)
	::neash::display::Stage_obj::nme_set_stage_handler(this->nmeHandle,this->nmeProcessStageEvent_dyn(),inWidth,inHeight);
	HX_STACK_LINE(99)
	this->nmeInvalid = false;
	HX_STACK_LINE(100)
	this->nmeLastRender = (int)0;
	HX_STACK_LINE(101)
	this->nmeLastDown = Array_obj< ::neash::display::InteractiveObject >::__new();
	HX_STACK_LINE(102)
	this->nmeLastClickTime = 0.0;
	HX_STACK_LINE(103)
	this->nmeSetFrameRate((int)100);
	HX_STACK_LINE(104)
	this->nmeTouchInfo = ::IntHash_obj::__new();
	HX_STACK_LINE(105)
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

int Stage_obj::nmeGetStageWidth( ){
	HX_STACK_PUSH("Stage::nmeGetStageWidth","neash/display/Stage.hx",873);
	HX_STACK_THIS(this);
	HX_STACK_LINE(873)
	return ::Std_obj::_int(hx::TCast< Float >::cast(::neash::display::Stage_obj::nme_stage_get_stage_width(this->nmeHandle)));
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageWidth,return )

int Stage_obj::nmeGetStageHeight( ){
	HX_STACK_PUSH("Stage::nmeGetStageHeight","neash/display/Stage.hx",867);
	HX_STACK_THIS(this);
	HX_STACK_LINE(867)
	return ::Std_obj::_int(hx::TCast< Float >::cast(::neash::display::Stage_obj::nme_stage_get_stage_height(this->nmeHandle)));
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageHeight,return )

bool Stage_obj::nmeSetStageFocusRect( bool inVal){
	HX_STACK_PUSH("Stage::nmeSetStageFocusRect","neash/display/Stage.hx",860);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(861)
	::neash::display::Stage_obj::nme_stage_set_focus_rect(this->nmeHandle,inVal);
	HX_STACK_LINE(862)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetStageFocusRect,return )

bool Stage_obj::nmeGetStageFocusRect( ){
	HX_STACK_PUSH("Stage::nmeGetStageFocusRect","neash/display/Stage.hx",858);
	HX_STACK_THIS(this);
	HX_STACK_LINE(858)
	return ::neash::display::Stage_obj::nme_stage_get_focus_rect(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetStageFocusRect,return )

::neash::display::StageScaleMode Stage_obj::nmeSetScaleMode( ::neash::display::StageScaleMode inMode){
	HX_STACK_PUSH("Stage::nmeSetScaleMode","neash/display/Stage.hx",852);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(853)
	::neash::display::Stage_obj::nme_stage_set_scale_mode(this->nmeHandle,inMode->__Index());
	HX_STACK_LINE(854)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetScaleMode,return )

::neash::display::StageScaleMode Stage_obj::nmeGetScaleMode( ){
	HX_STACK_PUSH("Stage::nmeGetScaleMode","neash/display/Stage.hx",845);
	HX_STACK_THIS(this);
	HX_STACK_LINE(846)
	int i = ::neash::display::Stage_obj::nme_stage_get_scale_mode(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(847)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::StageScaleMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetScaleMode,return )

::neash::display::StageQuality Stage_obj::nmeSetQuality( ::neash::display::StageQuality inQuality){
	HX_STACK_PUSH("Stage::nmeSetQuality","neash/display/Stage.hx",838);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inQuality,"inQuality");
	HX_STACK_LINE(839)
	::neash::display::Stage_obj::nme_stage_set_quality(this->nmeHandle,inQuality->__Index());
	HX_STACK_LINE(840)
	return inQuality;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetQuality,return )

::neash::display::StageQuality Stage_obj::nmeGetQuality( ){
	HX_STACK_PUSH("Stage::nmeGetQuality","neash/display/Stage.hx",831);
	HX_STACK_THIS(this);
	HX_STACK_LINE(832)
	int i = ::neash::display::Stage_obj::nme_stage_get_quality(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(833)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::StageQuality >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetQuality,return )

bool Stage_obj::nmeIsOpenGL( ){
	HX_STACK_PUSH("Stage::nmeIsOpenGL","neash/display/Stage.hx",825);
	HX_STACK_THIS(this);
	HX_STACK_LINE(825)
	return ::neash::display::Stage_obj::nme_stage_is_opengl(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeIsOpenGL,return )

Float Stage_obj::nmeSetFrameRate( Float inRate){
	HX_STACK_PUSH("Stage::nmeSetFrameRate","neash/display/Stage.hx",817);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inRate,"inRate");
	HX_STACK_LINE(818)
	this->frameRate = inRate;
	HX_STACK_LINE(819)
	this->nmeFramePeriod = (  (((this->frameRate <= (int)0))) ? Float(this->frameRate) : Float((Float(1.0) / Float(this->frameRate))) );
	HX_STACK_LINE(820)
	return inRate;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetFrameRate,return )

::neash::display::InteractiveObject Stage_obj::nmeSetFocus( ::neash::display::InteractiveObject inObject){
	HX_STACK_PUSH("Stage::nmeSetFocus","neash/display/Stage.hx",807);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inObject,"inObject");
	HX_STACK_LINE(808)
	if (((inObject == null()))){
		HX_STACK_LINE(809)
		::neash::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,null(),(int)0);
	}
	else{
		HX_STACK_LINE(811)
		::neash::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,inObject->nmeHandle,(int)0);
	}
	HX_STACK_LINE(812)
	return inObject;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetFocus,return )

::neash::display::InteractiveObject Stage_obj::nmeGetFocus( ){
	HX_STACK_PUSH("Stage::nmeGetFocus","neash/display/Stage.hx",799);
	HX_STACK_THIS(this);
	HX_STACK_LINE(800)
	int id = ::neash::display::Stage_obj::nme_stage_get_focus_id(this->nmeHandle);		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(801)
	::neash::display::DisplayObject obj = this->nmeFindByID(id);		HX_STACK_VAR(obj,"obj");
	HX_STACK_LINE(802)
	return obj;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetFocus,return )

Float Stage_obj::nmeGetDPIScale( ){
	HX_STACK_PUSH("Stage::nmeGetDPIScale","neash/display/Stage.hx",793);
	HX_STACK_THIS(this);
	HX_STACK_LINE(793)
	return ::neash::display::Stage_obj::nme_stage_get_dpi_scale(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetDPIScale,return )

::neash::display::StageDisplayState Stage_obj::nmeSetDisplayState( ::neash::display::StageDisplayState inState){
	HX_STACK_PUSH("Stage::nmeSetDisplayState","neash/display/Stage.hx",786);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inState,"inState");
	HX_STACK_LINE(787)
	::neash::display::Stage_obj::nme_stage_set_display_state(this->nmeHandle,inState->__Index());
	HX_STACK_LINE(788)
	return inState;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetDisplayState,return )

::neash::display::StageDisplayState Stage_obj::nmeGetDisplayState( ){
	HX_STACK_PUSH("Stage::nmeGetDisplayState","neash/display/Stage.hx",779);
	HX_STACK_THIS(this);
	HX_STACK_LINE(780)
	int i = ::neash::display::Stage_obj::nme_stage_get_display_state(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(781)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::StageDisplayState >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetDisplayState,return )

::neash::display::StageAlign Stage_obj::nmeSetAlign( ::neash::display::StageAlign inMode){
	HX_STACK_PUSH("Stage::nmeSetAlign","neash/display/Stage.hx",772);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(773)
	::neash::display::Stage_obj::nme_stage_set_align(this->nmeHandle,inMode->__Index());
	HX_STACK_LINE(774)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetAlign,return )

::neash::display::StageAlign Stage_obj::nmeGetAlign( ){
	HX_STACK_PUSH("Stage::nmeGetAlign","neash/display/Stage.hx",765);
	HX_STACK_THIS(this);
	HX_STACK_LINE(766)
	int i = ::neash::display::Stage_obj::nme_stage_get_align(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(767)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::neash::display::StageAlign >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeGetAlign,return )

Void Stage_obj::showCursor( bool inShow){
{
		HX_STACK_PUSH("Stage::showCursor","neash/display/Stage.hx",754);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inShow,"inShow");
		HX_STACK_LINE(754)
		::neash::display::Stage_obj::nme_stage_show_cursor(this->nmeHandle,inShow);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,showCursor,(void))

Float Stage_obj::nmeUpdateNextWake( ){
	HX_STACK_PUSH("Stage::nmeUpdateNextWake","neash/display/Stage.hx",725);
	HX_STACK_THIS(this);
	HX_STACK_LINE(727)
	Float next_wake = ::haxe::Timer_obj::nmeNextWake(315000000.0);		HX_STACK_VAR(next_wake,"next_wake");
	HX_STACK_LINE(728)
	if (((bool((next_wake > 0.001)) && bool((::neash::media::SoundChannel_obj::nmeDynamicSoundCount > (int)0))))){
		HX_STACK_LINE(729)
		next_wake = 0.001;
	}
	HX_STACK_LINE(730)
	if (((bool((next_wake > 0.02)) && bool(((bool(::neash::media::SoundChannel_obj::nmeCompletePending()) || bool(::neash::net::URLLoader_obj::nmeLoadPending()))))))){
		HX_STACK_LINE(731)
		next_wake = (  (((bool(this->active) || bool(!(this->pauseWhenDeactivated))))) ? Float(0.020) : Float(0.500) );
	}
	HX_STACK_LINE(734)
	next_wake = this->nmeNextFrameDue(next_wake);
	HX_STACK_LINE(735)
	::neash::display::Stage_obj::nme_stage_set_next_wake(this->nmeHandle,next_wake);
	HX_STACK_LINE(736)
	return next_wake;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeUpdateNextWake,return )

Void Stage_obj::nmeStopDrag( ::neash::display::Sprite sprite){
{
		HX_STACK_PUSH("Stage::nmeStopDrag","neash/display/Stage.hx",718);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sprite,"sprite");
		HX_STACK_LINE(719)
		this->nmeDragBounds = null();
		HX_STACK_LINE(720)
		this->nmeDragObject = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeStopDrag,(void))

Void Stage_obj::nmeStartDrag( ::neash::display::Sprite sprite,bool lockCenter,::neash::geom::Rectangle bounds){
{
		HX_STACK_PUSH("Stage::nmeStartDrag","neash/display/Stage.hx",692);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sprite,"sprite");
		HX_STACK_ARG(lockCenter,"lockCenter");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(693)
		this->nmeDragBounds = (  (((bounds == null()))) ? ::neash::geom::Rectangle(null()) : ::neash::geom::Rectangle(bounds->clone()) );
		HX_STACK_LINE(694)
		this->nmeDragObject = sprite;
		HX_STACK_LINE(696)
		if (((this->nmeDragObject != null()))){
			HX_STACK_LINE(697)
			if ((lockCenter)){
				HX_STACK_LINE(700)
				this->nmeDragOffsetX = (Float(-(this->nmeDragObject->nmeGetWidth())) / Float((int)2));
				HX_STACK_LINE(701)
				this->nmeDragOffsetY = (Float(-(this->nmeDragObject->nmeGetHeight())) / Float((int)2));
			}
			else{
				HX_STACK_LINE(705)
				::neash::geom::Point mouse = ::neash::geom::Point_obj::__new(this->nmeGetMouseX(),this->nmeGetMouseY());		HX_STACK_VAR(mouse,"mouse");
				HX_STACK_LINE(706)
				::neash::display::DisplayObjectContainer p = this->nmeDragObject->nmeGetParent();		HX_STACK_VAR(p,"p");
				HX_STACK_LINE(707)
				if (((p != null()))){
					HX_STACK_LINE(708)
					mouse = p->globalToLocal(mouse);
				}
				HX_STACK_LINE(710)
				this->nmeDragOffsetX = (this->nmeDragObject->nmeGetX() - mouse->x);
				HX_STACK_LINE(711)
				this->nmeDragOffsetY = (this->nmeDragObject->nmeGetY() - mouse->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeStartDrag,(void))

Void Stage_obj::nmeSetActive( bool inActive){
{
		HX_STACK_PUSH("Stage::nmeSetActive","neash/display/Stage.hx",675);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inActive,"inActive");
		HX_STACK_LINE(675)
		if (((inActive != this->active))){
			HX_STACK_LINE(679)
			this->active = inActive;
			HX_STACK_LINE(680)
			if ((!(this->active))){
				HX_STACK_LINE(681)
				this->nmeLastRender = ::haxe::Timer_obj::stamp();
			}
			HX_STACK_LINE(683)
			::neash::events::Event evt = ::neash::events::Event_obj::__new((  ((inActive)) ? ::String(::neash::events::Event_obj::ACTIVATE) : ::String(::neash::events::Event_obj::DEACTIVATE) ),null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(684)
			this->nmeBroadcast(evt);
			HX_STACK_LINE(685)
			if ((inActive)){
				HX_STACK_LINE(686)
				this->nmePollTimers();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetActive,(void))

Void Stage_obj::nmeRender( bool inSendEnterFrame){
{
		HX_STACK_PUSH("Stage::nmeRender","neash/display/Stage.hx",656);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSendEnterFrame,"inSendEnterFrame");
		HX_STACK_LINE(657)
		if ((!(this->active))){
			HX_STACK_LINE(658)
			return null();
		}
		HX_STACK_LINE(661)
		if ((inSendEnterFrame)){
			HX_STACK_LINE(662)
			this->nmeBroadcast(::neash::events::Event_obj::__new(::neash::events::Event_obj::ENTER_FRAME,null(),null()));
		}
		HX_STACK_LINE(665)
		if ((this->nmeInvalid)){
			HX_STACK_LINE(667)
			this->nmeInvalid = false;
			HX_STACK_LINE(668)
			this->nmeBroadcast(::neash::events::Event_obj::__new(::neash::events::Event_obj::RENDER,null(),null()));
		}
		HX_STACK_LINE(670)
		::neash::display::Stage_obj::nme_render_stage(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeRender,(void))

Void Stage_obj::nmePollTimers( ){
{
		HX_STACK_PUSH("Stage::nmePollTimers","neash/display/Stage.hx",646);
		HX_STACK_THIS(this);
		HX_STACK_LINE(648)
		::haxe::Timer_obj::nmeCheckTimers();
		HX_STACK_LINE(649)
		::neash::media::SoundChannel_obj::nmePollComplete();
		HX_STACK_LINE(650)
		::neash::net::URLLoader_obj::nmePollData();
		HX_STACK_LINE(651)
		this->nmeCheckRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmePollTimers,(void))

Void Stage_obj::nmeOnTouch( Dynamic inEvent,::String inType,::neash::display::TouchInfo touchInfo){
{
		HX_STACK_PUSH("Stage::nmeOnTouch","neash/display/Stage.hx",607);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_ARG(touchInfo,"touchInfo");
		HX_STACK_LINE(608)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(609)
		::neash::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(610)
		if (((obj != null()))){
			HX_STACK_LINE(611)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(613)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(615)
			::neash::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(616)
			stack->reverse();
			HX_STACK_LINE(617)
			::neash::geom::Point local = obj1->globalToLocal(::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));		HX_STACK_VAR(local,"local");
			HX_STACK_LINE(618)
			::neash::events::TouchEvent evt = ::neash::events::TouchEvent_obj::nmeCreate(inType,inEvent,local,obj1,inEvent->__Field(HX_CSTRING("sx"),true),inEvent->__Field(HX_CSTRING("sy"),true));		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(619)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"),true);
			HX_STACK_LINE(620)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0);
			HX_STACK_LINE(622)
			this->nmeCheckInOuts(evt,stack,touchInfo);
			HX_STACK_LINE(623)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(624)
			if (((bool(evt->isPrimaryTouchPoint) && bool((inType == ::neash::events::TouchEvent_obj::TOUCH_MOVE))))){
				HX_STACK_LINE(626)
				if (((this->nmeDragObject != null()))){
					HX_STACK_LINE(627)
					this->nmeDrag(::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
				}
				HX_STACK_LINE(629)
				::neash::events::MouseEvent evt1 = ::neash::events::MouseEvent_obj::nmeCreate(::neash::events::MouseEvent_obj::MOUSE_MOVE,inEvent,local,obj1);		HX_STACK_VAR(evt1,"evt1");
				HX_STACK_LINE(630)
				obj1->nmeFireEvent(evt1);
			}
		}
		else{
			HX_STACK_LINE(636)
			::neash::events::TouchEvent evt = ::neash::events::TouchEvent_obj::nmeCreate(inType,inEvent,::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)),null(),inEvent->__Field(HX_CSTRING("sx"),true),inEvent->__Field(HX_CSTRING("sy"),true));		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(637)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"),true);
			HX_STACK_LINE(638)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0);
			HX_STACK_LINE(640)
			this->nmeCheckInOuts(evt,stack,touchInfo);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnTouch,(void))

Void Stage_obj::nmeOnResize( Float inW,Float inH){
{
		HX_STACK_PUSH("Stage::nmeOnResize","neash/display/Stage.hx",600);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inW,"inW");
		HX_STACK_ARG(inH,"inH");
		HX_STACK_LINE(601)
		::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::Event_obj::RESIZE,null(),null());		HX_STACK_VAR(evt,"evt");
		HX_STACK_LINE(602)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnResize,(void))

Void Stage_obj::nmeOnMouse( Dynamic inEvent,::String inType,bool inFromMouse){
{
		HX_STACK_PUSH("Stage::nmeOnMouse","neash/display/Stage.hx",517);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_ARG(inFromMouse,"inFromMouse");
		HX_STACK_LINE(518)
		::String type = inType;		HX_STACK_VAR(type,"type");
		HX_STACK_LINE(519)
		int button = inEvent->__Field(HX_CSTRING("value"),true);		HX_STACK_VAR(button,"button");
		HX_STACK_LINE(520)
		if ((!(inFromMouse))){
			HX_STACK_LINE(521)
			button = (int)0;
		}
		HX_STACK_LINE(522)
		int wheel = (int)0;		HX_STACK_VAR(wheel,"wheel");
		HX_STACK_LINE(523)
		if (((inType == ::neash::events::MouseEvent_obj::MOUSE_DOWN))){
			HX_STACK_LINE(525)
			if (((button > (int)2))){
				HX_STACK_LINE(526)
				return null();
			}
			HX_STACK_LINE(527)
			type = ::neash::display::Stage_obj::sDownEvents->__get(button);
		}
		else{
			HX_STACK_LINE(529)
			if (((inType == ::neash::events::MouseEvent_obj::MOUSE_UP))){
				HX_STACK_LINE(530)
				if (((button > (int)2))){
					HX_STACK_LINE(533)
					type = ::neash::events::MouseEvent_obj::MOUSE_WHEEL;
					HX_STACK_LINE(534)
					wheel = (  (((button == (int)3))) ? int((int)1) : int((int)-1) );
				}
				else{
					HX_STACK_LINE(538)
					type = ::neash::display::Stage_obj::sUpEvents->__get(button);
				}
			}
		}
		HX_STACK_LINE(541)
		if (((this->nmeDragObject != null()))){
			HX_STACK_LINE(542)
			this->nmeDrag(::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
		}
		HX_STACK_LINE(544)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(545)
		::neash::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(546)
		if (((obj != null()))){
			HX_STACK_LINE(547)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(549)
		::neash::geom::Point local = null();		HX_STACK_VAR(local,"local");
		HX_STACK_LINE(550)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(552)
			::neash::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(553)
			stack->reverse();
			HX_STACK_LINE(554)
			local = obj1->globalToLocal(::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
			HX_STACK_LINE(555)
			::neash::events::MouseEvent evt = ::neash::events::MouseEvent_obj::nmeCreate(type,inEvent,local,obj1);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(556)
			evt->delta = wheel;
			HX_STACK_LINE(557)
			if ((inFromMouse)){
				HX_STACK_LINE(558)
				this->nmeCheckInOuts(evt,stack,null());
			}
			HX_STACK_LINE(559)
			obj1->nmeFireEvent(evt);
		}
		else{
			HX_STACK_LINE(564)
			local = ::neash::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(565)
			::neash::events::MouseEvent evt = ::neash::events::MouseEvent_obj::nmeCreate(type,inEvent,local,null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(566)
			evt->delta = wheel;
			HX_STACK_LINE(567)
			if ((inFromMouse)){
				HX_STACK_LINE(568)
				this->nmeCheckInOuts(evt,stack,null());
			}
		}
		HX_STACK_LINE(571)
		::neash::display::InteractiveObject click_obj = (  (((stack->length > (int)0))) ? ::neash::display::InteractiveObject(stack->__get((stack->length - (int)1))) : ::neash::display::InteractiveObject(hx::ObjectPtr<OBJ_>(this)) );		HX_STACK_VAR(click_obj,"click_obj");
		HX_STACK_LINE(572)
		if (((bool((inType == ::neash::events::MouseEvent_obj::MOUSE_DOWN)) && bool((button < (int)3))))){
			HX_STACK_LINE(573)
			this->nmeLastDown[button] = click_obj;
		}
		else{
			HX_STACK_LINE(576)
			if (((bool((inType == ::neash::events::MouseEvent_obj::MOUSE_UP)) && bool((button < (int)3))))){
				HX_STACK_LINE(578)
				if (((click_obj == this->nmeLastDown->__get(button)))){
					HX_STACK_LINE(580)
					::neash::events::MouseEvent evt = ::neash::events::MouseEvent_obj::nmeCreate(::neash::display::Stage_obj::sClickEvents->__get(button),inEvent,local,click_obj);		HX_STACK_VAR(evt,"evt");
					HX_STACK_LINE(581)
					click_obj->nmeFireEvent(evt);
					HX_STACK_LINE(583)
					if (((bool((button == (int)0)) && bool(click_obj->doubleClickEnabled)))){
						HX_STACK_LINE(585)
						Float now = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(now,"now");
						HX_STACK_LINE(586)
						if ((((now - this->nmeLastClickTime) < 0.25))){
							HX_STACK_LINE(588)
							::neash::events::MouseEvent evt1 = ::neash::events::MouseEvent_obj::nmeCreate(::neash::events::MouseEvent_obj::DOUBLE_CLICK,inEvent,local,click_obj);		HX_STACK_VAR(evt1,"evt1");
							HX_STACK_LINE(589)
							click_obj->nmeFireEvent(evt1);
						}
						HX_STACK_LINE(591)
						this->nmeLastClickTime = now;
					}
				}
				HX_STACK_LINE(594)
				this->nmeLastDown[button] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnMouse,(void))

Void Stage_obj::nmeOnKey( Dynamic inEvent,::String inType){
{
		HX_STACK_PUSH("Stage::nmeOnKey","neash/display/Stage.hx",499);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_LINE(500)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(501)
		::neash::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(502)
		if (((obj != null()))){
			HX_STACK_LINE(503)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(504)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(506)
			::neash::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(507)
			int flags = inEvent->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
			HX_STACK_LINE(508)
			::neash::events::KeyboardEvent evt = ::neash::events::KeyboardEvent_obj::__new(inType,true,true,inEvent->__Field(HX_CSTRING("code"),true),inEvent->__Field(HX_CSTRING("value"),true),(  (((((int(flags) & int(::neash::display::Stage_obj::efLocationRight))) == (int)0))) ? int((int)1) : int((int)0) ),(((int(flags) & int(::neash::display::Stage_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::neash::display::Stage_obj::efAltDown))) != (int)0),(((int(flags) & int(::neash::display::Stage_obj::efShiftDown))) != (int)0),null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(509)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(510)
			if ((evt->nmeGetIsCancelled())){
				HX_STACK_LINE(511)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnKey,(void))

Void Stage_obj::nmeOnJoystick( Dynamic inEvent,::String inType){
{
		HX_STACK_PUSH("Stage::nmeOnJoystick","neash/display/Stage.hx",439);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_LINE(440)
		::neash::events::JoystickEvent evt = null();		HX_STACK_VAR(evt,"evt");
		HX_STACK_LINE(441)
		::String _switch_1 = (inType);
		if (  ( _switch_1==::neash::events::JoystickEvent_obj::AXIS_MOVE)){
			HX_STACK_LINE(444)
			Dynamic data = this->nmeJoyAxisData->get(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(445)
			if (((data == null()))){
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","neash/display/Stage.hx",447);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("x") , 0.0,false);
							__result->Add(HX_CSTRING("y") , 0.0,false);
							__result->Add(HX_CSTRING("z") , 0.0,false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(446)
				data = _Function_3_1::Block();
			}
			HX_STACK_LINE(450)
			Float value = (Float(inEvent->__Field(HX_CSTRING("value"),true)) / Float((int)32767));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(451)
			if (((value < (int)-1))){
				HX_STACK_LINE(451)
				value = (int)-1;
			}
			HX_STACK_LINE(453)
			switch( (int)(inEvent->__Field(HX_CSTRING("code"),true))){
				case (int)0: {
					HX_STACK_LINE(455)
					data->__FieldRef(HX_CSTRING("x")) = value;
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(456)
					data->__FieldRef(HX_CSTRING("y")) = value;
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(457)
					data->__FieldRef(HX_CSTRING("z")) = value;
				}
				;break;
			}
			HX_STACK_LINE(460)
			evt = ::neash::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),(int)0,data->__Field(HX_CSTRING("x"),true),data->__Field(HX_CSTRING("y"),true),data->__Field(HX_CSTRING("z"),true));
			HX_STACK_LINE(462)
			this->nmeJoyAxisData->set(inEvent->__Field(HX_CSTRING("id"),true),data);
		}
		else if (  ( _switch_1==::neash::events::JoystickEvent_obj::BALL_MOVE)){
			HX_STACK_LINE(464)
			evt = ::neash::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true),null());
		}
		else if (  ( _switch_1==::neash::events::JoystickEvent_obj::HAT_MOVE)){
			HX_STACK_LINE(468)
			int x = (int)0;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(469)
			int y = (int)0;		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(471)
			if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)1))) != (int)0))){
				HX_STACK_LINE(472)
				y = (int)-1;
			}
			else{
				HX_STACK_LINE(475)
				if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)4))) != (int)0))){
					HX_STACK_LINE(476)
					y = (int)1;
				}
			}
			HX_STACK_LINE(480)
			if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)2))) != (int)0))){
				HX_STACK_LINE(481)
				x = (int)1;
			}
			else{
				HX_STACK_LINE(484)
				if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)8))) != (int)0))){
					HX_STACK_LINE(485)
					x = (int)-1;
				}
			}
			HX_STACK_LINE(489)
			evt = ::neash::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),x,y,null());
		}
		else  {
			HX_STACK_LINE(491)
			evt = ::neash::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),null(),null(),null());
		}
;
;
		HX_STACK_LINE(494)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnJoystick,(void))

Void Stage_obj::nmeOnFocus( Dynamic inEvent){
{
		HX_STACK_PUSH("Stage::nmeOnFocus","neash/display/Stage.hx",415);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_LINE(416)
		Array< ::neash::display::InteractiveObject > stack = Array_obj< ::neash::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(417)
		::neash::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(418)
		if (((obj != null()))){
			HX_STACK_LINE(419)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(420)
		if (((bool((stack->length > (int)0)) && bool(((bool((inEvent->__Field(HX_CSTRING("value"),true) == (int)1)) || bool((inEvent->__Field(HX_CSTRING("value"),true) == (int)2)))))))){
			HX_STACK_LINE(422)
			::neash::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(423)
			::neash::events::FocusEvent evt = ::neash::events::FocusEvent_obj::__new((  (((inEvent->__Field(HX_CSTRING("value"),true) == (int)1))) ? ::String(::neash::events::FocusEvent_obj::MOUSE_FOCUS_CHANGE) : ::String(::neash::events::FocusEvent_obj::KEY_FOCUS_CHANGE) ),true,true,(  (((this->nmeFocusOverObjects->length == (int)0))) ? ::neash::display::InteractiveObject(null()) : ::neash::display::InteractiveObject(this->nmeFocusOverObjects->__get((int)0)) ),(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(424)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(425)
			if ((evt->nmeGetIsCancelled())){
				HX_STACK_LINE(427)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
				HX_STACK_LINE(428)
				return null();
			}
		}
		HX_STACK_LINE(432)
		stack->reverse();
		HX_STACK_LINE(434)
		this->nmeCheckFocusInOuts(inEvent,stack);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnFocus,(void))

Void Stage_obj::nmeOnChange( Dynamic inEvent){
{
		HX_STACK_PUSH("Stage::nmeOnChange","neash/display/Stage.hx",407);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_LINE(408)
		::neash::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(409)
		if (((obj != null()))){
			HX_STACK_LINE(410)
			obj->nmeFireEvent(::neash::events::Event_obj::__new(::neash::events::Event_obj::CHANGE,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnChange,(void))

Float Stage_obj::nmeNextFrameDue( Float inOtherTimers){
	HX_STACK_PUSH("Stage::nmeNextFrameDue","neash/display/Stage.hx",393);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inOtherTimers,"inOtherTimers");
	HX_STACK_LINE(394)
	if (((bool(!(this->active)) && bool(this->pauseWhenDeactivated)))){
		HX_STACK_LINE(395)
		return inOtherTimers;
	}
	HX_STACK_LINE(396)
	if (((this->frameRate > (int)0))){
		HX_STACK_LINE(398)
		Float next = (((this->nmeLastRender + this->nmeFramePeriod) - ::haxe::Timer_obj::stamp()) - ::neash::display::Stage_obj::nmeEarlyWakeup);		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(399)
		if (((next < inOtherTimers))){
			HX_STACK_LINE(400)
			return next;
		}
	}
	HX_STACK_LINE(402)
	return inOtherTimers;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeNextFrameDue,return )

::neash::display::Stage Stage_obj::nmeGetStage( ){
	HX_STACK_PUSH("Stage::nmeGetStage","neash/display/Stage.hx",387);
	HX_STACK_THIS(this);
	HX_STACK_LINE(387)
	return hx::ObjectPtr<OBJ_>(this);
}


Void Stage_obj::nmeDrag( ::neash::geom::Point inMouse){
{
		HX_STACK_PUSH("Stage::nmeDrag","neash/display/Stage.hx",364);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inMouse,"inMouse");
		HX_STACK_LINE(365)
		::neash::display::DisplayObjectContainer p = this->nmeDragObject->nmeGetParent();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(366)
		if (((p != null()))){
			HX_STACK_LINE(367)
			inMouse = p->globalToLocal(inMouse);
		}
		HX_STACK_LINE(369)
		Float x = (inMouse->x + this->nmeDragOffsetX);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(370)
		Float y = (inMouse->y + this->nmeDragOffsetY);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(372)
		if (((this->nmeDragBounds != null()))){
			HX_STACK_LINE(374)
			if (((x < this->nmeDragBounds->x))){
				HX_STACK_LINE(374)
				x = this->nmeDragBounds->x;
			}
			else{
				HX_STACK_LINE(375)
				if (((x > this->nmeDragBounds->nmeGetRight()))){
					HX_STACK_LINE(375)
					x = this->nmeDragBounds->nmeGetRight();
				}
			}
			HX_STACK_LINE(377)
			if (((y < this->nmeDragBounds->y))){
				HX_STACK_LINE(377)
				y = this->nmeDragBounds->y;
			}
			else{
				HX_STACK_LINE(378)
				if (((y > this->nmeDragBounds->nmeGetBottom()))){
					HX_STACK_LINE(378)
					y = this->nmeDragBounds->nmeGetBottom();
				}
			}
		}
		HX_STACK_LINE(381)
		this->nmeDragObject->nmeSetX(x);
		HX_STACK_LINE(382)
		this->nmeDragObject->nmeSetY(y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDrag,(void))

Dynamic Stage_obj::nmeProcessStageEvent( Dynamic inEvent){
	HX_STACK_PUSH("Stage::nmeProcessStageEvent","neash/display/Stage.hx",357);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_LINE(358)
	this->nmeDoProcessStageEvent(inEvent);
	HX_STACK_LINE(359)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeProcessStageEvent,return )

Void Stage_obj::dummyTrace( ){
{
		HX_STACK_PUSH("Stage::dummyTrace","neash/display/Stage.hx",350);
		HX_STACK_THIS(this);
		HX_STACK_LINE(350)
		::haxe::Log_obj::trace(HX_CSTRING(""),hx::SourceInfo(HX_CSTRING("Stage.hx"),350,HX_CSTRING("neash.display.Stage"),HX_CSTRING("dummyTrace")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,dummyTrace,(void))

Float Stage_obj::nmeDoProcessStageEvent( Dynamic inEvent){
	HX_STACK_PUSH("Stage::nmeDoProcessStageEvent","neash/display/Stage.hx",235);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_LINE(236)
	Float result = 0.0;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(238)
	int type = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("type")));		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(240)
	switch( (int)(type)){
		case (int)2: {
			HX_STACK_LINE(242)
			if (((this->onKey_dyn() != null()))){
				HX_STACK_LINE(244)
				this->onKey(inEvent->__Field(HX_CSTRING("code"),true),inEvent->__Field(HX_CSTRING("down"),true),inEvent->__Field(HX_CSTRING("char"),true),inEvent->__Field(HX_CSTRING("flags"),true));
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(246)
			this->nmeOnKey(inEvent,::neash::events::KeyboardEvent_obj::KEY_DOWN);
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(249)
			this->nmeOnKey(inEvent,::neash::events::KeyboardEvent_obj::KEY_UP);
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(252)
			this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::MOUSE_MOVE,true);
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(255)
			this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::MOUSE_DOWN,true);
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(258)
			this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::CLICK,true);
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(261)
			this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::MOUSE_UP,true);
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(265)
			this->nmeOnResize(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(266)
			if (((this->renderRequest_dyn() == null()))){
				HX_STACK_LINE(267)
				this->nmeRender(false);
			}
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(269)
			this->nmePollTimers();
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(272)
			if (((this->onQuit_dyn() != null()))){
				HX_STACK_LINE(274)
				this->onQuit();
			}
		}
		;break;
		case (int)11: {
			HX_STACK_LINE(276)
			this->nmeOnFocus(inEvent);
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(279)
			if ((::neash::display::Stage_obj::shouldRotateInterface(inEvent->__Field(HX_CSTRING("value"),true)))){
				HX_STACK_LINE(281)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)2;
			}
		}
		;break;
		case (int)14: {
			HX_STACK_LINE(283)
			this->nmeRender(true);
		}
		;break;
		case (int)15: {
			HX_STACK_LINE(287)
			::neash::display::TouchInfo touchInfo = ::neash::display::TouchInfo_obj::__new();		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(288)
			this->nmeTouchInfo->set(inEvent->__Field(HX_CSTRING("value"),true),touchInfo);
			HX_STACK_LINE(289)
			this->nmeOnTouch(inEvent,::neash::events::TouchEvent_obj::TOUCH_BEGIN,touchInfo);
			HX_STACK_LINE(291)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0))){
				HX_STACK_LINE(292)
				this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::MOUSE_DOWN,false);
			}
		}
		;break;
		case (int)16: {
			HX_STACK_LINE(295)
			::neash::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value"),true));		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(296)
			this->nmeOnTouch(inEvent,::neash::events::TouchEvent_obj::TOUCH_MOVE,touchInfo);
		}
		;break;
		case (int)17: {
			HX_STACK_LINE(299)
			::neash::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value"),true));		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(300)
			this->nmeOnTouch(inEvent,::neash::events::TouchEvent_obj::TOUCH_END,touchInfo);
			HX_STACK_LINE(301)
			this->nmeTouchInfo->remove(inEvent->__Field(HX_CSTRING("value"),true));
			HX_STACK_LINE(303)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0))){
				HX_STACK_LINE(304)
				this->nmeOnMouse(inEvent,::neash::events::MouseEvent_obj::MOUSE_UP,false);
			}
		}
		;break;
		case (int)18: {
		}
		;break;
		case (int)19: {
			HX_STACK_LINE(309)
			this->nmeOnChange(inEvent);
		}
		;break;
		case (int)20: {
			HX_STACK_LINE(312)
			this->nmeSetActive(true);
		}
		;break;
		case (int)21: {
			HX_STACK_LINE(315)
			this->nmeSetActive(false);
		}
		;break;
		case (int)22: {
			HX_STACK_LINE(319)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::FocusEvent_obj::FOCUS_IN,null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(320)
			this->nmeBroadcast(evt);
		}
		;break;
		case (int)23: {
			HX_STACK_LINE(323)
			::neash::events::Event evt = ::neash::events::Event_obj::__new(::neash::events::FocusEvent_obj::FOCUS_OUT,null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(324)
			this->nmeBroadcast(evt);
		}
		;break;
		case (int)24: {
			HX_STACK_LINE(326)
			this->nmeOnJoystick(inEvent,::neash::events::JoystickEvent_obj::AXIS_MOVE);
		}
		;break;
		case (int)25: {
			HX_STACK_LINE(329)
			this->nmeOnJoystick(inEvent,::neash::events::JoystickEvent_obj::BALL_MOVE);
		}
		;break;
		case (int)26: {
			HX_STACK_LINE(332)
			this->nmeOnJoystick(inEvent,::neash::events::JoystickEvent_obj::HAT_MOVE);
		}
		;break;
		case (int)27: {
			HX_STACK_LINE(335)
			this->nmeOnJoystick(inEvent,::neash::events::JoystickEvent_obj::BUTTON_DOWN);
		}
		;break;
		case (int)28: {
			HX_STACK_LINE(338)
			this->nmeOnJoystick(inEvent,::neash::events::JoystickEvent_obj::BUTTON_UP);
		}
		;break;
	}
	HX_STACK_LINE(344)
	result = this->nmeUpdateNextWake();
	HX_STACK_LINE(347)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDoProcessStageEvent,return )

Void Stage_obj::nmeCheckRender( ){
{
		HX_STACK_PUSH("Stage::nmeCheckRender","neash/display/Stage.hx",217);
		HX_STACK_THIS(this);
		HX_STACK_LINE(217)
		if (((this->frameRate > (int)0))){
			HX_STACK_LINE(221)
			Float now = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(now,"now");
			HX_STACK_LINE(222)
			if (((now >= (this->nmeLastRender + this->nmeFramePeriod)))){
				HX_STACK_LINE(224)
				this->nmeLastRender = now;
				HX_STACK_LINE(225)
				if (((this->renderRequest_dyn() != null()))){
					HX_STACK_LINE(226)
					this->renderRequest();
				}
				else{
					HX_STACK_LINE(228)
					this->nmeRender(true);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeCheckRender,(void))

bool Stage_obj::nmeCheckInOuts( ::neash::events::MouseEvent inEvent,Array< ::neash::display::InteractiveObject > inStack,::neash::display::TouchInfo touchInfo){
	HX_STACK_PUSH("Stage::nmeCheckInOuts","neash/display/Stage.hx",165);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_ARG(inStack,"inStack");
	HX_STACK_ARG(touchInfo,"touchInfo");
	HX_STACK_LINE(166)
	Array< ::neash::display::InteractiveObject > prev = (  (((touchInfo == null()))) ? Array< ::neash::display::InteractiveObject >(this->nmeMouseOverObjects) : Array< ::neash::display::InteractiveObject >(touchInfo->touchOverObjects) );		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(167)
	Array< ::String > events = (  (((touchInfo == null()))) ? Array< ::String >(::neash::display::Stage_obj::nmeMouseChanges) : Array< ::String >(::neash::display::Stage_obj::nmeTouchChanges) );		HX_STACK_VAR(events,"events");
	HX_STACK_LINE(169)
	int new_n = inStack->length;		HX_STACK_VAR(new_n,"new_n");
	HX_STACK_LINE(170)
	::neash::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::neash::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::neash::display::InteractiveObject(null()) );		HX_STACK_VAR(new_obj,"new_obj");
	HX_STACK_LINE(171)
	int old_n = prev->length;		HX_STACK_VAR(old_n,"old_n");
	HX_STACK_LINE(172)
	::neash::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::neash::display::InteractiveObject(prev->__get((old_n - (int)1))) : ::neash::display::InteractiveObject(null()) );		HX_STACK_VAR(old_obj,"old_obj");
	HX_STACK_LINE(174)
	if (((new_obj != old_obj))){
		HX_STACK_LINE(177)
		if (((old_obj != null()))){
			HX_STACK_LINE(178)
			old_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)0),new_obj,old_obj));
		}
		HX_STACK_LINE(180)
		if (((new_obj != null()))){
			HX_STACK_LINE(181)
			new_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)1),old_obj,null()));
		}
		HX_STACK_LINE(184)
		int common = (int)0;		HX_STACK_VAR(common,"common");
		HX_STACK_LINE(185)
		while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == prev->__get(common)))))){
			HX_STACK_LINE(186)
			(common)++;
		}
		HX_STACK_LINE(188)
		::neash::events::MouseEvent rollOut = inEvent->nmeCreateSimilar(events->__get((int)2),new_obj,old_obj);		HX_STACK_VAR(rollOut,"rollOut");
		HX_STACK_LINE(189)
		int i = (old_n - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(190)
		while(((i >= common))){
			HX_STACK_LINE(192)
			prev->__get(i)->nmeDispatchEvent(rollOut);
			HX_STACK_LINE(193)
			(i)--;
		}
		HX_STACK_LINE(196)
		::neash::events::MouseEvent rollOver = inEvent->nmeCreateSimilar(events->__get((int)3),old_obj,null());		HX_STACK_VAR(rollOver,"rollOver");
		HX_STACK_LINE(197)
		int i1 = (new_n - (int)1);		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(198)
		while(((i1 >= common))){
			HX_STACK_LINE(200)
			inStack->__get(i1)->nmeDispatchEvent(rollOver);
			HX_STACK_LINE(201)
			(i1)--;
		}
		HX_STACK_LINE(204)
		if (((touchInfo == null()))){
			HX_STACK_LINE(205)
			this->nmeMouseOverObjects = inStack;
		}
		else{
			HX_STACK_LINE(207)
			touchInfo->touchOverObjects = inStack;
		}
		HX_STACK_LINE(209)
		return false;
	}
	HX_STACK_LINE(212)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeCheckInOuts,return )

Void Stage_obj::nmeCheckFocusInOuts( Dynamic inEvent,Array< ::neash::display::InteractiveObject > inStack){
{
		HX_STACK_PUSH("Stage::nmeCheckFocusInOuts","neash/display/Stage.hx",127);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inStack,"inStack");
		HX_STACK_LINE(129)
		int new_n = inStack->length;		HX_STACK_VAR(new_n,"new_n");
		HX_STACK_LINE(130)
		::neash::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::neash::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::neash::display::InteractiveObject(null()) );		HX_STACK_VAR(new_obj,"new_obj");
		HX_STACK_LINE(131)
		int old_n = this->nmeFocusOverObjects->length;		HX_STACK_VAR(old_n,"old_n");
		HX_STACK_LINE(132)
		::neash::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::neash::display::InteractiveObject(this->nmeFocusOverObjects->__get((old_n - (int)1))) : ::neash::display::InteractiveObject(null()) );		HX_STACK_VAR(old_obj,"old_obj");
		HX_STACK_LINE(134)
		if (((new_obj != old_obj))){
			HX_STACK_LINE(137)
			int common = (int)0;		HX_STACK_VAR(common,"common");
			HX_STACK_LINE(138)
			while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == this->nmeFocusOverObjects->__get(common)))))){
				HX_STACK_LINE(139)
				(common)++;
			}
			HX_STACK_LINE(141)
			::neash::events::FocusEvent focusOut = ::neash::events::FocusEvent_obj::__new(::neash::events::FocusEvent_obj::FOCUS_OUT,false,false,new_obj,(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(focusOut,"focusOut");
			HX_STACK_LINE(143)
			int i = (old_n - (int)1);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(144)
			while(((i >= common))){
				HX_STACK_LINE(146)
				this->nmeFocusOverObjects->__get(i)->nmeDispatchEvent(focusOut);
				HX_STACK_LINE(147)
				(i)--;
			}
			HX_STACK_LINE(150)
			::neash::events::FocusEvent focusIn = ::neash::events::FocusEvent_obj::__new(::neash::events::FocusEvent_obj::FOCUS_IN,false,false,old_obj,(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(focusIn,"focusIn");
			HX_STACK_LINE(151)
			int i1 = (new_n - (int)1);		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(153)
			while(((i1 >= common))){
				HX_STACK_LINE(155)
				inStack->__get(i1)->nmeDispatchEvent(focusIn);
				HX_STACK_LINE(156)
				(i1)--;
			}
			HX_STACK_LINE(159)
			this->nmeFocusOverObjects = inStack;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeCheckFocusInOuts,(void))

Void Stage_obj::invalidate( ){
{
		HX_STACK_PUSH("Stage::invalidate","neash/display/Stage.hx",121);
		HX_STACK_THIS(this);
		HX_STACK_LINE(121)
		this->nmeInvalid = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,invalidate,(void))

Float Stage_obj::nmeEarlyWakeup;

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
	HX_STACK_PUSH("Stage::getOrientation","neash/display/Stage.hx",110);
	HX_STACK_LINE(110)
	return ::neash::display::Stage_obj::nme_stage_get_orientation();
}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::getOrientation;

HX_BEGIN_DEFAULT_FUNC(__default_getNormalOrientation,Stage_obj)
int run(){
	HX_STACK_PUSH("Stage::getNormalOrientation","neash/display/Stage.hx",115);
	HX_STACK_LINE(115)
	return ::neash::display::Stage_obj::nme_stage_get_normal_orientation();
}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::getNormalOrientation;

Void Stage_obj::setFixedOrientation( int inOrientation){
{
		HX_STACK_PUSH("Stage::setFixedOrientation","neash/display/Stage.hx",741);
		HX_STACK_ARG(inOrientation,"inOrientation");
		HX_STACK_LINE(741)
		::neash::display::Stage_obj::nme_stage_set_fixed_orientation(inOrientation);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,setFixedOrientation,(void))

HX_BEGIN_DEFAULT_FUNC(__default_shouldRotateInterface,Stage_obj)
bool run(int inOrientation){
	HX_STACK_PUSH("Stage::shouldRotateInterface","neash/display/Stage.hx",748);
	HX_STACK_ARG(inOrientation,"inOrientation");
	HX_STACK_LINE(748)
	return (inOrientation == ::neash::display::Stage_obj::OrientationPortrait);
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

Dynamic Stage_obj::nme_stage_get_normal_orientation;


Stage_obj::Stage_obj()
{
}

void Stage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stage);
	HX_MARK_MEMBER_NAME(nmeTouchInfo,"nmeTouchInfo");
	HX_MARK_MEMBER_NAME(nmeMouseOverObjects,"nmeMouseOverObjects");
	HX_MARK_MEMBER_NAME(nmeLastRender,"nmeLastRender");
	HX_MARK_MEMBER_NAME(nmeLastDown,"nmeLastDown");
	HX_MARK_MEMBER_NAME(nmeLastClickTime,"nmeLastClickTime");
	HX_MARK_MEMBER_NAME(nmeInvalid,"nmeInvalid");
	HX_MARK_MEMBER_NAME(nmeFramePeriod,"nmeFramePeriod");
	HX_MARK_MEMBER_NAME(nmeFocusOverObjects,"nmeFocusOverObjects");
	HX_MARK_MEMBER_NAME(nmeDragOffsetY,"nmeDragOffsetY");
	HX_MARK_MEMBER_NAME(nmeDragOffsetX,"nmeDragOffsetX");
	HX_MARK_MEMBER_NAME(nmeDragObject,"nmeDragObject");
	HX_MARK_MEMBER_NAME(nmeDragBounds,"nmeDragBounds");
	HX_MARK_MEMBER_NAME(nmeJoyAxisData,"nmeJoyAxisData");
	HX_MARK_MEMBER_NAME(stageWidth,"stageWidth");
	HX_MARK_MEMBER_NAME(stageHeight,"stageHeight");
	HX_MARK_MEMBER_NAME(stageFocusRect,"stageFocusRect");
	HX_MARK_MEMBER_NAME(scaleMode,"scaleMode");
	HX_MARK_MEMBER_NAME(renderRequest,"renderRequest");
	HX_MARK_MEMBER_NAME(quality,"quality");
	HX_MARK_MEMBER_NAME(pauseWhenDeactivated,"pauseWhenDeactivated");
	HX_MARK_MEMBER_NAME(onQuit,"onQuit");
	HX_MARK_MEMBER_NAME(onKey,"onKey");
	HX_MARK_MEMBER_NAME(isOpenGL,"isOpenGL");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(focus,"focus");
	HX_MARK_MEMBER_NAME(dpiScale,"dpiScale");
	HX_MARK_MEMBER_NAME(displayState,"displayState");
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_MEMBER_NAME(active,"active");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Stage_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeTouchInfo,"nmeTouchInfo");
	HX_VISIT_MEMBER_NAME(nmeMouseOverObjects,"nmeMouseOverObjects");
	HX_VISIT_MEMBER_NAME(nmeLastRender,"nmeLastRender");
	HX_VISIT_MEMBER_NAME(nmeLastDown,"nmeLastDown");
	HX_VISIT_MEMBER_NAME(nmeLastClickTime,"nmeLastClickTime");
	HX_VISIT_MEMBER_NAME(nmeInvalid,"nmeInvalid");
	HX_VISIT_MEMBER_NAME(nmeFramePeriod,"nmeFramePeriod");
	HX_VISIT_MEMBER_NAME(nmeFocusOverObjects,"nmeFocusOverObjects");
	HX_VISIT_MEMBER_NAME(nmeDragOffsetY,"nmeDragOffsetY");
	HX_VISIT_MEMBER_NAME(nmeDragOffsetX,"nmeDragOffsetX");
	HX_VISIT_MEMBER_NAME(nmeDragObject,"nmeDragObject");
	HX_VISIT_MEMBER_NAME(nmeDragBounds,"nmeDragBounds");
	HX_VISIT_MEMBER_NAME(nmeJoyAxisData,"nmeJoyAxisData");
	HX_VISIT_MEMBER_NAME(stageWidth,"stageWidth");
	HX_VISIT_MEMBER_NAME(stageHeight,"stageHeight");
	HX_VISIT_MEMBER_NAME(stageFocusRect,"stageFocusRect");
	HX_VISIT_MEMBER_NAME(scaleMode,"scaleMode");
	HX_VISIT_MEMBER_NAME(renderRequest,"renderRequest");
	HX_VISIT_MEMBER_NAME(quality,"quality");
	HX_VISIT_MEMBER_NAME(pauseWhenDeactivated,"pauseWhenDeactivated");
	HX_VISIT_MEMBER_NAME(onQuit,"onQuit");
	HX_VISIT_MEMBER_NAME(onKey,"onKey");
	HX_VISIT_MEMBER_NAME(isOpenGL,"isOpenGL");
	HX_VISIT_MEMBER_NAME(frameRate,"frameRate");
	HX_VISIT_MEMBER_NAME(focus,"focus");
	HX_VISIT_MEMBER_NAME(dpiScale,"dpiScale");
	HX_VISIT_MEMBER_NAME(displayState,"displayState");
	HX_VISIT_MEMBER_NAME(align,"align");
	HX_VISIT_MEMBER_NAME(active,"active");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Stage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"onKey") ) { return onKey; }
		if (HX_FIELD_EQ(inName,"focus") ) { return inCallProp ? nmeGetFocus() : focus; }
		if (HX_FIELD_EQ(inName,"align") ) { return inCallProp ? nmeGetAlign() : align; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onQuit") ) { return onQuit; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nmeDrag") ) { return nmeDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"quality") ) { return inCallProp ? nmeGetQuality() : quality; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nmeOnKey") ) { return nmeOnKey_dyn(); }
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { return inCallProp ? nmeIsOpenGL() : isOpenGL; }
		if (HX_FIELD_EQ(inName,"dpiScale") ) { return inCallProp ? nmeGetDPIScale() : dpiScale; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { return sUpEvents; }
		if (HX_FIELD_EQ(inName,"nmeRender") ) { return nmeRender_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { return inCallProp ? nmeGetScaleMode() : scaleMode; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { return efLeftDown; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { return efCtrlDown; }
		if (HX_FIELD_EQ(inName,"showCursor") ) { return showCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnTouch") ) { return nmeOnTouch_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnMouse") ) { return nmeOnMouse_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnFocus") ) { return nmeOnFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"dummyTrace") ) { return dummyTrace_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeInvalid") ) { return nmeInvalid; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return inCallProp ? nmeGetStageWidth() : stageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"sDownEvents") ) { return sDownEvents; }
		if (HX_FIELD_EQ(inName,"nmeIsOpenGL") ) { return nmeIsOpenGL_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFocus") ) { return nmeSetFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetFocus") ) { return nmeGetFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetAlign") ) { return nmeSetAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetAlign") ) { return nmeGetAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeStopDrag") ) { return nmeStopDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnResize") ) { return nmeOnResize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnChange") ) { return nmeOnChange_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { return nmeLastDown; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return inCallProp ? nmeGetStageHeight() : stageHeight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { return sClickEvents; }
		if (HX_FIELD_EQ(inName,"nmeStartDrag") ) { return nmeStartDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetActive") ) { return nmeSetActive_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { return nmeTouchInfo; }
		if (HX_FIELD_EQ(inName,"displayState") ) { return inCallProp ? nmeGetDisplayState() : displayState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		if (HX_FIELD_EQ(inName,"nmeSetQuality") ) { return nmeSetQuality_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetQuality") ) { return nmeGetQuality_dyn(); }
		if (HX_FIELD_EQ(inName,"nmePollTimers") ) { return nmePollTimers_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnJoystick") ) { return nmeOnJoystick_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeLastRender") ) { return nmeLastRender; }
		if (HX_FIELD_EQ(inName,"nmeDragObject") ) { return nmeDragObject; }
		if (HX_FIELD_EQ(inName,"nmeDragBounds") ) { return nmeDragBounds; }
		if (HX_FIELD_EQ(inName,"renderRequest") ) { return renderRequest; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeEarlyWakeup") ) { return nmeEarlyWakeup; }
		if (HX_FIELD_EQ(inName,"getOrientation") ) { return getOrientation; }
		if (HX_FIELD_EQ(inName,"nmeGetDPIScale") ) { return nmeGetDPIScale_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeCheckRender") ) { return nmeCheckRender_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeCheckInOuts") ) { return nmeCheckInOuts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { return nmeFramePeriod; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { return nmeDragOffsetY; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { return nmeDragOffsetX; }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { return nmeJoyAxisData; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { return inCallProp ? nmeGetStageFocusRect() : stageFocusRect; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { return efLocationRight; }
		if (HX_FIELD_EQ(inName,"efNoNativeClick") ) { return efNoNativeClick; }
		if (HX_FIELD_EQ(inName,"nmeMouseChanges") ) { return nmeMouseChanges; }
		if (HX_FIELD_EQ(inName,"nmeTouchChanges") ) { return nmeTouchChanges; }
		if (HX_FIELD_EQ(inName,"nmeSetScaleMode") ) { return nmeSetScaleMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetScaleMode") ) { return nmeGetScaleMode_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetFrameRate") ) { return nmeSetFrameRate_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeNextFrameDue") ) { return nmeNextFrameDue_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_render_stage") ) { return nme_render_stage; }
		if (HX_FIELD_EQ(inName,"nmeGetStageWidth") ) { return nmeGetStageWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeLastClickTime") ) { return nmeLastClickTime; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OrientationFaceUp") ) { return OrientationFaceUp; }
		if (HX_FIELD_EQ(inName,"nmeGetStageHeight") ) { return nmeGetStageHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeUpdateNextWake") ) { return nmeUpdateNextWake_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nmeSetDisplayState") ) { return nmeSetDisplayState_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetDisplayState") ) { return nmeGetDisplayState_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"OrientationPortrait") ) { return OrientationPortrait; }
		if (HX_FIELD_EQ(inName,"OrientationFaceDown") ) { return OrientationFaceDown; }
		if (HX_FIELD_EQ(inName,"setFixedOrientation") ) { return setFixedOrientation_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_stage_set_focus") ) { return nme_stage_set_focus; }
		if (HX_FIELD_EQ(inName,"nme_stage_is_opengl") ) { return nme_stage_is_opengl; }
		if (HX_FIELD_EQ(inName,"nme_stage_get_align") ) { return nme_stage_get_align; }
		if (HX_FIELD_EQ(inName,"nme_stage_set_align") ) { return nme_stage_set_align; }
		if (HX_FIELD_EQ(inName,"nmeCheckFocusInOuts") ) { return nmeCheckFocusInOuts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeMouseOverObjects") ) { return nmeMouseOverObjects; }
		if (HX_FIELD_EQ(inName,"nmeFocusOverObjects") ) { return nmeFocusOverObjects; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getNormalOrientation") ) { return getNormalOrientation; }
		if (HX_FIELD_EQ(inName,"nmeSetStageFocusRect") ) { return nmeSetStageFocusRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetStageFocusRect") ) { return nmeGetStageFocusRect_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeProcessStageEvent") ) { return nmeProcessStageEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"pauseWhenDeactivated") ) { return pauseWhenDeactivated; }
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
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nme_stage_get_normal_orientation") ) { return nme_stage_get_normal_orientation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"onKey") ) { onKey=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"focus") ) { if (inCallProp) return nmeSetFocus(inValue);focus=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"align") ) { if (inCallProp) return nmeSetAlign(inValue);align=inValue.Cast< ::neash::display::StageAlign >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onQuit") ) { onQuit=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { if (inCallProp) return nmeSetQuality(inValue);quality=inValue.Cast< ::neash::display::StageQuality >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { isOpenGL=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dpiScale") ) { dpiScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { sUpEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { if (inCallProp) return nmeSetScaleMode(inValue);scaleMode=inValue.Cast< ::neash::display::StageScaleMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { if (inCallProp) return nmeSetFrameRate(inValue);frameRate=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { efLeftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { efCtrlDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeInvalid") ) { nmeInvalid=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageWidth") ) { stageWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { efShiftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sDownEvents") ) { sDownEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { nmeLastDown=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { sClickEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { nmeTouchInfo=inValue.Cast< ::IntHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"displayState") ) { if (inCallProp) return nmeSetDisplayState(inValue);displayState=inValue.Cast< ::neash::display::StageDisplayState >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastRender") ) { nmeLastRender=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragObject") ) { nmeDragObject=inValue.Cast< ::neash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragBounds") ) { nmeDragBounds=inValue.Cast< ::neash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderRequest") ) { renderRequest=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeEarlyWakeup") ) { nmeEarlyWakeup=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"getOrientation") ) { getOrientation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { nmeFramePeriod=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { nmeDragOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { nmeDragOffsetX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { nmeJoyAxisData=inValue.Cast< ::IntHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { if (inCallProp) return nmeSetStageFocusRect(inValue);stageFocusRect=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { efLocationRight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efNoNativeClick") ) { efNoNativeClick=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeMouseChanges") ) { nmeMouseChanges=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeTouchChanges") ) { nmeTouchChanges=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_render_stage") ) { nme_render_stage=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastClickTime") ) { nmeLastClickTime=inValue.Cast< Float >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"nmeMouseOverObjects") ) { nmeMouseOverObjects=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFocusOverObjects") ) { nmeFocusOverObjects=inValue.Cast< Array< ::neash::display::InteractiveObject > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getNormalOrientation") ) { getNormalOrientation=inValue.Cast< Dynamic >(); return inValue; }
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
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nme_stage_get_normal_orientation") ) { nme_stage_get_normal_orientation=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Stage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeTouchInfo"));
	outFields->push(HX_CSTRING("nmeMouseOverObjects"));
	outFields->push(HX_CSTRING("nmeLastRender"));
	outFields->push(HX_CSTRING("nmeLastDown"));
	outFields->push(HX_CSTRING("nmeLastClickTime"));
	outFields->push(HX_CSTRING("nmeInvalid"));
	outFields->push(HX_CSTRING("nmeFramePeriod"));
	outFields->push(HX_CSTRING("nmeFocusOverObjects"));
	outFields->push(HX_CSTRING("nmeDragOffsetY"));
	outFields->push(HX_CSTRING("nmeDragOffsetX"));
	outFields->push(HX_CSTRING("nmeDragObject"));
	outFields->push(HX_CSTRING("nmeDragBounds"));
	outFields->push(HX_CSTRING("nmeJoyAxisData"));
	outFields->push(HX_CSTRING("stageWidth"));
	outFields->push(HX_CSTRING("stageHeight"));
	outFields->push(HX_CSTRING("stageFocusRect"));
	outFields->push(HX_CSTRING("scaleMode"));
	outFields->push(HX_CSTRING("quality"));
	outFields->push(HX_CSTRING("pauseWhenDeactivated"));
	outFields->push(HX_CSTRING("isOpenGL"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("focus"));
	outFields->push(HX_CSTRING("dpiScale"));
	outFields->push(HX_CSTRING("displayState"));
	outFields->push(HX_CSTRING("align"));
	outFields->push(HX_CSTRING("active"));
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
	HX_CSTRING("getNormalOrientation"),
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
	HX_CSTRING("nme_stage_get_normal_orientation"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetStageWidth"),
	HX_CSTRING("nmeGetStageHeight"),
	HX_CSTRING("nmeSetStageFocusRect"),
	HX_CSTRING("nmeGetStageFocusRect"),
	HX_CSTRING("nmeSetScaleMode"),
	HX_CSTRING("nmeGetScaleMode"),
	HX_CSTRING("nmeSetQuality"),
	HX_CSTRING("nmeGetQuality"),
	HX_CSTRING("nmeIsOpenGL"),
	HX_CSTRING("nmeSetFrameRate"),
	HX_CSTRING("nmeSetFocus"),
	HX_CSTRING("nmeGetFocus"),
	HX_CSTRING("nmeGetDPIScale"),
	HX_CSTRING("nmeSetDisplayState"),
	HX_CSTRING("nmeGetDisplayState"),
	HX_CSTRING("nmeSetAlign"),
	HX_CSTRING("nmeGetAlign"),
	HX_CSTRING("showCursor"),
	HX_CSTRING("nmeUpdateNextWake"),
	HX_CSTRING("nmeStopDrag"),
	HX_CSTRING("nmeStartDrag"),
	HX_CSTRING("nmeSetActive"),
	HX_CSTRING("nmeRender"),
	HX_CSTRING("nmePollTimers"),
	HX_CSTRING("nmeOnTouch"),
	HX_CSTRING("nmeOnResize"),
	HX_CSTRING("nmeOnMouse"),
	HX_CSTRING("nmeOnKey"),
	HX_CSTRING("nmeOnJoystick"),
	HX_CSTRING("nmeOnFocus"),
	HX_CSTRING("nmeOnChange"),
	HX_CSTRING("nmeNextFrameDue"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("nmeDrag"),
	HX_CSTRING("nmeProcessStageEvent"),
	HX_CSTRING("dummyTrace"),
	HX_CSTRING("nmeDoProcessStageEvent"),
	HX_CSTRING("nmeCheckRender"),
	HX_CSTRING("nmeCheckInOuts"),
	HX_CSTRING("nmeCheckFocusInOuts"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("nmeTouchInfo"),
	HX_CSTRING("nmeMouseOverObjects"),
	HX_CSTRING("nmeLastRender"),
	HX_CSTRING("nmeLastDown"),
	HX_CSTRING("nmeLastClickTime"),
	HX_CSTRING("nmeInvalid"),
	HX_CSTRING("nmeFramePeriod"),
	HX_CSTRING("nmeFocusOverObjects"),
	HX_CSTRING("nmeDragOffsetY"),
	HX_CSTRING("nmeDragOffsetX"),
	HX_CSTRING("nmeDragObject"),
	HX_CSTRING("nmeDragBounds"),
	HX_CSTRING("nmeJoyAxisData"),
	HX_CSTRING("stageWidth"),
	HX_CSTRING("stageHeight"),
	HX_CSTRING("stageFocusRect"),
	HX_CSTRING("scaleMode"),
	HX_CSTRING("renderRequest"),
	HX_CSTRING("quality"),
	HX_CSTRING("pauseWhenDeactivated"),
	HX_CSTRING("onQuit"),
	HX_CSTRING("onKey"),
	HX_CSTRING("isOpenGL"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("focus"),
	HX_CSTRING("dpiScale"),
	HX_CSTRING("displayState"),
	HX_CSTRING("align"),
	HX_CSTRING("active"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stage_obj::__mClass,"__mClass");
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
	HX_MARK_MEMBER_NAME(Stage_obj::getNormalOrientation,"getNormalOrientation");
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
	HX_MARK_MEMBER_NAME(Stage_obj::nme_stage_get_normal_orientation,"nme_stage_get_normal_orientation");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stage_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Stage_obj::nmeEarlyWakeup,"nmeEarlyWakeup");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationPortrait,"OrientationPortrait");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationPortraitUpsideDown,"OrientationPortraitUpsideDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationLandscapeRight,"OrientationLandscapeRight");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationLandscapeLeft,"OrientationLandscapeLeft");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationFaceUp,"OrientationFaceUp");
	HX_VISIT_MEMBER_NAME(Stage_obj::OrientationFaceDown,"OrientationFaceDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efLeftDown,"efLeftDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efShiftDown,"efShiftDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efCtrlDown,"efCtrlDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efAltDown,"efAltDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efCommandDown,"efCommandDown");
	HX_VISIT_MEMBER_NAME(Stage_obj::efLocationRight,"efLocationRight");
	HX_VISIT_MEMBER_NAME(Stage_obj::efNoNativeClick,"efNoNativeClick");
	HX_VISIT_MEMBER_NAME(Stage_obj::nmeMouseChanges,"nmeMouseChanges");
	HX_VISIT_MEMBER_NAME(Stage_obj::nmeTouchChanges,"nmeTouchChanges");
	HX_VISIT_MEMBER_NAME(Stage_obj::sClickEvents,"sClickEvents");
	HX_VISIT_MEMBER_NAME(Stage_obj::sDownEvents,"sDownEvents");
	HX_VISIT_MEMBER_NAME(Stage_obj::sUpEvents,"sUpEvents");
	HX_VISIT_MEMBER_NAME(Stage_obj::getOrientation,"getOrientation");
	HX_VISIT_MEMBER_NAME(Stage_obj::getNormalOrientation,"getNormalOrientation");
	HX_VISIT_MEMBER_NAME(Stage_obj::shouldRotateInterface,"shouldRotateInterface");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_set_stage_handler,"nme_set_stage_handler");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_render_stage,"nme_render_stage");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_focus_id,"nme_stage_get_focus_id");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_focus,"nme_stage_set_focus");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_focus_rect,"nme_stage_get_focus_rect");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_focus_rect,"nme_stage_set_focus_rect");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_is_opengl,"nme_stage_is_opengl");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_stage_width,"nme_stage_get_stage_width");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_stage_height,"nme_stage_get_stage_height");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_dpi_scale,"nme_stage_get_dpi_scale");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_scale_mode,"nme_stage_get_scale_mode");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_scale_mode,"nme_stage_set_scale_mode");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_align,"nme_stage_get_align");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_align,"nme_stage_set_align");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_quality,"nme_stage_get_quality");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_quality,"nme_stage_set_quality");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_display_state,"nme_stage_get_display_state");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_display_state,"nme_stage_set_display_state");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_next_wake,"nme_stage_set_next_wake");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_request_render,"nme_stage_request_render");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_show_cursor,"nme_stage_show_cursor");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_set_fixed_orientation,"nme_stage_set_fixed_orientation");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_orientation,"nme_stage_get_orientation");
	HX_VISIT_MEMBER_NAME(Stage_obj::nme_stage_get_normal_orientation,"nme_stage_get_normal_orientation");
};

Class Stage_obj::__mClass;

void Stage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.Stage"), hx::TCanCast< Stage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Stage_obj::__boot()
{
	nmeEarlyWakeup= 0.005;
	OrientationPortrait= (int)1;
	OrientationPortraitUpsideDown= (int)2;
	OrientationLandscapeRight= (int)3;
	OrientationLandscapeLeft= (int)4;
	OrientationFaceUp= (int)5;
	OrientationFaceDown= (int)6;
	efLeftDown= (int)1;
	efShiftDown= (int)2;
	efCtrlDown= (int)4;
	efAltDown= (int)8;
	efCommandDown= (int)16;
	efLocationRight= (int)16384;
	efNoNativeClick= (int)65536;
	nmeMouseChanges= Array_obj< ::String >::__new().Add(::neash::events::MouseEvent_obj::MOUSE_OUT).Add(::neash::events::MouseEvent_obj::MOUSE_OVER).Add(::neash::events::MouseEvent_obj::ROLL_OUT).Add(::neash::events::MouseEvent_obj::ROLL_OVER);
	nmeTouchChanges= Array_obj< ::String >::__new().Add(::neash::events::TouchEvent_obj::TOUCH_OUT).Add(::neash::events::TouchEvent_obj::TOUCH_OVER).Add(::neash::events::TouchEvent_obj::TOUCH_ROLL_OUT).Add(::neash::events::TouchEvent_obj::TOUCH_ROLL_OVER);
	sClickEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("click")).Add(HX_CSTRING("middleClick")).Add(HX_CSTRING("rightClick"));
	sDownEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("mouseDown")).Add(HX_CSTRING("middleMouseDown")).Add(HX_CSTRING("rightMouseDown"));
	sUpEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("mouseUp")).Add(HX_CSTRING("middleMouseUp")).Add(HX_CSTRING("rightMouseUp"));
	getOrientation = new __default_getOrientation;

	getNormalOrientation = new __default_getNormalOrientation;

	shouldRotateInterface = new __default_shouldRotateInterface;

	nme_set_stage_handler= ::neash::Loader_obj::load(HX_CSTRING("nme_set_stage_handler"),(int)4);
	nme_render_stage= ::neash::Loader_obj::load(HX_CSTRING("nme_render_stage"),(int)1);
	nme_stage_get_focus_id= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_id"),(int)1);
	nme_stage_set_focus= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_focus"),(int)3);
	nme_stage_get_focus_rect= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_rect"),(int)1);
	nme_stage_set_focus_rect= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_focus_rect"),(int)2);
	nme_stage_is_opengl= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_is_opengl"),(int)1);
	nme_stage_get_stage_width= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_width"),(int)1);
	nme_stage_get_stage_height= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_height"),(int)1);
	nme_stage_get_dpi_scale= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_dpi_scale"),(int)1);
	nme_stage_get_scale_mode= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_scale_mode"),(int)1);
	nme_stage_set_scale_mode= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_scale_mode"),(int)2);
	nme_stage_get_align= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_align"),(int)1);
	nme_stage_set_align= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_align"),(int)2);
	nme_stage_get_quality= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_quality"),(int)1);
	nme_stage_set_quality= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_quality"),(int)2);
	nme_stage_get_display_state= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_display_state"),(int)1);
	nme_stage_set_display_state= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_display_state"),(int)2);
	nme_stage_set_next_wake= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_next_wake"),(int)2);
	nme_stage_request_render= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_request_render"),(int)0);
	nme_stage_show_cursor= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_show_cursor"),(int)2);
	nme_stage_set_fixed_orientation= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_set_fixed_orientation"),(int)1);
	nme_stage_get_orientation= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_orientation"),(int)0);
	nme_stage_get_normal_orientation= ::neash::Loader_obj::load(HX_CSTRING("nme_stage_get_normal_orientation"),(int)0);
}

} // end namespace neash
} // end namespace display
