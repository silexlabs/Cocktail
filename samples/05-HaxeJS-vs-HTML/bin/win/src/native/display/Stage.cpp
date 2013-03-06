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
#ifndef INCLUDED_native_Loader
#include <native/Loader.h>
#endif
#ifndef INCLUDED_native_display_DisplayObject
#include <native/display/DisplayObject.h>
#endif
#ifndef INCLUDED_native_display_DisplayObjectContainer
#include <native/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_InteractiveObject
#include <native/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_native_display_Sprite
#include <native/display/Sprite.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_display_StageAlign
#include <native/display/StageAlign.h>
#endif
#ifndef INCLUDED_native_display_StageDisplayState
#include <native/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_native_display_StageQuality
#include <native/display/StageQuality.h>
#endif
#ifndef INCLUDED_native_display_StageScaleMode
#include <native/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_native_display_TouchInfo
#include <native/display/TouchInfo.h>
#endif
#ifndef INCLUDED_native_events_Event
#include <native/events/Event.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_FocusEvent
#include <native/events/FocusEvent.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_JoystickEvent
#include <native/events/JoystickEvent.h>
#endif
#ifndef INCLUDED_native_events_KeyboardEvent
#include <native/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_native_events_MouseEvent
#include <native/events/MouseEvent.h>
#endif
#ifndef INCLUDED_native_events_TouchEvent
#include <native/events/TouchEvent.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_media_SoundChannel
#include <native/media/SoundChannel.h>
#endif
#ifndef INCLUDED_native_net_URLLoader
#include <native/net/URLLoader.h>
#endif
namespace native{
namespace display{

Void Stage_obj::__construct(Dynamic inHandle,int inWidth,int inHeight)
{
HX_STACK_PUSH("Stage::new","native/display/Stage.hx",95);
{
	HX_STACK_LINE(97)
	super::__construct(inHandle,HX_CSTRING("Stage"));
	HX_STACK_LINE(99)
	this->nmeMouseOverObjects = Array_obj< ::native::display::InteractiveObject >::__new();
	HX_STACK_LINE(100)
	this->nmeFocusOverObjects = Array_obj< ::native::display::InteractiveObject >::__new();
	HX_STACK_LINE(101)
	this->active = true;
	HX_STACK_LINE(102)
	this->pauseWhenDeactivated = true;
	HX_STACK_LINE(107)
	this->renderRequest = null();
	HX_STACK_LINE(110)
	::native::display::Stage_obj::nme_set_stage_handler(this->nmeHandle,this->nmeProcessStageEvent_dyn(),inWidth,inHeight);
	HX_STACK_LINE(111)
	this->nmeInvalid = false;
	HX_STACK_LINE(112)
	this->nmeLastRender = (int)0;
	HX_STACK_LINE(113)
	this->nmeLastDown = Array_obj< ::native::display::InteractiveObject >::__new();
	HX_STACK_LINE(114)
	this->nmeLastClickTime = 0.0;
	HX_STACK_LINE(115)
	this->set_frameRate((int)100);
	HX_STACK_LINE(116)
	this->nmeTouchInfo = ::IntHash_obj::__new();
	HX_STACK_LINE(117)
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

int Stage_obj::get_stageWidth( ){
	HX_STACK_PUSH("Stage::get_stageWidth","native/display/Stage.hx",1013);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1013)
	return ::Std_obj::_int(hx::TCast< Float >::cast(::native::display::Stage_obj::nme_stage_get_stage_width(this->nmeHandle)));
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_stageWidth,return )

int Stage_obj::get_stageHeight( ){
	HX_STACK_PUSH("Stage::get_stageHeight","native/display/Stage.hx",1006);
	HX_STACK_THIS(this);
	HX_STACK_LINE(1006)
	return ::Std_obj::_int(hx::TCast< Float >::cast(::native::display::Stage_obj::nme_stage_get_stage_height(this->nmeHandle)));
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_stageHeight,return )

bool Stage_obj::set_stageFocusRect( bool inVal){
	HX_STACK_PUSH("Stage::set_stageFocusRect","native/display/Stage.hx",998);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(1000)
	::native::display::Stage_obj::nme_stage_set_focus_rect(this->nmeHandle,inVal);
	HX_STACK_LINE(1001)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_stageFocusRect,return )

bool Stage_obj::get_stageFocusRect( ){
	HX_STACK_PUSH("Stage::get_stageFocusRect","native/display/Stage.hx",997);
	HX_STACK_THIS(this);
	HX_STACK_LINE(997)
	return ::native::display::Stage_obj::nme_stage_get_focus_rect(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_stageFocusRect,return )

::native::display::Stage Stage_obj::get_stage( ){
	HX_STACK_PUSH("Stage::get_stage","native/display/Stage.hx",990);
	HX_STACK_THIS(this);
	HX_STACK_LINE(990)
	return hx::ObjectPtr<OBJ_>(this);
}


::native::display::StageScaleMode Stage_obj::set_scaleMode( ::native::display::StageScaleMode inMode){
	HX_STACK_PUSH("Stage::set_scaleMode","native/display/Stage.hx",982);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(984)
	::native::display::Stage_obj::nme_stage_set_scale_mode(this->nmeHandle,inMode->__Index());
	HX_STACK_LINE(985)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_scaleMode,return )

::native::display::StageScaleMode Stage_obj::get_scaleMode( ){
	HX_STACK_PUSH("Stage::get_scaleMode","native/display/Stage.hx",974);
	HX_STACK_THIS(this);
	HX_STACK_LINE(976)
	int i = ::native::display::Stage_obj::nme_stage_get_scale_mode(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(977)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::native::display::StageScaleMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_scaleMode,return )

::native::display::StageQuality Stage_obj::set_quality( ::native::display::StageQuality inQuality){
	HX_STACK_PUSH("Stage::set_quality","native/display/Stage.hx",966);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inQuality,"inQuality");
	HX_STACK_LINE(968)
	::native::display::Stage_obj::nme_stage_set_quality(this->nmeHandle,inQuality->__Index());
	HX_STACK_LINE(969)
	return inQuality;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_quality,return )

::native::display::StageQuality Stage_obj::get_quality( ){
	HX_STACK_PUSH("Stage::get_quality","native/display/Stage.hx",958);
	HX_STACK_THIS(this);
	HX_STACK_LINE(960)
	int i = ::native::display::Stage_obj::nme_stage_get_quality(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(961)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::native::display::StageQuality >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_quality,return )

bool Stage_obj::get_isOpenGL( ){
	HX_STACK_PUSH("Stage::get_isOpenGL","native/display/Stage.hx",951);
	HX_STACK_THIS(this);
	HX_STACK_LINE(951)
	return ::native::display::Stage_obj::nme_stage_is_opengl(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_isOpenGL,return )

Float Stage_obj::set_frameRate( Float inRate){
	HX_STACK_PUSH("Stage::set_frameRate","native/display/Stage.hx",942);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inRate,"inRate");
	HX_STACK_LINE(944)
	this->frameRate = inRate;
	HX_STACK_LINE(945)
	this->nmeFramePeriod = (  (((this->frameRate <= (int)0))) ? Float(this->frameRate) : Float((Float(1.0) / Float(this->frameRate))) );
	HX_STACK_LINE(946)
	return inRate;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_frameRate,return )

::native::display::InteractiveObject Stage_obj::set_focus( ::native::display::InteractiveObject inObject){
	HX_STACK_PUSH("Stage::set_focus","native/display/Stage.hx",931);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inObject,"inObject");
	HX_STACK_LINE(933)
	if (((inObject == null()))){
		HX_STACK_LINE(934)
		::native::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,null(),(int)0);
	}
	else{
		HX_STACK_LINE(936)
		::native::display::Stage_obj::nme_stage_set_focus(this->nmeHandle,inObject->nmeHandle,(int)0);
	}
	HX_STACK_LINE(937)
	return inObject;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_focus,return )

::native::display::InteractiveObject Stage_obj::get_focus( ){
	HX_STACK_PUSH("Stage::get_focus","native/display/Stage.hx",922);
	HX_STACK_THIS(this);
	HX_STACK_LINE(924)
	int id = ::native::display::Stage_obj::nme_stage_get_focus_id(this->nmeHandle);		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(925)
	::native::display::DisplayObject obj = this->nmeFindByID(id);		HX_STACK_VAR(obj,"obj");
	HX_STACK_LINE(926)
	return obj;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_focus,return )

Float Stage_obj::get_dpiScale( ){
	HX_STACK_PUSH("Stage::get_dpiScale","native/display/Stage.hx",915);
	HX_STACK_THIS(this);
	HX_STACK_LINE(915)
	return ::native::display::Stage_obj::nme_stage_get_dpi_scale(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_dpiScale,return )

::native::display::StageDisplayState Stage_obj::set_displayState( ::native::display::StageDisplayState inState){
	HX_STACK_PUSH("Stage::set_displayState","native/display/Stage.hx",907);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inState,"inState");
	HX_STACK_LINE(909)
	::native::display::Stage_obj::nme_stage_set_display_state(this->nmeHandle,inState->__Index());
	HX_STACK_LINE(910)
	return inState;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_displayState,return )

::native::display::StageDisplayState Stage_obj::get_displayState( ){
	HX_STACK_PUSH("Stage::get_displayState","native/display/Stage.hx",899);
	HX_STACK_THIS(this);
	HX_STACK_LINE(901)
	int i = ::native::display::Stage_obj::nme_stage_get_display_state(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(902)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::native::display::StageDisplayState >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_displayState,return )

::native::display::StageAlign Stage_obj::set_align( ::native::display::StageAlign inMode){
	HX_STACK_PUSH("Stage::set_align","native/display/Stage.hx",891);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inMode,"inMode");
	HX_STACK_LINE(893)
	::native::display::Stage_obj::nme_stage_set_align(this->nmeHandle,inMode->__Index());
	HX_STACK_LINE(894)
	return inMode;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,set_align,return )

::native::display::StageAlign Stage_obj::get_align( ){
	HX_STACK_PUSH("Stage::get_align","native/display/Stage.hx",883);
	HX_STACK_THIS(this);
	HX_STACK_LINE(885)
	int i = ::native::display::Stage_obj::nme_stage_get_align(this->nmeHandle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(886)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::native::display::StageAlign >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,get_align,return )

Void Stage_obj::showCursor( bool inShow){
{
		HX_STACK_PUSH("Stage::showCursor","native/display/Stage.hx",869);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inShow,"inShow");
		HX_STACK_LINE(869)
		::native::display::Stage_obj::nme_stage_show_cursor(this->nmeHandle,inShow);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,showCursor,(void))

Float Stage_obj::nmeUpdateNextWake( ){
	HX_STACK_PUSH("Stage::nmeUpdateNextWake","native/display/Stage.hx",832);
	HX_STACK_THIS(this);
	HX_STACK_LINE(835)
	Float next_wake = ::haxe::Timer_obj::nmeNextWake(315000000.0);		HX_STACK_VAR(next_wake,"next_wake");
	HX_STACK_LINE(837)
	if (((bool((next_wake > 0.001)) && bool((::native::media::SoundChannel_obj::nmeDynamicSoundCount > (int)0))))){
		HX_STACK_LINE(838)
		next_wake = 0.001;
	}
	HX_STACK_LINE(840)
	if (((bool((next_wake > 0.02)) && bool(((bool(::native::media::SoundChannel_obj::nmeCompletePending()) || bool(::native::net::URLLoader_obj::nmeLoadPending()))))))){
		HX_STACK_LINE(840)
		next_wake = (  (((bool(this->active) || bool(!(this->pauseWhenDeactivated))))) ? Float(0.020) : Float(0.500) );
	}
	HX_STACK_LINE(846)
	next_wake = this->nmeNextFrameDue(next_wake);
	HX_STACK_LINE(847)
	::native::display::Stage_obj::nme_stage_set_next_wake(this->nmeHandle,next_wake);
	HX_STACK_LINE(849)
	return next_wake;
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeUpdateNextWake,return )

Void Stage_obj::nmeStopDrag( ::native::display::Sprite sprite){
{
		HX_STACK_PUSH("Stage::nmeStopDrag","native/display/Stage.hx",824);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sprite,"sprite");
		HX_STACK_LINE(826)
		this->nmeDragBounds = null();
		HX_STACK_LINE(827)
		this->nmeDragObject = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeStopDrag,(void))

Void Stage_obj::nmeStartDrag( ::native::display::Sprite sprite,bool lockCenter,::native::geom::Rectangle bounds){
{
		HX_STACK_PUSH("Stage::nmeStartDrag","native/display/Stage.hx",795);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sprite,"sprite");
		HX_STACK_ARG(lockCenter,"lockCenter");
		HX_STACK_ARG(bounds,"bounds");
		HX_STACK_LINE(797)
		this->nmeDragBounds = (  (((bounds == null()))) ? ::native::geom::Rectangle(null()) : ::native::geom::Rectangle(bounds->clone()) );
		HX_STACK_LINE(798)
		this->nmeDragObject = sprite;
		HX_STACK_LINE(800)
		if (((this->nmeDragObject != null()))){
			HX_STACK_LINE(800)
			if ((lockCenter)){
				HX_STACK_LINE(804)
				this->nmeDragOffsetX = (Float(-(this->nmeDragObject->get_width())) / Float((int)2));
				HX_STACK_LINE(805)
				this->nmeDragOffsetY = (Float(-(this->nmeDragObject->get_height())) / Float((int)2));
			}
			else{
				HX_STACK_LINE(809)
				::native::geom::Point mouse = ::native::geom::Point_obj::__new(this->get_mouseX(),this->get_mouseY());		HX_STACK_VAR(mouse,"mouse");
				HX_STACK_LINE(810)
				::native::display::DisplayObjectContainer p = this->nmeDragObject->get_parent();		HX_STACK_VAR(p,"p");
				HX_STACK_LINE(811)
				if (((p != null()))){
					HX_STACK_LINE(812)
					mouse = p->globalToLocal(mouse);
				}
				HX_STACK_LINE(814)
				this->nmeDragOffsetX = (this->nmeDragObject->get_x() - mouse->x);
				HX_STACK_LINE(815)
				this->nmeDragOffsetY = (this->nmeDragObject->get_y() - mouse->y);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeStartDrag,(void))

Void Stage_obj::nmeSetActive( bool inActive){
{
		HX_STACK_PUSH("Stage::nmeSetActive","native/display/Stage.hx",776);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inActive,"inActive");
		HX_STACK_LINE(776)
		if (((inActive != this->active))){
			HX_STACK_LINE(781)
			this->active = inActive;
			HX_STACK_LINE(782)
			if ((!(this->active))){
				HX_STACK_LINE(783)
				this->nmeLastRender = ::haxe::Timer_obj::stamp();
			}
			HX_STACK_LINE(785)
			::native::events::Event evt = ::native::events::Event_obj::__new((  ((inActive)) ? ::String(::native::events::Event_obj::ACTIVATE) : ::String(::native::events::Event_obj::DEACTIVATE) ),null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(786)
			this->nmeBroadcast(evt);
			HX_STACK_LINE(787)
			if ((inActive)){
				HX_STACK_LINE(788)
				this->nmePollTimers();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeSetActive,(void))

Void Stage_obj::nmeRender( bool inSendEnterFrame){
{
		HX_STACK_PUSH("Stage::nmeRender","native/display/Stage.hx",754);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSendEnterFrame,"inSendEnterFrame");
		HX_STACK_LINE(756)
		if ((!(this->active))){
			HX_STACK_LINE(757)
			return null();
		}
		HX_STACK_LINE(760)
		if ((inSendEnterFrame)){
			HX_STACK_LINE(760)
			this->nmeBroadcast(::native::events::Event_obj::__new(::native::events::Event_obj::ENTER_FRAME,null(),null()));
		}
		HX_STACK_LINE(764)
		if ((this->nmeInvalid)){
			HX_STACK_LINE(766)
			this->nmeInvalid = false;
			HX_STACK_LINE(767)
			this->nmeBroadcast(::native::events::Event_obj::__new(::native::events::Event_obj::RENDER,null(),null()));
		}
		HX_STACK_LINE(771)
		::native::display::Stage_obj::nme_render_stage(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeRender,(void))

Void Stage_obj::nmePollTimers( ){
{
		HX_STACK_PUSH("Stage::nmePollTimers","native/display/Stage.hx",743);
		HX_STACK_THIS(this);
		HX_STACK_LINE(746)
		::haxe::Timer_obj::nmeCheckTimers();
		HX_STACK_LINE(747)
		::native::media::SoundChannel_obj::nmePollComplete();
		HX_STACK_LINE(748)
		::native::net::URLLoader_obj::nmePollData();
		HX_STACK_LINE(749)
		this->nmeCheckRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmePollTimers,(void))

Void Stage_obj::nmeOnTouch( Dynamic inEvent,::String inType,::native::display::TouchInfo touchInfo){
{
		HX_STACK_PUSH("Stage::nmeOnTouch","native/display/Stage.hx",699);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_ARG(touchInfo,"touchInfo");
		HX_STACK_LINE(701)
		Array< ::native::display::InteractiveObject > stack = Array_obj< ::native::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(702)
		::native::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(704)
		if (((obj != null()))){
			HX_STACK_LINE(705)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(707)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(709)
			::native::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(710)
			stack->reverse();
			HX_STACK_LINE(711)
			::native::geom::Point local = obj1->globalToLocal(::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));		HX_STACK_VAR(local,"local");
			HX_STACK_LINE(712)
			::native::events::TouchEvent evt = ::native::events::TouchEvent_obj::nmeCreate(inType,inEvent,local,obj1,inEvent->__Field(HX_CSTRING("sx"),true),inEvent->__Field(HX_CSTRING("sy"),true));		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(713)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"),true);
			HX_STACK_LINE(714)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0);
			HX_STACK_LINE(716)
			this->nmeCheckInOuts(evt,stack,touchInfo);
			HX_STACK_LINE(717)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(719)
			if (((bool(evt->isPrimaryTouchPoint) && bool((inType == ::native::events::TouchEvent_obj::TOUCH_MOVE))))){
				HX_STACK_LINE(721)
				if (((this->nmeDragObject != null()))){
					HX_STACK_LINE(722)
					this->nmeDrag(::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
				}
				HX_STACK_LINE(724)
				::native::events::MouseEvent evt1 = ::native::events::MouseEvent_obj::nmeCreate(::native::events::MouseEvent_obj::MOUSE_MOVE,inEvent,local,obj1);		HX_STACK_VAR(evt1,"evt1");
				HX_STACK_LINE(725)
				obj1->nmeFireEvent(evt1);
			}
		}
		else{
			HX_STACK_LINE(732)
			::native::events::TouchEvent evt = ::native::events::TouchEvent_obj::nmeCreate(inType,inEvent,::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)),null(),inEvent->__Field(HX_CSTRING("sx"),true),inEvent->__Field(HX_CSTRING("sy"),true));		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(733)
			evt->touchPointID = inEvent->__Field(HX_CSTRING("value"),true);
			HX_STACK_LINE(734)
			evt->isPrimaryTouchPoint = (((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0);
			HX_STACK_LINE(736)
			this->nmeCheckInOuts(evt,stack,touchInfo);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnTouch,(void))

Void Stage_obj::nmeOnResize( Float inW,Float inH){
{
		HX_STACK_PUSH("Stage::nmeOnResize","native/display/Stage.hx",691);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inW,"inW");
		HX_STACK_ARG(inH,"inH");
		HX_STACK_LINE(693)
		::native::events::Event evt = ::native::events::Event_obj::__new(::native::events::Event_obj::RESIZE,null(),null());		HX_STACK_VAR(evt,"evt");
		HX_STACK_LINE(694)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnResize,(void))

Void Stage_obj::nmeOnMouse( Dynamic inEvent,::String inType,bool inFromMouse){
{
		HX_STACK_PUSH("Stage::nmeOnMouse","native/display/Stage.hx",593);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_ARG(inFromMouse,"inFromMouse");
		HX_STACK_LINE(595)
		::String type = inType;		HX_STACK_VAR(type,"type");
		HX_STACK_LINE(596)
		int button = inEvent->__Field(HX_CSTRING("value"),true);		HX_STACK_VAR(button,"button");
		HX_STACK_LINE(598)
		if ((!(inFromMouse))){
			HX_STACK_LINE(599)
			button = (int)0;
		}
		HX_STACK_LINE(601)
		int wheel = (int)0;		HX_STACK_VAR(wheel,"wheel");
		HX_STACK_LINE(603)
		if (((inType == ::native::events::MouseEvent_obj::MOUSE_DOWN))){
			HX_STACK_LINE(605)
			if (((button > (int)2))){
				HX_STACK_LINE(606)
				return null();
			}
			HX_STACK_LINE(607)
			type = ::native::display::Stage_obj::sDownEvents->__get(button);
		}
		else{
			HX_STACK_LINE(609)
			if (((inType == ::native::events::MouseEvent_obj::MOUSE_UP))){
				HX_STACK_LINE(609)
				if (((button > (int)2))){
					HX_STACK_LINE(613)
					type = ::native::events::MouseEvent_obj::MOUSE_WHEEL;
					HX_STACK_LINE(614)
					wheel = (  (((button == (int)3))) ? int((int)1) : int((int)-1) );
				}
				else{
					HX_STACK_LINE(616)
					type = ::native::display::Stage_obj::sUpEvents->__get(button);
				}
			}
		}
		HX_STACK_LINE(624)
		if (((this->nmeDragObject != null()))){
			HX_STACK_LINE(625)
			this->nmeDrag(::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
		}
		HX_STACK_LINE(627)
		Array< ::native::display::InteractiveObject > stack = Array_obj< ::native::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(628)
		::native::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(630)
		if (((obj != null()))){
			HX_STACK_LINE(631)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(633)
		::native::geom::Point local = null();		HX_STACK_VAR(local,"local");
		HX_STACK_LINE(634)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(636)
			::native::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(637)
			stack->reverse();
			HX_STACK_LINE(638)
			local = obj1->globalToLocal(::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true)));
			HX_STACK_LINE(639)
			::native::events::MouseEvent evt = ::native::events::MouseEvent_obj::nmeCreate(type,inEvent,local,obj1);		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(640)
			evt->delta = wheel;
			HX_STACK_LINE(641)
			if ((inFromMouse)){
				HX_STACK_LINE(642)
				this->nmeCheckInOuts(evt,stack,null());
			}
			HX_STACK_LINE(643)
			obj1->nmeFireEvent(evt);
		}
		else{
			HX_STACK_LINE(648)
			local = ::native::geom::Point_obj::__new(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(649)
			::native::events::MouseEvent evt = ::native::events::MouseEvent_obj::nmeCreate(type,inEvent,local,null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(650)
			evt->delta = wheel;
			HX_STACK_LINE(651)
			if ((inFromMouse)){
				HX_STACK_LINE(652)
				this->nmeCheckInOuts(evt,stack,null());
			}
		}
		HX_STACK_LINE(656)
		::native::display::InteractiveObject click_obj = (  (((stack->length > (int)0))) ? ::native::display::InteractiveObject(stack->__get((stack->length - (int)1))) : ::native::display::InteractiveObject(hx::ObjectPtr<OBJ_>(this)) );		HX_STACK_VAR(click_obj,"click_obj");
		HX_STACK_LINE(657)
		if (((bool((inType == ::native::events::MouseEvent_obj::MOUSE_DOWN)) && bool((button < (int)3))))){
			HX_STACK_LINE(657)
			this->nmeLastDown[button] = click_obj;
		}
		else{
			HX_STACK_LINE(661)
			if (((bool((inType == ::native::events::MouseEvent_obj::MOUSE_UP)) && bool((button < (int)3))))){
				HX_STACK_LINE(663)
				if (((click_obj == this->nmeLastDown->__get(button)))){
					HX_STACK_LINE(665)
					::native::events::MouseEvent evt = ::native::events::MouseEvent_obj::nmeCreate(::native::display::Stage_obj::sClickEvents->__get(button),inEvent,local,click_obj);		HX_STACK_VAR(evt,"evt");
					HX_STACK_LINE(666)
					click_obj->nmeFireEvent(evt);
					HX_STACK_LINE(668)
					if (((bool((button == (int)0)) && bool(click_obj->doubleClickEnabled)))){
						HX_STACK_LINE(670)
						Float now = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(now,"now");
						HX_STACK_LINE(671)
						if ((((now - this->nmeLastClickTime) < 0.25))){
							HX_STACK_LINE(673)
							::native::events::MouseEvent evt1 = ::native::events::MouseEvent_obj::nmeCreate(::native::events::MouseEvent_obj::DOUBLE_CLICK,inEvent,local,click_obj);		HX_STACK_VAR(evt1,"evt1");
							HX_STACK_LINE(674)
							click_obj->nmeFireEvent(evt1);
						}
						HX_STACK_LINE(678)
						this->nmeLastClickTime = now;
					}
				}
				HX_STACK_LINE(684)
				this->nmeLastDown[button] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeOnMouse,(void))

Void Stage_obj::nmeOnKey( Dynamic inEvent,::String inType){
{
		HX_STACK_PUSH("Stage::nmeOnKey","native/display/Stage.hx",550);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_LINE(552)
		Array< ::native::display::InteractiveObject > stack = Array_obj< ::native::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(553)
		::native::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(555)
		if (((obj != null()))){
			HX_STACK_LINE(556)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(558)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(560)
			int value = inEvent->__Field(HX_CSTRING("value"),true);		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(562)
			if (((bool((value >= (int)96)) && bool((value <= (int)122))))){
				HX_STACK_LINE(562)
				hx::SubEq(value,(int)32);
			}
			HX_STACK_LINE(564)
			::native::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(565)
			int flags = inEvent->__Field(HX_CSTRING("flags"),true);		HX_STACK_VAR(flags,"flags");
			HX_STACK_LINE(566)
			::native::events::KeyboardEvent evt = ::native::events::KeyboardEvent_obj::__new(inType,true,true,inEvent->__Field(HX_CSTRING("code"),true),value,(  (((((int(flags) & int(::native::display::Stage_obj::efLocationRight))) == (int)0))) ? int((int)1) : int((int)0) ),(((int(flags) & int(::native::display::Stage_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::native::display::Stage_obj::efAltDown))) != (int)0),(((int(flags) & int(::native::display::Stage_obj::efShiftDown))) != (int)0),null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(567)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(569)
			if ((evt->nmeGetIsCancelled())){
				HX_STACK_LINE(570)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnKey,(void))

Void Stage_obj::nmeOnJoystick( Dynamic inEvent,::String inType){
{
		HX_STACK_PUSH("Stage::nmeOnJoystick","native/display/Stage.hx",481);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inType,"inType");
		HX_STACK_LINE(483)
		::native::events::JoystickEvent evt = null();		HX_STACK_VAR(evt,"evt");
		HX_STACK_LINE(485)
		::String _switch_1 = (inType);
		if (  ( _switch_1==HX_CSTRING("axisMove"))){
			HX_STACK_LINE(488)
			Array< Float > data = this->nmeJoyAxisData->get(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(489)
			if (((data == null()))){
				HX_STACK_LINE(489)
				data = Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(0.0).Add(0.0);
			}
			HX_STACK_LINE(495)
			Float value = (Float(inEvent->__Field(HX_CSTRING("value"),true)) / Float((int)32767));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(496)
			if (((value < (int)-1))){
				HX_STACK_LINE(496)
				value = (int)-1;
			}
			HX_STACK_LINE(498)
			while(((data->length < inEvent->__Field(HX_CSTRING("code"),true)))){
				HX_STACK_LINE(498)
				data->push((int)0);
			}
			HX_STACK_LINE(504)
			data[inEvent->__Field(HX_CSTRING("code"),true)] = value;
			HX_STACK_LINE(506)
			evt = ::native::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),(int)0,data->__get((int)0),data->__get((int)1),data->__get((int)2));
			HX_STACK_LINE(507)
			evt->axis = data->copy();
			HX_STACK_LINE(509)
			this->nmeJoyAxisData->set(inEvent->__Field(HX_CSTRING("id"),true),data);
		}
		else if (  ( _switch_1==HX_CSTRING("ballMove"))){
			HX_STACK_LINE(511)
			evt = ::native::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true),null());
		}
		else if (  ( _switch_1==HX_CSTRING("hatMove"))){
			HX_STACK_LINE(515)
			int x = (int)0;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(516)
			int y = (int)0;		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(518)
			if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)1))) != (int)0))){
				HX_STACK_LINE(518)
				y = (int)-1;
			}
			else{
				HX_STACK_LINE(522)
				if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)4))) != (int)0))){
					HX_STACK_LINE(522)
					y = (int)1;
				}
			}
			HX_STACK_LINE(528)
			if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)2))) != (int)0))){
				HX_STACK_LINE(528)
				x = (int)1;
			}
			else{
				HX_STACK_LINE(532)
				if (((((int(inEvent->__Field(HX_CSTRING("value"),true)) & int((int)8))) != (int)0))){
					HX_STACK_LINE(532)
					x = (int)-1;
				}
			}
			HX_STACK_LINE(538)
			evt = ::native::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),x,y,null());
		}
		else  {
			HX_STACK_LINE(540)
			evt = ::native::events::JoystickEvent_obj::__new(inType,false,false,inEvent->__Field(HX_CSTRING("id"),true),inEvent->__Field(HX_CSTRING("code"),true),null(),null(),null());
		}
;
;
		HX_STACK_LINE(545)
		this->nmeDispatchEvent(evt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeOnJoystick,(void))

Void Stage_obj::nmeOnFocus( Dynamic inEvent){
{
		HX_STACK_PUSH("Stage::nmeOnFocus","native/display/Stage.hx",451);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_LINE(453)
		Array< ::native::display::InteractiveObject > stack = Array_obj< ::native::display::InteractiveObject >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(454)
		::native::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(456)
		if (((obj != null()))){
			HX_STACK_LINE(457)
			obj->nmeGetInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(459)
		if (((bool((stack->length > (int)0)) && bool(((bool((inEvent->__Field(HX_CSTRING("value"),true) == (int)1)) || bool((inEvent->__Field(HX_CSTRING("value"),true) == (int)2)))))))){
			HX_STACK_LINE(461)
			::native::display::InteractiveObject obj1 = stack->__get((int)0);		HX_STACK_VAR(obj1,"obj1");
			HX_STACK_LINE(462)
			::native::events::FocusEvent evt = ::native::events::FocusEvent_obj::__new((  (((inEvent->__Field(HX_CSTRING("value"),true) == (int)1))) ? ::String(::native::events::FocusEvent_obj::MOUSE_FOCUS_CHANGE) : ::String(::native::events::FocusEvent_obj::KEY_FOCUS_CHANGE) ),true,true,(  (((this->nmeFocusOverObjects->length == (int)0))) ? ::native::display::InteractiveObject(null()) : ::native::display::InteractiveObject(this->nmeFocusOverObjects->__get((int)0)) ),(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(463)
			obj1->nmeFireEvent(evt);
			HX_STACK_LINE(465)
			if ((evt->nmeGetIsCancelled())){
				HX_STACK_LINE(467)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)1;
				HX_STACK_LINE(468)
				return null();
			}
		}
		HX_STACK_LINE(474)
		stack->reverse();
		HX_STACK_LINE(476)
		this->nmeCheckFocusInOuts(inEvent,stack);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnFocus,(void))

Void Stage_obj::nmeOnChange( Dynamic inEvent){
{
		HX_STACK_PUSH("Stage::nmeOnChange","native/display/Stage.hx",442);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_LINE(444)
		::native::display::DisplayObject obj = this->nmeFindByID(inEvent->__Field(HX_CSTRING("id"),true));		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(445)
		if (((obj != null()))){
			HX_STACK_LINE(446)
			obj->nmeFireEvent(::native::events::Event_obj::__new(::native::events::Event_obj::CHANGE,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeOnChange,(void))

Float Stage_obj::nmeNextFrameDue( Float inOtherTimers){
	HX_STACK_PUSH("Stage::nmeNextFrameDue","native/display/Stage.hx",424);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inOtherTimers,"inOtherTimers");
	HX_STACK_LINE(426)
	if (((bool(!(this->active)) && bool(this->pauseWhenDeactivated)))){
		HX_STACK_LINE(427)
		return inOtherTimers;
	}
	HX_STACK_LINE(429)
	if (((this->frameRate > (int)0))){
		HX_STACK_LINE(431)
		Float next = (((this->nmeLastRender + this->nmeFramePeriod) - ::haxe::Timer_obj::stamp()) - ::native::display::Stage_obj::nmeEarlyWakeup);		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(432)
		if (((next < inOtherTimers))){
			HX_STACK_LINE(433)
			return next;
		}
	}
	HX_STACK_LINE(437)
	return inOtherTimers;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeNextFrameDue,return )

Void Stage_obj::nmeDrag( ::native::geom::Point inMouse){
{
		HX_STACK_PUSH("Stage::nmeDrag","native/display/Stage.hx",399);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inMouse,"inMouse");
		HX_STACK_LINE(401)
		::native::display::DisplayObjectContainer p = this->nmeDragObject->get_parent();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(402)
		if (((p != null()))){
			HX_STACK_LINE(403)
			inMouse = p->globalToLocal(inMouse);
		}
		HX_STACK_LINE(405)
		Float x = (inMouse->x + this->nmeDragOffsetX);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(406)
		Float y = (inMouse->y + this->nmeDragOffsetY);		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(408)
		if (((this->nmeDragBounds != null()))){
			HX_STACK_LINE(410)
			if (((x < this->nmeDragBounds->x))){
				HX_STACK_LINE(410)
				x = this->nmeDragBounds->x;
			}
			else{
				HX_STACK_LINE(411)
				if (((x > this->nmeDragBounds->get_right()))){
					HX_STACK_LINE(411)
					x = this->nmeDragBounds->get_right();
				}
			}
			HX_STACK_LINE(413)
			if (((y < this->nmeDragBounds->y))){
				HX_STACK_LINE(413)
				y = this->nmeDragBounds->y;
			}
			else{
				HX_STACK_LINE(414)
				if (((y > this->nmeDragBounds->get_bottom()))){
					HX_STACK_LINE(414)
					y = this->nmeDragBounds->get_bottom();
				}
			}
		}
		HX_STACK_LINE(418)
		this->nmeDragObject->set_x(x);
		HX_STACK_LINE(419)
		this->nmeDragObject->set_y(y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDrag,(void))

Dynamic Stage_obj::nmeProcessStageEvent( Dynamic inEvent){
	HX_STACK_PUSH("Stage::nmeProcessStageEvent","native/display/Stage.hx",391);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_LINE(393)
	this->nmeDoProcessStageEvent(inEvent);
	HX_STACK_LINE(394)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeProcessStageEvent,return )

Void Stage_obj::dummyTrace( ){
{
		HX_STACK_PUSH("Stage::dummyTrace","native/display/Stage.hx",384);
		HX_STACK_THIS(this);
		HX_STACK_LINE(384)
		::haxe::Log_obj::trace(HX_CSTRING(""),hx::SourceInfo(HX_CSTRING("Stage.hx"),384,HX_CSTRING("native.display.Stage"),HX_CSTRING("dummyTrace")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,dummyTrace,(void))

Float Stage_obj::nmeDoProcessStageEvent( Dynamic inEvent){
	HX_STACK_PUSH("Stage::nmeDoProcessStageEvent","native/display/Stage.hx",267);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_LINE(269)
	Float result = 0.0;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(271)
	int type = ::Std_obj::_int(::Reflect_obj::field(inEvent,HX_CSTRING("type")));		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(273)
	switch( (int)(type)){
		case (int)2: {
			HX_STACK_LINE(275)
			if (((this->onKey_dyn() != null()))){
				HX_STACK_LINE(277)
				this->onKey(inEvent->__Field(HX_CSTRING("code"),true),inEvent->__Field(HX_CSTRING("down"),true),inEvent->__Field(HX_CSTRING("char"),true),inEvent->__Field(HX_CSTRING("flags"),true));
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(279)
			this->nmeOnKey(inEvent,::native::events::KeyboardEvent_obj::KEY_DOWN);
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(282)
			this->nmeOnKey(inEvent,::native::events::KeyboardEvent_obj::KEY_UP);
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(285)
			this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::MOUSE_MOVE,true);
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(288)
			this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::MOUSE_DOWN,true);
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(291)
			this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::CLICK,true);
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(294)
			this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::MOUSE_UP,true);
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(298)
			this->nmeOnResize(inEvent->__Field(HX_CSTRING("x"),true),inEvent->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(299)
			if (((this->renderRequest_dyn() == null()))){
				HX_STACK_LINE(300)
				this->nmeRender(false);
			}
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(302)
			this->nmePollTimers();
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(305)
			if (((this->onQuit_dyn() != null()))){
				HX_STACK_LINE(307)
				this->onQuit();
			}
		}
		;break;
		case (int)11: {
			HX_STACK_LINE(309)
			this->nmeOnFocus(inEvent);
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(312)
			if ((::native::display::Stage_obj::shouldRotateInterface(inEvent->__Field(HX_CSTRING("value"),true)))){
				HX_STACK_LINE(314)
				inEvent->__FieldRef(HX_CSTRING("result")) = (int)2;
			}
		}
		;break;
		case (int)14: {
			HX_STACK_LINE(316)
			this->nmeRender(true);
		}
		;break;
		case (int)15: {
			HX_STACK_LINE(320)
			::native::display::TouchInfo touchInfo = ::native::display::TouchInfo_obj::__new();		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(321)
			this->nmeTouchInfo->set(inEvent->__Field(HX_CSTRING("value"),true),touchInfo);
			HX_STACK_LINE(322)
			this->nmeOnTouch(inEvent,::native::events::TouchEvent_obj::TOUCH_BEGIN,touchInfo);
			HX_STACK_LINE(324)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0))){
				HX_STACK_LINE(325)
				this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::MOUSE_DOWN,false);
			}
		}
		;break;
		case (int)16: {
			HX_STACK_LINE(328)
			::native::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value"),true));		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(329)
			this->nmeOnTouch(inEvent,::native::events::TouchEvent_obj::TOUCH_MOVE,touchInfo);
		}
		;break;
		case (int)17: {
			HX_STACK_LINE(332)
			::native::display::TouchInfo touchInfo = this->nmeTouchInfo->get(inEvent->__Field(HX_CSTRING("value"),true));		HX_STACK_VAR(touchInfo,"touchInfo");
			HX_STACK_LINE(333)
			this->nmeOnTouch(inEvent,::native::events::TouchEvent_obj::TOUCH_END,touchInfo);
			HX_STACK_LINE(334)
			this->nmeTouchInfo->remove(inEvent->__Field(HX_CSTRING("value"),true));
			HX_STACK_LINE(336)
			if (((((int(inEvent->__Field(HX_CSTRING("flags"),true)) & int((int)32768))) > (int)0))){
				HX_STACK_LINE(337)
				this->nmeOnMouse(inEvent,::native::events::MouseEvent_obj::MOUSE_UP,false);
			}
		}
		;break;
		case (int)18: {
		}
		;break;
		case (int)19: {
			HX_STACK_LINE(342)
			this->nmeOnChange(inEvent);
		}
		;break;
		case (int)20: {
			HX_STACK_LINE(345)
			this->nmeSetActive(true);
		}
		;break;
		case (int)21: {
			HX_STACK_LINE(348)
			this->nmeSetActive(false);
		}
		;break;
		case (int)22: {
			HX_STACK_LINE(352)
			::native::events::Event evt = ::native::events::Event_obj::__new(::native::events::FocusEvent_obj::FOCUS_IN,null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(353)
			this->nmeDispatchEvent(evt);
		}
		;break;
		case (int)23: {
			HX_STACK_LINE(356)
			::native::events::Event evt = ::native::events::Event_obj::__new(::native::events::FocusEvent_obj::FOCUS_OUT,null(),null());		HX_STACK_VAR(evt,"evt");
			HX_STACK_LINE(357)
			this->nmeDispatchEvent(evt);
		}
		;break;
		case (int)24: {
			HX_STACK_LINE(359)
			this->nmeOnJoystick(inEvent,HX_CSTRING("axisMove"));
		}
		;break;
		case (int)25: {
			HX_STACK_LINE(362)
			this->nmeOnJoystick(inEvent,HX_CSTRING("ballMove"));
		}
		;break;
		case (int)26: {
			HX_STACK_LINE(365)
			this->nmeOnJoystick(inEvent,HX_CSTRING("hatMove"));
		}
		;break;
		case (int)27: {
			HX_STACK_LINE(368)
			this->nmeOnJoystick(inEvent,HX_CSTRING("buttonDown"));
		}
		;break;
		case (int)28: {
			HX_STACK_LINE(371)
			this->nmeOnJoystick(inEvent,HX_CSTRING("buttonUp"));
		}
		;break;
	}
	HX_STACK_LINE(377)
	result = this->nmeUpdateNextWake();
	HX_STACK_LINE(379)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,nmeDoProcessStageEvent,return )

Void Stage_obj::nmeCheckRender( ){
{
		HX_STACK_PUSH("Stage::nmeCheckRender","native/display/Stage.hx",246);
		HX_STACK_THIS(this);
		HX_STACK_LINE(246)
		if (((this->frameRate > (int)0))){
			HX_STACK_LINE(251)
			Float now = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(now,"now");
			HX_STACK_LINE(252)
			if (((now >= (this->nmeLastRender + this->nmeFramePeriod)))){
				HX_STACK_LINE(254)
				this->nmeLastRender = now;
				HX_STACK_LINE(255)
				if (((this->renderRequest_dyn() != null()))){
					HX_STACK_LINE(256)
					this->renderRequest();
				}
				else{
					HX_STACK_LINE(258)
					this->nmeRender(true);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stage_obj,nmeCheckRender,(void))

bool Stage_obj::nmeCheckInOuts( ::native::events::MouseEvent inEvent,Array< ::native::display::InteractiveObject > inStack,::native::display::TouchInfo touchInfo){
	HX_STACK_PUSH("Stage::nmeCheckInOuts","native/display/Stage.hx",190);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_ARG(inStack,"inStack");
	HX_STACK_ARG(touchInfo,"touchInfo");
	HX_STACK_LINE(192)
	Array< ::native::display::InteractiveObject > prev = (  (((touchInfo == null()))) ? Array< ::native::display::InteractiveObject >(this->nmeMouseOverObjects) : Array< ::native::display::InteractiveObject >(touchInfo->touchOverObjects) );		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(193)
	Array< ::String > events = (  (((touchInfo == null()))) ? Array< ::String >(::native::display::Stage_obj::nmeMouseChanges) : Array< ::String >(::native::display::Stage_obj::nmeTouchChanges) );		HX_STACK_VAR(events,"events");
	HX_STACK_LINE(195)
	int new_n = inStack->length;		HX_STACK_VAR(new_n,"new_n");
	HX_STACK_LINE(196)
	::native::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::native::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::native::display::InteractiveObject(null()) );		HX_STACK_VAR(new_obj,"new_obj");
	HX_STACK_LINE(197)
	int old_n = prev->length;		HX_STACK_VAR(old_n,"old_n");
	HX_STACK_LINE(198)
	::native::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::native::display::InteractiveObject(prev->__get((old_n - (int)1))) : ::native::display::InteractiveObject(null()) );		HX_STACK_VAR(old_obj,"old_obj");
	HX_STACK_LINE(200)
	if (((new_obj != old_obj))){
		HX_STACK_LINE(203)
		if (((old_obj != null()))){
			HX_STACK_LINE(204)
			old_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)0),new_obj,old_obj));
		}
		HX_STACK_LINE(206)
		if (((new_obj != null()))){
			HX_STACK_LINE(207)
			new_obj->nmeFireEvent(inEvent->nmeCreateSimilar(events->__get((int)1),old_obj,null()));
		}
		HX_STACK_LINE(210)
		int common = (int)0;		HX_STACK_VAR(common,"common");
		HX_STACK_LINE(211)
		while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == prev->__get(common)))))){
			HX_STACK_LINE(212)
			(common)++;
		}
		HX_STACK_LINE(214)
		::native::events::MouseEvent rollOut = inEvent->nmeCreateSimilar(events->__get((int)2),new_obj,old_obj);		HX_STACK_VAR(rollOut,"rollOut");
		HX_STACK_LINE(215)
		int i = (old_n - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(216)
		while(((i >= common))){
			HX_STACK_LINE(218)
			prev->__get(i)->nmeDispatchEvent(rollOut);
			HX_STACK_LINE(219)
			(i)--;
		}
		HX_STACK_LINE(223)
		::native::events::MouseEvent rollOver = inEvent->nmeCreateSimilar(events->__get((int)3),old_obj,null());		HX_STACK_VAR(rollOver,"rollOver");
		HX_STACK_LINE(224)
		int i1 = (new_n - (int)1);		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(225)
		while(((i1 >= common))){
			HX_STACK_LINE(227)
			inStack->__get(i1)->nmeDispatchEvent(rollOver);
			HX_STACK_LINE(228)
			(i1)--;
		}
		HX_STACK_LINE(232)
		if (((touchInfo == null()))){
			HX_STACK_LINE(233)
			this->nmeMouseOverObjects = inStack;
		}
		else{
			HX_STACK_LINE(235)
			touchInfo->touchOverObjects = inStack;
		}
		HX_STACK_LINE(237)
		return false;
	}
	HX_STACK_LINE(241)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(Stage_obj,nmeCheckInOuts,return )

Void Stage_obj::nmeCheckFocusInOuts( Dynamic inEvent,Array< ::native::display::InteractiveObject > inStack){
{
		HX_STACK_PUSH("Stage::nmeCheckFocusInOuts","native/display/Stage.hx",148);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_ARG(inStack,"inStack");
		HX_STACK_LINE(151)
		int new_n = inStack->length;		HX_STACK_VAR(new_n,"new_n");
		HX_STACK_LINE(152)
		::native::display::InteractiveObject new_obj = (  (((new_n > (int)0))) ? ::native::display::InteractiveObject(inStack->__get((new_n - (int)1))) : ::native::display::InteractiveObject(null()) );		HX_STACK_VAR(new_obj,"new_obj");
		HX_STACK_LINE(153)
		int old_n = this->nmeFocusOverObjects->length;		HX_STACK_VAR(old_n,"old_n");
		HX_STACK_LINE(154)
		::native::display::InteractiveObject old_obj = (  (((old_n > (int)0))) ? ::native::display::InteractiveObject(this->nmeFocusOverObjects->__get((old_n - (int)1))) : ::native::display::InteractiveObject(null()) );		HX_STACK_VAR(old_obj,"old_obj");
		HX_STACK_LINE(156)
		if (((new_obj != old_obj))){
			HX_STACK_LINE(159)
			int common = (int)0;		HX_STACK_VAR(common,"common");
			HX_STACK_LINE(160)
			while(((bool((bool((common < new_n)) && bool((common < old_n)))) && bool((inStack->__get(common) == this->nmeFocusOverObjects->__get(common)))))){
				HX_STACK_LINE(161)
				(common)++;
			}
			HX_STACK_LINE(163)
			::native::events::FocusEvent focusOut = ::native::events::FocusEvent_obj::__new(::native::events::FocusEvent_obj::FOCUS_OUT,false,false,new_obj,(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(focusOut,"focusOut");
			HX_STACK_LINE(165)
			int i = (old_n - (int)1);		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(166)
			while(((i >= common))){
				HX_STACK_LINE(168)
				this->nmeFocusOverObjects->__get(i)->nmeDispatchEvent(focusOut);
				HX_STACK_LINE(169)
				(i)--;
			}
			HX_STACK_LINE(173)
			::native::events::FocusEvent focusIn = ::native::events::FocusEvent_obj::__new(::native::events::FocusEvent_obj::FOCUS_IN,false,false,old_obj,(inEvent->__Field(HX_CSTRING("flags"),true) > (int)0),inEvent->__Field(HX_CSTRING("code"),true),null());		HX_STACK_VAR(focusIn,"focusIn");
			HX_STACK_LINE(174)
			int i1 = (new_n - (int)1);		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(176)
			while(((i1 >= common))){
				HX_STACK_LINE(178)
				inStack->__get(i1)->nmeDispatchEvent(focusIn);
				HX_STACK_LINE(179)
				(i1)--;
			}
			HX_STACK_LINE(183)
			this->nmeFocusOverObjects = inStack;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Stage_obj,nmeCheckFocusInOuts,(void))

Void Stage_obj::invalidate( ){
{
		HX_STACK_PUSH("Stage::invalidate","native/display/Stage.hx",141);
		HX_STACK_THIS(this);
		HX_STACK_LINE(141)
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
	HX_STACK_PUSH("Stage::getOrientation","native/display/Stage.hx",127);
	HX_STACK_LINE(127)
	return ::native::display::Stage_obj::nme_stage_get_orientation();
}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::getOrientation;

HX_BEGIN_DEFAULT_FUNC(__default_getNormalOrientation,Stage_obj)
int run(){
	HX_STACK_PUSH("Stage::getNormalOrientation","native/display/Stage.hx",134);
	HX_STACK_LINE(134)
	return ::native::display::Stage_obj::nme_stage_get_normal_orientation();
}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

Dynamic Stage_obj::getNormalOrientation;

Void Stage_obj::setFixedOrientation( int inOrientation){
{
		HX_STACK_PUSH("Stage::setFixedOrientation","native/display/Stage.hx",854);
		HX_STACK_ARG(inOrientation,"inOrientation");
		HX_STACK_LINE(854)
		::native::display::Stage_obj::nme_stage_set_fixed_orientation(inOrientation);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Stage_obj,setFixedOrientation,(void))

HX_BEGIN_DEFAULT_FUNC(__default_shouldRotateInterface,Stage_obj)
bool run(int inOrientation){
	HX_STACK_PUSH("Stage::shouldRotateInterface","native/display/Stage.hx",862);
	HX_STACK_ARG(inOrientation,"inOrientation");
	HX_STACK_LINE(862)
	return (inOrientation == ::native::display::Stage_obj::OrientationPortrait);
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
		if (HX_FIELD_EQ(inName,"focus") ) { return inCallProp ? get_focus() : focus; }
		if (HX_FIELD_EQ(inName,"align") ) { return inCallProp ? get_align() : align; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onQuit") ) { return onQuit; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nmeDrag") ) { return nmeDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"quality") ) { return inCallProp ? get_quality() : quality; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nmeOnKey") ) { return nmeOnKey_dyn(); }
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { return inCallProp ? get_isOpenGL() : isOpenGL; }
		if (HX_FIELD_EQ(inName,"dpiScale") ) { return inCallProp ? get_dpiScale() : dpiScale; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { return sUpEvents; }
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
		if (HX_FIELD_EQ(inName,"set_focus") ) { return set_focus_dyn(); }
		if (HX_FIELD_EQ(inName,"get_focus") ) { return get_focus_dyn(); }
		if (HX_FIELD_EQ(inName,"set_align") ) { return set_align_dyn(); }
		if (HX_FIELD_EQ(inName,"get_align") ) { return get_align_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeRender") ) { return nmeRender_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { return inCallProp ? get_scaleMode() : scaleMode; }
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
		if (HX_FIELD_EQ(inName,"stageWidth") ) { return inCallProp ? get_stageWidth() : stageWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"sDownEvents") ) { return sDownEvents; }
		if (HX_FIELD_EQ(inName,"set_quality") ) { return set_quality_dyn(); }
		if (HX_FIELD_EQ(inName,"get_quality") ) { return get_quality_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeStopDrag") ) { return nmeStopDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnResize") ) { return nmeOnResize_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnChange") ) { return nmeOnChange_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { return nmeLastDown; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { return inCallProp ? get_stageHeight() : stageHeight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { return sClickEvents; }
		if (HX_FIELD_EQ(inName,"get_isOpenGL") ) { return get_isOpenGL_dyn(); }
		if (HX_FIELD_EQ(inName,"get_dpiScale") ) { return get_dpiScale_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeStartDrag") ) { return nmeStartDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetActive") ) { return nmeSetActive_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { return nmeTouchInfo; }
		if (HX_FIELD_EQ(inName,"displayState") ) { return inCallProp ? get_displayState() : displayState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		if (HX_FIELD_EQ(inName,"set_scaleMode") ) { return set_scaleMode_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleMode") ) { return get_scaleMode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_frameRate") ) { return set_frameRate_dyn(); }
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
		if (HX_FIELD_EQ(inName,"get_stageWidth") ) { return get_stageWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeCheckRender") ) { return nmeCheckRender_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeCheckInOuts") ) { return nmeCheckInOuts_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { return nmeFramePeriod; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { return nmeDragOffsetY; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { return nmeDragOffsetX; }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { return nmeJoyAxisData; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { return inCallProp ? get_stageFocusRect() : stageFocusRect; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { return efLocationRight; }
		if (HX_FIELD_EQ(inName,"efNoNativeClick") ) { return efNoNativeClick; }
		if (HX_FIELD_EQ(inName,"nmeMouseChanges") ) { return nmeMouseChanges; }
		if (HX_FIELD_EQ(inName,"nmeTouchChanges") ) { return nmeTouchChanges; }
		if (HX_FIELD_EQ(inName,"get_stageHeight") ) { return get_stageHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeNextFrameDue") ) { return nmeNextFrameDue_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_render_stage") ) { return nme_render_stage; }
		if (HX_FIELD_EQ(inName,"set_displayState") ) { return set_displayState_dyn(); }
		if (HX_FIELD_EQ(inName,"get_displayState") ) { return get_displayState_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeLastClickTime") ) { return nmeLastClickTime; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OrientationFaceUp") ) { return OrientationFaceUp; }
		if (HX_FIELD_EQ(inName,"nmeUpdateNextWake") ) { return nmeUpdateNextWake_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"set_stageFocusRect") ) { return set_stageFocusRect_dyn(); }
		if (HX_FIELD_EQ(inName,"get_stageFocusRect") ) { return get_stageFocusRect_dyn(); }
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
		if (HX_FIELD_EQ(inName,"focus") ) { if (inCallProp) return set_focus(inValue);focus=inValue.Cast< ::native::display::InteractiveObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"align") ) { if (inCallProp) return set_align(inValue);align=inValue.Cast< ::native::display::StageAlign >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"onQuit") ) { onQuit=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { if (inCallProp) return set_quality(inValue);quality=inValue.Cast< ::native::display::StageQuality >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isOpenGL") ) { isOpenGL=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dpiScale") ) { dpiScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sUpEvents") ) { sUpEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleMode") ) { if (inCallProp) return set_scaleMode(inValue);scaleMode=inValue.Cast< ::native::display::StageScaleMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { if (inCallProp) return set_frameRate(inValue);frameRate=inValue.Cast< Float >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"nmeLastDown") ) { nmeLastDown=inValue.Cast< Array< ::native::display::InteractiveObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageHeight") ) { stageHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sClickEvents") ) { sClickEvents=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeTouchInfo") ) { nmeTouchInfo=inValue.Cast< ::IntHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"displayState") ) { if (inCallProp) return set_displayState(inValue);displayState=inValue.Cast< ::native::display::StageDisplayState >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeLastRender") ) { nmeLastRender=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragObject") ) { nmeDragObject=inValue.Cast< ::native::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragBounds") ) { nmeDragBounds=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderRequest") ) { renderRequest=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeEarlyWakeup") ) { nmeEarlyWakeup=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"getOrientation") ) { getOrientation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFramePeriod") ) { nmeFramePeriod=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetY") ) { nmeDragOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeDragOffsetX") ) { nmeDragOffsetX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeJoyAxisData") ) { nmeJoyAxisData=inValue.Cast< ::IntHash >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageFocusRect") ) { if (inCallProp) return set_stageFocusRect(inValue);stageFocusRect=inValue.Cast< bool >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"nmeMouseOverObjects") ) { nmeMouseOverObjects=inValue.Cast< Array< ::native::display::InteractiveObject > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeFocusOverObjects") ) { nmeFocusOverObjects=inValue.Cast< Array< ::native::display::InteractiveObject > >(); return inValue; }
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
	HX_CSTRING("get_stageWidth"),
	HX_CSTRING("get_stageHeight"),
	HX_CSTRING("set_stageFocusRect"),
	HX_CSTRING("get_stageFocusRect"),
	HX_CSTRING("get_stage"),
	HX_CSTRING("set_scaleMode"),
	HX_CSTRING("get_scaleMode"),
	HX_CSTRING("set_quality"),
	HX_CSTRING("get_quality"),
	HX_CSTRING("get_isOpenGL"),
	HX_CSTRING("set_frameRate"),
	HX_CSTRING("set_focus"),
	HX_CSTRING("get_focus"),
	HX_CSTRING("get_dpiScale"),
	HX_CSTRING("set_displayState"),
	HX_CSTRING("get_displayState"),
	HX_CSTRING("set_align"),
	HX_CSTRING("get_align"),
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
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.display.Stage"), hx::TCanCast< Stage_obj> ,sStaticFields,sMemberFields,
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
	nmeMouseChanges= Array_obj< ::String >::__new().Add(::native::events::MouseEvent_obj::MOUSE_OUT).Add(::native::events::MouseEvent_obj::MOUSE_OVER).Add(::native::events::MouseEvent_obj::ROLL_OUT).Add(::native::events::MouseEvent_obj::ROLL_OVER);
	nmeTouchChanges= Array_obj< ::String >::__new().Add(::native::events::TouchEvent_obj::TOUCH_OUT).Add(::native::events::TouchEvent_obj::TOUCH_OVER).Add(::native::events::TouchEvent_obj::TOUCH_ROLL_OUT).Add(::native::events::TouchEvent_obj::TOUCH_ROLL_OVER);
	sClickEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("click")).Add(HX_CSTRING("middleClick")).Add(HX_CSTRING("rightClick"));
	sDownEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("mouseDown")).Add(HX_CSTRING("middleMouseDown")).Add(HX_CSTRING("rightMouseDown"));
	sUpEvents= Array_obj< ::String >::__new().Add(HX_CSTRING("mouseUp")).Add(HX_CSTRING("middleMouseUp")).Add(HX_CSTRING("rightMouseUp"));
	getOrientation = new __default_getOrientation;

	getNormalOrientation = new __default_getNormalOrientation;

	shouldRotateInterface = new __default_shouldRotateInterface;

	nme_set_stage_handler= ::native::Loader_obj::load(HX_CSTRING("nme_set_stage_handler"),(int)4);
	nme_render_stage= ::native::Loader_obj::load(HX_CSTRING("nme_render_stage"),(int)1);
	nme_stage_get_focus_id= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_id"),(int)1);
	nme_stage_set_focus= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_focus"),(int)3);
	nme_stage_get_focus_rect= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_focus_rect"),(int)1);
	nme_stage_set_focus_rect= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_focus_rect"),(int)2);
	nme_stage_is_opengl= ::native::Loader_obj::load(HX_CSTRING("nme_stage_is_opengl"),(int)1);
	nme_stage_get_stage_width= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_width"),(int)1);
	nme_stage_get_stage_height= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_stage_height"),(int)1);
	nme_stage_get_dpi_scale= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_dpi_scale"),(int)1);
	nme_stage_get_scale_mode= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_scale_mode"),(int)1);
	nme_stage_set_scale_mode= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_scale_mode"),(int)2);
	nme_stage_get_align= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_align"),(int)1);
	nme_stage_set_align= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_align"),(int)2);
	nme_stage_get_quality= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_quality"),(int)1);
	nme_stage_set_quality= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_quality"),(int)2);
	nme_stage_get_display_state= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_display_state"),(int)1);
	nme_stage_set_display_state= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_display_state"),(int)2);
	nme_stage_set_next_wake= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_next_wake"),(int)2);
	nme_stage_request_render= ::native::Loader_obj::load(HX_CSTRING("nme_stage_request_render"),(int)0);
	nme_stage_show_cursor= ::native::Loader_obj::load(HX_CSTRING("nme_stage_show_cursor"),(int)2);
	nme_stage_set_fixed_orientation= ::native::Loader_obj::load(HX_CSTRING("nme_stage_set_fixed_orientation"),(int)1);
	nme_stage_get_orientation= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_orientation"),(int)0);
	nme_stage_get_normal_orientation= ::native::Loader_obj::load(HX_CSTRING("nme_stage_get_normal_orientation"),(int)0);
}

} // end namespace native
} // end namespace display
