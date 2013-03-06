#include <hxcpp.h>

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
#ifndef INCLUDED_native_display_ManagedStage
#include <native/display/ManagedStage.h>
#endif
#ifndef INCLUDED_native_display_Stage
#include <native/display/Stage.h>
#endif
#ifndef INCLUDED_native_events_EventDispatcher
#include <native/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_native_events_IEventDispatcher
#include <native/events/IEventDispatcher.h>
#endif
namespace native{
namespace display{

Void ManagedStage_obj::__construct(int inWidth,int inHeight,hx::Null< int >  __o_inFlags)
{
HX_STACK_PUSH("ManagedStage::new","native/display/ManagedStage.hx",42);
int inFlags = __o_inFlags.Default(0);
{
	HX_STACK_LINE(42)
	super::__construct(::native::display::ManagedStage_obj::nme_managed_stage_create(inWidth,inHeight,inFlags),inWidth,inHeight);
}
;
	return null();
}

ManagedStage_obj::~ManagedStage_obj() { }

Dynamic ManagedStage_obj::__CreateEmpty() { return  new ManagedStage_obj; }
hx::ObjectPtr< ManagedStage_obj > ManagedStage_obj::__new(int inWidth,int inHeight,hx::Null< int >  __o_inFlags)
{  hx::ObjectPtr< ManagedStage_obj > result = new ManagedStage_obj();
	result->__construct(inWidth,inHeight,__o_inFlags);
	return result;}

Dynamic ManagedStage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ManagedStage_obj > result = new ManagedStage_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_setNextWake,ManagedStage_obj)
Void run(Float inDelay){
{
		HX_STACK_PUSH("ManagedStage::setNextWake","native/display/ManagedStage.hx",105);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inDelay,"inDelay");
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Void ManagedStage_obj::sendQuit( ){
{
		HX_STACK_PUSH("ManagedStage::sendQuit","native/display/ManagedStage.hx",98);
		HX_STACK_THIS(this);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_PUSH("*::closure","native/display/ManagedStage.hx",100);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)10,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(98)
		this->pumpEvent(_Function_1_1::Block());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ManagedStage_obj,sendQuit,(void))

Void ManagedStage_obj::resize( int inWidth,int inHeight){
{
		HX_STACK_PUSH("ManagedStage::resize","native/display/ManagedStage.hx",91);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inWidth,"inWidth");
		HX_STACK_ARG(inHeight,"inHeight");
		struct _Function_1_1{
			inline static Dynamic Block( int &inWidth,int &inHeight){
				HX_STACK_PUSH("*::closure","native/display/ManagedStage.hx",93);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					__result->Add(HX_CSTRING("x") , inWidth,false);
					__result->Add(HX_CSTRING("y") , inHeight,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(91)
		this->pumpEvent(_Function_1_1::Block(inWidth,inHeight));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ManagedStage_obj,resize,(void))

Void ManagedStage_obj::pumpEvent( Dynamic inEvent){
{
		HX_STACK_PUSH("ManagedStage::pumpEvent","native/display/ManagedStage.hx",84);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inEvent,"inEvent");
		HX_STACK_LINE(84)
		::native::display::ManagedStage_obj::nme_managed_stage_pump_event(this->nmeHandle,inEvent);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ManagedStage_obj,pumpEvent,(void))

Void ManagedStage_obj::nmeRender( bool inSendEnterFrame){
{
		HX_STACK_PUSH("ManagedStage::nmeRender","native/display/ManagedStage.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSendEnterFrame,"inSendEnterFrame");
		HX_STACK_LINE(77)
		this->beginRender();
		HX_STACK_LINE(78)
		this->super::nmeRender(inSendEnterFrame);
		HX_STACK_LINE(79)
		this->endRender();
	}
return null();
}


Float ManagedStage_obj::nmeDoProcessStageEvent( Dynamic inEvent){
	HX_STACK_PUSH("ManagedStage::nmeDoProcessStageEvent","native/display/ManagedStage.hx",63);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inEvent,"inEvent");
	HX_STACK_LINE(65)
	this->nmePollTimers();
	HX_STACK_LINE(67)
	Float wake = this->super::nmeDoProcessStageEvent(inEvent);		HX_STACK_VAR(wake,"wake");
	HX_STACK_LINE(68)
	this->setNextWake(wake);
	HX_STACK_LINE(70)
	return wake;
}


HX_BEGIN_DEFAULT_FUNC(__default_endRender,ManagedStage_obj)
Void run(){
{
		HX_STACK_PUSH("ManagedStage::endRender","native/display/ManagedStage.hx",56);
		HX_STACK_THIS(this);
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_beginRender,ManagedStage_obj)
Void run(){
{
		HX_STACK_PUSH("ManagedStage::beginRender","native/display/ManagedStage.hx",49);
		HX_STACK_THIS(this);
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

int ManagedStage_obj::etUnknown;

int ManagedStage_obj::etKeyDown;

int ManagedStage_obj::etChar;

int ManagedStage_obj::etKeyUp;

int ManagedStage_obj::etMouseMove;

int ManagedStage_obj::etMouseDown;

int ManagedStage_obj::etMouseClick;

int ManagedStage_obj::etMouseUp;

int ManagedStage_obj::etResize;

int ManagedStage_obj::etPoll;

int ManagedStage_obj::etQuit;

int ManagedStage_obj::etFocus;

int ManagedStage_obj::etShouldRotate;

int ManagedStage_obj::etDestroyHandler;

int ManagedStage_obj::etRedraw;

int ManagedStage_obj::etTouchBegin;

int ManagedStage_obj::etTouchMove;

int ManagedStage_obj::etTouchEnd;

int ManagedStage_obj::etTouchTap;

int ManagedStage_obj::etChange;

int ManagedStage_obj::efLeftDown;

int ManagedStage_obj::efShiftDown;

int ManagedStage_obj::efCtrlDown;

int ManagedStage_obj::efAltDown;

int ManagedStage_obj::efCommandDown;

int ManagedStage_obj::efMiddleDown;

int ManagedStage_obj::efRightDown;

int ManagedStage_obj::efLocationRight;

int ManagedStage_obj::efPrimaryTouch;

Dynamic ManagedStage_obj::nme_managed_stage_create;

Dynamic ManagedStage_obj::nme_managed_stage_pump_event;


ManagedStage_obj::ManagedStage_obj()
{
	setNextWake = new __default_setNextWake(this);
	endRender = new __default_endRender(this);
	beginRender = new __default_beginRender(this);
}

void ManagedStage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ManagedStage);
	HX_MARK_MEMBER_NAME(setNextWake,"setNextWake");
	HX_MARK_MEMBER_NAME(endRender,"endRender");
	HX_MARK_MEMBER_NAME(beginRender,"beginRender");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ManagedStage_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(setNextWake,"setNextWake");
	HX_VISIT_MEMBER_NAME(endRender,"endRender");
	HX_VISIT_MEMBER_NAME(beginRender,"beginRender");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ManagedStage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"etChar") ) { return etChar; }
		if (HX_FIELD_EQ(inName,"etPoll") ) { return etPoll; }
		if (HX_FIELD_EQ(inName,"etQuit") ) { return etQuit; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"etKeyUp") ) { return etKeyUp; }
		if (HX_FIELD_EQ(inName,"etFocus") ) { return etFocus; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"etResize") ) { return etResize; }
		if (HX_FIELD_EQ(inName,"etRedraw") ) { return etRedraw; }
		if (HX_FIELD_EQ(inName,"etChange") ) { return etChange; }
		if (HX_FIELD_EQ(inName,"sendQuit") ) { return sendQuit_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"etUnknown") ) { return etUnknown; }
		if (HX_FIELD_EQ(inName,"etKeyDown") ) { return etKeyDown; }
		if (HX_FIELD_EQ(inName,"etMouseUp") ) { return etMouseUp; }
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"pumpEvent") ) { return pumpEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeRender") ) { return nmeRender_dyn(); }
		if (HX_FIELD_EQ(inName,"endRender") ) { return endRender; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"etTouchEnd") ) { return etTouchEnd; }
		if (HX_FIELD_EQ(inName,"etTouchTap") ) { return etTouchTap; }
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { return efLeftDown; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { return efCtrlDown; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"etMouseMove") ) { return etMouseMove; }
		if (HX_FIELD_EQ(inName,"etMouseDown") ) { return etMouseDown; }
		if (HX_FIELD_EQ(inName,"etTouchMove") ) { return etTouchMove; }
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"efRightDown") ) { return efRightDown; }
		if (HX_FIELD_EQ(inName,"setNextWake") ) { return setNextWake; }
		if (HX_FIELD_EQ(inName,"beginRender") ) { return beginRender; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"etMouseClick") ) { return etMouseClick; }
		if (HX_FIELD_EQ(inName,"etTouchBegin") ) { return etTouchBegin; }
		if (HX_FIELD_EQ(inName,"efMiddleDown") ) { return efMiddleDown; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"etShouldRotate") ) { return etShouldRotate; }
		if (HX_FIELD_EQ(inName,"efPrimaryTouch") ) { return efPrimaryTouch; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { return efLocationRight; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"etDestroyHandler") ) { return etDestroyHandler; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeDoProcessStageEvent") ) { return nmeDoProcessStageEvent_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_create") ) { return nme_managed_stage_create; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_pump_event") ) { return nme_managed_stage_pump_event; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ManagedStage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"etChar") ) { etChar=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etPoll") ) { etPoll=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etQuit") ) { etQuit=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"etKeyUp") ) { etKeyUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etFocus") ) { etFocus=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"etResize") ) { etResize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etRedraw") ) { etRedraw=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etChange") ) { etChange=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"etUnknown") ) { etUnknown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etKeyDown") ) { etKeyDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etMouseUp") ) { etMouseUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endRender") ) { endRender=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"etTouchEnd") ) { etTouchEnd=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchTap") ) { etTouchTap=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { efLeftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { efCtrlDown=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"etMouseMove") ) { etMouseMove=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etMouseDown") ) { etMouseDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchMove") ) { etTouchMove=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { efShiftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efRightDown") ) { efRightDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"setNextWake") ) { setNextWake=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"beginRender") ) { beginRender=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"etMouseClick") ) { etMouseClick=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"etTouchBegin") ) { etTouchBegin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efMiddleDown") ) { efMiddleDown=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"etShouldRotate") ) { etShouldRotate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efPrimaryTouch") ) { efPrimaryTouch=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"efLocationRight") ) { efLocationRight=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"etDestroyHandler") ) { etDestroyHandler=inValue.Cast< int >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_create") ) { nme_managed_stage_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_managed_stage_pump_event") ) { nme_managed_stage_pump_event=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ManagedStage_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("etUnknown"),
	HX_CSTRING("etKeyDown"),
	HX_CSTRING("etChar"),
	HX_CSTRING("etKeyUp"),
	HX_CSTRING("etMouseMove"),
	HX_CSTRING("etMouseDown"),
	HX_CSTRING("etMouseClick"),
	HX_CSTRING("etMouseUp"),
	HX_CSTRING("etResize"),
	HX_CSTRING("etPoll"),
	HX_CSTRING("etQuit"),
	HX_CSTRING("etFocus"),
	HX_CSTRING("etShouldRotate"),
	HX_CSTRING("etDestroyHandler"),
	HX_CSTRING("etRedraw"),
	HX_CSTRING("etTouchBegin"),
	HX_CSTRING("etTouchMove"),
	HX_CSTRING("etTouchEnd"),
	HX_CSTRING("etTouchTap"),
	HX_CSTRING("etChange"),
	HX_CSTRING("efLeftDown"),
	HX_CSTRING("efShiftDown"),
	HX_CSTRING("efCtrlDown"),
	HX_CSTRING("efAltDown"),
	HX_CSTRING("efCommandDown"),
	HX_CSTRING("efMiddleDown"),
	HX_CSTRING("efRightDown"),
	HX_CSTRING("efLocationRight"),
	HX_CSTRING("efPrimaryTouch"),
	HX_CSTRING("nme_managed_stage_create"),
	HX_CSTRING("nme_managed_stage_pump_event"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setNextWake"),
	HX_CSTRING("sendQuit"),
	HX_CSTRING("resize"),
	HX_CSTRING("pumpEvent"),
	HX_CSTRING("nmeRender"),
	HX_CSTRING("nmeDoProcessStageEvent"),
	HX_CSTRING("endRender"),
	HX_CSTRING("beginRender"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ManagedStage_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etUnknown,"etUnknown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etKeyDown,"etKeyDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etChar,"etChar");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etKeyUp,"etKeyUp");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseMove,"etMouseMove");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseDown,"etMouseDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseClick,"etMouseClick");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etMouseUp,"etMouseUp");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etResize,"etResize");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etPoll,"etPoll");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etQuit,"etQuit");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etFocus,"etFocus");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etShouldRotate,"etShouldRotate");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etDestroyHandler,"etDestroyHandler");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etRedraw,"etRedraw");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchBegin,"etTouchBegin");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchMove,"etTouchMove");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchEnd,"etTouchEnd");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etTouchTap,"etTouchTap");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::etChange,"etChange");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efLeftDown,"efLeftDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efShiftDown,"efShiftDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efCtrlDown,"efCtrlDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efAltDown,"efAltDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efCommandDown,"efCommandDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efMiddleDown,"efMiddleDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efRightDown,"efRightDown");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efLocationRight,"efLocationRight");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::efPrimaryTouch,"efPrimaryTouch");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_create,"nme_managed_stage_create");
	HX_MARK_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_pump_event,"nme_managed_stage_pump_event");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etUnknown,"etUnknown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etKeyDown,"etKeyDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etChar,"etChar");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etKeyUp,"etKeyUp");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etMouseMove,"etMouseMove");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etMouseDown,"etMouseDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etMouseClick,"etMouseClick");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etMouseUp,"etMouseUp");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etResize,"etResize");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etPoll,"etPoll");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etQuit,"etQuit");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etFocus,"etFocus");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etShouldRotate,"etShouldRotate");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etDestroyHandler,"etDestroyHandler");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etRedraw,"etRedraw");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etTouchBegin,"etTouchBegin");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etTouchMove,"etTouchMove");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etTouchEnd,"etTouchEnd");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etTouchTap,"etTouchTap");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::etChange,"etChange");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efLeftDown,"efLeftDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efShiftDown,"efShiftDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efCtrlDown,"efCtrlDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efAltDown,"efAltDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efCommandDown,"efCommandDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efMiddleDown,"efMiddleDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efRightDown,"efRightDown");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efLocationRight,"efLocationRight");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::efPrimaryTouch,"efPrimaryTouch");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_create,"nme_managed_stage_create");
	HX_VISIT_MEMBER_NAME(ManagedStage_obj::nme_managed_stage_pump_event,"nme_managed_stage_pump_event");
};

Class ManagedStage_obj::__mClass;

void ManagedStage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.display.ManagedStage"), hx::TCanCast< ManagedStage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ManagedStage_obj::__boot()
{
	etUnknown= (int)0;
	etKeyDown= (int)1;
	etChar= (int)2;
	etKeyUp= (int)3;
	etMouseMove= (int)4;
	etMouseDown= (int)5;
	etMouseClick= (int)6;
	etMouseUp= (int)7;
	etResize= (int)8;
	etPoll= (int)9;
	etQuit= (int)10;
	etFocus= (int)11;
	etShouldRotate= (int)12;
	etDestroyHandler= (int)13;
	etRedraw= (int)14;
	etTouchBegin= (int)15;
	etTouchMove= (int)16;
	etTouchEnd= (int)17;
	etTouchTap= (int)18;
	etChange= (int)19;
	efLeftDown= (int)1;
	efShiftDown= (int)2;
	efCtrlDown= (int)4;
	efAltDown= (int)8;
	efCommandDown= (int)16;
	efMiddleDown= (int)32;
	efRightDown= (int)64;
	efLocationRight= (int)16384;
	efPrimaryTouch= (int)32768;
	nme_managed_stage_create= ::native::Loader_obj::load(HX_CSTRING("nme_managed_stage_create"),(int)3);
	nme_managed_stage_pump_event= ::native::Loader_obj::load(HX_CSTRING("nme_managed_stage_pump_event"),(int)2);
}

} // end namespace native
} // end namespace display
